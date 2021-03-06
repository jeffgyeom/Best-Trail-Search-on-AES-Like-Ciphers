#include "astbb.h"
#include "bogi_common_info.h"
#include <stdio.h>
#include <string.h>

// There are 10 round commuting word-wise permutations for BOGI16 ciphers
// BOGI16_W00:  (0, 1, 2, 3) A : {(0, 1, 2, 3)} C: (0, )
// BOGI16_W01 : (1, 0, 3, 2) A : {(1, 0, 3, 2)} C: (0, )
// BOGI16_W02 : (1, 2, 3, 0) A : {(1, 2, 3, 0)} C: (0, )
// BOGI16_W03 : (1, 3, 0, 2) A : {(1, 3, 0, 2)} C: (0, )
// BOGI16_W04 : (2, 0, 3, 1) A : {(2, 0, 3, 1)} C: (0, )
// BOGI16_W05 : (2, 3, 0, 1) A : {(2, 3, 0, 1)} C: (0, )
// BOGI16_W06 : (2, 3, 1, 0) A : {(2, 3, 1, 0)} C: (0, )
// BOGI16_W07 : (3, 0, 1, 2) A : {(3, 0, 1, 2)} C: (0, )
// BOGI16_W08 : (3, 2, 0, 1) A : {(3, 2, 0, 1)} C: (0, )
// BOGI16_W09 : (3, 2, 1, 0) A : {(3, 2, 1, 0)} C: (0, )
//
// There are 5 types of round commuting word-wise permutation sets(GIFT(344)- BOGI16_3)
// BOGI16_0 : 1 : [W00]
// BOGI16_1 : 4 : [W00, W01, W05, W09]
// BOGI16_2 : 4 : [W00, W01, W06, W08]
// BOGI16_3 : 4 : [W00, W02, W05, W07]
// BOGI16_4 : 4 : [W00, W03, W04, W09]
CNT_t BOGI16_omega_types[576] = 
{
	BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_3, BOGI16_3, BOGI16_4, BOGI16_4, BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_3, BOGI16_3, BOGI16_1, BOGI16_2, BOGI16_2,
	BOGI16_3, BOGI16_3, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_2, BOGI16_1, BOGI16_1, BOGI16_2, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_2, BOGI16_2,
	BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_4, BOGI16_4,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_4, BOGI16_1, BOGI16_1, BOGI16_4, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1,
	BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0,
	BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_3, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_1, BOGI16_1, BOGI16_3, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_3,
	BOGI16_2, BOGI16_1, BOGI16_1, BOGI16_2, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1,
	BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_4, BOGI16_4, BOGI16_3, BOGI16_3,
	BOGI16_3, BOGI16_3, BOGI16_1, BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_4, BOGI16_4, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_3, BOGI16_3, BOGI16_1,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_3, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_3, BOGI16_3, BOGI16_3, BOGI16_1, BOGI16_1, BOGI16_3, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_4, BOGI16_1, BOGI16_1, BOGI16_4, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_4, BOGI16_4, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1,
	BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0,
	BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_4, BOGI16_1, BOGI16_1, BOGI16_4, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_4, BOGI16_4,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_1, BOGI16_1, BOGI16_3, BOGI16_3, BOGI16_3, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_3, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_1, BOGI16_3, BOGI16_3, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_4, BOGI16_4, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_3, BOGI16_3,
	BOGI16_3, BOGI16_3, BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0,
	BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_2, BOGI16_1, BOGI16_1, BOGI16_2,
	BOGI16_3, BOGI16_3, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_1, BOGI16_1, BOGI16_3, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_3, BOGI16_3, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1,
	BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_1, BOGI16_0,
	BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_4, BOGI16_1, BOGI16_1, BOGI16_4, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0,
	BOGI16_4, BOGI16_4, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_4, BOGI16_4,
	BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_0, BOGI16_0, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_0, BOGI16_0,
	BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_0, BOGI16_2, BOGI16_1, BOGI16_1, BOGI16_2, BOGI16_1, BOGI16_4, BOGI16_4, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_3, BOGI16_3,
	BOGI16_2, BOGI16_2, BOGI16_1, BOGI16_3, BOGI16_3, BOGI16_1, BOGI16_4, BOGI16_4, BOGI16_4, BOGI16_4, BOGI16_3, BOGI16_3, BOGI16_1, BOGI16_2, BOGI16_2, BOGI16_1
};

void BOGI16_info_out(void)
{
	int i;
	FILE* ofp;
	char name[256];
	sprintf_s(name, 256, "%s_info.txt", ALG_NAME);
	ofp = fopen(name, "w");
	fprintf(ofp, "%s\n", bogi16_commuting_types_strs[PERM_TYPE]);

	fprintf(ofp, "sidx : %d\n", SIDX);
	for (i = 0; i < NUM_SBOX_ENTRIES; i++)
	{
		fprintf(ofp, "%d, ", SBOX[i]);
	}
	fprintf(ofp, "\n");
	fprintf(ofp, "pidx : %d\n", PIDX);
	fclose(ofp);
}

extern void Use_Predefined_1Round_Active_Maps_BOGI16(CNT_t perm_type);
extern void SPN_Prep_Info_For_DC(void);
extern void SPN_Best_DC_Prob_Search(PROB_t * prob_rst, CNT_t target_round);
extern void SPN_Prep_Info_For_LC(void);
extern void SPN_Best_LC_Corr_Search(CORR_t * corr_rst, CNT_t target_round);


void PY_BOGI16_DC_Prob_Searching(
	PROB_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx
)
{
	SIDX = sbox_idx;
	PIDX = perm_idx;
	sprintf_s(ALG_NAME, 256, "BOGI16_%d_%d", SIDX, PIDX);
	memcpy(SBOX, BOGI_applicable_sboxes[SIDX], sizeof(SBOX_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[0], BOGI_pmixes_lookup[PIDX][0], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[1], BOGI_pmixes_lookup[PIDX][1], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[2], BOGI_pmixes_lookup[PIDX][2], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[3], BOGI_pmixes_lookup[PIDX][3], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	PERM_TYPE = BOGI16_omega_types[PIDX];

	BOGI16_info_out();

	SPN_Prep_Info_For_DC();

#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI16(PERM_TYPE);
#else
	Use_Predefined_1Round_Active_Maps_BOGI16(BOGI16_0);
#endif

	SPN_Best_DC_Prob_Search(rst, num_round);
}


void PY_BOGI16_LC_Corr_Searching(
	CORR_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx
)
{
	SIDX = sbox_idx;
	PIDX = perm_idx;
	sprintf_s(ALG_NAME, 256, "BOGI16_%d_%d", SIDX, PIDX);
	memcpy(SBOX, BOGI_applicable_sboxes[SIDX], sizeof(SBOX_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[0], BOGI_pmixes_lookup[PIDX][0], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[1], BOGI_pmixes_lookup[PIDX][1], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[2], BOGI_pmixes_lookup[PIDX][2], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[3], BOGI_pmixes_lookup[PIDX][3], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	PERM_TYPE = BOGI16_omega_types[PIDX];

	BOGI16_info_out();

	SPN_Prep_Info_For_LC();

#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI16(PERM_TYPE);
#else
	Use_Predefined_1Round_Active_Maps_BOGI16(BOGI16_0);
#endif

	SPN_Best_LC_Corr_Search(rst, num_round);
}