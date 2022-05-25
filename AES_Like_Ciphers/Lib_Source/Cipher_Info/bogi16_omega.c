#include "astbb.h"


//((0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_0(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_0(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_1(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4282, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x2428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_1(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8242, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x2824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_2(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8242, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x2824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_2(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4282, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x2428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_3(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_3(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 2, 3, 0), (2, 3, 0, 1), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 13, 10, 7, 4, 1, 14, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_4(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_4(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 2, 3, 0), (3, 0, 1, 2), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 1, 10, 7, 0, 5, 14, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_5(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_5(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 3, 0, 2), (2, 0, 3, 1), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 1, 14, 7, 4, 13, 2, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_6(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8284, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_6(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8482, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 3, 0, 2), (3, 2, 1, 0), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 9, 14, 7, 12, 5, 2, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_7(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4248, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_7(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4842, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 0, 3, 1), (1, 3, 0, 2), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 13, 2, 7, 4, 1, 14, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_8(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8482, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_8(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8284, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 0, 3, 1), (3, 2, 1, 0), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 9, 2, 7, 0, 5, 14, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_9(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4842, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_9(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4248, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 1, 14, 7, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_10(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_10(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 9, 14, 7, 4, 13, 2, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_11(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_11(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 1, 14, 7, 12, 5, 2, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_12(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_12(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 9, 14, 7, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_13(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_13(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 1, 0), (1, 0, 3, 2), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 1, 14, 7, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_14(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2484, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x4248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_14(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8424, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x4842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 9, 14, 7, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_15(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2848, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x8284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_15(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4828, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x8482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 0, 1, 2), (1, 2, 3, 0), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 9, 2, 7, 0, 13, 6, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_16(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_16(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 0, 1, 2), (2, 3, 0, 1), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_17(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_17(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 0, 1), (1, 0, 3, 2), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 1, 10, 7, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_18(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x8424, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x4842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_18(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2484, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x4248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 13, 10, 7, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_19(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x4828, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x8482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_19(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2848, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x8284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_20(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_20(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_21(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2428, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_21(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2824, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_22(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2824, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_22(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2428, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_23(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_23(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1111)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_24(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x8281, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_24(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x8281, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_25(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x4281, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x2418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_25(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x8241, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x2814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_26(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x8241, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x2814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_26(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x4281, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x2418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_27(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x4241, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_27(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1122)
		| ROL16(x & 0x4241, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 2, 0, 3), (2, 3, 1, 0), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 13, 10, 7, 8, 5, 2, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_28(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1182)
		| ROL16(x & 0x4221, 4)
		| ROL16(x & 0x2844, 8)
		| ROL16(x & 0x8418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_28(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1182)
		| ROL16(x & 0x8841, 4)
		| ROL16(x & 0x4428, 8)
		| ROL16(x & 0x2214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 2, 0, 3), (3, 0, 2, 1), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 1, 10, 7, 4, 9, 2, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_29(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1142)
		| ROL16(x & 0x8221, 4)
		| ROL16(x & 0x2488, 8)
		| ROL16(x & 0x4814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_29(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1142)
		| ROL16(x & 0x4481, 4)
		| ROL16(x & 0x8824, 8)
		| ROL16(x & 0x2218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 3, 2, 0), (2, 0, 1, 3), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 1, 14, 7, 0, 5, 10, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_30(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1124)
		| ROL16(x & 0x2281, 4)
		| ROL16(x & 0x8842, 8)
		| ROL16(x & 0x4418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_30(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1124)
		| ROL16(x & 0x8441, 4)
		| ROL16(x & 0x4288, 8)
		| ROL16(x & 0x2812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 3, 2, 0), (3, 2, 0, 1), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 9, 14, 7, 4, 1, 10, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_31(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1128)
		| ROL16(x & 0x2241, 4)
		| ROL16(x & 0x4482, 8)
		| ROL16(x & 0x8814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_31(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1128)
		| ROL16(x & 0x4881, 4)
		| ROL16(x & 0x8244, 8)
		| ROL16(x & 0x2412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 0, 1, 3), (1, 3, 2, 0), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 13, 2, 7, 0, 9, 6, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_32(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1142)
		| ROL16(x & 0x4481, 4)
		| ROL16(x & 0x8824, 8)
		| ROL16(x & 0x2218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_32(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1142)
		| ROL16(x & 0x8221, 4)
		| ROL16(x & 0x2488, 8)
		| ROL16(x & 0x4814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 0, 1, 3), (3, 2, 0, 1), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 9, 2, 7, 8, 1, 6, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_33(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1182)
		| ROL16(x & 0x8841, 4)
		| ROL16(x & 0x4428, 8)
		| ROL16(x & 0x2214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_33(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1182)
		| ROL16(x & 0x4221, 4)
		| ROL16(x & 0x2844, 8)
		| ROL16(x & 0x8418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 0, 1), (1, 0, 2, 3), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 1, 14, 7, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_34(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x8481, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_34(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x8481, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 9, 14, 7, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_35(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x4841, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_35(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x4841, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_36(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x2481, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x4218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_36(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x8421, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x4812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_37(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1184)
		| ROL16(x & 0x2441, 4)
		| ROL16(x & 0x4822, 8)
		| ROL16(x & 0x8218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_37(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1184)
		| ROL16(x & 0x8821, 4)
		| ROL16(x & 0x2248, 8)
		| ROL16(x & 0x4412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_38(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1148)
		| ROL16(x & 0x2881, 4)
		| ROL16(x & 0x8422, 8)
		| ROL16(x & 0x4214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_38(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1148)
		| ROL16(x & 0x4421, 4)
		| ROL16(x & 0x2284, 8)
		| ROL16(x & 0x8812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_39(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x2841, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x8214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_39(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x4821, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x8412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 0, 2, 1), (1, 2, 0, 3), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 9, 2, 7, 4, 1, 10, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_40(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1124)
		| ROL16(x & 0x8441, 4)
		| ROL16(x & 0x4288, 8)
		| ROL16(x & 0x2812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_40(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1124)
		| ROL16(x & 0x2281, 4)
		| ROL16(x & 0x8842, 8)
		| ROL16(x & 0x4418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 0, 2, 1), (2, 3, 1, 0), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 13, 2, 7, 0, 5, 10, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_41(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1128)
		| ROL16(x & 0x4881, 4)
		| ROL16(x & 0x8244, 8)
		| ROL16(x & 0x2412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_41(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1128)
		| ROL16(x & 0x2241, 4)
		| ROL16(x & 0x4482, 8)
		| ROL16(x & 0x8814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 1, 10, 7, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_42(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x8421, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x4812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_42(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x2481, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x4218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 13, 10, 7, 4, 9, 2, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_43(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1148)
		| ROL16(x & 0x4421, 4)
		| ROL16(x & 0x2284, 8)
		| ROL16(x & 0x8812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_43(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1148)
		| ROL16(x & 0x2881, 4)
		| ROL16(x & 0x8422, 8)
		| ROL16(x & 0x4214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 1, 10, 7, 8, 5, 2, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_44(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1184)
		| ROL16(x & 0x8821, 4)
		| ROL16(x & 0x2248, 8)
		| ROL16(x & 0x4412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_44(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1184)
		| ROL16(x & 0x2441, 4)
		| ROL16(x & 0x4822, 8)
		| ROL16(x & 0x8218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 13, 10, 7, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_45(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x4821, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x8412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_45(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x2841, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x8214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 1, 0), (1, 0, 2, 3), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 1, 10, 7, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_46(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x2421, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_46(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1144)
		| ROL16(x & 0x2421, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 13, 10, 7, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_47(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x2821, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_47(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1188)
		| ROL16(x & 0x2821, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 0, 3, 2), (2, 3, 0, 1), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 13, 2, 11, 8, 1, 14, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_48(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8212, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_48(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8212, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 0, 3, 2), (3, 1, 2, 0), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 5, 2, 11, 0, 9, 14, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_49(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4212, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_49(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4212, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 1, 14, 11, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_50(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8214, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_50(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8412, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 5, 14, 11, 8, 13, 2, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_51(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1481)
		| ROL16(x & 0x4214, 4)
		| ROL16(x & 0x2842, 8)
		| ROL16(x & 0x8128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_51(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1481)
		| ROL16(x & 0x8812, 4)
		| ROL16(x & 0x4228, 8)
		| ROL16(x & 0x2144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 1, 14, 11, 12, 9, 2, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_52(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1841)
		| ROL16(x & 0x8218, 4)
		| ROL16(x & 0x2482, 8)
		| ROL16(x & 0x4124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_52(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1841)
		| ROL16(x & 0x4412, 4)
		| ROL16(x & 0x8224, 8)
		| ROL16(x & 0x2188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 5, 14, 11, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_53(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4218, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_53(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4812, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 2, 0), (2, 0, 3, 1), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 1, 14, 11, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_54(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1821)
		| ROL16(x & 0x2214, 4)
		| ROL16(x & 0x8442, 8)
		| ROL16(x & 0x4188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_54(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1821)
		| ROL16(x & 0x8418, 4)
		| ROL16(x & 0x4284, 8)
		| ROL16(x & 0x2142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 5, 14, 11, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_55(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1421)
		| ROL16(x & 0x2218, 4)
		| ROL16(x & 0x4882, 8)
		| ROL16(x & 0x8144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_55(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1421)
		| ROL16(x & 0x4814, 4)
		| ROL16(x & 0x8248, 8)
		| ROL16(x & 0x2182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_56(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8412, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_56(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8214, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_57(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1841)
		| ROL16(x & 0x4412, 4)
		| ROL16(x & 0x8224, 8)
		| ROL16(x & 0x2188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_57(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1841)
		| ROL16(x & 0x8218, 4)
		| ROL16(x & 0x2482, 8)
		| ROL16(x & 0x4124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_58(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1481)
		| ROL16(x & 0x8812, 4)
		| ROL16(x & 0x4228, 8)
		| ROL16(x & 0x2144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_58(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1481)
		| ROL16(x & 0x4214, 4)
		| ROL16(x & 0x2842, 8)
		| ROL16(x & 0x8128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_59(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4812, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_59(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4218, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 1, 3, 0), (1, 3, 0, 2), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 13, 6, 11, 8, 1, 14, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_60(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1281)
		| ROL16(x & 0x2412, 4)
		| ROL16(x & 0x4824, 8)
		| ROL16(x & 0x8148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_60(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1281)
		| ROL16(x & 0x8814, 4)
		| ROL16(x & 0x2448, 8)
		| ROL16(x & 0x4122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 1, 3, 0), (3, 0, 2, 1), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 1, 6, 11, 0, 9, 14, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_61(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1241)
		| ROL16(x & 0x2812, 4)
		| ROL16(x & 0x8428, 8)
		| ROL16(x & 0x4184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_61(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1241)
		| ROL16(x & 0x4418, 4)
		| ROL16(x & 0x2884, 8)
		| ROL16(x & 0x8122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 3, 0, 1), (1, 0, 3, 2), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 1, 14, 11, 8, 13, 2, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_62(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8414, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_62(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1881)
		| ROL16(x & 0x8414, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 3, 0, 1), (3, 1, 2, 0), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 5, 14, 11, 12, 9, 2, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_63(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4818, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_63(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1441)
		| ROL16(x & 0x4818, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 0, 2, 1), (1, 3, 0, 2), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 13, 2, 11, 12, 1, 10, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_64(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1821)
		| ROL16(x & 0x8418, 4)
		| ROL16(x & 0x4284, 8)
		| ROL16(x & 0x2142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_64(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1821)
		| ROL16(x & 0x2214, 4)
		| ROL16(x & 0x8442, 8)
		| ROL16(x & 0x4188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 0, 2, 1), (2, 1, 3, 0), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 5, 2, 11, 0, 13, 10, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_65(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1421)
		| ROL16(x & 0x4814, 4)
		| ROL16(x & 0x8248, 8)
		| ROL16(x & 0x2182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_65(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1421)
		| ROL16(x & 0x2218, 4)
		| ROL16(x & 0x4882, 8)
		| ROL16(x & 0x8144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 13, 6, 11, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_66(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1241)
		| ROL16(x & 0x4418, 4)
		| ROL16(x & 0x2884, 8)
		| ROL16(x & 0x8122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_66(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1241)
		| ROL16(x & 0x2812, 4)
		| ROL16(x & 0x8428, 8)
		| ROL16(x & 0x4184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 0, 2), (2, 0, 3, 1), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 1, 6, 11, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_67(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1281)
		| ROL16(x & 0x8814, 4)
		| ROL16(x & 0x2448, 8)
		| ROL16(x & 0x4122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_67(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1281)
		| ROL16(x & 0x2412, 4)
		| ROL16(x & 0x4824, 8)
		| ROL16(x & 0x8148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_68(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2414, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_68(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2414, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_69(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2418, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_69(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2814, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_70(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2814, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_70(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2418, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_71(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2818, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_71(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1221)
		| ROL16(x & 0x2818, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 0, 2, 3), (2, 3, 1, 0), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 13, 2, 11, 0, 5, 10, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_72(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1822)
		| ROL16(x & 0x4211, 4)
		| ROL16(x & 0x8144, 8)
		| ROL16(x & 0x2488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_72(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1822)
		| ROL16(x & 0x8248, 4)
		| ROL16(x & 0x4481, 8)
		| ROL16(x & 0x2114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 0, 2, 3), (3, 1, 0, 2), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 5, 2, 11, 4, 1, 10, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_73(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1422)
		| ROL16(x & 0x8211, 4)
		| ROL16(x & 0x4188, 8)
		| ROL16(x & 0x2844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_73(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1422)
		| ROL16(x & 0x4284, 4)
		| ROL16(x & 0x8841, 8)
		| ROL16(x & 0x2118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 0, 2), (2, 0, 1, 3), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 1, 14, 11, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_74(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1884)
		| ROL16(x & 0x8211, 4)
		| ROL16(x & 0x2142, 8)
		| ROL16(x & 0x4428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_74(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1884)
		| ROL16(x & 0x8442, 4)
		| ROL16(x & 0x4221, 8)
		| ROL16(x & 0x2118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 5, 14, 11, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_75(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1448)
		| ROL16(x & 0x4211, 4)
		| ROL16(x & 0x2182, 8)
		| ROL16(x & 0x8824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_75(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1448)
		| ROL16(x & 0x4882, 4)
		| ROL16(x & 0x8221, 8)
		| ROL16(x & 0x2114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_76(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1824)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x8142, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_76(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1824)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4281, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_77(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1424)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x4142, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_77(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1424)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4241, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_78(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1828)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x8182, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_78(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1828)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8281, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_79(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1428)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x4182, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_79(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1428)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8241, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_80(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1882)
		| ROL16(x & 0x8411, 4)
		| ROL16(x & 0x4124, 8)
		| ROL16(x & 0x2248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_80(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1882)
		| ROL16(x & 0x8224, 4)
		| ROL16(x & 0x2441, 8)
		| ROL16(x & 0x4118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_81(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1842)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x8124, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_81(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1842)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2481, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_82(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1482)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x4128, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_82(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1482)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2841, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_83(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1442)
		| ROL16(x & 0x4811, 4)
		| ROL16(x & 0x8128, 8)
		| ROL16(x & 0x2284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_83(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1442)
		| ROL16(x & 0x4228, 4)
		| ROL16(x & 0x2881, 8)
		| ROL16(x & 0x8114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 1, 0, 3), (1, 3, 2, 0), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 13, 6, 11, 4, 9, 2, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_84(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1242)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x2124, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_84(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1242)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2421, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 1, 0, 3), (3, 0, 1, 2), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 1, 6, 11, 8, 5, 2, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_85(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1282)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x2128, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_85(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1282)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2821, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 3, 1, 0), (1, 0, 2, 3), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 1, 14, 11, 0, 9, 6, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_86(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1844)
		| ROL16(x & 0x2411, 4)
		| ROL16(x & 0x8122, 8)
		| ROL16(x & 0x4288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_86(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1844)
		| ROL16(x & 0x8428, 4)
		| ROL16(x & 0x2281, 8)
		| ROL16(x & 0x4112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 3, 1, 0), (3, 1, 0, 2), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 5, 14, 11, 8, 1, 6, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_87(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1488)
		| ROL16(x & 0x2811, 4)
		| ROL16(x & 0x4122, 8)
		| ROL16(x & 0x8244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_87(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1488)
		| ROL16(x & 0x4824, 4)
		| ROL16(x & 0x2241, 8)
		| ROL16(x & 0x8112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 0, 1, 2), (1, 3, 2, 0), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 13, 2, 11, 0, 9, 6, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_88(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1848)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x8184, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_88(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1848)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8481, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 0, 1, 2), (2, 1, 0, 3), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 5, 2, 11, 8, 1, 6, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_89(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1484)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x4148, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_89(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1484)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4841, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 1, 6, 11, 4, 9, 2, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_90(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1244)
		| ROL16(x & 0x8411, 4)
		| ROL16(x & 0x2188, 8)
		| ROL16(x & 0x4822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_90(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1244)
		| ROL16(x & 0x2482, 4)
		| ROL16(x & 0x8821, 8)
		| ROL16(x & 0x4118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 13, 6, 11, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_91(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1248)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x2184, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_91(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1248)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8421, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 1, 6, 11, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_92(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1284)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x2148, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_92(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1284)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4821, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 13, 6, 11, 8, 5, 2, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_93(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1288)
		| ROL16(x & 0x4811, 4)
		| ROL16(x & 0x2144, 8)
		| ROL16(x & 0x8422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_93(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1288)
		| ROL16(x & 0x2842, 4)
		| ROL16(x & 0x4421, 8)
		| ROL16(x & 0x8114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 13, 6, 11, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_94(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1228)
		| ROL16(x & 0x2411, 4)
		| ROL16(x & 0x4184, 8)
		| ROL16(x & 0x8842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_94(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1228)
		| ROL16(x & 0x2884, 4)
		| ROL16(x & 0x8441, 8)
		| ROL16(x & 0x4112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 2, 0), (2, 0, 1, 3), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 1, 6, 11, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_95(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1224)
		| ROL16(x & 0x2811, 4)
		| ROL16(x & 0x8148, 8)
		| ROL16(x & 0x4482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_95(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1224)
		| ROL16(x & 0x2448, 4)
		| ROL16(x & 0x4881, 8)
		| ROL16(x & 0x8112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 0, 2, 3), (2, 1, 3, 0), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 5, 2, 15, 0, 13, 10, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_96(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1422)
		| ROL16(x & 0x4284, 4)
		| ROL16(x & 0x8841, 8)
		| ROL16(x & 0x2118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_96(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1422)
		| ROL16(x & 0x8211, 4)
		| ROL16(x & 0x4188, 8)
		| ROL16(x & 0x2844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 0, 2, 3), (3, 2, 0, 1), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 9, 2, 15, 12, 1, 10, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_97(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1822)
		| ROL16(x & 0x8248, 4)
		| ROL16(x & 0x4481, 8)
		| ROL16(x & 0x2114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_97(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1822)
		| ROL16(x & 0x4211, 4)
		| ROL16(x & 0x8144, 8)
		| ROL16(x & 0x2488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 1, 10, 15, 8, 13, 2, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_98(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1882)
		| ROL16(x & 0x8224, 4)
		| ROL16(x & 0x2441, 8)
		| ROL16(x & 0x4118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_98(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1882)
		| ROL16(x & 0x8411, 4)
		| ROL16(x & 0x4124, 8)
		| ROL16(x & 0x2248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 5, 10, 15, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_99(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1482)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2841, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_99(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1482)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x4128, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 1, 10, 15, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_100(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1842)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2481, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_100(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1842)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x8124, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 5, 10, 15, 12, 9, 2, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_101(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1442)
		| ROL16(x & 0x4228, 4)
		| ROL16(x & 0x2881, 8)
		| ROL16(x & 0x8114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_101(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1442)
		| ROL16(x & 0x4811, 4)
		| ROL16(x & 0x8128, 8)
		| ROL16(x & 0x2284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 5, 10, 15, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_102(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1484)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4841, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_102(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1484)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x4148, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 3, 0), (3, 0, 2, 1), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 1, 10, 15, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_103(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1848)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8481, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_103(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1848)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x8184, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 0, 3, 1), (1, 2, 0, 3), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 9, 2, 15, 8, 1, 14, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_104(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1884)
		| ROL16(x & 0x8442, 4)
		| ROL16(x & 0x4221, 8)
		| ROL16(x & 0x2118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_104(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1884)
		| ROL16(x & 0x8211, 4)
		| ROL16(x & 0x2142, 8)
		| ROL16(x & 0x4428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 0, 3, 1), (3, 1, 2, 0), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 5, 2, 15, 0, 9, 14, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_105(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1448)
		| ROL16(x & 0x4882, 4)
		| ROL16(x & 0x8221, 8)
		| ROL16(x & 0x2114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_105(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1448)
		| ROL16(x & 0x4211, 4)
		| ROL16(x & 0x2182, 8)
		| ROL16(x & 0x8824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 9, 6, 15, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_106(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1282)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2821, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_106(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1282)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x2128, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 0, 3), (3, 0, 2, 1), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 1, 6, 15, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_107(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1242)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2421, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_107(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1242)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x2124, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_108(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1244)
		| ROL16(x & 0x2482, 4)
		| ROL16(x & 0x8821, 8)
		| ROL16(x & 0x4118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_108(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1244)
		| ROL16(x & 0x8411, 4)
		| ROL16(x & 0x2188, 8)
		| ROL16(x & 0x4822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_109(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1284)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4821, 8)
		| ROL16(x & 0x8118, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_109(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1284)
		| ROL16(x & 0x8811, 4)
		| ROL16(x & 0x2148, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_110(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1248)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8421, 8)
		| ROL16(x & 0x4114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_110(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1248)
		| ROL16(x & 0x4411, 4)
		| ROL16(x & 0x2184, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_111(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1288)
		| ROL16(x & 0x2842, 4)
		| ROL16(x & 0x4421, 8)
		| ROL16(x & 0x8114, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_111(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1288)
		| ROL16(x & 0x4811, 4)
		| ROL16(x & 0x2144, 8)
		| ROL16(x & 0x8422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_112(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1824)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4281, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_112(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1824)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x8142, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_113(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1828)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8281, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_113(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1828)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x8182, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_114(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1424)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4241, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_114(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1424)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x4142, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_115(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1428)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8241, 8)
		| ROL16(x & 0x2112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_115(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1428)
		| ROL16(x & 0x2211, 4)
		| ROL16(x & 0x4182, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 1, 2, 0), (1, 2, 0, 3), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 9, 6, 15, 12, 1, 10, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_116(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1224)
		| ROL16(x & 0x2448, 4)
		| ROL16(x & 0x4881, 8)
		| ROL16(x & 0x8112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_116(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1224)
		| ROL16(x & 0x2811, 4)
		| ROL16(x & 0x8148, 8)
		| ROL16(x & 0x4482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 1, 2, 0), (2, 0, 3, 1), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 1, 6, 15, 0, 13, 10, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_117(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1228)
		| ROL16(x & 0x2884, 4)
		| ROL16(x & 0x8441, 8)
		| ROL16(x & 0x4112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_117(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1228)
		| ROL16(x & 0x2411, 4)
		| ROL16(x & 0x4184, 8)
		| ROL16(x & 0x8842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 2, 0, 1), (1, 0, 2, 3), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 1, 10, 15, 12, 9, 2, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_118(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1844)
		| ROL16(x & 0x8428, 4)
		| ROL16(x & 0x2281, 8)
		| ROL16(x & 0x4112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_118(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1844)
		| ROL16(x & 0x2411, 4)
		| ROL16(x & 0x8122, 8)
		| ROL16(x & 0x4288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 2, 0, 1), (2, 1, 3, 0), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 5, 10, 15, 8, 13, 2, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_119(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1488)
		| ROL16(x & 0x4824, 4)
		| ROL16(x & 0x2241, 8)
		| ROL16(x & 0x8112, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_119(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1488)
		| ROL16(x & 0x2811, 4)
		| ROL16(x & 0x4122, 8)
		| ROL16(x & 0x8244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 0, 3, 2), (2, 1, 0, 3), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 5, 2, 15, 4, 1, 14, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_120(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_120(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 0, 3, 2), (3, 2, 1, 0), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 9, 2, 15, 0, 5, 14, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_121(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_121(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 5, 10, 15, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_122(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1412)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2141, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_122(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1412)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4121, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 0, 3), (3, 0, 1, 2), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 1, 10, 15, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_123(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1812)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2181, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_123(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1812)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8121, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_124(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1814)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8141, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_124(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1814)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4181, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_125(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_125(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_126(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_126(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_127(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1418)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4181, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_127(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1418)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8141, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 0, 1, 3), (1, 2, 3, 0), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 9, 2, 15, 0, 13, 6, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_128(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1812)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8121, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_128(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1812)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2181, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 0, 1, 3), (3, 1, 0, 2), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 5, 2, 15, 12, 1, 6, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_129(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1412)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4121, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_129(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1412)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2141, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 1, 6, 15, 4, 13, 2, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_130(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_130(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 9, 6, 15, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_131(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_131(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 1, 6, 15, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_132(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_132(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 9, 6, 15, 12, 5, 2, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_133(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_133(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1212)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x2121, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 9, 6, 15, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_134(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1214)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4121, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_134(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1214)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2141, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 3, 0), (3, 0, 1, 2), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 1, 6, 15, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_135(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1218)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8121, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_135(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1218)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2181, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_136(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1814)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4181, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_136(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1814)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8141, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_137(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_137(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_138(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_138(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_139(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1418)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8141, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_139(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1418)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4181, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 1, 0, 2), (1, 2, 3, 0), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 9, 6, 15, 4, 13, 2, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_140(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1218)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2181, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_140(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1218)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8121, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 1, 0, 2), (2, 0, 1, 3), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 1, 6, 15, 12, 5, 2, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_141(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1214)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2141, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_141(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1214)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4121, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 2, 1, 0), (1, 0, 3, 2), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 1, 10, 15, 0, 13, 6, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_142(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_142(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1818)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x8181, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 2, 1, 0), (2, 1, 0, 3), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 5, 10, 15, 12, 1, 6, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_143(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_143(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x1414)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x4141, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_144(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x8182, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_144(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x8182, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_145(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x4182, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x1428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_145(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x8142, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x1824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_146(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x8142, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x1824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_146(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x4182, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x1428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_147(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x4142, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_147(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2211)
		| ROL16(x & 0x4142, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 2, 3, 1), (2, 3, 1, 0), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 13, 10, 3, 0, 5, 14, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_148(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2811)
		| ROL16(x & 0x4122, 4)
		| ROL16(x & 0x8244, 8)
		| ROL16(x & 0x1488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_148(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2811)
		| ROL16(x & 0x8148, 4)
		| ROL16(x & 0x4482, 8)
		| ROL16(x & 0x1224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 2, 3, 1), (3, 1, 0, 2), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 5, 10, 3, 4, 1, 14, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_149(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2411)
		| ROL16(x & 0x8122, 4)
		| ROL16(x & 0x4288, 8)
		| ROL16(x & 0x1844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_149(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2411)
		| ROL16(x & 0x4184, 4)
		| ROL16(x & 0x8842, 8)
		| ROL16(x & 0x1228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 3, 1, 2), (2, 1, 3, 0), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 5, 14, 3, 0, 13, 6, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_150(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2411)
		| ROL16(x & 0x4184, 4)
		| ROL16(x & 0x8842, 8)
		| ROL16(x & 0x1228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_150(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2411)
		| ROL16(x & 0x8122, 4)
		| ROL16(x & 0x4288, 8)
		| ROL16(x & 0x1844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 3, 1, 2), (3, 2, 0, 1), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 9, 14, 3, 12, 1, 6, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_151(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2811)
		| ROL16(x & 0x8148, 4)
		| ROL16(x & 0x4482, 8)
		| ROL16(x & 0x1224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_151(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2811)
		| ROL16(x & 0x4122, 4)
		| ROL16(x & 0x8244, 8)
		| ROL16(x & 0x1488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 1, 3, 0), (0, 3, 1, 2), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 13, 6, 3, 0, 5, 14, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_152(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4211)
		| ROL16(x & 0x2182, 4)
		| ROL16(x & 0x8824, 8)
		| ROL16(x & 0x1448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_152(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4211)
		| ROL16(x & 0x8144, 4)
		| ROL16(x & 0x2488, 8)
		| ROL16(x & 0x1822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 1, 3, 0), (3, 2, 0, 1), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 9, 6, 3, 4, 1, 14, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_153(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8211)
		| ROL16(x & 0x2142, 4)
		| ROL16(x & 0x4428, 8)
		| ROL16(x & 0x1884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_153(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8211)
		| ROL16(x & 0x4188, 4)
		| ROL16(x & 0x2844, 8)
		| ROL16(x & 0x1422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 0, 1), (0, 1, 3, 2), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 5, 14, 3, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_154(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x8184, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_154(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x8184, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 9, 14, 3, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_155(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x4148, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_155(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x4148, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 5, 14, 3, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_156(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x2184, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x1248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_156(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x8124, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x1842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 9, 14, 3, 0, 13, 6, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_157(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4811)
		| ROL16(x & 0x2144, 4)
		| ROL16(x & 0x8422, 8)
		| ROL16(x & 0x1288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_157(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4811)
		| ROL16(x & 0x8128, 4)
		| ROL16(x & 0x2284, 8)
		| ROL16(x & 0x1442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 5, 14, 3, 12, 1, 6, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_158(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8411)
		| ROL16(x & 0x2188, 4)
		| ROL16(x & 0x4822, 8)
		| ROL16(x & 0x1244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_158(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8411)
		| ROL16(x & 0x4124, 4)
		| ROL16(x & 0x2248, 8)
		| ROL16(x & 0x1882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 9, 14, 3, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_159(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x2148, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x1284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_159(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x4128, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x1482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 1, 0, 2), (0, 2, 3, 1), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 9, 6, 3, 4, 13, 2, 11, 0, 5, 10, 15]
void BOGI16_omega_diffusion_160(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4211)
		| ROL16(x & 0x8144, 4)
		| ROL16(x & 0x2488, 8)
		| ROL16(x & 0x1822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_160(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4211)
		| ROL16(x & 0x2182, 4)
		| ROL16(x & 0x8824, 8)
		| ROL16(x & 0x1448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 1, 0, 2), (2, 3, 1, 0), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 13, 6, 3, 12, 5, 2, 11, 4, 1, 10, 15]
void BOGI16_omega_diffusion_161(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8211)
		| ROL16(x & 0x4188, 4)
		| ROL16(x & 0x2844, 8)
		| ROL16(x & 0x1422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_161(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8211)
		| ROL16(x & 0x2142, 4)
		| ROL16(x & 0x4428, 8)
		| ROL16(x & 0x1884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_162(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x8124, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x1842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_162(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x2184, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x1248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 6, 15]
void BOGI16_omega_diffusion_163(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4811)
		| ROL16(x & 0x8128, 4)
		| ROL16(x & 0x2284, 8)
		| ROL16(x & 0x1442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_163(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4811)
		| ROL16(x & 0x2144, 4)
		| ROL16(x & 0x8422, 8)
		| ROL16(x & 0x1288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_164(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8411)
		| ROL16(x & 0x4124, 4)
		| ROL16(x & 0x2248, 8)
		| ROL16(x & 0x1882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_164(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8411)
		| ROL16(x & 0x2188, 4)
		| ROL16(x & 0x4822, 8)
		| ROL16(x & 0x1244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI16_omega_diffusion_165(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x4128, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x1482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_165(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x2148, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x1284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 1, 0), (0, 1, 3, 2), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 5, 10, 3, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI16_omega_diffusion_166(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x2124, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_166(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4411)
		| ROL16(x & 0x2124, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 13, 10, 3, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI16_omega_diffusion_167(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x2128, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_167(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8811)
		| ROL16(x & 0x2128, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_168(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_168(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_169(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4181, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x1418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_169(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8141, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x1814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_170(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8141, 4)
		| ROL16(x & 0x4488, 8)
		| ROL16(x & 0x1814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_170(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4181, 4)
		| ROL16(x & 0x8844, 8)
		| ROL16(x & 0x1418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_171(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_171(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 2, 1, 3), (2, 3, 0, 1), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 13, 10, 3, 8, 1, 6, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_172(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8121, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_172(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8121, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 2, 1, 3), (3, 1, 2, 0), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 5, 10, 3, 0, 9, 6, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_173(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4121, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_173(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4121, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 3, 2, 1), (2, 1, 0, 3), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 5, 14, 3, 4, 1, 10, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_174(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_174(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 3, 2, 1), (3, 2, 1, 0), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 9, 14, 3, 0, 5, 10, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_175(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_175(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 1, 0, 3), (0, 3, 2, 1), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 13, 6, 3, 4, 9, 2, 15, 0, 5, 14, 11]
void BOGI16_omega_diffusion_176(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_176(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 1, 0, 3), (3, 2, 1, 0), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 9, 6, 3, 8, 5, 2, 15, 4, 1, 14, 11]
void BOGI16_omega_diffusion_177(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_177(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_178(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_178(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8181, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_179(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8141, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_179(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8141, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_180(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4181, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_180(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4181, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_181(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_181(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4141, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 1, 0), (0, 1, 2, 3), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 5, 14, 3, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_182(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2181, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x1218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_182(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8121, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x1812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 9, 14, 3, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_183(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2141, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x1214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_183(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4121, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x1412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 1, 2, 0), (0, 2, 1, 3), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 9, 6, 3, 0, 5, 10, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_184(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2141, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_184(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2141, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 1, 2, 0), (2, 3, 0, 1), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 13, 6, 3, 4, 1, 10, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_185(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2181, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_185(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2181, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 0, 1), (0, 1, 2, 3), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 5, 10, 3, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI16_omega_diffusion_186(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8121, 4)
		| ROL16(x & 0x2288, 8)
		| ROL16(x & 0x1812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_186(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2181, 4)
		| ROL16(x & 0x8822, 8)
		| ROL16(x & 0x1218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 13, 10, 3, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI16_omega_diffusion_187(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4121, 4)
		| ROL16(x & 0x2244, 8)
		| ROL16(x & 0x1412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_187(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2141, 4)
		| ROL16(x & 0x4422, 8)
		| ROL16(x & 0x1214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 5, 10, 3, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_188(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_188(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 13, 10, 3, 0, 9, 6, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_189(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_189(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 5, 10, 3, 8, 1, 6, 15, 4, 13, 2, 11]
void BOGI16_omega_diffusion_190(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_190(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 13, 10, 3, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI16_omega_diffusion_191(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_191(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2121, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 1, 3, 2), (2, 3, 1, 0), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 13, 6, 11, 8, 5, 14, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_192(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2281)
		| ROL16(x & 0x4112, 4)
		| ROL16(x & 0x1844, 8)
		| ROL16(x & 0x8428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_192(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2281)
		| ROL16(x & 0x8842, 4)
		| ROL16(x & 0x4418, 8)
		| ROL16(x & 0x1124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 1, 3, 2), (3, 0, 2, 1), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 1, 6, 11, 4, 9, 14, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_193(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2241)
		| ROL16(x & 0x8112, 4)
		| ROL16(x & 0x1488, 8)
		| ROL16(x & 0x4824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_193(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2241)
		| ROL16(x & 0x4482, 4)
		| ROL16(x & 0x8814, 8)
		| ROL16(x & 0x1128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 1, 14, 11, 8, 13, 6, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_194(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2881)
		| ROL16(x & 0x8114, 4)
		| ROL16(x & 0x1442, 8)
		| ROL16(x & 0x4228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_194(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2881)
		| ROL16(x & 0x8422, 4)
		| ROL16(x & 0x4214, 8)
		| ROL16(x & 0x1148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 5, 14, 11, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_195(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2481)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1842, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_195(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2481)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x4218, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 1, 14, 11, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_196(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2841)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1482, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_196(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2841)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x8214, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 5, 14, 11, 12, 9, 6, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_197(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2441)
		| ROL16(x & 0x4118, 4)
		| ROL16(x & 0x1882, 8)
		| ROL16(x & 0x8224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_197(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2441)
		| ROL16(x & 0x4822, 4)
		| ROL16(x & 0x8218, 8)
		| ROL16(x & 0x1184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 2, 1), (2, 1, 3, 0), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 5, 14, 11, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_198(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2421)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1242, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_198(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2421)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4212, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 1, 14, 11, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_199(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2821)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1282, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_199(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2821)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8212, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 0, 3, 1), (0, 3, 1, 2), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 13, 2, 11, 8, 5, 14, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_200(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4881)
		| ROL16(x & 0x8112, 4)
		| ROL16(x & 0x1224, 8)
		| ROL16(x & 0x2448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_200(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4881)
		| ROL16(x & 0x8244, 4)
		| ROL16(x & 0x2412, 8)
		| ROL16(x & 0x1128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 0, 3, 1), (3, 1, 2, 0), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 5, 2, 11, 4, 9, 14, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_201(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8441)
		| ROL16(x & 0x4112, 4)
		| ROL16(x & 0x1228, 8)
		| ROL16(x & 0x2884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_201(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8441)
		| ROL16(x & 0x4288, 4)
		| ROL16(x & 0x2812, 8)
		| ROL16(x & 0x1124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_202(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4281)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1824, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_202(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4281)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x2418, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_203(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4241)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1424, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_203(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4241)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2414, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_204(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8281)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1828, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_204(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8281)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2818, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_205(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8241)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1428, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_205(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8241)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x2814, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 3, 1, 0), (0, 1, 3, 2), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 5, 14, 11, 8, 13, 6, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_206(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4481)
		| ROL16(x & 0x2114, 4)
		| ROL16(x & 0x1822, 8)
		| ROL16(x & 0x8248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_206(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4481)
		| ROL16(x & 0x8824, 4)
		| ROL16(x & 0x2218, 8)
		| ROL16(x & 0x1142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 3, 1, 0), (3, 0, 2, 1), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 1, 14, 11, 12, 9, 6, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_207(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8841)
		| ROL16(x & 0x2118, 4)
		| ROL16(x & 0x1422, 8)
		| ROL16(x & 0x4284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_207(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8841)
		| ROL16(x & 0x4428, 4)
		| ROL16(x & 0x2214, 8)
		| ROL16(x & 0x1182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 13, 2, 11, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_208(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4841)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1484, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_208(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4841)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8414, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 1, 2), (2, 1, 3, 0), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 5, 2, 11, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_209(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8481)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1848, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_209(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8481)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4818, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_210(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4421)
		| ROL16(x & 0x8114, 4)
		| ROL16(x & 0x1288, 8)
		| ROL16(x & 0x2842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_210(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4421)
		| ROL16(x & 0x2284, 4)
		| ROL16(x & 0x8812, 8)
		| ROL16(x & 0x1148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_211(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4821)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1284, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_211(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4821)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x8412, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_212(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8421)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1248, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_212(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8421)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x4812, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_213(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8821)
		| ROL16(x & 0x4118, 4)
		| ROL16(x & 0x1244, 8)
		| ROL16(x & 0x2482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_213(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8821)
		| ROL16(x & 0x2248, 4)
		| ROL16(x & 0x4412, 8)
		| ROL16(x & 0x1184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 1, 2, 0), (0, 3, 1, 2), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 13, 6, 11, 12, 5, 10, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_214(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4221)
		| ROL16(x & 0x2118, 4)
		| ROL16(x & 0x1884, 8)
		| ROL16(x & 0x8442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_214(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4221)
		| ROL16(x & 0x2844, 4)
		| ROL16(x & 0x8418, 8)
		| ROL16(x & 0x1182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 1, 2, 0), (2, 0, 3, 1), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 1, 6, 11, 4, 13, 10, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_215(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8221)
		| ROL16(x & 0x2114, 4)
		| ROL16(x & 0x1448, 8)
		| ROL16(x & 0x4882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_215(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8221)
		| ROL16(x & 0x2488, 4)
		| ROL16(x & 0x4814, 8)
		| ROL16(x & 0x1142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 1, 2, 3), (2, 3, 0, 1), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 13, 6, 11, 4, 1, 10, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_216(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_216(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 1, 2, 3), (3, 0, 1, 2), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_217(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_217(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 1, 2), (2, 1, 0, 3), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 5, 14, 11, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_218(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2484)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4842, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_218(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2484)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x4248, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 1, 14, 11, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_219(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2848)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8482, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_219(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2848)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x8284, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_220(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2824)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8242, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_220(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2824)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4282, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_221(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_221(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_222(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_222(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_223(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2428)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4282, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_223(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2428)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8242, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 0, 1, 3), (0, 3, 2, 1), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 13, 2, 11, 0, 9, 6, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_224(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4842)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8424, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_224(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4842)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2484, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 0, 1, 3), (3, 1, 0, 2), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 5, 2, 11, 8, 1, 6, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_225(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8482)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4828, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_225(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8482)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2848, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_226(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4282)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2824, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_226(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4282)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x2428, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_227(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_227(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_228(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_228(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_229(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8242)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2428, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_229(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8242)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x2824, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 3, 0, 1), (0, 1, 2, 3), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 5, 14, 11, 4, 9, 2, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_230(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_230(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 3, 0, 1), (3, 0, 1, 2), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 1, 14, 11, 8, 5, 2, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_231(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_231(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 5, 2, 11, 0, 9, 6, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_232(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_232(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 13, 2, 11, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_233(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_233(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 5, 2, 11, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_234(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_234(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 13, 2, 11, 8, 1, 6, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_235(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_235(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 13, 2, 11, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_236(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4828)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8284, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_236(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4828)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x8482, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 2, 1), (2, 1, 0, 3), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 5, 2, 11, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_237(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8424)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4248, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_237(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8424)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x4842, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 1, 0, 2), (0, 3, 2, 1), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 13, 6, 11, 4, 9, 2, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_238(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4248)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2484, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_238(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4248)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8424, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 1, 0, 2), (2, 0, 1, 3), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 1, 6, 11, 8, 5, 2, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_239(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8284)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2848, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_239(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8284)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4828, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 1, 2, 3), (2, 0, 3, 1), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 1, 6, 15, 4, 13, 10, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_240(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8184, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_240(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8481, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 1, 2, 3), (3, 2, 1, 0), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 9, 6, 15, 12, 5, 10, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_241(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4148, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_241(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4841, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 1, 10, 15, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_242(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8124, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_242(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8421, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 5, 10, 15, 8, 13, 6, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_243(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2482)
		| ROL16(x & 0x4124, 4)
		| ROL16(x & 0x1841, 8)
		| ROL16(x & 0x8218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_243(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2482)
		| ROL16(x & 0x8821, 4)
		| ROL16(x & 0x4118, 8)
		| ROL16(x & 0x1244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 1, 10, 15, 12, 9, 6, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_244(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2842)
		| ROL16(x & 0x8128, 4)
		| ROL16(x & 0x1481, 8)
		| ROL16(x & 0x4214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_244(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2842)
		| ROL16(x & 0x4421, 4)
		| ROL16(x & 0x8114, 8)
		| ROL16(x & 0x1288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 5, 10, 15, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_245(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4128, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_245(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4821, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 1, 10, 15, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_246(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2884)
		| ROL16(x & 0x8122, 4)
		| ROL16(x & 0x1241, 8)
		| ROL16(x & 0x4418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_246(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2884)
		| ROL16(x & 0x8441, 4)
		| ROL16(x & 0x4112, 8)
		| ROL16(x & 0x1228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 3, 1), (3, 1, 2, 0), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 5, 10, 15, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_247(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2448)
		| ROL16(x & 0x4122, 4)
		| ROL16(x & 0x1281, 8)
		| ROL16(x & 0x8814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_247(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2448)
		| ROL16(x & 0x4881, 4)
		| ROL16(x & 0x8112, 8)
		| ROL16(x & 0x1224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 9, 2, 15, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_248(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4882)
		| ROL16(x & 0x8144, 4)
		| ROL16(x & 0x1421, 8)
		| ROL16(x & 0x2218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_248(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4882)
		| ROL16(x & 0x8221, 4)
		| ROL16(x & 0x2114, 8)
		| ROL16(x & 0x1448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 1, 3), (3, 1, 2, 0), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 5, 2, 15, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_249(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8442)
		| ROL16(x & 0x4188, 4)
		| ROL16(x & 0x1821, 8)
		| ROL16(x & 0x2214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_249(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8442)
		| ROL16(x & 0x4221, 4)
		| ROL16(x & 0x2118, 8)
		| ROL16(x & 0x1884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_250(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8182, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_250(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8281, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_251(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8142, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_251(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8241, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_252(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4182, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_252(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4281, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_253(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4142, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_253(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4241, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 1, 3, 0), (0, 2, 1, 3), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 9, 6, 15, 8, 5, 14, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_254(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4284)
		| ROL16(x & 0x2142, 4)
		| ROL16(x & 0x1821, 8)
		| ROL16(x & 0x8418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_254(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4284)
		| ROL16(x & 0x8841, 4)
		| ROL16(x & 0x2118, 8)
		| ROL16(x & 0x1422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 1, 3, 0), (3, 0, 2, 1), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 1, 6, 15, 4, 9, 14, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_255(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8248)
		| ROL16(x & 0x2182, 4)
		| ROL16(x & 0x1421, 8)
		| ROL16(x & 0x4814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_255(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8248)
		| ROL16(x & 0x4481, 4)
		| ROL16(x & 0x2114, 8)
		| ROL16(x & 0x1822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 0, 2, 1), (0, 2, 1, 3), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 9, 2, 15, 12, 5, 10, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_256(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4824)
		| ROL16(x & 0x8148, 4)
		| ROL16(x & 0x1281, 8)
		| ROL16(x & 0x2412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_256(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4824)
		| ROL16(x & 0x2241, 4)
		| ROL16(x & 0x8112, 8)
		| ROL16(x & 0x1488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 0, 2, 1), (2, 1, 3, 0), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 5, 2, 15, 4, 13, 10, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_257(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8428)
		| ROL16(x & 0x4184, 4)
		| ROL16(x & 0x1241, 8)
		| ROL16(x & 0x2812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_257(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8428)
		| ROL16(x & 0x2281, 4)
		| ROL16(x & 0x4112, 8)
		| ROL16(x & 0x1844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_258(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2148, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_258(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2841, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_259(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4228)
		| ROL16(x & 0x2144, 4)
		| ROL16(x & 0x1481, 8)
		| ROL16(x & 0x8812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_259(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4228)
		| ROL16(x & 0x2881, 4)
		| ROL16(x & 0x8114, 8)
		| ROL16(x & 0x1442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_260(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8224)
		| ROL16(x & 0x2188, 4)
		| ROL16(x & 0x1841, 8)
		| ROL16(x & 0x4412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_260(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8224)
		| ROL16(x & 0x2441, 4)
		| ROL16(x & 0x4118, 8)
		| ROL16(x & 0x1882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_261(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2184, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_261(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2481, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 2, 1, 0), (0, 1, 2, 3), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 5, 10, 15, 12, 9, 6, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_262(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2128, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_262(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2821, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 2, 1, 0), (2, 0, 3, 1), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 1, 10, 15, 8, 13, 6, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_263(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2124, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_263(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2421, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 1, 3, 2), (2, 0, 1, 3), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 1, 6, 15, 0, 5, 14, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_264(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2214)
		| ROL16(x & 0x1182, 4)
		| ROL16(x & 0x8841, 8)
		| ROL16(x & 0x4428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_264(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2214)
		| ROL16(x & 0x8442, 4)
		| ROL16(x & 0x4188, 8)
		| ROL16(x & 0x1821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 1, 3, 2), (3, 2, 0, 1), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 9, 6, 15, 4, 1, 14, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_265(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2218)
		| ROL16(x & 0x1142, 4)
		| ROL16(x & 0x4481, 8)
		| ROL16(x & 0x8824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_265(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2218)
		| ROL16(x & 0x4882, 4)
		| ROL16(x & 0x8144, 8)
		| ROL16(x & 0x1421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 1, 10, 15, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_266(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2812)
		| ROL16(x & 0x1124, 4)
		| ROL16(x & 0x8441, 8)
		| ROL16(x & 0x4288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_266(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2812)
		| ROL16(x & 0x8428, 4)
		| ROL16(x & 0x4184, 8)
		| ROL16(x & 0x1241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 1, 3), (3, 1, 0, 2), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 5, 10, 15, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_267(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2412)
		| ROL16(x & 0x1128, 4)
		| ROL16(x & 0x4881, 8)
		| ROL16(x & 0x8244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_267(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2412)
		| ROL16(x & 0x4824, 4)
		| ROL16(x & 0x8148, 8)
		| ROL16(x & 0x1281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_268(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2814)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x8241, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_268(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2814)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4182, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_269(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2414)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x4241, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_269(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2414)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4142, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_270(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2818)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x8281, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_270(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2818)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8182, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_271(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2418)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x4281, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_271(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2418)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8142, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 5, 2, 15, 0, 13, 6, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_272(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4412)
		| ROL16(x & 0x1184, 4)
		| ROL16(x & 0x8821, 8)
		| ROL16(x & 0x2248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_272(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4412)
		| ROL16(x & 0x8224, 4)
		| ROL16(x & 0x2188, 8)
		| ROL16(x & 0x1841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 9, 2, 15, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_273(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4812)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x8421, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_273(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4812)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2184, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 5, 2, 15, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_274(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8412)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x4821, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_274(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8412)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2148, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 9, 2, 15, 12, 1, 6, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_275(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8812)
		| ROL16(x & 0x1148, 4)
		| ROL16(x & 0x4421, 8)
		| ROL16(x & 0x2284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_275(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8812)
		| ROL16(x & 0x4228, 4)
		| ROL16(x & 0x2144, 8)
		| ROL16(x & 0x1481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 9, 2, 15, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_276(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4814)
		| ROL16(x & 0x1142, 4)
		| ROL16(x & 0x8221, 8)
		| ROL16(x & 0x2488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_276(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4814)
		| ROL16(x & 0x8248, 4)
		| ROL16(x & 0x2182, 8)
		| ROL16(x & 0x1421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 3, 1), (3, 1, 0, 2), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 5, 2, 15, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_277(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8418)
		| ROL16(x & 0x1182, 4)
		| ROL16(x & 0x4221, 8)
		| ROL16(x & 0x2844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_277(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8418)
		| ROL16(x & 0x4284, 4)
		| ROL16(x & 0x2142, 8)
		| ROL16(x & 0x1821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 1, 0, 3), (0, 2, 3, 1), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 9, 6, 15, 4, 13, 2, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_278(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4212)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x2421, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_278(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4212)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2124, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 1, 0, 3), (3, 0, 1, 2), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 1, 6, 15, 12, 5, 2, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_279(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8212)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x2821, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_279(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8212)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2128, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 0, 1, 2), (0, 2, 3, 1), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 9, 2, 15, 0, 13, 6, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_280(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4818)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x8481, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_280(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4818)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8184, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 0, 1, 2), (2, 1, 0, 3), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 5, 2, 15, 12, 1, 6, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_281(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8414)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x4841, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_281(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8414)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4148, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_282(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4214)
		| ROL16(x & 0x1148, 4)
		| ROL16(x & 0x2881, 8)
		| ROL16(x & 0x8422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_282(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4214)
		| ROL16(x & 0x2842, 4)
		| ROL16(x & 0x8128, 8)
		| ROL16(x & 0x1481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_283(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4218)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x2481, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_283(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4218)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8124, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_284(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8214)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x2841, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_284(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8214)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4128, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_285(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8218)
		| ROL16(x & 0x1184, 4)
		| ROL16(x & 0x2441, 8)
		| ROL16(x & 0x4822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_285(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8218)
		| ROL16(x & 0x2482, 4)
		| ROL16(x & 0x4124, 8)
		| ROL16(x & 0x1841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 2, 0, 1), (0, 1, 3, 2), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 5, 10, 15, 4, 13, 2, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_286(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4418)
		| ROL16(x & 0x1124, 4)
		| ROL16(x & 0x2281, 8)
		| ROL16(x & 0x8842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_286(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4418)
		| ROL16(x & 0x2884, 4)
		| ROL16(x & 0x8122, 8)
		| ROL16(x & 0x1241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 2, 0, 1), (2, 0, 1, 3), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 1, 10, 15, 12, 5, 2, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_287(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8814)
		| ROL16(x & 0x1128, 4)
		| ROL16(x & 0x2241, 8)
		| ROL16(x & 0x4482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_287(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8814)
		| ROL16(x & 0x2448, 4)
		| ROL16(x & 0x4122, 8)
		| ROL16(x & 0x1281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 1, 3, 2), (1, 3, 2, 0), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 13, 6, 3, 0, 9, 14, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_288(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2241)
		| ROL16(x & 0x4482, 4)
		| ROL16(x & 0x8814, 8)
		| ROL16(x & 0x1128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_288(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2241)
		| ROL16(x & 0x8112, 4)
		| ROL16(x & 0x1488, 8)
		| ROL16(x & 0x4824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 1, 3, 2), (3, 2, 0, 1), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 9, 6, 3, 8, 1, 14, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_289(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2281)
		| ROL16(x & 0x8842, 4)
		| ROL16(x & 0x4418, 8)
		| ROL16(x & 0x1124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_289(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2281)
		| ROL16(x & 0x4112, 4)
		| ROL16(x & 0x1844, 8)
		| ROL16(x & 0x8428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_290(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2881)
		| ROL16(x & 0x8422, 4)
		| ROL16(x & 0x4214, 8)
		| ROL16(x & 0x1148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_290(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2881)
		| ROL16(x & 0x8114, 4)
		| ROL16(x & 0x1442, 8)
		| ROL16(x & 0x4228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_291(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2841)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x8214, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_291(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2841)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1482, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_292(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2481)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x4218, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_292(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2481)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1842, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_293(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2441)
		| ROL16(x & 0x4822, 4)
		| ROL16(x & 0x8218, 8)
		| ROL16(x & 0x1184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_293(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2441)
		| ROL16(x & 0x4118, 4)
		| ROL16(x & 0x1882, 8)
		| ROL16(x & 0x8224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 3, 2, 1), (1, 2, 3, 0), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 9, 14, 3, 0, 13, 10, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_294(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2821)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8212, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_294(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2821)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1282, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 3, 2, 1), (3, 1, 0, 2), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 5, 14, 3, 12, 1, 10, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_295(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2421)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4212, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_295(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2421)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1242, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 2, 3, 0), (0, 3, 2, 1), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 13, 10, 3, 0, 9, 14, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_296(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4841)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8414, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_296(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4841)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1484, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 2, 3, 0), (3, 1, 0, 2), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 5, 10, 3, 8, 1, 14, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_297(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8481)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4818, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_297(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8481)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1848, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 0, 2), (0, 2, 3, 1), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 9, 14, 3, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_298(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4881)
		| ROL16(x & 0x8244, 4)
		| ROL16(x & 0x2412, 8)
		| ROL16(x & 0x1128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_298(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4881)
		| ROL16(x & 0x8112, 4)
		| ROL16(x & 0x1224, 8)
		| ROL16(x & 0x2448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 5, 14, 3, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_299(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8441)
		| ROL16(x & 0x4288, 4)
		| ROL16(x & 0x2812, 8)
		| ROL16(x & 0x1124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_299(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8441)
		| ROL16(x & 0x4112, 4)
		| ROL16(x & 0x1228, 8)
		| ROL16(x & 0x2884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 5, 14, 3, 0, 13, 10, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_300(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4421)
		| ROL16(x & 0x2284, 4)
		| ROL16(x & 0x8812, 8)
		| ROL16(x & 0x1148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_300(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4421)
		| ROL16(x & 0x8114, 4)
		| ROL16(x & 0x1288, 8)
		| ROL16(x & 0x2842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 9, 14, 3, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_301(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4821)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x8412, 8)
		| ROL16(x & 0x1188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_301(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4821)
		| ROL16(x & 0x8118, 4)
		| ROL16(x & 0x1284, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 5, 14, 3, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_302(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8421)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x4812, 8)
		| ROL16(x & 0x1144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_302(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8421)
		| ROL16(x & 0x4114, 4)
		| ROL16(x & 0x1248, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 9, 14, 3, 12, 1, 10, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_303(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8821)
		| ROL16(x & 0x2248, 4)
		| ROL16(x & 0x4412, 8)
		| ROL16(x & 0x1184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_303(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8821)
		| ROL16(x & 0x4118, 4)
		| ROL16(x & 0x1244, 8)
		| ROL16(x & 0x2482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_304(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4281)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x2418, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_304(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4281)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1824, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 10, 15]
void BOGI16_omega_diffusion_305(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4241)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2414, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_305(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4241)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1424, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_306(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8281)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2818, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_306(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8281)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1828, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI16_omega_diffusion_307(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8241)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x2814, 8)
		| ROL16(x & 0x1122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_307(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8241)
		| ROL16(x & 0x2112, 4)
		| ROL16(x & 0x1428, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 2, 0), (0, 2, 3, 1), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 9, 6, 3, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI16_omega_diffusion_308(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4221)
		| ROL16(x & 0x2844, 4)
		| ROL16(x & 0x8418, 8)
		| ROL16(x & 0x1182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_308(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4221)
		| ROL16(x & 0x2118, 4)
		| ROL16(x & 0x1884, 8)
		| ROL16(x & 0x8442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 13, 6, 3, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI16_omega_diffusion_309(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8221)
		| ROL16(x & 0x2488, 4)
		| ROL16(x & 0x4814, 8)
		| ROL16(x & 0x1142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_309(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8221)
		| ROL16(x & 0x2114, 4)
		| ROL16(x & 0x1448, 8)
		| ROL16(x & 0x4882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 2, 0, 1), (0, 1, 3, 2), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 5, 10, 3, 8, 13, 2, 7, 0, 9, 6, 15]
void BOGI16_omega_diffusion_310(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4481)
		| ROL16(x & 0x8824, 4)
		| ROL16(x & 0x2218, 8)
		| ROL16(x & 0x1142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_310(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4481)
		| ROL16(x & 0x2114, 4)
		| ROL16(x & 0x1822, 8)
		| ROL16(x & 0x8248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 2, 0, 1), (1, 3, 2, 0), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 13, 10, 3, 12, 9, 2, 7, 8, 1, 6, 15]
void BOGI16_omega_diffusion_311(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8841)
		| ROL16(x & 0x4428, 4)
		| ROL16(x & 0x2214, 8)
		| ROL16(x & 0x1182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_311(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8841)
		| ROL16(x & 0x2118, 4)
		| ROL16(x & 0x1422, 8)
		| ROL16(x & 0x4284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 1, 2, 3), (1, 3, 0, 2), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 13, 6, 3, 4, 1, 10, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_312(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8481, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_312(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8184, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 1, 2, 3), (3, 2, 1, 0), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 9, 6, 3, 0, 5, 10, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_313(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4841, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_313(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4148, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_314(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8421, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_314(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8124, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_315(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2842)
		| ROL16(x & 0x4421, 4)
		| ROL16(x & 0x8114, 8)
		| ROL16(x & 0x1288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_315(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2842)
		| ROL16(x & 0x8128, 4)
		| ROL16(x & 0x1481, 8)
		| ROL16(x & 0x4214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_316(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2482)
		| ROL16(x & 0x8821, 4)
		| ROL16(x & 0x4118, 8)
		| ROL16(x & 0x1244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_316(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2482)
		| ROL16(x & 0x4124, 4)
		| ROL16(x & 0x1841, 8)
		| ROL16(x & 0x8218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_317(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4821, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_317(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4128, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 3, 1, 2), (1, 2, 0, 3), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 9, 14, 3, 8, 1, 6, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_318(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2884)
		| ROL16(x & 0x8441, 4)
		| ROL16(x & 0x4112, 8)
		| ROL16(x & 0x1228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_318(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2884)
		| ROL16(x & 0x8122, 4)
		| ROL16(x & 0x1241, 8)
		| ROL16(x & 0x4418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 3, 1, 2), (3, 1, 2, 0), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 5, 14, 3, 0, 9, 6, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_319(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2448)
		| ROL16(x & 0x4881, 4)
		| ROL16(x & 0x8112, 8)
		| ROL16(x & 0x1224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_319(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2448)
		| ROL16(x & 0x4122, 4)
		| ROL16(x & 0x1281, 8)
		| ROL16(x & 0x8814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 2, 0, 3), (0, 3, 1, 2), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 13, 10, 3, 8, 5, 2, 15, 0, 9, 14, 7]
void BOGI16_omega_diffusion_320(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4882)
		| ROL16(x & 0x8221, 4)
		| ROL16(x & 0x2114, 8)
		| ROL16(x & 0x1448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_320(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4882)
		| ROL16(x & 0x8144, 4)
		| ROL16(x & 0x1421, 8)
		| ROL16(x & 0x2218, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 2, 0, 3), (3, 1, 2, 0), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 5, 10, 3, 4, 9, 2, 15, 8, 1, 14, 7]
void BOGI16_omega_diffusion_321(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8442)
		| ROL16(x & 0x4221, 4)
		| ROL16(x & 0x2118, 8)
		| ROL16(x & 0x1884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_321(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8442)
		| ROL16(x & 0x4188, 4)
		| ROL16(x & 0x1821, 8)
		| ROL16(x & 0x2214, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_322(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8281, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_322(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8182, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2818, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_323(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8241, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_323(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8142, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_324(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4281, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_324(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4182, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_325(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4241, 4)
		| ROL16(x & 0x2112, 8)
		| ROL16(x & 0x1424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_325(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4142, 4)
		| ROL16(x & 0x1221, 8)
		| ROL16(x & 0x2414, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 2, 0), (0, 2, 1, 3), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 9, 14, 3, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_326(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4824)
		| ROL16(x & 0x2241, 4)
		| ROL16(x & 0x8112, 8)
		| ROL16(x & 0x1488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_326(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4824)
		| ROL16(x & 0x8148, 4)
		| ROL16(x & 0x1281, 8)
		| ROL16(x & 0x2412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 5, 14, 3, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_327(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8428)
		| ROL16(x & 0x2281, 4)
		| ROL16(x & 0x4112, 8)
		| ROL16(x & 0x1844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_327(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8428)
		| ROL16(x & 0x4184, 4)
		| ROL16(x & 0x1241, 8)
		| ROL16(x & 0x2812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 0, 2), (0, 2, 1, 3), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 9, 6, 3, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI16_omega_diffusion_328(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4284)
		| ROL16(x & 0x8841, 4)
		| ROL16(x & 0x2118, 8)
		| ROL16(x & 0x1422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_328(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4284)
		| ROL16(x & 0x2142, 4)
		| ROL16(x & 0x1821, 8)
		| ROL16(x & 0x8418, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 13, 6, 3, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI16_omega_diffusion_329(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8248)
		| ROL16(x & 0x4481, 4)
		| ROL16(x & 0x2114, 8)
		| ROL16(x & 0x1822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_329(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8248)
		| ROL16(x & 0x2182, 4)
		| ROL16(x & 0x1421, 8)
		| ROL16(x & 0x4814, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 9, 6, 3, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_330(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2841, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_330(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2148, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 13, 6, 3, 0, 5, 10, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_331(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4228)
		| ROL16(x & 0x2881, 4)
		| ROL16(x & 0x8114, 8)
		| ROL16(x & 0x1442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_331(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4228)
		| ROL16(x & 0x2144, 4)
		| ROL16(x & 0x1481, 8)
		| ROL16(x & 0x8812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 9, 6, 3, 4, 1, 10, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_332(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8224)
		| ROL16(x & 0x2441, 4)
		| ROL16(x & 0x4118, 8)
		| ROL16(x & 0x1882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_332(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8224)
		| ROL16(x & 0x2188, 4)
		| ROL16(x & 0x1841, 8)
		| ROL16(x & 0x4412, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 13, 6, 3, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_333(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2481, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_333(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2184, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4812, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 2, 1, 0), (0, 1, 2, 3), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 5, 10, 3, 0, 9, 6, 15, 8, 13, 2, 7]
void BOGI16_omega_diffusion_334(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2821, 4)
		| ROL16(x & 0x8118, 8)
		| ROL16(x & 0x1282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_334(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2128, 4)
		| ROL16(x & 0x1881, 8)
		| ROL16(x & 0x8212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 2, 1, 0), (1, 3, 0, 2), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 13, 10, 3, 8, 1, 6, 15, 12, 9, 2, 7]
void BOGI16_omega_diffusion_335(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2421, 4)
		| ROL16(x & 0x4114, 8)
		| ROL16(x & 0x1242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_335(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2124, 4)
		| ROL16(x & 0x1441, 8)
		| ROL16(x & 0x4212, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 2, 3, 1), (1, 3, 2, 0), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 13, 10, 7, 4, 9, 14, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_336(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2141)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x1214, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_336(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2141)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1412, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 2, 3, 1), (3, 0, 1, 2), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 1, 10, 7, 8, 5, 14, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_337(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2181)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x1218, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_337(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2181)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1812, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 1, 2), (1, 2, 3, 0), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 9, 14, 7, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_338(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2181)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1812, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_338(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2181)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x1218, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 1, 14, 7, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_339(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2141)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1412, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_339(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2141)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x1214, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 1, 14, 7, 4, 13, 10, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_340(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_340(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 9, 14, 7, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_341(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_341(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 1, 14, 7, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_342(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_342(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 9, 14, 7, 12, 5, 10, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_343(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_343(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2121)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x1212, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 0, 3, 2), (0, 3, 2, 1), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 13, 2, 7, 4, 9, 14, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_344(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_344(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 0, 3, 2), (3, 2, 1, 0), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 9, 2, 7, 8, 5, 14, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_345(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_345(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_346(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4181)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1814, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_346(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4181)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x1418, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_347(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_347(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_348(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_348(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_349(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8141)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1418, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_349(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8141)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x1814, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 3, 2, 0), (0, 2, 3, 1), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 9, 14, 7, 4, 13, 10, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_350(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4121)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x1412, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_350(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4121)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1214, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 3, 2, 0), (3, 0, 1, 2), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 1, 14, 7, 12, 5, 10, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_351(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8121)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x1812, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_351(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8121)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1218, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_352(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4181)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x1418, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_352(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4181)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1814, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI16_omega_diffusion_353(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_353(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_354(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_354(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 10, 15]
void BOGI16_omega_diffusion_355(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8141)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x1814, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_355(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8141)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1418, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 13, 2, 7, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI16_omega_diffusion_356(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4121)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1214, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_356(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4121)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x1412, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 2, 1), (1, 2, 3, 0), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 9, 2, 7, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI16_omega_diffusion_357(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8121)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1218, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_357(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8121)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x1812, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 2, 1, 0), (0, 3, 2, 1), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 13, 10, 7, 12, 9, 6, 3, 8, 5, 2, 15]
void BOGI16_omega_diffusion_358(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_358(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4141)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x1414, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 2, 1, 0), (1, 0, 3, 2), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 1, 10, 7, 8, 13, 6, 3, 4, 9, 2, 15]
void BOGI16_omega_diffusion_359(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_359(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8181)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x1818, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 2, 1, 3), (1, 3, 0, 2), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 13, 10, 7, 8, 1, 6, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_360(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2182)
		| ROL16(x & 0x1421, 4)
		| ROL16(x & 0x4814, 8)
		| ROL16(x & 0x8248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_360(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2182)
		| ROL16(x & 0x8824, 4)
		| ROL16(x & 0x1448, 8)
		| ROL16(x & 0x4211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 2, 1, 3), (3, 0, 2, 1), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 1, 10, 7, 0, 9, 6, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_361(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2142)
		| ROL16(x & 0x1821, 4)
		| ROL16(x & 0x8418, 8)
		| ROL16(x & 0x4284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_361(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2142)
		| ROL16(x & 0x4428, 4)
		| ROL16(x & 0x1884, 8)
		| ROL16(x & 0x8211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_362(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2144)
		| ROL16(x & 0x1481, 4)
		| ROL16(x & 0x8812, 8)
		| ROL16(x & 0x4228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_362(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2144)
		| ROL16(x & 0x8422, 4)
		| ROL16(x & 0x1288, 8)
		| ROL16(x & 0x4811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_363(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2184)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4812, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_363(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2184)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x1248, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_364(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2148)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8412, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_364(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2148)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x1284, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_365(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2188)
		| ROL16(x & 0x1841, 4)
		| ROL16(x & 0x4412, 8)
		| ROL16(x & 0x8224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_365(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2188)
		| ROL16(x & 0x4822, 4)
		| ROL16(x & 0x1244, 8)
		| ROL16(x & 0x8411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 2, 1), (1, 2, 0, 3), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 9, 14, 7, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_366(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2124)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4212, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_366(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2124)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1242, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 1, 14, 7, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_367(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2128)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8212, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_367(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2128)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1282, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 0, 2, 3), (0, 3, 1, 2), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 13, 2, 7, 0, 5, 10, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_368(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4122)
		| ROL16(x & 0x1281, 4)
		| ROL16(x & 0x8814, 8)
		| ROL16(x & 0x2448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_368(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4122)
		| ROL16(x & 0x8244, 4)
		| ROL16(x & 0x1488, 8)
		| ROL16(x & 0x2811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 0, 2, 3), (3, 2, 0, 1), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 9, 2, 7, 4, 1, 10, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_369(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8122)
		| ROL16(x & 0x1241, 4)
		| ROL16(x & 0x4418, 8)
		| ROL16(x & 0x2884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_369(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8122)
		| ROL16(x & 0x4288, 4)
		| ROL16(x & 0x1844, 8)
		| ROL16(x & 0x2411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_370(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4182)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2814, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_370(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4182)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x1428, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_371(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4142)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2414, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_371(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4142)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1424, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI16_omega_diffusion_372(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8182)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2818, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_372(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8182)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1828, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI16_omega_diffusion_373(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8142)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2418, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_373(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8142)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x1824, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 3, 0, 2), (0, 2, 1, 3), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 9, 14, 7, 8, 5, 2, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_374(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4184)
		| ROL16(x & 0x1241, 4)
		| ROL16(x & 0x2812, 8)
		| ROL16(x & 0x8428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_374(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4184)
		| ROL16(x & 0x8842, 4)
		| ROL16(x & 0x1228, 8)
		| ROL16(x & 0x2411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 3, 0, 2), (3, 0, 2, 1), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 1, 14, 7, 4, 9, 2, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_375(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8148)
		| ROL16(x & 0x1281, 4)
		| ROL16(x & 0x2412, 8)
		| ROL16(x & 0x4824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_375(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8148)
		| ROL16(x & 0x4482, 4)
		| ROL16(x & 0x1224, 8)
		| ROL16(x & 0x2811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 13, 2, 7, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI16_omega_diffusion_376(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4148)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8414, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_376(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4148)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1484, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 1, 2), (1, 2, 0, 3), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 9, 2, 7, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI16_omega_diffusion_377(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8184)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4818, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_377(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8184)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1848, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 9, 2, 7, 0, 5, 10, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_378(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4124)
		| ROL16(x & 0x1841, 4)
		| ROL16(x & 0x8218, 8)
		| ROL16(x & 0x2482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_378(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4124)
		| ROL16(x & 0x2248, 4)
		| ROL16(x & 0x1882, 8)
		| ROL16(x & 0x8411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 13, 2, 7, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_379(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4128)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8214, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_379(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4128)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x1482, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 9, 2, 7, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_380(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8124)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4218, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_380(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8124)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x1842, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 13, 2, 7, 4, 1, 10, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_381(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8128)
		| ROL16(x & 0x1481, 4)
		| ROL16(x & 0x4214, 8)
		| ROL16(x & 0x2842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_381(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8128)
		| ROL16(x & 0x2284, 4)
		| ROL16(x & 0x1442, 8)
		| ROL16(x & 0x4811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 2, 0, 1), (0, 3, 1, 2), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 13, 10, 7, 8, 5, 2, 15, 12, 9, 6, 3]
void BOGI16_omega_diffusion_382(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4188)
		| ROL16(x & 0x1821, 4)
		| ROL16(x & 0x2214, 8)
		| ROL16(x & 0x8442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_382(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4188)
		| ROL16(x & 0x2844, 4)
		| ROL16(x & 0x1422, 8)
		| ROL16(x & 0x8211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 2, 0, 1), (1, 0, 2, 3), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 1, 10, 7, 4, 9, 2, 15, 8, 13, 6, 3]
void BOGI16_omega_diffusion_383(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8144)
		| ROL16(x & 0x1421, 4)
		| ROL16(x & 0x2218, 8)
		| ROL16(x & 0x4882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_383(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8144)
		| ROL16(x & 0x2488, 4)
		| ROL16(x & 0x1822, 8)
		| ROL16(x & 0x4211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 1, 6, 15, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_384(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_384(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8484, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 9, 6, 15, 4, 13, 10, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_385(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_385(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 1, 6, 15, 12, 5, 10, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_386(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_386(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 9, 6, 15, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_387(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_387(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4848, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 1, 6, 15, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_388(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x8482, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_388(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x8482, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 3, 2), (3, 2, 1, 0), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 9, 6, 15, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_389(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x4842, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_389(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x4842, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 2, 1, 3), (1, 0, 3, 2), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 1, 10, 15, 8, 13, 6, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_390(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8424, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_390(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2882)
		| ROL16(x & 0x8424, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 2, 1, 3), (3, 1, 2, 0), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 5, 10, 15, 12, 9, 6, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_391(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4828, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_391(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2442)
		| ROL16(x & 0x4828, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 5, 2, 15, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_392(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x8284, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_392(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x8284, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2848, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 2, 3), (3, 2, 1, 0), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 9, 2, 15, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_393(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x4248, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_393(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x4248, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2484, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_394(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_394(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8282, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2828, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_395(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8242, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_395(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4884)
		| ROL16(x & 0x8242, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_396(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4282, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_396(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8448)
		| ROL16(x & 0x4282, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_397(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_397(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4242, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2424, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 2, 3, 0), (0, 1, 2, 3), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_398(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_398(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 2, 3, 0), (3, 0, 1, 2), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 1, 10, 15, 8, 5, 14, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_399(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_399(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 0, 1, 2), (0, 1, 2, 3), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 5, 2, 15, 12, 9, 6, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_400(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_400(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 0, 1, 2), (1, 2, 3, 0), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 9, 2, 15, 8, 13, 6, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_401(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_401(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 1, 2, 0), (0, 2, 1, 3), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 9, 6, 15, 12, 5, 10, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_402(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2848, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_402(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4224)
		| ROL16(x & 0x2848, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 1, 2, 0), (1, 0, 3, 2), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 1, 6, 15, 4, 13, 10, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_403(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2484, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_403(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8228)
		| ROL16(x & 0x2484, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_404(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_404(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2828, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_405(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x2824, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_405(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x2824, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x8242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_406(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x2428, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_406(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x2428, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4282, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_407(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_407(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2424, 4)
		| ROL16(x & 0x1111, 8)
		| ROL16(x & 0x4242, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 1, 6, 15, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_408(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1484, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x4148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_408(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8414, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x4841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 2, 3), (3, 2, 0, 1), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 9, 6, 15, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_409(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1848, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x8184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_409(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4818, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x8481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_410(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x1482, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x4128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_410(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x8412, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x4821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_411(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2284)
		| ROL16(x & 0x1442, 4)
		| ROL16(x & 0x4811, 8)
		| ROL16(x & 0x8128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_411(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2284)
		| ROL16(x & 0x8812, 4)
		| ROL16(x & 0x1148, 8)
		| ROL16(x & 0x4421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_412(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2248)
		| ROL16(x & 0x1882, 4)
		| ROL16(x & 0x8411, 8)
		| ROL16(x & 0x4124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_412(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2248)
		| ROL16(x & 0x4412, 4)
		| ROL16(x & 0x1184, 8)
		| ROL16(x & 0x8821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_413(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x1842, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x8124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_413(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x4812, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x8421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 2, 3, 1), (1, 0, 2, 3), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 1, 10, 15, 0, 9, 14, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_414(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2844)
		| ROL16(x & 0x1422, 4)
		| ROL16(x & 0x8211, 8)
		| ROL16(x & 0x4188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_414(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2844)
		| ROL16(x & 0x8418, 4)
		| ROL16(x & 0x1182, 8)
		| ROL16(x & 0x4221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 2, 3, 1), (3, 1, 0, 2), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 5, 10, 15, 8, 1, 14, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_415(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2488)
		| ROL16(x & 0x1822, 4)
		| ROL16(x & 0x4211, 8)
		| ROL16(x & 0x8144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_415(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2488)
		| ROL16(x & 0x4814, 4)
		| ROL16(x & 0x1142, 8)
		| ROL16(x & 0x8221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 5, 2, 15, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_416(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x1284, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x2148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_416(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x8214, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x2841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 9, 2, 15, 0, 13, 10, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_417(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4822)
		| ROL16(x & 0x1244, 4)
		| ROL16(x & 0x8411, 8)
		| ROL16(x & 0x2188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_417(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4822)
		| ROL16(x & 0x8218, 4)
		| ROL16(x & 0x1184, 8)
		| ROL16(x & 0x2441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 5, 2, 15, 12, 1, 10, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_418(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8422)
		| ROL16(x & 0x1288, 4)
		| ROL16(x & 0x4811, 8)
		| ROL16(x & 0x2144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_418(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8422)
		| ROL16(x & 0x4214, 4)
		| ROL16(x & 0x1148, 8)
		| ROL16(x & 0x2881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 9, 2, 15, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_419(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x1248, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x2184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_419(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x4218, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x2481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 5, 2, 15, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_420(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1282, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x2128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_420(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8212, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x2821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 3, 2), (3, 2, 0, 1), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 9, 2, 15, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_421(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1242, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x2124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_421(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4212, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x2421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 2, 0, 3), (0, 1, 3, 2), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 5, 10, 15, 8, 13, 2, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_422(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4482)
		| ROL16(x & 0x1224, 4)
		| ROL16(x & 0x2811, 8)
		| ROL16(x & 0x8148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_422(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4482)
		| ROL16(x & 0x8814, 4)
		| ROL16(x & 0x1128, 8)
		| ROL16(x & 0x2241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 2, 0, 3), (3, 0, 2, 1), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 1, 10, 15, 12, 9, 2, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_423(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8842)
		| ROL16(x & 0x1228, 4)
		| ROL16(x & 0x2411, 8)
		| ROL16(x & 0x4184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_423(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8842)
		| ROL16(x & 0x4418, 4)
		| ROL16(x & 0x1124, 8)
		| ROL16(x & 0x2281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 0, 2, 1), (0, 1, 3, 2), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 5, 2, 15, 0, 13, 10, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_424(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4428)
		| ROL16(x & 0x1884, 4)
		| ROL16(x & 0x8211, 8)
		| ROL16(x & 0x2142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_424(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4428)
		| ROL16(x & 0x2214, 4)
		| ROL16(x & 0x1182, 8)
		| ROL16(x & 0x8841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 0, 2, 1), (1, 2, 0, 3), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 9, 2, 15, 12, 1, 10, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_425(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8824)
		| ROL16(x & 0x1448, 4)
		| ROL16(x & 0x4211, 8)
		| ROL16(x & 0x2182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_425(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8824)
		| ROL16(x & 0x2218, 4)
		| ROL16(x & 0x1142, 8)
		| ROL16(x & 0x4481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 1, 0, 2), (0, 2, 3, 1), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 9, 6, 15, 8, 13, 2, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_426(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4288)
		| ROL16(x & 0x1844, 4)
		| ROL16(x & 0x2411, 8)
		| ROL16(x & 0x8122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_426(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4288)
		| ROL16(x & 0x2812, 4)
		| ROL16(x & 0x1124, 8)
		| ROL16(x & 0x8441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 1, 0, 2), (1, 0, 2, 3), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 1, 6, 15, 12, 9, 2, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_427(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8244)
		| ROL16(x & 0x1488, 4)
		| ROL16(x & 0x2811, 8)
		| ROL16(x & 0x4122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_427(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8244)
		| ROL16(x & 0x2412, 4)
		| ROL16(x & 0x1128, 8)
		| ROL16(x & 0x4881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_428(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1828, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x8182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_428(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2818, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x8281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_429(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x1824, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x8142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_429(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x2814, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x8241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_430(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x1428, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x4182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_430(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x2418, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x4281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_431(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1424, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x4142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_431(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2414, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x4241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 1, 2, 3), (1, 2, 3, 0), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 9, 6, 3, 0, 13, 10, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_432(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_432(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 1, 2, 3), (2, 3, 0, 1), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 13, 6, 3, 12, 1, 10, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_433(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_433(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 2, 3, 1), (1, 3, 2, 0), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 13, 10, 3, 0, 9, 14, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_434(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2848)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x8284, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_434(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2848)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8482, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 2, 3, 1), (2, 1, 0, 3), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 5, 10, 3, 8, 1, 14, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_435(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2484)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x4248, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_435(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2484)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4842, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_436(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2824)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4282, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_436(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2824)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8242, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_437(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_437(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_438(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_438(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_439(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2428)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8242, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_439(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2428)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4282, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 0, 3), (0, 3, 2, 1), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 13, 10, 3, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_440(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4842)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2484, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_440(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4842)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8424, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 5, 10, 3, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_441(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8482)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2848, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_441(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8482)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4828, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 5, 10, 3, 0, 9, 14, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_442(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_442(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 13, 10, 3, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_443(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_443(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 5, 10, 3, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_444(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_444(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 13, 10, 3, 8, 1, 14, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_445(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_445(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 3, 2, 0), (0, 2, 3, 1), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 9, 14, 3, 0, 13, 10, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_446(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4828)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x8482, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_446(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4828)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x8284, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 3, 2, 0), (2, 1, 0, 3), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 5, 14, 3, 12, 1, 10, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_447(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8424)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x4842, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_447(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8424)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x4248, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_448(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4282)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x2428, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_448(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4282)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2824, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI16_omega_diffusion_449(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_449(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_450(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_450(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 14, 11]
void BOGI16_omega_diffusion_451(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8242)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x2824, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_451(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8242)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2428, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 3, 0), (0, 3, 2, 1), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 13, 6, 3, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI16_omega_diffusion_452(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4248)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8424, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_452(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4248)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2484, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 9, 6, 3, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI16_omega_diffusion_453(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8284)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4828, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_453(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8284)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2848, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 3, 0, 1), (0, 1, 2, 3), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 5, 14, 3, 12, 9, 2, 7, 0, 13, 6, 11]
void BOGI16_omega_diffusion_454(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_454(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 3, 0, 1), (1, 2, 3, 0), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11]
void BOGI16_omega_diffusion_455(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x1111, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_455(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1111, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 1, 3, 2), (1, 2, 0, 3), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 9, 6, 3, 4, 1, 14, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_456(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2214)
		| ROL16(x & 0x8442, 4)
		| ROL16(x & 0x4188, 8)
		| ROL16(x & 0x1821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_456(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2214)
		| ROL16(x & 0x1182, 4)
		| ROL16(x & 0x8841, 8)
		| ROL16(x & 0x4428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 1, 3, 2), (2, 3, 1, 0), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 13, 6, 3, 0, 5, 14, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_457(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2218)
		| ROL16(x & 0x4882, 4)
		| ROL16(x & 0x8144, 8)
		| ROL16(x & 0x1421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_457(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2218)
		| ROL16(x & 0x1142, 4)
		| ROL16(x & 0x4481, 8)
		| ROL16(x & 0x8824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 2, 1, 3), (1, 3, 0, 2), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 13, 10, 3, 12, 1, 6, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_458(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2812)
		| ROL16(x & 0x8428, 4)
		| ROL16(x & 0x4184, 8)
		| ROL16(x & 0x1241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_458(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2812)
		| ROL16(x & 0x1124, 4)
		| ROL16(x & 0x8441, 8)
		| ROL16(x & 0x4288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 2, 1, 3), (2, 1, 3, 0), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 5, 10, 3, 0, 13, 6, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_459(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2412)
		| ROL16(x & 0x4824, 4)
		| ROL16(x & 0x8148, 8)
		| ROL16(x & 0x1281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_459(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2412)
		| ROL16(x & 0x1128, 4)
		| ROL16(x & 0x4881, 8)
		| ROL16(x & 0x8244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_460(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2814)
		| ROL16(x & 0x8448, 4)
		| ROL16(x & 0x4182, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_460(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2814)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x8241, 8)
		| ROL16(x & 0x4488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_461(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2818)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x8182, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_461(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2818)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x8281, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_462(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2414)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x4142, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_462(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2414)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x4241, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_463(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2418)
		| ROL16(x & 0x4884, 4)
		| ROL16(x & 0x8142, 8)
		| ROL16(x & 0x1221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_463(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2418)
		| ROL16(x & 0x1122, 4)
		| ROL16(x & 0x4281, 8)
		| ROL16(x & 0x8844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_464(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4412)
		| ROL16(x & 0x8224, 4)
		| ROL16(x & 0x2188, 8)
		| ROL16(x & 0x1841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_464(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4412)
		| ROL16(x & 0x1184, 4)
		| ROL16(x & 0x8821, 8)
		| ROL16(x & 0x2248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_465(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4812)
		| ROL16(x & 0x8228, 4)
		| ROL16(x & 0x2184, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_465(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4812)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x8421, 8)
		| ROL16(x & 0x2288, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_466(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8412)
		| ROL16(x & 0x4224, 4)
		| ROL16(x & 0x2148, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_466(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8412)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x4821, 8)
		| ROL16(x & 0x2244, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_467(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8812)
		| ROL16(x & 0x4228, 4)
		| ROL16(x & 0x2144, 8)
		| ROL16(x & 0x1481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_467(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8812)
		| ROL16(x & 0x1148, 4)
		| ROL16(x & 0x4421, 8)
		| ROL16(x & 0x2284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 3, 0), (0, 3, 1, 2), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 13, 10, 3, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_468(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4818)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x8184, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_468(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4818)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x8481, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 5, 10, 3, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_469(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8414)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x4148, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_469(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8414)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x4841, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 3, 0, 2), (0, 2, 1, 3), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 9, 14, 3, 12, 5, 2, 11, 0, 13, 10, 7]
void BOGI16_omega_diffusion_470(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4814)
		| ROL16(x & 0x8248, 4)
		| ROL16(x & 0x2182, 8)
		| ROL16(x & 0x1421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_470(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4814)
		| ROL16(x & 0x1142, 4)
		| ROL16(x & 0x8221, 8)
		| ROL16(x & 0x2488, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 3, 0, 2), (2, 1, 3, 0), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 5, 14, 3, 4, 13, 2, 11, 12, 1, 10, 7]
void BOGI16_omega_diffusion_471(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8418)
		| ROL16(x & 0x4284, 4)
		| ROL16(x & 0x2142, 8)
		| ROL16(x & 0x1821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_471(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8418)
		| ROL16(x & 0x1182, 4)
		| ROL16(x & 0x4221, 8)
		| ROL16(x & 0x2844, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 0, 3), (0, 3, 1, 2), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 13, 6, 3, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI16_omega_diffusion_472(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4212)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x2124, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_472(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4212)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x2421, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 9, 6, 3, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI16_omega_diffusion_473(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8212)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x2128, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_473(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8212)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x2821, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 9, 6, 3, 0, 5, 14, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_474(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4214)
		| ROL16(x & 0x2842, 4)
		| ROL16(x & 0x8128, 8)
		| ROL16(x & 0x1481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_474(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4214)
		| ROL16(x & 0x1148, 4)
		| ROL16(x & 0x2881, 8)
		| ROL16(x & 0x8422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 13, 6, 3, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_475(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4218)
		| ROL16(x & 0x2882, 4)
		| ROL16(x & 0x8124, 8)
		| ROL16(x & 0x1441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_475(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4218)
		| ROL16(x & 0x1144, 4)
		| ROL16(x & 0x2481, 8)
		| ROL16(x & 0x8822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 9, 6, 3, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_476(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8214)
		| ROL16(x & 0x2442, 4)
		| ROL16(x & 0x4128, 8)
		| ROL16(x & 0x1881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_476(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8214)
		| ROL16(x & 0x1188, 4)
		| ROL16(x & 0x2841, 8)
		| ROL16(x & 0x4422, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 13, 6, 3, 4, 1, 14, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_477(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8218)
		| ROL16(x & 0x2482, 4)
		| ROL16(x & 0x4124, 8)
		| ROL16(x & 0x1841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_477(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8218)
		| ROL16(x & 0x1184, 4)
		| ROL16(x & 0x2441, 8)
		| ROL16(x & 0x4822, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 3, 1, 0), (0, 1, 3, 2), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 5, 14, 3, 0, 13, 6, 11, 12, 9, 2, 7]
void BOGI16_omega_diffusion_478(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4418)
		| ROL16(x & 0x2884, 4)
		| ROL16(x & 0x8122, 8)
		| ROL16(x & 0x1241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_478(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4418)
		| ROL16(x & 0x1124, 4)
		| ROL16(x & 0x2281, 8)
		| ROL16(x & 0x8842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 3, 1, 0), (1, 2, 0, 3), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 9, 14, 3, 12, 1, 6, 11, 8, 13, 2, 7]
void BOGI16_omega_diffusion_479(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8814)
		| ROL16(x & 0x2448, 4)
		| ROL16(x & 0x4122, 8)
		| ROL16(x & 0x1281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_479(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8814)
		| ROL16(x & 0x1128, 4)
		| ROL16(x & 0x2241, 8)
		| ROL16(x & 0x4482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 1, 3), (1, 3, 2, 0), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 13, 10, 7, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_480(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2142)
		| ROL16(x & 0x4428, 4)
		| ROL16(x & 0x1884, 8)
		| ROL16(x & 0x8211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_480(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2142)
		| ROL16(x & 0x1821, 4)
		| ROL16(x & 0x8418, 8)
		| ROL16(x & 0x4284, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 1, 10, 7, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_481(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2182)
		| ROL16(x & 0x8824, 4)
		| ROL16(x & 0x1448, 8)
		| ROL16(x & 0x4211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_481(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2182)
		| ROL16(x & 0x1421, 4)
		| ROL16(x & 0x4814, 8)
		| ROL16(x & 0x8248, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 1, 10, 7, 4, 9, 14, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_482(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2144)
		| ROL16(x & 0x8422, 4)
		| ROL16(x & 0x1288, 8)
		| ROL16(x & 0x4811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_482(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2144)
		| ROL16(x & 0x1481, 4)
		| ROL16(x & 0x8812, 8)
		| ROL16(x & 0x4228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 13, 10, 7, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_483(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2148)
		| ROL16(x & 0x4422, 4)
		| ROL16(x & 0x1284, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_483(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2148)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8412, 8)
		| ROL16(x & 0x4224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 1, 10, 7, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_484(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2184)
		| ROL16(x & 0x8822, 4)
		| ROL16(x & 0x1248, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_484(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2184)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4812, 8)
		| ROL16(x & 0x8228, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 13, 10, 7, 8, 5, 14, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_485(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2188)
		| ROL16(x & 0x4822, 4)
		| ROL16(x & 0x1244, 8)
		| ROL16(x & 0x8411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_485(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2188)
		| ROL16(x & 0x1841, 4)
		| ROL16(x & 0x4412, 8)
		| ROL16(x & 0x8224, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 3, 2, 1), (1, 2, 3, 0), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 9, 14, 7, 4, 13, 10, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_486(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2128)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1282, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_486(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2128)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8212, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 3, 2, 1), (2, 0, 1, 3), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 1, 14, 7, 12, 5, 10, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_487(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2124)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1242, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_487(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2124)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4212, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 0, 2, 3), (0, 2, 3, 1), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 9, 2, 7, 4, 13, 10, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_488(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4122)
		| ROL16(x & 0x8244, 4)
		| ROL16(x & 0x1488, 8)
		| ROL16(x & 0x2811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_488(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4122)
		| ROL16(x & 0x1281, 4)
		| ROL16(x & 0x8814, 8)
		| ROL16(x & 0x2448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 0, 2, 3), (2, 3, 1, 0), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 13, 2, 7, 12, 5, 10, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_489(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8122)
		| ROL16(x & 0x4288, 4)
		| ROL16(x & 0x1844, 8)
		| ROL16(x & 0x2411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_489(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8122)
		| ROL16(x & 0x1241, 4)
		| ROL16(x & 0x4418, 8)
		| ROL16(x & 0x2884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 2, 3, 0), (0, 3, 2, 1), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 13, 10, 7, 4, 9, 14, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_490(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4148)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1484, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_490(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4148)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8414, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 2, 3, 0), (2, 0, 1, 3), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 1, 10, 7, 8, 5, 14, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_491(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8184)
		| ROL16(x & 0x2222, 4)
		| ROL16(x & 0x1848, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_491(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8184)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4818, 8)
		| ROL16(x & 0x2222, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_492(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4124)
		| ROL16(x & 0x2248, 4)
		| ROL16(x & 0x1882, 8)
		| ROL16(x & 0x8411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_492(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4124)
		| ROL16(x & 0x1841, 4)
		| ROL16(x & 0x8218, 8)
		| ROL16(x & 0x2482, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_493(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4128)
		| ROL16(x & 0x2244, 4)
		| ROL16(x & 0x1482, 8)
		| ROL16(x & 0x8811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_493(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4128)
		| ROL16(x & 0x1881, 4)
		| ROL16(x & 0x8214, 8)
		| ROL16(x & 0x2442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_494(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8124)
		| ROL16(x & 0x2288, 4)
		| ROL16(x & 0x1842, 8)
		| ROL16(x & 0x4411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_494(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8124)
		| ROL16(x & 0x1441, 4)
		| ROL16(x & 0x4218, 8)
		| ROL16(x & 0x2882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_495(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8128)
		| ROL16(x & 0x2284, 4)
		| ROL16(x & 0x1442, 8)
		| ROL16(x & 0x4811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_495(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8128)
		| ROL16(x & 0x1481, 4)
		| ROL16(x & 0x4214, 8)
		| ROL16(x & 0x2842, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_496(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4182)
		| ROL16(x & 0x8844, 4)
		| ROL16(x & 0x1428, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_496(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4182)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2814, 8)
		| ROL16(x & 0x8448, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 14, 11]
void BOGI16_omega_diffusion_497(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4142)
		| ROL16(x & 0x8888, 4)
		| ROL16(x & 0x1424, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_497(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4142)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2414, 8)
		| ROL16(x & 0x8888, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_498(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8182)
		| ROL16(x & 0x4444, 4)
		| ROL16(x & 0x1828, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_498(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8182)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2818, 8)
		| ROL16(x & 0x4444, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI16_omega_diffusion_499(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8142)
		| ROL16(x & 0x4488, 4)
		| ROL16(x & 0x1824, 8)
		| ROL16(x & 0x2211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_499(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8142)
		| ROL16(x & 0x1221, 4)
		| ROL16(x & 0x2418, 8)
		| ROL16(x & 0x4884, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 9, 2, 7, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI16_omega_diffusion_500(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4184)
		| ROL16(x & 0x8842, 4)
		| ROL16(x & 0x1228, 8)
		| ROL16(x & 0x2411, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_500(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4184)
		| ROL16(x & 0x1241, 4)
		| ROL16(x & 0x2812, 8)
		| ROL16(x & 0x8428, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 3, 1), (1, 3, 2, 0), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 13, 2, 7, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI16_omega_diffusion_501(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8148)
		| ROL16(x & 0x4482, 4)
		| ROL16(x & 0x1224, 8)
		| ROL16(x & 0x2811, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_501(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8148)
		| ROL16(x & 0x1281, 4)
		| ROL16(x & 0x2412, 8)
		| ROL16(x & 0x4824, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 3, 1, 0), (0, 2, 3, 1), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 9, 14, 7, 8, 13, 6, 3, 12, 5, 2, 11]
void BOGI16_omega_diffusion_502(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4188)
		| ROL16(x & 0x2844, 4)
		| ROL16(x & 0x1422, 8)
		| ROL16(x & 0x8211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_502(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4188)
		| ROL16(x & 0x1821, 4)
		| ROL16(x & 0x2214, 8)
		| ROL16(x & 0x8442, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 3, 1, 0), (1, 0, 2, 3), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 1, 14, 7, 12, 9, 6, 3, 4, 13, 2, 11]
void BOGI16_omega_diffusion_503(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8144)
		| ROL16(x & 0x2488, 4)
		| ROL16(x & 0x1822, 8)
		| ROL16(x & 0x4211, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_503(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8144)
		| ROL16(x & 0x1421, 4)
		| ROL16(x & 0x2218, 8)
		| ROL16(x & 0x4882, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_504(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1424, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_504(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1424, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_505(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1428, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_505(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1824, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_506(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1824, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_506(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1428, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_507(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1828, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_507(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2112)
		| ROL16(x & 0x1828, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 3, 1), (1, 3, 0, 2), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 13, 10, 7, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_508(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2118)
		| ROL16(x & 0x1422, 4)
		| ROL16(x & 0x4284, 8)
		| ROL16(x & 0x8841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_508(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2118)
		| ROL16(x & 0x1884, 4)
		| ROL16(x & 0x8442, 8)
		| ROL16(x & 0x4221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 1, 10, 7, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_509(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2114)
		| ROL16(x & 0x1822, 4)
		| ROL16(x & 0x8248, 8)
		| ROL16(x & 0x4481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_509(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2114)
		| ROL16(x & 0x1448, 4)
		| ROL16(x & 0x4882, 8)
		| ROL16(x & 0x8221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 3, 1, 2), (1, 2, 0, 3), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 9, 14, 7, 12, 1, 6, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_510(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2114)
		| ROL16(x & 0x1448, 4)
		| ROL16(x & 0x4882, 8)
		| ROL16(x & 0x8221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_510(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2114)
		| ROL16(x & 0x1822, 4)
		| ROL16(x & 0x8248, 8)
		| ROL16(x & 0x4481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 3, 1, 2), (2, 0, 3, 1), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 1, 14, 7, 0, 13, 6, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_511(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2118)
		| ROL16(x & 0x1884, 4)
		| ROL16(x & 0x8442, 8)
		| ROL16(x & 0x4221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_511(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2118)
		| ROL16(x & 0x1422, 4)
		| ROL16(x & 0x4284, 8)
		| ROL16(x & 0x8841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 0, 3, 2), (0, 2, 1, 3), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 9, 2, 7, 0, 5, 14, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_512(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1242, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_512(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1242, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 0, 3, 2), (2, 3, 0, 1), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 13, 2, 7, 4, 1, 14, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_513(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1282, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_513(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1282, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 2, 0, 3), (0, 3, 1, 2), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 13, 10, 7, 12, 5, 2, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_514(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4112)
		| ROL16(x & 0x1228, 4)
		| ROL16(x & 0x2884, 8)
		| ROL16(x & 0x8441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_514(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4112)
		| ROL16(x & 0x1844, 4)
		| ROL16(x & 0x8428, 8)
		| ROL16(x & 0x2281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 2, 0, 3), (2, 0, 3, 1), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 1, 10, 7, 4, 13, 2, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_515(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8112)
		| ROL16(x & 0x1224, 4)
		| ROL16(x & 0x2448, 8)
		| ROL16(x & 0x4881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_515(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8112)
		| ROL16(x & 0x1488, 4)
		| ROL16(x & 0x4824, 8)
		| ROL16(x & 0x2241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_516(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1248, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_516(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1842, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_517(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4118)
		| ROL16(x & 0x1244, 4)
		| ROL16(x & 0x2482, 8)
		| ROL16(x & 0x8821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_517(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4118)
		| ROL16(x & 0x1882, 4)
		| ROL16(x & 0x8224, 8)
		| ROL16(x & 0x2441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI16_omega_diffusion_518(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8114)
		| ROL16(x & 0x1288, 4)
		| ROL16(x & 0x2842, 8)
		| ROL16(x & 0x4421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_518(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8114)
		| ROL16(x & 0x1442, 4)
		| ROL16(x & 0x4228, 8)
		| ROL16(x & 0x2881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI16_omega_diffusion_519(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1284, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_519(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1482, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 9, 2, 7, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI16_omega_diffusion_520(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4112)
		| ROL16(x & 0x1844, 4)
		| ROL16(x & 0x8428, 8)
		| ROL16(x & 0x2281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_520(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4112)
		| ROL16(x & 0x1228, 4)
		| ROL16(x & 0x2884, 8)
		| ROL16(x & 0x8441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 1, 3), (1, 3, 0, 2), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 13, 2, 7, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI16_omega_diffusion_521(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8112)
		| ROL16(x & 0x1488, 4)
		| ROL16(x & 0x4824, 8)
		| ROL16(x & 0x2241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_521(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8112)
		| ROL16(x & 0x1224, 4)
		| ROL16(x & 0x2448, 8)
		| ROL16(x & 0x4881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 9, 2, 7, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_522(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1842, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_522(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1248, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 13, 2, 7, 0, 5, 14, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_523(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4118)
		| ROL16(x & 0x1882, 4)
		| ROL16(x & 0x8224, 8)
		| ROL16(x & 0x2441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_523(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4118)
		| ROL16(x & 0x1244, 4)
		| ROL16(x & 0x2482, 8)
		| ROL16(x & 0x8821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 9, 2, 7, 4, 1, 14, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_524(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8114)
		| ROL16(x & 0x1442, 4)
		| ROL16(x & 0x4228, 8)
		| ROL16(x & 0x2881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_524(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8114)
		| ROL16(x & 0x1288, 4)
		| ROL16(x & 0x2842, 8)
		| ROL16(x & 0x4421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 13, 2, 7, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_525(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1482, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_525(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1284, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 3, 0, 1), (0, 2, 1, 3), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 9, 14, 7, 12, 5, 2, 11, 8, 13, 6, 3]
void BOGI16_omega_diffusion_526(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1848, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_526(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4114)
		| ROL16(x & 0x1848, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 3, 0, 1), (1, 0, 3, 2), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 1, 14, 7, 4, 13, 2, 11, 12, 9, 6, 3]
void BOGI16_omega_diffusion_527(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1484, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_527(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8118)
		| ROL16(x & 0x1484, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 1, 6, 11, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_528(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x8414, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x4841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_528(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1484, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x4148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 2, 3), (2, 3, 1, 0), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 13, 6, 11, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_529(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x4818, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x8481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_529(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1848, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x8184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 1, 6, 11, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_530(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x8412, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x4821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_530(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x1482, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x4128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 13, 6, 11, 4, 9, 14, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_531(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2248)
		| ROL16(x & 0x4412, 4)
		| ROL16(x & 0x1184, 8)
		| ROL16(x & 0x8821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_531(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2248)
		| ROL16(x & 0x1882, 4)
		| ROL16(x & 0x8411, 8)
		| ROL16(x & 0x4124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 1, 6, 11, 8, 5, 14, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_532(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2284)
		| ROL16(x & 0x8812, 4)
		| ROL16(x & 0x1148, 8)
		| ROL16(x & 0x4421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_532(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2284)
		| ROL16(x & 0x1442, 4)
		| ROL16(x & 0x4811, 8)
		| ROL16(x & 0x8128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 13, 6, 11, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_533(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x4812, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x8421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_533(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x1842, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x8124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 3, 1, 2), (1, 0, 2, 3), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 1, 14, 11, 12, 9, 6, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_534(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2844)
		| ROL16(x & 0x8418, 4)
		| ROL16(x & 0x1182, 8)
		| ROL16(x & 0x4221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_534(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2844)
		| ROL16(x & 0x1422, 4)
		| ROL16(x & 0x8211, 8)
		| ROL16(x & 0x4188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 3, 1, 2), (2, 1, 3, 0), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 5, 14, 11, 8, 13, 6, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_535(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2488)
		| ROL16(x & 0x4814, 4)
		| ROL16(x & 0x1142, 8)
		| ROL16(x & 0x8221, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_535(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2488)
		| ROL16(x & 0x1822, 4)
		| ROL16(x & 0x4211, 8)
		| ROL16(x & 0x8144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_536(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x8214, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x2841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_536(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x1284, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x2148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_537(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4822)
		| ROL16(x & 0x8218, 4)
		| ROL16(x & 0x1184, 8)
		| ROL16(x & 0x2441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_537(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4822)
		| ROL16(x & 0x1244, 4)
		| ROL16(x & 0x8411, 8)
		| ROL16(x & 0x2188, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_538(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8422)
		| ROL16(x & 0x4214, 4)
		| ROL16(x & 0x1148, 8)
		| ROL16(x & 0x2881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_538(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8422)
		| ROL16(x & 0x1288, 4)
		| ROL16(x & 0x4811, 8)
		| ROL16(x & 0x2144, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_539(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x4218, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x2481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_539(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x1248, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x2184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 5, 2, 11, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI16_omega_diffusion_540(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x8212, 4)
		| ROL16(x & 0x1188, 8)
		| ROL16(x & 0x2821, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_540(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1282, 4)
		| ROL16(x & 0x8811, 8)
		| ROL16(x & 0x2128, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 3, 2), (2, 3, 1, 0), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 13, 2, 11, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI16_omega_diffusion_541(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x4212, 4)
		| ROL16(x & 0x1144, 8)
		| ROL16(x & 0x2421, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_541(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1242, 4)
		| ROL16(x & 0x4411, 8)
		| ROL16(x & 0x2124, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 3, 2, 0), (0, 1, 3, 2), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 5, 14, 11, 4, 13, 10, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_542(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4428)
		| ROL16(x & 0x2214, 4)
		| ROL16(x & 0x1182, 8)
		| ROL16(x & 0x8841, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_542(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4428)
		| ROL16(x & 0x1884, 4)
		| ROL16(x & 0x8211, 8)
		| ROL16(x & 0x2142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 3, 2, 0), (2, 0, 1, 3), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 1, 14, 11, 12, 5, 10, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_543(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8824)
		| ROL16(x & 0x2218, 4)
		| ROL16(x & 0x1142, 8)
		| ROL16(x & 0x4481, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_543(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8824)
		| ROL16(x & 0x1448, 4)
		| ROL16(x & 0x4211, 8)
		| ROL16(x & 0x2182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 0, 1, 3), (0, 1, 3, 2), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 5, 2, 11, 8, 13, 6, 3, 0, 9, 14, 7]
void BOGI16_omega_diffusion_544(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4482)
		| ROL16(x & 0x8814, 4)
		| ROL16(x & 0x1128, 8)
		| ROL16(x & 0x2241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_544(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4482)
		| ROL16(x & 0x1224, 4)
		| ROL16(x & 0x2811, 8)
		| ROL16(x & 0x8148, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 0, 1, 3), (1, 3, 2, 0), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 13, 2, 11, 12, 9, 6, 3, 8, 1, 14, 7]
void BOGI16_omega_diffusion_545(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8842)
		| ROL16(x & 0x4418, 4)
		| ROL16(x & 0x1124, 8)
		| ROL16(x & 0x2281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_545(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8842)
		| ROL16(x & 0x1228, 4)
		| ROL16(x & 0x2411, 8)
		| ROL16(x & 0x4184, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 1, 3, 0), (0, 3, 1, 2), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 13, 6, 11, 8, 5, 14, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_546(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4288)
		| ROL16(x & 0x2812, 4)
		| ROL16(x & 0x1124, 8)
		| ROL16(x & 0x8441, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_546(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4288)
		| ROL16(x & 0x1844, 4)
		| ROL16(x & 0x2411, 8)
		| ROL16(x & 0x8122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 1, 3, 0), (1, 0, 2, 3), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 1, 6, 11, 4, 9, 14, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_547(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8244)
		| ROL16(x & 0x2412, 4)
		| ROL16(x & 0x1128, 8)
		| ROL16(x & 0x4881, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_547(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8244)
		| ROL16(x & 0x1488, 4)
		| ROL16(x & 0x2811, 8)
		| ROL16(x & 0x4122, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_548(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x2818, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x8281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_548(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1828, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x8182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_549(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x2814, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x8241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_549(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x1824, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x8142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI16_omega_diffusion_550(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x2418, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x4281, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_550(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x1428, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x4182, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI16_omega_diffusion_551(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x2414, 4)
		| ROL16(x & 0x1122, 8)
		| ROL16(x & 0x4241, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_551(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1424, 4)
		| ROL16(x & 0x2211, 8)
		| ROL16(x & 0x4142, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_552(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_552(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_553(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1418, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_553(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1814, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_554(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1814, 4)
		| ROL16(x & 0x8448, 8)
		| ROL16(x & 0x4181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_554(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1418, 4)
		| ROL16(x & 0x4884, 8)
		| ROL16(x & 0x8141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_555(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_555(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2222)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 1, 6, 11, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_556(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x1412, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_556(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2244)
		| ROL16(x & 0x1412, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x4121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 3, 2), (2, 3, 0, 1), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 13, 6, 11, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_557(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x1812, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_557(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2288)
		| ROL16(x & 0x1812, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x8121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 3, 2, 1), (1, 0, 3, 2), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 1, 14, 11, 0, 13, 10, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_558(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_558(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2828)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x8282, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 3, 2, 1), (2, 1, 0, 3), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 5, 14, 11, 12, 1, 10, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_559(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_559(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x2424)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x4242, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 5, 2, 11, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_560(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x1214, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_560(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4422)
		| ROL16(x & 0x1214, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 2, 3), (2, 3, 0, 1), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 13, 2, 11, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_561(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x1218, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_561(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8822)
		| ROL16(x & 0x1218, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 5, 2, 11, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_562(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_562(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x8888, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 13, 2, 11, 0, 9, 14, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_563(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_563(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4848)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x8484, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 5, 2, 11, 8, 1, 14, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_564(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_564(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8484)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x4848, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 13, 2, 11, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_565(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_565(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1212, 4)
		| ROL16(x & 0x4444, 8)
		| ROL16(x & 0x2121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 3, 0, 2), (0, 1, 2, 3), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 5, 14, 11, 12, 9, 2, 7, 4, 13, 10, 3]
void BOGI16_omega_diffusion_566(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1218, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_566(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1812, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 3, 0, 2), (2, 0, 3, 1), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 1, 14, 11, 8, 13, 2, 7, 12, 5, 10, 3]
void BOGI16_omega_diffusion_567(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1214, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_567(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1412, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 0, 3, 1), (0, 1, 2, 3), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 5, 2, 11, 0, 9, 14, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_568(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1812, 4)
		| ROL16(x & 0x8228, 8)
		| ROL16(x & 0x2181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_568(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1218, 4)
		| ROL16(x & 0x2882, 8)
		| ROL16(x & 0x8121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 0, 3, 1), (1, 3, 0, 2), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 13, 2, 11, 8, 1, 14, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_569(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1412, 4)
		| ROL16(x & 0x4224, 8)
		| ROL16(x & 0x2141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_569(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1214, 4)
		| ROL16(x & 0x2442, 8)
		| ROL16(x & 0x4121, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 1, 0, 3), (0, 3, 2, 1), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 13, 6, 11, 12, 9, 2, 7, 8, 5, 14, 3]
void BOGI16_omega_diffusion_570(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_570(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4242)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x2424, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 1, 0, 3), (1, 0, 3, 2), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 1, 6, 11, 8, 13, 2, 7, 4, 9, 14, 3]
void BOGI16_omega_diffusion_571(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_571(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8282)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x2828, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_572(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_572(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4444)
		| ROL16(x & 0x1818, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_573(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x1814, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_573(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x4488)
		| ROL16(x & 0x1814, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x8141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI16_omega_diffusion_574(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x1418, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_574(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8844)
		| ROL16(x & 0x1418, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4181, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI16_omega_diffusion_575(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI16_omega_inv_diffusion_575(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint16_t x = 0;
	int i;

	for (i = 0; i < 4; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 7 cycles, 4 masks
	x = (x & 0x8888)
		| ROL16(x & 0x1414, 4)
		| ROL16(x & 0x2222, 8)
		| ROL16(x & 0x4141, 12);

	for (i = 3; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void(*BOGI16_omega_diffusion[576])(DIFF_O_WRD_t *, DIFF_I_WRD_t *) = {
	BOGI16_omega_diffusion_0, BOGI16_omega_diffusion_1, BOGI16_omega_diffusion_2, BOGI16_omega_diffusion_3,
	BOGI16_omega_diffusion_4, BOGI16_omega_diffusion_5, BOGI16_omega_diffusion_6, BOGI16_omega_diffusion_7,
	BOGI16_omega_diffusion_8, BOGI16_omega_diffusion_9, BOGI16_omega_diffusion_10, BOGI16_omega_diffusion_11,
	BOGI16_omega_diffusion_12, BOGI16_omega_diffusion_13, BOGI16_omega_diffusion_14, BOGI16_omega_diffusion_15,
	BOGI16_omega_diffusion_16, BOGI16_omega_diffusion_17, BOGI16_omega_diffusion_18, BOGI16_omega_diffusion_19,
	BOGI16_omega_diffusion_20, BOGI16_omega_diffusion_21, BOGI16_omega_diffusion_22, BOGI16_omega_diffusion_23,
	BOGI16_omega_diffusion_24, BOGI16_omega_diffusion_25, BOGI16_omega_diffusion_26, BOGI16_omega_diffusion_27,
	BOGI16_omega_diffusion_28, BOGI16_omega_diffusion_29, BOGI16_omega_diffusion_30, BOGI16_omega_diffusion_31,
	BOGI16_omega_diffusion_32, BOGI16_omega_diffusion_33, BOGI16_omega_diffusion_34, BOGI16_omega_diffusion_35,
	BOGI16_omega_diffusion_36, BOGI16_omega_diffusion_37, BOGI16_omega_diffusion_38, BOGI16_omega_diffusion_39,
	BOGI16_omega_diffusion_40, BOGI16_omega_diffusion_41, BOGI16_omega_diffusion_42, BOGI16_omega_diffusion_43,
	BOGI16_omega_diffusion_44, BOGI16_omega_diffusion_45, BOGI16_omega_diffusion_46, BOGI16_omega_diffusion_47,
	BOGI16_omega_diffusion_48, BOGI16_omega_diffusion_49, BOGI16_omega_diffusion_50, BOGI16_omega_diffusion_51,
	BOGI16_omega_diffusion_52, BOGI16_omega_diffusion_53, BOGI16_omega_diffusion_54, BOGI16_omega_diffusion_55,
	BOGI16_omega_diffusion_56, BOGI16_omega_diffusion_57, BOGI16_omega_diffusion_58, BOGI16_omega_diffusion_59,
	BOGI16_omega_diffusion_60, BOGI16_omega_diffusion_61, BOGI16_omega_diffusion_62, BOGI16_omega_diffusion_63,
	BOGI16_omega_diffusion_64, BOGI16_omega_diffusion_65, BOGI16_omega_diffusion_66, BOGI16_omega_diffusion_67,
	BOGI16_omega_diffusion_68, BOGI16_omega_diffusion_69, BOGI16_omega_diffusion_70, BOGI16_omega_diffusion_71,
	BOGI16_omega_diffusion_72, BOGI16_omega_diffusion_73, BOGI16_omega_diffusion_74, BOGI16_omega_diffusion_75,
	BOGI16_omega_diffusion_76, BOGI16_omega_diffusion_77, BOGI16_omega_diffusion_78, BOGI16_omega_diffusion_79,
	BOGI16_omega_diffusion_80, BOGI16_omega_diffusion_81, BOGI16_omega_diffusion_82, BOGI16_omega_diffusion_83,
	BOGI16_omega_diffusion_84, BOGI16_omega_diffusion_85, BOGI16_omega_diffusion_86, BOGI16_omega_diffusion_87,
	BOGI16_omega_diffusion_88, BOGI16_omega_diffusion_89, BOGI16_omega_diffusion_90, BOGI16_omega_diffusion_91,
	BOGI16_omega_diffusion_92, BOGI16_omega_diffusion_93, BOGI16_omega_diffusion_94, BOGI16_omega_diffusion_95,
	BOGI16_omega_diffusion_96, BOGI16_omega_diffusion_97, BOGI16_omega_diffusion_98, BOGI16_omega_diffusion_99,
	BOGI16_omega_diffusion_100, BOGI16_omega_diffusion_101, BOGI16_omega_diffusion_102, BOGI16_omega_diffusion_103,
	BOGI16_omega_diffusion_104, BOGI16_omega_diffusion_105, BOGI16_omega_diffusion_106, BOGI16_omega_diffusion_107,
	BOGI16_omega_diffusion_108, BOGI16_omega_diffusion_109, BOGI16_omega_diffusion_110, BOGI16_omega_diffusion_111,
	BOGI16_omega_diffusion_112, BOGI16_omega_diffusion_113, BOGI16_omega_diffusion_114, BOGI16_omega_diffusion_115,
	BOGI16_omega_diffusion_116, BOGI16_omega_diffusion_117, BOGI16_omega_diffusion_118, BOGI16_omega_diffusion_119,
	BOGI16_omega_diffusion_120, BOGI16_omega_diffusion_121, BOGI16_omega_diffusion_122, BOGI16_omega_diffusion_123,
	BOGI16_omega_diffusion_124, BOGI16_omega_diffusion_125, BOGI16_omega_diffusion_126, BOGI16_omega_diffusion_127,
	BOGI16_omega_diffusion_128, BOGI16_omega_diffusion_129, BOGI16_omega_diffusion_130, BOGI16_omega_diffusion_131,
	BOGI16_omega_diffusion_132, BOGI16_omega_diffusion_133, BOGI16_omega_diffusion_134, BOGI16_omega_diffusion_135,
	BOGI16_omega_diffusion_136, BOGI16_omega_diffusion_137, BOGI16_omega_diffusion_138, BOGI16_omega_diffusion_139,
	BOGI16_omega_diffusion_140, BOGI16_omega_diffusion_141, BOGI16_omega_diffusion_142, BOGI16_omega_diffusion_143,
	BOGI16_omega_diffusion_144, BOGI16_omega_diffusion_145, BOGI16_omega_diffusion_146, BOGI16_omega_diffusion_147,
	BOGI16_omega_diffusion_148, BOGI16_omega_diffusion_149, BOGI16_omega_diffusion_150, BOGI16_omega_diffusion_151,
	BOGI16_omega_diffusion_152, BOGI16_omega_diffusion_153, BOGI16_omega_diffusion_154, BOGI16_omega_diffusion_155,
	BOGI16_omega_diffusion_156, BOGI16_omega_diffusion_157, BOGI16_omega_diffusion_158, BOGI16_omega_diffusion_159,
	BOGI16_omega_diffusion_160, BOGI16_omega_diffusion_161, BOGI16_omega_diffusion_162, BOGI16_omega_diffusion_163,
	BOGI16_omega_diffusion_164, BOGI16_omega_diffusion_165, BOGI16_omega_diffusion_166, BOGI16_omega_diffusion_167,
	BOGI16_omega_diffusion_168, BOGI16_omega_diffusion_169, BOGI16_omega_diffusion_170, BOGI16_omega_diffusion_171,
	BOGI16_omega_diffusion_172, BOGI16_omega_diffusion_173, BOGI16_omega_diffusion_174, BOGI16_omega_diffusion_175,
	BOGI16_omega_diffusion_176, BOGI16_omega_diffusion_177, BOGI16_omega_diffusion_178, BOGI16_omega_diffusion_179,
	BOGI16_omega_diffusion_180, BOGI16_omega_diffusion_181, BOGI16_omega_diffusion_182, BOGI16_omega_diffusion_183,
	BOGI16_omega_diffusion_184, BOGI16_omega_diffusion_185, BOGI16_omega_diffusion_186, BOGI16_omega_diffusion_187,
	BOGI16_omega_diffusion_188, BOGI16_omega_diffusion_189, BOGI16_omega_diffusion_190, BOGI16_omega_diffusion_191,
	BOGI16_omega_diffusion_192, BOGI16_omega_diffusion_193, BOGI16_omega_diffusion_194, BOGI16_omega_diffusion_195,
	BOGI16_omega_diffusion_196, BOGI16_omega_diffusion_197, BOGI16_omega_diffusion_198, BOGI16_omega_diffusion_199,
	BOGI16_omega_diffusion_200, BOGI16_omega_diffusion_201, BOGI16_omega_diffusion_202, BOGI16_omega_diffusion_203,
	BOGI16_omega_diffusion_204, BOGI16_omega_diffusion_205, BOGI16_omega_diffusion_206, BOGI16_omega_diffusion_207,
	BOGI16_omega_diffusion_208, BOGI16_omega_diffusion_209, BOGI16_omega_diffusion_210, BOGI16_omega_diffusion_211,
	BOGI16_omega_diffusion_212, BOGI16_omega_diffusion_213, BOGI16_omega_diffusion_214, BOGI16_omega_diffusion_215,
	BOGI16_omega_diffusion_216, BOGI16_omega_diffusion_217, BOGI16_omega_diffusion_218, BOGI16_omega_diffusion_219,
	BOGI16_omega_diffusion_220, BOGI16_omega_diffusion_221, BOGI16_omega_diffusion_222, BOGI16_omega_diffusion_223,
	BOGI16_omega_diffusion_224, BOGI16_omega_diffusion_225, BOGI16_omega_diffusion_226, BOGI16_omega_diffusion_227,
	BOGI16_omega_diffusion_228, BOGI16_omega_diffusion_229, BOGI16_omega_diffusion_230, BOGI16_omega_diffusion_231,
	BOGI16_omega_diffusion_232, BOGI16_omega_diffusion_233, BOGI16_omega_diffusion_234, BOGI16_omega_diffusion_235,
	BOGI16_omega_diffusion_236, BOGI16_omega_diffusion_237, BOGI16_omega_diffusion_238, BOGI16_omega_diffusion_239,
	BOGI16_omega_diffusion_240, BOGI16_omega_diffusion_241, BOGI16_omega_diffusion_242, BOGI16_omega_diffusion_243,
	BOGI16_omega_diffusion_244, BOGI16_omega_diffusion_245, BOGI16_omega_diffusion_246, BOGI16_omega_diffusion_247,
	BOGI16_omega_diffusion_248, BOGI16_omega_diffusion_249, BOGI16_omega_diffusion_250, BOGI16_omega_diffusion_251,
	BOGI16_omega_diffusion_252, BOGI16_omega_diffusion_253, BOGI16_omega_diffusion_254, BOGI16_omega_diffusion_255,
	BOGI16_omega_diffusion_256, BOGI16_omega_diffusion_257, BOGI16_omega_diffusion_258, BOGI16_omega_diffusion_259,
	BOGI16_omega_diffusion_260, BOGI16_omega_diffusion_261, BOGI16_omega_diffusion_262, BOGI16_omega_diffusion_263,
	BOGI16_omega_diffusion_264, BOGI16_omega_diffusion_265, BOGI16_omega_diffusion_266, BOGI16_omega_diffusion_267,
	BOGI16_omega_diffusion_268, BOGI16_omega_diffusion_269, BOGI16_omega_diffusion_270, BOGI16_omega_diffusion_271,
	BOGI16_omega_diffusion_272, BOGI16_omega_diffusion_273, BOGI16_omega_diffusion_274, BOGI16_omega_diffusion_275,
	BOGI16_omega_diffusion_276, BOGI16_omega_diffusion_277, BOGI16_omega_diffusion_278, BOGI16_omega_diffusion_279,
	BOGI16_omega_diffusion_280, BOGI16_omega_diffusion_281, BOGI16_omega_diffusion_282, BOGI16_omega_diffusion_283,
	BOGI16_omega_diffusion_284, BOGI16_omega_diffusion_285, BOGI16_omega_diffusion_286, BOGI16_omega_diffusion_287,
	BOGI16_omega_diffusion_288, BOGI16_omega_diffusion_289, BOGI16_omega_diffusion_290, BOGI16_omega_diffusion_291,
	BOGI16_omega_diffusion_292, BOGI16_omega_diffusion_293, BOGI16_omega_diffusion_294, BOGI16_omega_diffusion_295,
	BOGI16_omega_diffusion_296, BOGI16_omega_diffusion_297, BOGI16_omega_diffusion_298, BOGI16_omega_diffusion_299,
	BOGI16_omega_diffusion_300, BOGI16_omega_diffusion_301, BOGI16_omega_diffusion_302, BOGI16_omega_diffusion_303,
	BOGI16_omega_diffusion_304, BOGI16_omega_diffusion_305, BOGI16_omega_diffusion_306, BOGI16_omega_diffusion_307,
	BOGI16_omega_diffusion_308, BOGI16_omega_diffusion_309, BOGI16_omega_diffusion_310, BOGI16_omega_diffusion_311,
	BOGI16_omega_diffusion_312, BOGI16_omega_diffusion_313, BOGI16_omega_diffusion_314, BOGI16_omega_diffusion_315,
	BOGI16_omega_diffusion_316, BOGI16_omega_diffusion_317, BOGI16_omega_diffusion_318, BOGI16_omega_diffusion_319,
	BOGI16_omega_diffusion_320, BOGI16_omega_diffusion_321, BOGI16_omega_diffusion_322, BOGI16_omega_diffusion_323,
	BOGI16_omega_diffusion_324, BOGI16_omega_diffusion_325, BOGI16_omega_diffusion_326, BOGI16_omega_diffusion_327,
	BOGI16_omega_diffusion_328, BOGI16_omega_diffusion_329, BOGI16_omega_diffusion_330, BOGI16_omega_diffusion_331,
	BOGI16_omega_diffusion_332, BOGI16_omega_diffusion_333, BOGI16_omega_diffusion_334, BOGI16_omega_diffusion_335,
	BOGI16_omega_diffusion_336, BOGI16_omega_diffusion_337, BOGI16_omega_diffusion_338, BOGI16_omega_diffusion_339,
	BOGI16_omega_diffusion_340, BOGI16_omega_diffusion_341, BOGI16_omega_diffusion_342, BOGI16_omega_diffusion_343,
	BOGI16_omega_diffusion_344, BOGI16_omega_diffusion_345, BOGI16_omega_diffusion_346, BOGI16_omega_diffusion_347,
	BOGI16_omega_diffusion_348, BOGI16_omega_diffusion_349, BOGI16_omega_diffusion_350, BOGI16_omega_diffusion_351,
	BOGI16_omega_diffusion_352, BOGI16_omega_diffusion_353, BOGI16_omega_diffusion_354, BOGI16_omega_diffusion_355,
	BOGI16_omega_diffusion_356, BOGI16_omega_diffusion_357, BOGI16_omega_diffusion_358, BOGI16_omega_diffusion_359,
	BOGI16_omega_diffusion_360, BOGI16_omega_diffusion_361, BOGI16_omega_diffusion_362, BOGI16_omega_diffusion_363,
	BOGI16_omega_diffusion_364, BOGI16_omega_diffusion_365, BOGI16_omega_diffusion_366, BOGI16_omega_diffusion_367,
	BOGI16_omega_diffusion_368, BOGI16_omega_diffusion_369, BOGI16_omega_diffusion_370, BOGI16_omega_diffusion_371,
	BOGI16_omega_diffusion_372, BOGI16_omega_diffusion_373, BOGI16_omega_diffusion_374, BOGI16_omega_diffusion_375,
	BOGI16_omega_diffusion_376, BOGI16_omega_diffusion_377, BOGI16_omega_diffusion_378, BOGI16_omega_diffusion_379,
	BOGI16_omega_diffusion_380, BOGI16_omega_diffusion_381, BOGI16_omega_diffusion_382, BOGI16_omega_diffusion_383,
	BOGI16_omega_diffusion_384, BOGI16_omega_diffusion_385, BOGI16_omega_diffusion_386, BOGI16_omega_diffusion_387,
	BOGI16_omega_diffusion_388, BOGI16_omega_diffusion_389, BOGI16_omega_diffusion_390, BOGI16_omega_diffusion_391,
	BOGI16_omega_diffusion_392, BOGI16_omega_diffusion_393, BOGI16_omega_diffusion_394, BOGI16_omega_diffusion_395,
	BOGI16_omega_diffusion_396, BOGI16_omega_diffusion_397, BOGI16_omega_diffusion_398, BOGI16_omega_diffusion_399,
	BOGI16_omega_diffusion_400, BOGI16_omega_diffusion_401, BOGI16_omega_diffusion_402, BOGI16_omega_diffusion_403,
	BOGI16_omega_diffusion_404, BOGI16_omega_diffusion_405, BOGI16_omega_diffusion_406, BOGI16_omega_diffusion_407,
	BOGI16_omega_diffusion_408, BOGI16_omega_diffusion_409, BOGI16_omega_diffusion_410, BOGI16_omega_diffusion_411,
	BOGI16_omega_diffusion_412, BOGI16_omega_diffusion_413, BOGI16_omega_diffusion_414, BOGI16_omega_diffusion_415,
	BOGI16_omega_diffusion_416, BOGI16_omega_diffusion_417, BOGI16_omega_diffusion_418, BOGI16_omega_diffusion_419,
	BOGI16_omega_diffusion_420, BOGI16_omega_diffusion_421, BOGI16_omega_diffusion_422, BOGI16_omega_diffusion_423,
	BOGI16_omega_diffusion_424, BOGI16_omega_diffusion_425, BOGI16_omega_diffusion_426, BOGI16_omega_diffusion_427,
	BOGI16_omega_diffusion_428, BOGI16_omega_diffusion_429, BOGI16_omega_diffusion_430, BOGI16_omega_diffusion_431,
	BOGI16_omega_diffusion_432, BOGI16_omega_diffusion_433, BOGI16_omega_diffusion_434, BOGI16_omega_diffusion_435,
	BOGI16_omega_diffusion_436, BOGI16_omega_diffusion_437, BOGI16_omega_diffusion_438, BOGI16_omega_diffusion_439,
	BOGI16_omega_diffusion_440, BOGI16_omega_diffusion_441, BOGI16_omega_diffusion_442, BOGI16_omega_diffusion_443,
	BOGI16_omega_diffusion_444, BOGI16_omega_diffusion_445, BOGI16_omega_diffusion_446, BOGI16_omega_diffusion_447,
	BOGI16_omega_diffusion_448, BOGI16_omega_diffusion_449, BOGI16_omega_diffusion_450, BOGI16_omega_diffusion_451,
	BOGI16_omega_diffusion_452, BOGI16_omega_diffusion_453, BOGI16_omega_diffusion_454, BOGI16_omega_diffusion_455,
	BOGI16_omega_diffusion_456, BOGI16_omega_diffusion_457, BOGI16_omega_diffusion_458, BOGI16_omega_diffusion_459,
	BOGI16_omega_diffusion_460, BOGI16_omega_diffusion_461, BOGI16_omega_diffusion_462, BOGI16_omega_diffusion_463,
	BOGI16_omega_diffusion_464, BOGI16_omega_diffusion_465, BOGI16_omega_diffusion_466, BOGI16_omega_diffusion_467,
	BOGI16_omega_diffusion_468, BOGI16_omega_diffusion_469, BOGI16_omega_diffusion_470, BOGI16_omega_diffusion_471,
	BOGI16_omega_diffusion_472, BOGI16_omega_diffusion_473, BOGI16_omega_diffusion_474, BOGI16_omega_diffusion_475,
	BOGI16_omega_diffusion_476, BOGI16_omega_diffusion_477, BOGI16_omega_diffusion_478, BOGI16_omega_diffusion_479,
	BOGI16_omega_diffusion_480, BOGI16_omega_diffusion_481, BOGI16_omega_diffusion_482, BOGI16_omega_diffusion_483,
	BOGI16_omega_diffusion_484, BOGI16_omega_diffusion_485, BOGI16_omega_diffusion_486, BOGI16_omega_diffusion_487,
	BOGI16_omega_diffusion_488, BOGI16_omega_diffusion_489, BOGI16_omega_diffusion_490, BOGI16_omega_diffusion_491,
	BOGI16_omega_diffusion_492, BOGI16_omega_diffusion_493, BOGI16_omega_diffusion_494, BOGI16_omega_diffusion_495,
	BOGI16_omega_diffusion_496, BOGI16_omega_diffusion_497, BOGI16_omega_diffusion_498, BOGI16_omega_diffusion_499,
	BOGI16_omega_diffusion_500, BOGI16_omega_diffusion_501, BOGI16_omega_diffusion_502, BOGI16_omega_diffusion_503,
	BOGI16_omega_diffusion_504, BOGI16_omega_diffusion_505, BOGI16_omega_diffusion_506, BOGI16_omega_diffusion_507,
	BOGI16_omega_diffusion_508, BOGI16_omega_diffusion_509, BOGI16_omega_diffusion_510, BOGI16_omega_diffusion_511,
	BOGI16_omega_diffusion_512, BOGI16_omega_diffusion_513, BOGI16_omega_diffusion_514, BOGI16_omega_diffusion_515,
	BOGI16_omega_diffusion_516, BOGI16_omega_diffusion_517, BOGI16_omega_diffusion_518, BOGI16_omega_diffusion_519,
	BOGI16_omega_diffusion_520, BOGI16_omega_diffusion_521, BOGI16_omega_diffusion_522, BOGI16_omega_diffusion_523,
	BOGI16_omega_diffusion_524, BOGI16_omega_diffusion_525, BOGI16_omega_diffusion_526, BOGI16_omega_diffusion_527,
	BOGI16_omega_diffusion_528, BOGI16_omega_diffusion_529, BOGI16_omega_diffusion_530, BOGI16_omega_diffusion_531,
	BOGI16_omega_diffusion_532, BOGI16_omega_diffusion_533, BOGI16_omega_diffusion_534, BOGI16_omega_diffusion_535,
	BOGI16_omega_diffusion_536, BOGI16_omega_diffusion_537, BOGI16_omega_diffusion_538, BOGI16_omega_diffusion_539,
	BOGI16_omega_diffusion_540, BOGI16_omega_diffusion_541, BOGI16_omega_diffusion_542, BOGI16_omega_diffusion_543,
	BOGI16_omega_diffusion_544, BOGI16_omega_diffusion_545, BOGI16_omega_diffusion_546, BOGI16_omega_diffusion_547,
	BOGI16_omega_diffusion_548, BOGI16_omega_diffusion_549, BOGI16_omega_diffusion_550, BOGI16_omega_diffusion_551,
	BOGI16_omega_diffusion_552, BOGI16_omega_diffusion_553, BOGI16_omega_diffusion_554, BOGI16_omega_diffusion_555,
	BOGI16_omega_diffusion_556, BOGI16_omega_diffusion_557, BOGI16_omega_diffusion_558, BOGI16_omega_diffusion_559,
	BOGI16_omega_diffusion_560, BOGI16_omega_diffusion_561, BOGI16_omega_diffusion_562, BOGI16_omega_diffusion_563,
	BOGI16_omega_diffusion_564, BOGI16_omega_diffusion_565, BOGI16_omega_diffusion_566, BOGI16_omega_diffusion_567,
	BOGI16_omega_diffusion_568, BOGI16_omega_diffusion_569, BOGI16_omega_diffusion_570, BOGI16_omega_diffusion_571,
	BOGI16_omega_diffusion_572, BOGI16_omega_diffusion_573, BOGI16_omega_diffusion_574, BOGI16_omega_diffusion_575,
};

void(*BOGI16_omega_inv_diffusion[576])(DIFF_I_WRD_t *, DIFF_O_WRD_t *) = {
	BOGI16_omega_inv_diffusion_0, BOGI16_omega_inv_diffusion_1, BOGI16_omega_inv_diffusion_2, BOGI16_omega_inv_diffusion_3,
	BOGI16_omega_inv_diffusion_4, BOGI16_omega_inv_diffusion_5, BOGI16_omega_inv_diffusion_6, BOGI16_omega_inv_diffusion_7,
	BOGI16_omega_inv_diffusion_8, BOGI16_omega_inv_diffusion_9, BOGI16_omega_inv_diffusion_10, BOGI16_omega_inv_diffusion_11,
	BOGI16_omega_inv_diffusion_12, BOGI16_omega_inv_diffusion_13, BOGI16_omega_inv_diffusion_14, BOGI16_omega_inv_diffusion_15,
	BOGI16_omega_inv_diffusion_16, BOGI16_omega_inv_diffusion_17, BOGI16_omega_inv_diffusion_18, BOGI16_omega_inv_diffusion_19,
	BOGI16_omega_inv_diffusion_20, BOGI16_omega_inv_diffusion_21, BOGI16_omega_inv_diffusion_22, BOGI16_omega_inv_diffusion_23,
	BOGI16_omega_inv_diffusion_24, BOGI16_omega_inv_diffusion_25, BOGI16_omega_inv_diffusion_26, BOGI16_omega_inv_diffusion_27,
	BOGI16_omega_inv_diffusion_28, BOGI16_omega_inv_diffusion_29, BOGI16_omega_inv_diffusion_30, BOGI16_omega_inv_diffusion_31,
	BOGI16_omega_inv_diffusion_32, BOGI16_omega_inv_diffusion_33, BOGI16_omega_inv_diffusion_34, BOGI16_omega_inv_diffusion_35,
	BOGI16_omega_inv_diffusion_36, BOGI16_omega_inv_diffusion_37, BOGI16_omega_inv_diffusion_38, BOGI16_omega_inv_diffusion_39,
	BOGI16_omega_inv_diffusion_40, BOGI16_omega_inv_diffusion_41, BOGI16_omega_inv_diffusion_42, BOGI16_omega_inv_diffusion_43,
	BOGI16_omega_inv_diffusion_44, BOGI16_omega_inv_diffusion_45, BOGI16_omega_inv_diffusion_46, BOGI16_omega_inv_diffusion_47,
	BOGI16_omega_inv_diffusion_48, BOGI16_omega_inv_diffusion_49, BOGI16_omega_inv_diffusion_50, BOGI16_omega_inv_diffusion_51,
	BOGI16_omega_inv_diffusion_52, BOGI16_omega_inv_diffusion_53, BOGI16_omega_inv_diffusion_54, BOGI16_omega_inv_diffusion_55,
	BOGI16_omega_inv_diffusion_56, BOGI16_omega_inv_diffusion_57, BOGI16_omega_inv_diffusion_58, BOGI16_omega_inv_diffusion_59,
	BOGI16_omega_inv_diffusion_60, BOGI16_omega_inv_diffusion_61, BOGI16_omega_inv_diffusion_62, BOGI16_omega_inv_diffusion_63,
	BOGI16_omega_inv_diffusion_64, BOGI16_omega_inv_diffusion_65, BOGI16_omega_inv_diffusion_66, BOGI16_omega_inv_diffusion_67,
	BOGI16_omega_inv_diffusion_68, BOGI16_omega_inv_diffusion_69, BOGI16_omega_inv_diffusion_70, BOGI16_omega_inv_diffusion_71,
	BOGI16_omega_inv_diffusion_72, BOGI16_omega_inv_diffusion_73, BOGI16_omega_inv_diffusion_74, BOGI16_omega_inv_diffusion_75,
	BOGI16_omega_inv_diffusion_76, BOGI16_omega_inv_diffusion_77, BOGI16_omega_inv_diffusion_78, BOGI16_omega_inv_diffusion_79,
	BOGI16_omega_inv_diffusion_80, BOGI16_omega_inv_diffusion_81, BOGI16_omega_inv_diffusion_82, BOGI16_omega_inv_diffusion_83,
	BOGI16_omega_inv_diffusion_84, BOGI16_omega_inv_diffusion_85, BOGI16_omega_inv_diffusion_86, BOGI16_omega_inv_diffusion_87,
	BOGI16_omega_inv_diffusion_88, BOGI16_omega_inv_diffusion_89, BOGI16_omega_inv_diffusion_90, BOGI16_omega_inv_diffusion_91,
	BOGI16_omega_inv_diffusion_92, BOGI16_omega_inv_diffusion_93, BOGI16_omega_inv_diffusion_94, BOGI16_omega_inv_diffusion_95,
	BOGI16_omega_inv_diffusion_96, BOGI16_omega_inv_diffusion_97, BOGI16_omega_inv_diffusion_98, BOGI16_omega_inv_diffusion_99,
	BOGI16_omega_inv_diffusion_100, BOGI16_omega_inv_diffusion_101, BOGI16_omega_inv_diffusion_102, BOGI16_omega_inv_diffusion_103,
	BOGI16_omega_inv_diffusion_104, BOGI16_omega_inv_diffusion_105, BOGI16_omega_inv_diffusion_106, BOGI16_omega_inv_diffusion_107,
	BOGI16_omega_inv_diffusion_108, BOGI16_omega_inv_diffusion_109, BOGI16_omega_inv_diffusion_110, BOGI16_omega_inv_diffusion_111,
	BOGI16_omega_inv_diffusion_112, BOGI16_omega_inv_diffusion_113, BOGI16_omega_inv_diffusion_114, BOGI16_omega_inv_diffusion_115,
	BOGI16_omega_inv_diffusion_116, BOGI16_omega_inv_diffusion_117, BOGI16_omega_inv_diffusion_118, BOGI16_omega_inv_diffusion_119,
	BOGI16_omega_inv_diffusion_120, BOGI16_omega_inv_diffusion_121, BOGI16_omega_inv_diffusion_122, BOGI16_omega_inv_diffusion_123,
	BOGI16_omega_inv_diffusion_124, BOGI16_omega_inv_diffusion_125, BOGI16_omega_inv_diffusion_126, BOGI16_omega_inv_diffusion_127,
	BOGI16_omega_inv_diffusion_128, BOGI16_omega_inv_diffusion_129, BOGI16_omega_inv_diffusion_130, BOGI16_omega_inv_diffusion_131,
	BOGI16_omega_inv_diffusion_132, BOGI16_omega_inv_diffusion_133, BOGI16_omega_inv_diffusion_134, BOGI16_omega_inv_diffusion_135,
	BOGI16_omega_inv_diffusion_136, BOGI16_omega_inv_diffusion_137, BOGI16_omega_inv_diffusion_138, BOGI16_omega_inv_diffusion_139,
	BOGI16_omega_inv_diffusion_140, BOGI16_omega_inv_diffusion_141, BOGI16_omega_inv_diffusion_142, BOGI16_omega_inv_diffusion_143,
	BOGI16_omega_inv_diffusion_144, BOGI16_omega_inv_diffusion_145, BOGI16_omega_inv_diffusion_146, BOGI16_omega_inv_diffusion_147,
	BOGI16_omega_inv_diffusion_148, BOGI16_omega_inv_diffusion_149, BOGI16_omega_inv_diffusion_150, BOGI16_omega_inv_diffusion_151,
	BOGI16_omega_inv_diffusion_152, BOGI16_omega_inv_diffusion_153, BOGI16_omega_inv_diffusion_154, BOGI16_omega_inv_diffusion_155,
	BOGI16_omega_inv_diffusion_156, BOGI16_omega_inv_diffusion_157, BOGI16_omega_inv_diffusion_158, BOGI16_omega_inv_diffusion_159,
	BOGI16_omega_inv_diffusion_160, BOGI16_omega_inv_diffusion_161, BOGI16_omega_inv_diffusion_162, BOGI16_omega_inv_diffusion_163,
	BOGI16_omega_inv_diffusion_164, BOGI16_omega_inv_diffusion_165, BOGI16_omega_inv_diffusion_166, BOGI16_omega_inv_diffusion_167,
	BOGI16_omega_inv_diffusion_168, BOGI16_omega_inv_diffusion_169, BOGI16_omega_inv_diffusion_170, BOGI16_omega_inv_diffusion_171,
	BOGI16_omega_inv_diffusion_172, BOGI16_omega_inv_diffusion_173, BOGI16_omega_inv_diffusion_174, BOGI16_omega_inv_diffusion_175,
	BOGI16_omega_inv_diffusion_176, BOGI16_omega_inv_diffusion_177, BOGI16_omega_inv_diffusion_178, BOGI16_omega_inv_diffusion_179,
	BOGI16_omega_inv_diffusion_180, BOGI16_omega_inv_diffusion_181, BOGI16_omega_inv_diffusion_182, BOGI16_omega_inv_diffusion_183,
	BOGI16_omega_inv_diffusion_184, BOGI16_omega_inv_diffusion_185, BOGI16_omega_inv_diffusion_186, BOGI16_omega_inv_diffusion_187,
	BOGI16_omega_inv_diffusion_188, BOGI16_omega_inv_diffusion_189, BOGI16_omega_inv_diffusion_190, BOGI16_omega_inv_diffusion_191,
	BOGI16_omega_inv_diffusion_192, BOGI16_omega_inv_diffusion_193, BOGI16_omega_inv_diffusion_194, BOGI16_omega_inv_diffusion_195,
	BOGI16_omega_inv_diffusion_196, BOGI16_omega_inv_diffusion_197, BOGI16_omega_inv_diffusion_198, BOGI16_omega_inv_diffusion_199,
	BOGI16_omega_inv_diffusion_200, BOGI16_omega_inv_diffusion_201, BOGI16_omega_inv_diffusion_202, BOGI16_omega_inv_diffusion_203,
	BOGI16_omega_inv_diffusion_204, BOGI16_omega_inv_diffusion_205, BOGI16_omega_inv_diffusion_206, BOGI16_omega_inv_diffusion_207,
	BOGI16_omega_inv_diffusion_208, BOGI16_omega_inv_diffusion_209, BOGI16_omega_inv_diffusion_210, BOGI16_omega_inv_diffusion_211,
	BOGI16_omega_inv_diffusion_212, BOGI16_omega_inv_diffusion_213, BOGI16_omega_inv_diffusion_214, BOGI16_omega_inv_diffusion_215,
	BOGI16_omega_inv_diffusion_216, BOGI16_omega_inv_diffusion_217, BOGI16_omega_inv_diffusion_218, BOGI16_omega_inv_diffusion_219,
	BOGI16_omega_inv_diffusion_220, BOGI16_omega_inv_diffusion_221, BOGI16_omega_inv_diffusion_222, BOGI16_omega_inv_diffusion_223,
	BOGI16_omega_inv_diffusion_224, BOGI16_omega_inv_diffusion_225, BOGI16_omega_inv_diffusion_226, BOGI16_omega_inv_diffusion_227,
	BOGI16_omega_inv_diffusion_228, BOGI16_omega_inv_diffusion_229, BOGI16_omega_inv_diffusion_230, BOGI16_omega_inv_diffusion_231,
	BOGI16_omega_inv_diffusion_232, BOGI16_omega_inv_diffusion_233, BOGI16_omega_inv_diffusion_234, BOGI16_omega_inv_diffusion_235,
	BOGI16_omega_inv_diffusion_236, BOGI16_omega_inv_diffusion_237, BOGI16_omega_inv_diffusion_238, BOGI16_omega_inv_diffusion_239,
	BOGI16_omega_inv_diffusion_240, BOGI16_omega_inv_diffusion_241, BOGI16_omega_inv_diffusion_242, BOGI16_omega_inv_diffusion_243,
	BOGI16_omega_inv_diffusion_244, BOGI16_omega_inv_diffusion_245, BOGI16_omega_inv_diffusion_246, BOGI16_omega_inv_diffusion_247,
	BOGI16_omega_inv_diffusion_248, BOGI16_omega_inv_diffusion_249, BOGI16_omega_inv_diffusion_250, BOGI16_omega_inv_diffusion_251,
	BOGI16_omega_inv_diffusion_252, BOGI16_omega_inv_diffusion_253, BOGI16_omega_inv_diffusion_254, BOGI16_omega_inv_diffusion_255,
	BOGI16_omega_inv_diffusion_256, BOGI16_omega_inv_diffusion_257, BOGI16_omega_inv_diffusion_258, BOGI16_omega_inv_diffusion_259,
	BOGI16_omega_inv_diffusion_260, BOGI16_omega_inv_diffusion_261, BOGI16_omega_inv_diffusion_262, BOGI16_omega_inv_diffusion_263,
	BOGI16_omega_inv_diffusion_264, BOGI16_omega_inv_diffusion_265, BOGI16_omega_inv_diffusion_266, BOGI16_omega_inv_diffusion_267,
	BOGI16_omega_inv_diffusion_268, BOGI16_omega_inv_diffusion_269, BOGI16_omega_inv_diffusion_270, BOGI16_omega_inv_diffusion_271,
	BOGI16_omega_inv_diffusion_272, BOGI16_omega_inv_diffusion_273, BOGI16_omega_inv_diffusion_274, BOGI16_omega_inv_diffusion_275,
	BOGI16_omega_inv_diffusion_276, BOGI16_omega_inv_diffusion_277, BOGI16_omega_inv_diffusion_278, BOGI16_omega_inv_diffusion_279,
	BOGI16_omega_inv_diffusion_280, BOGI16_omega_inv_diffusion_281, BOGI16_omega_inv_diffusion_282, BOGI16_omega_inv_diffusion_283,
	BOGI16_omega_inv_diffusion_284, BOGI16_omega_inv_diffusion_285, BOGI16_omega_inv_diffusion_286, BOGI16_omega_inv_diffusion_287,
	BOGI16_omega_inv_diffusion_288, BOGI16_omega_inv_diffusion_289, BOGI16_omega_inv_diffusion_290, BOGI16_omega_inv_diffusion_291,
	BOGI16_omega_inv_diffusion_292, BOGI16_omega_inv_diffusion_293, BOGI16_omega_inv_diffusion_294, BOGI16_omega_inv_diffusion_295,
	BOGI16_omega_inv_diffusion_296, BOGI16_omega_inv_diffusion_297, BOGI16_omega_inv_diffusion_298, BOGI16_omega_inv_diffusion_299,
	BOGI16_omega_inv_diffusion_300, BOGI16_omega_inv_diffusion_301, BOGI16_omega_inv_diffusion_302, BOGI16_omega_inv_diffusion_303,
	BOGI16_omega_inv_diffusion_304, BOGI16_omega_inv_diffusion_305, BOGI16_omega_inv_diffusion_306, BOGI16_omega_inv_diffusion_307,
	BOGI16_omega_inv_diffusion_308, BOGI16_omega_inv_diffusion_309, BOGI16_omega_inv_diffusion_310, BOGI16_omega_inv_diffusion_311,
	BOGI16_omega_inv_diffusion_312, BOGI16_omega_inv_diffusion_313, BOGI16_omega_inv_diffusion_314, BOGI16_omega_inv_diffusion_315,
	BOGI16_omega_inv_diffusion_316, BOGI16_omega_inv_diffusion_317, BOGI16_omega_inv_diffusion_318, BOGI16_omega_inv_diffusion_319,
	BOGI16_omega_inv_diffusion_320, BOGI16_omega_inv_diffusion_321, BOGI16_omega_inv_diffusion_322, BOGI16_omega_inv_diffusion_323,
	BOGI16_omega_inv_diffusion_324, BOGI16_omega_inv_diffusion_325, BOGI16_omega_inv_diffusion_326, BOGI16_omega_inv_diffusion_327,
	BOGI16_omega_inv_diffusion_328, BOGI16_omega_inv_diffusion_329, BOGI16_omega_inv_diffusion_330, BOGI16_omega_inv_diffusion_331,
	BOGI16_omega_inv_diffusion_332, BOGI16_omega_inv_diffusion_333, BOGI16_omega_inv_diffusion_334, BOGI16_omega_inv_diffusion_335,
	BOGI16_omega_inv_diffusion_336, BOGI16_omega_inv_diffusion_337, BOGI16_omega_inv_diffusion_338, BOGI16_omega_inv_diffusion_339,
	BOGI16_omega_inv_diffusion_340, BOGI16_omega_inv_diffusion_341, BOGI16_omega_inv_diffusion_342, BOGI16_omega_inv_diffusion_343,
	BOGI16_omega_inv_diffusion_344, BOGI16_omega_inv_diffusion_345, BOGI16_omega_inv_diffusion_346, BOGI16_omega_inv_diffusion_347,
	BOGI16_omega_inv_diffusion_348, BOGI16_omega_inv_diffusion_349, BOGI16_omega_inv_diffusion_350, BOGI16_omega_inv_diffusion_351,
	BOGI16_omega_inv_diffusion_352, BOGI16_omega_inv_diffusion_353, BOGI16_omega_inv_diffusion_354, BOGI16_omega_inv_diffusion_355,
	BOGI16_omega_inv_diffusion_356, BOGI16_omega_inv_diffusion_357, BOGI16_omega_inv_diffusion_358, BOGI16_omega_inv_diffusion_359,
	BOGI16_omega_inv_diffusion_360, BOGI16_omega_inv_diffusion_361, BOGI16_omega_inv_diffusion_362, BOGI16_omega_inv_diffusion_363,
	BOGI16_omega_inv_diffusion_364, BOGI16_omega_inv_diffusion_365, BOGI16_omega_inv_diffusion_366, BOGI16_omega_inv_diffusion_367,
	BOGI16_omega_inv_diffusion_368, BOGI16_omega_inv_diffusion_369, BOGI16_omega_inv_diffusion_370, BOGI16_omega_inv_diffusion_371,
	BOGI16_omega_inv_diffusion_372, BOGI16_omega_inv_diffusion_373, BOGI16_omega_inv_diffusion_374, BOGI16_omega_inv_diffusion_375,
	BOGI16_omega_inv_diffusion_376, BOGI16_omega_inv_diffusion_377, BOGI16_omega_inv_diffusion_378, BOGI16_omega_inv_diffusion_379,
	BOGI16_omega_inv_diffusion_380, BOGI16_omega_inv_diffusion_381, BOGI16_omega_inv_diffusion_382, BOGI16_omega_inv_diffusion_383,
	BOGI16_omega_inv_diffusion_384, BOGI16_omega_inv_diffusion_385, BOGI16_omega_inv_diffusion_386, BOGI16_omega_inv_diffusion_387,
	BOGI16_omega_inv_diffusion_388, BOGI16_omega_inv_diffusion_389, BOGI16_omega_inv_diffusion_390, BOGI16_omega_inv_diffusion_391,
	BOGI16_omega_inv_diffusion_392, BOGI16_omega_inv_diffusion_393, BOGI16_omega_inv_diffusion_394, BOGI16_omega_inv_diffusion_395,
	BOGI16_omega_inv_diffusion_396, BOGI16_omega_inv_diffusion_397, BOGI16_omega_inv_diffusion_398, BOGI16_omega_inv_diffusion_399,
	BOGI16_omega_inv_diffusion_400, BOGI16_omega_inv_diffusion_401, BOGI16_omega_inv_diffusion_402, BOGI16_omega_inv_diffusion_403,
	BOGI16_omega_inv_diffusion_404, BOGI16_omega_inv_diffusion_405, BOGI16_omega_inv_diffusion_406, BOGI16_omega_inv_diffusion_407,
	BOGI16_omega_inv_diffusion_408, BOGI16_omega_inv_diffusion_409, BOGI16_omega_inv_diffusion_410, BOGI16_omega_inv_diffusion_411,
	BOGI16_omega_inv_diffusion_412, BOGI16_omega_inv_diffusion_413, BOGI16_omega_inv_diffusion_414, BOGI16_omega_inv_diffusion_415,
	BOGI16_omega_inv_diffusion_416, BOGI16_omega_inv_diffusion_417, BOGI16_omega_inv_diffusion_418, BOGI16_omega_inv_diffusion_419,
	BOGI16_omega_inv_diffusion_420, BOGI16_omega_inv_diffusion_421, BOGI16_omega_inv_diffusion_422, BOGI16_omega_inv_diffusion_423,
	BOGI16_omega_inv_diffusion_424, BOGI16_omega_inv_diffusion_425, BOGI16_omega_inv_diffusion_426, BOGI16_omega_inv_diffusion_427,
	BOGI16_omega_inv_diffusion_428, BOGI16_omega_inv_diffusion_429, BOGI16_omega_inv_diffusion_430, BOGI16_omega_inv_diffusion_431,
	BOGI16_omega_inv_diffusion_432, BOGI16_omega_inv_diffusion_433, BOGI16_omega_inv_diffusion_434, BOGI16_omega_inv_diffusion_435,
	BOGI16_omega_inv_diffusion_436, BOGI16_omega_inv_diffusion_437, BOGI16_omega_inv_diffusion_438, BOGI16_omega_inv_diffusion_439,
	BOGI16_omega_inv_diffusion_440, BOGI16_omega_inv_diffusion_441, BOGI16_omega_inv_diffusion_442, BOGI16_omega_inv_diffusion_443,
	BOGI16_omega_inv_diffusion_444, BOGI16_omega_inv_diffusion_445, BOGI16_omega_inv_diffusion_446, BOGI16_omega_inv_diffusion_447,
	BOGI16_omega_inv_diffusion_448, BOGI16_omega_inv_diffusion_449, BOGI16_omega_inv_diffusion_450, BOGI16_omega_inv_diffusion_451,
	BOGI16_omega_inv_diffusion_452, BOGI16_omega_inv_diffusion_453, BOGI16_omega_inv_diffusion_454, BOGI16_omega_inv_diffusion_455,
	BOGI16_omega_inv_diffusion_456, BOGI16_omega_inv_diffusion_457, BOGI16_omega_inv_diffusion_458, BOGI16_omega_inv_diffusion_459,
	BOGI16_omega_inv_diffusion_460, BOGI16_omega_inv_diffusion_461, BOGI16_omega_inv_diffusion_462, BOGI16_omega_inv_diffusion_463,
	BOGI16_omega_inv_diffusion_464, BOGI16_omega_inv_diffusion_465, BOGI16_omega_inv_diffusion_466, BOGI16_omega_inv_diffusion_467,
	BOGI16_omega_inv_diffusion_468, BOGI16_omega_inv_diffusion_469, BOGI16_omega_inv_diffusion_470, BOGI16_omega_inv_diffusion_471,
	BOGI16_omega_inv_diffusion_472, BOGI16_omega_inv_diffusion_473, BOGI16_omega_inv_diffusion_474, BOGI16_omega_inv_diffusion_475,
	BOGI16_omega_inv_diffusion_476, BOGI16_omega_inv_diffusion_477, BOGI16_omega_inv_diffusion_478, BOGI16_omega_inv_diffusion_479,
	BOGI16_omega_inv_diffusion_480, BOGI16_omega_inv_diffusion_481, BOGI16_omega_inv_diffusion_482, BOGI16_omega_inv_diffusion_483,
	BOGI16_omega_inv_diffusion_484, BOGI16_omega_inv_diffusion_485, BOGI16_omega_inv_diffusion_486, BOGI16_omega_inv_diffusion_487,
	BOGI16_omega_inv_diffusion_488, BOGI16_omega_inv_diffusion_489, BOGI16_omega_inv_diffusion_490, BOGI16_omega_inv_diffusion_491,
	BOGI16_omega_inv_diffusion_492, BOGI16_omega_inv_diffusion_493, BOGI16_omega_inv_diffusion_494, BOGI16_omega_inv_diffusion_495,
	BOGI16_omega_inv_diffusion_496, BOGI16_omega_inv_diffusion_497, BOGI16_omega_inv_diffusion_498, BOGI16_omega_inv_diffusion_499,
	BOGI16_omega_inv_diffusion_500, BOGI16_omega_inv_diffusion_501, BOGI16_omega_inv_diffusion_502, BOGI16_omega_inv_diffusion_503,
	BOGI16_omega_inv_diffusion_504, BOGI16_omega_inv_diffusion_505, BOGI16_omega_inv_diffusion_506, BOGI16_omega_inv_diffusion_507,
	BOGI16_omega_inv_diffusion_508, BOGI16_omega_inv_diffusion_509, BOGI16_omega_inv_diffusion_510, BOGI16_omega_inv_diffusion_511,
	BOGI16_omega_inv_diffusion_512, BOGI16_omega_inv_diffusion_513, BOGI16_omega_inv_diffusion_514, BOGI16_omega_inv_diffusion_515,
	BOGI16_omega_inv_diffusion_516, BOGI16_omega_inv_diffusion_517, BOGI16_omega_inv_diffusion_518, BOGI16_omega_inv_diffusion_519,
	BOGI16_omega_inv_diffusion_520, BOGI16_omega_inv_diffusion_521, BOGI16_omega_inv_diffusion_522, BOGI16_omega_inv_diffusion_523,
	BOGI16_omega_inv_diffusion_524, BOGI16_omega_inv_diffusion_525, BOGI16_omega_inv_diffusion_526, BOGI16_omega_inv_diffusion_527,
	BOGI16_omega_inv_diffusion_528, BOGI16_omega_inv_diffusion_529, BOGI16_omega_inv_diffusion_530, BOGI16_omega_inv_diffusion_531,
	BOGI16_omega_inv_diffusion_532, BOGI16_omega_inv_diffusion_533, BOGI16_omega_inv_diffusion_534, BOGI16_omega_inv_diffusion_535,
	BOGI16_omega_inv_diffusion_536, BOGI16_omega_inv_diffusion_537, BOGI16_omega_inv_diffusion_538, BOGI16_omega_inv_diffusion_539,
	BOGI16_omega_inv_diffusion_540, BOGI16_omega_inv_diffusion_541, BOGI16_omega_inv_diffusion_542, BOGI16_omega_inv_diffusion_543,
	BOGI16_omega_inv_diffusion_544, BOGI16_omega_inv_diffusion_545, BOGI16_omega_inv_diffusion_546, BOGI16_omega_inv_diffusion_547,
	BOGI16_omega_inv_diffusion_548, BOGI16_omega_inv_diffusion_549, BOGI16_omega_inv_diffusion_550, BOGI16_omega_inv_diffusion_551,
	BOGI16_omega_inv_diffusion_552, BOGI16_omega_inv_diffusion_553, BOGI16_omega_inv_diffusion_554, BOGI16_omega_inv_diffusion_555,
	BOGI16_omega_inv_diffusion_556, BOGI16_omega_inv_diffusion_557, BOGI16_omega_inv_diffusion_558, BOGI16_omega_inv_diffusion_559,
	BOGI16_omega_inv_diffusion_560, BOGI16_omega_inv_diffusion_561, BOGI16_omega_inv_diffusion_562, BOGI16_omega_inv_diffusion_563,
	BOGI16_omega_inv_diffusion_564, BOGI16_omega_inv_diffusion_565, BOGI16_omega_inv_diffusion_566, BOGI16_omega_inv_diffusion_567,
	BOGI16_omega_inv_diffusion_568, BOGI16_omega_inv_diffusion_569, BOGI16_omega_inv_diffusion_570, BOGI16_omega_inv_diffusion_571,
	BOGI16_omega_inv_diffusion_572, BOGI16_omega_inv_diffusion_573, BOGI16_omega_inv_diffusion_574, BOGI16_omega_inv_diffusion_575,
};
