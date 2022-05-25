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


LIB_PATH_DICT = dict()

if platform == "linux" or platform == "linux2":
    # linux
    LIB_PATH_DICT["libatsbb16"]  = os.path.join(LIB_PATH,"libASTBB_Linux_16.so")
    LIB_PATH_DICT["libatsbb32"]  = os.path.join(LIB_PATH,"libASTBB_Linux_32.so")
    LIB_PATH_DICT["libatsbb64"]  = os.path.join(LIB_PATH,"libASTBB_Linux_64.so")
    LIB_PATH_DICT["libatsbb128"] = os.path.join(LIB_PATH,"libASTBB_Linux_128.so")
    LIB_PATH_DICT["libatsbb176"] = os.path.join(LIB_PATH,"libASTBB_Linux_176.so")
    LIB_PATH_DICT["libatsbb256"] = os.path.join(LIB_PATH,"libASTBB_Linux_256.so") 

elif platform == "win32":
    # Windows
    LIB_PATH_DICT["libatsbb16"]  = os.path.join(LIB_PATH,"ASTBB_Windows_16.dll")
    LIB_PATH_DICT["libatsbb32"]  = os.path.join(LIB_PATH,"ASTBB_Windows_32.dll")
    LIB_PATH_DICT["libatsbb64"]  = os.path.join(LIB_PATH,"ASTBB_Windows_64.dll")
    LIB_PATH_DICT["libatsbb128"] = os.path.join(LIB_PATH,"ASTBB_Windows_128.dll")
    LIB_PATH_DICT["libatsbb176"] = os.path.join(LIB_PATH,"ASTBB_Windows_176.dll")
    LIB_PATH_DICT["libatsbb256"] = os.path.join(LIB_PATH,"ASTBB_Windows_256.dll") 

libatsbb16  = CDLL(LIB_PATH_DICT["libatsbb16"])
libatsbb32  = CDLL(LIB_PATH_DICT["libatsbb32"])
libatsbb64  = CDLL(LIB_PATH_DICT["libatsbb64"])
libatsbb128 = CDLL(LIB_PATH_DICT["libatsbb128"])
libatsbb176 = CDLL(LIB_PATH_DICT["libatsbb176"])
libatsbb256 = CDLL(LIB_PATH_DICT["libatsbb256"])

class c_double_array:
    def __init__(self, length=1):
        self.length = length
        self.array  = (c_double * length)()

class CORR_t(Structure):
    _fields_ = [
        ("sign", c_int32),
        ("magnitude", c_double),
        ]

#BOGI Ciphers
PY_BOGI16_DC_Prob_Searching  = libatsbb16['PY_BOGI16_DC_Prob_Searching']
PY_BOGI16_LC_Corr_Searching  = libatsbb16['PY_BOGI16_LC_Corr_Searching']

PY_BOGI32_DC_Prob_Searching  = libatsbb32['PY_BOGI32_DC_Prob_Searching']
PY_BOGI32_LC_Corr_Searching  = libatsbb32['PY_BOGI32_LC_Corr_Searching']

PY_BOGI64_DC_Prob_Searching  = libatsbb64['PY_BOGI64_DC_Prob_Searching']
PY_BOGI64_LC_Corr_Searching  = libatsbb64['PY_BOGI64_LC_Corr_Searching']

PY_BOGI128_DC_Prob_Searching = libatsbb128['PY_BOGI128_DC_Prob_Searching']
PY_BOGI128_LC_Corr_Searching = libatsbb128['PY_BOGI128_LC_Corr_Searching']

PY_BOGI176_DC_Prob_Searching = libatsbb176['PY_BOGI176_DC_Prob_Searching']
PY_BOGI176_LC_Corr_Searching = libatsbb176['PY_BOGI176_LC_Corr_Searching']

PY_BOGI256_DC_Prob_Searching = libatsbb256['PY_BOGI256_DC_Prob_Searching']
PY_BOGI256_LC_Corr_Searching = libatsbb256['PY_BOGI256_LC_Corr_Searching']


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

    def DC_Prob_Searching(self):

        PY_BOGI16_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self):

        PY_BOGI16_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI32_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self):

        PY_BOGI32_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self):

        PY_BOGI32_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI64_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self):

        PY_BOGI64_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self):

        PY_BOGI64_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI128_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self):

        PY_BOGI128_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self):

        PY_BOGI128_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI176_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self):

        PY_BOGI176_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self):

        PY_BOGI176_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))

class BOGI256_Cipher(BOGI16_Cipher):
    def DC_Prob_Searching(self):

        PY_BOGI256_DC_Prob_Searching(
            self.ct_prob_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )

        self.DC_Prob_Results = []
        for i in range(self.num_round):
            self.DC_Prob_Results.append(float(self.ct_prob_rst[i]))

    def LC_Corr_Searching(self):

        PY_BOGI256_LC_Corr_Searching(
            self.ct_corr_rst,
            self.ct_num_round,
            self.ct_sbox_idx,
            self.ct_perm_idx
            )
        
        self.LC_Corr_Results = []
        for i in range(self.num_round):
            self.LC_Corr_Results.append(float(self.ct_corr_rst[i].magnitude))


if __name__ == "__main__":
    import numpy as np

    analysis_round = 5
    bogi_sbox_idx  = 94   #This must be 0 ~ 1727, GIFT_SBOX_IDX = 94
    bogi_pbox_idx  = 344  #This must be 0 ~ 575,  GIFT_PBOX_IDX = 344

    bb = BOGI16_Cipher(analysis_round, bogi_sbox_idx, bogi_pbox_idx)
    bb.DC_Prob_Searching()
    print(np.round(bb.DC_Prob_Results, 1))
    bb.LC_Corr_Searching()
    print(np.round(bb.LC_Corr_Results, 1))

    bb = BOGI32_Cipher(analysis_round, bogi_sbox_idx, bogi_pbox_idx)
    bb.DC_Prob_Searching()
    print(np.round(bb.DC_Prob_Results, 1))
    bb.LC_Corr_Searching()
    print(np.round(bb.LC_Corr_Results, 1))

    bb = BOGI64_Cipher(analysis_round, bogi_sbox_idx, bogi_pbox_idx)
    bb.DC_Prob_Searching()
    print(np.round(bb.DC_Prob_Results, 1))
    bb.LC_Corr_Searching()
    print(np.round(bb.LC_Corr_Results, 1))

    bb = BOGI128_Cipher(analysis_round, bogi_sbox_idx, bogi_pbox_idx)
    bb.DC_Prob_Searching()
    print(np.round(bb.DC_Prob_Results, 1))
    bb.LC_Corr_Searching()
    print(np.round(bb.LC_Corr_Results, 1))

    bb = BOGI176_Cipher(analysis_round, bogi_sbox_idx, bogi_pbox_idx)
    bb.DC_Prob_Searching()
    print(np.round(bb.DC_Prob_Results, 1))
    bb.LC_Corr_Searching()
    print(np.round(bb.LC_Corr_Results, 1))

    bb = BOGI256_Cipher(analysis_round, bogi_sbox_idx, bogi_pbox_idx)
    bb.DC_Prob_Searching()
    print(np.round(bb.DC_Prob_Results, 1))
    bb.LC_Corr_Searching()
    print(np.round(bb.LC_Corr_Results, 1))