#include <string.h>
#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"



/*local variables*/
BLK_CIPHER_INFO_t SBMN;
NUM_t SBMN_NUM_DIFF_IN_A_STATE;
NUM_t SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION;
CNT_t * BIN_MAT;
CNT_t * INV_BIN_MAT;
CNT_t * INV_TRANS_BIN_MAT;
CNT_t * TRANS_BIN_MAT;


CNT_t * SHUFFLE_IDX;
CNT_t * INV_SHUFFLE_IDX = NULL;



////Diffusion For DC searching
void SBMN_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	CNT_t word_idx;
	CNT_t bin_row_idx;
	CNT_t bin_col_idx;
	CNT_t text_col_idx;
	DIFF_I_WRD_t instate[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
	
	//binary matrix multiplication
	for (bin_row_idx = 0; bin_row_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_row_idx++)
	{
		for (text_col_idx = 0; text_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; text_col_idx++)
		{
			for (bin_col_idx = 0; bin_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_col_idx++)
			{
				if (BIN_MAT[bin_row_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx] != 0)
				{
					instate[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_row_idx] ^= in[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx];
				}
			}
		}
	}


	//shuffle
	for (word_idx = 0; word_idx < SBMN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		out[SHUFFLE_IDX[word_idx]] = instate[word_idx];
	}
}
void SBMN_inv_diffusion(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	CNT_t word_idx;
	CNT_t bin_row_idx;
	CNT_t bin_col_idx;
	CNT_t text_col_idx;
	DIFF_O_WRD_t instate[NUM_WORD_IN_A_STATE_THRESHOLD];
	DIFF_I_WRD_t instate2[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
	//inv shuffle
	for (word_idx = 0; word_idx < SBMN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		instate[INV_SHUFFLE_IDX[word_idx]] = in[word_idx];
	}
	
	//inv_binary matrix multiplication
	for (bin_row_idx = 0; bin_row_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_row_idx++)
	{
		for (text_col_idx = 0; text_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; text_col_idx++)
		{
			for (bin_col_idx = 0; bin_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_col_idx++)
			{
				if (INV_BIN_MAT[bin_row_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx] != 0)
				{
					instate2[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_row_idx] ^= instate[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx];
				}
			}
		}
	}
	memcpy(out, instate2, sizeof(DIFF_I_WRD_t) * SBMN_NUM_DIFF_IN_A_STATE);
}
////////////////////////////////////

////Diffusion For LC searching
void SBMN_inv_trans_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	CNT_t word_idx;
	CNT_t bin_row_idx;
	CNT_t bin_col_idx;
	CNT_t text_col_idx;
	DIFF_I_WRD_t instate[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };

	//inverse transpose binary matrix multiplication
	for (bin_row_idx = 0; bin_row_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_row_idx++)
	{
		for (text_col_idx = 0; text_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; text_col_idx++)
		{
			for (bin_col_idx = 0; bin_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_col_idx++)
			{
				if (INV_TRANS_BIN_MAT[bin_row_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx] != 0)
				{
					instate[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_row_idx] ^= in[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx];
				}
			}
		}
	}


	//shuffle
	for (word_idx = 0; word_idx < SBMN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		out[SHUFFLE_IDX[word_idx]] = instate[word_idx];
	}
}
void SBMN_trans_diffusion(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	CNT_t word_idx;
	CNT_t bin_row_idx;
	CNT_t bin_col_idx;
	CNT_t text_col_idx;
	DIFF_O_WRD_t instate[NUM_WORD_IN_A_STATE_THRESHOLD];
	DIFF_I_WRD_t instate2[NUM_WORD_IN_A_STATE_THRESHOLD] = { 0, };
	//inv shuffle
	for (word_idx = 0; word_idx < SBMN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		instate[INV_SHUFFLE_IDX[word_idx]] = in[word_idx];
	}

	//trans matrix multiplication
	for (bin_row_idx = 0; bin_row_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_row_idx++)
	{
		for (text_col_idx = 0; text_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; text_col_idx++)
		{
			for (bin_col_idx = 0; bin_col_idx < SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION; bin_col_idx++)
			{
				if (TRANS_BIN_MAT[bin_row_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx] != 0)
				{
					instate2[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_row_idx] ^= instate[text_col_idx * SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION + bin_col_idx];
				}
			}
		}
	}
	memcpy(out, instate2, sizeof(DIFF_I_WRD_t) * SBMN_NUM_DIFF_IN_A_STATE);
}
////////////////////////////////////

SET_INITIAL_BOUND_OPT_t SBMN_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	NULL,
	/*prob_interval*/
	ZERO_PROB,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	NULL,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)1}
};

DIFFUSION_BOUND_OPT_t SBMN_diffusion_bound_opt;




void SBMN_Template_DC_Prob_Searching(PROB_t * rst, SBMN_BLK_CIPHER_t * ci, UFLAG_t verbose)
{
	CNT_t i, o;

	strcpy(SBMN.alg_name, "SBMN");
	SBMN.alg_structure = SPN; //fixed
	SBMN.num_round = ci->num_round;
	SBMN.block_bit_size = ci->num_word_in_a_state * ci->word_bit_size;
	SBMN.key_bit_size = ci->num_word_in_a_state * ci->word_bit_size * 2; //by default
	SBMN.num_word_in_a_state = ci->num_word_in_a_state;

	SBMN.distinct_sbox = ci->distinct_sbox;
	SBMN.sbox_i_word_bit_size = ci->word_bit_size;
	SBMN.sbox_o_word_bit_size = ci->word_bit_size;
	SBMN.sboxes = ci->sboxes;

	SBMN.diffusion_info = PARTIAL_BINARY_MATRIX; //fixed
	SBMN.diff_i_word_bit_size = ci->word_bit_size;
	SBMN.diff_o_word_bit_size = ci->word_bit_size;

	SBMN.Diffusion = SBMN_diffusion; /*Declare here*/
	SBMN.Inv_Diffusion = SBMN_inv_diffusion; /*Declare here*/
	SBMN.Inv_Trans_Diffusion = SBMN_inv_trans_diffusion; /*Declare here*/
	SBMN.Trans_Diffusion = SBMN_trans_diffusion; /*Declare here*/

	SBMN.dc_known_best_round = 0; /*This is always fixed*/
	SBMN.Set_Known_Prob_Bound = NULL; /*This is always fixed*/
	SBMN.lc_known_best_round = 0; /*This is always fixed*/
	SBMN.Set_Known_Corr_Bound = NULL; /*This is always fixed*/

	SBMN.searching_start_opt = ci->searching_start_opt;
	SBMN.set_initial_bound_opt = &SBMN_initial_bound_opt; /*This is always fixed*/
	
	SBMN.diffusion_bound_opt = &SBMN_diffusion_bound_opt;
	SBMN.diffusion_bound_opt->num_diff_of_partial_diffusion = ci->diffusion_bound_opt->num_diff_of_partial_diffusion;
	SBMN.diffusion_bound_opt->diff_branch_num = ci->diffusion_bound_opt->diff_branch_num;
	SBMN.diffusion_bound_opt->inv_trans_diff_branch_num = ci->diffusion_bound_opt->inv_trans_diff_branch_num;

	SBMN_NUM_DIFF_IN_A_STATE = SBMN.num_word_in_a_state;
	SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION = SBMN.diffusion_bound_opt->num_diff_of_partial_diffusion;

	BIN_MAT = ci->bin_mat;
	INV_BIN_MAT = ci->inv_bin_mat;
	INV_TRANS_BIN_MAT = ci->inv_trans_bin_mat;
	TRANS_BIN_MAT = ci->trans_bin_mat;

	SHUFFLE_IDX = ci->shuffle_idx;

	if (INV_SHUFFLE_IDX != NULL)
	{
		free(INV_SHUFFLE_IDX);
		INV_SHUFFLE_IDX = NULL;
	}
	INV_SHUFFLE_IDX = (CNT_t*)malloc(sizeof(CNT_t) * (size_t)SBMN_NUM_DIFF_IN_A_STATE);

	for (i = 0; i < SBMN_NUM_DIFF_IN_A_STATE; i++)
	{
		for (o = 0; o < SBMN_NUM_DIFF_IN_A_STATE; o++)
		{
			if (SHUFFLE_IDX[o] == i)
			{
				INV_SHUFFLE_IDX[i] = o;
				break;
			}
		}
	}
	SPN_Prep_Info_For_DC(&SBMN);
	Use_Predefined_1Round_Active_Maps(&SBMN);
	SPN_Best_DC_Prob_Search(rst, &SBMN, 0, ci->num_round, verbose);
}

void SBMN_Template_LC_Corr_Searching(CORR_t * rst, SBMN_BLK_CIPHER_t * ci, UFLAG_t verbose)
{
	CNT_t i, o;

	strcpy(SBMN.alg_name, "SBMN");
	SBMN.alg_structure		 = SPN; //fixed
	SBMN.num_round			 = ci->num_round;
	SBMN.block_bit_size		 = ci->num_word_in_a_state * ci->word_bit_size;
	SBMN.key_bit_size		 = ci->num_word_in_a_state * ci->word_bit_size * 2; //by default
	SBMN.num_word_in_a_state = ci->num_word_in_a_state;

	SBMN.distinct_sbox			= ci->distinct_sbox;
	SBMN.sbox_i_word_bit_size	= ci->word_bit_size;
	SBMN.sbox_o_word_bit_size	= ci->word_bit_size;
	SBMN.sboxes					= ci->sboxes;

	SBMN.diffusion_info			= PARTIAL_BINARY_MATRIX; //fixed
	SBMN.diff_i_word_bit_size	= ci->word_bit_size;
	SBMN.diff_o_word_bit_size	= ci->word_bit_size;

	SBMN.Diffusion				= SBMN_diffusion; /*Declare here*/
	SBMN.Inv_Diffusion			= SBMN_inv_diffusion; /*Declare here*/
	SBMN.Inv_Trans_Diffusion	= SBMN_inv_trans_diffusion; /*Declare here*/
	SBMN.Trans_Diffusion		= SBMN_trans_diffusion; /*Declare here*/

	SBMN.dc_known_best_round	= 0; /*This is always fixed*/
	SBMN.Set_Known_Prob_Bound	= NULL; /*This is always fixed*/
	SBMN.lc_known_best_round	= 0; /*This is always fixed*/
	SBMN.Set_Known_Corr_Bound	= NULL; /*This is always fixed*/

	SBMN.searching_start_opt	= ci->searching_start_opt;
	SBMN.set_initial_bound_opt	= &SBMN_initial_bound_opt; /*This is always fixed*/
	SBMN.diffusion_bound_opt	= &SBMN_diffusion_bound_opt;

	SBMN.diffusion_bound_opt->num_diff_of_partial_diffusion = ci->diffusion_bound_opt->num_diff_of_partial_diffusion;
	SBMN.diffusion_bound_opt->diff_branch_num				= ci->diffusion_bound_opt->diff_branch_num;
	SBMN.diffusion_bound_opt->inv_trans_diff_branch_num		= ci->diffusion_bound_opt->inv_trans_diff_branch_num;


	SBMN_NUM_DIFF_IN_A_STATE = SBMN.num_word_in_a_state;
	SBMN_NUM_DIFF_OF_PARTIAL_DIFFUSION = SBMN.diffusion_bound_opt->num_diff_of_partial_diffusion;


	BIN_MAT = ci->bin_mat;
	INV_BIN_MAT = ci->inv_bin_mat;
	INV_TRANS_BIN_MAT = ci->inv_trans_bin_mat;
	TRANS_BIN_MAT = ci->trans_bin_mat;

	SHUFFLE_IDX = ci->shuffle_idx;

	if (INV_SHUFFLE_IDX != NULL)
	{
		free(INV_SHUFFLE_IDX);
		INV_SHUFFLE_IDX = NULL;
	}
	INV_SHUFFLE_IDX = (CNT_t*)malloc(sizeof(CNT_t) * (size_t)SBMN_NUM_DIFF_IN_A_STATE);

	for (i = 0; i < SBMN_NUM_DIFF_IN_A_STATE; i++)
	{
		for (o = 0; o < SBMN_NUM_DIFF_IN_A_STATE; o++)
		{
			if (SHUFFLE_IDX[o] == i)
			{
				INV_SHUFFLE_IDX[i] = o;
				break;
			}
		}
	}
	SPN_Prep_Info_For_LC(&SBMN);
	Use_Predefined_1Round_Active_Maps(&SBMN);
	SPN_Best_LC_Corr_Search(rst, &SBMN, 0, ci->num_round, verbose);
}



void PY_SBMN_Template_DC_Prob_Searching(
	PROB_t * rst,
	CNT_t num_round,
	CNT_t num_word_in_a_state,
	BIT_SIZE_t word_bit_size,
	FLAG_t distinct_sbox,
	SBOX_O_WRD_t * sboxes,

	CNT_t * bin_mat,
	CNT_t * inv_bin_mat,
	NUM_t diff_branch_num,

	CNT_t * inv_trans_bin_mat,
	CNT_t * trans_bin_mat,
	NUM_t inv_trans_diff_branch_num,

	CNT_t * shuffle_idx,
	
	FLAG_t enable_1round_active_map,
	FLAG_t rotational_symmetric_equivalent,
	NUM_t num_diff_of_partial_diffusion,
	UFLAG_t verbose
)
{
	SBMN_BLK_CIPHER_t inner = { 0, };
	SEARCHING_START_OPT_t inner_searching_start_opt;
	DIFFUSION_BOUND_OPT_t inner_diffusion_bound_opt;

	inner.num_round = num_round;
	inner.num_word_in_a_state = num_word_in_a_state;
	inner.word_bit_size = word_bit_size;

	inner.distinct_sbox = distinct_sbox;
	inner.sboxes = sboxes;

	inner.searching_start_opt = &inner_searching_start_opt;
	inner.diffusion_bound_opt = &inner_diffusion_bound_opt;

	inner.searching_start_opt->enable_1round_active_map = enable_1round_active_map;
	inner.searching_start_opt->rotational_symmetric_equivalent = rotational_symmetric_equivalent;
	inner.diffusion_bound_opt->num_diff_of_partial_diffusion = num_diff_of_partial_diffusion;

	inner.bin_mat = bin_mat;
	inner.inv_bin_mat = inv_bin_mat;
	inner_diffusion_bound_opt.diff_branch_num = diff_branch_num;

	inner.inv_trans_bin_mat = inv_trans_bin_mat;
	inner.trans_bin_mat = trans_bin_mat;
	inner_diffusion_bound_opt.inv_trans_diff_branch_num = inv_trans_diff_branch_num;

	inner.shuffle_idx = shuffle_idx;

	SBMN_Template_DC_Prob_Searching(rst, &inner, verbose);
}


void PY_SBMN_Template_LC_Corr_Searching(
	CORR_t * rst,
	CNT_t num_round,
	CNT_t num_word_in_a_state,
	BIT_SIZE_t word_bit_size,
	FLAG_t distinct_sbox,
	SBOX_O_WRD_t * sboxes,
	
	CNT_t * bin_mat,
	CNT_t * inv_bin_mat,
	NUM_t diff_branch_num,

	CNT_t * inv_trans_bin_mat,
	CNT_t * trans_bin_mat,
	NUM_t inv_trans_diff_branch_num,

	CNT_t * shuffle_idx,

	FLAG_t enable_1round_active_map,
	FLAG_t rotational_symmetric_equivalent,
	NUM_t num_diff_of_partial_diffusion,
	UFLAG_t verbose
)
{
	SBMN_BLK_CIPHER_t inner = { 0, };
	SEARCHING_START_OPT_t inner_searching_start_opt;
	DIFFUSION_BOUND_OPT_t inner_diffusion_bound_opt;

	inner.num_round = num_round;
	inner.num_word_in_a_state = num_word_in_a_state;
	inner.word_bit_size = word_bit_size;

	inner.distinct_sbox = distinct_sbox;
	inner.sboxes = sboxes;

	inner.searching_start_opt = &inner_searching_start_opt;
	inner.diffusion_bound_opt = &inner_diffusion_bound_opt;

	inner.searching_start_opt->enable_1round_active_map = enable_1round_active_map;
	inner.searching_start_opt->rotational_symmetric_equivalent = rotational_symmetric_equivalent;
	inner.diffusion_bound_opt->num_diff_of_partial_diffusion = num_diff_of_partial_diffusion;

	inner.bin_mat = bin_mat;
	inner.inv_bin_mat = inv_bin_mat;
	inner_diffusion_bound_opt.diff_branch_num = diff_branch_num;

	inner.inv_trans_bin_mat = inv_trans_bin_mat;
	inner.trans_bin_mat = trans_bin_mat;
	inner_diffusion_bound_opt.inv_trans_diff_branch_num = inv_trans_diff_branch_num;

	inner.shuffle_idx = shuffle_idx;

	SBMN_Template_LC_Corr_Searching(rst, &inner, verbose);
}