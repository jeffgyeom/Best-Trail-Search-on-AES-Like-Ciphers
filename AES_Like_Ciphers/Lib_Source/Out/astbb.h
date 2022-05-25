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

	#define OUR_OPTION
	//#define PRE_OPTION

	//#define OUR_PC1
	//#define OUR_PC2
	//#define EMPLOY_PERM_CHAR


#if defined OUR_OPTION
	#define OUR_PC1
	#define OUR_PC2
	#define EMPLOY_PERM_CHAR
#elif defined PRE_OPTION
	#define PRE_PC1
	#define PRE_PC2
#endif

	/*
	* Warning!! : NUM_WORD_IN_A_STATE_THRESHOLD_CHECK must be  between 32 and 64
	* Note      : the value of NUM_WORD_IN_A_STATE_THRESHOLD_CHECK (slightly) affects the whole efficiency
	*/
	

	#define NUM_WORD_IN_A_STATE_THRESHOLD_CHECK 64



	//Define types to use
	/*
	*	Attention! as you can see, 1) input(output) word of S-box must has the same data type as output(input) word of Diffusion
	*                              2) the size of CNT_t must be bigger than "REAL-USED" word size
	*/
	typedef int32_t			CNT_t;
	typedef uint32_t		SBOX_I_WRD_t;
	typedef CNT_t			SBOX_I_CNT_t;
	typedef uint32_t		SBOX_O_WRD_t;
	typedef CNT_t			SBOX_O_CNT_t;
	typedef SBOX_O_WRD_t	DIFF_I_WRD_t;
	typedef CNT_t			DIFF_I_CNT_t;
	typedef SBOX_I_WRD_t	DIFF_O_WRD_t;
	typedef CNT_t			DIFF_O_CNT_t;
	typedef uint32_t		DDT_ENTRY_t;
	typedef uint32_t		SBOX_ENTRY_t;
	typedef int32_t			LAT_ENTRY_t;
	typedef int32_t			BIT_SIZE_t;
	typedef int32_t			FLAG_t;
	typedef uint32_t		UFLAG_t;
	typedef int32_t			NUM_t;
	typedef char			CHAR_t;
#if NUM_WORD_IN_A_STATE_THRESHOLD_CHECK <= 32
	typedef uint32_t		ACTIVE_MAP_t;
#elif NUM_WORD_IN_A_STATE_THRESHOLD_CHECK <= 64
	typedef uint64_t		ACTIVE_MAP_t;
#else
	typedef uint128_t		ACTIVE_MAP_t; //128 is not available at the moment
#endif
	typedef double			PROB_t;
	typedef double			ABS_CORR_t;
	typedef	int32_t			SIGN_t;
	 

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

	#define UNKNOWN ((NUM_t)-1)

	#define SPN			((FLAG_t)1)
	#define FEISTEL		((FLAG_t)2)
	#define ARX			((FLAG_t)3)

	#define BIT_PERMUTATION				((FLAG_t)1)
	#define PARTIAL_BINARY_MATRIX		((FLAG_t)2)
	#define PARTIAL_NON_BINARY_MATRIX	((FLAG_t)3)
	#define FULL_BINARY_MATRIX			((FLAG_t)4)
	#define FULL_NON_BINARY_MATRIX		((FLAG_t)5)
	#define MIDORI128_ONLY_MATRIX		((FLAG_t)6)

	#define NUM_WORD_IN_A_STATE_THRESHOLD ((CNT_t)NUM_WORD_IN_A_STATE_THRESHOLD_CHECK)

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

	#define USING_MIN_PROB ((FLAG_t)1)
	#define USING_MAX_PROB ((FLAG_t)-1)

	static const CORR_t ZERO_CORR = { ZERO, (ABS_CORR_t)1 };
	static const CORR_t ONE_CORR = { POSI, (ABS_CORR_t)0 };

	#define USING_MIN_CORR ((FLAG_t)1)
	#define USING_MAX_CORR ((FLAG_t)-1)

	#define VV_ALL					((UFLAG_t)0b111111111)
	#define VV_OFF					((UFLAG_t)0b000000000)
	#define VV_ROUND_PROGRESS		((UFLAG_t)0b000000001)
	#define VV_UPDATE_BOUND 		((UFLAG_t)0b000000010)
	#define VV_UPDATE_BOUND_TRAIL	((UFLAG_t)0b000000100)
	#define VV_LAST_UPDATE_TRAIL	((UFLAG_t)0b000001000)
	#define VV_PROGRESS				((UFLAG_t)0b000010000)
	#define VV_LAST_RESULT			((UFLAG_t)0b000100000)
	#define VV_ACTIVE_MAP_PROGRESS	((UFLAG_t)0b001000000)
	#define VV_ETA					((UFLAG_t)0b010000000) //not available
	#define VV_FILE_PRINT			((UFLAG_t)0b100000000)

	typedef struct
	{
		FLAG_t			enable_1round_active_map;
		FLAG_t			rotational_symmetric_equivalent;
	}SEARCHING_START_OPT_t;

	typedef struct
	{
		FLAG_t			enable_set_initial_prob_bound;
		PROB_t *		each_round_initial_prob_bound;
		PROB_t			prob_interval;
		FLAG_t			enable_set_initial_corr_bound;
		CORR_t *		each_round_initial_corr_bound;
		CORR_t			corr_interval;
	}SET_INITIAL_BOUND_OPT_t;

	typedef struct
	{
		NUM_t			num_diff_of_partial_diffusion; //if it is unkown, set the number of words in a state
		NUM_t			diff_branch_num; //if it is unknown, UNKNOWN
		NUM_t			inv_trans_diff_branch_num; //if it is unknown, UNKNOWN
	}DIFFUSION_BOUND_OPT_t;

	typedef struct
	{
		/*general information*/
		CHAR_t			alg_name[256];
		FLAG_t			alg_structure;
		NUM_t			num_round;
		BIT_SIZE_t		block_bit_size;
		BIT_SIZE_t		key_bit_size;
		NUM_t			num_word_in_a_state;

		/*about substitution*/
		//distinct sbox in a state?(e.g., TRUE, FALSE)
		FLAG_t			distinct_sbox;
		BIT_SIZE_t		sbox_i_word_bit_size;
		BIT_SIZE_t		sbox_o_word_bit_size;
		//Sboxes
		SBOX_O_WRD_t *	sboxes;

		/*about diffusion*/
		//what diffusion is used?(e.g., bit-permutation, matrix(partial), matrix(full))
		FLAG_t			diffusion_info;
		BIT_SIZE_t		diff_i_word_bit_size;
		BIT_SIZE_t		diff_o_word_bit_size;
		//diffusion function
		void			(*Diffusion)(DIFF_O_WRD_t *, DIFF_I_WRD_t *);
		void			(*Inv_Diffusion)(DIFF_O_WRD_t *, DIFF_I_WRD_t *);
		void			(*Inv_Trans_Diffusion)(DIFF_O_WRD_t *, DIFF_I_WRD_t *);
		void			(*Trans_Diffusion)(DIFF_O_WRD_t *, DIFF_I_WRD_t *);

		/*about bound info*/
		NUM_t			dc_known_best_round;
		void			(*Set_Known_Prob_Bound)(PROB_t *);
		NUM_t			lc_known_best_round;
		void			(*Set_Known_Corr_Bound)(CORR_t *);

		/*add from here*/
		SEARCHING_START_OPT_t *		searching_start_opt;
		SET_INITIAL_BOUND_OPT_t *	set_initial_bound_opt;
		DIFFUSION_BOUND_OPT_t *		diffusion_bound_opt;
		
	}BLK_CIPHER_INFO_t;

	typedef struct
	{
		/*general information*/
		NUM_t			num_round;
		NUM_t			num_word_in_a_state;
		BIT_SIZE_t		word_bit_size;
		/*about substitution*/
		//distinct sbox in a state?(e.g., TRUE, FALSE)
		FLAG_t			distinct_sbox;
		//Sboxes
		SBOX_O_WRD_t *	sboxes;

		/*add from here*/
		SEARCHING_START_OPT_t *		searching_start_opt;
		DIFFUSION_BOUND_OPT_t *		diffusion_bound_opt;

		CNT_t * bitperm_idx;
	}SBPN_BLK_CIPHER_t;


	typedef struct
	{
		/*general information*/
		NUM_t			num_round;
		NUM_t			num_word_in_a_state;
		BIT_SIZE_t		word_bit_size;
		/*about substitution*/
		//distinct sbox in a state?(e.g., TRUE, FALSE)
		FLAG_t			distinct_sbox;
		//Sboxes
		SBOX_O_WRD_t *	sboxes;

		/*add from here*/
		SEARCHING_START_OPT_t *		searching_start_opt;
		DIFFUSION_BOUND_OPT_t *		diffusion_bound_opt;

		CNT_t * bin_mat;
		CNT_t * inv_bin_mat;
		CNT_t * inv_trans_bin_mat;
		CNT_t * trans_bin_mat;

		CNT_t * shuffle_idx;

	}SBMN_BLK_CIPHER_t;


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
	static CNT_t get_32word_hw(uint32_t word)
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

#if NUM_WORD_IN_A_STATE_THRESHOLD_CHECK <= 32
	/*this function only considers word size 32bit */
	static CNT_t get_word_hw(uint32_t word)
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
	/*************************************/
#elif NUM_WORD_IN_A_STATE_THRESHOLD_CHECK <= 64
	/*this function only considers word size 64bit */
	static CNT_t get_word_hw(uint64_t word)
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
	/*************************************/
#else

#endif



	/*Extern Functions*/
	DEV_DEFINE void Print_Module_Status(void);


	//Step1
	//1-1
	DEV_DEFINE void SPN_Prep_Info_For_DC(BLK_CIPHER_INFO_t * ci);
	DEV_DEFINE void SPN_Prep_Info_For_LC(BLK_CIPHER_INFO_t * ci);
	//1-2
	DEV_DEFINE void SPN_Prep_Info_For_DC_Active(BLK_CIPHER_INFO_t * ci, FLAG_t max_min);
	DEV_DEFINE void SPN_Prep_Info_For_LC_Active(BLK_CIPHER_INFO_t * ci, FLAG_t max_min);
	//1-3
	DEV_DEFINE void SPN_Prep_Info_For_DC_With_Prob_DDT(BLK_CIPHER_INFO_t * ci, PROB_t ** prob_ddts);
	DEV_DEFINE void SPN_Prep_Info_For_LC_With_Corr_LAT(BLK_CIPHER_INFO_t * ci, CORR_t ** corr_lats);
	
	//Step2
	//2-1
	DEV_DEFINE void Use_Defined_1Round_Active_Maps(BLK_CIPHER_INFO_t * ci, ACTIVE_MAP_t * _1round_active_maps, NUM_t num_maps, FLAG_t sorted_by_hw);
	//2-2
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps(BLK_CIPHER_INFO_t * ci);
	//2-3
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_AES128(BLK_CIPHER_INFO_t * ci);
	//2-4
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_LED64(BLK_CIPHER_INFO_t * ci);
	//2-5
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_MIDORI64(BLK_CIPHER_INFO_t * ci);
	//2-6
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_CRAFT64(BLK_CIPHER_INFO_t * ci);
	//2-7
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_SKINNY64(BLK_CIPHER_INFO_t * ci);
	//2-8
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_SKINNY128(BLK_CIPHER_INFO_t * ci);
	//2-9
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_BOGI16(BLK_CIPHER_INFO_t * ci, CNT_t omega_type);
	//2-10
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_BOGI32(BLK_CIPHER_INFO_t * ci, CNT_t omega_type);
	//2-11
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_BOGI64(BLK_CIPHER_INFO_t * ci, CNT_t omega_type);
	//2-12
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_BOGI128(BLK_CIPHER_INFO_t * ci, CNT_t omega_type);
	//2-13
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_BOGI176(BLK_CIPHER_INFO_t * ci, CNT_t omega_type);
	//2-14
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_BOGI256(BLK_CIPHER_INFO_t * ci, CNT_t omega_type);
	//2-15
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_GIFT64(BLK_CIPHER_INFO_t * ci);
	//2-16
	DEV_DEFINE void Use_Predefined_1Round_Active_Maps_GIFT128(BLK_CIPHER_INFO_t * ci);


	//Step3
	DEV_DEFINE void SPN_Best_DC_Prob_Search(PROB_t * prob_rst, BLK_CIPHER_INFO_t * ci, CNT_t set_round, CNT_t target_round, UFLAG_t verbose);
	DEV_DEFINE void SPN_Best_LC_Corr_Search(CORR_t * corr_rst, BLK_CIPHER_INFO_t * ci, CNT_t set_round, CNT_t target_round, UFLAG_t verbose);


	/*Predefined Blockciphers*/
	//SMN - Substitution Matrix-multiplication Network
	DEV_DEFINE extern BLK_CIPHER_INFO_t AES128;
	DEV_DEFINE void PY_AES128_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_AES128_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t LED64;
	DEV_DEFINE void PY_LED64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_LED64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);

	//SBMN - Substitution Binary-Matrix-multiplication Network
	DEV_DEFINE extern BLK_CIPHER_INFO_t MIDORI64;
	DEV_DEFINE void PY_MIDORI64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_MIDORI64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t SKINNY64;
	DEV_DEFINE void PY_SKINNY64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_SKINNY64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t SKINNY128;
	DEV_DEFINE void PY_SKINNY128_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_SKINNY128_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t CRAFT64;
	DEV_DEFINE void PY_CRAFT64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_CRAFT64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);


	//SBPN - Substitution Bit-Permutation Network
	DEV_DEFINE extern BLK_CIPHER_INFO_t GIFT64;
	DEV_DEFINE void PY_GIFT64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_GIFT64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t GIFT128;
	DEV_DEFINE void PY_GIFT128_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_GIFT128_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t PRESENT64;
	DEV_DEFINE void PY_PRESENT64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_PRESENT64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t PRESENT128;
	DEV_DEFINE void PY_PRESENT128_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_PRESENT128_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
#if NUM_WORD_IN_A_STATE_THRESHOLD_CHECK >= 44
	DEV_DEFINE extern BLK_CIPHER_INFO_t SPONGENT176;
	DEV_DEFINE void PY_SPONGENT176_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_SPONGENT176_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
#endif

	

	//SRBPN - Substitution Rotation-based Bit-Permutation Network
	DEV_DEFINE extern BLK_CIPHER_INFO_t RECTANGLE64;
	DEV_DEFINE void PY_RECTANGLE64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_RECTANGLE64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t FLY64;
	DEV_DEFINE void PY_FLY64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_FLY64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE extern BLK_CIPHER_INFO_t PIPO64;
	DEV_DEFINE void PY_PIPO64_DC_Prob_Searching(PROB_t * rst, CNT_t num_round, UFLAG_t verbose);
	DEV_DEFINE void PY_PIPO64_LC_Corr_Searching(CORR_t * rst, CNT_t num_round, UFLAG_t verbose);

	
	//BOGI16 Ciphers
	DEV_DEFINE void PY_BOGI16_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	DEV_DEFINE void PY_BOGI16_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	//BOGI32 Ciphers
	DEV_DEFINE void PY_BOGI32_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	DEV_DEFINE void PY_BOGI32_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	//BOGI64 Ciphers
	DEV_DEFINE void PY_BOGI64_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	DEV_DEFINE void PY_BOGI64_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	//BOGI128 Ciphers
	DEV_DEFINE void PY_BOGI128_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	DEV_DEFINE void PY_BOGI128_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);

	#if NUM_WORD_IN_A_STATE_THRESHOLD_CHECK >=44
	DEV_DEFINE void PY_BOGI176_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);
	DEV_DEFINE void PY_BOGI176_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);
	#endif

	#if NUM_WORD_IN_A_STATE_THRESHOLD_CHECK >=64
	DEV_DEFINE void PY_BOGI256_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);
	DEV_DEFINE void PY_BOGI256_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t sbox_idx,
		CNT_t perm_idx,
		UFLAG_t verbose
	);
	#endif


	//Template - SBMN
	DEV_DEFINE void SBMN_Template_DC_Prob_Searching(PROB_t * rst, SBMN_BLK_CIPHER_t * ci, UFLAG_t verbose);
	DEV_DEFINE void SBMN_Template_LC_Corr_Searching(CORR_t * rst, SBMN_BLK_CIPHER_t * ci, UFLAG_t verbose);
	DEV_DEFINE void PY_SBMN_Template_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t num_word_in_a_state,
		BIT_SIZE_t word_bit_size,
		FLAG_t distinct_sbox,
		SBOX_O_WRD_t * sboxes,
		CNT_t * bin_mat,
		CNT_t * inv_bin_mat,
		NUM_t diff_branch_num,
		CNT_t * inv_trans_bin_mat,
		CNT_t * trans_bin_mat,
		NUM_t inv_trans_diff_branch_num,
		CNT_t * shuffle_idx,
		FLAG_t enable_1round_active_map,
		FLAG_t rotational_symmetric_equivalent,
		NUM_t num_diff_of_partial_diffusion,
		UFLAG_t verbose
	);
	DEV_DEFINE void PY_SBMN_Template_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t num_word_in_a_state,
		BIT_SIZE_t word_bit_size,
		FLAG_t distinct_sbox,
		SBOX_O_WRD_t * sboxes,
		CNT_t * bin_mat,
		CNT_t * inv_bin_mat,
		NUM_t diff_branch_num,
		CNT_t * inv_trans_bin_mat,
		CNT_t * trans_bin_mat,
		NUM_t inv_trans_diff_branch_num,
		CNT_t * shuffle_idx,
		FLAG_t enable_1round_active_map,
		FLAG_t rotational_symmetric_equivalent,
		NUM_t num_diff_of_partial_diffusion,
		UFLAG_t verbose
	);

	//Template - SBPN
	DEV_DEFINE void SBPN_Template_DC_Prob_Searching(PROB_t * rst, SBPN_BLK_CIPHER_t * ci, UFLAG_t verbose);
	DEV_DEFINE void PY_SBPN_Template_DC_Prob_Searching(
		PROB_t * rst,
		CNT_t num_round,
		CNT_t num_word_in_a_state,
		BIT_SIZE_t word_bit_size,
		FLAG_t distinct_sbox,
		SBOX_O_WRD_t * sboxes,
		CNT_t  * perm_idx,
		FLAG_t enable_1round_active_map,
		FLAG_t rotational_symmetric_equivalent,
		NUM_t num_diff_of_partial_diffusion,
		UFLAG_t verbose
	);
	DEV_DEFINE void SBPN_Template_LC_Corr_Searching(CORR_t * rst, SBPN_BLK_CIPHER_t * ci, UFLAG_t verbose);
	DEV_DEFINE void PY_SBPN_Template_LC_Corr_Searching(
		CORR_t * rst,
		CNT_t num_round,
		CNT_t num_word_in_a_state,
		BIT_SIZE_t word_bit_size,
		FLAG_t distinct_sbox,
		SBOX_O_WRD_t * sboxes,
		CNT_t  * perm_idx,
		FLAG_t enable_1round_active_map,
		FLAG_t rotational_symmetric_equivalent,
		NUM_t num_diff_of_partial_diffusion,
		UFLAG_t verbose
	);

#ifdef __cplusplus
}
#endif /*extern "C"*/

#endif /*_ASTBB_H_*/