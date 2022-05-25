#ifndef _ACTIVE_MAP_H_
#define _ACTIVE_MAP_H_

#ifdef __cplusplus
extern "C" {
#endif



	extern ACTIVE_MAP_t * _1ROUND_ACTIVE_MAPS;
	extern NUM_t		  NUM_1ROUND_ACTIVE_MAPS;
	extern FLAG_t		  CONSTRUCT_1ROUND_ACTIVE_MAPS;

	void	Init_1Round_Active_Map(NUM_t hw);
	FLAG_t	Next_1Round_Active_Map(ACTIVE_MAP_t * next);
	

	#define BEFORE_STARTING_THE_ROUND	((FLAG_t)(-1))
	#define THIS_IS_THE_LAST			((FLAG_t)(-1))
	#define THIS_IS_NOT_THE_LAST		((FLAG_t)(1))


	static DEV_INLINE ACTIVE_MAP_t Compute_Active_Map_From_State(SBOX_I_WRD_t * Xi, CNT_t num_sbox_in_a_state)
	{
		ACTIVE_MAP_t rst = 0x0;
		CNT_t word_idx;
		//compute i-round active maprst
		for (word_idx = 0; word_idx < num_sbox_in_a_state; word_idx++)
		{
			if (Xi[word_idx] != 0x0)
			{
				rst |= ((ACTIVE_MAP_t)0x1 << word_idx);
			}
		}

		return rst;
	}

	static DEV_INLINE CNT_t Next_Active_Word(CNT_t wi, ACTIVE_MAP_t cur_round_active_map, CNT_t num_sbox_in_a_state)
	{
		CNT_t idx;
		CNT_t next_idx = THIS_IS_THE_LAST;
		if (wi == BEFORE_STARTING_THE_ROUND)
		{
			//Get index of active word from 0
			for (idx = 0; idx < num_sbox_in_a_state; idx++)
			{
				if ((cur_round_active_map & ((ACTIVE_MAP_t)1 << (idx))) != 0x0)
				{
					next_idx = idx;
					break;
				}
			}
		}
		else if ((wi >= 0) && (wi <= (num_sbox_in_a_state - 2)))
		{
			for (idx = (wi + 1); idx < num_sbox_in_a_state; idx++)
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

	static DEV_INLINE CNT_t Num_Active_Word(CNT_t wi, ACTIVE_MAP_t cur_round_active_map, CNT_t num_sbox_in_a_state)
	{
		CNT_t num_act;
		if (wi == BEFORE_STARTING_THE_ROUND)
		{
			num_act = get_word_hw(cur_round_active_map);
		}
		else if ((wi >= 0) && (wi <= (num_sbox_in_a_state - 1)))
		{
			ACTIVE_MAP_t mask = (((ACTIVE_MAP_t)1 << (wi + 1)) - 1);
			mask = ~mask;
			num_act = get_word_hw(cur_round_active_map & mask);
		}
		return num_act;
	}


	//There are 5 types of round commuting word-wise permutation sets.
	// BOGI16_0 : 1 : [W00]
	// BOGI16_1 : 4 : [W00, W01, W05, W09]
	// BOGI16_2 : 4 : [W00, W01, W06, W08]
	// BOGI16_3 : 4 : [W00, W02, W05, W07]
	// BOGI16_4 : 4 : [W00, W03, W04, W09]
	enum bogi16_commuting_types { BOGI16_0 = 0, BOGI16_1, BOGI16_2, BOGI16_3, BOGI16_4 };
	static char bogi16_commuting_types_strs[5][16] = { "BOGI16_0", "BOGI16_1", "BOGI16_2", "BOGI16_3", "BOGI16_4" };

	//There are 5 types of round commuting word-wise permutation sets.
	// BOGI32_0 : 1 : [W00]
	// BOGI32_1 : 2 : [W00, W07]
	// BOGI32_2 : 2 : [W00, W02]
	// BOGI32_3 : 4 : [W00, W01, W04, W05]
	// BOGI32_4 : 8 : [W00, W01, W02, W03, W04, W05, W06, W07]
	enum bogi32_commuting_types { BOGI32_0 = 0, BOGI32_1, BOGI32_2, BOGI32_3, BOGI32_4 };
	static char bogi32_commuting_types_strs[5][16] = { "BOGI32_0", "BOGI32_1", "BOGI32_2", "BOGI32_3", "BOGI32_4" };

	//There are 5 types of round commuting word-wise permutation sets.
	// BOGI64_0 : 1 : [W00]
	// BOGI64_1 : 16: [W00, W01, W05, W09, W0A, W0D, W11, W16, W19, W1B, W20, W25, W28, W2A, W2F, W33]
	// BOGI64_2 : 16: [W00, W01, W06, W08, W0A, W0D, W13, W15, W1A, W1C, W21, W23, W27, W29, W30, W32]
	// BOGI64_3 : 16: [W00, W02, W05, W07, W0B, W0E, W12, W14, W19, W1D, W20, W22, W26, W2B, W2E, W31]
	// BOGI64_4 : 16: [W00, W03, W04, W09, W0C, W0F, W10, W17, W18, W1E, W1F, W24, W28, W2C, W2D, W33]
	enum bogi64_commuting_types { BOGI64_0 = 0, BOGI64_1, BOGI64_2, BOGI64_3, BOGI64_4 };
	static char bogi64_commuting_types_strs[5][16] = { "BOGI64_0", "BOGI64_1", "BOGI64_2", "BOGI64_3", "BOGI64_4" };

	//There are 5 types of round commuting word-wise permutation sets.
	// BOGI128_0 : 1 : [W00]
	// BOGI128_1 : 2 : [W00, W1F]
	// BOGI128_2 : 4 : [W00, W02, W08, W0A]
	// BOGI128_3 : 8 : [W00, W01, W04, W05, W10, W11, W14, W15]
	// BOGI128_4 : 32: [W00, W01, W02, W03, W04, W05, W06, W07, W08, W09, W0A, W0B, W0C, W0D, W0E, W0F, 
	//                  W10, W11, W12, W13, W14, W15, W16, W17, W18, W19, W1A, W1B, W1C, W1D, W1E, W1F]
	enum bogi128_commuting_types { BOGI128_0 = 0, BOGI128_1, BOGI128_2, BOGI128_3, BOGI128_4 };
	static char bogi128_commuting_types_strs[5][16] = { "BOGI128_0", "BOGI128_1", "BOGI128_2", "BOGI128_3", "BOGI128_4" };

	//There are 2 types of round commuting word-wise permutation sets.
	// BOGI176_0 : 1 : [W00]
	// BOGI176_1 : 2 : [W00, W01]
	enum bogi176_commuting_types { BOGI176_0 = 0, BOGI176_1 };
	static char bogi176_commuting_types_strs[2][16] = { "BOGI176_0", "BOGI176_1" };

	//There are 2 types of round commuting word-wise permutation sets.
	// BOGI256_0 : 1 : [W00]
	// BOGI256_1 : 64: [W00, W01, W05, W09, W0A, W0D, W11, W16, W19, W1B, W20, W25, W28, W2A, W2F, W33, W34, W37, W3B, W40, W42, W45, W49, W4E, W51, W54, W59, W5F, W62, W65, W6A, W6E, W71, W73, W78, W7D, W7E, W82, W87, W8C, W8F, W91, W96, W9B, W9F, WA1, WA6, WAB, WAE, WB0, WB5, WB9, WBB, WBF, WC3, WC8, WCC, WCE, WD4, WD9, WDC, WDE, WE3, WE7, ]
	// BOGI256_2 : 64: [W00, W01, W06, W08, W0A, W0D, W13, W15, W1A, W1C, W21, W23, W27, W29, W30, W32, W34, W37, W3D, W3F, W42, W45, W4B, W4D, W53, W55, W5B, W5D, W61, W64, W6B, W6D, W72, W74, W79, W7B, W7F, W83, W89, W8B, W90, W92, W97, W99, W9D, WA0, WA7, WA9, WAD, WAF, WB6, WB8, WBA, WBE, WC5, WC7, WCD, WCF, WD5, WD7, WDB, WDD, WE4, WE6, ]
	// BOGI256_3 : 64: [W00, W02, W05, W07, W0B, W0E, W12, W14, W19, W1D, W20, W22, W26, W2B, W2E, W31, W35, W38, W3C, W3E, W43, W46, W4A, W4C, W52, W56, W5A, W5C, W60, W66, W69, W6C, W71, W75, W78, W7A, W80, W84, W88, W8A, W8F, W93, W96, W98, W9C, WA2, WA5, WA8, WAC, WB1, WB4, WB7, WBC, WC0, WC4, WC6, WCB, WD0, WD3, WD6, WDA, WDF, WE2, WE5, ]
	// BOGI256_4 : 64: [W00, W03, W04, W09, W0C, W0F, W10, W17, W18, W1E, W1F, W24, W28, W2C, W2D, W33, W36, W39, W3A, W41, W44, W47, W48, W4F, W50, W57, W58, W5E, W63, W67, W68, W6F, W70, W76, W77, W7C, W81, W85, W86, W8D, W8E, W94, W95, W9A, W9E, WA3, WA4, WAA, WAE, WB2, WB3, WB9, WBD, WC1, WC2, WC9, WCA, WD1, WD2, WD8, WDC, WE0, WE1, WE7, ]
	enum bogi256_commuting_types { BOGI256_0 = 0, BOGI256_1, BOGI256_2, BOGI256_3, BOGI256_4};
	static char bogi256_commuting_types_strs[5][16] = { "BOGI256_0", "BOGI256_1", "BOGI256_2", "BOGI256_3", "BOGI256_4" };

#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_ACTIVE_MAP_H_*/