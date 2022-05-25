#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"

SBOX_O_WRD_t MIDORI64_sboxes[16 * 16] =
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


void MIDORI64_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//Mix Column
	temp[0] = in[1] ^ in[2] ^ in[3];
	temp[1] = in[0] ^ in[2] ^ in[3];
	temp[2] = in[0] ^ in[1] ^ in[3];
	temp[3] = in[0] ^ in[1] ^ in[2];

	temp[4] = in[5] ^ in[6] ^ in[7];
	temp[5] = in[4] ^ in[6] ^ in[7];
	temp[6] = in[4] ^ in[5] ^ in[7];
	temp[7] = in[4] ^ in[5] ^ in[6];

	temp[8] = in[9] ^ in[10] ^ in[11];
	temp[9] = in[8] ^ in[10] ^ in[11];
	temp[10] = in[8] ^ in[9] ^ in[11];
	temp[11] = in[8] ^ in[9] ^ in[10];

	temp[12] = in[13] ^ in[14] ^ in[15];
	temp[13] = in[12] ^ in[14] ^ in[15];
	temp[14] = in[12] ^ in[13] ^ in[15];
	temp[15] = in[12] ^ in[13] ^ in[14];

	//ShuffleCell
	out[0] = temp[0];
	out[1] = temp[10];
	out[2] = temp[5];
	out[3] = temp[15];
	
	out[4] = temp[14];
	out[5] = temp[4];
	out[6] = temp[11];
	out[7] = temp[1];
	
	out[8] = temp[9];
	out[9] = temp[3];
	out[10] = temp[12];
	out[11] = temp[6];
	
	out[12] = temp[7];
	out[13] = temp[13];
	out[14] = temp[2];
	out[15] = temp[8];
}

void MIDORI64_inv_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//Inverse ShuffleCell
	temp[0] = in[0];
	temp[1] = in[7];
	temp[2] = in[14];
	temp[3] = in[9];

	temp[4] = in[5];
	temp[5] = in[2];
	temp[6] = in[11];
	temp[7] = in[12];

	temp[8] = in[15];
	temp[9] = in[8];
	temp[10] = in[1];
	temp[11] = in[6];

	temp[12] = in[10];
	temp[13] = in[13];
	temp[14] = in[4];
	temp[15] = in[3];


	//Inverse Mix Column
	out[0] = temp[1] ^ temp[2] ^ temp[3];
	out[1] = temp[0] ^ temp[2] ^ temp[3];
	out[2] = temp[0] ^ temp[1] ^ temp[3];
	out[3] = temp[0] ^ temp[1] ^ temp[2];

	out[4] = temp[5] ^ temp[6] ^ temp[7];
	out[5] = temp[4] ^ temp[6] ^ temp[7];
	out[6] = temp[4] ^ temp[5] ^ temp[7];
	out[7] = temp[4] ^ temp[5] ^ temp[6];

	out[8] = temp[9] ^ temp[10] ^ temp[11];
	out[9] = temp[8] ^ temp[10] ^ temp[11];
	out[10] = temp[8] ^ temp[9] ^ temp[11];
	out[11] = temp[8] ^ temp[9] ^ temp[10];

	out[12] = temp[13] ^ temp[14] ^ temp[15];
	out[13] = temp[12] ^ temp[14] ^ temp[15];
	out[14] = temp[12] ^ temp[13] ^ temp[15];
	out[15] = temp[12] ^ temp[13] ^ temp[14];

}

#define MIDORI64_DC_KNOWN_BEST_ROUND 3
void MIDORI64_set_known_prob_bound(PROB_t * B)
{
	// 0Round :nothing
	B[0] = (PROB_t)0;
	// 1Round : 2^{- 2.0000} Best
	B[1] = (PROB_t)-2;
	// 2Round : 2^{- 8.0000} Best
	B[2] = (PROB_t)-8;
	// 3Round : 2^{- 14.0000} Best
	B[3] = (PROB_t)-14;
};

#define MIDORI64_LC_KNOWN_BEST_ROUND 3
void MIDORI64_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
	// 1 Round :  -2^{-1.0000} Best
	B[1].sign = POSI; B[1].magnitude = (ABS_CORR_t)-1;
	// 2 Round :  -2^{-4.0000} Best
	B[2].sign = POSI; B[2].magnitude = (ABS_CORR_t)-4;
	// 3 Round :  -2^{-7.0000} Best
	B[3].sign = NEGA; B[3].magnitude = (ABS_CORR_t)-7;
};


#define MIDORI64_NUM_ROUND 16
PROB_t MIDORI64_each_round_initial_prob_bound[MIDORI64_NUM_ROUND + 1] =
{				  
				  //each minimum number of active sboxes is followed by the analysis in "[2015 ASIACRYPT] Midori A Block Cipher for Low Energy"
	(PROB_t)0,    //0-round
	(PROB_t)-3,   //From minimum number of active sboxes of  1-round differential trail
	(PROB_t)-9,   //From minimum number of active sboxes of  2-round differential trail
	(PROB_t)-21,  //From minimum number of active sboxes of  3-round differential trail
	(PROB_t)-48,  //From minimum number of active sboxes of  4-round differential trail
	(PROB_t)-69,  //From minimum number of active sboxes of  5-round differential trail
	(PROB_t)-90,  //From minimum number of active sboxes of  6-round differential trail
	(PROB_t)-105, //From minimum number of active sboxes of  7-round differential trail
	(PROB_t)-114, //From minimum number of active sboxes of  8-round differential trail
	(PROB_t)-123, //From minimum number of active sboxes of  9-round differential trail
	(PROB_t)-150, //From minimum number of active sboxes of 10-round differential trail
	(PROB_t)-171, //From minimum number of active sboxes of 11-round differential trail
	(PROB_t)-186, //From minimum number of active sboxes of 12-round differential trail
	(PROB_t)-201, //From minimum number of active sboxes of 13-round differential trail
	(PROB_t)-216, //From minimum number of active sboxes of 14-round differential trail
	(PROB_t)-225, //From minimum number of active sboxes of 15-round differential trail
	(PROB_t)-252, //From minimum number of active sboxes of 16-round differential trail
};
CORR_t MIDORI64_each_round_initial_corr_bound[MIDORI64_NUM_ROUND + 1] =
{
								//each minimum number of active sboxes is followed by the analysis in "[2015 ASIACRYPT] Midori A Block Cipher for Low Energy"
	{POSI, (ABS_CORR_t)0},		//0-round
	{POSI, (ABS_CORR_t)-2},		//From minimum number of active sboxes of  1-round linear trail
	{POSI, (ABS_CORR_t)-6},		//From minimum number of active sboxes of  2-round linear trail
	{POSI, (ABS_CORR_t)-14},	//From minimum number of active sboxes of  3-round linear trail
	{POSI, (ABS_CORR_t)-32},	//From minimum number of active sboxes of  4-round linear trail
	{POSI, (ABS_CORR_t)-46},	//From minimum number of active sboxes of  5-round linear trail
	{POSI, (ABS_CORR_t)-60},	//From minimum number of active sboxes of  6-round linear trail
	{POSI, (ABS_CORR_t)-70},	//From minimum number of active sboxes of  7-round linear trail
	{POSI, (ABS_CORR_t)-76},	//From minimum number of active sboxes of  8-round linear trail
	{POSI, (ABS_CORR_t)-82},	//From minimum number of active sboxes of  9-round linear trail
	{POSI, (ABS_CORR_t)-100},	//From minimum number of active sboxes of 10-round linear trail
	{POSI, (ABS_CORR_t)-114},	//From minimum number of active sboxes of 11-round linear trail
	{POSI, (ABS_CORR_t)-124},	//From minimum number of active sboxes of 12-round linear trail
	{POSI, (ABS_CORR_t)-134},	//From minimum number of active sboxes of 13-round linear trail
	{POSI, (ABS_CORR_t)-144},	//From minimum number of active sboxes of 14-round linear trail
	{POSI, (ABS_CORR_t)-150},	//From minimum number of active sboxes of 15-round linear trail
	{POSI, (ABS_CORR_t)-168},	//From minimum number of active sboxes of 16-round linear trail
};

SEARCHING_START_OPT_t MIDORI64_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t MIDORI64_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	MIDORI64_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-3,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	MIDORI64_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2}
};

DIFFUSION_BOUND_OPT_t MIDORI64_diffusion_bound_opt =
{
	/*num_diff_of_partial_diffusion*/
	4,
	/*diff_branch_num*/
	4,
	/*inv_trans_diff_branch_num*/
	4,
};

BLK_CIPHER_INFO_t MIDORI64 =
{
	/*general information*/
	//algname
	"MIDORI64",
	//alg_structure
	SPN,
	//num_round
	MIDORI64_NUM_ROUND,
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
	MIDORI64_sboxes,

	/*about diffusion*/
	//diffusion_info [what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))]
	PARTIAL_BINARY_MATRIX,
	/*diff_i_word_bit_size*/
	4,
	/*diff_o_word_bit_size*/
	4,
	//diffusion functions
	//Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	MIDORI64_diffusion,
	//Inv_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	MIDORI64_inv_diffusion,
	//Inv_Trans_Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	MIDORI64_diffusion,
	//Trans_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	MIDORI64_inv_diffusion,

	/*about bound info*/
	//dc_known_best_round
	MIDORI64_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	MIDORI64_set_known_prob_bound,
	//lc_known_best_round
	MIDORI64_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	MIDORI64_set_known_corr_bound,
	/*start searching opt ptr*/
	&MIDORI64_searching_start_opt,
	&MIDORI64_set_initial_bound_opt,
	&MIDORI64_diffusion_bound_opt
};


void PY_MIDORI64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_DC(&MIDORI64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_MIDORI64(&MIDORI64);
#else
	Use_Predefined_1Round_Active_Maps(&MIDORI64);
#endif
	SPN_Best_DC_Prob_Search(rst, &MIDORI64, 0, num_round, verbose);
}

void PY_MIDORI64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_LC(&MIDORI64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_MIDORI64(&MIDORI64);
#else
	Use_Predefined_1Round_Active_Maps(&MIDORI64);
#endif
	SPN_Best_LC_Corr_Search(rst, &MIDORI64, 0, num_round, verbose);
}