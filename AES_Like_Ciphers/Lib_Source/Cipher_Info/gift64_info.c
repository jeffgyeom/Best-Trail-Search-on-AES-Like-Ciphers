#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "bit_perm_opt.h"

SBOX_O_WRD_t GIFT64_sboxes[16*16] =
{
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,

	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,

	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,

	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe,
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe
};



//Bit Permutation
//GIFT64_16_WORD = 63||62||61||60||...||3||2||1||0
void GIFT64_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint64_t x = 0;
	int i;

	for (i = 0; i < 16; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	//31 cycles, 16 masks
	x = (x & 0x4000010000400001)
		| ((x & 0x0200008000021000) << 4)
		| ((x & 0x0010000420000800) << 8)
		| ((x & 0x0008400001000040) << 12)
		| ROL64(x & 0x8000020000800002, 16)
		| ROL64(x & 0x0400001000042000, 20)
		| ROL64(x & 0x0020000840000100, 24)
		| ROL64(x & 0x0001800002000080, 28)
		| ROL64(x & 0x1000040000100004, 32)
		| ROL64(x & 0x0800002000084000, 36)
		| ROL64(x & 0x0040000180000200, 40)
		| ROL64(x & 0x0002100004000010, 44)
		| ROL64(x & 0x2000080000200008, 48)
		| ((x & 0x0100004000018000) >> 12)
		| ((x & 0x0080000210000400) >> 8)
		| ((x & 0x0004200008000020) >> 4);

	for (i = 15; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

//GIFT64_16_WORD = 63||62||61||60||...||3||2||1||0
void GIFT64_inv_diffusion(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint64_t x = 0;
	int i;

	for (i = 0; i < 16; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	//31 cycles, 16 masks
	x = (x & 0x4000010000400001)
		| ((x & 0x0000420000800002) << 4)
		| ((x & 0x0000800002100004) << 8)
		| ((x & 0x0000100004000018) << 12)
		| ROL64(x & 0x0008200008000020, 16)
		| ROL64(x & 0x0001000021000040, 20)
		| ROL64(x & 0x0002000040000180, 24)
		| ROL64(x & 0x0084000080000200, 28)
		| ROL64(x & 0x0010000410000400, 32)
		| ROL64(x & 0x0020000800001800, 36)
		| ROL64(x & 0x0840000100002000, 40)
		| ROL64(x & 0x0100004200004000, 44)
		| ROL64(x & 0x0200008000028000, 48)
		| ((x & 0x8400001000040000) >> 12)
		| ((x & 0x1000042000080000) >> 8)
		| ((x & 0x2000080000210000) >> 4);

	for (i = 15; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

#define GIFT64_DC_KNOWN_BEST_ROUND 28

void GIFT64_set_known_prob_bound(PROB_t * B)
{
	// 0Round :nothing
	B[0] = (PROB_t)0;
	// 1Round : 2^{- 1.4150} Best
	B[1] = (PROB_t)log2((PROB_t)6 / (PROB_t)16);
	// 2Round : 2^{- 3.4150} Best
	B[2] = (PROB_t)-2 + (PROB_t)log2((PROB_t)6 / (PROB_t)16);
	// 3Round : 2^{- 7.0000} Best
	B[3] = (PROB_t)-7;
	// 4Round : 2^{-11.4150} Best
	B[4] = (PROB_t)-10 + (PROB_t)log2((PROB_t)6 / (PROB_t)16);
	// 5Round : 2^{-17.0000} Best
	B[5] = (PROB_t)-17;
	// 6Round : 2^{-22.4150} Best
	B[6] = (PROB_t)-21 + (PROB_t)log2((PROB_t)6 / (PROB_t)16);
	// 7Round : 2^{-28.4150} Best
	B[7] = (PROB_t)-27 + (PROB_t)log2((PROB_t)6 / (PROB_t)16);
	// 8Round : 2^{-38.0000} Best
	B[8] = (PROB_t)-38;
	// 9Round : 2^{-42.0000} Best
	B[9] = (PROB_t)-42;
	//10Round : 2^{-48.0000} Best
	B[10] = (PROB_t)-48;
	//11Round : 2^{-52.0000} Best
	B[11] = (PROB_t)-52;
	//12Round : 2^{-58.0000} Best
	B[12] = (PROB_t)-58;
	//13Round : 2^{-62.0000} Best
	B[13] = (PROB_t)-62;
	//14Round : 2^{-68.0000} Best
	B[14] = (PROB_t)-68;
	//15Round : 2^{-72.0000} Best
	B[15] = (PROB_t)-72;
	//16Round : 2^{-78.0000} Best
	B[16] = (PROB_t)-78;
	//17Round : 2^{-82.0000} Best
	B[17] = (PROB_t)-82;
	//18Round : 2^{-88.0000} Best
	B[18] = (PROB_t)-88;
	//19Round : 2^{-92.0000} Best
	B[19] = (PROB_t)-92;
	//20Round : 2^{-98.0000} Best
	B[20] = (PROB_t)-98;
	//21Round : 2^{-102.0000} Best
	B[21] = (PROB_t)-102;
	//22Round : 2^{-108.0000} Best
	B[22] = (PROB_t)-108;
	//23Round : 2^{-112.0000} Best
	B[23] = (PROB_t)-112;
	//14Round : 2^{-118.0000} Best
	B[24] = (PROB_t)-118;
	//25Round : 2^{-122.0000} Best
	B[25] = (PROB_t)-122;
	//26Round : 2^{-128.0000} Best
	B[26] = (PROB_t)-128;
	//27Round : 2^{-132.0000} Best
	B[27] = (PROB_t)-132;
	//28Round : 2^{-138.0000} Best
	B[28] = (PROB_t)-138;
};

#define GIFT64_LC_KNOWN_BEST_ROUND 28
void GIFT64_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
	// 1 Round :  -2^{-1.0000} Best
	B[1].sign = NEGA; B[1].magnitude = (ABS_CORR_t)-1;
	// 2 Round :  -2^{-2.0000} Best
	B[2].sign = NEGA; B[2].magnitude = (ABS_CORR_t)-2;
	// 3 Round :  -2^{-3.0000} Best
	B[3].sign = NEGA; B[3].magnitude = (ABS_CORR_t)-3;
	// 4 Round :  -2^{-5.0000} Best
	B[4].sign = NEGA; B[4].magnitude = (ABS_CORR_t)-5;
	// 5 Round :  +2^{-7.0000} Best
	B[5].sign = POSI; B[5].magnitude = (ABS_CORR_t)-7;
	// 6 Round :  +2^{-10.0000} Best
	B[6].sign = POSI; B[6].magnitude = (ABS_CORR_t)-10;
	// 7 Round :  +2^{-13.0000} Best
	B[7].sign = POSI; B[7].magnitude = (ABS_CORR_t)-13;
	// 8 Round :  +2^{-16.0000} Best
	B[8].sign = POSI; B[8].magnitude = (ABS_CORR_t)-16;
	// 9 Round :  -2^{-20.0000} Best
	B[9].sign = NEGA; B[9].magnitude = (ABS_CORR_t)-20;
	//10 Round :  -2^{-25.0000} Best
	B[10].sign = NEGA; B[10].magnitude = (ABS_CORR_t)-25;
	//11 Round :  -2^{-29.0000} Best
	B[11].sign = NEGA; B[11].magnitude = (ABS_CORR_t)-29;
	//12 Round :  -2^{-31.0000} Best
	B[12].sign = NEGA; B[12].magnitude = (ABS_CORR_t)-31;
	//13 Round :  -2^{-34.0000} Best
	B[13].sign = NEGA; B[13].magnitude = (ABS_CORR_t)-34;
	//14 Round :  -2^{-37.0000} Best
	B[14].sign = NEGA; B[14].magnitude = (ABS_CORR_t)-37;
	//15 Round :  -2^{-40.0000} Best
	B[15].sign = NEGA; B[15].magnitude = (ABS_CORR_t)-40;
	//16 Round :  -2^{-43.0000} Best
	B[16].sign = NEGA; B[16].magnitude = (ABS_CORR_t)-43;
	//17 Round :  -2^{-46.0000} Best
	B[17].sign = NEGA; B[17].magnitude = (ABS_CORR_t)-46;
	//18 Round :  -2^{-49.0000} Best
	B[18].sign = NEGA; B[18].magnitude = (ABS_CORR_t)-49;
	//19 Round :  -2^{-52.0000} Best
	B[19].sign = NEGA; B[19].magnitude = (ABS_CORR_t)-52;
	//20 Round :  -2^{-55.0000} Best
	B[20].sign = NEGA; B[20].magnitude = (ABS_CORR_t)-55;
	//21 Round :  -2^{-58.0000} Best
	B[21].sign = NEGA; B[21].magnitude = (ABS_CORR_t)-58;
	//22 Round :  -2^{-61.0000} Best
	B[22].sign = NEGA; B[22].magnitude = (ABS_CORR_t)-61;
	//23 Round :  -2^{-64.0000} Best
	B[23].sign = NEGA; B[23].magnitude = (ABS_CORR_t)-64;
	//24 Round :  -2^{-67.0000} Best
	B[24].sign = NEGA; B[24].magnitude = (ABS_CORR_t)-67;
	//25 Round :  -2^{-70.0000} Best
	B[25].sign = NEGA; B[25].magnitude = (ABS_CORR_t)-70;
	//26 Round :  -2^{-73.0000} Best
	B[26].sign = NEGA; B[26].magnitude = (ABS_CORR_t)-73;
	//27 Round :  -2^{-76.0000} Best
	B[27].sign = NEGA; B[27].magnitude = (ABS_CORR_t)-76;
	//28 Round :  -2^{-79.0000} Best
	B[28].sign = NEGA; B[28].magnitude = (ABS_CORR_t)-79;
};

#define GIFT64_NUM_ROUND 28
PROB_t GIFT64_each_round_initial_prob_bound[GIFT64_NUM_ROUND + 1]=
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
CORR_t GIFT64_each_round_initial_corr_bound[GIFT64_NUM_ROUND + 1]=
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

SEARCHING_START_OPT_t GIFT64_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t GIFT64_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	GIFT64_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-5,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	GIFT64_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2.5}
};

DIFFUSION_BOUND_OPT_t GIFT64_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	4,
	/*diff_branch_num*/
	UNKNOWN,
	/*inv_trans_diff_branch_num*/
	UNKNOWN
};

BLK_CIPHER_INFO_t GIFT64 =
{
	/*general information*/
	//algname
	"GIFT64",
	//alg_structure
	SPN,
	//num_round
	GIFT64_NUM_ROUND,
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
	GIFT64_sboxes,

	/*about diffusion*/
	//diffusion_info [what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))]
	BIT_PERMUTATION,
	/*diff_i_word_bit_size*/
	4,
	/*diff_o_word_bit_size*/
	4,
	//diffusion functions
	//Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	GIFT64_diffusion,
	//Inv_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	GIFT64_inv_diffusion,
	//Inv_Trans_Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	GIFT64_diffusion,
	//Trans_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	GIFT64_inv_diffusion,

	/*about bound info*/
	//dc_known_best_round
	GIFT64_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	GIFT64_set_known_prob_bound,
	//lc_known_best_round
	GIFT64_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	GIFT64_set_known_corr_bound,
	/*start searching opt ptr*/
	&GIFT64_searching_start_opt,
	&GIFT64_set_initial_bound_opt,
	&GIFT64_diffusion_bound_opt
};


void PY_GIFT64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_DC(&GIFT64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_GIFT64(&GIFT64);
#else
	Use_Predefined_1Round_Active_Maps(&GIFT64);
#endif
	SPN_Best_DC_Prob_Search(rst, &GIFT64, 0, num_round, verbose);
}

void PY_GIFT64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_LC(&GIFT64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_GIFT64(&GIFT64);
#else
	Use_Predefined_1Round_Active_Maps(&GIFT64);
#endif
	SPN_Best_LC_Corr_Search(rst, &GIFT64, 0, num_round, verbose);
}