#include "astbb.h"
#include "dif_prob.h"
#include "active_map.h"
#include "printout.h"
#include "bogi_common_info.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

//declared in prep_dc.c
extern DC_I_O_PROB_t		DC_SBOX_I_O_PROB[SBOX_IO_CARDINALITY];
extern NUM_t				NUM_I_O_WITH_NONZERO_PROB;
extern NUM_t				NUM_I_O_WITH_MAX_PROB;

extern DC_O_PROB_t			DC_SBOX_O_PROB_FIXED_I[SBOX_I_CARDINALITY][SBOX_O_CARDINALITY];
extern CNT_t				NUM_O_WITH_NONZERO_PROB[SBOX_I_CARDINALITY];
extern CNT_t				NUM_O_WITH_MAX_PROB[SBOX_I_CARDINALITY];

extern DC_I_PROB_t			DC_SBOX_I_PROB_FIXED_O[SBOX_O_CARDINALITY][SBOX_I_CARDINALITY];
extern CNT_t				NUM_I_WITH_NONZERO_PROB[SBOX_O_CARDINALITY];
extern CNT_t				NUM_I_WITH_MAX_PROB[SBOX_O_CARDINALITY];

extern DC_I_O_PROB_t		DC_SBOX_I_O_PROB_FIXED_O[SBOX_O_CARDINALITY]; //this table is very special!
extern PROB_t				DC_1ROUND_MAX_PROB;
extern PROB_t				MAX_PROB_FOR_SBOX;
extern PROB_t				MIN_PROB_FOR_SBOX;

extern PROB_t				DC_BOUNDS[NUM_ROUND_THRESHOLD + 1]; //for convenience, the first element is always 0 and is not used
extern DC_1ROUND_CHAR_t		DC_TRAIL_IN_PROGRESS[NUM_ROUND_THRESHOLD + 1]; //for convenience, the first element is never used
extern DC_1ROUND_CHAR_t		DC_TRAIL_FOR_OUT[NUM_ROUND_THRESHOLD + 1]; //for convenience, the first element is never used


/*Variables only for the current c code region*/
static FLAG_t DONE_FLAG = FALSE;
static FLAG_t TOUCH_THE_LEAF_FLAG = FALSE;
static PROB_t DC_BOUND_IN_PROGRESS;
static SBOX_t ZERO_INPUT_STATE[NUM_SBOX_IN_A_STATE] = { 0, };
static NUM_t CUR_TARGET_ROUND;
static NUM_t WHOLE_TARGET_ROUND;
/***********************************************/


void SPN_Best_Dif_FirstRound(void);
void SPN_Best_Dif_FirstSubRound(CNT_t j, ACTIVE_MAP_t A, PROB_t Wbef, PROB_t Wbef_nxt);
void SPN_Best_Dif_MiddleRound(CNT_t i, PROB_t RWbef);
void SPN_Best_Dif_MiddleSubRound(CNT_t i, CNT_t j, ACTIVE_MAP_t A, PROB_t Wbef, PROB_t Wbef_nxt);
void SPN_Best_Dif_LastRound(PROB_t RWbef);
void SPN_Best_Dif_LastSubRound(CNT_t j, ACTIVE_MAP_t A, PROB_t Wbef);


static DEV_INLINE void Prob_Fill_Undertermined(PROB_t * pred, CNT_t j, SBOX_t * sin)
{
	CNT_t	sbox_idx;
	/*condition*/
	// 1) i > 2
	// 2) thus, sin is determined already

	*pred = ONE_PROB;
	//We should check the input value
	for (sbox_idx = j + 1; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		if (sin[sbox_idx] != 0) //When it is not zero difference
		{
			//Multiple the maximum probability with the non-zero estimated input difference word.
			MUL_PROB(pred, *pred, DC_SBOX_O_PROB_FIXED_I[sin[sbox_idx]][0].p);
		}
	}
}


static DEV_INLINE CNT_t Prob_Next_Round_Lower_Bound_Bf_Starting_Round(PROB_t * pred, ACTIVE_MAP_t A)
{
	int   widx;
	CNT_t j_nxt;
	CNT_t pred_nxt_num_act = 0;

	//The First Arive S-box Location
	j_nxt = Next_Active_Word(BEFORE_STARTING_THE_ROUND, A);

	for (widx = 0; widx < NUM_PARTION_OF_DIFF_IN_A_STATE; widx++)
	{
		if ((A & (ACTIVE_MAP_t)0xf) != 0)
		{
			pred_nxt_num_act++; //At least one of S-boxes in the current Pmix output is active
		}
		A = (A >> NUM_DIFF_OF_PARTIAL_DIFFUSION);
	}

	POW_MAX_PROB(pred, pred_nxt_num_act);

	return j_nxt;
}

static DEV_INLINE void Prob_Next_Round_Lower_Bound_Rem(PROB_t * pred_rem, CNT_t pmix_loc, CNT_t pmix_loc_nxt, ACTIVE_MAP_t A)
{
	int   widx;
	CNT_t rem_act = 0;
	CNT_t rem_pmix_start_loc;
	
	//NOTE : pmix_loc_nxt < NUM_PARTION_OF_DIFF_IN_A_STATE
	//In the Same Pmix
	if (pmix_loc == pmix_loc_nxt)
	{
		//Then From next
		rem_pmix_start_loc = pmix_loc_nxt + 1;
	}
	else
	{
		//Then From pmix_loc_nxt
		rem_pmix_start_loc = pmix_loc_nxt;
	}

	A = A >> ((NUM_DIFF_OF_PARTIAL_DIFFUSION) * (rem_pmix_start_loc));
	for (widx = rem_pmix_start_loc; widx < NUM_PARTION_OF_DIFF_IN_A_STATE; widx++)
	{
		if ((A & (ACTIVE_MAP_t)((1 << NUM_DIFF_OF_PARTIAL_DIFFUSION) - 1)) != 0)
		{
			rem_act++; //At least one of S-boxes in the current Pmix output is active
		}
		A = (A >> NUM_DIFF_OF_PARTIAL_DIFFUSION);
	}
	POW_MAX_PROB(pred_rem, rem_act);
}




static DEV_INLINE void Prob_Next_Round_Lower_Bound(PROB_t * pred_cur, SBOX_t * psh_i, CNT_t pmix_loc, CNT_t pmix_loc_nxt)
{
	int   widx;

	if (pmix_loc < pmix_loc_nxt)
	{
		*pred_cur = ONE_PROB;
		//Current Pmix is Determined
		//Then, We check each fixed input word has the maximum
		for (widx = 0; widx < NUM_DIFF_OF_PARTIAL_DIFFUSION; widx++)
		{
			if (psh_i[widx] != 0)
			{
				MUL_PROB(pred_cur, *pred_cur, DC_SBOX_O_PROB_FIXED_I[psh_i[widx]][0].p);
			}
		}
	}
	else
	{
		CNT_t cur_act = 0;
		//Current Pmix is NOT Determined yet.
		for (widx = 0; widx < NUM_DIFF_OF_PARTIAL_DIFFUSION; widx++)
		{
			if (psh_i[widx] != 0)
			{
				cur_act++;
			}
		}
		POW_MAX_PROB(pred_cur, cur_act);
	}
}


#define UNDER_BOUND		((FLAG_t)1)
#define EXCEED_BOUND	((FLAG_t)-1)

static DEV_INLINE FLAG_t Prob_Bound_Checker(CNT_t ri, PROB_t cur)
{
	PROB_t check;
	if (ri == CUR_TARGET_ROUND)
		check = cur;
	else
		MUL_PROB(&check, DC_BOUNDS[CUR_TARGET_ROUND - ri], cur);

	if (TOUCH_THE_LEAF_FLAG == TRUE)
	{
		if (COMP_PROB(check, DC_BOUND_IN_PROGRESS) != LEFT)
			return EXCEED_BOUND;

		else
			return UNDER_BOUND;
	}
	else
	{
		if (COMP_PROB(check, DC_BOUND_IN_PROGRESS) == RIGHT)
			return EXCEED_BOUND;
		else
			return UNDER_BOUND;
	}
}


/*	Attention
*   1) set_round < target_round
*	2) set_round <= round of which we know best bound.
*/
void SPN_Best_DC_Prob_Search(PROB_t * prob_rst, CNT_t target_round)
{
	CNT_t round_idx;
	char filename[256];

#ifdef OUT_ELAPSED_TIME
	char filename_time[256];
	clock_t START_CLK;
	clock_t CHECK_CLK;
	double  CLK_TIME;
	time_t  START_TIME;
	time_t  CHECK_TIME;
	FILE    * otfp = NULL;
	sprintf(filename_time, "%s_Best_Differential_Trail_Elapsed.bin", ALG_NAME);
	otfp = fopen(filename_time, "wb");
	fclose(otfp);
#endif 



	/*general information*/
	WHOLE_TARGET_ROUND = target_round;
	/***********************************************************************/

	DC_BOUNDS[1] = DC_1ROUND_MAX_PROB;

	//Start searching
	for (round_idx = 2; round_idx <= WHOLE_TARGET_ROUND; round_idx++)
	{
		FLAG_t first_trial_flag;

		first_trial_flag = TRUE;
		DONE_FLAG = FALSE;

		while (DONE_FLAG != TRUE)
		{
			//Set the initial bound : MAX_PROB_FOR_SBOX * Before Round bound
			if (first_trial_flag == TRUE)
			{
				first_trial_flag = FALSE;

				#ifdef OUT_ELAPSED_TIME
				START_CLK = clock();
				START_TIME = time(NULL);
				#endif

				MUL_PROB(&DC_BOUND_IN_PROGRESS, DC_BOUNDS[round_idx - 1], MAX_PROB_FOR_SBOX);
			}
			else  //Set next bound using MIN_PROB_FOR_SBOX
			{
				MUL_PROB(&DC_BOUND_IN_PROGRESS, DC_BOUND_IN_PROGRESS, MIN_PROB_FOR_SBOX);
			}

			CUR_TARGET_ROUND = round_idx;
			TOUCH_THE_LEAF_FLAG = FALSE;

			//CORE
			SPN_Best_Dif_FirstRound();

		}//EACH ROUND FINISHES

		#ifdef OUT_ELAPSED_TIME
		CHECK_CLK = clock() - START_CLK;
		CLK_TIME = (double)(CHECK_CLK) / CLOCKS_PER_SEC;
		CHECK_TIME = time(NULL) - START_TIME;
		otfp = fopen(filename_time, "ab");
		fwrite((void*)&CHECK_TIME, sizeof(CHECK_TIME), 1, otfp);
		fwrite((void*)&CLK_TIME, sizeof(CLK_TIME), 1, otfp);
		printf("==[%2d]-Round [takes %lld secs(%0.4lf secs)]==\n", round_idx, CHECK_TIME, CLK_TIME);
		fclose(otfp);
		#endif

		DC_BOUNDS[round_idx] = DC_BOUND_IN_PROGRESS;

		sprintf(filename, "%s_Best_Differential_Trail_%dR.txt", ALG_NAME, round_idx);
		FPrint_DC_Trail(filename, DC_TRAIL_FOR_OUT, round_idx);

	}//EVERY ROUND FINISHES

	for (round_idx = 1; round_idx <= target_round; round_idx++)
	{
		prob_rst[round_idx - 1] = DC_BOUNDS[round_idx];
	}
}


void SPN_Best_Dif_FirstRound(void)
{
	CNT_t  j_init;
	PROB_t W_init, W_nxt_init;

	ACTIVE_MAP_t A;
	PROB_t      Wnxt;
	PROB_t		Wpred1, Wpred2;

#ifndef CONSTRUCT_1ROUND_ACTIVE_MAPS
	CNT_t	HA;
	CNT_t	idx_active_map;
	NUM_t   hw = 0;

	//Note that : This loop may determine the whole search complexity.
	for (idx_active_map = 0; idx_active_map < NUM_1ROUND_ACTIVE_MAPS; idx_active_map++)
	{
		//Set 1-round active_map
		A = _1ROUND_ACTIVE_MAPS[idx_active_map];

		//Pruning (PC-1)
		HA = Num_Active_Word(BEFORE_STARTING_THE_ROUND, A);
		POW_MAX_PROB(&Wpred1, HA);
		if (Prob_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
			break; //We do not have to check other active maps which have more than(and equal to) the current number of active S-box


		//Pruning (PC-2)
		j_init = Prob_Next_Round_Lower_Bound_Bf_Starting_Round(&Wnxt, A);
		MUL_PROB(&Wpred2, Wpred1, Wnxt);
		if (Prob_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
			continue; //Try other active maps


		//init the input/output states and probabilities
		memset(DC_TRAIL_IN_PROGRESS[1].sub_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
		memset(DC_TRAIL_IN_PROGRESS[1].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
		memset(DC_TRAIL_IN_PROGRESS[1].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);

		Set_Probs_One(DC_TRAIL_IN_PROGRESS[1].p, NUM_SBOX_IN_A_STATE);

		W_init = ONE_PROB;
		W_nxt_init = ONE_PROB;

		SPN_Best_Dif_FirstSubRound(j_init, A, W_init, W_nxt_init);
	}

#else

	CNT_t idx_hw;
	for (idx_hw = 1; idx_hw <= NUM_SBOX_IN_A_STATE; idx_hw++)
	{
		FLAG_t last_flag;
		
		//Pruning (PC-1)
		POW_MAX_PROB(&Wpred1, idx_hw);
		if (Prob_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
		{
			break;//We do not have to check other active maps which have more than(and equal to) the current number of active S-box
		}


		Init_1Round_Active_Map(idx_hw);
		do
		{
			//Set 1-round active_map
			last_flag = Next_1Round_Active_Map(&A);


			//Pruning (PC-2)
			j_init = Prob_Next_Round_Lower_Bound_Bf_Starting_Round(&Wnxt, A);
			MUL_PROB(&Wpred2, Wpred1, Wnxt);
			if (Prob_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
				continue; //Try other active maps


			//init the input/output states and probabilities
			memset(DC_TRAIL_IN_PROGRESS[1].sub_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
			memset(DC_TRAIL_IN_PROGRESS[1].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
			memset(DC_TRAIL_IN_PROGRESS[1].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);

			Set_Probs_One(DC_TRAIL_IN_PROGRESS[1].p, NUM_SBOX_IN_A_STATE);

			W_init = ONE_PROB;
			W_nxt_init = ONE_PROB;

			SPN_Best_Dif_FirstSubRound(j_init, A, W_init, W_nxt_init);

		} while (last_flag == THIS_IS_NOT_THE_LAST);
	}
	
#endif
}

void SPN_Best_Dif_FirstSubRound(CNT_t j, ACTIVE_MAP_t A, PROB_t Wbef, PROB_t Wbef_nxt)
{
	CNT_t  _1_j;
	SBOX_t * X1_j = &(DC_TRAIL_IN_PROGRESS[1].sub_i[j]);
	SBOX_t * Y1_j = &(DC_TRAIL_IN_PROGRESS[1].sub_o[j]);
	PROB_t * P1_j = &(DC_TRAIL_IN_PROGRESS[1].p[j]);
	CNT_t  Hrm;
	PROB_t Wdet, Wrm, Wnxt_sub, Wnxt, Wnxt_det, Wnxt_cur, Wnxt_rem;
	PROB_t Wpred1, Wpred2;
	CNT_t  j_nxt;
	CNT_t  pmix_loc  = j / NUM_DIFF_OF_PARTIAL_DIFFUSION;
	CNT_t  pmix_sloc = j % NUM_DIFF_OF_PARTIAL_DIFFUSION;
	SBOX_t * cur_pmix_start = &(DC_TRAIL_IN_PROGRESS[1].psh_i[(pmix_loc)* NUM_DIFF_OF_PARTIAL_DIFFUSION]);
	CNT_t  pmix_loc_nxt;


	j_nxt = Next_Active_Word(j, A);
	
	if (j_nxt != THIS_IS_THE_LAST)
	{
		pmix_loc_nxt = j_nxt / NUM_DIFF_OF_PARTIAL_DIFFUSION;
		Prob_Next_Round_Lower_Bound_Rem(&Wnxt_rem, pmix_loc, pmix_loc_nxt, A);
	}
	else
	{
		pmix_loc_nxt = NUM_PARTION_OF_DIFF_IN_A_STATE;
		Wnxt_rem = ONE_PROB;
	}

	MUL_PROB(&Wnxt_sub, Wbef_nxt, Wnxt_rem);
	
	Hrm = Num_Active_Word(j, A);
	POW_MAX_PROB(&Wrm, Hrm);
	MUL_PROB(&Wrm, Wbef, Wrm);

	//It is always active!
	for (_1_j = 1; _1_j < SBOX_O_CARDINALITY; _1_j++)
	{
		Wnxt_det = Wbef_nxt;
		*Y1_j = DC_SBOX_I_O_PROB_FIXED_O[_1_j].o;
		*P1_j = DC_SBOX_I_O_PROB_FIXED_O[_1_j].p;

		//Pruning (PC-1)
		MUL_PROB(&Wpred1, Wrm, *P1_j);
		if (Prob_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
			break;
		
		//Pruning (PC-2)
		PMIX(cur_pmix_start, pmix_sloc, (*Y1_j));
		Prob_Next_Round_Lower_Bound(&Wnxt_cur, cur_pmix_start, pmix_loc, pmix_loc_nxt);
		//Wnxt = (Wbef_nxt + Wnxt_rem) + Wnxt_cur
		MUL_PROB(&Wnxt, Wnxt_sub, Wnxt_cur);
		//Wpred2 = Wpred1 + Wnxt
		MUL_PROB(&Wpred2, Wpred1, Wnxt);
		if (Prob_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
		{
			//Removing Pmix Effect
			PMIX(cur_pmix_start, pmix_sloc, (*Y1_j));
			continue; //Try other out value
		}

		//store the current input word
		*X1_j = DC_SBOX_I_O_PROB_FIXED_O[_1_j].i;

		MUL_PROB(&Wdet, Wbef, *P1_j);
		if (j_nxt != THIS_IS_THE_LAST) //when this word is not the last word
		{
			if (pmix_loc != pmix_loc_nxt)
			{
				MUL_PROB(&Wnxt_det, Wnxt_det, Wnxt_cur);
			}
			//Move to next word
			SPN_Best_Dif_FirstSubRound(j_nxt, A, Wdet, Wnxt_det);
		}
		else //when this word is the last word
		{
			PROB_t RWdet = Wdet;
			//Move to next round
			if (CUR_TARGET_ROUND == 2)
			{
				//Move to the last round
				SPN_Best_Dif_LastRound(RWdet);
			}
			else
			{
				//Move to next(2) round
				SPN_Best_Dif_MiddleRound(2, RWdet);
			}
		}

		//Removing Pmix Effect
		PMIX(cur_pmix_start, pmix_sloc, (*Y1_j));
	}
}

void SPN_Best_Dif_MiddleRound(CNT_t i, PROB_t RWbef)
{
	CNT_t  j_init;
	PROB_t W_init, W_nxt_init;

	ACTIVE_MAP_t A;
	PROB_t       Wall, Wnxt;
	PROB_t       Wpred1, Wpred2;
	
	PSHUF(DC_TRAIL_IN_PROGRESS[i].sub_i, DC_TRAIL_IN_PROGRESS[i - 1].psh_i);
	A = Compute_Active_Map_From_State(DC_TRAIL_IN_PROGRESS[i].sub_i);

	//Pruning (PC-1)
	Prob_Fill_Undertermined(&Wall, (CNT_t)-1, DC_TRAIL_IN_PROGRESS[i].sub_i);
	MUL_PROB(&Wpred1, RWbef, Wall);
	if (Prob_Bound_Checker(i, Wpred1) == EXCEED_BOUND)
		return;


	//Pruning (PC-2)
	j_init = Prob_Next_Round_Lower_Bound_Bf_Starting_Round(&Wnxt, A);
	MUL_PROB(&Wpred2, Wpred1, Wnxt);
	if (Prob_Bound_Checker(i + 1, Wpred2) == EXCEED_BOUND)
		return;


	//init the input/output states and probabilities
	memset(DC_TRAIL_IN_PROGRESS[i].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	memset(DC_TRAIL_IN_PROGRESS[i].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	Set_Probs_One(DC_TRAIL_IN_PROGRESS[i].p, NUM_SBOX_IN_A_STATE);

	W_init = RWbef;
	W_nxt_init = ONE_PROB;

	SPN_Best_Dif_MiddleSubRound(i, j_init, A, W_init, W_nxt_init);
}

void SPN_Best_Dif_MiddleSubRound(CNT_t i, CNT_t j, ACTIVE_MAP_t A, PROB_t Wbef, PROB_t Wbef_nxt)
{
	CNT_t  _i_j;
	SBOX_t   Xi_j = DC_TRAIL_IN_PROGRESS[i].sub_i[j]; //This word is fixed from before state
	SBOX_t * Yi_j = &(DC_TRAIL_IN_PROGRESS[i].sub_o[j]);
	PROB_t * Pi_j = &(DC_TRAIL_IN_PROGRESS[i].p[j]);
	PROB_t	Wdet, Wrm, Wnxt_sub, Wnxt, Wnxt_det, Wnxt_cur, Wnxt_rem;
	PROB_t	Wpred1, Wpred2;
	CNT_t	j_nxt;
	CNT_t  pmix_loc = j / NUM_DIFF_OF_PARTIAL_DIFFUSION;
	CNT_t  pmix_sloc = j % NUM_DIFF_OF_PARTIAL_DIFFUSION;
	SBOX_t * cur_pmix_start = &(DC_TRAIL_IN_PROGRESS[i].psh_i[(pmix_loc)* NUM_DIFF_OF_PARTIAL_DIFFUSION]);
	CNT_t  pmix_loc_nxt;

	Prob_Fill_Undertermined(&Wrm, j, DC_TRAIL_IN_PROGRESS[i].sub_i);
	MUL_PROB(&Wrm, Wbef, Wrm);
	
	j_nxt = Next_Active_Word(j, A);

	if (j_nxt != THIS_IS_THE_LAST)
	{
		pmix_loc_nxt = j_nxt / NUM_DIFF_OF_PARTIAL_DIFFUSION;
		Prob_Next_Round_Lower_Bound_Rem(&Wnxt_rem, pmix_loc, pmix_loc_nxt, A);
	}
	else
	{
		pmix_loc_nxt = NUM_PARTION_OF_DIFF_IN_A_STATE;
		Wnxt_rem = ONE_PROB;
	}

	MUL_PROB(&Wnxt_sub, Wbef_nxt, Wnxt_rem);

	for (_i_j = 0; _i_j < NUM_O_WITH_NONZERO_PROB[Xi_j]; _i_j++)
	{
		Wnxt_det = Wbef_nxt;
		*Pi_j = DC_SBOX_O_PROB_FIXED_I[Xi_j][_i_j].p;
		
		//Pruning (PC-1)
		MUL_PROB(&Wpred1, Wrm, *Pi_j);
		if (Prob_Bound_Checker(i, Wpred1) == EXCEED_BOUND)
			break;

		//store the current out word
		*Yi_j = DC_SBOX_O_PROB_FIXED_I[Xi_j][_i_j].o;

		//Pruning (PC-2)
		PMIX(cur_pmix_start, pmix_sloc, (*Yi_j));
		Prob_Next_Round_Lower_Bound(&Wnxt_cur, cur_pmix_start, pmix_loc, pmix_loc_nxt);
		//Wnxt = (Wbef_nxt + Wnxt_rem) + Wnxt_cur
		MUL_PROB(&Wnxt, Wnxt_sub, Wnxt_cur);
		//Wpred2 = Wpred1 + Wnxt
		MUL_PROB(&Wpred2, Wpred1, Wnxt);
		if (Prob_Bound_Checker(i + 1, Wpred2) == EXCEED_BOUND)
		{
			//Removing Pmix Effect
			PMIX(cur_pmix_start, pmix_sloc, (*Yi_j));
			continue; //Try other out value
		}
		

		MUL_PROB(&Wdet, Wbef, *Pi_j);
		if (j_nxt != THIS_IS_THE_LAST)  //when this word is not the last word
		{
			if (pmix_loc != pmix_loc_nxt)
			{
				MUL_PROB(&Wnxt_det, Wnxt_det, Wnxt_cur);
			}

			//Move to next word
			SPN_Best_Dif_MiddleSubRound(i, j_nxt, A, Wdet, Wnxt_det);
		}
		else //when this word is the last word
		{
			PROB_t RWdet = Wdet;
			//Move to next round
			if (i == CUR_TARGET_ROUND - 1)
			{
				SPN_Best_Dif_LastRound(RWdet);
			}
			else//if (i < CUR_TARGET_ROUND - 1)
			{
				SPN_Best_Dif_MiddleRound(i + 1, RWdet);
			}
		}

		//Removing Pmix Effect
		PMIX(cur_pmix_start, pmix_sloc, (*Yi_j));
	}
}


void SPN_Best_Dif_LastRound(PROB_t RWbef)
{
	CNT_t  j_init;
	PROB_t W_init;

	ACTIVE_MAP_t A;
	PROB_t       Wall;
	PROB_t		 Wpred1;


	PSHUF(DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i, DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND - 1].psh_i);
	A = Compute_Active_Map_From_State(DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i);


	//Pruning (PC-1)
	Prob_Fill_Undertermined(&Wall, (CNT_t)-1, DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i);
	MUL_PROB(&Wpred1, RWbef, Wall);
	if (Prob_Bound_Checker(CUR_TARGET_ROUND, Wpred1) == EXCEED_BOUND)
		return; //We do not have to check the input sate which has more than(and equal to) the current number of active S-box

	//init the input/output states and probabilities
	memset(DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	memset(DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	Set_Probs_One(DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].p, NUM_SBOX_IN_A_STATE);


	W_init = RWbef;
	j_init = Next_Active_Word(BEFORE_STARTING_THE_ROUND, A);

	SPN_Best_Dif_LastSubRound(j_init, A, W_init);
}

void SPN_Best_Dif_LastSubRound(CNT_t j, ACTIVE_MAP_t A, PROB_t Wbef)
{
	SBOX_t  Xn_j = DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i[j]; //This word is fixed from before state
	SBOX_t *Yn_j = &(DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_o[j]);
	PROB_t *Pn_j = &(DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].p[j]);
	PROB_t  Wdet, Wrm;
	PROB_t  Wpred1;
	CNT_t	j_nxt;

	*Pn_j = DC_SBOX_O_PROB_FIXED_I[Xn_j][0].p; //max prob with fixed in
	MUL_PROB(&Wdet, Wbef, *Pn_j);

	//Pruning (PC-1)
	Prob_Fill_Undertermined(&Wrm, j, DC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i);
	MUL_PROB(&Wpred1, Wdet, Wrm);
	if (Prob_Bound_Checker(CUR_TARGET_ROUND, Wpred1) == EXCEED_BOUND)
		return; 

	//store the current out word
	*Yn_j = DC_SBOX_O_PROB_FIXED_I[Xn_j][0].o;

	//get next active_word
	j_nxt = Next_Active_Word(j, A);

	if (j_nxt != THIS_IS_THE_LAST) //when this word is not the last word  
	{
		//Move to next word
		SPN_Best_Dif_LastSubRound(j_nxt, A, Wdet);
	}
	else //when this word is the last word
	{
		TOUCH_THE_LEAF_FLAG = TRUE;
		DONE_FLAG = TRUE;

		//update Progress bound
		DC_BOUND_IN_PROGRESS = Wdet;

		//Store the current trail
		Copy_DC_Trail(DC_TRAIL_FOR_OUT, DC_TRAIL_IN_PROGRESS, CUR_TARGET_ROUND);
	}
}