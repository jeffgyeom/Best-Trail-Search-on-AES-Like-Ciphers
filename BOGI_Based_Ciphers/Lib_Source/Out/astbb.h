#ifndef _ASTBB_H_
#define _ASTBB_H_


#ifdef __cplusplus
extern "C" {
#endif

#if defined _MSC_VER
	//Visual Studio
	#ifdef _DEVELOPMENT
		#define DEV_DEFINE __declspec(dllexport)
	#else
		#define DEV_DEFINE __declspec(dllimport)
	#endif
#elif defined __GNUC__
	//GCC
	#ifdef _DEVELOPMENT
		#define DEV_DEFINE __attribute__ ((visibility("default")))
	#else
		//nothing to define
		#define DEV_DEFINE 
	#endif

#define sprintf_s(buf, size, fmt, ...) sprintf(buf, fmt, ##__VA_ARGS__) 
#endif


#if defined	__NO_INLINE__
	#define DEV_INLINE //nothing
#else
	#define DEV_INLINE inline
#endif

	#include <stdint.h>
	#include <stdlib.h>
	

	/*
	*  Module Build Options
	*/

	#define EMPLOY_PERM_CHAR

	//#define PRINT_PSHUF_INPUT
	#define OUT_ELAPSED_TIME


	/*
	*  One of the Following Options Must be chosen
	*/
	//#define BOGI_CIPHER_16
	//#define BOGI_CIPHER_32
	#define BOGI_CIPHER_64
	//#define BOGI_CIPHER_128
	//#define BOGI_CIPHER_176
	//#define BOGI_CIPHER_256


	/*
	* System Options
	*/
	#define IS_LITTLE_ENDIAN
	//#define IS_BIG_ENDIAN
	#if (!defined IS_LITTLE_ENDIAN) && (!defined IS_BIG_ENDIAN)
	#error Endian Info is Required.
	#elif (defined IS_LITTLE_ENDIAN) && (defined IS_BIG_ENDIAN)
	#error Endian Info must be only One.
	#endif

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	#if defined BOGI_CIPHER_16
		#define NUM_SBOX_IN_A_STATE 4
	#elif defined BOGI_CIPHER_32
		#define NUM_SBOX_IN_A_STATE 8	
	#elif defined BOGI_CIPHER_64
		#define NUM_SBOX_IN_A_STATE 16
	#elif defined BOGI_CIPHER_128
		#define NUM_SBOX_IN_A_STATE 32
	#elif defined BOGI_CIPHER_176
		#define NUM_SBOX_IN_A_STATE 44
	#elif defined BOGI_CIPHER_256
		#define NUM_SBOX_IN_A_STATE 64	
	#endif

	#define NUM_ROUND_THRESHOLD 40

	
	typedef uint8_t		SBOX_t; //4-bit
	typedef int32_t		CNT_t;

	typedef uint32_t	DDT_ENTRY_t;
	typedef int32_t		LAT_ENTRY_t;
	typedef int32_t		BIT_SIZE_t;
	typedef int32_t		FLAG_t;
	typedef uint32_t	UFLAG_t;
	typedef int32_t		NUM_t;
	typedef char		CHAR_t;
	typedef uint64_t	ACTIVE_MAP_t;
	typedef double		PROB_t;
	typedef double		ABS_CORR_t;
	typedef	int32_t		SIGN_t;
	 

	//0<= 2^{ABS_CORR_t} <=1 always i.e, always negative
	typedef struct corr
	{
		SIGN_t sign;
		ABS_CORR_t magnitude;
	}CORR_t;


	//Define error return
	#define SUCCESS	((FLAG_t)0)
	#define FAILURE	((FLAG_t)-1)
	
	//TRUE or FALSE
	#ifndef TRUE
	#define TRUE	((FLAG_t)1)
	#endif	
	#ifndef FALSE
	#define FALSE	((FLAG_t)-1)
	#endif


	#define EQUAL	((FLAG_t)0)
	#define LEFT	((FLAG_t)1)
	#define RIGHT	((FLAG_t)-1)

	#define NEGA ((FLAG_t)-1)
	#define ZERO ((FLAG_t)0)
	#define POSI ((FLAG_t)1)

	/*
	*Warning Point : In general, checking the eaulity of two double data fails only by using ==.
	*				However, the difference of two double data must be bigger than or equal to -log2{(NM)/(M)} 
	*				where M is the maximum probability NM is the next-maximum probability exept for ONE probability.
	*				With 8-bit S-box, which is the biggest size, the difference must be bigger than -log2{(252)/(254)} \approx 0.0114047632.
	*				With the error magin, 0.00001 is enough
	*/
	#define PRECISION_THRESHOLD ((PROB_t)0.00001)
	
	//ZERO_PROB means 2^{-infinte} i.e, "0"
	#define ZERO_PROB ((PROB_t)1) 
	#define ONE_PROB ((PROB_t)0)


	static const CORR_t ZERO_CORR = { ZERO, (ABS_CORR_t)1 };
	static const CORR_t ONE_CORR = { POSI, (ABS_CORR_t)0 };

	/*some utility functions*/
	#define  ROL8( _8bit_ , i) ((( _8bit_) << ((i)%8)) | (( _8bit_) >> ( 8 - ((i)% 8))))
	#define  ROR8( _8bit_ , i) ((( _8bit_) >> ((i)%8)) | (( _8bit_) << ( 8 - ((i)% 8))))
	#define ROL16(_16bit_ , i) (((_16bit_) << ((i)%16)) | ((_16bit_) >> (16 - ((i)%16))))
	#define ROR16(_16bit_ , i) (((_16bit_) >> ((i)%16)) | ((_16bit_) << (16 - ((i)%16))))

	#ifdef _MSC_VER
	//For Windows
	#include <Windows.h>
	#define ROL32(_32bit_ , i) (_lrotl((_32bit_) , ((i)%32)))
	#define ROR32(_32bit_ , i) (_lrotr((_32bit_) , ((i)%32)))
	#define ROL64(_64bit_ , i) (_rotl64((_64bit_) , ((i)%64)))
	#define ROR64(_64bit_ , i) (_rotr64((_64bit_) , ((i)%64)))
	#elif __GNUC__
	//For Linux
	#define ROL32(_32bit_ , i) (((_32bit_) << (i)) | ((_32bit_) >> (32 - ((i)%32))))
	#define ROR32(_32bit_ , i) (((_32bit_) >> (i)) | ((_32bit_) << (32 - ((i)%32))))
	#define ROL64(_64bit_ , i) (((_64bit_) << (i)) | ((_64bit_) >> (64 - ((i)%64))))
	#define ROR64(_64bit_ , i) (((_64bit_) >> (i)) | ((_64bit_) << (64 - ((i)%64))))
	#define max(a,b) (((a) > (b)) ? (a) : (b))
	#define min(a,b) (((a) > (b)) ? (b) : (a))
	#endif

	#if defined __GNUC__ && _DEBUG
	#else
		#include <nmmintrin.h>
	#endif
	
	/*this function only considers word size 32bit */
	static DEV_INLINE CNT_t get_32word_hw(uint32_t word)
	{

		#ifdef _MSC_VER
			return (CNT_t)_mm_popcnt_u32(word);
		#elif __GNUC__
		#ifndef _DEBUG
			return (CNT_t)__builtin_popcount(word);
		#else
			CNT_t hamming_weight = 0;
			int shift;
			for (shift = 0; shift < 32; shift++)
			{
				if (((word >> shift) & 1) == 1)
					hamming_weight++;
			}
			return (CNT_t)hamming_weight;
		#endif
		#endif
	}

	static DEV_INLINE CNT_t get_64word_hw(uint64_t word)
	{

		#if defined _MSC_VER && _WIN64
			return (CNT_t)_mm_popcnt_u64(word);
		#elif __GNUC__
		#ifndef _DEBUG
			return (CNT_t)__builtin_popcountll(word);
		#else
			CNT_t hamming_weight = 0;
			int shift;
			for (shift = 0; shift < 64; shift++)
			{
				if (((word >> shift) & 1) == 1)
					hamming_weight++;
			}
			return (CNT_t)hamming_weight;
		#endif
		#endif
	}


	/*Extern Functions*/
	DEV_DEFINE void Print_Module_Status(void);

	//Step2
#if defined BOGI_CIPHER_16
	DEV_DEFINE void PY_BOGI16_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);

	DEV_DEFINE void PY_BOGI16_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
#elif defined BOGI_CIPHER_32
	DEV_DEFINE void PY_BOGI32_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);

	DEV_DEFINE void PY_BOGI32_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
#elif defined BOGI_CIPHER_64
	DEV_DEFINE void PY_BOGI64_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);

	DEV_DEFINE void PY_BOGI64_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
#elif defined BOGI_CIPHER_128
	DEV_DEFINE void PY_BOGI128_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);

	DEV_DEFINE void PY_BOGI128_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
#elif defined BOGI_CIPHER_176
	DEV_DEFINE void PY_BOGI176_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
	DEV_DEFINE void PY_BOGI176_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
#elif defined BOGI_CIPHER_256
	DEV_DEFINE void PY_BOGI256_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
	DEV_DEFINE void PY_BOGI256_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx
	);
#endif

#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_ASTBB_H_*/