#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"

SBOX_O_WRD_t CRAFT64_sboxes[16 * 16] =
{
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,

	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,

	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,

	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6,
	0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6
};

//w0, w4, w8, w12, w1, w5, w9, w13, w2, w6, w10, w14, w3, w7, w11, w15
//||  ||  ||   ||  ||  ||  ||   ||  ||  ||   ||   ||  ||  ||   ||   ||
//o0, o1, o2,  o3, o4, o5, o6,  o7, o8, o9, o10, o11,o12,o13, o14, o15
void CRAFT64_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	/*
	// 1 0 1 1
	// 0 1 0 1
	// 0 0 1 0
	// 0 0 0 1
	*/


	//Mix Column
	temp[0] = in[0] ^ in[2] ^ in[3];
	temp[1] = in[1] ^ in[3];
	temp[2] = in[2];
	temp[3] = in[3];

	temp[4] = in[4] ^ in[6] ^ in[7];
	temp[5] = in[5] ^ in[7];
	temp[6] = in[6];
	temp[7] = in[7];

	temp[8]  = in[8] ^ in[10] ^ in[11];
	temp[9]  = in[9] ^ in[11];
	temp[10] = in[10];
	temp[11] = in[11];

	temp[12] = in[12] ^ in[14] ^ in[15];
	temp[13] = in[13] ^ in[15];
	temp[14] = in[14];
	temp[15] = in[15];

	//ShuffleCell
	out[0] = temp[15];
	out[1] = temp[10];
	out[2] = temp[9];
	out[3] = temp[4];

	out[4] = temp[3];
	out[5] = temp[6];
	out[6] = temp[5];
	out[7] = temp[8];

	out[8] = temp[7];
	out[9] = temp[2];
	out[10] = temp[1];
	out[11] = temp[12];

	out[12] = temp[11];
	out[13] = temp[14];
	out[14] = temp[13];
	out[15] = temp[0];
}


//w0, w4, w8, w12, w1, w5, w9, w13, w2, w6, w10, w14, w3, w7, w11, w15
//||  ||  ||   ||  ||  ||  ||   ||  ||  ||   ||   ||  ||  ||   ||   ||
//o0, o1, o2,  o3, o4, o5, o6,  o7, o8, o9, o10, o11,o12,o13, o14, o15
void CRAFT64_inv_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//Inverse ShuffleCell
	temp[0] = in[15];
	temp[1] = in[10];
	temp[2] = in[9];
	temp[3] = in[4];

	temp[4] = in[3];
	temp[5] = in[6];
	temp[6] = in[5];
	temp[7] = in[8];

	temp[8] = in[7];
	temp[9] = in[2];
	temp[10] = in[1];
	temp[11] = in[12];

	temp[12] = in[11];
	temp[13] = in[14];
	temp[14] = in[13];
	temp[15] = in[0];


	//Inverse Mix Column
	out[0] = temp[0] ^ temp[2] ^ temp[3];
	out[1] = temp[1] ^ temp[3];
	out[2] = temp[2];
	out[3] = temp[3];

	out[4] = temp[4] ^ temp[6] ^ temp[7];
	out[5] = temp[5] ^ temp[7];
	out[6] = temp[6];
	out[7] = temp[7];

	out[8] = temp[8] ^ temp[10] ^ temp[11];
	out[9] = temp[9] ^ temp[11];
	out[10] = temp[10];
	out[11] = temp[11];

	out[12] = temp[12] ^ temp[14] ^ temp[15];
	out[13] = temp[13] ^ temp[15];
	out[14] = temp[14];
	out[15] = temp[15];

}


//w0, w4, w8, w12, w1, w5, w9, w13, w2, w6, w10, w14, w3, w7, w11, w15
//||  ||  ||   ||  ||  ||  ||   ||  ||  ||   ||   ||  ||  ||   ||   ||
//o0, o1, o2,  o3, o4, o5, o6,  o7, o8, o9, o10, o11,o12,o13, o14, o15
void CRAFT64_inv_trans_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//inverse transpose matrix
	/*
	// 1 0 0 0
	// 0 1 0 0
	// 1 0 1 0
	// 1 1 0 1
	*/

	//inverse transpose Mix Column
	temp[0] = in[0];
	temp[1] = in[1];
	temp[2] = in[2] ^ in[0];
	temp[3] = in[3] ^ in[0] ^ in[1];

	temp[4] = in[4];
	temp[5] = in[5];
	temp[6] = in[6] ^ in[4];
	temp[7] = in[7] ^ in[4] ^ in[5];

	temp[8] = in[8];
	temp[9] = in[9];
	temp[10] = in[10] ^ in[8];
	temp[11] = in[11] ^ in[8] ^ in[9];

	temp[12] = in[12];
	temp[13] = in[13];
	temp[14] = in[14] ^ in[12];
	temp[15] = in[15] ^ in[12] ^ in[13];

	//ShuffleCell
	out[0] = temp[15];
	out[1] = temp[10];
	out[2] = temp[9];
	out[3] = temp[4];

	out[4] = temp[3];
	out[5] = temp[6];
	out[6] = temp[5];
	out[7] = temp[8];

	out[8] = temp[7];
	out[9] = temp[2];
	out[10] = temp[1];
	out[11] = temp[12];

	out[12] = temp[11];
	out[13] = temp[14];
	out[14] = temp[13];
	out[15] = temp[0];
}


//w0, w4, w8, w12, w1, w5, w9, w13, w2, w6, w10, w14, w3, w7, w11, w15
//||  ||  ||   ||  ||  ||  ||   ||  ||  ||   ||   ||  ||  ||   ||   ||
//o0, o1, o2,  o3, o4, o5, o6,  o7, o8, o9, o10, o11,o12,o13, o14, o15
void CRAFT64_trans_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//transpose ShuffleCell
	temp[0] = in[15];
	temp[1] = in[10];
	temp[2] = in[9];
	temp[3] = in[4];

	temp[4] = in[3];
	temp[5] = in[6];
	temp[6] = in[5];
	temp[7] = in[8];

	temp[8] = in[7];
	temp[9] = in[2];
	temp[10] = in[1];
	temp[11] = in[12];

	temp[12] = in[11];
	temp[13] = in[14];
	temp[14] = in[13];
	temp[15] = in[0];


	//transpose Mix Column
	out[0] = temp[0];
	out[1] = temp[1];
	out[2] = temp[2] ^ temp[0];
	out[3] = temp[3] ^ temp[0] ^ temp[1];

	out[4] = temp[4];
	out[5] = temp[5];
	out[6] = temp[6] ^ temp[4];
	out[7] = temp[7] ^ temp[4] ^ temp[5];

	out[8] = temp[8];
	out[9] = temp[9];
	out[10] = temp[10] ^ temp[8];
	out[11] = temp[11] ^ temp[8] ^ temp[9];

	out[12] = temp[12];
	out[13] = temp[13];
	out[14] = temp[14] ^ temp[12];
	out[15] = temp[15] ^ temp[12] ^ temp[13];

}



#define CRAFT64_DC_KNOWN_BEST_ROUND 0
void CRAFT64_set_known_prob_bound(PROB_t * B)
{
	// 0Round :nothing
	B[0] = (PROB_t)0;
};

#define CRAFT64_LC_KNOWN_BEST_ROUND 0
void CRAFT64_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
};


#define CRAFT64_NUM_ROUND 30
PROB_t CRAFT64_each_round_initial_prob_bound[CRAFT64_NUM_ROUND + 1] =
{
(PROB_t)0,    //0-round
};
CORR_t CRAFT64_each_round_initial_corr_bound[CRAFT64_NUM_ROUND + 1] =
{
{POSI, (ABS_CORR_t)0},		//0-round
};

SEARCHING_START_OPT_t CRAFT64_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t CRAFT64_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	CRAFT64_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-3,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	CRAFT64_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2}
};

DIFFUSION_BOUND_OPT_t CRAFT64_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	4,
	/*diff_branch_num*/
	2,
	/*inv_trans_diff_branch_num*/
	2,
};

BLK_CIPHER_INFO_t CRAFT64 =
{
	/*general information*/
	//algname
	"CRAFT64",
	//alg_structure
	SPN,
	//num_round
	CRAFT64_NUM_ROUND,
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
	CRAFT64_sboxes,

	/*about diffusion*/
	//diffusion_info [what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))]
	PARTIAL_BINARY_MATRIX,
	/*diff_i_word_bit_size*/
	4,
	/*diff_o_word_bit_size*/
	4,
	//diffusion functions
	//Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	CRAFT64_diffusion,
	//Inv_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	CRAFT64_inv_diffusion,
	//Inv_Trans_Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	CRAFT64_inv_trans_diffusion,
	//Trans_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	CRAFT64_trans_diffusion,

	/*about bound info*/
	//dc_known_best_round
	CRAFT64_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	CRAFT64_set_known_prob_bound,
	//lc_known_best_round
	CRAFT64_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	CRAFT64_set_known_corr_bound,
	/*start searching opt ptr*/
	&CRAFT64_searching_start_opt,
	&CRAFT64_set_initial_bound_opt,
	&CRAFT64_diffusion_bound_opt
};


void PY_CRAFT64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_DC(&CRAFT64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_CRAFT64(&CRAFT64);
#else
	Use_Predefined_1Round_Active_Maps(&CRAFT64);
#endif
	SPN_Best_DC_Prob_Search(rst, &CRAFT64, 0, num_round, verbose);
}

void PY_CRAFT64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_LC(&CRAFT64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_CRAFT64(&CRAFT64);
#else
	Use_Predefined_1Round_Active_Maps(&CRAFT64);
#endif
	SPN_Best_LC_Corr_Search(rst, &CRAFT64, 0, num_round, verbose);
}