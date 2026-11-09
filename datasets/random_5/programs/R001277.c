/*
 * Benchmark Program: R001277
 * Security Family: nested_implicit_flow
 * Generator Seed: 627713
 * High Inputs: 19 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001277_7713_0 {
    int stride;
    short scale;
    short density;
    short trace;
    unsigned char determinant;
    int buffer[3];
};

struct StreamBuffer_R001277_7713_1 {
    unsigned char checksum;
    int tail;
    short watermark;
    unsigned char head;
    int buffer[3];
};

union ColorPixel_R001277_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001277_7713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001277_7713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_21 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_21 = (index_reg_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_21) & 127;
    }
    int offset_41 = (aux + st.buffer[1]) & 3;
    switch (offset_41) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_70 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_70 > 11) {
        acc = (acc + stride_70 * 2 + 5) & 127;
        aux ^= (stride_70 & 15);
    } else {
        acc = (acc - stride_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_11 = local_arr[aux % 3];
    acc = (acc + phase_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001277_7713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int pivot_77 = local_arr[aux % 3];
    acc = (acc + pivot_77 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001277_7713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int offset_41 = local_arr[aux % 3];
    acc = (acc + offset_41 * 2) & 127;
    int tally_34 = 0;
    for (int k = 0; k < 2; k++) {
        tally_34 = (tally_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_34) & 127;
    }
    int margin_33 = (aux + st.buffer[1]) & 3;
    switch (margin_33) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_98 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_98 > 29) {
        acc = (acc + index_reg_98 * 2 + 5) & 127;
        aux ^= (index_reg_98 & 15);
    } else {
        acc = (acc - index_reg_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_3(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_28 = (aux + st.buffer[1]) & 3;
    switch (weight_28) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_4(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_48 = 0;
    for (int k = 0; k < 2; k++) {
        factor_48 = (factor_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_48) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_79 = local_arr[aux % 3];
    acc = (acc + coefficient_79 * 2) & 127;
    int stride_59 = (aux + st.buffer[1]) & 3;
    switch (stride_59) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_5(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_33 = local_arr[aux % 3];
    acc = (acc + margin_33 * 2) & 127;
    int index_reg_52 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_52 > 12) {
        acc = (acc + index_reg_52 * 2 + 5) & 127;
        aux ^= (index_reg_52 & 15);
    } else {
        acc = (acc - index_reg_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_6(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int margin_70 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_70 > 39) {
        acc = (acc + margin_70 * 2 + 5) & 127;
        aux ^= (margin_70 & 15);
    } else {
        acc = (acc - margin_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_93 = local_arr[aux % 3];
    acc = (acc + mask_93 * 2) & 127;
    int scale_21 = (aux + st.buffer[1]) & 3;
    switch (scale_21) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001277_7713_7(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int parity_26 = 0;
    for (int k = 0; k < 2; k++) {
        parity_26 = (parity_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_26) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_26 = local_arr[aux % 3];
    acc = (acc + metric_26 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_66 = (aux + st.buffer[1]) & 3;
    switch (accumulator_66) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int coefficient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_32) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_79 = (aux + st.buffer[1]) & 3;
    switch (weight_79) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_41 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_41 > 12) {
        acc = (acc + weight_41 * 2 + 5) & 127;
        aux ^= (weight_41 & 15);
    } else {
        acc = (acc - weight_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_34) & 63;
    acc ^= aux;
    int checksum_90 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_90 = (checksum_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tracker_71 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_71 = (tracker_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_71) & 127;
    }
    int cursor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_46 = local_arr[aux % 3];
    acc = (acc + phase_46 * 2) & 127;
    int sample_63 = (aux + st.buffer[1]) & 3;
    switch (sample_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int anchor_13 = local_arr[aux % 3];
    acc = (acc + anchor_13 * 2) & 127;
    int quotient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001277_7713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int metric_81 = 0;
    for (int k = 0; k < 3; k++) {
        metric_81 = (metric_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_81) & 127;
    }
    int stride_68 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_68 > 36) {
        acc = (acc + stride_68 * 2 + 5) & 127;
        aux ^= (stride_68 & 15);
    } else {
        acc = (acc - stride_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int vector_18 = 0;
    for (int k = 0; k < 2; k++) {
        vector_18 = (vector_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_18) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001277_7713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tally_47 = (aux + st.buffer[1]) & 3;
    switch (tally_47) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_20) & 63;
    acc ^= aux;
    int stride_65 = 0;
    for (int k = 0; k < 3; k++) {
        stride_65 = (stride_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_65) & 127;
    }
    int threshold_84 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_84 > 20) {
        acc = (acc + threshold_84 * 2 + 5) & 127;
        aux ^= (threshold_84 & 15);
    } else {
        acc = (acc - threshold_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int window_81 = local_arr[aux % 3];
    acc = (acc + window_81 * 2) & 127;
    int vector_96 = (aux + st.buffer[1]) & 3;
    switch (vector_96) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_16(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_48 = (st.buffer[0] * 3 + aux) & 63;
    if (window_48 > 35) {
        acc = (acc + window_48 * 2 + 5) & 127;
        aux ^= (window_48 & 15);
    } else {
        acc = (acc - window_48 + 11) & 127;
        aux += 3;
    }
    int threshold_67 = (aux + st.buffer[1]) & 3;
    switch (threshold_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_18) & 63;
    acc ^= aux;
    int scale_52 = 0;
    for (int k = 0; k < 3; k++) {
        scale_52 = (scale_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int threshold_78 = (aux + st.buffer[1]) & 3;
    switch (threshold_78) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001277_7713_18(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int accumulator_97 = (aux + st.buffer[1]) & 3;
    switch (accumulator_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_48 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_48 > 34) {
        acc = (acc + margin_48 * 2 + 5) & 127;
        aux ^= (margin_48 & 15);
    } else {
        acc = (acc - margin_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_57 = local_arr[aux % 3];
    acc = (acc + window_57 * 2) & 127;
    int stride_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001277_7713_19(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_23 = 0;
    for (int k = 0; k < 3; k++) {
        weight_23 = (weight_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_20(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int pivot_70 = local_arr[aux % 3];
    acc = (acc + pivot_70 * 2) & 127;
    int checksum_74 = (aux + st.buffer[1]) & 3;
    switch (checksum_74) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_21 = 0;
    for (int k = 0; k < 2; k++) {
        stride_21 = (stride_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_21(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_57 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_57 = (quantum_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_57) & 127;
    }
    int checksum_72 = (aux + st.buffer[1]) & 3;
    switch (checksum_72) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_32 = local_arr[aux % 3];
    acc = (acc + metric_32 * 2) & 127;
    int mask_25 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_25 > 24) {
        acc = (acc + mask_25 * 2 + 5) & 127;
        aux ^= (mask_25 & 15);
    } else {
        acc = (acc - mask_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001277_7713_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_62 = local_arr[aux % 3];
    acc = (acc + weight_62 * 2) & 127;
    int anchor_45 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_45 = (anchor_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_45) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001277_0;
    int sec_r001277_1;
    int sec_r001277_2;
    int sec_r001277_3;
    int sec_r001277_4;
    int sec_r001277_5;
    int sec_r001277_6;
    int sec_r001277_7;
    int sec_r001277_8;
    int sec_r001277_9;
    int sec_r001277_10;
    int sec_r001277_11;
    int sec_r001277_12;
    int sec_r001277_13;
    int sec_r001277_14;
    int sec_r001277_15;
    int sec_r001277_16;
    int sec_r001277_17;
    int sec_r001277_18;
    int pub_r001277_0;
    int pub_r001277_1;
    int pub_r001277_2;
    int pub_r001277_3;
    int pub_r001277_4;
    int pub_r001277_5;
    int pub_r001277_6;
    int pub_r001277_7;
    int pub_r001277_8;
    int pub_r001277_9;
    int pub_r001277_10;
    int pub_r001277_11;
    int pub_r001277_12;
    int pub_r001277_13;
    int pub_r001277_14;
    int pub_r001277_15;
    int pub_r001277_16;
    int pub_r001277_17;
    int pub_r001277_18;
    int pub_r001277_19;
    int pub_r001277_20;
    int pub_r001277_21;
    int pub_r001277_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001277_0 >= -100 && pub_r001277_0 <= 100);
    __CPROVER_assume(pub_r001277_1 >= -100 && pub_r001277_1 <= 100);
    __CPROVER_assume(pub_r001277_2 >= -100 && pub_r001277_2 <= 100);
    __CPROVER_assume(pub_r001277_3 >= -100 && pub_r001277_3 <= 100);
    __CPROVER_assume(pub_r001277_4 >= -100 && pub_r001277_4 <= 100);
    __CPROVER_assume(pub_r001277_5 >= -100 && pub_r001277_5 <= 100);
    __CPROVER_assume(pub_r001277_6 >= -100 && pub_r001277_6 <= 100);
    __CPROVER_assume(pub_r001277_7 >= -100 && pub_r001277_7 <= 100);
    __CPROVER_assume(pub_r001277_8 >= -100 && pub_r001277_8 <= 100);
    __CPROVER_assume(pub_r001277_9 >= -100 && pub_r001277_9 <= 100);
    __CPROVER_assume(pub_r001277_10 >= -100 && pub_r001277_10 <= 100);
    __CPROVER_assume(pub_r001277_11 >= -100 && pub_r001277_11 <= 100);
    __CPROVER_assume(pub_r001277_12 >= -100 && pub_r001277_12 <= 100);
    __CPROVER_assume(pub_r001277_13 >= -100 && pub_r001277_13 <= 100);
    __CPROVER_assume(pub_r001277_14 >= -100 && pub_r001277_14 <= 100);
    __CPROVER_assume(pub_r001277_15 >= -100 && pub_r001277_15 <= 100);
    __CPROVER_assume(pub_r001277_16 >= -100 && pub_r001277_16 <= 100);
    __CPROVER_assume(pub_r001277_17 >= -100 && pub_r001277_17 <= 100);
    __CPROVER_assume(pub_r001277_18 >= -100 && pub_r001277_18 <= 100);
    __CPROVER_assume(pub_r001277_19 >= -100 && pub_r001277_19 <= 100);
    __CPROVER_assume(pub_r001277_20 >= -100 && pub_r001277_20 <= 100);
    __CPROVER_assume(pub_r001277_21 >= -100 && pub_r001277_21 <= 100);
    __CPROVER_assume(pub_r001277_22 >= -100 && pub_r001277_22 <= 100);
    __CPROVER_assume(sec_r001277_0 >= 0 && sec_r001277_0 <= 255);
    __CPROVER_assume(sec_r001277_1 >= 0 && sec_r001277_1 <= 255);
    __CPROVER_assume(sec_r001277_2 >= 0 && sec_r001277_2 <= 255);
    __CPROVER_assume(sec_r001277_3 >= 0 && sec_r001277_3 <= 255);
    __CPROVER_assume(sec_r001277_4 >= 0 && sec_r001277_4 <= 255);
    __CPROVER_assume(sec_r001277_5 >= 0 && sec_r001277_5 <= 255);
    __CPROVER_assume(sec_r001277_6 >= 0 && sec_r001277_6 <= 255);
    __CPROVER_assume(sec_r001277_7 >= 0 && sec_r001277_7 <= 255);
    __CPROVER_assume(sec_r001277_8 >= 0 && sec_r001277_8 <= 255);
    __CPROVER_assume(sec_r001277_9 >= 0 && sec_r001277_9 <= 255);
    __CPROVER_assume(sec_r001277_10 >= 0 && sec_r001277_10 <= 255);
    __CPROVER_assume(sec_r001277_11 >= 0 && sec_r001277_11 <= 255);
    __CPROVER_assume(sec_r001277_12 >= 0 && sec_r001277_12 <= 255);
    __CPROVER_assume(sec_r001277_13 >= 0 && sec_r001277_13 <= 255);
    __CPROVER_assume(sec_r001277_14 >= 0 && sec_r001277_14 <= 255);
    __CPROVER_assume(sec_r001277_15 >= 0 && sec_r001277_15 <= 255);
    __CPROVER_assume(sec_r001277_16 >= 0 && sec_r001277_16 <= 255);
    __CPROVER_assume(sec_r001277_17 >= 0 && sec_r001277_17 <= 255);
    __CPROVER_assume(sec_r001277_18 >= 0 && sec_r001277_18 <= 255);

    struct MatrixBlock_R001277_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001277_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001277_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001277_0 + 7) & 15;
    struct StreamBuffer_R001277_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001277_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001277_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001277_0 + 9) & 15;

    union ColorPixel_R001277_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001277_7713_0(sec_r001277_0, sec_r001277_1, pub_r001277_2, pub_r001277_3);
    int helper_flow_1 = fn_R001277_7713_1(sec_r001277_1, pub_r001277_2, pub_r001277_3, pub_r001277_4, pub_r001277_5);
    int helper_flow_2 = fn_R001277_7713_2(sec_r001277_2, sec_r001277_3, pub_r001277_4, pub_r001277_5);
    int helper_flow_3 = fn_R001277_7713_3(sec_r001277_3, pub_r001277_4);
    int helper_flow_4 = fn_R001277_7713_4(sec_r001277_4, sec_r001277_5, pub_r001277_6);
    int helper_flow_5 = fn_R001277_7713_5(sec_r001277_5, pub_r001277_6);
    int helper_flow_6 = fn_R001277_7713_6(sec_r001277_6, sec_r001277_7, pub_r001277_8);
    int helper_flow_7 = fn_R001277_7713_7(sec_r001277_7, pub_r001277_8, pub_r001277_9);
    int helper_flow_8 = fn_R001277_7713_8(sec_r001277_8, sec_r001277_9, pub_r001277_10, pub_r001277_11, pub_r001277_12);
    int helper_flow_9 = fn_R001277_7713_9(sec_r001277_9, sec_r001277_10, pub_r001277_11, pub_r001277_12, pub_r001277_13);
    int helper_flow_10 = fn_R001277_7713_10(sec_r001277_10, pub_r001277_11, pub_r001277_12, pub_r001277_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_4 ^ pub_r001277_18) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001277_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001277_11 ^ pub_r001277_11) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001277_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001277_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_3 ^ pub_r001277_15) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001277_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001277_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001277_11 ^ pub_r001277_19) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001277_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001277_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_0 ^ pub_r001277_16) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001277_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_3 ^ pub_r001277_2) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001277_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001277_16 ^ pub_r001277_7) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001277_3 ^ pub_r001277_11) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001277_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_8 ^ pub_r001277_11) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r001277_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_9 ^ pub_r001277_14) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001277_14 ^ pub_r001277_3) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001277_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001277_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001277_0 ^ pub_r001277_13) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r001277_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001277_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_4 ^ pub_r001277_2) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001277_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001277_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001277_17 ^ pub_r001277_6) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001277_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_1 ^ pub_r001277_11) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001277_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001277_7 ^ pub_r001277_7) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001277_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001277_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001277_1 ^ pub_r001277_16) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001277_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_3 ^ pub_r001277_11) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001277_4 ^ pub_r001277_0) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001277_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001277_2 ^ pub_r001277_18) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001277_15 ^ pub_r001277_4) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r001277_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001277_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001277_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001277_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001277_11 ^ pub_r001277_11) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001277_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_38 ^ pub_r001277_12) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001277_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_0 ^ pub_r001277_14) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001277_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001277_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_1 ^ pub_r001277_9) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_4 ^ pub_r001277_2) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r001277_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001277_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001277_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_22 ^ pub_r001277_3) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001277_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_4 ^ pub_r001277_4) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r001277_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (helper_flow_6 ^ pub_r001277_3) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001277_22 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001277_15 ^ pub_r001277_10) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001277_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_33 ^ pub_r001277_21) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001277_9 ^ pub_r001277_17) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001277_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001277_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_11 ^ pub_r001277_0) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001277_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_53 ^ pub_r001277_16) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001277_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_33 ^ pub_r001277_13) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001277_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001277_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001277_16 ^ pub_r001277_6) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_0 ^ pub_r001277_3) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r001277_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r001277_4 ^ pub_r001277_17) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001277_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001277_10 ^ pub_r001277_20) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001277_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_44 ^ pub_r001277_15) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001277_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001277_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_11 ^ pub_r001277_18) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_12 ^ pub_r001277_15) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_8 ^ pub_r001277_18) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001277_3 ^ pub_r001277_5) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_48 ^ pub_r001277_5) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r001277_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_4 ^ pub_r001277_4) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_8 ^ pub_r001277_6) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001277_22 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (helper_flow_3 ^ pub_r001277_14) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001277_13 ^ pub_r001277_17) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r001277_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001277_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_58 ^ pub_r001277_17) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_18 ^ pub_r001277_17) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001277_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001277_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_12 ^ pub_r001277_20) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001277_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_87 ^ pub_r001277_0) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001277_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001277_21 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_25 ^ pub_r001277_14) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001277_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_84 ^ pub_r001277_3) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_84 ^ pub_r001277_0) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_33 ^ pub_r001277_10) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001277_21 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001277_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001277_1 ^ pub_r001277_10) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001277_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_96 ^ pub_r001277_19) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r001277_9 ^ pub_r001277_14) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001277_14 ^ pub_r001277_2) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_16 ^ pub_r001277_2) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001277_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001277_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_16 ^ pub_r001277_0) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_99 ^ pub_r001277_17) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r001277_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_50 ^ pub_r001277_7) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001277_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001277_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (helper_flow_3 ^ pub_r001277_6) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001277_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001277_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (helper_flow_6 ^ pub_r001277_14) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_77 ^ pub_r001277_6) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_76 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_64 ^ pub_r001277_14) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001277_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_102 ^ pub_r001277_9) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001277_1 ^ pub_r001277_18) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_77 ^ pub_r001277_18) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r001277_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_66 ^ pub_r001277_5) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_96 ^ pub_r001277_14) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (helper_flow_2 ^ pub_r001277_0) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001277_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001277_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_10 ^ pub_r001277_12) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_64 ^ pub_r001277_2) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001277_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_76 ^ pub_r001277_6) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_87 ^ pub_r001277_14) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001277_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (helper_flow_6 ^ pub_r001277_7) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_89 ^ pub_r001277_4) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001277_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001277_1 ^ pub_r001277_5) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_13 ^ pub_r001277_16) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r001277_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001277_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001277_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001277_1 ^ pub_r001277_4) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001277_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001277_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001277_7 ^ pub_r001277_7) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001277_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_64 ^ pub_r001277_8) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r001277_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001277_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_22 ^ pub_r001277_10) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_38 ^ pub_r001277_7) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_119 ^ pub_r001277_13) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_72 ^ pub_r001277_22) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_75 ^ pub_r001277_9) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_126 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_129 ^ pub_r001277_16) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001277_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_30 ^ pub_r001277_19) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((sec_r001277_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_44 ^ pub_r001277_6) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((sec_r001277_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_84 ^ pub_r001277_17) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_132 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_127 ^ pub_r001277_16) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_7 ^ pub_r001277_18) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_69 ^ pub_r001277_15) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((sec_r001277_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001277_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001277_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_61 ^ pub_r001277_17) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001277_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_66 ^ pub_r001277_4) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_154 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_123 ^ pub_r001277_8) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (helper_flow_7 ^ pub_r001277_4) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001277_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_156 ^ pub_r001277_17) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_61 ^ pub_r001277_17) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_144 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (helper_flow_10 ^ pub_r001277_0) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_38 ^ pub_r001277_19) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((sec_r001277_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r001277_2 ^ pub_r001277_12) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_165 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (helper_flow_0 ^ pub_r001277_8) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001277_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_153 ^ pub_r001277_21) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((sec_r001277_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_81 ^ pub_r001277_19) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_115 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_80 ^ pub_r001277_15) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_147 ^ pub_r001277_12) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((sec_r001277_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001277_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (sec_r001277_10 ^ pub_r001277_19) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_139 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001277_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001277_19 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001277_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
