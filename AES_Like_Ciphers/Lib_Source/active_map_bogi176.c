#include "astbb.h"
#include "bit_perm_opt.h"

/*
BOGI176_0
1 Word-wise Permutations are Considered
active num  1 :  44
active num  2 :  946
active num  3 :  13244
active num  4 :  135751
active num  5 :  1086008
active num  6 :  7059052
active num  7 :  38320568
active num  8 :  177232627
active num  9 :  708930508
active num 10 :  2481256778
active num 11 :  7669339132
active num 12 :  21090682613
active num 13 :  51915526432
active num 14 :  114955808528
active num 15 :  229911617056
active num 16 :  416714805914
active num 17 :  686353797976
active num 18 :  1029530696964
active num 19 :  1408831480056
active num 20 :  1761039350070
active num 21 :  2012616400080
active num 22 :  2104098963720
active num 23 :  2012616400080
active num 24 :  1761039350070
active num 25 :  1408831480056
active num 26 :  1029530696964
active num 27 :  686353797976
active num 28 :  416714805914
active num 29 :  229911617056
active num 30 :  114955808528
active num 31 :  51915526432
active num 32 :  21090682613
active num 33 :  7669339132
active num 34 :  2481256778
active num 35 :  708930508
active num 36 :  177232627
active num 37 :  38320568
active num 38 :  7059052
active num 39 :  1086008
active num 40 :  135751
active num 41 :  13244
active num 42 :  946
active num 43 :  44
active num 44 :  1
		TOTAL : 17592186044415 (43.99)
*/


/*
BOGI176_1
2 Word-wise Permutations are Considered
active num  1 :  22
active num  2 :  484
active num  3 :  6622
active num  4 :  67991
active num  5 :  543004
active num  6 :  3530296
active num  7 :  19160284
active num  8 :  88619971
active num  9 :  354465254
active num 10 :  1240641556
active num 11 :  3834669566
active num 12 :  10545378613
active num 13 :  25957763216
active num 14 :  57477989536
active num 15 :  114955808528
active num 16 :  208357562842
active num 17 :  343176898988
active num 18 :  514765597192
active num 19 :  704415740028
active num 20 :  880519998358
active num 21 :  1006308200040
active num 22 :  1052049834576
active num 23 :  1006308200040
active num 24 :  880519998358
active num 25 :  704415740028
active num 26 :  514765597192
active num 27 :  343176898988
active num 28 :  208357562842
active num 29 :  114955808528
active num 30 :  57477989536
active num 31 :  25957763216
active num 32 :  10545378613
active num 33 :  3834669566
active num 34 :  1240641556
active num 35 :  354465254
active num 36 :  88619971
active num 37 :  19160284
active num 38 :  3530296
active num 39 :  543004
active num 40 :  67991
active num 41 :  6622
active num 42 :  484
active num 43 :  22
active num 44 :  1
		TOTAL : 8796095119359 (43.00)
*/




//(43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
//(43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
void BOGI176_W01(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xfffffffffffULL;
	//Benes 543210: 30 cycles, 5 masks
	bit_permute_step_64(&x, x, 0x0000055555555555, 1);
	bit_permute_step_64(&x, x, 0x0000033333333333, 2);
	bit_permute_step_64(&x, x, 0x0000000f000f000f, 8);
	bit_permute_step_64(&x, x, 0x000000000000f000, 16);
	bit_permute_step_64(&x, x, 0x0000000000000fff, 32);
	*out = (ACTIVE_MAP_t)x & 0xfffffffffffULL;
}