#include "astbb.h"

ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_0[15] =
{
	//1-active
	0x1, 0x2, 0x4, 0x8,
	//2-active
	0x3, 0x5, 0x9, 0x6, 0xA, 0xC,
	//3-active
	0x7, 0xB, 0xD, 0xE,
	//4-active
	0xF
};


/*
BOGI16_1
4 Word-wise Permutations are Considered
active num  1 : 1
active num  2 : 3
active num  3 : 1
active num  4 : 1
		TOTAL : 6
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_1[6] =
{
	// 1_active : 1
	0x1,
	// 2_active : 3
	0x3, 0x5, 0x6,
	// 3_active : 1
	0x7,
	// 4_active : 1
	0xf,
};

/*
BOGI16_2
4 Word-wise Permutations are Considered
active num  1 : 1
active num  2 : 2
active num  3 : 1
active num  4 : 1
		TOTAL : 5
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_2[5] =
{
	// 1_active : 1
	0x1,
	// 2_active : 2
	0x3, 0x5,
	// 3_active : 1
	0x7,
	// 4_active : 1
	0xf,
};

/*
BOGI16_3
4 Word-wise Permutations are Considered
active num  1 : 1
active num  2 : 2
active num  3 : 1
active num  4 : 1
		TOTAL : 5
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_3[5] =
{
	// 1_active : 1
	0x1,
	// 2_active : 2
	0x3, 0x5,
	// 3_active : 1
	0x7,
	// 4_active : 1
	0xf,
};

/*
BOGI16_4
4 Word-wise Permutations are Considered
active num  1 : 1
active num  2 : 2
active num  3 : 1
active num  4 : 1
			TOTAL : 5
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI16_4[5] =
{
	// 1_active : 1
	0x1,
	// 2_active : 2
	0x3, 0x6,
	// 3_active : 1
	0x7,
	// 4_active : 1
	0xf,
};