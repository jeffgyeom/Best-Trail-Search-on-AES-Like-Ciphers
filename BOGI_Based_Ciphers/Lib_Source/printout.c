#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"
#include "bogi_common_info.h"

void Print_Module_Status(void)
{
	printf("-- Compiled at %s %s\n", __TIME__, __DATE__);
	#if defined BOGI_CIPHER_16
	printf("-> BOGI_CIPHER_16 Module\n");
	#elif defined BOGI_CIPHER_32
	printf("-> BOGI_CIPHER_32 Module\n");
	#elif defined BOGI_CIPHER_64
	printf("-> BOGI_CIPHER_64 Module\n");
	#elif defined BOGI_CIPHER_128
	printf("-> BOGI_CIPHER_128 Module\n");
	#elif defined BOGI_CIPHER_176
	printf("-> BOGI_CIPHER_176 Module\n");
	#elif defined BOGI_CIPHER_256
	printf("-> BOGI_CIPHER_256 Module\n");
	#endif
#ifdef PRINT_PSHUF_INPUT
	printf("-> PRINT_PSHUF_INPUT\n");
#endif
#ifdef OUT_ELAPSED_TIME
	printf("-> OUT_ELAPSED_TIME\n");
#endif
#ifdef EMPLOY_PERM_CHAR
	printf("-> EMPLOY_PERM_CHAR\n");
#else
	printf("-> GENERAL_OPT_METHOD_FOR_ACTIVE_MAP\n");
#endif
}




void Copy_DC_Trail(DC_1ROUND_CHAR_t * dst_trail, DC_1ROUND_CHAR_t * src_trail, CNT_t round)
{
	CNT_t __FF__;

	for (__FF__ = 1; __FF__ < round; __FF__++)
	{
		memcpy(dst_trail[__FF__].sub_i, src_trail[__FF__].sub_i, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
		memcpy(dst_trail[__FF__].sub_o, src_trail[__FF__].sub_o, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
		memcpy(dst_trail[__FF__].psh_i, src_trail[__FF__].psh_i, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
		memcpy(dst_trail[__FF__].p    , src_trail[__FF__].p    , sizeof(PROB_t) * (size_t)NUM_SBOX_IN_A_STATE);
	}

	memcpy(dst_trail[round].sub_i, src_trail[round].sub_i, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
	memcpy(dst_trail[round].sub_o, src_trail[round].sub_o, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
	
	memset(dst_trail[round].psh_i, 0, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);

	for (__FF__ = 0; __FF__ < NUM_PARTION_OF_DIFF_IN_A_STATE; __FF__++)
	{
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 0, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 0)]);
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 1, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 1)]);
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 2, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 2)]);
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 3, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 3)]);
	}

	memcpy(dst_trail[round].p    , src_trail[round].p,     sizeof(PROB_t) * (size_t)NUM_SBOX_IN_A_STATE);
}

void Copy_LC_Trail(LC_1ROUND_CHAR_t * dst_trail, LC_1ROUND_CHAR_t * src_trail, CNT_t round)
{
	CNT_t __FF__;

	for (__FF__ = 1; __FF__ < round; __FF__++)
	{
		memcpy(dst_trail[__FF__].sub_i, src_trail[__FF__].sub_i, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
		memcpy(dst_trail[__FF__].sub_o, src_trail[__FF__].sub_o, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
		memcpy(dst_trail[__FF__].psh_i, src_trail[__FF__].psh_i, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
		memcpy(dst_trail[__FF__].c    , src_trail[__FF__].c    , sizeof(CORR_t) * (size_t)NUM_SBOX_IN_A_STATE);
	}

	memcpy(dst_trail[round].sub_i, src_trail[round].sub_i, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
	memcpy(dst_trail[round].sub_o, src_trail[round].sub_o, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);

	memset(dst_trail[round].psh_i, 0, sizeof(SBOX_t) * (size_t)NUM_SBOX_IN_A_STATE);
	
	for (__FF__ = 0; __FF__ < NUM_PARTION_OF_DIFF_IN_A_STATE; __FF__++)
	{
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 0, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 0)]);
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 1, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 1)]);
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 2, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 2)]);
		PMIX(&(dst_trail[round].psh_i[__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION]), 3, src_trail[round].sub_o[(__FF__ * NUM_DIFF_OF_PARTIAL_DIFFUSION + 3)]);
	}

	memcpy(dst_trail[round].c    , src_trail[round].c    , sizeof(CORR_t) * (size_t)NUM_SBOX_IN_A_STATE);
}


void Print_DC_Trail(DC_1ROUND_CHAR_t * dc_trail, CNT_t round)
{
	CNT_t __FF__;
	CNT_t word_idx;
	CNT_t idx = 0;
	SBOX_t round_out[NUM_SBOX_IN_A_STATE];

	printf("[%2d] Round Differential Trail\n", round);
	printf("========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		printf("R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", dc_trail[__FF__].sub_i[word_idx]);
		}
		printf("\n");
		printf("R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", dc_trail[__FF__].sub_o[word_idx]);
		}
		printf("\n");
		#ifdef PRINT_PSHUF_INPUT
		printf("R %2d: PSHUFIN  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", dc_trail[__FF__].psh_i[word_idx]);
		}
		printf("\n");
		#endif
		PSHUF(round_out, dc_trail[__FF__].psh_i);
		printf("R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", round_out[word_idx]);
		}
		printf("\n");
		{
			PROB_t sum;
			Mul_Probs(&sum, dc_trail[__FF__].p, NUM_SBOX_IN_A_STATE);
			printf("R %2d: PROB     | 2^{%0.4lf}\n", __FF__, sum);
		}
		printf("========================\n");
	}
}

void FPrint_DC_Trail(char* filename, DC_1ROUND_CHAR_t * dc_trail, CNT_t round)
{
	CNT_t __FF__;
	CNT_t word_idx;
	CNT_t idx = 0;
	SBOX_t round_out[NUM_SBOX_IN_A_STATE];

	FILE * fileptr = fopen(filename, "w");

	fprintf(fileptr, "[%2d] Round Differential Trail\n", round);
	fprintf(fileptr, "========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		fprintf(fileptr, "R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", dc_trail[__FF__].sub_i[word_idx]);
		}
		fprintf(fileptr, "\n");
		fprintf(fileptr, "R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", dc_trail[__FF__].sub_o[word_idx]);
		}
		fprintf(fileptr, "\n");
		#ifdef PRINT_PSHUF_INPUT
		fprintf(fileptr, "R %2d: PSHUFIN  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", dc_trail[__FF__].psh_i[word_idx]);
		}
		fprintf(fileptr, "\n");
		#endif
		PSHUF(round_out, dc_trail[__FF__].psh_i);
		fprintf(fileptr, "R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", round_out[word_idx]);
		}
		fprintf(fileptr, "\n");
		{
			PROB_t sum;
			Mul_Probs(&sum, dc_trail[__FF__].p, NUM_SBOX_IN_A_STATE);
			fprintf(fileptr, "R %2d: PROB     | 2^{%0.4lf}\n", __FF__, sum);
		}
		fprintf(fileptr, "========================\n");
	}

	fclose(fileptr);
}

void Print_LC_Trail(LC_1ROUND_CHAR_t * lc_trail, CNT_t round)
{
	CNT_t __FF__;
	CNT_t word_idx;
	CNT_t idx = 0;
	SBOX_t round_out[NUM_SBOX_IN_A_STATE];

	printf("[%2d] Round Linear Trail\n", round);
	printf("========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		printf("R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", lc_trail[__FF__].sub_i[word_idx]);
		}
		printf("\n");
		printf("R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", lc_trail[__FF__].sub_o[word_idx]);
		}
		printf("\n");
		#ifdef PRINT_PSHUF_INPUT
		printf("R %2d: PSHUFIN  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", lc_trail[__FF__].psh_i[word_idx]);
		}
		printf("\n");
		#endif	
		PSHUF(round_out, lc_trail[__FF__].psh_i);
		printf("R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			printf("%01X ", round_out[word_idx]);
		}
		printf("\n");
		{
			CORR_t sum;
			Mul_Corrs(&sum, lc_trail[__FF__].c, NUM_SBOX_IN_A_STATE);
			if (sum.sign == ZERO)
			{
				printf("R %2d: CORR     |  ZERO\n", __FF__);
			}
			else if (sum.sign == POSI)
			{
				printf("R %2d: CORR     | +2^{%0.4lf}\n", __FF__, sum.magnitude);
			}
			else
			{
				printf("R %2d: CORR     | -2^{%0.4lf}\n", __FF__, sum.magnitude);
			}
		}
		printf("========================\n");
	}
}

void FPrint_LC_Trail(char* filename, LC_1ROUND_CHAR_t * lc_trail, CNT_t round)
{
	CNT_t __FF__;
	CNT_t word_idx;
	CNT_t idx = 0;
	SBOX_t round_out[NUM_SBOX_IN_A_STATE];

	FILE * fileptr = fopen(filename, "w");

	fprintf(fileptr, "[%2d] Round Linear Trail\n", round);
	fprintf(fileptr, "========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		fprintf(fileptr, "R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", lc_trail[__FF__].sub_i[word_idx]);
		}
		fprintf(fileptr, "\n");
		fprintf(fileptr, "R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", lc_trail[__FF__].sub_o[word_idx]);
		}
		fprintf(fileptr, "\n");
		#ifdef PRINT_PSHUF_INPUT
		fprintf(fileptr, "R %2d: PSHUFIN  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", lc_trail[__FF__].psh_i[word_idx]);
		}
		fprintf(fileptr, "\n");
		#endif
		PSHUF(round_out, lc_trail[__FF__].psh_i);
		fprintf(fileptr, "R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < NUM_SBOX_IN_A_STATE; word_idx++)
		{
			fprintf(fileptr, "%01X ", round_out[word_idx]);
		}
		fprintf(fileptr, "\n");
		{
			CORR_t sum;
			Mul_Corrs(&sum, lc_trail[__FF__].c, NUM_SBOX_IN_A_STATE);
			if (sum.sign == ZERO)
			{
				fprintf(fileptr, "R %2d: CORR     |  ZERO\n", __FF__);
			}
			else if (sum.sign == POSI)
			{
				fprintf(fileptr, "R %2d: CORR     | +2^{%0.4lf}\n", __FF__, sum.magnitude);
			}
			else
			{
				fprintf(fileptr, "R %2d: CORR     | -2^{%0.4lf}\n", __FF__, sum.magnitude);
			}
		}
		fprintf(fileptr, "========================\n");
	}

	fclose(fileptr);
}