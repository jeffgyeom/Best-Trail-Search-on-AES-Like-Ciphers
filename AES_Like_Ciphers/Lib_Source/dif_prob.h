//This header is used for computing Differential Probability.
//When need to compute correlation, use lin_corr.h

#ifndef _DIF_PROB_H_
#define _DIF_PROB_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "astbb.h"
#include <math.h>

//0<= 2^{PROB_t} <=1 always i.e, always negative

extern PROB_t			*	MAX_PROB_POWER_TABLE;


//comparison of probability
//p1 == p2 :0, p1 > p2 : 1, p1 < p2 : -1
static DEV_INLINE int COMP_PROB(PROB_t x, PROB_t y)
{
	if (x == y)
	{
		return EQUAL;
	}
	else if (x == ZERO_PROB)
	{
		return RIGHT;
	}
	else if (y == ZERO_PROB)
	{
		return LEFT;
	}
	else if (fabs(x - y) < PRECISION_THRESHOLD)
	{
		return EQUAL;
	}
	else if (x > y)
	{
		return LEFT;
	}
	else
	{
		return RIGHT;
	}
}

//multiplication of probability
static DEV_INLINE void MUL_PROB(PROB_t * out, PROB_t in1, PROB_t in2)
{
	if ((in1 == ZERO_PROB) || (in2 == ZERO_PROB))
	{
		*out = ZERO_PROB;
	}
	else
	{
		*out = in1 + in2;
	}
}

//exponent of probability
static DEV_INLINE void POW_PROB(PROB_t * out, PROB_t in, CNT_t power)
{
	if (COMP_PROB(ZERO_PROB, in) == EQUAL)
	{
		*out = ZERO_PROB;
	}
	else if (power == 0)
	{
		*out = ONE_PROB;
	}
	else
	{
		*out = in * power;
	}
}

//exponent of probability
static DEV_INLINE void POW_MAX_PROB(PROB_t * out, CNT_t power)
{
	*out = MAX_PROB_POWER_TABLE[power];
}

static DEV_INLINE void Mul_Probs(PROB_t * out,PROB_t * p, CNT_t num_sbox_in_a_state)
{
	CNT_t i;
	PROB_t P;
	P = p[0];
	if (num_sbox_in_a_state != 1)
	{
		for (i = 1; i < num_sbox_in_a_state; i++)
		{
			MUL_PROB(&P, P, p[i]);
		}
	}
	*out = P;
}

static DEV_INLINE void Set_Probs_One(PROB_t * p, CNT_t num_sbox_in_a_state)
{
	CNT_t i;
	for (i = 0; i < num_sbox_in_a_state; i++)
	{
		p[i] = ONE_PROB;
	}
}


/*Data types for DDT information*/
typedef struct
{
	SBOX_I_WRD_t i;	//S-Box Input
	SBOX_O_WRD_t o;	//S-Box Ouput
	PROB_t		 p;	//S-Box Prob
} DC_I_O_PROB_t;

typedef struct
{
	SBOX_O_WRD_t o;	//S-Box Ouput
	PROB_t		 p;	//S-Box Prob
} DC_O_PROB_t;

typedef struct
{
	SBOX_I_WRD_t i;	//S-Box Iuput
	PROB_t		 p; //S-Box Prob
} DC_I_PROB_t;

typedef struct
{
	SBOX_I_WRD_t * sub_i;	//1Round Substitution Input
	SBOX_O_WRD_t * sub_o;	//1Round Substitution Output(ie, not apply diffusion)
	DIFF_O_WRD_t * dif_o;	//1Round Diffusion Output
	PROB_t		 *	   p;	//1Round Prob
} DC_1ROUND_CHAR_t;


//declare in prep_dc.c
extern DC_I_O_PROB_t	**	DC_SBOXES_I_O_PROB;
extern NUM_t			*	NUM_I_O_WITH_NONZERO_PROB;
extern NUM_t			*	NUM_I_O_WITH_MAX_PROB;
extern DC_O_PROB_t		*** DC_SBOXES_O_PROB_FIXED_I;
extern SBOX_I_CNT_t		**	NUM_O_WITH_NONZERO_PROB;
extern SBOX_I_CNT_t		**	NUM_O_WITH_MAX_PROB;
extern DC_I_PROB_t		*** DC_SBOXES_I_PROB_FIXED_O;
extern SBOX_O_CNT_t		**	NUM_I_WITH_NONZERO_PROB;
extern SBOX_O_CNT_t		**	NUM_I_WITH_MAX_PROB;
extern DC_I_O_PROB_t	**	DC_SBOXES_I_O_PROB_FIXED_O;
extern PROB_t				DC_1ROUND_MAX_PROB;
extern PROB_t			*	DC_BOUNDS_ONLY_WITH_MAX_PROB;
extern PROB_t			*	DC_BOUNDS;
extern DC_1ROUND_CHAR_t	*	DC_TRAIL_IN_PROGRESS;
extern DC_1ROUND_CHAR_t *	DC_TRAIL_FOR_OUT;
extern PROB_t			*	MAX_PROB_FOR_EACH_SBOX;
extern PROB_t			*	MIN_PROB_FOR_EACH_SBOX;
extern PROB_t				MAX_PROB_FOR_WHOLE_SBOXES;
extern PROB_t				MIN_PROB_FOR_WHOLE_SBOXES;
extern FLAG_t				MAX_PROB_EQUAL_EVERY_SBOX;
extern FLAG_t			*	FIX_IN_MAX_PROB_EQUAL;
extern FLAG_t				FIX_IN_MAX_PROB_EQUAL_EVERY_SBOX;
extern FLAG_t			*	FIX_OU_MAX_PROB_EQUAL;
extern FLAG_t				FIX_OU_MAX_PROB_EQUAL_EVERY_SBOX;


#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_DIF_PROB_H_*/