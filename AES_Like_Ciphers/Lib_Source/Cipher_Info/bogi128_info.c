#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "bit_perm_opt.h"
#include "active_map.h"
#include <stdio.h>
#include <string.h>

extern SBOX_O_WRD_t BOGI_applicable_sboxes[1728][16];

extern void(*BOGI128_omega_diffusion[576])(DIFF_O_WRD_t *, DIFF_I_WRD_t *);
extern void(*BOGI128_omega_inv_diffusion[576])(DIFF_I_WRD_t *, DIFF_O_WRD_t *);

SBOX_O_WRD_t BOGI128_sboxes[32 * 16] =
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
	0x1, 0xa, 0x4, 0xc, 0x6, 0xf, 0x3, 0x9, 0x2, 0xd, 0xb, 0x7, 0x5, 0x0, 0x8, 0xe
};


#define BOGI128_DC_KNOWN_BEST_ROUND 0

void BOGI128_set_known_prob_bound(PROB_t * B)
{
	// 0Round :nothing
	B[0] = (PROB_t)0;
};

#define BOGI128_LC_KNOWN_BEST_ROUND 0
void BOGI128_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
};

#define BOGI128_NUM_ROUND 40
PROB_t BOGI128_each_round_initial_prob_bound[BOGI128_NUM_ROUND + 1] =
{
	(PROB_t)0, //0-round
};
CORR_t BOGI128_each_round_initial_corr_bound[BOGI128_NUM_ROUND + 1] =
{
	{POSI, (ABS_CORR_t)0}, //0-round
};

SEARCHING_START_OPT_t BOGI128_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t BOGI128_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	BOGI128_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-5,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	BOGI128_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2.5}
};

DIFFUSION_BOUND_OPT_t BOGI128_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	4,
	/*diff_branch_num*/
	UNKNOWN,
	/*inv_trans_diff_branch_num*/
	UNKNOWN
};

BLK_CIPHER_INFO_t BOGI128 =
{
	/*general information*/
	//algname
	"BOGI128",
	//alg_structure
	SPN,
	//num_round
	BOGI128_NUM_ROUND,
	//block_bit_size
	128,
	//key_bit_size
	128,
	//num_word_in_a_state
	32,

	/*about substitution*/
	//distinct_sbox
	FALSE,
	//sbox_i_word_bit_size
	4,
	//sbox_o_word_bit_size
	4,
	//sboxes
	BOGI128_sboxes,

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
	BOGI128_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	BOGI128_set_known_prob_bound,
	//lc_known_best_round
	BOGI128_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	BOGI128_set_known_corr_bound,
	/*start searching opt ptr*/
	&BOGI128_searching_start_opt,
	&BOGI128_set_initial_bound_opt,
	&BOGI128_diffusion_bound_opt
};


#define BOGI128_NUM_WORD_IN_A_STATE (32)
#define BOGI128_SBOX_ENTRIES (16)

void BOGI128_Set_Sboxes(CNT_t sbox_idx)
{
	int i;
	for (i = 0; i < BOGI128_NUM_WORD_IN_A_STATE; i++)
	{
		int cpy_st_idx = i * BOGI128_SBOX_ENTRIES;
		memcpy(BOGI128_sboxes + cpy_st_idx, BOGI_applicable_sboxes[sbox_idx], sizeof(SBOX_O_WRD_t) * BOGI128_SBOX_ENTRIES);
	}
}


// There are 32 round commuting word-wise permutations for BOGI128 ciphers
// BOGI128_W00 : (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31) A : {(0, 1, 2, 3)} C: (0, 1, 2, 3, 4, 5, 6, 7)
// BOGI128_W01 : (1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30) A : {(1, 0, 3, 2)} C: (0, 1, 2, 3, 4, 5, 6, 7)
// BOGI128_W02 : (2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29) A : {(2, 3, 0, 1)} C: (0, 1, 2, 3, 4, 5, 6, 7)
// BOGI128_W03 : (3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28) A : {(3, 2, 1, 0)} C: (0, 1, 2, 3, 4, 5, 6, 7)
// BOGI128_W04 : (4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27) A : {(0, 1, 2, 3)} C: (1, 0, 3, 2, 5, 4, 7, 6)
// BOGI128_W05 : (5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26) A : {(1, 0, 3, 2)} C: (1, 0, 3, 2, 5, 4, 7, 6)
// BOGI128_W06 : (6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9, 22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25) A : {(2, 3, 0, 1)} C: (1, 0, 3, 2, 5, 4, 7, 6)
// BOGI128_W07 : (7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24) A : {(3, 2, 1, 0)} C: (1, 0, 3, 2, 5, 4, 7, 6)
// BOGI128_W08 : (8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23) A : {(0, 1, 2, 3)} C: (2, 3, 0, 1, 6, 7, 4, 5)
// BOGI128_W09 : (9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6, 25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22) A : {(1, 0, 3, 2)} C: (2, 3, 0, 1, 6, 7, 4, 5)
// BOGI128_W0A : (10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21) A : {(2, 3, 0, 1)} C: (2, 3, 0, 1, 6, 7, 4, 5)
// BOGI128_W0B : (11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4, 27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20) A : {(3, 2, 1, 0)} C: (2, 3, 0, 1, 6, 7, 4, 5)
// BOGI128_W0C : (12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19) A : {(0, 1, 2, 3)} C: (3, 2, 1, 0, 7, 6, 5, 4)
// BOGI128_W0D : (13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2, 29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18) A : {(1, 0, 3, 2)} C: (3, 2, 1, 0, 7, 6, 5, 4)
// BOGI128_W0E : (14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1, 30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17) A : {(2, 3, 0, 1)} C: (3, 2, 1, 0, 7, 6, 5, 4)
// BOGI128_W0F : (15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16) A : {(3, 2, 1, 0)} C: (3, 2, 1, 0, 7, 6, 5, 4)
// BOGI128_W10 : (16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15) A : {(0, 1, 2, 3)} C: (4, 5, 6, 7, 0, 1, 2, 3)
// BOGI128_W11 : (17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14) A : {(1, 0, 3, 2)} C: (4, 5, 6, 7, 0, 1, 2, 3)
// BOGI128_W12 : (18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13) A : {(2, 3, 0, 1)} C: (4, 5, 6, 7, 0, 1, 2, 3)
// BOGI128_W13 : (19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12) A : {(3, 2, 1, 0)} C: (4, 5, 6, 7, 0, 1, 2, 3)
// BOGI128_W14 : (20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11) A : {(0, 1, 2, 3)} C: (5, 4, 7, 6, 1, 0, 3, 2)
// BOGI128_W15 : (21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10) A : {(1, 0, 3, 2)} C: (5, 4, 7, 6, 1, 0, 3, 2)
// BOGI128_W16 : (22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25, 6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9) A : {(2, 3, 0, 1)} C: (5, 4, 7, 6, 1, 0, 3, 2)
// BOGI128_W17 : (23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8) A : {(3, 2, 1, 0)} C: (5, 4, 7, 6, 1, 0, 3, 2)
// BOGI128_W18 : (24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7) A : {(0, 1, 2, 3)} C: (6, 7, 4, 5, 2, 3, 0, 1)
// BOGI128_W19 : (25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22, 9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6) A : {(1, 0, 3, 2)} C: (6, 7, 4, 5, 2, 3, 0, 1)
// BOGI128_W1A : (26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5) A : {(2, 3, 0, 1)} C: (6, 7, 4, 5, 2, 3, 0, 1)
// BOGI128_W1B : (27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20, 11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4) A : {(3, 2, 1, 0)} C: (6, 7, 4, 5, 2, 3, 0, 1)
// BOGI128_W1C : (28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3) A : {(0, 1, 2, 3)} C: (7, 6, 5, 4, 3, 2, 1, 0)
// BOGI128_W1D : (29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18, 13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2) A : {(1, 0, 3, 2)} C: (7, 6, 5, 4, 3, 2, 1, 0)
// BOGI128_W1E : (30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1) A : {(2, 3, 0, 1)} C: (7, 6, 5, 4, 3, 2, 1, 0)
// BOGI128_W1F : (31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0) A : {(3, 2, 1, 0)} C: (7, 6, 5, 4, 3, 2, 1, 0)
//
// There are 5 types of round commuting word-wise permutation sets(GIFT(344) - BOGI128_0)
// BOGI128_0 : 1 : [W00]
// BOGI128_1 : 2 : [W00, W1F]
// BOGI128_2 : 4 : [W00, W02, W08, W0A]
// BOGI128_3 : 8 : [W00, W01, W04, W05, W10, W11, W14, W15]
// BOGI128_4 : 32: [W00, W01, W02, W03, W04, W05, W06, W07, W08, W09, W0A, W0B, W0C, W0D, W0E, W0F, 
//                  W10, W11, W12, W13, W14, W15, W16, W17, W18, W19, W1A, W1B, W1C, W1D, W1E, W1F]
CNT_t BOGI128_omega_types[576] =
{
	BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_1, BOGI128_1, BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0,
	BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_3, BOGI128_3, BOGI128_1, BOGI128_1,
	BOGI128_3, BOGI128_3, BOGI128_2, BOGI128_2, BOGI128_1, BOGI128_4, BOGI128_4, BOGI128_1, BOGI128_0, BOGI128_0, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4,
	BOGI128_2, BOGI128_4, BOGI128_4, BOGI128_2, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_2, BOGI128_2,
	BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_4, BOGI128_4, BOGI128_3, BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_3, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0,
	BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_3, BOGI128_3, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4,
	BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_1, BOGI128_1, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_1, BOGI128_1, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4,
	BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_4, BOGI128_4, BOGI128_3, BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_3, BOGI128_3, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_2, BOGI128_2, BOGI128_1, BOGI128_4, BOGI128_4, BOGI128_1, BOGI128_3, BOGI128_3,
	BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_1, BOGI128_1, BOGI128_0, BOGI128_0, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4,
	BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_2, BOGI128_2, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_2, BOGI128_4, BOGI128_4, BOGI128_2, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_2, BOGI128_4, BOGI128_4, BOGI128_2, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_2, BOGI128_2, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0,
	BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_0, BOGI128_0, BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_3, BOGI128_3,
	BOGI128_3, BOGI128_3, BOGI128_1, BOGI128_4, BOGI128_4, BOGI128_1, BOGI128_2, BOGI128_2, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_1, BOGI128_1,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_3, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_3, BOGI128_3, BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_4, BOGI128_4, BOGI128_3, BOGI128_0, BOGI128_0,
	BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_1, BOGI128_1, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0,
	BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4,
	BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_3, BOGI128_0, BOGI128_0, BOGI128_3, BOGI128_4, BOGI128_4, BOGI128_3, BOGI128_0, BOGI128_0,
	BOGI128_2, BOGI128_2, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_2, BOGI128_4, BOGI128_4, BOGI128_2,
	BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_0, BOGI128_0, BOGI128_1, BOGI128_4, BOGI128_4, BOGI128_1, BOGI128_2, BOGI128_2, BOGI128_3, BOGI128_3,
	BOGI128_1, BOGI128_1, BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_2, BOGI128_2, BOGI128_4, BOGI128_3, BOGI128_3, BOGI128_4, BOGI128_1, BOGI128_1,
	BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_4, BOGI128_0, BOGI128_4, BOGI128_1, BOGI128_1, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_0, BOGI128_0,
	BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_1, BOGI128_1, BOGI128_1, BOGI128_1, BOGI128_0, BOGI128_0, BOGI128_4, BOGI128_0, BOGI128_0, BOGI128_4,
};

void BOGI128_info_out(CNT_t OMEGA_TYPE)
{
	int i;
	FILE* ofp;
	char name[256];
	sprintf_s(name, 256, "%s_info.txt", BOGI128.alg_name);
	ofp = fopen(name, "w");
	fprintf(ofp, "%s\n", bogi128_commuting_types_strs[OMEGA_TYPE]);
	for (i = 0; i < BOGI128_NUM_WORD_IN_A_STATE; i++)
	{
		int j;
		for (j = 0; j < BOGI128_SBOX_ENTRIES; j++)
		{
			fprintf(ofp, "%d, ", BOGI128_sboxes[i*BOGI128_SBOX_ENTRIES + j]);
		}
		fprintf(ofp, "\n");
	}
	fclose(ofp);
}

void PY_BOGI128_DC_Prob_Searching(
	PROB_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx,
	UFLAG_t verbose
)
{
	CNT_t OMEGA_TYPE;
	sprintf_s(BOGI128.alg_name, 256, "BOGI128_%d_%d", sbox_idx, perm_idx);
	BOGI128.num_round = num_round;

	BOGI128_Set_Sboxes(sbox_idx);
	BOGI128.Diffusion = BOGI128_omega_diffusion[perm_idx];
	BOGI128.Inv_Diffusion = BOGI128_omega_inv_diffusion[perm_idx];
	BOGI128.Inv_Trans_Diffusion = BOGI128_omega_diffusion[perm_idx];
	BOGI128.Trans_Diffusion = BOGI128_omega_inv_diffusion[perm_idx];
	OMEGA_TYPE = BOGI128_omega_types[perm_idx];

	BOGI128_info_out(OMEGA_TYPE);

	SPN_Prep_Info_For_DC(&BOGI128);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI128(&BOGI128, OMEGA_TYPE);
#else
	Use_Predefined_1Round_Active_Maps(&BOGI128);
#endif
	SPN_Best_DC_Prob_Search(rst, &BOGI128, 0, num_round, verbose);
}


void PY_BOGI128_LC_Corr_Searching(
	CORR_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx,
	UFLAG_t verbose
)
{
	CNT_t OMEGA_TYPE;
	sprintf_s(BOGI128.alg_name, 256, "BOGI128_%d_%d", sbox_idx, perm_idx);
	BOGI128.num_round = num_round;

	BOGI128_Set_Sboxes(sbox_idx);
	BOGI128.Diffusion = BOGI128_omega_diffusion[perm_idx];
	BOGI128.Inv_Diffusion = BOGI128_omega_inv_diffusion[perm_idx];
	BOGI128.Inv_Trans_Diffusion = BOGI128_omega_diffusion[perm_idx];
	BOGI128.Trans_Diffusion = BOGI128_omega_inv_diffusion[perm_idx];
	OMEGA_TYPE = BOGI128_omega_types[perm_idx];

	BOGI128_info_out(OMEGA_TYPE);

	SPN_Prep_Info_For_LC(&BOGI128);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI128(&BOGI128, OMEGA_TYPE);
#else
	Use_Predefined_1Round_Active_Maps(&BOGI128);
#endif
	SPN_Best_LC_Corr_Search(rst, &BOGI128, 0, num_round, verbose);
}