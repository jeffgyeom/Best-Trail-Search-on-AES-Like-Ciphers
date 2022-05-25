#include "astbb.h"
#include "lin_corr.h"
#include "active_map.h"
#include "printout.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

/*Variables only for the current c code region*/
static char ALG_NAME[256] = { 0, };
static FLAG_t DONE_FLAG = FALSE;
static FLAG_t TOUCH_THE_LEAF_FLAG = FALSE;
static CORR_t LC_BOUND_IN_PROGRESS;
static NUM_t NUM_SBOX_IN_A_STATE;
static NUM_t NUM_DIFF_IN_A_STATE;
static BIT_SIZE_t SBOX_I_WORD_BIT_SIZE;
static SBOX_I_CNT_t SBOX_I_CARDINALITY;
static BIT_SIZE_t SBOX_O_WORD_BIT_SIZE;
static SBOX_O_CNT_t SBOX_O_CARDINALITY;
static void(*Inv_Trans_Diffusion)(DIFF_O_WRD_t *, DIFF_I_WRD_t *);
static void(*Trans_Diffusion)(DIFF_I_WRD_t *, DIFF_O_WRD_t *);
static void(*Set_Known_Corr_Bound)(CORR_t *);
static FLAG_t ENABLE_1ROUND_ACTIVE_MAPS = FALSE;
static SBOX_I_WRD_t ZERO_INPUT_STATE[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
static FLAG_t DIFFUSION_TYPE;
static NUM_t NUM_DIFF_OF_PARTIAL_DIFFUSION;
static NUM_t NUM_PARTION_OF_DIFF_IN_A_STATE;
static NUM_t BRANCH_NUM;
static FLAG_t ENABLE_SET_INITIAL_BOUND;
static CORR_t * EACH_ROUND_INTIAL_CORR_BOUND;
static CORR_t CORR_INTERVAL;
static FLAG_t DISTINCT_SBOX = FALSE;
static UFLAG_t VERBOSE = VV_ALL;
static NUM_t WHOLE_TARGET_ROUND;
static NUM_t CUR_TARGET_ROUND;
static clock_t START_CLK;
static clock_t CHECK_CLK;
static time_t  START_TIME;
static time_t  CHECK_TIME;
/***********************************************/


void SPN_Best_Lin_FirstRound(void);
void SPN_Best_Lin_FirstSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef);
void SPN_Best_Lin_MiddleRound(CNT_t i, CORR_t RWbef);
void SPN_Best_Lin_MiddleSubRound(CNT_t i, CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef);
void SPN_Best_Lin_LastRound(CORR_t RWbef);
void SPN_Best_Lin_LastSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef);


#if defined OUR_PC1

static DEV_INLINE void Corr_Fill_Undertermined(CORR_t * pred, CNT_t j, SBOX_I_WRD_t * sin, ACTIVE_MAP_t Ain)
{
	CORR_t	estimated_curr_round_corr = ONE_CORR;
	CNT_t	sbox_idx;


	/*condition*/
	// 1) i > 2
	// 2) thus, sin is determined already


	//When the word is the last,
	if ((j + 1) == NUM_SBOX_IN_A_STATE)
	{
		*pred = estimated_curr_round_corr;
		return;
	}


	//When the word is "NOT" the last,
	if ((MAX_CORR_EQUAL_EVERY_SBOX == TRUE) && (FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX == TRUE)) //This includes the case when all the S-boxes in a state equal.
	{
		//if FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX is TRUE
		// We don't have to check the input value
		CNT_t HA;
		HA = Num_Active_Word(j, Ain, NUM_SBOX_IN_A_STATE);
		POW_MAX_CORR(&estimated_curr_round_corr, HA);
	}
	else
	{
		//We should check the input value
		for (sbox_idx = j + 1; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
		{
			if (sin[sbox_idx] != 0) //When it is not zero difference
			{
				//Multiple the maximum correlation with the non-zero estimated input difference word.
				MUL_CORR(&estimated_curr_round_corr, estimated_curr_round_corr, LC_SBOXES_O_CORR_FIXED_I[sbox_idx][sin[sbox_idx]][0].c);
			}
		}
	}

	*pred = estimated_curr_round_corr;
}

#elif defined PRE_PC1

static DEV_INLINE void Corr_Fill_Undertermined(CORR_t * pred, CNT_t j, SBOX_I_WRD_t * sin, ACTIVE_MAP_t Ain)
{
	CORR_t	estimated_curr_round_corr = ONE_CORR;
	CNT_t	HA;

	/*condition*/
	// 1) i > 2
	// 2) thus, sin is determined already


	//When the word is the last,
	if ((j + 1) == NUM_SBOX_IN_A_STATE)
	{
		*pred = estimated_curr_round_corr;
		return;
	}

	HA = Num_Active_Word(j, Ain, NUM_SBOX_IN_A_STATE);
	POW_MAX_CORR(&estimated_curr_round_corr, HA);
	*pred = estimated_curr_round_corr;
}

#endif

#if defined OUR_PC2 

static DEV_INLINE CNT_t Corr_Next_Round_Lower_Bound(CORR_t * pred, CNT_t i, CNT_t j, SBOX_O_WRD_t * sout, ACTIVE_MAP_t A)
{
	CORR_t estimated_next_round_corr = ONE_CORR;
	DIFF_I_WRD_t  i_round_state_till_j_word[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
	DIFF_O_WRD_t  iplus1_round_partial_in[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
	ACTIVE_MAP_t  estimated_iplus1_round_active_map;
	CNT_t		  sbox_idx;
	CNT_t		  num_det_word;
	CNT_t		  num_det_partition;
	CNT_t		  j_nxt;

	if ((i != 1) || (ENABLE_1ROUND_ACTIVE_MAPS == TRUE))
	{
		j_nxt = Next_Active_Word(j, A, NUM_SBOX_IN_A_STATE);
	}
	else
	{
		//get next active_word
		if (j == (NUM_SBOX_IN_A_STATE - 1))
		{
			//go to next round
			j_nxt = THIS_IS_THE_LAST;
		}
		else
		{
			//go to next word
			j_nxt = j + 1;
		}
	}


	if (j == BEFORE_STARTING_THE_ROUND)
	{
		num_det_word = 0;
		num_det_partition = 0;
	}
	else
	{

		if (j_nxt == THIS_IS_THE_LAST)
		{
			num_det_word = NUM_DIFF_IN_A_STATE;
		}
		else
		{
			num_det_word = j_nxt;
		}
		num_det_partition = (num_det_word) / NUM_DIFF_OF_PARTIAL_DIFFUSION;
	}

	if ((DIFFUSION_TYPE == BIT_PERMUTATION) && (MAX_CORR_EQUAL_EVERY_SBOX == TRUE) && (FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX == TRUE)) //This includes the case when all the S-boxes in a state equal.
	{
		/*Apply The Previous Way*/
		CNT_t  num_active;
		CORR_t active_corr;

		/*With repect to estimated part*/
		/*init i_round_state_till_j_word already*/
		memcpy(i_round_state_till_j_word, sout, sizeof(DIFF_I_WRD_t)*((size_t)num_det_word));
		/*Estimated Part from Partial Determined Values*/
		Inv_Trans_Diffusion(iplus1_round_partial_in, i_round_state_till_j_word);
		estimated_iplus1_round_active_map = Compute_Active_Map_From_State(iplus1_round_partial_in, NUM_SBOX_IN_A_STATE);
		num_active = (CNT_t)get_word_hw(estimated_iplus1_round_active_map);
		POW_MAX_CORR(&active_corr, num_active);
		MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, active_corr);
		
		/*Estimated Part from (undetermined) part of Active Map*/
		if ((i != 1) || (ENABLE_1ROUND_ACTIVE_MAPS == TRUE))
		{
			//check if every word is determined already.
			if (num_det_word != NUM_DIFF_IN_A_STATE)
			{
				CNT_t num_ongoing_partition;

				if (num_det_word == (num_det_partition * NUM_DIFF_OF_PARTIAL_DIFFUSION))
				{
					num_ongoing_partition = num_det_partition;
				}
				else //(num_fixed_word > (how_many_partition * NUM_DIFF_OF_PARTIAL_DIFFUSION))
				{
					num_ongoing_partition = num_det_partition + 1;  //+ a on-going partial permutation 
				}


				if (num_ongoing_partition != NUM_PARTION_OF_DIFF_IN_A_STATE)
				{
					NUM_t estimated_next_round_num_active = 0;
					CNT_t partial_idx;
					ACTIVE_MAP_t partial_mask = (((ACTIVE_MAP_t)1 << NUM_DIFF_OF_PARTIAL_DIFFUSION) - 1);
					for (partial_idx = num_ongoing_partition; partial_idx < NUM_PARTION_OF_DIFF_IN_A_STATE; partial_idx++)
					{
						ACTIVE_MAP_t this_partition;
						this_partition = A & (partial_mask << (partial_idx * NUM_DIFF_OF_PARTIAL_DIFFUSION));

						//estimate next round active using branch number
						if (this_partition != 0)
						{
							estimated_next_round_num_active += 1;
						}
					}
					POW_MAX_CORR(&active_corr, estimated_next_round_num_active);
					MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, active_corr);

				}
			}
		}

		*pred = estimated_next_round_corr;
		return j_nxt;
	}



	/*Totally Determined Partial State of Next Round*/
	if (num_det_partition != 0)
	{
		/*With repect to determined part*/
		memcpy(i_round_state_till_j_word, sout, sizeof(DIFF_I_WRD_t)*(size_t)(num_det_partition*NUM_DIFF_OF_PARTIAL_DIFFUSION));
		/*Determined Part*/
		Inv_Trans_Diffusion(iplus1_round_partial_in, i_round_state_till_j_word);
		for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
		{
			if (iplus1_round_partial_in[sbox_idx] != 0) //When it is not zero difference
			{
				//Multiple the maximum correlation with the non-zero estimated input difference word.
				MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, LC_SBOXES_O_CORR_FIXED_I[sbox_idx][iplus1_round_partial_in[sbox_idx]][0].c);
			}
		}
	}


	if (DIFFUSION_TYPE == BIT_PERMUTATION)
	{
		CNT_t  num_active;
		CORR_t active_corr;

		/*With repect to estimated part*/
		memset(i_round_state_till_j_word, 0, sizeof(DIFF_I_WRD_t)*((size_t)NUM_DIFF_IN_A_STATE));
		memcpy(i_round_state_till_j_word, sout, sizeof(DIFF_I_WRD_t)*((size_t)num_det_word));
		memset(i_round_state_till_j_word, 0, sizeof(DIFF_I_WRD_t)*((size_t)(num_det_partition * NUM_DIFF_OF_PARTIAL_DIFFUSION)));
		/*Estimated Part from Partial Determined Values*/
		Inv_Trans_Diffusion(iplus1_round_partial_in, i_round_state_till_j_word);
		estimated_iplus1_round_active_map = Compute_Active_Map_From_State(iplus1_round_partial_in, NUM_SBOX_IN_A_STATE);
		num_active = (CNT_t)get_word_hw(estimated_iplus1_round_active_map);
		POW_MAX_CORR(&active_corr, num_active);
		MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, active_corr);

		/*Estimated Part from (undetermined) part of Active Map*/
		if ((i != 1) || (ENABLE_1ROUND_ACTIVE_MAPS == TRUE))
		{
			//check if every word is determined already.
			if (num_det_word != NUM_DIFF_IN_A_STATE)
			{
				CNT_t num_ongoing_partition;

				if (num_det_word == (num_det_partition * NUM_DIFF_OF_PARTIAL_DIFFUSION))
				{
					num_ongoing_partition = num_det_partition;
				}
				else //(num_fixed_word > (how_many_partition * NUM_DIFF_OF_PARTIAL_DIFFUSION))
				{
					num_ongoing_partition = num_det_partition + 1;  //+ a on-going partial permutation 
				}


				if (num_ongoing_partition != NUM_PARTION_OF_DIFF_IN_A_STATE)
				{
					NUM_t estimated_next_round_num_active = 0;
					CNT_t partial_idx;
					ACTIVE_MAP_t partial_mask = (((ACTIVE_MAP_t)1 << NUM_DIFF_OF_PARTIAL_DIFFUSION) - 1);
					for (partial_idx = num_ongoing_partition; partial_idx < NUM_PARTION_OF_DIFF_IN_A_STATE; partial_idx++)
					{
						ACTIVE_MAP_t this_partition;
						this_partition = A & (partial_mask << (partial_idx * NUM_DIFF_OF_PARTIAL_DIFFUSION));

						//estimate next round active using branch number
						if (this_partition != 0)
						{
							estimated_next_round_num_active+=1;
						}
					}
					POW_MAX_CORR(&active_corr, estimated_next_round_num_active);
					MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, active_corr);

				}
			}
		}

	}
	else if ((DIFFUSION_TYPE == PARTIAL_BINARY_MATRIX) || (DIFFUSION_TYPE == PARTIAL_NON_BINARY_MATRIX))
	{
		if ((i != 1) || (ENABLE_1ROUND_ACTIVE_MAPS == TRUE))
		{
			//check if every word is determined already.
			if (num_det_partition != NUM_PARTION_OF_DIFF_IN_A_STATE)
			{
				NUM_t estimated_next_round_num_active = 0;
				CNT_t partial_idx;
				CORR_t active_corr;
				ACTIVE_MAP_t partial_mask = (((ACTIVE_MAP_t)1 << NUM_DIFF_OF_PARTIAL_DIFFUSION) - 1);
				for (partial_idx = num_det_partition; partial_idx < NUM_PARTION_OF_DIFF_IN_A_STATE; partial_idx++)
				{
					ACTIVE_MAP_t this_partition;
					NUM_t num_active_of_this_partition;
					NUM_t min_num_active_of_next_partition;
					this_partition = A & (partial_mask << (partial_idx * NUM_DIFF_OF_PARTIAL_DIFFUSION));
					num_active_of_this_partition = get_word_hw(this_partition);

					//estimate next round active using branch number
					if (num_active_of_this_partition == 0)
					{
						min_num_active_of_next_partition = 0;
					}
					else if (BRANCH_NUM - num_active_of_this_partition >= 0)
					{
						min_num_active_of_next_partition = BRANCH_NUM - num_active_of_this_partition;
					}
					else
					{
						min_num_active_of_next_partition = 1; //Look! Here is at least one active
					}
					estimated_next_round_num_active += min_num_active_of_next_partition;
				}
				POW_MAX_CORR(&active_corr, estimated_next_round_num_active);
				MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, active_corr);

			}
		}
	}
	else //FULL_BINARY_MATRIX or FULL_NON_BINARY_MATRIX
	{
		if ((i != 1) || (ENABLE_1ROUND_ACTIVE_MAPS == TRUE))
		{
			NUM_t estimated_next_round_num_active = 0;
			NUM_t num_active_of_this_round;
			CORR_t active_corr;

			num_active_of_this_round = get_word_hw(A);

			if (BRANCH_NUM - num_active_of_this_round >= 0)
			{
				estimated_next_round_num_active = BRANCH_NUM - num_active_of_this_round;
			}
			else if (num_active_of_this_round != 0)
			{
				estimated_next_round_num_active = 1; //Look! Here is at least one active
			}
			//else => active word does not exist

			POW_MAX_CORR(&active_corr, estimated_next_round_num_active);
			MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, active_corr);
		}
	}
	*pred = estimated_next_round_corr;
	return j_nxt;
}
#elif defined PRE_PC2

static DEV_INLINE CNT_t Corr_Next_Round_Lower_Bound(CORR_t * pred, CNT_t i, CNT_t j, SBOX_O_WRD_t * sout, ACTIVE_MAP_t A)
{
	CORR_t estimated_next_round_corr = ONE_CORR;
	DIFF_I_WRD_t  i_round_state_till_j_word[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
	DIFF_O_WRD_t  iplus1_round_partial_in[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
	ACTIVE_MAP_t  estimated_iplus1_round_active_map;
	CNT_t		  num_det_word;
	//CNT_t		  num_det_partition;
	CNT_t		  j_nxt;

	if ((i != 1) || (ENABLE_1ROUND_ACTIVE_MAPS == TRUE))
	{
		j_nxt = Next_Active_Word(j, A, NUM_SBOX_IN_A_STATE);
	}
	else
	{
		//get next active_word
		if (j == (NUM_SBOX_IN_A_STATE - 1))
		{
			//go to next round
			j_nxt = THIS_IS_THE_LAST;
		}
		else
		{
			//go to next word
			j_nxt = j + 1;
		}
	}


	if (j == BEFORE_STARTING_THE_ROUND)
	{
		num_det_word = 0;
	}
	else
	{

		if (j_nxt == THIS_IS_THE_LAST)
		{
			num_det_word = NUM_DIFF_IN_A_STATE;
		}
		else
		{
			num_det_word = j_nxt;
		}
	}

	if (DIFFUSION_TYPE == BIT_PERMUTATION)
	{
		CNT_t  num_active;
		CORR_t active_corr;

		/*With repect to estimated part*/
		/*init i_round_state_till_j_word already*/
		memcpy(i_round_state_till_j_word, sout, sizeof(DIFF_I_WRD_t)*((size_t)num_det_word));
		/*Estimated Part from Partial Determined Values*/
		Inv_Trans_Diffusion(iplus1_round_partial_in, i_round_state_till_j_word);
		estimated_iplus1_round_active_map = Compute_Active_Map_From_State(iplus1_round_partial_in, NUM_SBOX_IN_A_STATE);
		num_active = (CNT_t)get_word_hw(estimated_iplus1_round_active_map);
		POW_CORR(&active_corr, MAX_CORR_FOR_WHOLE_SBOXES, num_active);
		MUL_CORR(&estimated_next_round_corr, estimated_next_round_corr, active_corr);
	}
	*pred = estimated_next_round_corr;
	return j_nxt;
}
#endif





/*	Attention
*   1) set_round < target_round
*	2) set_round <= round of which we know best bound.
*/
void SPN_Best_LC_Corr_Search(CORR_t * corr_rst, BLK_CIPHER_INFO_t * ci, CNT_t set_round, CNT_t target_round, UFLAG_t verbose)
{
	CNT_t round_idx;


	/*general information*/
	strcpy(ALG_NAME, ci->alg_name);
	NUM_SBOX_IN_A_STATE		= ci->num_word_in_a_state;
	NUM_DIFF_IN_A_STATE		= ci->num_word_in_a_state;
	SBOX_I_WORD_BIT_SIZE	= ci->sbox_i_word_bit_size;
	SBOX_O_WORD_BIT_SIZE	= ci->sbox_o_word_bit_size;
	SBOX_I_CARDINALITY		= 1 << SBOX_I_WORD_BIT_SIZE;
	SBOX_O_CARDINALITY		= 1 << SBOX_O_WORD_BIT_SIZE;
	Inv_Trans_Diffusion		= ci->Inv_Trans_Diffusion;
	Trans_Diffusion			= ci->Trans_Diffusion;
	Set_Known_Corr_Bound	= ci->Set_Known_Corr_Bound;
	ENABLE_1ROUND_ACTIVE_MAPS		= TRUE;//ci->searching_start_opt->enable_1round_active_map;
	DIFFUSION_TYPE					= ci->diffusion_info;
	NUM_DIFF_OF_PARTIAL_DIFFUSION	= ci->diffusion_bound_opt->num_diff_of_partial_diffusion;
	NUM_PARTION_OF_DIFF_IN_A_STATE	= NUM_DIFF_IN_A_STATE / NUM_DIFF_OF_PARTIAL_DIFFUSION;
	BRANCH_NUM						= ci->diffusion_bound_opt->inv_trans_diff_branch_num;
	ENABLE_SET_INITIAL_BOUND		= ci->set_initial_bound_opt->enable_set_initial_corr_bound;
	EACH_ROUND_INTIAL_CORR_BOUND	= ci->set_initial_bound_opt->each_round_initial_corr_bound;
	CORR_INTERVAL			= ci->set_initial_bound_opt->corr_interval;
	DISTINCT_SBOX			= ci->distinct_sbox;
	VERBOSE					= verbose;
	WHOLE_TARGET_ROUND		= target_round;
	/***********************************************************************/

	if (Verbose_Check(VERBOSE, VV_PROGRESS) == TRUE)
	{
		printf("=================SPN_Best_Linear_Trail_Search=================\n\n");
	}

	LC_BOUNDS[1] = LC_1ROUND_MAX_CORR;

	if (Set_Known_Corr_Bound != NULL)
	{
		Set_Known_Corr_Bound(LC_BOUNDS);
	}

	//Set the bounds till rounds which we want
	for (round_idx = 1; round_idx <= (CNT_t)max(set_round, 1); round_idx++)
	{
		if (Verbose_Check(VERBOSE, VV_PROGRESS) == TRUE)
		{
			if (LC_BOUNDS[round_idx].sign == POSI)
			{
				printf("==Set   [%2d]-Round Bound with the Known Correlation +2^{%0.4lf}\n\n", round_idx, LC_BOUNDS[round_idx].magnitude);
			}
			else
			{
				printf("==Set   [%2d]-Round Bound with the Known Correlation -2^{%0.4lf}\n\n", round_idx, LC_BOUNDS[round_idx].magnitude);
			}
		}
	}


	//Start searching
	for (round_idx = max(set_round, 1) + 1; round_idx <= target_round; round_idx++)
	{
		FLAG_t first_trial_flag;

		first_trial_flag = TRUE;
		DONE_FLAG = FALSE;

		while (DONE_FLAG != TRUE)
		{
			if (ENABLE_SET_INITIAL_BOUND == TRUE)
			{
				//Set the initial bound
				if (first_trial_flag == TRUE)
				{
					first_trial_flag = FALSE;
					START_CLK = clock();
					START_TIME = time(NULL);
					LC_BOUND_IN_PROGRESS = EACH_ROUND_INTIAL_CORR_BOUND[round_idx];
				}
				else //Set next bound using CORR_INTERVAL
				{
					MUL_CORR(&LC_BOUND_IN_PROGRESS, LC_BOUND_IN_PROGRESS, CORR_INTERVAL);
				}
			}
			else
			{
				//Set the initial bound : MAX_CORR_FOR_WHOLE_SBOXES * Before Round bound
				if (first_trial_flag == TRUE)
				{
					first_trial_flag = FALSE;
					START_CLK = clock();
					START_TIME = time(NULL);
					MUL_CORR(&LC_BOUND_IN_PROGRESS, LC_BOUNDS[round_idx - 1], MAX_CORR_FOR_WHOLE_SBOXES);
				} //Set next bound using MIN_CORR_FOR_WHOLE_SBOXES
				else
				{
					MUL_CORR(&LC_BOUND_IN_PROGRESS, LC_BOUND_IN_PROGRESS, MIN_CORR_FOR_WHOLE_SBOXES);
				}
			}
			//END : Set bound --> LC_BOUND_IN_PROGRESS

			if (Verbose_Check(VERBOSE, VV_ACTIVE_MAP_PROGRESS|VV_PROGRESS) == TRUE)
			{
				struct tm * local;
				CHECK_CLK = clock();
				CHECK_TIME = time(NULL);
				local = localtime(&CHECK_TIME);
				if (LC_BOUND_IN_PROGRESS.sign == POSI)
				{
					printf("==Start [%2d]-Round With Bound +2^{%0.4lf}[previous takes %lld secs(%0.4lf secs)]", round_idx, LC_BOUND_IN_PROGRESS.magnitude, CHECK_TIME - START_TIME, (double)(CHECK_CLK - START_CLK) / CLOCKS_PER_SEC);
				}
				else
				{
					printf("==Start [%2d]-Round With Bound -2^{%0.4lf}[previous takes %lld secs(%0.4lf secs)]", round_idx, LC_BOUND_IN_PROGRESS.magnitude, CHECK_TIME - START_TIME, (double)(CHECK_CLK - START_CLK) / CLOCKS_PER_SEC);
				}
				printf("(%4d/%02d/%02d %02d:%02d)==\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min);
			}

			//CORE
			CUR_TARGET_ROUND = round_idx;
			SPN_Best_Lin_FirstRound();

		}//EACH ROUND FINISHES

		LC_BOUNDS[round_idx] = LC_BOUND_IN_PROGRESS;

		if (Verbose_Check(VERBOSE, VV_ACTIVE_MAP_PROGRESS|VV_PROGRESS|VV_LAST_UPDATE_TRAIL) == TRUE)
		{
			CHECK_CLK = clock();
			CHECK_TIME = time(NULL);
			if (LC_BOUNDS[round_idx].sign == POSI)
			{
				printf("==End   [%2d]-Round With Bound +2^{%0.4lf}[takes %lld secs(%0.4lf secs)]==\n", round_idx, LC_BOUNDS[round_idx].magnitude, CHECK_TIME - START_TIME, (double)(CHECK_CLK - START_CLK) / CLOCKS_PER_SEC);
			}
			else
			{
				printf("==End   [%2d]-Round With Bound -2^{%0.4lf}[takes %lld secs(%0.4lf secs)]==\n", round_idx, LC_BOUNDS[round_idx].magnitude, CHECK_TIME - START_TIME, (double)(CHECK_CLK - START_CLK) / CLOCKS_PER_SEC);
			}
		}

		if (Verbose_Check(VERBOSE, VV_LAST_UPDATE_TRAIL) == TRUE)
		{
			Print_LC_Trail(LC_TRAIL_FOR_OUT, round_idx, SBOX_I_WORD_BIT_SIZE, SBOX_O_WORD_BIT_SIZE, NUM_SBOX_IN_A_STATE);
		}

		if (Verbose_Check(VERBOSE, VV_FILE_PRINT) == TRUE)
		{
			char filename[256];
			sprintf(filename, "%s_Best_Linear_Trail_%dR.txt", ALG_NAME, round_idx);
			FPrint_LC_Trail(filename, LC_TRAIL_FOR_OUT, round_idx, SBOX_I_WORD_BIT_SIZE, SBOX_O_WORD_BIT_SIZE, NUM_SBOX_IN_A_STATE);
		}

		if (Verbose_Check(VERBOSE, VV_ROUND_PROGRESS) == TRUE)
		{
			printf("Progress %-3d /Target %-3d\r", round_idx, WHOLE_TARGET_ROUND);
		}


		if (Verbose_Check(VERBOSE, VV_ACTIVE_MAP_PROGRESS|VV_PROGRESS) == TRUE)
		{
			if (round_idx == target_round)
			{
				printf("Everything's done             \n");
			}
		}

	}//EVERY ROUND FINISHES

	if (Verbose_Check(VERBOSE, VV_LAST_RESULT) == TRUE)
	{
		printf("===================================================================\n\n");
		printf("==   The Best Correlation of Each Round Linear Trail  ==\n");
		for (round_idx = 1; round_idx <= target_round; round_idx++)
		{
			if (LC_BOUNDS[round_idx].sign == POSI)
			{
				printf("==   [%2d]-Round Best Linear Correlation : +2^{%0.4lf}\n", round_idx, LC_BOUNDS[round_idx].magnitude);
			}
			else
			{
				printf("==   [%2d]-Round Best Linear Correlation : +2^{%0.4lf}\n", round_idx, LC_BOUNDS[round_idx].magnitude);
			}
		}
	}

	for (round_idx = 1; round_idx <= target_round; round_idx++)
	{
		corr_rst[round_idx - 1] = LC_BOUNDS[round_idx];
	}
}


#define UNDER_BOUND		((FLAG_t)1)
#define EXCEED_BOUND	((FLAG_t)-1)

static DEV_INLINE FLAG_t Corr_Bound_Checker(CNT_t ri, CORR_t cur)
{
	CORR_t check;
	if (ri == CUR_TARGET_ROUND)
		check = cur;
	else
		MUL_CORR(&check, LC_BOUNDS[CUR_TARGET_ROUND - ri], cur);

	if (TOUCH_THE_LEAF_FLAG == TRUE)
	{
		if (COMP_CORR(check, LC_BOUND_IN_PROGRESS) != LEFT)
			return EXCEED_BOUND;

		else
			return UNDER_BOUND;
	}
	else
	{
		if (COMP_CORR(check, LC_BOUND_IN_PROGRESS) == RIGHT)
			return EXCEED_BOUND;
		else
			return UNDER_BOUND;
	}
}


void SPN_Best_Lin_FirstRound(void)
{
	CNT_t  j_init;
	CORR_t W_init;

	ACTIVE_MAP_t A;
	CNT_t		HA;
	CORR_t      Wnxt;
	CORR_t		Wpred1, Wpred2;

	TOUCH_THE_LEAF_FLAG = FALSE;

	if (CONSTRUCT_1ROUND_ACTIVE_MAPS == FALSE)
	{
		CNT_t	idx_active_map;
		NUM_t   hw = 0;

		//Note that : This loop may determine the whole search complexity.
		for (idx_active_map = 0; idx_active_map < NUM_1ROUND_ACTIVE_MAPS; idx_active_map++)
		{
			//Set 1-round active_map
			A = _1ROUND_ACTIVE_MAPS[idx_active_map];

			//Pruning (PC-1)
			HA = Num_Active_Word(BEFORE_STARTING_THE_ROUND, A, NUM_SBOX_IN_A_STATE);
			POW_MAX_CORR(&Wpred1, HA);
			if (Corr_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
				break; //We do not have to check other active maps which have more than(and equal to) the current number of active S-box

			//Pruning (PC-2)
			j_init = Corr_Next_Round_Lower_Bound(&Wnxt, 1, BEFORE_STARTING_THE_ROUND, NULL, A);
			MUL_CORR(&Wpred2, Wpred1, Wnxt);
			if (Corr_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
				continue; //Try other active maps


			//init the input/output states and correlations
			memset(LC_TRAIL_IN_PROGRESS[1].sub_i, 0, sizeof(SBOX_I_WRD_t)*(size_t)NUM_SBOX_IN_A_STATE);
			memset(LC_TRAIL_IN_PROGRESS[1].sub_o, 0, sizeof(SBOX_O_WRD_t)*(size_t)NUM_SBOX_IN_A_STATE);
			Set_Corrs_One(LC_TRAIL_IN_PROGRESS[1].c, NUM_SBOX_IN_A_STATE);

			W_init = ONE_CORR;

			if (Verbose_Check(VERBOSE, VV_ACTIVE_MAP_PROGRESS) == TRUE)
			{
				NUM_t now_hw = (NUM_t)get_word_hw((uint32_t)_1ROUND_ACTIVE_MAPS[idx_active_map]);
				if (hw != now_hw)
				{
					hw = now_hw;
					printf("Current %-3d(%-4d/%-4d)/Target %-3d\r", CUR_TARGET_ROUND, hw, NUM_SBOX_IN_A_STATE, WHOLE_TARGET_ROUND);
				}
			}

			SPN_Best_Lin_FirstSubRound(j_init, A, W_init);
		}
	}
	else//(CONSTRUCT_1ROUND_ACTIVE_MAPS == TRUE)
	{
		CNT_t idx_hw;
		for (idx_hw = 1; idx_hw <= NUM_SBOX_IN_A_STATE; idx_hw++)
		{
			FLAG_t last_flag;

			//Pruning (PC-1)
			POW_MAX_CORR(&Wpred1, idx_hw);
			if (Corr_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
			{
				break; //We do not have to check other active maps which have more than(and equal to) the current number of active S-box
			}


			Init_1Round_Active_Map(idx_hw);
			do
			{
				//Set 1-round activity pattern
				last_flag = Next_1Round_Active_Map(&A);

				//Pruning (PC-2)
				j_init = Corr_Next_Round_Lower_Bound(&Wnxt, 1, BEFORE_STARTING_THE_ROUND, NULL, A);
				MUL_CORR(&Wpred2, Wpred1, Wnxt);
				if (Corr_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
					continue; //Try other active patterns

				//init the input/output states and correlations
				memset(LC_TRAIL_IN_PROGRESS[1].sub_i, 0, sizeof(SBOX_I_WRD_t)*(size_t)NUM_SBOX_IN_A_STATE);
				memset(LC_TRAIL_IN_PROGRESS[1].sub_o, 0, sizeof(SBOX_O_WRD_t)*(size_t)NUM_SBOX_IN_A_STATE);
				Set_Corrs_One(LC_TRAIL_IN_PROGRESS[1].c, NUM_SBOX_IN_A_STATE);

				W_init = ONE_CORR;

				if (Verbose_Check(VERBOSE, VV_ROUND_PROGRESS | VV_ACTIVE_MAP_PROGRESS) == TRUE)
				{
					printf("Current %-3d(%-4d/%-4d)/Target %-3d\r", CUR_TARGET_ROUND, idx_hw, NUM_SBOX_IN_A_STATE, WHOLE_TARGET_ROUND);
				}

				SPN_Best_Lin_FirstSubRound(j_init, A, W_init);

			} while (last_flag == THIS_IS_NOT_THE_LAST);

		}
	}
}

void SPN_Best_Lin_FirstSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef)
{
	SBOX_O_CNT_t _1_j;
	SBOX_I_WRD_t * X1_j = &(LC_TRAIL_IN_PROGRESS[1].sub_i[j]);
	SBOX_O_WRD_t * Y1_j = &(LC_TRAIL_IN_PROGRESS[1].sub_o[j]);
	CORR_t		 * C1_j = &(LC_TRAIL_IN_PROGRESS[1].c[j]);
	CNT_t		 Hrm;
	CORR_t		 Wdet, Wnxt;
	CORR_t		 Wpred1rm, Wpred1, Wpred2;
	CNT_t		 j_nxt;

	Hrm = Num_Active_Word(j, A, NUM_SBOX_IN_A_STATE);
	POW_MAX_CORR(&Wpred1rm, Hrm);
	MUL_CORR(&Wpred1rm, Wbef, Wpred1rm);


	for (_1_j = 0; _1_j < SBOX_O_CARDINALITY; _1_j++)
	{
		*Y1_j = LC_SBOXES_I_O_CORR_FIXED_O[j][_1_j].o;
		//It is always active!
		if (*Y1_j == (SBOX_O_WRD_t)0)
		{
			continue;
		}
		*C1_j = LC_SBOXES_I_O_CORR_FIXED_O[j][_1_j].c;

		//Pruning (PC-1)
		MUL_CORR(&Wpred1, Wpred1rm, *C1_j);
		if (Corr_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
			break;

		//Pruning (PC-2)
		j_nxt = Corr_Next_Round_Lower_Bound(&Wnxt, 1, j, LC_TRAIL_IN_PROGRESS[1].sub_o, A);
		MUL_CORR(&Wpred2, Wpred1, Wnxt);
		if (Corr_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
			continue; //Try other out value

		//store the current input word
		*X1_j = LC_SBOXES_I_O_CORR_FIXED_O[j][_1_j].i;

		MUL_CORR(&Wdet, Wbef, *C1_j);

		if (j_nxt != THIS_IS_THE_LAST) //when this word is not the last word
		{
			//Move to next word
			SPN_Best_Lin_FirstSubRound(j_nxt, A, Wdet);
		}
		else //when this word is the last word
		{
			CORR_t RWdet = Wdet;
			//Move to next round
			if (CUR_TARGET_ROUND == 2)
			{
				//Move to the last round
				SPN_Best_Lin_LastRound(RWdet);
			}
			else
			{
				//Move to next(2) round
				SPN_Best_Lin_MiddleRound(2, RWdet);
			}
		}
	}
}


void SPN_Best_Lin_MiddleRound(CNT_t i, CORR_t RWbef)
{
	CNT_t  j_init;
	CORR_t W_init;

	ACTIVE_MAP_t A;
	CORR_t       Wall, Wnxt;
	CORR_t       Wpred1, Wpred2;
	

	Inv_Trans_Diffusion(LC_TRAIL_IN_PROGRESS[i].sub_i, LC_TRAIL_IN_PROGRESS[i - 1].sub_o);
	A = Compute_Active_Map_From_State(LC_TRAIL_IN_PROGRESS[i].sub_i, NUM_SBOX_IN_A_STATE);

	//Pruning (PC-1)
	Corr_Fill_Undertermined(&Wall, BEFORE_STARTING_THE_ROUND, LC_TRAIL_IN_PROGRESS[i].sub_i, A);
	MUL_CORR(&Wpred1, RWbef, Wall);
	if (Corr_Bound_Checker(i, Wpred1) == EXCEED_BOUND)
		return; //We do not have to check the input sate which has more than(and equal to) the current number of active S-box


	//Pruning (PC-2)
	j_init = Corr_Next_Round_Lower_Bound(&Wnxt, i, BEFORE_STARTING_THE_ROUND, NULL, A);
	MUL_CORR(&Wpred2, Wpred1, Wnxt);
	if (Corr_Bound_Checker(i + 1, Wpred2) == EXCEED_BOUND)
		return;


	//init the input/output states and correlation
	memset(LC_TRAIL_IN_PROGRESS[i].sub_o, 0, sizeof(SBOX_O_WRD_t)*(size_t)NUM_SBOX_IN_A_STATE);
	Set_Corrs_One(LC_TRAIL_IN_PROGRESS[i].c, NUM_SBOX_IN_A_STATE);

	W_init = RWbef;

	SPN_Best_Lin_MiddleSubRound(i, j_init, A, W_init);
}

void SPN_Best_Lin_MiddleSubRound(CNT_t i, CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef)
{
	SBOX_I_CNT_t _i_j;
	SBOX_I_WRD_t Xi_j = LC_TRAIL_IN_PROGRESS[i].sub_i[j]; //This word is fixed from before state
	SBOX_O_WRD_t * Yi_j = &(LC_TRAIL_IN_PROGRESS[i].sub_o[j]);
	CORR_t	     * Ci_j = &(LC_TRAIL_IN_PROGRESS[i].c[j]);
	CORR_t		 Wdet, Wnxt;
	CORR_t		 Wpred1rm, Wpred1, Wpred2;
	CNT_t		 j_nxt;

	Corr_Fill_Undertermined(&Wpred1rm, j, LC_TRAIL_IN_PROGRESS[i].sub_i, A);
	MUL_CORR(&Wpred1rm, Wbef, Wpred1rm);

	for (_i_j = 0; _i_j < NUM_O_WITH_NONZERO_CORR[j][Xi_j]; _i_j++)
	{
		*Ci_j = LC_SBOXES_O_CORR_FIXED_I[j][Xi_j][_i_j].c;
		
		//Pruning (PC-1)
		MUL_CORR(&Wpred1, Wpred1rm, *Ci_j);
		if (Corr_Bound_Checker(i, Wpred1) == EXCEED_BOUND)
			break;

		//store the current out word
		*Yi_j = LC_SBOXES_O_CORR_FIXED_I[j][Xi_j][_i_j].o;

		//Pruning (PC-2)
		j_nxt = Corr_Next_Round_Lower_Bound(&Wnxt, i, j, LC_TRAIL_IN_PROGRESS[i].sub_o, A);
		MUL_CORR(&Wpred2, Wpred1, Wnxt);
		if (Corr_Bound_Checker(i + 1, Wpred2) == EXCEED_BOUND)
			continue; //Try other out value

		MUL_CORR(&Wdet, Wbef, *Ci_j);
		if (j_nxt != THIS_IS_THE_LAST)  //when this word is not the last word
		{
			//Move to next word
			SPN_Best_Lin_MiddleSubRound(i, j_nxt, A, Wdet);
		}
		else //when this word is the last word
		{
			CORR_t RWdet = Wdet;
			//Move to next round
			if (i == CUR_TARGET_ROUND - 1)
			{
				SPN_Best_Lin_LastRound(RWdet);
			}
			else//if (i < CUR_TARGET_ROUND - 1)
			{
				SPN_Best_Lin_MiddleRound(i + 1, RWdet);
			}
		}
	}
}


void SPN_Best_Lin_LastRound(CORR_t RWbef)
{
	CNT_t  j_init;
	CORR_t W_init;

	ACTIVE_MAP_t A;
	CORR_t       Wall;
	CORR_t		 Wpred1;


	Inv_Trans_Diffusion(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i, LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND - 1].sub_o);
	A = Compute_Active_Map_From_State(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i, NUM_SBOX_IN_A_STATE);

	//Pruning (PC-1)
	Corr_Fill_Undertermined(&Wall, BEFORE_STARTING_THE_ROUND, LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i, A);
	MUL_CORR(&Wpred1, RWbef, Wall);
	if (Corr_Bound_Checker(CUR_TARGET_ROUND, Wpred1) == EXCEED_BOUND)
		return; //We do not have to check the input sate which has more than(and equal to) the current number of active S-box

	//init the input/output states and correlations
	memset(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_o, 0, sizeof(SBOX_O_WRD_t)*(size_t)NUM_SBOX_IN_A_STATE);
	Set_Corrs_One(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].c, NUM_SBOX_IN_A_STATE);


	W_init = RWbef;
	j_init = Next_Active_Word(BEFORE_STARTING_THE_ROUND, A, NUM_SBOX_IN_A_STATE);

	SPN_Best_Lin_LastSubRound(j_init, A, W_init);
}

void SPN_Best_Lin_LastSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef)
{
	SBOX_I_WRD_t Xn_j = LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i[j]; //This word is fixed from before state
	SBOX_O_WRD_t *Yn_j = &(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_o[j]);
	CORR_t		 *Cn_j = &(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].c[j]);
	CORR_t		 Wdet, Wrm;
	CORR_t       Wpred1;
	CNT_t		 j_nxt;

	*Cn_j = LC_SBOXES_O_CORR_FIXED_I[j][Xn_j][0].c; //max corr with fixed in
	MUL_CORR(&Wdet, Wbef, *Cn_j);

	//Pruning (PC-1)
	Corr_Fill_Undertermined(&Wrm, j, LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i, A);
	MUL_CORR(&Wpred1, Wdet, Wrm);
	if (Corr_Bound_Checker(CUR_TARGET_ROUND, Wpred1) == EXCEED_BOUND)
		return; 

	//store the current out word
	*Yn_j = LC_SBOXES_O_CORR_FIXED_I[j][Xn_j][0].o;

	//get next active_word
	j_nxt = Next_Active_Word(j, A, NUM_SBOX_IN_A_STATE);

	if (j_nxt != THIS_IS_THE_LAST) //when this word is not the last word  
	{
		//Move to next word
		SPN_Best_Lin_LastSubRound(j_nxt, A, Wdet);
	}
	else //when this word is the last word
	{
		TOUCH_THE_LEAF_FLAG = TRUE;
		DONE_FLAG = TRUE;

		//update Progress bound
		LC_BOUND_IN_PROGRESS = Wdet;


		//print
		if (Verbose_Check(VERBOSE, VV_UPDATE_BOUND | VV_UPDATE_BOUND_TRAIL) == TRUE)
		{
			CHECK_CLK = clock();
			CHECK_TIME = time(NULL);
			printf("--New Bound!! 2^{%0.4lf}[takes %lld secs(%0.4lf secs)]\n", LC_BOUND_IN_PROGRESS.magnitude, CHECK_TIME - START_TIME, (double)(CHECK_CLK - START_CLK) / CLOCKS_PER_SEC);
		}

		if (Verbose_Check(VERBOSE, VV_UPDATE_BOUND_TRAIL) == TRUE)
		{
			CNT_t __FF__;
			for (__FF__ = 1; __FF__ <= CUR_TARGET_ROUND; __FF__++)
			{
				Inv_Trans_Diffusion(LC_TRAIL_IN_PROGRESS[__FF__].dif_o, LC_TRAIL_IN_PROGRESS[__FF__].sub_o);
			}
			Print_LC_Trail(LC_TRAIL_IN_PROGRESS, CUR_TARGET_ROUND, SBOX_I_WORD_BIT_SIZE, SBOX_O_WORD_BIT_SIZE, NUM_SBOX_IN_A_STATE);
		}

		if (Verbose_Check(VERBOSE, VV_FILE_PRINT | VV_LAST_UPDATE_TRAIL) == TRUE)
		{
			CNT_t __FF__;
			Copy_LC_Trail(LC_TRAIL_FOR_OUT, LC_TRAIL_IN_PROGRESS, CUR_TARGET_ROUND, NUM_SBOX_IN_A_STATE);

			for (__FF__ = 1; __FF__ <= CUR_TARGET_ROUND; __FF__++)
			{
				Inv_Trans_Diffusion(LC_TRAIL_FOR_OUT[__FF__].dif_o, LC_TRAIL_FOR_OUT[__FF__].sub_o);
			}
		}
	}
}