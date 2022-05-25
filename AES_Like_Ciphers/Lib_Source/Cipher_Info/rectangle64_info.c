#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "bit_perm_opt.h"

SBOX_O_WRD_t RECTANGLE64_sboxes[16 * 16] =
{
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,

	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,

	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,

	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
	0x6, 0x5, 0xc, 0xa, 0x1, 0xe, 0x7, 0x9, 0xb, 0x0, 0x3, 0xd, 0x8, 0xf, 0x4, 0x2,
};

//Bit Permutation
//RECTANGLE64_16_WORD = 63||62||61||60||...||3||2||1||0
void RECTANGLE64_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint64_t x = 0;
	int i;

	for (i = 0; i < 16; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}

	//Gather/scatter opt: 7 cycles, 4 masks
	x = ROL64(x & 0x2222222222222222, 4)
		| (x & 0x1111111111111111)
		| ROL64(x & 0x8888888888888888, 52)
		| ROL64(x & 0x4444444444444444, 48);

	for (i = 15; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

//RECTANGLE64_16_WORD = 63||62||61||60||...||3||2||1||0
void RECTANGLE64_inv_diffusion(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint64_t x = 0;
	int i;

	for (i = 0; i < 16; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}

	//Gather/scatter opt: 7 cycles, 4 masks
	x = (x & 0x1111111111111111)
		| ROL64(x & 0x2222222222222222, 60)
		| ROL64(x & 0x4444444444444444, 16)
		| ROL64(x & 0x8888888888888888, 12);

	for (i = 15; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

#define RECTANGLE64_DC_KNOWN_BEST_ROUND 0
void RECTANGLE64_set_known_prob_bound(PROB_t * B)
{
	// 0 Round :  nothing
	B[0] = (PROB_t)0;
};

#define RECTANGLE64_LC_KNOWN_BEST_ROUND 0
void RECTANGLE64_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
};

#define RECTANGLE64_NUM_ROUND 25
PROB_t RECTANGLE64_each_round_initial_prob_bound[RECTANGLE64_NUM_ROUND + 1] =
{
	(PROB_t)0, //0-round
};
CORR_t RECTANGLE64_each_round_initial_corr_bound[RECTANGLE64_NUM_ROUND + 1] =
{
	{POSI, (ABS_CORR_t)0}, //0-round
};

SEARCHING_START_OPT_t RECTANGLE64_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	TRUE,
};

SET_INITIAL_BOUND_OPT_t RECTANGLE64_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	RECTANGLE64_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-5,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	RECTANGLE64_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2.5}
};

DIFFUSION_BOUND_OPT_t RECTANGLE64_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	16,
	/*diff_branch_num*/
	UNKNOWN,
	/*inv_trans_diff_branch_num*/
	UNKNOWN
};

BLK_CIPHER_INFO_t RECTANGLE64 =
{
	/*general information*/
	//algname
	"RECTANGLE64",
	//alg_structure
	SPN,
	//num_round
	RECTANGLE64_NUM_ROUND,
	//block_bit_size
	64,
	//key_bit_size
	128, //or 80
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
	RECTANGLE64_sboxes,

	/*about diffusion*/
	//diffusion_info [what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))]
	BIT_PERMUTATION,
	/*diff_i_word_bit_size*/
	4,
	/*diff_o_word_bit_size*/
	4,
	//diffusion functions
	//Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	RECTANGLE64_diffusion,
	//Inv_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	RECTANGLE64_inv_diffusion,
	//Inv_Trans_Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	RECTANGLE64_diffusion,
	//Trans_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	RECTANGLE64_inv_diffusion,

	/*about bound info*/
	//dc_known_best_round
	RECTANGLE64_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	RECTANGLE64_set_known_prob_bound,
	//lc_known_best_round
	RECTANGLE64_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	RECTANGLE64_set_known_corr_bound,
	/*start searching opt ptr*/
	&RECTANGLE64_searching_start_opt,
	&RECTANGLE64_set_initial_bound_opt,
	&RECTANGLE64_diffusion_bound_opt
};


void PY_RECTANGLE64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_DC(&RECTANGLE64);
#ifdef EMPLOY_PERM_CHAR
	RECTANGLE64.searching_start_opt->rotational_symmetric_equivalent = TRUE;
#else
	RECTANGLE64.searching_start_opt->rotational_symmetric_equivalent = FALSE;
#endif
	Use_Predefined_1Round_Active_Maps(&RECTANGLE64);
	SPN_Best_DC_Prob_Search(rst, &RECTANGLE64, 0, num_round, verbose);
}

void PY_RECTANGLE64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_LC(&RECTANGLE64);
#ifdef EMPLOY_PERM_CHAR
	RECTANGLE64.searching_start_opt->rotational_symmetric_equivalent = TRUE;
#else
	RECTANGLE64.searching_start_opt->rotational_symmetric_equivalent = FALSE;
#endif
	Use_Predefined_1Round_Active_Maps(&RECTANGLE64);
	SPN_Best_LC_Corr_Search(rst, &RECTANGLE64, 0, num_round, verbose);
}