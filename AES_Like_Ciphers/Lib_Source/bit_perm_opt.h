#ifndef _BIT_PERM_OPT_H_
#define _BIT_PERM_OPT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "astbb.h"


/*For 128-bit*/
static DEV_INLINE void ROL128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, CNT_t rot)
{
	CNT_t in_rot = rot % 128;
	if (in_rot == 64)
	{
		*outH = inL;
		*outL = inH;
	}
	else if (in_rot > 64)
	{
		CNT_t again_rot = in_rot - 64;
		uint64_t tmp_inL = inH << again_rot;
		uint64_t tmp_inH = inL << again_rot;
		tmp_inH |= inH >> (64 - again_rot);
		tmp_inL |= inL >> (64 - again_rot);
		*outH = tmp_inH;
		*outL = tmp_inL;
	}
	else if (in_rot < 64)
	{
		CNT_t again_rot = in_rot;
		uint64_t tmp_inL = inL << again_rot;
		uint64_t tmp_inH = inH << again_rot;
		tmp_inH |= inL >> (64 - again_rot);
		tmp_inL |= inH >> (64 - again_rot);
		*outH = tmp_inH;
		*outL = tmp_inL;
	}
}

static DEV_INLINE void ROR128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, CNT_t rot)
{
	CNT_t in_rot = rot % 128;
	CNT_t in_rot2 = (128 - in_rot) % 128;
	ROL128(outH, outL, inH, inL, rot);
}



static DEV_INLINE void RSHIFT128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, CNT_t shift)
{
	if (shift > 128)
	{
		*outH = 0ULL;
		*outL = 0ULL;
	}
	else if (shift >= 64)
	{
		CNT_t in_shift = shift - 64;
		*outH = 0ULL;
		*outL = inH >> in_shift;
	}
	else if (shift < 64)
	{
		CNT_t in_shift = shift;
		uint64_t tmp_inH = inH << (64 - shift);
		*outH = inH >> shift;
		*outL = (inL >> shift) | tmp_inH;
	}
}

static DEV_INLINE void LSHIFT128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, CNT_t shift)
{
	if (shift > 128)
	{
		*outH = 0ULL;
		*outL = 0ULL;
	}
	else if (shift >= 64)
	{
		CNT_t in_shift = shift - 64;
		*outH = inL << in_shift;
		*outL = 0ULL;
	}
	else if (shift < 64)
	{
		CNT_t in_shift = shift;
		uint64_t tmp_inL = inL >> (64 - shift);
		*outH = (inH << shift) | tmp_inL;
		*outL = inL << shift;
	}
}


static DEV_INLINE void bit_permute_step_128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, uint64_t mH, uint64_t mL, CNT_t shift)
{
	uint64_t tH = 0ULL, tL = 0ULL;
	uint64_t tmp_outH = 0ULL, tmp_outL = 0ULL;
	RSHIFT128(&tH, &tL, inH, inL, shift);
	tH = tH ^ inH;
	tL = tL ^ inL;
	tH = tH & mH;
	tL = tL & mL;
	LSHIFT128(&tmp_outH, &tmp_outL, tH, tL, shift);
	*outH = inH ^ tH ^ tmp_outH;
	*outL = inL ^ tL ^ tmp_outL;
}


static DEV_INLINE void bit_permute_step_simple_128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, uint64_t mH, uint64_t mL, CNT_t shift)
{
	uint64_t tH = 0ULL, tL = 0ULL;
	uint64_t tmp_outH = 0ULL, tmp_outL = 0ULL;
	RSHIFT128(&tH, &tL, inH, inL, shift);
	tH = tH & mH;
	tL = tL & mL;

	tmp_outH = inH & mH;
	tmp_outL = inL & mL;
	LSHIFT128(&tmp_outH, &tmp_outL, tmp_outH, tmp_outL, shift);
	
	*outH = tmp_outH | tH;
	*outL = tmp_outL | tL;
}

static DEV_INLINE void mask_rshift128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, uint64_t mH, uint64_t mL, CNT_t shift)
{
	uint64_t tH = 0ULL, tL = 0ULL;
	tH = inH & mH;
	tL = inL & mL;
	RSHIFT128(outH, outL, tH, tL, shift);
}

static DEV_INLINE void mask_lshift128(uint64_t * outH, uint64_t * outL, uint64_t inH, uint64_t inL, uint64_t mH, uint64_t mL, CNT_t shift)
{
	uint64_t tH = 0ULL, tL = 0ULL;
	tH = inH & mH;
	tL = inL & mL;
	LSHIFT128(outH, outL, tH, tL, shift);
}



/*For 64-bit*/
static DEV_INLINE void bit_permute_step_64(uint64_t * out, uint64_t x, uint64_t m, CNT_t shift)
{
	uint64_t t;
	(t) = (((x) >> (shift)) ^ (x)) & (m);
	(*out) = ((x) ^ (t)) ^ ((t) << (shift));
}

static DEV_INLINE void bit_permute_step_simple_64(uint64_t * out, uint64_t x, uint64_t m, CNT_t shift)
{
	uint64_t t;
	t = (x & m) << shift;
	*out = t | ((x >> shift) & m);
}

/*For 16-bit*/
static DEV_INLINE void bit_permute_step_16(uint16_t * out, uint16_t x, uint16_t m, CNT_t shift)
{
	uint16_t t;
	(t) = ((uint16_t)((x) >> (shift)) ^ (x)) & (m);
	(*out) = ((x) ^ (t)) ^ (uint16_t)((t) << (shift));
}


/*For 32-bit*/
static DEV_INLINE void bit_permute_step_simple_32(uint32_t * out, uint32_t x, uint32_t m, CNT_t shift)
{
	uint32_t t;
	t = (x & m) << shift;
	*out = t | ((x >> shift) & m);
}


#if defined __GNUC__

#include <byteswap.h>

#endif

static DEV_INLINE uint16_t BSWAP16(uint16_t in)
{
#if defined _MSC_VER
	return (uint16_t)_byteswap_ushort((unsigned short)in);
#elif defined __GNUC__
	return (uint16_t)bswap_16(in);
#else
	return ((uint16_t)(in >> 8) | (uint16_t)(in << 8));
#endif
}

static DEV_INLINE uint32_t BSWAP32(uint32_t in)
{
#if defined _MSC_VER
	return (uint32_t)_byteswap_ulong((unsigned long) in);
#elif defined __GNUC__
	return (uint32_t)bswap_32(in);
#else
	return ((uint32_t)BSWAP16(in & 0xffff) << 16) | (uint32_t)BSWAP16(in >> 16);
#endif
}

static DEV_INLINE uint64_t BSWAP64(uint64_t in)
{
#if defined _MSC_VER
	return (uint64_t)_byteswap_uint64((unsigned long long) in);
#elif defined __GNUC__
	return (uint64_t)bswap_64(in);
#else
	return ((uint64_t)BSWAP32(in & 0xffffffff) << 32) | (uint64_t)BSWAP32(in >> 32);
#endif
}



#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_BIT_PERM_OPT_H_*/