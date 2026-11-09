/*
 * Benchmark Program: R001314
 * Security Family: arithmetic_flow
 * Generator Seed: 631413
 * High Inputs: 20 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001314_1413_0 {
    unsigned char cutoff;
    short damping;
    unsigned char prev_out;
    int mode;
    int buffer[3];
};

struct MatrixBlock_R001314_1413_1 {
    unsigned char stride;
    unsigned char dim;
    int density;
    int trace;
    int buffer[3];
};

union PacketPayload_R001314_1413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001314_1413_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001314_1413_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int delta_58 = local_arr[aux % 3];
    acc = (acc + delta_58 * 2) & 127;
    int window_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_97) & 63;
    acc ^= aux;
    int bound_47 = 0;
    for (int k = 0; k < 3; k++) {
        bound_47 = (bound_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_47) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_1(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int anchor_85 = local_arr[aux % 3];
    acc = (acc + anchor_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001314_1413_2(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_10 = (aux + st.buffer[1]) & 3;
    switch (threshold_10) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_3(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int stride_72 = local_arr[aux % 3];
    acc = (acc + stride_72 * 2) & 127;
    int cursor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_75 > 25) {
        acc = (acc + cursor_75 * 2 + 5) & 127;
        aux ^= (cursor_75 & 15);
    } else {
        acc = (acc - cursor_75 + 11) & 127;
        aux += 3;
    }
    int coefficient_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001314_1413_4(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int window_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_10) & 63;
    acc ^= aux;
    int accumulator_90 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_90 = (accumulator_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_90) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_35 = local_arr[aux % 3];
    acc = (acc + pivot_35 * 2) & 127;
    int window_91 = (aux + st.buffer[1]) & 3;
    switch (window_91) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_5(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int vector_29 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_29 > 45) {
        acc = (acc + vector_29 * 2 + 5) & 127;
        aux ^= (vector_29 & 15);
    } else {
        acc = (acc - vector_29 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_74 = local_arr[aux % 3];
    acc = (acc + offset_74 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001314_1413_6(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_56 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_56 > 44) {
        acc = (acc + tracker_56 * 2 + 5) & 127;
        aux ^= (tracker_56 & 15);
    } else {
        acc = (acc - tracker_56 + 11) & 127;
        aux += 3;
    }
    int stride_54 = 0;
    for (int k = 0; k < 3; k++) {
        stride_54 = (stride_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_54) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_7(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int scale_96 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_96 > 47) {
        acc = (acc + scale_96 * 2 + 5) & 127;
        aux ^= (scale_96 & 15);
    } else {
        acc = (acc - scale_96 + 11) & 127;
        aux += 3;
    }
    int residue_42 = (aux + st.buffer[1]) & 3;
    switch (residue_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001314_1413_8(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int pivot_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_21) & 63;
    acc ^= aux;
    int stride_91 = 0;
    for (int k = 0; k < 2; k++) {
        stride_91 = (stride_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_89) & 63;
    acc ^= aux;
    int scale_90 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_90 > 41) {
        acc = (acc + scale_90 * 2 + 5) & 127;
        aux ^= (scale_90 & 15);
    } else {
        acc = (acc - scale_90 + 11) & 127;
        aux += 3;
    }
    int scale_81 = 0;
    for (int k = 0; k < 2; k++) {
        scale_81 = (scale_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_81) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int offset_59 = local_arr[aux % 3];
    acc = (acc + offset_59 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_78 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_78 > 30) {
        acc = (acc + scale_78 * 2 + 5) & 127;
        aux ^= (scale_78 & 15);
    } else {
        acc = (acc - scale_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int factor_32 = 0;
    for (int k = 0; k < 3; k++) {
        factor_32 = (factor_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_32) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_72 = local_arr[aux % 3];
    acc = (acc + tally_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001314_1413_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int parity_97 = local_arr[aux % 3];
    acc = (acc + parity_97 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_44 = (aux + st.buffer[1]) & 3;
    switch (vector_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_74 = 0;
    for (int k = 0; k < 3; k++) {
        margin_74 = (margin_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_74) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int accumulator_34 = local_arr[aux % 3];
    acc = (acc + accumulator_34 * 2) & 127;
    int tracker_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001314_1413_14(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_21 = 0;
    for (int k = 0; k < 3; k++) {
        phase_21 = (phase_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_21) & 127;
    }
    int threshold_94 = (aux + st.buffer[1]) & 3;
    switch (threshold_94) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001314_1413_15(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_39 = (aux + st.buffer[1]) & 3;
    switch (factor_39) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_14) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_97 = local_arr[aux % 3];
    acc = (acc + bound_97 * 2) & 127;
    int index_reg_75 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_75 = (index_reg_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_75) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int vector_41 = 0;
    for (int k = 0; k < 2; k++) {
        vector_41 = (vector_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_41) & 127;
    }
    int damping_12 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_12 > 31) {
        acc = (acc + damping_12 * 2 + 5) & 127;
        aux ^= (damping_12 & 15);
    } else {
        acc = (acc - damping_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001314_1413_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int tally_13 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_13 > 20) {
        acc = (acc + tally_13 * 2 + 5) & 127;
        aux ^= (tally_13 & 15);
    } else {
        acc = (acc - tally_13 + 11) & 127;
        aux += 3;
    }
    int delta_63 = 0;
    for (int k = 0; k < 3; k++) {
        delta_63 = (delta_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_63) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_81 = local_arr[aux % 3];
    acc = (acc + damping_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001314_1413_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int offset_48 = (aux + st.buffer[1]) & 3;
    switch (offset_48) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_95 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_95 = (index_reg_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_95) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001314_0;
    int sec_r001314_1;
    int sec_r001314_2;
    int sec_r001314_3;
    int sec_r001314_4;
    int sec_r001314_5;
    int sec_r001314_6;
    int sec_r001314_7;
    int sec_r001314_8;
    int sec_r001314_9;
    int sec_r001314_10;
    int sec_r001314_11;
    int sec_r001314_12;
    int sec_r001314_13;
    int sec_r001314_14;
    int sec_r001314_15;
    int sec_r001314_16;
    int sec_r001314_17;
    int sec_r001314_18;
    int sec_r001314_19;
    int pub_r001314_0;
    int pub_r001314_1;
    int pub_r001314_2;
    int pub_r001314_3;
    int pub_r001314_4;
    int pub_r001314_5;
    int pub_r001314_6;
    int pub_r001314_7;
    int pub_r001314_8;
    int pub_r001314_9;
    int pub_r001314_10;
    int pub_r001314_11;
    int pub_r001314_12;
    int pub_r001314_13;
    int pub_r001314_14;
    int pub_r001314_15;
    int pub_r001314_16;
    int pub_r001314_17;
    int pub_r001314_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001314_0 >= -100 && pub_r001314_0 <= 100);
    __CPROVER_assume(pub_r001314_1 >= -100 && pub_r001314_1 <= 100);
    __CPROVER_assume(pub_r001314_2 >= -100 && pub_r001314_2 <= 100);
    __CPROVER_assume(pub_r001314_3 >= -100 && pub_r001314_3 <= 100);
    __CPROVER_assume(pub_r001314_4 >= -100 && pub_r001314_4 <= 100);
    __CPROVER_assume(pub_r001314_5 >= -100 && pub_r001314_5 <= 100);
    __CPROVER_assume(pub_r001314_6 >= -100 && pub_r001314_6 <= 100);
    __CPROVER_assume(pub_r001314_7 >= -100 && pub_r001314_7 <= 100);
    __CPROVER_assume(pub_r001314_8 >= -100 && pub_r001314_8 <= 100);
    __CPROVER_assume(pub_r001314_9 >= -100 && pub_r001314_9 <= 100);
    __CPROVER_assume(pub_r001314_10 >= -100 && pub_r001314_10 <= 100);
    __CPROVER_assume(pub_r001314_11 >= -100 && pub_r001314_11 <= 100);
    __CPROVER_assume(pub_r001314_12 >= -100 && pub_r001314_12 <= 100);
    __CPROVER_assume(pub_r001314_13 >= -100 && pub_r001314_13 <= 100);
    __CPROVER_assume(pub_r001314_14 >= -100 && pub_r001314_14 <= 100);
    __CPROVER_assume(pub_r001314_15 >= -100 && pub_r001314_15 <= 100);
    __CPROVER_assume(pub_r001314_16 >= -100 && pub_r001314_16 <= 100);
    __CPROVER_assume(pub_r001314_17 >= -100 && pub_r001314_17 <= 100);
    __CPROVER_assume(pub_r001314_18 >= -100 && pub_r001314_18 <= 100);
    __CPROVER_assume(sec_r001314_0 >= 0 && sec_r001314_0 <= 255);
    __CPROVER_assume(sec_r001314_1 >= 0 && sec_r001314_1 <= 255);
    __CPROVER_assume(sec_r001314_2 >= 0 && sec_r001314_2 <= 255);
    __CPROVER_assume(sec_r001314_3 >= 0 && sec_r001314_3 <= 255);
    __CPROVER_assume(sec_r001314_4 >= 0 && sec_r001314_4 <= 255);
    __CPROVER_assume(sec_r001314_5 >= 0 && sec_r001314_5 <= 255);
    __CPROVER_assume(sec_r001314_6 >= 0 && sec_r001314_6 <= 255);
    __CPROVER_assume(sec_r001314_7 >= 0 && sec_r001314_7 <= 255);
    __CPROVER_assume(sec_r001314_8 >= 0 && sec_r001314_8 <= 255);
    __CPROVER_assume(sec_r001314_9 >= 0 && sec_r001314_9 <= 255);
    __CPROVER_assume(sec_r001314_10 >= 0 && sec_r001314_10 <= 255);
    __CPROVER_assume(sec_r001314_11 >= 0 && sec_r001314_11 <= 255);
    __CPROVER_assume(sec_r001314_12 >= 0 && sec_r001314_12 <= 255);
    __CPROVER_assume(sec_r001314_13 >= 0 && sec_r001314_13 <= 255);
    __CPROVER_assume(sec_r001314_14 >= 0 && sec_r001314_14 <= 255);
    __CPROVER_assume(sec_r001314_15 >= 0 && sec_r001314_15 <= 255);
    __CPROVER_assume(sec_r001314_16 >= 0 && sec_r001314_16 <= 255);
    __CPROVER_assume(sec_r001314_17 >= 0 && sec_r001314_17 <= 255);
    __CPROVER_assume(sec_r001314_18 >= 0 && sec_r001314_18 <= 255);
    __CPROVER_assume(sec_r001314_19 >= 0 && sec_r001314_19 <= 255);

    struct FilterState_R001314_1413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001314_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001314_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001314_0 + 7) & 15;
    struct MatrixBlock_R001314_1413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001314_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001314_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001314_0 + 9) & 15;

    union PacketPayload_R001314_1413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001314_1413_0(sec_r001314_0, sec_r001314_1, pub_r001314_2, pub_r001314_3, pub_r001314_4);
    int helper_flow_1 = fn_R001314_1413_1(sec_r001314_1, pub_r001314_2, pub_r001314_3);
    int helper_flow_2 = fn_R001314_1413_2(sec_r001314_2, sec_r001314_3, pub_r001314_4);
    int helper_flow_3 = fn_R001314_1413_3(sec_r001314_3, pub_r001314_4);
    int helper_flow_4 = fn_R001314_1413_4(sec_r001314_4, sec_r001314_5, pub_r001314_6);
    int helper_flow_5 = fn_R001314_1413_5(sec_r001314_5, pub_r001314_6, pub_r001314_7);
    int helper_flow_6 = fn_R001314_1413_6(sec_r001314_6, pub_r001314_7);
    int helper_flow_7 = fn_R001314_1413_7(sec_r001314_7, pub_r001314_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001314_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_2 * 3) + pub_r001314_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_1) & 255;
    out_sink = (out_sink + stage_v_1 * 2) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_6 * 3) + pub_r001314_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001314_15 * 3) + pub_r001314_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_3) & 255;
    out_sink = (out_sink + stage_v_3 * 2) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001314_19 * 3) + pub_r001314_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_3 * 3) + pub_r001314_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001314_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_3 * 3) + pub_r001314_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001314_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001314_1 * 3) + pub_r001314_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001314_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001314_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_1 * 3) + pub_r001314_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001314_2 * 3) + pub_r001314_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001314_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001314_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001314_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001314_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_6 * 3) + pub_r001314_3 + 29) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001314_2 * 3) + pub_r001314_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001314_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001314_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_5 * 3) + pub_r001314_4 + 15) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001314_15 * 3) + pub_r001314_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001314_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001314_1 * 3) + pub_r001314_14 + 41) & 127;
    sec_accum = (sec_accum + stage_v_25) & 255;
    out_sink = (out_sink + stage_v_25 * 2) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_6 * 3) + pub_r001314_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26 * 2) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001314_19 * 3) + pub_r001314_16 + 12) & 127;
    sec_accum = (sec_accum + stage_v_27) & 255;
    out_sink = (out_sink + stage_v_27 * 2) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001314_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001314_6 * 3) + pub_r001314_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29 * 2) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001314_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001314_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_1 * 3) + pub_r001314_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001314_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001314_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001314_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001314_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001314_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_23 * 3) + pub_r001314_13 + 31) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38 * 2) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001314_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001314_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((helper_flow_0 * 3) + pub_r001314_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001314_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001314_4 * 3) + pub_r001314_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001314_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001314_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_18 * 3) + pub_r001314_6 + 38) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46 * 2) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_25 * 3) + pub_r001314_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001314_13 * 3) + pub_r001314_4 + 25) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001314_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001314_4 * 3) + pub_r001314_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_1 * 3) + pub_r001314_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001314_14 * 3) + pub_r001314_18 + 17) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_38 * 3) + pub_r001314_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53 * 2) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001314_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001314_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001314_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001314_10 * 3) + pub_r001314_13 + 34) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001314_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001314_9 * 3) + pub_r001314_18 + 8) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59 * 2) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001314_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001314_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001314_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001314_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001314_9 * 3) + pub_r001314_0 + 19) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001314_0 * 3) + pub_r001314_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001314_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001314_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_57 * 3) + pub_r001314_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_19 * 3) + pub_r001314_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69 * 2) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_69 * 3) + pub_r001314_16 + 18) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70 * 2) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001314_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_25 * 3) + pub_r001314_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001314_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001314_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001314_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001314_9 * 3) + pub_r001314_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76 * 2) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001314_17 * 3) + pub_r001314_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001314_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001314_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001314_11 * 3) + pub_r001314_18 + 31) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80 * 2) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_12 * 3) + pub_r001314_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81 * 2) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001314_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_9 * 3) + pub_r001314_18 + 18) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001314_18 * 3) + pub_r001314_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84 * 2) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001314_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001314_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001314_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001314_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001314_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_81 * 3) + pub_r001314_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_12 * 3) + pub_r001314_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001314_14 * 3) + pub_r001314_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_90 * 3) + pub_r001314_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001314_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001314_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001314_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001314_9 * 3) + pub_r001314_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001314_8 * 3) + pub_r001314_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001314_10 * 3) + pub_r001314_8 + 39) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_5 * 3) + pub_r001314_8 + 5) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_100 * 3) + pub_r001314_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001314_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((helper_flow_0 * 3) + pub_r001314_3 + 31) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103 * 2) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001314_1 * 3) + pub_r001314_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001314_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_12 * 3) + pub_r001314_3 + 9) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001314_18 * 3) + pub_r001314_1 + 15) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107 * 2) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001314_14 * 3) + pub_r001314_12 + 26) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001314_12 * 3) + pub_r001314_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r001314_7 * 3) + pub_r001314_15 + 35) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_41 * 3) + pub_r001314_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001314_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_90 * 3) + pub_r001314_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001314_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001314_5 * 3) + pub_r001314_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115 * 2) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_27 * 3) + pub_r001314_2 + 39) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001314_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_72 * 3) + pub_r001314_12 + 36) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118 * 2) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001314_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_77 * 3) + pub_r001314_3 + 13) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_48 * 3) + pub_r001314_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001314_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_113 * 3) + pub_r001314_2 + 31) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123 * 2) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001314_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001314_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001314_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_19 * 3) + pub_r001314_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127 * 2) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((helper_flow_7 * 3) + pub_r001314_17 + 11) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001314_6 * 3) + pub_r001314_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_97 * 3) + pub_r001314_2 + 38) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r001314_3 * 3) + pub_r001314_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001314_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001314_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_9 * 3) + pub_r001314_13 + 9) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134 * 2) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_2 * 3) + pub_r001314_10 + 45) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001314_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_107 * 3) + pub_r001314_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137 * 2) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_57 * 3) + pub_r001314_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138 * 2) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_5 * 3) + pub_r001314_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_130 * 3) + pub_r001314_10 + 41) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140 * 2) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((helper_flow_0 * 3) + pub_r001314_3 + 18) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_113 * 3) + pub_r001314_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001314_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001314_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001314_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001314_8 * 3) + pub_r001314_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_5 * 3) + pub_r001314_4 + 34) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147 * 2) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_32 * 3) + pub_r001314_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001314_8 * 3) + pub_r001314_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149 * 2) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_81 * 3) + pub_r001314_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001314_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001314_3 * 3) + pub_r001314_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_108 * 3) + pub_r001314_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153 * 2) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001314_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001314_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001314_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_129 * 3) + pub_r001314_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157 * 2) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_68 * 3) + pub_r001314_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_142 * 3) + pub_r001314_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001314_11 * 3) + pub_r001314_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_123 * 3) + pub_r001314_2 + 16) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_65 * 3) + pub_r001314_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162 * 2) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r001314_2 * 3) + pub_r001314_18 + 31) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163 * 2) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_134 * 3) + pub_r001314_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_128 * 3) + pub_r001314_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((helper_flow_3 * 3) + pub_r001314_15 + 11) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_101 * 3) + pub_r001314_8 + 35) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167 * 2) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001314_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001314_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001314_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001314_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001314_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_116 * 3) + pub_r001314_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173 * 2) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001314_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001314_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001314_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001314_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_164 * 3) + pub_r001314_17 + 44) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_109 * 3) + pub_r001314_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_178 * 3) + pub_r001314_3 + 45) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_178 * 3) + pub_r001314_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181 * 2) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_77 * 3) + pub_r001314_7 + 37) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_150 * 3) + pub_r001314_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183 * 2) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001314_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001314_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_131 * 3) + pub_r001314_14 + 3) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001314_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001314_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001314_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r001314_16 * 3) + pub_r001314_9 + 33) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_64 * 3) + pub_r001314_15 + 10) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_68 * 3) + pub_r001314_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192 * 2) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_76 * 3) + pub_r001314_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001314_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((helper_flow_3 * 3) + pub_r001314_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((helper_flow_6 * 3) + pub_r001314_12 + 25) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001314_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_59 * 3) + pub_r001314_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198 * 2) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001314_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_137 * 3) + pub_r001314_6 + 25) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200 * 2) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_147 * 3) + pub_r001314_18 + 33) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((helper_flow_6 * 3) + pub_r001314_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_22 * 3) + pub_r001314_0 + 45) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203 * 2) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001314_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_202 * 3) + pub_r001314_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_146 * 3) + pub_r001314_18 + 20) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206 * 2) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r001314_19 * 3) + pub_r001314_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207 * 2) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001314_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001314_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001314_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((helper_flow_4 * 3) + pub_r001314_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211 * 2) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001314_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_65 * 3) + pub_r001314_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001314_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_110 * 3) + pub_r001314_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001314_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001314_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001314_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001314_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_163 * 3) + pub_r001314_16 + 5) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220 * 2) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_77 * 3) + pub_r001314_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r001314_11 * 3) + pub_r001314_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222 * 2) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001314_10 * 3) + pub_r001314_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_148 * 3) + pub_r001314_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_38 * 3) + pub_r001314_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225 * 2) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001314_12 * 3) + pub_r001314_17 + 14) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_12 * 3) + pub_r001314_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001314_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_19 * 3) + pub_r001314_6 + 34) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001314_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001314_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001314_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001314_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001314_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001314_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001314_16 * 3) + pub_r001314_18 + 22) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001314_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001314_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((sec_r001314_18 * 3) + pub_r001314_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_224 * 3) + pub_r001314_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240 * 2) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_195 * 3) + pub_r001314_11 + 39) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241 * 2) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001314_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001314_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001314_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001314_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001314_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001314_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001314_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001314_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001314_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_127 * 3) + pub_r001314_16 + 24) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001314_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001314_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_46 * 3) + pub_r001314_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001314_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_26 * 3) + pub_r001314_9 + 26) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_131 * 3) + pub_r001314_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257 * 2) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001314_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_101 * 3) + pub_r001314_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001314_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001314_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_29 * 3) + pub_r001314_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_68 * 3) + pub_r001314_17 + 43) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263 * 2) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_101 * 3) + pub_r001314_18 + 20) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_134 * 3) + pub_r001314_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265 * 2) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_161 * 3) + pub_r001314_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001314_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001314_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_181 * 3) + pub_r001314_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_269 * 3) + pub_r001314_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_183 * 3) + pub_r001314_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001314_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_77 * 3) + pub_r001314_16 + 27) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001314_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((helper_flow_2 * 3) + pub_r001314_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_93 * 3) + pub_r001314_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001314_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001314_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_254 * 3) + pub_r001314_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((helper_flow_6 * 3) + pub_r001314_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_158 * 3) + pub_r001314_1 + 34) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281 * 2) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_157 * 3) + pub_r001314_2 + 13) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282 * 2) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_158 * 3) + pub_r001314_11 + 25) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283 * 2) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001314_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_203 * 3) + pub_r001314_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_25 * 3) + pub_r001314_12 + 22) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_5 * 3) + pub_r001314_17 + 33) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287 * 2) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001314_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001314_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_140 * 3) + pub_r001314_18 + 15) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001314_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_64 * 3) + pub_r001314_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001314_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001314_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_292 * 3) + pub_r001314_5 + 43) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r001314_15 * 3) + pub_r001314_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001314_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001314_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001314_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001314_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001314_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001314_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_150 * 3) + pub_r001314_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((sec_r001314_5 * 3) + pub_r001314_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_26 * 3) + pub_r001314_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_160 * 3) + pub_r001314_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306 * 2) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_32 * 3) + pub_r001314_18 + 4) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001314_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001314_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_200 * 3) + pub_r001314_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001314_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_165 * 3) + pub_r001314_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312 * 2) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001314_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001314_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_275 * 3) + pub_r001314_2 + 22) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001314_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001314_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001314_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001314_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001314_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_152 * 3) + pub_r001314_18 + 27) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_271 * 3) + pub_r001314_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001314_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001314_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_265 * 3) + pub_r001314_17 + 40) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325 * 2) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_111 * 3) + pub_r001314_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((helper_flow_7 * 3) + pub_r001314_0 + 10) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001314_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001314_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_206 * 3) + pub_r001314_16 + 45) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001314_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001314_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001314_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_257 * 3) + pub_r001314_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_3 * 3) + pub_r001314_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335 * 2) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001314_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_190 * 3) + pub_r001314_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337 * 2) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001314_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_68 * 3) + pub_r001314_3 + 11) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339 * 2) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_262 * 3) + pub_r001314_6 + 36) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001314_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001314_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_285 * 3) + pub_r001314_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001314_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_158 * 3) + pub_r001314_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001314_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001314_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001314_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_53 * 3) + pub_r001314_6 + 43) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_137 * 3) + pub_r001314_16 + 5) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001314_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_72 * 3) + pub_r001314_4 + 19) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_107 * 3) + pub_r001314_4 + 5) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_203 * 3) + pub_r001314_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354 * 2) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001314_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001314_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_335 * 3) + pub_r001314_17 + 40) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001314_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_83 * 3) + pub_r001314_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_52 * 3) + pub_r001314_9 + 26) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001314_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001314_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001314_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_134 * 3) + pub_r001314_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364 * 2) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001314_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_337 * 3) + pub_r001314_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_68 * 3) + pub_r001314_14 + 39) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001314_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001314_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001314_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_1 * 3) + pub_r001314_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_193 * 3) + pub_r001314_10 + 39) & 127;
    sec_accum = (sec_accum + stage_v_372) & 255;
    out_sink = (out_sink + stage_v_372 * 2) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_312 * 3) + pub_r001314_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_222 * 3) + pub_r001314_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001314_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001314_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001314_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001314_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_134 * 3) + pub_r001314_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_352 * 3) + pub_r001314_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380 * 2) & 255;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_129 * 3) + pub_r001314_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001314_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_304 * 3) + pub_r001314_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_381 * 3) + pub_r001314_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_384) & 255;
    out_sink = (out_sink + stage_v_384 * 2) & 255;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_353 * 3) + pub_r001314_1 + 26) & 127;
    sec_accum = (sec_accum + stage_v_385) & 255;
    out_sink = (out_sink + stage_v_385 * 2) & 255;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001314_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001314_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001314_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001314_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001314_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001314_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_140 * 3) + pub_r001314_15 + 19) & 127;
    sec_accum = (sec_accum + stage_v_392) & 255;
    out_sink = (out_sink + stage_v_392 * 2) & 255;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_46 * 3) + pub_r001314_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_393) & 255;
    out_sink = (out_sink + stage_v_393 * 2) & 255;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_305 * 3) + pub_r001314_11 + 18) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001314_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001314_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001314_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001314_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001314_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001314_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001314_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_190 * 3) + pub_r001314_17 + 6) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_221 * 3) + pub_r001314_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_1 * 3) + pub_r001314_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001314_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_50 * 3) + pub_r001314_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_406) & 255;
    out_sink = (out_sink + stage_v_406 * 2) & 255;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_196 * 3) + pub_r001314_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_407) & 255;
    out_sink = (out_sink + stage_v_407 * 2) & 255;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001314_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001314_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((helper_flow_3 * 3) + pub_r001314_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001314_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_141 * 3) + pub_r001314_12 + 35) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_101 * 3) + pub_r001314_0 + 44) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001314_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001314_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001314_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001314_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001314_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_100 * 3) + pub_r001314_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_413 * 3) + pub_r001314_13 + 42) & 127;
    sec_accum = (sec_accum + stage_v_420) & 255;
    out_sink = (out_sink + stage_v_420 * 2) & 255;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001314_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001314_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001314_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001314_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_32 * 3) + pub_r001314_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001314_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001314_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001314_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_72 * 3) + pub_r001314_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_429) & 255;
    out_sink = (out_sink + stage_v_429 * 2) & 255;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_113 * 3) + pub_r001314_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_265 * 3) + pub_r001314_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_431) & 255;
    out_sink = (out_sink + stage_v_431 * 2) & 255;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_334 * 3) + pub_r001314_10 + 20) & 127;
    sec_accum = (sec_accum + stage_v_432) & 255;
    out_sink = (out_sink + stage_v_432 * 2) & 255;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_256 * 3) + pub_r001314_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_433) & 255;
    out_sink = (out_sink + stage_v_433 * 2) & 255;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_72 * 3) + pub_r001314_5 + 25) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001314_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_99 * 3) + pub_r001314_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001314_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001314_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_159 * 3) + pub_r001314_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((helper_flow_3 * 3) + pub_r001314_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001314_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((sec_r001314_2 * 3) + pub_r001314_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_196 * 3) + pub_r001314_18 + 15) & 127;
    sec_accum = (sec_accum + stage_v_443) & 255;
    out_sink = (out_sink + stage_v_443 * 2) & 255;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001314_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_103 * 3) + pub_r001314_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_445) & 255;
    out_sink = (out_sink + stage_v_445 * 2) & 255;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001314_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001314_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_221 * 3) + pub_r001314_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_149 * 3) + pub_r001314_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_101 * 3) + pub_r001314_6 + 18) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001314_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_276 * 3) + pub_r001314_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_452) & 255;
    out_sink = (out_sink + stage_v_452 * 2) & 255;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((helper_flow_7 * 3) + pub_r001314_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_453) & 255;
    out_sink = (out_sink + stage_v_453 * 2) & 255;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001314_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001314_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_27 * 3) + pub_r001314_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((sec_r001314_15 * 3) + pub_r001314_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_457) & 255;
    out_sink = (out_sink + stage_v_457 * 2) & 255;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001314_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001314_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_41 * 3) + pub_r001314_12 + 45) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001314_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_110 * 3) + pub_r001314_2 + 6) & 127;
    sec_accum = (sec_accum + stage_v_462) & 255;
    out_sink = (out_sink + stage_v_462 * 2) & 255;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_350 * 3) + pub_r001314_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_463) & 255;
    out_sink = (out_sink + stage_v_463 * 2) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
