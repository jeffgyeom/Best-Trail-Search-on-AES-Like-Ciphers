import struct
import os
from sys import platform
import sys
from ctypes import *

system_bit = struct.calcsize("P") * 8
#Load libarary and Set S-boxes info path
#The path of the directory including this file
THIS_FILE_DIR = os.path.dirname(os.path.realpath(__file__))

if system_bit == 64:
    LIB_PATH = os.path.join(THIS_FILE_DIR,"ASTBB","x64","Release")
else:#default
    LIB_PATH = os.path.join(THIS_FILE_DIR,"ASTBB","x86","Release")


if platform == "linux" or platform == "linux2":
    # linux
    LIB_PATH = os.path.join(LIB_PATH,"libASTBB_Linux.so")
    libatsbb = CDLL(LIB_PATH)
elif platform == "win32":
    # Windows
    LIB_PATH = os.path.join(LIB_PATH,"ASTBB_Windows.dll")
    libatsbb = CDLL(LIB_PATH)



#Array Allocations
# 32-bit unsigned int
#e.g., DDT = c_uint32_array(256 * 256).array
# 32-bit signed int
#e.g., LAT = c_int32_array(256 * 256).array
class c_uint32_array:
    def __init__(self, length=1, values = None):
        self.length = length
        self.array  = (c_uint32 * length)()
        if values != None:
            list_values = list(values)
            for idx in range(len(list_values)):
                self.array[idx] = list_values[idx]

class c_int32_array:
    def __init__(self, length=1, values = None):
        self.length = length
        self.array  = (c_int32 * length)()
        if values != None:
            list_values = list(values)
            for idx in range(len(list_values)):
                self.array[idx] = list_values[idx]
class c_double_array:
    def __init__(self, length=1):
        self.length = length
        self.array  = (c_double * length)()


class c_longdouble_array:
    def __init__(self, length=1):
        self.length = length
        self.array  = (c_longdouble * length)()

#Followings are the same as atsbb.h

#Define types to use
'''
Attention! as you can see, 1) input(output) word of S-box must has the same data type as output(input) word of Diffusion
                           2) the size of CNT_t must be bigger than "REAL-USED" word size
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
	typedef int32_t			NUM_t;
	typedef char			CHAR_t;
	typedef uint32_t		ACTIVE_MAP_t;
'''
class CORR_t(Structure):
    _fields_ = [
        ("sign", c_int32),
        ("magnitude", c_double),
        ]

SUCCESS	 = 0
FAILURE	 = -1
TRUE     = 1
FALSE	 = -1
NEGA     = -1
ZERO     = 0
POSI     = 1

SPN		 = 1
FEISTEL	 = 2
ARX		 = 3

BIT_PERMUTATION             = 1
PARTIAL_BINARY_MATRIX		= 2
PARTIAL_NON_BINARY_MATRIX	= 3
FULL_BINARY_MATRIX			= 4
FULL_NON_BINARY_MATRIX		= 5

NEGA =-1
ZERO = 0
POSI = 1

UNKNOWN = -1

VV_ALL					    =(0b111111111)
VV_OFF					    =(0b000000000)
VV_ROUND_PROGRESS		    =(0b000000001) #not available
VV_UPDATE_BOUND 		    =(0b000000010)
VV_UPDATE_BOUND_TRAIL	    =(0b000000100)
VV_LAST_UPDATE_TRAIL	    =(0b000001000)
VV_PROGRESS				    =(0b000010000)
VV_LAST_RESULT			    =(0b000100000) 
VV_ACTIVE_MAP_PROGRESS	    =(0b001000000) #not available
VV_ETA					    =(0b010000000) #not available
VV_FILE_PRINT				=(0b100000000)


########################

#BOGI Ciphers
PY_BOGI16_DC_Prob_Searching  = libatsbb['PY_BOGI16_DC_Prob_Searching']
PY_BOGI16_LC_Corr_Searching  = libatsbb['PY_BOGI16_LC_Corr_Searching']
PY_BOGI32_DC_Prob_Searching  = libatsbb['PY_BOGI32_DC_Prob_Searching']
PY_BOGI32_LC_Corr_Searching  = libatsbb['PY_BOGI32_LC_Corr_Searching']
PY_BOGI64_DC_Prob_Searching  = libatsbb['PY_BOGI64_DC_Prob_Searching']
PY_BOGI64_LC_Corr_Searching  = libatsbb['PY_BOGI64_LC_Corr_Searching']
PY_BOGI128_DC_Prob_Searching = libatsbb['PY_BOGI128_DC_Prob_Searching']
PY_BOGI128_LC_Corr_Searching = libatsbb['PY_BOGI128_LC_Corr_Searching']
PY_BOGI176_DC_Prob_Searching = libatsbb['PY_BOGI176_DC_Prob_Searching']
PY_BOGI176_LC_Corr_Searching = libatsbb['PY_BOGI176_LC_Corr_Searching']
PY_BOGI256_DC_Prob_Searching = libatsbb['PY_BOGI256_DC_Prob_Searching']
PY_BOGI256_LC_Corr_Searching = libatsbb['PY_BOGI256_LC_Corr_Searching']


class BOGI16_Cipher:
    def __init__(self, num_round, sbox_idx, perm_idx):
        self.num_round = int(num_round)
        self.sbox_idx  = int(sbox_idx)
        self.perm_idx  = int(perm_idx)

        if self.num_round > 40:
            raise ValueError("Rounds must not be bigger than 40")
        
        if (self.sbox_idx < 0) or (self.sbox_idx > 1727):
            raise ValueError("0 <= S-box Index <= 1727")
        
        if (self.perm_idx < 0) or (self.perm_idx > 575):
            raise ValueError("0 <= Perm Index <= 575")
        
        self.ct_num_round = c_int32(self.num_round)
        self.ct_sbox_idx  = c_int32(self.sbox_idx)
        self.ct_perm_idx  = c_int32(self.perm_idx)
        
        self.ct_prob_rst = c_double_array(self.num_round).array
        self.ct_corr_rst = (CORR_t * self.num_round)()

    def DC_Prob_Searching(self, verbose):

        PY_BOGI16_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self, verbose):

        PY_BOGI16_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI32_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self, verbose):

        PY_BOGI32_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self, verbose):

        PY_BOGI32_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI64_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self, verbose):

        PY_BOGI64_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self, verbose):

        PY_BOGI64_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI128_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self, verbose):

        PY_BOGI128_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self, verbose):

        PY_BOGI128_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI176_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self, verbose):

        PY_BOGI176_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self, verbose):

        PY_BOGI176_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI256_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self, verbose):

        PY_BOGI256_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self, verbose):

        PY_BOGI256_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx,
            c_uint32(verbose)
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))


SBPN_Template_DC_Prob_Searching = libatsbb['PY_SBPN_Template_DC_Prob_Searching']                          
SBPN_Template_DC_Prob_Searching.argtype = (
    POINTER(c_double), #prob results
    c_int32, #num_round
    c_int32, #num_word_in_a_state
    c_int32, #word_bit_size
    c_int32, #distinct_sbox
    POINTER(c_uint32), #sboxes
    POINTER(c_int32), #perm_idx
    c_int32, #enable_1round_active_map
    c_int32, #rotational_symmetric_equivalent
    c_int32, #num_diff_of_partial_diffusion
    c_uint32 #verbose
	)



SBPN_Template_LC_Corr_Searching = libatsbb['PY_SBPN_Template_LC_Corr_Searching']                          
SBPN_Template_LC_Corr_Searching.argtype = (
    POINTER(CORR_t), #corr results
    c_int32, #num_round
    c_int32, #num_word_in_a_state
    c_int32, #word_bit_size
    c_int32, #distinct_sbox
    POINTER(c_uint32), #sboxes
    POINTER(c_int32), #perm_idx
    c_int32, #enable_1round_active_map
    c_int32, #rotational_symmetric_equivalent
    c_int32, #num_diff_of_partial_diffusion
    c_uint32 #verbose
	)


########################



class SBPN_Cipher:
    def __init__(self, num_round, num_word_in_a_state, word_bit_size, distinct_sbox, sboxes, num_diff_of_partial_diffusion, perm_idx):
        self.num_round              = num_round
        self.num_word_in_a_state    = num_word_in_a_state
        self.word_bit_size          = word_bit_size
        self.block_bit_size         = self.num_word_in_a_state * self.word_bit_size
        self.distinct_sbox          = distinct_sbox
        self.num_diff_of_partial_diffusion = num_diff_of_partial_diffusion

        #check size
        self.sboxes                 = tuple(sboxes)
        self.perm_idx               = tuple(perm_idx)

        #ctype
        self.ct_num_round              = c_int32(self.num_round)
        self.ct_num_word_in_a_state    = c_int32(self.num_word_in_a_state)
        self.ct_word_bit_size          = c_int32(self.word_bit_size)
        if distinct_sbox in [TRUE, FALSE]:
            self.ct_distinct_sbox          = c_int32(distinct_sbox)
        else:
            raise NameError("Flag Option is not compatible")

        if distinct_sbox == FALSE:
            if len(list(sboxes)) != 2**self.word_bit_size:
                raise NameError("The S-box size is not correct")
            list_sboxes = []
            for idx in range(self.num_word_in_a_state):
                list_sboxes = list_sboxes + list(self.sboxes)
        else:
            if len(list(sboxes)) != (2**self.word_bit_size) * self.num_word_in_a_state:
                raise NameError("The S-box size is not correct")
            list_sboxes = list(self.sboxes)
        
        self.ct_sboxes = c_uint32_array(len(list_sboxes), list_sboxes).array
        if len(list(self.perm_idx)) != self.block_bit_size:
            raise NameError("The Permutation size is not correct")
        self.ct_perm_idx = c_int32_array(len(self.perm_idx), self.perm_idx).array

        #self.ct_prob_rst = c_double_array(self.num_round).array

    def DC_Prob_Searching(self, enable_1round_active_map, rotational_symmetric_equivalent, verbose):

        if enable_1round_active_map not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")

        if rotational_symmetric_equivalent not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")
        
        if self.num_diff_of_partial_diffusion > self.num_word_in_a_state:
            raise NameError("Flag Option is not compatible")

        ct_prob_rst = c_double_array(self.num_round).array

        SBPN_Template_DC_Prob_Searching(
            ct_prob_rst,
            self.ct_num_round,
            self.ct_num_word_in_a_state,
            self.ct_word_bit_size,
            self.ct_distinct_sbox,
            self.ct_sboxes,
            self.ct_perm_idx,
            c_int32(enable_1round_active_map),
            c_int32(rotational_symmetric_equivalent),
            c_int32(self.num_diff_of_partial_diffusion),
            c_uint32(verbose)
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(ct_prob_rst[i]))

    def LC_Corr_Searching(self, enable_1round_active_map, rotational_symmetric_equivalent, verbose):
    
        if enable_1round_active_map not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")
        
        if rotational_symmetric_equivalent not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")
        
        if self.num_diff_of_partial_diffusion > self.num_word_in_a_state:
            raise NameError("Flag Option is not compatible")
        
        ct_corr_rst = (CORR_t * self.num_round)()
        
        SBPN_Template_LC_Corr_Searching(
            ct_corr_rst,
            self.ct_num_round,
            self.ct_num_word_in_a_state,
            self.ct_word_bit_size,
            self.ct_distinct_sbox,
            self.ct_sboxes,
            self.ct_perm_idx,
            c_int32(enable_1round_active_map),
            c_int32(rotational_symmetric_equivalent),
            c_int32(self.num_diff_of_partial_diffusion),
            c_uint32(verbose)
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(ct_corr_rst[i].magnitude))



SBMN_Template_DC_Prob_Searching = libatsbb['PY_SBMN_Template_DC_Prob_Searching']                          
SBMN_Template_DC_Prob_Searching.argtype = (
    POINTER(c_double), #prob results
    c_int32, #num_round
    c_int32, #num_word_in_a_state
    c_int32, #word_bit_size
    c_int32, #distinct_sbox
    POINTER(c_uint32),  #sboxes
    POINTER(c_int32),   #bin_mat,
	POINTER(c_int32),   #inv_bin_mat,
	c_int32,            #diff_branch_num,
	POINTER(c_int32),   # inv_trans_bin_mat,
	POINTER(c_int32),   #trans_bin_mat,
    c_int32,            #inv_trans_diff_branch_num,
	POINTER(c_int32),   #shuffle_idx,
    c_int32, #enable_1round_active_map
    c_int32, #rotational_symmetric_equivalent
    c_int32, #num_diff_of_partial_diffusion
    c_uint32 #verbose
	)

SBMN_Template_LC_Corr_Searching = libatsbb['PY_SBMN_Template_LC_Corr_Searching']                          
SBMN_Template_LC_Corr_Searching.argtype = (
    POINTER(CORR_t), #corr results
    c_int32, #num_round
    c_int32, #num_word_in_a_state
    c_int32, #word_bit_size
    c_int32, #distinct_sbox
    POINTER(c_uint32),  #sboxes
    POINTER(c_int32),   #bin_mat,
	POINTER(c_int32),   #inv_bin_mat,
	c_int32,            #diff_branch_num,
	POINTER(c_int32),   # inv_trans_bin_mat,
	POINTER(c_int32),   #trans_bin_mat,
    c_int32,            #inv_trans_diff_branch_num,
	POINTER(c_int32),   #shuffle_idx,
    c_int32, #enable_1round_active_map
    c_int32, #rotational_symmetric_equivalent
    c_int32, #num_diff_of_partial_diffusion
    c_uint32 #verbose
	)

########################


class SBMN_Cipher:
    def __init__(self, 
                 num_round, 
                 num_word_in_a_state, 
                 word_bit_size, 
                 distinct_sbox, 
                 sboxes, 
                 num_diff_of_partial_diffusion, 
                 bin_mat, 
                 inv_bin_mat, 
                 diff_branch_num, 
                 inv_trans_bin_mat, 
                 trans_bin_mat, 
                 inv_trans_diff_branch_num,
                 shuffle_idx):
        self.num_round              = num_round
        self.num_word_in_a_state    = num_word_in_a_state
        self.word_bit_size          = word_bit_size
        self.distinct_sbox          = distinct_sbox
        
        #check size
        self.sboxes                     = tuple(sboxes)

        self.shuffle_idx                = tuple(shuffle_idx)

        self.num_diff_of_partial_diffusion = num_diff_of_partial_diffusion

        self.bin_mat                    = tuple(bin_mat)
        self.inv_bin_mat                = tuple(inv_bin_mat)
        self.diff_branch_num            = diff_branch_num
        
        self.inv_trans_bin_mat          = tuple(inv_trans_bin_mat)
        self.trans_bin_mat              = tuple(trans_bin_mat)
        self.inv_trans_diff_branch_num  = inv_trans_diff_branch_num


        #ctype
        self.ct_num_round              = c_int32(self.num_round)
        self.ct_num_word_in_a_state    = c_int32(self.num_word_in_a_state)
        self.ct_word_bit_size          = c_int32(self.word_bit_size)
        if distinct_sbox in [TRUE, FALSE]:
            self.ct_distinct_sbox          = c_int32(distinct_sbox)
        else:
            raise NameError("Flag Option is not compatible")

        if distinct_sbox == FALSE:
            if len(list(sboxes)) != 2**self.word_bit_size:
                raise NameError("The S-box size is not correct")
            list_sboxes = []
            for idx in range(self.num_word_in_a_state):
                list_sboxes = list_sboxes + list(self.sboxes)
        else:
            if len(list(sboxes)) != (2**self.word_bit_size) * self.num_word_in_a_state:
                raise NameError("The S-box size is not correct")
            list_sboxes = list(self.sboxes)
        self.ct_sboxes = c_uint32_array(len(list_sboxes), list_sboxes).array

        if len(self.shuffle_idx)  != self.num_word_in_a_state:
            raise NameError("shuffle idx length is not correct")
        self.ct_shuffle_idx = c_int32_array(len(self.shuffle_idx), self.shuffle_idx).array

        if len(list(self.bin_mat)) != self.num_diff_of_partial_diffusion*self.num_diff_of_partial_diffusion:
            raise NameError("binary matrix size is not correct")
        self.ct_bin_mat = c_int32_array(len(self.bin_mat), self.bin_mat).array

        if len(list(self.inv_bin_mat)) != self.num_diff_of_partial_diffusion*self.num_diff_of_partial_diffusion:
            raise NameError("inverse binary matrix size is not correct")
        self.ct_inv_bin_mat = c_int32_array(len(self.inv_bin_mat), self.inv_bin_mat).array

        if len(list(self.inv_trans_bin_mat)) != self.num_diff_of_partial_diffusion*self.num_diff_of_partial_diffusion:
            raise NameError("inverse transpose binary matrix size is not correct")
        self.ct_inv_trans_bin_mat = c_int32_array(len(self.inv_trans_bin_mat), self.inv_trans_bin_mat).array

        if len(list(self.trans_bin_mat)) != self.num_diff_of_partial_diffusion*self.num_diff_of_partial_diffusion:
            raise NameError("transpose binary matrix size is not correct")
        self.ct_trans_bin_mat = c_int32_array(len(self.trans_bin_mat), self.trans_bin_mat).array


    def DC_Prob_Searching(self, enable_1round_active_map, rotational_symmetric_equivalent, verbose):

        if enable_1round_active_map not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")

        if rotational_symmetric_equivalent not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")

        if self.num_diff_of_partial_diffusion > self.num_word_in_a_state:
            raise NameError("Flag Option is not compatible")

        ct_prob_rst = c_double_array(self.num_round).array

        SBMN_Template_DC_Prob_Searching(
            ct_prob_rst,
            self.ct_num_round,
            self.ct_num_word_in_a_state,
            self.ct_word_bit_size,
            self.ct_distinct_sbox,
            self.ct_sboxes,
            self.ct_bin_mat,
            self.ct_inv_bin_mat,
            c_int32(self.diff_branch_num),
            self.ct_inv_trans_bin_mat,
            self.ct_trans_bin_mat,
            c_int32(self.inv_trans_diff_branch_num),
            self.ct_shuffle_idx,
            c_int32(enable_1round_active_map),
            c_int32(rotational_symmetric_equivalent),
            c_int32(self.num_diff_of_partial_diffusion),
            c_uint32(verbose)
	    )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(ct_prob_rst[i]))

    def LC_Corr_Searching(self, enable_1round_active_map, rotational_symmetric_equivalent, verbose):
    
        if enable_1round_active_map not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")
        
        if rotational_symmetric_equivalent not in [TRUE, FALSE]:
            raise NameError("Flag Option is not compatible")
        
        if self.num_diff_of_partial_diffusion > self.num_word_in_a_state:
            raise NameError("Flag Option is not compatible")
        
        ct_corr_rst = (CORR_t * self.num_round)()
        SBMN_Template_LC_Corr_Searching(
            ct_corr_rst,
            self.ct_num_round,
            self.ct_num_word_in_a_state,
            self.ct_word_bit_size,
            self.ct_distinct_sbox,
            self.ct_sboxes,
            self.ct_bin_mat,
            self.ct_inv_bin_mat,
            c_int32(self.diff_branch_num),
            self.ct_inv_trans_bin_mat,
            self.ct_trans_bin_mat,
            c_int32(self.inv_trans_diff_branch_num),
            self.ct_shuffle_idx,
            c_int32(enable_1round_active_map),
            c_int32(rotational_symmetric_equivalent),
            c_int32(self.num_diff_of_partial_diffusion),
            c_uint32(verbose)
	    )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(ct_corr_rst[i].magnitude))


if __name__ == "__main__":
    
    ## Example 1

    #GIFT
    sbox_lut       = (1, 10, 4, 12, 6, 15, 3, 9, 2, 13, 11, 7, 5, 0, 8, 14) # GIFT-Sbox
    perm_idx       = (
        12, 1, 6, 11, 28, 17, 22, 27, 44, 33, 38, 43, 60, 49, 54, 59, 8, 
        13, 2, 7, 24, 29, 18, 23, 40, 45, 34, 39, 56, 61, 50, 55, 4, 9, 
        14, 3, 20, 25, 30, 19, 36, 41, 46, 35, 52, 57, 62, 51, 0, 5, 10, 
        15, 16, 21, 26, 31, 32, 37, 42, 47, 48, 53, 58, 63) #GIFT-64 bit permutation
    bb = SBPN_Cipher(
        num_round = 7,
        num_word_in_a_state = 16,
        word_bit_size = 4,
        distinct_sbox = FALSE,
        sboxes        = sbox_lut,
        num_diff_of_partial_diffusion = 4,                 #The size of M in Mixing Layer.
        perm_idx      = perm_idx
        )
    bb.DC_Prob_Searching(
        enable_1round_active_map = TRUE,
        rotational_symmetric_equivalent = FALSE,
        verbose = 272
        )
    print(bb.DC_Prob_Results)
    bb.LC_Corr_Searching(
        enable_1round_active_map = TRUE,
        rotational_symmetric_equivalent = FALSE,
        verbose = 272
        )
    print(bb.LC_Corr_Results)
    
    #MIDORI
    sbox_lut       = (12, 10, 13, 3, 14, 11, 15, 7, 8, 9, 1, 5, 0, 2, 4, 6) # MIDORI-Sbox
    bin_mat = [
        0, 1, 1, 1, 
        1, 0, 1, 1,
        1, 1, 0, 1,
        1, 1, 1, 0
        ]
    inv_bin_mat = bin_mat
    trans_bin_mat = bin_mat
    inv_trans_bin_mat = bin_mat
    shuffle_idx  = (0, 10, 5, 15, 14, 4, 11, 1, 9, 3, 12, 6, 7, 13, 2, 8)

    bb = SBMN_Cipher(
        num_round = 3,
        num_word_in_a_state = 16,
        word_bit_size = 4,
        distinct_sbox = FALSE,
        sboxes = sbox_lut,
        num_diff_of_partial_diffusion = 4,                 #The size of M in Mixing Layer.
        bin_mat       = bin_mat,                           #Midori Matrix M
        inv_bin_mat   = inv_bin_mat,                       #M = M^{-1}
        diff_branch_num = 4,                               #Branch Number
        inv_trans_bin_mat = inv_trans_bin_mat,             #M = M^{-T}
        trans_bin_mat     = trans_bin_mat,                 #M = M^{T}
        inv_trans_diff_branch_num  = 4,
        shuffle_idx       = shuffle_idx                    # The sigma of Shuffle Layer
        )
    bb.DC_Prob_Searching(
        enable_1round_active_map = TRUE,
        rotational_symmetric_equivalent = FALSE,
        verbose = 272
        )
    print(bb.DC_Prob_Results)
    bb.LC_Corr_Searching(
        enable_1round_active_map = TRUE,
        rotational_symmetric_equivalent = FALSE,
        verbose = 272
        )
    print(bb.LC_Corr_Results)


    ## Example 2
    analysis_round = 7
    bogi_sbox_idx  = 94   #This must be 0 ~ 1727, GIFT_SBOX_IDX = 94
    bogi_pbox_idx  = 344  #This must be 0 ~ 575,  GIFT_PBOX_IDX = 344
    verbose_mode   = 272
    bb = BOGI64_Cipher(analysis_round, bogi_sbox_idx, bogi_pbox_idx)
    bb.DC_Prob_Searching(verbose_mode)
    print(bb.DC_Prob_Results)
    bb.LC_Corr_Searching(verbose_mode)
    print(bb.LC_Corr_Results)


