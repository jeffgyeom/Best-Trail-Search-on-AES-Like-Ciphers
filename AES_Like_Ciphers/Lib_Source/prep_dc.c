#include "astbb.h"
#include "dif_prob.h"
#include <string.h>

/*Global Variables*/
DC_I_O_PROB_t	**	DC_SBOXES_I_O_PROB = NULL;
NUM_t			*	NUM_I_O_WITH_NONZERO_PROB = NULL;
NUM_t			*	NUM_I_O_WITH_MAX_PROB = NULL;
DC_O_PROB_t		*** DC_SBOXES_O_PROB_FIXED_I = NULL;
SBOX_I_CNT_t	**	NUM_O_WITH_NONZERO_PROB = NULL;
SBOX_I_CNT_t	**	NUM_O_WITH_MAX_PROB = NULL;
DC_I_PROB_t		*** DC_SBOXES_I_PROB_FIXED_O = NULL;
SBOX_O_CNT_t	**	NUM_I_WITH_NONZERO_PROB = NULL;
SBOX_O_CNT_t	**	NUM_I_WITH_MAX_PROB = NULL;
DC_I_O_PROB_t	**	DC_SBOXES_I_O_PROB_FIXED_O = NULL; //this table is very special!
PROB_t				DC_1ROUND_MAX_PROB;
PROB_t			*	DC_BOUNDS_ONLY_WITH_MAX_PROB; //for convenience, the first element is always 0 and is not used
PROB_t			*	DC_BOUNDS; //for convenience, the first element is always 0 and is not used
DC_1ROUND_CHAR_t*	DC_TRAIL_IN_PROGRESS; //for convenience, the first element is never used
DC_1ROUND_CHAR_t*	DC_TRAIL_FOR_OUT; //for convenience, the first element is never used
PROB_t			*	MAX_PROB_FOR_EACH_SBOX = NULL;
PROB_t			*	MIN_PROB_FOR_EACH_SBOX = NULL;
PROB_t				MAX_PROB_FOR_WHOLE_SBOXES;
PROB_t				MIN_PROB_FOR_WHOLE_SBOXES;
PROB_t			*	MAX_PROB_POWER_TABLE = NULL;
FLAG_t				MAX_PROB_EQUAL_EVERY_SBOX = TRUE;
FLAG_t			*	FIX_IN_MAX_PROB_EQUAL = NULL;
FLAG_t				FIX_IN_MAX_PROB_EQUAL_EVERY_SBOX = TRUE;
FLAG_t			*	FIX_OU_MAX_PROB_EQUAL = NULL;
FLAG_t				FIX_OU_MAX_PROB_EQUAL_EVERY_SBOX = TRUE;
/************************************************/


/*Variables only for the current c code region*/
static NUM_t			NUM_SBOX_IN_A_STATE;
static BIT_SIZE_t		SBOX_I_WORD_BIT_SIZE;
static BIT_SIZE_t		SBOX_O_WORD_BIT_SIZE;
static SBOX_I_CNT_t		SBOX_I_CARDINALITY;
static SBOX_O_CNT_t		SBOX_O_CARDINALITY;
static CNT_t			SBOX_IO_CARDINARLITY; //SBOX_I_CARDINALITY * SBOX_O_CARDINALITY
static SBOX_O_WRD_t*	SBOXES;
typedef struct
{
	int has_been_allocated;
	int num_sboxes;
	SBOX_I_CNT_t sbox_i_num_entries;
	SBOX_O_CNT_t sbox_o_num_entries;
	int ddt_num_etnries;
	int num_round;
}DC_Allocated_Info;
static DC_Allocated_Info bf_info = { FALSE,0,0,0,0 };
/***********************************************/



/*********Additional functions************/
void DC_Prep_Memory(BLK_CIPHER_INFO_t * ci);
//Compute DDT with complexity O(2^(n+m))
void Compute_DDT(DDT_ENTRY_t * ddt, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
void Compute_Prob_DDT(PROB_t * prob_ddt, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
void Compute_Prob_Active_DDT(PROB_t * prob_ddt, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz, FLAG_t max_min);
int descending_P(const void *first, const void *second);
int descending_IOP(const void *first, const void *second);
int descending_OP(const void *first, const void *second);
int descending_IP(const void *first, const void *second);
/****************************************/

void SPN_Prep_Info_For_DC_With_Prob_DDT(BLK_CIPHER_INFO_t * ci, PROB_t ** prob_ddts)
{
	NUM_t sbox_idx;
	SBOX_I_CNT_t delta_i;
	SBOX_O_CNT_t delta_o;
	CNT_t idx;
	PROB_t the_prob;

	//General Information Setting
	NUM_SBOX_IN_A_STATE = ci->num_word_in_a_state;
	SBOX_I_WORD_BIT_SIZE = ci->sbox_i_word_bit_size;
	SBOX_O_WORD_BIT_SIZE = ci->sbox_o_word_bit_size;
	SBOX_I_CARDINALITY = 1 << SBOX_I_WORD_BIT_SIZE;
	SBOX_O_CARDINALITY = 1 << SBOX_O_WORD_BIT_SIZE;
	SBOX_IO_CARDINARLITY = SBOX_I_CARDINALITY * SBOX_O_CARDINALITY;
	SBOXES = ci->sboxes;
	/*****************************************/

	//allocate memory for extern information
	DC_Prep_Memory(ci);
	/*****************************************/



	// DDT information rearrange
	// all I_O_PROB
	// O_PROB with fixed input
	// I_PROB with fixed output
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		//rearrange
		for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
		{
			for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
			{
				//all I_O_PROB
				the_prob = prob_ddts[sbox_idx][delta_i * SBOX_O_CARDINALITY + delta_o];
				DC_SBOXES_I_O_PROB[sbox_idx][delta_i * SBOX_O_CARDINALITY + delta_o].i = (SBOX_I_WRD_t)delta_i;
				DC_SBOXES_I_O_PROB[sbox_idx][delta_i * SBOX_O_CARDINALITY + delta_o].o = (SBOX_O_WRD_t)delta_o;
				DC_SBOXES_I_O_PROB[sbox_idx][delta_i * SBOX_O_CARDINALITY + delta_o].p = (PROB_t)the_prob;
				//O_PROB with fixed input
				DC_SBOXES_O_PROB_FIXED_I[sbox_idx][delta_i][delta_o].o = (SBOX_O_WRD_t)delta_o;
				DC_SBOXES_O_PROB_FIXED_I[sbox_idx][delta_i][delta_o].p = (PROB_t)the_prob;
				//I_PROB with fixed output
				DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o][delta_i].i = (SBOX_I_WRD_t)delta_i;
				DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o][delta_i].p = (PROB_t)the_prob;
			}
		}

		//sorting all I_O_PROB
		qsort((void*)DC_SBOXES_I_O_PROB[sbox_idx], (size_t)SBOX_IO_CARDINARLITY, sizeof(DC_I_O_PROB_t), descending_IOP);

		//sorting O_PROB with fixed input
		for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
		{
			qsort((void*)DC_SBOXES_O_PROB_FIXED_I[sbox_idx][delta_i], (size_t)SBOX_O_CARDINALITY, sizeof(DC_O_PROB_t), descending_OP);
		}
		//sorting I_PROB with fixed output
		for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
		{
			qsort((void*)DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o], (size_t)SBOX_I_CARDINALITY, sizeof(DC_I_PROB_t), descending_IP);
		}
		//Get Each maximum I_O_PROB with fixed output
		for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
		{
			DC_SBOXES_I_O_PROB_FIXED_O[sbox_idx][delta_o].i = DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o][0].i;
			DC_SBOXES_I_O_PROB_FIXED_O[sbox_idx][delta_o].o = (SBOX_O_WRD_t)delta_o;
			DC_SBOXES_I_O_PROB_FIXED_O[sbox_idx][delta_o].p = DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o][0].p;
		}
		//sorting I_O_PROB with fixed output
		qsort((void*)DC_SBOXES_I_O_PROB_FIXED_O[sbox_idx], (size_t)SBOX_O_CARDINALITY, sizeof(DC_I_O_PROB_t), descending_IOP);
	}


	//Counting the numbers of each information
	/*
	*  1) The number of sbox trails which have NON-zero probability.
	*  2) The number of sbox trails which have the best probability.
	*  3) The number of sbox trails which have NON-zero probability with each fixed sbox output/input.
	*  4) The number of sbox trails which have the best probability with each fixed sbox output/input.
	*  5) The number of sbox trails which have Best probability with each fixed sbox output
	*  6) The 1Round Best Probability
	*/
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		////init
		NUM_I_O_WITH_NONZERO_PROB[sbox_idx] = 0;
		NUM_I_O_WITH_MAX_PROB[sbox_idx] = 0;
		for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
		{
			NUM_O_WITH_NONZERO_PROB[sbox_idx][delta_i] = 0;
			NUM_O_WITH_MAX_PROB[sbox_idx][delta_i] = 0;
		}
		for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
		{
			NUM_I_WITH_NONZERO_PROB[sbox_idx][delta_o] = 0;
			NUM_I_WITH_MAX_PROB[sbox_idx][delta_o] = 0;
		}

		////Counting IO_PROB
		for (idx = 0; idx < SBOX_IO_CARDINARLITY; idx++)
		{
			PROB_t IO_prob = DC_SBOXES_I_O_PROB[sbox_idx][idx].p;
			PROB_t max_IO_prob = DC_SBOXES_I_O_PROB[sbox_idx][0].p;
			if (COMP_PROB(IO_prob, ZERO_PROB) != EQUAL)
			{
				NUM_I_O_WITH_NONZERO_PROB[sbox_idx]++;
			}
			if (COMP_PROB(max_IO_prob, IO_prob) == EQUAL)
			{
				NUM_I_O_WITH_MAX_PROB[sbox_idx]++;
			}
		}

		////Counting O_PROB
		for (delta_i = 0; delta_i < SBOX_I_CARDINALITY; delta_i++)
		{
			for (idx = 0; idx < SBOX_O_CARDINALITY; idx++)
			{
				PROB_t O_prob = DC_SBOXES_O_PROB_FIXED_I[sbox_idx][delta_i][idx].p;
				PROB_t max_O_prob = DC_SBOXES_O_PROB_FIXED_I[sbox_idx][delta_i][0].p;
				if (COMP_PROB(O_prob, ZERO_PROB) != EQUAL)
				{
					NUM_O_WITH_NONZERO_PROB[sbox_idx][delta_i]++;
				}
				if (COMP_PROB(max_O_prob, O_prob) == EQUAL)
				{
					NUM_O_WITH_MAX_PROB[sbox_idx][delta_i]++;
				}
			}
		}

		////Counting I_PROB
		for (delta_o = 0; delta_o < SBOX_O_CARDINALITY; delta_o++)
		{
			for (idx = 0; idx < SBOX_I_CARDINALITY; idx++)
			{
				PROB_t I_prob = DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o][idx].p;
				PROB_t max_I_prob = DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o][0].p;
				if (COMP_PROB(I_prob, ZERO_PROB) != EQUAL)
				{
					NUM_I_WITH_NONZERO_PROB[sbox_idx][delta_o]++;
				}
				if (COMP_PROB(max_I_prob, I_prob) == EQUAL)
				{
					NUM_I_WITH_MAX_PROB[sbox_idx][delta_o]++;
				}
			}
		}
	}


	MAX_PROB_FOR_WHOLE_SBOXES = ZERO_PROB;
	MIN_PROB_FOR_WHOLE_SBOXES = ONE_PROB;
	//Computing Max/Min probability for each sbox
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		MAX_PROB_FOR_EACH_SBOX[sbox_idx] = ZERO_PROB;
		MIN_PROB_FOR_EACH_SBOX[sbox_idx] = ONE_PROB;
		for (idx = 0; idx < SBOX_I_CARDINALITY * SBOX_O_CARDINALITY; idx++)
		{
			if (DC_SBOXES_I_O_PROB[sbox_idx][idx].i != 0 || DC_SBOXES_I_O_PROB[sbox_idx][idx].o != 0)
			{
				if (COMP_PROB(MAX_PROB_FOR_EACH_SBOX[sbox_idx], DC_SBOXES_I_O_PROB[sbox_idx][idx].p) == RIGHT)
				{
					MAX_PROB_FOR_EACH_SBOX[sbox_idx] = DC_SBOXES_I_O_PROB[sbox_idx][idx].p;
				}

				if (COMP_PROB(DC_SBOXES_I_O_PROB[sbox_idx][idx].p, ZERO_PROB) != EQUAL)
				{
					if (COMP_PROB(MIN_PROB_FOR_EACH_SBOX[sbox_idx], DC_SBOXES_I_O_PROB[sbox_idx][idx].p) == LEFT)
					{
						MIN_PROB_FOR_EACH_SBOX[sbox_idx] = DC_SBOXES_I_O_PROB[sbox_idx][idx].p;
					}
				}
			}
		}

		if (COMP_PROB(MAX_PROB_FOR_WHOLE_SBOXES, MAX_PROB_FOR_EACH_SBOX[sbox_idx]) == RIGHT)
		{
			MAX_PROB_FOR_WHOLE_SBOXES = MAX_PROB_FOR_EACH_SBOX[sbox_idx];
		}

		if (COMP_PROB(MIN_PROB_FOR_WHOLE_SBOXES, MIN_PROB_FOR_EACH_SBOX[sbox_idx]) == LEFT)
		{
			MIN_PROB_FOR_WHOLE_SBOXES = MIN_PROB_FOR_EACH_SBOX[sbox_idx];
		}

	}
	//here : might change when we consider FEISTEL/*TODO*/
	DC_1ROUND_MAX_PROB = MAX_PROB_FOR_WHOLE_SBOXES;

	MAX_PROB_POWER_TABLE[0] = ONE_PROB;
	MAX_PROB_POWER_TABLE[1] = MAX_PROB_FOR_WHOLE_SBOXES;
	for (sbox_idx = 2; sbox_idx <= NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		MUL_PROB(&(MAX_PROB_POWER_TABLE[sbox_idx]), MAX_PROB_POWER_TABLE[sbox_idx - 1], MAX_PROB_FOR_WHOLE_SBOXES);
	}


	//For MAX_PROB_EQUAL_EVERY_SBOX
	MAX_PROB_EQUAL_EVERY_SBOX = TRUE;
	for (sbox_idx = 1; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		if (COMP_PROB(MAX_PROB_FOR_EACH_SBOX[0], MAX_PROB_FOR_EACH_SBOX[sbox_idx]) != EQUAL)
		{
			MAX_PROB_EQUAL_EVERY_SBOX = FALSE;
			break;
		}
	}

	//For FIX_IN_MAX_PROB_EQUAL, FIX_IN_MAX_PROB_EQUAL_EVERY_SBOX
	FIX_IN_MAX_PROB_EQUAL_EVERY_SBOX = TRUE;
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		PROB_t equal_check;
		SBOX_I_CNT_t in_idx;
		equal_check = DC_SBOXES_O_PROB_FIXED_I[sbox_idx][0x1][0].p; //first row's max
		FIX_IN_MAX_PROB_EQUAL[sbox_idx] = TRUE;
		for (in_idx = 0x2; in_idx < SBOX_I_CARDINALITY; in_idx++)
		{
			SBOX_I_WRD_t in_val = (SBOX_I_WRD_t)in_idx;
			//each row's max
			if (COMP_PROB(equal_check, DC_SBOXES_O_PROB_FIXED_I[sbox_idx][in_val][0].p) != EQUAL)
			{
				FIX_IN_MAX_PROB_EQUAL[sbox_idx] = FALSE;
				break;
			}
		}

		if (FIX_IN_MAX_PROB_EQUAL[sbox_idx] == FALSE)
		{
			FIX_IN_MAX_PROB_EQUAL_EVERY_SBOX = FALSE;
		}
	}


	//For FIX_OU_MAX_PROB_EQUAL, FIX_OU_MAX_PROB_EQUAL_EVERY_SBOX
	FIX_OU_MAX_PROB_EQUAL_EVERY_SBOX = TRUE;
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		PROB_t equal_check;
		SBOX_O_CNT_t ou_idx;
		equal_check = DC_SBOXES_I_PROB_FIXED_O[sbox_idx][0x1][0].p; //first col's max
		FIX_OU_MAX_PROB_EQUAL[sbox_idx] = TRUE;
		for (ou_idx = 0x2; ou_idx < SBOX_O_CARDINALITY; ou_idx++)
		{
			SBOX_O_WRD_t ou_val = (SBOX_O_WRD_t)ou_idx;
			//each col's max
			if (COMP_PROB(equal_check, DC_SBOXES_O_PROB_FIXED_I[sbox_idx][ou_val][0].p) != EQUAL)
			{
				FIX_OU_MAX_PROB_EQUAL[sbox_idx] = FALSE;
				break;
			}
		}

		if (FIX_OU_MAX_PROB_EQUAL[sbox_idx] == FALSE)
		{
			FIX_OU_MAX_PROB_EQUAL_EVERY_SBOX = FALSE;
		}
	}
}


void SPN_Prep_Info_For_DC(BLK_CIPHER_INFO_t * ci)
{
	NUM_t sbox_idx;
	PROB_t ** PROB_DDTs = NULL;

	//General Information Setting
	NUM_SBOX_IN_A_STATE		= ci->num_word_in_a_state;
	SBOX_I_WORD_BIT_SIZE	= ci->sbox_i_word_bit_size;
	SBOX_I_CARDINALITY		= 1 << SBOX_I_WORD_BIT_SIZE;
	SBOX_O_WORD_BIT_SIZE	= ci->sbox_o_word_bit_size;
	SBOX_O_CARDINALITY		= 1 << SBOX_O_WORD_BIT_SIZE;
	SBOXES					= ci->sboxes;
	/*****************************************/


	//allocate memory for DDTs and then compute each DDT
	PROB_DDTs = (PROB_t**)malloc(sizeof(PROB_t *) * (size_t)NUM_SBOX_IN_A_STATE);
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		PROB_DDTs[sbox_idx] = (PROB_t*)malloc(((size_t)1<<(SBOX_I_WORD_BIT_SIZE + SBOX_O_WORD_BIT_SIZE)) * sizeof(PROB_t));
		Compute_Prob_DDT(PROB_DDTs[sbox_idx], &(SBOXES[sbox_idx * SBOX_I_CARDINALITY]), SBOX_I_WORD_BIT_SIZE, SBOX_O_WORD_BIT_SIZE);
	}

	SPN_Prep_Info_For_DC_With_Prob_DDT(ci, PROB_DDTs);

	//free for DDTs
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		free(PROB_DDTs[sbox_idx]);
	}
	free(PROB_DDTs);
}

void SPN_Prep_Info_For_DC_Active(BLK_CIPHER_INFO_t * ci, FLAG_t max_min)
{
	NUM_t sbox_idx;
	PROB_t ** PROB_DDTs = NULL;

	//General Information Setting
	NUM_SBOX_IN_A_STATE = ci->num_word_in_a_state;
	SBOX_I_WORD_BIT_SIZE = ci->sbox_i_word_bit_size;
	SBOX_I_CARDINALITY = 1 << SBOX_I_WORD_BIT_SIZE;
	SBOX_O_WORD_BIT_SIZE = ci->sbox_o_word_bit_size;
	SBOX_O_CARDINALITY = 1 << SBOX_O_WORD_BIT_SIZE;
	SBOXES = ci->sboxes;
	/*****************************************/


	//allocate memory for DDTs and then compute each DDT
	PROB_DDTs = (PROB_t**)malloc(sizeof(PROB_t *) * (size_t)NUM_SBOX_IN_A_STATE);
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		PROB_DDTs[sbox_idx] = (PROB_t*)malloc(((size_t)1 << (SBOX_I_WORD_BIT_SIZE + SBOX_O_WORD_BIT_SIZE)) * sizeof(PROB_t));
		Compute_Prob_Active_DDT(PROB_DDTs[sbox_idx], &(SBOXES[sbox_idx * SBOX_I_CARDINALITY]), SBOX_I_WORD_BIT_SIZE, SBOX_O_WORD_BIT_SIZE, max_min);
	}

	SPN_Prep_Info_For_DC_With_Prob_DDT(ci, PROB_DDTs);

	//free for DDTs
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		free(PROB_DDTs[sbox_idx]);
	}
	free(PROB_DDTs);
}

void DC_Prep_Memory(BLK_CIPHER_INFO_t * ci)
{
	int sbox_idx;
	int round_idx;
	SBOX_I_CNT_t delta_i;
	SBOX_O_CNT_t delta_o;
	CNT_t sbox_i_cardinality = 1 << ci->sbox_i_word_bit_size;
	CNT_t sbox_o_cardinality = 1 << ci->sbox_o_word_bit_size;
	CNT_t sbox_io_cardinality = sbox_i_cardinality * sbox_o_cardinality;

	//If memory has been allocated before, free all of them. 
	if (bf_info.has_been_allocated == TRUE)
	{
		//abount maximum probability for each S-box
		free(MAX_PROB_FOR_EACH_SBOX);
		free(MIN_PROB_FOR_EACH_SBOX);
		//about MAX_PROB_POWER_TABLE
		free(MAX_PROB_POWER_TABLE);


		//about I_O_PROB
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			free(DC_SBOXES_I_O_PROB[sbox_idx]);
		}
		free(DC_SBOXES_I_O_PROB);
		free(NUM_I_O_WITH_NONZERO_PROB);
		free(NUM_I_O_WITH_MAX_PROB);


		//about O_PROB with a fixed input
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			for (delta_i = 0; delta_i < bf_info.sbox_i_num_entries; delta_i++)
			{
				free(DC_SBOXES_O_PROB_FIXED_I[sbox_idx][delta_i]);
			}
			free(DC_SBOXES_O_PROB_FIXED_I[sbox_idx]);
			free(NUM_O_WITH_NONZERO_PROB[sbox_idx]);
			free(NUM_O_WITH_MAX_PROB[sbox_idx]);
		}
		free(DC_SBOXES_O_PROB_FIXED_I);
		free(NUM_O_WITH_NONZERO_PROB);
		free(NUM_O_WITH_MAX_PROB);


		//about I_PROB with a fixed output
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			for (delta_o = 0; delta_o < bf_info.sbox_o_num_entries; delta_o++)
			{
				free(DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o]);
			}
			free(DC_SBOXES_I_PROB_FIXED_O[sbox_idx]);
			free(NUM_I_WITH_NONZERO_PROB[sbox_idx]);
			free(NUM_I_WITH_MAX_PROB[sbox_idx]);
		}
		free(DC_SBOXES_I_PROB_FIXED_O);
		free(NUM_I_WITH_NONZERO_PROB);
		free(NUM_I_WITH_MAX_PROB);

		//about I_O_PROB with a fixed output
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			free(DC_SBOXES_I_O_PROB_FIXED_O[sbox_idx]);
		}
		free(DC_SBOXES_I_O_PROB_FIXED_O);

		//about FIX_IN_MAX_PROB_EQUAL
		free(FIX_IN_MAX_PROB_EQUAL);
		//about FIX_OU_MAX_PROB_EQUAL
		free(FIX_OU_MAX_PROB_EQUAL);


		free(DC_BOUNDS_ONLY_WITH_MAX_PROB);
		free(DC_BOUNDS); //for convenience, the first element is always 0 and is not used
		
		for (round_idx = 0; round_idx <= bf_info.num_round; round_idx++)
		{
			free(DC_TRAIL_IN_PROGRESS[round_idx].sub_i);
			free(DC_TRAIL_IN_PROGRESS[round_idx].sub_o);
			free(DC_TRAIL_IN_PROGRESS[round_idx].dif_o);
			free(DC_TRAIL_IN_PROGRESS[round_idx].p);

			free(DC_TRAIL_FOR_OUT[round_idx].sub_i);
			free(DC_TRAIL_FOR_OUT[round_idx].sub_o);
			free(DC_TRAIL_FOR_OUT[round_idx].dif_o);
			free(DC_TRAIL_FOR_OUT[round_idx].p);
		}
		free(DC_TRAIL_IN_PROGRESS);
		free(DC_TRAIL_FOR_OUT);
	}

	//Start allocating

	//about max/min probability for each S-box
	MAX_PROB_FOR_EACH_SBOX = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)(ci->num_word_in_a_state));
	MIN_PROB_FOR_EACH_SBOX = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)(ci->num_word_in_a_state));
	MAX_PROB_POWER_TABLE = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)(ci->num_word_in_a_state + 1));


	//about I_O_PROB
	DC_SBOXES_I_O_PROB = (DC_I_O_PROB_t**)malloc(sizeof(DC_I_O_PROB_t*)*(size_t)(ci->num_word_in_a_state));
	NUM_I_O_WITH_NONZERO_PROB = (NUM_t*)malloc(sizeof(NUM_t)*(size_t)(ci->num_word_in_a_state));
	NUM_I_O_WITH_MAX_PROB = (NUM_t*)malloc(sizeof(NUM_t)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		DC_SBOXES_I_O_PROB[sbox_idx] = (DC_I_O_PROB_t*)malloc(sizeof(DC_I_O_PROB_t)*((size_t)sbox_io_cardinality));
	}



	//about O_PROB with a fixed input
	DC_SBOXES_O_PROB_FIXED_I = (DC_O_PROB_t***)malloc(sizeof(DC_O_PROB_t**)*(size_t)(ci->num_word_in_a_state));
	NUM_O_WITH_NONZERO_PROB = (SBOX_O_CNT_t**)malloc(sizeof(SBOX_O_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	NUM_O_WITH_MAX_PROB = (SBOX_O_CNT_t**)malloc(sizeof(SBOX_O_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		DC_SBOXES_O_PROB_FIXED_I[sbox_idx] = (DC_O_PROB_t**)malloc(sizeof(DC_O_PROB_t*)*(size_t)sbox_i_cardinality);
		NUM_O_WITH_NONZERO_PROB[sbox_idx] = (SBOX_O_CNT_t*)malloc(sizeof(SBOX_O_CNT_t)*(size_t)sbox_i_cardinality);
		NUM_O_WITH_MAX_PROB[sbox_idx] = (SBOX_O_CNT_t*)malloc(sizeof(SBOX_O_CNT_t)*(size_t)sbox_i_cardinality);
		for (delta_i = 0; delta_i < sbox_i_cardinality; delta_i++)
		{
			DC_SBOXES_O_PROB_FIXED_I[sbox_idx][delta_i] = (DC_O_PROB_t*)malloc(sizeof(DC_O_PROB_t)*(size_t)sbox_o_cardinality);
		}
	}

	//about I_PROB with a fixed output
	DC_SBOXES_I_PROB_FIXED_O = (DC_I_PROB_t***)malloc(sizeof(DC_I_PROB_t**)*(size_t)(ci->num_word_in_a_state));
	NUM_I_WITH_NONZERO_PROB = (SBOX_I_CNT_t**)malloc(sizeof(SBOX_I_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	NUM_I_WITH_MAX_PROB = (SBOX_I_CNT_t**)malloc(sizeof(SBOX_I_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		DC_SBOXES_I_PROB_FIXED_O[sbox_idx] = (DC_I_PROB_t**)malloc(sizeof(DC_I_PROB_t*)*(size_t)sbox_o_cardinality);
		NUM_I_WITH_NONZERO_PROB[sbox_idx] = (SBOX_I_CNT_t*)malloc(sizeof(SBOX_I_CNT_t)*(size_t)sbox_o_cardinality);
		NUM_I_WITH_MAX_PROB[sbox_idx] = (SBOX_I_CNT_t*)malloc(sizeof(SBOX_I_CNT_t)*(size_t)sbox_o_cardinality);
		for (delta_o = 0; delta_o < sbox_o_cardinality; delta_o++)
		{
			DC_SBOXES_I_PROB_FIXED_O[sbox_idx][delta_o] = (DC_I_PROB_t*)malloc(sizeof(DC_I_PROB_t)*(size_t)sbox_i_cardinality);
		}
	}

	//about I_O_PROB with a fixed output
	DC_SBOXES_I_O_PROB_FIXED_O = (DC_I_O_PROB_t**)malloc(sizeof(DC_I_O_PROB_t*)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		DC_SBOXES_I_O_PROB_FIXED_O[sbox_idx] = (DC_I_O_PROB_t*)malloc(sizeof(DC_I_O_PROB_t)*((size_t)sbox_o_cardinality));
	}

	//about FIX_IN_MAX_PROB_EQUAL
	FIX_IN_MAX_PROB_EQUAL = (FLAG_t*)malloc(sizeof(FLAG_t)*((size_t)ci->num_word_in_a_state));
	//about FIX_OU_MAX_PROB_EQUAL
	FIX_OU_MAX_PROB_EQUAL = (FLAG_t*)malloc(sizeof(FLAG_t)*((size_t)ci->num_word_in_a_state));

	DC_BOUNDS_ONLY_WITH_MAX_PROB = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used
	DC_BOUNDS = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used
	
	DC_TRAIL_IN_PROGRESS = (DC_1ROUND_CHAR_t*)malloc(sizeof(DC_1ROUND_CHAR_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used
	DC_TRAIL_FOR_OUT = (DC_1ROUND_CHAR_t*)malloc(sizeof(DC_1ROUND_CHAR_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used

	for (round_idx = 0; round_idx <= ci->num_round; round_idx++)
	{
		DC_TRAIL_IN_PROGRESS[round_idx].sub_i = (SBOX_I_WRD_t*)malloc(sizeof(SBOX_I_WRD_t)*(size_t)(ci->num_word_in_a_state));
		DC_TRAIL_IN_PROGRESS[round_idx].sub_o = (SBOX_O_WRD_t*)malloc(sizeof(SBOX_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		DC_TRAIL_IN_PROGRESS[round_idx].dif_o = (DIFF_O_WRD_t*)malloc(sizeof(DIFF_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		DC_TRAIL_IN_PROGRESS[round_idx].p     = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)(ci->num_word_in_a_state));

		DC_TRAIL_FOR_OUT[round_idx].sub_i = (SBOX_I_WRD_t*)malloc(sizeof(SBOX_I_WRD_t)*(size_t)(ci->num_word_in_a_state));
		DC_TRAIL_FOR_OUT[round_idx].sub_o = (SBOX_O_WRD_t*)malloc(sizeof(SBOX_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		DC_TRAIL_FOR_OUT[round_idx].dif_o = (DIFF_O_WRD_t*)malloc(sizeof(DIFF_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		DC_TRAIL_FOR_OUT[round_idx].p = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)(ci->num_word_in_a_state));
	}


	bf_info.has_been_allocated = TRUE;
	bf_info.num_sboxes = ci->num_word_in_a_state;
	bf_info.sbox_i_num_entries = sbox_i_cardinality;
	bf_info.sbox_o_num_entries = sbox_o_cardinality;
	bf_info.ddt_num_etnries = sbox_io_cardinality;
	bf_info.num_round = ci->num_round;
}



//Compute DDT with complexity O(2^(n+m))
void Compute_DDT(DDT_ENTRY_t * ddt, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	SBOX_I_CNT_t i_df_its;
	SBOX_I_CNT_t i_its;
	SBOX_I_CNT_t x;
	SBOX_O_CNT_t y;
	SBOX_I_CNT_t max_in = (SBOX_I_CNT_t)(1 << sbox_in_bitsz) - 1;
	SBOX_O_CNT_t max_out = (SBOX_O_CNT_t)(1 << sbox_out_bitsz) - 1;
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			ddt[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] = 0;
		}
	}


	//compute DDT
#define i_df ((SBOX_I_WRD_t)i_df_its)
#define i_1 ((SBOX_I_WRD_t)i_its)
	for (i_df_its = 0; i_df_its <= max_in; i_df_its++)
	{
		//compute the differential distribution under a fixed input difference(i_df).
		for (i_its = 0; i_its <= max_in; i_its++)
		{
			SBOX_I_WRD_t i_2 = i_1 ^ i_df;
			SBOX_O_WRD_t o_1 = sbox[i_1];
			SBOX_O_WRD_t o_2 = sbox[i_2];
			SBOX_O_WRD_t o_df = o_1 ^ o_2;
			ddt[i_df*(SBOX_O_CNT_t)(max_out + 1) + o_df]++;
		}
	}
#undef i_df
#undef i_1
	//Finish computing DDT
}

void Compute_Prob_DDT(PROB_t * prob_ddt, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	SBOX_I_CNT_t x;
	SBOX_O_CNT_t y;
	SBOX_I_CNT_t max_in = (SBOX_I_CNT_t)(1 << sbox_in_bitsz) - 1;
	SBOX_O_CNT_t max_out = (SBOX_O_CNT_t)(1 << sbox_out_bitsz) - 1;
	DDT_ENTRY_t * DDT = NULL;

	DDT = (DDT_ENTRY_t*)malloc(((size_t)1 << (sbox_in_bitsz + sbox_out_bitsz)) * sizeof(DDT_ENTRY_t));

	Compute_DDT(DDT, sbox, sbox_in_bitsz, sbox_out_bitsz);
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			if (DDT[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] != 0)
			{
				prob_ddt[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] = (PROB_t)log2((PROB_t)DDT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] / (1 << sbox_in_bitsz));
			}
			else
			{
				prob_ddt[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] = ZERO_PROB;
			}
		}
	}
	free(DDT);
}

void Compute_Prob_Active_DDT(PROB_t * prob_ddt, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz, FLAG_t max_min)
{
	SBOX_I_CNT_t x;
	SBOX_O_CNT_t y;
	SBOX_I_CNT_t max_in = (SBOX_I_CNT_t)(1 << sbox_in_bitsz) - 1;
	SBOX_O_CNT_t max_out = (SBOX_O_CNT_t)(1 << sbox_out_bitsz) - 1;
	DDT_ENTRY_t * DDT = NULL;
	PROB_t max_min_value;

	if (max_min == USING_MIN_PROB)
	{
		max_min_value = ONE_PROB;
	}
	else // if (max_min == USING_MAX_PROB)
	{
		max_min_value = ZERO_PROB;
	}


	DDT = (DDT_ENTRY_t*)malloc(((size_t)1 << (sbox_in_bitsz + sbox_out_bitsz)) * sizeof(DDT_ENTRY_t));

	Compute_DDT(DDT, sbox, sbox_in_bitsz, sbox_out_bitsz);
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			if (DDT[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] != 0)
			{
				PROB_t prob_entry = (PROB_t)log2((PROB_t)DDT[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] / (1 << sbox_in_bitsz));

				if (max_min == USING_MIN_PROB)
				{
					if (COMP_PROB(max_min_value, prob_entry) == LEFT)
					{
						max_min_value = prob_entry;
					}
				}
				else // if (max_min == USING_MAX_PROB)
				{
					if ((x != 0) || (y != 0))
					{
						if (COMP_PROB(max_min_value, prob_entry) == RIGHT)
						{
							max_min_value = prob_entry;
						}
					}
				}
			}
		}
	}

	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			if (DDT[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] != 0)
			{
				if ((x == 0) && (y == 0))
				{
					prob_ddt[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] = ONE_PROB;
				}
				else
				{
					prob_ddt[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] = max_min_value;
				}	
			}
			else
			{
				prob_ddt[(SBOX_I_WRD_t)x * (SBOX_O_CNT_t)(max_out + 1) + (SBOX_O_WRD_t)y] = ZERO_PROB;
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
	SBOX_O_WRD_t first_o = t_first->o;
	SBOX_O_WRD_t second_o = t_second->o;
	
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