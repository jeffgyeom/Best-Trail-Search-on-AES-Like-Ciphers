#ifndef _BIT_PERM_OPT_H_
#define _BIT_PERM_OPT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "astbb.h"

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

#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_BIT_PERM_OPT_H_*/