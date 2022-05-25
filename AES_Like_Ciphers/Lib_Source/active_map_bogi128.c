#include "astbb.h"
#include "bit_perm_opt.h"


/*
BOGI128_0
4294967295(31.99) Word-wise Permutations are Considered
active num  1 : 32
active num  2 : 496
active num  3 : 4960
active num  4 : 35960
active num  5 : 201376
active num  6 : 906192
active num  7 : 3365856
active num  8 : 10518300
active num  9 : 28048800
active num 10 : 64512240
active num 11 : 129024480
active num 12 : 225792840
active num 13 : 347373600
active num 14 : 471435600
active num 15 : 565722720
active num 16 : 601080390
active num 17 : 565722720
active num 18 : 471435600
active num 19 : 347373600
active num 20 : 225792840
active num 21 : 129024480
active num 22 : 64512240
active num 23 : 28048800
active num 24 : 10518300
active num 25 : 3365856
active num 26 : 906192
active num 27 : 201376
active num 28 : 35960
active num 29 : 4960
active num 30 : 496
active num 31 : 32
active num 32 : 1
		TOTAL : 4294967295(31.99)
*/


/*
BOGI128_1
2147516415(31.00) Word-wise Permutations are Considered
active num  1 : 16
active num  2 : 256
active num  3 : 2480
active num  4 : 18040
active num  5 : 100688
active num  6 : 453376
active num  7 : 1682928
active num  8 : 5260060
active num  9 : 14024400
active num 10 : 32258304
active num 11 : 64512240
active num 12 : 112900424
active num 13 : 173686800
active num 14 : 235723520
active num 15 : 282861360
active num 16 : 300546630
active num 17 : 282861360
active num 18 : 235723520
active num 19 : 173686800
active num 20 : 112900424
active num 21 : 64512240
active num 22 : 32258304
active num 23 : 14024400
active num 24 : 5260060
active num 25 : 1682928
active num 26 : 453376
active num 27 : 100688
active num 28 : 18040
active num 29 : 2480
active num 30 : 256
active num 31 : 16
active num 32 : 1
		TOTAL : 2147516415(31.00)
*/

/*
BOGI128_2
1073790975(30.00) Word-wise Permutations are Considered
active num  1 : 8
active num  2 : 136
active num  3 : 1240
active num  4 : 9080
active num  5 : 50344
active num  6 : 226968
active num  7 : 841464
active num  8 : 2630940
active num  9 : 7012200
active num 10 : 16131336
active num 11 : 32256120
active num 12 : 56454216
active num 13 : 86843400
active num 14 : 117867480
active num 15 : 141430680
active num 16 : 150279750
active num 17 : 141430680
active num 18 : 117867480
active num 19 : 86843400
active num 20 : 56454216
active num 21 : 32256120
active num 22 : 16131336
active num 23 : 7012200
active num 24 : 2630940
active num 25 : 841464
active num 26 : 226968
active num 27 : 50344
active num 28 : 9080
active num 29 : 1240
active num 30 : 136
active num 31 : 8
active num 32 : 1
		TOTAL : 1073790975(30.00)
*/

/*
BOGI128_3
536928255(29.00) Word-wise Permutations are Considered
active num  1 : 4
active num  2 : 76
active num  3 : 620
active num  4 : 4600
active num  5 : 25172
active num  6 : 113764
active num  7 : 420732
active num  8 : 1316380
active num  9 : 3506100
active num 10 : 8067852
active num 11 : 16128060
active num 12 : 28231112
active num 13 : 43421700
active num 14 : 58939460
active num 15 : 70715340
active num 16 : 75146310
active num 17 : 70715340
active num 18 : 58939460
active num 19 : 43421700
active num 20 : 28231112
active num 21 : 16128060
active num 22 : 8067852
active num 23 : 3506100
active num 24 : 1316380
active num 25 : 420732
active num 26 : 113764
active num 27 : 25172
active num 28 : 4600
active num 29 : 620
active num 30 : 76
active num 31 : 4
active num 32 : 1
		TOTAL : 536928255(29.00)
*/


/*
BOGI128_4
134281215(27.00) Word-wise Permutations are Considered
active num  1 : 1
active num  2 : 31
active num  3 : 155
active num  4 : 1240
active num  5 : 6293
active num  6 : 28861
active num  7 : 105183
active num  8 : 330460
active num  9 : 876525
active num 10 : 2020239
active num 11 : 4032015
active num 12 : 7063784
active num 13 : 10855425
active num 14 : 14743445
active num 15 : 17678835
active num 16 : 18796230
active num 17 : 17678835
active num 18 : 14743445
active num 19 : 10855425
active num 20 : 7063784
active num 21 : 4032015
active num 22 : 2020239
active num 23 : 876525
active num 24 : 330460
active num 25 : 105183
active num 26 : 28861
active num 27 : 6293
active num 28 : 1240
active num 29 : 155
active num 30 : 31
active num 31 : 1
active num 32 : 1
		TOTAL : 134281215(27.00)
*/


//(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30)
void BOGI128_W01(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	
	x = ((x & 0x55555555) << 1)
		| ((x & 0xaaaaaaaa) >> 1);
	
	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29)
void BOGI128_W02(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	
	x = ((x & 0x33333333) << 2)
		| ((x & 0xcccccccc) >> 2);
	
	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, 19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28)
void BOGI128_W03(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ((x & 0x22222222) << 1)
		| ((x & 0x11111111) << 3)
		| ((x & 0x88888888) >> 3)
		| ((x & 0x44444444) >> 1);
	
	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27)
void BOGI128_W04(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	x = ((x & 0x0f0f0f0f) << 4)
		| ((x & 0xf0f0f0f0) >> 4);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10, 21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26)
void BOGI128_W05(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ((x & 0x0a0a0a0a) << 3)
		| ((x & 0x05050505) << 5)
		| ((x & 0xa0a0a0a0) >> 5)
		| ((x & 0x50505050) >> 3);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9, 22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25)
void BOGI128_W06(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ((x & 0x0c0c0c0c) << 2)
		| ((x & 0x03030303) << 6)
		| ((x & 0xc0c0c0c0) >> 6)
		| ((x & 0x30303030) >> 2);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24)
void BOGI128_W07(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//BPC permutation 01234 / 0x00000007 : 15 cycles, 3 masks
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23)
void BOGI128_W08(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	x = ((x & 0x00ff00ff) << 8)
		| ((x & 0xff00ff00) >> 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6, 25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22)
void BOGI128_W09(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ((x & 0x00aa00aa) << 7)
		| ((x & 0x00550055) << 9)
		| ((x & 0xaa00aa00) >> 9)
		| ((x & 0x55005500) >> 7);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5, 26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21)
void BOGI128_W0A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ((x & 0x00cc00cc) << 6)
		| ((x & 0x00330033) << 10)
		| ((x & 0xcc00cc00) >> 10)
		| ((x & 0x33003300) >> 6);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4, 27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20)
void BOGI128_W0B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//BPC permutation 01234 / 0x0000000b : 15 cycles, 3 masks
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3, 28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19)
void BOGI128_W0C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ((x & 0x00f000f0) << 4)
		| ((x & 0x000f000f) << 12)
		| ((x & 0xf000f000) >> 12)
		| ((x & 0x0f000f00) >> 4);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2, 29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18)
void BOGI128_W0D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//BPC permutation 01234 / 0x0000000d : 15 cycles, 3 masks
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1, 30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17)
void BOGI128_W0E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//BPC permutation 01234 / 0x0000000e : 15 cycles, 3 masks
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);
	
	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16)
void BOGI128_W0F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	uint32_t x = in & 0xffffffff;

	//BPC permutation 01234 / 0x0000000f : 20 cycles, 4 masks
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
void BOGI128_W10(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 1 cycles, 0 masks
	x = ROL32(x, 16);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14)
void BOGI128_W11(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	x = ROL32(x & 0xaaaaaaaa, 15)
		| ROL32(x & 0x55555555, 17);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(18, 19, 16, 17, 22, 23, 20, 21, 26, 27, 24, 25, 30, 31, 28, 29, 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13)
void BOGI128_W12(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	x = ROL32(x & 0xcccccccc, 14)
		| ROL32(x & 0x33333333, 18);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(19, 18, 17, 16, 23, 22, 21, 20, 27, 26, 25, 24, 31, 30, 29, 28, 3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12)
void BOGI128_W13(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ROL32(x & 0x88888888, 13)
		| ROL32(x & 0x44444444, 15)
		| ROL32(x & 0x22222222, 17)
		| ROL32(x & 0x11111111, 19);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(20, 21, 22, 23, 16, 17, 18, 19, 28, 29, 30, 31, 24, 25, 26, 27, 4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11)
void BOGI128_W14(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	x = ROL32(x & 0xf0f0f0f0, 12)
		| ROL32(x & 0x0f0f0f0f, 20);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(21, 20, 23, 22, 17, 16, 19, 18, 29, 28, 31, 30, 25, 24, 27, 26, 5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10)
void BOGI128_W15(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ROL32(x & 0xa0a0a0a0, 11)
		| ROL32(x & 0x50505050, 13)
		| ROL32(x & 0x0a0a0a0a, 19)
		| ROL32(x & 0x05050505, 21);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(22, 23, 20, 21, 18, 19, 16, 17, 30, 31, 28, 29, 26, 27, 24, 25, 6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9)
void BOGI128_W16(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ROL32(x & 0xc0c0c0c0, 10)
		| ROL32(x & 0x30303030, 14)
		| ROL32(x & 0x0c0c0c0c, 18)
		| ROL32(x & 0x03030303, 22);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8)
void BOGI128_W17(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Rol 16 + BPC permutation 01234 / 0x00000007 : 16 cycles, 3 masks
	x = ROL32(x, 16);
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7)
void BOGI128_W18(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 4 cycles, 2 masks
	x = ROL32(x & 0xff00ff00, 8)
		| ROL32(x & 0x00ff00ff, 24);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(25, 24, 27, 26, 29, 28, 31, 30, 17, 16, 19, 18, 21, 20, 23, 22, 9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6)
void BOGI128_W19(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ROL32(x & 0xaa00aa00, 7)
		| ROL32(x & 0x55005500, 9)
		| ROL32(x & 0x00aa00aa, 23)
		| ROL32(x & 0x00550055, 25);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(26, 27, 24, 25, 30, 31, 28, 29, 18, 19, 16, 17, 22, 23, 20, 21, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5)
void BOGI128_W1A(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ROL32(x & 0xcc00cc00, 6)
		| ROL32(x & 0x33003300, 10)
		| ROL32(x & 0x00cc00cc, 22)
		| ROL32(x & 0x00330033, 26);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(27, 26, 25, 24, 31, 30, 29, 28, 19, 18, 17, 16, 23, 22, 21, 20, 11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4)
void BOGI128_W1B(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Rol 16 + BPC permutation 01234 / 0x0000000b : 16 cycles, 3 masks
	x = ROL32(x, 16);
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(28, 29, 30, 31, 24, 25, 26, 27, 20, 21, 22, 23, 16, 17, 18, 19, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3)
void BOGI128_W1C(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Bit group moving : 8 cycles, 4 masks
	x = ROL32(x & 0xf000f000, 4)
		| ROL32(x & 0x0f000f00, 12)
		| ROL32(x & 0x00f000f0, 20)
		| ROL32(x & 0x000f000f, 28);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(29, 28, 31, 30, 25, 24, 27, 26, 21, 20, 23, 22, 17, 16, 19, 18, 13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2)
void BOGI128_W1D(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	uint32_t x = in & 0xffffffff;

	//Rol 16 + BPC permutation 01234 / 0x0000000d : 16 cycles, 3 masks
	x = ROL32(x, 16);
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1)
void BOGI128_W1E(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Rol 16 + BPC permutation 01234 / 0x0000000e : 16 cycles, 3 masks
	x = ROL32(x, 16);
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}
//(31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
void BOGI128_W1F(ACTIVE_MAP_t * out, ACTIVE_MAP_t in)
{
	//Consider the above lut as "LSB"-like since we let the active_map_t's lsb have the index 0. 
	uint32_t x = in & 0xffffffff;
	//Rol 16 + BPC permutation 01234 / 0x0000000f : 21 cycles, 4 masks
	x = ROL32(x, 16);
	bit_permute_step_simple_32(&x, x, 0x55555555, 1);
	bit_permute_step_simple_32(&x, x, 0x33333333, 2);
	bit_permute_step_simple_32(&x, x, 0x0f0f0f0f, 4);
	bit_permute_step_simple_32(&x, x, 0x00ff00ff, 8);

	*out = (ACTIVE_MAP_t)x & 0xffffffff;
}