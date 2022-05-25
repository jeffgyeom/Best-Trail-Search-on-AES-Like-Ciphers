#include "astbb.h"
#include "lin_corr.h"
#include <stdio.h>
#include <string.h>
#include <immintrin.h>

/*Global Variables*/

LC_I_O_CORR_t	**	LC_SBOXES_I_O_CORR = NULL;
NUM_t			*	NUM_I_O_WITH_NONZERO_CORR = NULL;
NUM_t			*	NUM_I_O_WITH_MAX_CORR = NULL;
LC_O_CORR_t		*** LC_SBOXES_O_CORR_FIXED_I = NULL;
SBOX_I_CNT_t	**	NUM_O_WITH_NONZERO_CORR = NULL;
SBOX_I_CNT_t	**	NUM_O_WITH_MAX_CORR = NULL;
LC_I_CORR_t		*** LC_SBOXES_I_CORR_FIXED_O = NULL;
SBOX_O_CNT_t	**	NUM_I_WITH_NONZERO_CORR = NULL;
SBOX_O_CNT_t	**	NUM_I_WITH_MAX_CORR = NULL;
LC_I_O_CORR_t	**	LC_SBOXES_I_O_CORR_FIXED_O = NULL; //this table is very special!
CORR_t				LC_1ROUND_MAX_CORR;
CORR_t			*	LC_BOUNDS_ONLY_WITH_MAX_CORR; //for convenience, the first element is always 0 and is not used
CORR_t			*	LC_BOUNDS; //for convenience, the first element is always 0 and is not used
LC_1ROUND_CHAR_t*	LC_TRAIL_IN_PROGRESS; //for convenience, the first element is always 0 and is not used
LC_1ROUND_CHAR_t*	LC_TRAIL_FOR_OUT; //for convenience, the first element is always 0 and is not used
CORR_t			*	MAX_CORR_FOR_EACH_SBOX = NULL;
CORR_t			*	MIN_CORR_FOR_EACH_SBOX = NULL;
CORR_t				MAX_CORR_FOR_WHOLE_SBOXES;
CORR_t				MIN_CORR_FOR_WHOLE_SBOXES;
CORR_t			*	MAX_CORR_POWER_TABLE = NULL;
FLAG_t			 	MAX_CORR_EQUAL_EVERY_SBOX = TRUE;
FLAG_t			*	FIX_IN_MAX_CORR_EQUAL = NULL;
FLAG_t				FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX = TRUE;
FLAG_t			*	FIX_OU_MAX_CORR_EQUAL = NULL;
FLAG_t				FIX_OU_MAX_CORR_EQUAL_EVERY_SBOX = TRUE;


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
	int lat_num_etnries;
	int num_round;
}LC_Allocated_Info;
static LC_Allocated_Info bf_info = { FALSE,0,0,0,0 };
/***********************************************/


/*********Additional functions************/
void LC_Prep_Memory(BLK_CIPHER_INFO_t * ci);
void Compute_LAT(LAT_ENTRY_t * lat, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
void Compute_Corr_LAT(CORR_t * corr_lat, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
void Compute_Corr_Active_LAT(CORR_t * corr_lat, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz, FLAG_t max_min);
int descending_C(const void *first, const void *second);
int descending_IOC(const void *first, const void *second);
int descending_OC(const void *first, const void *second);
int descending_IC(const void *first, const void *second);
/****************************************/

void SPN_Prep_Info_For_LC_With_Corr_LAT(BLK_CIPHER_INFO_t * ci, CORR_t ** corr_lats)
{
	NUM_t sbox_idx;
	SBOX_I_CNT_t mask_i;
	SBOX_O_CNT_t mask_o;
	CNT_t idx;
	CORR_t the_corr;

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
	LC_Prep_Memory(ci);
	/*****************************************/



	// LAT information rearrange
	// all I_O_CORR
	// O_CORR with fixed input
	// I_CORR with fixed output
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		//rearrange
		for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
		{
			for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
			{
				//all I_O_CORR
				the_corr = corr_lats[sbox_idx][mask_i * SBOX_O_CARDINALITY + mask_o];
				LC_SBOXES_I_O_CORR[sbox_idx][mask_i * SBOX_O_CARDINALITY + mask_o].i = (SBOX_I_WRD_t)mask_i;
				LC_SBOXES_I_O_CORR[sbox_idx][mask_i * SBOX_O_CARDINALITY + mask_o].o = (SBOX_O_WRD_t)mask_o;
				LC_SBOXES_I_O_CORR[sbox_idx][mask_i * SBOX_O_CARDINALITY + mask_o].c.sign = the_corr.sign;
				LC_SBOXES_I_O_CORR[sbox_idx][mask_i * SBOX_O_CARDINALITY + mask_o].c.magnitude = the_corr.magnitude;
				//O_CORR with fixed input
				LC_SBOXES_O_CORR_FIXED_I[sbox_idx][mask_i][mask_o].o = (SBOX_O_WRD_t)mask_o;
				LC_SBOXES_O_CORR_FIXED_I[sbox_idx][mask_i][mask_o].c = the_corr;
				//I_CORR with fixed output
				LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o][mask_i].i = (SBOX_I_WRD_t)mask_i;
				LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o][mask_i].c = the_corr;
			}
		}

		//sorting all I_O_CORR
		qsort((void*)LC_SBOXES_I_O_CORR[sbox_idx], (size_t)SBOX_IO_CARDINARLITY, sizeof(LC_I_O_CORR_t), descending_IOC);

		//sorting O_CORR with fixed input
		for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
		{
			qsort((void*)LC_SBOXES_O_CORR_FIXED_I[sbox_idx][mask_i], (size_t)SBOX_O_CARDINALITY, sizeof(LC_O_CORR_t), descending_OC);
		}
		//sorting I_CORR with fixed output
		for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
		{
			qsort((void*)LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o], (size_t)SBOX_I_CARDINALITY, sizeof(LC_I_CORR_t), descending_IC);
		}
		//Get Each maximum I_O_CORR with fixed output
		for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
		{
			LC_SBOXES_I_O_CORR_FIXED_O[sbox_idx][mask_o].i = LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o][0].i;
			LC_SBOXES_I_O_CORR_FIXED_O[sbox_idx][mask_o].o = (SBOX_O_WRD_t)mask_o;
			LC_SBOXES_I_O_CORR_FIXED_O[sbox_idx][mask_o].c = LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o][0].c;
		}
		//sorting I_O_PROB with fixed output
		qsort((void*)LC_SBOXES_I_O_CORR_FIXED_O[sbox_idx], (size_t)SBOX_O_CARDINALITY, sizeof(LC_I_O_CORR_t), descending_IOC);
	}


	//Counting the numbers of each information
	/*
	*  1) The number of sbox trails which have NON-zero correlation.
	*  2) The number of sbox trails which have the best correlation.
	*  3) The number of sbox trails which have NON-zero correlation with each fixed sbox output/input.
	*  4) The number of sbox trails which have the best correlation with each fixed sbox output/input.
	*  5) The number of sbox trails which have Best correlation with each fixed sbox output
	*  6) The 1Round Best Correlation
	*/
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		////init
		NUM_I_O_WITH_NONZERO_CORR[sbox_idx] = 0;
		NUM_I_O_WITH_MAX_CORR[sbox_idx] = 0;
		for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
		{
			NUM_O_WITH_NONZERO_CORR[sbox_idx][mask_i] = 0;
			NUM_O_WITH_MAX_CORR[sbox_idx][mask_i] = 0;
		}
		for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
		{
			NUM_I_WITH_NONZERO_CORR[sbox_idx][mask_o] = 0;
			NUM_I_WITH_MAX_CORR[sbox_idx][mask_o] = 0;
		}

		////Counting IO_CORR
		for (idx = 0; idx < SBOX_IO_CARDINARLITY; idx++)
		{
			CORR_t IO_corr = LC_SBOXES_I_O_CORR[sbox_idx][idx].c;
			CORR_t max_IO_corr = LC_SBOXES_I_O_CORR[sbox_idx][0].c;
			if (COMP_CORR(IO_corr, ZERO_CORR) != EQUAL)
			{
				NUM_I_O_WITH_NONZERO_CORR[sbox_idx]++;
			}
			if (COMP_CORR(max_IO_corr, IO_corr) == EQUAL)
			{
				NUM_I_O_WITH_MAX_CORR[sbox_idx]++;
			}
		}

		////Counting O_CORR
		for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
		{
			for (idx = 0; idx < SBOX_O_CARDINALITY; idx++)
			{
				CORR_t O_corr = LC_SBOXES_O_CORR_FIXED_I[sbox_idx][mask_i][idx].c;
				CORR_t max_O_corr = LC_SBOXES_O_CORR_FIXED_I[sbox_idx][mask_i][0].c;
				if (COMP_CORR(O_corr, ZERO_CORR) != EQUAL)
				{
					NUM_O_WITH_NONZERO_CORR[sbox_idx][mask_i]++;
				}
				if (COMP_CORR(max_O_corr, O_corr) == EQUAL)
				{
					NUM_O_WITH_MAX_CORR[sbox_idx][mask_i]++;
				}
			}
		}

		////Counting I_CORR
		for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
		{
			for (idx = 0; idx < SBOX_I_CARDINALITY; idx++)
			{
				CORR_t I_corr = LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o][idx].c;
				CORR_t max_I_corr = LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o][0].c;
				if (COMP_CORR(I_corr, ZERO_CORR) != EQUAL)
				{
					NUM_I_WITH_NONZERO_CORR[sbox_idx][mask_o]++;
				}
				if (COMP_CORR(max_I_corr, I_corr) == EQUAL)
				{
					NUM_I_WITH_MAX_CORR[sbox_idx][mask_o]++;
				}
			}
		}
	}


	MAX_CORR_FOR_WHOLE_SBOXES = ZERO_CORR;
	MIN_CORR_FOR_WHOLE_SBOXES = ONE_CORR;
	//Computing Max/Min correlation for each sbox
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		MAX_CORR_FOR_EACH_SBOX[sbox_idx] = ZERO_CORR;
		MIN_CORR_FOR_EACH_SBOX[sbox_idx] = ONE_CORR;
		for (idx = 0; idx < SBOX_I_CARDINALITY * SBOX_O_CARDINALITY; idx++)
		{
			if (LC_SBOXES_I_O_CORR[sbox_idx][idx].i != 0 || LC_SBOXES_I_O_CORR[sbox_idx][idx].o != 0)
			{
				if (COMP_CORR(MAX_CORR_FOR_EACH_SBOX[sbox_idx], LC_SBOXES_I_O_CORR[sbox_idx][idx].c) == RIGHT)
				{
					MAX_CORR_FOR_EACH_SBOX[sbox_idx] = LC_SBOXES_I_O_CORR[sbox_idx][idx].c;
				}

				if (COMP_CORR(LC_SBOXES_I_O_CORR[sbox_idx][idx].c, ZERO_CORR) != EQUAL)
				{
					if (COMP_CORR(MIN_CORR_FOR_EACH_SBOX[sbox_idx], LC_SBOXES_I_O_CORR[sbox_idx][idx].c) == LEFT)
					{
						MIN_CORR_FOR_EACH_SBOX[sbox_idx] = LC_SBOXES_I_O_CORR[sbox_idx][idx].c;
					}
				}
			}
		}

		if (COMP_CORR(MAX_CORR_FOR_WHOLE_SBOXES, MAX_CORR_FOR_EACH_SBOX[sbox_idx]) == RIGHT)
		{
			MAX_CORR_FOR_WHOLE_SBOXES = MAX_CORR_FOR_EACH_SBOX[sbox_idx];
		}

		if (COMP_CORR(MIN_CORR_FOR_WHOLE_SBOXES, MIN_CORR_FOR_EACH_SBOX[sbox_idx]) == LEFT)
		{
			MIN_CORR_FOR_WHOLE_SBOXES = MIN_CORR_FOR_EACH_SBOX[sbox_idx];
		}

	}
	//here : might change when we consider FEISTEL/*TODO*/
	LC_1ROUND_MAX_CORR = MAX_CORR_FOR_WHOLE_SBOXES;

	MAX_CORR_POWER_TABLE[0] = ONE_CORR;
	MAX_CORR_POWER_TABLE[1] = MAX_CORR_FOR_WHOLE_SBOXES;
	for (sbox_idx = 2; sbox_idx <= NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		MUL_CORR(&(MAX_CORR_POWER_TABLE[sbox_idx]), MAX_CORR_POWER_TABLE[sbox_idx - 1], MAX_CORR_FOR_WHOLE_SBOXES);
	}

	//For MAX_CORR_EQUAL_EVERY_SBOX
	MAX_CORR_EQUAL_EVERY_SBOX = TRUE;
	for (sbox_idx = 1; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		if (COMP_CORR(MAX_CORR_FOR_EACH_SBOX[0], MAX_CORR_FOR_EACH_SBOX[sbox_idx]) != EQUAL)
		{
			MAX_CORR_EQUAL_EVERY_SBOX = FALSE;
			break;
		}
	}

	//For FIX_IN_MAX_CORR_EQUAL, FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX
	FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX = TRUE;
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		CORR_t equal_check;
		SBOX_I_CNT_t in_idx;
		equal_check = LC_SBOXES_O_CORR_FIXED_I[sbox_idx][0x1][0].c; //first row's max
		FIX_IN_MAX_CORR_EQUAL[sbox_idx] = TRUE;
		for (in_idx = 0x2; in_idx < SBOX_I_CARDINALITY; in_idx++)
		{
			SBOX_I_WRD_t in_val = (SBOX_I_WRD_t)in_idx;
			//each row's max
			if (COMP_CORR(equal_check, LC_SBOXES_O_CORR_FIXED_I[sbox_idx][in_val][0].c) != EQUAL)
			{
				FIX_IN_MAX_CORR_EQUAL[sbox_idx] = FALSE;
				break;
			}
		}

		if (FIX_IN_MAX_CORR_EQUAL[sbox_idx] == FALSE)
		{
			FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX = FALSE;
		}
	}


	//For FIX_OU_MAX_CORR_EQUAL, FIX_OU_MAX_CORR_EQUAL_EVERY_SBOX
	FIX_OU_MAX_CORR_EQUAL_EVERY_SBOX = TRUE;
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		CORR_t equal_check;
		SBOX_O_CNT_t ou_idx;
		equal_check = LC_SBOXES_I_CORR_FIXED_O[sbox_idx][0x1][0].c;  //first col's max
		FIX_OU_MAX_CORR_EQUAL[sbox_idx] = TRUE;
		for (ou_idx = 0x2; ou_idx < SBOX_O_CARDINALITY; ou_idx++)
		{
			SBOX_O_WRD_t ou_val = (SBOX_O_WRD_t)ou_idx;
			//each col's max
			if (COMP_CORR(equal_check, LC_SBOXES_O_CORR_FIXED_I[sbox_idx][ou_val][0].c) != EQUAL)
			{
				FIX_OU_MAX_CORR_EQUAL[sbox_idx] = FALSE;
				break;
			}
		}

		if (FIX_OU_MAX_CORR_EQUAL[sbox_idx] == FALSE)
		{
			FIX_OU_MAX_CORR_EQUAL_EVERY_SBOX = FALSE;
		}
	}

}


void SPN_Prep_Info_For_LC(BLK_CIPHER_INFO_t * ci)
{
	NUM_t sbox_idx;
	CORR_t ** CORR_LATs = NULL;

	//General Information Setting
	NUM_SBOX_IN_A_STATE = ci->num_word_in_a_state;
	SBOX_I_WORD_BIT_SIZE = ci->sbox_i_word_bit_size;
	SBOX_I_CARDINALITY = 1 << SBOX_I_WORD_BIT_SIZE;
	SBOX_O_WORD_BIT_SIZE = ci->sbox_o_word_bit_size;
	SBOX_O_CARDINALITY = 1 << SBOX_O_WORD_BIT_SIZE;
	SBOXES = ci->sboxes;
	/*****************************************/


	//allocate memory for LATs and then compute each LAT
	CORR_LATs = (CORR_t**)malloc(sizeof(CORR_t *) * (size_t)NUM_SBOX_IN_A_STATE);
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		CORR_LATs[sbox_idx] = (CORR_t*)malloc(((size_t)1 << (SBOX_I_WORD_BIT_SIZE + SBOX_O_WORD_BIT_SIZE)) * sizeof(CORR_t));
		Compute_Corr_LAT(CORR_LATs[sbox_idx], &(SBOXES[sbox_idx * SBOX_I_CARDINALITY]), SBOX_I_WORD_BIT_SIZE, SBOX_O_WORD_BIT_SIZE);
	}

	SPN_Prep_Info_For_LC_With_Corr_LAT(ci, CORR_LATs);

	//free for LATs
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		free(CORR_LATs[sbox_idx]);
	}
	free(CORR_LATs);
}


void SPN_Prep_Info_For_LC_Active(BLK_CIPHER_INFO_t * ci, FLAG_t max_min)
{
	NUM_t sbox_idx;
	CORR_t ** CORR_LATs = NULL;

	//General Information Setting
	NUM_SBOX_IN_A_STATE = ci->num_word_in_a_state;
	SBOX_I_WORD_BIT_SIZE = ci->sbox_i_word_bit_size;
	SBOX_I_CARDINALITY = 1 << SBOX_I_WORD_BIT_SIZE;
	SBOX_O_WORD_BIT_SIZE = ci->sbox_o_word_bit_size;
	SBOX_O_CARDINALITY = 1 << SBOX_O_WORD_BIT_SIZE;
	SBOXES = ci->sboxes;
	/*****************************************/


	//allocate memory for LATs and then compute each LAT
	CORR_LATs = (CORR_t**)malloc(sizeof(CORR_t *) * (size_t)NUM_SBOX_IN_A_STATE);
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		CORR_LATs[sbox_idx] = (CORR_t*)malloc(((size_t)1 << (SBOX_I_WORD_BIT_SIZE + SBOX_O_WORD_BIT_SIZE)) * sizeof(CORR_t));
		Compute_Corr_Active_LAT(CORR_LATs[sbox_idx], &(SBOXES[sbox_idx * SBOX_I_CARDINALITY]), SBOX_I_WORD_BIT_SIZE, SBOX_O_WORD_BIT_SIZE, max_min);
	}

	SPN_Prep_Info_For_LC_With_Corr_LAT(ci, CORR_LATs);

	//free for LATs
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		free(CORR_LATs[sbox_idx]);
	}
	free(CORR_LATs);
}



void LC_Prep_Memory(BLK_CIPHER_INFO_t * ci)
{
	int sbox_idx;
	int round_idx;
	SBOX_I_CNT_t mask_i;
	SBOX_O_CNT_t mask_o;
	CNT_t sbox_i_cardinality = 1 << ci->sbox_i_word_bit_size;
	CNT_t sbox_o_cardinality = 1 << ci->sbox_o_word_bit_size;
	CNT_t sbox_io_cardinality = sbox_i_cardinality * sbox_o_cardinality;

	//If memory has been allocated before, free all of them. 
	if (bf_info.has_been_allocated == TRUE)
	{
		//abount maximum correlation for each S-box
		free(MAX_CORR_FOR_EACH_SBOX);
		free(MIN_CORR_FOR_EACH_SBOX);
		//about MAX_CORR_POWER_TABLE
		free(MAX_CORR_POWER_TABLE);


		//about I_O_CORR
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			free(LC_SBOXES_I_O_CORR[sbox_idx]);
		}
		free(LC_SBOXES_I_O_CORR);
		free(NUM_I_O_WITH_NONZERO_CORR);
		free(NUM_I_O_WITH_MAX_CORR);


		//about O_CORR with a fixed input
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			for (mask_i = 0; mask_i < bf_info.sbox_i_num_entries; mask_i++)
			{
				free(LC_SBOXES_O_CORR_FIXED_I[sbox_idx][mask_i]);
			}
			free(LC_SBOXES_O_CORR_FIXED_I[sbox_idx]);
			free(NUM_O_WITH_NONZERO_CORR[sbox_idx]);
			free(NUM_O_WITH_MAX_CORR[sbox_idx]);
		}
		free(LC_SBOXES_O_CORR_FIXED_I);
		free(NUM_O_WITH_NONZERO_CORR);
		free(NUM_O_WITH_MAX_CORR);


		//about I_CORR with a fixed output
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			for (mask_o = 0; mask_o < bf_info.sbox_o_num_entries; mask_o++)
			{
				free(LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o]);
			}
			free(LC_SBOXES_I_CORR_FIXED_O[sbox_idx]);
			free(NUM_I_WITH_NONZERO_CORR[sbox_idx]);
			free(NUM_I_WITH_MAX_CORR[sbox_idx]);
		}
		free(LC_SBOXES_I_CORR_FIXED_O);
		free(NUM_I_WITH_NONZERO_CORR);
		free(NUM_I_WITH_MAX_CORR);

		//about I_O_CORR with a fixed output
		for (sbox_idx = 0; sbox_idx < bf_info.num_sboxes; sbox_idx++)
		{
			free(LC_SBOXES_I_O_CORR_FIXED_O[sbox_idx]);
		}
		free(LC_SBOXES_I_O_CORR_FIXED_O);

		//about FIX_IN_MAX_CORR_EQUAL
		free(FIX_IN_MAX_CORR_EQUAL);
		//about FIX_OU_MAX_CORR_EQUAL
		free(FIX_OU_MAX_CORR_EQUAL);


		free(LC_BOUNDS_ONLY_WITH_MAX_CORR);
		free(LC_BOUNDS); //for convenience, the first element is always 0 and is not used

		for (round_idx = 0; round_idx <= bf_info.num_round; round_idx++)
		{
			free(LC_TRAIL_IN_PROGRESS[round_idx].sub_i);
			free(LC_TRAIL_IN_PROGRESS[round_idx].sub_o);
			free(LC_TRAIL_IN_PROGRESS[round_idx].dif_o);
			free(LC_TRAIL_IN_PROGRESS[round_idx].c);

			free(LC_TRAIL_FOR_OUT[round_idx].sub_i);
			free(LC_TRAIL_FOR_OUT[round_idx].sub_o);
			free(LC_TRAIL_FOR_OUT[round_idx].dif_o);
			free(LC_TRAIL_FOR_OUT[round_idx].c);
		}
		free(LC_TRAIL_IN_PROGRESS);
		free(LC_TRAIL_FOR_OUT);
	}

	//Start allocating

	//about max/min correlation for each S-box
	MAX_CORR_FOR_EACH_SBOX = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)(ci->num_word_in_a_state));
	MIN_CORR_FOR_EACH_SBOX = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)(ci->num_word_in_a_state));
	MAX_CORR_POWER_TABLE = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)(ci->num_word_in_a_state + 1));


	//about I_O_CORR
	LC_SBOXES_I_O_CORR = (LC_I_O_CORR_t**)malloc(sizeof(LC_I_O_CORR_t*)*(size_t)(ci->num_word_in_a_state));
	NUM_I_O_WITH_NONZERO_CORR = (NUM_t*)malloc(sizeof(NUM_t)*(size_t)(ci->num_word_in_a_state));
	NUM_I_O_WITH_MAX_CORR = (NUM_t*)malloc(sizeof(NUM_t)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		LC_SBOXES_I_O_CORR[sbox_idx] = (LC_I_O_CORR_t*)malloc(sizeof(LC_I_O_CORR_t)*((size_t)sbox_io_cardinality));
	}


	//about O_CORR with a fixed input
	LC_SBOXES_O_CORR_FIXED_I = (LC_O_CORR_t***)malloc(sizeof(LC_O_CORR_t**)*(size_t)(ci->num_word_in_a_state));
	NUM_O_WITH_NONZERO_CORR = (SBOX_O_CNT_t**)malloc(sizeof(SBOX_O_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	NUM_O_WITH_MAX_CORR = (SBOX_O_CNT_t**)malloc(sizeof(SBOX_O_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		LC_SBOXES_O_CORR_FIXED_I[sbox_idx] = (LC_O_CORR_t**)malloc(sizeof(LC_O_CORR_t*)*(size_t)sbox_i_cardinality);
		NUM_O_WITH_NONZERO_CORR[sbox_idx] = (SBOX_O_CNT_t*)malloc(sizeof(SBOX_O_CNT_t)*(size_t)sbox_i_cardinality);
		NUM_O_WITH_MAX_CORR[sbox_idx] = (SBOX_O_CNT_t*)malloc(sizeof(SBOX_O_CNT_t)*(size_t)sbox_i_cardinality);
		for (mask_i = 0; mask_i < sbox_i_cardinality; mask_i++)
		{
			LC_SBOXES_O_CORR_FIXED_I[sbox_idx][mask_i] = (LC_O_CORR_t*)malloc(sizeof(LC_O_CORR_t)*(size_t)sbox_o_cardinality);
		}
	}

	//about I_CORR with a fixed output
	LC_SBOXES_I_CORR_FIXED_O = (LC_I_CORR_t***)malloc(sizeof(LC_I_CORR_t**)*(size_t)(ci->num_word_in_a_state));
	NUM_I_WITH_NONZERO_CORR = (SBOX_I_CNT_t**)malloc(sizeof(SBOX_I_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	NUM_I_WITH_MAX_CORR = (SBOX_I_CNT_t**)malloc(sizeof(SBOX_I_CNT_t*)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		LC_SBOXES_I_CORR_FIXED_O[sbox_idx] = (LC_I_CORR_t**)malloc(sizeof(LC_I_CORR_t*)*(size_t)sbox_o_cardinality);
		NUM_I_WITH_NONZERO_CORR[sbox_idx] = (SBOX_I_CNT_t*)malloc(sizeof(SBOX_I_CNT_t)*(size_t)sbox_o_cardinality);
		NUM_I_WITH_MAX_CORR[sbox_idx] = (SBOX_I_CNT_t*)malloc(sizeof(SBOX_I_CNT_t)*(size_t)sbox_o_cardinality);
		for (mask_o = 0; mask_o < sbox_o_cardinality; mask_o++)
		{
			LC_SBOXES_I_CORR_FIXED_O[sbox_idx][mask_o] = (LC_I_CORR_t*)malloc(sizeof(LC_I_CORR_t)*(size_t)sbox_i_cardinality);
		}
	}

	//about I_O_CORR with a fixed output
	LC_SBOXES_I_O_CORR_FIXED_O = (LC_I_O_CORR_t**)malloc(sizeof(LC_I_O_CORR_t*)*(size_t)(ci->num_word_in_a_state));
	for (sbox_idx = 0; sbox_idx < ci->num_word_in_a_state; sbox_idx++)
	{
		LC_SBOXES_I_O_CORR_FIXED_O[sbox_idx] = (LC_I_O_CORR_t*)malloc(sizeof(LC_I_O_CORR_t)*((size_t)sbox_o_cardinality));
	}

	//about FIX_IN_MAX_CORR_EQUAL
	FIX_IN_MAX_CORR_EQUAL = (FLAG_t*)malloc(sizeof(FLAG_t)*((size_t)ci->num_word_in_a_state));
	//about FIX_OU_MAX_CORR_EQUAL
	FIX_OU_MAX_CORR_EQUAL = (FLAG_t*)malloc(sizeof(FLAG_t)*((size_t)ci->num_word_in_a_state));

	LC_BOUNDS_ONLY_WITH_MAX_CORR = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used
	LC_BOUNDS = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used

	LC_TRAIL_IN_PROGRESS = (LC_1ROUND_CHAR_t*)malloc(sizeof(LC_1ROUND_CHAR_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used
	LC_TRAIL_FOR_OUT = (LC_1ROUND_CHAR_t*)malloc(sizeof(LC_1ROUND_CHAR_t)*(size_t)(ci->num_round + 1)); //for convenience, the first element is always 0 and is not used

	for (round_idx = 0; round_idx <= ci->num_round; round_idx++)
	{
		LC_TRAIL_IN_PROGRESS[round_idx].sub_i = (SBOX_I_WRD_t*)malloc(sizeof(SBOX_I_WRD_t)*(size_t)(ci->num_word_in_a_state));
		LC_TRAIL_IN_PROGRESS[round_idx].sub_o = (SBOX_O_WRD_t*)malloc(sizeof(SBOX_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		LC_TRAIL_IN_PROGRESS[round_idx].dif_o = (DIFF_O_WRD_t*)malloc(sizeof(DIFF_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		LC_TRAIL_IN_PROGRESS[round_idx].c     = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)(ci->num_word_in_a_state));

		LC_TRAIL_FOR_OUT[round_idx].sub_i = (SBOX_I_WRD_t*)malloc(sizeof(SBOX_I_WRD_t)*(size_t)(ci->num_word_in_a_state));
		LC_TRAIL_FOR_OUT[round_idx].sub_o = (SBOX_O_WRD_t*)malloc(sizeof(SBOX_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		LC_TRAIL_FOR_OUT[round_idx].dif_o = (DIFF_O_WRD_t*)malloc(sizeof(DIFF_O_WRD_t)*(size_t)(ci->num_word_in_a_state));
		LC_TRAIL_FOR_OUT[round_idx].c     = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)(ci->num_word_in_a_state));
	}


	bf_info.has_been_allocated = TRUE;
	bf_info.num_sboxes = ci->num_word_in_a_state;
	bf_info.sbox_i_num_entries = sbox_i_cardinality;
	bf_info.sbox_o_num_entries = sbox_o_cardinality;
	bf_info.lat_num_etnries = sbox_io_cardinality;
	bf_info.num_round = ci->num_round;
}


/*this function only considers word size 32bit */
uint32_t get_nbitword_hw(uint32_t word, int n)
{
	/* non target-optimized code
	int hamming_weight = 0;
	int shift;
	for (shift = 0; shift < n; shift++)
	{
		if (((word >> shift) & 1) == 1)
			hamming_weight++;
	}
	return hamming_weight;
	*/
#ifdef _MSC_VER
	return (uint32_t)_mm_popcnt_u32(word);
#elif __GNUC__
#ifndef _DEBUG
	return (uint32_t)__builtin_popcount(word);
#else
	int hamming_weight = 0;
	int shift;
	for (shift = 0; shift < n; shift++)
	{
		if (((word >> shift) & 1) == 1)
			hamming_weight++;
	}
	return (uint32_t)hamming_weight;
#endif
#endif
}

//Compute LAT with complexity O(n2^(n+m))
//note(\lambda_{ 0 } -\lambda_{ 1 })
void Compute_LAT(LAT_ENTRY_t * lat, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	SBOX_O_CNT_t o_mask_its;
	SBOX_I_CNT_t i_mask_its;
	SBOX_I_CNT_t max_in = (SBOX_I_CNT_t)(1 << sbox_in_bitsz) - 1;
	SBOX_O_CNT_t max_out = (SBOX_O_CNT_t)(1 << sbox_out_bitsz) - 1;
	CNT_t row_size = max_in + 1;
	CNT_t odd_even_hw_table_size = max_in > max_out ? max_in + 1 : max_out + 1;
	int bigger_bit = 0;
	int * odd_even_hw_table = NULL;
	int * m_dot_sbox_boolean_f = NULL;

	//prepare some tables
	odd_even_hw_table = (int*)malloc(sizeof(int)*odd_even_hw_table_size);
	if (odd_even_hw_table == NULL)
	{
		printf("Error ! Memory Allocation for odd_even_hamming_table.\n");
	}

	while ((odd_even_hw_table_size >> bigger_bit) != 0)
	{
		bigger_bit++;
	}
	bigger_bit--;

	{
		int32_t masked_re;
		//init odd_even_hamming_table
		//odd_even_hamming_table has the entries -1 or 1 with repect to the corresponding mask result
		//when mask result has the odd  hamming weight -> -1  [note: when the mask result x&y has odd hamming weight, inner_product{x,y}=1.] 
		//when mask result has the even hamming weight -> 1   [note: when the mask result x&y has odd hamming weight, inner_product{x,y}=0.]
		for (masked_re = 0; masked_re < odd_even_hw_table_size; masked_re++)
		{
			odd_even_hw_table[masked_re] = (get_nbitword_hw(masked_re, bigger_bit) & 1) == 1 ? -1 : 1;
		}
	}

	m_dot_sbox_boolean_f = (int*)malloc(sizeof(int)*row_size);
	if (m_dot_sbox_boolean_f == NULL)
	{
		printf("Error ! Memory Allocation for m_dot_sbox_boolean_f.\n");
	}



	//Compute LAT
#define INNER_PRODUCT(x,y) (odd_even_hw_table[(x)&(y)])
#define o_mask ((SBOX_O_WRD_t)o_mask_its)
#define i_mask ((SBOX_I_WRD_t)i_mask_its)
#define in ((SBOX_I_WRD_t)i_its)
	for (o_mask_its = 0; o_mask_its <= max_out; o_mask_its++)
	{
		//init [m \{dot} SBox(x)] table with a fixed outmask m.
		SBOX_I_CNT_t i_its;
		int size = (int)max_in + 1;
		int i, i0, i1, step;
		int sum, diff;

		for (i_its = 0; i_its <= max_in; i_its++)
		{
			m_dot_sbox_boolean_f[in] = INNER_PRODUCT(o_mask, sbox[in]);
		}

		//Walsh Transformation of The boolean function m\{dot}SBox(x)
		for (step = 1; step < size; step <<= 1)
		{
			for (i1 = 0; i1 < size; i1 += 2 * step)
			{
				for (i0 = 0; i0 < step; i0++)
				{
					i = i1 + i0;
					sum = m_dot_sbox_boolean_f[i] + m_dot_sbox_boolean_f[i + step];
					diff = m_dot_sbox_boolean_f[i] - m_dot_sbox_boolean_f[i + step];
					m_dot_sbox_boolean_f[i] = sum;
					m_dot_sbox_boolean_f[i + step] = diff;
				}
			}
		}
		//end Walsh with [a fixed outmask]

		for (i_mask_its = 0; i_mask_its <= max_in; i_mask_its++)
		{
			lat[i_mask*(max_out + 1) + o_mask] = m_dot_sbox_boolean_f[i_mask];
		}

	}
#undef INNER_PRODUCT
#undef i_mask
#undef o_mask
#undef in
	//finish computing LAT

	free(m_dot_sbox_boolean_f);
	free(odd_even_hw_table);
}

void Compute_Corr_LAT(CORR_t * corr_lat, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	SBOX_I_CNT_t x;
	SBOX_O_CNT_t y;
	SBOX_I_CNT_t max_in = (SBOX_I_CNT_t)(1 << sbox_in_bitsz) - 1;
	SBOX_O_CNT_t max_out = (SBOX_O_CNT_t)(1 << sbox_out_bitsz) - 1;
	LAT_ENTRY_t * LAT = NULL;

	LAT = (LAT_ENTRY_t*)malloc(((size_t)1 << (sbox_in_bitsz + sbox_out_bitsz)) * sizeof(LAT_ENTRY_t));

	Compute_LAT(LAT, sbox, sbox_in_bitsz, sbox_out_bitsz);
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			if (LAT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] != 0)
			{
				if (LAT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] < 0)
				{
					corr_lat[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y].sign = NEGA;
				}
				else
				{
					corr_lat[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y].sign = POSI;
				}
				corr_lat[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y].magnitude = (ABS_CORR_t)log2((ABS_CORR_t)llabs((long long)LAT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y]) / (1 << sbox_in_bitsz));
			}
			else
			{
				corr_lat[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] = ZERO_CORR;
			}
		}
	}
	free(LAT);
}

void Compute_Corr_Active_LAT(CORR_t * corr_lat, SBOX_O_WRD_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz, FLAG_t max_min)
{
	SBOX_I_CNT_t x;
	SBOX_O_CNT_t y;
	SBOX_I_CNT_t max_in = (SBOX_I_CNT_t)(1 << sbox_in_bitsz) - 1;
	SBOX_O_CNT_t max_out = (SBOX_O_CNT_t)(1 << sbox_out_bitsz) - 1;
	LAT_ENTRY_t * LAT = NULL;
	CORR_t max_min_value;

	if (max_min == USING_MIN_CORR)
	{
		max_min_value = ONE_CORR;
	}
	else if (max_min == USING_MAX_CORR)
	{
		max_min_value = ZERO_CORR;
	}


	LAT = (LAT_ENTRY_t*)malloc(((size_t)1 << (sbox_in_bitsz + sbox_out_bitsz)) * sizeof(LAT_ENTRY_t));

	Compute_LAT(LAT, sbox, sbox_in_bitsz, sbox_out_bitsz);
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			if (LAT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] != 0)
			{
				CORR_t corr_entry;
				if (LAT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] < 0)
				{
					corr_entry.sign = NEGA;
				}
				else
				{
					corr_entry.sign = POSI;
				}
				corr_entry.magnitude = (ABS_CORR_t)log2((ABS_CORR_t)llabs((long long)LAT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y]) / (1 << sbox_in_bitsz));

				if (max_min == USING_MIN_CORR)
				{
					if (COMP_CORR(max_min_value, corr_entry) == LEFT)
					{
						max_min_value = corr_entry;
					}
				}
				else if (max_min == USING_MAX_CORR)
				{
					if ((x != 0) || (y != 0))
					{
						if (COMP_CORR(max_min_value, corr_entry) == RIGHT)
						{
							max_min_value = corr_entry;
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
			if (LAT[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] != 0)
			{
				if ((x == 0) && (y == 0))
				{
					corr_lat[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] = ONE_CORR;
				}
				else
				{
					corr_lat[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] = max_min_value;
				}
			}
			else
			{
				corr_lat[(SBOX_I_WRD_t)x * (max_out + 1) + (SBOX_O_WRD_t)y] = ZERO_CORR;
			}
		}
	}

	free(LAT);
}







//Compare Function for descending order.
int descending_C(const void *first, const void *second)
{
	CORR_t first_c = *((CORR_t*)first);
	CORR_t second_c = *((CORR_t*)second);
	return COMP_CORR(second_c, first_c);
}

//Compare Function for descending order.
int descending_IOC(const void *first, const void *second)
{
	const LC_I_O_CORR_t * t_first = first;
	const LC_I_O_CORR_t * t_second = second;
	CORR_t first_c = t_first->c;
	CORR_t second_c = t_second->c;
	return COMP_CORR(second_c, first_c);
}

//Compare Function for descending order.
int descending_OC(const void *first, const void *second)
{
	const LC_O_CORR_t * t_first = first;
	const LC_O_CORR_t * t_second = second;
	CORR_t first_c = t_first->c;
	CORR_t second_c = t_second->c;
	SBOX_O_WRD_t first_o = t_first->o;
	SBOX_O_WRD_t second_o = t_second->o;
	if (COMP_CORR(second_c, first_c) == EQUAL)
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
		return COMP_CORR(second_c, first_c);
	}
}

//Compare Function for descending order.
int descending_IC(const void *first, const void *second)
{
	const LC_I_CORR_t * t_first = first;
	const LC_I_CORR_t * t_second = second;
	CORR_t first_c = t_first->c;
	CORR_t second_c = t_second->c;
	return COMP_CORR(second_c, first_c);
}