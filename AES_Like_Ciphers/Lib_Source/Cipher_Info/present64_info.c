#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "bit_perm_opt.h"

SBOX_O_WRD_t PRESENT64_sboxes[16 * 16] =
{
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,

	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,

	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,

	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
	0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2
};

//Bit Permutation
//PRESENT64_16_WORD = 63||62||61||60||...||3||2||1||0
void PRESENT64_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint64_t x = 0;
	int i;

	for (i = 0; i < 16; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	//53 cycles, 25 masks
	x = ((x & 0x0008000040000200) >> 8)
		| ((x & 0x0000000008000040) << 10)
		| ROL64(x & 0x8000040000200001, 47)
		| ROL64(x & 0x4000020000100000, 32)
		| ((x & 0x0000800004000020) >> 5)
		| ROL64(x & 0x0000080000400002, 62)
		| ROL64(x & 0x0400002000010000, 35)
		| ROL64(x & 0x0020000100000000, 23)
		| ((x & 0x0000008000040000) << 1)
		| ROL64(x & 0x0004000020000100, 41)
		| ROL64(x & 0x0000400002000010, 44)
		| ((x & 0x0000000080000400) << 7)
		| ((x & 0x0000000800004000) << 4)
		| ROL64(x & 0x0040000200001000, 38)
		| ((x & 0x0000000000800004) << 13)
		| ROL64(x & 0x2000010000000000, 17)
		| ((x & 0x0800004000020000) >> 14)
		| ((x & 0x0080000400002000) >> 11)
		| ((x & 0x0000000000080000) << 16)
		| (((ROL64(x, 19) & 0x0000000444408888) * 0x0124800000000249) & 0x7800000780000000)
		| (((ROL64(x, 20) & 0x0101100000002023) * 0x0400000000000241) & 0x0560000000002c00);
	x = ROL64(x, 17);

	for (i = 15; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

//PRESENT64_16_WORD = 63||62||61||60||...||3||2||1||0
void PRESENT64_inv_diffusion(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint64_t x = 0;
	int i;

	for (i = 0; i < 16; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	//50 cycles, 22 masks
	x = ROL64(x & 0x8000040000200001, 4)
		| ((x & 0x4000020000100000) << 1)
		| (((ROL64(x, 7) & 0x001c0000e0040700) * 0x0000000040000049) & 0x0445002220011100)
		| (((ROL64(x, 16) & 0x40002a0001500005) * 0x00000000000030c1) & 0x4202021010108080)
		| (((ROL64(x, 19) & 0x0002a00015000054) * 0x00000000000030c1) & 0x2020210101080804)
		| ((x & 0x0400002000010000) >> 11)
		| ((x & 0x0800004000020000) >> 8)
		| ((x & 0x1000008000040000) >> 5)
		| ((x & 0x2000010000080000) >> 2)
		| (((ROL64(x, 34) & 0x000150000540002a) * 0x00000000000030c3) & 0x1010108080840402)
		| (((ROL64(x, 38) & 0x00080000a8000540) * 0x0000000000001061) & 0x0100080808404040)
		| ((x & 0x0000000000008000) >> 15);
	x = ROL64(x, 60);

	for (i = 15; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

#define PRESENT64_DC_KNOWN_BEST_ROUND 31

void PRESENT64_set_known_prob_bound(PROB_t * B)
{
	// 0 Round :  nothing
	B[0] = (PROB_t)0;
	// 1 Round :  2^{-2.0000} Best
	B[1] = (PROB_t)-2;
	// 2 Round :  2^{-4.0000} Best
	B[2] = (PROB_t)-4;
	// 3 Round :  2^{-8.0000} Best
	B[3] = (PROB_t)-8;
	// 4 Round :  2^{-12.0000} Best
	B[4] = (PROB_t)-12;
	// 5 Round :  2^{-20.0000} Best
	B[5] = (PROB_t)-20;
	// 6 Round :  2^{-24.0000} Best
	B[6] = (PROB_t)-24;
	// 7 Round :  2^{-28.0000} Best
	B[7] = (PROB_t)-28;
	// 8 Round :  2^{-32.0000} Best
	B[8] = (PROB_t)-32;
	// 9 Round :  2^{-36.0000} Best
	B[9] = (PROB_t)-36;
	//10 Round :  2^{-41.0000} Best
	B[10] = (PROB_t)-41;
	//11 Round :  2^{-46.0000} Best
	B[11] = (PROB_t)-46;
	//12 Round :  2^{-52.0000} Best
	B[12] = (PROB_t)-52;
	//13 Round :  2^{-56.0000} Best
	B[13] = (PROB_t)-56;
	//14 Round :  2^{-62.0000} Best
	B[14] = (PROB_t)-62;
	//15 Round :  2^{-66.0000} Best
	B[15] = (PROB_t)-66;
	//16 Round :  2^{-70.0000} Best
	B[16] = (PROB_t)-70;
	//17 Round :  2^{-74.0000} Best
	B[17] = (PROB_t)-74;
	//18 Round :  2^{-78.0000} Best
	B[18] = (PROB_t)-78;
	//19 Round :  2^{-82.0000} Best
	B[19] = (PROB_t)-82;
	//20 Round :  2^{-86.0000} Best
	B[20] = (PROB_t)-86;
	//21 Round :  2^{-90.0000} Best
	B[21] = (PROB_t)-90;
	//22 Round :  2^{-96.0000} Best
	B[22] = (PROB_t)-96;
	//23 Round :  2^{-100.0000} Best
	B[23] = (PROB_t)-100;
	//24 Round :  2^{-106.0000} Best
	B[24] = (PROB_t)-106;
	//25 Round :  2^{-110.0000} Best
	B[25] = (PROB_t)-110;
	//26 Round :  2^{-116.0000} Best
	B[26] = (PROB_t)-116;
	//27 Round :  2^{-120.0000} Best
	B[27] = (PROB_t)-120;
	//28 Round :  2^{-124.0000} Best
	B[28] = (PROB_t)-124;
	//29 Round :  2^{-128.0000} Best
	B[29] = (PROB_t)-128;
	//30 Round :  2^{-132.0000} Best
	B[30] = (PROB_t)-132;
	//31 Round :  2^{-136.0000} Best
	B[31] = (PROB_t)-136;
};

#define PRESENT64_LC_KNOWN_BEST_ROUND 31
void PRESENT64_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
	// 1 Round :  +2^{-1.0000} Best
	B[1].sign = POSI; B[1].magnitude = (ABS_CORR_t)-1;
	// 2 Round :  +2^{-2.0000} Best
	B[2].sign = POSI; B[2].magnitude = (ABS_CORR_t)-2;
	// 3 Round :  -2^{-4.0000} Best
	B[3].sign = NEGA; B[3].magnitude = (ABS_CORR_t)-4;
	// 4 Round :  +2^{-6.0000} Best
	B[4].sign = POSI; B[4].magnitude = (ABS_CORR_t)-6;
	// 5 Round :  -2^{-8.0000} Best
	B[5].sign = NEGA; B[5].magnitude = (ABS_CORR_t)-8;
	// 6 Round :  -2^{-10.0000} Best
	B[6].sign = NEGA; B[6].magnitude = (ABS_CORR_t)-10;
	// 7 Round :  +2^{-12.0000} Best
	B[7].sign = POSI; B[7].magnitude = (ABS_CORR_t)-12;
	// 8 Round :  -2^{-14.0000} Best
	B[8].sign = NEGA; B[8].magnitude = (ABS_CORR_t)-14;
	// 9 Round :  +2^{-16.0000} Best
	B[9].sign = POSI; B[9].magnitude = (ABS_CORR_t)-16;
	//10 Round :  -2^{-18.0000} Best
	B[10].sign = NEGA; B[10].magnitude = (ABS_CORR_t)-18;
	//11 Round :  +2^{-20.0000} Best
	B[11].sign = POSI; B[11].magnitude = (ABS_CORR_t)-20;
	//12 Round :  -2^{-22.0000} Best
	B[12].sign = NEGA; B[12].magnitude = (ABS_CORR_t)-22;
	//13 Round :  +2^{-24.0000} Best
	B[13].sign = POSI; B[13].magnitude = (ABS_CORR_t)-24;
	//14 Round :  -2^{-26.0000} Best
	B[14].sign = NEGA; B[14].magnitude = (ABS_CORR_t)-26;
	//15 Round :  +2^{-28.0000} Best
	B[15].sign = POSI; B[15].magnitude = (ABS_CORR_t)-28;
	//16 Round :  -2^{-30.0000} Best
	B[16].sign = NEGA; B[16].magnitude = (ABS_CORR_t)-30;
	//17 Round :  +2^{-32.0000} Best
	B[17].sign = POSI; B[17].magnitude = (ABS_CORR_t)-32;
	//18 Round :  -2^{-34.0000} Best
	B[18].sign = NEGA; B[18].magnitude = (ABS_CORR_t)-34;
	//19 Round :  +2^{-36.0000} Best
	B[19].sign = POSI; B[19].magnitude = (ABS_CORR_t)-36;
	//20 Round :  -2^{-38.0000} Best
	B[20].sign = NEGA; B[20].magnitude = (ABS_CORR_t)-38;
	//21 Round :  +2^{-40.0000} Best
	B[21].sign = POSI; B[21].magnitude = (ABS_CORR_t)-40;
	//22 Round :  -2^{-42.0000} Best
	B[22].sign = NEGA; B[22].magnitude = (ABS_CORR_t)-42;
	//23 Round :  +2^{-44.0000} Best
	B[23].sign = POSI; B[23].magnitude = (ABS_CORR_t)-44;
	//24 Round :  -2^{-46.0000} Best
	B[24].sign = NEGA; B[24].magnitude = (ABS_CORR_t)-46;
};

#define PRESENT64_NUM_ROUND 31
PROB_t PRESENT64_each_round_initial_prob_bound[PRESENT64_NUM_ROUND + 1] =
{
	(PROB_t)0, //0-round
	(PROB_t)-4,
	(PROB_t)-4,
	(PROB_t)-8,
	(PROB_t)-12,
	(PROB_t)-18,
	(PROB_t)-23,
	(PROB_t)-30,
	(PROB_t)-40,
};
CORR_t PRESENT64_each_round_initial_corr_bound[PRESENT64_NUM_ROUND + 1] =
{
	{POSI, (ABS_CORR_t)0}, //0-round
	{POSI, (ABS_CORR_t)-2},
	{POSI, (ABS_CORR_t)-3},
	{POSI, (ABS_CORR_t)-5},
	{POSI, (ABS_CORR_t)-7},
	{POSI, (ABS_CORR_t)-10},
	{POSI, (ABS_CORR_t)-15},
	{POSI, (ABS_CORR_t)-18},
	{POSI, (ABS_CORR_t)-21},
};

SEARCHING_START_OPT_t PRESENT64_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t PRESENT64_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	PRESENT64_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-5,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	PRESENT64_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2.5}
};

DIFFUSION_BOUND_OPT_t PRESENT64_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	4,
	/*diff_branch_num*/
	UNKNOWN,
	/*inv_trans_diff_branch_num*/
	UNKNOWN
};

BLK_CIPHER_INFO_t PRESENT64 =
{
	/*general information*/
	//algname
	"PRESENT64",
	//alg_structure
	SPN,
	//num_round
	PRESENT64_NUM_ROUND,
	//block_bit_size
	64,
	//key_bit_size
	128,
	//num_word_in_a_state
	16,

	/*about substitution*/
	//distinct_sbox
	FALSE,
	//sbox_i_word_bit_size
	4,
	//sbox_o_word_bit_size
	4,
	//sboxes
	PRESENT64_sboxes,

	/*about diffusion*/
	//diffusion_info [what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))]
	BIT_PERMUTATION,
	/*diff_i_word_bit_size*/
	4,
	/*diff_o_word_bit_size*/
	4,
	//diffusion functions
	//Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	PRESENT64_diffusion,
	//Inv_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	PRESENT64_inv_diffusion,
	//Inv_Trans_Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	PRESENT64_diffusion,
	//Trans_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	PRESENT64_inv_diffusion,

	/*about bound info*/
	//dc_known_best_round
	PRESENT64_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	PRESENT64_set_known_prob_bound,
	//lc_known_best_round
	PRESENT64_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	PRESENT64_set_known_corr_bound,
	/*start searching opt ptr*/
	&PRESENT64_searching_start_opt,
	&PRESENT64_set_initial_bound_opt,
	&PRESENT64_diffusion_bound_opt
};


void PY_PRESENT64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_DC(&PRESENT64);
	Use_Predefined_1Round_Active_Maps(&PRESENT64);
	SPN_Best_DC_Prob_Search(rst, &PRESENT64, 0, num_round, verbose);
}

void PY_PRESENT64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_LC(&PRESENT64);
	Use_Predefined_1Round_Active_Maps(&PRESENT64);
	SPN_Best_LC_Corr_Search(rst, &PRESENT64, 0, num_round, verbose);
}