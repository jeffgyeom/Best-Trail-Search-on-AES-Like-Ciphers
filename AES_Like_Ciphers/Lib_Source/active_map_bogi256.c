#include "astbb.h"
#include "bit_perm_opt.h"

/*
BOGI256_0
18446744073709551616(64) Word-wise Permutations are Considered
active num  1 : 64
active num  2 : 2016
active num  3 : 41664
active num  4 : 635376
active num  5 : 7624512
active num  6 : 74974368
active num  7 : 621216192
active num  8 : 4426165368
active num  9 : 27540584512
active num 10 : 151473214816
....
active num 54 : 151473214816
active num 55 : 27540584512
active num 56 : 4426165368
active num 57 : 621216192
active num 58 : 74974368
active num 59 : 7624512
active num 60 : 635376
active num 61 : 41664
active num 62 : 2016
active num 63 : 64
active num 64 : 1
		TOTAL : 18446744073709551616(64)
*/

/*
BOGI256_1

active num  1 : 1
active num  2 : 63
active num  3 : 651
active num  4 : 10416
active num  5 : 119133
active num  6 : 1176357
active num  7 : 9706503
active num  8 : 69194232
active num  9 : 430321633
active num 10 : 2366967211
....
active num 54 : 2366967211
active num 55 : 430321633
active num 56 : 69194232
active num 57 : 9706503
active num 58 : 1176357
active num 59 : 119133
active num 60 : 10416
active num 61 : 651
active num 62 : 63
active num 63 : 1
active num 64 : 1
		TOTAL : 
*/


/*
BOGI256_2, BOGI256_3, BOGI256_4

active num  1 : 1
active num  2 : 35
active num  3 : 651
active num  4 : 9996
active num  5 : 119133
active num  6 : 1172017
active num  7 : 9706503
active num  8 : 69162872
active num  9 : 430321633
active num 10 : 2366791007
....
active num 54 : 2366791007
active num 55 : 430321633
active num 56 : 69162872
active num 57 : 9706503
active num 58 : 1172017
active num 59 : 119133
active num 60 : 9996
active num 61 : 651
active num 62 : 35
active num 63 : 1
active num 64 : 1
		TOTAL :
*/




void BOGI256_W00(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	*out = in;
}

//(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 33, 32, 35, 34, 37, 36, 39, 38, 41, 40, 43, 42, 45, 44, 47, 46, 49, 48, 51, 50, 53, 52, 55, 54, 57, 56, 59, 58, 61, 60, 63, 62)
void BOGI256_W01(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000001: 4 cycles, 1 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);

	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30, 35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46, 51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62)
void BOGI256_W02(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ((x & 0x1111111111111111) << 3)
		| ((x & 0xeeeeeeeeeeeeeeee) >> 1);

	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(1, 3, 0, 2, 5, 7, 4, 6, 9, 11, 8, 10, 13, 15, 12, 14, 17, 19, 16, 18, 21, 23, 20, 22, 25, 27, 24, 26, 29, 31, 28, 30, 33, 35, 32, 34, 37, 39, 36, 38, 41, 43, 40, 42, 45, 47, 44, 46, 49, 51, 48, 50, 53, 55, 52, 54, 57, 59, 56, 58, 61, 63, 60, 62)
void BOGI256_W03(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x4444444444444444) << 1)
		| ((x & 0x1111111111111111) << 2)
		| ((x & 0x8888888888888888) >> 2)
		| ((x & 0x2222222222222222) >> 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(2, 0, 3, 1, 6, 4, 7, 5, 10, 8, 11, 9, 14, 12, 15, 13, 18, 16, 19, 17, 22, 20, 23, 21, 26, 24, 27, 25, 30, 28, 31, 29, 34, 32, 35, 33, 38, 36, 39, 37, 42, 40, 43, 41, 46, 44, 47, 45, 50, 48, 51, 49, 54, 52, 55, 53, 58, 56, 59, 57, 62, 60, 63, 61)
void BOGI256_W04(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x1111111111111111) << 1)
		| ((x & 0x2222222222222222) << 2)
		| ((x & 0x4444444444444444) >> 2)
		| ((x & 0x8888888888888888) >> 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61)
void BOGI256_W05(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000002: 4 cycles, 1 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(3, 2, 0, 1, 7, 6, 4, 5, 11, 10, 8, 9, 15, 14, 12, 13, 19, 18, 16, 17, 23, 22, 20, 21, 27, 26, 24, 25, 31, 30, 28, 29, 35, 34, 32, 33, 39, 38, 36, 37, 43, 42, 40, 41, 47, 46, 44, 45, 51, 50, 48, 49, 55, 54, 52, 53, 59, 58, 56, 57, 63, 62, 60, 61)
void BOGI256_W06(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 6 cycles, 3 masks

	x = ((x & 0x2222222222222222) << 1)
		| ((x & 0x1111111111111111) << 3)
		| ((x & 0xcccccccccccccccc) >> 2);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28, 33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44, 49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60)
void BOGI256_W07(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ((x & 0x7777777777777777) << 1)
		| ((x & 0x8888888888888888) >> 3);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(2, 3, 1, 0, 6, 7, 5, 4, 10, 11, 9, 8, 14, 15, 13, 12, 18, 19, 17, 16, 22, 23, 21, 20, 26, 27, 25, 24, 30, 31, 29, 28, 34, 35, 33, 32, 38, 39, 37, 36, 42, 43, 41, 40, 46, 47, 45, 44, 50, 51, 49, 48, 54, 55, 53, 52, 58, 59, 57, 56, 62, 63, 61, 60)
void BOGI256_W08(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 6 cycles, 3 masks

	x = ((x & 0x3333333333333333) << 2)
		| ((x & 0x8888888888888888) >> 3)
		| ((x & 0x4444444444444444) >> 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28, 35, 34, 33, 32, 39, 38, 37, 36, 43, 42, 41, 40, 47, 46, 45, 44, 51, 50, 49, 48, 55, 54, 53, 52, 59, 58, 57, 56, 63, 62, 61, 60)
void BOGI256_W09(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000003: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27, 36, 37, 38, 39, 32, 33, 34, 35, 44, 45, 46, 47, 40, 41, 42, 43, 52, 53, 54, 55, 48, 49, 50, 51, 60, 61, 62, 63, 56, 57, 58, 59)
void BOGI256_W0A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000004: 4 cycles, 1 masks

	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59)
void BOGI256_W0B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ((x & 0x000f000f000f000f) << 12)
		| ((x & 0xfff0fff0fff0fff0) >> 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(4, 5, 6, 7, 12, 13, 14, 15, 0, 1, 2, 3, 8, 9, 10, 11, 20, 21, 22, 23, 28, 29, 30, 31, 16, 17, 18, 19, 24, 25, 26, 27, 36, 37, 38, 39, 44, 45, 46, 47, 32, 33, 34, 35, 40, 41, 42, 43, 52, 53, 54, 55, 60, 61, 62, 63, 48, 49, 50, 51, 56, 57, 58, 59)
void BOGI256_W0C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x0f000f000f000f00) << 4)
		| ((x & 0x000f000f000f000f) << 8)
		| ((x & 0xf000f000f000f000) >> 8)
		| ((x & 0x00f000f000f000f0) >> 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26, 37, 36, 39, 38, 33, 32, 35, 34, 45, 44, 47, 46, 41, 40, 43, 42, 53, 52, 55, 54, 49, 48, 51, 50, 61, 60, 63, 62, 57, 56, 59, 58)
void BOGI256_W0D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000005: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26, 47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42, 63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58)
void BOGI256_W0E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x000e000e000e000e) << 11)
		| ((x & 0x0001000100010001) << 15)
		| ((x & 0xeee0eee0eee0eee0) >> 5)
		| ((x & 0x1110111011101110) >> 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(5, 7, 4, 6, 13, 15, 12, 14, 1, 3, 0, 2, 9, 11, 8, 10, 21, 23, 20, 22, 29, 31, 28, 30, 17, 19, 16, 18, 25, 27, 24, 26, 37, 39, 36, 38, 45, 47, 44, 46, 33, 35, 32, 34, 41, 43, 40, 42, 53, 55, 52, 54, 61, 63, 60, 62, 49, 51, 48, 50, 57, 59, 56, 58)
void BOGI256_W0F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 103245/0x000000000000000a: 18 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(6, 4, 7, 5, 14, 12, 15, 13, 2, 0, 3, 1, 10, 8, 11, 9, 22, 20, 23, 21, 30, 28, 31, 29, 18, 16, 19, 17, 26, 24, 27, 25, 38, 36, 39, 37, 46, 44, 47, 45, 34, 32, 35, 33, 42, 40, 43, 41, 54, 52, 55, 53, 62, 60, 63, 61, 50, 48, 51, 49, 58, 56, 59, 57)
void BOGI256_W10(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 103245/0x0000000000000009: 18 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9, 22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25, 38, 39, 36, 37, 34, 35, 32, 33, 46, 47, 44, 45, 42, 43, 40, 41, 54, 55, 52, 53, 50, 51, 48, 49, 62, 63, 60, 61, 58, 59, 56, 57)
void BOGI256_W11(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000006: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57)
void BOGI256_W12(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x000c000c000c000c) << 10)
		| ((x & 0x0003000300030003) << 14)
		| ((x & 0xccc0ccc0ccc0ccc0) >> 6)
		| ((x & 0x3330333033303330) >> 2);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(7, 6, 4, 5, 3, 2, 0, 1, 15, 14, 12, 13, 11, 10, 8, 9, 23, 22, 20, 21, 19, 18, 16, 17, 31, 30, 28, 29, 27, 26, 24, 25, 39, 38, 36, 37, 35, 34, 32, 33, 47, 46, 44, 45, 43, 42, 40, 41, 55, 54, 52, 53, 51, 50, 48, 49, 63, 62, 60, 61, 59, 58, 56, 57)
void BOGI256_W13(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x0c0c0c0c0c0c0c0c) << 2)
		| ((x & 0x0202020202020202) << 5)
		| ((x & 0x0101010101010101) << 7)
		| ((x & 0xc0c0c0c0c0c0c0c0) >> 6)
		| ((x & 0x2020202020202020) >> 3)
		| ((x & 0x1010101010101010) >> 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24, 45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40, 61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56)
void BOGI256_W14(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x0008000800080008) << 9)
		| ((x & 0x0007000700070007) << 13)
		| ((x & 0x8880888088808880) >> 7)
		| ((x & 0x7770777077707770) >> 3);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(6, 7, 5, 4, 2, 3, 1, 0, 14, 15, 13, 12, 10, 11, 9, 8, 22, 23, 21, 20, 18, 19, 17, 16, 30, 31, 29, 28, 26, 27, 25, 24, 38, 39, 37, 36, 34, 35, 33, 32, 46, 47, 45, 44, 42, 43, 41, 40, 54, 55, 53, 52, 50, 51, 49, 48, 62, 63, 61, 60, 58, 59, 57, 56)
void BOGI256_W15(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x0808080808080808) << 1)
		| ((x & 0x0404040404040404) << 3)
		| ((x & 0x0303030303030303) << 6)
		| ((x & 0x8080808080808080) >> 7)
		| ((x & 0x4040404040404040) >> 5)
		| ((x & 0x3030303030303030) >> 2);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40, 55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56)
void BOGI256_W16(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000007: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(7, 6, 5, 4, 15, 14, 13, 12, 3, 2, 1, 0, 11, 10, 9, 8, 23, 22, 21, 20, 31, 30, 29, 28, 19, 18, 17, 16, 27, 26, 25, 24, 39, 38, 37, 36, 47, 46, 45, 44, 35, 34, 33, 32, 43, 42, 41, 40, 55, 54, 53, 52, 63, 62, 61, 60, 51, 50, 49, 48, 59, 58, 57, 56)
void BOGI256_W17(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 013245/0x000000000000000b: 17 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(8, 9, 10, 11, 0, 1, 2, 3, 12, 13, 14, 15, 4, 5, 6, 7, 24, 25, 26, 27, 16, 17, 18, 19, 28, 29, 30, 31, 20, 21, 22, 23, 40, 41, 42, 43, 32, 33, 34, 35, 44, 45, 46, 47, 36, 37, 38, 39, 56, 57, 58, 59, 48, 49, 50, 51, 60, 61, 62, 63, 52, 53, 54, 55)
void BOGI256_W18(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x000f000f000f000f) << 4)
		| ((x & 0x00f000f000f000f0) << 8)
		| ((x & 0x0f000f000f000f00) >> 8)
		| ((x & 0xf000f000f000f000) >> 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55)
void BOGI256_W19(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000008: 4 cycles, 1 masks

	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(12, 13, 14, 15, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 28, 29, 30, 31, 24, 25, 26, 27, 16, 17, 18, 19, 20, 21, 22, 23, 44, 45, 46, 47, 40, 41, 42, 43, 32, 33, 34, 35, 36, 37, 38, 39, 60, 61, 62, 63, 56, 57, 58, 59, 48, 49, 50, 51, 52, 53, 54, 55)
void BOGI256_W1A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 6 cycles, 3 masks

	x = ((x & 0x00f000f000f000f0) << 4)
		| ((x & 0x000f000f000f000f) << 12)
		| ((x & 0xff00ff00ff00ff00) >> 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6, 25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22, 41, 40, 43, 42, 45, 44, 47, 46, 33, 32, 35, 34, 37, 36, 39, 38, 57, 56, 59, 58, 61, 60, 63, 62, 49, 48, 51, 50, 53, 52, 55, 54)
void BOGI256_W1B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000009: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(13, 12, 15, 14, 9, 8, 11, 10, 1, 0, 3, 2, 5, 4, 7, 6, 29, 28, 31, 30, 25, 24, 27, 26, 17, 16, 19, 18, 21, 20, 23, 22, 45, 44, 47, 46, 41, 40, 43, 42, 33, 32, 35, 34, 37, 36, 39, 38, 61, 60, 63, 62, 57, 56, 59, 58, 49, 48, 51, 50, 53, 52, 55, 54)
void BOGI256_W1C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x00a000a000a000a0) << 3)
		| ((x & 0x0050005000500050) << 5)
		| ((x & 0x000a000a000a000a) << 11)
		| ((x & 0x0005000500050005) << 13)
		| ((x & 0xaa00aa00aa00aa00) >> 9)
		| ((x & 0x5500550055005500) >> 7);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22, 43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38, 59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54)
void BOGI256_W1D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x00ee00ee00ee00ee) << 7)
		| ((x & 0x0011001100110011) << 11)
		| ((x & 0xee00ee00ee00ee00) >> 9)
		| ((x & 0x1100110011001100) >> 5);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(9, 11, 8, 10, 1, 3, 0, 2, 13, 15, 12, 14, 5, 7, 4, 6, 25, 27, 24, 26, 17, 19, 16, 18, 29, 31, 28, 30, 21, 23, 20, 22, 41, 43, 40, 42, 33, 35, 32, 34, 45, 47, 44, 46, 37, 39, 36, 38, 57, 59, 56, 58, 49, 51, 48, 50, 61, 63, 60, 62, 53, 55, 52, 54)
void BOGI256_W1E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 103245/0x0000000000000006: 18 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(10, 8, 11, 9, 2, 0, 3, 1, 14, 12, 15, 13, 6, 4, 7, 5, 26, 24, 27, 25, 18, 16, 19, 17, 30, 28, 31, 29, 22, 20, 23, 21, 42, 40, 43, 41, 34, 32, 35, 33, 46, 44, 47, 45, 38, 36, 39, 37, 58, 56, 59, 57, 50, 48, 51, 49, 62, 60, 63, 61, 54, 52, 55, 53)
void BOGI256_W1F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 103245/0x0000000000000005: 18 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53)
void BOGI256_W20(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000000a: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(15, 14, 12, 13, 11, 10, 8, 9, 3, 2, 0, 1, 7, 6, 4, 5, 31, 30, 28, 29, 27, 26, 24, 25, 19, 18, 16, 17, 23, 22, 20, 21, 47, 46, 44, 45, 43, 42, 40, 41, 35, 34, 32, 33, 39, 38, 36, 37, 63, 62, 60, 61, 59, 58, 56, 57, 51, 50, 48, 49, 55, 54, 52, 53)
void BOGI256_W21(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Shift by mul (1): 16 cycles, 8 masks

	x = ((x & 0x00c000c000c000c0) << 2)
		| ((x & 0xcc00cc00cc00cc00) >> 10)
		| ((x & 0x2200220022002200) >> 7)
		| ((x & 0x1100110011001100) >> 5)
		| ((x & 0x000c000c000c000c) << 10)
		| (((x & 0x0033003300330033) * 0x000000000000a0a0) & 0xcc00cc00cc00cc00);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20, 41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36, 57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52)
void BOGI256_W22(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x0088008800880088) << 5)
		| ((x & 0x0077007700770077) << 9)
		| ((x & 0x8800880088008800) >> 11)
		| ((x & 0x7700770077007700) >> 7);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(14, 15, 13, 12, 10, 11, 9, 8, 2, 3, 1, 0, 6, 7, 5, 4, 30, 31, 29, 28, 26, 27, 25, 24, 18, 19, 17, 16, 22, 23, 21, 20, 46, 47, 45, 44, 42, 43, 41, 40, 34, 35, 33, 32, 38, 39, 37, 36, 62, 63, 61, 60, 58, 59, 57, 56, 50, 51, 49, 48, 54, 55, 53, 52)
void BOGI256_W23(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Shift by mul (1): 16 cycles, 8 masks

	x = ((x & 0x4400440044004400) >> 9)
		| ((x & 0x0030003000300030) << 6)
		| ((x & 0x8800880088008800) >> 11)
		| ((x & 0x3300330033003300) >> 6)
		| ((x & 0x0003000300030003) << 14)
		| (((x & 0x00cc00cc00cc00cc) * 0x0000000000000a0a) & 0x3300330033003300);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(11, 10, 9, 8, 3, 2, 1, 0, 15, 14, 13, 12, 7, 6, 5, 4, 27, 26, 25, 24, 19, 18, 17, 16, 31, 30, 29, 28, 23, 22, 21, 20, 43, 42, 41, 40, 35, 34, 33, 32, 47, 46, 45, 44, 39, 38, 37, 36, 59, 58, 57, 56, 51, 50, 49, 48, 63, 62, 61, 60, 55, 54, 53, 52)
void BOGI256_W24(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 013245/0x0000000000000007: 17 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4, 27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20, 43, 42, 41, 40, 47, 46, 45, 44, 35, 34, 33, 32, 39, 38, 37, 36, 59, 58, 57, 56, 63, 62, 61, 60, 51, 50, 49, 48, 55, 54, 53, 52)
void BOGI256_W25(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000000b: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51)
void BOGI256_W26(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ((x & 0x0fff0fff0fff0fff) << 4)
		| ((x & 0xf000f000f000f000) >> 12);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(8, 9, 10, 11, 12, 13, 14, 15, 4, 5, 6, 7, 0, 1, 2, 3, 24, 25, 26, 27, 28, 29, 30, 31, 20, 21, 22, 23, 16, 17, 18, 19, 40, 41, 42, 43, 44, 45, 46, 47, 36, 37, 38, 39, 32, 33, 34, 35, 56, 57, 58, 59, 60, 61, 62, 63, 52, 53, 54, 55, 48, 49, 50, 51)
void BOGI256_W27(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 6 cycles, 3 masks

	x = ((x & 0x00ff00ff00ff00ff) << 8)
		| ((x & 0xf000f000f000f000) >> 12)
		| ((x & 0x0f000f000f000f00) >> 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19, 44, 45, 46, 47, 40, 41, 42, 43, 36, 37, 38, 39, 32, 33, 34, 35, 60, 61, 62, 63, 56, 57, 58, 59, 52, 53, 54, 55, 48, 49, 50, 51)
void BOGI256_W28(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000000c: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(9, 8, 11, 10, 13, 12, 15, 14, 5, 4, 7, 6, 1, 0, 3, 2, 25, 24, 27, 26, 29, 28, 31, 30, 21, 20, 23, 22, 17, 16, 19, 18, 41, 40, 43, 42, 45, 44, 47, 46, 37, 36, 39, 38, 33, 32, 35, 34, 57, 56, 59, 58, 61, 60, 63, 62, 53, 52, 55, 54, 49, 48, 51, 50)
void BOGI256_W29(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x00aa00aa00aa00aa) << 7)
		| ((x & 0x0055005500550055) << 9)
		| ((x & 0xa000a000a000a000) >> 13)
		| ((x & 0x5000500050005000) >> 11)
		| ((x & 0x0a000a000a000a00) >> 5)
		| ((x & 0x0500050005000500) >> 3);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2, 29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18, 45, 44, 47, 46, 41, 40, 43, 42, 37, 36, 39, 38, 33, 32, 35, 34, 61, 60, 63, 62, 57, 56, 59, 58, 53, 52, 55, 54, 49, 48, 51, 50)
void BOGI256_W2A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000000d: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18, 39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34, 55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50)
void BOGI256_W2B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x0eee0eee0eee0eee) << 3)
		| ((x & 0x0111011101110111) << 7)
		| ((x & 0xe000e000e000e000) >> 13)
		| ((x & 0x1000100010001000) >> 9);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(13, 15, 12, 14, 9, 11, 8, 10, 5, 7, 4, 6, 1, 3, 0, 2, 29, 31, 28, 30, 25, 27, 24, 26, 21, 23, 20, 22, 17, 19, 16, 18, 45, 47, 44, 46, 41, 43, 40, 42, 37, 39, 36, 38, 33, 35, 32, 34, 61, 63, 60, 62, 57, 59, 56, 58, 53, 55, 52, 54, 49, 51, 48, 50)
void BOGI256_W2C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 102345/0x000000000000000e: 17 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(14, 12, 15, 13, 10, 8, 11, 9, 6, 4, 7, 5, 2, 0, 3, 1, 30, 28, 31, 29, 26, 24, 27, 25, 22, 20, 23, 21, 18, 16, 19, 17, 46, 44, 47, 45, 42, 40, 43, 41, 38, 36, 39, 37, 34, 32, 35, 33, 62, 60, 63, 61, 58, 56, 59, 57, 54, 52, 55, 53, 50, 48, 51, 49)
void BOGI256_W2D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 102345/0x000000000000000d: 17 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49)
void BOGI256_W2E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x0ccc0ccc0ccc0ccc) << 2)
		| ((x & 0x0333033303330333) << 6)
		| ((x & 0xc000c000c000c000) >> 14)
		| ((x & 0x3000300030003000) >> 10);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1, 30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33, 62, 63, 60, 61, 58, 59, 56, 57, 54, 55, 52, 53, 50, 51, 48, 49)
void BOGI256_W2F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000000e: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(11, 10, 8, 9, 15, 14, 12, 13, 7, 6, 4, 5, 3, 2, 0, 1, 27, 26, 24, 25, 31, 30, 28, 29, 23, 22, 20, 21, 19, 18, 16, 17, 43, 42, 40, 41, 47, 46, 44, 45, 39, 38, 36, 37, 35, 34, 32, 33, 59, 58, 56, 57, 63, 62, 60, 61, 55, 54, 52, 53, 51, 50, 48, 49)
void BOGI256_W30(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Shift by mul (3) + Rol 58: 17 cycles, 8 masks

	x = ((x & 0xc000c000c000c000) >> 8)
		| (x & 0x0c000c000c000c00)
		| ROL64(x & 0x00cc00cc00cc00cc, 12)
		| ROL64(x & 0x0022002200220022, 15)
		| ROL64(x & 0x0011001100110011, 17)
		| (((ROL64(x, 59) & 0x0198019801980198) * 0x0000000000000505) & 0x3300330033003300);
	x = ROL64(x, 58);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16, 37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32, 53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48)
void BOGI256_W31(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ((x & 0x0888088808880888) << 1)
		| ((x & 0x0777077707770777) << 5)
		| ((x & 0x8000800080008000) >> 15)
		| ((x & 0x7000700070007000) >> 11);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(10, 11, 9, 8, 14, 15, 13, 12, 6, 7, 5, 4, 2, 3, 1, 0, 26, 27, 25, 24, 30, 31, 29, 28, 22, 23, 21, 20, 18, 19, 17, 16, 42, 43, 41, 40, 46, 47, 45, 44, 38, 39, 37, 36, 34, 35, 33, 32, 58, 59, 57, 56, 62, 63, 61, 60, 54, 55, 53, 52, 50, 51, 49, 48)
void BOGI256_W32(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Shift by mul (1) + Rol 54: 17 cycles, 8 masks

	x = (x & 0x3000300030003000)
		| ROL64(x & 0x0300030003000300, 8)
		| ROL64(x & 0x0088008800880088, 15)
		| ROL64(x & 0x0044004400440044, 17)
		| ROL64(x & 0x0033003300330033, 20)
		| (((ROL64(x, 59) & 0x0660066006600660) * 0x0000000000000505) & 0xcc00cc00cc00cc00);
	x = ROL64(x, 54);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48)
void BOGI256_W33(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000000f: 16 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47)
void BOGI256_W34(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000010: 4 cycles, 1 masks

	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47)
void BOGI256_W35(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 1 cycles, 0 masks

	x = ROL64(x, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47)
void BOGI256_W36(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x0000000000000030: 6 cycles, 1 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 49, 48, 51, 50, 53, 52, 55, 54, 57, 56, 59, 58, 61, 60, 63, 62, 33, 32, 35, 34, 37, 36, 39, 38, 41, 40, 43, 42, 45, 44, 47, 46)
void BOGI256_W37(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000011: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30, 35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46)
void BOGI256_W38(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xeeeeeeeeeeeeeeee, 47)
		| ROL64(x & 0x1111111111111111, 51);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(17, 19, 16, 18, 21, 23, 20, 22, 25, 27, 24, 26, 29, 31, 28, 30, 49, 51, 48, 50, 53, 55, 52, 54, 57, 59, 56, 58, 61, 63, 60, 62, 1, 3, 0, 2, 5, 7, 4, 6, 9, 11, 8, 10, 13, 15, 12, 14, 33, 35, 32, 34, 37, 39, 36, 38, 41, 43, 40, 42, 45, 47, 44, 46)
void BOGI256_W39(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x0000000000000032: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(18, 16, 19, 17, 22, 20, 23, 21, 26, 24, 27, 25, 30, 28, 31, 29, 50, 48, 51, 49, 54, 52, 55, 53, 58, 56, 59, 57, 62, 60, 63, 61, 2, 0, 3, 1, 6, 4, 7, 5, 10, 8, 11, 9, 14, 12, 15, 13, 34, 32, 35, 33, 38, 36, 39, 37, 42, 40, 43, 41, 46, 44, 47, 45)
void BOGI256_W3A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x0000000000000031: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45)
void BOGI256_W3B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000012: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45)
void BOGI256_W3C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xcccccccccccccccc, 46)
		| ROL64(x & 0x3333333333333333, 50);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(19, 18, 16, 17, 23, 22, 20, 21, 27, 26, 24, 25, 31, 30, 28, 29, 3, 2, 0, 1, 7, 6, 4, 5, 11, 10, 8, 9, 15, 14, 12, 13, 51, 50, 48, 49, 55, 54, 52, 53, 59, 58, 56, 57, 63, 62, 60, 61, 35, 34, 32, 33, 39, 38, 36, 37, 43, 42, 40, 41, 47, 46, 44, 45)
void BOGI256_W3D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x0000cccc0000cccc) << 14)
		| ((x & 0x0000222200002222) << 17)
		| ((x & 0x0000111100001111) << 19)
		| ((x & 0xcccc0000cccc0000) >> 18)
		| ((x & 0x2222000022220000) >> 15)
		| ((x & 0x1111000011110000) >> 13);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28, 33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44)
void BOGI256_W3E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0x8888888888888888, 45)
		| ROL64(x & 0x7777777777777777, 49);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(18, 19, 17, 16, 22, 23, 21, 20, 26, 27, 25, 24, 30, 31, 29, 28, 2, 3, 1, 0, 6, 7, 5, 4, 10, 11, 9, 8, 14, 15, 13, 12, 50, 51, 49, 48, 54, 55, 53, 52, 58, 59, 57, 56, 62, 63, 61, 60, 34, 35, 33, 32, 38, 39, 37, 36, 42, 43, 41, 40, 46, 47, 45, 44)
void BOGI256_W3F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x0000888800008888) << 13)
		| ((x & 0x0000444400004444) << 15)
		| ((x & 0x0000333300003333) << 18)
		| ((x & 0x8888000088880000) >> 19)
		| ((x & 0x4444000044440000) >> 17)
		| ((x & 0x3333000033330000) >> 14);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 51, 50, 49, 48, 55, 54, 53, 52, 59, 58, 57, 56, 63, 62, 61, 60, 35, 34, 33, 32, 39, 38, 37, 36, 43, 42, 41, 40, 47, 46, 45, 44)
void BOGI256_W40(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000013: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28, 51, 50, 49, 48, 55, 54, 53, 52, 59, 58, 57, 56, 63, 62, 61, 60, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 35, 34, 33, 32, 39, 38, 37, 36, 43, 42, 41, 40, 47, 46, 45, 44)
void BOGI256_W41(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x0000000000000033: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 52, 53, 54, 55, 48, 49, 50, 51, 60, 61, 62, 63, 56, 57, 58, 59, 36, 37, 38, 39, 32, 33, 34, 35, 44, 45, 46, 47, 40, 41, 42, 43)
void BOGI256_W42(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000014: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43)
void BOGI256_W43(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xfff0fff0fff0fff0, 44)
		| ROL64(x & 0x000f000f000f000f, 60);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(20, 21, 22, 23, 28, 29, 30, 31, 16, 17, 18, 19, 24, 25, 26, 27, 52, 53, 54, 55, 60, 61, 62, 63, 48, 49, 50, 51, 56, 57, 58, 59, 4, 5, 6, 7, 12, 13, 14, 15, 0, 1, 2, 3, 8, 9, 10, 11, 36, 37, 38, 39, 44, 45, 46, 47, 32, 33, 34, 35, 40, 41, 42, 43)
void BOGI256_W44(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x0000000000000038: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10, 53, 52, 55, 54, 49, 48, 51, 50, 61, 60, 63, 62, 57, 56, 59, 58, 37, 36, 39, 38, 33, 32, 35, 34, 45, 44, 47, 46, 41, 40, 43, 42)
void BOGI256_W45(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000015: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26, 47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42)
void BOGI256_W46(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xeee0eee0eee0eee0, 43)
		| ROL64(x & 0x1110111011101110, 47)
		| ROL64(x & 0x000e000e000e000e, 59)
		| ROL64(x & 0x0001000100010001, 63);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(21, 23, 20, 22, 29, 31, 28, 30, 17, 19, 16, 18, 25, 27, 24, 26, 53, 55, 52, 54, 61, 63, 60, 62, 49, 51, 48, 50, 57, 59, 56, 58, 5, 7, 4, 6, 13, 15, 12, 14, 1, 3, 0, 2, 9, 11, 8, 10, 37, 39, 36, 38, 45, 47, 44, 46, 33, 35, 32, 34, 41, 43, 40, 42)
void BOGI256_W47(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x000000000000003a: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(22, 20, 23, 21, 30, 28, 31, 29, 18, 16, 19, 17, 26, 24, 27, 25, 54, 52, 55, 53, 62, 60, 63, 61, 50, 48, 51, 49, 58, 56, 59, 57, 6, 4, 7, 5, 14, 12, 15, 13, 2, 0, 3, 1, 10, 8, 11, 9, 38, 36, 39, 37, 46, 44, 47, 45, 34, 32, 35, 33, 42, 40, 43, 41)
void BOGI256_W48(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x0000000000000039: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25, 6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9, 54, 55, 52, 53, 50, 51, 48, 49, 62, 63, 60, 61, 58, 59, 56, 57, 38, 39, 36, 37, 34, 35, 32, 33, 46, 47, 44, 45, 42, 43, 40, 41)
void BOGI256_W49(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000016: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41)
void BOGI256_W4A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xccc0ccc0ccc0ccc0, 42)
		| ROL64(x & 0x3330333033303330, 46)
		| ROL64(x & 0x000c000c000c000c, 58)
		| ROL64(x & 0x0003000300030003, 62);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(23, 22, 20, 21, 19, 18, 16, 17, 31, 30, 28, 29, 27, 26, 24, 25, 7, 6, 4, 5, 3, 2, 0, 1, 15, 14, 12, 13, 11, 10, 8, 9, 55, 54, 52, 53, 51, 50, 48, 49, 63, 62, 60, 61, 59, 58, 56, 57, 39, 38, 36, 37, 35, 34, 32, 33, 47, 46, 44, 45, 43, 42, 40, 41)
void BOGI256_W4B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 17 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x1111111111111111, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24, 45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40)
void BOGI256_W4C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8880888088808880, 41)
		| ROL64(x & 0x7770777077707770, 45)
		| ROL64(x & 0x0008000800080008, 57)
		| ROL64(x & 0x0007000700070007, 61);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(22, 23, 21, 20, 18, 19, 17, 16, 30, 31, 29, 28, 26, 27, 25, 24, 6, 7, 5, 4, 2, 3, 1, 0, 14, 15, 13, 12, 10, 11, 9, 8, 54, 55, 53, 52, 50, 51, 49, 48, 62, 63, 61, 60, 58, 59, 57, 56, 38, 39, 37, 36, 34, 35, 33, 32, 46, 47, 45, 44, 42, 43, 41, 40)
void BOGI256_W4D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 17 cycles, 4 masks

	bit_permute_step_64(&x, x, 0x4444444444444444, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56, 39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40)
void BOGI256_W4E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000017: 16 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(23, 22, 21, 20, 31, 30, 29, 28, 19, 18, 17, 16, 27, 26, 25, 24, 55, 54, 53, 52, 63, 62, 61, 60, 51, 50, 49, 48, 59, 58, 57, 56, 7, 6, 5, 4, 15, 14, 13, 12, 3, 2, 1, 0, 11, 10, 9, 8, 39, 38, 37, 36, 47, 46, 45, 44, 35, 34, 33, 32, 43, 42, 41, 40)
void BOGI256_W4F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x000000000000003b: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(24, 25, 26, 27, 16, 17, 18, 19, 28, 29, 30, 31, 20, 21, 22, 23, 56, 57, 58, 59, 48, 49, 50, 51, 60, 61, 62, 63, 52, 53, 54, 55, 8, 9, 10, 11, 0, 1, 2, 3, 12, 13, 14, 15, 4, 5, 6, 7, 40, 41, 42, 43, 32, 33, 34, 35, 44, 45, 46, 47, 36, 37, 38, 39)
void BOGI256_W50(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x0000000000000034: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39)
void BOGI256_W51(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000018: 8 cycles, 2 masks

	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39)
void BOGI256_W52(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xff00ff00ff00ff00, 40)
		| ROL64(x & 0x00ff00ff00ff00ff, 56);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(28, 29, 30, 31, 24, 25, 26, 27, 16, 17, 18, 19, 20, 21, 22, 23, 12, 13, 14, 15, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 60, 61, 62, 63, 56, 57, 58, 59, 48, 49, 50, 51, 52, 53, 54, 55, 44, 45, 46, 47, 40, 41, 42, 43, 32, 33, 34, 35, 36, 37, 38, 39)
void BOGI256_W53(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x0000ff000000ff00) << 8)
		| ((x & 0x000000f0000000f0) << 20)
		| ((x & 0x0000000f0000000f) << 28)
		| ((x & 0xff000000ff000000) >> 24)
		| ((x & 0x00f0000000f00000) >> 12)
		| ((x & 0x000f0000000f0000) >> 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22, 9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6, 57, 56, 59, 58, 61, 60, 63, 62, 49, 48, 51, 50, 53, 52, 55, 54, 41, 40, 43, 42, 45, 44, 47, 46, 33, 32, 35, 34, 37, 36, 39, 38)
void BOGI256_W54(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x0000000000000019: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(29, 28, 31, 30, 25, 24, 27, 26, 17, 16, 19, 18, 21, 20, 23, 22, 13, 12, 15, 14, 9, 8, 11, 10, 1, 0, 3, 2, 5, 4, 7, 6, 61, 60, 63, 62, 57, 56, 59, 58, 49, 48, 51, 50, 53, 52, 55, 54, 45, 44, 47, 46, 41, 40, 43, 42, 33, 32, 35, 34, 37, 36, 39, 38)
void BOGI256_W55(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 17 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22, 43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38)
void BOGI256_W56(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xee00ee00ee00ee00, 39)
		| ROL64(x & 0x1100110011001100, 43)
		| ROL64(x & 0x00ee00ee00ee00ee, 55)
		| ROL64(x & 0x0011001100110011, 59);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(25, 27, 24, 26, 17, 19, 16, 18, 29, 31, 28, 30, 21, 23, 20, 22, 57, 59, 56, 58, 49, 51, 48, 50, 61, 63, 60, 62, 53, 55, 52, 54, 9, 11, 8, 10, 1, 3, 0, 2, 13, 15, 12, 14, 5, 7, 4, 6, 41, 43, 40, 42, 33, 35, 32, 34, 45, 47, 44, 46, 37, 39, 36, 38)
void BOGI256_W57(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x0000000000000036: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(26, 24, 27, 25, 18, 16, 19, 17, 30, 28, 31, 29, 22, 20, 23, 21, 58, 56, 59, 57, 50, 48, 51, 49, 62, 60, 63, 61, 54, 52, 55, 53, 10, 8, 11, 9, 2, 0, 3, 1, 14, 12, 15, 13, 6, 4, 7, 5, 42, 40, 43, 41, 34, 32, 35, 33, 46, 44, 47, 45, 38, 36, 39, 37)
void BOGI256_W58(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x0000000000000035: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37)
void BOGI256_W59(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000001a: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37)
void BOGI256_W5A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xcc00cc00cc00cc00, 38)
		| ROL64(x & 0x3300330033003300, 42)
		| ROL64(x & 0x00cc00cc00cc00cc, 54)
		| ROL64(x & 0x0033003300330033, 58);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(31, 30, 28, 29, 27, 26, 24, 25, 19, 18, 16, 17, 23, 22, 20, 21, 15, 14, 12, 13, 11, 10, 8, 9, 3, 2, 0, 1, 7, 6, 4, 5, 63, 62, 60, 61, 59, 58, 56, 57, 51, 50, 48, 49, 55, 54, 52, 53, 47, 46, 44, 45, 43, 42, 40, 41, 35, 34, 32, 33, 39, 38, 36, 37)
void BOGI256_W5B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 22 cycles, 5 masks

	bit_permute_step_64(&x, x, 0x1111111111111111, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20, 41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36)
void BOGI256_W5C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8800880088008800, 37)
		| ROL64(x & 0x7700770077007700, 41)
		| ROL64(x & 0x0088008800880088, 53)
		| ROL64(x & 0x0077007700770077, 57);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(30, 31, 29, 28, 26, 27, 25, 24, 18, 19, 17, 16, 22, 23, 21, 20, 14, 15, 13, 12, 10, 11, 9, 8, 2, 3, 1, 0, 6, 7, 5, 4, 62, 63, 61, 60, 58, 59, 57, 56, 50, 51, 49, 48, 54, 55, 53, 52, 46, 47, 45, 44, 42, 43, 41, 40, 34, 35, 33, 32, 38, 39, 37, 36)
void BOGI256_W5D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 22 cycles, 5 masks

	bit_permute_step_64(&x, x, 0x4444444444444444, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(27, 26, 25, 24, 19, 18, 17, 16, 31, 30, 29, 28, 23, 22, 21, 20, 59, 58, 57, 56, 51, 50, 49, 48, 63, 62, 61, 60, 55, 54, 53, 52, 11, 10, 9, 8, 3, 2, 1, 0, 15, 14, 13, 12, 7, 6, 5, 4, 43, 42, 41, 40, 35, 34, 33, 32, 47, 46, 45, 44, 39, 38, 37, 36)
void BOGI256_W5E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x0000000000000037: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20, 11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4, 59, 58, 57, 56, 63, 62, 61, 60, 51, 50, 49, 48, 55, 54, 53, 52, 43, 42, 41, 40, 47, 46, 45, 44, 35, 34, 33, 32, 39, 38, 37, 36)
void BOGI256_W5F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000001b: 16 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35)
void BOGI256_W60(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xf000f000f000f000, 36)
		| ROL64(x & 0x0fff0fff0fff0fff, 52);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(24, 25, 26, 27, 28, 29, 30, 31, 20, 21, 22, 23, 16, 17, 18, 19, 8, 9, 10, 11, 12, 13, 14, 15, 4, 5, 6, 7, 0, 1, 2, 3, 56, 57, 58, 59, 60, 61, 62, 63, 52, 53, 54, 55, 48, 49, 50, 51, 40, 41, 42, 43, 44, 45, 46, 47, 36, 37, 38, 39, 32, 33, 34, 35)
void BOGI256_W61(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 12 cycles, 6 masks

	x = ((x & 0x0000f0000000f000) << 4)
		| ((x & 0x00000f0000000f00) << 12)
		| ((x & 0x000000ff000000ff) << 24)
		| ((x & 0xf0000000f0000000) >> 28)
		| ((x & 0x0f0000000f000000) >> 20)
		| ((x & 0x00ff000000ff0000) >> 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 60, 61, 62, 63, 56, 57, 58, 59, 52, 53, 54, 55, 48, 49, 50, 51, 44, 45, 46, 47, 40, 41, 42, 43, 36, 37, 38, 39, 32, 33, 34, 35)
void BOGI256_W62(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000001c: 12 cycles, 3 masks

	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19, 60, 61, 62, 63, 56, 57, 58, 59, 52, 53, 54, 55, 48, 49, 50, 51, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 44, 45, 46, 47, 40, 41, 42, 43, 36, 37, 38, 39, 32, 33, 34, 35)
void BOGI256_W63(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x000000000000003c: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(25, 24, 27, 26, 29, 28, 31, 30, 21, 20, 23, 22, 17, 16, 19, 18, 9, 8, 11, 10, 13, 12, 15, 14, 5, 4, 7, 6, 1, 0, 3, 2, 57, 56, 59, 58, 61, 60, 63, 62, 53, 52, 55, 54, 49, 48, 51, 50, 41, 40, 43, 42, 45, 44, 47, 46, 37, 36, 39, 38, 33, 32, 35, 34)
void BOGI256_W64(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 17 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18, 13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2, 61, 60, 63, 62, 57, 56, 59, 58, 53, 52, 55, 54, 49, 48, 51, 50, 45, 44, 47, 46, 41, 40, 43, 42, 37, 36, 39, 38, 33, 32, 35, 34)
void BOGI256_W65(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000001d: 16 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18, 39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34)
void BOGI256_W66(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xe000e000e000e000, 35)
		| ROL64(x & 0x1000100010001000, 39)
		| ROL64(x & 0x0eee0eee0eee0eee, 51)
		| ROL64(x & 0x0111011101110111, 55);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(29, 31, 28, 30, 25, 27, 24, 26, 21, 23, 20, 22, 17, 19, 16, 18, 61, 63, 60, 62, 57, 59, 56, 58, 53, 55, 52, 54, 49, 51, 48, 50, 13, 15, 12, 14, 9, 11, 8, 10, 5, 7, 4, 6, 1, 3, 0, 2, 45, 47, 44, 46, 41, 43, 40, 42, 37, 39, 36, 38, 33, 35, 32, 34)
void BOGI256_W67(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x000000000000003e: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(30, 28, 31, 29, 26, 24, 27, 25, 22, 20, 23, 21, 18, 16, 19, 17, 62, 60, 63, 61, 58, 56, 59, 57, 54, 52, 55, 53, 50, 48, 51, 49, 14, 12, 15, 13, 10, 8, 11, 9, 6, 4, 7, 5, 2, 0, 3, 1, 46, 44, 47, 45, 42, 40, 43, 41, 38, 36, 39, 37, 34, 32, 35, 33)
void BOGI256_W68(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x000000000000003d: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33)
void BOGI256_W69(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xc000c000c000c000, 34)
		| ROL64(x & 0x3000300030003000, 38)
		| ROL64(x & 0x0ccc0ccc0ccc0ccc, 50)
		| ROL64(x & 0x0333033303330333, 54);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1, 62, 63, 60, 61, 58, 59, 56, 57, 54, 55, 52, 53, 50, 51, 48, 49, 46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33)
void BOGI256_W6A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000001e: 16 cycles, 4 masks

	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(27, 26, 24, 25, 31, 30, 28, 29, 23, 22, 20, 21, 19, 18, 16, 17, 11, 10, 8, 9, 15, 14, 12, 13, 7, 6, 4, 5, 3, 2, 0, 1, 59, 58, 56, 57, 63, 62, 60, 61, 55, 54, 52, 53, 51, 50, 48, 49, 43, 42, 40, 41, 47, 46, 44, 45, 39, 38, 36, 37, 35, 34, 32, 33)
void BOGI256_W6B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 22 cycles, 5 masks

	bit_permute_step_64(&x, x, 0x1111111111111111, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16, 37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32)
void BOGI256_W6C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8000800080008000, 33)
		| ROL64(x & 0x7000700070007000, 37)
		| ROL64(x & 0x0888088808880888, 49)
		| ROL64(x & 0x0777077707770777, 53);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(26, 27, 25, 24, 30, 31, 29, 28, 22, 23, 21, 20, 18, 19, 17, 16, 10, 11, 9, 8, 14, 15, 13, 12, 6, 7, 5, 4, 2, 3, 1, 0, 58, 59, 57, 56, 62, 63, 61, 60, 54, 55, 53, 52, 50, 51, 49, 48, 42, 43, 41, 40, 46, 47, 45, 44, 38, 39, 37, 36, 34, 35, 33, 32)
void BOGI256_W6D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Benes 543210: 22 cycles, 5 masks

	bit_permute_step_64(&x, x, 0x4444444444444444, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32)
void BOGI256_W6E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//BPC permutation 012345/0x000000000000001f: 20 cycles, 5 masks

	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32)
void BOGI256_W6F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x000000000000003f: 22 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
void BOGI256_W70(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x0000000000000000: 6 cycles, 1 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
void BOGI256_W71(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 1 cycles, 0 masks

	x = ROL64(x, 32);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
void BOGI256_W72(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 6 cycles, 1 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(33, 32, 35, 34, 37, 36, 39, 38, 41, 40, 43, 42, 45, 44, 47, 46, 49, 48, 51, 50, 53, 52, 55, 54, 57, 56, 59, 58, 61, 60, 63, 62, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30)
void BOGI256_W73(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xaaaaaaaaaaaaaaaa, 31)
		| ROL64(x & 0x5555555555555555, 33);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(49, 48, 51, 50, 53, 52, 55, 54, 57, 56, 59, 58, 61, 60, 63, 62, 33, 32, 35, 34, 37, 36, 39, 38, 41, 40, 43, 42, 45, 44, 47, 46, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30)
void BOGI256_W74(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 10 cycles, 2 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46, 51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30)
void BOGI256_W75(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xeeeeeeeeeeeeeeee, 31)
		| ROL64(x & 0x1111111111111111, 35);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(33, 35, 32, 34, 37, 39, 36, 38, 41, 43, 40, 42, 45, 47, 44, 46, 1, 3, 0, 2, 5, 7, 4, 6, 9, 11, 8, 10, 13, 15, 12, 14, 49, 51, 48, 50, 53, 55, 52, 54, 57, 59, 56, 58, 61, 63, 60, 62, 17, 19, 16, 18, 21, 23, 20, 22, 25, 27, 24, 26, 29, 31, 28, 30)
void BOGI256_W76(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x0000000000000002: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(34, 32, 35, 33, 38, 36, 39, 37, 42, 40, 43, 41, 46, 44, 47, 45, 2, 0, 3, 1, 6, 4, 7, 5, 10, 8, 11, 9, 14, 12, 15, 13, 50, 48, 51, 49, 54, 52, 55, 53, 58, 56, 59, 57, 62, 60, 63, 61, 18, 16, 19, 17, 22, 20, 23, 21, 26, 24, 27, 25, 30, 28, 31, 29)
void BOGI256_W77(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x0000000000000001: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29)
void BOGI256_W78(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xcccccccccccccccc, 30)
		| ROL64(x & 0x3333333333333333, 34);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(51, 50, 48, 49, 55, 54, 52, 53, 59, 58, 56, 57, 63, 62, 60, 61, 35, 34, 32, 33, 39, 38, 36, 37, 43, 42, 40, 41, 47, 46, 44, 45, 3, 2, 0, 1, 7, 6, 4, 5, 11, 10, 8, 9, 15, 14, 12, 13, 19, 18, 16, 17, 23, 22, 20, 21, 27, 26, 24, 25, 31, 30, 28, 29)
void BOGI256_W79(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44, 49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28)
void BOGI256_W7A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0x8888888888888888, 29)
		| ROL64(x & 0x7777777777777777, 33);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(50, 51, 49, 48, 54, 55, 53, 52, 58, 59, 57, 56, 62, 63, 61, 60, 34, 35, 33, 32, 38, 39, 37, 36, 42, 43, 41, 40, 46, 47, 45, 44, 2, 3, 1, 0, 6, 7, 5, 4, 10, 11, 9, 8, 14, 15, 13, 12, 18, 19, 17, 16, 22, 23, 21, 20, 26, 27, 25, 24, 30, 31, 29, 28)
void BOGI256_W7B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(35, 34, 33, 32, 39, 38, 37, 36, 43, 42, 41, 40, 47, 46, 45, 44, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 51, 50, 49, 48, 55, 54, 53, 52, 59, 58, 57, 56, 63, 62, 61, 60, 19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28)
void BOGI256_W7C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x0000000000000003: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(35, 34, 33, 32, 39, 38, 37, 36, 43, 42, 41, 40, 47, 46, 45, 44, 51, 50, 49, 48, 55, 54, 53, 52, 59, 58, 57, 56, 63, 62, 61, 60, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28)
void BOGI256_W7D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8888888888888888, 29)
		| ROL64(x & 0x4444444444444444, 31)
		| ROL64(x & 0x2222222222222222, 33)
		| ROL64(x & 0x1111111111111111, 35);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(36, 37, 38, 39, 32, 33, 34, 35, 44, 45, 46, 47, 40, 41, 42, 43, 52, 53, 54, 55, 48, 49, 50, 51, 60, 61, 62, 63, 56, 57, 58, 59, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27)
void BOGI256_W7E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xf0f0f0f0f0f0f0f0, 28)
		| ROL64(x & 0x0f0f0f0f0f0f0f0f, 36);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(52, 53, 54, 55, 48, 49, 50, 51, 60, 61, 62, 63, 56, 57, 58, 59, 36, 37, 38, 39, 32, 33, 34, 35, 44, 45, 46, 47, 40, 41, 42, 43, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27)
void BOGI256_W7F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 10 cycles, 2 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27)
void BOGI256_W80(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xfff0fff0fff0fff0, 28)
		| ROL64(x & 0x000f000f000f000f, 44);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(36, 37, 38, 39, 44, 45, 46, 47, 32, 33, 34, 35, 40, 41, 42, 43, 4, 5, 6, 7, 12, 13, 14, 15, 0, 1, 2, 3, 8, 9, 10, 11, 52, 53, 54, 55, 60, 61, 62, 63, 48, 49, 50, 51, 56, 57, 58, 59, 20, 21, 22, 23, 28, 29, 30, 31, 16, 17, 18, 19, 24, 25, 26, 27)
void BOGI256_W81(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x0000000000000008: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(37, 36, 39, 38, 33, 32, 35, 34, 45, 44, 47, 46, 41, 40, 43, 42, 53, 52, 55, 54, 49, 48, 51, 50, 61, 60, 63, 62, 57, 56, 59, 58, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26)
void BOGI256_W82(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xa0a0a0a0a0a0a0a0, 27)
		| ROL64(x & 0x5050505050505050, 29)
		| ROL64(x & 0x0a0a0a0a0a0a0a0a, 35)
		| ROL64(x & 0x0505050505050505, 37);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(53, 52, 55, 54, 49, 48, 51, 50, 61, 60, 63, 62, 57, 56, 59, 58, 37, 36, 39, 38, 33, 32, 35, 34, 45, 44, 47, 46, 41, 40, 43, 42, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26)
void BOGI256_W83(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42, 63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26)
void BOGI256_W84(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xeee0eee0eee0eee0, 27)
		| ROL64(x & 0x1110111011101110, 31)
		| ROL64(x & 0x000e000e000e000e, 43)
		| ROL64(x & 0x0001000100010001, 47);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(37, 39, 36, 38, 45, 47, 44, 46, 33, 35, 32, 34, 41, 43, 40, 42, 5, 7, 4, 6, 13, 15, 12, 14, 1, 3, 0, 2, 9, 11, 8, 10, 53, 55, 52, 54, 61, 63, 60, 62, 49, 51, 48, 50, 57, 59, 56, 58, 21, 23, 20, 22, 29, 31, 28, 30, 17, 19, 16, 18, 25, 27, 24, 26)
void BOGI256_W85(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x000000000000000a: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(38, 36, 39, 37, 46, 44, 47, 45, 34, 32, 35, 33, 42, 40, 43, 41, 6, 4, 7, 5, 14, 12, 15, 13, 2, 0, 3, 1, 10, 8, 11, 9, 54, 52, 55, 53, 62, 60, 63, 61, 50, 48, 51, 49, 58, 56, 59, 57, 22, 20, 23, 21, 30, 28, 31, 29, 18, 16, 19, 17, 26, 24, 27, 25)
void BOGI256_W86(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x0000000000000009: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(38, 39, 36, 37, 34, 35, 32, 33, 46, 47, 44, 45, 42, 43, 40, 41, 54, 55, 52, 53, 50, 51, 48, 49, 62, 63, 60, 61, 58, 59, 56, 57, 6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9, 22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25)
void BOGI256_W87(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xc0c0c0c0c0c0c0c0, 26)
		| ROL64(x & 0x3030303030303030, 30)
		| ROL64(x & 0x0c0c0c0c0c0c0c0c, 34)
		| ROL64(x & 0x0303030303030303, 38);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25)
void BOGI256_W88(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xccc0ccc0ccc0ccc0, 26)
		| ROL64(x & 0x3330333033303330, 30)
		| ROL64(x & 0x000c000c000c000c, 42)
		| ROL64(x & 0x0003000300030003, 46);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(55, 54, 52, 53, 51, 50, 48, 49, 63, 62, 60, 61, 59, 58, 56, 57, 39, 38, 36, 37, 35, 34, 32, 33, 47, 46, 44, 45, 43, 42, 40, 41, 7, 6, 4, 5, 3, 2, 0, 1, 15, 14, 12, 13, 11, 10, 8, 9, 23, 22, 20, 21, 19, 18, 16, 17, 31, 30, 28, 29, 27, 26, 24, 25)
void BOGI256_W89(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40, 61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24)
void BOGI256_W8A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8880888088808880, 25)
		| ROL64(x & 0x7770777077707770, 29)
		| ROL64(x & 0x0008000800080008, 41)
		| ROL64(x & 0x0007000700070007, 45);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(54, 55, 53, 52, 50, 51, 49, 48, 62, 63, 61, 60, 58, 59, 57, 56, 38, 39, 37, 36, 34, 35, 33, 32, 46, 47, 45, 44, 42, 43, 41, 40, 6, 7, 5, 4, 2, 3, 1, 0, 14, 15, 13, 12, 10, 11, 9, 8, 22, 23, 21, 20, 18, 19, 17, 16, 30, 31, 29, 28, 26, 27, 25, 24)
void BOGI256_W8B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40, 55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24)
void BOGI256_W8C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x0000000000000007: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(39, 38, 37, 36, 47, 46, 45, 44, 35, 34, 33, 32, 43, 42, 41, 40, 7, 6, 5, 4, 15, 14, 13, 12, 3, 2, 1, 0, 11, 10, 9, 8, 55, 54, 53, 52, 63, 62, 61, 60, 51, 50, 49, 48, 59, 58, 57, 56, 23, 22, 21, 20, 31, 30, 29, 28, 19, 18, 17, 16, 27, 26, 25, 24)
void BOGI256_W8D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x000000000000000b: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(40, 41, 42, 43, 32, 33, 34, 35, 44, 45, 46, 47, 36, 37, 38, 39, 8, 9, 10, 11, 0, 1, 2, 3, 12, 13, 14, 15, 4, 5, 6, 7, 56, 57, 58, 59, 48, 49, 50, 51, 60, 61, 62, 63, 52, 53, 54, 55, 24, 25, 26, 27, 16, 17, 18, 19, 28, 29, 30, 31, 20, 21, 22, 23)
void BOGI256_W8E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x0000000000000004: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23)
void BOGI256_W8F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xff00ff00ff00ff00, 24)
		| ROL64(x & 0x00ff00ff00ff00ff, 40);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(60, 61, 62, 63, 56, 57, 58, 59, 48, 49, 50, 51, 52, 53, 54, 55, 44, 45, 46, 47, 40, 41, 42, 43, 32, 33, 34, 35, 36, 37, 38, 39, 12, 13, 14, 15, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 28, 29, 30, 31, 24, 25, 26, 27, 16, 17, 18, 19, 20, 21, 22, 23)
void BOGI256_W90(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(41, 40, 43, 42, 45, 44, 47, 46, 33, 32, 35, 34, 37, 36, 39, 38, 57, 56, 59, 58, 61, 60, 63, 62, 49, 48, 51, 50, 53, 52, 55, 54, 9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6, 25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22)
void BOGI256_W91(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xaa00aa00aa00aa00, 23)
		| ROL64(x & 0x5500550055005500, 25)
		| ROL64(x & 0x00aa00aa00aa00aa, 39)
		| ROL64(x & 0x0055005500550055, 41);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(61, 60, 63, 62, 57, 56, 59, 58, 49, 48, 51, 50, 53, 52, 55, 54, 45, 44, 47, 46, 41, 40, 43, 42, 33, 32, 35, 34, 37, 36, 39, 38, 13, 12, 15, 14, 9, 8, 11, 10, 1, 0, 3, 2, 5, 4, 7, 6, 29, 28, 31, 30, 25, 24, 27, 26, 17, 16, 19, 18, 21, 20, 23, 22)
void BOGI256_W92(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38, 59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22)
void BOGI256_W93(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xee00ee00ee00ee00, 23)
		| ROL64(x & 0x1100110011001100, 27)
		| ROL64(x & 0x00ee00ee00ee00ee, 39)
		| ROL64(x & 0x0011001100110011, 43);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(41, 43, 40, 42, 33, 35, 32, 34, 45, 47, 44, 46, 37, 39, 36, 38, 9, 11, 8, 10, 1, 3, 0, 2, 13, 15, 12, 14, 5, 7, 4, 6, 57, 59, 56, 58, 49, 51, 48, 50, 61, 63, 60, 62, 53, 55, 52, 54, 25, 27, 24, 26, 17, 19, 16, 18, 29, 31, 28, 30, 21, 23, 20, 22)
void BOGI256_W94(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x0000000000000006: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(42, 40, 43, 41, 34, 32, 35, 33, 46, 44, 47, 45, 38, 36, 39, 37, 10, 8, 11, 9, 2, 0, 3, 1, 14, 12, 15, 13, 6, 4, 7, 5, 58, 56, 59, 57, 50, 48, 51, 49, 62, 60, 63, 61, 54, 52, 55, 53, 26, 24, 27, 25, 18, 16, 19, 17, 30, 28, 31, 29, 22, 20, 23, 21)
void BOGI256_W95(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103254/0x0000000000000005: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21)
void BOGI256_W96(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xcc00cc00cc00cc00, 22)
		| ROL64(x & 0x3300330033003300, 26)
		| ROL64(x & 0x00cc00cc00cc00cc, 38)
		| ROL64(x & 0x0033003300330033, 42);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(63, 62, 60, 61, 59, 58, 56, 57, 51, 50, 48, 49, 55, 54, 52, 53, 47, 46, 44, 45, 43, 42, 40, 41, 35, 34, 32, 33, 39, 38, 36, 37, 15, 14, 12, 13, 11, 10, 8, 9, 3, 2, 0, 1, 7, 6, 4, 5, 31, 30, 28, 29, 27, 26, 24, 25, 19, 18, 16, 17, 23, 22, 20, 21)
void BOGI256_W97(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36, 57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20)
void BOGI256_W98(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8800880088008800, 21)
		| ROL64(x & 0x7700770077007700, 25)
		| ROL64(x & 0x0088008800880088, 37)
		| ROL64(x & 0x0077007700770077, 41);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(62, 63, 61, 60, 58, 59, 57, 56, 50, 51, 49, 48, 54, 55, 53, 52, 46, 47, 45, 44, 42, 43, 41, 40, 34, 35, 33, 32, 38, 39, 37, 36, 14, 15, 13, 12, 10, 11, 9, 8, 2, 3, 1, 0, 6, 7, 5, 4, 30, 31, 29, 28, 26, 27, 25, 24, 18, 19, 17, 16, 22, 23, 21, 20)
void BOGI256_W99(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(43, 42, 41, 40, 35, 34, 33, 32, 47, 46, 45, 44, 39, 38, 37, 36, 11, 10, 9, 8, 3, 2, 1, 0, 15, 14, 13, 12, 7, 6, 5, 4, 59, 58, 57, 56, 51, 50, 49, 48, 63, 62, 61, 60, 55, 54, 53, 52, 27, 26, 25, 24, 19, 18, 17, 16, 31, 30, 29, 28, 23, 22, 21, 20)
void BOGI256_W9A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013254/0x0000000000000007: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(43, 42, 41, 40, 47, 46, 45, 44, 35, 34, 33, 32, 39, 38, 37, 36, 59, 58, 57, 56, 63, 62, 61, 60, 51, 50, 49, 48, 55, 54, 53, 52, 11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4, 27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20)
void BOGI256_W9B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000000b: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19)
void BOGI256_W9C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xf000f000f000f000, 20)
		| ROL64(x & 0x0fff0fff0fff0fff, 36);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(56, 57, 58, 59, 60, 61, 62, 63, 52, 53, 54, 55, 48, 49, 50, 51, 40, 41, 42, 43, 44, 45, 46, 47, 36, 37, 38, 39, 32, 33, 34, 35, 8, 9, 10, 11, 12, 13, 14, 15, 4, 5, 6, 7, 0, 1, 2, 3, 24, 25, 26, 27, 28, 29, 30, 31, 20, 21, 22, 23, 16, 17, 18, 19)
void BOGI256_W9D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(44, 45, 46, 47, 40, 41, 42, 43, 36, 37, 38, 39, 32, 33, 34, 35, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 60, 61, 62, 63, 56, 57, 58, 59, 52, 53, 54, 55, 48, 49, 50, 51, 28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19)
void BOGI256_W9E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x000000000000000c: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(44, 45, 46, 47, 40, 41, 42, 43, 36, 37, 38, 39, 32, 33, 34, 35, 60, 61, 62, 63, 56, 57, 58, 59, 52, 53, 54, 55, 48, 49, 50, 51, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19)
void BOGI256_W9F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xf000f000f000f000, 20)
		| ROL64(x & 0x0f000f000f000f00, 28)
		| ROL64(x & 0x00f000f000f000f0, 36)
		| ROL64(x & 0x000f000f000f000f, 44);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(57, 56, 59, 58, 61, 60, 63, 62, 53, 52, 55, 54, 49, 48, 51, 50, 41, 40, 43, 42, 45, 44, 47, 46, 37, 36, 39, 38, 33, 32, 35, 34, 9, 8, 11, 10, 13, 12, 15, 14, 5, 4, 7, 6, 1, 0, 3, 2, 25, 24, 27, 26, 29, 28, 31, 30, 21, 20, 23, 22, 17, 16, 19, 18)
void BOGI256_WA0(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(45, 44, 47, 46, 41, 40, 43, 42, 37, 36, 39, 38, 33, 32, 35, 34, 61, 60, 63, 62, 57, 56, 59, 58, 53, 52, 55, 54, 49, 48, 51, 50, 13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2, 29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18)
void BOGI256_WA1(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000000d: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34, 55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18)
void BOGI256_WA2(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xe000e000e000e000, 19)
		| ROL64(x & 0x1000100010001000, 23)
		| ROL64(x & 0x0eee0eee0eee0eee, 35)
		| ROL64(x & 0x0111011101110111, 39);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(45, 47, 44, 46, 41, 43, 40, 42, 37, 39, 36, 38, 33, 35, 32, 34, 13, 15, 12, 14, 9, 11, 8, 10, 5, 7, 4, 6, 1, 3, 0, 2, 61, 63, 60, 62, 57, 59, 56, 58, 53, 55, 52, 54, 49, 51, 48, 50, 29, 31, 28, 30, 25, 27, 24, 26, 21, 23, 20, 22, 17, 19, 16, 18)
void BOGI256_WA3(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x000000000000000e: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(46, 44, 47, 45, 42, 40, 43, 41, 38, 36, 39, 37, 34, 32, 35, 33, 14, 12, 15, 13, 10, 8, 11, 9, 6, 4, 7, 5, 2, 0, 3, 1, 62, 60, 63, 61, 58, 56, 59, 57, 54, 52, 55, 53, 50, 48, 51, 49, 30, 28, 31, 29, 26, 24, 27, 25, 22, 20, 23, 21, 18, 16, 19, 17)
void BOGI256_WA4(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102354/0x000000000000000d: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17)
void BOGI256_WA5(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xc000c000c000c000, 18)
		| ROL64(x & 0x3000300030003000, 22)
		| ROL64(x & 0x0ccc0ccc0ccc0ccc, 34)
		| ROL64(x & 0x0333033303330333, 38);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33, 62, 63, 60, 61, 58, 59, 56, 57, 54, 55, 52, 53, 50, 51, 48, 49, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1, 30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17)
void BOGI256_WA6(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000000e: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(59, 58, 56, 57, 63, 62, 60, 61, 55, 54, 52, 53, 51, 50, 48, 49, 43, 42, 40, 41, 47, 46, 44, 45, 39, 38, 36, 37, 35, 34, 32, 33, 11, 10, 8, 9, 15, 14, 12, 13, 7, 6, 4, 5, 3, 2, 0, 1, 27, 26, 24, 25, 31, 30, 28, 29, 23, 22, 20, 21, 19, 18, 16, 17)
void BOGI256_WA7(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32, 53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16)
void BOGI256_WA8(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8000800080008000, 17)
		| ROL64(x & 0x7000700070007000, 21)
		| ROL64(x & 0x0888088808880888, 33)
		| ROL64(x & 0x0777077707770777, 37);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(58, 59, 57, 56, 62, 63, 61, 60, 54, 55, 53, 52, 50, 51, 49, 48, 42, 43, 41, 40, 46, 47, 45, 44, 38, 39, 37, 36, 34, 35, 33, 32, 10, 11, 9, 8, 14, 15, 13, 12, 6, 7, 5, 4, 2, 3, 1, 0, 26, 27, 25, 24, 30, 31, 29, 28, 22, 23, 21, 20, 18, 19, 17, 16)
void BOGI256_WA9(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x0000ffff00000000, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16)
void BOGI256_WAA(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012354/0x000000000000000f: 22 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x00000000ffff0000, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16)
void BOGI256_WAB(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000000f: 17 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
void BOGI256_WAC(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 1 cycles, 0 masks

	x = ROL64(x, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
void BOGI256_WAD(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 6 cycles, 1 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
void BOGI256_WAE(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xffff0000ffff0000, 16)
		| ROL64(x & 0x0000ffff0000ffff, 48);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(33, 32, 35, 34, 37, 36, 39, 38, 41, 40, 43, 42, 45, 44, 47, 46, 49, 48, 51, 50, 53, 52, 55, 54, 57, 56, 59, 58, 61, 60, 63, 62, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14)
void BOGI256_WAF(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 10 cycles, 2 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(49, 48, 51, 50, 53, 52, 55, 54, 57, 56, 59, 58, 61, 60, 63, 62, 33, 32, 35, 34, 37, 36, 39, 38, 41, 40, 43, 42, 45, 44, 47, 46, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14)
void BOGI256_WB0(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xaaaa0000aaaa0000, 15)
		| ROL64(x & 0x5555000055550000, 17)
		| ROL64(x & 0x0000aaaa0000aaaa, 47)
		| ROL64(x & 0x0000555500005555, 49);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30, 35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46, 51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14)
void BOGI256_WB1(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xeeeeeeeeeeeeeeee, 15)
		| ROL64(x & 0x1111111111111111, 19);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(49, 51, 48, 50, 53, 55, 52, 54, 57, 59, 56, 58, 61, 63, 60, 62, 33, 35, 32, 34, 37, 39, 36, 38, 41, 43, 40, 42, 45, 47, 44, 46, 17, 19, 16, 18, 21, 23, 20, 22, 25, 27, 24, 26, 29, 31, 28, 30, 1, 3, 0, 2, 5, 7, 4, 6, 9, 11, 8, 10, 13, 15, 12, 14)
void BOGI256_WB2(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102345/0x0000000000000012: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(50, 48, 51, 49, 54, 52, 55, 53, 58, 56, 59, 57, 62, 60, 63, 61, 34, 32, 35, 33, 38, 36, 39, 37, 42, 40, 43, 41, 46, 44, 47, 45, 18, 16, 19, 17, 22, 20, 23, 21, 26, 24, 27, 25, 30, 28, 31, 29, 2, 0, 3, 1, 6, 4, 7, 5, 10, 8, 11, 9, 14, 12, 15, 13)
void BOGI256_WB3(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102345/0x0000000000000011: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13)
void BOGI256_WB4(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xcccccccccccccccc, 14)
		| ROL64(x & 0x3333333333333333, 18);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13)
void BOGI256_WB5(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xcccc0000cccc0000, 14)
		| ROL64(x & 0x3333000033330000, 18)
		| ROL64(x & 0x0000cccc0000cccc, 46)
		| ROL64(x & 0x0000333300003333, 50);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(35, 34, 32, 33, 39, 38, 36, 37, 43, 42, 40, 41, 47, 46, 44, 45, 51, 50, 48, 49, 55, 54, 52, 53, 59, 58, 56, 57, 63, 62, 60, 61, 19, 18, 16, 17, 23, 22, 20, 21, 27, 26, 24, 25, 31, 30, 28, 29, 3, 2, 0, 1, 7, 6, 4, 5, 11, 10, 8, 9, 15, 14, 12, 13)
void BOGI256_WB6(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28, 33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44, 49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12)
void BOGI256_WB7(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0x8888888888888888, 13)
		| ROL64(x & 0x7777777777777777, 17);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(34, 35, 33, 32, 38, 39, 37, 36, 42, 43, 41, 40, 46, 47, 45, 44, 50, 51, 49, 48, 54, 55, 53, 52, 58, 59, 57, 56, 62, 63, 61, 60, 18, 19, 17, 16, 22, 23, 21, 20, 26, 27, 25, 24, 30, 31, 29, 28, 2, 3, 1, 0, 6, 7, 5, 4, 10, 11, 9, 8, 14, 15, 13, 12)
void BOGI256_WB8(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(51, 50, 49, 48, 55, 54, 53, 52, 59, 58, 57, 56, 63, 62, 61, 60, 35, 34, 33, 32, 39, 38, 37, 36, 43, 42, 41, 40, 47, 46, 45, 44, 19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12)
void BOGI256_WB9(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x0000000000000013: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(36, 37, 38, 39, 32, 33, 34, 35, 44, 45, 46, 47, 40, 41, 42, 43, 52, 53, 54, 55, 48, 49, 50, 51, 60, 61, 62, 63, 56, 57, 58, 59, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11)
void BOGI256_WBA(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 10 cycles, 2 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(52, 53, 54, 55, 48, 49, 50, 51, 60, 61, 62, 63, 56, 57, 58, 59, 36, 37, 38, 39, 32, 33, 34, 35, 44, 45, 46, 47, 40, 41, 42, 43, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11)
void BOGI256_WBB(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xf0f00000f0f00000, 12)
		| ROL64(x & 0x0f0f00000f0f0000, 20)
		| ROL64(x & 0x0000f0f00000f0f0, 44)
		| ROL64(x & 0x00000f0f00000f0f, 52);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)
void BOGI256_WBC(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xfff0fff0fff0fff0, 12)
		| ROL64(x & 0x000f000f000f000f, 28);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(52, 53, 54, 55, 60, 61, 62, 63, 48, 49, 50, 51, 56, 57, 58, 59, 36, 37, 38, 39, 44, 45, 46, 47, 32, 33, 34, 35, 40, 41, 42, 43, 20, 21, 22, 23, 28, 29, 30, 31, 16, 17, 18, 19, 24, 25, 26, 27, 4, 5, 6, 7, 12, 13, 14, 15, 0, 1, 2, 3, 8, 9, 10, 11)
void BOGI256_WBD(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013245/0x0000000000000018: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(37, 36, 39, 38, 33, 32, 35, 34, 45, 44, 47, 46, 41, 40, 43, 42, 53, 52, 55, 54, 49, 48, 51, 50, 61, 60, 63, 62, 57, 56, 59, 58, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10)
void BOGI256_WBE(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(53, 52, 55, 54, 49, 48, 51, 50, 61, 60, 63, 62, 57, 56, 59, 58, 37, 36, 39, 38, 33, 32, 35, 34, 45, 44, 47, 46, 41, 40, 43, 42, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10)
void BOGI256_WBF(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x0000000000000015: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22, 27, 24, 25, 26, 47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38, 43, 40, 41, 42, 63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54, 59, 56, 57, 58, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10)
void BOGI256_WC0(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xeee0eee0eee0eee0, 11)
		| ROL64(x & 0x1110111011101110, 15)
		| ROL64(x & 0x000e000e000e000e, 27)
		| ROL64(x & 0x0001000100010001, 31);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(53, 55, 52, 54, 61, 63, 60, 62, 49, 51, 48, 50, 57, 59, 56, 58, 37, 39, 36, 38, 45, 47, 44, 46, 33, 35, 32, 34, 41, 43, 40, 42, 21, 23, 20, 22, 29, 31, 28, 30, 17, 19, 16, 18, 25, 27, 24, 26, 5, 7, 4, 6, 13, 15, 12, 14, 1, 3, 0, 2, 9, 11, 8, 10)
void BOGI256_WC1(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103245/0x000000000000001a: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(54, 52, 55, 53, 62, 60, 63, 61, 50, 48, 51, 49, 58, 56, 59, 57, 38, 36, 39, 37, 46, 44, 47, 45, 34, 32, 35, 33, 42, 40, 43, 41, 22, 20, 23, 21, 30, 28, 31, 29, 18, 16, 19, 17, 26, 24, 27, 25, 6, 4, 7, 5, 14, 12, 15, 13, 2, 0, 3, 1, 10, 8, 11, 9)
void BOGI256_WC2(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103245/0x0000000000000019: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(54, 55, 52, 53, 50, 51, 48, 49, 62, 63, 60, 61, 58, 59, 56, 57, 38, 39, 36, 37, 34, 35, 32, 33, 46, 47, 44, 45, 42, 43, 40, 41, 22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25, 6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9)
void BOGI256_WC3(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x0000000000000016: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 42, 43, 40, 41, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 58, 59, 56, 57, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9)
void BOGI256_WC4(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xccc0ccc0ccc0ccc0, 10)
		| ROL64(x & 0x3330333033303330, 14)
		| ROL64(x & 0x000c000c000c000c, 26)
		| ROL64(x & 0x0003000300030003, 30);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(39, 38, 36, 37, 35, 34, 32, 33, 47, 46, 44, 45, 43, 42, 40, 41, 55, 54, 52, 53, 51, 50, 48, 49, 63, 62, 60, 61, 59, 58, 56, 57, 23, 22, 20, 21, 19, 18, 16, 17, 31, 30, 28, 29, 27, 26, 24, 25, 7, 6, 4, 5, 3, 2, 0, 1, 15, 14, 12, 13, 11, 10, 8, 9)
void BOGI256_WC5(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20, 25, 26, 27, 24, 45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36, 41, 42, 43, 40, 61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52, 57, 58, 59, 56, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8)
void BOGI256_WC6(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8880888088808880, 9)
		| ROL64(x & 0x7770777077707770, 13)
		| ROL64(x & 0x0008000800080008, 25)
		| ROL64(x & 0x0007000700070007, 29);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(38, 39, 37, 36, 34, 35, 33, 32, 46, 47, 45, 44, 42, 43, 41, 40, 54, 55, 53, 52, 50, 51, 49, 48, 62, 63, 61, 60, 58, 59, 57, 56, 22, 23, 21, 20, 18, 19, 17, 16, 30, 31, 29, 28, 26, 27, 25, 24, 6, 7, 5, 4, 2, 3, 1, 0, 14, 15, 13, 12, 10, 11, 9, 8)
void BOGI256_WC7(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56, 39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8)
void BOGI256_WC8(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x0000000000000017: 17 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(55, 54, 53, 52, 63, 62, 61, 60, 51, 50, 49, 48, 59, 58, 57, 56, 39, 38, 37, 36, 47, 46, 45, 44, 35, 34, 33, 32, 43, 42, 41, 40, 23, 22, 21, 20, 31, 30, 29, 28, 19, 18, 17, 16, 27, 26, 25, 24, 7, 6, 5, 4, 15, 14, 13, 12, 3, 2, 1, 0, 11, 10, 9, 8)
void BOGI256_WC9(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013245/0x000000000000001b: 22 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x00f000f000f000f0, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(56, 57, 58, 59, 48, 49, 50, 51, 60, 61, 62, 63, 52, 53, 54, 55, 40, 41, 42, 43, 32, 33, 34, 35, 44, 45, 46, 47, 36, 37, 38, 39, 24, 25, 26, 27, 16, 17, 18, 19, 28, 29, 30, 31, 20, 21, 22, 23, 8, 9, 10, 11, 0, 1, 2, 3, 12, 13, 14, 15, 4, 5, 6, 7)
void BOGI256_WCA(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013245/0x0000000000000014: 14 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7)
void BOGI256_WCB(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xff00ff00ff00ff00, 8)
		| ROL64(x & 0x00ff00ff00ff00ff, 24);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 53, 54, 55, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 36, 37, 38, 39, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7)
void BOGI256_WCC(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xff000000ff000000, 8)
		| ROL64(x & 0x00ff000000ff0000, 24)
		| ROL64(x & 0x0000ff000000ff00, 40)
		| ROL64(x & 0x000000ff000000ff, 56);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(44, 45, 46, 47, 40, 41, 42, 43, 32, 33, 34, 35, 36, 37, 38, 39, 60, 61, 62, 63, 56, 57, 58, 59, 48, 49, 50, 51, 52, 53, 54, 55, 28, 29, 30, 31, 24, 25, 26, 27, 16, 17, 18, 19, 20, 21, 22, 23, 12, 13, 14, 15, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7)
void BOGI256_WCD(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(57, 56, 59, 58, 61, 60, 63, 62, 49, 48, 51, 50, 53, 52, 55, 54, 41, 40, 43, 42, 45, 44, 47, 46, 33, 32, 35, 34, 37, 36, 39, 38, 25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22, 9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6)
void BOGI256_WCE(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x0000000000000019: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(45, 44, 47, 46, 41, 40, 43, 42, 33, 32, 35, 34, 37, 36, 39, 38, 61, 60, 63, 62, 57, 56, 59, 58, 49, 48, 51, 50, 53, 52, 55, 54, 29, 28, 31, 30, 25, 24, 27, 26, 17, 16, 19, 18, 21, 20, 23, 22, 13, 12, 15, 14, 9, 8, 11, 10, 1, 0, 3, 2, 5, 4, 7, 6)
void BOGI256_WCF(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18, 23, 20, 21, 22, 43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34, 39, 36, 37, 38, 59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50, 55, 52, 53, 54, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2, 7, 4, 5, 6)
void BOGI256_WD0(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xee00ee00ee00ee00, 7)
		| ROL64(x & 0x1100110011001100, 11)
		| ROL64(x & 0x00ee00ee00ee00ee, 23)
		| ROL64(x & 0x0011001100110011, 27);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(57, 59, 56, 58, 49, 51, 48, 50, 61, 63, 60, 62, 53, 55, 52, 54, 41, 43, 40, 42, 33, 35, 32, 34, 45, 47, 44, 46, 37, 39, 36, 38, 25, 27, 24, 26, 17, 19, 16, 18, 29, 31, 28, 30, 21, 23, 20, 22, 9, 11, 8, 10, 1, 3, 0, 2, 13, 15, 12, 14, 5, 7, 4, 6)
void BOGI256_WD1(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103245/0x0000000000000016: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(58, 56, 59, 57, 50, 48, 51, 49, 62, 60, 63, 61, 54, 52, 55, 53, 42, 40, 43, 41, 34, 32, 35, 33, 46, 44, 47, 45, 38, 36, 39, 37, 26, 24, 27, 25, 18, 16, 19, 17, 30, 28, 31, 29, 22, 20, 23, 21, 10, 8, 11, 9, 2, 0, 3, 1, 14, 12, 15, 13, 6, 4, 7, 5)
void BOGI256_WD2(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 103245/0x0000000000000015: 23 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5)
void BOGI256_WD3(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xcc00cc00cc00cc00, 6)
		| ROL64(x & 0x3300330033003300, 10)
		| ROL64(x & 0x00cc00cc00cc00cc, 22)
		| ROL64(x & 0x0033003300330033, 26);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 54, 55, 52, 53, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 38, 39, 36, 37, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5)
void BOGI256_WD4(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000001a: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(47, 46, 44, 45, 43, 42, 40, 41, 35, 34, 32, 33, 39, 38, 36, 37, 63, 62, 60, 61, 59, 58, 56, 57, 51, 50, 48, 49, 55, 54, 52, 53, 31, 30, 28, 29, 27, 26, 24, 25, 19, 18, 16, 17, 23, 22, 20, 21, 15, 14, 12, 13, 11, 10, 8, 9, 3, 2, 0, 1, 7, 6, 4, 5)
void BOGI256_WD5(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16, 21, 22, 23, 20, 41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32, 37, 38, 39, 36, 57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48, 53, 54, 55, 52, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0, 5, 6, 7, 4)
void BOGI256_WD6(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8800880088008800, 5)
		| ROL64(x & 0x7700770077007700, 9)
		| ROL64(x & 0x0088008800880088, 21)
		| ROL64(x & 0x0077007700770077, 25);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(46, 47, 45, 44, 42, 43, 41, 40, 34, 35, 33, 32, 38, 39, 37, 36, 62, 63, 61, 60, 58, 59, 57, 56, 50, 51, 49, 48, 54, 55, 53, 52, 30, 31, 29, 28, 26, 27, 25, 24, 18, 19, 17, 16, 22, 23, 21, 20, 14, 15, 13, 12, 10, 11, 9, 8, 2, 3, 1, 0, 6, 7, 5, 4)
void BOGI256_WD7(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x0f000f000f000f00, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(59, 58, 57, 56, 51, 50, 49, 48, 63, 62, 61, 60, 55, 54, 53, 52, 43, 42, 41, 40, 35, 34, 33, 32, 47, 46, 45, 44, 39, 38, 37, 36, 27, 26, 25, 24, 19, 18, 17, 16, 31, 30, 29, 28, 23, 22, 21, 20, 11, 10, 9, 8, 3, 2, 1, 0, 15, 14, 13, 12, 7, 6, 5, 4)
void BOGI256_WD8(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 013245/0x0000000000000017: 22 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 12);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(59, 58, 57, 56, 63, 62, 61, 60, 51, 50, 49, 48, 55, 54, 53, 52, 43, 42, 41, 40, 47, 46, 45, 44, 35, 34, 33, 32, 39, 38, 37, 36, 27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20, 11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4)
void BOGI256_WD9(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000001b: 17 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 32, 33, 34, 35, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3)
void BOGI256_WDA(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 4 cycles, 2 masks

	x = ROL64(x & 0xf000f000f000f000, 4)
		| ROL64(x & 0x0fff0fff0fff0fff, 20);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(40, 41, 42, 43, 44, 45, 46, 47, 36, 37, 38, 39, 32, 33, 34, 35, 56, 57, 58, 59, 60, 61, 62, 63, 52, 53, 54, 55, 48, 49, 50, 51, 24, 25, 26, 27, 28, 29, 30, 31, 20, 21, 22, 23, 16, 17, 18, 19, 8, 9, 10, 11, 12, 13, 14, 15, 4, 5, 6, 7, 0, 1, 2, 3)
void BOGI256_WDB(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 15 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(60, 61, 62, 63, 56, 57, 58, 59, 52, 53, 54, 55, 48, 49, 50, 51, 44, 45, 46, 47, 40, 41, 42, 43, 36, 37, 38, 39, 32, 33, 34, 35, 28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3)
void BOGI256_WDC(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000001c: 13 cycles, 3 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(41, 40, 43, 42, 45, 44, 47, 46, 37, 36, 39, 38, 33, 32, 35, 34, 57, 56, 59, 58, 61, 60, 63, 62, 53, 52, 55, 54, 49, 48, 51, 50, 25, 24, 27, 26, 29, 28, 31, 30, 21, 20, 23, 22, 17, 16, 19, 18, 9, 8, 11, 10, 13, 12, 15, 14, 5, 4, 7, 6, 1, 0, 3, 2)
void BOGI256_WDD(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 19 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(61, 60, 63, 62, 57, 56, 59, 58, 53, 52, 55, 54, 49, 48, 51, 50, 45, 44, 47, 46, 41, 40, 43, 42, 37, 36, 39, 38, 33, 32, 35, 34, 29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18, 13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2)
void BOGI256_WDE(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000001d: 17 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(23, 20, 21, 22, 27, 24, 25, 26, 31, 28, 29, 30, 19, 16, 17, 18, 39, 36, 37, 38, 43, 40, 41, 42, 47, 44, 45, 46, 35, 32, 33, 34, 55, 52, 53, 54, 59, 56, 57, 58, 63, 60, 61, 62, 51, 48, 49, 50, 7, 4, 5, 6, 11, 8, 9, 10, 15, 12, 13, 14, 3, 0, 1, 2)
void BOGI256_WDF(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xe000e000e000e000, 3)
		| ROL64(x & 0x1000100010001000, 7)
		| ROL64(x & 0x0eee0eee0eee0eee, 19)
		| ROL64(x & 0x0111011101110111, 23);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(61, 63, 60, 62, 57, 59, 56, 58, 53, 55, 52, 54, 49, 51, 48, 50, 45, 47, 44, 46, 41, 43, 40, 42, 37, 39, 36, 38, 33, 35, 32, 34, 29, 31, 28, 30, 25, 27, 24, 26, 21, 23, 20, 22, 17, 19, 16, 18, 13, 15, 12, 14, 9, 11, 8, 10, 5, 7, 4, 6, 1, 3, 0, 2)
void BOGI256_WE0(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102345/0x000000000000001e: 22 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x2222222222222222, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(62, 60, 63, 61, 58, 56, 59, 57, 54, 52, 55, 53, 50, 48, 51, 49, 46, 44, 47, 45, 42, 40, 43, 41, 38, 36, 39, 37, 34, 32, 35, 33, 30, 28, 31, 29, 26, 24, 27, 25, 22, 20, 23, 21, 18, 16, 19, 17, 14, 12, 15, 13, 10, 8, 11, 9, 6, 4, 7, 5, 2, 0, 3, 1)
void BOGI256_WE1(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 102345/0x000000000000001d: 22 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x1111111111111111, 3);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 38, 39, 36, 37, 42, 43, 40, 41, 46, 47, 44, 45, 34, 35, 32, 33, 54, 55, 52, 53, 58, 59, 56, 57, 62, 63, 60, 61, 50, 51, 48, 49, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1)
void BOGI256_WE2(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0xc000c000c000c000, 2)
		| ROL64(x & 0x3000300030003000, 6)
		| ROL64(x & 0x0ccc0ccc0ccc0ccc, 18)
		| ROL64(x & 0x0333033303330333, 22);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(62, 63, 60, 61, 58, 59, 56, 57, 54, 55, 52, 53, 50, 51, 48, 49, 46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33, 30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1)
void BOGI256_WE3(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000001e: 17 cycles, 4 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(43, 42, 40, 41, 47, 46, 44, 45, 39, 38, 36, 37, 35, 34, 32, 33, 59, 58, 56, 57, 63, 62, 60, 61, 55, 54, 52, 53, 51, 50, 48, 49, 27, 26, 24, 25, 31, 30, 28, 29, 23, 22, 20, 21, 19, 18, 16, 17, 11, 10, 8, 9, 15, 14, 12, 13, 7, 6, 4, 5, 3, 2, 0, 1)
void BOGI256_WE4(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x4444444444444444, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(21, 22, 23, 20, 25, 26, 27, 24, 29, 30, 31, 28, 17, 18, 19, 16, 37, 38, 39, 36, 41, 42, 43, 40, 45, 46, 47, 44, 33, 34, 35, 32, 53, 54, 55, 52, 57, 58, 59, 56, 61, 62, 63, 60, 49, 50, 51, 48, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12, 1, 2, 3, 0)
void BOGI256_WE5(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Bit group moving: 8 cycles, 4 masks

	x = ROL64(x & 0x8000800080008000, 1)
		| ROL64(x & 0x7000700070007000, 5)
		| ROL64(x & 0x0888088808880888, 17)
		| ROL64(x & 0x0777077707770777, 21);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(42, 43, 41, 40, 46, 47, 45, 44, 38, 39, 37, 36, 34, 35, 33, 32, 58, 59, 57, 56, 62, 63, 61, 60, 54, 55, 53, 52, 50, 51, 49, 48, 26, 27, 25, 24, 30, 31, 29, 28, 22, 23, 21, 20, 18, 19, 17, 16, 10, 11, 9, 8, 14, 15, 13, 12, 6, 7, 5, 4, 2, 3, 1, 0)
void BOGI256_WE6(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + Benes 012345: 24 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_64(&x, x, 0x000000000000ffff, 16);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_64(&x, x, 0x000f000f000f000f, 4);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_64(&x, x, 0x1111111111111111, 1);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}
//(63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
void BOGI256_WE7(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint64_t x = in & 0xffffffffffffffffULL;
	//Rol 32 + BPC permutation 012345/0x000000000000001f: 21 cycles, 5 masks

	x = ROL64(x, 32);
	bit_permute_step_simple_64(&x, x, 0x5555555555555555, 1);
	bit_permute_step_simple_64(&x, x, 0x3333333333333333, 2);
	bit_permute_step_simple_64(&x, x, 0x0f0f0f0f0f0f0f0f, 4);
	bit_permute_step_simple_64(&x, x, 0x00ff00ff00ff00ff, 8);
	bit_permute_step_simple_64(&x, x, 0x0000ffff0000ffff, 16);


	*out = (ACTIVE_MAP_t)x & 0xffffffffffffffffULL;
}

void (*BOGI256_1_PERMS[64])(ACTIVE_MAP_t * , ACTIVE_MAP_t ) = {
	BOGI256_W00, BOGI256_W01, BOGI256_W05, BOGI256_W09, BOGI256_W0A, BOGI256_W0D, BOGI256_W11, BOGI256_W16,
	BOGI256_W19, BOGI256_W1B, BOGI256_W20, BOGI256_W25, BOGI256_W28, BOGI256_W2A, BOGI256_W2F, BOGI256_W33,
	BOGI256_W34, BOGI256_W37, BOGI256_W3B, BOGI256_W40, BOGI256_W42, BOGI256_W45, BOGI256_W49, BOGI256_W4E, 
	BOGI256_W51, BOGI256_W54, BOGI256_W59, BOGI256_W5F, BOGI256_W62, BOGI256_W65, BOGI256_W6A, BOGI256_W6E,
	BOGI256_W71, BOGI256_W73, BOGI256_W78, BOGI256_W7D, BOGI256_W7E, BOGI256_W82, BOGI256_W87, BOGI256_W8C, 
	BOGI256_W8F, BOGI256_W91, BOGI256_W96, BOGI256_W9B, BOGI256_W9F, BOGI256_WA1, BOGI256_WA6, BOGI256_WAB,
	BOGI256_WAE, BOGI256_WB0, BOGI256_WB5, BOGI256_WB9, BOGI256_WBB, BOGI256_WBF, BOGI256_WC3, BOGI256_WC8, 
	BOGI256_WCC, BOGI256_WCE, BOGI256_WD4, BOGI256_WD9, BOGI256_WDC, BOGI256_WDE, BOGI256_WE3, BOGI256_WE7 };

void(*BOGI256_2_PERMS[64])(ACTIVE_MAP_t *, ACTIVE_MAP_t) = {
	BOGI256_W00, BOGI256_W01, BOGI256_W06, BOGI256_W08, BOGI256_W0A, BOGI256_W0D, BOGI256_W13, BOGI256_W15, 
	BOGI256_W1A, BOGI256_W1C, BOGI256_W21, BOGI256_W23, BOGI256_W27, BOGI256_W29, BOGI256_W30, BOGI256_W32,
	BOGI256_W34, BOGI256_W37, BOGI256_W3D, BOGI256_W3F, BOGI256_W42, BOGI256_W45, BOGI256_W4B, BOGI256_W4D, 
	BOGI256_W53, BOGI256_W55, BOGI256_W5B, BOGI256_W5D, BOGI256_W61, BOGI256_W64, BOGI256_W6B, BOGI256_W6D, 
	BOGI256_W72, BOGI256_W74, BOGI256_W79, BOGI256_W7B, BOGI256_W7F, BOGI256_W83, BOGI256_W89, BOGI256_W8B, 
	BOGI256_W90, BOGI256_W92, BOGI256_W97, BOGI256_W99, BOGI256_W9D, BOGI256_WA0, BOGI256_WA7, BOGI256_WA9, 
	BOGI256_WAD, BOGI256_WAF, BOGI256_WB6, BOGI256_WB8, BOGI256_WBA, BOGI256_WBE, BOGI256_WC5, BOGI256_WC7, 
	BOGI256_WCD, BOGI256_WCF, BOGI256_WD5, BOGI256_WD7, BOGI256_WDB, BOGI256_WDD, BOGI256_WE4, BOGI256_WE6};

void(*BOGI256_3_PERMS[64])(ACTIVE_MAP_t *, ACTIVE_MAP_t) = {
	BOGI256_W00, BOGI256_W02, BOGI256_W05, BOGI256_W07, BOGI256_W0B, BOGI256_W0E, BOGI256_W12, BOGI256_W14, 
	BOGI256_W19, BOGI256_W1D, BOGI256_W20, BOGI256_W22, BOGI256_W26, BOGI256_W2B, BOGI256_W2E, BOGI256_W31,
	BOGI256_W35, BOGI256_W38, BOGI256_W3C, BOGI256_W3E, BOGI256_W43, BOGI256_W46, BOGI256_W4A, BOGI256_W4C, 
	BOGI256_W52, BOGI256_W56, BOGI256_W5A, BOGI256_W5C, BOGI256_W60, BOGI256_W66, BOGI256_W69, BOGI256_W6C, 
	BOGI256_W71, BOGI256_W75, BOGI256_W78, BOGI256_W7A, BOGI256_W80, BOGI256_W84, BOGI256_W88, BOGI256_W8A,
	BOGI256_W8F, BOGI256_W93, BOGI256_W96, BOGI256_W98, BOGI256_W9C, BOGI256_WA2, BOGI256_WA5, BOGI256_WA8,
	BOGI256_WAC, BOGI256_WB1, BOGI256_WB4, BOGI256_WB7, BOGI256_WBC, BOGI256_WC0, BOGI256_WC4, BOGI256_WC6,
	BOGI256_WCB, BOGI256_WD0, BOGI256_WD3, BOGI256_WD6, BOGI256_WDA, BOGI256_WDF, BOGI256_WE2, BOGI256_WE5};

void(*BOGI256_4_PERMS[64])(ACTIVE_MAP_t *, ACTIVE_MAP_t) = {
	BOGI256_W00, BOGI256_W03, BOGI256_W04, BOGI256_W09, BOGI256_W0C, BOGI256_W0F, BOGI256_W10, BOGI256_W17, 
	BOGI256_W18, BOGI256_W1E, BOGI256_W1F, BOGI256_W24, BOGI256_W28, BOGI256_W2C, BOGI256_W2D, BOGI256_W33, 
	BOGI256_W36, BOGI256_W39, BOGI256_W3A, BOGI256_W41, BOGI256_W44, BOGI256_W47, BOGI256_W48, BOGI256_W4F, 
	BOGI256_W50, BOGI256_W57, BOGI256_W58, BOGI256_W5E, BOGI256_W63, BOGI256_W67, BOGI256_W68, BOGI256_W6F,
	BOGI256_W70, BOGI256_W76, BOGI256_W77, BOGI256_W7C, BOGI256_W81, BOGI256_W85, BOGI256_W86, BOGI256_W8D, 
	BOGI256_W8E, BOGI256_W94, BOGI256_W95, BOGI256_W9A, BOGI256_W9E, BOGI256_WA3, BOGI256_WA4, BOGI256_WAA, 
	BOGI256_WAE, BOGI256_WB2, BOGI256_WB3, BOGI256_WB9, BOGI256_WBD, BOGI256_WC1, BOGI256_WC2, BOGI256_WC9, 
	BOGI256_WCA, BOGI256_WD1, BOGI256_WD2, BOGI256_WD8, BOGI256_WDC, BOGI256_WE0, BOGI256_WE1, BOGI256_WE7};