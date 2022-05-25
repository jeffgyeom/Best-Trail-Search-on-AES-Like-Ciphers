#ifndef _ACTIVE_MAP_H_
#define _ACTIVE_MAP_H_

#ifdef __cplusplus
extern "C" {
#endif

	#include "astbb.h"

#if (defined BOGI_CIPHER_16)||(defined BOGI_CIPHER_32)||(defined BOGI_CIPHER_64)
	//When we use predified active maps
	void Use_Predefined_1Round_Active_Maps_BOGI16(CNT_t perm_type);
	void Use_Predefined_1Round_Active_Maps_BOGI32(CNT_t perm_type);
	void Use_Predefined_1Round_Active_Maps_BOGI64(CNT_t perm_type);

	extern ACTIVE_MAP_t * _1ROUND_ACTIVE_MAPS;
	extern NUM_t		   NUM_1ROUND_ACTIVE_MAPS;

	#undef CONSTRUCT_1ROUND_ACTIVE_MAPS
#elif (defined BOGI_CIPHER_128)||(defined BOGI_CIPHER_176)||(defined BOGI_CIPHER_256)
	//When we can't use predified active maps
	void Use_Predefined_1Round_Active_Maps_BOGI128(CNT_t perm_type);
	void Use_Predefined_1Round_Active_Maps_BOGI176(CNT_t perm_type);
	void Use_Predefined_1Round_Active_Maps_BOGI256(CNT_t perm_type);

	void	Init_1Round_Active_Map(NUM_t hw);
	FLAG_t	Next_1Round_Active_Map(ACTIVE_MAP_t * next);

	#define CONSTRUCT_1ROUND_ACTIVE_MAPS
#endif

	#define THIS_IS_THE_LAST			((FLAG_t)(-1))
	#define THIS_IS_NOT_THE_LAST		((FLAG_t)(1))
	
	#define BEFORE_STARTING_THE_ROUND	((FLAG_t)(-1))


	static DEV_INLINE ACTIVE_MAP_t Compute_Active_Map_From_State(SBOX_t * Xi)
	{
		ACTIVE_MAP_t rst = 0x0;
		CNT_t word_idx;
		//compute i-round active maprst
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			if (Xi[word_idx] != 0x0)
			{
				rst |= ((ACTIVE_MAP_t)0x1 << word_idx);
			}
		}
		return rst;
	}

	static DEV_INLINE CNT_t Next_Active_Word(CNT_t wi, ACTIVE_MAP_t cur_round_active_map)
	{
		CNT_t idx;
		CNT_t next_idx = THIS_IS_THE_LAST;
		if (wi == BEFORE_STARTING_THE_ROUND)
		{
			//Get index of active word from 0
			for (idx = 0; idx < NUM_SBOX_IN_A_STATE; idx++)
			{
				if ((cur_round_active_map & ((ACTIVE_MAP_t)1 << (idx))) != 0x0)
				{
					next_idx = idx;
					break;
				}
			}
		}
		else if ((wi >= 0) && (wi <= (NUM_SBOX_IN_A_STATE - 2)))
		{
			for (idx = (wi + 1); idx < NUM_SBOX_IN_A_STATE; idx++)
			{
				if ((cur_round_active_map & ((ACTIVE_MAP_t)1 << (idx))) != 0x0)
				{
					next_idx = idx;
					break;
				}
			}
		}
		return next_idx;
	}

	static DEV_INLINE CNT_t Num_Active_Word(CNT_t wi, ACTIVE_MAP_t cur_round_active_map)
	{
		CNT_t num_act;
		if (wi == BEFORE_STARTING_THE_ROUND)
		{
			num_act = get_64word_hw(cur_round_active_map);
		}
		else if ((wi >= 0) && (wi <= (NUM_SBOX_IN_A_STATE - 1)))
		{
			ACTIVE_MAP_t mask = (((ACTIVE_MAP_t)1 << (wi + 1)) - 1);
			mask = ~mask;
			num_act = get_64word_hw(cur_round_active_map & mask);
		}
		return num_act;
	}


#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_ACTIVE_MAP_H_*/