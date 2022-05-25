#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "bit_perm_opt.h"
#include "active_map.h"
#include <stdio.h>
#include <string.h>

extern SBOX_O_WRD_t BOGI_applicable_sboxes[1728][16];

extern void(*BOGI32_omega_diffusion[576])(DIFF_O_WRD_t *, DIFF_I_WRD_t *);
extern void(*BOGI32_omega_inv_diffusion[576])(DIFF_I_WRD_t *, DIFF_O_WRD_t *);

SBOX_O_WRD_t BOGI32_sboxes[8 * 16] =
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
};


#define BOGI32_DC_KNOWN_BEST_ROUND 0

void BOGI32_set_known_prob_bound(PROB_t * B)
{
	// 0Round :nothing
	B[0] = (PROB_t)0;
};

#define BOGI32_LC_KNOWN_BEST_ROUND 0
void BOGI32_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
};

#define BOGI32_NUM_ROUND 40
PROB_t BOGI32_each_round_initial_prob_bound[BOGI32_NUM_ROUND + 1] =
{
	(PROB_t)0, //0-round
};
CORR_t BOGI32_each_round_initial_corr_bound[BOGI32_NUM_ROUND + 1] =
{
	{POSI, (ABS_CORR_t)0}, //0-round
};

SEARCHING_START_OPT_t BOGI32_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t BOGI32_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	BOGI32_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-5,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	BOGI32_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2.5}
};

DIFFUSION_BOUND_OPT_t BOGI32_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	4,
	/*diff_branch_num*/
	UNKNOWN,
	/*inv_trans_diff_branch_num*/
	UNKNOWN
};

BLK_CIPHER_INFO_t BOGI32 =
{
	/*general information*/
	//algname
	"BOGI32",
	//alg_structure
	SPN,
	//num_round
	BOGI32_NUM_ROUND,
	//block_bit_size
	32,
	//key_bit_size
	128,
	//num_word_in_a_state
	8,

	/*about substitution*/
	//distinct_sbox
	FALSE,
	//sbox_i_word_bit_size
	4,
	//sbox_o_word_bit_size
	4,
	//sboxes
	BOGI32_sboxes,

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
	BOGI32_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	BOGI32_set_known_prob_bound,
	//lc_known_best_round
	BOGI32_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	BOGI32_set_known_corr_bound,
	/*start searching opt ptr*/
	&BOGI32_searching_start_opt,
	&BOGI32_set_initial_bound_opt,
	&BOGI32_diffusion_bound_opt
};


#define BOGI32_NUM_WORD_IN_A_STATE (8)
#define BOGI32_SBOX_ENTRIES (16)

void BOGI32_Set_Sboxes(CNT_t sbox_idx)
{
	int i;
	for (i = 0; i < BOGI32_NUM_WORD_IN_A_STATE; i++)
	{
		int cpy_st_idx = i * BOGI32_SBOX_ENTRIES;
		memcpy(BOGI32_sboxes + cpy_st_idx, BOGI_applicable_sboxes[sbox_idx], sizeof(SBOX_O_WRD_t) * BOGI32_SBOX_ENTRIES);
	}
}

// There are 8 round commuting word-wise permutations for BOGI32 ciphers
// BOGI32_W00 : (0, 1, 2, 3, 4, 5, 6, 7) A : {(0, 1, 2, 3)}				  C: (0, 1)
// BOGI32_W01 : (1, 0, 3, 2, 5, 4, 7, 6) A : {(1, 0, 3, 2)}				  C: (0, 1)
// BOGI32_W02 : (1, 2, 3, 0, 5, 6, 7, 4) A : {(1, 2, 3, 0)}				  C: (0, 1)
// BOGI32_W03 : (2, 3, 0, 1, 6, 7, 4, 5) A : {(2, 3, 0, 1)}				  C: (0, 1)
// BOGI32_W04 : (3, 0, 1, 2, 7, 4, 5, 6) A : {(3, 0, 1, 2)}				  C: (0, 1)
// BOGI32_W05 : (3, 2, 1, 0, 7, 6, 5, 4) A : {(3, 2, 1, 0)}				  C: (0, 1)
// BOGI32_W06 : (4, 5, 6, 7, 0, 1, 2, 3) A : {(0, 1, 2, 3)}				  C: (1, 0)
// BOGI32_W07 : (4, 5, 6, 7, 2, 3, 0, 1) A : {(2, 3, 0, 1), (0, 1, 2, 3)} C: (1, 0)
// BOGI32_W08 : (5, 4, 7, 6, 1, 0, 3, 2) A : {(1, 0, 3, 2)}				  C: (1, 0)
// BOGI32_W09 : (5, 6, 7, 4, 3, 0, 1, 2) A : {(1, 2, 3, 0), (3, 0, 1, 2)} C: (1, 0)
// BOGI32_W0A : (6, 7, 4, 5, 0, 1, 2, 3) A : {(2, 3, 0, 1), (0, 1, 2, 3)} C: (1, 0)
// BOGI32_W0B : (6, 7, 4, 5, 2, 3, 0, 1) A : {(2, 3, 0, 1)}				  C: (1, 0)
// BOGI32_W0C : (7, 4, 5, 6, 1, 2, 3, 0) A : {(3, 0, 1, 2), (1, 2, 3, 0)} C: (1, 0)
// BOGI32_W0D : (7, 6, 5, 4, 3, 2, 1, 0) A : {(3, 2, 1, 0)}				  C: (1, 0)
//
// There are 5 types of round commuting word-wise permutation sets(GIFT(344) - BOGI32_0)
// BOGI32_0 : 1 : [W00]
// BOGI32_1 : 2 : [W00, W0D]
// BOGI32_2 : 4 : [W00, W01, W06, W08]
// BOGI32_3 : 8 : [W00, W01, W03, W05, W06, W08, W0B, W0D]
// BOGI32_4 : 8 : [W00, W02, W03, W04, W07, W09, W0A, W0C]
CNT_t BOGI32_omega_types[576] =
{
	BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_1, BOGI32_1, BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0,
	BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_2, BOGI32_2, BOGI32_1, BOGI32_1,
	BOGI32_2, BOGI32_2, BOGI32_4, BOGI32_4, BOGI32_1, BOGI32_3, BOGI32_3, BOGI32_1, BOGI32_0, BOGI32_0, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3,
	BOGI32_4, BOGI32_3, BOGI32_3, BOGI32_4, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_4, BOGI32_4,
	BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_3, BOGI32_3, BOGI32_2, BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_2, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0,
	BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_2, BOGI32_2, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3,
	BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_1, BOGI32_1, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_1, BOGI32_1, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3,
	BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_3, BOGI32_3, BOGI32_2, BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_2, BOGI32_2, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_4, BOGI32_4, BOGI32_1, BOGI32_3, BOGI32_3, BOGI32_1, BOGI32_2, BOGI32_2,
	BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_1, BOGI32_1, BOGI32_0, BOGI32_0, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3,
	BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_4, BOGI32_4, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_4, BOGI32_3, BOGI32_3, BOGI32_4, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_4, BOGI32_3, BOGI32_3, BOGI32_4, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_4, BOGI32_4, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0,
	BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_0, BOGI32_0, BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_2, BOGI32_2,
	BOGI32_2, BOGI32_2, BOGI32_1, BOGI32_3, BOGI32_3, BOGI32_1, BOGI32_4, BOGI32_4, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_1, BOGI32_1,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_2, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_2, BOGI32_2, BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_3, BOGI32_3, BOGI32_2, BOGI32_0, BOGI32_0,
	BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_1, BOGI32_1, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0,
	BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3,
	BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_2, BOGI32_0, BOGI32_0, BOGI32_2, BOGI32_3, BOGI32_3, BOGI32_2, BOGI32_0, BOGI32_0,
	BOGI32_4, BOGI32_4, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_4, BOGI32_3, BOGI32_3, BOGI32_4,
	BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_0, BOGI32_0, BOGI32_1, BOGI32_3, BOGI32_3, BOGI32_1, BOGI32_4, BOGI32_4, BOGI32_2, BOGI32_2,
	BOGI32_1, BOGI32_1, BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_4, BOGI32_4, BOGI32_3, BOGI32_2, BOGI32_2, BOGI32_3, BOGI32_1, BOGI32_1,
	BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_3, BOGI32_0, BOGI32_3, BOGI32_1, BOGI32_1, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_0, BOGI32_0,
	BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_1, BOGI32_1, BOGI32_1, BOGI32_1, BOGI32_0, BOGI32_0, BOGI32_3, BOGI32_0, BOGI32_0, BOGI32_3
};

void BOGI32_info_out(CNT_t OMEGA_TYPE)
{
	int i;
	FILE* ofp;
	char name[256];
	sprintf_s(name, 256, "%s_info.txt", BOGI32.alg_name);
	ofp = fopen(name, "w");
	fprintf(ofp, "%s\n", bogi32_commuting_types_strs[OMEGA_TYPE]);
	for (i = 0; i < BOGI32_NUM_WORD_IN_A_STATE; i++)
	{
		int j;
		for (j = 0; j < BOGI32_SBOX_ENTRIES; j++)
		{
			fprintf(ofp, "%d, ", BOGI32_sboxes[i*BOGI32_SBOX_ENTRIES + j]);
		}
		fprintf(ofp, "\n");
	}
	fclose(ofp);
}

void PY_BOGI32_DC_Prob_Searching(
	PROB_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx,
	UFLAG_t verbose
)
{
	CNT_t OMEGA_TYPE;
	sprintf_s(BOGI32.alg_name, 256, "BOGI32_%d_%d", sbox_idx, perm_idx);
	BOGI32.num_round = num_round;

	BOGI32_Set_Sboxes(sbox_idx);
	BOGI32.Diffusion = BOGI32_omega_diffusion[perm_idx];
	BOGI32.Inv_Diffusion = BOGI32_omega_inv_diffusion[perm_idx];
	BOGI32.Inv_Trans_Diffusion = BOGI32_omega_diffusion[perm_idx];
	BOGI32.Trans_Diffusion = BOGI32_omega_inv_diffusion[perm_idx];
	OMEGA_TYPE = BOGI32_omega_types[perm_idx];

	BOGI32_info_out(OMEGA_TYPE);

	SPN_Prep_Info_For_DC(&BOGI32);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI32(&BOGI32, OMEGA_TYPE);
#else
	Use_Predefined_1Round_Active_Maps(&BOGI32);
#endif
	SPN_Best_DC_Prob_Search(rst, &BOGI32, 0, num_round, verbose);
}


void PY_BOGI32_LC_Corr_Searching(
	CORR_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx,
	UFLAG_t verbose
)
{
	CNT_t OMEGA_TYPE;
	sprintf_s(BOGI32.alg_name, 256, "BOGI32_%d_%d", sbox_idx, perm_idx);
	BOGI32.num_round = num_round;

	BOGI32_Set_Sboxes(sbox_idx);
	BOGI32.Diffusion = BOGI32_omega_diffusion[perm_idx];
	BOGI32.Inv_Diffusion = BOGI32_omega_inv_diffusion[perm_idx];
	BOGI32.Inv_Trans_Diffusion = BOGI32_omega_diffusion[perm_idx];
	BOGI32.Trans_Diffusion = BOGI32_omega_inv_diffusion[perm_idx];
	OMEGA_TYPE = BOGI32_omega_types[perm_idx];

	BOGI32_info_out(OMEGA_TYPE);

	SPN_Prep_Info_For_LC(&BOGI32);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI32(&BOGI32, OMEGA_TYPE);
#else
	Use_Predefined_1Round_Active_Maps(&BOGI32);
#endif
	SPN_Best_LC_Corr_Search(rst, &BOGI32, 0, num_round, verbose);
}