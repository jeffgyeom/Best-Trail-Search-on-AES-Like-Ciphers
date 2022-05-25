#include "astbb.h"
#include "dif_prob.h"
#include "bogi_common_info.h"
#include <string.h>

/*Global Variables*/
DC_I_O_PROB_t		DC_SBOX_I_O_PROB[SBOX_IO_CARDINALITY];
NUM_t				NUM_I_O_WITH_NONZERO_PROB;
NUM_t				NUM_I_O_WITH_MAX_PROB;

DC_O_PROB_t			DC_SBOX_O_PROB_FIXED_I[SBOX_I_CARDINALITY][SBOX_O_CARDINALITY];
CNT_t				NUM_O_WITH_NONZERO_PROB[SBOX_I_CARDINALITY];
CNT_t				NUM_O_WITH_MAX_PROB[SBOX_I_CARDINALITY];

DC_I_PROB_t			DC_SBOX_I_PROB_FIXED_O[SBOX_O_CARDINALITY][SBOX_I_CARDINALITY];
CNT_t				NUM_I_WITH_NONZERO_PROB[SBOX_O_CARDINALITY];
CNT_t				NUM_I_WITH_MAX_PROB[SBOX_O_CARDINALITY];

DC_I_O_PROB_t		DC_SBOX_I_O_PROB_FIXED_O[SBOX_O_CARDINALITY]; //this table is very special!
PROB_t				DC_1ROUND_MAX_PROB;
PROB_t				MAX_PROB_FOR_SBOX;
PROB_t				MIN_PROB_FOR_SBOX;

PROB_t				DC_BOUNDS[NUM_ROUND_THRESHOLD + 1]; //for convenience, the first element is always 0 and is not used
DC_1ROUND_CHAR_t	DC_TRAIL_IN_PROGRESS[NUM_ROUND_THRESHOLD + 1]; //for convenience, the first element is never used
DC_1ROUND_CHAR_t	DC_TRAIL_FOR_OUT[NUM_ROUND_THRESHOLD + 1]; //for convenience, the first element is never used

PROB_t				MAX_PROB_POWER_TABLE[NUM_SBOX_IN_A_STATE + 1];
/************************************************/

/*********Additional functions************/
//Compute DDT with complexity O(2^(n+m))
void Compute_DDT(DDT_ENTRY_t * ddt, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
void Compute_Prob_DDT(PROB_t * prob_ddt, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
int descending_P(const void *first, const void *second);
int descending_IOP(const void *first, const void *second);
int descending_OP(const void *first, const void *second);
int descending_IP(const void *first, const void *second);
/****************************************/

void SPN_Prep_Info_For_DC_With_Prob_DDT(PROB_t * prob_ddt)
{
	CNT_t delta_i;
	CNT_t delta_o;
	CNT_t idx;
	PROB_t the_prob;


	// Step - 1 DDT information rearrange
	// all I_O_PROB
	// O_PROB with fixed input
	// I_PROB with fixed output
	for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
	{
		for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
		{
			//all I_O_PROB
			the_prob = prob_ddt[delta_i * SBOX_O_CARDINALITY + delta_o];
			DC_SBOX_I_O_PROB[delta_i * SBOX_O_CARDINALITY + delta_o].i = (SBOX_t)delta_i;
			DC_SBOX_I_O_PROB[delta_i * SBOX_O_CARDINALITY + delta_o].o = (SBOX_t)delta_o;
			DC_SBOX_I_O_PROB[delta_i * SBOX_O_CARDINALITY + delta_o].p = (PROB_t)the_prob;
			//O_PROB with fixed input
			DC_SBOX_O_PROB_FIXED_I[delta_i][delta_o].o = (SBOX_t)delta_o;
			DC_SBOX_O_PROB_FIXED_I[delta_i][delta_o].p = (PROB_t)the_prob;
			//I_PROB with fixed output
			DC_SBOX_I_PROB_FIXED_O[delta_o][delta_i].i = (SBOX_t)delta_i;
			DC_SBOX_I_PROB_FIXED_O[delta_o][delta_i].p = (PROB_t)the_prob;
		}
	}

	//sorting all I_O_PROB
	qsort((void*)DC_SBOX_I_O_PROB, (size_t)SBOX_IO_CARDINALITY, sizeof(DC_I_O_PROB_t), descending_IOP);

	//sorting O_PROB with fixed input
	for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
	{
		qsort((void*)DC_SBOX_O_PROB_FIXED_I[delta_i], (size_t)SBOX_O_CARDINALITY, sizeof(DC_O_PROB_t), descending_OP);
	}
	//sorting I_PROB with fixed output
	for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
	{
		qsort((void*)DC_SBOX_I_PROB_FIXED_O[delta_o], (size_t)SBOX_I_CARDINALITY, sizeof(DC_I_PROB_t), descending_IP);
	}
	//Get Each maximum I_O_PROB with fixed output
	for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
	{
		DC_SBOX_I_O_PROB_FIXED_O[delta_o].i = DC_SBOX_I_PROB_FIXED_O[delta_o][0].i;
		DC_SBOX_I_O_PROB_FIXED_O[delta_o].o = (SBOX_t)delta_o;
		DC_SBOX_I_O_PROB_FIXED_O[delta_o].p = DC_SBOX_I_PROB_FIXED_O[delta_o][0].p;
	}
	//sorting I_O_PROB with fixed output
	qsort((void*)DC_SBOX_I_O_PROB_FIXED_O, (size_t)SBOX_O_CARDINALITY, sizeof(DC_I_O_PROB_t), descending_IOP);
	


	//Counting the numbers of each information
	/*
	*  1) The number of sbox trails which have NON-zero probability.
	*  2) The number of sbox trails which have the best probability.
	*  3) The number of sbox trails which have NON-zero probability with each fixed sbox output/input.
	*  4) The number of sbox trails which have the best probability with each fixed sbox output/input.
	*  5) The number of sbox trails which have Best probability with each fixed sbox output
	*  6) The 1Round Best Probability
	*/
	
	////init
	NUM_I_O_WITH_NONZERO_PROB = 0;
	NUM_I_O_WITH_MAX_PROB = 0;
	for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
	{
		NUM_O_WITH_NONZERO_PROB[delta_i] = 0;
		NUM_O_WITH_MAX_PROB[delta_i] = 0;
	}
	for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
	{
		NUM_I_WITH_NONZERO_PROB[delta_o] = 0;
		NUM_I_WITH_MAX_PROB[delta_o] = 0;
	}

	////Counting IO_PROB
	for (idx = 0; idx < SBOX_IO_CARDINALITY; idx++)
	{
		PROB_t IO_prob = DC_SBOX_I_O_PROB[idx].p;
		PROB_t max_IO_prob = DC_SBOX_I_O_PROB[0].p;
		if (COMP_PROB(IO_prob, ZERO_PROB) != EQUAL)
		{
			NUM_I_O_WITH_NONZERO_PROB++;
		}
		if (COMP_PROB(max_IO_prob, IO_prob) == EQUAL)
		{
			NUM_I_O_WITH_MAX_PROB++;
		}
	}

	////Counting O_PROB
	for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
	{
		for (idx = 0; idx < SBOX_O_CARDINALITY; idx++)
		{
			PROB_t O_prob = DC_SBOX_O_PROB_FIXED_I[delta_i][idx].p;
			PROB_t max_O_prob = DC_SBOX_O_PROB_FIXED_I[delta_i][0].p;
			if (COMP_PROB(O_prob, ZERO_PROB) != EQUAL)
			{
				NUM_O_WITH_NONZERO_PROB[delta_i]++;
			}
			if (COMP_PROB(max_O_prob, O_prob) == EQUAL)
			{
				NUM_O_WITH_MAX_PROB[delta_i]++;
			}
		}
	}

	////Counting I_PROB
	for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
	{
		for (idx = 0; idx < SBOX_I_CARDINALITY; idx++)
		{
			PROB_t I_prob = DC_SBOX_I_PROB_FIXED_O[delta_o][idx].p;
			PROB_t max_I_prob = DC_SBOX_I_PROB_FIXED_O[delta_o][0].p;
			if (COMP_PROB(I_prob, ZERO_PROB) != EQUAL)
			{
				NUM_I_WITH_NONZERO_PROB[delta_o]++;
			}
			if (COMP_PROB(max_I_prob, I_prob) == EQUAL)
			{
				NUM_I_WITH_MAX_PROB[delta_o]++;
			}
		}
	}
	


	MAX_PROB_FOR_SBOX = ZERO_PROB;
	MIN_PROB_FOR_SBOX = ONE_PROB;
	//Computing Max/Min probability for the sbox
	for (idx = 0; idx < SBOX_IO_CARDINALITY; idx++)
	{
		if (DC_SBOX_I_O_PROB[idx].i != 0 || DC_SBOX_I_O_PROB[idx].o != 0)
		{
			if (COMP_PROB(MAX_PROB_FOR_SBOX, DC_SBOX_I_O_PROB[idx].p) == RIGHT)
			{
				MAX_PROB_FOR_SBOX = DC_SBOX_I_O_PROB[idx].p;
			}

			if (COMP_PROB(DC_SBOX_I_O_PROB[idx].p, ZERO_PROB) != EQUAL)
			{
				if (COMP_PROB(MIN_PROB_FOR_SBOX, DC_SBOX_I_O_PROB[idx].p) == LEFT)
				{
					MIN_PROB_FOR_SBOX = DC_SBOX_I_O_PROB[idx].p;
				}
			}
		}
	}
	
	//here : might change when we consider FEISTEL/*TODO*/
	DC_1ROUND_MAX_PROB = MAX_PROB_FOR_SBOX;

	MAX_PROB_POWER_TABLE[0] = ONE_PROB;
	MAX_PROB_POWER_TABLE[1] = MAX_PROB_FOR_SBOX;
	for (idx = 2; idx <= NUM_SBOX_IN_A_STATE; idx++)
	{
		MUL_PROB(&(MAX_PROB_POWER_TABLE[idx]), MAX_PROB_POWER_TABLE[idx - 1], MAX_PROB_FOR_SBOX);
	}
}


void SPN_Prep_Info_For_DC(void)
{
	PROB_t * PROB_DDT = NULL;

	//allocate memory for DDT
	PROB_DDT = (PROB_t*)malloc(sizeof(PROB_t) * (size_t)(SBOX_IO_CARDINALITY));
	
	Compute_Prob_DDT(PROB_DDT, SBOX, SBOX_BIT_SIZE, SBOX_BIT_SIZE);

	SPN_Prep_Info_For_DC_With_Prob_DDT(PROB_DDT);

	//free for DDT
	free(PROB_DDT);
}


//Compute DDT with complexity O(2^(n+m))
void Compute_DDT(DDT_ENTRY_t * ddt, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	CNT_t i_df_its;
	CNT_t i_its;
	CNT_t x;
	CNT_t y;
	CNT_t max_in = (CNT_t)(1 << sbox_in_bitsz) - 1;
	CNT_t max_out = (CNT_t)(1 << sbox_out_bitsz) - 1;
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			ddt[(SBOX_t)x * (CNT_t)(max_out + 1) + (SBOX_t)y] = 0;
		}
	}


	//compute DDT
#define i_df ((SBOX_t)i_df_its)
#define i_1 ((SBOX_t)i_its)
	for (i_df_its = 0; i_df_its <= max_in; i_df_its++)
	{
		//compute the differential distribution under a fixed input difference(i_df).
		for (i_its = 0; i_its <= max_in; i_its++)
		{
			SBOX_t i_2 = i_1 ^ i_df;
			SBOX_t o_1 = sbox[i_1];
			SBOX_t o_2 = sbox[i_2];
			SBOX_t o_df = o_1 ^ o_2;
			ddt[i_df*(CNT_t)(max_out + 1) + o_df]++;
		}
	}
#undef i_df
#undef i_1
	//Finish computing DDT
}

void Compute_Prob_DDT(PROB_t * prob_ddt, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	CNT_t x;
	CNT_t y;
	CNT_t max_in = (CNT_t)(1 << sbox_in_bitsz) - 1;
	CNT_t max_out = (CNT_t)(1 << sbox_out_bitsz) - 1;
	DDT_ENTRY_t * DDT = NULL;

	DDT = (DDT_ENTRY_t*)malloc(((size_t)1 << (sbox_in_bitsz + sbox_out_bitsz)) * sizeof(DDT_ENTRY_t));

	Compute_DDT(DDT, sbox, sbox_in_bitsz, sbox_out_bitsz);
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			if (DDT[(SBOX_t)x * (CNT_t)(max_out + 1) + (SBOX_t)y] != 0)
			{
				prob_ddt[(SBOX_t)x * (CNT_t)(max_out + 1) + (SBOX_t)y] = (PROB_t)log2((PROB_t)DDT[(SBOX_t)x * (max_out + 1) + (SBOX_t)y] / (1 << sbox_in_bitsz));
			}
			else
			{
				prob_ddt[(SBOX_t)x * (CNT_t)(max_out + 1) + (SBOX_t)y] = ZERO_PROB;
			}
		}
	}
	free(DDT);
}

//Compare Function for descending order.
int descending_P(const void *first, const void *second)
{
	PROB_t first_p = *((PROB_t*)first);
	PROB_t second_p = *((PROB_t*)second);
	return COMP_PROB(second_p, first_p);
}


//Compare Function for descending order.
int descending_IOP(const void *first, const void *second)
{
	const DC_I_O_PROB_t * t_first = first;
	const DC_I_O_PROB_t * t_second = second;
	PROB_t first_p = t_first->p;
	PROB_t second_p = t_second->p;
	return COMP_PROB(second_p, first_p);
}

//Compare Function for descending order.
int descending_OP(const void *first, const void *second)
{
	const DC_O_PROB_t * t_first = first;
	const DC_O_PROB_t * t_second = second;
	PROB_t first_p = t_first->p;
	PROB_t second_p = t_second->p;
	SBOX_t first_o = t_first->o;
	SBOX_t second_o = t_second->o;
	
	if (COMP_PROB(second_p, first_p) == EQUAL)
	{
		CNT_t hw_first_o = get_32word_hw(first_o);
		CNT_t hw_second_o = get_32word_hw(second_o);

		if (hw_first_o == hw_second_o)
		{
			return EQUAL;
		}
		else if (hw_first_o < hw_second_o)
		{
			return RIGHT;
		}
		//else if (hw_first_o > hw_second_o)
		//{
		return LEFT;
		//}
	}
	else
	{
		return COMP_PROB(second_p, first_p);
	}
}

//Compare Function for descending order.
int descending_IP(const void *first, const void *second)
{
	const DC_I_PROB_t * t_first = first;
	const DC_I_PROB_t * t_second = second;
	PROB_t first_p = t_first->p;
	PROB_t second_p = t_second->p;
	return COMP_PROB(second_p, first_p);
}