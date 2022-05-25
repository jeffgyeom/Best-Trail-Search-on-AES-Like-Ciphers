#include "astbb.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	PROB_t DC_RST[NUM_ROUND_THRESHOLD];
	CORR_t LC_RST[NUM_ROUND_THRESHOLD];
	int round;
	int choose;
	int sidx;
	int pidx;

	Print_Module_Status();
	
	printf("-> sidx (0 ~ 1727) (GIFT 94) : ");
	scanf("%d", &sidx);
	printf("-> pidx (0 ~ 575)  (GIFT 344): ");
	scanf("%d", &pidx);
	printf("-> (DC 1, LC 2)              : ");
	scanf("%d", &choose);
#if (defined BOGI_CIPHER_16 || defined BOGI_CIPHER_32 || defined BOGI_CIPHER_64)
	printf("-> Round (/28)               : ");
#else
	printf("-> Round (/40)               : ");
#endif
	scanf("%d", &round);

#ifdef BOGI_CIPHER_16
	if (choose == 1) //DC
	{
		PY_BOGI16_DC_Prob_Searching(DC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
	else if (choose == 2) //LC
	{
		PY_BOGI16_LC_Corr_Searching(LC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
#elif (defined BOGI_CIPHER_32)
	if (choose == 1) //DC
	{
		PY_BOGI32_DC_Prob_Searching(DC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
	else if (choose == 2) //LC
	{
		PY_BOGI32_LC_Corr_Searching(LC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
#elif (defined BOGI_CIPHER_64)
	if (choose == 1) //DC
	{
		PY_BOGI64_DC_Prob_Searching(DC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
	else if (choose == 2) //LC
	{
		PY_BOGI64_LC_Corr_Searching(LC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
#elif (defined BOGI_CIPHER_128)
	if (choose == 1) //DC
	{
		PY_BOGI128_DC_Prob_Searching(DC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
	else if (choose == 2) //LC
	{
		PY_BOGI128_LC_Corr_Searching(LC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
#elif (defined BOGI_CIPHER_176)
	if (choose == 1) //DC
	{
		PY_BOGI176_DC_Prob_Searching(DC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
	else if (choose == 2) //LC
	{
		PY_BOGI176_LC_Corr_Searching(LC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
#elif (defined BOGI_CIPHER_256)
	if (choose == 1) //DC
	{
		PY_BOGI256_DC_Prob_Searching(DC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
	else if (choose == 2) //LC
	{
		PY_BOGI256_LC_Corr_Searching(LC_RST, (CNT_t)round, (CNT_t)sidx, (CNT_t)pidx);
	}
#endif
	return 0;
}