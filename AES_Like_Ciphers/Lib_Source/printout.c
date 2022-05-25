#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "astbb.h"
#include "dif_prob.h"
#include "lin_corr.h"


void Print_Module_Status(void)
{
	printf("-- Compiled at %s %s\n", __TIME__, __DATE__);
#ifdef OUR_PC1
	printf("-> OUR_PC1\n");
#elif defined PRE_PC1
	printf("-> PRE_PC1\n");
#endif
#ifdef OUR_PC2
	printf("-> OUR_PC2\n");
#elif defined PRE_PC2
	printf("-> PRE_PC2\n");
#endif
#ifdef EMPLOY_PERM_CHAR
	printf("-> EMPLOY_PERM_CHAR\n");
#else
	printf("-> GENERAL_OPT_METHOD_FOR_ACTIVE_MAP\n");
#endif
}


FLAG_t Verbose_Check(UFLAG_t in_flag, UFLAG_t check_flag)
{
	FLAG_t rt;

	if (in_flag & check_flag)
	{
		rt = TRUE;
	}
	else
	{
		rt = FALSE;
	}

	return rt;
}


void Print_DC_Trail(DC_1ROUND_CHAR_t * dc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state)
{
	CNT_t __FF__;
	CNT_t word_idx;
	char sbox_i_word_template[256];
	char sbox_o_word_template[256];
	CNT_t idx = 0;

	while (sbox_i_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_i_word_template, "%%0%dX ", idx);
	idx = 0;
	while (sbox_o_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_o_word_template, "%%0%dX ", idx);

	printf("[%2d] Round Differential Trail\n", round);
	printf("========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		printf("R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			printf(sbox_i_word_template, dc_trail[__FF__].sub_i[word_idx]);
		}
		printf("\n");
		printf("R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			printf(sbox_o_word_template, dc_trail[__FF__].sub_o[word_idx]);
		}
		printf("\n");
		printf("R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			printf(sbox_i_word_template, dc_trail[__FF__].dif_o[word_idx]);
		}
		printf("\n");
		{
			PROB_t sum;
			Mul_Probs(&sum, dc_trail[__FF__].p, num_word_in_a_state);
			printf("R %2d: PROB     | 2^{%0.4lf}\n", __FF__, sum);
		}
		printf("========================\n");
	}
}

void FPrint_DC_Trail(char* filename, DC_1ROUND_CHAR_t * dc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state)
{
	CNT_t __FF__;
	CNT_t word_idx;
	char sbox_i_word_template[256];
	char sbox_o_word_template[256];
	CNT_t idx = 0;

	FILE * fileptr = fopen(filename, "w");

	while (sbox_i_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_i_word_template, "%%0%dX ", idx);
	idx = 0;
	while (sbox_o_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_o_word_template, "%%0%dX ", idx);

	fprintf(fileptr, "[%2d] Round Differential Trail\n", round);
	fprintf(fileptr, "========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		fprintf(fileptr, "R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			fprintf(fileptr, sbox_i_word_template, dc_trail[__FF__].sub_i[word_idx]);
		}
		fprintf(fileptr, "\n");
		fprintf(fileptr, "R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			fprintf(fileptr, sbox_o_word_template, dc_trail[__FF__].sub_o[word_idx]);
		}
		fprintf(fileptr, "\n");
		fprintf(fileptr, "R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			fprintf(fileptr, sbox_i_word_template, dc_trail[__FF__].dif_o[word_idx]);
		}
		fprintf(fileptr, "\n");
		{
			PROB_t sum;
			Mul_Probs(&sum, dc_trail[__FF__].p, num_word_in_a_state);
			fprintf(fileptr, "R %2d: PROB     | 2^{%0.4lf}\n", __FF__, sum);
		}
		fprintf(fileptr, "========================\n");
	}

	fclose(fileptr);
}

void Print_LC_Trail(LC_1ROUND_CHAR_t * lc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state)
{
	CNT_t __FF__;
	CNT_t word_idx;
	char sbox_i_word_template[256];
	char sbox_o_word_template[256];
	CNT_t idx = 0;

	while (sbox_i_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_i_word_template, "%%0%dX ", idx);
	idx = 0;
	while (sbox_o_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_o_word_template, "%%0%dX ", idx);

	printf("[%2d] Round Linear Trail\n", round);
	printf("========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		printf("R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			printf(sbox_i_word_template, lc_trail[__FF__].sub_i[word_idx]);
		}
		printf("\n");
		printf("R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			printf(sbox_o_word_template, lc_trail[__FF__].sub_o[word_idx]);
		}
		printf("\n");
		printf("R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			printf(sbox_i_word_template, lc_trail[__FF__].dif_o[word_idx]);
		}
		printf("\n");
		{
			CORR_t sum;
			Mul_Corrs(&sum, lc_trail[__FF__].c, num_word_in_a_state);
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

void FPrint_LC_Trail(char* filename, LC_1ROUND_CHAR_t * lc_trail, CNT_t round, BIT_SIZE_t sbox_i_word_bit_size, BIT_SIZE_t sbox_o_word_bit_size, NUM_t num_word_in_a_state)
{
	CNT_t __FF__;
	CNT_t word_idx;
	char sbox_i_word_template[256];
	char sbox_o_word_template[256];
	CNT_t idx = 0;

	FILE * fileptr = fopen(filename, "w");

	while (sbox_i_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_i_word_template, "%%0%dX ", idx);
	idx = 0;
	while (sbox_o_word_bit_size > (idx * 4))
	{
		idx++;
	}
	sprintf(sbox_o_word_template, "%%0%dX ", idx);

	fprintf(fileptr, "[%2d] Round Linear Trail\n", round);
	fprintf(fileptr, "========================\n");
	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		fprintf(fileptr, "R %2d: SBOXIN   | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			fprintf(fileptr, sbox_i_word_template, lc_trail[__FF__].sub_i[word_idx]);
		}
		fprintf(fileptr, "\n");
		fprintf(fileptr, "R %2d: SBOXOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			fprintf(fileptr, sbox_o_word_template, lc_trail[__FF__].sub_o[word_idx]);
		}
		fprintf(fileptr, "\n");
		fprintf(fileptr, "R %2d: DIFFOUT  | ", __FF__);
		for (word_idx = 0; word_idx < num_word_in_a_state; word_idx++)
		{
			fprintf(fileptr, sbox_i_word_template, lc_trail[__FF__].dif_o[word_idx]);
		}
		fprintf(fileptr, "\n");

		{
			CORR_t sum;
			Mul_Corrs(&sum, lc_trail[__FF__].c, num_word_in_a_state);
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


void Copy_DC_Trail(DC_1ROUND_CHAR_t * dst_trail, DC_1ROUND_CHAR_t * src_trail, CNT_t round, NUM_t num_word_in_a_state)
{
	CNT_t __FF__;

	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		memcpy(dst_trail[__FF__].sub_i, src_trail[__FF__].sub_i, sizeof(SBOX_I_WRD_t) * (size_t)num_word_in_a_state);
		memcpy(dst_trail[__FF__].sub_o, src_trail[__FF__].sub_o, sizeof(SBOX_O_WRD_t) * (size_t)num_word_in_a_state);
		//memcpy(dst_trail[__FF__].dif_o, src_trail[__FF__].dif_o, sizeof(DIFF_O_WRD_t) * (size_t)num_word_in_a_state);
		memcpy(dst_trail[__FF__].p    , src_trail[__FF__].p    , sizeof(PROB_t) * (size_t)num_word_in_a_state);
	}
}

void Copy_LC_Trail(LC_1ROUND_CHAR_t * dst_trail, LC_1ROUND_CHAR_t * src_trail, CNT_t round, NUM_t num_word_in_a_state)
{
	CNT_t __FF__;

	for (__FF__ = 1; __FF__ <= round; __FF__++)
	{
		memcpy(dst_trail[__FF__].sub_i, src_trail[__FF__].sub_i, sizeof(SBOX_I_WRD_t) * (size_t)num_word_in_a_state);
		memcpy(dst_trail[__FF__].sub_o, src_trail[__FF__].sub_o, sizeof(SBOX_O_WRD_t) * (size_t)num_word_in_a_state);
		//memcpy(dst_trail[__FF__].dif_o, src_trail[__FF__].dif_o, sizeof(DIFF_O_WRD_t) * (size_t)num_word_in_a_state);
		memcpy(dst_trail[__FF__].c    , src_trail[__FF__].c    , sizeof(CORR_t) * (size_t)num_word_in_a_state);
	}
}



