//This header is used for computing Linear Apporximation's Correlation.
//When need to compute differential probabilty, use dif_prob.h

#ifndef _LIN_CORR_H_
#define _LIN_CORR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "astbb.h"
#include <math.h>

extern CORR_t			*	MAX_CORR_POWER_TABLE;
//comparison of correlation
static DEV_INLINE int COMP_CORR(CORR_t x, CORR_t y)
{
	if ((x.sign == ZERO) || (y.sign == ZERO))
	{
		if ((x.sign == ZERO) && (y.sign == ZERO))
		{
			return EQUAL;
		}
		else if (x.sign == ZERO)
		{
			return RIGHT;
		}
		else
		{
			return LEFT;
		}
	}
	else //non-zero magnitude
	{
		if (x.magnitude == y.magnitude)
		{
			return EQUAL;
		}
		else if(fabs(x.magnitude - y.magnitude) < PRECISION_THRESHOLD)
		{
			return EQUAL;
		}
		else if (x.magnitude > y.magnitude)
		{
			return LEFT;
		}
		else
		{
			return RIGHT;
		}
	}
}

//multiplication of correlation
static DEV_INLINE void MUL_CORR(CORR_t * out, CORR_t x, CORR_t y)
{
	if ((x.sign == ZERO) || (y.sign == ZERO))
	{
		*out = ZERO_CORR;
	}
	else
	{
		out->sign = x.sign * y.sign;
		out->magnitude = x.magnitude + y.magnitude;
	}
}

//exponent of correlation
static DEV_INLINE void POW_CORR(CORR_t * out, CORR_t in, CNT_t power)
{
	if (in.sign == ZERO)
	{
		*out = ZERO_CORR;
	}
	else if (power == 0)
	{
		*out = ONE_CORR;
	}
	else
	{
		if (power & 0x1)//Odd
		{
			out->sign = in.sign;
		}
		else //Even
		{
			out->sign = POSI;
		}
		out->magnitude = power * in.magnitude;
	}
}

//exponent of max correlation
static DEV_INLINE void POW_MAX_CORR(CORR_t * out, CNT_t power)
{
	*out = MAX_CORR_POWER_TABLE[power];
}

//multiplication of correlations
static DEV_INLINE void Mul_Corrs(CORR_t * out, CORR_t *c, CNT_t num_sbox_in_a_state)
{
	CNT_t i;
	CORR_t C;
	C = c[0];
	if (num_sbox_in_a_state != 1)
	{
		for (i = 1; i < num_sbox_in_a_state; i++)
		{
			MUL_CORR(&C, C, c[i]);
		}
	}
	*out = C;
}


static DEV_INLINE void Set_Corrs_One(CORR_t * c, CNT_t num_sbox_in_a_state)
{
	CNT_t i;
	for (i = 0; i < num_sbox_in_a_state; i++)
	{
		c[i] = ONE_CORR;
	}
}

/*Data types for LAT information*/
typedef struct
{
	SBOX_I_WRD_t i;	//S-Box Input
	SBOX_O_WRD_t o;	//S-Box Ouput
	CORR_t		 c;	//S-Box Corr
} LC_I_O_CORR_t;

typedef struct
{
	SBOX_O_WRD_t o;	//S-Box Ouput
	CORR_t		 c;	//S-Box Corr
} LC_O_CORR_t;

typedef struct
{
	SBOX_I_WRD_t i;	//S-Box Iuput
	CORR_t		 c;	//S-Box Corr
} LC_I_CORR_t;

typedef struct
{
	SBOX_I_WRD_t * sub_i;	//1Round Substitution Input
	SBOX_O_WRD_t * sub_o;	//1Round Substitution Output(ie, not apply diffusion)
	DIFF_O_WRD_t * dif_o;	//1Round Diffusion Output
	CORR_t		 *     c;	//1Round Corr
} LC_1ROUND_CHAR_t;


//declared in prep_lc.c
extern LC_I_O_CORR_t	**	LC_SBOXES_I_O_CORR;
extern NUM_t			*	NUM_I_O_WITH_NONZERO_CORR;
extern NUM_t			*	NUM_I_O_WITH_MAX_CORR;
extern LC_O_CORR_t		*** LC_SBOXES_O_CORR_FIXED_I;
extern SBOX_I_CNT_t		**	NUM_O_WITH_NONZERO_CORR;
extern SBOX_I_CNT_t		**	NUM_O_WITH_MAX_CORR;
extern LC_I_CORR_t		*** LC_SBOXES_I_CORR_FIXED_O;
extern SBOX_O_CNT_t		**	NUM_I_WITH_NONZERO_CORR;
extern SBOX_O_CNT_t		**	NUM_I_WITH_MAX_CORR;
extern LC_I_O_CORR_t	**	LC_SBOXES_I_O_CORR_FIXED_O;
extern CORR_t				LC_1ROUND_MAX_CORR;
extern CORR_t			*	LC_BOUNDS_ONLY_WITH_MAX_CORR;
extern CORR_t			*	LC_BOUNDS;
extern LC_1ROUND_CHAR_t	*	LC_TRAIL_IN_PROGRESS;
extern LC_1ROUND_CHAR_t *	LC_TRAIL_FOR_OUT;
extern CORR_t			*	MAX_CORR_FOR_EACH_SBOX;
extern CORR_t			*	MIN_CORR_FOR_EACH_SBOX;
extern CORR_t				MAX_CORR_FOR_WHOLE_SBOXES;
extern CORR_t				MIN_CORR_FOR_WHOLE_SBOXES;
extern FLAG_t			 	MAX_CORR_EQUAL_EVERY_SBOX;
extern FLAG_t			*	FIX_IN_MAX_CORR_EQUAL;
extern FLAG_t				FIX_IN_MAX_CORR_EQUAL_EVERY_SBOX;
extern FLAG_t			*	FIX_OU_MAX_CORR_EQUAL;
extern FLAG_t				FIX_OU_MAX_CORR_EQUAL_EVERY_SBOX;

#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_LIN_CORR_H_*/


