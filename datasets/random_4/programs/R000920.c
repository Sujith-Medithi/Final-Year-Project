/*
 * Benchmark Program: R000920
 * Family: mixed_control_data
 * Generator Seed: 492013
 * High Inputs: 21 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000920_2013_0 {
    short norm_sq;
    int coord_x;
    int heading;
    int buffer[3];
};

struct CipherContext_R000920_2013_1 {
    short flags;
    unsigned char iv;
    int nonce;
    short counter;
    unsigned char round_key;
    short tag;
    int buffer[3];
};

struct StreamBuffer_R000920_2013_2 {
    short checksum;
    int capacity;
    short state;
    int head;
    int buffer[3];
};

union RegisterBank_R000920_2013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000920_2013_0(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_15) & 63;
    acc ^= aux;
    int checksum_18 = (aux + st.buffer[1]) & 3;
    switch (checksum_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int vector_26 = (aux + st.buffer[1]) & 3;
    switch (vector_26) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_2(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_42 = (aux + st.buffer[1]) & 3;
    switch (weight_42) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_52 = local_arr[aux % 3];
    acc = (acc + residue_52 * 2) & 127;
    int cursor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_75) & 63;
    acc ^= aux;
    int index_reg_67 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_67 = (index_reg_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_3(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_68) & 63;
    acc ^= aux;
    int scale_72 = 0;
    for (int k = 0; k < 3; k++) {
        scale_72 = (scale_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_72) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_4(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int mask_30 = local_arr[aux % 3];
    acc = (acc + mask_30 * 2) & 127;
    int quotient_78 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_78 = (quotient_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_78) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_5(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int checksum_83 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_83 > 31) {
        acc = (acc + checksum_83 * 2 + 5) & 127;
        aux ^= (checksum_83 & 15);
    } else {
        acc = (acc - checksum_83 + 11) & 127;
        aux += 3;
    }
    int scale_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_88 = (aux + st.buffer[1]) & 3;
    switch (vector_88) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_20 = (st.buffer[0] * 3 + aux) & 63;
    if (window_20 > 39) {
        acc = (acc + window_20 * 2 + 5) & 127;
        aux ^= (window_20 & 15);
    } else {
        acc = (acc - window_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int weight_64 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_64 > 16) {
        acc = (acc + weight_64 * 2 + 5) & 127;
        aux ^= (weight_64 & 15);
    } else {
        acc = (acc - weight_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_21 = local_arr[aux % 3];
    acc = (acc + vector_21 * 2) & 127;
    int scale_89 = (aux + st.buffer[1]) & 3;
    switch (scale_89) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int quotient_37 = local_arr[aux % 3];
    acc = (acc + quotient_37 * 2) & 127;
    int anchor_87 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_87 > 47) {
        acc = (acc + anchor_87 * 2 + 5) & 127;
        aux ^= (anchor_87 & 15);
    } else {
        acc = (acc - anchor_87 + 11) & 127;
        aux += 3;
    }
    int delta_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_79) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_9(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int stride_89 = local_arr[aux % 3];
    acc = (acc + stride_89 * 2) & 127;
    int weight_25 = 0;
    for (int k = 0; k < 3; k++) {
        weight_25 = (weight_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_25) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_29 = (st.buffer[0] * 3 + aux) & 63;
    if (window_29 > 22) {
        acc = (acc + window_29 * 2 + 5) & 127;
        aux ^= (window_29 & 15);
    } else {
        acc = (acc - window_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int weight_12 = 0;
    for (int k = 0; k < 3; k++) {
        weight_12 = (weight_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_12) & 127;
    }
    int quantum_55 = (aux + st.buffer[1]) & 3;
    switch (quantum_55) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_95 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_95 > 38) {
        acc = (acc + phase_95 * 2 + 5) & 127;
        aux ^= (phase_95 & 15);
    } else {
        acc = (acc - phase_95 + 11) & 127;
        aux += 3;
    }
    int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000920_2013_11(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_23 = (aux + st.buffer[1]) & 3;
    switch (offset_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_24) & 63;
    acc ^= aux;
    int index_reg_98 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_98 > 36) {
        acc = (acc + index_reg_98 * 2 + 5) & 127;
        aux ^= (index_reg_98 & 15);
    } else {
        acc = (acc - index_reg_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_25 = (aux + st.buffer[1]) & 3;
    switch (index_reg_25) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_25 = 0;
    for (int k = 0; k < 3; k++) {
        segment_25 = (segment_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_25) & 127;
    }
    int quotient_78 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_78 > 38) {
        acc = (acc + quotient_78 * 2 + 5) & 127;
        aux ^= (quotient_78 & 15);
    } else {
        acc = (acc - quotient_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_70 = local_arr[aux % 3];
    acc = (acc + tracker_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_14(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_81 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_81 > 27) {
        acc = (acc + phase_81 * 2 + 5) & 127;
        aux ^= (phase_81 & 15);
    } else {
        acc = (acc - phase_81 + 11) & 127;
        aux += 3;
    }
    int checksum_29 = (aux + st.buffer[1]) & 3;
    switch (checksum_29) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int sample_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_12 = local_arr[aux % 3];
    acc = (acc + residue_12 * 2) & 127;
    int coefficient_42 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_42 = (coefficient_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_16(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int parity_98 = 0;
    for (int k = 0; k < 3; k++) {
        parity_98 = (parity_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_98) & 127;
    }
    int quantum_23 = (aux + st.buffer[1]) & 3;
    switch (quantum_23) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_13 = local_arr[aux % 3];
    acc = (acc + window_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_77 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_77 > 28) {
        acc = (acc + metric_77 * 2 + 5) & 127;
        aux ^= (metric_77 & 15);
    } else {
        acc = (acc - metric_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_54 = local_arr[aux % 3];
    acc = (acc + sample_54 * 2) & 127;
    int residue_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000920_2013_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_33) & 63;
    acc ^= aux;
    int checksum_12 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_12 > 25) {
        acc = (acc + checksum_12 * 2 + 5) & 127;
        aux ^= (checksum_12 & 15);
    } else {
        acc = (acc - checksum_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_55 = local_arr[aux % 3];
    acc = (acc + index_reg_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_38) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000920_2013_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_10) & 63;
    acc ^= aux;
    int weight_43 = 0;
    for (int k = 0; k < 2; k++) {
        weight_43 = (weight_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_43) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000920_2013_21(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int window_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_98) & 63;
    acc ^= aux;
    int factor_84 = (aux + st.buffer[1]) & 3;
    switch (factor_84) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_14 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_14 > 42) {
        acc = (acc + tracker_14 * 2 + 5) & 127;
        aux ^= (tracker_14 & 15);
    } else {
        acc = (acc - tracker_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000920_0;
    int sec_r000920_1;
    int sec_r000920_2;
    int sec_r000920_3;
    int sec_r000920_4;
    int sec_r000920_5;
    int sec_r000920_6;
    int sec_r000920_7;
    int sec_r000920_8;
    int sec_r000920_9;
    int sec_r000920_10;
    int sec_r000920_11;
    int sec_r000920_12;
    int sec_r000920_13;
    int sec_r000920_14;
    int sec_r000920_15;
    int sec_r000920_16;
    int sec_r000920_17;
    int sec_r000920_18;
    int sec_r000920_19;
    int sec_r000920_20;
    int pub_r000920_0;
    int pub_r000920_1;
    int pub_r000920_2;
    int pub_r000920_3;
    int pub_r000920_4;
    int pub_r000920_5;
    int pub_r000920_6;
    int pub_r000920_7;
    int pub_r000920_8;
    int pub_r000920_9;
    int pub_r000920_10;
    int pub_r000920_11;
    int pub_r000920_12;
    int pub_r000920_13;
    int pub_r000920_14;
    int pub_r000920_15;
    int pub_r000920_16;
    int pub_r000920_17;
    int pub_r000920_18;
    int pub_r000920_19;
    int pub_r000920_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000920_0 >= -100 && pub_r000920_0 <= 100);
    __CPROVER_assume(pub_r000920_1 >= -100 && pub_r000920_1 <= 100);
    __CPROVER_assume(pub_r000920_2 >= -100 && pub_r000920_2 <= 100);
    __CPROVER_assume(pub_r000920_3 >= -100 && pub_r000920_3 <= 100);
    __CPROVER_assume(pub_r000920_4 >= -100 && pub_r000920_4 <= 100);
    __CPROVER_assume(pub_r000920_5 >= -100 && pub_r000920_5 <= 100);
    __CPROVER_assume(pub_r000920_6 >= -100 && pub_r000920_6 <= 100);
    __CPROVER_assume(pub_r000920_7 >= -100 && pub_r000920_7 <= 100);
    __CPROVER_assume(pub_r000920_8 >= -100 && pub_r000920_8 <= 100);
    __CPROVER_assume(pub_r000920_9 >= -100 && pub_r000920_9 <= 100);
    __CPROVER_assume(pub_r000920_10 >= -100 && pub_r000920_10 <= 100);
    __CPROVER_assume(pub_r000920_11 >= -100 && pub_r000920_11 <= 100);
    __CPROVER_assume(pub_r000920_12 >= -100 && pub_r000920_12 <= 100);
    __CPROVER_assume(pub_r000920_13 >= -100 && pub_r000920_13 <= 100);
    __CPROVER_assume(pub_r000920_14 >= -100 && pub_r000920_14 <= 100);
    __CPROVER_assume(pub_r000920_15 >= -100 && pub_r000920_15 <= 100);
    __CPROVER_assume(pub_r000920_16 >= -100 && pub_r000920_16 <= 100);
    __CPROVER_assume(pub_r000920_17 >= -100 && pub_r000920_17 <= 100);
    __CPROVER_assume(pub_r000920_18 >= -100 && pub_r000920_18 <= 100);
    __CPROVER_assume(pub_r000920_19 >= -100 && pub_r000920_19 <= 100);
    __CPROVER_assume(pub_r000920_20 >= -100 && pub_r000920_20 <= 100);
    __CPROVER_assume(sec_r000920_0 >= 0 && sec_r000920_0 <= 255);
    __CPROVER_assume(sec_r000920_1 >= 0 && sec_r000920_1 <= 255);
    __CPROVER_assume(sec_r000920_2 >= 0 && sec_r000920_2 <= 255);
    __CPROVER_assume(sec_r000920_3 >= 0 && sec_r000920_3 <= 255);
    __CPROVER_assume(sec_r000920_4 >= 0 && sec_r000920_4 <= 255);
    __CPROVER_assume(sec_r000920_5 >= 0 && sec_r000920_5 <= 255);
    __CPROVER_assume(sec_r000920_6 >= 0 && sec_r000920_6 <= 255);
    __CPROVER_assume(sec_r000920_7 >= 0 && sec_r000920_7 <= 255);
    __CPROVER_assume(sec_r000920_8 >= 0 && sec_r000920_8 <= 255);
    __CPROVER_assume(sec_r000920_9 >= 0 && sec_r000920_9 <= 255);
    __CPROVER_assume(sec_r000920_10 >= 0 && sec_r000920_10 <= 255);
    __CPROVER_assume(sec_r000920_11 >= 0 && sec_r000920_11 <= 255);
    __CPROVER_assume(sec_r000920_12 >= 0 && sec_r000920_12 <= 255);
    __CPROVER_assume(sec_r000920_13 >= 0 && sec_r000920_13 <= 255);
    __CPROVER_assume(sec_r000920_14 >= 0 && sec_r000920_14 <= 255);
    __CPROVER_assume(sec_r000920_15 >= 0 && sec_r000920_15 <= 255);
    __CPROVER_assume(sec_r000920_16 >= 0 && sec_r000920_16 <= 255);
    __CPROVER_assume(sec_r000920_17 >= 0 && sec_r000920_17 <= 255);
    __CPROVER_assume(sec_r000920_18 >= 0 && sec_r000920_18 <= 255);
    __CPROVER_assume(sec_r000920_19 >= 0 && sec_r000920_19 <= 255);
    __CPROVER_assume(sec_r000920_20 >= 0 && sec_r000920_20 <= 255);

    struct Vector3D_R000920_2013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000920_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000920_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000920_0 + 7) & 15;
    struct CipherContext_R000920_2013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000920_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000920_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000920_0 + 9) & 15;
    struct StreamBuffer_R000920_2013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000920_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000920_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000920_0 + 11) & 15;

    union RegisterBank_R000920_2013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 25) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 40) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 34) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 49) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 13) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 28) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 17) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 32) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 16) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 31) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 40) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 55) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 15) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 30) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 35) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 50) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 33) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 48) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 12) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 27) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 14) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 29) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 21) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 36) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 36) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 51) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 24) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 39) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 30) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 45) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 28) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 43) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 82 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 30) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 45) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_2.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_90 = (stage_v_90 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_92 = (stage_v_92 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_93 = (stage_v_93 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_1.buffer[0] ^ 97) & 3;
    switch (stage_v_94) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_97 = (stage_v_97 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[0] ^ 103) & 3;
    switch (stage_v_100) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 103 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 104) & 15;
    int stage_v_103 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= stage_v_103;

    /* Execution Pipeline Stage 104 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (out_sink > 100) ? (chk_sum & 31) : (112 & 31);
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= (stage_v_107 << 1) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[2] * 2 + 337) & 63;
    if (stage_v_110 > 16) {
        out_sink = (out_sink + stage_v_110 - 5) & 255;
        if (stage_v_110 > 31) {
            chk_sum ^= (stage_v_110 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_110 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 117) & 15;
    int stage_v_116 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= stage_v_116;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_0.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 118 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[0] ^ 125) & 3;
    switch (stage_v_122) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 125) & 15;
    int stage_v_124 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= stage_v_124;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[2] * 2 + 391) & 63;
    if (stage_v_128 > 31) {
        out_sink = (out_sink + stage_v_128 - 5) & 255;
        if (stage_v_128 > 46) {
            chk_sum ^= (stage_v_128 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_128 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 134) & 15;
    int stage_v_133 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= stage_v_133;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (out_sink > 100) ? (chk_sum & 31) : (140 & 31);
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= (stage_v_135 << 1) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] * 2 + 439) & 63;
    if (stage_v_144 > 32) {
        out_sink = (out_sink + stage_v_144 - 5) & 255;
        if (stage_v_144 > 47) {
            chk_sum ^= (stage_v_144 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_144 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_145 = (stage_v_145 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = table[0];
    table[0] = (table[1] + 297) & 63;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = table[1];
    table[1] = (table[2] + 299) & 63;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_152 = (stage_v_152 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 28) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 43) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 155) & 15;
    int stage_v_154 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= stage_v_154;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[0] ^ 160) & 3;
    switch (stage_v_157) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (out_sink > 100) ? (chk_sum & 31) : (163 & 31);
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= (stage_v_158 << 1) & 127;

    /* Execution Pipeline Stage 159 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 162 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = table[3];
    table[3] = (table[0] + 327) & 63;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_0.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 19) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 34) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] ^ 171) & 3;
    switch (stage_v_168) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[0] ^ 172) & 3;
    switch (stage_v_169) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_2.buffer[0] ^ 173) & 3;
    switch (stage_v_170) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (out_sink > 100) ? (chk_sum & 31) : (177 & 31);
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= (stage_v_172 << 1) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_173 = (stage_v_173 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_174 = (stage_v_174 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_175 = (stage_v_175 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_175) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_2.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 12) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 27) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_181 = (stage_v_181 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 183) & 15;
    int stage_v_182 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= stage_v_182;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_1.buffer[1] * 2 + 559) & 63;
    if (stage_v_184 > 25) {
        out_sink = (out_sink + stage_v_184 - 5) & 255;
        if (stage_v_184 > 40) {
            chk_sum ^= (stage_v_184 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_184 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 187) & 15;
    int stage_v_186 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_186) & 255;
    chk_sum ^= stage_v_186;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (st_var_1.buffer[1] * 2 + 568) & 63;
    if (stage_v_187 > 12) {
        out_sink = (out_sink + stage_v_187 - 5) & 255;
        if (stage_v_187 > 27) {
            chk_sum ^= (stage_v_187 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_187 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (st_var_0.buffer[0] * 2 + 574) & 63;
    if (stage_v_189 > 14) {
        out_sink = (out_sink + stage_v_189 - 5) & 255;
        if (stage_v_189 > 29) {
            chk_sum ^= (stage_v_189 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_189 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_192 = (stage_v_192 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_192) & 127;
    }
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_193 = (stage_v_193 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_193) & 127;
    }
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_0.buffer[0] ^ 198) & 3;
    switch (stage_v_195) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 196 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 197) & 15;
    int stage_v_196 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    chk_sum ^= stage_v_196;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_0.buffer[0] ^ 201) & 3;
    switch (stage_v_198) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = table[3];
    table[3] = (table[0] + 399) & 63;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (out_sink > 100) ? (chk_sum & 31) : (205 & 31);
    out_sink = (out_sink + stage_v_200) & 255;
    chk_sum ^= (stage_v_200 << 1) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_201 = (stage_v_201 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_201) & 127;
    }
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 203) & 15;
    int stage_v_202 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    chk_sum ^= stage_v_202;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (out_sink > 100) ? (chk_sum & 31) : (208 & 31);
    out_sink = (out_sink + stage_v_203) & 255;
    chk_sum ^= (stage_v_203 << 1) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (out_sink > 100) ? (chk_sum & 31) : (209 & 31);
    out_sink = (out_sink + stage_v_204) & 255;
    chk_sum ^= (stage_v_204 << 1) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (out_sink > 100) ? (chk_sum & 31) : (210 & 31);
    out_sink = (out_sink + stage_v_205) & 255;
    chk_sum ^= (stage_v_205 << 1) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (st_var_2.buffer[0] ^ 209) & 3;
    switch (stage_v_206) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_207 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (st_var_1.buffer[0] ^ 211) & 3;
    switch (stage_v_208) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (out_sink > 100) ? (chk_sum & 31) : (214 & 31);
    out_sink = (out_sink + stage_v_209) & 255;
    chk_sum ^= (stage_v_209 << 1) & 127;

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000920_2 ^ 0x55) & 63;
    if (m_var > 29) {
        out_sink += (m_var * 2 + pub_r000920_3) & 127;
    } else {
        out_sink -= (m_var + 11) & 31;
    }
    out_sink ^= (sec_r000920_9 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
