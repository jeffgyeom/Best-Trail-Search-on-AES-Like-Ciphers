#include "astbb.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	CHAR_t	alg_name[256];
	CNT_t   num_round;
	void	(*cb_dc_searching)(PROB_t *, CNT_t, UFLAG_t);
	void	(*cb_lc_searching)(CORR_t *, CNT_t, UFLAG_t);
}ALG_INFO_t;

ALG_INFO_t TEST_ALGS[] = {
	//SMN
	{"AES128",		10,	PY_AES128_DC_Prob_Searching,	PY_AES128_LC_Corr_Searching	},

	//SMN
	{"LED64",		48,	PY_LED64_DC_Prob_Searching,	    PY_LED64_LC_Corr_Searching	},
	
	//SBMN
	{"MIDORI64",	16, PY_MIDORI64_DC_Prob_Searching,	PY_MIDORI64_LC_Corr_Searching	},
	{"SKINNY64",	36, PY_SKINNY64_DC_Prob_Searching,	PY_SKINNY64_LC_Corr_Searching	},
	{"SKINNY128",	48, PY_SKINNY128_DC_Prob_Searching,	PY_SKINNY128_LC_Corr_Searching	},
	{"CRAFT64",		30, PY_CRAFT64_DC_Prob_Searching,	PY_CRAFT64_LC_Corr_Searching	},

	//SBPN
	{"GIFT64",		28, PY_GIFT64_DC_Prob_Searching,		PY_GIFT64_LC_Corr_Searching		},
	{"GIFT128",		40, PY_GIFT128_DC_Prob_Searching,		PY_GIFT128_LC_Corr_Searching	},
	{"PRESENT64",	31, PY_PRESENT64_DC_Prob_Searching,		PY_PRESENT64_LC_Corr_Searching	},
	{"PRESENT128",	43, PY_PRESENT128_DC_Prob_Searching,	PY_PRESENT128_LC_Corr_Searching	},
	{"SPONGENT176",	90, PY_SPONGENT176_DC_Prob_Searching,	PY_SPONGENT176_LC_Corr_Searching},

	//SRBPN
	{"RECTANGLE64",	25, PY_RECTANGLE64_DC_Prob_Searching,	PY_RECTANGLE64_LC_Corr_Searching},
	{"FLY64",		20, PY_FLY64_DC_Prob_Searching,			PY_FLY64_LC_Corr_Searching},
	{"PIPO64",		17, PY_PIPO64_DC_Prob_Searching,		PY_PIPO64_LC_Corr_Searching},
};


int main(int argc, char * argv[])
{
	int num_test_algs = sizeof(TEST_ALGS) / sizeof(ALG_INFO_t);
	UFLAG_t vv_mode;
	int round;
	int choose;
	int ii;
	int chosen_alg;
	Print_Module_Status();
	if (argc != 5)
	{

		for (ii = 0; ii < num_test_algs; ii++)
		{
			printf("%2d : %s\n", ii, TEST_ALGS[ii].alg_name);
		}
		printf("-> ");
		scanf("%d", &chosen_alg);
		printf("Trail Searching For %s\n", TEST_ALGS[chosen_alg].alg_name);
		printf("->(DC 1, LC 2) : ");
		scanf("%d", &choose);
		printf("->Round (/%d) : ", TEST_ALGS[chosen_alg].num_round);
		scanf("%d", &round);
		printf("->Verbose Mode : ");
		scanf("%u", &vv_mode);
	}
	else
	{
		chosen_alg	= atoi(argv[1]);
		choose		= atoi(argv[2]);
		round		= atoi(argv[3]);
		vv_mode		= (UFLAG_t)atoi(argv[4]);
		printf("-> ");
		printf("%d\n", chosen_alg);
		printf("Trail Searching For %s\n", TEST_ALGS[chosen_alg].alg_name);
		printf("-> (DC 1, LC 2) : ");
		printf("%d\n", choose);
		printf("-> Round (/%d)  : ", TEST_ALGS[chosen_alg].num_round);
		printf("%d\n", round);
		printf("-> Verbose Mode : ");
		printf("%u\n", vv_mode);
	}

	if (choose == 1)//DC
	{
		PROB_t *rst;
		rst = (PROB_t*)malloc(sizeof(PROB_t)*(size_t)TEST_ALGS[chosen_alg].num_round);
		TEST_ALGS[chosen_alg].cb_dc_searching(rst, round, vv_mode);
		free(rst);
	}
	else if(choose == 2)//LC
	{
		CORR_t *rst;
		rst = (CORR_t*)malloc(sizeof(CORR_t)*(size_t)TEST_ALGS[chosen_alg].num_round);
		TEST_ALGS[chosen_alg].cb_lc_searching(rst, round, vv_mode);
		free(rst);
	}

	return 0;
}