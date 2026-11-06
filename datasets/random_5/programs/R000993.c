/*
 * Benchmark Program: R000993
 * Security Family: multi_step_explicit
 * Generator Seed: 599313
 * High Inputs: 17 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000993_9313_0 {
    int scale;
    short density;
    int determinant;
    int trace;
    unsigned char stride;
    int buffer[3];
};

struct CipherContext_R000993_9313_1 {
    int iv;
    unsigned char counter;
    int flags;
    int tag;
    unsigned char round_key;
    int nonce;
    int buffer[3];
};

union RegisterBank_R000993_9313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000993_9313_0(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int stride_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_40) & 63;
    acc ^= aux;
    int accumulator_98 = (aux + st.buffer[1]) & 3;
    switch (accumulator_98) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int cursor_78 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_78 > 28) {
        acc = (acc + cursor_78 * 2 + 5) & 127;
        aux ^= (cursor_78 & 15);
    } else {
        acc = (acc - cursor_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_43) & 63;
    acc ^= aux;
    int coefficient_83 = (aux + st.buffer[1]) & 3;
    switch (coefficient_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_2(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int scale_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_16) & 63;
    acc ^= aux;
    int anchor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_79 > 23) {
        acc = (acc + anchor_79 * 2 + 5) & 127;
        aux ^= (anchor_79 & 15);
    } else {
        acc = (acc - anchor_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_3(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_89 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_89 > 21) {
        acc = (acc + phase_89 * 2 + 5) & 127;
        aux ^= (phase_89 & 15);
    } else {
        acc = (acc - phase_89 + 11) & 127;
        aux += 3;
    }
    int bound_89 = (aux + st.buffer[1]) & 3;
    switch (bound_89) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000993_9313_4(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int mask_21 = local_arr[aux % 3];
    acc = (acc + mask_21 * 2) & 127;
    int window_89 = (st.buffer[0] * 3 + aux) & 63;
    if (window_89 > 42) {
        acc = (acc + window_89 * 2 + 5) & 127;
        aux ^= (window_89 & 15);
    } else {
        acc = (acc - window_89 + 11) & 127;
        aux += 3;
    }
    int mask_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_16) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int bound_94 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_94 > 35) {
        acc = (acc + bound_94 * 2 + 5) & 127;
        aux ^= (bound_94 & 15);
    } else {
        acc = (acc - bound_94 + 11) & 127;
        aux += 3;
    }
    int vector_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_71) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_6(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_65 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_65 > 32) {
        acc = (acc + parity_65 * 2 + 5) & 127;
        aux ^= (parity_65 & 15);
    } else {
        acc = (acc - parity_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_7(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int residue_82 = (aux + st.buffer[1]) & 3;
    switch (residue_82) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_15) & 63;
    acc ^= aux;
    int tracker_66 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_66 > 18) {
        acc = (acc + tracker_66 * 2 + 5) & 127;
        aux ^= (tracker_66 & 15);
    } else {
        acc = (acc - tracker_66 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_43 = local_arr[aux % 3];
    acc = (acc + checksum_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_56 = local_arr[aux % 3];
    acc = (acc + sample_56 * 2) & 127;
    int tally_80 = (aux + st.buffer[1]) & 3;
    switch (tally_80) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_70 = (aux + st.buffer[1]) & 3;
    switch (vector_70) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_62 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_62 > 33) {
        acc = (acc + mask_62 * 2 + 5) & 127;
        aux ^= (mask_62 & 15);
    } else {
        acc = (acc - mask_62 + 11) & 127;
        aux += 3;
    }
    int delta_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_96 = local_arr[aux % 3];
    acc = (acc + coefficient_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int pivot_37 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_37 > 36) {
        acc = (acc + pivot_37 * 2 + 5) & 127;
        aux ^= (pivot_37 & 15);
    } else {
        acc = (acc - pivot_37 + 11) & 127;
        aux += 3;
    }
    int margin_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000993_9313_11(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int delta_63 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_63 > 17) {
        acc = (acc + delta_63 * 2 + 5) & 127;
        aux ^= (delta_63 & 15);
    } else {
        acc = (acc - delta_63 + 11) & 127;
        aux += 3;
    }
    int weight_28 = (aux + st.buffer[1]) & 3;
    switch (weight_28) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_12(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_39 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_39 > 26) {
        acc = (acc + weight_39 * 2 + 5) & 127;
        aux ^= (weight_39 & 15);
    } else {
        acc = (acc - weight_39 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_62 = (aux + st.buffer[1]) & 3;
    switch (scale_62) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int coefficient_40 = local_arr[aux % 3];
    acc = (acc + coefficient_40 * 2) & 127;
    int delta_40 = (aux + st.buffer[1]) & 3;
    switch (delta_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_32 = local_arr[aux % 3];
    acc = (acc + threshold_32 * 2) & 127;
    int margin_98 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_98 > 31) {
        acc = (acc + margin_98 * 2 + 5) & 127;
        aux ^= (margin_98 & 15);
    } else {
        acc = (acc - margin_98 + 11) & 127;
        aux += 3;
    }
    int residue_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000993_9313_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int delta_41 = local_arr[aux % 3];
    acc = (acc + delta_41 * 2) & 127;
    int margin_18 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_18 > 13) {
        acc = (acc + margin_18 * 2 + 5) & 127;
        aux ^= (margin_18 & 15);
    } else {
        acc = (acc - margin_18 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_33 = (aux + st.buffer[1]) & 3;
    switch (tracker_33) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int damping_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_41) & 63;
    acc ^= aux;
    int anchor_69 = (aux + st.buffer[1]) & 3;
    switch (anchor_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_12 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_12 > 27) {
        acc = (acc + vector_12 * 2 + 5) & 127;
        aux ^= (vector_12 & 15);
    } else {
        acc = (acc - vector_12 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int offset_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_83) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_18(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int offset_95 = (aux + st.buffer[1]) & 3;
    switch (offset_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_82 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_82 > 16) {
        acc = (acc + checksum_82 * 2 + 5) & 127;
        aux ^= (checksum_82 & 15);
    } else {
        acc = (acc - checksum_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int scale_20 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_20 > 10) {
        acc = (acc + scale_20 * 2 + 5) & 127;
        aux ^= (scale_20 & 15);
    } else {
        acc = (acc - scale_20 + 11) & 127;
        aux += 3;
    }
    int weight_41 = (aux + st.buffer[1]) & 3;
    switch (weight_41) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int residue_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_56) & 63;
    acc ^= aux;
    int metric_80 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_80 > 24) {
        acc = (acc + metric_80 * 2 + 5) & 127;
        aux ^= (metric_80 & 15);
    } else {
        acc = (acc - metric_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int vector_43 = local_arr[aux % 3];
    acc = (acc + vector_43 * 2) & 127;
    int sample_29 = (aux + st.buffer[1]) & 3;
    switch (sample_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_48) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int sample_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_65) & 63;
    acc ^= aux;
    int segment_11 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_11 > 50) {
        acc = (acc + segment_11 * 2 + 5) & 127;
        aux ^= (segment_11 & 15);
    } else {
        acc = (acc - segment_11 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_21 = (aux + st.buffer[1]) & 3;
    switch (window_21) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000993_0;
    int sec_r000993_1;
    int sec_r000993_2;
    int sec_r000993_3;
    int sec_r000993_4;
    int sec_r000993_5;
    int sec_r000993_6;
    int sec_r000993_7;
    int sec_r000993_8;
    int sec_r000993_9;
    int sec_r000993_10;
    int sec_r000993_11;
    int sec_r000993_12;
    int sec_r000993_13;
    int sec_r000993_14;
    int sec_r000993_15;
    int sec_r000993_16;
    int pub_r000993_0;
    int pub_r000993_1;
    int pub_r000993_2;
    int pub_r000993_3;
    int pub_r000993_4;
    int pub_r000993_5;
    int pub_r000993_6;
    int pub_r000993_7;
    int pub_r000993_8;
    int pub_r000993_9;
    int pub_r000993_10;
    int pub_r000993_11;
    int pub_r000993_12;
    int pub_r000993_13;
    int pub_r000993_14;
    int pub_r000993_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000993_0 >= -100 && pub_r000993_0 <= 100);
    __CPROVER_assume(pub_r000993_1 >= -100 && pub_r000993_1 <= 100);
    __CPROVER_assume(pub_r000993_2 >= -100 && pub_r000993_2 <= 100);
    __CPROVER_assume(pub_r000993_3 >= -100 && pub_r000993_3 <= 100);
    __CPROVER_assume(pub_r000993_4 >= -100 && pub_r000993_4 <= 100);
    __CPROVER_assume(pub_r000993_5 >= -100 && pub_r000993_5 <= 100);
    __CPROVER_assume(pub_r000993_6 >= -100 && pub_r000993_6 <= 100);
    __CPROVER_assume(pub_r000993_7 >= -100 && pub_r000993_7 <= 100);
    __CPROVER_assume(pub_r000993_8 >= -100 && pub_r000993_8 <= 100);
    __CPROVER_assume(pub_r000993_9 >= -100 && pub_r000993_9 <= 100);
    __CPROVER_assume(pub_r000993_10 >= -100 && pub_r000993_10 <= 100);
    __CPROVER_assume(pub_r000993_11 >= -100 && pub_r000993_11 <= 100);
    __CPROVER_assume(pub_r000993_12 >= -100 && pub_r000993_12 <= 100);
    __CPROVER_assume(pub_r000993_13 >= -100 && pub_r000993_13 <= 100);
    __CPROVER_assume(pub_r000993_14 >= -100 && pub_r000993_14 <= 100);
    __CPROVER_assume(pub_r000993_15 >= -100 && pub_r000993_15 <= 100);
    __CPROVER_assume(sec_r000993_0 >= 0 && sec_r000993_0 <= 255);
    __CPROVER_assume(sec_r000993_1 >= 0 && sec_r000993_1 <= 255);
    __CPROVER_assume(sec_r000993_2 >= 0 && sec_r000993_2 <= 255);
    __CPROVER_assume(sec_r000993_3 >= 0 && sec_r000993_3 <= 255);
    __CPROVER_assume(sec_r000993_4 >= 0 && sec_r000993_4 <= 255);
    __CPROVER_assume(sec_r000993_5 >= 0 && sec_r000993_5 <= 255);
    __CPROVER_assume(sec_r000993_6 >= 0 && sec_r000993_6 <= 255);
    __CPROVER_assume(sec_r000993_7 >= 0 && sec_r000993_7 <= 255);
    __CPROVER_assume(sec_r000993_8 >= 0 && sec_r000993_8 <= 255);
    __CPROVER_assume(sec_r000993_9 >= 0 && sec_r000993_9 <= 255);
    __CPROVER_assume(sec_r000993_10 >= 0 && sec_r000993_10 <= 255);
    __CPROVER_assume(sec_r000993_11 >= 0 && sec_r000993_11 <= 255);
    __CPROVER_assume(sec_r000993_12 >= 0 && sec_r000993_12 <= 255);
    __CPROVER_assume(sec_r000993_13 >= 0 && sec_r000993_13 <= 255);
    __CPROVER_assume(sec_r000993_14 >= 0 && sec_r000993_14 <= 255);
    __CPROVER_assume(sec_r000993_15 >= 0 && sec_r000993_15 <= 255);
    __CPROVER_assume(sec_r000993_16 >= 0 && sec_r000993_16 <= 255);

    struct MatrixBlock_R000993_9313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000993_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000993_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000993_0 + 7) & 15;
    struct CipherContext_R000993_9313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000993_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000993_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000993_0 + 9) & 15;

    union RegisterBank_R000993_9313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 34) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 49) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 28) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 43) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 36) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 51) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 22) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 37) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 11) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 26) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 28) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 43) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 12) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 27) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 36) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 51) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 36) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 51) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 27) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 42) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int sub_step_53 = (sec_r000993_5 + pub_r000993_2 + 28) & 127;
    int stage_v_53 = (sub_step_53 * 2 + pub_r000993_0) & 127;
    st_var_1.buffer[2] = (stage_v_53 & 15);
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int sub_step_54 = (sec_r000993_3 + pub_r000993_3 + 6) & 127;
    int stage_v_54 = (sub_step_54 * 2 + pub_r000993_3) & 127;
    st_var_0.buffer[0] = (stage_v_54 & 15);
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int sub_step_55 = (stage_v_53 + pub_r000993_12 + 33) & 127;
    int stage_v_55 = (sub_step_55 * 2 + pub_r000993_1) & 127;
    st_var_1.buffer[1] = (stage_v_55 & 15);
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int sub_step_56 = (stage_v_53 + pub_r000993_1 + 30) & 127;
    int stage_v_56 = (sub_step_56 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[2] = (stage_v_56 & 15);
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int sub_step_57 = (sec_r000993_9 + pub_r000993_8 + 5) & 127;
    int stage_v_57 = (sub_step_57 * 2 + pub_r000993_7) & 127;
    st_var_1.buffer[0] = (stage_v_57 & 15);
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int sub_step_58 = (stage_v_57 + pub_r000993_4 + 8) & 127;
    int stage_v_58 = (sub_step_58 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[1] = (stage_v_58 & 15);
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int sub_step_59 = (sec_r000993_5 + pub_r000993_8 + 7) & 127;
    int stage_v_59 = (sub_step_59 * 2 + pub_r000993_4) & 127;
    st_var_1.buffer[2] = (stage_v_59 & 15);
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int sub_step_60 = (sec_r000993_14 + pub_r000993_10 + 19) & 127;
    int stage_v_60 = (sub_step_60 * 2 + pub_r000993_12) & 127;
    st_var_0.buffer[0] = (stage_v_60 & 15);
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int sub_step_61 = (sec_r000993_7 + pub_r000993_4 + 13) & 127;
    int stage_v_61 = (sub_step_61 * 2 + pub_r000993_9) & 127;
    st_var_1.buffer[1] = (stage_v_61 & 15);
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int sub_step_62 = (sub_step_53 + pub_r000993_14 + 32) & 127;
    int stage_v_62 = (sub_step_62 * 2 + pub_r000993_14) & 127;
    st_var_0.buffer[2] = (stage_v_62 & 15);
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int sub_step_63 = (stage_v_61 + pub_r000993_8 + 6) & 127;
    int stage_v_63 = (sub_step_63 * 2 + pub_r000993_3) & 127;
    st_var_1.buffer[0] = (stage_v_63 & 15);
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int sub_step_64 = (sub_step_55 + pub_r000993_0 + 34) & 127;
    int stage_v_64 = (sub_step_64 * 2 + pub_r000993_5) & 127;
    st_var_0.buffer[1] = (stage_v_64 & 15);
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int sub_step_65 = (sub_step_64 + pub_r000993_3 + 5) & 127;
    int stage_v_65 = (sub_step_65 * 2 + pub_r000993_8) & 127;
    st_var_1.buffer[2] = (stage_v_65 & 15);
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int sub_step_66 = (sec_r000993_7 + pub_r000993_10 + 24) & 127;
    int stage_v_66 = (sub_step_66 * 2 + pub_r000993_10) & 127;
    st_var_0.buffer[0] = (stage_v_66 & 15);
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int sub_step_67 = (sec_r000993_12 + pub_r000993_14 + 26) & 127;
    int stage_v_67 = (sub_step_67 * 2 + pub_r000993_8) & 127;
    st_var_1.buffer[1] = (stage_v_67 & 15);
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int sub_step_68 = (sec_r000993_7 + pub_r000993_10 + 5) & 127;
    int stage_v_68 = (sub_step_68 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[2] = (stage_v_68 & 15);
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int sub_step_69 = (stage_v_64 + pub_r000993_1 + 34) & 127;
    int stage_v_69 = (sub_step_69 * 2 + pub_r000993_9) & 127;
    st_var_1.buffer[0] = (stage_v_69 & 15);
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int sub_step_70 = (sub_step_62 + pub_r000993_7 + 9) & 127;
    int stage_v_70 = (sub_step_70 * 2 + pub_r000993_5) & 127;
    st_var_0.buffer[1] = (stage_v_70 & 15);
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int sub_step_71 = (sec_r000993_7 + pub_r000993_13 + 15) & 127;
    int stage_v_71 = (sub_step_71 * 2 + pub_r000993_3) & 127;
    st_var_1.buffer[2] = (stage_v_71 & 15);
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int sub_step_72 = (sec_r000993_15 + pub_r000993_5 + 8) & 127;
    int stage_v_72 = (sub_step_72 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[0] = (stage_v_72 & 15);
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int sub_step_73 = (stage_v_62 + pub_r000993_6 + 19) & 127;
    int stage_v_73 = (sub_step_73 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[1] = (stage_v_73 & 15);
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int sub_step_74 = (stage_v_67 + pub_r000993_9 + 18) & 127;
    int stage_v_74 = (sub_step_74 * 2 + pub_r000993_10) & 127;
    st_var_0.buffer[2] = (stage_v_74 & 15);
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int sub_step_75 = (sec_r000993_4 + pub_r000993_5 + 21) & 127;
    int stage_v_75 = (sub_step_75 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[0] = (stage_v_75 & 15);
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int sub_step_76 = (stage_v_70 + pub_r000993_14 + 27) & 127;
    int stage_v_76 = (sub_step_76 * 2 + pub_r000993_4) & 127;
    st_var_0.buffer[1] = (stage_v_76 & 15);
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int sub_step_77 = (sec_r000993_7 + pub_r000993_3 + 32) & 127;
    int stage_v_77 = (sub_step_77 * 2 + pub_r000993_3) & 127;
    st_var_1.buffer[2] = (stage_v_77 & 15);
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int sub_step_78 = (stage_v_55 + pub_r000993_13 + 25) & 127;
    int stage_v_78 = (sub_step_78 * 2 + pub_r000993_12) & 127;
    st_var_0.buffer[0] = (stage_v_78 & 15);
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int sub_step_79 = (sec_r000993_9 + pub_r000993_1 + 30) & 127;
    int stage_v_79 = (sub_step_79 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[1] = (stage_v_79 & 15);
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int sub_step_80 = (sub_step_72 + pub_r000993_8 + 14) & 127;
    int stage_v_80 = (sub_step_80 * 2 + pub_r000993_12) & 127;
    st_var_0.buffer[2] = (stage_v_80 & 15);
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (sec_r000993_1 + pub_r000993_3 + 20) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000993_12) & 127;
    st_var_1.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (sec_r000993_15 + pub_r000993_4 + 21) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000993_8) & 127;
    st_var_0.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (stage_v_56 + pub_r000993_4 + 17) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000993_12) & 127;
    st_var_1.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (sub_step_69 + pub_r000993_12 + 35) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000993_3) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (stage_v_72 + pub_r000993_12 + 10) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000993_8) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (sub_step_59 + pub_r000993_14 + 28) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (stage_v_68 + pub_r000993_11 + 15) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000993_4) & 127;
    st_var_1.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (sec_r000993_7 + pub_r000993_12 + 10) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000993_0) & 127;
    st_var_0.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (stage_v_65 + pub_r000993_4 + 18) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000993_14) & 127;
    st_var_1.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sub_step_88 + pub_r000993_8 + 23) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000993_0) & 127;
    st_var_0.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sec_r000993_12 + pub_r000993_3 + 31) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (stage_v_79 + pub_r000993_9 + 32) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000993_0) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (stage_v_82 + pub_r000993_5 + 6) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000993_2) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sec_r000993_8 + pub_r000993_13 + 34) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sec_r000993_2 + pub_r000993_9 + 29) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000993_15) & 127;
    st_var_1.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (stage_v_77 + pub_r000993_1 + 13) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (sub_step_58 + pub_r000993_1 + 10) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000993_13) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sub_step_89 + pub_r000993_1 + 18) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sub_step_74 + pub_r000993_0 + 6) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (stage_v_95 + pub_r000993_4 + 22) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (stage_v_80 + pub_r000993_2 + 27) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000993_14) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sec_r000993_9 + pub_r000993_9 + 20) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (stage_v_92 + pub_r000993_11 + 11) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000993_9) & 127;
    st_var_1.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (sec_r000993_13 + pub_r000993_1 + 17) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000993_6) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sub_step_68 + pub_r000993_0 + 17) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000993_14) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (stage_v_60 + pub_r000993_12 + 33) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (stage_v_89 + pub_r000993_5 + 23) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000993_3) & 127;
    st_var_1.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sec_r000993_3 + pub_r000993_9 + 34) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sec_r000993_0 + pub_r000993_14 + 11) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000993_13) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (sub_step_94 + pub_r000993_8 + 8) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (stage_v_71 + pub_r000993_5 + 7) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000993_12) & 127;
    st_var_1.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000993_12 + pub_r000993_7 + 33) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000993_10) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (stage_v_105 + pub_r000993_8 + 31) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (stage_v_90 + pub_r000993_8 + 32) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000993_8) & 127;
    st_var_0.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_63 + pub_r000993_11 + 10) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000993_11) & 127;
    st_var_1.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (stage_v_76 + pub_r000993_6 + 12) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000993_14) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (stage_v_69 + pub_r000993_9 + 11) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000993_14) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (stage_v_107 + pub_r000993_13 + 6) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sec_r000993_4 + pub_r000993_14 + 17) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000993_9) & 127;
    st_var_1.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sec_r000993_2 + pub_r000993_2 + 22) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000993_14) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sec_r000993_10 + pub_r000993_3 + 35) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (stage_v_63 + pub_r000993_15 + 17) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sub_step_122 + pub_r000993_9 + 35) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000993_1) & 127;
    st_var_1.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sub_step_106 + pub_r000993_4 + 19) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000993_11) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sub_step_104 + pub_r000993_2 + 26) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000993_14) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (sub_step_77 + pub_r000993_12 + 15) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sub_step_74 + pub_r000993_12 + 27) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000993_7) & 127;
    st_var_1.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (stage_v_75 + pub_r000993_6 + 30) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sub_step_118 + pub_r000993_6 + 19) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000993_15) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sub_step_94 + pub_r000993_15 + 32) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sub_step_100 + pub_r000993_8 + 30) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000993_8) & 127;
    st_var_1.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (sec_r000993_3 + pub_r000993_6 + 17) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000993_11) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (stage_v_106 + pub_r000993_13 + 27) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000993_15) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sub_step_124 + pub_r000993_9 + 24) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000993_6) & 127;
    st_var_0.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (stage_v_79 + pub_r000993_15 + 27) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000993_13) & 127;
    st_var_1.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (stage_v_56 + pub_r000993_6 + 15) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sub_step_53 + pub_r000993_1 + 26) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000993_15) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sec_r000993_10 + pub_r000993_1 + 14) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000993_5) & 127;
    st_var_0.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (stage_v_58 + pub_r000993_8 + 8) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sec_r000993_11 + pub_r000993_7 + 10) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000993_6) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sec_r000993_0 + pub_r000993_14 + 8) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000993_0) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (stage_v_114 + pub_r000993_9 + 7) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000993_0) & 127;
    st_var_0.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (stage_v_80 + pub_r000993_3 + 25) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (stage_v_122 + pub_r000993_7 + 32) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000993_14) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (stage_v_53 + pub_r000993_14 + 32) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (stage_v_69 + pub_r000993_14 + 26) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000993_10) & 127;
    st_var_0.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sec_r000993_16 + pub_r000993_0 + 20) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sub_step_61 + pub_r000993_5 + 25) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000993_2) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (stage_v_104 + pub_r000993_14 + 8) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000993_0) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (sub_step_72 + pub_r000993_14 + 22) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000993_2) & 127;
    st_var_0.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sec_r000993_11 + pub_r000993_5 + 17) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000993_15) & 127;
    st_var_1.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sec_r000993_12 + pub_r000993_6 + 31) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000993_2) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sec_r000993_7 + pub_r000993_14 + 17) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (sub_step_83 + pub_r000993_4 + 12) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sec_r000993_11 + pub_r000993_8 + 31) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000993_9) & 127;
    st_var_1.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sec_r000993_7 + pub_r000993_11 + 5) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000993_0) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (stage_v_99 + pub_r000993_3 + 26) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000993_14) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sub_step_119 + pub_r000993_8 + 10) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sec_r000993_4 + pub_r000993_5 + 9) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000993_4) & 127;
    st_var_1.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (sec_r000993_7 + pub_r000993_14 + 24) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000993_5) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (stage_v_147 + pub_r000993_2 + 20) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (stage_v_71 + pub_r000993_8 + 7) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000993_2) & 127;
    st_var_0.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_160 + pub_r000993_11 + 30) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000993_0) & 127;
    st_var_1.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (stage_v_141 + pub_r000993_3 + 5) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000993_12) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (sec_r000993_13 + pub_r000993_6 + 11) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000993_4) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sec_r000993_3 + pub_r000993_3 + 34) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (sec_r000993_1 + pub_r000993_5 + 30) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sec_r000993_12 + pub_r000993_15 + 12) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (stage_v_65 + pub_r000993_10 + 25) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sub_step_158 + pub_r000993_8 + 12) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (stage_v_134 + pub_r000993_15 + 11) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (stage_v_140 + pub_r000993_8 + 22) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (stage_v_155 + pub_r000993_7 + 29) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sub_step_134 + pub_r000993_5 + 27) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000993_11) & 127;
    st_var_0.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (stage_v_161 + pub_r000993_1 + 20) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000993_2) & 127;
    st_var_1.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sec_r000993_12 + pub_r000993_14 + 17) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000993_2) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sec_r000993_9 + pub_r000993_2 + 23) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000993_0) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (stage_v_141 + pub_r000993_3 + 16) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000993_8) & 127;
    st_var_0.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sub_step_69 + pub_r000993_9 + 5) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (stage_v_108 + pub_r000993_5 + 31) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000993_11) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (stage_v_83 + pub_r000993_12 + 34) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000993_12) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sub_step_125 + pub_r000993_13 + 10) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (stage_v_93 + pub_r000993_13 + 27) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000993_8) & 127;
    st_var_1.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (sec_r000993_1 + pub_r000993_10 + 34) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000993_6) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sub_step_102 + pub_r000993_1 + 17) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000993_14) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (stage_v_155 + pub_r000993_5 + 30) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (stage_v_126 + pub_r000993_12 + 12) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sec_r000993_7 + pub_r000993_14 + 19) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000993_12) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sub_step_109 + pub_r000993_7 + 28) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (stage_v_112 + pub_r000993_0 + 20) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000993_14) & 127;
    st_var_0.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (sec_r000993_1 + pub_r000993_4 + 6) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000993_2) & 127;
    st_var_1.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sec_r000993_9 + pub_r000993_13 + 14) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000993_8) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sec_r000993_4 + pub_r000993_3 + 22) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000993_9) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (stage_v_110 + pub_r000993_7 + 32) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (stage_v_55 + pub_r000993_14 + 31) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000993_15) & 127;
    st_var_1.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (stage_v_165 + pub_r000993_4 + 9) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sec_r000993_16 + pub_r000993_8 + 30) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sub_step_160 + pub_r000993_10 + 16) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (stage_v_164 + pub_r000993_2 + 19) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000993_11) & 127;
    st_var_1.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (stage_v_166 + pub_r000993_9 + 26) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sec_r000993_4 + pub_r000993_2 + 34) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000993_4) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (stage_v_169 + pub_r000993_10 + 34) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (stage_v_190 + pub_r000993_6 + 32) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000993_4) & 127;
    st_var_1.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (stage_v_176 + pub_r000993_3 + 35) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000993_5) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sec_r000993_6 + pub_r000993_5 + 7) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000993_7) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sec_r000993_15 + pub_r000993_4 + 24) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000993_15) & 127;
    st_var_0.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (sec_r000993_7 + pub_r000993_10 + 20) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000993_4) & 127;
    st_var_1.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sec_r000993_7 + pub_r000993_5 + 7) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (stage_v_146 + pub_r000993_3 + 11) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000993_7) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (sub_step_155 + pub_r000993_1 + 20) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000993_6) & 127;
    st_var_0.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sec_r000993_4 + pub_r000993_0 + 30) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000993_1) & 127;
    st_var_1.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sec_r000993_8 + pub_r000993_12 + 10) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000993_4) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (stage_v_153 + pub_r000993_0 + 15) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000993_11) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (stage_v_205 + pub_r000993_7 + 11) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000993_4) & 127;
    st_var_0.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_201 + pub_r000993_8 + 29) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000993_3) & 127;
    st_var_1.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sec_r000993_4 + pub_r000993_6 + 19) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000993_10) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sec_r000993_11 + pub_r000993_10 + 24) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000993_7) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (stage_v_173 + pub_r000993_6 + 12) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sec_r000993_14 + pub_r000993_10 + 14) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000993_0) & 127;
    st_var_1.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (sec_r000993_3 + pub_r000993_11 + 25) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sub_step_215 + pub_r000993_12 + 12) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000993_1) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sub_step_100 + pub_r000993_8 + 34) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000993_6) & 127;
    st_var_0.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (stage_v_215 + pub_r000993_11 + 5) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000993_7) & 127;
    st_var_1.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (stage_v_145 + pub_r000993_11 + 19) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sub_step_92 + pub_r000993_13 + 20) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sec_r000993_15 + pub_r000993_9 + 14) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (stage_v_185 + pub_r000993_15 + 11) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000993_0) & 127;
    st_var_1.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (stage_v_219 + pub_r000993_8 + 33) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (sub_step_91 + pub_r000993_14 + 6) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000993_7) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sec_r000993_14 + pub_r000993_1 + 15) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000993_12) & 127;
    st_var_0.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (stage_v_58 + pub_r000993_1 + 12) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000993_13) & 127;
    st_var_1.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (stage_v_122 + pub_r000993_13 + 22) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (stage_v_133 + pub_r000993_8 + 24) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000993_3) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sec_r000993_1 + pub_r000993_15 + 19) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000993_14) & 127;
    st_var_0.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sub_step_221 + pub_r000993_12 + 18) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000993_1) & 127;
    st_var_1.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (sec_r000993_11 + pub_r000993_13 + 26) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000993_7) & 127;
    st_var_0.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (sec_r000993_15 + pub_r000993_11 + 12) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (sub_step_156 + pub_r000993_11 + 11) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000993_14) & 127;
    st_var_0.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sec_r000993_12 + pub_r000993_12 + 28) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000993_13) & 127;
    st_var_1.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sub_step_154 + pub_r000993_1 + 16) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000993_1) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (stage_v_138 + pub_r000993_13 + 28) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000993_8) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sub_step_122 + pub_r000993_4 + 35) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000993_0) & 127;
    st_var_0.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (sec_r000993_10 + pub_r000993_2 + 31) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000993_11) & 127;
    st_var_1.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (sub_step_185 + pub_r000993_13 + 19) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sec_r000993_0 + pub_r000993_7 + 26) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000993_5) & 127;
    st_var_1.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (stage_v_75 + pub_r000993_15 + 31) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000993_4) & 127;
    st_var_0.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (stage_v_129 + pub_r000993_10 + 34) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000993_6) & 127;
    st_var_1.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sec_r000993_10 + pub_r000993_2 + 35) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000993_3) & 127;
    st_var_0.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (stage_v_137 + pub_r000993_2 + 5) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000993_8) & 127;
    st_var_1.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (stage_v_73 + pub_r000993_4 + 26) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000993_9) & 127;
    st_var_0.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (sec_r000993_3 + pub_r000993_1 + 13) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000993_15) & 127;
    st_var_1.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (sec_r000993_3 + pub_r000993_0 + 18) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000993_10) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (sub_step_162 + pub_r000993_15 + 28) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000993_10) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (sec_r000993_10 + pub_r000993_11 + 14) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000993_13) & 127;
    st_var_0.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (sec_r000993_4 + pub_r000993_5 + 21) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000993_13) & 127;
    st_var_1.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (sub_step_214 + pub_r000993_0 + 13) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000993_4) & 127;
    st_var_0.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
