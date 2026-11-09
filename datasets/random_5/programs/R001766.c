/*
 * Benchmark Program: R001766
 * Security Family: implicit_flow
 * Generator Seed: 676613
 * High Inputs: 21 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001766_6613_0 {
    unsigned char offset;
    short gain;
    short threshold;
    int calib;
    int buffer[3];
};

struct MatrixBlock_R001766_6613_1 {
    int stride;
    int determinant;
    int dim;
    unsigned char density;
    int scale;
    short trace;
    int buffer[3];
};

union ColorPixel_R001766_6613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001766_6613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int residue_86 = 0;
    for (int k = 0; k < 3; k++) {
        residue_86 = (residue_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_86) & 127;
    }
    int offset_54 = (aux + st.buffer[1]) & 3;
    switch (offset_54) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001766_6613_1(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int offset_89 = 0;
    for (int k = 0; k < 2; k++) {
        offset_89 = (offset_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_89) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_40 = (aux + st.buffer[1]) & 3;
    switch (accumulator_40) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_2(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int residue_57 = (aux + st.buffer[1]) & 3;
    switch (residue_57) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_24 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_24 > 44) {
        acc = (acc + parity_24 * 2 + 5) & 127;
        aux ^= (parity_24 & 15);
    } else {
        acc = (acc - parity_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int index_reg_56 = local_arr[aux % 3];
    acc = (acc + index_reg_56 * 2) & 127;
    int vector_41 = 0;
    for (int k = 0; k < 2; k++) {
        vector_41 = (vector_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_41) & 127;
    }
    int damping_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001766_6613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int pivot_31 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_31 = (pivot_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_31) & 127;
    }
    int margin_51 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_51 > 45) {
        acc = (acc + margin_51 * 2 + 5) & 127;
        aux ^= (margin_51 & 15);
    } else {
        acc = (acc - margin_51 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001766_6613_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_42 = 0;
    for (int k = 0; k < 3; k++) {
        parity_42 = (parity_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_42) & 127;
    }
    int anchor_33 = (aux + st.buffer[1]) & 3;
    switch (anchor_33) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_6(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_84 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_84 > 40) {
        acc = (acc + cursor_84 * 2 + 5) & 127;
        aux ^= (cursor_84 & 15);
    } else {
        acc = (acc - cursor_84 + 11) & 127;
        aux += 3;
    }
    int margin_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001766_6613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int coefficient_10 = local_arr[aux % 3];
    acc = (acc + coefficient_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_62 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_62 > 49) {
        acc = (acc + index_reg_62 * 2 + 5) & 127;
        aux ^= (index_reg_62 & 15);
    } else {
        acc = (acc - index_reg_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_83 = 0;
    for (int k = 0; k < 3; k++) {
        metric_83 = (metric_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_9(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int anchor_62 = local_arr[aux % 3];
    acc = (acc + anchor_62 * 2) & 127;
    int metric_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_54) & 63;
    acc ^= aux;
    int stride_44 = 0;
    for (int k = 0; k < 2; k++) {
        stride_44 = (stride_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_44) & 127;
    }
    int parity_83 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_83 > 23) {
        acc = (acc + parity_83 * 2 + 5) & 127;
        aux ^= (parity_83 & 15);
    } else {
        acc = (acc - parity_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_44 = (aux + st.buffer[1]) & 3;
    switch (factor_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001766_6613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int vector_71 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_71 > 26) {
        acc = (acc + vector_71 * 2 + 5) & 127;
        aux ^= (vector_71 & 15);
    } else {
        acc = (acc - vector_71 + 11) & 127;
        aux += 3;
    }
    int offset_55 = 0;
    for (int k = 0; k < 2; k++) {
        offset_55 = (offset_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int factor_13 = 0;
    for (int k = 0; k < 3; k++) {
        factor_13 = (factor_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_13) & 127;
    }
    int scale_67 = (aux + st.buffer[1]) & 3;
    switch (scale_67) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_38 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_38 > 36) {
        acc = (acc + tally_38 * 2 + 5) & 127;
        aux ^= (tally_38 & 15);
    } else {
        acc = (acc - tally_38 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001766_6613_13(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_17 = (aux + st.buffer[1]) & 3;
    switch (factor_17) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001766_6613_14(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_19 = local_arr[aux % 3];
    acc = (acc + bound_19 * 2) & 127;
    int anchor_18 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_18 > 33) {
        acc = (acc + anchor_18 * 2 + 5) & 127;
        aux ^= (anchor_18 & 15);
    } else {
        acc = (acc - anchor_18 + 11) & 127;
        aux += 3;
    }
    int index_reg_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001766_6613_15(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int threshold_43 = (aux + st.buffer[1]) & 3;
    switch (threshold_43) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_52 = local_arr[aux % 3];
    acc = (acc + tracker_52 * 2) & 127;
    int bound_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001766_6613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_86 = (aux + st.buffer[1]) & 3;
    switch (accumulator_86) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_52 = 0;
    for (int k = 0; k < 2; k++) {
        residue_52 = (residue_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_52) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_52 = local_arr[aux % 3];
    acc = (acc + sample_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001766_6613_17(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quotient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_68 = local_arr[aux % 3];
    acc = (acc + factor_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001766_6613_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int delta_35 = local_arr[aux % 3];
    acc = (acc + delta_35 * 2) & 127;
    int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001766_6613_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int cursor_65 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_65 = (cursor_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_65) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_84 = local_arr[aux % 3];
    acc = (acc + mask_84 * 2) & 127;
    int scale_11 = (aux + st.buffer[1]) & 3;
    switch (scale_11) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_69) & 63;
    acc ^= aux;
    int scale_43 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_43 > 18) {
        acc = (acc + scale_43 * 2 + 5) & 127;
        aux ^= (scale_43 & 15);
    } else {
        acc = (acc - scale_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_18 = local_arr[aux % 3];
    acc = (acc + residue_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001766_6613_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int metric_63 = (aux + st.buffer[1]) & 3;
    switch (metric_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_48 = local_arr[aux % 3];
    acc = (acc + weight_48 * 2) & 127;
    int bound_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001766_6613_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001766_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int scale_41 = local_arr[aux % 3];
    acc = (acc + scale_41 * 2) & 127;
    int residue_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_20) & 63;
    acc ^= aux;
    int vector_69 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_69 > 36) {
        acc = (acc + vector_69 * 2 + 5) & 127;
        aux ^= (vector_69 & 15);
    } else {
        acc = (acc - vector_69 + 11) & 127;
        aux += 3;
    }
    int margin_75 = 0;
    for (int k = 0; k < 3; k++) {
        margin_75 = (margin_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_75) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001766_6613_23(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001766_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int threshold_33 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_33 = (threshold_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_33) & 127;
    }
    int vector_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_35) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_85 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_85 > 28) {
        acc = (acc + phase_85 * 2 + 5) & 127;
        aux ^= (phase_85 & 15);
    } else {
        acc = (acc - phase_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001766_0;
    int sec_r001766_1;
    int sec_r001766_2;
    int sec_r001766_3;
    int sec_r001766_4;
    int sec_r001766_5;
    int sec_r001766_6;
    int sec_r001766_7;
    int sec_r001766_8;
    int sec_r001766_9;
    int sec_r001766_10;
    int sec_r001766_11;
    int sec_r001766_12;
    int sec_r001766_13;
    int sec_r001766_14;
    int sec_r001766_15;
    int sec_r001766_16;
    int sec_r001766_17;
    int sec_r001766_18;
    int sec_r001766_19;
    int sec_r001766_20;
    int pub_r001766_0;
    int pub_r001766_1;
    int pub_r001766_2;
    int pub_r001766_3;
    int pub_r001766_4;
    int pub_r001766_5;
    int pub_r001766_6;
    int pub_r001766_7;
    int pub_r001766_8;
    int pub_r001766_9;
    int pub_r001766_10;
    int pub_r001766_11;
    int pub_r001766_12;
    int pub_r001766_13;
    int pub_r001766_14;
    int pub_r001766_15;
    int pub_r001766_16;
    int pub_r001766_17;
    int pub_r001766_18;
    int pub_r001766_19;
    int pub_r001766_20;
    int pub_r001766_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001766_0 >= -100 && pub_r001766_0 <= 100);
    __CPROVER_assume(pub_r001766_1 >= -100 && pub_r001766_1 <= 100);
    __CPROVER_assume(pub_r001766_2 >= -100 && pub_r001766_2 <= 100);
    __CPROVER_assume(pub_r001766_3 >= -100 && pub_r001766_3 <= 100);
    __CPROVER_assume(pub_r001766_4 >= -100 && pub_r001766_4 <= 100);
    __CPROVER_assume(pub_r001766_5 >= -100 && pub_r001766_5 <= 100);
    __CPROVER_assume(pub_r001766_6 >= -100 && pub_r001766_6 <= 100);
    __CPROVER_assume(pub_r001766_7 >= -100 && pub_r001766_7 <= 100);
    __CPROVER_assume(pub_r001766_8 >= -100 && pub_r001766_8 <= 100);
    __CPROVER_assume(pub_r001766_9 >= -100 && pub_r001766_9 <= 100);
    __CPROVER_assume(pub_r001766_10 >= -100 && pub_r001766_10 <= 100);
    __CPROVER_assume(pub_r001766_11 >= -100 && pub_r001766_11 <= 100);
    __CPROVER_assume(pub_r001766_12 >= -100 && pub_r001766_12 <= 100);
    __CPROVER_assume(pub_r001766_13 >= -100 && pub_r001766_13 <= 100);
    __CPROVER_assume(pub_r001766_14 >= -100 && pub_r001766_14 <= 100);
    __CPROVER_assume(pub_r001766_15 >= -100 && pub_r001766_15 <= 100);
    __CPROVER_assume(pub_r001766_16 >= -100 && pub_r001766_16 <= 100);
    __CPROVER_assume(pub_r001766_17 >= -100 && pub_r001766_17 <= 100);
    __CPROVER_assume(pub_r001766_18 >= -100 && pub_r001766_18 <= 100);
    __CPROVER_assume(pub_r001766_19 >= -100 && pub_r001766_19 <= 100);
    __CPROVER_assume(pub_r001766_20 >= -100 && pub_r001766_20 <= 100);
    __CPROVER_assume(pub_r001766_21 >= -100 && pub_r001766_21 <= 100);
    __CPROVER_assume(sec_r001766_0 >= 0 && sec_r001766_0 <= 255);
    __CPROVER_assume(sec_r001766_1 >= 0 && sec_r001766_1 <= 255);
    __CPROVER_assume(sec_r001766_2 >= 0 && sec_r001766_2 <= 255);
    __CPROVER_assume(sec_r001766_3 >= 0 && sec_r001766_3 <= 255);
    __CPROVER_assume(sec_r001766_4 >= 0 && sec_r001766_4 <= 255);
    __CPROVER_assume(sec_r001766_5 >= 0 && sec_r001766_5 <= 255);
    __CPROVER_assume(sec_r001766_6 >= 0 && sec_r001766_6 <= 255);
    __CPROVER_assume(sec_r001766_7 >= 0 && sec_r001766_7 <= 255);
    __CPROVER_assume(sec_r001766_8 >= 0 && sec_r001766_8 <= 255);
    __CPROVER_assume(sec_r001766_9 >= 0 && sec_r001766_9 <= 255);
    __CPROVER_assume(sec_r001766_10 >= 0 && sec_r001766_10 <= 255);
    __CPROVER_assume(sec_r001766_11 >= 0 && sec_r001766_11 <= 255);
    __CPROVER_assume(sec_r001766_12 >= 0 && sec_r001766_12 <= 255);
    __CPROVER_assume(sec_r001766_13 >= 0 && sec_r001766_13 <= 255);
    __CPROVER_assume(sec_r001766_14 >= 0 && sec_r001766_14 <= 255);
    __CPROVER_assume(sec_r001766_15 >= 0 && sec_r001766_15 <= 255);
    __CPROVER_assume(sec_r001766_16 >= 0 && sec_r001766_16 <= 255);
    __CPROVER_assume(sec_r001766_17 >= 0 && sec_r001766_17 <= 255);
    __CPROVER_assume(sec_r001766_18 >= 0 && sec_r001766_18 <= 255);
    __CPROVER_assume(sec_r001766_19 >= 0 && sec_r001766_19 <= 255);
    __CPROVER_assume(sec_r001766_20 >= 0 && sec_r001766_20 <= 255);

    struct SensorNode_R001766_6613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001766_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001766_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001766_0 + 7) & 15;
    struct MatrixBlock_R001766_6613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001766_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001766_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001766_0 + 9) & 15;

    union ColorPixel_R001766_6613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001766_6613_0(sec_r001766_0, pub_r001766_1, pub_r001766_2, pub_r001766_3, pub_r001766_4);
    int helper_flow_1 = fn_R001766_6613_1(sec_r001766_1, pub_r001766_2);
    int helper_flow_2 = fn_R001766_6613_2(sec_r001766_2, pub_r001766_3, pub_r001766_4);
    int helper_flow_3 = fn_R001766_6613_3(sec_r001766_3, sec_r001766_4, pub_r001766_5, pub_r001766_6, pub_r001766_7);
    int helper_flow_4 = fn_R001766_6613_4(sec_r001766_4, sec_r001766_5, pub_r001766_6, pub_r001766_7, pub_r001766_8);
    int helper_flow_5 = fn_R001766_6613_5(sec_r001766_5, sec_r001766_6, pub_r001766_7, pub_r001766_8);
    int helper_flow_6 = fn_R001766_6613_6(sec_r001766_6, sec_r001766_7, pub_r001766_8);
    int helper_flow_7 = fn_R001766_6613_7(sec_r001766_7, pub_r001766_8, pub_r001766_9, pub_r001766_10);
    int helper_flow_8 = fn_R001766_6613_8(sec_r001766_8, sec_r001766_9, pub_r001766_10, pub_r001766_11);
    int helper_flow_9 = fn_R001766_6613_9(sec_r001766_9, sec_r001766_10);
    int helper_flow_10 = fn_R001766_6613_10(sec_r001766_10, sec_r001766_11, pub_r001766_12, pub_r001766_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001766_10 + pub_r001766_13 * 2 + 5) & 127;
    if (stage_v_0 > 34) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_9 + pub_r001766_6 * 2 + 8) & 127;
    if (stage_v_1 > 45) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001766_14 + pub_r001766_3 * 2 + 11) & 127;
    if (stage_v_2 > 58) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_8 + pub_r001766_6 * 2 + 14) & 127;
    if (stage_v_3 > 54) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001766_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001766_12 + pub_r001766_7 * 2 + 20) & 127;
    if (stage_v_5 > 16) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001766_20 + pub_r001766_1 * 2 + 23) & 127;
    if (stage_v_6 > 31) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_8 + pub_r001766_1 * 2 + 26) & 127;
    if (stage_v_7 > 49) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001766_2 + pub_r001766_11 * 2 + 29) & 127;
    if (stage_v_8 > 43) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001766_21 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001766_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001766_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001766_9 + pub_r001766_12 * 2 + 41) & 127;
    if (stage_v_12 > 38) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001766_17 + pub_r001766_12 * 2 + 44) & 127;
    if (stage_v_13 > 16) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_8 + pub_r001766_20 * 2 + 47) & 127;
    if (stage_v_14 > 47) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_5 + pub_r001766_9 * 2 + 50) & 127;
    if (stage_v_15 > 50) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001766_18 + pub_r001766_8 * 2 + 53) & 127;
    if (stage_v_16 > 34) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (helper_flow_7 + pub_r001766_3 * 2 + 56) & 127;
    if (stage_v_17 > 53) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001766_19 + pub_r001766_10 * 2 + 59) & 127;
    if (stage_v_18 > 18) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_12 + pub_r001766_15 * 2 + 62) & 127;
    if (stage_v_19 > 36) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001766_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_5 + pub_r001766_0 * 2 + 68) & 127;
    if (stage_v_21 > 37) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_2 + pub_r001766_14 * 2 + 71) & 127;
    if (stage_v_22 > 43) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_5 + pub_r001766_6 * 2 + 74) & 127;
    if (stage_v_23 > 45) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_2 + pub_r001766_8 * 2 + 77) & 127;
    if (stage_v_24 > 35) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_2 + pub_r001766_17 * 2 + 80) & 127;
    if (stage_v_25 > 56) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_16 + pub_r001766_18 * 2 + 83) & 127;
    if (stage_v_26 > 43) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001766_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_2 + pub_r001766_14 * 2 + 89) & 127;
    if (stage_v_28 > 52) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_6 + pub_r001766_3 * 2 + 92) & 127;
    if (stage_v_29 > 37) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_23 + pub_r001766_13 * 2 + 95) & 127;
    if (stage_v_30 > 35) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001766_5 + pub_r001766_12 * 2 + 98) & 127;
    if (stage_v_31 > 24) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001766_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_10 + pub_r001766_3 * 2 + 104) & 127;
    if (stage_v_33 > 39) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_23 + pub_r001766_0 * 2 + 107) & 127;
    if (stage_v_34 > 46) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001766_10 + pub_r001766_20 * 2 + 110) & 127;
    if (stage_v_35 > 21) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001766_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_9 + pub_r001766_9 * 2 + 116) & 127;
    if (stage_v_37 > 52) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001766_10 + pub_r001766_16 * 2 + 119) & 127;
    if (stage_v_38 > 50) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (helper_flow_7 + pub_r001766_0 * 2 + 122) & 127;
    if (stage_v_39 > 16) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001766_11 + pub_r001766_18 * 2 + 125) & 127;
    if (stage_v_40 > 17) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001766_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_14 + pub_r001766_2 * 2 + 131) & 127;
    if (stage_v_42 > 32) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001766_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001766_11 + pub_r001766_8 * 2 + 137) & 127;
    if (stage_v_44 > 36) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001766_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001766_10 + pub_r001766_4 * 2 + 143) & 127;
    if (stage_v_46 > 54) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001766_12 + pub_r001766_7 * 2 + 146) & 127;
    if (stage_v_47 > 47) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001766_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_4 + pub_r001766_3 * 2 + 152) & 127;
    if (stage_v_49 > 18) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001766_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001766_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001766_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_13 + pub_r001766_21 * 2 + 164) & 127;
    if (stage_v_53 > 15) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001766_0 + pub_r001766_9 * 2 + 167) & 127;
    if (stage_v_54 > 18) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001766_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001766_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_42 + pub_r001766_13 * 2 + 176) & 127;
    if (stage_v_57 > 43) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_37 + pub_r001766_6 * 2 + 179) & 127;
    if (stage_v_58 > 40) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001766_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001766_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001766_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r001766_11 + pub_r001766_14 * 2 + 191) & 127;
    if (stage_v_62 > 44) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_14 + pub_r001766_11 * 2 + 194) & 127;
    if (stage_v_63 > 32) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_1 + pub_r001766_21 * 2 + 197) & 127;
    if (stage_v_64 > 16) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001766_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_2 + pub_r001766_6 * 2 + 203) & 127;
    if (stage_v_66 > 31) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_14 + pub_r001766_3 * 2 + 206) & 127;
    if (stage_v_67 > 52) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001766_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001766_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (helper_flow_0 + pub_r001766_18 * 2 + 215) & 127;
    if (stage_v_70 > 19) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_25 + pub_r001766_0 * 2 + 218) & 127;
    if (stage_v_71 > 21) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001766_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001766_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_0 + pub_r001766_20 * 2 + 227) & 127;
    if (stage_v_74 > 45) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001766_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001766_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_28 + pub_r001766_20 * 2 + 236) & 127;
    if (stage_v_77 > 49) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_74 + pub_r001766_7 * 2 + 239) & 127;
    if (stage_v_78 > 48) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001766_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_22 + pub_r001766_10 * 2 + 245) & 127;
    if (stage_v_80 > 17) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (helper_flow_7 + pub_r001766_13 * 2 + 248) & 127;
    if (stage_v_81 > 60) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001766_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001766_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_54 + pub_r001766_19 * 2 + 257) & 127;
    if (stage_v_84 > 28) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_44 + pub_r001766_15 * 2 + 260) & 127;
    if (stage_v_85 > 32) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_57 + pub_r001766_12 * 2 + 263) & 127;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_80 + pub_r001766_3 * 2 + 266) & 127;
    if (stage_v_87 > 45) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001766_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001766_21 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_0 + pub_r001766_2 * 2 + 275) & 127;
    if (stage_v_90 > 58) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_53 + pub_r001766_20 * 2 + 278) & 127;
    if (stage_v_91 > 59) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_35 + pub_r001766_10 * 2 + 281) & 127;
    if (stage_v_92 > 31) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001766_5 + pub_r001766_12 * 2 + 284) & 127;
    if (stage_v_93 > 36) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_12 + pub_r001766_19 * 2 + 287) & 127;
    if (stage_v_94 > 50) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_38 + pub_r001766_20 * 2 + 290) & 127;
    if (stage_v_95 > 60) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001766_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001766_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_74 + pub_r001766_16 * 2 + 299) & 127;
    if (stage_v_98 > 36) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_64 + pub_r001766_15 * 2 + 302) & 127;
    if (stage_v_99 > 48) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001766_3 + pub_r001766_8 * 2 + 305) & 127;
    if (stage_v_100 > 21) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (helper_flow_9 + pub_r001766_7 * 2 + 308) & 127;
    if (stage_v_101 > 47) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_38 + pub_r001766_9 * 2 + 311) & 127;
    if (stage_v_102 > 54) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_87 + pub_r001766_3 * 2 + 314) & 127;
    if (stage_v_103 > 60) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001766_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_26 + pub_r001766_2 * 2 + 320) & 127;
    if (stage_v_105 > 46) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (helper_flow_2 + pub_r001766_15 * 2 + 323) & 127;
    if (stage_v_106 > 46) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_103 + pub_r001766_18 * 2 + 326) & 127;
    if (stage_v_107 > 47) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (helper_flow_0 + pub_r001766_7 * 2 + 329) & 127;
    if (stage_v_108 > 49) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_98 + pub_r001766_6 * 2 + 332) & 127;
    if (stage_v_109 > 26) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001766_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001766_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001766_20 + pub_r001766_8 * 2 + 341) & 127;
    if (stage_v_112 > 42) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001766_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001766_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_23 + pub_r001766_17 * 2 + 350) & 127;
    if (stage_v_115 > 41) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_44 + pub_r001766_21 * 2 + 353) & 127;
    if (stage_v_116 > 17) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_66 + pub_r001766_18 * 2 + 356) & 127;
    if (stage_v_117 > 30) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001766_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001766_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_85 + pub_r001766_9 * 2 + 365) & 127;
    if (stage_v_120 > 46) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001766_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_91 + pub_r001766_14 * 2 + 371) & 127;
    if (stage_v_122 > 48) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_38 + pub_r001766_1 * 2 + 374) & 127;
    if (stage_v_123 > 46) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001766_13 + pub_r001766_1 * 2 + 377) & 127;
    if (stage_v_124 > 23) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001766_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001766_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001766_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001766_21 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001766_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_103 + pub_r001766_9 * 2 + 395) & 127;
    if (stage_v_130 > 48) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_6 + pub_r001766_2 * 2 + 398) & 127;
    if (stage_v_131 > 20) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001766_12 + pub_r001766_7 * 2 + 401) & 127;
    if (stage_v_132 > 25) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r001766_3 + pub_r001766_15 * 2 + 404) & 127;
    if (stage_v_133 > 16) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001766_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001766_17 + pub_r001766_18 * 2 + 410) & 127;
    if (stage_v_135 > 46) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_15 + pub_r001766_20 * 2 + 413) & 127;
    if (stage_v_136 > 57) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_23 + pub_r001766_16 * 2 + 416) & 127;
    if (stage_v_137 > 22) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001766_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001766_1 + pub_r001766_4 * 2 + 422) & 127;
    if (stage_v_139 > 35) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001766_9 + pub_r001766_8 * 2 + 425) & 127;
    if (stage_v_140 > 56) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_85 + pub_r001766_7 * 2 + 428) & 127;
    if (stage_v_141 > 30) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001766_19 + pub_r001766_20 * 2 + 431) & 127;
    if (stage_v_142 > 17) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_135 + pub_r001766_18 * 2 + 434) & 127;
    if (stage_v_143 > 21) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_112 + pub_r001766_14 * 2 + 437) & 127;
    if (stage_v_144 > 24) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_132 + pub_r001766_19 * 2 + 440) & 127;
    if (stage_v_145 > 36) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_80 + pub_r001766_7 * 2 + 443) & 127;
    if (stage_v_146 > 16) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001766_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_39 + pub_r001766_5 * 2 + 449) & 127;
    if (stage_v_148 > 27) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001766_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_1 + pub_r001766_9 * 2 + 455) & 127;
    if (stage_v_150 > 26) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001766_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_19 + pub_r001766_6 * 2 + 461) & 127;
    if (stage_v_152 > 28) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_135 + pub_r001766_16 * 2 + 464) & 127;
    if (stage_v_153 > 20) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (helper_flow_8 + pub_r001766_20 * 2 + 467) & 127;
    if (stage_v_154 > 30) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_93 + pub_r001766_13 * 2 + 470) & 127;
    if (stage_v_155 > 59) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001766_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001766_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001766_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_39 + pub_r001766_13 * 2 + 482) & 127;
    if (stage_v_159 > 51) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r001766_18 + pub_r001766_7 * 2 + 485) & 127;
    if (stage_v_160 > 23) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_54 + pub_r001766_18 * 2 + 488) & 127;
    if (stage_v_161 > 21) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001766_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_133 + pub_r001766_9 * 2 + 494) & 127;
    if (stage_v_163 > 60) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_74 + pub_r001766_0 * 2 + 497) & 127;
    if (stage_v_164 > 41) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001766_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001766_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_2 + pub_r001766_10 * 2 + 506) & 127;
    if (stage_v_167 > 60) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_47 + pub_r001766_2 * 2 + 509) & 127;
    if (stage_v_168 > 46) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_164 + pub_r001766_11 * 2 + 512) & 127;
    if (stage_v_169 > 42) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_100 + pub_r001766_15 * 2 + 515) & 127;
    if (stage_v_170 > 33) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r001766_13 + pub_r001766_12 * 2 + 518) & 127;
    if (stage_v_171 > 37) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_84 + pub_r001766_1 * 2 + 521) & 127;
    if (stage_v_172 > 40) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_130 + pub_r001766_15 * 2 + 524) & 127;
    if (stage_v_173 > 49) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r001766_19 + pub_r001766_19 * 2 + 527) & 127;
    if (stage_v_174 > 58) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_54 + pub_r001766_8 * 2 + 530) & 127;
    if (stage_v_175 > 49) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001766_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_101 + pub_r001766_9 * 2 + 536) & 127;
    if (stage_v_177 > 45) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_122 + pub_r001766_18 * 2 + 539) & 127;
    if (stage_v_178 > 59) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001766_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001766_14 + pub_r001766_21 * 2 + 545) & 127;
    if (stage_v_180 > 24) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001766_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001766_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001766_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_115 + pub_r001766_16 * 2 + 557) & 127;
    if (stage_v_184 > 49) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001766_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001766_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001766_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_178 + pub_r001766_4 * 2 + 569) & 127;
    if (stage_v_188 > 20) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (sec_r001766_11 + pub_r001766_9 * 2 + 572) & 127;
    if (stage_v_189 > 46) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001766_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001766_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001766_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_148 + pub_r001766_6 * 2 + 584) & 127;
    if (stage_v_193 > 48) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (sec_r001766_20 + pub_r001766_18 * 2 + 587) & 127;
    if (stage_v_194 > 24) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_31 + pub_r001766_16 * 2 + 590) & 127;
    if (stage_v_195 > 51) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r001766_19 + pub_r001766_10 * 2 + 593) & 127;
    if (stage_v_196 > 29) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001766_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_100 + pub_r001766_4 * 2 + 599) & 127;
    if (stage_v_198 > 32) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_102 + pub_r001766_11 * 2 + 602) & 127;
    if (stage_v_199 > 47) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_160 + pub_r001766_20 * 2 + 605) & 127;
    if (stage_v_200 > 55) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_86 + pub_r001766_13 * 2 + 608) & 127;
    if (stage_v_201 > 52) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_169 + pub_r001766_10 * 2 + 611) & 127;
    if (stage_v_202 > 22) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_5 + pub_r001766_14 * 2 + 614) & 127;
    if (stage_v_203 > 44) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001766_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (sec_r001766_9 + pub_r001766_17 * 2 + 620) & 127;
    if (stage_v_205 > 44) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (sec_r001766_0 + pub_r001766_4 * 2 + 623) & 127;
    if (stage_v_206 > 59) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_195 + pub_r001766_21 * 2 + 626) & 127;
    if (stage_v_207 > 56) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_70 + pub_r001766_11 * 2 + 629) & 127;
    if (stage_v_208 > 23) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001766_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_139 + pub_r001766_16 * 2 + 635) & 127;
    if (stage_v_210 > 27) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001766_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_198 + pub_r001766_20 * 2 + 641) & 127;
    if (stage_v_212 > 22) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_18 + pub_r001766_7 * 2 + 644) & 127;
    if (stage_v_213 > 55) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001766_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (helper_flow_5 + pub_r001766_9 * 2 + 650) & 127;
    if (stage_v_215 > 21) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001766_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (sec_r001766_10 + pub_r001766_21 * 2 + 656) & 127;
    if (stage_v_217 > 59) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_206 + pub_r001766_3 * 2 + 659) & 127;
    if (stage_v_218 > 24) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (sec_r001766_19 + pub_r001766_1 * 2 + 662) & 127;
    if (stage_v_219 > 49) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_54 + pub_r001766_4 * 2 + 665) & 127;
    if (stage_v_220 > 55) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_193 + pub_r001766_9 * 2 + 668) & 127;
    if (stage_v_221 > 18) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_38 + pub_r001766_12 * 2 + 671) & 127;
    if (stage_v_222 > 41) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (sec_r001766_5 + pub_r001766_12 * 2 + 674) & 127;
    if (stage_v_223 > 17) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_195 + pub_r001766_20 * 2 + 677) & 127;
    if (stage_v_224 > 15) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001766_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_94 + pub_r001766_7 * 2 + 683) & 127;
    if (stage_v_226 > 39) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001766_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001766_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001766_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (sec_r001766_16 + pub_r001766_21 * 2 + 695) & 127;
    if (stage_v_230 > 30) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
