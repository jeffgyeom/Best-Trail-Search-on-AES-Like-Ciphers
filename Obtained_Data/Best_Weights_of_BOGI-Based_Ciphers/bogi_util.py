import numpy as np

def LS_TO_P16(LS):
    P16 = [0]*16
    #MSB, ENT_SOURCE
    for r_idx in range(4):
        for c_idx in range(4):
            input_sbox_idx = LS[r_idx][c_idx]
            input_bit_idx  = input_sbox_idx * 4 + (3 - r_idx)
            output_sbox_idx = c_idx
            output_bit_idx = output_sbox_idx * 4 + (3 - r_idx)
            P16[output_bit_idx] = input_bit_idx
    return tuple(P16)

def P16_TO_PN(_16_PERM, N):
    if (N%16) != 0:
        raise NameError("N must be a multiple of 16")
    num_sub_perm = N//16
    sub_perm = np.array(_16_PERM)
    rst_perm = np.array([0]*N)
    for sub_perm_idx in range(num_sub_perm):
        for word_idx_of_the_sub_perm in range(4):
            _4bits_ = sub_perm[word_idx_of_the_sub_perm * 4 : word_idx_of_the_sub_perm * 4  + 4]
            base_idx = sub_perm_idx * 4
            base_idx += (num_sub_perm*4) * word_idx_of_the_sub_perm
            rst_perm[base_idx : base_idx + 4] = _4bits_ + 16*sub_perm_idx
    return tuple(rst_perm)

def P16_TO_P32(P16):
    return P16_TO_PN(P16, 32)
def P16_TO_P64(P16):
    return P16_TO_PN(P16, 64)
def P16_TO_P128(P16):
    return P16_TO_PN(P16, 128)
def P16_TO_P176(P16):
    return P16_TO_PN(P16, 176)
def P16_TO_P256(P16):
    return P16_TO_PN(P16, 256)

#MSB SOURCE : p2 o p1
def composition_nbit(p1, p2, N):
    lut_out = [0]*N
    for inbit_idx in range(N):
        lut_out[p2.index(p1.index(inbit_idx))] = inbit_idx
    return tuple(lut_out)