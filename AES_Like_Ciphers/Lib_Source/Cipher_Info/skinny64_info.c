#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"

SBOX_O_WRD_t SKINNY64_sboxes[16 * 16] =
{
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,

	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,

	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,

	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf,
	0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf
};


void SKINNY64_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//Mix Columns
	temp[ 0] = in[ 0] ^ in[ 2] ^ in[ 3];
	temp[ 4] = in[ 4] ^ in[ 6] ^ in[ 7];
	temp[ 8] = in[ 8] ^ in[10] ^ in[11];
	temp[12] = in[12] ^ in[14] ^ in[15];

	temp[ 1] = in[ 0];
	temp[ 5] = in[ 4];
	temp[ 9] = in[ 8];
	temp[13] = in[12];

	temp[ 2] = in[ 1] ^ in[ 2];
	temp[ 6] = in[ 5] ^ in[ 6];
	temp[10] = in[ 9] ^ in[10];
	temp[14] = in[13] ^ in[14];

	temp[ 3] = in[ 0] ^ in[ 2];
	temp[ 7] = in[ 4] ^ in[ 6];
	temp[11] = in[ 8] ^ in[10];
	temp[15] = in[12] ^ in[14];

	//ShiftRows
	out[ 0] = temp[ 0];
	out[ 1] = temp[13];
	out[ 2] = temp[10];
	out[ 3] = temp[ 7];

	out[ 4] = temp[ 4];
	out[ 5] = temp[ 1];
	out[ 6] = temp[14];
	out[ 7] = temp[11];

	out[ 8] = temp[ 8];
	out[ 9] = temp[ 5];
	out[10] = temp[ 2];
	out[11] = temp[15];

	out[12] = temp[12];
	out[13] = temp[ 9];
	out[14] = temp[ 6];
	out[15] = temp[ 3];
}


void SKINNY64_inv_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//Inverse ShiftRows
	temp[ 0] = in[ 0];
	temp[ 1] = in[ 5];
	temp[ 2] = in[10];
	temp[ 3] = in[15];

	temp[ 4] = in[ 4];
	temp[ 5] = in[ 9];
	temp[ 6] = in[14];
	temp[ 7] = in[ 3];

	temp[ 8] = in[ 8];
	temp[ 9] = in[13];
	temp[10] = in[ 2];
	temp[11] = in[ 7];

	temp[12] = in[12];
	temp[13] = in[ 1];
	temp[14] = in[ 6];
	temp[15] = in[11];


	//Inverse Mix Column
	out[ 0] = temp[ 1];
	out[ 4] = temp[ 5];
	out[ 8] = temp[ 9];
	out[12] = temp[13];
		    
	out[ 1] = temp[ 1] ^ temp[ 2] ^ temp[ 3];
	out[ 5] = temp[ 5] ^ temp[ 6] ^ temp[ 7];
	out[ 9] = temp[ 9] ^ temp[10] ^ temp[11];
	out[13] = temp[13] ^ temp[14] ^ temp[15];
		    
	out[ 2] = temp[ 1] ^ temp[ 3];
	out[ 6] = temp[ 5] ^ temp[ 7];
	out[10] = temp[ 9] ^ temp[11];
	out[14] = temp[13] ^ temp[15];

	out[ 3] = temp[ 0] ^ temp[ 3];
	out[ 7] = temp[ 4] ^ temp[ 7];
	out[11] = temp[ 8] ^ temp[11];
	out[15] = temp[12] ^ temp[15];
}

void SKINNY64_inv_trans_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//Inverse(Transpose(Mix Columns))
	temp[ 0] = in[ 3];
	temp[ 4] = in[ 7];
	temp[ 8] = in[11];
	temp[12] = in[15];

	temp[ 1] = in[ 0] ^ in[ 1] ^ in[ 2];
	temp[ 5] = in[ 4] ^ in[ 5] ^ in[ 6];
	temp[ 9] = in[ 8] ^ in[ 9] ^ in[10];
	temp[13] = in[12] ^ in[13] ^ in[14];

	temp[ 2] = in[ 1];
	temp[ 6] = in[ 5];
	temp[10] = in[ 9];
	temp[14] = in[13];

	temp[ 3] = in[ 1] ^ in[ 2] ^ in[ 3];
	temp[ 7] = in[ 5] ^ in[ 6] ^ in[ 7];
	temp[11] = in[ 9] ^ in[10] ^ in[11];
	temp[15] = in[13] ^ in[14] ^ in[15];

	//ShiftRows
	out[ 0] = temp[ 0];
	out[ 1] = temp[13];
	out[ 2] = temp[10];
	out[ 3] = temp[ 7];

	out[ 4] = temp[ 4];
	out[ 5] = temp[ 1];
	out[ 6] = temp[14];
	out[ 7] = temp[11];

	out[ 8] = temp[ 8];
	out[ 9] = temp[ 5];
	out[10] = temp[ 2];
	out[11] = temp[15];

	out[12] = temp[12];
	out[13] = temp[ 9];
	out[14] = temp[ 6];
	out[15] = temp[ 3];
}

void SKINNY64_trans_diffusion(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	DIFF_I_WRD_t temp[16];

	//Inverse ShiftRows
	temp[ 0] = in[ 0];
	temp[ 1] = in[ 5];
	temp[ 2] = in[10];
	temp[ 3] = in[15];

	temp[ 4] = in[ 4];
	temp[ 5] = in[ 9];
	temp[ 6] = in[14];
	temp[ 7] = in[ 3];

	temp[ 8] = in[ 8];
	temp[ 9] = in[13];
	temp[10] = in[ 2];
	temp[11] = in[ 7];

	temp[12] = in[12];
	temp[13] = in[ 1];
	temp[14] = in[ 6];
	temp[15] = in[11];


	//Transpose(Mix Columns)
	out[ 0] = temp[ 0] ^ temp[ 1] ^ temp[ 3];
	out[ 4] = temp[ 4] ^ temp[ 5] ^ temp[ 7];
	out[ 8] = temp[ 8] ^ temp[ 9] ^ temp[11];
	out[12] = temp[12] ^ temp[13] ^ temp[15];
		    
	out[ 1] = temp[ 2];
	out[ 5] = temp[ 6];
	out[ 9] = temp[10];
	out[13] = temp[14];
		    
	out[ 2] = temp[ 0] ^ temp[ 2] ^ temp[ 3];
	out[ 6] = temp[ 4] ^ temp[ 5] ^ temp[ 7];
	out[10] = temp[ 8] ^ temp[ 9] ^ temp[11];
	out[14] = temp[12] ^ temp[14] ^ temp[15];

	out[ 3] = temp[ 0];
	out[ 7] = temp[ 4];
	out[11] = temp[ 8];
	out[15] = temp[12];
}


#define SKINNY64_DC_KNOWN_BEST_ROUND 0

void SKINNY64_set_known_prob_bound(PROB_t * B)
{
	// 0Round :nothing
	B[0] = (PROB_t)0;
};

#define SKINNY64_LC_KNOWN_BEST_ROUND 0
void SKINNY64_set_known_corr_bound(CORR_t * B)
{
	// 0 Round :  nothing
	B[0].sign = POSI; B[0].magnitude = (ABS_CORR_t)0;
};


#define SKINNY64_NUM_ROUND 36
PROB_t SKINNY64_each_round_initial_prob_bound[SKINNY64_NUM_ROUND + 1] =
{
				  //each minimum number of active sboxes is followed by the analysis in "The SKINNY Family of Block Ciphers and Its Low - Latency Variant MANTIS crypto 2016"
	(PROB_t)0,	  //0-round
	(PROB_t)-3,   //From minimum number of active sboxes of  1-round differential trail
	(PROB_t)-6,   //From minimum number of active sboxes of  2-round differential trail
	(PROB_t)-15,  //From minimum number of active sboxes of  3-round differential trail
	(PROB_t)-24,  //From minimum number of active sboxes of  4-round differential trail
	(PROB_t)-36,  //From minimum number of active sboxes of  5-round differential trail
	(PROB_t)-48,  //From minimum number of active sboxes of  6-round differential trail
	(PROB_t)-78,  //From minimum number of active sboxes of  7-round differential trail 
	(PROB_t)-108, //From minimum number of active sboxes of  8-round differential trail 
	(PROB_t)-123, //From minimum number of active sboxes of  9-round differential trail 
	(PROB_t)-138, //From minimum number of active sboxes of 10-round differential trail 
	(PROB_t)-153, //From minimum number of active sboxes of 11-round differential trail 
	(PROB_t)-165, //From minimum number of active sboxes of 12-round differential trail 
	(PROB_t)-174, //From minimum number of active sboxes of 13-round differential trail 
	(PROB_t)-183, //From minimum number of active sboxes of 14-round differential trail 
	(PROB_t)-198, //From minimum number of active sboxes of 15-round differential trail 
	(PROB_t)-225, //From minimum number of active sboxes of 16-round differential trail
	(PROB_t)-246, //From minimum number of active sboxes of 17-round differential trail 
	(PROB_t)-264, //From minimum number of active sboxes of 18-round differential trail 
	(PROB_t)-276, //From minimum number of active sboxes of 19-round differential trail 
	(PROB_t)-288, //From minimum number of active sboxes of 20-round differential trail 
	(PROB_t)-306, //From minimum number of active sboxes of 21-round differential trail 
	(PROB_t)-324, //From minimum number of active sboxes of 22-round differential trail
	(PROB_t)-342, //From minimum number of active sboxes of 23-round differential trail
	(PROB_t)-348, //From minimum number of active sboxes of 24-round differential trail
	(PROB_t)-372, //From minimum number of active sboxes of 25-round differential trail
	(PROB_t)-396, //From minimum number of active sboxes of 26-round differential trail
	(PROB_t)-414, //From minimum number of active sboxes of 27-round differential trail
	(PROB_t)-408, //From minimum number of active sboxes of 28-round differential trail
	(PROB_t)-444, //From minimum number of active sboxes of 29-round differential trail
	(PROB_t)-474, //From minimum number of active sboxes of 30-round differential trail
};
CORR_t SKINNY64_each_round_initial_corr_bound[SKINNY64_NUM_ROUND + 1] =
{
							  //each minimum number of active sboxes is followed by the analysis in "The SKINNY Family of Block Ciphers and Its Low - Latency Variant MANTIS crypto 2016"
	{POSI, (ABS_CORR_t)0},    //0-round
	{POSI, (ABS_CORR_t)-2},   //From minimum number of active sboxes of  1-round linear trail
	{POSI, (ABS_CORR_t)-4},	  //From minimum number of active sboxes of  2-round linear trail
	{POSI, (ABS_CORR_t)-10},  //From minimum number of active sboxes of  3-round linear trail
	{POSI, (ABS_CORR_t)-16},  //From minimum number of active sboxes of  4-round linear trail
	{POSI, (ABS_CORR_t)-26},  //From minimum number of active sboxes of  5-round linear trail
	{POSI, (ABS_CORR_t)-38},  //From minimum number of active sboxes of  6-round linear trail
	{POSI, (ABS_CORR_t)-50},  //From minimum number of active sboxes of  7-round linear trail
	{POSI, (ABS_CORR_t)-64},  //From minimum number of active sboxes of  8-round linear trail
	{POSI, (ABS_CORR_t)-76},  //From minimum number of active sboxes of  9-round linear trail
	{POSI, (ABS_CORR_t)-86},  //From minimum number of active sboxes of 10-round linear trail
	{POSI, (ABS_CORR_t)-96},  //From minimum number of active sboxes of 11-round linear trail
	{POSI, (ABS_CORR_t)-104}, //From minimum number of active sboxes of 12-round linear trail
	{POSI, (ABS_CORR_t)-110}, //From minimum number of active sboxes of 13-round linear trail
	{POSI, (ABS_CORR_t)-116}, //From minimum number of active sboxes of 14-round linear trail
	{POSI, (ABS_CORR_t)-128}, //From minimum number of active sboxes of 15-round linear trail
	{POSI, (ABS_CORR_t)-140}, //From minimum number of active sboxes of 16-round linear trail
	{POSI, (ABS_CORR_t)-152}, //From minimum number of active sboxes of 17-round linear trail
	{POSI, (ABS_CORR_t)-160}, //From minimum number of active sboxes of 18-round linear trail
	{POSI, (ABS_CORR_t)-170}, //From minimum number of active sboxes of 19-round linear trail
	{POSI, (ABS_CORR_t)-180}, //From minimum number of active sboxes of 20-round linear trail
	{POSI, (ABS_CORR_t)-192}, //From minimum number of active sboxes of 21-round linear trail
	{POSI, (ABS_CORR_t)-204}, //From minimum number of active sboxes of 22-round linear trail
	{POSI, (ABS_CORR_t)-214}, //From minimum number of active sboxes of 23-round linear trail
	{POSI, (ABS_CORR_t)-220}, //From minimum number of active sboxes of 24-round linear trail
	{POSI, (ABS_CORR_t)-236}, //From minimum number of active sboxes of 25-round linear trail
	{POSI, (ABS_CORR_t)-244}, //From minimum number of active sboxes of 26-round linear trail
	{POSI, (ABS_CORR_t)-256}, //From minimum number of active sboxes of 27-round linear trail
	{POSI, (ABS_CORR_t)-272}, //From minimum number of active sboxes of 28-round linear trail
	{POSI, (ABS_CORR_t)-282}, //From minimum number of active sboxes of 29-round linear trail
	{POSI, (ABS_CORR_t)-286}, //From minimum number of active sboxes of 30-round linear trail
};

SEARCHING_START_OPT_t SKINNY64_searching_start_opt =
{
	/*enable_1round_active_map*/
	TRUE,
	/*rotational_symmetric_equivalent*/
	FALSE,
};

SET_INITIAL_BOUND_OPT_t SKINNY64_set_initial_bound_opt =
{
	/*enable_set_initial_prob_bound*/
	FALSE,
	/*each_round_initial_prob_bound*/
	SKINNY64_each_round_initial_prob_bound,
	/*prob_interval*/
	(PROB_t)-3,
	/*enable_set_initial_corr_bound*/
	FALSE,
	/*each_round_initial_corr_bound*/
	SKINNY64_each_round_initial_corr_bound,
	/*corr_interval*/
	{POSI, (ABS_CORR_t)-2}
};

DIFFUSION_BOUND_OPT_t SKINNY64_diffusion_bound_opt =
{
	/*num_partial_diff_in_a_state*/
	4,
	/*inv_diff_branch_num*/
	2,
	/*inv_trans_diff_branch_num*/
	2,
};

BLK_CIPHER_INFO_t SKINNY64 =
{
	/*general information*/
	//algname
	"SKINNY64",
	//alg_structure
	SPN,
	//num_round
	SKINNY64_NUM_ROUND,
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
	SKINNY64_sboxes,

	/*about diffusion*/
	//diffusion_info [what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))]
	PARTIAL_BINARY_MATRIX,
	/*diff_i_word_bit_size*/
	4,
	/*diff_o_word_bit_size*/
	4,
	//diffusion functions
	//Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	SKINNY64_diffusion,
	//Inv_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	SKINNY64_inv_diffusion,
	//Inv_Trans_Diffusion(DIFF_O_WRD_t *, DIFF_I_WRD_t *)
	SKINNY64_diffusion,
	//Trans_Diffusion(DIFF_I_WRD_t *, DIFF_O_WRD_t *)
	SKINNY64_inv_diffusion,

	/*about bound info*/
	//dc_known_best_round
	SKINNY64_DC_KNOWN_BEST_ROUND,
	//Set_Known_Prob_Bound
	SKINNY64_set_known_prob_bound,
	//lc_known_best_round
	SKINNY64_LC_KNOWN_BEST_ROUND,
	//Set_Known_Corr_Bound
	SKINNY64_set_known_corr_bound,
	/*start searching opt ptr*/
	&SKINNY64_searching_start_opt,
	&SKINNY64_set_initial_bound_opt,
	&SKINNY64_diffusion_bound_opt
};


void PY_SKINNY64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_DC(&SKINNY64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_SKINNY64(&SKINNY64);
#else
	Use_Predefined_1Round_Active_Maps(&SKINNY64);
#endif
	SPN_Best_DC_Prob_Search(rst, &SKINNY64, 0, num_round, verbose);
}

void PY_SKINNY64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose)
{
	SPN_Prep_Info_For_LC(&SKINNY64);
#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_SKINNY64(&SKINNY64);
#else
	Use_Predefined_1Round_Active_Maps(&SKINNY64);
#endif
	SPN_Best_LC_Corr_Search(rst, &SKINNY64, 0, num_round, verbose);
}
