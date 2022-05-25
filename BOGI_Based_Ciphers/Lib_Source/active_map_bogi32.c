#include "astbb.h"

ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_0[255] =
{
	//1-active
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
	//2-active
	0x03, 0x05, 0x09, 0x11, 0x21, 0x41, 0x81, 0x06, 0x0A, 0x12, 0x22, 0x42, 0x82, 0x0C, 0x14, 0x24,
	0x44, 0x84, 0x18, 0x28, 0x48, 0x88, 0x30, 0x50, 0x90, 0x60, 0xA0, 0xC0,
	//3-active
	0x07, 0x0B, 0x13, 0x23, 0x43, 0x83, 0x0D, 0x15, 0x25, 0x45, 0x85, 0x19, 0x29, 0x49, 0x89, 0x31,
	0x51, 0x91, 0x61, 0xA1, 0xC1, 0x0E, 0x16, 0x26, 0x46, 0x86, 0x1A, 0x2A, 0x4A, 0x8A, 0x32, 0x52,
	0x92, 0x62, 0xA2, 0xC2, 0x1C, 0x2C, 0x4C, 0x8C, 0x34, 0x54, 0x94, 0x64, 0xA4, 0xC4, 0x38, 0x58,
	0x98, 0x68, 0xA8, 0xC8, 0x70, 0xB0, 0xD0, 0xE0,
	//4-active
	0x0F, 0x17, 0x27, 0x47, 0x87, 0x1B, 0x2B, 0x4B, 0x8B, 0x33, 0x53, 0x93, 0x63, 0xA3, 0xC3, 0x1D,
	0x2D, 0x4D, 0x8D, 0x35, 0x55, 0x95, 0x65, 0xA5, 0xC5, 0x39, 0x59, 0x99, 0x69, 0xA9, 0xC9, 0x71,
	0xB1, 0xD1, 0xE1, 0x1E, 0x2E, 0x4E, 0x8E, 0x36, 0x56, 0x96, 0x66, 0xA6, 0xC6, 0x3A, 0x5A, 0x9A,
	0x6A, 0xAA, 0xCA, 0x72, 0xB2, 0xD2, 0xE2, 0x3C, 0x5C, 0x9C, 0x6C, 0xAC, 0xCC, 0x74, 0xB4, 0xD4,
	0xE4, 0x78, 0xB8, 0xD8, 0xE8, 0xF0,
	//5-active
	0x1F, 0x2F, 0x4F, 0x8F, 0x37, 0x57, 0x97, 0x67, 0xA7, 0xC7, 0x3B, 0x5B, 0x9B, 0x6B, 0xAB, 0xCB,
	0x73, 0xB3, 0xD3, 0xE3, 0x3D, 0x5D, 0x9D, 0x6D, 0xAD, 0xCD, 0x75, 0xB5, 0xD5, 0xE5, 0x79, 0xB9,
	0xD9, 0xE9, 0xF1, 0x3E, 0x5E, 0x9E, 0x6E, 0xAE, 0xCE, 0x76, 0xB6, 0xD6, 0xE6, 0x7A, 0xBA, 0xDA,
	0xEA, 0xF2, 0x7C, 0xBC, 0xDC, 0xEC, 0xF4, 0xF8,
	//6-active
	0x3F, 0x5F, 0x9F, 0x6F, 0xAF, 0xCF, 0x77, 0xB7, 0xD7, 0xE7, 0x7B, 0xBB, 0xDB, 0xEB, 0xF3, 0x7D,
	0xBD, 0xDD, 0xED, 0xF5, 0xF9, 0x7E, 0xBE, 0xDE, 0xEE, 0xF6, 0xFA, 0xFC,
	//7-active
	0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE,
	//8-active
	0xFF
};


/*
BOGI32_1
2 Word-wise Permutations are Considered
active num  1 : 4
active num  2 : 16
active num  3 : 28
active num  4 : 38
active num  5 : 28
active num  6 : 16
active num  7 : 4
active num  8 : 1
			TOTAL : 135
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_1[135] =
{
	// 1_active : 4
	0x01, 0x02, 0x04, 0x08,
	// 2_active : 16
	0x03, 0x05, 0x06, 0x09, 0x0a, 0x0c, 0x11, 0x12, 0x14, 0x18, 0x21, 0x22, 0x24, 0x41, 0x42, 0x81,
	// 3_active : 28
	0x07, 0x0b, 0x0d, 0x0e, 0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c, 0x23, 0x25, 0x26, 0x29, 0x2a, 0x2c,
	0x31, 0x32, 0x43, 0x45, 0x46, 0x49, 0x4a, 0x51, 0x61, 0x83, 0x85, 0x89,
	// 4_active : 38
	0x0f, 0x17, 0x1b, 0x1d, 0x1e, 0x27, 0x2b, 0x2d, 0x2e, 0x33, 0x35, 0x36, 0x39, 0x3a, 0x3c, 0x47,
	0x4b, 0x4d, 0x4e, 0x53, 0x55, 0x56, 0x59, 0x5a, 0x63, 0x65, 0x66, 0x69, 0x71, 0x87, 0x8b, 0x8d,
	0x93, 0x95, 0x99, 0xa3, 0xa5, 0xc3,
	// 5_active : 28
	0x1f, 0x2f, 0x37, 0x3b, 0x3d, 0x3e, 0x4f, 0x57, 0x5b, 0x5d, 0x5e, 0x67, 0x6b, 0x6d, 0x6e, 0x73,
	0x75, 0x79, 0x8f, 0x97, 0x9b, 0x9d, 0xa7, 0xab, 0xad, 0xb3, 0xc7, 0xcb,
	// 6_active : 16
	0x3f, 0x5f, 0x6f, 0x77, 0x7b, 0x7d, 0x7e, 0x9f, 0xaf, 0xb7, 0xbb, 0xbd, 0xcf, 0xd7, 0xdb, 0xe7,
	// 7_active : 4
	0x7f, 0xbf, 0xdf, 0xef,
	// 8_active : 1
	0xff,
};

/*
BOGI32_2
4 Word-wise Permutations are Considered
active num  1 : 2
active num  2 : 10
active num  3 : 14
active num  4 : 22
active num  5 : 14
active num  6 : 10
active num  7 : 2
active num  8 : 1
			TOTAL : 75
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_2[75] =
{
	// 1_active : 2
	0x01, 0x04,
	// 2_active : 10
	0x03, 0x05, 0x06, 0x0c, 0x11, 0x12, 0x14, 0x18, 0x44, 0x48,
	// 3_active : 14
	0x07, 0x0d, 0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c, 0x34, 0x45, 0x46, 0x49, 0x4a, 0x4c,
	// 4_active : 22
	0x0f, 0x17, 0x1b, 0x1d, 0x1e, 0x33, 0x35, 0x36, 0x3c, 0x47, 0x4b, 0x4d, 0x4e, 0x55, 0x56, 0x59,
	0x5a, 0x5c, 0x66, 0x69, 0x6c, 0xcc,
	// 5_active : 14
	0x1f, 0x37, 0x3d, 0x4f, 0x57, 0x5b, 0x5d, 0x5e, 0x67, 0x6b, 0x6d, 0x6e, 0x7c, 0xcd,
	// 6_active : 10
	0x3f, 0x5f, 0x6f, 0x77, 0x7b, 0x7d, 0x7e, 0xcf, 0xdd, 0xde,
	// 7_active : 2
	0x7f, 0xdf,
	// 8_active : 1
	0xff,
};

/*
BOGI32_3
8 Word-wise Permutations are Considered
active num  1 : 1
active num  2 : 7
active num  3 : 7
active num  4 : 14
active num  5 : 7
active num  6 : 7
active num  7 : 1
active num  8 : 1
			TOTAL : 45
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_3[45] =
{

	// 1_active : 1
	0x01,
	// 2_active : 7
	0x03, 0x05, 0x06, 0x11, 0x12, 0x14, 0x18,
	// 3_active : 7
	0x07, 0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c,
	// 4_active : 14
	0x0f, 0x17, 0x1b, 0x1d, 0x1e, 0x33, 0x35, 0x36, 0x3c, 0x55, 0x56, 0x5a, 0x66, 0x69,
	// 5_active : 7
	0x1f, 0x37, 0x3d, 0x57, 0x5b, 0x67, 0x6b,
	// 6_active : 7
	0x3f, 0x5f, 0x6f, 0x77, 0x7b, 0x7d, 0x7e,
	// 7_active : 1
	0x7f,
	// 8_active : 1
	0xff,
};

/*
BOGI32_4
8 Word-wise Permutations are Considered
active num  1 : 1
active num  2 : 5
active num  3 : 7
active num  4 : 12
active num  5 : 7
active num  6 : 5
active num  7 : 1
active num  8 : 1
			TOTAL : 39
*/
ACTIVE_MAP_t ACTIVE_MAPS_BOGI32_4[39] =
{

	// 1_active : 1
	0x01,
	// 2_active : 5
	0x03, 0x05, 0x11, 0x12, 0x18,
	// 3_active : 7
	0x07, 0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c,
	// 4_active : 12
	0x0f, 0x17, 0x1b, 0x1d, 0x1e, 0x33, 0x35, 0x36, 0x39, 0x3a, 0x55, 0x5a,
	// 5_active : 7
	0x1f, 0x37, 0x3b, 0x3d, 0x3e, 0x57, 0x5b,
	// 6_active : 5
	0x3f, 0x5f, 0x77, 0x7b, 0x7e,
	// 7_active : 1
	0x7f,
	// 8_active : 1
	0xff,
};