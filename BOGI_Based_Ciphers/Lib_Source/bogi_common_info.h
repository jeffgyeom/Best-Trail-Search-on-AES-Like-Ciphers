#ifndef _BOGI_COMMON_INFO_H_
#define _BOGI_COMMON_INFO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "astbb.h"

/*
VARIABLES
*/
extern CHAR_t	   ALG_NAME[256];
extern CNT_t	   SIDX, PIDX;
extern SBOX_t	   SBOX[16];
extern uint32_t    PMIX_LOOKUP[4][16];
extern FLAG_t	   PERM_TYPE;


/*
CONSTANTS
*/


#define SBOX_BIT_SIZE					4
#define NUM_SBOX_ENTRIES				16
#define SBOX_CARDINALITY				NUM_SBOX_ENTRIES
#define SBOX_I_CARDINALITY				SBOX_CARDINALITY
#define SBOX_O_CARDINALITY				SBOX_CARDINALITY
#define SBOX_IO_CARDINALITY				(SBOX_I_CARDINALITY*SBOX_O_CARDINALITY)
#define NUM_DIFF_OF_PARTIAL_DIFFUSION	4
#define NUM_PARTION_OF_DIFF_IN_A_STATE	(NUM_SBOX_IN_A_STATE/NUM_DIFF_OF_PARTIAL_DIFFUSION)
#define BLOCK_BIT_SIZE					(SBOX_BIT_SIZE * NUM_SBOX_IN_A_STATE)

#define PMIX(outptr, sloc, in) *((uint32_t*)outptr) ^= PMIX_LOOKUP[(sloc)][(in)];

#if defined BOGI_CIPHER_16
static DEV_INLINE void PSHUF(SBOX_t out[NUM_SBOX_IN_A_STATE], SBOX_t in[NUM_SBOX_IN_A_STATE])
{
	out[0] = in[0]; out[1] = in[1]; out[2] = in[2]; out[3] = in[3];
}
#elif defined BOGI_CIPHER_32
static DEV_INLINE void PSHUF(SBOX_t out[NUM_SBOX_IN_A_STATE], SBOX_t in[NUM_SBOX_IN_A_STATE])
{
	out[0] = in[0]; out[2] = in[1]; out[4] = in[2]; out[6] = in[3];
	out[1] = in[4]; out[3] = in[5]; out[5] = in[6]; out[7] = in[7];
}
#elif defined BOGI_CIPHER_64
static DEV_INLINE void PSHUF(SBOX_t out[NUM_SBOX_IN_A_STATE], SBOX_t in[NUM_SBOX_IN_A_STATE])
{
	out[0]  = in[0];  out[4]  = in[1];  out[8]  = in[2];  out[12] = in[3];
	out[1]  = in[4];  out[5]  = in[5];  out[9]  = in[6];  out[13] = in[7];
	out[2]  = in[8];  out[6]  = in[9];  out[10] = in[10]; out[14] = in[11];
	out[3]  = in[12]; out[7]  = in[13]; out[11] = in[14]; out[15] = in[15];
}
#elif defined BOGI_CIPHER_128
static DEV_INLINE void PSHUF(SBOX_t out[NUM_SBOX_IN_A_STATE], SBOX_t in[NUM_SBOX_IN_A_STATE])
{
	out[0]  = in[0];  out[8]  = in[1];  out[16] = in[2];  out[24] = in[3];
	out[1]  = in[4];  out[9]  = in[5];  out[17] = in[6];  out[25] = in[7];
	out[2]  = in[8];  out[10] = in[9];  out[18] = in[10]; out[26] = in[11];
	out[3]  = in[12]; out[11] = in[13]; out[19] = in[14]; out[27] = in[15];
	out[4]  = in[16]; out[12] = in[17]; out[20] = in[18]; out[28] = in[19];
	out[5]  = in[20]; out[13] = in[21]; out[21] = in[22]; out[29] = in[23];
	out[6]  = in[24]; out[14] = in[25]; out[22] = in[26]; out[30] = in[27];
	out[7]  = in[28]; out[15] = in[29]; out[23] = in[30]; out[31] = in[31];
}
#elif defined BOGI_CIPHER_176
static DEV_INLINE void PSHUF(SBOX_t out[NUM_SBOX_IN_A_STATE], SBOX_t in[NUM_SBOX_IN_A_STATE])
{
	out[0]  = in[0];  out[11] = in[1];  out[22] = in[2];  out[33] = in[3];
	out[1]  = in[4];  out[12] = in[5];  out[23] = in[6];  out[34] = in[7];
	out[2]  = in[8];  out[13] = in[9];  out[24] = in[10]; out[35] = in[11];
	out[3]  = in[12]; out[14] = in[13]; out[25] = in[14]; out[36] = in[15];
	out[4]  = in[16]; out[15] = in[17]; out[26] = in[18]; out[37] = in[19];
	out[5]  = in[20]; out[16] = in[21]; out[27] = in[22]; out[38] = in[23];
	out[6]  = in[24]; out[17] = in[25]; out[28] = in[26]; out[39] = in[27];
	out[7]  = in[28]; out[18] = in[29]; out[29] = in[30]; out[40] = in[31];
	out[8]  = in[32]; out[19] = in[33]; out[30] = in[34]; out[41] = in[35];
	out[9]  = in[36]; out[20] = in[37]; out[31] = in[38]; out[42] = in[39];
	out[10] = in[40]; out[21] = in[41]; out[32] = in[42]; out[43] = in[43];
}
#elif defined BOGI_CIPHER_256
static DEV_INLINE void PSHUF(SBOX_t out[NUM_SBOX_IN_A_STATE], SBOX_t in[NUM_SBOX_IN_A_STATE])
{
	out[0]  = in[0];  out[16] = in[1];  out[32] = in[2];  out[48] = in[3];  
	out[1]  = in[4];  out[17] = in[5];  out[33] = in[6];  out[49] = in[7];  
	out[2]  = in[8];  out[18] = in[9];  out[34] = in[10]; out[50] = in[11]; 
	out[3]  = in[12]; out[19] = in[13]; out[35] = in[14]; out[51] = in[15]; 
	out[4]  = in[16]; out[20] = in[17]; out[36] = in[18]; out[52] = in[19]; 
	out[5]  = in[20]; out[21] = in[21]; out[37] = in[22]; out[53] = in[23]; 
	out[6]  = in[24]; out[22] = in[25]; out[38] = in[26]; out[54] = in[27]; 
	out[7]  = in[28]; out[23] = in[29]; out[39] = in[30]; out[55] = in[31]; 
	out[8]  = in[32]; out[24] = in[33]; out[40] = in[34]; out[56] = in[35]; 
	out[9]  = in[36]; out[25] = in[37]; out[41] = in[38]; out[57] = in[39]; 
	out[10] = in[40]; out[26] = in[41]; out[42] = in[42]; out[58] = in[43]; 
	out[11] = in[44]; out[27] = in[45]; out[43] = in[46]; out[59] = in[47]; 
	out[12] = in[48]; out[28] = in[49]; out[44] = in[50]; out[60] = in[51]; 
	out[13] = in[52]; out[29] = in[53]; out[45] = in[54]; out[61] = in[55]; 
	out[14] = in[56]; out[30] = in[57]; out[46] = in[58]; out[62] = in[59]; 
	out[15] = in[60]; out[31] = in[61]; out[47] = in[62]; out[63] = in[63]; 
}
#endif


extern SBOX_t BOGI_applicable_sboxes[1728][16];
extern uint32_t BOGI_pmixes_lookup[576][4][16];

//There are 5 types of round commuting word-wise permutation sets.
// BOGI16_0 : 1 : [W00]
// BOGI16_1 : 4 : [W00, W01, W05, W09]
// BOGI16_2 : 4 : [W00, W01, W06, W08] 
// BOGI16_3 : 4 : [W00, W02, W05, W07]
// BOGI16_4 : 4 : [W00, W03, W04, W09]
enum bogi16_commuting_types { BOGI16_0 = 0, BOGI16_1, BOGI16_2, BOGI16_3, BOGI16_4 };
static char bogi16_commuting_types_strs[5][16] = { "BOGI16_0", "BOGI16_1", "BOGI16_2", "BOGI16_3", "BOGI16_4" };

//There are 5 types of round commuting word-wise permutation sets.
// BOGI32_0 : 1 : [W00]
// BOGI32_1 : 2 : [W00, W0D]
// BOGI32_2 : 4 : [W00, W01, W06, W08]
// BOGI32_3 : 8 : [W00, W01, W03, W05, W06, W08, W0B, W0D]
// BOGI32_4 : 8 : [W00, W02, W03, W04, W07, W09, W0A, W0C]
enum bogi32_commuting_types { BOGI32_0 = 0, BOGI32_1, BOGI32_2, BOGI32_3, BOGI32_4 };
static char bogi32_commuting_types_strs[5][16] = { "BOGI32_0", "BOGI32_1", "BOGI32_2", "BOGI32_3", "BOGI32_4" };

//There are 5 types of round commuting word-wise permutation sets.
// BOGI64_0 : 1 : [W00]
// BOGI64_1 : 16: [W00, W01, W05, W09, W0A, W0D, W11, W16, W19, W1B, W20, W25, W28, W2A, W2F, W33]
// BOGI64_2 : 16: [W00, W01, W06, W08, W0A, W0D, W13, W15, W1A, W1C, W21, W23, W27, W29, W30, W32]
// BOGI64_3 : 16: [W00, W02, W05, W07, W0B, W0E, W12, W14, W19, W1D, W20, W22, W26, W2B, W2E, W31]
// BOGI64_4 : 16: [W00, W03, W04, W09, W0C, W0F, W10, W17, W18, W1E, W1F, W24, W28, W2C, W2D, W33]
enum bogi64_commuting_types { BOGI64_0 = 0, BOGI64_1, BOGI64_2, BOGI64_3, BOGI64_4 };
static char bogi64_commuting_types_strs[5][16] = { "BOGI64_0", "BOGI64_1", "BOGI64_2", "BOGI64_3", "BOGI64_4" };

//There are 5 types of round commuting word-wise permutation sets.
// BOGI128_0 : 1 : [W00]
// BOGI128_1 : 2 : [W00, W1F]
// BOGI128_2 : 4 : [W00, W02, W08, W0A]
// BOGI128_3 : 8 : [W00, W01, W04, W05, W10, W11, W14, W15]
// BOGI128_4 : 32: [W00, W01, W02, W03, W04, W05, W06, W07, W08, W09, W0A, W0B, W0C, W0D, W0E, W0F, 
//                  W10, W11, W12, W13, W14, W15, W16, W17, W18, W19, W1A, W1B, W1C, W1D, W1E, W1F]
enum bogi128_commuting_types { BOGI128_0 = 0, BOGI128_1, BOGI128_2, BOGI128_3, BOGI128_4 };
static char bogi128_commuting_types_strs[5][16] = { "BOGI128_0", "BOGI128_1", "BOGI128_2", "BOGI128_3", "BOGI128_4" };

//There are 2 types of round commuting word-wise permutation sets.
// BOGI176_0 : 1 : [W00]
// BOGI176_1 : 2 : [W00, W01]
enum bogi176_commuting_types { BOGI176_0 = 0, BOGI176_1 };
static char bogi176_commuting_types_strs[2][16] = { "BOGI176_0", "BOGI176_1" };

//There are 2 types of round commuting word-wise permutation sets.
// BOGI256_0 : 1 : [W00]
// BOGI256_1 : 64: [W00, W01, W05, W09, W0A, W0D, W11, W16, W19, W1B, W20, W25, W28, W2A, W2F, W33, W34, W37, W3B, W40, W42, W45, W49, W4E, W51, W54, W59, W5F, W62, W65, W6A, W6E, W71, W73, W78, W7D, W7E, W82, W87, W8C, W8F, W91, W96, W9B, W9F, WA1, WA6, WAB, WAE, WB0, WB5, WB9, WBB, WBF, WC3, WC8, WCC, WCE, WD4, WD9, WDC, WDE, WE3, WE7, ]
// BOGI256_2 : 64: [W00, W01, W06, W08, W0A, W0D, W13, W15, W1A, W1C, W21, W23, W27, W29, W30, W32, W34, W37, W3D, W3F, W42, W45, W4B, W4D, W53, W55, W5B, W5D, W61, W64, W6B, W6D, W72, W74, W79, W7B, W7F, W83, W89, W8B, W90, W92, W97, W99, W9D, WA0, WA7, WA9, WAD, WAF, WB6, WB8, WBA, WBE, WC5, WC7, WCD, WCF, WD5, WD7, WDB, WDD, WE4, WE6, ]
// BOGI256_3 : 64: [W00, W02, W05, W07, W0B, W0E, W12, W14, W19, W1D, W20, W22, W26, W2B, W2E, W31, W35, W38, W3C, W3E, W43, W46, W4A, W4C, W52, W56, W5A, W5C, W60, W66, W69, W6C, W71, W75, W78, W7A, W80, W84, W88, W8A, W8F, W93, W96, W98, W9C, WA2, WA5, WA8, WAC, WB1, WB4, WB7, WBC, WC0, WC4, WC6, WCB, WD0, WD3, WD6, WDA, WDF, WE2, WE5, ]
// BOGI256_4 : 64: [W00, W03, W04, W09, W0C, W0F, W10, W17, W18, W1E, W1F, W24, W28, W2C, W2D, W33, W36, W39, W3A, W41, W44, W47, W48, W4F, W50, W57, W58, W5E, W63, W67, W68, W6F, W70, W76, W77, W7C, W81, W85, W86, W8D, W8E, W94, W95, W9A, W9E, WA3, WA4, WAA, WAE, WB2, WB3, WB9, WBD, WC1, WC2, WC9, WCA, WD1, WD2, WD8, WDC, WE0, WE1, WE7, ]
enum bogi256_commuting_types { BOGI256_0 = 0, BOGI256_1, BOGI256_2, BOGI256_3, BOGI256_4 };
static char bogi256_commuting_types_strs[5][16] = { "BOGI256_0", "BOGI256_1", "BOGI256_2", "BOGI256_3", "BOGI256_4" };





#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_BOGI_COMMON_INFO_H_*/