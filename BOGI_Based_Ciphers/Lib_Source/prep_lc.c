#include "astbb.h"
#include "lin_corr.h"
#include "bogi_common_info.h"
#include <string.h>
#include <stdio.h>

/*Global Variables*/
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

CORR_t				MAX_CORR_POWER_TABLE[NUM_SBOX_IN_A_STATE + 1];
/************************************************/

/*********Additional functions************/
void Compute_LAT(LAT_ENTRY_t * lat, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
void Compute_Corr_LAT(CORR_t * corr_lat, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz);
int descending_C(const void *first, const void *second);
int descending_IOC(const void *first, const void *second);
int descending_OC(const void *first, const void *second);
int descending_IC(const void *first, const void *second);
/****************************************/

void SPN_Prep_Info_For_LC_With_Corr_LAT(CORR_t * corr_lat)
{
	NUM_t sbox_idx;
	CNT_t mask_i;
	CNT_t mask_o;
	CNT_t idx;
	CORR_t the_corr;

	
	// Step - 1 LAT information rearrange
	// all I_O_CORR
	// O_CORR with fixed input
	// I_CORR with fixed output
	//rearrange
	for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
	{
		for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
		{
			//all I_O_CORR
			the_corr = corr_lat[mask_i * SBOX_O_CARDINALITY + mask_o];
			LC_SBOX_I_O_CORR[mask_i * SBOX_O_CARDINALITY + mask_o].i = (SBOX_t)mask_i;
			LC_SBOX_I_O_CORR[mask_i * SBOX_O_CARDINALITY + mask_o].o = (SBOX_t)mask_o;
			LC_SBOX_I_O_CORR[mask_i * SBOX_O_CARDINALITY + mask_o].c.sign = the_corr.sign;
			LC_SBOX_I_O_CORR[mask_i * SBOX_O_CARDINALITY + mask_o].c.magnitude = the_corr.magnitude;
			//O_CORR with fixed input
			LC_SBOX_O_CORR_FIXED_I[mask_i][mask_o].o = (SBOX_t)mask_o;
			LC_SBOX_O_CORR_FIXED_I[mask_i][mask_o].c = the_corr;
			//I_CORR with fixed output
			LC_SBOX_I_CORR_FIXED_O[mask_o][mask_i].i = (SBOX_t)mask_i;
			LC_SBOX_I_CORR_FIXED_O[mask_o][mask_i].c = the_corr;
		}
	}

	//sorting all I_O_CORR
	qsort((void*)LC_SBOX_I_O_CORR, (size_t)SBOX_IO_CARDINALITY, sizeof(LC_I_O_CORR_t), descending_IOC);

	//sorting O_CORR with fixed input
	for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
	{
		qsort((void*)LC_SBOX_O_CORR_FIXED_I[mask_i], (size_t)SBOX_O_CARDINALITY, sizeof(LC_O_CORR_t), descending_OC);
	}
	//sorting I_CORR with fixed output
	for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
	{
		qsort((void*)LC_SBOX_I_CORR_FIXED_O[mask_o], (size_t)SBOX_I_CARDINALITY, sizeof(LC_I_CORR_t), descending_IC);
	}
	//Get Each maximum I_O_CORR with fixed output
	for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
	{
		LC_SBOX_I_O_CORR_FIXED_O[mask_o].i = LC_SBOX_I_CORR_FIXED_O[mask_o][0].i;
		LC_SBOX_I_O_CORR_FIXED_O[mask_o].o = (SBOX_t)mask_o;
		LC_SBOX_I_O_CORR_FIXED_O[mask_o].c = LC_SBOX_I_CORR_FIXED_O[mask_o][0].c;
	}
	//sorting I_O_PROB with fixed output
	qsort((void*)LC_SBOX_I_O_CORR_FIXED_O, (size_t)SBOX_O_CARDINALITY, sizeof(LC_I_O_CORR_t), descending_IOC);


	//Counting the numbers of each information
	/*
	*  1) The number of sbox trails which have NON-zero correlation.
	*  2) The number of sbox trails which have the best correlation.
	*  3) The number of sbox trails which have NON-zero correlation with each fixed sbox output/input.
	*  4) The number of sbox trails which have the best correlation with each fixed sbox output/input.
	*  5) The number of sbox trails which have Best correlation with each fixed sbox output
	*  6) The 1Round Best Correlation
	*/

	////init
	NUM_I_O_WITH_NONZERO_CORR = 0;
	NUM_I_O_WITH_MAX_CORR = 0;
	for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
	{
		NUM_O_WITH_NONZERO_CORR[mask_i] = 0;
		NUM_O_WITH_MAX_CORR[mask_i] = 0;
	}
	for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
	{
		NUM_I_WITH_NONZERO_CORR[mask_o] = 0;
		NUM_I_WITH_MAX_CORR[mask_o] = 0;
	}

	////Counting IO_CORR
	for (idx = 0; idx < SBOX_IO_CARDINALITY; idx++)
	{
		CORR_t IO_corr = LC_SBOX_I_O_CORR[idx].c;
		CORR_t max_IO_corr = LC_SBOX_I_O_CORR[0].c;
		if (COMP_CORR(IO_corr, ZERO_CORR) != EQUAL)
		{
			NUM_I_O_WITH_NONZERO_CORR++;
		}
		if (COMP_CORR(max_IO_corr, IO_corr) == EQUAL)
		{
			NUM_I_O_WITH_MAX_CORR++;
		}
	}

	////Counting O_CORR
	for (mask_i = 0; mask_i < SBOX_I_CARDINALITY; mask_i++)
	{
		for (idx = 0; idx < SBOX_O_CARDINALITY; idx++)
		{
			CORR_t O_corr = LC_SBOX_O_CORR_FIXED_I[mask_i][idx].c;
			CORR_t max_O_corr = LC_SBOX_O_CORR_FIXED_I[mask_i][0].c;
			if (COMP_CORR(O_corr, ZERO_CORR) != EQUAL)
			{
				NUM_O_WITH_NONZERO_CORR[mask_i]++;
			}
			if (COMP_CORR(max_O_corr, O_corr) == EQUAL)
			{
				NUM_O_WITH_MAX_CORR[mask_i]++;
			}
		}
	}

	////Counting I_CORR
	for (mask_o = 0; mask_o < SBOX_O_CARDINALITY; mask_o++)
	{
		for (idx = 0; idx < SBOX_I_CARDINALITY; idx++)
		{
			CORR_t I_corr = LC_SBOX_I_CORR_FIXED_O[mask_o][idx].c;
			CORR_t max_I_corr = LC_SBOX_I_CORR_FIXED_O[mask_o][0].c;
			if (COMP_CORR(I_corr, ZERO_CORR) != EQUAL)
			{
				NUM_I_WITH_NONZERO_CORR[mask_o]++;
			}
			if (COMP_CORR(max_I_corr, I_corr) == EQUAL)
			{
				NUM_I_WITH_MAX_CORR[mask_o]++;
			}
		}
	}



	MAX_CORR_FOR_SBOX = ZERO_CORR;
	MIN_CORR_FOR_SBOX = ONE_CORR;
	//Computing Max/Min correlation for the sbox
	for (idx = 0; idx < SBOX_IO_CARDINALITY; idx++)
	{
		if (LC_SBOX_I_O_CORR[idx].i != 0 || LC_SBOX_I_O_CORR[idx].o != 0)
		{
			if (COMP_CORR(MAX_CORR_FOR_SBOX, LC_SBOX_I_O_CORR[idx].c) == RIGHT)
			{
				MAX_CORR_FOR_SBOX = LC_SBOX_I_O_CORR[idx].c;
			}

			if (COMP_CORR(LC_SBOX_I_O_CORR[idx].c, ZERO_CORR) != EQUAL)
			{
				if (COMP_CORR(MIN_CORR_FOR_SBOX, LC_SBOX_I_O_CORR[idx].c) == LEFT)
				{
					MIN_CORR_FOR_SBOX = LC_SBOX_I_O_CORR[idx].c;
				}
			}
		}
	}

	//here : might change when we consider FEISTEL/*TODO*/
	LC_1ROUND_MAX_CORR = MAX_CORR_FOR_SBOX;

	MAX_CORR_POWER_TABLE[0] = ONE_CORR;
	MAX_CORR_POWER_TABLE[1] = MAX_CORR_FOR_SBOX;
	for (sbox_idx = 2; sbox_idx <= NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		MUL_CORR(&(MAX_CORR_POWER_TABLE[sbox_idx]), MAX_CORR_POWER_TABLE[sbox_idx - 1], MAX_CORR_FOR_SBOX);
	}
}


void SPN_Prep_Info_For_LC(void)
{
	CORR_t * CORR_LAT = NULL;

	//allocate memory for LAT
	CORR_LAT = (CORR_t*)malloc(sizeof(CORR_t) * (size_t)(SBOX_IO_CARDINALITY));
	
	Compute_Corr_LAT(CORR_LAT, SBOX, SBOX_BIT_SIZE, SBOX_BIT_SIZE);

	SPN_Prep_Info_For_LC_With_Corr_LAT(CORR_LAT);

	//free for LAT
	free(CORR_LAT);
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
void Compute_LAT(LAT_ENTRY_t * lat, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	CNT_t o_mask_its;
	CNT_t i_mask_its;
	CNT_t max_in = (CNT_t)(1 << sbox_in_bitsz) - 1;
	CNT_t max_out = (CNT_t)(1 << sbox_out_bitsz) - 1;
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
#define o_mask ((SBOX_t)o_mask_its)
#define i_mask ((SBOX_t)i_mask_its)
#define in ((SBOX_t)i_its)
	for (o_mask_its = 0; o_mask_its <= max_out; o_mask_its++)
	{
		//init [m \{dot} SBox(x)] table with a fixed outmask m.
		CNT_t i_its;
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

void Compute_Corr_LAT(CORR_t * corr_lat, SBOX_t * sbox, BIT_SIZE_t sbox_in_bitsz, BIT_SIZE_t sbox_out_bitsz)
{
	CNT_t x;
	CNT_t y;
	CNT_t max_in = (CNT_t)(1 << sbox_in_bitsz) - 1;
	CNT_t max_out = (CNT_t)(1 << sbox_out_bitsz) - 1;
	LAT_ENTRY_t * LAT = NULL;

	LAT = (LAT_ENTRY_t*)malloc(((size_t)1 << (sbox_in_bitsz + sbox_out_bitsz)) * sizeof(LAT_ENTRY_t));

	Compute_LAT(LAT, sbox, sbox_in_bitsz, sbox_out_bitsz);
	for (x = 0; x <= max_in; x++)
	{
		for (y = 0; y <= max_out; y++)
		{
			if (LAT[(SBOX_t)x * (max_out + 1) + (SBOX_t)y] != 0)
			{
				if (LAT[(SBOX_t)x * (max_out + 1) + (SBOX_t)y] < 0)
				{
					corr_lat[(SBOX_t)x * (max_out + 1) + (SBOX_t)y].sign = NEGA;
				}
				else
				{
					corr_lat[(SBOX_t)x * (max_out + 1) + (SBOX_t)y].sign = POSI;
				}
				corr_lat[(SBOX_t)x * (max_out + 1) + (SBOX_t)y].magnitude = (ABS_CORR_t)log2((ABS_CORR_t)llabs((long long)LAT[(SBOX_t)x * (max_out + 1) + (SBOX_t)y]) / (1 << sbox_in_bitsz));
			}
			else
			{
				corr_lat[(SBOX_t)x * (max_out + 1) + (SBOX_t)y] = ZERO_CORR;
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
	SBOX_t first_o = t_first->o;
	SBOX_t second_o = t_second->o;
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