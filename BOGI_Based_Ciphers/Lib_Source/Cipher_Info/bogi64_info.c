#include "astbb.h"
#include "bogi_common_info.h"
#include <stdio.h>
#include <string.h>

// There are 52 round commuting word-wise permutations for BOGI128 ciphers
// BOGI64_W00:  (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15) A : {(0, 1, 2, 3)} C: (0, 1, 2, 3)
// BOGI64_W01 : (1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14) A : {(1, 0, 3, 2)} C: (0, 1, 2, 3)
// BOGI64_W02 : (1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12) A : {(1, 2, 3, 0)} C: (0, 1, 2, 3)
// BOGI64_W03 : (1, 3, 0, 2, 5, 7, 4, 6, 9, 11, 8, 10, 13, 15, 12, 14) A : {(1, 3, 0, 2)} C: (0, 1, 2, 3)
// BOGI64_W04 : (2, 0, 3, 1, 6, 4, 7, 5, 10, 8, 11, 9, 14, 12, 15, 13) A : {(2, 0, 3, 1)} C: (0, 1, 2, 3)
// BOGI64_W05 : (2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13) A : {(2, 3, 0, 1)} C: (0, 1, 2, 3)
// BOGI64_W06 : (2, 3, 1, 0, 6, 7, 5, 4, 10, 11, 9, 8, 14, 15, 13, 12) A : {(2, 3, 1, 0)} C: (0, 1, 2, 3)
// BOGI64_W07 : (3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14) A : {(3, 0, 1, 2)} C: (0, 1, 2, 3)
// BOGI64_W08 : (3, 2, 0, 1, 7, 6, 4, 5, 11, 10, 8, 9, 15, 14, 12, 13) A : {(3, 2, 0, 1)} C: (0, 1, 2, 3)
// BOGI64_W09 : (3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12) A : {(3, 2, 1, 0)} C: (0, 1, 2, 3)
// BOGI64_W0A : (4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11) A : {(0, 1, 2, 3)} C: (1, 0, 3, 2)
// BOGI64_W0B : (4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3) A : {(0, 1, 2, 3)} C: (1, 2, 3, 0)
// BOGI64_W0C : (4, 5, 6, 7, 12, 13, 14, 15, 0, 1, 2, 3, 8, 9, 10, 11) A : {(0, 1, 2, 3)} C: (1, 3, 0, 2)
// BOGI64_W0D : (5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10) A : {(1, 0, 3, 2)} C: (1, 0, 3, 2)
// BOGI64_W0E : (5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0) A : {(1, 2, 3, 0)} C: (1, 2, 3, 0)
// BOGI64_W0F : (5, 7, 4, 6, 13, 15, 12, 14, 1, 3, 0, 2, 9, 11, 8, 10) A : {(1, 3, 0, 2)} C: (1, 3, 0, 2)
// BOGI64_W10 : (6, 4, 7, 5, 14, 12, 15, 13, 2, 0, 3, 1, 10, 8, 11, 9) A : {(2, 0, 3, 1)} C: (1, 3, 0, 2)
// BOGI64_W11 : (6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9) A : {(2, 3, 0, 1)} C: (1, 0, 3, 2)
// BOGI64_W12 : (6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1) A : {(2, 3, 0, 1)} C: (1, 2, 3, 0)
// BOGI64_W13 : (6, 7, 5, 4, 2, 3, 1, 0, 14, 15, 13, 12, 10, 11, 9, 8) A : {(2, 3, 1, 0)} C: (1, 0, 3, 2)
// BOGI64_W14 : (7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2) A : {(3, 0, 1, 2)} C: (1, 2, 3, 0)
// BOGI64_W15 : (7, 6, 4, 5, 3, 2, 0, 1, 15, 14, 12, 13, 11, 10, 8, 9) A : {(3, 2, 0, 1)} C: (1, 0, 3, 2)
// BOGI64_W16 : (7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8) A : {(3, 2, 1, 0)} C: (1, 0, 3, 2)
// BOGI64_W17 : (7, 6, 5, 4, 15, 14, 13, 12, 3, 2, 1, 0, 11, 10, 9, 8) A : {(3, 2, 1, 0)} C: (1, 3, 0, 2)
// BOGI64_W18 : (8, 9, 10, 11, 0, 1, 2, 3, 12, 13, 14, 15, 4, 5, 6, 7) A : {(0, 1, 2, 3)} C: (2, 0, 3, 1)
// BOGI64_W19 : (8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7) A : {(0, 1, 2, 3)} C: (2, 3, 0, 1)
// BOGI64_W1A : (8, 9, 10, 11, 12, 13, 14, 15, 4, 5, 6, 7, 0, 1, 2, 3) A : {(0, 1, 2, 3)} C: (2, 3, 1, 0)
// BOGI64_W1B : (9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6) A : {(1, 0, 3, 2)} C: (2, 3, 0, 1)
// BOGI64_W1C : (9, 8, 11, 10, 13, 12, 15, 14, 5, 4, 7, 6, 1, 0, 3, 2) A : {(1, 0, 3, 2)} C: (2, 3, 1, 0)
// BOGI64_W1D : (9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4) A : {(1, 2, 3, 0)} C: (2, 3, 0, 1)
// BOGI64_W1E : (9, 11, 8, 10, 1, 3, 0, 2, 13, 15, 12, 14, 5, 7, 4, 6) A : {(1, 3, 0, 2)} C: (2, 0, 3, 1)
// BOGI64_W1F : (10, 8, 11, 9, 2, 0, 3, 1, 14, 12, 15, 13, 6, 4, 7, 5) A : {(2, 0, 3, 1)} C: (2, 0, 3, 1)
// BOGI64_W20 : (10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5) A : {(2, 3, 0, 1)} C: (2, 3, 0, 1)
// BOGI64_W21 : (10, 11, 9, 8, 14, 15, 13, 12, 6, 7, 5, 4, 2, 3, 1, 0) A : {(2, 3, 1, 0)} C: (2, 3, 1, 0)
// BOGI64_W22 : (11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6) A : {(3, 0, 1, 2)} C: (2, 3, 0, 1)
// BOGI64_W23 : (11, 10, 8, 9, 15, 14, 12, 13, 7, 6, 4, 5, 3, 2, 0, 1) A : {(3, 2, 0, 1)} C: (2, 3, 1, 0)
// BOGI64_W24 : (11, 10, 9, 8, 3, 2, 1, 0, 15, 14, 13, 12, 7, 6, 5, 4) A : {(3, 2, 1, 0)} C: (2, 0, 3, 1)
// BOGI64_W25 : (11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4) A : {(3, 2, 1, 0)} C: (2, 3, 0, 1)
// BOGI64_W26 : (12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11) A : {(0, 1, 2, 3)} C: (3, 0, 1, 2)
// BOGI64_W27 : (12, 13, 14, 15, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7) A : {(0, 1, 2, 3)} C: (3, 2, 0, 1)
// BOGI64_W28 : (12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3) A : {(0, 1, 2, 3)} C: (3, 2, 1, 0)
// BOGI64_W29 : (13, 12, 15, 14, 9, 8, 11, 10, 1, 0, 3, 2, 5, 4, 7, 6) A : {(1, 0, 3, 2)} C: (3, 2, 0, 1)
// BOGI64_W2A : (13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2) A : {(1, 0, 3, 2)} C: (3, 2, 1, 0)
// BOGI64_W2B : (13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8) A : {(1, 2, 3, 0)} C: (3, 0, 1, 2)
// BOGI64_W2C : (13, 15, 12, 14, 9, 11, 8, 10, 5, 7, 4, 6, 1, 3, 0, 2) A : {(1, 3, 0, 2)} C: (3, 2, 1, 0)
// BOGI64_W2D : (14, 12, 15, 13, 10, 8, 11, 9, 6, 4, 7, 5, 2, 0, 3, 1) A : {(2, 0, 3, 1)} C: (3, 2, 1, 0)
// BOGI64_W2E : (14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9) A : {(2, 3, 0, 1)} C: (3, 0, 1, 2)
// BOGI64_W2F : (14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1) A : {(2, 3, 0, 1)} C: (3, 2, 1, 0)
// BOGI64_W30 : (14, 15, 13, 12, 10, 11, 9, 8, 2, 3, 1, 0, 6, 7, 5, 4) A : {(2, 3, 1, 0)} C: (3, 2, 0, 1)
// BOGI64_W31 : (15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10) A : {(3, 0, 1, 2)} C: (3, 0, 1, 2)
// BOGI64_W32 : (15, 14, 12, 13, 11, 10, 8, 9, 3, 2, 0, 1, 7, 6, 4, 5) A : {(3, 2, 0, 1)} C: (3, 2, 0, 1)
// BOGI64_W33 : (15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0) A : {(3, 2, 1, 0)} C: (3, 2, 1, 0)
//
// There are 5 types of round commuting word-wise permutation sets(GIFT(344) - BOGI64_3)
// BOGI64_0 : 1 : [W00]
// BOGI64_1 : 16: [W00, W01, W05, W09, W0A, W0D, W11, W16, W19, W1B, W20, W25, W28, W2A, W2F, W33]
// BOGI64_2 : 16: [W00, W01, W06, W08, W0A, W0D, W13, W15, W1A, W1C, W21, W23, W27, W29, W30, W32]
// BOGI64_3 : 16: [W00, W02, W05, W07, W0B, W0E, W12, W14, W19, W1D, W20, W22, W26, W2B, W2E, W31]
// BOGI64_4 : 16: [W00, W03, W04, W09, W0C, W0F, W10, W17, W18, W1E, W1F, W24, W28, W2C, W2D, W33]
CNT_t BOGI64_omega_types[576] =
{
	BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_3, BOGI64_3, BOGI64_4, BOGI64_4, BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_3, BOGI64_3, BOGI64_1, BOGI64_2, BOGI64_2,
	BOGI64_3, BOGI64_3, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_2, BOGI64_1, BOGI64_1, BOGI64_2, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_2, BOGI64_2,
	BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_4, BOGI64_4,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_4, BOGI64_1, BOGI64_1, BOGI64_4, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1,
	BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0,
	BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_3, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_1, BOGI64_1, BOGI64_3, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_3,
	BOGI64_2, BOGI64_1, BOGI64_1, BOGI64_2, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1,
	BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_4, BOGI64_4, BOGI64_3, BOGI64_3,
	BOGI64_3, BOGI64_3, BOGI64_1, BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_4, BOGI64_4, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_3, BOGI64_3, BOGI64_1,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_3, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_3, BOGI64_3, BOGI64_3, BOGI64_1, BOGI64_1, BOGI64_3, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_4, BOGI64_1, BOGI64_1, BOGI64_4, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_4, BOGI64_4, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1,
	BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0,
	BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_4, BOGI64_1, BOGI64_1, BOGI64_4, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_4, BOGI64_4,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_1, BOGI64_1, BOGI64_3, BOGI64_3, BOGI64_3, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_3, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_1, BOGI64_3, BOGI64_3, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_4, BOGI64_4, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_3, BOGI64_3,
	BOGI64_3, BOGI64_3, BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0,
	BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_2, BOGI64_1, BOGI64_1, BOGI64_2,
	BOGI64_3, BOGI64_3, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_1, BOGI64_1, BOGI64_3, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_3, BOGI64_3, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1,
	BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_1, BOGI64_0,
	BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_4, BOGI64_1, BOGI64_1, BOGI64_4, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0,
	BOGI64_4, BOGI64_4, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_4, BOGI64_4,
	BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_0, BOGI64_0, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_0, BOGI64_0,
	BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_0, BOGI64_2, BOGI64_1, BOGI64_1, BOGI64_2, BOGI64_1, BOGI64_4, BOGI64_4, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_3, BOGI64_3,
	BOGI64_2, BOGI64_2, BOGI64_1, BOGI64_3, BOGI64_3, BOGI64_1, BOGI64_4, BOGI64_4, BOGI64_4, BOGI64_4, BOGI64_3, BOGI64_3, BOGI64_1, BOGI64_2, BOGI64_2, BOGI64_1,
};
void BOGI64_info_out(void)
{
	int i;
	FILE* ofp;
	char name[256];
	sprintf_s(name, 256, "%s_info.txt", ALG_NAME);
	ofp = fopen(name, "w");
	fprintf(ofp, "%s\n", bogi64_commuting_types_strs[PERM_TYPE]);

	fprintf(ofp, "sidx : %d\n", SIDX);
	for (i = 0; i < NUM_SBOX_ENTRIES; i++)
	{
		fprintf(ofp, "%d, ", SBOX[i]);
	}
	fprintf(ofp, "\n");
	fprintf(ofp, "pidx : %d\n", PIDX);
	fclose(ofp);
}

extern void Use_Predefined_1Round_Active_Maps_BOGI64(CNT_t perm_type);
extern void SPN_Prep_Info_For_DC(void);
extern void SPN_Best_DC_Prob_Search(PROB_t * prob_rst, CNT_t target_round);
extern void SPN_Prep_Info_For_LC(void);
extern void SPN_Best_LC_Corr_Search(CORR_t * corr_rst, CNT_t target_round);


void PY_BOGI64_DC_Prob_Searching(
	PROB_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx
)
{
	SIDX = sbox_idx;
	PIDX = perm_idx;
	sprintf_s(ALG_NAME, 256, "BOGI64_%d_%d", SIDX, PIDX);
	memcpy(SBOX, BOGI_applicable_sboxes[SIDX], sizeof(SBOX_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[0], BOGI_pmixes_lookup[PIDX][0], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[1], BOGI_pmixes_lookup[PIDX][1], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[2], BOGI_pmixes_lookup[PIDX][2], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[3], BOGI_pmixes_lookup[PIDX][3], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	PERM_TYPE = BOGI64_omega_types[PIDX];

	BOGI64_info_out();

	SPN_Prep_Info_For_DC();

#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI64(PERM_TYPE);
#else
	Use_Predefined_1Round_Active_Maps_BOGI64(BOGI64_0);
#endif

	SPN_Best_DC_Prob_Search(rst, num_round);
}


void PY_BOGI64_LC_Corr_Searching(
	CORR_t * rst,
	CNT_t num_round,
	CNT_t sbox_idx,
	CNT_t perm_idx
)
{
	SIDX = sbox_idx;
	PIDX = perm_idx;
	sprintf_s(ALG_NAME, 256, "BOGI64_%d_%d", SIDX, PIDX);
	memcpy(SBOX, BOGI_applicable_sboxes[SIDX], sizeof(SBOX_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[0], BOGI_pmixes_lookup[PIDX][0], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[1], BOGI_pmixes_lookup[PIDX][1], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[2], BOGI_pmixes_lookup[PIDX][2], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	memcpy(PMIX_LOOKUP[3], BOGI_pmixes_lookup[PIDX][3], sizeof(uint32_t) * NUM_SBOX_ENTRIES);
	PERM_TYPE = BOGI64_omega_types[PIDX];

	BOGI64_info_out();

	SPN_Prep_Info_For_LC();

#ifdef EMPLOY_PERM_CHAR
	Use_Predefined_1Round_Active_Maps_BOGI64(PERM_TYPE);
#else
	Use_Predefined_1Round_Active_Maps_BOGI64(BOGI64_0);
#endif

	SPN_Best_LC_Corr_Search(rst, num_round);
}