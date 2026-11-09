/*
 * Benchmark Program: R001956
 * Security Family: implicit_flow
 * Generator Seed: 695613
 * High Inputs: 16 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001956_5613_0 {
    unsigned char offset;
    int reading;
    int calib;
    unsigned char threshold;
    int status;
    int buffer[3];
};

struct StreamBuffer_R001956_5613_1 {
    int capacity;
    short head;
    int tail;
    int watermark;
    short state;
    int checksum;
    int buffer[3];
};

struct MatrixBlock_R001956_5613_2 {
    short scale;
    short determinant;
    int density;
    int buffer[3];
};

union RegisterBank_R001956_5613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001956_5613_0(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001956_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int window_37 = local_arr[aux % 3];
    acc = (acc + window_37 * 2) & 127;
    int scale_28 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_28 > 37) {
        acc = (acc + scale_28 * 2 + 5) & 127;
        aux ^= (scale_28 & 15);
    } else {
        acc = (acc - scale_28 + 11) & 127;
        aux += 3;
    }
    int factor_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_60) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int threshold_36 = (aux + st.buffer[1]) & 3;
    switch (threshold_36) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_63 = local_arr[aux % 3];
    acc = (acc + vector_63 * 2) & 127;
    int sample_54 = 0;
    for (int k = 0; k < 3; k++) {
        sample_54 = (sample_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_54) & 127;
    }
    int threshold_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_77) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001956_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int window_11 = local_arr[aux % 3];
    acc = (acc + window_11 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_93 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_93 > 37) {
        acc = (acc + stride_93 * 2 + 5) & 127;
        aux ^= (stride_93 & 15);
    } else {
        acc = (acc - stride_93 + 11) & 127;
        aux += 3;
    }
    int offset_36 = 0;
    for (int k = 0; k < 3; k++) {
        offset_36 = (offset_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_36) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001956_5613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int factor_69 = (aux + st.buffer[1]) & 3;
    switch (factor_69) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_43 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_43 > 23) {
        acc = (acc + cursor_43 * 2 + 5) & 127;
        aux ^= (cursor_43 & 15);
    } else {
        acc = (acc - cursor_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001956_5613_4(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001956_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int anchor_57 = (aux + st.buffer[1]) & 3;
    switch (anchor_57) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_5(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_68 = 0;
    for (int k = 0; k < 2; k++) {
        metric_68 = (metric_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_68) & 127;
    }
    int vector_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_70 = 0;
    for (int k = 0; k < 2; k++) {
        residue_70 = (residue_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_70) & 127;
    }
    int segment_24 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_24 > 47) {
        acc = (acc + segment_24 * 2 + 5) & 127;
        aux ^= (segment_24 & 15);
    } else {
        acc = (acc - segment_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001956_5613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001956_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_8(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int parity_32 = 0;
    for (int k = 0; k < 2; k++) {
        parity_32 = (parity_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_32) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_95 = local_arr[aux % 3];
    acc = (acc + mask_95 * 2) & 127;
    int checksum_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_55) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001956_5613_9(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int residue_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_16) & 63;
    acc ^= aux;
    int sample_32 = (aux + st.buffer[1]) & 3;
    switch (sample_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_91 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_91 > 14) {
        acc = (acc + scale_91 * 2 + 5) & 127;
        aux ^= (scale_91 & 15);
    } else {
        acc = (acc - scale_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001956_5613_10(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001956_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int cursor_41 = local_arr[aux % 3];
    acc = (acc + cursor_41 * 2) & 127;
    int parity_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_88) & 63;
    acc ^= aux;
    int scale_88 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_88 > 48) {
        acc = (acc + scale_88 * 2 + 5) & 127;
        aux ^= (scale_88 & 15);
    } else {
        acc = (acc - scale_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001956_5613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001956_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int anchor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_35 > 37) {
        acc = (acc + anchor_35 * 2 + 5) & 127;
        aux ^= (anchor_35 & 15);
    } else {
        acc = (acc - anchor_35 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_95 = local_arr[aux % 3];
    acc = (acc + scale_95 * 2) & 127;
    int segment_90 = (aux + st.buffer[1]) & 3;
    switch (segment_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_12(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int segment_91 = (aux + st.buffer[1]) & 3;
    switch (segment_91) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_15 = local_arr[aux % 3];
    acc = (acc + weight_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001956_5613_13(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001956_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int mask_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_42) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_47 = local_arr[aux % 3];
    acc = (acc + phase_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001956_5613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001956_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int checksum_66 = (aux + st.buffer[1]) & 3;
    switch (checksum_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_37 = 0;
    for (int k = 0; k < 2; k++) {
        segment_37 = (segment_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_37) & 127;
    }
    int index_reg_64 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_64 > 21) {
        acc = (acc + index_reg_64 * 2 + 5) & 127;
        aux ^= (index_reg_64 & 15);
    } else {
        acc = (acc - index_reg_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_71 = local_arr[aux % 3];
    acc = (acc + sample_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001956_5613_15(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001956_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_53 = (aux + st.buffer[1]) & 3;
    switch (anchor_53) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001956_5613_16(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int quantum_12 = local_arr[aux % 3];
    acc = (acc + quantum_12 * 2) & 127;
    int index_reg_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001956_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int segment_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_46) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001956_5613_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int phase_10 = 0;
    for (int k = 0; k < 2; k++) {
        phase_10 = (phase_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_10) & 127;
    }
    int delta_30 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_30 > 24) {
        acc = (acc + delta_30 * 2 + 5) & 127;
        aux ^= (delta_30 & 15);
    } else {
        acc = (acc - delta_30 + 11) & 127;
        aux += 3;
    }
    int stride_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int cursor_97 = local_arr[aux % 3];
    acc = (acc + cursor_97 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_44 = (aux + st.buffer[1]) & 3;
    switch (checksum_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001956_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int threshold_36 = (aux + st.buffer[1]) & 3;
    switch (threshold_36) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001956_5613_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001956_5613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int factor_14 = 0;
    for (int k = 0; k < 2; k++) {
        factor_14 = (factor_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_14) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_10 = local_arr[aux % 3];
    acc = (acc + coefficient_10 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001956_0;
    int sec_r001956_1;
    int sec_r001956_2;
    int sec_r001956_3;
    int sec_r001956_4;
    int sec_r001956_5;
    int sec_r001956_6;
    int sec_r001956_7;
    int sec_r001956_8;
    int sec_r001956_9;
    int sec_r001956_10;
    int sec_r001956_11;
    int sec_r001956_12;
    int sec_r001956_13;
    int sec_r001956_14;
    int sec_r001956_15;
    int pub_r001956_0;
    int pub_r001956_1;
    int pub_r001956_2;
    int pub_r001956_3;
    int pub_r001956_4;
    int pub_r001956_5;
    int pub_r001956_6;
    int pub_r001956_7;
    int pub_r001956_8;
    int pub_r001956_9;
    int pub_r001956_10;
    int pub_r001956_11;
    int pub_r001956_12;
    int pub_r001956_13;
    int pub_r001956_14;
    int pub_r001956_15;
    int pub_r001956_16;
    int pub_r001956_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001956_0 >= -100 && pub_r001956_0 <= 100);
    __CPROVER_assume(pub_r001956_1 >= -100 && pub_r001956_1 <= 100);
    __CPROVER_assume(pub_r001956_2 >= -100 && pub_r001956_2 <= 100);
    __CPROVER_assume(pub_r001956_3 >= -100 && pub_r001956_3 <= 100);
    __CPROVER_assume(pub_r001956_4 >= -100 && pub_r001956_4 <= 100);
    __CPROVER_assume(pub_r001956_5 >= -100 && pub_r001956_5 <= 100);
    __CPROVER_assume(pub_r001956_6 >= -100 && pub_r001956_6 <= 100);
    __CPROVER_assume(pub_r001956_7 >= -100 && pub_r001956_7 <= 100);
    __CPROVER_assume(pub_r001956_8 >= -100 && pub_r001956_8 <= 100);
    __CPROVER_assume(pub_r001956_9 >= -100 && pub_r001956_9 <= 100);
    __CPROVER_assume(pub_r001956_10 >= -100 && pub_r001956_10 <= 100);
    __CPROVER_assume(pub_r001956_11 >= -100 && pub_r001956_11 <= 100);
    __CPROVER_assume(pub_r001956_12 >= -100 && pub_r001956_12 <= 100);
    __CPROVER_assume(pub_r001956_13 >= -100 && pub_r001956_13 <= 100);
    __CPROVER_assume(pub_r001956_14 >= -100 && pub_r001956_14 <= 100);
    __CPROVER_assume(pub_r001956_15 >= -100 && pub_r001956_15 <= 100);
    __CPROVER_assume(pub_r001956_16 >= -100 && pub_r001956_16 <= 100);
    __CPROVER_assume(pub_r001956_17 >= -100 && pub_r001956_17 <= 100);
    __CPROVER_assume(sec_r001956_0 >= 0 && sec_r001956_0 <= 255);
    __CPROVER_assume(sec_r001956_1 >= 0 && sec_r001956_1 <= 255);
    __CPROVER_assume(sec_r001956_2 >= 0 && sec_r001956_2 <= 255);
    __CPROVER_assume(sec_r001956_3 >= 0 && sec_r001956_3 <= 255);
    __CPROVER_assume(sec_r001956_4 >= 0 && sec_r001956_4 <= 255);
    __CPROVER_assume(sec_r001956_5 >= 0 && sec_r001956_5 <= 255);
    __CPROVER_assume(sec_r001956_6 >= 0 && sec_r001956_6 <= 255);
    __CPROVER_assume(sec_r001956_7 >= 0 && sec_r001956_7 <= 255);
    __CPROVER_assume(sec_r001956_8 >= 0 && sec_r001956_8 <= 255);
    __CPROVER_assume(sec_r001956_9 >= 0 && sec_r001956_9 <= 255);
    __CPROVER_assume(sec_r001956_10 >= 0 && sec_r001956_10 <= 255);
    __CPROVER_assume(sec_r001956_11 >= 0 && sec_r001956_11 <= 255);
    __CPROVER_assume(sec_r001956_12 >= 0 && sec_r001956_12 <= 255);
    __CPROVER_assume(sec_r001956_13 >= 0 && sec_r001956_13 <= 255);
    __CPROVER_assume(sec_r001956_14 >= 0 && sec_r001956_14 <= 255);
    __CPROVER_assume(sec_r001956_15 >= 0 && sec_r001956_15 <= 255);

    struct SensorNode_R001956_5613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001956_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001956_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001956_0 + 7) & 15;
    struct StreamBuffer_R001956_5613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001956_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001956_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001956_0 + 9) & 15;
    struct MatrixBlock_R001956_5613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001956_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001956_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001956_0 + 11) & 15;

    union RegisterBank_R001956_5613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001956_5613_0(sec_r001956_0, sec_r001956_1);
    int helper_flow_1 = fn_R001956_5613_1(sec_r001956_1, pub_r001956_2, pub_r001956_3, pub_r001956_4, pub_r001956_5);
    int helper_flow_2 = fn_R001956_5613_2(sec_r001956_2, sec_r001956_3, pub_r001956_4, pub_r001956_5);
    int helper_flow_3 = fn_R001956_5613_3(sec_r001956_3, pub_r001956_4, pub_r001956_5, pub_r001956_6, pub_r001956_7);
    int helper_flow_4 = fn_R001956_5613_4(sec_r001956_4, sec_r001956_5, pub_r001956_6);
    int helper_flow_5 = fn_R001956_5613_5(sec_r001956_5, sec_r001956_6);
    int helper_flow_6 = fn_R001956_5613_6(sec_r001956_6, pub_r001956_7, pub_r001956_8, pub_r001956_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001956_15 + pub_r001956_0 * 2 + 5) & 127;
    if (stage_v_0 > 19) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001956_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001956_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001956_8 + pub_r001956_15 * 2 + 14) & 127;
    if (stage_v_3 > 42) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001956_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001956_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001956_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001956_15 + pub_r001956_3 * 2 + 26) & 127;
    if (stage_v_7 > 15) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001956_3 + pub_r001956_12 * 2 + 29) & 127;
    if (stage_v_8 > 35) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001956_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_6 + pub_r001956_13 * 2 + 35) & 127;
    if (stage_v_10 > 45) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001956_13 + pub_r001956_0 * 2 + 38) & 127;
    if (stage_v_11 > 15) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_6 + pub_r001956_15 * 2 + 41) & 127;
    if (stage_v_12 > 42) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_10 + pub_r001956_1 * 2 + 44) & 127;
    if (stage_v_13 > 24) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001956_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001956_11 + pub_r001956_2 * 2 + 50) & 127;
    if (stage_v_15 > 27) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001956_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001956_7 + pub_r001956_0 * 2 + 56) & 127;
    if (stage_v_17 > 49) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001956_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001956_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001956_14 + pub_r001956_10 * 2 + 65) & 127;
    if (stage_v_20 > 24) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_12 + pub_r001956_4 * 2 + 68) & 127;
    if (stage_v_21 > 45) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001956_5 + pub_r001956_9 * 2 + 71) & 127;
    if (stage_v_22 > 25) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001956_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001956_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001956_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (helper_flow_0 + pub_r001956_12 * 2 + 83) & 127;
    if (stage_v_26 > 25) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_7 + pub_r001956_11 * 2 + 86) & 127;
    if (stage_v_27 > 48) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_21 + pub_r001956_8 * 2 + 89) & 127;
    if (stage_v_28 > 44) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_17 + pub_r001956_5 * 2 + 92) & 127;
    if (stage_v_29 > 22) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_8 + pub_r001956_12 * 2 + 95) & 127;
    if (stage_v_30 > 43) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_8 + pub_r001956_10 * 2 + 98) & 127;
    if (stage_v_31 > 43) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_27 + pub_r001956_8 * 2 + 101) & 127;
    if (stage_v_32 > 24) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001956_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001956_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_3 + pub_r001956_5 * 2 + 110) & 127;
    if (stage_v_35 > 19) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_3 + pub_r001956_2 * 2 + 113) & 127;
    if (stage_v_36 > 41) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001956_6 + pub_r001956_15 * 2 + 116) & 127;
    if (stage_v_37 > 34) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001956_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_37 + pub_r001956_14 * 2 + 122) & 127;
    if (stage_v_39 > 23) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_0 + pub_r001956_14 * 2 + 125) & 127;
    if (stage_v_40 > 49) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_12 + pub_r001956_6 * 2 + 128) & 127;
    if (stage_v_41 > 40) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001956_4 + pub_r001956_15 * 2 + 131) & 127;
    if (stage_v_42 > 34) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_0 + pub_r001956_12 * 2 + 134) & 127;
    if (stage_v_43 > 46) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001956_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001956_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001956_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001956_2 + pub_r001956_5 * 2 + 146) & 127;
    if (stage_v_47 > 54) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_12 + pub_r001956_7 * 2 + 149) & 127;
    if (stage_v_48 > 19) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_17 + pub_r001956_13 * 2 + 152) & 127;
    if (stage_v_49 > 34) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001956_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001956_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001956_12 + pub_r001956_0 * 2 + 161) & 127;
    if (stage_v_52 > 16) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001956_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001956_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001956_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001956_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (helper_flow_3 + pub_r001956_4 * 2 + 176) & 127;
    if (stage_v_57 > 51) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001956_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001956_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_13 + pub_r001956_15 * 2 + 185) & 127;
    if (stage_v_60 > 41) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001956_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001956_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_42 + pub_r001956_9 * 2 + 194) & 127;
    if (stage_v_63 > 36) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_60 + pub_r001956_5 * 2 + 197) & 127;
    if (stage_v_64 > 34) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_27 + pub_r001956_4 * 2 + 200) & 127;
    if (stage_v_65 > 40) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001956_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001956_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_10 + pub_r001956_10 * 2 + 209) & 127;
    if (stage_v_68 > 30) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_47 + pub_r001956_3 * 2 + 212) & 127;
    if (stage_v_69 > 40) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001956_2 + pub_r001956_9 * 2 + 215) & 127;
    if (stage_v_70 > 35) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_65 + pub_r001956_1 * 2 + 218) & 127;
    if (stage_v_71 > 47) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001956_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001956_11 + pub_r001956_7 * 2 + 224) & 127;
    if (stage_v_73 > 30) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_57 + pub_r001956_11 * 2 + 227) & 127;
    if (stage_v_74 > 40) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_63 + pub_r001956_2 * 2 + 230) & 127;
    if (stage_v_75 > 43) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001956_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001956_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_21 + pub_r001956_1 * 2 + 239) & 127;
    if (stage_v_78 > 17) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001956_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_35 + pub_r001956_17 * 2 + 245) & 127;
    if (stage_v_80 > 55) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001956_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_11 + pub_r001956_7 * 2 + 251) & 127;
    if (stage_v_82 > 17) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_21 + pub_r001956_6 * 2 + 254) & 127;
    if (stage_v_83 > 18) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_69 + pub_r001956_7 * 2 + 257) & 127;
    if (stage_v_84 > 32) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001956_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_63 + pub_r001956_0 * 2 + 263) & 127;
    if (stage_v_86 > 42) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_83 + pub_r001956_12 * 2 + 266) & 127;
    if (stage_v_87 > 23) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_69 + pub_r001956_10 * 2 + 269) & 127;
    if (stage_v_88 > 49) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_42 + pub_r001956_14 * 2 + 272) & 127;
    if (stage_v_89 > 15) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001956_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001956_7 + pub_r001956_3 * 2 + 278) & 127;
    if (stage_v_91 > 18) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r001956_8 + pub_r001956_14 * 2 + 281) & 127;
    if (stage_v_92 > 20) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001956_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (helper_flow_1 + pub_r001956_16 * 2 + 287) & 127;
    if (stage_v_94 > 55) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_37 + pub_r001956_7 * 2 + 290) & 127;
    if (stage_v_95 > 38) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_65 + pub_r001956_12 * 2 + 293) & 127;
    if (stage_v_96 > 17) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001956_0 + pub_r001956_11 * 2 + 296) & 127;
    if (stage_v_97 > 49) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001956_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001956_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001956_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001956_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001956_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_41 + pub_r001956_15 * 2 + 314) & 127;
    if (stage_v_103 > 50) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001956_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001956_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_80 + pub_r001956_0 * 2 + 323) & 127;
    if (stage_v_106 > 29) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_75 + pub_r001956_7 * 2 + 326) & 127;
    if (stage_v_107 > 56) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001956_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (helper_flow_4 + pub_r001956_7 * 2 + 332) & 127;
    if (stage_v_109 > 18) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_57 + pub_r001956_9 * 2 + 335) & 127;
    if (stage_v_110 > 50) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_12 + pub_r001956_9 * 2 + 338) & 127;
    if (stage_v_111 > 22) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (helper_flow_5 + pub_r001956_8 * 2 + 341) & 127;
    if (stage_v_112 > 26) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_22 + pub_r001956_8 * 2 + 344) & 127;
    if (stage_v_113 > 45) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001956_0 + pub_r001956_10 * 2 + 347) & 127;
    if (stage_v_114 > 22) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001956_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001956_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001956_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_113 + pub_r001956_7 * 2 + 359) & 127;
    if (stage_v_118 > 46) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001956_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001956_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (helper_flow_6 + pub_r001956_15 * 2 + 368) & 127;
    if (stage_v_121 > 49) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_22 + pub_r001956_11 * 2 + 371) & 127;
    if (stage_v_122 > 24) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_89 + pub_r001956_1 * 2 + 374) & 127;
    if (stage_v_123 > 41) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001956_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_8 + pub_r001956_10 * 2 + 380) & 127;
    if (stage_v_125 > 54) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_64 + pub_r001956_16 * 2 + 383) & 127;
    if (stage_v_126 > 35) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_48 + pub_r001956_11 * 2 + 386) & 127;
    if (stage_v_127 > 43) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001956_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_95 + pub_r001956_3 * 2 + 392) & 127;
    if (stage_v_129 > 59) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_3 + pub_r001956_10 * 2 + 395) & 127;
    if (stage_v_130 > 31) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_121 + pub_r001956_3 * 2 + 398) & 127;
    if (stage_v_131 > 44) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_107 + pub_r001956_14 * 2 + 401) & 127;
    if (stage_v_132 > 58) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_27 + pub_r001956_7 * 2 + 404) & 127;
    if (stage_v_133 > 17) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001956_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_103 + pub_r001956_4 * 2 + 410) & 127;
    if (stage_v_135 > 40) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (sec_r001956_2 + pub_r001956_11 * 2 + 413) & 127;
    if (stage_v_136 > 38) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001956_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_82 + pub_r001956_2 * 2 + 419) & 127;
    if (stage_v_138 > 53) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001956_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001956_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_131 + pub_r001956_4 * 2 + 428) & 127;
    if (stage_v_141 > 54) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_12 + pub_r001956_17 * 2 + 431) & 127;
    if (stage_v_142 > 18) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_39 + pub_r001956_4 * 2 + 434) & 127;
    if (stage_v_143 > 15) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_26 + pub_r001956_8 * 2 + 437) & 127;
    if (stage_v_144 > 23) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_92 + pub_r001956_3 * 2 + 440) & 127;
    if (stage_v_145 > 46) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_107 + pub_r001956_14 * 2 + 443) & 127;
    if (stage_v_146 > 30) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_63 + pub_r001956_4 * 2 + 446) & 127;
    if (stage_v_147 > 28) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_27 + pub_r001956_2 * 2 + 449) & 127;
    if (stage_v_148 > 56) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001956_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_103 + pub_r001956_7 * 2 + 455) & 127;
    if (stage_v_150 > 42) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_41 + pub_r001956_13 * 2 + 458) & 127;
    if (stage_v_151 > 60) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (helper_flow_3 + pub_r001956_9 * 2 + 461) & 127;
    if (stage_v_152 > 28) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001956_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_8 + pub_r001956_14 * 2 + 467) & 127;
    if (stage_v_154 > 37) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001956_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001956_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_29 + pub_r001956_14 * 2 + 476) & 127;
    if (stage_v_157 > 41) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001956_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_86 + pub_r001956_7 * 2 + 482) & 127;
    if (stage_v_159 > 38) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_86 + pub_r001956_3 * 2 + 485) & 127;
    if (stage_v_160 > 44) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_151 + pub_r001956_11 * 2 + 488) & 127;
    if (stage_v_161 > 48) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_13 + pub_r001956_1 * 2 + 491) & 127;
    if (stage_v_162 > 24) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (sec_r001956_0 + pub_r001956_17 * 2 + 494) & 127;
    if (stage_v_163 > 47) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_142 + pub_r001956_6 * 2 + 497) & 127;
    if (stage_v_164 > 55) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_141 + pub_r001956_14 * 2 + 500) & 127;
    if (stage_v_165 > 50) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_60 + pub_r001956_12 * 2 + 503) & 127;
    if (stage_v_166 > 17) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r001956_3 + pub_r001956_7 * 2 + 506) & 127;
    if (stage_v_167 > 40) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_73 + pub_r001956_15 * 2 + 509) & 127;
    if (stage_v_168 > 28) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001956_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001956_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_126 + pub_r001956_17 * 2 + 518) & 127;
    if (stage_v_171 > 28) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_142 + pub_r001956_8 * 2 + 521) & 127;
    if (stage_v_172 > 36) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_64 + pub_r001956_3 * 2 + 524) & 127;
    if (stage_v_173 > 38) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001956_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001956_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_150 + pub_r001956_10 * 2 + 533) & 127;
    if (stage_v_176 > 25) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001956_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (helper_flow_4 + pub_r001956_1 * 2 + 539) & 127;
    if (stage_v_178 > 24) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_30 + pub_r001956_11 * 2 + 542) & 127;
    if (stage_v_179 > 59) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001956_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001956_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_150 + pub_r001956_16 * 2 + 551) & 127;
    if (stage_v_182 > 31) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_136 + pub_r001956_7 * 2 + 554) & 127;
    if (stage_v_183 > 31) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_172 + pub_r001956_10 * 2 + 557) & 127;
    if (stage_v_184 > 46) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_133 + pub_r001956_13 * 2 + 560) & 127;
    if (stage_v_185 > 46) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_131 + pub_r001956_6 * 2 + 563) & 127;
    if (stage_v_186 > 28) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_154 + pub_r001956_7 * 2 + 566) & 127;
    if (stage_v_187 > 37) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001956_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001956_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001956_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_12 + pub_r001956_3 * 2 + 578) & 127;
    if (stage_v_191 > 60) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_74 + pub_r001956_11 * 2 + 581) & 127;
    if (stage_v_192 > 50) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001956_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001956_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001956_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_184 + pub_r001956_7 * 2 + 593) & 127;
    if (stage_v_196 > 17) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001956_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001956_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_49 + pub_r001956_16 * 2 + 602) & 127;
    if (stage_v_199 > 53) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_162 + pub_r001956_11 * 2 + 605) & 127;
    if (stage_v_200 > 41) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_127 + pub_r001956_14 * 2 + 608) & 127;
    if (stage_v_201 > 58) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (sec_r001956_15 + pub_r001956_4 * 2 + 611) & 127;
    if (stage_v_202 > 27) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_133 + pub_r001956_12 * 2 + 614) & 127;
    if (stage_v_203 > 20) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r001956_14 + pub_r001956_6 * 2 + 617) & 127;
    if (stage_v_204 > 45) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001956_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001956_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_106 + pub_r001956_11 * 2 + 626) & 127;
    if (stage_v_207 > 16) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_199 + pub_r001956_6 * 2 + 629) & 127;
    if (stage_v_208 > 28) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001956_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_80 + pub_r001956_4 * 2 + 635) & 127;
    if (stage_v_210 > 22) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_123 + pub_r001956_17 * 2 + 638) & 127;
    if (stage_v_211 > 44) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_191 + pub_r001956_15 * 2 + 641) & 127;
    if (stage_v_212 > 39) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_144 + pub_r001956_11 * 2 + 644) & 127;
    if (stage_v_213 > 20) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001956_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001956_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001956_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_187 + pub_r001956_0 * 2 + 656) & 127;
    if (stage_v_217 > 20) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001956_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_138 + pub_r001956_8 * 2 + 662) & 127;
    if (stage_v_219 > 53) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001956_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_26 + pub_r001956_12 * 2 + 668) & 127;
    if (stage_v_221 > 57) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001956_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_150 + pub_r001956_3 * 2 + 674) & 127;
    if (stage_v_223 > 54) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_141 + pub_r001956_14 * 2 + 677) & 127;
    if (stage_v_224 > 32) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_186 + pub_r001956_17 * 2 + 680) & 127;
    if (stage_v_225 > 25) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001956_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001956_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001956_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001956_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_68 + pub_r001956_12 * 2 + 695) & 127;
    if (stage_v_230 > 45) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001956_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_126 + pub_r001956_14 * 2 + 701) & 127;
    if (stage_v_232 > 53) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_13 + pub_r001956_1 * 2 + 704) & 127;
    if (stage_v_233 > 60) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (sec_r001956_8 + pub_r001956_15 * 2 + 707) & 127;
    if (stage_v_234 > 59) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_87 + pub_r001956_2 * 2 + 710) & 127;
    if (stage_v_235 > 22) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_112 + pub_r001956_5 * 2 + 713) & 127;
    if (stage_v_236 > 19) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001956_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_210 + pub_r001956_2 * 2 + 719) & 127;
    if (stage_v_238 > 22) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_161 + pub_r001956_14 * 2 + 722) & 127;
    if (stage_v_239 > 19) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_22 + pub_r001956_5 * 2 + 725) & 127;
    if (stage_v_240 > 54) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_217 + pub_r001956_8 * 2 + 728) & 127;
    if (stage_v_241 > 18) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_80 + pub_r001956_10 * 2 + 731) & 127;
    if (stage_v_242 > 46) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_42 + pub_r001956_12 * 2 + 734) & 127;
    if (stage_v_243 > 59) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_35 + pub_r001956_5 * 2 + 737) & 127;
    if (stage_v_244 > 26) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001956_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_49 + pub_r001956_1 * 2 + 743) & 127;
    if (stage_v_246 > 55) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_123 + pub_r001956_8 * 2 + 746) & 127;
    if (stage_v_247 > 46) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001956_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001956_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001956_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_31 + pub_r001956_11 * 2 + 758) & 127;
    if (stage_v_251 > 29) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_147 + pub_r001956_11 * 2 + 761) & 127;
    if (stage_v_252 > 54) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
        sec_accum ^= (stage_v_252 & 31);
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_172 + pub_r001956_13 * 2 + 764) & 127;
    if (stage_v_253 > 24) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001956_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001956_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (sec_r001956_3 + pub_r001956_7 * 2 + 773) & 127;
    if (stage_v_256 > 37) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
        sec_accum ^= (stage_v_256 & 31);
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (sec_r001956_1 + pub_r001956_12 * 2 + 776) & 127;
    if (stage_v_257 > 20) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
        sec_accum ^= (stage_v_257 & 31);
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001956_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_133 + pub_r001956_5 * 2 + 782) & 127;
    if (stage_v_259 > 40) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
        sec_accum ^= (stage_v_259 & 31);
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
