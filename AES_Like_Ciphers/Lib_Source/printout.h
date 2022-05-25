#ifndef _PRINTOUR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"

//Verbose Check option
FLAG_t Verbose_Check(UFLAG_t in_flag, UFLAG_t check_flag);

void Print_DC_Trail(DC_1ROUND_CHAR_t * dc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state);
void FPrint_DC_Trail(char* filename, DC_1ROUND_CHAR_t * dc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state);
void Print_LC_Trail(LC_1ROUND_CHAR_t * lc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state);
void FPrint_LC_Trail(char* filename, LC_1ROUND_CHAR_t * lc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state);
void Copy_DC_Trail(DC_1ROUND_CHAR_t * dst_trail, DC_1ROUND_CHAR_t * src_trail, CNT_t round, NUM_t num_word_in_a_state);
void Copy_LC_Trail(LC_1ROUND_CHAR_t * dst_trail, LC_1ROUND_CHAR_t * src_trail, CNT_t round, NUM_t num_word_in_a_state);


#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif/*_PRINTOUR_H_*/