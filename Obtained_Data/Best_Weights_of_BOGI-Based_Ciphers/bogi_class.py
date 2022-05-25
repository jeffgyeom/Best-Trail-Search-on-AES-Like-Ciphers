import os
import pickle
import sys

from numpy.lib.function_base import average
THIS_FILE_DIR = os.path.dirname(__file__)
sys.path.append(THIS_FILE_DIR)
import bogi_util as bu
import numpy as np
import pandas as pd

DATA_PATH  = os.path.join(THIS_FILE_DIR, "__data")

DATA_LISTS = dict()
### BOGI-applicabls S-boxes
DATA_LISTS["BOGI-applicabls S-boxes Dict"       ] = os.path.join(DATA_PATH, "BOGI_sboxes.pickle")
### BOGI16 Permutations
DATA_LISTS["BOGI16 Permutations Dict"                   ] = os.path.join(DATA_PATH, "BOGI16_bitperm.pickle")
DATA_LISTS["BOGI16 Round Commuting Permutations Dict"   ] = os.path.join(DATA_PATH, "BOGI16_round_commuting_perm.pickle")
### BOGI64 Permutations
DATA_LISTS["BOGI32 Permutations Dict"                   ] = os.path.join(DATA_PATH, "BOGI32_bitperm.pickle")
DATA_LISTS["BOGI32 Round Commuting Permutations Dict"   ] = os.path.join(DATA_PATH, "BOGI32_round_commuting_perm.pickle")
### BOGI64 Permutations
DATA_LISTS["BOGI64 Permutations Dict"                   ] = os.path.join(DATA_PATH, "BOGI64_bitperm.pickle")
DATA_LISTS["BOGI64 Round Commuting Permutations Dict"   ] = os.path.join(DATA_PATH, "BOGI64_round_commuting_perm.pickle")
### BOGI128 Permutations
DATA_LISTS["BOGI128 Permutations Dict"                  ] = os.path.join(DATA_PATH, "BOGI128_bitperm.pickle")
DATA_LISTS["BOGI128 Round Commuting Permutations Dict"  ] = os.path.join(DATA_PATH, "BOGI128_round_commuting_perm.pickle")
### BOGI176 Permutations
DATA_LISTS["BOGI176 Permutations Dict"                  ] = os.path.join(DATA_PATH, "BOGI176_bitperm.pickle")
DATA_LISTS["BOGI176 Round Commuting Permutations Dict"  ] = os.path.join(DATA_PATH, "BOGI176_round_commuting_perm.pickle")
### BOGI256 Permutations
DATA_LISTS["BOGI256 Permutations Dict"                  ] = os.path.join(DATA_PATH, "BOGI256_bitperm.pickle")
DATA_LISTS["BOGI256 Round Commuting Permutations Dict"  ] = os.path.join(DATA_PATH, "BOGI256_round_commuting_perm.pickle")
### BOGI Cipher Probability Analysis Representives
DATA_LISTS["BOGI Cipher Representives"                  ] = os.path.join(DATA_PATH, "BOGI_cipher_prob_repre_info.pickle")
### BOGI16 Ciphers
DATA_LISTS["BOGI16 Best Differential Probability"       ] = os.path.join(DATA_PATH, "BOGI16_differential_prob.pickle")
DATA_LISTS["BOGI16 Best Linear Probability"             ] = os.path.join(DATA_PATH, "BOGI16_linear_prob.pickle")
### BOGI32 Ciphers
DATA_LISTS["BOGI32 Best Differential Probability"       ] = os.path.join(DATA_PATH, "BOGI32_differential_prob.pickle")
DATA_LISTS["BOGI32 Best Linear Probability"             ] = os.path.join(DATA_PATH, "BOGI32_linear_prob.pickle")
### BOGI64 Ciphers
DATA_LISTS["BOGI64 Best Differential Probability"       ] = os.path.join(DATA_PATH, "BOGI64_differential_prob.pickle")
DATA_LISTS["BOGI64 Best Linear Probability"             ] = os.path.join(DATA_PATH, "BOGI64_linear_prob.pickle")
### BOGI128 Ciphers
DATA_LISTS["BOGI128 Best Differential Probability"       ] = os.path.join(DATA_PATH, "BOGI128_differential_prob.pickle")
DATA_LISTS["BOGI128 Best Linear Probability"             ] = os.path.join(DATA_PATH, "BOGI128_linear_prob.pickle")
### BOGI256 Ciphers
DATA_LISTS["BOGI256 Best Differential Probability"       ] = os.path.join(DATA_PATH, "BOGI256_differential_prob.pickle")
DATA_LISTS["BOGI256 Best Linear Probability"             ] = os.path.join(DATA_PATH, "BOGI256_linear_prob.pickle")



### BOGI-Applicabls S-boxes
with open(DATA_LISTS["BOGI-applicabls S-boxes Dict"], "rb") as f:
    BOGI_SBOXES_DICT          = pickle.load(f)
    NUM_BOGI_SBOXES           = len(BOGI_SBOXES_DICT.keys())
    NUM_EFFICIENT_BOGI_SBOXES = 384
### BOGI16 Permutations
with open(DATA_LISTS["BOGI16 Permutations Dict"], "rb") as f:
    BOGI16_PERMUTATIONS_DICT    = pickle.load(f)
    NUM_BOGI16_PERMUTATIONS     = len(BOGI16_PERMUTATIONS_DICT.keys())
    NUM_BOGI_PERMUTATIONS       = NUM_BOGI16_PERMUTATIONS
with open(DATA_LISTS["BOGI16 Round Commuting Permutations Dict"], "rb") as f:
    BOGI16_ROUND_CUMMUTING_PERM_DICT = pickle.load(f)
### BOGI32 Permutations
with open(DATA_LISTS["BOGI32 Permutations Dict"], "rb") as f:
    BOGI32_PERMUTATIONS_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI32 Round Commuting Permutations Dict"], "rb") as f:
    BOGI32_ROUND_CUMMUTING_PERM_DICT = pickle.load(f)
### BOGI64 Permutations
with open(DATA_LISTS["BOGI64 Permutations Dict"], "rb") as f:
    BOGI64_PERMUTATIONS_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI64 Round Commuting Permutations Dict"], "rb") as f:
    BOGI64_ROUND_CUMMUTING_PERM_DICT = pickle.load(f)
### BOGI128 Permutations
with open(DATA_LISTS["BOGI128 Permutations Dict"], "rb") as f:
    BOGI128_PERMUTATIONS_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI128 Round Commuting Permutations Dict"], "rb") as f:
    BOGI128_ROUND_CUMMUTING_PERM_DICT = pickle.load(f)
### BOGI176 Permutations
with open(DATA_LISTS["BOGI176 Permutations Dict"], "rb") as f:
    BOGI176_PERMUTATIONS_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI176 Round Commuting Permutations Dict"], "rb") as f:
    BOGI176_ROUND_CUMMUTING_PERM_DICT = pickle.load(f)
### BOGI256 Permutations
with open(DATA_LISTS["BOGI256 Permutations Dict"], "rb") as f:
    BOGI256_PERMUTATIONS_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI256 Round Commuting Permutations Dict"], "rb") as f:
    BOGI256_ROUND_CUMMUTING_PERM_DICT = pickle.load(f)
### BOGI Cipher Probability Analysis Representives
with open(DATA_LISTS["BOGI Cipher Representives"], "rb") as f:
    BOGI_ANALYSIS_IDX_DICT = pickle.load(f)
### BOGI16 Ciphers
with open(DATA_LISTS["BOGI16 Best Differential Probability"], "rb") as f:
    BOGI16_DIFF_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI16 Best Linear Probability"], "rb") as f:
    BOGI16_LIN_DICT = pickle.load(f)
### BOGI32 Ciphers
with open(DATA_LISTS["BOGI32 Best Differential Probability"], "rb") as f:
    BOGI32_DIFF_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI32 Best Linear Probability"], "rb") as f:
    BOGI32_LIN_DICT = pickle.load(f)
### BOGI64 Ciphers
with open(DATA_LISTS["BOGI64 Best Differential Probability"], "rb") as f:
    BOGI64_DIFF_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI64 Best Linear Probability"], "rb") as f:
    BOGI64_LIN_DICT = pickle.load(f)
### BOGI128 Ciphers
with open(DATA_LISTS["BOGI128 Best Differential Probability"], "rb") as f:
    BOGI128_DIFF_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI128 Best Linear Probability"], "rb") as f:
    BOGI128_LIN_DICT = pickle.load(f)
### BOGI256 Ciphers
with open(DATA_LISTS["BOGI256 Best Differential Probability"], "rb") as f:
    BOGI256_DIFF_DICT = pickle.load(f)
with open(DATA_LISTS["BOGI256 Best Linear Probability"], "rb") as f:
    BOGI256_LIN_DICT = pickle.load(f)


GIFT_SIDX       = 94
INV_GIFT_SIDX   = 152
GIFT_PIDX       = 344
INV_GIFT_PIDX   = GIFT_PIDX #involutory
REPRE_SIDX_LIST = tuple(range(NUM_BOGI_SBOXES))
#S-boxes that are XOR-equivalent to S-boxes that have the same software/hardware implementation costs as them of GIFT's S-box (BGC : 11, GEC : 16)
BOGI_SBOX_GIFT_SAME_COSTS     = (11., 16.)
#S-boxes that are XOR-equivalent to S-boxes that have the optimal software-oriented implementation costs (BGC : 10, GEC : 16.66)
BOGI_SBOX_SOFT_ORIENTED_COSTS = (10., 16.66)
EFFIC_SIDX_LIST = tuple(range(NUM_EFFICIENT_BOGI_SBOXES))
REPRE_PIDX_LIST = (0, 1, 4, 6, 24, 25, 28, 30, 48, 50, 51, 54, 72, 74, 76, 77, 96, 98, 99, 102, 122, 124, 125, 344)

class bogi16_perm:
    total_num_bogi_permutations = NUM_BOGI16_PERMUTATIONS
    def __init__(self, pidx = 0):
        self.set_idx(pidx)
        
    def set_idx(self, pidx):
        if pidx<0 or pidx>=self.total_num_bogi_permutations:
            raise NameError("Out of range for pidx")
        
        self.pidx           = pidx
        self.p16            = BOGI16_PERMUTATIONS_DICT[pidx][0] #16-bit Permutation(MSB, SOURCE)
        self.ls             = BOGI16_PERMUTATIONS_DICT[pidx][1] #The Corresponding Latin Square
        self.is_repre       = BOGI16_PERMUTATIONS_DICT[pidx][2] #Whether This is a Representive
        self.repre_pidx     = BOGI16_PERMUTATIONS_DICT[pidx][3] #Representive P16 Index
        self.p16_class      = BOGI16_PERMUTATIONS_DICT[pidx][4] #INV_A o P16 o A - Equivalent Class
        self.in_transform   = BOGI16_PERMUTATIONS_DICT[pidx][5] #A(MSB, ENT_SOURCE) such that P16 = INV_A o REPRE_P16 o A
        self.out_transform  = BOGI16_PERMUTATIONS_DICT[pidx][6] #INV_A(MSB, ENT_SOURCE) such that P16 = INV_A o REPRE_P16 o A
        
        #Round Commuting Word-wise Permutations
        self.commuting_perm_type = BOGI16_ROUND_CUMMUTING_PERM_DICT[pidx][0] # Word-wise permutations Type
        self.commuting_perm = BOGI16_ROUND_CUMMUTING_PERM_DICT[pidx][1] # Word-wise permutations which are included in an iterative permutation characteristic

        if self.pidx == 344:
            self.add_info       = "This is GIFT's P16"
        elif self.repre_pidx == 344:
            self.add_info       = "This has the representive as GIFT's P16"
        else:
            self.add_info       = "None"

    def next(self):
        if self.pidx<(self.total_num_bogi_permutations-1):
            self.set_idx(self.pidx + 1)
            return True
        else:
            return False

    def prev(self):
        if self.pidx > 0:
            self.set_idx(self.pidx - 1)
            return True
        else:
            return False

    def __repre__(self):
        return self.pidx

    def __out_info__(self):
        outstr  = ""
        outstr += " > pidx                   : %d\n"%self.pidx
        outstr += " > Repre pidx             : %d (LS%d)\n"%(self.repre_pidx, REPRE_PIDX_LIST.index(self.repre_pidx))
        outstr += " > P16(MSB, SOURCE)       : %s\n"%str(self.p16)
        outstr += " > In Transform           : %s\n"%str(self.in_transform)
        outstr += " > Repre P16              : %s\n"%str(bogi64_perm(self.repre_pidx).p16)
        outstr += " > Out Transform          : %s\n"%str(self.out_transform)
        if self.add_info != "None":
            outstr += " > Additional Info        : %s\n"%str(self.add_info)
        outstr += " > Comm Perm Type         : %s\n"%(self.commuting_perm_type)
        outstr += " > Number of Comm Perm    : %d\n"%len(self.commuting_perm)
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI16 Permutation    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi32_perm(bogi16_perm):
    def set_idx(self, pidx):
        super().set_idx(pidx)

        assert(self.p16 == BOGI32_PERMUTATIONS_DICT[self.pidx][0])

        self.p32                = BOGI32_PERMUTATIONS_DICT[self.pidx][1]
        #Round Commuting Word-wise Permutations
        self.commuting_perm_type = BOGI32_ROUND_CUMMUTING_PERM_DICT[pidx][0] # Word-wise permutations Type
        self.commuting_perm     = BOGI32_ROUND_CUMMUTING_PERM_DICT[pidx][1] # Word-wise permutations which are included in an iterative permutation characteristic


    def __out_info__(self):
        outstr  = super().__out_info__()
        outstr += " > Is a Representive      : %s\n"%str(self.is_repre)
        outstr += " > P32(MSB, SOURCE)       : %s ...\n"%str(self.p32[:32])[:-1]
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI32 Permutation <<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi64_perm(bogi16_perm):
    def set_idx(self, pidx):
        super().set_idx(pidx)
        
        assert(self.p16 == BOGI64_PERMUTATIONS_DICT[self.pidx][0])

        self.p64                = BOGI64_PERMUTATIONS_DICT[self.pidx][1]
        #Round Commuting Word-wise Permutations
        self.commuting_perm_type = BOGI64_ROUND_CUMMUTING_PERM_DICT[pidx][0] # Word-wise permutations Type
        self.commuting_perm     = BOGI64_ROUND_CUMMUTING_PERM_DICT[pidx][1] # Word-wise permutations which are included in an iterative permutation characteristic


    def __out_info__(self):
        outstr  = super().__out_info__()
        outstr += " > Is a Representive      : %s\n"%str(self.is_repre)
        outstr += " > P64(MSB, SOURCE)       : %s ...\n"%str(self.p64[:16])[:-1]
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI64 Permutation <<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi128_perm(bogi16_perm):
    def set_idx(self, pidx):
        super().set_idx(pidx)
        self.p128 = BOGI128_PERMUTATIONS_DICT[pidx][1]
        #Round Commuting Word-wise Permutations
        self.commuting_perm_type = BOGI128_ROUND_CUMMUTING_PERM_DICT[pidx][0] # Word-wise permutations Type
        self.commuting_perm     = BOGI128_ROUND_CUMMUTING_PERM_DICT[pidx][1] # Word-wise permutations which are included in an iterative permutation characteristic

    
    def __out_info__(self):
        outstr = super().__out_info__()
        outstr += " > P128(MSB, SOURCE)      : %s ...\n"%str(self.p128[:16])[:-1]
        return outstr
    
    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI128 Permutation    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi176_perm(bogi16_perm):
    def set_idx(self, pidx):
        super().set_idx(pidx)
        self.p176 = BOGI176_PERMUTATIONS_DICT[pidx][1]
        #Round Commuting Word-wise Permutations
        self.commuting_perm_type = BOGI176_ROUND_CUMMUTING_PERM_DICT[pidx][0] # Word-wise permutations Type
        self.commuting_perm      = BOGI176_ROUND_CUMMUTING_PERM_DICT[pidx][1] # Word-wise permutations which are included in an iterative permutation characteristic

    def __out_info__(self):
        outstr = super().__out_info__()
        outstr += " > P176(MSB, SOURCE)      : %s ...\n"%str(self.p176[:16])[:-1]
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI176 Permutation    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi256_perm(bogi16_perm):
    def set_idx(self, pidx):
        super().set_idx(pidx)
        self.p256 = BOGI256_PERMUTATIONS_DICT[pidx][1]
        #Round Commuting Word-wise Permutations
        self.commuting_perm_type = BOGI256_ROUND_CUMMUTING_PERM_DICT[pidx][0] # Word-wise permutations Type
        self.commuting_perm      = BOGI256_ROUND_CUMMUTING_PERM_DICT[pidx][1] # Word-wise permutations which are included in an iterative permutation characteristic

    def __out_info__(self):
        outstr = super().__out_info__()
        outstr += " > P256(MSB, SOURCE)      : %s ...\n"%str(self.p256[:16])[:-1]
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI256 Permutation    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr



class bogi_sbox:
    total_num_bogi_sboxes = NUM_BOGI_SBOXES
    def __init__(self, sidx = 0):
        self.set_idx(sidx)
        
    def set_idx(self, sidx):
        if sidx<0 or sidx >=self.total_num_bogi_sboxes:
            raise NameError("Out of range for sidx")
        self.sidx                   = sidx
        self.lut                    = BOGI_SBOXES_DICT[sidx][0]
        self.pxe_idx                = BOGI_SBOXES_DICT[sidx][1]
        self.av_imple_costs_dict    = BOGI_SBOXES_DICT[sidx][2]
        av_imple_costs              = list(self.av_imple_costs_dict.keys())
        av_imple_costs.sort(key = lambda ele : (ele[0], ele[1]))
        self.best_cost_software_0   = av_imple_costs[0]
        av_imple_costs.sort(key = lambda ele : (ele[1], ele[0]))
        self.best_cost_umc180nm_1   = av_imple_costs[0]


    def __out_info__(self):
        outstr  = ""
        outstr += " > sidx                   : %d\n"%self.sidx
        outstr += " > PXE index              : %d\n"%self.pxe_idx
        outstr += " > LUT                    : %s\n"%str(self.lut)
        outstr += " === Considering XOR-Equivalent S-boxes to the Current S-box (i.e., DDTs are the Same) ===\n"
        outstr += " > Best Cost in Software  : %5.2f %s \n"%(self.best_cost_software_0[0],str(self.best_cost_software_0))
        outstr += " >    an Example LUT /%2d  : %s \n"%(len(self.av_imple_costs_dict[self.best_cost_software_0]), str(self.av_imple_costs_dict[self.best_cost_software_0][0]))
        outstr += " > Best Cost in UMC180nm  : %5.2f %s \n"%(self.best_cost_umc180nm_1[1],str(self.best_cost_umc180nm_1))
        outstr += " >    an Example LUT /%2d  : %s \n"%(len(self.av_imple_costs_dict[self.best_cost_umc180nm_1]), str(self.av_imple_costs_dict[self.best_cost_umc180nm_1][0]))
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI-applicable S-box    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi16_cipher:
    def __init__(self, sidx = 0, pidx = 0):
        self.sbox               = bogi_sbox(sidx)
        self.perm               = bogi16_perm(pidx)
        self.cipher_idx         = (sidx, pidx)
        self.repre_cipher_idx   = BOGI_ANALYSIS_IDX_DICT[(sidx, pidx)]
        self.is_repre           = (self.cipher_idx==self.repre_cipher_idx)
        self.has_bdp            = self.repre_cipher_idx in BOGI16_DIFF_DICT.keys()
        self.has_blp            = self.repre_cipher_idx in BOGI16_LIN_DICT.keys()
        self.has_bdp_trail      = self.is_repre and self.has_bdp
        self.has_blp_trail      = self.is_repre and self.has_blp

        if self.has_bdp:
            self.bdp         = [None] + list(BOGI16_DIFF_DICT[self.repre_cipher_idx][0])
            self.bdp_elapsed = BOGI16_DIFF_DICT[self.repre_cipher_idx][1]
        else:
            self.bdp         = None
            self.bdp_elapsed = None

        if self.has_blp:
            self.blp         = [None] + list(BOGI16_LIN_DICT[self.repre_cipher_idx][0])
            self.blp_elapsed = BOGI16_LIN_DICT[self.repre_cipher_idx][1]
        else:
            self.blp         = None
            self.blp_elapsed = None

    def __repre__(self):
        return self.cipher_idx

    def __out_info__(self):
        outstr  = " > Cipher Index           : %s[%s]\n"%(str(self.cipher_idx), str(self.repre_cipher_idx))
        outstr += " > Is Repre               : %s\n"%(str(self.is_repre))
        outstr += " ========== S-box Info =========\n"
        outstr += str(self.sbox.__out_info__())
        outstr += " === 16-Bit Permutation  Info ==\n"
        outstr += str(self.perm.__out_info__())
        outstr += " ====== Probability  Info ======\n"
        if self.has_bdp:
            outstr += " > BDP                    : %s\n"%str(list(np.round(self.bdp[1:], 1)))
            outstr += " > Elapsed Time(BDP)      : %s\n"%str(self.bdp_elapsed)
        else:
            outstr += " > BDP                    : None\n"
            outstr += " > Elapsed Time(BDP)      : None\n"
            
        if self.has_blp:
            outstr += " > BLP                    : %s\n"%str(list(np.round(self.blp[1:], 1)))
            outstr += " > Elapsed Time(BLP)      : %s\n"%str(self.blp_elapsed)
        else:
            outstr += " > BLP                    : None\n"
            outstr += " > Elapsed Time(BLP)      : None\n"

        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI16 Cipher    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi32_cipher:
    def __init__(self, sidx = 0, pidx = 0):
        self.sbox               = bogi_sbox(sidx)
        self.perm               = bogi32_perm(pidx)
        self.cipher_idx         = (sidx, pidx)
        self.repre_cipher_idx   = BOGI_ANALYSIS_IDX_DICT[(sidx, pidx)]
        self.is_repre           = (self.cipher_idx==self.repre_cipher_idx)
        self.has_bdp            = self.repre_cipher_idx in BOGI32_DIFF_DICT.keys()
        self.has_blp            = self.repre_cipher_idx in BOGI32_LIN_DICT.keys()
        self.has_bdp_trail      = self.is_repre and self.has_bdp
        self.has_blp_trail      = self.is_repre and self.has_blp
        
        if self.has_bdp:
            self.bdp         = [None] + list(BOGI32_DIFF_DICT[self.repre_cipher_idx][0])
            self.bdp_elapsed = BOGI32_DIFF_DICT[self.repre_cipher_idx][1]
        else:
            self.bdp         = None
            self.bdp_elapsed = None
        
        if self.has_blp:
            self.blp         = [None] + list(BOGI32_LIN_DICT[self.repre_cipher_idx][0])
            self.blp_elapsed = BOGI32_LIN_DICT[self.repre_cipher_idx][1]
        else:
            self.blp         = None
            self.blp_elapsed = None
        

    def __repre__(self):
        return self.cipher_idx

    def __out_info__(self):
        outstr  = " > Cipher Index           : %s[%s]\n"%(str(self.cipher_idx), str(self.repre_cipher_idx))
        outstr += " > Is Repre               : %s\n"%(str(self.is_repre))
        outstr += " ========== S-box Info =========\n"
        outstr += str(self.sbox.__out_info__())
        outstr += " == 32-Bit Permutation  Info ==\n"
        outstr += str(self.perm.__out_info__())
        outstr += " ====== Probability  Info ======\n"
        if self.has_bdp:
            outstr += " > BDP                    : %s\n"%str(list(np.round(self.bdp[1:], 1)))
            outstr += " > Elapsed Time(BDP)      : %s\n"%str(self.bdp_elapsed)
        else:
            outstr += " > BDP                    : None\n"
            outstr += " > Elapsed Time(BDP)      : None\n"
        
        if self.has_blp:
            outstr += " > BLP                    : %s\n"%str(list(np.round(self.blp[1:], 1)))
            outstr += " > Elapsed Time(BLP)      : %s\n"%str(self.blp_elapsed)
        else:
            outstr += " > BLP                    : None\n"
            outstr += " > Elapsed Time(BLP)      : None\n"
        
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI32 Cipher    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi64_cipher:
    def __init__(self, sidx = 0, pidx = 0):
        self.sbox               = bogi_sbox(sidx)
        self.perm               = bogi64_perm(pidx)
        self.cipher_idx         = (sidx, pidx)
        self.repre_cipher_idx   = BOGI_ANALYSIS_IDX_DICT[(sidx, pidx)]
        self.is_repre           = (self.cipher_idx==self.repre_cipher_idx)
        self.has_bdp            = self.repre_cipher_idx in BOGI64_DIFF_DICT.keys()
        self.has_blp            = self.repre_cipher_idx in BOGI64_LIN_DICT.keys()
        self.has_bdp_trail      = self.is_repre and self.has_bdp
        self.has_blp_trail      = self.is_repre and self.has_blp

        if self.has_bdp:
            self.bdp         = [None] + list(BOGI64_DIFF_DICT[self.repre_cipher_idx][0])
            self.bdp_elapsed = BOGI64_DIFF_DICT[self.repre_cipher_idx][1]
        else:
            self.bdp         = None
            self.bdp_elapsed = None

        if self.has_blp:
            self.blp         = [None] + list(BOGI64_LIN_DICT[self.repre_cipher_idx][0])
            self.blp_elapsed = BOGI64_LIN_DICT[self.repre_cipher_idx][1]
        else:
            self.blp         = None
            self.blp_elapsed = None

    def __repre__(self):
        return self.cipher_idx

    def __out_info__(self):
        outstr  = " > Cipher Index           : %s[%s]\n"%(str(self.cipher_idx), str(self.repre_cipher_idx))
        outstr += " > Is Repre               : %s\n"%(str(self.is_repre))
        outstr += " ========== S-box Info =========\n"
        outstr += str(self.sbox.__out_info__())
        outstr += " === 64-Bit Permutation  Info ==\n"
        outstr += str(self.perm.__out_info__())
        outstr += " ====== Probability  Info ======\n"
        if self.has_bdp:
            outstr += " > BDP                    : %s\n"%str(list(np.round(self.bdp[1:], 1)))
            outstr += " > Elapsed Time(BDP)      : %s\n"%str(self.bdp_elapsed)
        else:
            outstr += " > BDP                    : None\n"
            outstr += " > Elapsed Time(BDP)      : None\n"
            
        if self.has_blp:
            outstr += " > BLP                    : %s\n"%str(list(np.round(self.blp[1:], 1)))
            outstr += " > Elapsed Time(BLP)      : %s\n"%str(self.blp_elapsed)
        else:
            outstr += " > BLP                    : None\n"
            outstr += " > Elapsed Time(BLP)      : None\n"

        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI64 Cipher    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr


class bogi128_cipher:
    def __init__(self, sidx = 0, pidx = 0):
        self.sbox               = bogi_sbox(sidx)
        self.perm               = bogi128_perm(pidx)
        self.cipher_idx         = (sidx, pidx)
        self.repre_cipher_idx   = BOGI_ANALYSIS_IDX_DICT[(sidx, pidx)]
        self.is_repre           = (self.cipher_idx==self.repre_cipher_idx)
        self.has_bdp            = self.repre_cipher_idx in BOGI128_DIFF_DICT.keys()
        self.has_blp            = self.repre_cipher_idx in BOGI128_LIN_DICT.keys()
        self.has_bdp_trail      = self.is_repre and self.has_bdp 
        self.has_blp_trail      = self.is_repre and self.has_blp
        
        if self.has_bdp:
            self.bdp         = [None] + list(BOGI128_DIFF_DICT[self.repre_cipher_idx][0])
            self.bdp_elapsed = BOGI128_DIFF_DICT[self.repre_cipher_idx][1]
        else:
            self.bdp         = None
            self.bdp_elapsed = None
        
        if self.has_blp:
            self.blp         = [None] + list(BOGI128_LIN_DICT[self.repre_cipher_idx][0])
            self.blp_elapsed = BOGI128_LIN_DICT[self.repre_cipher_idx][1]
        else:
            self.blp         = None
            self.blp_elapsed = None
        

    def __repre__(self):
        return self.cipher_idx

    def __out_info__(self):
        outstr  = " > Cipher Index           : %s[%s]\n"%(str(self.cipher_idx), str(self.repre_cipher_idx))
        outstr += " > Is Repre               : %s\n"%(str(self.is_repre))
        outstr += " ========== S-box Info =========\n"
        outstr += str(self.sbox.__out_info__())
        outstr += " == 128-Bit Permutation  Info ==\n"
        outstr += str(self.perm.__out_info__())
        outstr += " ====== Probability  Info ======\n"
        if self.has_bdp:
            outstr += " > BDP                    : %s\n"%str(list(np.round(self.bdp[1:], 1)))
            outstr += " > Elapsed Time(BDP)      : %s\n"%str(self.bdp_elapsed)
        else:
            outstr += " > BDP                    : None\n"
            outstr += " > Elapsed Time(BDP)      : None\n"
        
        if self.has_blp:
            outstr += " > BLP                    : %s\n"%str(list(np.round(self.blp[1:], 1)))
            outstr += " > Elapsed Time(BLP)      : %s\n"%str(self.blp_elapsed)
        else:
            outstr += " > BLP                    : None\n"
            outstr += " > Elapsed Time(BLP)      : None\n"
        
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI128 Cipher    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

class bogi256_cipher:
    def __init__(self, sidx = 0, pidx = 0):
        self.sbox               = bogi_sbox(sidx)
        self.perm               = bogi256_perm(pidx)
        self.cipher_idx         = (sidx, pidx)
        self.repre_cipher_idx   = BOGI_ANALYSIS_IDX_DICT[(sidx, pidx)]
        self.is_repre           = (self.cipher_idx==self.repre_cipher_idx)
        self.has_bdp            = self.repre_cipher_idx in BOGI256_DIFF_DICT.keys()
        self.has_blp            = self.repre_cipher_idx in BOGI256_LIN_DICT.keys()
        self.has_bdp_trail      = self.is_repre and self.has_bdp 
        self.has_blp_trail      = self.is_repre and self.has_blp
        
        if self.has_bdp:
            self.bdp         = [None] + list(BOGI256_DIFF_DICT[self.repre_cipher_idx][0])
            self.bdp_elapsed = BOGI256_DIFF_DICT[self.repre_cipher_idx][1]
        else:
            self.bdp         = None
            self.bdp_elapsed = None
        
        if self.has_blp:
            self.blp         = [None] + list(BOGI256_LIN_DICT[self.repre_cipher_idx][0])
            self.blp_elapsed = BOGI256_LIN_DICT[self.repre_cipher_idx][1]
        else:
            self.blp         = None
            self.blp_elapsed = None
        

    def __repre__(self):
        return self.cipher_idx

    def __out_info__(self):
        outstr  = " > Cipher Index           : %s[%s]\n"%(str(self.cipher_idx), str(self.repre_cipher_idx))
        outstr += " > Is Repre               : %s\n"%(str(self.is_repre))
        outstr += " ========== S-box Info =========\n"
        outstr += str(self.sbox.__out_info__())
        outstr += " == 256-Bit Permutation  Info ==\n"
        outstr += str(self.perm.__out_info__())
        outstr += " ====== Probability  Info ======\n"
        if self.has_bdp:
            outstr += " > BDP                    : %s\n"%str(list(np.round(self.bdp[1:], 1)))
            outstr += " > Elapsed Time(BDP)      : %s\n"%str(self.bdp_elapsed)
        else:
            outstr += " > BDP                    : None\n"
            outstr += " > Elapsed Time(BDP)      : None\n"
        
        if self.has_blp:
            outstr += " > BLP                    : %s\n"%str(list(np.round(self.blp[1:], 1)))
            outstr += " > Elapsed Time(BLP)      : %s\n"%str(self.blp_elapsed)
        else:
            outstr += " > BLP                    : None\n"
            outstr += " > Elapsed Time(BLP)      : None\n"
        
        return outstr

    def __str__(self):
        outstr = ">>>>>>>>>>>>>>>>    BOGI256 Cipher    <<<<<<<<<<<<<<<<\n" + self.__out_info__()
        return outstr

BOGI16_CIPHER_ANALYSIS_ROUND  = 15
BOGI32_CIPHER_ANALYSIS_ROUND  = 15
BOGI64_CIPHER_ANALYSIS_ROUND  = 13
BOGI128_CIPHER_ANALYSIS_ROUND = 11
BOGI256_CIPHER_ANALYSIS_ROUND = 9

def bogi_cipher_rst_tab(r = 12, bit=64, check_sidx_range = REPRE_SIDX_LIST, check_pidx_range = REPRE_SIDX_LIST):
    assert(bit in [16, 32, 64, 128, 256])
    if bit == 16:
        assert(r >=1 and r <= BOGI16_CIPHER_ANALYSIS_ROUND)
    elif bit == 32:
        assert(r >=1 and r <= BOGI32_CIPHER_ANALYSIS_ROUND)
    elif bit == 64:
        assert(r >=1 and r <= BOGI64_CIPHER_ANALYSIS_ROUND)
    elif bit == 128:
        assert(r >=1 and r <= BOGI128_CIPHER_ANALYSIS_ROUND)
    elif bit == 256:
        assert(r >=1 and r <= BOGI256_CIPHER_ANALYSIS_ROUND)
    bdps = []
    blps = []

    if bit == 16:
        ccc = bogi16_cipher(GIFT_SIDX, GIFT_PIDX)
    elif bit == 32:
        ccc = bogi32_cipher(GIFT_SIDX, GIFT_PIDX)
    elif bit == 64:
        ccc = bogi64_cipher(GIFT_SIDX, GIFT_PIDX)
    elif bit == 128:
        ccc = bogi128_cipher(GIFT_SIDX, GIFT_PIDX)
    elif bit == 256:
        ccc = bogi256_cipher(GIFT_SIDX, GIFT_PIDX)

    if ccc.has_bdp and ccc.has_blp:
        print("GIFT : (%5.1f, %5.1f)"%(round(ccc.bdp[r], 1), round(ccc.blp[r], 1)))
    for sidx in check_sidx_range:
        for pidx in check_pidx_range:
            if bit == 16:
                ccc = bogi16_cipher(sidx, pidx)
            elif bit == 32:
                ccc = bogi32_cipher(sidx, pidx)
            elif bit == 64:
                ccc = bogi64_cipher(sidx, pidx)
            elif bit == 128:
                ccc = bogi128_cipher(sidx, pidx)
            elif bit == 256:
                ccc = bogi256_cipher(sidx, pidx)
            if ccc.has_bdp and ccc.has_blp:
                if round(ccc.bdp[r], 1) not in bdps:
                    bdps.append(round(ccc.bdp[r], 1))
                if round(ccc.blp[r], 1) not in blps:
                    blps.append(round(ccc.blp[r], 1))
    bdps.sort(reverse=True)
    blps.sort(reverse=True)

    idx = 0
    bdp_idx_dict = dict()
    for ele in bdps:
        bdp_idx_dict[ele] = idx
        idx+=1
    blp_idx_dict = dict()
    idx = 0
    for ele in blps:
        blp_idx_dict[ele] = idx
        idx+=1
    rst_tab = np.zeros((len(bdps), len(blps)), dtype=int)
    for sidx in check_sidx_range:
        for pidx in check_pidx_range:
            if bit == 16:
                ccc = bogi16_cipher(sidx, pidx)
            elif bit == 32:
                ccc = bogi32_cipher(sidx, pidx)
            elif bit == 64:
                ccc = bogi64_cipher(sidx, pidx)
            elif bit == 128:
                ccc = bogi128_cipher(sidx, pidx)
            elif bit == 256:
                ccc = bogi256_cipher(sidx, pidx)
            if ccc.has_bdp and ccc.has_blp:
                bdp = round(ccc.bdp[r], 1)
                blp = round(ccc.blp[r], 1)
                bdp_idx = bdp_idx_dict[bdp]
                blp_idx = blp_idx_dict[blp]
                rst_tab[bdp_idx][blp_idx]+=1
    return pd.DataFrame(rst_tab, index = bdps, columns = blps)






if __name__ == "__main__":

    def check_fix_point(s_lut):
        for in_val, ou_val in enumerate(s_lut):
            if in_val == ou_val:
                return True
        return False

    check_list = [
        "BOGI-16",
        "BOGI-32",
        "BOGI-64",
        "BOGI-128",
        "BOGI-256",
        "BOGI-64-GIFT-SBOX",
        "BOGI-128-GIFT-SBOX",
        "BOGI-64-GIFT-COST",
        "BOGI-128-GIFT-COST",
    ]
    for idx, c in enumerate(check_list):
        print("%2d) "%idx, c)
    choose = int(input("> (e.g., 0) "))
    print("> Chosen : %s"%(check_list[choose]))
    chosen = check_list[choose]

    if chosen == "BOGI-16":
        check_sidx_range = REPRE_SIDX_LIST
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 5
        opt_probs = (-17., -16.)
        tab = bogi_cipher_rst_tab(ROUND, 16, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-32":
        check_sidx_range = REPRE_SIDX_LIST
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 8
        opt_probs = (-33., -32.)
        tab = bogi_cipher_rst_tab(ROUND, 32, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-64":
        check_sidx_range = REPRE_SIDX_LIST
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 12
        opt_probs = (-68., -64.)
        tab = bogi_cipher_rst_tab(ROUND, 64, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-128":
        check_sidx_range = REPRE_SIDX_LIST
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 11
        opt_probs = (-72., -72.)
        tab = bogi_cipher_rst_tab(ROUND, 128, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-256":
        check_sidx_range = REPRE_SIDX_LIST
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 9
        opt_probs = (-51.8, -50.)
        tab = bogi_cipher_rst_tab(ROUND, 256, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-64-GIFT-SBOX":
        check_sidx_range = [GIFT_SIDX]
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 13
        opt_probs = (-69.4, -68.)
        tab = bogi_cipher_rst_tab(ROUND, 64, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-128-GIFT-SBOX":
        check_sidx_range = [GIFT_SIDX]
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 11
        opt_probs = (-68.8, -68.)
        tab = bogi_cipher_rst_tab(ROUND, 128, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-64-GIFT-COST":
        check_sidx_range = EFFIC_SIDX_LIST
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 13
        opt_probs = (-69.4, -68.)
        tab = bogi_cipher_rst_tab(ROUND, 64, check_sidx_range, check_pidx_range)
    if chosen == "BOGI-128-GIFT-COST":
        check_sidx_range = EFFIC_SIDX_LIST
        check_pidx_range = REPRE_PIDX_LIST
        ROUND = 11
        opt_probs = (-71.8, -68.)
        tab = bogi_cipher_rst_tab(ROUND, 128, check_sidx_range, check_pidx_range)
    bit = int(chosen.split("-")[1])
    
    print(tab)
    tab.to_excel("%s.xlsx"%(chosen))

    
    if type(opt_probs) != type(None):
        idx = 0
        print(">>>> %s that have %d-round best weights as %s <<<<"%(chosen, ROUND, str(opt_probs)))
        for sidx in check_sidx_range:
            for pidx in check_pidx_range:
                bc = eval("bogi%d_cipher(sidx, pidx)"%(bit))
                if (round(bc.bdp[ROUND], 1), round(bc.blp[ROUND], 1)) == opt_probs:
                    ##choose a S-box that has optimal implementation costs and does not have the fixed points.
                    ##software oriented
                    found = False
                    for sbox_lut in bc.sbox.av_imple_costs_dict[bc.sbox.best_cost_software_0]:
                        if check_fix_point(sbox_lut) == False:
                            print("%3d) %s with LS%2d at"%(idx, str(sbox_lut), REPRE_PIDX_LIST.index(pidx)), bc.sbox.best_cost_software_0)
                            found = True
                            break
                    if found == False:
                        print("%3d) Every S-box has at least one fixed point               with LS%2d at"%(idx, REPRE_PIDX_LIST.index(pidx)), bc.sbox.best_cost_software_0)

                    ##hardware oriented
                    found = False
                    for sbox_lut in bc.sbox.av_imple_costs_dict[bc.sbox.best_cost_umc180nm_1]:
                        if check_fix_point(sbox_lut) == False:
                            print("%3d) %s with LS%2d at"%(idx, str(sbox_lut), REPRE_PIDX_LIST.index(pidx)), bc.sbox.best_cost_umc180nm_1)
                            found = True
                            break
                    if found == False:
                        print("%3d) Every S-box has at least one fixed point               with LS%2d at"%(idx, REPRE_PIDX_LIST.index(pidx)), bc.sbox.best_cost_umc180nm_1)
                    idx+=1