#include "astbb.h"


//((0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_0(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x02042010) << 4)
		| ROL32(x & 0x80400102, 8)
		| ROL32(x & 0x04081080, 12)
		| ROL32(x & 0x40200204, 16)
		| ROL32(x & 0x08018040, 20)
		| ROL32(x & 0x20100408, 24)
		| ((x & 0x01024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_0(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x00102402) << 4)
		| ROL32(x & 0x08201004, 8)
		| ROL32(x & 0x04008018, 12)
		| ROL32(x & 0x02044020, 16)
		| ROL32(x & 0x81080040, 20)
		| ROL32(x & 0x40010280, 24)
		| ((x & 0x20420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_1(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800401)
		| ((x & 0x02042010) << 4)
		| ROL32(x & 0x40400102, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80200204, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x20100808, 24)
		| ((x & 0x01028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_1(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800401)
		| ((x & 0x00102802) << 4)
		| ROL32(x & 0x08201008, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x02048020, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x40010240, 24)
		| ((x & 0x20420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_2(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400801)
		| ((x & 0x02082010) << 4)
		| ROL32(x & 0x80800102, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40200208, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x20100404, 24)
		| ((x & 0x01024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_2(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400801)
		| ((x & 0x00102402) << 4)
		| ROL32(x & 0x04201004, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x02084020, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x80010280, 24)
		| ((x & 0x20820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_3(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x02082010) << 4)
		| ROL32(x & 0x40800102, 8)
		| ROL32(x & 0x08041040, 12)
		| ROL32(x & 0x80200208, 16)
		| ROL32(x & 0x04014080, 20)
		| ROL32(x & 0x20100804, 24)
		| ((x & 0x01028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_3(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x00102802) << 4)
		| ROL32(x & 0x04201008, 8)
		| ROL32(x & 0x08004014, 12)
		| ROL32(x & 0x02088020, 16)
		| ROL32(x & 0x41040080, 20)
		| ROL32(x & 0x80010240, 24)
		| ((x & 0x20820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 2, 3, 0), (2, 3, 0, 1), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 13, 10, 7, 4, 1, 14, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_4(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200801)
		| ((x & 0x02048010) << 4)
		| ROL32(x & 0x20400102, 8)
		| ROL32(x & 0x04081020, 12)
		| ROL32(x & 0x40800204, 16)
		| ROL32(x & 0x08012040, 20)
		| ROL32(x & 0x80100408, 24)
		| ((x & 0x01024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_4(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200801)
		| ((x & 0x00102408) << 4)
		| ROL32(x & 0x08801004, 8)
		| ROL32(x & 0x04008012, 12)
		| ROL32(x & 0x02044080, 16)
		| ROL32(x & 0x81020040, 20)
		| ROL32(x & 0x40010220, 24)
		| ((x & 0x20480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 2, 3, 0), (3, 0, 1, 2), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 1, 10, 7, 0, 5, 14, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_5(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200401)
		| ((x & 0x02084010) << 4)
		| ROL32(x & 0x20800102, 8)
		| ROL32(x & 0x08041020, 12)
		| ROL32(x & 0x80400208, 16)
		| ROL32(x & 0x04012080, 20)
		| ROL32(x & 0x40100804, 24)
		| ((x & 0x01028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_5(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200401)
		| ((x & 0x00102804) << 4)
		| ROL32(x & 0x04401008, 8)
		| ROL32(x & 0x08004012, 12)
		| ROL32(x & 0x02088040, 16)
		| ROL32(x & 0x41020080, 20)
		| ROL32(x & 0x80010220, 24)
		| ((x & 0x20840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 3, 0, 2), (2, 0, 3, 1), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 1, 14, 7, 4, 13, 2, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_6(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x02024010) << 4)
		| ROL32(x & 0x80400104, 8)
		| ROL32(x & 0x04081080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08018040, 20)
		| ROL32(x & 0x40100408, 24)
		| ((x & 0x01042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_6(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x00104202) << 4)
		| ROL32(x & 0x08401004, 8)
		| ROL32(x & 0x04008018, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x81080040, 20)
		| ROL32(x & 0x40010480, 24)
		| ((x & 0x20240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (1, 3, 0, 2), (3, 2, 1, 0), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 9, 14, 7, 12, 5, 2, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_7(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x02028010) << 4)
		| ROL32(x & 0x40800108, 8)
		| ROL32(x & 0x08041040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04014080, 20)
		| ROL32(x & 0x80100804, 24)
		| ((x & 0x01082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_7(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x00108202) << 4)
		| ROL32(x & 0x04801008, 8)
		| ROL32(x & 0x08004014, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x41040080, 20)
		| ROL32(x & 0x80010840, 24)
		| ((x & 0x20280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 0, 3, 1), (1, 3, 0, 2), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 13, 2, 7, 4, 1, 14, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_8(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x04042010) << 4)
		| ROL32(x & 0x80200102, 8)
		| ROL32(x & 0x02081080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08018020, 20)
		| ROL32(x & 0x20100208, 24)
		| ((x & 0x01024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_8(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x00102404) << 4)
		| ROL32(x & 0x08201002, 8)
		| ROL32(x & 0x02008018, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x81080020, 20)
		| ROL32(x & 0x20010280, 24)
		| ((x & 0x40420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 0, 3, 1), (3, 2, 1, 0), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 9, 2, 7, 0, 5, 14, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_9(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x08082010) << 4)
		| ROL32(x & 0x40200102, 8)
		| ROL32(x & 0x02041040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04014020, 20)
		| ROL32(x & 0x20100204, 24)
		| ((x & 0x01028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_9(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x00102808) << 4)
		| ROL32(x & 0x04201002, 8)
		| ROL32(x & 0x02004014, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x41040020, 20)
		| ROL32(x & 0x20010240, 24)
		| ((x & 0x80820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 1, 14, 7, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_10(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x04024010) << 4)
		| ROL32(x & 0x80200104, 8)
		| ROL32(x & 0x02081080, 12)
		| ROL32(x & 0x20400402, 16)
		| ROL32(x & 0x08018020, 20)
		| ROL32(x & 0x40100208, 24)
		| ((x & 0x01042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_10(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800801)
		| ((x & 0x00104204) << 4)
		| ROL32(x & 0x08401002, 8)
		| ROL32(x & 0x02008018, 12)
		| ROL32(x & 0x04022040, 16)
		| ROL32(x & 0x81080020, 20)
		| ROL32(x & 0x20010480, 24)
		| ((x & 0x40240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 9, 14, 7, 4, 13, 2, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_11(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400801)
		| ((x & 0x04028010) << 4)
		| ROL32(x & 0x40200104, 8)
		| ROL32(x & 0x02081040, 12)
		| ROL32(x & 0x20800402, 16)
		| ROL32(x & 0x08014020, 20)
		| ROL32(x & 0x80100208, 24)
		| ((x & 0x01042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_11(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400801)
		| ((x & 0x00104208) << 4)
		| ROL32(x & 0x08801002, 8)
		| ROL32(x & 0x02008014, 12)
		| ROL32(x & 0x04022080, 16)
		| ROL32(x & 0x81040020, 20)
		| ROL32(x & 0x20010440, 24)
		| ((x & 0x40280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 1, 14, 7, 12, 5, 2, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_12(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800401)
		| ((x & 0x08024010) << 4)
		| ROL32(x & 0x80200108, 8)
		| ROL32(x & 0x02041080, 12)
		| ROL32(x & 0x20400802, 16)
		| ROL32(x & 0x04018020, 20)
		| ROL32(x & 0x40100204, 24)
		| ((x & 0x01082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_12(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800401)
		| ((x & 0x00108204) << 4)
		| ROL32(x & 0x04401002, 8)
		| ROL32(x & 0x02004018, 12)
		| ROL32(x & 0x08022040, 16)
		| ROL32(x & 0x41080020, 20)
		| ROL32(x & 0x20010880, 24)
		| ((x & 0x80240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 9, 14, 7, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_13(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x08028010) << 4)
		| ROL32(x & 0x40200108, 8)
		| ROL32(x & 0x02041040, 12)
		| ROL32(x & 0x20800802, 16)
		| ROL32(x & 0x04014020, 20)
		| ROL32(x & 0x80100204, 24)
		| ((x & 0x01082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_13(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400401)
		| ((x & 0x00108208) << 4)
		| ROL32(x & 0x04801002, 8)
		| ROL32(x & 0x02004014, 12)
		| ROL32(x & 0x08022080, 16)
		| ROL32(x & 0x41040020, 20)
		| ROL32(x & 0x20010840, 24)
		| ((x & 0x80280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 1, 0), (1, 0, 3, 2), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 1, 14, 7, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_14(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800201)
		| ((x & 0x04024010) << 4)
		| ROL32(x & 0x20200104, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80400402, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x40100808, 24)
		| ((x & 0x01048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_14(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800201)
		| ((x & 0x00104804) << 4)
		| ROL32(x & 0x08401008, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x04028040, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x20010420, 24)
		| ((x & 0x40240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 9, 14, 7, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_15(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400201)
		| ((x & 0x08028010) << 4)
		| ROL32(x & 0x20200108, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40800802, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x80100404, 24)
		| ((x & 0x01084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_15(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400201)
		| ((x & 0x00108408) << 4)
		| ROL32(x & 0x04801004, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x08024080, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x20010820, 24)
		| ((x & 0x80280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 0, 1, 2), (1, 2, 3, 0), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 9, 2, 7, 0, 13, 6, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_16(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400201)
		| ((x & 0x04082010) << 4)
		| ROL32(x & 0x40800104, 8)
		| ROL32(x & 0x08021040, 12)
		| ROL32(x & 0x80200408, 16)
		| ROL32(x & 0x02014080, 20)
		| ROL32(x & 0x20100802, 24)
		| ((x & 0x01048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_16(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400201)
		| ((x & 0x00104802) << 4)
		| ROL32(x & 0x02201008, 8)
		| ROL32(x & 0x08002014, 12)
		| ROL32(x & 0x04088020, 16)
		| ROL32(x & 0x21040080, 20)
		| ROL32(x & 0x80010440, 24)
		| ((x & 0x40820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 0, 1, 2), (2, 3, 0, 1), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_17(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800201)
		| ((x & 0x08042010) << 4)
		| ROL32(x & 0x80400108, 8)
		| ROL32(x & 0x04021080, 12)
		| ROL32(x & 0x40200804, 16)
		| ROL32(x & 0x02018040, 20)
		| ROL32(x & 0x20100402, 24)
		| ((x & 0x01084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_17(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800201)
		| ((x & 0x00108402) << 4)
		| ROL32(x & 0x02201004, 8)
		| ROL32(x & 0x04002018, 12)
		| ROL32(x & 0x08044020, 16)
		| ROL32(x & 0x21080040, 20)
		| ROL32(x & 0x40010880, 24)
		| ((x & 0x80420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 0, 1), (1, 0, 3, 2), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 1, 10, 7, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_18(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200801)
		| ((x & 0x04084010) << 4)
		| ROL32(x & 0x80800104, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20400408, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x40100202, 24)
		| ((x & 0x01042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_18(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200801)
		| ((x & 0x00104204) << 4)
		| ROL32(x & 0x02401002, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x04082040, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x80010480, 24)
		| ((x & 0x40840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 13, 10, 7, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_19(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200401)
		| ((x & 0x08048010) << 4)
		| ROL32(x & 0x40400108, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20800804, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x80100202, 24)
		| ((x & 0x01082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_19(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200401)
		| ((x & 0x00108208) << 4)
		| ROL32(x & 0x02801002, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x08042080, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x40010840, 24)
		| ((x & 0x80480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_20(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x04084010) << 4)
		| ROL32(x & 0x20800104, 8)
		| ROL32(x & 0x08021020, 12)
		| ROL32(x & 0x80400408, 16)
		| ROL32(x & 0x02012080, 20)
		| ROL32(x & 0x40100802, 24)
		| ((x & 0x01048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_20(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x00104804) << 4)
		| ROL32(x & 0x02401008, 8)
		| ROL32(x & 0x08002012, 12)
		| ROL32(x & 0x04088040, 16)
		| ROL32(x & 0x21020080, 20)
		| ROL32(x & 0x80010420, 24)
		| ((x & 0x40840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_21(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x04048010) << 4)
		| ROL32(x & 0x20800108, 8)
		| ROL32(x & 0x08021020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02012080, 20)
		| ROL32(x & 0x80100802, 24)
		| ((x & 0x01084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_21(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x00108404) << 4)
		| ROL32(x & 0x02801008, 8)
		| ROL32(x & 0x08002012, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x21020080, 20)
		| ROL32(x & 0x80010820, 24)
		| ((x & 0x40480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_22(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x08084010) << 4)
		| ROL32(x & 0x20400104, 8)
		| ROL32(x & 0x04021020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02012040, 20)
		| ROL32(x & 0x40100402, 24)
		| ((x & 0x01048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_22(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x00104808) << 4)
		| ROL32(x & 0x02401004, 8)
		| ROL32(x & 0x04002012, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x21020040, 20)
		| ROL32(x & 0x40010420, 24)
		| ((x & 0x80840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_23(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x08048010) << 4)
		| ROL32(x & 0x20400108, 8)
		| ROL32(x & 0x04021020, 12)
		| ROL32(x & 0x40800804, 16)
		| ROL32(x & 0x02012040, 20)
		| ROL32(x & 0x80100402, 24)
		| ((x & 0x01084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_23(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200201)
		| ((x & 0x00108408) << 4)
		| ROL32(x & 0x02801004, 8)
		| ROL32(x & 0x04002012, 12)
		| ROL32(x & 0x08044080, 16)
		| ROL32(x & 0x21020040, 20)
		| ROL32(x & 0x40010820, 24)
		| ((x & 0x80480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_24(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800802)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x80400101, 8)
		| ROL32(x & 0x04081080, 12)
		| ROL32(x & 0x40100204, 16)
		| ROL32(x & 0x08028040, 20)
		| ROL32(x & 0x20200408, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_24(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800802)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x08202004, 8)
		| ROL32(x & 0x04008028, 12)
		| ROL32(x & 0x02044010, 16)
		| ROL32(x & 0x81080040, 20)
		| ROL32(x & 0x40010180, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_25(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800402)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x40400101, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80100204, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x20200808, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_25(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800402)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x08202008, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x02048010, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x40010140, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_26(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400802)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x80800101, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40100208, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x20200404, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_26(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400802)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x04202004, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x02084010, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x80010180, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_27(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400402)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x40800101, 8)
		| ROL32(x & 0x08041040, 12)
		| ROL32(x & 0x80100208, 16)
		| ROL32(x & 0x04024080, 20)
		| ROL32(x & 0x20200804, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_27(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400402)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x04202008, 8)
		| ROL32(x & 0x08004024, 12)
		| ROL32(x & 0x02088010, 16)
		| ROL32(x & 0x41040080, 20)
		| ROL32(x & 0x80010140, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 2, 0, 3), (2, 3, 1, 0), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 13, 10, 7, 8, 5, 2, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_28(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200402)
		| ((x & 0x02048080) << 4)
		| ROL32(x & 0x40400101, 8)
		| ROL32(x & 0x08081020, 12)
		| ROL32(x & 0x20100204, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_28(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200402)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x02042010, 16)
		| ROL32(x & 0x81020080, 20)
		| ROL32(x & 0x40010140, 24)
		| ((x & 0x20480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 2, 0, 3), (3, 0, 2, 1), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 1, 10, 7, 4, 9, 2, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_29(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200802)
		| ((x & 0x02084040) << 4)
		| ROL32(x & 0x80800101, 8)
		| ROL32(x & 0x04041020, 12)
		| ROL32(x & 0x20100208, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_29(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200802)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x02082010, 16)
		| ROL32(x & 0x41020040, 20)
		| ROL32(x & 0x80010180, 24)
		| ((x & 0x20840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 3, 2, 0), (2, 0, 1, 3), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 1, 14, 7, 0, 5, 10, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_30(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800404)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20400101, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80100202, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40200808, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_30(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800404)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x08402008, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x02028010, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x40010120, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (1, 3, 2, 0), (3, 2, 0, 1), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 9, 14, 7, 4, 1, 10, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_31(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400808)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20800101, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40100202, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80200404, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_31(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400808)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x04802004, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x02024010, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x80010120, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 0, 1, 3), (1, 3, 2, 0), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 13, 2, 7, 0, 9, 6, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_32(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800202)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40200101, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80100404, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20400808, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_32(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800202)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x08204008, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x04048010, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x20010140, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 0, 1, 3), (3, 2, 0, 1), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 9, 2, 7, 8, 1, 6, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_33(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400202)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80200101, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40100808, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20800404, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_33(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400202)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x04208004, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x08084010, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x20010180, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 0, 1), (1, 0, 2, 3), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 1, 14, 7, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_34(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800804)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x80200101, 8)
		| ROL32(x & 0x02081080, 12)
		| ROL32(x & 0x20100402, 16)
		| ROL32(x & 0x08048020, 20)
		| ROL32(x & 0x40400208, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_34(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800804)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x08404002, 8)
		| ROL32(x & 0x02008048, 12)
		| ROL32(x & 0x04022010, 16)
		| ROL32(x & 0x81080020, 20)
		| ROL32(x & 0x20010180, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 9, 14, 7, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_35(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400408)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x40200101, 8)
		| ROL32(x & 0x02041040, 12)
		| ROL32(x & 0x20100802, 16)
		| ROL32(x & 0x04084020, 20)
		| ROL32(x & 0x80800204, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_35(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400408)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x04808002, 8)
		| ROL32(x & 0x02004084, 12)
		| ROL32(x & 0x08022010, 16)
		| ROL32(x & 0x41040020, 20)
		| ROL32(x & 0x20010140, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_36(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800204)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x20200101, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80100402, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x40400808, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_36(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800204)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x08404008, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x04028010, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x20010120, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_37(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400204)
		| ((x & 0x04028080) << 4)
		| ROL32(x & 0x20200101, 8)
		| ROL32(x & 0x08081040, 12)
		| ROL32(x & 0x40100402, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_37(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400204)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x04024010, 16)
		| ROL32(x & 0x81040080, 20)
		| ROL32(x & 0x20010120, 24)
		| ((x & 0x40280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_38(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800208)
		| ((x & 0x08024040) << 4)
		| ROL32(x & 0x20200101, 8)
		| ROL32(x & 0x04041080, 12)
		| ROL32(x & 0x80100802, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_38(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800208)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x08028010, 16)
		| ROL32(x & 0x41080040, 20)
		| ROL32(x & 0x20010120, 24)
		| ((x & 0x80240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_39(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400208)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x20200101, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40100802, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x80800404, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_39(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400208)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x04808004, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x08024010, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x20010120, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 0, 2, 1), (1, 2, 0, 3), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 9, 2, 7, 4, 1, 10, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_40(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400804)
		| ((x & 0x04082020) << 4)
		| ROL32(x & 0x80800101, 8)
		| ROL32(x & 0x02021040, 12)
		| ROL32(x & 0x40100408, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_40(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400804)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x04084010, 16)
		| ROL32(x & 0x21040020, 20)
		| ROL32(x & 0x80010180, 24)
		| ((x & 0x40820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 0, 2, 1), (2, 3, 1, 0), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 13, 2, 7, 0, 5, 10, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_41(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800408)
		| ((x & 0x08042020) << 4)
		| ROL32(x & 0x40400101, 8)
		| ROL32(x & 0x02021080, 12)
		| ROL32(x & 0x80100804, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_41(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800408)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x08048010, 16)
		| ROL32(x & 0x21080020, 20)
		| ROL32(x & 0x40010140, 24)
		| ((x & 0x80420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 1, 10, 7, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_42(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200804)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x80800101, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20100408, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x40400202, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_42(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200804)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x02404002, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x04082010, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x80010180, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 13, 10, 7, 4, 9, 2, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_43(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200808)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40800101, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20100404, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80400202, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_43(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200808)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x02804002, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x04042010, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x80010140, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 1, 10, 7, 8, 5, 2, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_44(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200404)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80400101, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20100808, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40800202, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_44(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200404)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x02408002, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x08082010, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x40010180, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 13, 10, 7, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_45(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200408)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x40400101, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20100804, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x80800202, 24)
		| ((x & 0x01012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_45(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200408)
		| ((x & 0x00101201) << 4)
		| ROL32(x & 0x02808002, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x08042010, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x40010140, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 1, 0), (1, 0, 2, 3), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 1, 10, 7, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_46(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200204)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x20800101, 8)
		| ROL32(x & 0x08021020, 12)
		| ROL32(x & 0x80100408, 16)
		| ROL32(x & 0x02042080, 20)
		| ROL32(x & 0x40400802, 24)
		| ((x & 0x01018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_46(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200204)
		| ((x & 0x00101801) << 4)
		| ROL32(x & 0x02404008, 8)
		| ROL32(x & 0x08002042, 12)
		| ROL32(x & 0x04088010, 16)
		| ROL32(x & 0x21020080, 20)
		| ROL32(x & 0x80010120, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 1, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 13, 10, 7, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_47(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200208)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x20400101, 8)
		| ROL32(x & 0x04021020, 12)
		| ROL32(x & 0x40100804, 16)
		| ROL32(x & 0x02082040, 20)
		| ROL32(x & 0x80800402, 24)
		| ((x & 0x01014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_47(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200208)
		| ((x & 0x00101401) << 4)
		| ROL32(x & 0x02808004, 8)
		| ROL32(x & 0x04002082, 12)
		| ROL32(x & 0x08044010, 16)
		| ROL32(x & 0x21020040, 20)
		| ROL32(x & 0x40010120, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 0, 3, 2), (2, 3, 0, 1), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 13, 2, 11, 8, 1, 14, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_48(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02042080) << 4)
		| ROL32(x & 0x80400802, 8)
		| ROL32(x & 0x04081010, 12)
		| ROL32(x & 0x40200204, 16)
		| ROL32(x & 0x01018040, 20)
		| ROL32(x & 0x20800408, 24)
		| ((x & 0x08024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_48(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00802402) << 4)
		| ROL32(x & 0x08208004, 8)
		| ROL32(x & 0x04001018, 12)
		| ROL32(x & 0x02044020, 16)
		| ROL32(x & 0x81010040, 20)
		| ROL32(x & 0x40080280, 24)
		| ((x & 0x20420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 0, 3, 2), (3, 1, 2, 0), (2, 3, 0, 1))
//[8, 13, 6, 3, 12, 5, 2, 11, 0, 9, 14, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_49(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02082040) << 4)
		| ROL32(x & 0x40800402, 8)
		| ROL32(x & 0x08041010, 12)
		| ROL32(x & 0x80200208, 16)
		| ROL32(x & 0x01014080, 20)
		| ROL32(x & 0x20400804, 24)
		| ((x & 0x04028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_49(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00402802) << 4)
		| ROL32(x & 0x04204008, 8)
		| ROL32(x & 0x08001014, 12)
		| ROL32(x & 0x02088020, 16)
		| ROL32(x & 0x41010080, 20)
		| ROL32(x & 0x80040240, 24)
		| ((x & 0x20820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 1, 14, 11, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_50(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02024080) << 4)
		| ROL32(x & 0x80400804, 8)
		| ROL32(x & 0x04081010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01018040, 20)
		| ROL32(x & 0x40800408, 24)
		| ((x & 0x08042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_50(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00804202) << 4)
		| ROL32(x & 0x08408004, 8)
		| ROL32(x & 0x04001018, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x81010040, 20)
		| ROL32(x & 0x40080480, 24)
		| ((x & 0x20240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 5, 14, 11, 8, 13, 2, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_51(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02028080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08081010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01014040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_51(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00404202) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04001014, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x81010080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 1, 14, 11, 12, 9, 2, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_52(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02024040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04041010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01018080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_52(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00808202) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08001018, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x41010040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 5, 14, 11, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_53(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02028040) << 4)
		| ROL32(x & 0x40800408, 8)
		| ROL32(x & 0x08041010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01014080, 20)
		| ROL32(x & 0x80400804, 24)
		| ((x & 0x04082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_53(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00408202) << 4)
		| ROL32(x & 0x04804008, 8)
		| ROL32(x & 0x08001014, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x41010080, 20)
		| ROL32(x & 0x80040840, 24)
		| ((x & 0x20280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 2, 0), (2, 0, 3, 1), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 1, 14, 11, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_54(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20400804, 8)
		| ROL32(x & 0x04081010, 12)
		| ROL32(x & 0x80800202, 16)
		| ROL32(x & 0x01012040, 20)
		| ROL32(x & 0x40200408, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_54(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08402004, 8)
		| ROL32(x & 0x04001012, 12)
		| ROL32(x & 0x02028080, 16)
		| ROL32(x & 0x81010040, 20)
		| ROL32(x & 0x40080420, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 5, 14, 11, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_55(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20800408, 8)
		| ROL32(x & 0x08041010, 12)
		| ROL32(x & 0x40400202, 16)
		| ROL32(x & 0x01012080, 20)
		| ROL32(x & 0x80200804, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_55(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04802008, 8)
		| ROL32(x & 0x08001012, 12)
		| ROL32(x & 0x02024040, 16)
		| ROL32(x & 0x41010080, 20)
		| ROL32(x & 0x80040820, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_56(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04042080) << 4)
		| ROL32(x & 0x80200802, 8)
		| ROL32(x & 0x02081010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01018020, 20)
		| ROL32(x & 0x20800208, 24)
		| ((x & 0x08024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_56(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00802404) << 4)
		| ROL32(x & 0x08208002, 8)
		| ROL32(x & 0x02001018, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x81010020, 20)
		| ROL32(x & 0x20080280, 24)
		| ((x & 0x40420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_57(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40200802, 8)
		| ROL32(x & 0x02081010, 12)
		| ROL32(x & 0x80800404, 16)
		| ROL32(x & 0x01014020, 20)
		| ROL32(x & 0x20400208, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_57(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08204002, 8)
		| ROL32(x & 0x02001014, 12)
		| ROL32(x & 0x04048080, 16)
		| ROL32(x & 0x81010020, 20)
		| ROL32(x & 0x20080240, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_58(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80200402, 8)
		| ROL32(x & 0x02041010, 12)
		| ROL32(x & 0x40400808, 16)
		| ROL32(x & 0x01018020, 20)
		| ROL32(x & 0x20800204, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_58(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04208002, 8)
		| ROL32(x & 0x02001018, 12)
		| ROL32(x & 0x08084040, 16)
		| ROL32(x & 0x41010020, 20)
		| ROL32(x & 0x20040280, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_59(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08082040) << 4)
		| ROL32(x & 0x40200402, 8)
		| ROL32(x & 0x02041010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01014020, 20)
		| ROL32(x & 0x20400204, 24)
		| ((x & 0x04028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_59(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00402808) << 4)
		| ROL32(x & 0x04204002, 8)
		| ROL32(x & 0x02001014, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x41010020, 20)
		| ROL32(x & 0x20040240, 24)
		| ((x & 0x80820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 1, 3, 0), (1, 3, 0, 2), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 13, 6, 11, 8, 1, 14, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_60(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04048080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08081010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01012020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_60(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00202404) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02001012, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x81010080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 1, 3, 0), (3, 0, 2, 1), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 1, 6, 11, 0, 9, 14, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_61(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08084040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04041010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01012020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_61(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00202808) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02001012, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x41010040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 3, 0, 1), (1, 0, 3, 2), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 1, 14, 11, 8, 13, 2, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_62(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04024080) << 4)
		| ROL32(x & 0x80200804, 8)
		| ROL32(x & 0x02081010, 12)
		| ROL32(x & 0x20400402, 16)
		| ROL32(x & 0x01018020, 20)
		| ROL32(x & 0x40800208, 24)
		| ((x & 0x08042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_62(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00804204) << 4)
		| ROL32(x & 0x08408002, 8)
		| ROL32(x & 0x02001018, 12)
		| ROL32(x & 0x04022040, 16)
		| ROL32(x & 0x81010020, 20)
		| ROL32(x & 0x20080480, 24)
		| ((x & 0x40240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (2, 3, 0, 1), (3, 1, 2, 0), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 5, 14, 11, 12, 9, 2, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_63(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08028040) << 4)
		| ROL32(x & 0x40200408, 8)
		| ROL32(x & 0x02041010, 12)
		| ROL32(x & 0x20800802, 16)
		| ROL32(x & 0x01014020, 20)
		| ROL32(x & 0x80400204, 24)
		| ((x & 0x04082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_63(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00408208) << 4)
		| ROL32(x & 0x04804002, 8)
		| ROL32(x & 0x02001014, 12)
		| ROL32(x & 0x08022080, 16)
		| ROL32(x & 0x41010020, 20)
		| ROL32(x & 0x20040840, 24)
		| ((x & 0x80280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 0, 2, 1), (1, 3, 0, 2), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 13, 2, 11, 12, 1, 10, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_64(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04042020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02021010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01018080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_64(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00808404) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08001018, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x21010020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 0, 2, 1), (2, 1, 3, 0), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 5, 2, 11, 0, 13, 10, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_65(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08082020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02021010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01014040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_65(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00404808) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04001014, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x21010020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 13, 6, 11, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_66(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40800208, 8)
		| ROL32(x & 0x08021010, 12)
		| ROL32(x & 0x20200404, 16)
		| ROL32(x & 0x01014080, 20)
		| ROL32(x & 0x80400802, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_66(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02804008, 8)
		| ROL32(x & 0x08001014, 12)
		| ROL32(x & 0x04042020, 16)
		| ROL32(x & 0x21010080, 20)
		| ROL32(x & 0x80020840, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 0, 2), (2, 0, 3, 1), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 1, 6, 11, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_67(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80400204, 8)
		| ROL32(x & 0x04021010, 12)
		| ROL32(x & 0x20200808, 16)
		| ROL32(x & 0x01018040, 20)
		| ROL32(x & 0x40800402, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_67(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02408004, 8)
		| ROL32(x & 0x04001018, 12)
		| ROL32(x & 0x08082020, 16)
		| ROL32(x & 0x21010040, 20)
		| ROL32(x & 0x40020480, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_68(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04084020) << 4)
		| ROL32(x & 0x20800204, 8)
		| ROL32(x & 0x08021010, 12)
		| ROL32(x & 0x80400408, 16)
		| ROL32(x & 0x01012080, 20)
		| ROL32(x & 0x40200802, 24)
		| ((x & 0x02048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_68(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00204804) << 4)
		| ROL32(x & 0x02402008, 8)
		| ROL32(x & 0x08001012, 12)
		| ROL32(x & 0x04088040, 16)
		| ROL32(x & 0x21010080, 20)
		| ROL32(x & 0x80020420, 24)
		| ((x & 0x40840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_69(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x04048020) << 4)
		| ROL32(x & 0x20800208, 8)
		| ROL32(x & 0x08021010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01012080, 20)
		| ROL32(x & 0x80200802, 24)
		| ((x & 0x02084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_69(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00208404) << 4)
		| ROL32(x & 0x02802008, 8)
		| ROL32(x & 0x08001012, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x21010080, 20)
		| ROL32(x & 0x80020820, 24)
		| ((x & 0x40480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_70(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08084020) << 4)
		| ROL32(x & 0x20400204, 8)
		| ROL32(x & 0x04021010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01012040, 20)
		| ROL32(x & 0x40200402, 24)
		| ((x & 0x02048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_70(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00204808) << 4)
		| ROL32(x & 0x02402004, 8)
		| ROL32(x & 0x04001012, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x21010040, 20)
		| ROL32(x & 0x40020420, 24)
		| ((x & 0x80840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 1, 3), (3, 1, 2, 0), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_71(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x08048020) << 4)
		| ROL32(x & 0x20400208, 8)
		| ROL32(x & 0x04021010, 12)
		| ROL32(x & 0x40800804, 16)
		| ROL32(x & 0x01012040, 20)
		| ROL32(x & 0x80200402, 24)
		| ((x & 0x02084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_71(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100101)
		| ((x & 0x00208408) << 4)
		| ROL32(x & 0x02802004, 8)
		| ROL32(x & 0x04001012, 12)
		| ROL32(x & 0x08044080, 16)
		| ROL32(x & 0x21010040, 20)
		| ROL32(x & 0x40020820, 24)
		| ((x & 0x80480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 0, 2, 3), (2, 3, 1, 0), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 13, 2, 11, 0, 5, 10, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_72(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100402)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x40400801, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x80800204, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x20200108, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_72(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100402)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08202001, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x02048080, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x40080140, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 0, 2, 3), (3, 1, 0, 2), (2, 3, 1, 0))
//[8, 13, 6, 3, 12, 5, 2, 11, 4, 1, 10, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_73(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100802)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x80800401, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x40400208, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x20200104, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_73(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100802)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04202001, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x02084040, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x80040180, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 0, 2), (2, 0, 1, 3), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 1, 14, 11, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_74(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x02024080) << 4)
		| ROL32(x & 0x80400801, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40800108, 24)
		| ((x & 0x08012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_74(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x00801202) << 4)
		| ROL32(x & 0x08408001, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x40080180, 24)
		| ((x & 0x20240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 5, 14, 11, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_75(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x02028040) << 4)
		| ROL32(x & 0x40800401, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80400104, 24)
		| ((x & 0x04012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_75(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x00401202) << 4)
		| ROL32(x & 0x04804001, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x80040140, 24)
		| ((x & 0x20280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_76(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20400801, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x80800202, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40200108, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_76(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08402001, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x02028080, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x40080120, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_77(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100804)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20400401, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x40800202, 16)
		| ROL32(x & 0x08042040, 20)
		| ROL32(x & 0x80200108, 24)
		| ((x & 0x04014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_77(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100804)
		| ((x & 0x00401408) << 4)
		| ROL32(x & 0x08802001, 8)
		| ROL32(x & 0x04008042, 12)
		| ROL32(x & 0x02024080, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x40040120, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_78(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100408)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20800801, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x80400202, 16)
		| ROL32(x & 0x04082080, 20)
		| ROL32(x & 0x40200104, 24)
		| ((x & 0x08018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_78(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100408)
		| ((x & 0x00801804) << 4)
		| ROL32(x & 0x04402001, 8)
		| ROL32(x & 0x08004082, 12)
		| ROL32(x & 0x02028040, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x80080120, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_79(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20800401, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x40400202, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80200104, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_79(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04802001, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x02024040, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x80040120, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_80(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x04042080) << 4)
		| ROL32(x & 0x80200801, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20800108, 24)
		| ((x & 0x08014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_80(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x00801404) << 4)
		| ROL32(x & 0x08208001, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x20080180, 24)
		| ((x & 0x40420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_81(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40200801, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x80800404, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20400108, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_81(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08204001, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x04048080, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x20080140, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_82(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80200401, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x40400808, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20800104, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_82(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04208001, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x08084040, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x20040180, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_83(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x08082040) << 4)
		| ROL32(x & 0x40200401, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20400104, 24)
		| ((x & 0x04018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_83(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100202)
		| ((x & 0x00401808) << 4)
		| ROL32(x & 0x04204001, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x20040140, 24)
		| ((x & 0x80820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 1, 0, 3), (1, 3, 2, 0), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 13, 6, 11, 4, 9, 2, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_84(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100802)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40200201, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x20800404, 16)
		| ROL32(x & 0x08024020, 20)
		| ROL32(x & 0x80400108, 24)
		| ((x & 0x02012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_84(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100802)
		| ((x & 0x00201208) << 4)
		| ROL32(x & 0x08804001, 8)
		| ROL32(x & 0x02008024, 12)
		| ROL32(x & 0x04042080, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x20020140, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 1, 0, 3), (3, 0, 1, 2), (1, 3, 2, 0))
//[4, 13, 10, 3, 12, 1, 6, 11, 8, 5, 2, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_85(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100402)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80200201, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x20400808, 16)
		| ROL32(x & 0x04028020, 20)
		| ROL32(x & 0x40800104, 24)
		| ((x & 0x02012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_85(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100402)
		| ((x & 0x00201204) << 4)
		| ROL32(x & 0x04408001, 8)
		| ROL32(x & 0x02004028, 12)
		| ROL32(x & 0x08082040, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x20020180, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 3, 1, 0), (1, 0, 2, 3), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 1, 14, 11, 0, 9, 6, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_86(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100204)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x20200801, 8)
		| ROL32(x & 0x01081010, 12)
		| ROL32(x & 0x80800402, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x40400108, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_86(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100204)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08404001, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x04028080, 16)
		| ROL32(x & 0x81010010, 20)
		| ROL32(x & 0x20080120, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (2, 3, 1, 0), (3, 1, 0, 2), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 5, 14, 11, 8, 1, 6, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_87(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100208)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x20200401, 8)
		| ROL32(x & 0x01041010, 12)
		| ROL32(x & 0x40400802, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x80800104, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_87(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100208)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04808001, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x08024040, 16)
		| ROL32(x & 0x41010010, 20)
		| ROL32(x & 0x20040120, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 0, 1, 2), (1, 3, 2, 0), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 13, 2, 11, 0, 9, 6, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_88(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100208)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40800801, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x80200404, 16)
		| ROL32(x & 0x02084080, 20)
		| ROL32(x & 0x20400102, 24)
		| ((x & 0x08018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_88(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100208)
		| ((x & 0x00801802) << 4)
		| ROL32(x & 0x02204001, 8)
		| ROL32(x & 0x08002084, 12)
		| ROL32(x & 0x04048020, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x80080140, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 0, 1, 2), (2, 1, 0, 3), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 5, 2, 11, 8, 1, 6, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_89(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100204)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80400401, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x40200808, 16)
		| ROL32(x & 0x02048040, 20)
		| ROL32(x & 0x20800102, 24)
		| ((x & 0x04014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_89(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100204)
		| ((x & 0x00401402) << 4)
		| ROL32(x & 0x02208001, 8)
		| ROL32(x & 0x04002048, 12)
		| ROL32(x & 0x08084020, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x40040180, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 14, 3, 12, 1, 6, 11, 4, 9, 2, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_90(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100804)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x80800201, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x20200408, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x40400102, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_90(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100804)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02404001, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x04082020, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x80020180, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 13, 6, 11, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_91(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40800201, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x20200404, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80400102, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_91(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02804001, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x04042020, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x80020140, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 14, 3, 12, 1, 6, 11, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_92(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80400201, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x20200808, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40800102, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_92(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02408001, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x08082020, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x40020180, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 0, 2), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 13, 6, 11, 8, 5, 2, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_93(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100408)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x40400201, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x20200804, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x80800102, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_93(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100408)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02808001, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x08042020, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x40020140, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 13, 6, 11, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_94(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x04048020) << 4)
		| ROL32(x & 0x20800201, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80200102, 24)
		| ((x & 0x02014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_94(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100808)
		| ((x & 0x00201404) << 4)
		| ROL32(x & 0x02802001, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x80020120, 24)
		| ((x & 0x40480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 2, 3, 1), (3, 1, 2, 0), (2, 0, 1, 3), (1, 3, 0, 2))
//[4, 9, 14, 3, 12, 1, 6, 11, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_95(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x08084020) << 4)
		| ROL32(x & 0x20400201, 8)
		| ROL32(x & 0x01021010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40200102, 24)
		| ((x & 0x02018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_95(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10100404)
		| ((x & 0x00201808) << 4)
		| ROL32(x & 0x02402001, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x21010010, 20)
		| ROL32(x & 0x40020120, 24)
		| ((x & 0x80840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 0, 2, 3), (2, 1, 3, 0), (3, 2, 0, 1))
//[12, 9, 6, 3, 8, 5, 2, 15, 0, 13, 10, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_96(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800102)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80100201, 16)
		| ROL32(x & 0x01024040, 20)
		| ROL32(x & 0x20200808, 24)
		| ((x & 0x04048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_96(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800102)
		| ((x & 0x00404801) << 4)
		| ROL32(x & 0x08202008, 8)
		| ROL32(x & 0x04001024, 12)
		| ROL32(x & 0x02018010, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 0, 2, 3), (3, 2, 0, 1), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 9, 2, 15, 12, 1, 10, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_97(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400102)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40100201, 16)
		| ROL32(x & 0x01028080, 20)
		| ROL32(x & 0x20200404, 24)
		| ((x & 0x08084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_97(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400102)
		| ((x & 0x00808401) << 4)
		| ROL32(x & 0x04202004, 8)
		| ROL32(x & 0x08001028, 12)
		| ROL32(x & 0x02014010, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 6, 3, 4, 1, 10, 15, 8, 13, 2, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_98(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x02014080) << 4)
		| ROL32(x & 0x80400804, 8)
		| ROL32(x & 0x04081020, 12)
		| ROL32(x & 0x20100201, 16)
		| ROL32(x & 0x01028040, 20)
		| ROL32(x & 0x40800408, 24)
		| ((x & 0x08042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_98(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x00804201) << 4)
		| ROL32(x & 0x08408004, 8)
		| ROL32(x & 0x04001028, 12)
		| ROL32(x & 0x02012010, 16)
		| ROL32(x & 0x81020040, 20)
		| ROL32(x & 0x40080480, 24)
		| ((x & 0x20140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 5, 10, 15, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_99(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x02018080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08081020, 12)
		| ROL32(x & 0x20100201, 16)
		| ROL32(x & 0x01024040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_99(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x00404201) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04001024, 12)
		| ROL32(x & 0x02012010, 16)
		| ROL32(x & 0x81020080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 1, 10, 15, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_100(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x02014040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04041020, 12)
		| ROL32(x & 0x20100201, 16)
		| ROL32(x & 0x01028080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_100(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x00808201) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08001028, 12)
		| ROL32(x & 0x02012010, 16)
		| ROL32(x & 0x41020040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 0, 3), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 6, 3, 0, 5, 10, 15, 12, 9, 2, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_101(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x02018040) << 4)
		| ROL32(x & 0x40800408, 8)
		| ROL32(x & 0x08041020, 12)
		| ROL32(x & 0x20100201, 16)
		| ROL32(x & 0x01024080, 20)
		| ROL32(x & 0x80400804, 24)
		| ((x & 0x04082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_101(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200102)
		| ((x & 0x00408201) << 4)
		| ROL32(x & 0x04804008, 8)
		| ROL32(x & 0x08001024, 12)
		| ROL32(x & 0x02012010, 16)
		| ROL32(x & 0x41020080, 20)
		| ROL32(x & 0x80040840, 24)
		| ((x & 0x20180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 2, 1))
//[12, 9, 6, 3, 0, 5, 10, 15, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_102(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200104)
		| ((x & 0x02018080) << 4)
		| ROL32(x & 0x20400402, 8)
		| ROL32(x & 0x08081020, 12)
		| ROL32(x & 0x40100201, 16)
		| ROL32(x & 0x01042040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_102(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200104)
		| ((x & 0x00402401) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04001042, 12)
		| ROL32(x & 0x02014010, 16)
		| ROL32(x & 0x81020080, 20)
		| ROL32(x & 0x40040220, 24)
		| ((x & 0x20180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (1, 2, 3, 0), (3, 0, 2, 1), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 1, 10, 15, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_103(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200108)
		| ((x & 0x02014040) << 4)
		| ROL32(x & 0x20800802, 8)
		| ROL32(x & 0x04041020, 12)
		| ROL32(x & 0x80100201, 16)
		| ROL32(x & 0x01082080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_103(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200108)
		| ((x & 0x00802801) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08001082, 12)
		| ROL32(x & 0x02018010, 16)
		| ROL32(x & 0x41020040, 20)
		| ROL32(x & 0x80080220, 24)
		| ((x & 0x20140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 0, 3, 1), (1, 2, 0, 3), (3, 1, 2, 0))
//[12, 5, 10, 3, 4, 9, 2, 15, 8, 1, 14, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_104(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x04012080) << 4)
		| ROL32(x & 0x80200802, 8)
		| ROL32(x & 0x02081040, 12)
		| ROL32(x & 0x40100401, 16)
		| ROL32(x & 0x01048020, 20)
		| ROL32(x & 0x20800208, 24)
		| ((x & 0x08024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_104(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x00802401) << 4)
		| ROL32(x & 0x08208002, 8)
		| ROL32(x & 0x02001048, 12)
		| ROL32(x & 0x04014010, 16)
		| ROL32(x & 0x81040020, 20)
		| ROL32(x & 0x20080280, 24)
		| ((x & 0x40120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 0, 3, 1), (3, 1, 2, 0), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 5, 2, 15, 0, 9, 14, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_105(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x08012040) << 4)
		| ROL32(x & 0x40200402, 8)
		| ROL32(x & 0x02041080, 12)
		| ROL32(x & 0x80100801, 16)
		| ROL32(x & 0x01084020, 20)
		| ROL32(x & 0x20400204, 24)
		| ((x & 0x04028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_105(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x00402801) << 4)
		| ROL32(x & 0x04204002, 8)
		| ROL32(x & 0x02001084, 12)
		| ROL32(x & 0x08018010, 16)
		| ROL32(x & 0x41080020, 20)
		| ROL32(x & 0x20040240, 24)
		| ((x & 0x80120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 9, 6, 15, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_106(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400102)
		| ((x & 0x04018080) << 4)
		| ROL32(x & 0x40200204, 8)
		| ROL32(x & 0x08081040, 12)
		| ROL32(x & 0x20100401, 16)
		| ROL32(x & 0x01024020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_106(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400102)
		| ((x & 0x00204201) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02001024, 12)
		| ROL32(x & 0x04012010, 16)
		| ROL32(x & 0x81040080, 20)
		| ROL32(x & 0x20020440, 24)
		| ((x & 0x40180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 0, 3), (3, 0, 2, 1), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 1, 6, 15, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_107(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800102)
		| ((x & 0x08014040) << 4)
		| ROL32(x & 0x80200208, 8)
		| ROL32(x & 0x04041080, 12)
		| ROL32(x & 0x20100801, 16)
		| ROL32(x & 0x01028020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_107(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800102)
		| ((x & 0x00208201) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02001028, 12)
		| ROL32(x & 0x08012010, 16)
		| ROL32(x & 0x41080040, 20)
		| ROL32(x & 0x20020880, 24)
		| ((x & 0x80140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_108(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800104)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08081080, 12)
		| ROL32(x & 0x80100401, 16)
		| ROL32(x & 0x01042020, 20)
		| ROL32(x & 0x40400808, 24)
		| ((x & 0x02028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_108(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800104)
		| ((x & 0x00202801) << 4)
		| ROL32(x & 0x08404008, 8)
		| ROL32(x & 0x02001042, 12)
		| ROL32(x & 0x04018010, 16)
		| ROL32(x & 0x81080080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_109(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x04018080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08081040, 12)
		| ROL32(x & 0x40100401, 16)
		| ROL32(x & 0x01042020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_109(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x00202401) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02001042, 12)
		| ROL32(x & 0x04014010, 16)
		| ROL32(x & 0x81040080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_110(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x08014040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04041080, 12)
		| ROL32(x & 0x80100801, 16)
		| ROL32(x & 0x01082020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_110(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x00202801) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02001082, 12)
		| ROL32(x & 0x08018010, 16)
		| ROL32(x & 0x41080040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (2, 1, 3, 0), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_111(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400108)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04041040, 12)
		| ROL32(x & 0x40100801, 16)
		| ROL32(x & 0x01082020, 20)
		| ROL32(x & 0x80800404, 24)
		| ((x & 0x02024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_111(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400108)
		| ((x & 0x00202401) << 4)
		| ROL32(x & 0x04808004, 8)
		| ROL32(x & 0x02001082, 12)
		| ROL32(x & 0x08014010, 16)
		| ROL32(x & 0x41040040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_112(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x04012020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02021040, 12)
		| ROL32(x & 0x40100401, 16)
		| ROL32(x & 0x01048080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_112(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x00808401) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08001048, 12)
		| ROL32(x & 0x04014010, 16)
		| ROL32(x & 0x21040020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_113(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400108)
		| ((x & 0x04012020) << 4)
		| ROL32(x & 0x40800804, 8)
		| ROL32(x & 0x02021040, 12)
		| ROL32(x & 0x80100401, 16)
		| ROL32(x & 0x01084080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_113(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400108)
		| ((x & 0x00804801) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08001084, 12)
		| ROL32(x & 0x04018010, 16)
		| ROL32(x & 0x21040020, 20)
		| ROL32(x & 0x80080440, 24)
		| ((x & 0x40120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_114(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800104)
		| ((x & 0x08012020) << 4)
		| ROL32(x & 0x80400408, 8)
		| ROL32(x & 0x02021080, 12)
		| ROL32(x & 0x40100801, 16)
		| ROL32(x & 0x01048040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_114(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800104)
		| ((x & 0x00408401) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04001048, 12)
		| ROL32(x & 0x08014010, 16)
		| ROL32(x & 0x21080020, 20)
		| ROL32(x & 0x40040880, 24)
		| ((x & 0x80120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_115(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x08012020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02021080, 12)
		| ROL32(x & 0x80100801, 16)
		| ROL32(x & 0x01084040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_115(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x00404801) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04001084, 12)
		| ROL32(x & 0x08018010, 16)
		| ROL32(x & 0x21080020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 1, 2, 0), (1, 2, 0, 3), (2, 0, 3, 1))
//[8, 5, 14, 3, 0, 9, 6, 15, 12, 1, 10, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_116(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x04018020) << 4)
		| ROL32(x & 0x20800208, 8)
		| ROL32(x & 0x08021040, 12)
		| ROL32(x & 0x40100401, 16)
		| ROL32(x & 0x01042080, 20)
		| ROL32(x & 0x80200802, 24)
		| ((x & 0x02084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_116(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400104)
		| ((x & 0x00208401) << 4)
		| ROL32(x & 0x02802008, 8)
		| ROL32(x & 0x08001042, 12)
		| ROL32(x & 0x04014010, 16)
		| ROL32(x & 0x21040080, 20)
		| ROL32(x & 0x80020820, 24)
		| ((x & 0x40180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 1, 2, 0), (2, 0, 3, 1), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 1, 6, 15, 0, 13, 10, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_117(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x08014020) << 4)
		| ROL32(x & 0x20400204, 8)
		| ROL32(x & 0x04021080, 12)
		| ROL32(x & 0x80100801, 16)
		| ROL32(x & 0x01082040, 20)
		| ROL32(x & 0x40200402, 24)
		| ((x & 0x02048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_117(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800108)
		| ((x & 0x00204801) << 4)
		| ROL32(x & 0x02402004, 8)
		| ROL32(x & 0x04001082, 12)
		| ROL32(x & 0x08018010, 16)
		| ROL32(x & 0x21080040, 20)
		| ROL32(x & 0x40020420, 24)
		| ((x & 0x80140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 2, 0, 1), (1, 0, 2, 3), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 1, 10, 15, 12, 9, 2, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_118(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200104)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20100401, 16)
		| ROL32(x & 0x01048080, 20)
		| ROL32(x & 0x40400202, 24)
		| ((x & 0x08082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_118(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200104)
		| ((x & 0x00808201) << 4)
		| ROL32(x & 0x02404002, 8)
		| ROL32(x & 0x08001048, 12)
		| ROL32(x & 0x04012010, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 1, 2), (3, 2, 0, 1), (2, 1, 3, 0), (1, 0, 2, 3))
//[4, 9, 14, 3, 0, 5, 10, 15, 8, 13, 2, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_119(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200108)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02021020, 12)
		| ROL32(x & 0x20100801, 16)
		| ROL32(x & 0x01084040, 20)
		| ROL32(x & 0x80800202, 24)
		| ((x & 0x04042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_119(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200108)
		| ((x & 0x00404201) << 4)
		| ROL32(x & 0x02808002, 8)
		| ROL32(x & 0x04001084, 12)
		| ROL32(x & 0x08012010, 16)
		| ROL32(x & 0x21020020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 0, 3, 2), (2, 1, 0, 3), (3, 2, 1, 0))
//[12, 9, 6, 3, 8, 5, 2, 15, 4, 1, 14, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_120(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800804)
		| ((x & 0x02012010) << 4)
		| ROL32(x & 0x80400402, 8)
		| ROL32(x & 0x01081080, 12)
		| ROL32(x & 0x40200201, 16)
		| ROL32(x & 0x08048040, 20)
		| ROL32(x & 0x20100108, 24)
		| ((x & 0x04024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_120(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800804)
		| ((x & 0x00402402) << 4)
		| ROL32(x & 0x08201001, 8)
		| ROL32(x & 0x04008048, 12)
		| ROL32(x & 0x02014020, 16)
		| ROL32(x & 0x81080010, 20)
		| ROL32(x & 0x40040280, 24)
		| ((x & 0x20120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 0, 3, 2), (3, 2, 1, 0), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 9, 2, 15, 0, 5, 14, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_121(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400408)
		| ((x & 0x02012010) << 4)
		| ROL32(x & 0x40800802, 8)
		| ROL32(x & 0x01041040, 12)
		| ROL32(x & 0x80200201, 16)
		| ROL32(x & 0x04084080, 20)
		| ROL32(x & 0x20100104, 24)
		| ((x & 0x08028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_121(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400408)
		| ((x & 0x00802802) << 4)
		| ROL32(x & 0x04201001, 8)
		| ROL32(x & 0x08004084, 12)
		| ROL32(x & 0x02018020, 16)
		| ROL32(x & 0x41040010, 20)
		| ROL32(x & 0x80080240, 24)
		| ((x & 0x20120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 5, 10, 15, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_122(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200802)
		| ((x & 0x02018010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01081020, 12)
		| ROL32(x & 0x20800201, 16)
		| ROL32(x & 0x08024040, 20)
		| ROL32(x & 0x80100108, 24)
		| ((x & 0x04042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_122(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200802)
		| ((x & 0x00404208) << 4)
		| ROL32(x & 0x08801001, 8)
		| ROL32(x & 0x04008024, 12)
		| ROL32(x & 0x02012080, 16)
		| ROL32(x & 0x81020010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 0, 3), (3, 0, 1, 2), (2, 1, 3, 0))
//[8, 13, 6, 3, 4, 1, 10, 15, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_123(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200402)
		| ((x & 0x02014010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01041020, 12)
		| ROL32(x & 0x20400201, 16)
		| ROL32(x & 0x04028080, 20)
		| ROL32(x & 0x40100104, 24)
		| ((x & 0x08082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_123(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200402)
		| ((x & 0x00808204) << 4)
		| ROL32(x & 0x04401001, 8)
		| ROL32(x & 0x08004028, 12)
		| ROL32(x & 0x02012040, 16)
		| ROL32(x & 0x41020010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_124(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200404)
		| ((x & 0x02014010) << 4)
		| ROL32(x & 0x20400802, 8)
		| ROL32(x & 0x01081020, 12)
		| ROL32(x & 0x80800201, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40100108, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_124(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200404)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08401001, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x02018080, 16)
		| ROL32(x & 0x81020010, 20)
		| ROL32(x & 0x40080220, 24)
		| ((x & 0x20140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_125(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200804)
		| ((x & 0x02018010) << 4)
		| ROL32(x & 0x20400402, 8)
		| ROL32(x & 0x01081020, 12)
		| ROL32(x & 0x40800201, 16)
		| ROL32(x & 0x08042040, 20)
		| ROL32(x & 0x80100108, 24)
		| ((x & 0x04024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_125(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200804)
		| ((x & 0x00402408) << 4)
		| ROL32(x & 0x08801001, 8)
		| ROL32(x & 0x04008042, 12)
		| ROL32(x & 0x02014080, 16)
		| ROL32(x & 0x81020010, 20)
		| ROL32(x & 0x40040220, 24)
		| ((x & 0x20180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_126(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200408)
		| ((x & 0x02014010) << 4)
		| ROL32(x & 0x20800802, 8)
		| ROL32(x & 0x01041020, 12)
		| ROL32(x & 0x80400201, 16)
		| ROL32(x & 0x04082080, 20)
		| ROL32(x & 0x40100104, 24)
		| ((x & 0x08028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_126(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200408)
		| ((x & 0x00802804) << 4)
		| ROL32(x & 0x04401001, 8)
		| ROL32(x & 0x08004082, 12)
		| ROL32(x & 0x02018040, 16)
		| ROL32(x & 0x41020010, 20)
		| ROL32(x & 0x80080220, 24)
		| ((x & 0x20140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (1, 2, 3, 0), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_127(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200808)
		| ((x & 0x02018010) << 4)
		| ROL32(x & 0x20800402, 8)
		| ROL32(x & 0x01041020, 12)
		| ROL32(x & 0x40400201, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80100104, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_127(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200808)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04801001, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x02014040, 16)
		| ROL32(x & 0x41020010, 20)
		| ROL32(x & 0x80040220, 24)
		| ((x & 0x20180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 0, 1, 3), (1, 2, 3, 0), (3, 1, 0, 2))
//[12, 5, 10, 3, 4, 9, 2, 15, 0, 13, 6, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_128(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400202)
		| ((x & 0x04012010) << 4)
		| ROL32(x & 0x40200804, 8)
		| ROL32(x & 0x01081040, 12)
		| ROL32(x & 0x80800401, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20100108, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_128(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400202)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08201001, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x04018080, 16)
		| ROL32(x & 0x81040010, 20)
		| ROL32(x & 0x20080440, 24)
		| ((x & 0x40120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 0, 1, 3), (3, 1, 0, 2), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 5, 2, 15, 12, 1, 6, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_129(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800202)
		| ((x & 0x08012010) << 4)
		| ROL32(x & 0x80200408, 8)
		| ROL32(x & 0x01041080, 12)
		| ROL32(x & 0x40400801, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20100104, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_129(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800202)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04201001, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x08014040, 16)
		| ROL32(x & 0x41080010, 20)
		| ROL32(x & 0x20040880, 24)
		| ((x & 0x80120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 10, 3, 8, 1, 6, 15, 4, 13, 2, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_130(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800802)
		| ((x & 0x04014010) << 4)
		| ROL32(x & 0x80200204, 8)
		| ROL32(x & 0x01081080, 12)
		| ROL32(x & 0x20400401, 16)
		| ROL32(x & 0x08028020, 20)
		| ROL32(x & 0x40100108, 24)
		| ((x & 0x02042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_130(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800802)
		| ((x & 0x00204204) << 4)
		| ROL32(x & 0x08401001, 8)
		| ROL32(x & 0x02008028, 12)
		| ROL32(x & 0x04012040, 16)
		| ROL32(x & 0x81080010, 20)
		| ROL32(x & 0x20020480, 24)
		| ((x & 0x40140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 9, 6, 15, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_131(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400802)
		| ((x & 0x04018010) << 4)
		| ROL32(x & 0x40200204, 8)
		| ROL32(x & 0x01081040, 12)
		| ROL32(x & 0x20800401, 16)
		| ROL32(x & 0x08024020, 20)
		| ROL32(x & 0x80100108, 24)
		| ((x & 0x02042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_131(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400802)
		| ((x & 0x00204208) << 4)
		| ROL32(x & 0x08801001, 8)
		| ROL32(x & 0x02008024, 12)
		| ROL32(x & 0x04012080, 16)
		| ROL32(x & 0x81040010, 20)
		| ROL32(x & 0x20020440, 24)
		| ((x & 0x40180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 10, 3, 8, 1, 6, 15, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_132(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800402)
		| ((x & 0x08014010) << 4)
		| ROL32(x & 0x80200208, 8)
		| ROL32(x & 0x01041080, 12)
		| ROL32(x & 0x20400801, 16)
		| ROL32(x & 0x04028020, 20)
		| ROL32(x & 0x40100104, 24)
		| ((x & 0x02082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_132(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800402)
		| ((x & 0x00208204) << 4)
		| ROL32(x & 0x04401001, 8)
		| ROL32(x & 0x02004028, 12)
		| ROL32(x & 0x08012040, 16)
		| ROL32(x & 0x41080010, 20)
		| ROL32(x & 0x20020880, 24)
		| ((x & 0x80140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 0, 3), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 10, 3, 0, 9, 6, 15, 12, 5, 2, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_133(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400402)
		| ((x & 0x08018010) << 4)
		| ROL32(x & 0x40200208, 8)
		| ROL32(x & 0x01041040, 12)
		| ROL32(x & 0x20800801, 16)
		| ROL32(x & 0x04024020, 20)
		| ROL32(x & 0x80100104, 24)
		| ((x & 0x02082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_133(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400402)
		| ((x & 0x00208208) << 4)
		| ROL32(x & 0x04801001, 8)
		| ROL32(x & 0x02004024, 12)
		| ROL32(x & 0x08012080, 16)
		| ROL32(x & 0x41040010, 20)
		| ROL32(x & 0x20020840, 24)
		| ((x & 0x80180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 1, 2))
//[12, 5, 10, 3, 0, 9, 6, 15, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_134(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400804)
		| ((x & 0x04018010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01081040, 12)
		| ROL32(x & 0x40800401, 16)
		| ROL32(x & 0x08042020, 20)
		| ROL32(x & 0x80100108, 24)
		| ((x & 0x02024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_134(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400804)
		| ((x & 0x00202408) << 4)
		| ROL32(x & 0x08801001, 8)
		| ROL32(x & 0x02008042, 12)
		| ROL32(x & 0x04014080, 16)
		| ROL32(x & 0x81040010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (2, 1, 3, 0), (3, 0, 1, 2), (1, 2, 0, 3))
//[4, 13, 10, 3, 8, 1, 6, 15, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_135(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800408)
		| ((x & 0x08014010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01041080, 12)
		| ROL32(x & 0x80400801, 16)
		| ROL32(x & 0x04082020, 20)
		| ROL32(x & 0x40100104, 24)
		| ((x & 0x02028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_135(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800408)
		| ((x & 0x00202804) << 4)
		| ROL32(x & 0x04401001, 8)
		| ROL32(x & 0x02004082, 12)
		| ROL32(x & 0x08018040, 16)
		| ROL32(x & 0x41080010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_136(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400204)
		| ((x & 0x04012010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01021040, 12)
		| ROL32(x & 0x40200401, 16)
		| ROL32(x & 0x02048080, 20)
		| ROL32(x & 0x20100102, 24)
		| ((x & 0x08084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_136(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400204)
		| ((x & 0x00808402) << 4)
		| ROL32(x & 0x02201001, 8)
		| ROL32(x & 0x08002048, 12)
		| ROL32(x & 0x04014020, 16)
		| ROL32(x & 0x21040010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_137(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400208)
		| ((x & 0x04012010) << 4)
		| ROL32(x & 0x40800804, 8)
		| ROL32(x & 0x01021040, 12)
		| ROL32(x & 0x80200401, 16)
		| ROL32(x & 0x02084080, 20)
		| ROL32(x & 0x20100102, 24)
		| ((x & 0x08048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_137(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400208)
		| ((x & 0x00804802) << 4)
		| ROL32(x & 0x02201001, 8)
		| ROL32(x & 0x08002084, 12)
		| ROL32(x & 0x04018020, 16)
		| ROL32(x & 0x21040010, 20)
		| ROL32(x & 0x80080440, 24)
		| ((x & 0x40120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_138(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800204)
		| ((x & 0x08012010) << 4)
		| ROL32(x & 0x80400408, 8)
		| ROL32(x & 0x01021080, 12)
		| ROL32(x & 0x40200801, 16)
		| ROL32(x & 0x02048040, 20)
		| ROL32(x & 0x20100102, 24)
		| ((x & 0x04084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_138(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800204)
		| ((x & 0x00408402) << 4)
		| ROL32(x & 0x02201001, 8)
		| ROL32(x & 0x04002048, 12)
		| ROL32(x & 0x08014020, 16)
		| ROL32(x & 0x21080010, 20)
		| ROL32(x & 0x40040880, 24)
		| ((x & 0x80120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_139(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800208)
		| ((x & 0x08012010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01021080, 12)
		| ROL32(x & 0x80200801, 16)
		| ROL32(x & 0x02084040, 20)
		| ROL32(x & 0x20100102, 24)
		| ((x & 0x04048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_139(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800208)
		| ((x & 0x00404802) << 4)
		| ROL32(x & 0x02201001, 8)
		| ROL32(x & 0x04002084, 12)
		| ROL32(x & 0x08018020, 16)
		| ROL32(x & 0x21080010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 1, 0, 2), (1, 2, 3, 0), (2, 0, 1, 3))
//[8, 5, 14, 3, 0, 9, 6, 15, 4, 13, 2, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_140(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400808)
		| ((x & 0x04018010) << 4)
		| ROL32(x & 0x40800204, 8)
		| ROL32(x & 0x01021040, 12)
		| ROL32(x & 0x20200401, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80100102, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_140(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10400808)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02801001, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x04012020, 16)
		| ROL32(x & 0x21040010, 20)
		| ROL32(x & 0x80020440, 24)
		| ((x & 0x40180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 1, 0, 2), (2, 0, 1, 3), (1, 2, 3, 0))
//[4, 9, 14, 3, 8, 1, 6, 15, 12, 5, 2, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_141(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800404)
		| ((x & 0x08014010) << 4)
		| ROL32(x & 0x80400208, 8)
		| ROL32(x & 0x01021080, 12)
		| ROL32(x & 0x20200801, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40100102, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_141(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10800404)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02401001, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x08012020, 16)
		| ROL32(x & 0x21080010, 20)
		| ROL32(x & 0x40020880, 24)
		| ((x & 0x80140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 2, 1, 0), (1, 0, 3, 2), (2, 1, 0, 3))
//[8, 5, 14, 3, 4, 1, 10, 15, 0, 13, 6, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_142(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200208)
		| ((x & 0x04014010) << 4)
		| ROL32(x & 0x20800804, 8)
		| ROL32(x & 0x01021020, 12)
		| ROL32(x & 0x80400401, 16)
		| ROL32(x & 0x02082080, 20)
		| ROL32(x & 0x40100102, 24)
		| ((x & 0x08048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_142(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200208)
		| ((x & 0x00804804) << 4)
		| ROL32(x & 0x02401001, 8)
		| ROL32(x & 0x08002082, 12)
		| ROL32(x & 0x04018040, 16)
		| ROL32(x & 0x21020010, 20)
		| ROL32(x & 0x80080420, 24)
		| ((x & 0x40140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((0, 3, 2, 1), (3, 2, 1, 0), (2, 1, 0, 3), (1, 0, 3, 2))
//[4, 9, 14, 3, 0, 5, 10, 15, 12, 1, 6, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_143(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200204)
		| ((x & 0x08018010) << 4)
		| ROL32(x & 0x20400408, 8)
		| ROL32(x & 0x01021020, 12)
		| ROL32(x & 0x40800801, 16)
		| ROL32(x & 0x02042040, 20)
		| ROL32(x & 0x80100102, 24)
		| ((x & 0x04084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_143(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x10200204)
		| ((x & 0x00408408) << 4)
		| ROL32(x & 0x02801001, 8)
		| ROL32(x & 0x04002042, 12)
		| ROL32(x & 0x08014080, 16)
		| ROL32(x & 0x21020010, 20)
		| ROL32(x & 0x40040820, 24)
		| ((x & 0x80180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_144(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800801)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x80400202, 8)
		| ROL32(x & 0x04082080, 12)
		| ROL32(x & 0x40200104, 16)
		| ROL32(x & 0x08018040, 20)
		| ROL32(x & 0x10100408, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_144(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800801)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x08101004, 8)
		| ROL32(x & 0x04008018, 12)
		| ROL32(x & 0x01044020, 16)
		| ROL32(x & 0x82080040, 20)
		| ROL32(x & 0x40020280, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_145(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800401)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x40400202, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80200104, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x10100808, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_145(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800401)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x08101008, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x01048020, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x40020240, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 14, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_146(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400801)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x80800202, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40200108, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x10100404, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_146(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400801)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x04101004, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x01084020, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x80020280, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 14, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_147(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400401)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x40800202, 8)
		| ROL32(x & 0x08042040, 12)
		| ROL32(x & 0x80200108, 16)
		| ROL32(x & 0x04014080, 20)
		| ROL32(x & 0x10100804, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_147(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400401)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x04101008, 8)
		| ROL32(x & 0x08004014, 12)
		| ROL32(x & 0x01088020, 16)
		| ROL32(x & 0x42040080, 20)
		| ROL32(x & 0x80020240, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 2, 3, 1), (2, 3, 1, 0), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 13, 10, 3, 0, 5, 14, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_148(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200401)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x40400802, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x80800104, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x10100208, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_148(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200401)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08101002, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x01048080, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x40080240, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 2, 3, 1), (3, 1, 0, 2), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 5, 10, 3, 4, 1, 14, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_149(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200801)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x80800402, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x40400108, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x10100204, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_149(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200801)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04101002, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x01084040, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x80040280, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 3, 1, 2), (2, 1, 3, 0), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 5, 14, 3, 0, 13, 6, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_150(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800201)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80200102, 16)
		| ROL32(x & 0x02014040, 20)
		| ROL32(x & 0x10100808, 24)
		| ((x & 0x04048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_150(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800201)
		| ((x & 0x00404802) << 4)
		| ROL32(x & 0x08101008, 8)
		| ROL32(x & 0x04002014, 12)
		| ROL32(x & 0x01028020, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (0, 3, 1, 2), (3, 2, 0, 1), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 9, 14, 3, 12, 1, 6, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_151(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400201)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40200102, 16)
		| ROL32(x & 0x02018080, 20)
		| ROL32(x & 0x10100404, 24)
		| ((x & 0x08084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_151(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400201)
		| ((x & 0x00808402) << 4)
		| ROL32(x & 0x04101004, 8)
		| ROL32(x & 0x08002018, 12)
		| ROL32(x & 0x01024020, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 1, 3, 0), (0, 3, 1, 2), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 13, 6, 3, 0, 5, 14, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_152(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800401)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80400104, 16)
		| ROL32(x & 0x04012020, 20)
		| ROL32(x & 0x10100808, 24)
		| ((x & 0x02028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_152(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800401)
		| ((x & 0x00202804) << 4)
		| ROL32(x & 0x08101008, 8)
		| ROL32(x & 0x02004012, 12)
		| ROL32(x & 0x01048040, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 1, 3, 0), (3, 2, 0, 1), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 9, 6, 3, 4, 1, 14, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_153(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400801)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40800108, 16)
		| ROL32(x & 0x08012020, 20)
		| ROL32(x & 0x10100404, 24)
		| ((x & 0x02024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_153(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400801)
		| ((x & 0x00202408) << 4)
		| ROL32(x & 0x04101004, 8)
		| ROL32(x & 0x02008012, 12)
		| ROL32(x & 0x01084080, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 0, 1), (0, 1, 3, 2), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 5, 14, 3, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_154(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800801)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x80200404, 8)
		| ROL32(x & 0x02084080, 12)
		| ROL32(x & 0x20400102, 16)
		| ROL32(x & 0x08018020, 20)
		| ROL32(x & 0x10100208, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_154(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800801)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x08101002, 8)
		| ROL32(x & 0x02008018, 12)
		| ROL32(x & 0x01022040, 16)
		| ROL32(x & 0x84080020, 20)
		| ROL32(x & 0x20040480, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 9, 14, 3, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_155(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400401)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x40200808, 8)
		| ROL32(x & 0x02048040, 12)
		| ROL32(x & 0x20800102, 16)
		| ROL32(x & 0x04014020, 20)
		| ROL32(x & 0x10100204, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_155(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400401)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x04101002, 8)
		| ROL32(x & 0x02004014, 12)
		| ROL32(x & 0x01022080, 16)
		| ROL32(x & 0x48040020, 20)
		| ROL32(x & 0x20080840, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 5, 14, 3, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_156(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800201)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x20200404, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80400102, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x10100808, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_156(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800201)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x08101008, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x01028040, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x20040420, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 9, 14, 3, 0, 13, 6, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_157(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400201)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x20200804, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x80800102, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x10100408, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_157(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400201)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08101004, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x01028080, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x20080420, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 5, 14, 3, 12, 1, 6, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_158(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800201)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x20200408, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x40400102, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x10100804, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_158(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800201)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04101008, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x01024040, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x20040820, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 9, 14, 3, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_159(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400201)
		| ((x & 0x01021010) << 4)
		| ROL32(x & 0x20200808, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40800102, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x10100404, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_159(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400201)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x04101004, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x01024080, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x20080820, 24)
		| ((x & 0x10210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 1, 0, 2), (0, 2, 3, 1), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 9, 6, 3, 4, 13, 2, 11, 0, 5, 10, 15]
void BOGI32_omega_diffusion_160(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400801)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x80800204, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x20200108, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x10100402, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_160(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400801)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02101004, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x01082020, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x80020480, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 1, 0, 2), (2, 3, 1, 0), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 13, 6, 3, 12, 5, 2, 11, 4, 1, 10, 15]
void BOGI32_omega_diffusion_161(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800401)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x40400208, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x20200104, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x10100802, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_161(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800401)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02101008, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x01042020, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x40020840, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_162(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200801)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x80800404, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20400108, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x10100202, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_162(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200801)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x02101002, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x01082040, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x80040480, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 6, 15]
void BOGI32_omega_diffusion_163(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200401)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20400104, 16)
		| ROL32(x & 0x04018080, 20)
		| ROL32(x & 0x10100202, 24)
		| ((x & 0x08082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_163(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200401)
		| ((x & 0x00808204) << 4)
		| ROL32(x & 0x02101002, 8)
		| ROL32(x & 0x08004018, 12)
		| ROL32(x & 0x01042040, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_164(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200801)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20800108, 16)
		| ROL32(x & 0x08014040, 20)
		| ROL32(x & 0x10100202, 24)
		| ((x & 0x04042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_164(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200801)
		| ((x & 0x00404208) << 4)
		| ROL32(x & 0x02101002, 8)
		| ROL32(x & 0x04008014, 12)
		| ROL32(x & 0x01082080, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 6, 15]
void BOGI32_omega_diffusion_165(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200401)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x40400808, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20800104, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x10100202, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_165(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200401)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x02101002, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x01042080, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x40080840, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 1, 0), (0, 1, 3, 2), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 5, 10, 3, 0, 13, 6, 11, 4, 9, 2, 15]
void BOGI32_omega_diffusion_166(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200201)
		| ((x & 0x01081010) << 4)
		| ROL32(x & 0x20800404, 8)
		| ROL32(x & 0x08024020, 12)
		| ROL32(x & 0x80400108, 16)
		| ROL32(x & 0x02012080, 20)
		| ROL32(x & 0x10100802, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_166(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200201)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x02101008, 8)
		| ROL32(x & 0x08002012, 12)
		| ROL32(x & 0x01088040, 16)
		| ROL32(x & 0x24020080, 20)
		| ROL32(x & 0x80040420, 24)
		| ((x & 0x10810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 13, 10, 3, 12, 1, 6, 11, 8, 5, 2, 15]
void BOGI32_omega_diffusion_167(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200201)
		| ((x & 0x01041010) << 4)
		| ROL32(x & 0x20400808, 8)
		| ROL32(x & 0x04028020, 12)
		| ROL32(x & 0x40800104, 16)
		| ROL32(x & 0x02012040, 20)
		| ROL32(x & 0x10100402, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_167(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200201)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x02101004, 8)
		| ROL32(x & 0x04002012, 12)
		| ROL32(x & 0x01044080, 16)
		| ROL32(x & 0x28020040, 20)
		| ROL32(x & 0x40080820, 24)
		| ((x & 0x10410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 0, 1), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_168(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x01041020) << 4)
		| ROL32(x & 0x80400201, 8)
		| ROL32(x & 0x04082080, 12)
		| ROL32(x & 0x40100104, 16)
		| ROL32(x & 0x08028040, 20)
		| ROL32(x & 0x10200408, 24)
		| ((x & 0x02014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_168(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x00201401) << 4)
		| ROL32(x & 0x08102004, 8)
		| ROL32(x & 0x04008028, 12)
		| ROL32(x & 0x01044010, 16)
		| ROL32(x & 0x82080040, 20)
		| ROL32(x & 0x40020180, 24)
		| ((x & 0x10410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 1, 0), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_169(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800402)
		| ((x & 0x01041020) << 4)
		| ROL32(x & 0x40400201, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80100104, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x10200808, 24)
		| ((x & 0x02018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_169(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800402)
		| ((x & 0x00201801) << 4)
		| ROL32(x & 0x08102008, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x01048010, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x40020140, 24)
		| ((x & 0x10410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 0, 1), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 10, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_170(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400802)
		| ((x & 0x01081020) << 4)
		| ROL32(x & 0x80800201, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40100108, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x10200404, 24)
		| ((x & 0x02014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_170(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400802)
		| ((x & 0x00201401) << 4)
		| ROL32(x & 0x04102004, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x01084010, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x80020180, 24)
		| ((x & 0x10810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 1, 0), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 10, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_171(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x01081020) << 4)
		| ROL32(x & 0x40800201, 8)
		| ROL32(x & 0x08042040, 12)
		| ROL32(x & 0x80100108, 16)
		| ROL32(x & 0x04024080, 20)
		| ROL32(x & 0x10200804, 24)
		| ((x & 0x02018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_171(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x00201801) << 4)
		| ROL32(x & 0x04102008, 8)
		| ROL32(x & 0x08004024, 12)
		| ROL32(x & 0x01088010, 16)
		| ROL32(x & 0x42040080, 20)
		| ROL32(x & 0x80020140, 24)
		| ((x & 0x10810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 2, 1, 3), (2, 3, 0, 1), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 13, 10, 3, 8, 1, 6, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_172(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01041080) << 4)
		| ROL32(x & 0x80400801, 8)
		| ROL32(x & 0x04082020, 12)
		| ROL32(x & 0x40100104, 16)
		| ROL32(x & 0x02028040, 20)
		| ROL32(x & 0x10800408, 24)
		| ((x & 0x08014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_172(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00801401) << 4)
		| ROL32(x & 0x08108004, 8)
		| ROL32(x & 0x04002028, 12)
		| ROL32(x & 0x01044010, 16)
		| ROL32(x & 0x82020040, 20)
		| ROL32(x & 0x40080180, 24)
		| ((x & 0x10410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 2, 1, 3), (3, 1, 2, 0), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 5, 10, 3, 0, 9, 6, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_173(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01081040) << 4)
		| ROL32(x & 0x40800401, 8)
		| ROL32(x & 0x08042020, 12)
		| ROL32(x & 0x80100108, 16)
		| ROL32(x & 0x02024080, 20)
		| ROL32(x & 0x10400804, 24)
		| ((x & 0x04018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_173(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00401801) << 4)
		| ROL32(x & 0x04104008, 8)
		| ROL32(x & 0x08002024, 12)
		| ROL32(x & 0x01088010, 16)
		| ROL32(x & 0x42020080, 20)
		| ROL32(x & 0x80040140, 24)
		| ((x & 0x10810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 3, 2, 1), (2, 1, 0, 3), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 5, 14, 3, 4, 1, 10, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_174(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800804)
		| ((x & 0x01021020) << 4)
		| ROL32(x & 0x80400401, 8)
		| ROL32(x & 0x02082080, 12)
		| ROL32(x & 0x40100102, 16)
		| ROL32(x & 0x08048040, 20)
		| ROL32(x & 0x10200208, 24)
		| ((x & 0x04014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_174(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800804)
		| ((x & 0x00401401) << 4)
		| ROL32(x & 0x08102002, 8)
		| ROL32(x & 0x04008048, 12)
		| ROL32(x & 0x01024010, 16)
		| ROL32(x & 0x82080020, 20)
		| ROL32(x & 0x40040180, 24)
		| ((x & 0x10210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (0, 3, 2, 1), (3, 2, 1, 0), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 9, 14, 3, 0, 5, 10, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_175(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400408)
		| ((x & 0x01021020) << 4)
		| ROL32(x & 0x40800801, 8)
		| ROL32(x & 0x02042040, 12)
		| ROL32(x & 0x80100102, 16)
		| ROL32(x & 0x04084080, 20)
		| ROL32(x & 0x10200204, 24)
		| ((x & 0x08018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_175(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400408)
		| ((x & 0x00801801) << 4)
		| ROL32(x & 0x04102002, 8)
		| ROL32(x & 0x08004084, 12)
		| ROL32(x & 0x01028010, 16)
		| ROL32(x & 0x42040020, 20)
		| ROL32(x & 0x80080140, 24)
		| ((x & 0x10210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 1, 0, 3), (0, 3, 2, 1), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 13, 6, 3, 4, 9, 2, 15, 0, 5, 14, 11]
void BOGI32_omega_diffusion_176(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800802)
		| ((x & 0x01041040) << 4)
		| ROL32(x & 0x80200201, 8)
		| ROL32(x & 0x04084080, 12)
		| ROL32(x & 0x20100104, 16)
		| ROL32(x & 0x08028020, 20)
		| ROL32(x & 0x10400408, 24)
		| ((x & 0x02012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_176(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800802)
		| ((x & 0x00201201) << 4)
		| ROL32(x & 0x08104004, 8)
		| ROL32(x & 0x02008028, 12)
		| ROL32(x & 0x01042010, 16)
		| ROL32(x & 0x84080040, 20)
		| ROL32(x & 0x20020180, 24)
		| ((x & 0x10410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 1, 0, 3), (3, 2, 1, 0), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 9, 6, 3, 8, 5, 2, 15, 4, 1, 14, 11]
void BOGI32_omega_diffusion_177(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400402)
		| ((x & 0x01081080) << 4)
		| ROL32(x & 0x40200201, 8)
		| ROL32(x & 0x08048040, 12)
		| ROL32(x & 0x20100108, 16)
		| ROL32(x & 0x04024020, 20)
		| ROL32(x & 0x10800804, 24)
		| ((x & 0x02012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_177(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400402)
		| ((x & 0x00201201) << 4)
		| ROL32(x & 0x04108008, 8)
		| ROL32(x & 0x02004024, 12)
		| ROL32(x & 0x01082010, 16)
		| ROL32(x & 0x48040080, 20)
		| ROL32(x & 0x20020140, 24)
		| ((x & 0x10810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_178(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x01021040) << 4)
		| ROL32(x & 0x80200401, 8)
		| ROL32(x & 0x02084080, 12)
		| ROL32(x & 0x20100102, 16)
		| ROL32(x & 0x08048020, 20)
		| ROL32(x & 0x10400208, 24)
		| ((x & 0x04012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_178(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x00401201) << 4)
		| ROL32(x & 0x08104002, 8)
		| ROL32(x & 0x02008048, 12)
		| ROL32(x & 0x01022010, 16)
		| ROL32(x & 0x84080020, 20)
		| ROL32(x & 0x20040180, 24)
		| ((x & 0x10210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_179(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01021080) << 4)
		| ROL32(x & 0x80200801, 8)
		| ROL32(x & 0x02084040, 12)
		| ROL32(x & 0x20100102, 16)
		| ROL32(x & 0x04048020, 20)
		| ROL32(x & 0x10800208, 24)
		| ((x & 0x08012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_179(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00801201) << 4)
		| ROL32(x & 0x08108002, 8)
		| ROL32(x & 0x02004048, 12)
		| ROL32(x & 0x01022010, 16)
		| ROL32(x & 0x84040020, 20)
		| ROL32(x & 0x20080180, 24)
		| ((x & 0x10210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_180(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01021040) << 4)
		| ROL32(x & 0x40200401, 8)
		| ROL32(x & 0x02048080, 12)
		| ROL32(x & 0x20100102, 16)
		| ROL32(x & 0x08084020, 20)
		| ROL32(x & 0x10400204, 24)
		| ((x & 0x04012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_180(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00401201) << 4)
		| ROL32(x & 0x04104002, 8)
		| ROL32(x & 0x02008084, 12)
		| ROL32(x & 0x01022010, 16)
		| ROL32(x & 0x48080020, 20)
		| ROL32(x & 0x20040140, 24)
		| ((x & 0x10210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_181(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x01021080) << 4)
		| ROL32(x & 0x40200801, 8)
		| ROL32(x & 0x02048040, 12)
		| ROL32(x & 0x20100102, 16)
		| ROL32(x & 0x04084020, 20)
		| ROL32(x & 0x10800204, 24)
		| ((x & 0x08012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_181(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x00801201) << 4)
		| ROL32(x & 0x04108002, 8)
		| ROL32(x & 0x02004084, 12)
		| ROL32(x & 0x01022010, 16)
		| ROL32(x & 0x48040020, 20)
		| ROL32(x & 0x20080140, 24)
		| ((x & 0x10210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 1, 0), (0, 1, 2, 3), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 5, 14, 3, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_182(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800204)
		| ((x & 0x01021040) << 4)
		| ROL32(x & 0x20200401, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80100102, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x10400808, 24)
		| ((x & 0x04018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_182(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800204)
		| ((x & 0x00401801) << 4)
		| ROL32(x & 0x08104008, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x01028010, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x20040120, 24)
		| ((x & 0x10210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 9, 14, 3, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_183(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400208)
		| ((x & 0x01021080) << 4)
		| ROL32(x & 0x20200801, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40100102, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x10800404, 24)
		| ((x & 0x08014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_183(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400208)
		| ((x & 0x00801401) << 4)
		| ROL32(x & 0x04108004, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x01024010, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x20080120, 24)
		| ((x & 0x10210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 1, 2, 0), (0, 2, 1, 3), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 9, 6, 3, 0, 5, 10, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_184(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01081020) << 4)
		| ROL32(x & 0x20800201, 8)
		| ROL32(x & 0x08024040, 12)
		| ROL32(x & 0x80100108, 16)
		| ROL32(x & 0x04042080, 20)
		| ROL32(x & 0x10200802, 24)
		| ((x & 0x02018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_184(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00201801) << 4)
		| ROL32(x & 0x02102008, 8)
		| ROL32(x & 0x08004042, 12)
		| ROL32(x & 0x01088010, 16)
		| ROL32(x & 0x24040080, 20)
		| ROL32(x & 0x80020120, 24)
		| ((x & 0x10810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 1, 2, 0), (2, 3, 0, 1), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 13, 6, 3, 4, 1, 10, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_185(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01041020) << 4)
		| ROL32(x & 0x20400201, 8)
		| ROL32(x & 0x04028080, 12)
		| ROL32(x & 0x40100104, 16)
		| ROL32(x & 0x08082040, 20)
		| ROL32(x & 0x10200402, 24)
		| ((x & 0x02014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_185(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00201401) << 4)
		| ROL32(x & 0x02102004, 8)
		| ROL32(x & 0x04008082, 12)
		| ROL32(x & 0x01044010, 16)
		| ROL32(x & 0x28080040, 20)
		| ROL32(x & 0x40020120, 24)
		| ((x & 0x10410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 0, 1), (0, 1, 2, 3), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 5, 10, 3, 4, 9, 2, 15, 0, 13, 6, 11]
void BOGI32_omega_diffusion_186(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200804)
		| ((x & 0x01081040) << 4)
		| ROL32(x & 0x80800401, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20100108, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x10400202, 24)
		| ((x & 0x04012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_186(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200804)
		| ((x & 0x00401201) << 4)
		| ROL32(x & 0x02104002, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x01082010, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x80040180, 24)
		| ((x & 0x10810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 13, 10, 3, 8, 5, 2, 15, 12, 1, 6, 11]
void BOGI32_omega_diffusion_187(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200408)
		| ((x & 0x01041080) << 4)
		| ROL32(x & 0x40400801, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20100104, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x10800202, 24)
		| ((x & 0x08012010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_187(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200408)
		| ((x & 0x00801201) << 4)
		| ROL32(x & 0x02108002, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x01042010, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x40080140, 24)
		| ((x & 0x10410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 5, 10, 3, 0, 9, 6, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_188(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x01081040) << 4)
		| ROL32(x & 0x20800401, 8)
		| ROL32(x & 0x08024020, 12)
		| ROL32(x & 0x80100108, 16)
		| ROL32(x & 0x02042080, 20)
		| ROL32(x & 0x10400802, 24)
		| ((x & 0x04018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_188(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x00401801) << 4)
		| ROL32(x & 0x02104008, 8)
		| ROL32(x & 0x08002042, 12)
		| ROL32(x & 0x01088010, 16)
		| ROL32(x & 0x24020080, 20)
		| ROL32(x & 0x80040120, 24)
		| ((x & 0x10810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 13, 10, 3, 0, 9, 6, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_189(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200208)
		| ((x & 0x01041040) << 4)
		| ROL32(x & 0x20800801, 8)
		| ROL32(x & 0x04024020, 12)
		| ROL32(x & 0x80100104, 16)
		| ROL32(x & 0x02082080, 20)
		| ROL32(x & 0x10400402, 24)
		| ((x & 0x08018010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_189(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200208)
		| ((x & 0x00801801) << 4)
		| ROL32(x & 0x02104004, 8)
		| ROL32(x & 0x08002082, 12)
		| ROL32(x & 0x01048010, 16)
		| ROL32(x & 0x24020040, 20)
		| ROL32(x & 0x80080120, 24)
		| ((x & 0x10410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 5, 10, 3, 8, 1, 6, 15, 4, 13, 2, 11]
void BOGI32_omega_diffusion_190(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200204)
		| ((x & 0x01081080) << 4)
		| ROL32(x & 0x20400401, 8)
		| ROL32(x & 0x08028020, 12)
		| ROL32(x & 0x40100108, 16)
		| ROL32(x & 0x02042040, 20)
		| ROL32(x & 0x10800802, 24)
		| ((x & 0x04014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_190(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200204)
		| ((x & 0x00401401) << 4)
		| ROL32(x & 0x02108008, 8)
		| ROL32(x & 0x04002042, 12)
		| ROL32(x & 0x01084010, 16)
		| ROL32(x & 0x28020080, 20)
		| ROL32(x & 0x40040120, 24)
		| ((x & 0x10810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 0, 3, 2), (3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 13, 10, 3, 8, 1, 6, 15, 12, 5, 2, 11]
void BOGI32_omega_diffusion_191(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x01041080) << 4)
		| ROL32(x & 0x20400801, 8)
		| ROL32(x & 0x04028020, 12)
		| ROL32(x & 0x40100104, 16)
		| ROL32(x & 0x02082040, 20)
		| ROL32(x & 0x10800402, 24)
		| ((x & 0x08014010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_191(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x00801401) << 4)
		| ROL32(x & 0x02108004, 8)
		| ROL32(x & 0x04002082, 12)
		| ROL32(x & 0x01044010, 16)
		| ROL32(x & 0x28020040, 20)
		| ROL32(x & 0x40080120, 24)
		| ((x & 0x10410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 1, 3, 2), (2, 3, 1, 0), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 13, 6, 11, 8, 5, 14, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_192(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100401)
		| ((x & 0x01048080) << 4)
		| ROL32(x & 0x40400202, 8)
		| ROL32(x & 0x08082010, 12)
		| ROL32(x & 0x10200104, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_192(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100401)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x01041020, 16)
		| ROL32(x & 0x82010080, 20)
		| ROL32(x & 0x40020240, 24)
		| ((x & 0x10480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 1, 3, 2), (3, 0, 2, 1), (2, 3, 1, 0))
//[8, 13, 2, 7, 12, 1, 6, 11, 4, 9, 14, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_193(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100801)
		| ((x & 0x01084040) << 4)
		| ROL32(x & 0x80800202, 8)
		| ROL32(x & 0x04042010, 12)
		| ROL32(x & 0x10200108, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_193(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100801)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x01081020, 16)
		| ROL32(x & 0x42010040, 20)
		| ROL32(x & 0x80020280, 24)
		| ((x & 0x10840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 1, 14, 11, 8, 13, 6, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_194(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x01024080) << 4)
		| ROL32(x & 0x80400804, 8)
		| ROL32(x & 0x04082010, 12)
		| ROL32(x & 0x10200102, 16)
		| ROL32(x & 0x02018040, 20)
		| ROL32(x & 0x40800408, 24)
		| ((x & 0x08041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_194(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x00804102) << 4)
		| ROL32(x & 0x08408004, 8)
		| ROL32(x & 0x04002018, 12)
		| ROL32(x & 0x01021020, 16)
		| ROL32(x & 0x82010040, 20)
		| ROL32(x & 0x40080480, 24)
		| ((x & 0x10240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 5, 14, 11, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_195(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x01028080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08082010, 12)
		| ROL32(x & 0x10200102, 16)
		| ROL32(x & 0x02014040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_195(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x00404102) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04002014, 12)
		| ROL32(x & 0x01021020, 16)
		| ROL32(x & 0x82010080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 1, 14, 11, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_196(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x01024040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04042010, 12)
		| ROL32(x & 0x10200102, 16)
		| ROL32(x & 0x02018080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_196(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x00808102) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08002018, 12)
		| ROL32(x & 0x01021020, 16)
		| ROL32(x & 0x42010040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 1, 2), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 5, 14, 11, 12, 9, 6, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_197(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x01028040) << 4)
		| ROL32(x & 0x40800408, 8)
		| ROL32(x & 0x08042010, 12)
		| ROL32(x & 0x10200102, 16)
		| ROL32(x & 0x02014080, 20)
		| ROL32(x & 0x80400804, 24)
		| ((x & 0x04081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_197(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100201)
		| ((x & 0x00408102) << 4)
		| ROL32(x & 0x04804008, 8)
		| ROL32(x & 0x08002014, 12)
		| ROL32(x & 0x01021020, 16)
		| ROL32(x & 0x42010080, 20)
		| ROL32(x & 0x80040840, 24)
		| ((x & 0x10280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 2, 1), (2, 1, 3, 0), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 5, 14, 11, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_198(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100801)
		| ((x & 0x01028020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02082010, 12)
		| ROL32(x & 0x10800102, 16)
		| ROL32(x & 0x08014040, 20)
		| ROL32(x & 0x80200208, 24)
		| ((x & 0x04041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_198(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100801)
		| ((x & 0x00404108) << 4)
		| ROL32(x & 0x08802002, 8)
		| ROL32(x & 0x04008014, 12)
		| ROL32(x & 0x01021080, 16)
		| ROL32(x & 0x82010020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 1, 14, 11, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_199(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100401)
		| ((x & 0x01024020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02042010, 12)
		| ROL32(x & 0x10400102, 16)
		| ROL32(x & 0x04018080, 20)
		| ROL32(x & 0x40200204, 24)
		| ((x & 0x08081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_199(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100401)
		| ((x & 0x00808104) << 4)
		| ROL32(x & 0x04402002, 8)
		| ROL32(x & 0x08004018, 12)
		| ROL32(x & 0x01021040, 16)
		| ROL32(x & 0x42010020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 0, 3, 1), (0, 3, 1, 2), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 13, 2, 11, 8, 5, 14, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_200(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x01042080) << 4)
		| ROL32(x & 0x80200802, 8)
		| ROL32(x & 0x02084010, 12)
		| ROL32(x & 0x10400104, 16)
		| ROL32(x & 0x04018020, 20)
		| ROL32(x & 0x20800208, 24)
		| ((x & 0x08021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_200(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x00802104) << 4)
		| ROL32(x & 0x08208002, 8)
		| ROL32(x & 0x02004018, 12)
		| ROL32(x & 0x01041040, 16)
		| ROL32(x & 0x84010020, 20)
		| ROL32(x & 0x20080280, 24)
		| ((x & 0x10420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 0, 3, 1), (3, 1, 2, 0), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 5, 2, 11, 4, 9, 14, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_201(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x01082040) << 4)
		| ROL32(x & 0x40200402, 8)
		| ROL32(x & 0x02048010, 12)
		| ROL32(x & 0x10800108, 16)
		| ROL32(x & 0x08014020, 20)
		| ROL32(x & 0x20400204, 24)
		| ((x & 0x04021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_201(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x00402108) << 4)
		| ROL32(x & 0x04204002, 8)
		| ROL32(x & 0x02008014, 12)
		| ROL32(x & 0x01081080, 16)
		| ROL32(x & 0x48010020, 20)
		| ROL32(x & 0x20040240, 24)
		| ((x & 0x10820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_202(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x01048080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08084010, 12)
		| ROL32(x & 0x10400104, 16)
		| ROL32(x & 0x04012020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_202(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x00202104) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02004012, 12)
		| ROL32(x & 0x01041040, 16)
		| ROL32(x & 0x84010080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_203(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100801)
		| ((x & 0x01048040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04084010, 12)
		| ROL32(x & 0x10800104, 16)
		| ROL32(x & 0x08012020, 20)
		| ROL32(x & 0x80400408, 24)
		| ((x & 0x02021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_203(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100801)
		| ((x & 0x00202108) << 4)
		| ROL32(x & 0x08804004, 8)
		| ROL32(x & 0x02008012, 12)
		| ROL32(x & 0x01041080, 16)
		| ROL32(x & 0x84010040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_204(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100401)
		| ((x & 0x01084080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08048010, 12)
		| ROL32(x & 0x10400108, 16)
		| ROL32(x & 0x04012020, 20)
		| ROL32(x & 0x40800804, 24)
		| ((x & 0x02021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_204(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100401)
		| ((x & 0x00202104) << 4)
		| ROL32(x & 0x04408008, 8)
		| ROL32(x & 0x02004012, 12)
		| ROL32(x & 0x01081040, 16)
		| ROL32(x & 0x48010080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 1, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_205(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x01084040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04048010, 12)
		| ROL32(x & 0x10800108, 16)
		| ROL32(x & 0x08012020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_205(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x00202108) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02008012, 12)
		| ROL32(x & 0x01081080, 16)
		| ROL32(x & 0x48010040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 3, 1, 0), (0, 1, 3, 2), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 5, 14, 11, 8, 13, 6, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_206(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100201)
		| ((x & 0x01028080) << 4)
		| ROL32(x & 0x20200404, 8)
		| ROL32(x & 0x08084010, 12)
		| ROL32(x & 0x10400102, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_206(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100201)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x01021040, 16)
		| ROL32(x & 0x84010080, 20)
		| ROL32(x & 0x20040420, 24)
		| ((x & 0x10280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (2, 3, 1, 0), (3, 0, 2, 1), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 1, 14, 11, 12, 9, 6, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_207(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100201)
		| ((x & 0x01024040) << 4)
		| ROL32(x & 0x20200808, 8)
		| ROL32(x & 0x04048010, 12)
		| ROL32(x & 0x10800102, 16)
		| ROL32(x & 0x02012020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_207(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100201)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02002012, 12)
		| ROL32(x & 0x01021080, 16)
		| ROL32(x & 0x48010040, 20)
		| ROL32(x & 0x20080820, 24)
		| ((x & 0x10240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 13, 2, 11, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_208(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100201)
		| ((x & 0x01042040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04024010, 12)
		| ROL32(x & 0x10200104, 16)
		| ROL32(x & 0x02018080, 20)
		| ROL32(x & 0x20400402, 24)
		| ((x & 0x08081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_208(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100201)
		| ((x & 0x00808102) << 4)
		| ROL32(x & 0x02204004, 8)
		| ROL32(x & 0x08002018, 12)
		| ROL32(x & 0x01041020, 16)
		| ROL32(x & 0x24010040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 1, 2), (2, 1, 3, 0), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 5, 2, 11, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_209(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100201)
		| ((x & 0x01082080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08028010, 12)
		| ROL32(x & 0x10200108, 16)
		| ROL32(x & 0x02014040, 20)
		| ROL32(x & 0x20800802, 24)
		| ((x & 0x04041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_209(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100201)
		| ((x & 0x00404102) << 4)
		| ROL32(x & 0x02208008, 8)
		| ROL32(x & 0x04002014, 12)
		| ROL32(x & 0x01081020, 16)
		| ROL32(x & 0x28010080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_210(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100801)
		| ((x & 0x01082020) << 4)
		| ROL32(x & 0x80800404, 8)
		| ROL32(x & 0x02024010, 12)
		| ROL32(x & 0x10400108, 16)
		| ROL32(x & 0x08018080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_210(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100801)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08008018, 12)
		| ROL32(x & 0x01081040, 16)
		| ROL32(x & 0x24010020, 20)
		| ROL32(x & 0x80040480, 24)
		| ((x & 0x10820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_211(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x01042020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02024010, 12)
		| ROL32(x & 0x10400104, 16)
		| ROL32(x & 0x04018080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_211(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x00808104) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08004018, 12)
		| ROL32(x & 0x01041040, 16)
		| ROL32(x & 0x24010020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_212(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x01082020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02028010, 12)
		| ROL32(x & 0x10800108, 16)
		| ROL32(x & 0x08014040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_212(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x00404108) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04008014, 12)
		| ROL32(x & 0x01081080, 16)
		| ROL32(x & 0x28010020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 0, 2, 1), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_213(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100401)
		| ((x & 0x01042020) << 4)
		| ROL32(x & 0x40400808, 8)
		| ROL32(x & 0x02028010, 12)
		| ROL32(x & 0x10800104, 16)
		| ROL32(x & 0x04014040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_213(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100401)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04004014, 12)
		| ROL32(x & 0x01041080, 16)
		| ROL32(x & 0x28010020, 20)
		| ROL32(x & 0x40080840, 24)
		| ((x & 0x10420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 1, 2, 0), (0, 3, 1, 2), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 13, 6, 11, 12, 5, 10, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_214(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x01048020) << 4)
		| ROL32(x & 0x20800208, 8)
		| ROL32(x & 0x08024010, 12)
		| ROL32(x & 0x10400104, 16)
		| ROL32(x & 0x04012080, 20)
		| ROL32(x & 0x80200802, 24)
		| ((x & 0x02081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_214(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100401)
		| ((x & 0x00208104) << 4)
		| ROL32(x & 0x02802008, 8)
		| ROL32(x & 0x08004012, 12)
		| ROL32(x & 0x01041040, 16)
		| ROL32(x & 0x24010080, 20)
		| ROL32(x & 0x80020820, 24)
		| ((x & 0x10480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 0, 3), (3, 1, 2, 0), (2, 0, 3, 1), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 1, 6, 11, 4, 13, 10, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_215(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x01084020) << 4)
		| ROL32(x & 0x20400204, 8)
		| ROL32(x & 0x04028010, 12)
		| ROL32(x & 0x10800108, 16)
		| ROL32(x & 0x08012040, 20)
		| ROL32(x & 0x40200402, 24)
		| ((x & 0x02041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_215(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100801)
		| ((x & 0x00204108) << 4)
		| ROL32(x & 0x02402004, 8)
		| ROL32(x & 0x04008012, 12)
		| ROL32(x & 0x01081080, 16)
		| ROL32(x & 0x28010040, 20)
		| ROL32(x & 0x40020420, 24)
		| ((x & 0x10840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 1, 2, 3), (2, 3, 0, 1), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 13, 6, 11, 4, 1, 10, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_216(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100802)
		| ((x & 0x01048020) << 4)
		| ROL32(x & 0x10400201, 8)
		| ROL32(x & 0x04082010, 12)
		| ROL32(x & 0x40800104, 16)
		| ROL32(x & 0x08021040, 20)
		| ROL32(x & 0x80200408, 24)
		| ((x & 0x02014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_216(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100802)
		| ((x & 0x00201408) << 4)
		| ROL32(x & 0x08802004, 8)
		| ROL32(x & 0x04008021, 12)
		| ROL32(x & 0x01044080, 16)
		| ROL32(x & 0x82010040, 20)
		| ROL32(x & 0x40020110, 24)
		| ((x & 0x10480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 1, 2, 3), (3, 0, 1, 2), (2, 3, 0, 1))
//[8, 13, 2, 7, 12, 1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_217(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100402)
		| ((x & 0x01084020) << 4)
		| ROL32(x & 0x10800201, 8)
		| ROL32(x & 0x08042010, 12)
		| ROL32(x & 0x80400108, 16)
		| ROL32(x & 0x04021080, 20)
		| ROL32(x & 0x40200804, 24)
		| ((x & 0x02018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_217(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100402)
		| ((x & 0x00201804) << 4)
		| ROL32(x & 0x04402008, 8)
		| ROL32(x & 0x08004021, 12)
		| ROL32(x & 0x01088040, 16)
		| ROL32(x & 0x42010080, 20)
		| ROL32(x & 0x80020110, 24)
		| ((x & 0x10840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 1, 2), (2, 1, 0, 3), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 5, 14, 11, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_218(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100204)
		| ((x & 0x01028080) << 4)
		| ROL32(x & 0x10400401, 8)
		| ROL32(x & 0x08082010, 12)
		| ROL32(x & 0x40200102, 16)
		| ROL32(x & 0x02041040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_218(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100204)
		| ((x & 0x00401402) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04002041, 12)
		| ROL32(x & 0x01024020, 16)
		| ROL32(x & 0x82010080, 20)
		| ROL32(x & 0x40040110, 24)
		| ((x & 0x10280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 1, 14, 11, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_219(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100208)
		| ((x & 0x01024040) << 4)
		| ROL32(x & 0x10800801, 8)
		| ROL32(x & 0x04042010, 12)
		| ROL32(x & 0x80200102, 16)
		| ROL32(x & 0x02081080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_219(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100208)
		| ((x & 0x00801802) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08002081, 12)
		| ROL32(x & 0x01028020, 16)
		| ROL32(x & 0x42010040, 20)
		| ROL32(x & 0x80080110, 24)
		| ((x & 0x10240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_220(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100404)
		| ((x & 0x01024020) << 4)
		| ROL32(x & 0x10400801, 8)
		| ROL32(x & 0x02082010, 12)
		| ROL32(x & 0x80800102, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40200208, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_220(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100404)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08402002, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x01028080, 16)
		| ROL32(x & 0x82010020, 20)
		| ROL32(x & 0x40080110, 24)
		| ((x & 0x10240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_221(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100804)
		| ((x & 0x01028020) << 4)
		| ROL32(x & 0x10400401, 8)
		| ROL32(x & 0x02082010, 12)
		| ROL32(x & 0x40800102, 16)
		| ROL32(x & 0x08041040, 20)
		| ROL32(x & 0x80200208, 24)
		| ((x & 0x04014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_221(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100804)
		| ((x & 0x00401408) << 4)
		| ROL32(x & 0x08802002, 8)
		| ROL32(x & 0x04008041, 12)
		| ROL32(x & 0x01024080, 16)
		| ROL32(x & 0x82010020, 20)
		| ROL32(x & 0x40040110, 24)
		| ((x & 0x10280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_222(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100408)
		| ((x & 0x01024020) << 4)
		| ROL32(x & 0x10800801, 8)
		| ROL32(x & 0x02042010, 12)
		| ROL32(x & 0x80400102, 16)
		| ROL32(x & 0x04081080, 20)
		| ROL32(x & 0x40200204, 24)
		| ((x & 0x08018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_222(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100408)
		| ((x & 0x00801804) << 4)
		| ROL32(x & 0x04402002, 8)
		| ROL32(x & 0x08004081, 12)
		| ROL32(x & 0x01028040, 16)
		| ROL32(x & 0x42010020, 20)
		| ROL32(x & 0x80080110, 24)
		| ((x & 0x10240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (0, 3, 2, 1), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_223(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100808)
		| ((x & 0x01028020) << 4)
		| ROL32(x & 0x10800401, 8)
		| ROL32(x & 0x02042010, 12)
		| ROL32(x & 0x40400102, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80200204, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_223(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100808)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04802002, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x01024040, 16)
		| ROL32(x & 0x42010020, 20)
		| ROL32(x & 0x80040110, 24)
		| ((x & 0x10280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 0, 1, 3), (0, 3, 2, 1), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 13, 2, 11, 0, 9, 6, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_224(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100202)
		| ((x & 0x01042040) << 4)
		| ROL32(x & 0x10200801, 8)
		| ROL32(x & 0x04084010, 12)
		| ROL32(x & 0x80800104, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20400408, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_224(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100202)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08204004, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x01048080, 16)
		| ROL32(x & 0x84010040, 20)
		| ROL32(x & 0x20080110, 24)
		| ((x & 0x10420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 0, 1, 3), (3, 1, 0, 2), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 5, 2, 11, 8, 1, 6, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_225(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100202)
		| ((x & 0x01082080) << 4)
		| ROL32(x & 0x10200401, 8)
		| ROL32(x & 0x08048010, 12)
		| ROL32(x & 0x40400108, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20800804, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_225(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100202)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04208008, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x01084040, 16)
		| ROL32(x & 0x48010080, 20)
		| ROL32(x & 0x20040110, 24)
		| ((x & 0x10820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_226(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100402)
		| ((x & 0x01048080) << 4)
		| ROL32(x & 0x10200201, 8)
		| ROL32(x & 0x08084010, 12)
		| ROL32(x & 0x20400104, 16)
		| ROL32(x & 0x04021020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_226(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100402)
		| ((x & 0x00201204) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02004021, 12)
		| ROL32(x & 0x01042040, 16)
		| ROL32(x & 0x84010080, 20)
		| ROL32(x & 0x20020110, 24)
		| ((x & 0x10480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_227(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100802)
		| ((x & 0x01048040) << 4)
		| ROL32(x & 0x10200201, 8)
		| ROL32(x & 0x04084010, 12)
		| ROL32(x & 0x20800104, 16)
		| ROL32(x & 0x08021020, 20)
		| ROL32(x & 0x80400408, 24)
		| ((x & 0x02012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_227(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100802)
		| ((x & 0x00201208) << 4)
		| ROL32(x & 0x08804004, 8)
		| ROL32(x & 0x02008021, 12)
		| ROL32(x & 0x01042080, 16)
		| ROL32(x & 0x84010040, 20)
		| ROL32(x & 0x20020110, 24)
		| ((x & 0x10480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_228(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100402)
		| ((x & 0x01084080) << 4)
		| ROL32(x & 0x10200201, 8)
		| ROL32(x & 0x08048010, 12)
		| ROL32(x & 0x20400108, 16)
		| ROL32(x & 0x04021020, 20)
		| ROL32(x & 0x40800804, 24)
		| ((x & 0x02012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_228(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100402)
		| ((x & 0x00201204) << 4)
		| ROL32(x & 0x04408008, 8)
		| ROL32(x & 0x02004021, 12)
		| ROL32(x & 0x01082040, 16)
		| ROL32(x & 0x48010080, 20)
		| ROL32(x & 0x20020110, 24)
		| ((x & 0x10840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 1, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_229(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100802)
		| ((x & 0x01084040) << 4)
		| ROL32(x & 0x10200201, 8)
		| ROL32(x & 0x04048010, 12)
		| ROL32(x & 0x20800108, 16)
		| ROL32(x & 0x08021020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_229(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100802)
		| ((x & 0x00201208) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02008021, 12)
		| ROL32(x & 0x01082080, 16)
		| ROL32(x & 0x48010040, 20)
		| ROL32(x & 0x20020110, 24)
		| ((x & 0x10840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 3, 0, 1), (0, 1, 2, 3), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 5, 14, 11, 4, 9, 2, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_230(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100804)
		| ((x & 0x01028040) << 4)
		| ROL32(x & 0x10200401, 8)
		| ROL32(x & 0x02084010, 12)
		| ROL32(x & 0x20800102, 16)
		| ROL32(x & 0x08041020, 20)
		| ROL32(x & 0x80400208, 24)
		| ((x & 0x04012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_230(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100804)
		| ((x & 0x00401208) << 4)
		| ROL32(x & 0x08804002, 8)
		| ROL32(x & 0x02008041, 12)
		| ROL32(x & 0x01022080, 16)
		| ROL32(x & 0x84010020, 20)
		| ROL32(x & 0x20040110, 24)
		| ((x & 0x10280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (2, 3, 0, 1), (3, 0, 1, 2), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 1, 14, 11, 8, 5, 2, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_231(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100408)
		| ((x & 0x01024080) << 4)
		| ROL32(x & 0x10200801, 8)
		| ROL32(x & 0x02048010, 12)
		| ROL32(x & 0x20400102, 16)
		| ROL32(x & 0x04081020, 20)
		| ROL32(x & 0x40800204, 24)
		| ((x & 0x08012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_231(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100408)
		| ((x & 0x00801204) << 4)
		| ROL32(x & 0x04408002, 8)
		| ROL32(x & 0x02004081, 12)
		| ROL32(x & 0x01022040, 16)
		| ROL32(x & 0x48010020, 20)
		| ROL32(x & 0x20080110, 24)
		| ((x & 0x10240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 14, 7, 12, 5, 2, 11, 0, 9, 6, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_232(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100204)
		| ((x & 0x01082040) << 4)
		| ROL32(x & 0x10800401, 8)
		| ROL32(x & 0x08024010, 12)
		| ROL32(x & 0x80200108, 16)
		| ROL32(x & 0x02041080, 20)
		| ROL32(x & 0x20400802, 24)
		| ((x & 0x04018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_232(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100204)
		| ((x & 0x00401802) << 4)
		| ROL32(x & 0x02204008, 8)
		| ROL32(x & 0x08002041, 12)
		| ROL32(x & 0x01088020, 16)
		| ROL32(x & 0x24010080, 20)
		| ROL32(x & 0x80040110, 24)
		| ((x & 0x10820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 13, 2, 11, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_233(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100208)
		| ((x & 0x01042040) << 4)
		| ROL32(x & 0x10800801, 8)
		| ROL32(x & 0x04024010, 12)
		| ROL32(x & 0x80200104, 16)
		| ROL32(x & 0x02081080, 20)
		| ROL32(x & 0x20400402, 24)
		| ((x & 0x08018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_233(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100208)
		| ((x & 0x00801802) << 4)
		| ROL32(x & 0x02204004, 8)
		| ROL32(x & 0x08002081, 12)
		| ROL32(x & 0x01048020, 16)
		| ROL32(x & 0x24010040, 20)
		| ROL32(x & 0x80080110, 24)
		| ((x & 0x10420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 5, 2, 11, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_234(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100204)
		| ((x & 0x01082080) << 4)
		| ROL32(x & 0x10400401, 8)
		| ROL32(x & 0x08028010, 12)
		| ROL32(x & 0x40200108, 16)
		| ROL32(x & 0x02041040, 20)
		| ROL32(x & 0x20800802, 24)
		| ((x & 0x04014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_234(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100204)
		| ((x & 0x00401402) << 4)
		| ROL32(x & 0x02208008, 8)
		| ROL32(x & 0x04002041, 12)
		| ROL32(x & 0x01084020, 16)
		| ROL32(x & 0x28010080, 20)
		| ROL32(x & 0x40040110, 24)
		| ((x & 0x10820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 1, 2), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 13, 2, 11, 8, 1, 6, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_235(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100208)
		| ((x & 0x01042080) << 4)
		| ROL32(x & 0x10400801, 8)
		| ROL32(x & 0x04028010, 12)
		| ROL32(x & 0x40200104, 16)
		| ROL32(x & 0x02081040, 20)
		| ROL32(x & 0x20800402, 24)
		| ((x & 0x08014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_235(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100208)
		| ((x & 0x00801402) << 4)
		| ROL32(x & 0x02208004, 8)
		| ROL32(x & 0x04002081, 12)
		| ROL32(x & 0x01044020, 16)
		| ROL32(x & 0x28010040, 20)
		| ROL32(x & 0x40080110, 24)
		| ((x & 0x10420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 13, 2, 11, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_236(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100408)
		| ((x & 0x01042020) << 4)
		| ROL32(x & 0x10800801, 8)
		| ROL32(x & 0x02024010, 12)
		| ROL32(x & 0x80400104, 16)
		| ROL32(x & 0x04081080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_236(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100408)
		| ((x & 0x00801804) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08004081, 12)
		| ROL32(x & 0x01048040, 16)
		| ROL32(x & 0x24010020, 20)
		| ROL32(x & 0x80080110, 24)
		| ((x & 0x10420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 0, 2, 1), (2, 1, 0, 3), (0, 3, 1, 2))
//[0, 9, 14, 7, 12, 5, 2, 11, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_237(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100804)
		| ((x & 0x01082020) << 4)
		| ROL32(x & 0x10400401, 8)
		| ROL32(x & 0x02028010, 12)
		| ROL32(x & 0x40800108, 16)
		| ROL32(x & 0x08041040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_237(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100804)
		| ((x & 0x00401408) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04008041, 12)
		| ROL32(x & 0x01084080, 16)
		| ROL32(x & 0x28010020, 20)
		| ROL32(x & 0x40040110, 24)
		| ((x & 0x10820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 1, 0, 2), (0, 3, 2, 1), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 13, 6, 11, 4, 9, 2, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_238(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100808)
		| ((x & 0x01048040) << 4)
		| ROL32(x & 0x10800201, 8)
		| ROL32(x & 0x04024010, 12)
		| ROL32(x & 0x20200104, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80400402, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_238(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100808)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02804004, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x01042020, 16)
		| ROL32(x & 0x24010040, 20)
		| ROL32(x & 0x80020110, 24)
		| ((x & 0x10480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 2, 3, 0), (3, 1, 0, 2), (2, 0, 1, 3), (0, 3, 2, 1))
//[0, 9, 14, 7, 12, 1, 6, 11, 8, 5, 2, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_239(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100404)
		| ((x & 0x01084080) << 4)
		| ROL32(x & 0x10400201, 8)
		| ROL32(x & 0x08028010, 12)
		| ROL32(x & 0x20200108, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40800802, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_239(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100404)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02408008, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x01082020, 16)
		| ROL32(x & 0x28010080, 20)
		| ROL32(x & 0x40020110, 24)
		| ((x & 0x10840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 1, 2, 3), (2, 0, 3, 1), (3, 2, 1, 0))
//[12, 9, 2, 7, 8, 1, 6, 15, 4, 13, 10, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_240(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x01014020) << 4)
		| ROL32(x & 0x80400204, 8)
		| ROL32(x & 0x04082080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08028040, 20)
		| ROL32(x & 0x40200408, 24)
		| ((x & 0x02041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_240(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x00204101) << 4)
		| ROL32(x & 0x08402004, 8)
		| ROL32(x & 0x04008028, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x82080040, 20)
		| ROL32(x & 0x40020480, 24)
		| ((x & 0x10140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 1, 2, 3), (3, 2, 1, 0), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 9, 6, 15, 12, 5, 10, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_241(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x01018020) << 4)
		| ROL32(x & 0x40800208, 8)
		| ROL32(x & 0x08042040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04024080, 20)
		| ROL32(x & 0x80200804, 24)
		| ((x & 0x02081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_241(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x00208101) << 4)
		| ROL32(x & 0x04802008, 8)
		| ROL32(x & 0x08004024, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x42040080, 20)
		| ROL32(x & 0x80020840, 24)
		| ((x & 0x10180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 1, 10, 15, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_242(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01014080) << 4)
		| ROL32(x & 0x80400804, 8)
		| ROL32(x & 0x04082020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02028040, 20)
		| ROL32(x & 0x40800408, 24)
		| ((x & 0x08041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_242(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00804101) << 4)
		| ROL32(x & 0x08408004, 8)
		| ROL32(x & 0x04002028, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x82020040, 20)
		| ROL32(x & 0x40080480, 24)
		| ((x & 0x10140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (2, 1, 3, 0), (3, 0, 2, 1))
//[12, 9, 2, 7, 0, 5, 10, 15, 8, 13, 6, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_243(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01018080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08082020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02024040, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_243(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00404101) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x04002024, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x82020080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (3, 0, 2, 1), (2, 1, 3, 0))
//[8, 13, 2, 7, 4, 1, 10, 15, 12, 9, 6, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_244(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01014040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04042020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02028080, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_244(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00808101) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x08002028, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x42020040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 1, 3), (3, 1, 2, 0), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 5, 10, 15, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_245(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01018040) << 4)
		| ROL32(x & 0x40800408, 8)
		| ROL32(x & 0x08042020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02024080, 20)
		| ROL32(x & 0x80400804, 24)
		| ((x & 0x04081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_245(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00408101) << 4)
		| ROL32(x & 0x04804008, 8)
		| ROL32(x & 0x08002024, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x42020080, 20)
		| ROL32(x & 0x80040840, 24)
		| ((x & 0x10180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 2, 0))
//[12, 9, 2, 7, 4, 1, 10, 15, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_246(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x01014080) << 4)
		| ROL32(x & 0x80400802, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40800208, 24)
		| ((x & 0x08021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_246(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x00802101) << 4)
		| ROL32(x & 0x08408002, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x40080280, 24)
		| ((x & 0x10140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (0, 2, 3, 1), (3, 1, 2, 0), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 5, 10, 15, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_247(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x01018040) << 4)
		| ROL32(x & 0x40800402, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80400204, 24)
		| ((x & 0x04021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_247(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x00402101) << 4)
		| ROL32(x & 0x04804002, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x80040240, 24)
		| ((x & 0x10180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 9, 2, 15, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_248(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x01012080) << 4)
		| ROL32(x & 0x80200804, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20800408, 24)
		| ((x & 0x08041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_248(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x00804101) << 4)
		| ROL32(x & 0x08208004, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x20080480, 24)
		| ((x & 0x10120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 1, 3), (3, 1, 2, 0), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 5, 2, 15, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_249(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x01012040) << 4)
		| ROL32(x & 0x40200408, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20400804, 24)
		| ((x & 0x04081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_249(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x00408101) << 4)
		| ROL32(x & 0x04204008, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x20040840, 24)
		| ((x & 0x10120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_250(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x01012040) << 4)
		| ROL32(x & 0x80200402, 8)
		| ROL32(x & 0x02084080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08048020, 20)
		| ROL32(x & 0x20400208, 24)
		| ((x & 0x04021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_250(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x00402101) << 4)
		| ROL32(x & 0x08204002, 8)
		| ROL32(x & 0x02008048, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x84080020, 20)
		| ROL32(x & 0x20040280, 24)
		| ((x & 0x10120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_251(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01012080) << 4)
		| ROL32(x & 0x80200802, 8)
		| ROL32(x & 0x02084040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04048020, 20)
		| ROL32(x & 0x20800208, 24)
		| ((x & 0x08021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_251(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00802101) << 4)
		| ROL32(x & 0x08208002, 8)
		| ROL32(x & 0x02004048, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x84040020, 20)
		| ROL32(x & 0x20080280, 24)
		| ((x & 0x10120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_252(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01012040) << 4)
		| ROL32(x & 0x40200402, 8)
		| ROL32(x & 0x02048080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08084020, 20)
		| ROL32(x & 0x20400204, 24)
		| ((x & 0x04021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_252(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00402101) << 4)
		| ROL32(x & 0x04204002, 8)
		| ROL32(x & 0x02008084, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x48080020, 20)
		| ROL32(x & 0x20040240, 24)
		| ((x & 0x10120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 0, 3, 1), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_253(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x01012080) << 4)
		| ROL32(x & 0x40200802, 8)
		| ROL32(x & 0x02048040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04084020, 20)
		| ROL32(x & 0x20800204, 24)
		| ((x & 0x08021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_253(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x00802101) << 4)
		| ROL32(x & 0x04208002, 8)
		| ROL32(x & 0x02004084, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x48040020, 20)
		| ROL32(x & 0x20080240, 24)
		| ((x & 0x10120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 1, 3, 0), (0, 2, 1, 3), (3, 0, 2, 1))
//[12, 1, 10, 7, 0, 9, 6, 15, 8, 5, 14, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_254(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01018080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08084040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04042020, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_254(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00202101) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x02004042, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x84040080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (2, 1, 3, 0), (3, 0, 2, 1), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 1, 6, 15, 4, 9, 14, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_255(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01014040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04048080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08082020, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_255(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00202101) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x02008082, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x48080040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x10140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 0, 2, 1), (0, 2, 1, 3), (2, 1, 3, 0))
//[8, 1, 14, 7, 4, 9, 2, 15, 12, 5, 10, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_256(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01012020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02024040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04048080, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_256(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00808101) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x08004048, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x24040020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x10120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 0, 2, 1), (2, 1, 3, 0), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 5, 2, 15, 4, 13, 10, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_257(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01012020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02028080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08084040, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_257(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00404101) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x04008084, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x28080020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x10120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_258(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01018020) << 4)
		| ROL32(x & 0x20800208, 8)
		| ROL32(x & 0x08024040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04042080, 20)
		| ROL32(x & 0x80200802, 24)
		| ((x & 0x02081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_258(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00208101) << 4)
		| ROL32(x & 0x02802008, 8)
		| ROL32(x & 0x08004042, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x24040080, 20)
		| ROL32(x & 0x80020820, 24)
		| ((x & 0x10180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_259(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x01018020) << 4)
		| ROL32(x & 0x20800204, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80200402, 24)
		| ((x & 0x02041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_259(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x00204101) << 4)
		| ROL32(x & 0x02802004, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x80020420, 24)
		| ((x & 0x10180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_260(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x01014020) << 4)
		| ROL32(x & 0x20400208, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40200802, 24)
		| ((x & 0x02081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_260(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x00208101) << 4)
		| ROL32(x & 0x02402008, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x40020820, 24)
		| ((x & 0x10140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 1, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_261(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01014020) << 4)
		| ROL32(x & 0x20400204, 8)
		| ROL32(x & 0x04028080, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x08082040, 20)
		| ROL32(x & 0x40200402, 24)
		| ((x & 0x02041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_261(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00204101) << 4)
		| ROL32(x & 0x02402004, 8)
		| ROL32(x & 0x04008082, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x28080040, 20)
		| ROL32(x & 0x40020420, 24)
		| ((x & 0x10140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 2, 1, 0), (0, 1, 2, 3), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 5, 10, 15, 12, 9, 6, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_262(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x01018040) << 4)
		| ROL32(x & 0x20800408, 8)
		| ROL32(x & 0x08024020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02042080, 20)
		| ROL32(x & 0x80400802, 24)
		| ((x & 0x04081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_262(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x00408101) << 4)
		| ROL32(x & 0x02804008, 8)
		| ROL32(x & 0x08002042, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x24020080, 20)
		| ROL32(x & 0x80040820, 24)
		| ((x & 0x10180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 0, 2), (3, 2, 1, 0), (2, 0, 3, 1), (0, 1, 2, 3))
//[0, 9, 14, 7, 4, 1, 10, 15, 8, 13, 6, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_263(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x01014080) << 4)
		| ROL32(x & 0x20400804, 8)
		| ROL32(x & 0x04028020, 12)
		| ROL32(x & 0x10100101, 16)
		| ROL32(x & 0x02082040, 20)
		| ROL32(x & 0x40800402, 24)
		| ((x & 0x08041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_263(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x00804101) << 4)
		| ROL32(x & 0x02408004, 8)
		| ROL32(x & 0x04002082, 12)
		| ROL32(x & 0x01011010, 16)
		| ROL32(x & 0x28020040, 20)
		| ROL32(x & 0x40080420, 24)
		| ((x & 0x10140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 1, 3, 2), (2, 0, 1, 3), (3, 2, 0, 1))
//[12, 9, 2, 7, 8, 1, 6, 15, 0, 5, 14, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_264(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800404)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10400202, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80200101, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40100808, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_264(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800404)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x08401008, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x01018020, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x40020210, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 1, 3, 2), (3, 2, 0, 1), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 9, 6, 15, 4, 1, 14, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_265(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400808)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10800202, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40200101, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80100404, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_265(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400808)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x04801004, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x01014020, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x80020210, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 1, 10, 15, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_266(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10400804, 8)
		| ROL32(x & 0x04082020, 12)
		| ROL32(x & 0x80800101, 16)
		| ROL32(x & 0x02021040, 20)
		| ROL32(x & 0x40100408, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_266(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08401004, 8)
		| ROL32(x & 0x04002021, 12)
		| ROL32(x & 0x01018080, 16)
		| ROL32(x & 0x82020040, 20)
		| ROL32(x & 0x40080410, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 1, 3), (3, 1, 0, 2), (2, 0, 3, 1))
//[8, 13, 2, 7, 0, 5, 10, 15, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_267(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10800408, 8)
		| ROL32(x & 0x08042020, 12)
		| ROL32(x & 0x40400101, 16)
		| ROL32(x & 0x02021080, 20)
		| ROL32(x & 0x80100804, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_267(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04801008, 8)
		| ROL32(x & 0x08002021, 12)
		| ROL32(x & 0x01014040, 16)
		| ROL32(x & 0x42020080, 20)
		| ROL32(x & 0x80040810, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3), (3, 1, 0, 2))
//[12, 9, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_268(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10400802, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x80800101, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40100208, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_268(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08401002, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x01018080, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x40080210, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (2, 1, 0, 3), (3, 0, 1, 2))
//[12, 9, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_269(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200804)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10400402, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x40800101, 16)
		| ROL32(x & 0x08041040, 20)
		| ROL32(x & 0x80100208, 24)
		| ((x & 0x04024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_269(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200804)
		| ((x & 0x00402408) << 4)
		| ROL32(x & 0x08801002, 8)
		| ROL32(x & 0x04008041, 12)
		| ROL32(x & 0x01014080, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x40040210, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (3, 0, 1, 2), (2, 1, 0, 3))
//[8, 13, 2, 7, 4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_270(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200408)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10800802, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x80400101, 16)
		| ROL32(x & 0x04081080, 20)
		| ROL32(x & 0x40100204, 24)
		| ((x & 0x08028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_270(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200408)
		| ((x & 0x00802804) << 4)
		| ROL32(x & 0x04401002, 8)
		| ROL32(x & 0x08004081, 12)
		| ROL32(x & 0x01018040, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x80080210, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (0, 2, 3, 1), (3, 1, 0, 2), (2, 0, 1, 3))
//[8, 13, 2, 7, 0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_271(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10800402, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x40400101, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80100204, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_271(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04801002, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x01014040, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x80040210, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 10, 7, 8, 5, 2, 15, 0, 13, 6, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_272(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800202)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10200404, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80400101, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20100808, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_272(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800202)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x08201008, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x01018040, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x20040410, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 9, 2, 15, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_273(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10200804, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x80800101, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20100408, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_273(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08201004, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x01018080, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x20080410, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 5, 2, 15, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_274(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10200408, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x40400101, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20100804, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_274(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04201008, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x01014040, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x20040810, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 1, 3), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 10, 7, 4, 9, 2, 15, 12, 1, 6, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_275(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400202)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10200808, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40800101, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20100404, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_275(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400202)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x04201004, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x01014080, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x20080810, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 0, 2))
//[12, 1, 10, 7, 4, 9, 2, 15, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_276(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10200802, 8)
		| ROL32(x & 0x02084040, 12)
		| ROL32(x & 0x80800101, 16)
		| ROL32(x & 0x04041020, 20)
		| ROL32(x & 0x20100208, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_276(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08201002, 8)
		| ROL32(x & 0x02004041, 12)
		| ROL32(x & 0x01018080, 16)
		| ROL32(x & 0x84040020, 20)
		| ROL32(x & 0x20080210, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 0, 3, 1), (3, 1, 0, 2), (0, 2, 1, 3))
//[0, 13, 10, 7, 8, 5, 2, 15, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_277(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10200402, 8)
		| ROL32(x & 0x02048080, 12)
		| ROL32(x & 0x40400101, 16)
		| ROL32(x & 0x08081020, 20)
		| ROL32(x & 0x20100204, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_277(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04201002, 8)
		| ROL32(x & 0x02008081, 12)
		| ROL32(x & 0x01014040, 16)
		| ROL32(x & 0x48080020, 20)
		| ROL32(x & 0x20040210, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 1, 0, 3), (0, 2, 3, 1), (3, 0, 1, 2))
//[12, 1, 10, 7, 0, 9, 6, 15, 4, 13, 2, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_278(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400802)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10200204, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x20800101, 16)
		| ROL32(x & 0x08021020, 20)
		| ROL32(x & 0x80100408, 24)
		| ((x & 0x02042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_278(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400802)
		| ((x & 0x00204208) << 4)
		| ROL32(x & 0x08801004, 8)
		| ROL32(x & 0x02008021, 12)
		| ROL32(x & 0x01012080, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x20020410, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (2, 1, 0, 3), (3, 0, 1, 2), (0, 2, 3, 1))
//[0, 13, 10, 7, 8, 1, 6, 15, 12, 5, 2, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_279(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800402)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10200208, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x20400101, 16)
		| ROL32(x & 0x04021020, 20)
		| ROL32(x & 0x40100804, 24)
		| ((x & 0x02082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_279(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800402)
		| ((x & 0x00208204) << 4)
		| ROL32(x & 0x04401008, 8)
		| ROL32(x & 0x02004021, 12)
		| ROL32(x & 0x01012040, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x20020810, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 0, 1, 2), (0, 2, 3, 1), (2, 1, 0, 3))
//[8, 1, 14, 7, 4, 9, 2, 15, 0, 13, 6, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_280(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400208)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10800804, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x80200101, 16)
		| ROL32(x & 0x02081080, 20)
		| ROL32(x & 0x20100402, 24)
		| ((x & 0x08048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_280(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400208)
		| ((x & 0x00804802) << 4)
		| ROL32(x & 0x02201004, 8)
		| ROL32(x & 0x08002081, 12)
		| ROL32(x & 0x01018020, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x80080410, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 0, 1, 2), (2, 1, 0, 3), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 5, 2, 15, 12, 1, 6, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_281(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800204)
		| ((x & 0x01012010) << 4)
		| ROL32(x & 0x10400408, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x40200101, 16)
		| ROL32(x & 0x02041040, 20)
		| ROL32(x & 0x20100802, 24)
		| ((x & 0x04084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_281(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800204)
		| ((x & 0x00408402) << 4)
		| ROL32(x & 0x02201008, 8)
		| ROL32(x & 0x04002041, 12)
		| ROL32(x & 0x01014020, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x40040810, 24)
		| ((x & 0x10120100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_282(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10800208, 8)
		| ROL32(x & 0x08024040, 12)
		| ROL32(x & 0x20200101, 16)
		| ROL32(x & 0x04041080, 20)
		| ROL32(x & 0x80100802, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_282(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02801008, 8)
		| ROL32(x & 0x08004041, 12)
		| ROL32(x & 0x01012020, 16)
		| ROL32(x & 0x24040080, 20)
		| ROL32(x & 0x80020810, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_283(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10800204, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x20200101, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80100402, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_283(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02801004, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x01012020, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x80020410, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_284(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10400208, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x20200101, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40100802, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_284(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02401008, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x01012020, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x40020810, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 1, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_285(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10400204, 8)
		| ROL32(x & 0x04028080, 12)
		| ROL32(x & 0x20200101, 16)
		| ROL32(x & 0x08081040, 20)
		| ROL32(x & 0x40100402, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_285(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02401004, 8)
		| ROL32(x & 0x04008081, 12)
		| ROL32(x & 0x01012020, 16)
		| ROL32(x & 0x28080040, 20)
		| ROL32(x & 0x40020410, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 2, 0, 1), (0, 1, 3, 2), (2, 0, 1, 3))
//[8, 1, 14, 7, 0, 5, 10, 15, 4, 13, 2, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_286(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200808)
		| ((x & 0x01018010) << 4)
		| ROL32(x & 0x10800404, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20400101, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80100202, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_286(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200808)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x02801002, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x01012040, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x80040410, 24)
		| ((x & 0x10180100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((1, 3, 2, 0), (3, 2, 0, 1), (2, 0, 1, 3), (0, 1, 3, 2))
//[0, 9, 14, 7, 4, 1, 10, 15, 12, 5, 2, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_287(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200404)
		| ((x & 0x01014010) << 4)
		| ROL32(x & 0x10400808, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20800101, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40100202, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_287(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200404)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x02401002, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x01012080, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x40080810, 24)
		| ((x & 0x10140100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 1, 3, 2), (1, 3, 2, 0), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 13, 6, 3, 0, 9, 14, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_288(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800101)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40100202, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80200404, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10400808, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_288(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800101)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x08104008, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x04048020, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x10020240, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 1, 3, 2), (3, 2, 0, 1), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 9, 6, 3, 8, 1, 14, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_289(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400101)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80100202, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40200808, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10800404, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_289(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400101)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x04108004, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x08084020, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x10020280, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_290(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x04041080) << 4)
		| ROL32(x & 0x80100802, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10800208, 24)
		| ((x & 0x08024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_290(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x00802404) << 4)
		| ROL32(x & 0x08108002, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x10080280, 24)
		| ((x & 0x40410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_291(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40100802, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x80800404, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10400208, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_291(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08104002, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x04048080, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x10080240, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 14, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_292(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80100402, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x40400808, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10800204, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_292(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04108002, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x08084040, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x10040280, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 2, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 14, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_293(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x08081040) << 4)
		| ROL32(x & 0x40100402, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10400204, 24)
		| ((x & 0x04028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_293(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200101)
		| ((x & 0x00402808) << 4)
		| ROL32(x & 0x04104002, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x10040240, 24)
		| ((x & 0x80810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 3, 2, 1), (1, 2, 3, 0), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 9, 14, 3, 0, 13, 10, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_294(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400101)
		| ((x & 0x04021020) << 4)
		| ROL32(x & 0x40100804, 8)
		| ROL32(x & 0x02082040, 12)
		| ROL32(x & 0x80800402, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10200208, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_294(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400101)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08102002, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x04028080, 16)
		| ROL32(x & 0x82040020, 20)
		| ROL32(x & 0x10080440, 24)
		| ((x & 0x40210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (0, 3, 2, 1), (3, 1, 0, 2), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 5, 14, 3, 12, 1, 10, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_295(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800101)
		| ((x & 0x08021020) << 4)
		| ROL32(x & 0x80100408, 8)
		| ROL32(x & 0x02042080, 12)
		| ROL32(x & 0x40400802, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10200204, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_295(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800101)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04102002, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x08024040, 16)
		| ROL32(x & 0x42080020, 20)
		| ROL32(x & 0x10040880, 24)
		| ((x & 0x80210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 2, 3, 0), (0, 3, 2, 1), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 13, 10, 3, 0, 9, 14, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_296(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200101)
		| ((x & 0x02041040) << 4)
		| ROL32(x & 0x20100802, 8)
		| ROL32(x & 0x04084020, 12)
		| ROL32(x & 0x80800204, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10400408, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_296(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200101)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08104004, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x02048080, 16)
		| ROL32(x & 0x84020040, 20)
		| ROL32(x & 0x10080220, 24)
		| ((x & 0x20410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 2, 3, 0), (3, 1, 0, 2), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 5, 10, 3, 8, 1, 14, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_297(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200101)
		| ((x & 0x02081080) << 4)
		| ROL32(x & 0x20100402, 8)
		| ROL32(x & 0x08048020, 12)
		| ROL32(x & 0x40400208, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10800804, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_297(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200101)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04108008, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x02084040, 16)
		| ROL32(x & 0x48020080, 20)
		| ROL32(x & 0x10040220, 24)
		| ((x & 0x20810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 0, 2), (0, 2, 3, 1), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 9, 14, 3, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_298(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x02021080) << 4)
		| ROL32(x & 0x80100804, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10800408, 24)
		| ((x & 0x08042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_298(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x00804202) << 4)
		| ROL32(x & 0x08108004, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x10080480, 24)
		| ((x & 0x20210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 5, 14, 3, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_299(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x02021040) << 4)
		| ROL32(x & 0x40100408, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10400804, 24)
		| ((x & 0x04082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_299(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x00408202) << 4)
		| ROL32(x & 0x04104008, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x10040840, 24)
		| ((x & 0x20210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 5, 14, 3, 0, 13, 10, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_300(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800101)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20100404, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80400202, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10200808, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_300(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800101)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x08102008, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x02028040, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x10040420, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 9, 14, 3, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_301(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20100804, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x80800202, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10200408, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_301(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08102004, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x02028080, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x10080420, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 5, 14, 3, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_302(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20100408, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x40400202, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10200804, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_302(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04102008, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x02024040, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x10040820, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (1, 3, 2, 0), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 9, 14, 3, 12, 1, 10, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_303(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400101)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20100808, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40800202, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10200404, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_303(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400101)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x04102004, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x02024080, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x10080820, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_304(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80100204, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x20200808, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10800402, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_304(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02108004, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x08082020, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x10020480, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 10, 15]
void BOGI32_omega_diffusion_305(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800101)
		| ((x & 0x08041040) << 4)
		| ROL32(x & 0x80100208, 8)
		| ROL32(x & 0x04024080, 12)
		| ROL32(x & 0x20200804, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10400402, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_305(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800101)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02104004, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x08042020, 16)
		| ROL32(x & 0x24080040, 20)
		| ROL32(x & 0x10020880, 24)
		| ((x & 0x80410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_306(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400101)
		| ((x & 0x04081080) << 4)
		| ROL32(x & 0x40100204, 8)
		| ROL32(x & 0x08028040, 12)
		| ROL32(x & 0x20200408, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10800802, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_306(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400101)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02108008, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x04082020, 16)
		| ROL32(x & 0x28040080, 20)
		| ROL32(x & 0x10020440, 24)
		| ((x & 0x40810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 10, 15]
void BOGI32_omega_diffusion_307(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40100208, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x20200404, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10400802, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_307(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02104008, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x04042020, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x10020840, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 2, 0), (0, 2, 3, 1), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 9, 6, 3, 0, 13, 10, 7, 8, 5, 2, 15]
void BOGI32_omega_diffusion_308(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x08081020) << 4)
		| ROL32(x & 0x20100204, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10200402, 24)
		| ((x & 0x02048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_308(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400101)
		| ((x & 0x00204808) << 4)
		| ROL32(x & 0x02102004, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x10020420, 24)
		| ((x & 0x80810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 13, 6, 3, 12, 1, 10, 7, 4, 9, 2, 15]
void BOGI32_omega_diffusion_309(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x04041020) << 4)
		| ROL32(x & 0x20100208, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01012010, 20)
		| ROL32(x & 0x10200802, 24)
		| ((x & 0x02084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_309(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800101)
		| ((x & 0x00208404) << 4)
		| ROL32(x & 0x02102008, 8)
		| ROL32(x & 0x01001012, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x10020820, 24)
		| ((x & 0x40410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 2, 0, 1), (0, 1, 3, 2), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 5, 10, 3, 8, 13, 2, 7, 0, 9, 6, 15]
void BOGI32_omega_diffusion_310(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200101)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80100404, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20400808, 16)
		| ROL32(x & 0x01018010, 20)
		| ROL32(x & 0x10800202, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_310(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200101)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x02108002, 8)
		| ROL32(x & 0x01001018, 12)
		| ROL32(x & 0x08082040, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x10040480, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 1, 3), (3, 2, 0, 1), (1, 3, 2, 0), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 13, 10, 3, 12, 9, 2, 7, 8, 1, 6, 15]
void BOGI32_omega_diffusion_311(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200101)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40100808, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20800404, 16)
		| ROL32(x & 0x01014010, 20)
		| ROL32(x & 0x10400202, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_311(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200101)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x02104002, 8)
		| ROL32(x & 0x01001014, 12)
		| ROL32(x & 0x04042080, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x10080840, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 1, 2, 3), (1, 3, 0, 2), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 13, 6, 3, 4, 1, 10, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_312(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x04041020) << 4)
		| ROL32(x & 0x80100201, 8)
		| ROL32(x & 0x01082080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08028010, 20)
		| ROL32(x & 0x10200108, 24)
		| ((x & 0x02014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_312(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x00201404) << 4)
		| ROL32(x & 0x08102001, 8)
		| ROL32(x & 0x01008028, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x82080010, 20)
		| ROL32(x & 0x10020180, 24)
		| ((x & 0x40410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 1, 2, 3), (3, 2, 1, 0), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 9, 6, 3, 0, 5, 10, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_313(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x08081020) << 4)
		| ROL32(x & 0x40100201, 8)
		| ROL32(x & 0x01042040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04024010, 20)
		| ROL32(x & 0x10200104, 24)
		| ((x & 0x02018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_313(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x00201808) << 4)
		| ROL32(x & 0x04102001, 8)
		| ROL32(x & 0x01004024, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x42040010, 20)
		| ROL32(x & 0x10020140, 24)
		| ((x & 0x80810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 0, 2), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_314(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04041080) << 4)
		| ROL32(x & 0x80100801, 8)
		| ROL32(x & 0x01082020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02028010, 20)
		| ROL32(x & 0x10800108, 24)
		| ((x & 0x08014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_314(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00801404) << 4)
		| ROL32(x & 0x08108001, 8)
		| ROL32(x & 0x01002028, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x82020010, 20)
		| ROL32(x & 0x10080180, 24)
		| ((x & 0x40410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 2, 0), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_315(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40100801, 8)
		| ROL32(x & 0x01082020, 12)
		| ROL32(x & 0x80800404, 16)
		| ROL32(x & 0x02024010, 20)
		| ROL32(x & 0x10400108, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_315(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08104001, 8)
		| ROL32(x & 0x01002024, 12)
		| ROL32(x & 0x04048080, 16)
		| ROL32(x & 0x82020010, 20)
		| ROL32(x & 0x10080140, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 0, 2), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 6, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_316(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80100401, 8)
		| ROL32(x & 0x01042020, 12)
		| ROL32(x & 0x40400808, 16)
		| ROL32(x & 0x02028010, 20)
		| ROL32(x & 0x10800104, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_316(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04108001, 8)
		| ROL32(x & 0x01002028, 12)
		| ROL32(x & 0x08084040, 16)
		| ROL32(x & 0x42020010, 20)
		| ROL32(x & 0x10040180, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 2, 1, 3), (3, 1, 2, 0), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 6, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_317(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08081040) << 4)
		| ROL32(x & 0x40100401, 8)
		| ROL32(x & 0x01042020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02024010, 20)
		| ROL32(x & 0x10400104, 24)
		| ((x & 0x04018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_317(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00401808) << 4)
		| ROL32(x & 0x04104001, 8)
		| ROL32(x & 0x01002024, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x42020010, 20)
		| ROL32(x & 0x10040140, 24)
		| ((x & 0x80810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 3, 1, 2), (1, 2, 0, 3), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 9, 14, 3, 8, 1, 6, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_318(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x04021080) << 4)
		| ROL32(x & 0x80100801, 8)
		| ROL32(x & 0x01082040, 12)
		| ROL32(x & 0x40200402, 16)
		| ROL32(x & 0x02048010, 20)
		| ROL32(x & 0x10800108, 24)
		| ((x & 0x08014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_318(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x00801402) << 4)
		| ROL32(x & 0x08108001, 8)
		| ROL32(x & 0x01002048, 12)
		| ROL32(x & 0x04024020, 16)
		| ROL32(x & 0x82040010, 20)
		| ROL32(x & 0x10080180, 24)
		| ((x & 0x40210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (0, 3, 1, 2), (3, 1, 2, 0), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 5, 14, 3, 0, 9, 6, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_319(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x08021040) << 4)
		| ROL32(x & 0x40100401, 8)
		| ROL32(x & 0x01042080, 12)
		| ROL32(x & 0x80200802, 16)
		| ROL32(x & 0x02084010, 20)
		| ROL32(x & 0x10400104, 24)
		| ((x & 0x04018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_319(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x00401802) << 4)
		| ROL32(x & 0x04104001, 8)
		| ROL32(x & 0x01002084, 12)
		| ROL32(x & 0x08028020, 16)
		| ROL32(x & 0x42080010, 20)
		| ROL32(x & 0x10040140, 24)
		| ((x & 0x80210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 2, 0, 3), (0, 3, 1, 2), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 13, 10, 3, 8, 5, 2, 15, 0, 9, 14, 7]
void BOGI32_omega_diffusion_320(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x02041080) << 4)
		| ROL32(x & 0x80100801, 8)
		| ROL32(x & 0x01084020, 12)
		| ROL32(x & 0x20400204, 16)
		| ROL32(x & 0x04028010, 20)
		| ROL32(x & 0x10800108, 24)
		| ((x & 0x08012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_320(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x00801204) << 4)
		| ROL32(x & 0x08108001, 8)
		| ROL32(x & 0x01004028, 12)
		| ROL32(x & 0x02042040, 16)
		| ROL32(x & 0x84020010, 20)
		| ROL32(x & 0x10080180, 24)
		| ((x & 0x20410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 2, 0, 3), (3, 1, 2, 0), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 5, 10, 3, 4, 9, 2, 15, 8, 1, 14, 7]
void BOGI32_omega_diffusion_321(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x02081040) << 4)
		| ROL32(x & 0x40100401, 8)
		| ROL32(x & 0x01048020, 12)
		| ROL32(x & 0x20800208, 16)
		| ROL32(x & 0x08024010, 20)
		| ROL32(x & 0x10400104, 24)
		| ((x & 0x04012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_321(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x00401208) << 4)
		| ROL32(x & 0x04104001, 8)
		| ROL32(x & 0x01008024, 12)
		| ROL32(x & 0x02082080, 16)
		| ROL32(x & 0x48020010, 20)
		| ROL32(x & 0x10040140, 24)
		| ((x & 0x20810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_322(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x02021040) << 4)
		| ROL32(x & 0x80100401, 8)
		| ROL32(x & 0x01084080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08048010, 20)
		| ROL32(x & 0x10400108, 24)
		| ((x & 0x04012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_322(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x00401202) << 4)
		| ROL32(x & 0x08104001, 8)
		| ROL32(x & 0x01008048, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x84080010, 20)
		| ROL32(x & 0x10040180, 24)
		| ((x & 0x20210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_323(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02021080) << 4)
		| ROL32(x & 0x80100801, 8)
		| ROL32(x & 0x01084040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04048010, 20)
		| ROL32(x & 0x10800108, 24)
		| ((x & 0x08012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_323(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00801202) << 4)
		| ROL32(x & 0x08108001, 8)
		| ROL32(x & 0x01004048, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x84040010, 20)
		| ROL32(x & 0x10080180, 24)
		| ((x & 0x20210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 5, 14, 3, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_324(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02021040) << 4)
		| ROL32(x & 0x40100401, 8)
		| ROL32(x & 0x01048080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08084010, 20)
		| ROL32(x & 0x10400104, 24)
		| ((x & 0x04012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_324(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00401202) << 4)
		| ROL32(x & 0x04104001, 8)
		| ROL32(x & 0x01008084, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x48080010, 20)
		| ROL32(x & 0x10040140, 24)
		| ((x & 0x20210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 0, 2), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 9, 14, 3, 8, 5, 2, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_325(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x02021080) << 4)
		| ROL32(x & 0x40100801, 8)
		| ROL32(x & 0x01048040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04084010, 20)
		| ROL32(x & 0x10800104, 24)
		| ((x & 0x08012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_325(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x00801202) << 4)
		| ROL32(x & 0x04108001, 8)
		| ROL32(x & 0x01004084, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x48040010, 20)
		| ROL32(x & 0x10080140, 24)
		| ((x & 0x20210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 2, 0), (0, 2, 1, 3), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 9, 14, 3, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_326(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20100801, 8)
		| ROL32(x & 0x01084040, 12)
		| ROL32(x & 0x80800202, 16)
		| ROL32(x & 0x04042010, 20)
		| ROL32(x & 0x10200108, 24)
		| ((x & 0x08018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_326(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00801808) << 4)
		| ROL32(x & 0x08102001, 8)
		| ROL32(x & 0x01004042, 12)
		| ROL32(x & 0x02028080, 16)
		| ROL32(x & 0x84040010, 20)
		| ROL32(x & 0x10080120, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (1, 3, 2, 0), (3, 1, 0, 2), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 5, 14, 3, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_327(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20100401, 8)
		| ROL32(x & 0x01048080, 12)
		| ROL32(x & 0x40400202, 16)
		| ROL32(x & 0x08082010, 20)
		| ROL32(x & 0x10200104, 24)
		| ((x & 0x04014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_327(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00401404) << 4)
		| ROL32(x & 0x04102001, 8)
		| ROL32(x & 0x01008082, 12)
		| ROL32(x & 0x02024040, 16)
		| ROL32(x & 0x48080010, 20)
		| ROL32(x & 0x10040120, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 0, 2), (0, 2, 1, 3), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 9, 6, 3, 8, 5, 2, 15, 0, 13, 10, 7]
void BOGI32_omega_diffusion_328(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80100201, 8)
		| ROL32(x & 0x01024040, 12)
		| ROL32(x & 0x20200808, 16)
		| ROL32(x & 0x04048010, 20)
		| ROL32(x & 0x10800102, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_328(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02108001, 8)
		| ROL32(x & 0x01004048, 12)
		| ROL32(x & 0x08082020, 16)
		| ROL32(x & 0x24040010, 20)
		| ROL32(x & 0x10020180, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 13, 6, 3, 4, 9, 2, 15, 12, 1, 10, 7]
void BOGI32_omega_diffusion_329(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40100201, 8)
		| ROL32(x & 0x01028080, 12)
		| ROL32(x & 0x20200404, 16)
		| ROL32(x & 0x08084010, 20)
		| ROL32(x & 0x10400102, 24)
		| ((x & 0x02012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_329(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00201202) << 4)
		| ROL32(x & 0x02104001, 8)
		| ROL32(x & 0x01008084, 12)
		| ROL32(x & 0x04042020, 16)
		| ROL32(x & 0x28080010, 20)
		| ROL32(x & 0x10020140, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 9, 6, 3, 0, 5, 10, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_330(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08081020) << 4)
		| ROL32(x & 0x20100201, 8)
		| ROL32(x & 0x01024040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04042010, 20)
		| ROL32(x & 0x10200102, 24)
		| ((x & 0x02018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_330(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00201808) << 4)
		| ROL32(x & 0x02102001, 8)
		| ROL32(x & 0x01004042, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x24040010, 20)
		| ROL32(x & 0x10020120, 24)
		| ((x & 0x80810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 13, 6, 3, 0, 5, 10, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_331(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x08041020) << 4)
		| ROL32(x & 0x20100201, 8)
		| ROL32(x & 0x01024080, 12)
		| ROL32(x & 0x80400804, 16)
		| ROL32(x & 0x04082010, 20)
		| ROL32(x & 0x10200102, 24)
		| ((x & 0x02018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_331(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x00201804) << 4)
		| ROL32(x & 0x02102001, 8)
		| ROL32(x & 0x01004082, 12)
		| ROL32(x & 0x08048040, 16)
		| ROL32(x & 0x24080010, 20)
		| ROL32(x & 0x10020120, 24)
		| ((x & 0x80410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 9, 6, 3, 4, 1, 10, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_332(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x04081020) << 4)
		| ROL32(x & 0x20100201, 8)
		| ROL32(x & 0x01028040, 12)
		| ROL32(x & 0x40800408, 16)
		| ROL32(x & 0x08042010, 20)
		| ROL32(x & 0x10200102, 24)
		| ((x & 0x02014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_332(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x00201408) << 4)
		| ROL32(x & 0x02102001, 8)
		| ROL32(x & 0x01008042, 12)
		| ROL32(x & 0x04084080, 16)
		| ROL32(x & 0x28040010, 20)
		| ROL32(x & 0x10020120, 24)
		| ((x & 0x40810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 13, 6, 3, 4, 1, 10, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_333(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04041020) << 4)
		| ROL32(x & 0x20100201, 8)
		| ROL32(x & 0x01028080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08082010, 20)
		| ROL32(x & 0x10200102, 24)
		| ((x & 0x02014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_333(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00201404) << 4)
		| ROL32(x & 0x02102001, 8)
		| ROL32(x & 0x01008082, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x28080010, 20)
		| ROL32(x & 0x10020120, 24)
		| ((x & 0x40410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 2, 1, 0), (0, 1, 2, 3), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 5, 10, 3, 0, 9, 6, 15, 8, 13, 2, 7]
void BOGI32_omega_diffusion_334(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x08081040) << 4)
		| ROL32(x & 0x20100401, 8)
		| ROL32(x & 0x01024020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02042010, 20)
		| ROL32(x & 0x10400102, 24)
		| ((x & 0x04018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_334(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x00401808) << 4)
		| ROL32(x & 0x02104001, 8)
		| ROL32(x & 0x01002042, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x24020010, 20)
		| ROL32(x & 0x10040120, 24)
		| ((x & 0x80810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 0, 3, 1), (3, 2, 1, 0), (1, 3, 0, 2), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 13, 10, 3, 8, 1, 6, 15, 12, 9, 2, 7]
void BOGI32_omega_diffusion_335(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x04041080) << 4)
		| ROL32(x & 0x20100801, 8)
		| ROL32(x & 0x01028020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02082010, 20)
		| ROL32(x & 0x10800102, 24)
		| ((x & 0x08014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_335(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x00801404) << 4)
		| ROL32(x & 0x02108001, 8)
		| ROL32(x & 0x01002082, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x28020010, 20)
		| ROL32(x & 0x10080120, 24)
		| ((x & 0x40410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 2, 3, 1), (1, 3, 2, 0), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 13, 10, 7, 4, 9, 14, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_336(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200801)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40100102, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x10800404, 16)
		| ROL32(x & 0x08014010, 20)
		| ROL32(x & 0x80400208, 24)
		| ((x & 0x01021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_336(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200801)
		| ((x & 0x00102108) << 4)
		| ROL32(x & 0x08804002, 8)
		| ROL32(x & 0x01008014, 12)
		| ROL32(x & 0x04041080, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x10010240, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 2, 3, 1), (3, 0, 1, 2), (1, 3, 2, 0))
//[4, 13, 2, 11, 12, 1, 10, 7, 8, 5, 14, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_337(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200401)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80100102, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x10400808, 16)
		| ROL32(x & 0x04018010, 20)
		| ROL32(x & 0x40800204, 24)
		| ((x & 0x01021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_337(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200401)
		| ((x & 0x00102104) << 4)
		| ROL32(x & 0x04408002, 8)
		| ROL32(x & 0x01004018, 12)
		| ROL32(x & 0x08081040, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x10010280, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 1, 2), (1, 2, 3, 0), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 9, 14, 7, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_338(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400201)
		| ((x & 0x04028080) << 4)
		| ROL32(x & 0x40100104, 8)
		| ROL32(x & 0x08082040, 12)
		| ROL32(x & 0x10200402, 16)
		| ROL32(x & 0x02014010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_338(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400201)
		| ((x & 0x00104102) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01002014, 12)
		| ROL32(x & 0x04021020, 16)
		| ROL32(x & 0x82040080, 20)
		| ROL32(x & 0x10010440, 24)
		| ((x & 0x40280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 1, 14, 7, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_339(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800201)
		| ((x & 0x08024040) << 4)
		| ROL32(x & 0x80100108, 8)
		| ROL32(x & 0x04042080, 12)
		| ROL32(x & 0x10200802, 16)
		| ROL32(x & 0x02018010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_339(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800201)
		| ((x & 0x00108102) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01002018, 12)
		| ROL32(x & 0x08021020, 16)
		| ROL32(x & 0x42080040, 20)
		| ROL32(x & 0x10010880, 24)
		| ((x & 0x80240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 1, 14, 7, 4, 13, 10, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_340(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800801)
		| ((x & 0x04024020) << 4)
		| ROL32(x & 0x80100104, 8)
		| ROL32(x & 0x02082080, 12)
		| ROL32(x & 0x10400402, 16)
		| ROL32(x & 0x08018010, 20)
		| ROL32(x & 0x40200208, 24)
		| ((x & 0x01041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_340(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800801)
		| ((x & 0x00104104) << 4)
		| ROL32(x & 0x08402002, 8)
		| ROL32(x & 0x01008018, 12)
		| ROL32(x & 0x04021040, 16)
		| ROL32(x & 0x82080020, 20)
		| ROL32(x & 0x10010480, 24)
		| ((x & 0x40240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 9, 14, 7, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_341(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400801)
		| ((x & 0x04028020) << 4)
		| ROL32(x & 0x40100104, 8)
		| ROL32(x & 0x02082040, 12)
		| ROL32(x & 0x10800402, 16)
		| ROL32(x & 0x08014010, 20)
		| ROL32(x & 0x80200208, 24)
		| ((x & 0x01041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_341(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400801)
		| ((x & 0x00104108) << 4)
		| ROL32(x & 0x08802002, 8)
		| ROL32(x & 0x01008014, 12)
		| ROL32(x & 0x04021080, 16)
		| ROL32(x & 0x82040020, 20)
		| ROL32(x & 0x10010440, 24)
		| ((x & 0x40280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 1, 14, 7, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_342(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800401)
		| ((x & 0x08024020) << 4)
		| ROL32(x & 0x80100108, 8)
		| ROL32(x & 0x02042080, 12)
		| ROL32(x & 0x10400802, 16)
		| ROL32(x & 0x04018010, 20)
		| ROL32(x & 0x40200204, 24)
		| ((x & 0x01081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_342(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800401)
		| ((x & 0x00108104) << 4)
		| ROL32(x & 0x04402002, 8)
		| ROL32(x & 0x01004018, 12)
		| ROL32(x & 0x08021040, 16)
		| ROL32(x & 0x42080020, 20)
		| ROL32(x & 0x10010880, 24)
		| ((x & 0x80240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (0, 3, 2, 1), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 9, 14, 7, 12, 5, 10, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_343(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400401)
		| ((x & 0x08028020) << 4)
		| ROL32(x & 0x40100108, 8)
		| ROL32(x & 0x02042040, 12)
		| ROL32(x & 0x10800802, 16)
		| ROL32(x & 0x04014010, 20)
		| ROL32(x & 0x80200204, 24)
		| ((x & 0x01081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_343(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400401)
		| ((x & 0x00108108) << 4)
		| ROL32(x & 0x04802002, 8)
		| ROL32(x & 0x01004014, 12)
		| ROL32(x & 0x08021080, 16)
		| ROL32(x & 0x42040020, 20)
		| ROL32(x & 0x10010840, 24)
		| ((x & 0x80280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 0, 3, 2), (0, 3, 2, 1), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 13, 2, 7, 4, 9, 14, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_344(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800801)
		| ((x & 0x02042040) << 4)
		| ROL32(x & 0x80100102, 8)
		| ROL32(x & 0x04084080, 12)
		| ROL32(x & 0x10200204, 16)
		| ROL32(x & 0x08018010, 20)
		| ROL32(x & 0x20400408, 24)
		| ((x & 0x01021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_344(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800801)
		| ((x & 0x00102102) << 4)
		| ROL32(x & 0x08204004, 8)
		| ROL32(x & 0x01008018, 12)
		| ROL32(x & 0x02041020, 16)
		| ROL32(x & 0x84080040, 20)
		| ROL32(x & 0x10010280, 24)
		| ((x & 0x20420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 0, 3, 2), (3, 2, 1, 0), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 9, 2, 7, 8, 5, 14, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_345(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400401)
		| ((x & 0x02082080) << 4)
		| ROL32(x & 0x40100102, 8)
		| ROL32(x & 0x08048040, 12)
		| ROL32(x & 0x10200208, 16)
		| ROL32(x & 0x04014010, 20)
		| ROL32(x & 0x20800804, 24)
		| ((x & 0x01021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_345(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400401)
		| ((x & 0x00102102) << 4)
		| ROL32(x & 0x04208008, 8)
		| ROL32(x & 0x01004014, 12)
		| ROL32(x & 0x02081020, 16)
		| ROL32(x & 0x48040080, 20)
		| ROL32(x & 0x10010240, 24)
		| ((x & 0x20820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_346(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200401)
		| ((x & 0x02048080) << 4)
		| ROL32(x & 0x20100102, 8)
		| ROL32(x & 0x08084020, 12)
		| ROL32(x & 0x10400204, 16)
		| ROL32(x & 0x04012010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_346(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200401)
		| ((x & 0x00102104) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01004012, 12)
		| ROL32(x & 0x02041040, 16)
		| ROL32(x & 0x84020080, 20)
		| ROL32(x & 0x10010220, 24)
		| ((x & 0x20480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_347(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200801)
		| ((x & 0x02048040) << 4)
		| ROL32(x & 0x20100102, 8)
		| ROL32(x & 0x04084020, 12)
		| ROL32(x & 0x10800204, 16)
		| ROL32(x & 0x08012010, 20)
		| ROL32(x & 0x80400408, 24)
		| ((x & 0x01021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_347(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200801)
		| ((x & 0x00102108) << 4)
		| ROL32(x & 0x08804004, 8)
		| ROL32(x & 0x01008012, 12)
		| ROL32(x & 0x02041080, 16)
		| ROL32(x & 0x84020040, 20)
		| ROL32(x & 0x10010220, 24)
		| ((x & 0x20480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 14, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_348(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200401)
		| ((x & 0x02084080) << 4)
		| ROL32(x & 0x20100102, 8)
		| ROL32(x & 0x08048020, 12)
		| ROL32(x & 0x10400208, 16)
		| ROL32(x & 0x04012010, 20)
		| ROL32(x & 0x40800804, 24)
		| ((x & 0x01021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_348(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200401)
		| ((x & 0x00102104) << 4)
		| ROL32(x & 0x04408008, 8)
		| ROL32(x & 0x01004012, 12)
		| ROL32(x & 0x02081040, 16)
		| ROL32(x & 0x48020080, 20)
		| ROL32(x & 0x10010220, 24)
		| ((x & 0x20840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 2, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 14, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_349(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200801)
		| ((x & 0x02084040) << 4)
		| ROL32(x & 0x20100102, 8)
		| ROL32(x & 0x04048020, 12)
		| ROL32(x & 0x10800208, 16)
		| ROL32(x & 0x08012010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_349(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200801)
		| ((x & 0x00102108) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01008012, 12)
		| ROL32(x & 0x02081080, 16)
		| ROL32(x & 0x48020040, 20)
		| ROL32(x & 0x10010220, 24)
		| ((x & 0x20840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 3, 2, 0), (0, 2, 3, 1), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 9, 14, 7, 4, 13, 10, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_350(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400801)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20100104, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x10800202, 16)
		| ROL32(x & 0x08012010, 20)
		| ROL32(x & 0x80200408, 24)
		| ((x & 0x01041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_350(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400801)
		| ((x & 0x00104108) << 4)
		| ROL32(x & 0x08802004, 8)
		| ROL32(x & 0x01008012, 12)
		| ROL32(x & 0x02021080, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x10010420, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (1, 3, 2, 0), (3, 0, 1, 2), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 1, 14, 7, 12, 5, 10, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_351(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800401)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20100108, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x10400202, 16)
		| ROL32(x & 0x04012010, 20)
		| ROL32(x & 0x40200804, 24)
		| ((x & 0x01081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_351(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800401)
		| ((x & 0x00108104) << 4)
		| ROL32(x & 0x04402008, 8)
		| ROL32(x & 0x01004012, 12)
		| ROL32(x & 0x02021040, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x10010820, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_352(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400201)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80100104, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x10200808, 16)
		| ROL32(x & 0x02018010, 20)
		| ROL32(x & 0x20800402, 24)
		| ((x & 0x01041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_352(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400201)
		| ((x & 0x00104102) << 4)
		| ROL32(x & 0x02208004, 8)
		| ROL32(x & 0x01002018, 12)
		| ROL32(x & 0x08081020, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x10010480, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 10, 15]
void BOGI32_omega_diffusion_353(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800201)
		| ((x & 0x08042040) << 4)
		| ROL32(x & 0x80100108, 8)
		| ROL32(x & 0x04024080, 12)
		| ROL32(x & 0x10200804, 16)
		| ROL32(x & 0x02018010, 20)
		| ROL32(x & 0x20400402, 24)
		| ((x & 0x01081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_353(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800201)
		| ((x & 0x00108102) << 4)
		| ROL32(x & 0x02204004, 8)
		| ROL32(x & 0x01002018, 12)
		| ROL32(x & 0x08041020, 16)
		| ROL32(x & 0x24080040, 20)
		| ROL32(x & 0x10010880, 24)
		| ((x & 0x80420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_354(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400201)
		| ((x & 0x04082080) << 4)
		| ROL32(x & 0x40100104, 8)
		| ROL32(x & 0x08028040, 12)
		| ROL32(x & 0x10200408, 16)
		| ROL32(x & 0x02014010, 20)
		| ROL32(x & 0x20800802, 24)
		| ((x & 0x01041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_354(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400201)
		| ((x & 0x00104102) << 4)
		| ROL32(x & 0x02208008, 8)
		| ROL32(x & 0x01002014, 12)
		| ROL32(x & 0x04081020, 16)
		| ROL32(x & 0x28040080, 20)
		| ROL32(x & 0x10010440, 24)
		| ((x & 0x40820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 1, 2), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 10, 15]
void BOGI32_omega_diffusion_355(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800201)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40100108, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x10200404, 16)
		| ROL32(x & 0x02014010, 20)
		| ROL32(x & 0x20400802, 24)
		| ((x & 0x01081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_355(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800201)
		| ((x & 0x00108102) << 4)
		| ROL32(x & 0x02204008, 8)
		| ROL32(x & 0x01002014, 12)
		| ROL32(x & 0x04041020, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x10010840, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 13, 2, 7, 12, 5, 10, 3, 0, 9, 6, 15]
void BOGI32_omega_diffusion_356(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800401)
		| ((x & 0x08042020) << 4)
		| ROL32(x & 0x80100108, 8)
		| ROL32(x & 0x02024080, 12)
		| ROL32(x & 0x10400804, 16)
		| ROL32(x & 0x04018010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_356(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800401)
		| ((x & 0x00108104) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01004018, 12)
		| ROL32(x & 0x08041040, 16)
		| ROL32(x & 0x24080020, 20)
		| ROL32(x & 0x10010880, 24)
		| ((x & 0x80420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 0, 2, 1), (1, 2, 3, 0), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 9, 2, 7, 4, 13, 10, 3, 8, 1, 6, 15]
void BOGI32_omega_diffusion_357(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400801)
		| ((x & 0x04082020) << 4)
		| ROL32(x & 0x40100104, 8)
		| ROL32(x & 0x02028040, 12)
		| ROL32(x & 0x10800408, 16)
		| ROL32(x & 0x08014010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_357(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400801)
		| ((x & 0x00104108) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01008014, 12)
		| ROL32(x & 0x04081080, 16)
		| ROL32(x & 0x28040020, 20)
		| ROL32(x & 0x10010440, 24)
		| ((x & 0x40820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 2, 1, 0), (0, 3, 2, 1), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 13, 10, 7, 12, 9, 6, 3, 8, 5, 2, 15]
void BOGI32_omega_diffusion_358(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200201)
		| ((x & 0x08048040) << 4)
		| ROL32(x & 0x20100108, 8)
		| ROL32(x & 0x04024020, 12)
		| ROL32(x & 0x10800804, 16)
		| ROL32(x & 0x02012010, 20)
		| ROL32(x & 0x80400402, 24)
		| ((x & 0x01081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_358(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200201)
		| ((x & 0x00108108) << 4)
		| ROL32(x & 0x02804004, 8)
		| ROL32(x & 0x01002012, 12)
		| ROL32(x & 0x08041080, 16)
		| ROL32(x & 0x24020040, 20)
		| ROL32(x & 0x10010820, 24)
		| ((x & 0x80480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 0, 3), (3, 2, 1, 0), (1, 0, 3, 2), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 1, 10, 7, 8, 13, 6, 3, 4, 9, 2, 15]
void BOGI32_omega_diffusion_359(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200201)
		| ((x & 0x04084080) << 4)
		| ROL32(x & 0x20100104, 8)
		| ROL32(x & 0x08028020, 12)
		| ROL32(x & 0x10400408, 16)
		| ROL32(x & 0x02012010, 20)
		| ROL32(x & 0x40800802, 24)
		| ((x & 0x01041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_359(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200201)
		| ((x & 0x00104104) << 4)
		| ROL32(x & 0x02408008, 8)
		| ROL32(x & 0x01002012, 12)
		| ROL32(x & 0x04081040, 16)
		| ROL32(x & 0x28020080, 20)
		| ROL32(x & 0x10010420, 24)
		| ((x & 0x40840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 2, 1, 3), (1, 3, 0, 2), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 13, 10, 7, 8, 1, 6, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_360(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04048080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08082020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02021010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_360(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00101404) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01002021, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x82020080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 2, 1, 3), (3, 0, 2, 1), (1, 3, 0, 2))
//[4, 13, 2, 11, 12, 1, 10, 7, 0, 9, 6, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_361(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08084040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04042020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02021010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_361(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00101808) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01002021, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x42020040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_362(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800204)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80200402, 16)
		| ROL32(x & 0x02041010, 20)
		| ROL32(x & 0x40400808, 24)
		| ((x & 0x01018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_362(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800204)
		| ((x & 0x00101802) << 4)
		| ROL32(x & 0x08404008, 8)
		| ROL32(x & 0x01002041, 12)
		| ROL32(x & 0x04028020, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_363(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x04028080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08082040, 12)
		| ROL32(x & 0x40200402, 16)
		| ROL32(x & 0x02041010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_363(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x00101402) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01002041, 12)
		| ROL32(x & 0x04024020, 16)
		| ROL32(x & 0x82040080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 1, 14, 7, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_364(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x08024040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04042080, 12)
		| ROL32(x & 0x80200802, 16)
		| ROL32(x & 0x02081010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_364(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x00101802) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01002081, 12)
		| ROL32(x & 0x08028020, 16)
		| ROL32(x & 0x42080040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 1, 2), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 9, 14, 7, 8, 1, 6, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_365(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400208)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40200802, 16)
		| ROL32(x & 0x02081010, 20)
		| ROL32(x & 0x80800404, 24)
		| ((x & 0x01014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_365(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400208)
		| ((x & 0x00101402) << 4)
		| ROL32(x & 0x04808004, 8)
		| ROL32(x & 0x01002081, 12)
		| ROL32(x & 0x08024020, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 2, 1), (1, 2, 0, 3), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 9, 14, 7, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_366(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400804)
		| ((x & 0x04028020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02082040, 12)
		| ROL32(x & 0x40800402, 16)
		| ROL32(x & 0x08041010, 20)
		| ROL32(x & 0x80200208, 24)
		| ((x & 0x01014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_366(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400804)
		| ((x & 0x00101408) << 4)
		| ROL32(x & 0x08802002, 8)
		| ROL32(x & 0x01008041, 12)
		| ROL32(x & 0x04024080, 16)
		| ROL32(x & 0x82040020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (0, 3, 2, 1), (3, 0, 1, 2), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 1, 14, 7, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_367(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800408)
		| ((x & 0x08024020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02042080, 12)
		| ROL32(x & 0x80400802, 16)
		| ROL32(x & 0x04081010, 20)
		| ROL32(x & 0x40200204, 24)
		| ((x & 0x01018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_367(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800408)
		| ((x & 0x00101804) << 4)
		| ROL32(x & 0x04402002, 8)
		| ROL32(x & 0x01004081, 12)
		| ROL32(x & 0x08028040, 16)
		| ROL32(x & 0x42080020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 0, 2, 3), (0, 3, 1, 2), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 13, 2, 7, 0, 5, 10, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_368(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800402)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80400204, 16)
		| ROL32(x & 0x04021010, 20)
		| ROL32(x & 0x20200808, 24)
		| ((x & 0x01018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_368(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800402)
		| ((x & 0x00101804) << 4)
		| ROL32(x & 0x08202008, 8)
		| ROL32(x & 0x01004021, 12)
		| ROL32(x & 0x02048040, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 0, 2, 3), (3, 2, 0, 1), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 9, 2, 7, 4, 1, 10, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_369(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400802)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40800208, 16)
		| ROL32(x & 0x08021010, 20)
		| ROL32(x & 0x20200404, 24)
		| ((x & 0x01014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_369(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400802)
		| ((x & 0x00101408) << 4)
		| ROL32(x & 0x04202004, 8)
		| ROL32(x & 0x01008021, 12)
		| ROL32(x & 0x02084080, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 1, 2), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_370(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x02048080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08084020, 12)
		| ROL32(x & 0x20400204, 16)
		| ROL32(x & 0x04021010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_370(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x00101204) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01004021, 12)
		| ROL32(x & 0x02042040, 16)
		| ROL32(x & 0x84020080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 2, 1), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_371(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200802)
		| ((x & 0x02048040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04084020, 12)
		| ROL32(x & 0x20800204, 16)
		| ROL32(x & 0x08021010, 20)
		| ROL32(x & 0x80400408, 24)
		| ((x & 0x01012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_371(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200802)
		| ((x & 0x00101208) << 4)
		| ROL32(x & 0x08804004, 8)
		| ROL32(x & 0x01008021, 12)
		| ROL32(x & 0x02042080, 16)
		| ROL32(x & 0x84020040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 1, 2), (0, 3, 2, 1))
//[0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 2, 15, 4, 9, 14, 3]
void BOGI32_omega_diffusion_372(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200402)
		| ((x & 0x02084080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08048020, 12)
		| ROL32(x & 0x20400208, 16)
		| ROL32(x & 0x04021010, 20)
		| ROL32(x & 0x40800804, 24)
		| ((x & 0x01012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_372(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200402)
		| ((x & 0x00101204) << 4)
		| ROL32(x & 0x04408008, 8)
		| ROL32(x & 0x01004021, 12)
		| ROL32(x & 0x02082040, 16)
		| ROL32(x & 0x48020080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 2, 0, 3), (3, 0, 2, 1), (0, 3, 1, 2))
//[0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 2, 15, 8, 5, 14, 3]
void BOGI32_omega_diffusion_373(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x02084040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04048020, 12)
		| ROL32(x & 0x20800208, 16)
		| ROL32(x & 0x08021010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_373(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x00101208) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01008021, 12)
		| ROL32(x & 0x02082080, 16)
		| ROL32(x & 0x48020040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 3, 0, 2), (0, 2, 1, 3), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 9, 14, 7, 8, 5, 2, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_374(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02028080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08084040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04041010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x01012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_374(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00101202) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01004041, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x84040080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (1, 3, 0, 2), (3, 0, 2, 1), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 1, 14, 7, 4, 9, 2, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_375(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02024040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04048080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08081010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x01012020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_375(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00101202) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01008081, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x48080040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x20240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 13, 2, 7, 0, 9, 6, 15, 12, 5, 10, 3]
void BOGI32_omega_diffusion_376(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800208)
		| ((x & 0x08042040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x04024080, 12)
		| ROL32(x & 0x80200804, 16)
		| ROL32(x & 0x02081010, 20)
		| ROL32(x & 0x20400402, 24)
		| ((x & 0x01018020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_376(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800208)
		| ((x & 0x00101802) << 4)
		| ROL32(x & 0x02204004, 8)
		| ROL32(x & 0x01002081, 12)
		| ROL32(x & 0x08048020, 16)
		| ROL32(x & 0x24080040, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 1, 2), (1, 2, 0, 3), (0, 3, 2, 1))
//[0, 5, 14, 11, 12, 9, 2, 7, 8, 1, 6, 15, 4, 13, 10, 3]
void BOGI32_omega_diffusion_377(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400204)
		| ((x & 0x04082080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x08028040, 12)
		| ROL32(x & 0x40200408, 16)
		| ROL32(x & 0x02041010, 20)
		| ROL32(x & 0x20800802, 24)
		| ((x & 0x01014020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_377(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400204)
		| ((x & 0x00101402) << 4)
		| ROL32(x & 0x02208008, 8)
		| ROL32(x & 0x01002041, 12)
		| ROL32(x & 0x04084020, 16)
		| ROL32(x & 0x28040080, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 14, 11, 12, 9, 2, 7, 0, 5, 10, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_378(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08082020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02024040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04041010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01018080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_378(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00101808) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01004041, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x24040020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 13, 2, 7, 0, 5, 10, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_379(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x08042020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02024080, 12)
		| ROL32(x & 0x80400804, 16)
		| ROL32(x & 0x04081010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01018040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_379(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x00101804) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01004081, 12)
		| ROL32(x & 0x08048040, 16)
		| ROL32(x & 0x24080020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 9, 2, 7, 4, 1, 10, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_380(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x04082020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02028040, 12)
		| ROL32(x & 0x40800408, 16)
		| ROL32(x & 0x08041010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01014080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_380(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x00101408) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01008041, 12)
		| ROL32(x & 0x04084080, 16)
		| ROL32(x & 0x28040020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 0, 2, 1), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 13, 2, 7, 4, 1, 10, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_381(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04042020) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02028080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08081010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x01014040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_381(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00101404) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01008081, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x28080020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 2, 0, 1), (0, 3, 1, 2), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 13, 10, 7, 8, 5, 2, 15, 12, 9, 6, 3]
void BOGI32_omega_diffusion_382(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200408)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20400804, 16)
		| ROL32(x & 0x04081010, 20)
		| ROL32(x & 0x80800202, 24)
		| ((x & 0x01012040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_382(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200408)
		| ((x & 0x00101204) << 4)
		| ROL32(x & 0x02808002, 8)
		| ROL32(x & 0x01004081, 12)
		| ROL32(x & 0x08042040, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 1, 3, 0), (3, 2, 0, 1), (1, 0, 2, 3), (0, 3, 1, 2))
//[0, 5, 14, 11, 12, 1, 10, 7, 4, 9, 2, 15, 8, 13, 6, 3]
void BOGI32_omega_diffusion_383(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200804)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x10100101, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20800408, 16)
		| ROL32(x & 0x08041010, 20)
		| ROL32(x & 0x40400202, 24)
		| ((x & 0x01012080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_383(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200804)
		| ((x & 0x00101208) << 4)
		| ROL32(x & 0x02404002, 8)
		| ROL32(x & 0x01008041, 12)
		| ROL32(x & 0x04082080, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x10010110, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 1, 6, 15, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_384(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x04014020) << 4)
		| ROL32(x & 0x80100204, 8)
		| ROL32(x & 0x01082080, 12)
		| ROL32(x & 0x10400401, 16)
		| ROL32(x & 0x08028010, 20)
		| ROL32(x & 0x40200108, 24)
		| ((x & 0x02041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_384(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800802)
		| ((x & 0x00204104) << 4)
		| ROL32(x & 0x08402001, 8)
		| ROL32(x & 0x01008028, 12)
		| ROL32(x & 0x04011040, 16)
		| ROL32(x & 0x82080010, 20)
		| ROL32(x & 0x10020480, 24)
		| ((x & 0x40140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (1, 2, 3, 0), (3, 0, 1, 2))
//[12, 5, 2, 11, 0, 9, 6, 15, 4, 13, 10, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_385(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400802)
		| ((x & 0x04018020) << 4)
		| ROL32(x & 0x40100204, 8)
		| ROL32(x & 0x01082040, 12)
		| ROL32(x & 0x10800401, 16)
		| ROL32(x & 0x08024010, 20)
		| ROL32(x & 0x80200108, 24)
		| ((x & 0x02041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_385(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400802)
		| ((x & 0x00204108) << 4)
		| ROL32(x & 0x08802001, 8)
		| ROL32(x & 0x01008024, 12)
		| ROL32(x & 0x04011080, 16)
		| ROL32(x & 0x82040010, 20)
		| ROL32(x & 0x10020440, 24)
		| ((x & 0x40180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (3, 0, 1, 2), (1, 2, 3, 0))
//[4, 13, 2, 11, 8, 1, 6, 15, 12, 5, 10, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_386(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800402)
		| ((x & 0x08014020) << 4)
		| ROL32(x & 0x80100208, 8)
		| ROL32(x & 0x01042080, 12)
		| ROL32(x & 0x10400801, 16)
		| ROL32(x & 0x04028010, 20)
		| ROL32(x & 0x40200104, 24)
		| ((x & 0x02081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_386(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800402)
		| ((x & 0x00208104) << 4)
		| ROL32(x & 0x04402001, 8)
		| ROL32(x & 0x01004028, 12)
		| ROL32(x & 0x08011040, 16)
		| ROL32(x & 0x42080010, 20)
		| ROL32(x & 0x10020880, 24)
		| ((x & 0x80140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 2, 3), (3, 2, 1, 0), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 9, 6, 15, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_387(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x08018020) << 4)
		| ROL32(x & 0x40100208, 8)
		| ROL32(x & 0x01042040, 12)
		| ROL32(x & 0x10800801, 16)
		| ROL32(x & 0x04024010, 20)
		| ROL32(x & 0x80200104, 24)
		| ((x & 0x02081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_387(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400402)
		| ((x & 0x00208108) << 4)
		| ROL32(x & 0x04802001, 8)
		| ROL32(x & 0x01004024, 12)
		| ROL32(x & 0x08011080, 16)
		| ROL32(x & 0x42040010, 20)
		| ROL32(x & 0x10020840, 24)
		| ((x & 0x80180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 1, 0))
//[12, 5, 2, 11, 8, 1, 6, 15, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_388(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800804)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x80100202, 8)
		| ROL32(x & 0x01082080, 12)
		| ROL32(x & 0x10200401, 16)
		| ROL32(x & 0x08048010, 20)
		| ROL32(x & 0x40400108, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_388(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800804)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x08404001, 8)
		| ROL32(x & 0x01008048, 12)
		| ROL32(x & 0x04011020, 16)
		| ROL32(x & 0x82080010, 20)
		| ROL32(x & 0x10020280, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 1, 3, 2), (3, 2, 1, 0), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 9, 6, 15, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_389(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400408)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x40100202, 8)
		| ROL32(x & 0x01042040, 12)
		| ROL32(x & 0x10200801, 16)
		| ROL32(x & 0x04084010, 20)
		| ROL32(x & 0x80800104, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_389(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400408)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x04808001, 8)
		| ROL32(x & 0x01004084, 12)
		| ROL32(x & 0x08011020, 16)
		| ROL32(x & 0x42040010, 20)
		| ROL32(x & 0x10020240, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 2, 1, 3), (1, 0, 3, 2), (3, 1, 2, 0))
//[12, 5, 2, 11, 4, 1, 10, 15, 8, 13, 6, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_390(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04014080) << 4)
		| ROL32(x & 0x80100804, 8)
		| ROL32(x & 0x01082020, 12)
		| ROL32(x & 0x10400401, 16)
		| ROL32(x & 0x02028010, 20)
		| ROL32(x & 0x40800108, 24)
		| ((x & 0x08041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_390(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00804104) << 4)
		| ROL32(x & 0x08408001, 8)
		| ROL32(x & 0x01002028, 12)
		| ROL32(x & 0x04011040, 16)
		| ROL32(x & 0x82020010, 20)
		| ROL32(x & 0x10080480, 24)
		| ((x & 0x40140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (0, 2, 1, 3), (3, 1, 2, 0), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 5, 10, 15, 12, 9, 6, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_391(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08018040) << 4)
		| ROL32(x & 0x40100408, 8)
		| ROL32(x & 0x01042020, 12)
		| ROL32(x & 0x10800801, 16)
		| ROL32(x & 0x02024010, 20)
		| ROL32(x & 0x80400104, 24)
		| ((x & 0x04081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_391(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00408108) << 4)
		| ROL32(x & 0x04804001, 8)
		| ROL32(x & 0x01002024, 12)
		| ROL32(x & 0x08011080, 16)
		| ROL32(x & 0x42020010, 20)
		| ROL32(x & 0x10040840, 24)
		| ((x & 0x80180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 5, 2, 15, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_392(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800802)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x80100404, 8)
		| ROL32(x & 0x01084080, 12)
		| ROL32(x & 0x10400201, 16)
		| ROL32(x & 0x08028010, 20)
		| ROL32(x & 0x20200108, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_392(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800802)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x08202001, 8)
		| ROL32(x & 0x01008028, 12)
		| ROL32(x & 0x02011040, 16)
		| ROL32(x & 0x84080010, 20)
		| ROL32(x & 0x10040480, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 2, 3), (3, 2, 1, 0), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 9, 2, 15, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_393(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400402)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x40100808, 8)
		| ROL32(x & 0x01048040, 12)
		| ROL32(x & 0x10800201, 16)
		| ROL32(x & 0x04024010, 20)
		| ROL32(x & 0x20200104, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_393(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400402)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x04202001, 8)
		| ROL32(x & 0x01004024, 12)
		| ROL32(x & 0x02011080, 16)
		| ROL32(x & 0x48040010, 20)
		| ROL32(x & 0x10080840, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 1, 0))
//[12, 1, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_394(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x02012040) << 4)
		| ROL32(x & 0x80100402, 8)
		| ROL32(x & 0x01084080, 12)
		| ROL32(x & 0x10200201, 16)
		| ROL32(x & 0x08048010, 20)
		| ROL32(x & 0x20400108, 24)
		| ((x & 0x04021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_394(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800804)
		| ((x & 0x00402102) << 4)
		| ROL32(x & 0x08204001, 8)
		| ROL32(x & 0x01008048, 12)
		| ROL32(x & 0x02011020, 16)
		| ROL32(x & 0x84080010, 20)
		| ROL32(x & 0x10040280, 24)
		| ((x & 0x20120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (0, 2, 1, 3), (3, 1, 2, 0))
//[12, 1, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_395(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02012080) << 4)
		| ROL32(x & 0x80100802, 8)
		| ROL32(x & 0x01084040, 12)
		| ROL32(x & 0x10200201, 16)
		| ROL32(x & 0x04048010, 20)
		| ROL32(x & 0x20800108, 24)
		| ((x & 0x08021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_395(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00802102) << 4)
		| ROL32(x & 0x08208001, 8)
		| ROL32(x & 0x01004048, 12)
		| ROL32(x & 0x02011020, 16)
		| ROL32(x & 0x84040010, 20)
		| ROL32(x & 0x10080280, 24)
		| ((x & 0x20120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (3, 1, 2, 0), (0, 2, 1, 3))
//[0, 13, 6, 11, 8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_396(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02012040) << 4)
		| ROL32(x & 0x40100402, 8)
		| ROL32(x & 0x01048080, 12)
		| ROL32(x & 0x10200201, 16)
		| ROL32(x & 0x08084010, 20)
		| ROL32(x & 0x20400104, 24)
		| ((x & 0x04021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_396(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00402102) << 4)
		| ROL32(x & 0x04204001, 8)
		| ROL32(x & 0x01008084, 12)
		| ROL32(x & 0x02011020, 16)
		| ROL32(x & 0x48080010, 20)
		| ROL32(x & 0x10040240, 24)
		| ((x & 0x20120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 0, 3, 2), (3, 2, 1, 0), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_397(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x02012080) << 4)
		| ROL32(x & 0x40100802, 8)
		| ROL32(x & 0x01048040, 12)
		| ROL32(x & 0x10200201, 16)
		| ROL32(x & 0x04084010, 20)
		| ROL32(x & 0x20800104, 24)
		| ((x & 0x08021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_397(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400408)
		| ((x & 0x00802102) << 4)
		| ROL32(x & 0x04208001, 8)
		| ROL32(x & 0x01004084, 12)
		| ROL32(x & 0x02011020, 16)
		| ROL32(x & 0x48040010, 20)
		| ROL32(x & 0x10080240, 24)
		| ((x & 0x20120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 2, 3, 0), (0, 1, 2, 3), (3, 0, 1, 2))
//[12, 1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_398(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200804)
		| ((x & 0x02018040) << 4)
		| ROL32(x & 0x20100402, 8)
		| ROL32(x & 0x01084020, 12)
		| ROL32(x & 0x10800201, 16)
		| ROL32(x & 0x08042010, 20)
		| ROL32(x & 0x80400108, 24)
		| ((x & 0x04021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_398(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200804)
		| ((x & 0x00402108) << 4)
		| ROL32(x & 0x08804001, 8)
		| ROL32(x & 0x01008042, 12)
		| ROL32(x & 0x02011080, 16)
		| ROL32(x & 0x84020010, 20)
		| ROL32(x & 0x10040220, 24)
		| ((x & 0x20180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (1, 2, 3, 0), (3, 0, 1, 2), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 1, 10, 15, 8, 5, 14, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_399(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200408)
		| ((x & 0x02014080) << 4)
		| ROL32(x & 0x20100802, 8)
		| ROL32(x & 0x01048020, 12)
		| ROL32(x & 0x10400201, 16)
		| ROL32(x & 0x04082010, 20)
		| ROL32(x & 0x40800104, 24)
		| ((x & 0x08021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_399(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200408)
		| ((x & 0x00802104) << 4)
		| ROL32(x & 0x04408001, 8)
		| ROL32(x & 0x01004082, 12)
		| ROL32(x & 0x02011040, 16)
		| ROL32(x & 0x48020010, 20)
		| ROL32(x & 0x10080220, 24)
		| ((x & 0x20140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 0, 1, 2), (0, 1, 2, 3), (1, 2, 3, 0))
//[4, 1, 14, 11, 8, 5, 2, 15, 12, 9, 6, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_400(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800204)
		| ((x & 0x08012040) << 4)
		| ROL32(x & 0x80100408, 8)
		| ROL32(x & 0x01024080, 12)
		| ROL32(x & 0x10200801, 16)
		| ROL32(x & 0x02048010, 20)
		| ROL32(x & 0x20400102, 24)
		| ((x & 0x04081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_400(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800204)
		| ((x & 0x00408102) << 4)
		| ROL32(x & 0x02204001, 8)
		| ROL32(x & 0x01002048, 12)
		| ROL32(x & 0x08011020, 16)
		| ROL32(x & 0x24080010, 20)
		| ROL32(x & 0x10040880, 24)
		| ((x & 0x80120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 0, 1, 2), (1, 2, 3, 0), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 9, 2, 15, 8, 13, 6, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_401(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400208)
		| ((x & 0x04012080) << 4)
		| ROL32(x & 0x40100804, 8)
		| ROL32(x & 0x01028040, 12)
		| ROL32(x & 0x10200401, 16)
		| ROL32(x & 0x02084010, 20)
		| ROL32(x & 0x20800102, 24)
		| ((x & 0x08041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_401(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400208)
		| ((x & 0x00804102) << 4)
		| ROL32(x & 0x02208001, 8)
		| ROL32(x & 0x01002084, 12)
		| ROL32(x & 0x04011020, 16)
		| ROL32(x & 0x28040010, 20)
		| ROL32(x & 0x10080440, 24)
		| ((x & 0x40120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 1, 2, 0), (0, 2, 1, 3), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 9, 6, 15, 12, 5, 10, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_402(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08018020) << 4)
		| ROL32(x & 0x20100208, 8)
		| ROL32(x & 0x01024040, 12)
		| ROL32(x & 0x10800801, 16)
		| ROL32(x & 0x04042010, 20)
		| ROL32(x & 0x80200102, 24)
		| ((x & 0x02081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_402(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00208108) << 4)
		| ROL32(x & 0x02802001, 8)
		| ROL32(x & 0x01004042, 12)
		| ROL32(x & 0x08011080, 16)
		| ROL32(x & 0x24040010, 20)
		| ROL32(x & 0x10020820, 24)
		| ((x & 0x80180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 1, 2, 0), (1, 0, 3, 2), (0, 2, 1, 3))
//[0, 5, 14, 11, 8, 1, 6, 15, 4, 13, 10, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_403(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04014020) << 4)
		| ROL32(x & 0x20100204, 8)
		| ROL32(x & 0x01028080, 12)
		| ROL32(x & 0x10400401, 16)
		| ROL32(x & 0x08082010, 20)
		| ROL32(x & 0x40200102, 24)
		| ((x & 0x02041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_403(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00204104) << 4)
		| ROL32(x & 0x02402001, 8)
		| ROL32(x & 0x01008082, 12)
		| ROL32(x & 0x04011040, 16)
		| ROL32(x & 0x28080010, 20)
		| ROL32(x & 0x10020420, 24)
		| ((x & 0x40140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_404(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x08018040) << 4)
		| ROL32(x & 0x20100408, 8)
		| ROL32(x & 0x01024020, 12)
		| ROL32(x & 0x10800801, 16)
		| ROL32(x & 0x02042010, 20)
		| ROL32(x & 0x80400102, 24)
		| ((x & 0x04081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_404(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200204)
		| ((x & 0x00408108) << 4)
		| ROL32(x & 0x02804001, 8)
		| ROL32(x & 0x01002042, 12)
		| ROL32(x & 0x08011080, 16)
		| ROL32(x & 0x24020010, 20)
		| ROL32(x & 0x10040820, 24)
		| ((x & 0x80180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_405(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200208)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x20100404, 8)
		| ROL32(x & 0x01024020, 12)
		| ROL32(x & 0x10400801, 16)
		| ROL32(x & 0x02082010, 20)
		| ROL32(x & 0x80800102, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_405(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200208)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x02808001, 8)
		| ROL32(x & 0x01002082, 12)
		| ROL32(x & 0x08011040, 16)
		| ROL32(x & 0x24020010, 20)
		| ROL32(x & 0x10040420, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_406(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200204)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x20100808, 8)
		| ROL32(x & 0x01028020, 12)
		| ROL32(x & 0x10800401, 16)
		| ROL32(x & 0x02042010, 20)
		| ROL32(x & 0x40400102, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_406(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200204)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x02404001, 8)
		| ROL32(x & 0x01002042, 12)
		| ROL32(x & 0x04011080, 16)
		| ROL32(x & 0x28020010, 20)
		| ROL32(x & 0x10080820, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 0, 1), (3, 2, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_407(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x04014080) << 4)
		| ROL32(x & 0x20100804, 8)
		| ROL32(x & 0x01028020, 12)
		| ROL32(x & 0x10400401, 16)
		| ROL32(x & 0x02082010, 20)
		| ROL32(x & 0x40800102, 24)
		| ((x & 0x08041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_407(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200208)
		| ((x & 0x00804104) << 4)
		| ROL32(x & 0x02408001, 8)
		| ROL32(x & 0x01002082, 12)
		| ROL32(x & 0x04011040, 16)
		| ROL32(x & 0x28020010, 20)
		| ROL32(x & 0x10080420, 24)
		| ((x & 0x40140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 1, 6, 15, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_408(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800102)
		| ((x & 0x04014020) << 4)
		| ROL32(x & 0x10100204, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80400401, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x40200808, 24)
		| ((x & 0x02048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_408(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800102)
		| ((x & 0x00204804) << 4)
		| ROL32(x & 0x08402008, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x04018040, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x10020410, 24)
		| ((x & 0x40140200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 2, 3), (3, 2, 0, 1), (1, 0, 3, 2))
//[4, 13, 2, 11, 0, 9, 6, 15, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_409(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400102)
		| ((x & 0x08018020) << 4)
		| ROL32(x & 0x10100208, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40800801, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x80200404, 24)
		| ((x & 0x02084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_409(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400102)
		| ((x & 0x00208408) << 4)
		| ROL32(x & 0x04802004, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x08014080, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x10020810, 24)
		| ((x & 0x80180200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3), (3, 2, 0, 1))
//[12, 5, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_410(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800104)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x10100202, 8)
		| ROL32(x & 0x08082080, 12)
		| ROL32(x & 0x80200401, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x40400808, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_410(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800104)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x08404008, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x04018020, 16)
		| ROL32(x & 0x82080080, 20)
		| ROL32(x & 0x10020210, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (1, 2, 0, 3), (3, 0, 2, 1))
//[12, 5, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_411(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400104)
		| ((x & 0x04018080) << 4)
		| ROL32(x & 0x10100202, 8)
		| ROL32(x & 0x08082040, 12)
		| ROL32(x & 0x40200401, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_411(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400104)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x04014020, 16)
		| ROL32(x & 0x82040080, 20)
		| ROL32(x & 0x10020210, 24)
		| ((x & 0x40180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (3, 0, 2, 1), (1, 2, 0, 3))
//[4, 13, 2, 11, 8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_412(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800108)
		| ((x & 0x08014040) << 4)
		| ROL32(x & 0x10100202, 8)
		| ROL32(x & 0x04042080, 12)
		| ROL32(x & 0x80200801, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_412(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800108)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x08018020, 16)
		| ROL32(x & 0x42080040, 20)
		| ROL32(x & 0x10020210, 24)
		| ((x & 0x80140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 1, 3, 2), (3, 2, 0, 1), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_413(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400108)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x10100202, 8)
		| ROL32(x & 0x04042040, 12)
		| ROL32(x & 0x40200801, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x80800404, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_413(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400108)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x04808004, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x08014020, 16)
		| ROL32(x & 0x42040040, 20)
		| ROL32(x & 0x10020210, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 2, 3, 1), (1, 0, 2, 3), (3, 1, 0, 2))
//[12, 5, 2, 11, 4, 1, 10, 15, 0, 9, 14, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_414(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200104)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x10100802, 8)
		| ROL32(x & 0x02082020, 12)
		| ROL32(x & 0x80800401, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x40400208, 24)
		| ((x & 0x08028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_414(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200104)
		| ((x & 0x00802808) << 4)
		| ROL32(x & 0x08404002, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x04018080, 16)
		| ROL32(x & 0x82020020, 20)
		| ROL32(x & 0x10080210, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (0, 2, 3, 1), (3, 1, 0, 2), (1, 0, 2, 3))
//[4, 13, 2, 11, 0, 5, 10, 15, 8, 1, 14, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_415(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200108)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x10100402, 8)
		| ROL32(x & 0x02042020, 12)
		| ROL32(x & 0x40400801, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x80800204, 24)
		| ((x & 0x04024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_415(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200108)
		| ((x & 0x00402404) << 4)
		| ROL32(x & 0x04808002, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x08014040, 16)
		| ROL32(x & 0x42020020, 20)
		| ROL32(x & 0x10040210, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 5, 2, 15, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_416(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800102)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x10100404, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80400201, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x20200808, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_416(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800102)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x08202008, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x02018040, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x10040410, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (0, 2, 3, 1), (3, 1, 0, 2))
//[12, 1, 6, 11, 4, 9, 2, 15, 0, 13, 10, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_417(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400102)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x10100804, 8)
		| ROL32(x & 0x04084040, 12)
		| ROL32(x & 0x80800201, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x20200408, 24)
		| ((x & 0x08048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_417(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400102)
		| ((x & 0x00804808) << 4)
		| ROL32(x & 0x08202004, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x02018080, 16)
		| ROL32(x & 0x84040040, 20)
		| ROL32(x & 0x10080410, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (3, 1, 0, 2), (0, 2, 3, 1))
//[0, 13, 6, 11, 8, 5, 2, 15, 12, 1, 10, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_418(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800102)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x10100408, 8)
		| ROL32(x & 0x08048080, 12)
		| ROL32(x & 0x40400201, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x20200804, 24)
		| ((x & 0x04084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_418(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800102)
		| ((x & 0x00408404) << 4)
		| ROL32(x & 0x04202008, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x02014040, 16)
		| ROL32(x & 0x48080080, 20)
		| ROL32(x & 0x10040810, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 2, 3), (3, 2, 0, 1), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 9, 2, 15, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_419(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400102)
		| ((x & 0x02012020) << 4)
		| ROL32(x & 0x10100808, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40800201, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x20200404, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_419(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400102)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x04202004, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x02014080, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x10080810, 24)
		| ((x & 0x20120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3), (3, 2, 0, 1))
//[12, 1, 6, 11, 8, 5, 2, 15, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_420(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800104)
		| ((x & 0x02012040) << 4)
		| ROL32(x & 0x10100402, 8)
		| ROL32(x & 0x08084080, 12)
		| ROL32(x & 0x80200201, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x20400808, 24)
		| ((x & 0x04028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_420(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800104)
		| ((x & 0x00402802) << 4)
		| ROL32(x & 0x08204008, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x02018020, 16)
		| ROL32(x & 0x84080080, 20)
		| ROL32(x & 0x10040210, 24)
		| ((x & 0x20120400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 0, 3, 2), (3, 2, 0, 1), (0, 1, 2, 3))
//[0, 13, 6, 11, 4, 9, 2, 15, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_421(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400108)
		| ((x & 0x02012080) << 4)
		| ROL32(x & 0x10100802, 8)
		| ROL32(x & 0x04048040, 12)
		| ROL32(x & 0x40200201, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x20800404, 24)
		| ((x & 0x08024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_421(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400108)
		| ((x & 0x00802402) << 4)
		| ROL32(x & 0x04208004, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x02014020, 16)
		| ROL32(x & 0x48040040, 20)
		| ROL32(x & 0x10080210, 24)
		| ((x & 0x20120800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 2, 0, 3), (0, 1, 3, 2), (3, 0, 2, 1))
//[12, 1, 6, 11, 0, 5, 10, 15, 8, 13, 2, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_422(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200102)
		| ((x & 0x02018080) << 4)
		| ROL32(x & 0x10100404, 8)
		| ROL32(x & 0x08084020, 12)
		| ROL32(x & 0x20400201, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x80800808, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_422(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200102)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x08808008, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x02012040, 16)
		| ROL32(x & 0x84020080, 20)
		| ROL32(x & 0x10040410, 24)
		| ((x & 0x20180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (1, 2, 0, 3), (3, 0, 2, 1), (0, 1, 3, 2))
//[0, 13, 6, 11, 4, 1, 10, 15, 12, 9, 2, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_423(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200102)
		| ((x & 0x02014040) << 4)
		| ROL32(x & 0x10100808, 8)
		| ROL32(x & 0x04048020, 12)
		| ROL32(x & 0x20800201, 16)
		| ROL32(x & 0x01021010, 20)
		| ROL32(x & 0x40400404, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_423(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200102)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x04404004, 8)
		| ROL32(x & 0x01001021, 12)
		| ROL32(x & 0x02012080, 16)
		| ROL32(x & 0x48020040, 20)
		| ROL32(x & 0x10080810, 24)
		| ((x & 0x20140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 0, 2, 1), (0, 1, 3, 2), (1, 2, 0, 3))
//[4, 1, 14, 11, 8, 5, 2, 15, 0, 13, 10, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_424(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800108)
		| ((x & 0x08012020) << 4)
		| ROL32(x & 0x10100404, 8)
		| ROL32(x & 0x02024080, 12)
		| ROL32(x & 0x80400801, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_424(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800108)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x08018040, 16)
		| ROL32(x & 0x24080020, 20)
		| ROL32(x & 0x10040410, 24)
		| ((x & 0x80120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 0, 2, 1), (1, 2, 0, 3), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 9, 2, 15, 12, 1, 10, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_425(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400104)
		| ((x & 0x04012020) << 4)
		| ROL32(x & 0x10100808, 8)
		| ROL32(x & 0x02028040, 12)
		| ROL32(x & 0x40800401, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x20200202, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_425(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400104)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x02202002, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x04014080, 16)
		| ROL32(x & 0x28040020, 20)
		| ROL32(x & 0x10080810, 24)
		| ((x & 0x40120200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 1, 0, 2), (0, 2, 3, 1), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 9, 6, 15, 8, 13, 2, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_426(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400108)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x10100204, 8)
		| ROL32(x & 0x04024040, 12)
		| ROL32(x & 0x20200801, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x80800402, 24)
		| ((x & 0x02042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_426(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400108)
		| ((x & 0x00204202) << 4)
		| ROL32(x & 0x02808004, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x08012020, 16)
		| ROL32(x & 0x24040040, 20)
		| ROL32(x & 0x10020410, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 1, 0, 2), (1, 0, 2, 3), (0, 2, 3, 1))
//[0, 5, 14, 11, 8, 1, 6, 15, 12, 9, 2, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_427(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800104)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x10100208, 8)
		| ROL32(x & 0x08028080, 12)
		| ROL32(x & 0x20200401, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x40400802, 24)
		| ((x & 0x02082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_427(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800104)
		| ((x & 0x00208202) << 4)
		| ROL32(x & 0x02404008, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x04012020, 16)
		| ROL32(x & 0x28080080, 20)
		| ROL32(x & 0x10020810, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 14, 11, 0, 5, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_428(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200104)
		| ((x & 0x08018040) << 4)
		| ROL32(x & 0x10100408, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20800801, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x80400202, 24)
		| ((x & 0x04082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_428(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200104)
		| ((x & 0x00408208) << 4)
		| ROL32(x & 0x02804002, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x08012080, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x10040810, 24)
		| ((x & 0x80180400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 14, 11, 0, 5, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_429(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200108)
		| ((x & 0x08018080) << 4)
		| ROL32(x & 0x10100404, 8)
		| ROL32(x & 0x02024020, 12)
		| ROL32(x & 0x20400801, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x80800202, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_429(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200108)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x02808002, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x08012040, 16)
		| ROL32(x & 0x24020020, 20)
		| ROL32(x & 0x10040410, 24)
		| ((x & 0x80180800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 14, 11, 4, 1, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_430(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200104)
		| ((x & 0x04014040) << 4)
		| ROL32(x & 0x10100808, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20800401, 16)
		| ROL32(x & 0x01041010, 20)
		| ROL32(x & 0x40400202, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_430(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200104)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x02404002, 8)
		| ROL32(x & 0x01001041, 12)
		| ROL32(x & 0x04012080, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x10080810, 24)
		| ((x & 0x40140400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((2, 3, 1, 0), (3, 2, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 14, 11, 4, 1, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_431(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200108)
		| ((x & 0x04014080) << 4)
		| ROL32(x & 0x10100804, 8)
		| ROL32(x & 0x02028020, 12)
		| ROL32(x & 0x20400401, 16)
		| ROL32(x & 0x01081010, 20)
		| ROL32(x & 0x40800202, 24)
		| ((x & 0x08042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_431(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200108)
		| ((x & 0x00804204) << 4)
		| ROL32(x & 0x02408002, 8)
		| ROL32(x & 0x01001081, 12)
		| ROL32(x & 0x04012040, 16)
		| ROL32(x & 0x28020020, 20)
		| ROL32(x & 0x10080410, 24)
		| ((x & 0x40140800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 1, 2, 3), (1, 2, 3, 0), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 9, 6, 3, 0, 13, 10, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_432(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400102)
		| ((x & 0x04081020) << 4)
		| ROL32(x & 0x40800204, 8)
		| ROL32(x & 0x08012040, 12)
		| ROL32(x & 0x80100408, 16)
		| ROL32(x & 0x01024080, 20)
		| ROL32(x & 0x10200801, 24)
		| ((x & 0x02048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_432(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400102)
		| ((x & 0x00204801) << 4)
		| ROL32(x & 0x01102008, 8)
		| ROL32(x & 0x08001024, 12)
		| ROL32(x & 0x04088010, 16)
		| ROL32(x & 0x12040080, 20)
		| ROL32(x & 0x80020440, 24)
		| ((x & 0x40810200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 1, 2, 3), (2, 3, 0, 1), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 13, 6, 3, 12, 1, 10, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_433(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800102)
		| ((x & 0x08041020) << 4)
		| ROL32(x & 0x80400208, 8)
		| ROL32(x & 0x04012080, 12)
		| ROL32(x & 0x40100804, 16)
		| ROL32(x & 0x01028040, 20)
		| ROL32(x & 0x10200401, 24)
		| ((x & 0x02084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_433(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800102)
		| ((x & 0x00208401) << 4)
		| ROL32(x & 0x01102004, 8)
		| ROL32(x & 0x04001028, 12)
		| ROL32(x & 0x08044010, 16)
		| ROL32(x & 0x12080040, 20)
		| ROL32(x & 0x40020880, 24)
		| ((x & 0x80410200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 2, 3, 1), (1, 3, 2, 0), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 13, 10, 3, 0, 9, 14, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_434(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200108)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40800802, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x80100404, 16)
		| ROL32(x & 0x01084080, 20)
		| ROL32(x & 0x10400201, 24)
		| ((x & 0x08028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_434(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200108)
		| ((x & 0x00802801) << 4)
		| ROL32(x & 0x01104002, 8)
		| ROL32(x & 0x08001084, 12)
		| ROL32(x & 0x04048010, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x80080240, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 2, 3, 1), (2, 1, 0, 3), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 5, 10, 3, 8, 1, 14, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_435(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200104)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80400402, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x40100808, 16)
		| ROL32(x & 0x01048040, 20)
		| ROL32(x & 0x10800201, 24)
		| ((x & 0x04024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_435(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200104)
		| ((x & 0x00402401) << 4)
		| ROL32(x & 0x01108002, 8)
		| ROL32(x & 0x04001048, 12)
		| ROL32(x & 0x08084010, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x40040280, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_436(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400104)
		| ((x & 0x04021020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x02012040, 12)
		| ROL32(x & 0x40100402, 16)
		| ROL32(x & 0x01048080, 20)
		| ROL32(x & 0x10200201, 24)
		| ((x & 0x08084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_436(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400104)
		| ((x & 0x00808401) << 4)
		| ROL32(x & 0x01102002, 8)
		| ROL32(x & 0x08001048, 12)
		| ROL32(x & 0x04024010, 16)
		| ROL32(x & 0x12040020, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_437(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400108)
		| ((x & 0x04021020) << 4)
		| ROL32(x & 0x40800804, 8)
		| ROL32(x & 0x02012040, 12)
		| ROL32(x & 0x80100402, 16)
		| ROL32(x & 0x01084080, 20)
		| ROL32(x & 0x10200201, 24)
		| ((x & 0x08048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_437(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400108)
		| ((x & 0x00804801) << 4)
		| ROL32(x & 0x01102002, 8)
		| ROL32(x & 0x08001084, 12)
		| ROL32(x & 0x04028010, 16)
		| ROL32(x & 0x12040020, 20)
		| ROL32(x & 0x80080440, 24)
		| ((x & 0x40210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 10, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_438(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800104)
		| ((x & 0x08021020) << 4)
		| ROL32(x & 0x80400408, 8)
		| ROL32(x & 0x02012080, 12)
		| ROL32(x & 0x40100802, 16)
		| ROL32(x & 0x01048040, 20)
		| ROL32(x & 0x10200201, 24)
		| ((x & 0x04084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_438(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800104)
		| ((x & 0x00408401) << 4)
		| ROL32(x & 0x01102002, 8)
		| ROL32(x & 0x04001048, 12)
		| ROL32(x & 0x08024010, 16)
		| ROL32(x & 0x12080020, 20)
		| ROL32(x & 0x40040880, 24)
		| ((x & 0x80210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (0, 3, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 10, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_439(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800108)
		| ((x & 0x08021020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x02012080, 12)
		| ROL32(x & 0x80100802, 16)
		| ROL32(x & 0x01084040, 20)
		| ROL32(x & 0x10200201, 24)
		| ((x & 0x04048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_439(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800108)
		| ((x & 0x00404801) << 4)
		| ROL32(x & 0x01102002, 8)
		| ROL32(x & 0x04001084, 12)
		| ROL32(x & 0x08028010, 16)
		| ROL32(x & 0x12080020, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 0, 3), (0, 3, 2, 1), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 13, 10, 3, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_440(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200102)
		| ((x & 0x02041040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x04014020, 12)
		| ROL32(x & 0x20100204, 16)
		| ROL32(x & 0x01028080, 20)
		| ROL32(x & 0x10400401, 24)
		| ((x & 0x08082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_440(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200102)
		| ((x & 0x00808201) << 4)
		| ROL32(x & 0x01104004, 8)
		| ROL32(x & 0x08001028, 12)
		| ROL32(x & 0x02042010, 16)
		| ROL32(x & 0x14020040, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 5, 10, 3, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_441(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200102)
		| ((x & 0x02081080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x08018020, 12)
		| ROL32(x & 0x20100208, 16)
		| ROL32(x & 0x01024040, 20)
		| ROL32(x & 0x10800801, 24)
		| ((x & 0x04042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_441(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200102)
		| ((x & 0x00404201) << 4)
		| ROL32(x & 0x01108008, 8)
		| ROL32(x & 0x04001024, 12)
		| ROL32(x & 0x02082010, 16)
		| ROL32(x & 0x18020080, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 5, 10, 3, 0, 9, 14, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_442(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200104)
		| ((x & 0x02081040) << 4)
		| ROL32(x & 0x20800402, 8)
		| ROL32(x & 0x08014020, 12)
		| ROL32(x & 0x80100208, 16)
		| ROL32(x & 0x01042080, 20)
		| ROL32(x & 0x10400801, 24)
		| ((x & 0x04028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_442(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200104)
		| ((x & 0x00402801) << 4)
		| ROL32(x & 0x01104008, 8)
		| ROL32(x & 0x08001042, 12)
		| ROL32(x & 0x02088010, 16)
		| ROL32(x & 0x14020080, 20)
		| ROL32(x & 0x80040220, 24)
		| ((x & 0x20810400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 13, 10, 3, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_443(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200108)
		| ((x & 0x02041040) << 4)
		| ROL32(x & 0x20800802, 8)
		| ROL32(x & 0x04014020, 12)
		| ROL32(x & 0x80100204, 16)
		| ROL32(x & 0x01082080, 20)
		| ROL32(x & 0x10400401, 24)
		| ((x & 0x08028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_443(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200108)
		| ((x & 0x00802801) << 4)
		| ROL32(x & 0x01104004, 8)
		| ROL32(x & 0x08001082, 12)
		| ROL32(x & 0x02048010, 16)
		| ROL32(x & 0x14020040, 20)
		| ROL32(x & 0x80080220, 24)
		| ((x & 0x20410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 5, 10, 3, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_444(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200104)
		| ((x & 0x02081080) << 4)
		| ROL32(x & 0x20400402, 8)
		| ROL32(x & 0x08018020, 12)
		| ROL32(x & 0x40100208, 16)
		| ROL32(x & 0x01042040, 20)
		| ROL32(x & 0x10800801, 24)
		| ((x & 0x04024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_444(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200104)
		| ((x & 0x00402401) << 4)
		| ROL32(x & 0x01108008, 8)
		| ROL32(x & 0x04001042, 12)
		| ROL32(x & 0x02084010, 16)
		| ROL32(x & 0x18020080, 20)
		| ROL32(x & 0x40040220, 24)
		| ((x & 0x20810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 2, 3, 0), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 13, 10, 3, 8, 1, 14, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_445(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200108)
		| ((x & 0x02041080) << 4)
		| ROL32(x & 0x20400802, 8)
		| ROL32(x & 0x04018020, 12)
		| ROL32(x & 0x40100204, 16)
		| ROL32(x & 0x01082040, 20)
		| ROL32(x & 0x10800401, 24)
		| ((x & 0x08024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_445(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200108)
		| ((x & 0x00802401) << 4)
		| ROL32(x & 0x01108004, 8)
		| ROL32(x & 0x04001082, 12)
		| ROL32(x & 0x02044010, 16)
		| ROL32(x & 0x18020040, 20)
		| ROL32(x & 0x40080220, 24)
		| ((x & 0x20410800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 3, 2, 0), (0, 2, 3, 1), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 9, 14, 3, 0, 13, 10, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_446(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400108)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20800804, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x80100202, 16)
		| ROL32(x & 0x01082080, 20)
		| ROL32(x & 0x10200401, 24)
		| ((x & 0x08048010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_446(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400108)
		| ((x & 0x00804801) << 4)
		| ROL32(x & 0x01102004, 8)
		| ROL32(x & 0x08001082, 12)
		| ROL32(x & 0x02028010, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x80080420, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (1, 3, 2, 0), (2, 1, 0, 3), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 5, 14, 3, 12, 1, 10, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_447(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800104)
		| ((x & 0x02021020) << 4)
		| ROL32(x & 0x20400408, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x40100202, 16)
		| ROL32(x & 0x01042040, 20)
		| ROL32(x & 0x10200801, 24)
		| ((x & 0x04084010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_447(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800104)
		| ((x & 0x00408401) << 4)
		| ROL32(x & 0x01102008, 8)
		| ROL32(x & 0x04001042, 12)
		| ROL32(x & 0x02024010, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x40040820, 24)
		| ((x & 0x20210200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_448(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400102)
		| ((x & 0x08081080) << 4)
		| ROL32(x & 0x80200204, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x20100808, 16)
		| ROL32(x & 0x01028020, 20)
		| ROL32(x & 0x10800401, 24)
		| ((x & 0x02042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_448(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400102)
		| ((x & 0x00204201) << 4)
		| ROL32(x & 0x01108004, 8)
		| ROL32(x & 0x02001028, 12)
		| ROL32(x & 0x08082010, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x20020480, 24)
		| ((x & 0x80810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7, 0, 5, 14, 11]
void BOGI32_omega_diffusion_449(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800102)
		| ((x & 0x08041040) << 4)
		| ROL32(x & 0x80200208, 8)
		| ROL32(x & 0x04014080, 12)
		| ROL32(x & 0x20100804, 16)
		| ROL32(x & 0x01028020, 20)
		| ROL32(x & 0x10400401, 24)
		| ((x & 0x02082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_449(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800102)
		| ((x & 0x00208201) << 4)
		| ROL32(x & 0x01104004, 8)
		| ROL32(x & 0x02001028, 12)
		| ROL32(x & 0x08042010, 16)
		| ROL32(x & 0x14080040, 20)
		| ROL32(x & 0x20020880, 24)
		| ((x & 0x80410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 9, 6, 3, 8, 13, 2, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_450(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400102)
		| ((x & 0x04081080) << 4)
		| ROL32(x & 0x40200204, 8)
		| ROL32(x & 0x08018040, 12)
		| ROL32(x & 0x20100408, 16)
		| ROL32(x & 0x01024020, 20)
		| ROL32(x & 0x10800801, 24)
		| ((x & 0x02042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_450(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400102)
		| ((x & 0x00204201) << 4)
		| ROL32(x & 0x01108008, 8)
		| ROL32(x & 0x02001024, 12)
		| ROL32(x & 0x04082010, 16)
		| ROL32(x & 0x18040080, 20)
		| ROL32(x & 0x20020440, 24)
		| ((x & 0x40810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 0, 3), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 13, 6, 3, 12, 9, 2, 7, 4, 1, 14, 11]
void BOGI32_omega_diffusion_451(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800102)
		| ((x & 0x04041040) << 4)
		| ROL32(x & 0x40200208, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x20100404, 16)
		| ROL32(x & 0x01024020, 20)
		| ROL32(x & 0x10400801, 24)
		| ((x & 0x02082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_451(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800102)
		| ((x & 0x00208201) << 4)
		| ROL32(x & 0x01104008, 8)
		| ROL32(x & 0x02001024, 12)
		| ROL32(x & 0x04042010, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x20020840, 24)
		| ((x & 0x40410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 3, 0), (0, 3, 2, 1), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 13, 6, 3, 0, 9, 14, 7, 12, 5, 2, 11]
void BOGI32_omega_diffusion_452(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800108)
		| ((x & 0x08041040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x04014080, 12)
		| ROL32(x & 0x80100804, 16)
		| ROL32(x & 0x01082020, 20)
		| ROL32(x & 0x10400401, 24)
		| ((x & 0x02028010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_452(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800108)
		| ((x & 0x00202801) << 4)
		| ROL32(x & 0x01104004, 8)
		| ROL32(x & 0x02001082, 12)
		| ROL32(x & 0x08048010, 16)
		| ROL32(x & 0x14080040, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80410400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 9, 6, 3, 8, 1, 14, 7, 4, 13, 2, 11]
void BOGI32_omega_diffusion_453(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400104)
		| ((x & 0x04081080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x08018040, 12)
		| ROL32(x & 0x40100408, 16)
		| ROL32(x & 0x01042020, 20)
		| ROL32(x & 0x10800801, 24)
		| ((x & 0x02024010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_453(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400104)
		| ((x & 0x00202401) << 4)
		| ROL32(x & 0x01108008, 8)
		| ROL32(x & 0x02001042, 12)
		| ROL32(x & 0x04084010, 16)
		| ROL32(x & 0x18040080, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40810800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 3, 0, 1), (0, 1, 2, 3), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 5, 14, 3, 12, 9, 2, 7, 0, 13, 6, 11]
void BOGI32_omega_diffusion_454(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800104)
		| ((x & 0x08021040) << 4)
		| ROL32(x & 0x80200408, 8)
		| ROL32(x & 0x02014080, 12)
		| ROL32(x & 0x20100802, 16)
		| ROL32(x & 0x01048020, 20)
		| ROL32(x & 0x10400201, 24)
		| ((x & 0x04082010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_454(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800104)
		| ((x & 0x00408201) << 4)
		| ROL32(x & 0x01104002, 8)
		| ROL32(x & 0x02001048, 12)
		| ROL32(x & 0x08022010, 16)
		| ROL32(x & 0x14080020, 20)
		| ROL32(x & 0x20040880, 24)
		| ((x & 0x80210400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 1, 2), (2, 3, 0, 1), (1, 2, 3, 0), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11]
void BOGI32_omega_diffusion_455(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400108)
		| ((x & 0x04021080) << 4)
		| ROL32(x & 0x40200804, 8)
		| ROL32(x & 0x02018040, 12)
		| ROL32(x & 0x20100402, 16)
		| ROL32(x & 0x01084020, 20)
		| ROL32(x & 0x10800201, 24)
		| ((x & 0x08042010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_455(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400108)
		| ((x & 0x00804201) << 4)
		| ROL32(x & 0x01108002, 8)
		| ROL32(x & 0x02001084, 12)
		| ROL32(x & 0x04022010, 16)
		| ROL32(x & 0x18040020, 20)
		| ROL32(x & 0x20080440, 24)
		| ((x & 0x40210800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 1, 3, 2), (1, 2, 0, 3), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 9, 6, 3, 4, 1, 14, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_456(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400804)
		| ((x & 0x04081010) << 4)
		| ROL32(x & 0x80800202, 8)
		| ROL32(x & 0x01012040, 12)
		| ROL32(x & 0x40200408, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_456(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400804)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x04084020, 16)
		| ROL32(x & 0x12040010, 20)
		| ROL32(x & 0x80020280, 24)
		| ((x & 0x40810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 1, 3, 2), (2, 3, 1, 0), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 13, 6, 3, 0, 5, 14, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_457(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800408)
		| ((x & 0x08041010) << 4)
		| ROL32(x & 0x40400202, 8)
		| ROL32(x & 0x01012080, 12)
		| ROL32(x & 0x80200804, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_457(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800408)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x08048020, 16)
		| ROL32(x & 0x12080010, 20)
		| ROL32(x & 0x40020240, 24)
		| ((x & 0x80410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 2, 1, 3), (1, 3, 0, 2), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 13, 10, 3, 12, 1, 6, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_458(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04041010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01012020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02028080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_458(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00808404) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08002028, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x12020010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 2, 1, 3), (2, 1, 3, 0), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 5, 10, 3, 0, 13, 6, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_459(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08081010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01012020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02024040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_459(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00404808) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04002024, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x12020010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 0, 3), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 9, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_460(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x04021010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01012040, 12)
		| ROL32(x & 0x40200402, 16)
		| ROL32(x & 0x02048080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_460(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x00808402) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08002048, 12)
		| ROL32(x & 0x04024020, 16)
		| ROL32(x & 0x12040010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (1, 2, 3, 0), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 9, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_461(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400208)
		| ((x & 0x04021010) << 4)
		| ROL32(x & 0x40800804, 8)
		| ROL32(x & 0x01012040, 12)
		| ROL32(x & 0x80200402, 16)
		| ROL32(x & 0x02084080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_461(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400208)
		| ((x & 0x00804802) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08002084, 12)
		| ROL32(x & 0x04028020, 16)
		| ROL32(x & 0x12040010, 20)
		| ROL32(x & 0x80080440, 24)
		| ((x & 0x40210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 0, 3), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 5, 14, 3, 12, 1, 6, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_462(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800204)
		| ((x & 0x08021010) << 4)
		| ROL32(x & 0x80400408, 8)
		| ROL32(x & 0x01012080, 12)
		| ROL32(x & 0x40200802, 16)
		| ROL32(x & 0x02048040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_462(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800204)
		| ((x & 0x00408402) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04002048, 12)
		| ROL32(x & 0x08024020, 16)
		| ROL32(x & 0x12080010, 20)
		| ROL32(x & 0x40040880, 24)
		| ((x & 0x80210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (0, 3, 1, 2), (2, 1, 3, 0), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 5, 14, 3, 0, 13, 6, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_463(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x08021010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01012080, 12)
		| ROL32(x & 0x80200802, 16)
		| ROL32(x & 0x02084040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_463(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x00404802) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04002084, 12)
		| ROL32(x & 0x08028020, 16)
		| ROL32(x & 0x12080010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_464(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200802)
		| ((x & 0x02081010) << 4)
		| ROL32(x & 0x80800404, 8)
		| ROL32(x & 0x01014020, 12)
		| ROL32(x & 0x20400208, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_464(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200802)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x02082040, 16)
		| ROL32(x & 0x14020010, 20)
		| ROL32(x & 0x80040480, 24)
		| ((x & 0x20810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_465(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x02041010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01014020, 12)
		| ROL32(x & 0x20400204, 16)
		| ROL32(x & 0x04028080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_465(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x00808204) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08004028, 12)
		| ROL32(x & 0x02042040, 16)
		| ROL32(x & 0x14020010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 5, 10, 3, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_466(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x02081010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01018020, 12)
		| ROL32(x & 0x20800208, 16)
		| ROL32(x & 0x08024040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_466(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x00404208) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04008024, 12)
		| ROL32(x & 0x02082080, 16)
		| ROL32(x & 0x18020010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 0, 3), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 13, 10, 3, 12, 5, 2, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_467(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200402)
		| ((x & 0x02041010) << 4)
		| ROL32(x & 0x40400808, 8)
		| ROL32(x & 0x01018020, 12)
		| ROL32(x & 0x20800204, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_467(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200402)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x02042080, 16)
		| ROL32(x & 0x18020010, 20)
		| ROL32(x & 0x40080840, 24)
		| ((x & 0x20410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 3, 0), (0, 3, 1, 2), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 13, 10, 3, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_468(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200408)
		| ((x & 0x02041010) << 4)
		| ROL32(x & 0x20800802, 8)
		| ROL32(x & 0x01014020, 12)
		| ROL32(x & 0x80400204, 16)
		| ROL32(x & 0x04082080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_468(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200408)
		| ((x & 0x00802804) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08004082, 12)
		| ROL32(x & 0x02048040, 16)
		| ROL32(x & 0x14020010, 20)
		| ROL32(x & 0x80080220, 24)
		| ((x & 0x20410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 2, 3, 0), (2, 1, 0, 3), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 5, 10, 3, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_469(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200804)
		| ((x & 0x02081010) << 4)
		| ROL32(x & 0x20400402, 8)
		| ROL32(x & 0x01018020, 12)
		| ROL32(x & 0x40800208, 16)
		| ROL32(x & 0x08042040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_469(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200804)
		| ((x & 0x00402408) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04008042, 12)
		| ROL32(x & 0x02084080, 16)
		| ROL32(x & 0x18020010, 20)
		| ROL32(x & 0x40040220, 24)
		| ((x & 0x20810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 3, 0, 2), (0, 2, 1, 3), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 9, 14, 3, 12, 5, 2, 11, 0, 13, 10, 7]
void BOGI32_omega_diffusion_470(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02021010) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01014040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04048080, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_470(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00808202) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x08004048, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x14040010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (1, 3, 0, 2), (2, 1, 3, 0), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 5, 14, 3, 4, 13, 2, 11, 12, 1, 10, 7]
void BOGI32_omega_diffusion_471(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02021010) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01018080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08084040, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_471(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00404202) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x04008084, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x18080010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 0, 3), (0, 3, 1, 2), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 13, 6, 3, 12, 5, 2, 11, 0, 9, 14, 7]
void BOGI32_omega_diffusion_472(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800402)
		| ((x & 0x08041010) << 4)
		| ROL32(x & 0x80200208, 8)
		| ROL32(x & 0x01014080, 12)
		| ROL32(x & 0x20400804, 16)
		| ROL32(x & 0x04028020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_472(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800402)
		| ((x & 0x00208204) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02004028, 12)
		| ROL32(x & 0x08042040, 16)
		| ROL32(x & 0x14080010, 20)
		| ROL32(x & 0x20020880, 24)
		| ((x & 0x80410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 0, 3), (1, 2, 3, 0), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 9, 6, 3, 4, 13, 2, 11, 8, 1, 14, 7]
void BOGI32_omega_diffusion_473(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400802)
		| ((x & 0x04081010) << 4)
		| ROL32(x & 0x40200204, 8)
		| ROL32(x & 0x01018040, 12)
		| ROL32(x & 0x20800408, 16)
		| ROL32(x & 0x08024020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_473(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400802)
		| ((x & 0x00204208) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02008024, 12)
		| ROL32(x & 0x04082080, 16)
		| ROL32(x & 0x18040010, 20)
		| ROL32(x & 0x20020440, 24)
		| ((x & 0x40810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 9, 6, 3, 0, 5, 14, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_474(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08081010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01014040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04042020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_474(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00202808) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02004042, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x14040010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 13, 6, 3, 0, 5, 14, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_475(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x08041010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01014080, 12)
		| ROL32(x & 0x80400804, 16)
		| ROL32(x & 0x04082020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_475(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x00202804) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02004082, 12)
		| ROL32(x & 0x08048040, 16)
		| ROL32(x & 0x14080010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 9, 6, 3, 4, 1, 14, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_476(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x04081010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01018040, 12)
		| ROL32(x & 0x40800408, 16)
		| ROL32(x & 0x08042020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_476(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x00202408) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02008042, 12)
		| ROL32(x & 0x04084080, 16)
		| ROL32(x & 0x18040010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40810100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 1, 3, 0), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 13, 6, 3, 4, 1, 14, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_477(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04041010) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01018080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08082020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x02024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_477(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00202404) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02008082, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x18080010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40410100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 3, 1, 0), (0, 1, 3, 2), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 5, 14, 3, 0, 13, 6, 11, 12, 9, 2, 7]
void BOGI32_omega_diffusion_478(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800208)
		| ((x & 0x08021010) << 4)
		| ROL32(x & 0x20200404, 8)
		| ROL32(x & 0x01014080, 12)
		| ROL32(x & 0x80400802, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_478(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800208)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x08028040, 16)
		| ROL32(x & 0x14080010, 20)
		| ROL32(x & 0x20040420, 24)
		| ((x & 0x80210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 0, 2, 1), (2, 3, 1, 0), (1, 2, 0, 3), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 9, 14, 3, 12, 1, 6, 11, 8, 13, 2, 7]
void BOGI32_omega_diffusion_479(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400204)
		| ((x & 0x04021010) << 4)
		| ROL32(x & 0x20200808, 8)
		| ROL32(x & 0x01018040, 12)
		| ROL32(x & 0x40800402, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x10100101, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_479(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400204)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x01101001, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x04024080, 16)
		| ROL32(x & 0x18040010, 20)
		| ROL32(x & 0x20080820, 24)
		| ((x & 0x40210100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 1, 3), (1, 3, 2, 0), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 13, 10, 7, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_480(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40800108, 8)
		| ROL32(x & 0x08012020, 12)
		| ROL32(x & 0x10100404, 16)
		| ROL32(x & 0x02024080, 20)
		| ROL32(x & 0x80400801, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_480(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01804008, 8)
		| ROL32(x & 0x08002024, 12)
		| ROL32(x & 0x04041010, 16)
		| ROL32(x & 0x12020080, 20)
		| ROL32(x & 0x80010840, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 1, 10, 7, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_481(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80400104, 8)
		| ROL32(x & 0x04012020, 12)
		| ROL32(x & 0x10100808, 16)
		| ROL32(x & 0x02028040, 20)
		| ROL32(x & 0x40800401, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_481(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01408004, 8)
		| ROL32(x & 0x04002028, 12)
		| ROL32(x & 0x08081010, 16)
		| ROL32(x & 0x12020040, 20)
		| ROL32(x & 0x40010480, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 1, 10, 7, 4, 9, 14, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_482(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200804)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x80800102, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x10100408, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x40400201, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_482(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200804)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01404002, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x04081010, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x80010280, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 13, 10, 7, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_483(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40800102, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x10100404, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80400201, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_483(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01804002, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x04041010, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x80010240, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 1, 10, 7, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_484(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80400102, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x10100808, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40800201, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_484(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01408002, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x08081010, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x40010280, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 2, 3, 1), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 13, 10, 7, 8, 5, 14, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_485(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200408)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x40400102, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x10100804, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x80800201, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_485(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200408)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01808002, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x08041010, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x40010240, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 3, 2, 1), (1, 2, 3, 0), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 9, 14, 7, 4, 13, 10, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_486(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400808)
		| ((x & 0x04028020) << 4)
		| ROL32(x & 0x40800104, 8)
		| ROL32(x & 0x02012040, 12)
		| ROL32(x & 0x10100402, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80200201, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_486(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400808)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01802002, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x04021010, 16)
		| ROL32(x & 0x12040020, 20)
		| ROL32(x & 0x80010440, 24)
		| ((x & 0x40280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (0, 3, 2, 1), (2, 0, 1, 3), (1, 2, 3, 0))
//[4, 9, 2, 15, 8, 1, 14, 7, 12, 5, 10, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_487(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800404)
		| ((x & 0x08024020) << 4)
		| ROL32(x & 0x80400108, 8)
		| ROL32(x & 0x02012080, 12)
		| ROL32(x & 0x10100802, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40200201, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_487(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800404)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01402002, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x08021010, 16)
		| ROL32(x & 0x12080020, 20)
		| ROL32(x & 0x40010880, 24)
		| ((x & 0x80240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 0, 2, 3), (0, 2, 3, 1), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 9, 2, 7, 4, 13, 10, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_488(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400802)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x80800104, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x10100208, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x20200401, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_488(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400802)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01202004, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x02081010, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x80010480, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 0, 2, 3), (2, 3, 1, 0), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 13, 2, 7, 12, 5, 10, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_489(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800402)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x40400108, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x10100204, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x20200801, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_489(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800402)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01202008, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x02041010, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x40010840, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 2, 3, 0), (0, 3, 2, 1), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 13, 10, 7, 4, 9, 14, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_490(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200808)
		| ((x & 0x02048040) << 4)
		| ROL32(x & 0x20800102, 8)
		| ROL32(x & 0x04014020, 12)
		| ROL32(x & 0x10100204, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80400401, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_490(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200808)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01804004, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x02041010, 16)
		| ROL32(x & 0x14020040, 20)
		| ROL32(x & 0x80010220, 24)
		| ((x & 0x20480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 2, 3, 0), (2, 0, 1, 3), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 1, 10, 7, 8, 5, 14, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_491(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200404)
		| ((x & 0x02084080) << 4)
		| ROL32(x & 0x20400102, 8)
		| ROL32(x & 0x08018020, 12)
		| ROL32(x & 0x10100208, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40800801, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_491(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200404)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01408008, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x02081010, 16)
		| ROL32(x & 0x18020080, 20)
		| ROL32(x & 0x40010220, 24)
		| ((x & 0x20840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_492(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20800108, 8)
		| ROL32(x & 0x08014040, 12)
		| ROL32(x & 0x10100202, 16)
		| ROL32(x & 0x04042080, 20)
		| ROL32(x & 0x80200801, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_492(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01802008, 8)
		| ROL32(x & 0x08004042, 12)
		| ROL32(x & 0x02021010, 16)
		| ROL32(x & 0x14040080, 20)
		| ROL32(x & 0x80010820, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_493(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20800104, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x10100202, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80200401, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_493(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01802004, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x02021010, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x80010420, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 10, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_494(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20400108, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x10100202, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40200801, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_494(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01402008, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x02021010, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x40010820, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (1, 3, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 10, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_495(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20400104, 8)
		| ROL32(x & 0x04018080, 12)
		| ROL32(x & 0x10100202, 16)
		| ROL32(x & 0x08082040, 20)
		| ROL32(x & 0x40200401, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_495(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01402004, 8)
		| ROL32(x & 0x04008082, 12)
		| ROL32(x & 0x02021010, 16)
		| ROL32(x & 0x18080040, 20)
		| ROL32(x & 0x40010420, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_496(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80200104, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x10100808, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20800401, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_496(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01208004, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x08081010, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x20010480, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (0, 3, 2, 1), (1, 2, 3, 0))
//[4, 1, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3, 0, 5, 14, 11]
void BOGI32_omega_diffusion_497(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800202)
		| ((x & 0x08042040) << 4)
		| ROL32(x & 0x80200108, 8)
		| ROL32(x & 0x04014080, 12)
		| ROL32(x & 0x10100804, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20400401, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_497(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800202)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01204004, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x08041010, 16)
		| ROL32(x & 0x14080040, 20)
		| ROL32(x & 0x20010880, 24)
		| ((x & 0x80420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (1, 2, 3, 0), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 9, 2, 7, 8, 13, 6, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_498(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400202)
		| ((x & 0x04082080) << 4)
		| ROL32(x & 0x40200104, 8)
		| ROL32(x & 0x08018040, 12)
		| ROL32(x & 0x10100408, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20800801, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_498(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400202)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01208008, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x04081010, 16)
		| ROL32(x & 0x18040080, 20)
		| ROL32(x & 0x20010440, 24)
		| ((x & 0x40820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 1, 3), (1, 3, 2, 0), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 13, 2, 7, 12, 9, 6, 3, 4, 1, 14, 11]
void BOGI32_omega_diffusion_499(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40200108, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x10100404, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20400801, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_499(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01204008, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x04041010, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x20010840, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 9, 2, 7, 8, 5, 14, 3, 0, 13, 6, 11]
void BOGI32_omega_diffusion_500(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80200102, 8)
		| ROL32(x & 0x02014040, 12)
		| ROL32(x & 0x10100808, 16)
		| ROL32(x & 0x04048020, 20)
		| ROL32(x & 0x20800201, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_500(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01208002, 8)
		| ROL32(x & 0x02004048, 12)
		| ROL32(x & 0x08081010, 16)
		| ROL32(x & 0x14040020, 20)
		| ROL32(x & 0x20010280, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 0, 3, 1), (1, 3, 2, 0), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 13, 2, 7, 4, 9, 14, 3, 12, 1, 6, 11]
void BOGI32_omega_diffusion_501(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40200102, 8)
		| ROL32(x & 0x02018080, 12)
		| ROL32(x & 0x10100404, 16)
		| ROL32(x & 0x08084020, 20)
		| ROL32(x & 0x20400201, 24)
		| ((x & 0x01021010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_501(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00102101) << 4)
		| ROL32(x & 0x01204002, 8)
		| ROL32(x & 0x02008084, 12)
		| ROL32(x & 0x04041010, 16)
		| ROL32(x & 0x18080020, 20)
		| ROL32(x & 0x20010240, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 3, 1, 0), (0, 2, 3, 1), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 9, 14, 7, 8, 13, 6, 3, 12, 5, 2, 11]
void BOGI32_omega_diffusion_502(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400208)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x20200104, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x10100802, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x80800401, 24)
		| ((x & 0x01041010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_502(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400208)
		| ((x & 0x00104101) << 4)
		| ROL32(x & 0x01808004, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x08021010, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x20010420, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 0, 2), (2, 3, 1, 0), (1, 0, 2, 3), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 1, 14, 7, 12, 9, 6, 3, 4, 13, 2, 11]
void BOGI32_omega_diffusion_503(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800204)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x20200108, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x10100402, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x40400801, 24)
		| ((x & 0x01081010) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_503(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800204)
		| ((x & 0x00108101) << 4)
		| ROL32(x & 0x01404008, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x04021010, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x20010820, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_504(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04084010) << 4)
		| ROL32(x & 0x10800104, 8)
		| ROL32(x & 0x08012020, 12)
		| ROL32(x & 0x80400408, 16)
		| ROL32(x & 0x02021080, 20)
		| ROL32(x & 0x40100801, 24)
		| ((x & 0x01048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_504(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00104804) << 4)
		| ROL32(x & 0x01401008, 8)
		| ROL32(x & 0x08002021, 12)
		| ROL32(x & 0x04088040, 16)
		| ROL32(x & 0x12020080, 20)
		| ROL32(x & 0x80010410, 24)
		| ((x & 0x40840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_505(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x04048010) << 4)
		| ROL32(x & 0x10800108, 8)
		| ROL32(x & 0x08012020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02021080, 20)
		| ROL32(x & 0x80100801, 24)
		| ((x & 0x01084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_505(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00108404) << 4)
		| ROL32(x & 0x01801008, 8)
		| ROL32(x & 0x08002021, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x12020080, 20)
		| ROL32(x & 0x80010810, 24)
		| ((x & 0x40480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 1, 10, 7, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_506(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08084010) << 4)
		| ROL32(x & 0x10400104, 8)
		| ROL32(x & 0x04012020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02021040, 20)
		| ROL32(x & 0x40100401, 24)
		| ((x & 0x01048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_506(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00104808) << 4)
		| ROL32(x & 0x01401004, 8)
		| ROL32(x & 0x04002021, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x12020040, 20)
		| ROL32(x & 0x40010410, 24)
		| ((x & 0x80840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 1, 3), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 13, 10, 7, 12, 1, 6, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_507(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x08048010) << 4)
		| ROL32(x & 0x10400108, 8)
		| ROL32(x & 0x04012020, 12)
		| ROL32(x & 0x40800804, 16)
		| ROL32(x & 0x02021040, 20)
		| ROL32(x & 0x80100401, 24)
		| ((x & 0x01084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_507(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200202)
		| ((x & 0x00108408) << 4)
		| ROL32(x & 0x01801004, 8)
		| ROL32(x & 0x04002021, 12)
		| ROL32(x & 0x08044080, 16)
		| ROL32(x & 0x12020040, 20)
		| ROL32(x & 0x40010810, 24)
		| ((x & 0x80480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 3, 1), (1, 3, 0, 2), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 13, 10, 7, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_508(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x04048010) << 4)
		| ROL32(x & 0x10800102, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80100201, 24)
		| ((x & 0x01024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_508(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200808)
		| ((x & 0x00102404) << 4)
		| ROL32(x & 0x01801002, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x80010210, 24)
		| ((x & 0x40480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 2, 3, 1), (2, 0, 1, 3), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 1, 10, 7, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_509(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x08084010) << 4)
		| ROL32(x & 0x10400102, 8)
		| ROL32(x & 0x02012020, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40100201, 24)
		| ((x & 0x01028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_509(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20200404)
		| ((x & 0x00102808) << 4)
		| ROL32(x & 0x01401002, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x12020020, 20)
		| ROL32(x & 0x40010210, 24)
		| ((x & 0x80840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 3, 1, 2), (1, 2, 0, 3), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 9, 14, 7, 12, 1, 6, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_510(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x04028010) << 4)
		| ROL32(x & 0x10800108, 8)
		| ROL32(x & 0x08012040, 12)
		| ROL32(x & 0x40200402, 16)
		| ROL32(x & 0x02041080, 20)
		| ROL32(x & 0x80100801, 24)
		| ((x & 0x01084020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_510(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20400204)
		| ((x & 0x00108402) << 4)
		| ROL32(x & 0x01801008, 8)
		| ROL32(x & 0x08002041, 12)
		| ROL32(x & 0x04024020, 16)
		| ROL32(x & 0x12040080, 20)
		| ROL32(x & 0x80010810, 24)
		| ((x & 0x40280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (0, 3, 1, 2), (2, 0, 3, 1), (1, 2, 0, 3))
//[4, 9, 2, 15, 8, 1, 14, 7, 0, 13, 6, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_511(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x08024010) << 4)
		| ROL32(x & 0x10400104, 8)
		| ROL32(x & 0x04012080, 12)
		| ROL32(x & 0x80200802, 16)
		| ROL32(x & 0x02081040, 20)
		| ROL32(x & 0x40100401, 24)
		| ((x & 0x01048020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_511(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20800208)
		| ((x & 0x00104802) << 4)
		| ROL32(x & 0x01401004, 8)
		| ROL32(x & 0x04002081, 12)
		| ROL32(x & 0x08028020, 16)
		| ROL32(x & 0x12080040, 20)
		| ROL32(x & 0x40010410, 24)
		| ((x & 0x80240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 0, 3, 2), (0, 2, 1, 3), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 9, 2, 7, 0, 5, 14, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_512(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02082010) << 4)
		| ROL32(x & 0x10800102, 8)
		| ROL32(x & 0x08014040, 12)
		| ROL32(x & 0x80200208, 16)
		| ROL32(x & 0x04041080, 20)
		| ROL32(x & 0x20100801, 24)
		| ((x & 0x01028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_512(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00102802) << 4)
		| ROL32(x & 0x01201008, 8)
		| ROL32(x & 0x08004041, 12)
		| ROL32(x & 0x02088020, 16)
		| ROL32(x & 0x14040080, 20)
		| ROL32(x & 0x80010210, 24)
		| ((x & 0x20820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 0, 3, 2), (2, 3, 0, 1), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 13, 2, 7, 4, 1, 14, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_513(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02042010) << 4)
		| ROL32(x & 0x10400102, 8)
		| ROL32(x & 0x04018080, 12)
		| ROL32(x & 0x40200204, 16)
		| ROL32(x & 0x08081040, 20)
		| ROL32(x & 0x20100401, 24)
		| ((x & 0x01024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_513(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00102402) << 4)
		| ROL32(x & 0x01201004, 8)
		| ROL32(x & 0x04008081, 12)
		| ROL32(x & 0x02044020, 16)
		| ROL32(x & 0x18080040, 20)
		| ROL32(x & 0x40010210, 24)
		| ((x & 0x20420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 2, 0, 3), (0, 3, 1, 2), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 13, 10, 7, 12, 5, 2, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_514(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x02048010) << 4)
		| ROL32(x & 0x10800108, 8)
		| ROL32(x & 0x08014020, 12)
		| ROL32(x & 0x20400204, 16)
		| ROL32(x & 0x04021080, 20)
		| ROL32(x & 0x80100801, 24)
		| ((x & 0x01082040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_514(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40200402)
		| ((x & 0x00108204) << 4)
		| ROL32(x & 0x01801008, 8)
		| ROL32(x & 0x08004021, 12)
		| ROL32(x & 0x02042040, 16)
		| ROL32(x & 0x14020080, 20)
		| ROL32(x & 0x80010810, 24)
		| ((x & 0x20480100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 2, 0, 3), (2, 0, 3, 1), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 1, 10, 7, 4, 13, 2, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_515(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x02084010) << 4)
		| ROL32(x & 0x10400104, 8)
		| ROL32(x & 0x04018020, 12)
		| ROL32(x & 0x20800208, 16)
		| ROL32(x & 0x08021040, 20)
		| ROL32(x & 0x40100401, 24)
		| ((x & 0x01042080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_515(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80200802)
		| ((x & 0x00104208) << 4)
		| ROL32(x & 0x01401004, 8)
		| ROL32(x & 0x04008021, 12)
		| ROL32(x & 0x02082080, 16)
		| ROL32(x & 0x18020040, 20)
		| ROL32(x & 0x40010410, 24)
		| ((x & 0x20840100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 1, 3), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 9, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_516(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x02028010) << 4)
		| ROL32(x & 0x10800108, 8)
		| ROL32(x & 0x08014040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04041080, 20)
		| ROL32(x & 0x80100801, 24)
		| ((x & 0x01082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_516(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00108202) << 4)
		| ROL32(x & 0x01801008, 8)
		| ROL32(x & 0x08004041, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x14040080, 20)
		| ROL32(x & 0x80010810, 24)
		| ((x & 0x20280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (0, 2, 3, 1), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 9, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_517(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x02028010) << 4)
		| ROL32(x & 0x10800104, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08081080, 20)
		| ROL32(x & 0x80100401, 24)
		| ((x & 0x01042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_517(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400808)
		| ((x & 0x00104202) << 4)
		| ROL32(x & 0x01801004, 8)
		| ROL32(x & 0x08008081, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x80010410, 24)
		| ((x & 0x20280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 1, 3), (0, 2, 3, 1))
//[0, 9, 6, 15, 8, 1, 14, 7, 12, 5, 2, 11, 4, 13, 10, 3]
void BOGI32_omega_diffusion_518(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x02024010) << 4)
		| ROL32(x & 0x10400108, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x04041040, 20)
		| ROL32(x & 0x40100801, 24)
		| ((x & 0x01082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_518(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800404)
		| ((x & 0x00108202) << 4)
		| ROL32(x & 0x01401008, 8)
		| ROL32(x & 0x04004041, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x40010810, 24)
		| ((x & 0x20240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (1, 3, 0, 2), (2, 0, 3, 1), (0, 2, 1, 3))
//[0, 9, 6, 15, 8, 1, 14, 7, 4, 13, 2, 11, 12, 5, 10, 3]
void BOGI32_omega_diffusion_519(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x02024010) << 4)
		| ROL32(x & 0x10400104, 8)
		| ROL32(x & 0x04018080, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x08081040, 20)
		| ROL32(x & 0x40100401, 24)
		| ((x & 0x01042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_519(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00104202) << 4)
		| ROL32(x & 0x01401004, 8)
		| ROL32(x & 0x04008081, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x18080040, 20)
		| ROL32(x & 0x40010410, 24)
		| ((x & 0x20240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 1, 3), (0, 2, 3, 1), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 9, 2, 7, 0, 13, 6, 11, 8, 5, 14, 3]
void BOGI32_omega_diffusion_520(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x08082010) << 4)
		| ROL32(x & 0x10200104, 8)
		| ROL32(x & 0x04014040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20100401, 24)
		| ((x & 0x01048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_520(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400202)
		| ((x & 0x00104808) << 4)
		| ROL32(x & 0x01201004, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x14040040, 20)
		| ROL32(x & 0x20010410, 24)
		| ((x & 0x80820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 1, 3), (1, 3, 0, 2), (0, 2, 3, 1))
//[0, 5, 10, 15, 8, 13, 2, 7, 12, 1, 6, 11, 4, 9, 14, 3]
void BOGI32_omega_diffusion_521(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x04042010) << 4)
		| ROL32(x & 0x10200108, 8)
		| ROL32(x & 0x08018080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x02021020, 20)
		| ROL32(x & 0x20100801, 24)
		| ((x & 0x01084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_521(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800202)
		| ((x & 0x00108404) << 4)
		| ROL32(x & 0x01201008, 8)
		| ROL32(x & 0x02002021, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x18080080, 20)
		| ROL32(x & 0x20010810, 24)
		| ((x & 0x40420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (0, 2, 1, 3), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 9, 2, 7, 0, 5, 14, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_522(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08082010) << 4)
		| ROL32(x & 0x10200102, 8)
		| ROL32(x & 0x02014040, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x04041020, 20)
		| ROL32(x & 0x20100201, 24)
		| ((x & 0x01028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_522(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00102808) << 4)
		| ROL32(x & 0x01201002, 8)
		| ROL32(x & 0x02004041, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x14040020, 20)
		| ROL32(x & 0x20010210, 24)
		| ((x & 0x80820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (0, 3, 1, 2), (1, 2, 0, 3))
//[4, 1, 10, 15, 8, 13, 2, 7, 0, 5, 14, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_523(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x08042010) << 4)
		| ROL32(x & 0x10200102, 8)
		| ROL32(x & 0x02014080, 12)
		| ROL32(x & 0x80400804, 16)
		| ROL32(x & 0x04081020, 20)
		| ROL32(x & 0x20100201, 24)
		| ((x & 0x01028040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_523(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40800408)
		| ((x & 0x00102804) << 4)
		| ROL32(x & 0x01201002, 8)
		| ROL32(x & 0x02004081, 12)
		| ROL32(x & 0x08048040, 16)
		| ROL32(x & 0x14080020, 20)
		| ROL32(x & 0x20010210, 24)
		| ((x & 0x80420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (1, 2, 0, 3), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 9, 2, 7, 4, 1, 14, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_524(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x04082010) << 4)
		| ROL32(x & 0x10200102, 8)
		| ROL32(x & 0x02018040, 12)
		| ROL32(x & 0x40800408, 16)
		| ROL32(x & 0x08041020, 20)
		| ROL32(x & 0x20100201, 24)
		| ((x & 0x01024080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_524(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80400804)
		| ((x & 0x00102408) << 4)
		| ROL32(x & 0x01201002, 8)
		| ROL32(x & 0x02008041, 12)
		| ROL32(x & 0x04084080, 16)
		| ROL32(x & 0x18040020, 20)
		| ROL32(x & 0x20010210, 24)
		| ((x & 0x40820100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 0, 3, 1), (1, 3, 0, 2), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 13, 2, 7, 4, 1, 14, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_525(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04042010) << 4)
		| ROL32(x & 0x10200102, 8)
		| ROL32(x & 0x02018080, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x08081020, 20)
		| ROL32(x & 0x20100201, 24)
		| ((x & 0x01024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_525(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00102404) << 4)
		| ROL32(x & 0x01201002, 8)
		| ROL32(x & 0x02008081, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x18080020, 20)
		| ROL32(x & 0x20010210, 24)
		| ((x & 0x40420100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 3, 0, 1), (0, 2, 1, 3), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 9, 14, 7, 12, 5, 2, 11, 8, 13, 6, 3]
void BOGI32_omega_diffusion_526(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x08028010) << 4)
		| ROL32(x & 0x10200108, 8)
		| ROL32(x & 0x02014040, 12)
		| ROL32(x & 0x20800802, 16)
		| ROL32(x & 0x04041020, 20)
		| ROL32(x & 0x80100201, 24)
		| ((x & 0x01082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_526(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40400404)
		| ((x & 0x00108208) << 4)
		| ROL32(x & 0x01801002, 8)
		| ROL32(x & 0x02004041, 12)
		| ROL32(x & 0x08022080, 16)
		| ROL32(x & 0x14040020, 20)
		| ROL32(x & 0x20010810, 24)
		| ((x & 0x80280100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 1, 2, 0), (2, 3, 0, 1), (1, 0, 3, 2), (0, 2, 1, 3))
//[0, 5, 10, 15, 8, 1, 14, 7, 4, 13, 2, 11, 12, 9, 6, 3]
void BOGI32_omega_diffusion_527(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x04024010) << 4)
		| ROL32(x & 0x10200104, 8)
		| ROL32(x & 0x02018080, 12)
		| ROL32(x & 0x20400402, 16)
		| ROL32(x & 0x08081020, 20)
		| ROL32(x & 0x40100201, 24)
		| ((x & 0x01042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_527(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80800808)
		| ((x & 0x00104204) << 4)
		| ROL32(x & 0x01401002, 8)
		| ROL32(x & 0x02008081, 12)
		| ROL32(x & 0x04022040, 16)
		| ROL32(x & 0x18080020, 20)
		| ROL32(x & 0x20010410, 24)
		| ((x & 0x40240100) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 1, 6, 11, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_528(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100802)
		| ((x & 0x04084020) << 4)
		| ROL32(x & 0x80800204, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10400408, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x40200101, 24)
		| ((x & 0x02041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_528(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100802)
		| ((x & 0x00204104) << 4)
		| ROL32(x & 0x01402001, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x04081040, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x80020480, 24)
		| ((x & 0x40840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 2, 3), (2, 3, 1, 0), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 13, 6, 11, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_529(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100402)
		| ((x & 0x08048020) << 4)
		| ROL32(x & 0x40400208, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10800804, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x80200101, 24)
		| ((x & 0x02081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_529(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100402)
		| ((x & 0x00208108) << 4)
		| ROL32(x & 0x01802001, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x08041080, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x40020840, 24)
		| ((x & 0x80480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 1, 0))
//[8, 5, 2, 15, 12, 1, 6, 11, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_530(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100804)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x80800202, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10200408, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x40400101, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_530(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100804)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x01404001, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x04081020, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x80020280, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (1, 3, 2, 0), (2, 0, 1, 3))
//[8, 5, 2, 15, 0, 13, 6, 11, 4, 9, 14, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_531(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100808)
		| ((x & 0x04048040) << 4)
		| ROL32(x & 0x40800202, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10200404, 16)
		| ROL32(x & 0x08084080, 20)
		| ROL32(x & 0x80400101, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_531(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100808)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x01804001, 8)
		| ROL32(x & 0x08008084, 12)
		| ROL32(x & 0x04041020, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x80020240, 24)
		| ((x & 0x40480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (2, 0, 1, 3), (1, 3, 2, 0))
//[4, 9, 2, 15, 12, 1, 6, 11, 8, 5, 14, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_532(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100404)
		| ((x & 0x08084080) << 4)
		| ROL32(x & 0x80400202, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10200808, 16)
		| ROL32(x & 0x04048040, 20)
		| ROL32(x & 0x40800101, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_532(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100404)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x01408001, 8)
		| ROL32(x & 0x04004048, 12)
		| ROL32(x & 0x08081020, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x40020280, 24)
		| ((x & 0x80840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 1, 3, 2), (2, 3, 1, 0), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 13, 6, 11, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_533(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100408)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x40400202, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10200804, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x80800101, 24)
		| ((x & 0x02021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_533(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100408)
		| ((x & 0x00202102) << 4)
		| ROL32(x & 0x01808001, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x08041020, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x40020240, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 3, 1, 2), (1, 0, 2, 3), (2, 1, 3, 0))
//[8, 5, 2, 15, 4, 1, 14, 11, 12, 9, 6, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_534(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100204)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10200402, 16)
		| ROL32(x & 0x02048080, 20)
		| ROL32(x & 0x40400101, 24)
		| ((x & 0x08081020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_534(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100204)
		| ((x & 0x00808102) << 4)
		| ROL32(x & 0x01404001, 8)
		| ROL32(x & 0x08002048, 12)
		| ROL32(x & 0x04021020, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (0, 3, 1, 2), (2, 1, 3, 0), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 5, 14, 11, 8, 13, 6, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_535(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100208)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01012010, 12)
		| ROL32(x & 0x10200802, 16)
		| ROL32(x & 0x02084040, 20)
		| ROL32(x & 0x80800101, 24)
		| ((x & 0x04041020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_535(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100208)
		| ((x & 0x00404102) << 4)
		| ROL32(x & 0x01808001, 8)
		| ROL32(x & 0x04002084, 12)
		| ROL32(x & 0x08021020, 16)
		| ROL32(x & 0x12010010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_536(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100802)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x80800404, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10400208, 16)
		| ROL32(x & 0x08028080, 20)
		| ROL32(x & 0x20200101, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_536(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100802)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x01202001, 8)
		| ROL32(x & 0x08008028, 12)
		| ROL32(x & 0x02081040, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x80040480, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (0, 3, 1, 2), (2, 1, 3, 0))
//[8, 1, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_537(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100402)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x80800808, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10400204, 16)
		| ROL32(x & 0x04028080, 20)
		| ROL32(x & 0x20200101, 24)
		| ((x & 0x08081040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_537(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100402)
		| ((x & 0x00808104) << 4)
		| ROL32(x & 0x01202001, 8)
		| ROL32(x & 0x08004028, 12)
		| ROL32(x & 0x02041040, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x80080880, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (2, 1, 3, 0), (0, 3, 1, 2))
//[0, 9, 6, 15, 12, 5, 2, 11, 4, 13, 10, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_538(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100802)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x40400404, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10800208, 16)
		| ROL32(x & 0x08024040, 20)
		| ROL32(x & 0x20200101, 24)
		| ((x & 0x04041080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_538(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100802)
		| ((x & 0x00404108) << 4)
		| ROL32(x & 0x01202001, 8)
		| ROL32(x & 0x04008024, 12)
		| ROL32(x & 0x02081080, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x40040440, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 2, 3), (2, 3, 1, 0), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 13, 2, 11, 12, 5, 10, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_539(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100402)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x40400808, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10800204, 16)
		| ROL32(x & 0x04024040, 20)
		| ROL32(x & 0x20200101, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_539(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100402)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x01202001, 8)
		| ROL32(x & 0x04004024, 12)
		| ROL32(x & 0x02041080, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x40080840, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 1, 0))
//[8, 1, 6, 15, 12, 5, 2, 11, 4, 9, 14, 3, 0, 13, 10, 7]
void BOGI32_omega_diffusion_540(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100804)
		| ((x & 0x02082040) << 4)
		| ROL32(x & 0x80800402, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10200208, 16)
		| ROL32(x & 0x08048080, 20)
		| ROL32(x & 0x20400101, 24)
		| ((x & 0x04021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_540(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100804)
		| ((x & 0x00402102) << 4)
		| ROL32(x & 0x01204001, 8)
		| ROL32(x & 0x08008048, 12)
		| ROL32(x & 0x02081020, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x80040280, 24)
		| ((x & 0x20820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 0, 3, 2), (2, 3, 1, 0), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 13, 2, 11, 8, 5, 14, 3, 12, 1, 10, 7]
void BOGI32_omega_diffusion_541(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100408)
		| ((x & 0x02042080) << 4)
		| ROL32(x & 0x40400802, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10200204, 16)
		| ROL32(x & 0x04084040, 20)
		| ROL32(x & 0x20800101, 24)
		| ((x & 0x08021020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_541(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100408)
		| ((x & 0x00802102) << 4)
		| ROL32(x & 0x01208001, 8)
		| ROL32(x & 0x04004084, 12)
		| ROL32(x & 0x02041020, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x40080240, 24)
		| ((x & 0x20420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 3, 2, 0), (0, 1, 3, 2), (2, 0, 1, 3))
//[8, 1, 6, 15, 0, 5, 14, 11, 4, 13, 10, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_542(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100808)
		| ((x & 0x02028020) << 4)
		| ROL32(x & 0x20800404, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10400202, 16)
		| ROL32(x & 0x08082080, 20)
		| ROL32(x & 0x80200101, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_542(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100808)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x01802001, 8)
		| ROL32(x & 0x08008082, 12)
		| ROL32(x & 0x02021040, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x80040420, 24)
		| ((x & 0x20280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (1, 3, 2, 0), (2, 0, 1, 3), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 1, 14, 11, 12, 5, 10, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_543(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100404)
		| ((x & 0x02024020) << 4)
		| ROL32(x & 0x20400808, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10800202, 16)
		| ROL32(x & 0x04042040, 20)
		| ROL32(x & 0x40200101, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_543(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100404)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x01402001, 8)
		| ROL32(x & 0x04004042, 12)
		| ROL32(x & 0x02021080, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x40080820, 24)
		| ((x & 0x20240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 0, 1, 3), (0, 1, 3, 2), (1, 3, 2, 0))
//[4, 1, 10, 15, 12, 5, 2, 11, 8, 13, 6, 3, 0, 9, 14, 7]
void BOGI32_omega_diffusion_544(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100202)
		| ((x & 0x08082080) << 4)
		| ROL32(x & 0x80200404, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10400808, 16)
		| ROL32(x & 0x02028020, 20)
		| ROL32(x & 0x20800101, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_544(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100202)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x01208001, 8)
		| ROL32(x & 0x02002028, 12)
		| ROL32(x & 0x08081040, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x20040480, 24)
		| ((x & 0x80820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 0, 1, 3), (1, 3, 2, 0), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 13, 2, 11, 12, 9, 6, 3, 8, 1, 14, 7]
void BOGI32_omega_diffusion_545(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100202)
		| ((x & 0x04042040) << 4)
		| ROL32(x & 0x40200808, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10800404, 16)
		| ROL32(x & 0x02024020, 20)
		| ROL32(x & 0x20400101, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_545(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100202)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x01204001, 8)
		| ROL32(x & 0x02002024, 12)
		| ROL32(x & 0x04041080, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x20080840, 24)
		| ((x & 0x40420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 1, 3, 0), (0, 3, 1, 2), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 13, 6, 11, 8, 5, 14, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_546(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100408)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10400804, 16)
		| ROL32(x & 0x04082020, 20)
		| ROL32(x & 0x80800101, 24)
		| ((x & 0x02021040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_546(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100408)
		| ((x & 0x00202104) << 4)
		| ROL32(x & 0x01808001, 8)
		| ROL32(x & 0x02004082, 12)
		| ROL32(x & 0x08041040, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 1, 3, 0), (1, 0, 2, 3), (0, 3, 1, 2))
//[0, 5, 10, 15, 12, 1, 6, 11, 4, 9, 14, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_547(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100804)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x20200202, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10800408, 16)
		| ROL32(x & 0x08042020, 20)
		| ROL32(x & 0x40400101, 24)
		| ((x & 0x02021080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_547(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100804)
		| ((x & 0x00202108) << 4)
		| ROL32(x & 0x01404001, 8)
		| ROL32(x & 0x02008042, 12)
		| ROL32(x & 0x04081080, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x20020220, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_548(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100204)
		| ((x & 0x08028040) << 4)
		| ROL32(x & 0x20200408, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10800802, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x80400101, 24)
		| ((x & 0x04081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_548(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100204)
		| ((x & 0x00408108) << 4)
		| ROL32(x & 0x01804001, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x08021080, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x20040820, 24)
		| ((x & 0x80280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_549(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100208)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x20200404, 8)
		| ROL32(x & 0x01014010, 12)
		| ROL32(x & 0x10400802, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x80800101, 24)
		| ((x & 0x04041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_549(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100208)
		| ((x & 0x00404104) << 4)
		| ROL32(x & 0x01808001, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x08021040, 16)
		| ROL32(x & 0x14010010, 20)
		| ROL32(x & 0x20040420, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 6, 3, 8, 13, 2, 7]
void BOGI32_omega_diffusion_550(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100204)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x20200808, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10800402, 16)
		| ROL32(x & 0x02042020, 20)
		| ROL32(x & 0x40400101, 24)
		| ((x & 0x08081080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_550(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100204)
		| ((x & 0x00808108) << 4)
		| ROL32(x & 0x01404001, 8)
		| ROL32(x & 0x02002042, 12)
		| ROL32(x & 0x04021080, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x20080820, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 0, 1), (2, 3, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 6, 3, 12, 9, 2, 7]
void BOGI32_omega_diffusion_551(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100208)
		| ((x & 0x04024080) << 4)
		| ROL32(x & 0x20200804, 8)
		| ROL32(x & 0x01018010, 12)
		| ROL32(x & 0x10400402, 16)
		| ROL32(x & 0x02082020, 20)
		| ROL32(x & 0x40800101, 24)
		| ((x & 0x08041040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_551(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100208)
		| ((x & 0x00804104) << 4)
		| ROL32(x & 0x01408001, 8)
		| ROL32(x & 0x02002082, 12)
		| ROL32(x & 0x04021040, 16)
		| ROL32(x & 0x18010010, 20)
		| ROL32(x & 0x20080420, 24)
		| ((x & 0x40240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (1, 0, 3, 2), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_552(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x04084020) << 4)
		| ROL32(x & 0x10800204, 8)
		| ROL32(x & 0x08012010, 12)
		| ROL32(x & 0x80400408, 16)
		| ROL32(x & 0x01021080, 20)
		| ROL32(x & 0x40200801, 24)
		| ((x & 0x02048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_552(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x00204804) << 4)
		| ROL32(x & 0x01402008, 8)
		| ROL32(x & 0x08001021, 12)
		| ROL32(x & 0x04088040, 16)
		| ROL32(x & 0x12010080, 20)
		| ROL32(x & 0x80020410, 24)
		| ((x & 0x40840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (1, 3, 0, 2), (2, 0, 3, 1))
//[8, 5, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_553(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x04048020) << 4)
		| ROL32(x & 0x10800208, 8)
		| ROL32(x & 0x08012010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01021080, 20)
		| ROL32(x & 0x80200801, 24)
		| ((x & 0x02084040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_553(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x00208404) << 4)
		| ROL32(x & 0x01802008, 8)
		| ROL32(x & 0x08001021, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x12010080, 20)
		| ROL32(x & 0x80020810, 24)
		| ((x & 0x40480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (2, 0, 3, 1), (1, 3, 0, 2))
//[4, 9, 2, 15, 12, 1, 6, 11, 0, 13, 10, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_554(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x08084020) << 4)
		| ROL32(x & 0x10400204, 8)
		| ROL32(x & 0x04012010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01021040, 20)
		| ROL32(x & 0x40200401, 24)
		| ((x & 0x02048080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_554(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x00204808) << 4)
		| ROL32(x & 0x01402004, 8)
		| ROL32(x & 0x04001021, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x12010040, 20)
		| ROL32(x & 0x40020410, 24)
		| ((x & 0x80840200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 2, 3), (2, 3, 0, 1), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 13, 6, 11, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_555(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x08048020) << 4)
		| ROL32(x & 0x10400208, 8)
		| ROL32(x & 0x04012010, 12)
		| ROL32(x & 0x40800804, 16)
		| ROL32(x & 0x01021040, 20)
		| ROL32(x & 0x80200401, 24)
		| ((x & 0x02084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_555(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100102)
		| ((x & 0x00208408) << 4)
		| ROL32(x & 0x01802004, 8)
		| ROL32(x & 0x04001021, 12)
		| ROL32(x & 0x08044080, 16)
		| ROL32(x & 0x12010040, 20)
		| ROL32(x & 0x40020810, 24)
		| ((x & 0x80480200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 3, 2), (1, 0, 2, 3), (2, 3, 0, 1))
//[8, 5, 2, 15, 12, 1, 6, 11, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_556(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100104)
		| ((x & 0x04084040) << 4)
		| ROL32(x & 0x10800202, 8)
		| ROL32(x & 0x08012010, 12)
		| ROL32(x & 0x80200408, 16)
		| ROL32(x & 0x01041080, 20)
		| ROL32(x & 0x40400801, 24)
		| ((x & 0x02028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_556(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100104)
		| ((x & 0x00202802) << 4)
		| ROL32(x & 0x01404008, 8)
		| ROL32(x & 0x08001041, 12)
		| ROL32(x & 0x04088020, 16)
		| ROL32(x & 0x12010080, 20)
		| ROL32(x & 0x80020210, 24)
		| ((x & 0x40840400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 1, 3, 2), (2, 3, 0, 1), (1, 0, 2, 3))
//[4, 9, 2, 15, 0, 13, 6, 11, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_557(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100108)
		| ((x & 0x08048080) << 4)
		| ROL32(x & 0x10400202, 8)
		| ROL32(x & 0x04012010, 12)
		| ROL32(x & 0x40200804, 16)
		| ROL32(x & 0x01081040, 20)
		| ROL32(x & 0x80800401, 24)
		| ((x & 0x02024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_557(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100108)
		| ((x & 0x00202402) << 4)
		| ROL32(x & 0x01808004, 8)
		| ROL32(x & 0x04001081, 12)
		| ROL32(x & 0x08044020, 16)
		| ROL32(x & 0x12010040, 20)
		| ROL32(x & 0x40020210, 24)
		| ((x & 0x80480800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 3, 2, 1), (1, 0, 3, 2), (2, 1, 0, 3))
//[8, 5, 2, 15, 4, 1, 14, 11, 0, 13, 10, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_558(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100108)
		| ((x & 0x04024020) << 4)
		| ROL32(x & 0x10800804, 8)
		| ROL32(x & 0x02012010, 12)
		| ROL32(x & 0x80400402, 16)
		| ROL32(x & 0x01081080, 20)
		| ROL32(x & 0x40200201, 24)
		| ((x & 0x08048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_558(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100108)
		| ((x & 0x00804804) << 4)
		| ROL32(x & 0x01402002, 8)
		| ROL32(x & 0x08001081, 12)
		| ROL32(x & 0x04028040, 16)
		| ROL32(x & 0x12010020, 20)
		| ROL32(x & 0x80080410, 24)
		| ((x & 0x40240200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (0, 3, 2, 1), (2, 1, 0, 3), (1, 0, 3, 2))
//[4, 9, 2, 15, 0, 5, 14, 11, 12, 1, 10, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_559(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100104)
		| ((x & 0x08028020) << 4)
		| ROL32(x & 0x10400408, 8)
		| ROL32(x & 0x02012010, 12)
		| ROL32(x & 0x40800802, 16)
		| ROL32(x & 0x01041040, 20)
		| ROL32(x & 0x80200201, 24)
		| ((x & 0x04084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_559(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x20100104)
		| ((x & 0x00408408) << 4)
		| ROL32(x & 0x01802002, 8)
		| ROL32(x & 0x04001041, 12)
		| ROL32(x & 0x08024080, 16)
		| ROL32(x & 0x12010020, 20)
		| ROL32(x & 0x40040810, 24)
		| ((x & 0x80280200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 2, 3), (0, 1, 3, 2), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 5, 2, 11, 0, 13, 10, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_560(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100102)
		| ((x & 0x02082020) << 4)
		| ROL32(x & 0x10800404, 8)
		| ROL32(x & 0x08014010, 12)
		| ROL32(x & 0x80400208, 16)
		| ROL32(x & 0x01021080, 20)
		| ROL32(x & 0x20200801, 24)
		| ((x & 0x04048040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_560(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100102)
		| ((x & 0x00404804) << 4)
		| ROL32(x & 0x01202008, 8)
		| ROL32(x & 0x08001021, 12)
		| ROL32(x & 0x02088040, 16)
		| ROL32(x & 0x14010080, 20)
		| ROL32(x & 0x80040410, 24)
		| ((x & 0x20820200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 2, 3), (2, 3, 0, 1), (0, 1, 3, 2))
//[0, 9, 6, 15, 4, 13, 2, 11, 12, 1, 10, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_561(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100102)
		| ((x & 0x02042020) << 4)
		| ROL32(x & 0x10400808, 8)
		| ROL32(x & 0x04018010, 12)
		| ROL32(x & 0x40800204, 16)
		| ROL32(x & 0x01021040, 20)
		| ROL32(x & 0x20200401, 24)
		| ((x & 0x08084080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_561(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100102)
		| ((x & 0x00808408) << 4)
		| ROL32(x & 0x01202004, 8)
		| ROL32(x & 0x04001021, 12)
		| ROL32(x & 0x02044080, 16)
		| ROL32(x & 0x18010040, 20)
		| ROL32(x & 0x40080810, 24)
		| ((x & 0x20420200) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (0, 1, 2, 3), (2, 3, 0, 1))
//[8, 1, 6, 15, 12, 5, 2, 11, 0, 9, 14, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_562(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x02082040) << 4)
		| ROL32(x & 0x10800402, 8)
		| ROL32(x & 0x08014010, 12)
		| ROL32(x & 0x80200208, 16)
		| ROL32(x & 0x01041080, 20)
		| ROL32(x & 0x20400801, 24)
		| ((x & 0x04028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_562(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x00402802) << 4)
		| ROL32(x & 0x01204008, 8)
		| ROL32(x & 0x08001041, 12)
		| ROL32(x & 0x02088020, 16)
		| ROL32(x & 0x14010080, 20)
		| ROL32(x & 0x80040210, 24)
		| ((x & 0x20820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (0, 3, 2, 1), (2, 1, 0, 3))
//[8, 1, 6, 15, 4, 13, 2, 11, 0, 9, 14, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_563(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100108)
		| ((x & 0x02042040) << 4)
		| ROL32(x & 0x10800802, 8)
		| ROL32(x & 0x04014010, 12)
		| ROL32(x & 0x80200204, 16)
		| ROL32(x & 0x01081080, 20)
		| ROL32(x & 0x20400401, 24)
		| ((x & 0x08028020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_563(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100108)
		| ((x & 0x00802802) << 4)
		| ROL32(x & 0x01204004, 8)
		| ROL32(x & 0x08001081, 12)
		| ROL32(x & 0x02048020, 16)
		| ROL32(x & 0x14010040, 20)
		| ROL32(x & 0x80080210, 24)
		| ((x & 0x20420400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (2, 1, 0, 3), (0, 3, 2, 1))
//[0, 9, 6, 15, 12, 5, 2, 11, 8, 1, 14, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_564(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100104)
		| ((x & 0x02082080) << 4)
		| ROL32(x & 0x10400402, 8)
		| ROL32(x & 0x08018010, 12)
		| ROL32(x & 0x40200208, 16)
		| ROL32(x & 0x01041040, 20)
		| ROL32(x & 0x20800801, 24)
		| ((x & 0x04024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_564(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100104)
		| ((x & 0x00402402) << 4)
		| ROL32(x & 0x01208008, 8)
		| ROL32(x & 0x04001041, 12)
		| ROL32(x & 0x02084020, 16)
		| ROL32(x & 0x18010080, 20)
		| ROL32(x & 0x40040210, 24)
		| ((x & 0x20820800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 0, 3, 2), (2, 3, 0, 1), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 13, 2, 11, 8, 1, 14, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_565(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x02042080) << 4)
		| ROL32(x & 0x10400802, 8)
		| ROL32(x & 0x04018010, 12)
		| ROL32(x & 0x40200204, 16)
		| ROL32(x & 0x01081040, 20)
		| ROL32(x & 0x20800401, 24)
		| ((x & 0x08024020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_565(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x00802402) << 4)
		| ROL32(x & 0x01208004, 8)
		| ROL32(x & 0x04001081, 12)
		| ROL32(x & 0x02044020, 16)
		| ROL32(x & 0x18010040, 20)
		| ROL32(x & 0x40080210, 24)
		| ((x & 0x20420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 3, 0, 2), (0, 1, 2, 3), (2, 0, 3, 1))
//[8, 1, 6, 15, 0, 5, 14, 11, 12, 9, 2, 7, 4, 13, 10, 3]
void BOGI32_omega_diffusion_566(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x02028040) << 4)
		| ROL32(x & 0x10800408, 8)
		| ROL32(x & 0x08014010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01041080, 20)
		| ROL32(x & 0x80400801, 24)
		| ((x & 0x04082020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_566(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x00408202) << 4)
		| ROL32(x & 0x01804008, 8)
		| ROL32(x & 0x08001041, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x14010080, 20)
		| ROL32(x & 0x80040810, 24)
		| ((x & 0x20280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (1, 3, 0, 2), (2, 0, 3, 1), (0, 1, 2, 3))
//[0, 9, 6, 15, 4, 1, 14, 11, 8, 13, 2, 7, 12, 5, 10, 3]
void BOGI32_omega_diffusion_567(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x02024080) << 4)
		| ROL32(x & 0x10400804, 8)
		| ROL32(x & 0x04018010, 12)
		| ROL32(x & 0x20200202, 16)
		| ROL32(x & 0x01081040, 20)
		| ROL32(x & 0x40800401, 24)
		| ((x & 0x08042020) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_567(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x00804202) << 4)
		| ROL32(x & 0x01408004, 8)
		| ROL32(x & 0x04001081, 12)
		| ROL32(x & 0x02022020, 16)
		| ROL32(x & 0x18010040, 20)
		| ROL32(x & 0x40080410, 24)
		| ((x & 0x20240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 0, 3, 1), (0, 1, 2, 3), (1, 3, 0, 2))
//[4, 1, 10, 15, 12, 5, 2, 11, 0, 9, 14, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_568(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x08082040) << 4)
		| ROL32(x & 0x10200402, 8)
		| ROL32(x & 0x02014010, 12)
		| ROL32(x & 0x80800808, 16)
		| ROL32(x & 0x01041020, 20)
		| ROL32(x & 0x20400201, 24)
		| ((x & 0x04028080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_568(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x00402808) << 4)
		| ROL32(x & 0x01204002, 8)
		| ROL32(x & 0x02001041, 12)
		| ROL32(x & 0x08088080, 16)
		| ROL32(x & 0x14010020, 20)
		| ROL32(x & 0x20040210, 24)
		| ((x & 0x80820400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 0, 3, 1), (1, 3, 0, 2), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 13, 2, 11, 8, 1, 14, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_569(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x04042080) << 4)
		| ROL32(x & 0x10200802, 8)
		| ROL32(x & 0x02018010, 12)
		| ROL32(x & 0x40400404, 16)
		| ROL32(x & 0x01081020, 20)
		| ROL32(x & 0x20800201, 24)
		| ((x & 0x08024040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_569(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x00802404) << 4)
		| ROL32(x & 0x01208002, 8)
		| ROL32(x & 0x02001081, 12)
		| ROL32(x & 0x04044040, 16)
		| ROL32(x & 0x18010020, 20)
		| ROL32(x & 0x20080210, 24)
		| ((x & 0x40420800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 1, 0, 3), (0, 3, 2, 1), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 13, 6, 11, 12, 9, 2, 7, 8, 5, 14, 3]
void BOGI32_omega_diffusion_570(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100102)
		| ((x & 0x08048040) << 4)
		| ROL32(x & 0x10200208, 8)
		| ROL32(x & 0x04014010, 12)
		| ROL32(x & 0x20800804, 16)
		| ROL32(x & 0x01021020, 20)
		| ROL32(x & 0x80400401, 24)
		| ((x & 0x02082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_570(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100102)
		| ((x & 0x00208208) << 4)
		| ROL32(x & 0x01804004, 8)
		| ROL32(x & 0x02001021, 12)
		| ROL32(x & 0x08042080, 16)
		| ROL32(x & 0x14010040, 20)
		| ROL32(x & 0x20020810, 24)
		| ((x & 0x80480400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 1, 0, 3), (1, 0, 3, 2), (0, 3, 2, 1))
//[0, 5, 10, 15, 12, 1, 6, 11, 8, 13, 2, 7, 4, 9, 14, 3]
void BOGI32_omega_diffusion_571(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100102)
		| ((x & 0x04084080) << 4)
		| ROL32(x & 0x10200204, 8)
		| ROL32(x & 0x08018010, 12)
		| ROL32(x & 0x20400408, 16)
		| ROL32(x & 0x01021020, 20)
		| ROL32(x & 0x40800801, 24)
		| ((x & 0x02042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_571(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100102)
		| ((x & 0x00204204) << 4)
		| ROL32(x & 0x01408008, 8)
		| ROL32(x & 0x02001021, 12)
		| ROL32(x & 0x04082040, 16)
		| ROL32(x & 0x18010080, 20)
		| ROL32(x & 0x20020410, 24)
		| ((x & 0x40840800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 2, 3), (1, 0, 3, 2))
//[4, 1, 10, 15, 0, 5, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_572(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x08028040) << 4)
		| ROL32(x & 0x10200408, 8)
		| ROL32(x & 0x02014010, 12)
		| ROL32(x & 0x20800802, 16)
		| ROL32(x & 0x01041020, 20)
		| ROL32(x & 0x80400201, 24)
		| ((x & 0x04082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_572(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100104)
		| ((x & 0x00408208) << 4)
		| ROL32(x & 0x01804002, 8)
		| ROL32(x & 0x02001041, 12)
		| ROL32(x & 0x08022080, 16)
		| ROL32(x & 0x14010020, 20)
		| ROL32(x & 0x20040810, 24)
		| ((x & 0x80280400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (0, 1, 3, 2), (1, 0, 2, 3))
//[4, 1, 10, 15, 0, 5, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_573(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100108)
		| ((x & 0x08028080) << 4)
		| ROL32(x & 0x10200404, 8)
		| ROL32(x & 0x02014010, 12)
		| ROL32(x & 0x20400802, 16)
		| ROL32(x & 0x01081020, 20)
		| ROL32(x & 0x80800201, 24)
		| ((x & 0x04042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_573(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x40100108)
		| ((x & 0x00404204) << 4)
		| ROL32(x & 0x01808002, 8)
		| ROL32(x & 0x02001081, 12)
		| ROL32(x & 0x08022040, 16)
		| ROL32(x & 0x14010020, 20)
		| ROL32(x & 0x20040410, 24)
		| ((x & 0x80280800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 2, 3), (0, 1, 3, 2))
//[0, 5, 10, 15, 4, 1, 14, 11, 12, 9, 2, 7, 8, 13, 6, 3]
void BOGI32_omega_diffusion_574(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100104)
		| ((x & 0x04024040) << 4)
		| ROL32(x & 0x10200808, 8)
		| ROL32(x & 0x02018010, 12)
		| ROL32(x & 0x20800402, 16)
		| ROL32(x & 0x01041020, 20)
		| ROL32(x & 0x40400201, 24)
		| ((x & 0x08082080) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_574(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100104)
		| ((x & 0x00808208) << 4)
		| ROL32(x & 0x01404002, 8)
		| ROL32(x & 0x02001041, 12)
		| ROL32(x & 0x04022080, 16)
		| ROL32(x & 0x18010020, 20)
		| ROL32(x & 0x20080810, 24)
		| ((x & 0x40240400) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}
//((3, 2, 1, 0), (2, 3, 0, 1), (1, 0, 3, 2), (0, 1, 2, 3))
//[0, 5, 10, 15, 4, 1, 14, 11, 8, 13, 2, 7, 12, 9, 6, 3]
void BOGI32_omega_diffusion_575(DIFF_O_WRD_t * out, DIFF_I_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x04024080) << 4)
		| ROL32(x & 0x10200804, 8)
		| ROL32(x & 0x02018010, 12)
		| ROL32(x & 0x20400402, 16)
		| ROL32(x & 0x01081020, 20)
		| ROL32(x & 0x40800201, 24)
		| ((x & 0x08042040) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_O_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void BOGI32_omega_inv_diffusion_575(DIFF_I_WRD_t * out, DIFF_O_WRD_t * in)
{
	uint32_t x = 0;
	int i;

	for (i = 0; i < 8; i++)
	{
		x = (x << 4) | (in[i] & 0xf);
	}
	// 15 cycles, 8 masks
	x = (x & 0x80100108)
		| ((x & 0x00804204) << 4)
		| ROL32(x & 0x01408002, 8)
		| ROL32(x & 0x02001081, 12)
		| ROL32(x & 0x04022040, 16)
		| ROL32(x & 0x18010020, 20)
		| ROL32(x & 0x20080410, 24)
		| ((x & 0x40240800) >> 4);

	for (i = 7; i >= 0; i--)
	{
		out[i] = (DIFF_I_WRD_t)(x & 0xf);
		x = x >> 4;
	}
}

void(*BOGI32_omega_diffusion[576])(DIFF_O_WRD_t *, DIFF_I_WRD_t *) = {
	BOGI32_omega_diffusion_0, BOGI32_omega_diffusion_1, BOGI32_omega_diffusion_2, BOGI32_omega_diffusion_3,
	BOGI32_omega_diffusion_4, BOGI32_omega_diffusion_5, BOGI32_omega_diffusion_6, BOGI32_omega_diffusion_7,
	BOGI32_omega_diffusion_8, BOGI32_omega_diffusion_9, BOGI32_omega_diffusion_10, BOGI32_omega_diffusion_11,
	BOGI32_omega_diffusion_12, BOGI32_omega_diffusion_13, BOGI32_omega_diffusion_14, BOGI32_omega_diffusion_15,
	BOGI32_omega_diffusion_16, BOGI32_omega_diffusion_17, BOGI32_omega_diffusion_18, BOGI32_omega_diffusion_19,
	BOGI32_omega_diffusion_20, BOGI32_omega_diffusion_21, BOGI32_omega_diffusion_22, BOGI32_omega_diffusion_23,
	BOGI32_omega_diffusion_24, BOGI32_omega_diffusion_25, BOGI32_omega_diffusion_26, BOGI32_omega_diffusion_27,
	BOGI32_omega_diffusion_28, BOGI32_omega_diffusion_29, BOGI32_omega_diffusion_30, BOGI32_omega_diffusion_31,
	BOGI32_omega_diffusion_32, BOGI32_omega_diffusion_33, BOGI32_omega_diffusion_34, BOGI32_omega_diffusion_35,
	BOGI32_omega_diffusion_36, BOGI32_omega_diffusion_37, BOGI32_omega_diffusion_38, BOGI32_omega_diffusion_39,
	BOGI32_omega_diffusion_40, BOGI32_omega_diffusion_41, BOGI32_omega_diffusion_42, BOGI32_omega_diffusion_43,
	BOGI32_omega_diffusion_44, BOGI32_omega_diffusion_45, BOGI32_omega_diffusion_46, BOGI32_omega_diffusion_47,
	BOGI32_omega_diffusion_48, BOGI32_omega_diffusion_49, BOGI32_omega_diffusion_50, BOGI32_omega_diffusion_51,
	BOGI32_omega_diffusion_52, BOGI32_omega_diffusion_53, BOGI32_omega_diffusion_54, BOGI32_omega_diffusion_55,
	BOGI32_omega_diffusion_56, BOGI32_omega_diffusion_57, BOGI32_omega_diffusion_58, BOGI32_omega_diffusion_59,
	BOGI32_omega_diffusion_60, BOGI32_omega_diffusion_61, BOGI32_omega_diffusion_62, BOGI32_omega_diffusion_63,
	BOGI32_omega_diffusion_64, BOGI32_omega_diffusion_65, BOGI32_omega_diffusion_66, BOGI32_omega_diffusion_67,
	BOGI32_omega_diffusion_68, BOGI32_omega_diffusion_69, BOGI32_omega_diffusion_70, BOGI32_omega_diffusion_71,
	BOGI32_omega_diffusion_72, BOGI32_omega_diffusion_73, BOGI32_omega_diffusion_74, BOGI32_omega_diffusion_75,
	BOGI32_omega_diffusion_76, BOGI32_omega_diffusion_77, BOGI32_omega_diffusion_78, BOGI32_omega_diffusion_79,
	BOGI32_omega_diffusion_80, BOGI32_omega_diffusion_81, BOGI32_omega_diffusion_82, BOGI32_omega_diffusion_83,
	BOGI32_omega_diffusion_84, BOGI32_omega_diffusion_85, BOGI32_omega_diffusion_86, BOGI32_omega_diffusion_87,
	BOGI32_omega_diffusion_88, BOGI32_omega_diffusion_89, BOGI32_omega_diffusion_90, BOGI32_omega_diffusion_91,
	BOGI32_omega_diffusion_92, BOGI32_omega_diffusion_93, BOGI32_omega_diffusion_94, BOGI32_omega_diffusion_95,
	BOGI32_omega_diffusion_96, BOGI32_omega_diffusion_97, BOGI32_omega_diffusion_98, BOGI32_omega_diffusion_99,
	BOGI32_omega_diffusion_100, BOGI32_omega_diffusion_101, BOGI32_omega_diffusion_102, BOGI32_omega_diffusion_103,
	BOGI32_omega_diffusion_104, BOGI32_omega_diffusion_105, BOGI32_omega_diffusion_106, BOGI32_omega_diffusion_107,
	BOGI32_omega_diffusion_108, BOGI32_omega_diffusion_109, BOGI32_omega_diffusion_110, BOGI32_omega_diffusion_111,
	BOGI32_omega_diffusion_112, BOGI32_omega_diffusion_113, BOGI32_omega_diffusion_114, BOGI32_omega_diffusion_115,
	BOGI32_omega_diffusion_116, BOGI32_omega_diffusion_117, BOGI32_omega_diffusion_118, BOGI32_omega_diffusion_119,
	BOGI32_omega_diffusion_120, BOGI32_omega_diffusion_121, BOGI32_omega_diffusion_122, BOGI32_omega_diffusion_123,
	BOGI32_omega_diffusion_124, BOGI32_omega_diffusion_125, BOGI32_omega_diffusion_126, BOGI32_omega_diffusion_127,
	BOGI32_omega_diffusion_128, BOGI32_omega_diffusion_129, BOGI32_omega_diffusion_130, BOGI32_omega_diffusion_131,
	BOGI32_omega_diffusion_132, BOGI32_omega_diffusion_133, BOGI32_omega_diffusion_134, BOGI32_omega_diffusion_135,
	BOGI32_omega_diffusion_136, BOGI32_omega_diffusion_137, BOGI32_omega_diffusion_138, BOGI32_omega_diffusion_139,
	BOGI32_omega_diffusion_140, BOGI32_omega_diffusion_141, BOGI32_omega_diffusion_142, BOGI32_omega_diffusion_143,
	BOGI32_omega_diffusion_144, BOGI32_omega_diffusion_145, BOGI32_omega_diffusion_146, BOGI32_omega_diffusion_147,
	BOGI32_omega_diffusion_148, BOGI32_omega_diffusion_149, BOGI32_omega_diffusion_150, BOGI32_omega_diffusion_151,
	BOGI32_omega_diffusion_152, BOGI32_omega_diffusion_153, BOGI32_omega_diffusion_154, BOGI32_omega_diffusion_155,
	BOGI32_omega_diffusion_156, BOGI32_omega_diffusion_157, BOGI32_omega_diffusion_158, BOGI32_omega_diffusion_159,
	BOGI32_omega_diffusion_160, BOGI32_omega_diffusion_161, BOGI32_omega_diffusion_162, BOGI32_omega_diffusion_163,
	BOGI32_omega_diffusion_164, BOGI32_omega_diffusion_165, BOGI32_omega_diffusion_166, BOGI32_omega_diffusion_167,
	BOGI32_omega_diffusion_168, BOGI32_omega_diffusion_169, BOGI32_omega_diffusion_170, BOGI32_omega_diffusion_171,
	BOGI32_omega_diffusion_172, BOGI32_omega_diffusion_173, BOGI32_omega_diffusion_174, BOGI32_omega_diffusion_175,
	BOGI32_omega_diffusion_176, BOGI32_omega_diffusion_177, BOGI32_omega_diffusion_178, BOGI32_omega_diffusion_179,
	BOGI32_omega_diffusion_180, BOGI32_omega_diffusion_181, BOGI32_omega_diffusion_182, BOGI32_omega_diffusion_183,
	BOGI32_omega_diffusion_184, BOGI32_omega_diffusion_185, BOGI32_omega_diffusion_186, BOGI32_omega_diffusion_187,
	BOGI32_omega_diffusion_188, BOGI32_omega_diffusion_189, BOGI32_omega_diffusion_190, BOGI32_omega_diffusion_191,
	BOGI32_omega_diffusion_192, BOGI32_omega_diffusion_193, BOGI32_omega_diffusion_194, BOGI32_omega_diffusion_195,
	BOGI32_omega_diffusion_196, BOGI32_omega_diffusion_197, BOGI32_omega_diffusion_198, BOGI32_omega_diffusion_199,
	BOGI32_omega_diffusion_200, BOGI32_omega_diffusion_201, BOGI32_omega_diffusion_202, BOGI32_omega_diffusion_203,
	BOGI32_omega_diffusion_204, BOGI32_omega_diffusion_205, BOGI32_omega_diffusion_206, BOGI32_omega_diffusion_207,
	BOGI32_omega_diffusion_208, BOGI32_omega_diffusion_209, BOGI32_omega_diffusion_210, BOGI32_omega_diffusion_211,
	BOGI32_omega_diffusion_212, BOGI32_omega_diffusion_213, BOGI32_omega_diffusion_214, BOGI32_omega_diffusion_215,
	BOGI32_omega_diffusion_216, BOGI32_omega_diffusion_217, BOGI32_omega_diffusion_218, BOGI32_omega_diffusion_219,
	BOGI32_omega_diffusion_220, BOGI32_omega_diffusion_221, BOGI32_omega_diffusion_222, BOGI32_omega_diffusion_223,
	BOGI32_omega_diffusion_224, BOGI32_omega_diffusion_225, BOGI32_omega_diffusion_226, BOGI32_omega_diffusion_227,
	BOGI32_omega_diffusion_228, BOGI32_omega_diffusion_229, BOGI32_omega_diffusion_230, BOGI32_omega_diffusion_231,
	BOGI32_omega_diffusion_232, BOGI32_omega_diffusion_233, BOGI32_omega_diffusion_234, BOGI32_omega_diffusion_235,
	BOGI32_omega_diffusion_236, BOGI32_omega_diffusion_237, BOGI32_omega_diffusion_238, BOGI32_omega_diffusion_239,
	BOGI32_omega_diffusion_240, BOGI32_omega_diffusion_241, BOGI32_omega_diffusion_242, BOGI32_omega_diffusion_243,
	BOGI32_omega_diffusion_244, BOGI32_omega_diffusion_245, BOGI32_omega_diffusion_246, BOGI32_omega_diffusion_247,
	BOGI32_omega_diffusion_248, BOGI32_omega_diffusion_249, BOGI32_omega_diffusion_250, BOGI32_omega_diffusion_251,
	BOGI32_omega_diffusion_252, BOGI32_omega_diffusion_253, BOGI32_omega_diffusion_254, BOGI32_omega_diffusion_255,
	BOGI32_omega_diffusion_256, BOGI32_omega_diffusion_257, BOGI32_omega_diffusion_258, BOGI32_omega_diffusion_259,
	BOGI32_omega_diffusion_260, BOGI32_omega_diffusion_261, BOGI32_omega_diffusion_262, BOGI32_omega_diffusion_263,
	BOGI32_omega_diffusion_264, BOGI32_omega_diffusion_265, BOGI32_omega_diffusion_266, BOGI32_omega_diffusion_267,
	BOGI32_omega_diffusion_268, BOGI32_omega_diffusion_269, BOGI32_omega_diffusion_270, BOGI32_omega_diffusion_271,
	BOGI32_omega_diffusion_272, BOGI32_omega_diffusion_273, BOGI32_omega_diffusion_274, BOGI32_omega_diffusion_275,
	BOGI32_omega_diffusion_276, BOGI32_omega_diffusion_277, BOGI32_omega_diffusion_278, BOGI32_omega_diffusion_279,
	BOGI32_omega_diffusion_280, BOGI32_omega_diffusion_281, BOGI32_omega_diffusion_282, BOGI32_omega_diffusion_283,
	BOGI32_omega_diffusion_284, BOGI32_omega_diffusion_285, BOGI32_omega_diffusion_286, BOGI32_omega_diffusion_287,
	BOGI32_omega_diffusion_288, BOGI32_omega_diffusion_289, BOGI32_omega_diffusion_290, BOGI32_omega_diffusion_291,
	BOGI32_omega_diffusion_292, BOGI32_omega_diffusion_293, BOGI32_omega_diffusion_294, BOGI32_omega_diffusion_295,
	BOGI32_omega_diffusion_296, BOGI32_omega_diffusion_297, BOGI32_omega_diffusion_298, BOGI32_omega_diffusion_299,
	BOGI32_omega_diffusion_300, BOGI32_omega_diffusion_301, BOGI32_omega_diffusion_302, BOGI32_omega_diffusion_303,
	BOGI32_omega_diffusion_304, BOGI32_omega_diffusion_305, BOGI32_omega_diffusion_306, BOGI32_omega_diffusion_307,
	BOGI32_omega_diffusion_308, BOGI32_omega_diffusion_309, BOGI32_omega_diffusion_310, BOGI32_omega_diffusion_311,
	BOGI32_omega_diffusion_312, BOGI32_omega_diffusion_313, BOGI32_omega_diffusion_314, BOGI32_omega_diffusion_315,
	BOGI32_omega_diffusion_316, BOGI32_omega_diffusion_317, BOGI32_omega_diffusion_318, BOGI32_omega_diffusion_319,
	BOGI32_omega_diffusion_320, BOGI32_omega_diffusion_321, BOGI32_omega_diffusion_322, BOGI32_omega_diffusion_323,
	BOGI32_omega_diffusion_324, BOGI32_omega_diffusion_325, BOGI32_omega_diffusion_326, BOGI32_omega_diffusion_327,
	BOGI32_omega_diffusion_328, BOGI32_omega_diffusion_329, BOGI32_omega_diffusion_330, BOGI32_omega_diffusion_331,
	BOGI32_omega_diffusion_332, BOGI32_omega_diffusion_333, BOGI32_omega_diffusion_334, BOGI32_omega_diffusion_335,
	BOGI32_omega_diffusion_336, BOGI32_omega_diffusion_337, BOGI32_omega_diffusion_338, BOGI32_omega_diffusion_339,
	BOGI32_omega_diffusion_340, BOGI32_omega_diffusion_341, BOGI32_omega_diffusion_342, BOGI32_omega_diffusion_343,
	BOGI32_omega_diffusion_344, BOGI32_omega_diffusion_345, BOGI32_omega_diffusion_346, BOGI32_omega_diffusion_347,
	BOGI32_omega_diffusion_348, BOGI32_omega_diffusion_349, BOGI32_omega_diffusion_350, BOGI32_omega_diffusion_351,
	BOGI32_omega_diffusion_352, BOGI32_omega_diffusion_353, BOGI32_omega_diffusion_354, BOGI32_omega_diffusion_355,
	BOGI32_omega_diffusion_356, BOGI32_omega_diffusion_357, BOGI32_omega_diffusion_358, BOGI32_omega_diffusion_359,
	BOGI32_omega_diffusion_360, BOGI32_omega_diffusion_361, BOGI32_omega_diffusion_362, BOGI32_omega_diffusion_363,
	BOGI32_omega_diffusion_364, BOGI32_omega_diffusion_365, BOGI32_omega_diffusion_366, BOGI32_omega_diffusion_367,
	BOGI32_omega_diffusion_368, BOGI32_omega_diffusion_369, BOGI32_omega_diffusion_370, BOGI32_omega_diffusion_371,
	BOGI32_omega_diffusion_372, BOGI32_omega_diffusion_373, BOGI32_omega_diffusion_374, BOGI32_omega_diffusion_375,
	BOGI32_omega_diffusion_376, BOGI32_omega_diffusion_377, BOGI32_omega_diffusion_378, BOGI32_omega_diffusion_379,
	BOGI32_omega_diffusion_380, BOGI32_omega_diffusion_381, BOGI32_omega_diffusion_382, BOGI32_omega_diffusion_383,
	BOGI32_omega_diffusion_384, BOGI32_omega_diffusion_385, BOGI32_omega_diffusion_386, BOGI32_omega_diffusion_387,
	BOGI32_omega_diffusion_388, BOGI32_omega_diffusion_389, BOGI32_omega_diffusion_390, BOGI32_omega_diffusion_391,
	BOGI32_omega_diffusion_392, BOGI32_omega_diffusion_393, BOGI32_omega_diffusion_394, BOGI32_omega_diffusion_395,
	BOGI32_omega_diffusion_396, BOGI32_omega_diffusion_397, BOGI32_omega_diffusion_398, BOGI32_omega_diffusion_399,
	BOGI32_omega_diffusion_400, BOGI32_omega_diffusion_401, BOGI32_omega_diffusion_402, BOGI32_omega_diffusion_403,
	BOGI32_omega_diffusion_404, BOGI32_omega_diffusion_405, BOGI32_omega_diffusion_406, BOGI32_omega_diffusion_407,
	BOGI32_omega_diffusion_408, BOGI32_omega_diffusion_409, BOGI32_omega_diffusion_410, BOGI32_omega_diffusion_411,
	BOGI32_omega_diffusion_412, BOGI32_omega_diffusion_413, BOGI32_omega_diffusion_414, BOGI32_omega_diffusion_415,
	BOGI32_omega_diffusion_416, BOGI32_omega_diffusion_417, BOGI32_omega_diffusion_418, BOGI32_omega_diffusion_419,
	BOGI32_omega_diffusion_420, BOGI32_omega_diffusion_421, BOGI32_omega_diffusion_422, BOGI32_omega_diffusion_423,
	BOGI32_omega_diffusion_424, BOGI32_omega_diffusion_425, BOGI32_omega_diffusion_426, BOGI32_omega_diffusion_427,
	BOGI32_omega_diffusion_428, BOGI32_omega_diffusion_429, BOGI32_omega_diffusion_430, BOGI32_omega_diffusion_431,
	BOGI32_omega_diffusion_432, BOGI32_omega_diffusion_433, BOGI32_omega_diffusion_434, BOGI32_omega_diffusion_435,
	BOGI32_omega_diffusion_436, BOGI32_omega_diffusion_437, BOGI32_omega_diffusion_438, BOGI32_omega_diffusion_439,
	BOGI32_omega_diffusion_440, BOGI32_omega_diffusion_441, BOGI32_omega_diffusion_442, BOGI32_omega_diffusion_443,
	BOGI32_omega_diffusion_444, BOGI32_omega_diffusion_445, BOGI32_omega_diffusion_446, BOGI32_omega_diffusion_447,
	BOGI32_omega_diffusion_448, BOGI32_omega_diffusion_449, BOGI32_omega_diffusion_450, BOGI32_omega_diffusion_451,
	BOGI32_omega_diffusion_452, BOGI32_omega_diffusion_453, BOGI32_omega_diffusion_454, BOGI32_omega_diffusion_455,
	BOGI32_omega_diffusion_456, BOGI32_omega_diffusion_457, BOGI32_omega_diffusion_458, BOGI32_omega_diffusion_459,
	BOGI32_omega_diffusion_460, BOGI32_omega_diffusion_461, BOGI32_omega_diffusion_462, BOGI32_omega_diffusion_463,
	BOGI32_omega_diffusion_464, BOGI32_omega_diffusion_465, BOGI32_omega_diffusion_466, BOGI32_omega_diffusion_467,
	BOGI32_omega_diffusion_468, BOGI32_omega_diffusion_469, BOGI32_omega_diffusion_470, BOGI32_omega_diffusion_471,
	BOGI32_omega_diffusion_472, BOGI32_omega_diffusion_473, BOGI32_omega_diffusion_474, BOGI32_omega_diffusion_475,
	BOGI32_omega_diffusion_476, BOGI32_omega_diffusion_477, BOGI32_omega_diffusion_478, BOGI32_omega_diffusion_479,
	BOGI32_omega_diffusion_480, BOGI32_omega_diffusion_481, BOGI32_omega_diffusion_482, BOGI32_omega_diffusion_483,
	BOGI32_omega_diffusion_484, BOGI32_omega_diffusion_485, BOGI32_omega_diffusion_486, BOGI32_omega_diffusion_487,
	BOGI32_omega_diffusion_488, BOGI32_omega_diffusion_489, BOGI32_omega_diffusion_490, BOGI32_omega_diffusion_491,
	BOGI32_omega_diffusion_492, BOGI32_omega_diffusion_493, BOGI32_omega_diffusion_494, BOGI32_omega_diffusion_495,
	BOGI32_omega_diffusion_496, BOGI32_omega_diffusion_497, BOGI32_omega_diffusion_498, BOGI32_omega_diffusion_499,
	BOGI32_omega_diffusion_500, BOGI32_omega_diffusion_501, BOGI32_omega_diffusion_502, BOGI32_omega_diffusion_503,
	BOGI32_omega_diffusion_504, BOGI32_omega_diffusion_505, BOGI32_omega_diffusion_506, BOGI32_omega_diffusion_507,
	BOGI32_omega_diffusion_508, BOGI32_omega_diffusion_509, BOGI32_omega_diffusion_510, BOGI32_omega_diffusion_511,
	BOGI32_omega_diffusion_512, BOGI32_omega_diffusion_513, BOGI32_omega_diffusion_514, BOGI32_omega_diffusion_515,
	BOGI32_omega_diffusion_516, BOGI32_omega_diffusion_517, BOGI32_omega_diffusion_518, BOGI32_omega_diffusion_519,
	BOGI32_omega_diffusion_520, BOGI32_omega_diffusion_521, BOGI32_omega_diffusion_522, BOGI32_omega_diffusion_523,
	BOGI32_omega_diffusion_524, BOGI32_omega_diffusion_525, BOGI32_omega_diffusion_526, BOGI32_omega_diffusion_527,
	BOGI32_omega_diffusion_528, BOGI32_omega_diffusion_529, BOGI32_omega_diffusion_530, BOGI32_omega_diffusion_531,
	BOGI32_omega_diffusion_532, BOGI32_omega_diffusion_533, BOGI32_omega_diffusion_534, BOGI32_omega_diffusion_535,
	BOGI32_omega_diffusion_536, BOGI32_omega_diffusion_537, BOGI32_omega_diffusion_538, BOGI32_omega_diffusion_539,
	BOGI32_omega_diffusion_540, BOGI32_omega_diffusion_541, BOGI32_omega_diffusion_542, BOGI32_omega_diffusion_543,
	BOGI32_omega_diffusion_544, BOGI32_omega_diffusion_545, BOGI32_omega_diffusion_546, BOGI32_omega_diffusion_547,
	BOGI32_omega_diffusion_548, BOGI32_omega_diffusion_549, BOGI32_omega_diffusion_550, BOGI32_omega_diffusion_551,
	BOGI32_omega_diffusion_552, BOGI32_omega_diffusion_553, BOGI32_omega_diffusion_554, BOGI32_omega_diffusion_555,
	BOGI32_omega_diffusion_556, BOGI32_omega_diffusion_557, BOGI32_omega_diffusion_558, BOGI32_omega_diffusion_559,
	BOGI32_omega_diffusion_560, BOGI32_omega_diffusion_561, BOGI32_omega_diffusion_562, BOGI32_omega_diffusion_563,
	BOGI32_omega_diffusion_564, BOGI32_omega_diffusion_565, BOGI32_omega_diffusion_566, BOGI32_omega_diffusion_567,
	BOGI32_omega_diffusion_568, BOGI32_omega_diffusion_569, BOGI32_omega_diffusion_570, BOGI32_omega_diffusion_571,
	BOGI32_omega_diffusion_572, BOGI32_omega_diffusion_573, BOGI32_omega_diffusion_574, BOGI32_omega_diffusion_575,
};

void(*BOGI32_omega_inv_diffusion[576])(DIFF_I_WRD_t *, DIFF_O_WRD_t *) = {
	BOGI32_omega_inv_diffusion_0, BOGI32_omega_inv_diffusion_1, BOGI32_omega_inv_diffusion_2, BOGI32_omega_inv_diffusion_3,
	BOGI32_omega_inv_diffusion_4, BOGI32_omega_inv_diffusion_5, BOGI32_omega_inv_diffusion_6, BOGI32_omega_inv_diffusion_7,
	BOGI32_omega_inv_diffusion_8, BOGI32_omega_inv_diffusion_9, BOGI32_omega_inv_diffusion_10, BOGI32_omega_inv_diffusion_11,
	BOGI32_omega_inv_diffusion_12, BOGI32_omega_inv_diffusion_13, BOGI32_omega_inv_diffusion_14, BOGI32_omega_inv_diffusion_15,
	BOGI32_omega_inv_diffusion_16, BOGI32_omega_inv_diffusion_17, BOGI32_omega_inv_diffusion_18, BOGI32_omega_inv_diffusion_19,
	BOGI32_omega_inv_diffusion_20, BOGI32_omega_inv_diffusion_21, BOGI32_omega_inv_diffusion_22, BOGI32_omega_inv_diffusion_23,
	BOGI32_omega_inv_diffusion_24, BOGI32_omega_inv_diffusion_25, BOGI32_omega_inv_diffusion_26, BOGI32_omega_inv_diffusion_27,
	BOGI32_omega_inv_diffusion_28, BOGI32_omega_inv_diffusion_29, BOGI32_omega_inv_diffusion_30, BOGI32_omega_inv_diffusion_31,
	BOGI32_omega_inv_diffusion_32, BOGI32_omega_inv_diffusion_33, BOGI32_omega_inv_diffusion_34, BOGI32_omega_inv_diffusion_35,
	BOGI32_omega_inv_diffusion_36, BOGI32_omega_inv_diffusion_37, BOGI32_omega_inv_diffusion_38, BOGI32_omega_inv_diffusion_39,
	BOGI32_omega_inv_diffusion_40, BOGI32_omega_inv_diffusion_41, BOGI32_omega_inv_diffusion_42, BOGI32_omega_inv_diffusion_43,
	BOGI32_omega_inv_diffusion_44, BOGI32_omega_inv_diffusion_45, BOGI32_omega_inv_diffusion_46, BOGI32_omega_inv_diffusion_47,
	BOGI32_omega_inv_diffusion_48, BOGI32_omega_inv_diffusion_49, BOGI32_omega_inv_diffusion_50, BOGI32_omega_inv_diffusion_51,
	BOGI32_omega_inv_diffusion_52, BOGI32_omega_inv_diffusion_53, BOGI32_omega_inv_diffusion_54, BOGI32_omega_inv_diffusion_55,
	BOGI32_omega_inv_diffusion_56, BOGI32_omega_inv_diffusion_57, BOGI32_omega_inv_diffusion_58, BOGI32_omega_inv_diffusion_59,
	BOGI32_omega_inv_diffusion_60, BOGI32_omega_inv_diffusion_61, BOGI32_omega_inv_diffusion_62, BOGI32_omega_inv_diffusion_63,
	BOGI32_omega_inv_diffusion_64, BOGI32_omega_inv_diffusion_65, BOGI32_omega_inv_diffusion_66, BOGI32_omega_inv_diffusion_67,
	BOGI32_omega_inv_diffusion_68, BOGI32_omega_inv_diffusion_69, BOGI32_omega_inv_diffusion_70, BOGI32_omega_inv_diffusion_71,
	BOGI32_omega_inv_diffusion_72, BOGI32_omega_inv_diffusion_73, BOGI32_omega_inv_diffusion_74, BOGI32_omega_inv_diffusion_75,
	BOGI32_omega_inv_diffusion_76, BOGI32_omega_inv_diffusion_77, BOGI32_omega_inv_diffusion_78, BOGI32_omega_inv_diffusion_79,
	BOGI32_omega_inv_diffusion_80, BOGI32_omega_inv_diffusion_81, BOGI32_omega_inv_diffusion_82, BOGI32_omega_inv_diffusion_83,
	BOGI32_omega_inv_diffusion_84, BOGI32_omega_inv_diffusion_85, BOGI32_omega_inv_diffusion_86, BOGI32_omega_inv_diffusion_87,
	BOGI32_omega_inv_diffusion_88, BOGI32_omega_inv_diffusion_89, BOGI32_omega_inv_diffusion_90, BOGI32_omega_inv_diffusion_91,
	BOGI32_omega_inv_diffusion_92, BOGI32_omega_inv_diffusion_93, BOGI32_omega_inv_diffusion_94, BOGI32_omega_inv_diffusion_95,
	BOGI32_omega_inv_diffusion_96, BOGI32_omega_inv_diffusion_97, BOGI32_omega_inv_diffusion_98, BOGI32_omega_inv_diffusion_99,
	BOGI32_omega_inv_diffusion_100, BOGI32_omega_inv_diffusion_101, BOGI32_omega_inv_diffusion_102, BOGI32_omega_inv_diffusion_103,
	BOGI32_omega_inv_diffusion_104, BOGI32_omega_inv_diffusion_105, BOGI32_omega_inv_diffusion_106, BOGI32_omega_inv_diffusion_107,
	BOGI32_omega_inv_diffusion_108, BOGI32_omega_inv_diffusion_109, BOGI32_omega_inv_diffusion_110, BOGI32_omega_inv_diffusion_111,
	BOGI32_omega_inv_diffusion_112, BOGI32_omega_inv_diffusion_113, BOGI32_omega_inv_diffusion_114, BOGI32_omega_inv_diffusion_115,
	BOGI32_omega_inv_diffusion_116, BOGI32_omega_inv_diffusion_117, BOGI32_omega_inv_diffusion_118, BOGI32_omega_inv_diffusion_119,
	BOGI32_omega_inv_diffusion_120, BOGI32_omega_inv_diffusion_121, BOGI32_omega_inv_diffusion_122, BOGI32_omega_inv_diffusion_123,
	BOGI32_omega_inv_diffusion_124, BOGI32_omega_inv_diffusion_125, BOGI32_omega_inv_diffusion_126, BOGI32_omega_inv_diffusion_127,
	BOGI32_omega_inv_diffusion_128, BOGI32_omega_inv_diffusion_129, BOGI32_omega_inv_diffusion_130, BOGI32_omega_inv_diffusion_131,
	BOGI32_omega_inv_diffusion_132, BOGI32_omega_inv_diffusion_133, BOGI32_omega_inv_diffusion_134, BOGI32_omega_inv_diffusion_135,
	BOGI32_omega_inv_diffusion_136, BOGI32_omega_inv_diffusion_137, BOGI32_omega_inv_diffusion_138, BOGI32_omega_inv_diffusion_139,
	BOGI32_omega_inv_diffusion_140, BOGI32_omega_inv_diffusion_141, BOGI32_omega_inv_diffusion_142, BOGI32_omega_inv_diffusion_143,
	BOGI32_omega_inv_diffusion_144, BOGI32_omega_inv_diffusion_145, BOGI32_omega_inv_diffusion_146, BOGI32_omega_inv_diffusion_147,
	BOGI32_omega_inv_diffusion_148, BOGI32_omega_inv_diffusion_149, BOGI32_omega_inv_diffusion_150, BOGI32_omega_inv_diffusion_151,
	BOGI32_omega_inv_diffusion_152, BOGI32_omega_inv_diffusion_153, BOGI32_omega_inv_diffusion_154, BOGI32_omega_inv_diffusion_155,
	BOGI32_omega_inv_diffusion_156, BOGI32_omega_inv_diffusion_157, BOGI32_omega_inv_diffusion_158, BOGI32_omega_inv_diffusion_159,
	BOGI32_omega_inv_diffusion_160, BOGI32_omega_inv_diffusion_161, BOGI32_omega_inv_diffusion_162, BOGI32_omega_inv_diffusion_163,
	BOGI32_omega_inv_diffusion_164, BOGI32_omega_inv_diffusion_165, BOGI32_omega_inv_diffusion_166, BOGI32_omega_inv_diffusion_167,
	BOGI32_omega_inv_diffusion_168, BOGI32_omega_inv_diffusion_169, BOGI32_omega_inv_diffusion_170, BOGI32_omega_inv_diffusion_171,
	BOGI32_omega_inv_diffusion_172, BOGI32_omega_inv_diffusion_173, BOGI32_omega_inv_diffusion_174, BOGI32_omega_inv_diffusion_175,
	BOGI32_omega_inv_diffusion_176, BOGI32_omega_inv_diffusion_177, BOGI32_omega_inv_diffusion_178, BOGI32_omega_inv_diffusion_179,
	BOGI32_omega_inv_diffusion_180, BOGI32_omega_inv_diffusion_181, BOGI32_omega_inv_diffusion_182, BOGI32_omega_inv_diffusion_183,
	BOGI32_omega_inv_diffusion_184, BOGI32_omega_inv_diffusion_185, BOGI32_omega_inv_diffusion_186, BOGI32_omega_inv_diffusion_187,
	BOGI32_omega_inv_diffusion_188, BOGI32_omega_inv_diffusion_189, BOGI32_omega_inv_diffusion_190, BOGI32_omega_inv_diffusion_191,
	BOGI32_omega_inv_diffusion_192, BOGI32_omega_inv_diffusion_193, BOGI32_omega_inv_diffusion_194, BOGI32_omega_inv_diffusion_195,
	BOGI32_omega_inv_diffusion_196, BOGI32_omega_inv_diffusion_197, BOGI32_omega_inv_diffusion_198, BOGI32_omega_inv_diffusion_199,
	BOGI32_omega_inv_diffusion_200, BOGI32_omega_inv_diffusion_201, BOGI32_omega_inv_diffusion_202, BOGI32_omega_inv_diffusion_203,
	BOGI32_omega_inv_diffusion_204, BOGI32_omega_inv_diffusion_205, BOGI32_omega_inv_diffusion_206, BOGI32_omega_inv_diffusion_207,
	BOGI32_omega_inv_diffusion_208, BOGI32_omega_inv_diffusion_209, BOGI32_omega_inv_diffusion_210, BOGI32_omega_inv_diffusion_211,
	BOGI32_omega_inv_diffusion_212, BOGI32_omega_inv_diffusion_213, BOGI32_omega_inv_diffusion_214, BOGI32_omega_inv_diffusion_215,
	BOGI32_omega_inv_diffusion_216, BOGI32_omega_inv_diffusion_217, BOGI32_omega_inv_diffusion_218, BOGI32_omega_inv_diffusion_219,
	BOGI32_omega_inv_diffusion_220, BOGI32_omega_inv_diffusion_221, BOGI32_omega_inv_diffusion_222, BOGI32_omega_inv_diffusion_223,
	BOGI32_omega_inv_diffusion_224, BOGI32_omega_inv_diffusion_225, BOGI32_omega_inv_diffusion_226, BOGI32_omega_inv_diffusion_227,
	BOGI32_omega_inv_diffusion_228, BOGI32_omega_inv_diffusion_229, BOGI32_omega_inv_diffusion_230, BOGI32_omega_inv_diffusion_231,
	BOGI32_omega_inv_diffusion_232, BOGI32_omega_inv_diffusion_233, BOGI32_omega_inv_diffusion_234, BOGI32_omega_inv_diffusion_235,
	BOGI32_omega_inv_diffusion_236, BOGI32_omega_inv_diffusion_237, BOGI32_omega_inv_diffusion_238, BOGI32_omega_inv_diffusion_239,
	BOGI32_omega_inv_diffusion_240, BOGI32_omega_inv_diffusion_241, BOGI32_omega_inv_diffusion_242, BOGI32_omega_inv_diffusion_243,
	BOGI32_omega_inv_diffusion_244, BOGI32_omega_inv_diffusion_245, BOGI32_omega_inv_diffusion_246, BOGI32_omega_inv_diffusion_247,
	BOGI32_omega_inv_diffusion_248, BOGI32_omega_inv_diffusion_249, BOGI32_omega_inv_diffusion_250, BOGI32_omega_inv_diffusion_251,
	BOGI32_omega_inv_diffusion_252, BOGI32_omega_inv_diffusion_253, BOGI32_omega_inv_diffusion_254, BOGI32_omega_inv_diffusion_255,
	BOGI32_omega_inv_diffusion_256, BOGI32_omega_inv_diffusion_257, BOGI32_omega_inv_diffusion_258, BOGI32_omega_inv_diffusion_259,
	BOGI32_omega_inv_diffusion_260, BOGI32_omega_inv_diffusion_261, BOGI32_omega_inv_diffusion_262, BOGI32_omega_inv_diffusion_263,
	BOGI32_omega_inv_diffusion_264, BOGI32_omega_inv_diffusion_265, BOGI32_omega_inv_diffusion_266, BOGI32_omega_inv_diffusion_267,
	BOGI32_omega_inv_diffusion_268, BOGI32_omega_inv_diffusion_269, BOGI32_omega_inv_diffusion_270, BOGI32_omega_inv_diffusion_271,
	BOGI32_omega_inv_diffusion_272, BOGI32_omega_inv_diffusion_273, BOGI32_omega_inv_diffusion_274, BOGI32_omega_inv_diffusion_275,
	BOGI32_omega_inv_diffusion_276, BOGI32_omega_inv_diffusion_277, BOGI32_omega_inv_diffusion_278, BOGI32_omega_inv_diffusion_279,
	BOGI32_omega_inv_diffusion_280, BOGI32_omega_inv_diffusion_281, BOGI32_omega_inv_diffusion_282, BOGI32_omega_inv_diffusion_283,
	BOGI32_omega_inv_diffusion_284, BOGI32_omega_inv_diffusion_285, BOGI32_omega_inv_diffusion_286, BOGI32_omega_inv_diffusion_287,
	BOGI32_omega_inv_diffusion_288, BOGI32_omega_inv_diffusion_289, BOGI32_omega_inv_diffusion_290, BOGI32_omega_inv_diffusion_291,
	BOGI32_omega_inv_diffusion_292, BOGI32_omega_inv_diffusion_293, BOGI32_omega_inv_diffusion_294, BOGI32_omega_inv_diffusion_295,
	BOGI32_omega_inv_diffusion_296, BOGI32_omega_inv_diffusion_297, BOGI32_omega_inv_diffusion_298, BOGI32_omega_inv_diffusion_299,
	BOGI32_omega_inv_diffusion_300, BOGI32_omega_inv_diffusion_301, BOGI32_omega_inv_diffusion_302, BOGI32_omega_inv_diffusion_303,
	BOGI32_omega_inv_diffusion_304, BOGI32_omega_inv_diffusion_305, BOGI32_omega_inv_diffusion_306, BOGI32_omega_inv_diffusion_307,
	BOGI32_omega_inv_diffusion_308, BOGI32_omega_inv_diffusion_309, BOGI32_omega_inv_diffusion_310, BOGI32_omega_inv_diffusion_311,
	BOGI32_omega_inv_diffusion_312, BOGI32_omega_inv_diffusion_313, BOGI32_omega_inv_diffusion_314, BOGI32_omega_inv_diffusion_315,
	BOGI32_omega_inv_diffusion_316, BOGI32_omega_inv_diffusion_317, BOGI32_omega_inv_diffusion_318, BOGI32_omega_inv_diffusion_319,
	BOGI32_omega_inv_diffusion_320, BOGI32_omega_inv_diffusion_321, BOGI32_omega_inv_diffusion_322, BOGI32_omega_inv_diffusion_323,
	BOGI32_omega_inv_diffusion_324, BOGI32_omega_inv_diffusion_325, BOGI32_omega_inv_diffusion_326, BOGI32_omega_inv_diffusion_327,
	BOGI32_omega_inv_diffusion_328, BOGI32_omega_inv_diffusion_329, BOGI32_omega_inv_diffusion_330, BOGI32_omega_inv_diffusion_331,
	BOGI32_omega_inv_diffusion_332, BOGI32_omega_inv_diffusion_333, BOGI32_omega_inv_diffusion_334, BOGI32_omega_inv_diffusion_335,
	BOGI32_omega_inv_diffusion_336, BOGI32_omega_inv_diffusion_337, BOGI32_omega_inv_diffusion_338, BOGI32_omega_inv_diffusion_339,
	BOGI32_omega_inv_diffusion_340, BOGI32_omega_inv_diffusion_341, BOGI32_omega_inv_diffusion_342, BOGI32_omega_inv_diffusion_343,
	BOGI32_omega_inv_diffusion_344, BOGI32_omega_inv_diffusion_345, BOGI32_omega_inv_diffusion_346, BOGI32_omega_inv_diffusion_347,
	BOGI32_omega_inv_diffusion_348, BOGI32_omega_inv_diffusion_349, BOGI32_omega_inv_diffusion_350, BOGI32_omega_inv_diffusion_351,
	BOGI32_omega_inv_diffusion_352, BOGI32_omega_inv_diffusion_353, BOGI32_omega_inv_diffusion_354, BOGI32_omega_inv_diffusion_355,
	BOGI32_omega_inv_diffusion_356, BOGI32_omega_inv_diffusion_357, BOGI32_omega_inv_diffusion_358, BOGI32_omega_inv_diffusion_359,
	BOGI32_omega_inv_diffusion_360, BOGI32_omega_inv_diffusion_361, BOGI32_omega_inv_diffusion_362, BOGI32_omega_inv_diffusion_363,
	BOGI32_omega_inv_diffusion_364, BOGI32_omega_inv_diffusion_365, BOGI32_omega_inv_diffusion_366, BOGI32_omega_inv_diffusion_367,
	BOGI32_omega_inv_diffusion_368, BOGI32_omega_inv_diffusion_369, BOGI32_omega_inv_diffusion_370, BOGI32_omega_inv_diffusion_371,
	BOGI32_omega_inv_diffusion_372, BOGI32_omega_inv_diffusion_373, BOGI32_omega_inv_diffusion_374, BOGI32_omega_inv_diffusion_375,
	BOGI32_omega_inv_diffusion_376, BOGI32_omega_inv_diffusion_377, BOGI32_omega_inv_diffusion_378, BOGI32_omega_inv_diffusion_379,
	BOGI32_omega_inv_diffusion_380, BOGI32_omega_inv_diffusion_381, BOGI32_omega_inv_diffusion_382, BOGI32_omega_inv_diffusion_383,
	BOGI32_omega_inv_diffusion_384, BOGI32_omega_inv_diffusion_385, BOGI32_omega_inv_diffusion_386, BOGI32_omega_inv_diffusion_387,
	BOGI32_omega_inv_diffusion_388, BOGI32_omega_inv_diffusion_389, BOGI32_omega_inv_diffusion_390, BOGI32_omega_inv_diffusion_391,
	BOGI32_omega_inv_diffusion_392, BOGI32_omega_inv_diffusion_393, BOGI32_omega_inv_diffusion_394, BOGI32_omega_inv_diffusion_395,
	BOGI32_omega_inv_diffusion_396, BOGI32_omega_inv_diffusion_397, BOGI32_omega_inv_diffusion_398, BOGI32_omega_inv_diffusion_399,
	BOGI32_omega_inv_diffusion_400, BOGI32_omega_inv_diffusion_401, BOGI32_omega_inv_diffusion_402, BOGI32_omega_inv_diffusion_403,
	BOGI32_omega_inv_diffusion_404, BOGI32_omega_inv_diffusion_405, BOGI32_omega_inv_diffusion_406, BOGI32_omega_inv_diffusion_407,
	BOGI32_omega_inv_diffusion_408, BOGI32_omega_inv_diffusion_409, BOGI32_omega_inv_diffusion_410, BOGI32_omega_inv_diffusion_411,
	BOGI32_omega_inv_diffusion_412, BOGI32_omega_inv_diffusion_413, BOGI32_omega_inv_diffusion_414, BOGI32_omega_inv_diffusion_415,
	BOGI32_omega_inv_diffusion_416, BOGI32_omega_inv_diffusion_417, BOGI32_omega_inv_diffusion_418, BOGI32_omega_inv_diffusion_419,
	BOGI32_omega_inv_diffusion_420, BOGI32_omega_inv_diffusion_421, BOGI32_omega_inv_diffusion_422, BOGI32_omega_inv_diffusion_423,
	BOGI32_omega_inv_diffusion_424, BOGI32_omega_inv_diffusion_425, BOGI32_omega_inv_diffusion_426, BOGI32_omega_inv_diffusion_427,
	BOGI32_omega_inv_diffusion_428, BOGI32_omega_inv_diffusion_429, BOGI32_omega_inv_diffusion_430, BOGI32_omega_inv_diffusion_431,
	BOGI32_omega_inv_diffusion_432, BOGI32_omega_inv_diffusion_433, BOGI32_omega_inv_diffusion_434, BOGI32_omega_inv_diffusion_435,
	BOGI32_omega_inv_diffusion_436, BOGI32_omega_inv_diffusion_437, BOGI32_omega_inv_diffusion_438, BOGI32_omega_inv_diffusion_439,
	BOGI32_omega_inv_diffusion_440, BOGI32_omega_inv_diffusion_441, BOGI32_omega_inv_diffusion_442, BOGI32_omega_inv_diffusion_443,
	BOGI32_omega_inv_diffusion_444, BOGI32_omega_inv_diffusion_445, BOGI32_omega_inv_diffusion_446, BOGI32_omega_inv_diffusion_447,
	BOGI32_omega_inv_diffusion_448, BOGI32_omega_inv_diffusion_449, BOGI32_omega_inv_diffusion_450, BOGI32_omega_inv_diffusion_451,
	BOGI32_omega_inv_diffusion_452, BOGI32_omega_inv_diffusion_453, BOGI32_omega_inv_diffusion_454, BOGI32_omega_inv_diffusion_455,
	BOGI32_omega_inv_diffusion_456, BOGI32_omega_inv_diffusion_457, BOGI32_omega_inv_diffusion_458, BOGI32_omega_inv_diffusion_459,
	BOGI32_omega_inv_diffusion_460, BOGI32_omega_inv_diffusion_461, BOGI32_omega_inv_diffusion_462, BOGI32_omega_inv_diffusion_463,
	BOGI32_omega_inv_diffusion_464, BOGI32_omega_inv_diffusion_465, BOGI32_omega_inv_diffusion_466, BOGI32_omega_inv_diffusion_467,
	BOGI32_omega_inv_diffusion_468, BOGI32_omega_inv_diffusion_469, BOGI32_omega_inv_diffusion_470, BOGI32_omega_inv_diffusion_471,
	BOGI32_omega_inv_diffusion_472, BOGI32_omega_inv_diffusion_473, BOGI32_omega_inv_diffusion_474, BOGI32_omega_inv_diffusion_475,
	BOGI32_omega_inv_diffusion_476, BOGI32_omega_inv_diffusion_477, BOGI32_omega_inv_diffusion_478, BOGI32_omega_inv_diffusion_479,
	BOGI32_omega_inv_diffusion_480, BOGI32_omega_inv_diffusion_481, BOGI32_omega_inv_diffusion_482, BOGI32_omega_inv_diffusion_483,
	BOGI32_omega_inv_diffusion_484, BOGI32_omega_inv_diffusion_485, BOGI32_omega_inv_diffusion_486, BOGI32_omega_inv_diffusion_487,
	BOGI32_omega_inv_diffusion_488, BOGI32_omega_inv_diffusion_489, BOGI32_omega_inv_diffusion_490, BOGI32_omega_inv_diffusion_491,
	BOGI32_omega_inv_diffusion_492, BOGI32_omega_inv_diffusion_493, BOGI32_omega_inv_diffusion_494, BOGI32_omega_inv_diffusion_495,
	BOGI32_omega_inv_diffusion_496, BOGI32_omega_inv_diffusion_497, BOGI32_omega_inv_diffusion_498, BOGI32_omega_inv_diffusion_499,
	BOGI32_omega_inv_diffusion_500, BOGI32_omega_inv_diffusion_501, BOGI32_omega_inv_diffusion_502, BOGI32_omega_inv_diffusion_503,
	BOGI32_omega_inv_diffusion_504, BOGI32_omega_inv_diffusion_505, BOGI32_omega_inv_diffusion_506, BOGI32_omega_inv_diffusion_507,
	BOGI32_omega_inv_diffusion_508, BOGI32_omega_inv_diffusion_509, BOGI32_omega_inv_diffusion_510, BOGI32_omega_inv_diffusion_511,
	BOGI32_omega_inv_diffusion_512, BOGI32_omega_inv_diffusion_513, BOGI32_omega_inv_diffusion_514, BOGI32_omega_inv_diffusion_515,
	BOGI32_omega_inv_diffusion_516, BOGI32_omega_inv_diffusion_517, BOGI32_omega_inv_diffusion_518, BOGI32_omega_inv_diffusion_519,
	BOGI32_omega_inv_diffusion_520, BOGI32_omega_inv_diffusion_521, BOGI32_omega_inv_diffusion_522, BOGI32_omega_inv_diffusion_523,
	BOGI32_omega_inv_diffusion_524, BOGI32_omega_inv_diffusion_525, BOGI32_omega_inv_diffusion_526, BOGI32_omega_inv_diffusion_527,
	BOGI32_omega_inv_diffusion_528, BOGI32_omega_inv_diffusion_529, BOGI32_omega_inv_diffusion_530, BOGI32_omega_inv_diffusion_531,
	BOGI32_omega_inv_diffusion_532, BOGI32_omega_inv_diffusion_533, BOGI32_omega_inv_diffusion_534, BOGI32_omega_inv_diffusion_535,
	BOGI32_omega_inv_diffusion_536, BOGI32_omega_inv_diffusion_537, BOGI32_omega_inv_diffusion_538, BOGI32_omega_inv_diffusion_539,
	BOGI32_omega_inv_diffusion_540, BOGI32_omega_inv_diffusion_541, BOGI32_omega_inv_diffusion_542, BOGI32_omega_inv_diffusion_543,
	BOGI32_omega_inv_diffusion_544, BOGI32_omega_inv_diffusion_545, BOGI32_omega_inv_diffusion_546, BOGI32_omega_inv_diffusion_547,
	BOGI32_omega_inv_diffusion_548, BOGI32_omega_inv_diffusion_549, BOGI32_omega_inv_diffusion_550, BOGI32_omega_inv_diffusion_551,
	BOGI32_omega_inv_diffusion_552, BOGI32_omega_inv_diffusion_553, BOGI32_omega_inv_diffusion_554, BOGI32_omega_inv_diffusion_555,
	BOGI32_omega_inv_diffusion_556, BOGI32_omega_inv_diffusion_557, BOGI32_omega_inv_diffusion_558, BOGI32_omega_inv_diffusion_559,
	BOGI32_omega_inv_diffusion_560, BOGI32_omega_inv_diffusion_561, BOGI32_omega_inv_diffusion_562, BOGI32_omega_inv_diffusion_563,
	BOGI32_omega_inv_diffusion_564, BOGI32_omega_inv_diffusion_565, BOGI32_omega_inv_diffusion_566, BOGI32_omega_inv_diffusion_567,
	BOGI32_omega_inv_diffusion_568, BOGI32_omega_inv_diffusion_569, BOGI32_omega_inv_diffusion_570, BOGI32_omega_inv_diffusion_571,
	BOGI32_omega_inv_diffusion_572, BOGI32_omega_inv_diffusion_573, BOGI32_omega_inv_diffusion_574, BOGI32_omega_inv_diffusion_575,
};
