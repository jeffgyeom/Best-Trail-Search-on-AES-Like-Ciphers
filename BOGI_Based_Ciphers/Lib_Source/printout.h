#ifndef _PRINTOUR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"




void Copy_DC_Trail(DC_1ROUND_CHAR_t * dst_trail, DC_1ROUND_CHAR_t * src_trail, CNT_t round);
void Copy_LC_Trail(LC_1ROUND_CHAR_t * dst_trail, LC_1ROUND_CHAR_t * src_trail, CNT_t round);

void Print_DC_Trail(DC_1ROUND_CHAR_t * dc_trail, CNT_t round);
void Print_LC_Trail(LC_1ROUND_CHAR_t * lc_trail, CNT_t round);
void FPrint_LC_Trail(char* filename, LC_1ROUND_CHAR_t * lc_trail, CNT_t round);
void FPrint_DC_Trail(char* filename, DC_1ROUND_CHAR_t * dc_trail, CNT_t round);


#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif/*_PRINTOUR_H_*/