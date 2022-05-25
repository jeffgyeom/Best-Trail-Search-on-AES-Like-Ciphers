#include <string.h>
#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"



/*local variables*/
BLK_CIPHER_INFO_t SBPN;
CNT_t SBPN_NUM_DIFF_IN_A_STATE;
CNT_t SBPN_DIFF_I_BIT_SIZE;
CNT_t SBPN_DIFFUSION_STATE_BIT_SIZE;
CNT_t * PERM_IDX;
CNT_t * INV_PERM_IDX = NULL;



////Diffusion For DC searching
void SBPN_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	char * instatebit;
	char * oustatebit;
	CNT_t word_idx;
	CNT_t inbit_idx;
	CNT_t bit_idx;

	instatebit = (char*)malloc(sizeof(char) * (size_t)SBPN_DIFFUSION_STATE_BIT_SIZE);
	oustatebit = (char*)malloc(sizeof(char) * (size_t)SBPN_DIFFUSION_STATE_BIT_SIZE);


	//split to bits
	////Word_idx_order  :          0      ||...||      15 
	////InBit_idx_order : || 3|| 2|| 1|| 0||...|| 3|| 2|| 1|| 0||
	////Bit_idx_order   : || 0|| 1|| 2|| 3||...||60||61||62||63||
	for (word_idx = 0; word_idx < SBPN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		DIFF_O_WRD_t diff_word = in[word_idx];
		for (inbit_idx = 0; inbit_idx < SBPN_DIFF_I_BIT_SIZE; inbit_idx++)
		{
			bit_idx = SBPN_DIFF_I_BIT_SIZE * word_idx;
			bit_idx += (SBPN_DIFF_I_BIT_SIZE - 1 - inbit_idx);

			if ((diff_word & (DIFF_O_WRD_t)(1 << inbit_idx)) != 0)
			{
				instatebit[bit_idx] = 1;
			}
			else
			{
				instatebit[bit_idx] = 0;
			}
		}
	}

	//bit permutation
	for (bit_idx = 0; bit_idx < SBPN_DIFFUSION_STATE_BIT_SIZE; bit_idx++)
	{
		oustatebit[bit_idx] = instatebit[PERM_IDX[bit_idx]];
	}

	//merge to state
	////Bit_idx_order   : || 0|| 1|| 2|| 3||...||60||61||62||63||
	////InBit_idx_order : || 3|| 2|| 1|| 0||...|| 3|| 2|| 1|| 0||
	////Word_idx_order  :          0      ||...||      15 

	for (word_idx = 0; word_idx < SBPN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		DIFF_O_WRD_t diff_out_word = 0x0;
		for (inbit_idx = 0; inbit_idx < SBPN_DIFF_I_BIT_SIZE; inbit_idx++)
		{
			DIFF_O_WRD_t mask = (((DIFF_O_WRD_t)1) << inbit_idx);

			bit_idx = SBPN_DIFF_I_BIT_SIZE * word_idx;
			bit_idx += (SBPN_DIFF_I_BIT_SIZE - 1 - inbit_idx);
			if (oustatebit[bit_idx] == 0x1)
				diff_out_word = diff_out_word | mask;
		}
		out[word_idx] = diff_out_word;
	}
	free(instatebit);
	free(oustatebit);
}

void SBPN_inv_diffusion(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	char * instatebit;
	char * oustatebit;
	CNT_t word_idx;
	CNT_t inbit_idx;
	CNT_t bit_idx;

	instatebit = (char*)malloc(sizeof(char) * (size_t)SBPN_DIFFUSION_STATE_BIT_SIZE);
	oustatebit = (char*)malloc(sizeof(char) * (size_t)SBPN_DIFFUSION_STATE_BIT_SIZE);


	//split to bits
	////Word_idx_order  :          0      ||...||      15 
	////InBit_idx_order : || 3|| 2|| 1|| 0||...|| 3|| 2|| 1|| 0||
	////Bit_idx_order   : || 0|| 1|| 2|| 3||...||60||61||62||63||
	for (word_idx = 0; word_idx < SBPN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		DIFF_O_WRD_t diff_word = in[word_idx];
		for (inbit_idx = 0; inbit_idx < SBPN_DIFF_I_BIT_SIZE; inbit_idx++)
		{
			bit_idx = SBPN_DIFF_I_BIT_SIZE * word_idx;
			bit_idx += (SBPN_DIFF_I_BIT_SIZE - 1 - inbit_idx);

			if ((diff_word & (DIFF_O_WRD_t)(1 << inbit_idx)) != 0)
			{
				instatebit[bit_idx] = 1;
			}
			else
			{
				instatebit[bit_idx] = 0;
			}
		}
	}

	//bit permutation
	for (bit_idx = 0; bit_idx < SBPN_DIFFUSION_STATE_BIT_SIZE; bit_idx++)
	{
		oustatebit[bit_idx] = instatebit[INV_PERM_IDX[bit_idx]];
	}

	//merge to state
	////Bit_idx_order   : || 0|| 1|| 2|| 3||...||60||61||62||63||
	////InBit_idx_order : || 3|| 2|| 1|| 0||...|| 3|| 2|| 1|| 0||
	////Word_idx_order  :          0      ||...||      15 

	for (word_idx = 0; word_idx < SBPN_NUM_DIFF_IN_A_STATE; word_idx++)
	{
		DIFF_O_WRD_t diff_out_word = 0x0;
		for (inbit_idx = 0; inbit_idx < SBPN_DIFF_I_BIT_SIZE; inbit_idx++)
		{
			DIFF_O_WRD_t mask = (((DIFF_O_WRD_t)1) << inbit_idx);

			bit_idx = SBPN_DIFF_I_BIT_SIZE * word_idx;
			bit_idx += (SBPN_DIFF_I_BIT_SIZE - 1 - inbit_idx);
			if (oustatebit[bit_idx] == 0x1)
				diff_out_word = diff_out_word | mask;
		}
		out[word_idx] = diff_out_word;
	}
	free(instatebit);
	free(oustatebit);
}
////////////////////////////////////



SET_INITIAL_BOUND_OPT_t SBPN_initial_bound_opt=
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
DIFFUSION_BOUND_OPT_t SBPN_diffusion_bound_opt;


void SBPN_Template_DC_Prob_Searching(PROB_t * rst, SBPN_BLK_CIPHER_t * ci, UFLAG_t verbose)
{
	CNT_t i, o;

	strcpy(SBPN.alg_name, "SBPN");
	SBPN.alg_structure				= SPN; //fixed
	SBPN.num_round					= ci->num_round;
	SBPN.block_bit_size				= ci->num_word_in_a_state * ci->word_bit_size;
	SBPN.key_bit_size				= ci->num_word_in_a_state * ci->word_bit_size * 2; //by default
	SBPN.num_word_in_a_state		= ci->num_word_in_a_state;

	SBPN.distinct_sbox				= ci->distinct_sbox;
	SBPN.sbox_i_word_bit_size		= ci->word_bit_size;
	SBPN.sbox_o_word_bit_size		= ci->word_bit_size;
	SBPN.sboxes						= ci->sboxes;

	SBPN.diffusion_info				= BIT_PERMUTATION; //fixed
	SBPN.diff_i_word_bit_size		= ci->word_bit_size;
	SBPN.diff_o_word_bit_size		= ci->word_bit_size;

	SBPN.Diffusion					= SBPN_diffusion; /*Declare here*/
	SBPN.Inv_Diffusion				= SBPN_inv_diffusion; /*Declare here*/
	SBPN.Inv_Trans_Diffusion		= SBPN_diffusion; /*Declare here*/
	SBPN.Trans_Diffusion			= SBPN_inv_diffusion; /*Declare here*/

	SBPN.dc_known_best_round		= 0; /*This is always fixed*/
	SBPN.Set_Known_Prob_Bound		= NULL; /*This is always fixed*/
	SBPN.lc_known_best_round		= 0; /*This is always fixed*/
	SBPN.Set_Known_Corr_Bound		= NULL; /*This is always fixed*/

	SBPN.searching_start_opt		= ci->searching_start_opt;
	SBPN.set_initial_bound_opt		= &SBPN_initial_bound_opt; /*This is always fixed*/

	SBPN.diffusion_bound_opt = &SBPN_diffusion_bound_opt;
	SBPN.diffusion_bound_opt->num_diff_of_partial_diffusion		= ci->diffusion_bound_opt->num_diff_of_partial_diffusion;
	SBPN.diffusion_bound_opt->diff_branch_num = UNKNOWN;
	SBPN.diffusion_bound_opt->inv_trans_diff_branch_num = UNKNOWN;


	SBPN_NUM_DIFF_IN_A_STATE		= SBPN.num_word_in_a_state;
	SBPN_DIFF_I_BIT_SIZE			= SBPN.diff_i_word_bit_size;
	SBPN_DIFFUSION_STATE_BIT_SIZE	= ci->num_word_in_a_state * ci->word_bit_size;
	
	PERM_IDX = ci->bitperm_idx;

	if (INV_PERM_IDX != NULL)
	{
		free(INV_PERM_IDX);
		INV_PERM_IDX = NULL;
	}
	INV_PERM_IDX = (CNT_t*)malloc(sizeof(CNT_t) * (size_t)SBPN_DIFFUSION_STATE_BIT_SIZE);

	for (i = 0; i < SBPN_DIFFUSION_STATE_BIT_SIZE; i++)
	{
		for (o = 0; o < SBPN_DIFFUSION_STATE_BIT_SIZE; o++)
		{
			if (PERM_IDX[o] == i)
			{
				INV_PERM_IDX[i] = o;
				break;
			}
		}
	}
	SPN_Prep_Info_For_DC(&SBPN);
	Use_Predefined_1Round_Active_Maps(&SBPN);
	SPN_Best_DC_Prob_Search(rst, &SBPN, 0, ci->num_round, verbose);
}

void SBPN_Template_LC_Corr_Searching(CORR_t * rst, SBPN_BLK_CIPHER_t * ci, UFLAG_t verbose)
{
	CNT_t i, o;

	strcpy(SBPN.alg_name, "SBPN");
	SBPN.alg_structure = SPN; //fixed
	SBPN.num_round = ci->num_round;
	SBPN.block_bit_size = ci->num_word_in_a_state * ci->word_bit_size;
	SBPN.key_bit_size = ci->num_word_in_a_state * ci->word_bit_size * 2; //by default
	SBPN.num_word_in_a_state = ci->num_word_in_a_state;

	SBPN.distinct_sbox = ci->distinct_sbox;
	SBPN.sbox_i_word_bit_size = ci->word_bit_size;
	SBPN.sbox_o_word_bit_size = ci->word_bit_size;
	SBPN.sboxes = ci->sboxes;

	SBPN.diffusion_info = BIT_PERMUTATION; //fixed
	SBPN.diff_i_word_bit_size = ci->word_bit_size;
	SBPN.diff_o_word_bit_size = ci->word_bit_size;

	SBPN.Diffusion = SBPN_diffusion; /*Declare here*/
	SBPN.Inv_Diffusion = SBPN_inv_diffusion; /*Declare here*/
	SBPN.Inv_Trans_Diffusion = SBPN_diffusion; /*Declare here*/
	SBPN.Trans_Diffusion = SBPN_inv_diffusion; /*Declare here*/

	SBPN.dc_known_best_round = 0; /*This is always fixed*/
	SBPN.Set_Known_Prob_Bound = NULL; /*This is always fixed*/
	SBPN.lc_known_best_round = 0; /*This is always fixed*/
	SBPN.Set_Known_Corr_Bound = NULL; /*This is always fixed*/

	SBPN.searching_start_opt = ci->searching_start_opt;
	SBPN.set_initial_bound_opt = &SBPN_initial_bound_opt; /*This is always fixed*/
	SBPN.diffusion_bound_opt = &SBPN_diffusion_bound_opt;

	SBPN.diffusion_bound_opt->num_diff_of_partial_diffusion = ci->diffusion_bound_opt->num_diff_of_partial_diffusion;
	SBPN.diffusion_bound_opt->diff_branch_num = UNKNOWN;
	SBPN.diffusion_bound_opt->inv_trans_diff_branch_num = UNKNOWN;


	SBPN_NUM_DIFF_IN_A_STATE = SBPN.num_word_in_a_state;
	SBPN_DIFF_I_BIT_SIZE = SBPN.diff_i_word_bit_size;
	SBPN_DIFFUSION_STATE_BIT_SIZE = ci->num_word_in_a_state * ci->word_bit_size;

	PERM_IDX = ci->bitperm_idx;

	if (INV_PERM_IDX != NULL)
	{
		free(INV_PERM_IDX);
		INV_PERM_IDX = NULL;
	}
	INV_PERM_IDX = (CNT_t*)malloc(sizeof(CNT_t) * (size_t)SBPN_DIFFUSION_STATE_BIT_SIZE);

	for (i = 0; i < SBPN_DIFFUSION_STATE_BIT_SIZE; i++)
	{
		for (o = 0; o < SBPN_DIFFUSION_STATE_BIT_SIZE; o++)
		{
			if (PERM_IDX[o] == i)
			{
				INV_PERM_IDX[i] = o;
				break;
			}
		}
	}
	SPN_Prep_Info_For_LC(&SBPN);
	Use_Predefined_1Round_Active_Maps(&SBPN);
	SPN_Best_LC_Corr_Search(rst, &SBPN, 0, ci->num_round, verbose);
}



void PY_SBPN_Template_DC_Prob_Searching(
	PROB_t * rst,
	CNT_t num_round,
	CNT_t num_word_in_a_state,
	BIT_SIZE_t word_bit_size,
	FLAG_t distinct_sbox,
	SBOX_O_WRD_t * sboxes,
	CNT_t  *perm_idx,
	FLAG_t enable_1round_active_map,
	FLAG_t rotational_symmetric_equivalent,
	NUM_t num_diff_of_partial_diffusion,
	UFLAG_t verbose
)
{
	SBPN_BLK_CIPHER_t inner = { 0, };
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

	inner.bitperm_idx = perm_idx;

	SBPN_Template_DC_Prob_Searching(rst, &inner, verbose);
}


void PY_SBPN_Template_LC_Corr_Searching(
	CORR_t * rst,
	CNT_t num_round,
	CNT_t num_word_in_a_state,
	BIT_SIZE_t word_bit_size,
	FLAG_t distinct_sbox,
	SBOX_O_WRD_t * sboxes,
	CNT_t  *perm_idx,
	FLAG_t enable_1round_active_map,
	FLAG_t rotational_symmetric_equivalent,
	NUM_t num_diff_of_partial_diffusion,
	UFLAG_t verbose
)
{
	SBPN_BLK_CIPHER_t inner = { 0, };
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

	inner.bitperm_idx = perm_idx;

	SBPN_Template_LC_Corr_Searching(rst, &inner, verbose);
}