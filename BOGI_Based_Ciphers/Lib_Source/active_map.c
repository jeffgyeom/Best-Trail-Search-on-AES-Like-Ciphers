#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "active_map.h"
#include "bogi_common_info.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*Global variables*/
//When we use predified active maps
ACTIVE_MAP_t * _1ROUND_ACTIVE_MAPS = NULL;
NUM_t		   NUM_1ROUND_ACTIVE_MAPS;
/**********************************************/


//When we use predified active maps
/*For BOGI16 declared in active_map_bogi16.c*/
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_0[15];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_1[6];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_2[5];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_3[5];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_4[5];
/*For BOGI32 declared in active_map_bogi32.c*/
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_0[255];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_1[135];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_2[135];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_3[75];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_4[45];
/*For BOGI64 declared in active_map_bogi64.c*/
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI64_0[65535];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI64_1[4335];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI64_2[4155];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI64_3[4155];
extern ACTIVE_MAP_t ACTIVE_MAPS_BOGI64_4[4155];
/**********************************************/


//When we can't use predified active maps
static SBOX_t INIT_1ROUND_ACTIVE_MAP[NUM_SBOX_IN_A_STATE];
static SBOX_t INNER_1ROUND_ACTIVE_MAP[NUM_SBOX_IN_A_STATE];
FLAG_t Get_Another_General(void);
static FLAG_t(*Get_Another)(void) = Get_Another_General;
/**********************************************/

void Use_Defined_1Round_Active_Maps(ACTIVE_MAP_t * _1round_active_maps, NUM_t num_maps)
{
	_1ROUND_ACTIVE_MAPS = _1round_active_maps;
	NUM_1ROUND_ACTIVE_MAPS = num_maps;
}

void Use_Predefined_1Round_Active_Maps_BOGI16(CNT_t perm_type)
{
	switch (perm_type)
	{
	case BOGI16_0:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI16_0, sizeof(ACTIVE_MAPS_BOGI16_0) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI16_1:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI16_1, sizeof(ACTIVE_MAPS_BOGI16_1) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI16_2:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI16_2, sizeof(ACTIVE_MAPS_BOGI16_2) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI16_3:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI16_3, sizeof(ACTIVE_MAPS_BOGI16_3) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI16_4:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI16_4, sizeof(ACTIVE_MAPS_BOGI16_4) / sizeof(ACTIVE_MAP_t));
		break;
	default:
		perror("There does not exsit 1-Round Active Maps For The Number of S-boxes in a State with the Corresponding Options\n");
		exit(-1);
		/*none*/
		break;
	}
}

void Use_Predefined_1Round_Active_Maps_BOGI32(CNT_t perm_type)
{
	switch (perm_type)
	{
	case BOGI32_0:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI32_0, sizeof(ACTIVE_MAPS_BOGI32_0) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI32_1:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI32_1, sizeof(ACTIVE_MAPS_BOGI32_1) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI32_2:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI32_2, sizeof(ACTIVE_MAPS_BOGI32_2) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI32_3:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI32_3, sizeof(ACTIVE_MAPS_BOGI32_3) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI32_4:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI32_4, sizeof(ACTIVE_MAPS_BOGI32_4) / sizeof(ACTIVE_MAP_t));
		break;
	default:
		perror("There does not exsit 1-Round Active Maps For The Number of S-boxes in a State with the Corresponding Options\n");
		exit(-1);
		/*none*/
		break;
	}
}

void Use_Predefined_1Round_Active_Maps_BOGI64(CNT_t perm_type)
{
	switch (perm_type)
	{
	case BOGI64_0:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI64_0, sizeof(ACTIVE_MAPS_BOGI64_0) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI64_1:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI64_1, sizeof(ACTIVE_MAPS_BOGI64_1) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI64_2:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI64_2, sizeof(ACTIVE_MAPS_BOGI64_2) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI64_3:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI64_3, sizeof(ACTIVE_MAPS_BOGI64_3) / sizeof(ACTIVE_MAP_t));
		break;
	case BOGI64_4:
		Use_Defined_1Round_Active_Maps(ACTIVE_MAPS_BOGI64_4, sizeof(ACTIVE_MAPS_BOGI64_4) / sizeof(ACTIVE_MAP_t));
		break;
	default:
		perror("There does not exsit 1-Round Active Maps For The Number of S-boxes in a State with the Corresponding Options\n");
		exit(-1);
		/*none*/
		break;
	}
}



FLAG_t Get_Another_BOGI128_1(void);
FLAG_t Get_Another_BOGI128_2(void);
FLAG_t Get_Another_BOGI128_3(void);
FLAG_t Get_Another_BOGI128_4(void);
void Use_Predefined_1Round_Active_Maps_BOGI128(CNT_t perm_type)
{
	switch (perm_type)
	{
	case BOGI128_0:
		Get_Another = Get_Another_General;
		break;
	case BOGI128_1:
		Get_Another = Get_Another_BOGI128_1;
		break;
	case BOGI128_2:
		Get_Another = Get_Another_BOGI128_2;
		break;
	case BOGI128_3:
		Get_Another = Get_Another_BOGI128_3;
		break;
	case BOGI128_4:
		Get_Another = Get_Another_BOGI128_4;
		break;
	default:
		perror("There does not exsit 1-Round Active Maps For The Number of S-boxes in a State with the Corresponding Options\n");
		exit(-1);
		/*none*/
		break;
	}
}

FLAG_t Get_Another_BOGI176_1(void);
void Use_Predefined_1Round_Active_Maps_BOGI176(CNT_t perm_type)
{
	switch (perm_type)
	{
	case BOGI176_0:
		Get_Another = Get_Another_General;
		break;
	case BOGI176_1:
		Get_Another = Get_Another_BOGI176_1;
		break;
	default:
		perror("There does not exsit 1-Round Active Maps For The Number of S-boxes in a State with the Corresponding Options\n");
		exit(-1);
		/*none*/
		break;
	}
}

FLAG_t Get_Another_BOGI256_1(void);
FLAG_t Get_Another_BOGI256_2(void);
FLAG_t Get_Another_BOGI256_3(void);
FLAG_t Get_Another_BOGI256_4(void);
void Use_Predefined_1Round_Active_Maps_BOGI256(CNT_t perm_type)
{
	switch (perm_type)
	{
	case BOGI256_0:
		Get_Another = Get_Another_General;
		break;
	case BOGI256_1:
		Get_Another = Get_Another_BOGI256_1;
		break;
	case BOGI256_2:
		Get_Another = Get_Another_BOGI256_2;
		break;
	case BOGI256_3:
		Get_Another = Get_Another_BOGI256_3;
		break;
	case BOGI256_4:
		Get_Another = Get_Another_BOGI256_4;
		break;
	default:
		perror("There does not exsit 1-Round Active Maps For The Number of S-boxes in a State with the Corresponding Options\n");
		exit(-1);
		/*none*/
		break;
	}
}


static DEV_INLINE ACTIVE_MAP_t Compute_Active_Map_From_Cipher_State(SBOX_t * Xi)
{
	ACTIVE_MAP_t rst = 0x0;
	CNT_t sbox_idx;
	//compute i-round active maprst
	for (sbox_idx = 0; sbox_idx < NUM_SBOX_IN_A_STATE; sbox_idx++)
	{
		if (Xi[sbox_idx] != 0x0)
		{
			rst |= ((ACTIVE_MAP_t)0x1 << sbox_idx);
		}
	}
	return rst;
}

static DEV_INLINE void Swap(SBOX_t * x, SBOX_t * y)
{
	SBOX_t temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

static DEV_INLINE void Sorting_Bin_Array(CNT_t from, CNT_t size)
{
	SBOX_t * from_array = INNER_1ROUND_ACTIVE_MAP + from;
	CNT_t num_ones = 0;
	CNT_t i;
	for (i = 0; i < size; i++)
	{
		if (from_array[i] == 1)
		{
			num_ones++;
		}
		from_array[i] = 0;
	}
	for (i = 0; i < num_ones; i++)
	{
		from_array[i] = 1;
	}
}

FLAG_t Get_Another_General(void)
{
	CNT_t i;
	// Find the rightmost active word
	// which is left to non-active word(e.g, 111'1'0,) 
	// Let us call it 'first active word'
	// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
	for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
		if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
			break;

	//when 00000011111
	if (i == -1)
	{
		return THIS_IS_THE_LAST;
	}
	else
	{
		Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
		Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);
		return THIS_IS_NOT_THE_LAST;
	}
}

//The Followings are defined in active_map_bogi128.c
//(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30)
extern void BOGI128_W01(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29)
extern void BOGI128_W02(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28)
extern void BOGI128_W03(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27)
extern void BOGI128_W04(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26)
extern void BOGI128_W05(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9, 22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25)
extern void BOGI128_W06(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24)
extern void BOGI128_W07(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23)
extern void BOGI128_W08(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6, 25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22)
extern void BOGI128_W09(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21)
extern void BOGI128_W0A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4, 27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20)
extern void BOGI128_W0B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19)
extern void BOGI128_W0C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2, 29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18)
extern void BOGI128_W0D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1, 30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17)
extern void BOGI128_W0E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16)
extern void BOGI128_W0F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
extern void BOGI128_W10(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14)
extern void BOGI128_W11(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13)
extern void BOGI128_W12(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12)
extern void BOGI128_W13(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11)
extern void BOGI128_W14(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10)
extern void BOGI128_W15(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25, 6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9)
extern void BOGI128_W16(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8)
extern void BOGI128_W17(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7)
extern void BOGI128_W18(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22, 9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6)
extern void BOGI128_W19(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5)
extern void BOGI128_W1A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20, 11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4)
extern void BOGI128_W1B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3)
extern void BOGI128_W1C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18, 13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2)
extern void BOGI128_W1D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1)
extern void BOGI128_W1E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
//(31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
extern void BOGI128_W1F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);

FLAG_t Get_Another_BOGI128_1(void)
{
	CNT_t i;

	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			//[W00, W1F]
			//W1F
			BOGI128_W1F(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

FLAG_t Get_Another_BOGI128_2(void)
{
	CNT_t i;

	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			//[W00, W02, W08, W0A]
			//W02
			BOGI128_W02(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W08
			BOGI128_W08(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W0A
			BOGI128_W0A(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

FLAG_t Get_Another_BOGI128_3(void)
{
	CNT_t i;

	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			//[W00, W01, W04, W05, W10, W11, W14, W15]
			//W01
			BOGI128_W01(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W04
			BOGI128_W04(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W05
			BOGI128_W05(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W10
			BOGI128_W10(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W11
			BOGI128_W11(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W14
			BOGI128_W14(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W15
			BOGI128_W15(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

FLAG_t Get_Another_BOGI128_4(void)
{
	CNT_t i;

	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			//[W00, W01, W02, W03, W04, W05, W06, W07, W08, W09, W0A, W0B, W0C, W0D, W0E, W0F, 
            // W10, W11, W12, W13, W14, W15, W16, W17, W18, W19, W1A, W1B, W1C, W1D, W1E, W1F]
			//W01
			BOGI128_W01(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W02
			BOGI128_W02(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W03
			BOGI128_W03(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W04
			BOGI128_W04(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W05
			BOGI128_W05(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W06
			BOGI128_W06(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W07
			BOGI128_W07(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W08
			BOGI128_W08(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W09
			BOGI128_W09(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W0A
			BOGI128_W0A(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W0B
			BOGI128_W0B(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W0C
			BOGI128_W0C(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W0D
			BOGI128_W0D(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W0E
			BOGI128_W0E(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W0F
			BOGI128_W0F(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W10
			BOGI128_W10(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W11
			BOGI128_W11(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W12
			BOGI128_W12(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W13
			BOGI128_W13(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W14
			BOGI128_W14(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W15
			BOGI128_W15(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W16
			BOGI128_W16(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W17
			BOGI128_W17(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W18
			BOGI128_W18(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W19
			BOGI128_W19(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W1A
			BOGI128_W1A(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W1B
			BOGI128_W1B(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W1C
			BOGI128_W1C(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W1D
			BOGI128_W1D(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W1E
			BOGI128_W1E(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			//W1F
			BOGI128_W1F(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

//(43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
//(43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
extern void BOGI176_W01(ACTIVE_MAP_t * out, ACTIVE_MAP_t in);
FLAG_t Get_Another_BOGI176_1(void)
{
	CNT_t i;

	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			//[W00, W01]
			//W01
			BOGI176_W01(&comp_actmap, cur_actmap);
			if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}


extern void(*BOGI256_1_PERMS[64])(ACTIVE_MAP_t *, ACTIVE_MAP_t);
FLAG_t Get_Another_BOGI256_1(void)
{
	CNT_t i;
	CNT_t j;
	FLAG_t found_repre;
	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			found_repre = TRUE;
			for (j = 1; j < 64; j++)
			{
				BOGI256_1_PERMS[j](&comp_actmap, cur_actmap);
				if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				{
					found_repre = FALSE;
					break;
				}
			}

			if (found_repre == FALSE) // There exsits smaller actmap than the current actmap
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

extern void(*BOGI256_2_PERMS[64])(ACTIVE_MAP_t *, ACTIVE_MAP_t);
FLAG_t Get_Another_BOGI256_2(void)
{
	CNT_t i;
	CNT_t j;
	FLAG_t found_repre;
	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			found_repre = TRUE;
			for (j = 1; j < 64; j++)
			{
				BOGI256_2_PERMS[j](&comp_actmap, cur_actmap);
				if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				{
					found_repre = FALSE;
					break;
				}
			}

			if (found_repre == FALSE) // There exsits smaller actmap than the current actmap
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

extern void(*BOGI256_3_PERMS[64])(ACTIVE_MAP_t *, ACTIVE_MAP_t);
FLAG_t Get_Another_BOGI256_3(void)
{
	CNT_t i;
	CNT_t j;
	FLAG_t found_repre;
	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			found_repre = TRUE;
			for (j = 1; j < 64; j++)
			{
				BOGI256_3_PERMS[j](&comp_actmap, cur_actmap);
				if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				{
					found_repre = FALSE;
					break;
				}
			}

			if (found_repre == FALSE) // There exsits smaller actmap than the current actmap
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

extern void(*BOGI256_4_PERMS[64])(ACTIVE_MAP_t *, ACTIVE_MAP_t);
FLAG_t Get_Another_BOGI256_4(void)
{
	CNT_t i;
	CNT_t j;
	FLAG_t found_repre;
	do {
		// Find the rightmost active word
		// which is left to non-active word(e.g, 111'1'0,) 
		// Let us call it 'first active word'
		// Look!! Here NUM_SBOX_IN_A_STATE must be > 2
		for (i = NUM_SBOX_IN_A_STATE - 2; i >= 0; --i)
			if (INNER_1ROUND_ACTIVE_MAP[i] > INNER_1ROUND_ACTIVE_MAP[i + 1])
				break;

		//when 00000011111
		if (i == -1)
		{
			return THIS_IS_THE_LAST;
		}
		else
		{
			ACTIVE_MAP_t cur_actmap, comp_actmap;
			Swap(&INNER_1ROUND_ACTIVE_MAP[i], &INNER_1ROUND_ACTIVE_MAP[i + 1]);
			Sorting_Bin_Array(i + 1, NUM_SBOX_IN_A_STATE - i - 1);

			cur_actmap = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);

			found_repre = TRUE;
			for (j = 1; j < 64; j++)
			{
				BOGI256_4_PERMS[j](&comp_actmap, cur_actmap);
				if (comp_actmap < cur_actmap) // We can check only the minimum active_map
				{
					found_repre = FALSE;
					break;
				}
			}

			if (found_repre == FALSE) // There exsits smaller actmap than the current actmap
				continue; //next
			else
				break; //we've found a representive.
		}
	} while (1);

	return THIS_IS_NOT_THE_LAST;
}

void Init_1Round_Active_Map(NUM_t hw)
{
	CNT_t sbox_idx;
	memset(INNER_1ROUND_ACTIVE_MAP, 0, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);
	for (sbox_idx = 0; sbox_idx < hw; sbox_idx++)
	{
		INNER_1ROUND_ACTIVE_MAP[sbox_idx] = (SBOX_t)1;
	}
	memcpy(INIT_1ROUND_ACTIVE_MAP, INNER_1ROUND_ACTIVE_MAP, sizeof(SBOX_t)*(size_t)NUM_SBOX_IN_A_STATE);

}

FLAG_t Next_1Round_Active_Map(ACTIVE_MAP_t * next)
{
	*next = Compute_Active_Map_From_Cipher_State(INNER_1ROUND_ACTIVE_MAP);
	/*perm*/
	return Get_Another();
}