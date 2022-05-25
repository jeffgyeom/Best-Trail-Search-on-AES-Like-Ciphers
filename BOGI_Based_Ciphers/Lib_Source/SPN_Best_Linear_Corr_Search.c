#include "astbb.h"
#include "lin_corr.h"
#include "active_map.h"
#include "printout.h"
#include "bogi_common_info.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

//declared in prep_l c.c
LC_I_O_CORR_t		LC_SBOX_I_O_CORR[SBOX_IO_CARDINALITY];
NUM_t				NUM_I_O_WITH_NONZERO_CORR;
NUM_t				NUM_I_O_WITH_MAX_CORR;

LC_O_CORR_t			LC_SBOX_O_CORR_FIXED_I[SBOX_I_CARDINALITY][SBOX_O_CARDINALITY];
CNT_t				NUM_O_WITH_NONZERO_CORR[SBOX_I_CARDINALITY];
CNT_t				NUM_O_WITH_MAX_CORR[SBOX_I_CARDINALITY];

LC_I_CORR_t			LC_SBOX_I_CORR_FIXED_O[SBOX_O_CARDINALITY][SBOX_I_CARDINALITY];
CNT_t				NUM_I_WITH_NONZERO_CORR[SBOX_O_CARDINALITY];
CNT_t				NUM_I_WITH_MAX_CORR[SBOX_O_CARDINALITY];

LC_I_O_CORR_t		LC_SBOX_I_O_CORR_FIXED_O[SBOX_O_CARDINALITY]; //this table is very special!
CORR_t				LC_1ROUND_MAX_CORR;
CORR_t				MAX_CORR_FOR_SBOX;
CORR_t				MIN_CORR_FOR_SBOX;


CORR_t				LC_BOUNDS[NUM_ROUND_THRESHOLD + 1];; //for convenience, the first element is always 0 and is not used
LC_1ROUND_CHAR_t	LC_TRAIL_IN_PROGRESS[NUM_ROUND_THRESHOLD + 1];; //for convenience, the first element is always 0 and is not used
LC_1ROUND_CHAR_t	LC_TRAIL_FOR_OUT[NUM_ROUND_THRESHOLD + 1];; //for convenience, the first element is always 0 and is not used


/*Variables only for the current c code region*/
static FLAG_t DONE_FLAG = FALSE;
static FLAG_t TOUCH_THE_LEAF_FLAG = FALSE;
static CORR_t LC_BOUND_IN_PROGRESS;
static SBOX_t ZERO_INPUT_STATE[NUM_SBOX_IN_A_STATE] = { 0, };
static NUM_t CUR_TARGET_ROUND;
static NUM_t WHOLE_TARGET_ROUND;
/***********************************************/


void SPN_Best_Lin_FirstRound(void);
void SPN_Best_Lin_FirstSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef, CORR_t Wbef_nxt);
void SPN_Best_Lin_MiddleRound(CNT_t i, CORR_t RWbef);
void SPN_Best_Lin_MiddleSubRound(CNT_t i, CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef, CORR_t Wbef_nxt);
void SPN_Best_Lin_LastRound(CORR_t RWbef);
void SPN_Best_Lin_LastSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef);


static DEV_INLINE void Corr_Fill_Undertermined(CORR_t * pred, CNT_t j, SBOX_t * sin)
{
	CNT_t sbox_idx;
	CNT_t cur_rm_act = 0;
	/*condition*/
	// 1) i > 2
	// 2) thus, sin is determined already

	//Note that : Optimal BOGI-applicable S-boxes have the MAXIMUM CORR in each row(Input Mask)
	//            Thus, we do not have to check each input mask can have the MAXIMUM CORR
	for (sbox_idx = j + 1; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		if (sin[sbox_idx] != 0) //When it is not zero difference
		{
			cur_rm_act++;
		}
	}
	POW_MAX_CORR(pred, cur_rm_act);
}


static DEV_INLINE CNT_t Corr_Next_Round_Lower_Bound_Bf_Starting_Round(CORR_t * pred, ACTIVE_MAP_t A)
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

	POW_MAX_CORR(pred, pred_nxt_num_act);

	return j_nxt;
}

static DEV_INLINE void Corr_Next_Round_Lower_Bound_Rem(CORR_t * pred_rem, CNT_t pmix_loc, CNT_t pmix_loc_nxt, ACTIVE_MAP_t A)
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
	POW_MAX_CORR(pred_rem, rem_act);
}


static DEV_INLINE void Corr_Next_Round_Lower_Bound(CORR_t * pred_cur, SBOX_t * psh_i, CNT_t pmix_loc, CNT_t pmix_loc_nxt)
{
	int   widx;
	CNT_t cur_act = 0;
	//Note that : Optimal BOGI-applicable S-boxes have the MAXIMUM CORR in each row(Input Mask)
	//            Thus, we do not have to check each input mask can have the MAXIMUM CORR
	for (widx = 0; widx < NUM_DIFF_OF_PARTIAL_DIFFUSION; widx++)
	{
		if (psh_i[widx] != 0)
		{
			cur_act++;
		}
	}
	POW_MAX_CORR(pred_cur, cur_act);
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



/*	Attention
*   1) set_round < target_round
*	2) set_round <= round of which we know best bound.
*/
void SPN_Best_LC_Corr_Search(CORR_t * corr_rst, CNT_t target_round)
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
	sprintf(filename_time, "%s_Best_Linear_Trail_Elapsed.bin", ALG_NAME);
	otfp = fopen(filename_time, "wb");
	fclose(otfp);
#endif 



	/*general information*/
	WHOLE_TARGET_ROUND = target_round;
	/***********************************************************************/

	LC_BOUNDS[1] = LC_1ROUND_MAX_CORR;
	
	//Start searching
	for (round_idx = 2; round_idx <= WHOLE_TARGET_ROUND; round_idx++)
	{
		FLAG_t first_trial_flag;

		first_trial_flag = TRUE;
		DONE_FLAG = FALSE;

		while (DONE_FLAG != TRUE)
		{
			//Set the initial bound : MAX_CORR_FOR_WHOLE_SBOXES * Before Round bound
			if (first_trial_flag == TRUE)
			{
				first_trial_flag = FALSE;
				
				#ifdef OUT_ELAPSED_TIME
				START_CLK = clock();
				START_TIME = time(NULL);
				#endif
				
				MUL_CORR(&LC_BOUND_IN_PROGRESS, LC_BOUNDS[round_idx - 1], MAX_CORR_FOR_SBOX);
			}
			else  //Set next bound using MIN_CORR_FOR_WHOLE_SBOXES
			{
				MUL_CORR(&LC_BOUND_IN_PROGRESS, LC_BOUND_IN_PROGRESS, MIN_CORR_FOR_SBOX);
			}

			CUR_TARGET_ROUND = round_idx;
			TOUCH_THE_LEAF_FLAG = FALSE;

			//CORE
			SPN_Best_Lin_FirstRound();

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

		LC_BOUNDS[round_idx] = LC_BOUND_IN_PROGRESS;

		sprintf(filename, "%s_Best_Linear_Trail_%dR.txt", ALG_NAME, round_idx);
		FPrint_LC_Trail(filename, LC_TRAIL_FOR_OUT, round_idx);

	}//EVERY ROUND FINISHES

	for (round_idx = 1; round_idx <= target_round; round_idx++)
	{
		corr_rst[round_idx - 1] = LC_BOUNDS[round_idx];
	}
}


void SPN_Best_Lin_FirstRound(void)
{
	CNT_t  j_init;
	CORR_t W_init, W_nxt_init;

	ACTIVE_MAP_t A;
	CORR_t      Wnxt;
	CORR_t		Wpred1, Wpred2;	

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
		POW_MAX_CORR(&Wpred1, HA);
		if (Corr_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
			break; //We do not have to check other active maps which have more than(and equal to) the current number of active S-box


		//Pruning (PC-2)
		j_init = Corr_Next_Round_Lower_Bound_Bf_Starting_Round(&Wnxt, A);
		MUL_CORR(&Wpred2, Wpred1, Wnxt);
		if (Corr_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
			continue; //Try other active maps


		//init the input/output states and correlations
		memset(LC_TRAIL_IN_PROGRESS[1].sub_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
		memset(LC_TRAIL_IN_PROGRESS[1].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
		memset(LC_TRAIL_IN_PROGRESS[1].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);

		Set_Corrs_One(LC_TRAIL_IN_PROGRESS[1].c, NUM_SBOX_IN_A_STATE);

		W_init = ONE_CORR;
		W_nxt_init = ONE_CORR;

		SPN_Best_Lin_FirstSubRound(j_init, A, W_init, W_nxt_init);
	}
	
#else
	
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
			//Set 1-round active_map
			last_flag = Next_1Round_Active_Map(&A);


			//Pruning (PC-2)
			j_init = Corr_Next_Round_Lower_Bound_Bf_Starting_Round(&Wnxt, A);
			MUL_CORR(&Wpred2, Wpred1, Wnxt);
			if (Corr_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
				continue; //Try other active maps


			//init the input/output states and correlations
			memset(LC_TRAIL_IN_PROGRESS[1].sub_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
			memset(LC_TRAIL_IN_PROGRESS[1].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
			memset(LC_TRAIL_IN_PROGRESS[1].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);

			Set_Corrs_One(LC_TRAIL_IN_PROGRESS[1].c, NUM_SBOX_IN_A_STATE);

			W_init = ONE_CORR;
			W_nxt_init = ONE_CORR;

			SPN_Best_Lin_FirstSubRound(j_init, A, W_init, W_nxt_init);

		} while (last_flag == THIS_IS_NOT_THE_LAST);

	}
	
#endif

}

void SPN_Best_Lin_FirstSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef, CORR_t Wbef_nxt)
{
	CNT_t _1_j;
	SBOX_t * X1_j = &(LC_TRAIL_IN_PROGRESS[1].sub_i[j]);
	SBOX_t * Y1_j = &(LC_TRAIL_IN_PROGRESS[1].sub_o[j]);
	CORR_t * C1_j = &(LC_TRAIL_IN_PROGRESS[1].c[j]);
	CNT_t  Hrm;
	CORR_t Wdet, Wrm, Wnxt_sub, Wnxt, Wnxt_det, Wnxt_cur, Wnxt_rem;
	CORR_t Wpred1, Wpred2;
	CNT_t  j_nxt;
	CNT_t  pmix_loc  = j / NUM_DIFF_OF_PARTIAL_DIFFUSION;
	CNT_t  pmix_sloc = j % NUM_DIFF_OF_PARTIAL_DIFFUSION;
	SBOX_t * cur_pmix_start = &(LC_TRAIL_IN_PROGRESS[1].psh_i[(pmix_loc)* NUM_DIFF_OF_PARTIAL_DIFFUSION]);
	CNT_t  pmix_loc_nxt;


	j_nxt = Next_Active_Word(j, A);

	if (j_nxt != THIS_IS_THE_LAST)
	{
		pmix_loc_nxt = j_nxt / NUM_DIFF_OF_PARTIAL_DIFFUSION;
		Corr_Next_Round_Lower_Bound_Rem(&Wnxt_rem, pmix_loc, pmix_loc_nxt, A);
	}
	else
	{
		pmix_loc_nxt = NUM_PARTION_OF_DIFF_IN_A_STATE;
		Wnxt_rem = ONE_CORR;
	}

	MUL_CORR(&Wnxt_sub, Wbef_nxt, Wnxt_rem);

	Hrm = Num_Active_Word(j, A);
	POW_MAX_CORR(&Wrm, Hrm);
	MUL_CORR(&Wrm, Wbef, Wrm);

	//It is always active!
	for (_1_j = 1; _1_j < SBOX_O_CARDINALITY; _1_j++)
	{
		Wnxt_det = Wbef_nxt;
		*Y1_j = LC_SBOX_I_O_CORR_FIXED_O[_1_j].o;
		*C1_j = LC_SBOX_I_O_CORR_FIXED_O[_1_j].c;

		//Pruning (PC-1)
		MUL_CORR(&Wpred1, Wrm, *C1_j);
		if (Corr_Bound_Checker(1, Wpred1) == EXCEED_BOUND)
			break;

		//Pruning (PC-2)
		PMIX(cur_pmix_start, pmix_sloc, (*Y1_j));
		Corr_Next_Round_Lower_Bound(&Wnxt_cur, cur_pmix_start, pmix_loc, pmix_loc_nxt);
		//Wnxt = (Wbef_nxt + Wnxt_rem) + Wnxt_cur
		MUL_CORR(&Wnxt, Wnxt_sub, Wnxt_cur);
		//Wpred2 = Wpred1 + Wnxt
		MUL_CORR(&Wpred2, Wpred1, Wnxt);
		if (Corr_Bound_Checker(2, Wpred2) == EXCEED_BOUND)
		{
			//Removing Pmix Effect
			PMIX(cur_pmix_start, pmix_sloc, (*Y1_j));
			continue; //Try other out value
		}

		//store the current input word
		*X1_j = LC_SBOX_I_O_CORR_FIXED_O[_1_j].i;

		MUL_CORR(&Wdet, Wbef, *C1_j);
		if (j_nxt != THIS_IS_THE_LAST) //when this word is not the last word
		{
			if (pmix_loc != pmix_loc_nxt)
			{
				MUL_CORR(&Wnxt_det, Wnxt_det, Wnxt_cur);
			}
			//Move to next word
			SPN_Best_Lin_FirstSubRound(j_nxt, A, Wdet, Wnxt_det);
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

		//Removing Pmix Effect
		PMIX(cur_pmix_start, pmix_sloc, (*Y1_j));
	}
}


void SPN_Best_Lin_MiddleRound(CNT_t i, CORR_t RWbef)
{
	CNT_t  j_init;
	CORR_t W_init, W_nxt_init;

	ACTIVE_MAP_t A;
	CORR_t       Wall, Wnxt;
	CORR_t       Wpred1, Wpred2;
	
	PSHUF(LC_TRAIL_IN_PROGRESS[i].sub_i, LC_TRAIL_IN_PROGRESS[i - 1].psh_i);
	A = Compute_Active_Map_From_State(LC_TRAIL_IN_PROGRESS[i].sub_i);

	//Pruning (PC-1)
	Corr_Fill_Undertermined(&Wall, (CNT_t)-1, LC_TRAIL_IN_PROGRESS[i].sub_i);
	MUL_CORR(&Wpred1, RWbef, Wall);
	if (Corr_Bound_Checker(i, Wpred1) == EXCEED_BOUND)
		return;


	//Pruning (PC-2)
	j_init = Corr_Next_Round_Lower_Bound_Bf_Starting_Round(&Wnxt, A);
	MUL_CORR(&Wpred2, Wpred1, Wnxt);
	if (Corr_Bound_Checker(i + 1, Wpred2) == EXCEED_BOUND)
		return;


	//init the input/output states and correlation
	memset(LC_TRAIL_IN_PROGRESS[i].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	memset(LC_TRAIL_IN_PROGRESS[i].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	Set_Corrs_One(LC_TRAIL_IN_PROGRESS[i].c, NUM_SBOX_IN_A_STATE);

	W_init = RWbef;
	W_nxt_init = ONE_CORR;

	SPN_Best_Lin_MiddleSubRound(i, j_init, A, W_init, W_nxt_init);
}

void SPN_Best_Lin_MiddleSubRound(CNT_t i, CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef, CORR_t Wbef_nxt)
{
	CNT_t   _i_j;
	SBOX_t   Xi_j = LC_TRAIL_IN_PROGRESS[i].sub_i[j]; //This word is fixed from before state
	SBOX_t * Yi_j = &(LC_TRAIL_IN_PROGRESS[i].sub_o[j]);
	CORR_t * Ci_j = &(LC_TRAIL_IN_PROGRESS[i].c[j]);
	CORR_t	Wdet, Wrm, Wnxt_sub, Wnxt, Wnxt_det, Wnxt_cur, Wnxt_rem;
	CORR_t	Wpred1, Wpred2;
	CNT_t	j_nxt;
	CNT_t   pmix_loc = j / NUM_DIFF_OF_PARTIAL_DIFFUSION;
	CNT_t   pmix_sloc = j % NUM_DIFF_OF_PARTIAL_DIFFUSION;
	SBOX_t * cur_pmix_start = &(LC_TRAIL_IN_PROGRESS[i].psh_i[(pmix_loc)* NUM_DIFF_OF_PARTIAL_DIFFUSION]);
	CNT_t  pmix_loc_nxt;

	Corr_Fill_Undertermined(&Wrm, j, LC_TRAIL_IN_PROGRESS[i].sub_i);
	MUL_CORR(&Wrm, Wbef, Wrm);
	
	j_nxt = Next_Active_Word(j, A);

	if (j_nxt != THIS_IS_THE_LAST)
	{
		pmix_loc_nxt = j_nxt / NUM_DIFF_OF_PARTIAL_DIFFUSION;
		Corr_Next_Round_Lower_Bound_Rem(&Wnxt_rem, pmix_loc, pmix_loc_nxt, A);
	}
	else
	{
		pmix_loc_nxt = NUM_PARTION_OF_DIFF_IN_A_STATE;
		Wnxt_rem = ONE_CORR;
	}

	MUL_CORR(&Wnxt_sub, Wbef_nxt, Wnxt_rem);

	for (_i_j = 0; _i_j < NUM_O_WITH_NONZERO_CORR[Xi_j]; _i_j++)
	{
		Wnxt_det = Wbef_nxt;
		*Ci_j = LC_SBOX_O_CORR_FIXED_I[Xi_j][_i_j].c;

		//Pruning (PC-1)
		MUL_CORR(&Wpred1, Wrm, *Ci_j);
		if (Corr_Bound_Checker(i, Wpred1) == EXCEED_BOUND)
			break;

		//store the current out word
		*Yi_j = LC_SBOX_O_CORR_FIXED_I[Xi_j][_i_j].o;

		//Pruning (PC-2)
		PMIX(cur_pmix_start, pmix_sloc, (*Yi_j));
		Corr_Next_Round_Lower_Bound(&Wnxt_cur, cur_pmix_start, pmix_loc, pmix_loc_nxt);
		//Wnxt = (Wbef_nxt + Wnxt_rem) + Wnxt_cur
		MUL_CORR(&Wnxt, Wnxt_sub, Wnxt_cur);
		//Wpred2 = Wpred1 + Wnxt
		MUL_CORR(&Wpred2, Wpred1, Wnxt);
		if (Corr_Bound_Checker(i + 1, Wpred2) == EXCEED_BOUND)
		{
			//Removing Pmix Effect
			PMIX(cur_pmix_start, pmix_sloc, (*Yi_j));
			continue; //Try other out value
		}


		MUL_CORR(&Wdet, Wbef, *Ci_j);
		if (j_nxt != THIS_IS_THE_LAST)  //when this word is not the last word
		{
			if (pmix_loc != pmix_loc_nxt)
			{
				MUL_CORR(&Wnxt_det, Wnxt_det, Wnxt_cur);
			}

			//Move to next word
			SPN_Best_Lin_MiddleSubRound(i, j_nxt, A, Wdet, Wnxt_det);
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

		//Removing Pmix Effect
		PMIX(cur_pmix_start, pmix_sloc, (*Yi_j));
	}
}


void SPN_Best_Lin_LastRound(CORR_t RWbef)
{
	CNT_t  j_init;
	CORR_t W_init;

	ACTIVE_MAP_t A;
	CORR_t       Wall;
	CORR_t		 Wpred1;


	PSHUF(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i, LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND - 1].psh_i);
	A = Compute_Active_Map_From_State(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i);


	//Pruning (PC-1)
	Corr_Fill_Undertermined(&Wall, (CNT_t)-1, LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i);
	MUL_CORR(&Wpred1, RWbef, Wall);
	if (Corr_Bound_Checker(CUR_TARGET_ROUND, Wpred1) == EXCEED_BOUND)
		return; //We do not have to check the input sate which has more than(and equal to) the current number of active S-box

	//init the input/output states and correlations
	memset(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_o, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	memset(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].psh_i, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	Set_Corrs_One(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].c, NUM_SBOX_IN_A_STATE);


	W_init = RWbef;
	j_init = Next_Active_Word(BEFORE_STARTING_THE_ROUND, A);

	SPN_Best_Lin_LastSubRound(j_init, A, W_init);
}

void SPN_Best_Lin_LastSubRound(CNT_t j, ACTIVE_MAP_t A, CORR_t Wbef)
{
	SBOX_t  Xn_j = LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i[j]; //This word is fixed from before state
	SBOX_t *Yn_j = &(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_o[j]);
	CORR_t *Cn_j = &(LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].c[j]);
	CORR_t	Wdet, Wrm;
	CORR_t  Wpred1;
	CNT_t	j_nxt;

	*Cn_j = LC_SBOX_O_CORR_FIXED_I[Xn_j][0].c; //max corr with fixed in
	MUL_CORR(&Wdet, Wbef, *Cn_j);

	//Pruning (PC-1)
	Corr_Fill_Undertermined(&Wrm, j, LC_TRAIL_IN_PROGRESS[CUR_TARGET_ROUND].sub_i);
	MUL_CORR(&Wpred1, Wdet, Wrm);
	if (Corr_Bound_Checker(CUR_TARGET_ROUND, Wpred1) == EXCEED_BOUND)
		return; 

	//store the current out word
	*Yn_j = LC_SBOX_O_CORR_FIXED_I[Xn_j][0].o;

	//get next active_word
	j_nxt = Next_Active_Word(j, A);

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
		
		//Store the current trail
		Copy_LC_Trail(LC_TRAIL_FOR_OUT, LC_TRAIL_IN_PROGRESS, CUR_TARGET_ROUND);
	}
}