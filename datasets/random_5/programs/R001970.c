/*
 * Benchmark Program: R001970
 * Security Family: mixed_control_data
 * Generator Seed: 697013
 * High Inputs: 18 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001970_7013_0 {
    short trace;
    unsigned char scale;
    int determinant;
    int dim;
    int buffer[3];
};

struct StreamBuffer_R001970_7013_1 {
    unsigned char watermark;
    unsigned char head;
    int checksum;
    int state;
    int capacity;
    int buffer[3];
};

struct CipherContext_R001970_7013_2 {
    int round_key;
    unsigned char tag;
    int flags;
    int counter;
    short iv;
    int nonce;
    int buffer[3];
};

union ColorPixel_R001970_7013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001970_7013_0(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int checksum_61 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_61 > 26) {
        acc = (acc + checksum_61 * 2 + 5) & 127;
        aux ^= (checksum_61 & 15);
    } else {
        acc = (acc - checksum_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_15 = local_arr[aux % 3];
    acc = (acc + window_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001970_7013_1(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int factor_22 = (aux + st.buffer[1]) & 3;
    switch (factor_22) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_2(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_84 = local_arr[aux % 3];
    acc = (acc + residue_84 * 2) & 127;
    int damping_17 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_17 > 13) {
        acc = (acc + damping_17 * 2 + 5) & 127;
        aux ^= (damping_17 & 15);
    } else {
        acc = (acc - damping_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_62) & 63;
    acc ^= aux;
    int parity_49 = (aux + st.buffer[1]) & 3;
    switch (parity_49) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_22 = 0;
    for (int k = 0; k < 3; k++) {
        delta_22 = (delta_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int pivot_83 = (aux + st.buffer[1]) & 3;
    switch (pivot_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_51 = local_arr[aux % 3];
    acc = (acc + stride_51 * 2) & 127;
    int scale_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_64) & 63;
    acc ^= aux;
    int pivot_45 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_45 > 42) {
        acc = (acc + pivot_45 * 2 + 5) & 127;
        aux ^= (pivot_45 & 15);
    } else {
        acc = (acc - pivot_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001970_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_88 = 0;
    for (int k = 0; k < 2; k++) {
        damping_88 = (damping_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_88) & 127;
    }
    int tally_23 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_23 > 12) {
        acc = (acc + tally_23 * 2 + 5) & 127;
        aux ^= (tally_23 & 15);
    } else {
        acc = (acc - tally_23 + 11) & 127;
        aux += 3;
    }
    int tracker_87 = (aux + st.buffer[1]) & 3;
    switch (tracker_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_71 = local_arr[aux % 3];
    acc = (acc + pivot_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001970_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quantum_20 = (aux + st.buffer[1]) & 3;
    switch (quantum_20) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_7(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int factor_10 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_10 > 24) {
        acc = (acc + factor_10 * 2 + 5) & 127;
        aux ^= (factor_10 & 15);
    } else {
        acc = (acc - factor_10 + 11) & 127;
        aux += 3;
    }
    int weight_78 = (aux + st.buffer[1]) & 3;
    switch (weight_78) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_93 = 0;
    for (int k = 0; k < 2; k++) {
        damping_93 = (damping_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_8(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001970_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int stride_90 = (aux + st.buffer[1]) & 3;
    switch (stride_90) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001970_7013_9(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001970_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int tracker_23 = local_arr[aux % 3];
    acc = (acc + tracker_23 * 2) & 127;
    int accumulator_48 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_48 = (accumulator_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_48) & 127;
    }
    int checksum_10 = (aux + st.buffer[1]) & 3;
    switch (checksum_10) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_10(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001970_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_89 = (aux + st.buffer[1]) & 3;
    switch (scale_89) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_72 = local_arr[aux % 3];
    acc = (acc + phase_72 * 2) & 127;
    int quantum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001970_7013_11(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001970_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quantum_60 = (aux + st.buffer[1]) & 3;
    switch (quantum_60) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_32) & 63;
    acc ^= aux;
    int index_reg_16 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_16 > 28) {
        acc = (acc + index_reg_16 * 2 + 5) & 127;
        aux ^= (index_reg_16 & 15);
    } else {
        acc = (acc - index_reg_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_59 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_59 > 27) {
        acc = (acc + damping_59 * 2 + 5) & 127;
        aux ^= (damping_59 & 15);
    } else {
        acc = (acc - damping_59 + 11) & 127;
        aux += 3;
    }
    int bound_95 = (aux + st.buffer[1]) & 3;
    switch (bound_95) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_56) & 63;
    acc ^= aux;
    int weight_69 = (aux + st.buffer[1]) & 3;
    switch (weight_69) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_21 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_21 > 14) {
        acc = (acc + stride_21 * 2 + 5) & 127;
        aux ^= (stride_21 & 15);
    } else {
        acc = (acc - stride_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_58 = 0;
    for (int k = 0; k < 2; k++) {
        stride_58 = (stride_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_58) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_36 = local_arr[aux % 3];
    acc = (acc + bound_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001970_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_45 = (aux + st.buffer[1]) & 3;
    switch (margin_45) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_95 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_95 > 24) {
        acc = (acc + scale_95 * 2 + 5) & 127;
        aux ^= (scale_95 & 15);
    } else {
        acc = (acc - scale_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_16(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001970_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_13 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_13 > 42) {
        acc = (acc + weight_13 * 2 + 5) & 127;
        aux ^= (weight_13 & 15);
    } else {
        acc = (acc - weight_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_31 = local_arr[aux % 3];
    acc = (acc + parity_31 * 2) & 127;
    int tally_38 = 0;
    for (int k = 0; k < 3; k++) {
        tally_38 = (tally_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_38) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_17(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001970_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_13) & 63;
    acc ^= aux;
    int anchor_16 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_16 > 49) {
        acc = (acc + anchor_16 * 2 + 5) & 127;
        aux ^= (anchor_16 & 15);
    } else {
        acc = (acc - anchor_16 + 11) & 127;
        aux += 3;
    }
    int residue_95 = 0;
    for (int k = 0; k < 2; k++) {
        residue_95 = (residue_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_95) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_18(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001970_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_92 = local_arr[aux % 3];
    acc = (acc + coefficient_92 * 2) & 127;
    int quantum_29 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_29 = (quantum_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_29) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001970_7013_19(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001970_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int offset_29 = 0;
    for (int k = 0; k < 3; k++) {
        offset_29 = (offset_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_29) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_33 = local_arr[aux % 3];
    acc = (acc + phase_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_20(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int offset_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_53 = local_arr[aux % 3];
    acc = (acc + damping_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int phase_55 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_55 > 22) {
        acc = (acc + phase_55 * 2 + 5) & 127;
        aux ^= (phase_55 & 15);
    } else {
        acc = (acc - phase_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_13 = local_arr[aux % 3];
    acc = (acc + scale_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001970_7013_22(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001970_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_29 = local_arr[aux % 3];
    acc = (acc + bound_29 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001970_0;
    int sec_r001970_1;
    int sec_r001970_2;
    int sec_r001970_3;
    int sec_r001970_4;
    int sec_r001970_5;
    int sec_r001970_6;
    int sec_r001970_7;
    int sec_r001970_8;
    int sec_r001970_9;
    int sec_r001970_10;
    int sec_r001970_11;
    int sec_r001970_12;
    int sec_r001970_13;
    int sec_r001970_14;
    int sec_r001970_15;
    int sec_r001970_16;
    int sec_r001970_17;
    int pub_r001970_0;
    int pub_r001970_1;
    int pub_r001970_2;
    int pub_r001970_3;
    int pub_r001970_4;
    int pub_r001970_5;
    int pub_r001970_6;
    int pub_r001970_7;
    int pub_r001970_8;
    int pub_r001970_9;
    int pub_r001970_10;
    int pub_r001970_11;
    int pub_r001970_12;
    int pub_r001970_13;
    int pub_r001970_14;
    int pub_r001970_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001970_0 >= -100 && pub_r001970_0 <= 100);
    __CPROVER_assume(pub_r001970_1 >= -100 && pub_r001970_1 <= 100);
    __CPROVER_assume(pub_r001970_2 >= -100 && pub_r001970_2 <= 100);
    __CPROVER_assume(pub_r001970_3 >= -100 && pub_r001970_3 <= 100);
    __CPROVER_assume(pub_r001970_4 >= -100 && pub_r001970_4 <= 100);
    __CPROVER_assume(pub_r001970_5 >= -100 && pub_r001970_5 <= 100);
    __CPROVER_assume(pub_r001970_6 >= -100 && pub_r001970_6 <= 100);
    __CPROVER_assume(pub_r001970_7 >= -100 && pub_r001970_7 <= 100);
    __CPROVER_assume(pub_r001970_8 >= -100 && pub_r001970_8 <= 100);
    __CPROVER_assume(pub_r001970_9 >= -100 && pub_r001970_9 <= 100);
    __CPROVER_assume(pub_r001970_10 >= -100 && pub_r001970_10 <= 100);
    __CPROVER_assume(pub_r001970_11 >= -100 && pub_r001970_11 <= 100);
    __CPROVER_assume(pub_r001970_12 >= -100 && pub_r001970_12 <= 100);
    __CPROVER_assume(pub_r001970_13 >= -100 && pub_r001970_13 <= 100);
    __CPROVER_assume(pub_r001970_14 >= -100 && pub_r001970_14 <= 100);
    __CPROVER_assume(pub_r001970_15 >= -100 && pub_r001970_15 <= 100);
    __CPROVER_assume(sec_r001970_0 >= 0 && sec_r001970_0 <= 255);
    __CPROVER_assume(sec_r001970_1 >= 0 && sec_r001970_1 <= 255);
    __CPROVER_assume(sec_r001970_2 >= 0 && sec_r001970_2 <= 255);
    __CPROVER_assume(sec_r001970_3 >= 0 && sec_r001970_3 <= 255);
    __CPROVER_assume(sec_r001970_4 >= 0 && sec_r001970_4 <= 255);
    __CPROVER_assume(sec_r001970_5 >= 0 && sec_r001970_5 <= 255);
    __CPROVER_assume(sec_r001970_6 >= 0 && sec_r001970_6 <= 255);
    __CPROVER_assume(sec_r001970_7 >= 0 && sec_r001970_7 <= 255);
    __CPROVER_assume(sec_r001970_8 >= 0 && sec_r001970_8 <= 255);
    __CPROVER_assume(sec_r001970_9 >= 0 && sec_r001970_9 <= 255);
    __CPROVER_assume(sec_r001970_10 >= 0 && sec_r001970_10 <= 255);
    __CPROVER_assume(sec_r001970_11 >= 0 && sec_r001970_11 <= 255);
    __CPROVER_assume(sec_r001970_12 >= 0 && sec_r001970_12 <= 255);
    __CPROVER_assume(sec_r001970_13 >= 0 && sec_r001970_13 <= 255);
    __CPROVER_assume(sec_r001970_14 >= 0 && sec_r001970_14 <= 255);
    __CPROVER_assume(sec_r001970_15 >= 0 && sec_r001970_15 <= 255);
    __CPROVER_assume(sec_r001970_16 >= 0 && sec_r001970_16 <= 255);
    __CPROVER_assume(sec_r001970_17 >= 0 && sec_r001970_17 <= 255);

    struct MatrixBlock_R001970_7013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001970_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001970_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001970_0 + 7) & 15;
    struct StreamBuffer_R001970_7013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001970_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001970_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001970_0 + 9) & 15;
    struct CipherContext_R001970_7013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001970_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001970_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001970_0 + 11) & 15;

    union ColorPixel_R001970_7013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001970_7013_0(sec_r001970_0, pub_r001970_1);
    int helper_flow_1 = fn_R001970_7013_1(sec_r001970_1, sec_r001970_2, pub_r001970_3);
    int helper_flow_2 = fn_R001970_7013_2(sec_r001970_2, pub_r001970_3, pub_r001970_4);
    int helper_flow_3 = fn_R001970_7013_3(sec_r001970_3, sec_r001970_4, pub_r001970_5, pub_r001970_6, pub_r001970_7);
    int helper_flow_4 = fn_R001970_7013_4(sec_r001970_4, pub_r001970_5, pub_r001970_6, pub_r001970_7, pub_r001970_8);
    int helper_flow_5 = fn_R001970_7013_5(sec_r001970_5, sec_r001970_6, pub_r001970_7, pub_r001970_8);
    int helper_flow_6 = fn_R001970_7013_6(sec_r001970_6, pub_r001970_7, pub_r001970_8, pub_r001970_9);
    int helper_flow_7 = fn_R001970_7013_7(sec_r001970_7, sec_r001970_8);
    int helper_flow_8 = fn_R001970_7013_8(sec_r001970_8, sec_r001970_9);
    int helper_flow_9 = fn_R001970_7013_9(sec_r001970_9, sec_r001970_10);
    int helper_flow_10 = fn_R001970_7013_10(sec_r001970_10, sec_r001970_11);
    int helper_flow_11 = fn_R001970_7013_11(sec_r001970_11, pub_r001970_12);
    int helper_flow_12 = fn_R001970_7013_12(sec_r001970_12, sec_r001970_13, pub_r001970_14, pub_r001970_15);
    int helper_flow_13 = fn_R001970_7013_13(sec_r001970_13, sec_r001970_14, pub_r001970_15, pub_r001970_0);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_0 > 39) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001970_3 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_1 > 41) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_2 > 27) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_3 > 42) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001970_15 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_4 > 31) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001970_11 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_5 > 21) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_6 > 20) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_7 > 48) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_8 > 44) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001970_6 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_9 > 24) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_10 > 48) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001970_9 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_11 > 42) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001970_11 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_12 > 38) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_13 > 40) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001970_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001970_16 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_15 > 45) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001970_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001970_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001970_9 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_18 > 43) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_19 > 21) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_20 > 24) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_21 > 35) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_22 > 40) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_23 > 24) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001970_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001970_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001970_15 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_26 > 29) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001970_6 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_27 > 27) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001970_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001970_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_30 > 47) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_31 > 34) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001970_9 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_32 > 26) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001970_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_34 > 27) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001970_2 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_35 > 46) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_36 > 38) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_37 > 28) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001970_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_39 > 25) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_40 > 36) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_41 > 25) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001970_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_43 > 27) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_44 > 44) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_45 > 32) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001970_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_47 > 44) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_48 > 20) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_49 > 48) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_50 > 36) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001970_0 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_51 > 26) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001970_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_53 > 44) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_54 > 31) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_55 > 31) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001970_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001970_15 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_57 > 26) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001970_8 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_58 > 21) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_59 > 38) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_60 > 30) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_61 > 25) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_62 > 25) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001970_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_64 > 47) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_65 > 50) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001970_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_67 > 41) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_68 > 26) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_69 > 24) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_70 > 20) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_71 > 32) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_72 > 42) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_73 > 30) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001970_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001970_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001970_8 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_76 > 23) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001970_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_78 > 50) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001970_9 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_79 > 21) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001970_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_81 > 25) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001970_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_83 > 24) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_84 > 37) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001970_1 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_85 > 43) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001970_14 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_86 > 43) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001970_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_88 > 39) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001970_10 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_89 > 39) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_90 > 48) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_91 > 48) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001970_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001970_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001970_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_95 > 25) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_96 > 36) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_97 > 25) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_98 > 46) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_99 > 20) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_100 > 30) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001970_11 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_101 > 50) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001970_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_103 > 32) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001970_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_105 > 20) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_106 > 42) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_107 > 31) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_108 > 49) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001970_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_110 > 25) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001970_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_112 > 29) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_113 > 39) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_114 > 45) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001970_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001970_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001970_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_118 > 43) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001970_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001970_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001970_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_122 > 44) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_123 > 33) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001970_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_125 > 43) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001970_0 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_126 > 21) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001970_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001970_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_129 > 25) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_130 > 36) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001970_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_132 > 35) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_133 > 40) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001970_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001970_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_136 > 49) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_137 > 38) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001970_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r001970_12 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_139 > 41) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_140 > 32) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_141 > 35) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_142 > 28) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_143 > 22) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_144 > 37) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_145 > 30) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_146 > 24) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_147 > 32) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_148 > 25) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_149 > 44) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001970_14 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_150 > 24) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_151 > 33) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_152 > 49) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_153 > 50) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001970_17 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_154 > 21) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_155 > 33) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_156 > 21) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_157 > 45) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_158 > 23) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_159 > 37) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001970_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001970_3) & 127;
    if (stage_v_161 > 32) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r001970_15 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_162 > 47) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r001970_14 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_163 > 44) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_164 > 48) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001970_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_166 > 34) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r001970_12 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_167 > 41) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_168 > 29) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_166 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_169 > 43) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001970_6 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_170 > 35) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001970_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001970_13 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_172 > 20) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r001970_8 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_173 > 29) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_156 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_174 > 31) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001970_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_176 > 20) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001970_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r001970_7 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_178 > 26) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_179 > 22) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001970_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r001970_17 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_181 > 44) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001970_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001970_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001970_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001970_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001970_5) & 127;
    if (stage_v_186 > 37) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001970_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_188 > 30) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_189 > 22) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_190 > 27) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_191 > 40) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001970_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_193 > 49) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_194 > 34) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_195 > 42) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001970_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_194 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_197 > 49) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001970_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001970_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_200 > 31) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_201 > 27) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_202 > 24) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001970_2) & 127;
    if (stage_v_203 > 29) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001970_13) & 127;
    if (stage_v_204 > 20) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_190 ^ 0x2A) * 2 + pub_r001970_8) & 127;
    if (stage_v_205 > 48) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001970_12) & 127;
    if (stage_v_206 > 22) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001970_6) & 127;
    if (stage_v_207 > 23) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001970_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001970_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001970_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001970_9) & 127;
    if (stage_v_211 > 24) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001970_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001970_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_205 ^ 0x2A) * 2 + pub_r001970_14) & 127;
    if (stage_v_214 > 30) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001970_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001970_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001970_1) & 127;
    if (stage_v_217 > 25) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_218 > 33) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001970_11) & 127;
    if (stage_v_219 > 48) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001970_10) & 127;
    if (stage_v_220 > 46) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_194 ^ 0x2A) * 2 + pub_r001970_7) & 127;
    if (stage_v_221 > 29) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001970_15) & 127;
    if (stage_v_222 > 49) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001970_0) & 127;
    if (stage_v_223 > 36) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001970_4) & 127;
    if (stage_v_224 > 30) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001970_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
