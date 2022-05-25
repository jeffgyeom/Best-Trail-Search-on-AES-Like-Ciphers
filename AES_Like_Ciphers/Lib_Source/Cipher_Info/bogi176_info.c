#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "bit_perm_opt.h"
#include "active_map.h"
#include <stdio.h>
#include <string.h>

extern SBOX_O_WRD_t BOGI_applicable_sboxes[1728][16];

extern void(*BOGI176_omega_diffusion[576])(DIFF_O_WRD_t *, DIFF_I_WRD_t *);
extern void(*BOGI176_omega_inv_diffusion[576])(DIFF_I_WRD_t *, DIFF_O_WRD_t *);

SBOX_O_WRD_t BOGI176_sboxes[44 * 16] =
{
	//it is set to be the original sbox by default
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
};


#define BOGI176_DC_KNOWN_BEST_ROUND 0

void BOGI176_set_known_prob_bound(PROB_t * B)
{
	// 0Round :nothing
	B[0] = (PROB_t)0;
};

#define BOGI176_LC_KNOWN_BEST_ROUND 0
void BOGI176_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
};

#define BOGI176_NUM_ROUND 40
PROB_t BOGI176_each_round_initial_prob_bound[BOGI176_NUM_ROUND + 1] =
{
	(PROB_t)0, //0-round
};
CORR_t BOGI176_each_round_initial_corr_bound[BOGI176_NUM_ROUND + 1] =
{
	{POSI, (ABS_CORR_t)0}, //0-round
};

SEARCHING_START_OPT_t BOGI176_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t BOGI176_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	BOGI176_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-5,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	BOGI176_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2.5}
};

DIFFUSION_BOUND_OPT_t BOGI176_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	4,
	/*diff_branch_num*/
	UNKNOWN,
	/*inv_trans_diff_branch_num*/
	UNKNOWN
};

BLK_CIPHER_INFO_t BOGI176 =
{
	/*general information*/
	//algname
	"BOGI176",
	//alg_structure
	SPN,
	//num_round
	BOGI176_NUM_ROUND,
	//block_bit_size
	128,
	//key_bit_size
	128,
	//num_word_in_a_state
	44,

	/*about substitution*/
	//distinct_sbox
	FALSE,
	//sbox_i_word_bit_size
	4,
	//sbox_o_word_bit_size
	4,
	//sboxes
	BOGI176_sboxes,

	/*about diffusion*/
	//diffusion_info [what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))]
	BIT_PERMUTATION,
	/*diff_i_word_bit_size*/
	4,
	/*diff_o_word_bit_size*/
	4,
	//diffusion functions
	//Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	NULL,
	//Inv_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	NULL,
	//Inv_Trans_Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	NULL,
	//Trans_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	NULL,

	/*about bound info*/
	//dc_known_best_round
	BOGI176_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	BOGI176_set_known_prob_bound,
	//lc_known_best_round
	BOGI176_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	BOGI176_set_known_corr_bound,
	/*start searching opt ptr*/
	&BOGI176_searching_start_opt,
	&BOGI176_set_initial_bound_opt,
	&BOGI176_diffusion_bound_opt
};


#define BOGI176_NUM_WORD_IN_A_STATE (44)
#define BOGI176_SBOX_ENTRIES (16)

void BOGI176_Set_Sboxes(CNT_t sbox_idx)
{
	int i;
	for (i = 0; i < BOGI176_NUM_WORD_IN_A_STATE; i++)
	{
		int cpy_st_idx = i * BOGI176_SBOX_ENTRIES;
		memcpy(BOGI176_sboxes + cpy_st_idx, BOGI_applicable_sboxes[sbox_idx], sizeof(SBOX_O_WRD_t) * BOGI176_SBOX_ENTRIES);
	}
}


// There are 2 round commuting word-wise permutations for BOGI176 ciphers
// BOGI176_W00:  (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43) A : {(0, 1, 2, 3)} C: (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
// BOGI176_W01 : (43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0) A : {(3, 2, 1, 0)} C: (10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)//
// There are 2 types of round commuting word-wise permutation sets(GIFT(344) - BOGI176_0)
// BOGI176_0 : 1 : [W00, ]
// BOGI176_1 : 2 : [W00, W01, ]
CNT_t BOGI176_omega_types[576] =
{
	BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_0, BOGI176_0,
	BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1, BOGI176_0, BOGI176_0, BOGI176_1
};

void BOGI176_info_out(CNT_t OMEGA_TYPE)
{
	int i;
	FILE* ofp;
	char name[256];
	sprintf_s(name, 256, "%s_info.txt", BOGI176.alg_name);
	ofp = fopen(name, "w");
	fprintf(ofp, "%s\n", bogi176_commuting_types_strs[OMEGA_TYPE]);
	for (i = 0; i < BOGI176_NUM_WORD_IN_A_STATE; i++)
	{
		int j;
		for (j = 0; j < BOGI176_SBOX_ENTRIES; j++)
		{
			fprintf(ofp, "%d, ", BOGI176_sboxes[i*BOGI176_SBOX_ENTRIES + j]);
		}
		fprintf(ofp, "\n");
	}
	fclose(ofp);
}

void PY_BOGI176_DC_Prob_Searching(
	PROB_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx,
	UFLAG_t verbose
)
{
	CNT_t OMEGA_TYPE;
	sprintf_s(BOGI176.alg_name, 256, "BOGI176_%d_%d", sbox_idx, perm_idx);
	BOGI176.num_round = num_round;

	BOGI176_Set_Sboxes(sbox_idx);
	BOGI176.Diffusion = BOGI176_omega_diffusion[perm_idx];
	BOGI176.Inv_Diffusion = BOGI176_omega_inv_diffusion[perm_idx];
	BOGI176.Inv_Trans_Diffusion = BOGI176_omega_diffusion[perm_idx];
	BOGI176.Trans_Diffusion = BOGI176_omega_inv_diffusion[perm_idx];
	OMEGA_TYPE = BOGI176_omega_types[perm_idx];

	BOGI176_info_out(OMEGA_TYPE);

	SPN_Prep_Info_For_DC(&BOGI176);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI176(&BOGI176, OMEGA_TYPE);
#else
	Use_Predefined_1Round_Active_Maps(&BOGI176);
#endif
	SPN_Best_DC_Prob_Search(rst, &BOGI176, 0, num_round, verbose);
}


void PY_BOGI176_LC_Corr_Searching(
	CORR_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx,
	UFLAG_t verbose
)
{
	CNT_t OMEGA_TYPE;
	sprintf_s(BOGI176.alg_name, 256, "BOGI176_%d_%d", sbox_idx, perm_idx);
	BOGI176.num_round = num_round;

	BOGI176_Set_Sboxes(sbox_idx);
	BOGI176.Diffusion = BOGI176_omega_diffusion[perm_idx];
	BOGI176.Inv_Diffusion = BOGI176_omega_inv_diffusion[perm_idx];
	BOGI176.Inv_Trans_Diffusion = BOGI176_omega_diffusion[perm_idx];
	BOGI176.Trans_Diffusion = BOGI176_omega_inv_diffusion[perm_idx];
	OMEGA_TYPE = BOGI176_omega_types[perm_idx];

	BOGI176_info_out(OMEGA_TYPE);

	SPN_Prep_Info_For_LC(&BOGI176);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI176(&BOGI176, OMEGA_TYPE);
#else
	Use_Predefined_1Round_Active_Maps(&BOGI176);
#endif
	SPN_Best_LC_Corr_Search(rst, &BOGI176, 0, num_round, verbose);
}