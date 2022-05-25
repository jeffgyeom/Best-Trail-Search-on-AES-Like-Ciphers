//This header is used for computing Differential Probability.
//When need to compute correlation, use lin_corr.h

#ifndef _DIF_PROB_H_
#define _DIF_PROB_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "astbb.h"
#include <math.h>

//declared in prep_dc.c
PROB_t MAX_PROB_POWER_TABLE[NUM_SBOX_IN_A_STATE + 1];



//0<= 2^{PROB_t} <=1 always i.e, always negative
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
	SBOX_t		i;	//S-Box Input
	SBOX_t		o;	//S-Box Ouput
	PROB_t		p;	//S-Box Prob
} DC_I_O_PROB_t;

typedef struct
{
	SBOX_t		o;	//S-Box Ouput
	PROB_t		p;	//S-Box Prob
} DC_O_PROB_t;

typedef struct
{
	SBOX_t		i;	//S-Box Iuput
	PROB_t		p;	//S-Box Prob
} DC_I_PROB_t;

typedef struct
{
	SBOX_t sub_i[NUM_SBOX_IN_A_STATE];	//1Round Substitution Input
	SBOX_t sub_o[NUM_SBOX_IN_A_STATE];	//1Round Substitution Output(ie, not apply diffusion)
	SBOX_t psh_i[NUM_SBOX_IN_A_STATE];	//1Round Pshuf Input(Pmix||Pmix||...||Pmix Output)
	//SBOX_t psh_o[NUM_SBOX_IN_A_STATE];//1Round Diffusion Output(Pshuf Output)[Note that, We don't have to store this]
	PROB_t	   p[NUM_SBOX_IN_A_STATE];	//1Round Prob
} DC_1ROUND_CHAR_t;

#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_DIF_PROB_H_*/