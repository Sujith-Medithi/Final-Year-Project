/*
 * Benchmark Program: R001086
 * Security Family: implicit_flow
 * Generator Seed: 608613
 * High Inputs: 24 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001086_8613_0 {
    int determinant;
    int density;
    unsigned char scale;
    int dim;
    int buffer[3];
};

struct SensorNode_R001086_8613_1 {
    short calib;
    short gain;
    short threshold;
    short offset;
    int buffer[3];
};

union ColorPixel_R001086_8613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001086_8613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001086_8613_0(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int window_89 = local_arr[aux % 3];
    acc = (acc + window_89 * 2) & 127;
    int residue_64 = (aux + st.buffer[1]) & 3;
    switch (residue_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_85 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_85 > 13) {
        acc = (acc + tracker_85 * 2 + 5) & 127;
        aux ^= (tracker_85 & 15);
    } else {
        acc = (acc - tracker_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int cursor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_41) & 63;
    acc ^= aux;
    int threshold_20 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_20 > 26) {
        acc = (acc + threshold_20 * 2 + 5) & 127;
        aux ^= (threshold_20 & 15);
    } else {
        acc = (acc - threshold_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_2(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_47 = (aux + st.buffer[1]) & 3;
    switch (residue_47) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_10 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_10 > 23) {
        acc = (acc + residue_10 * 2 + 5) & 127;
        aux ^= (residue_10 & 15);
    } else {
        acc = (acc - residue_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_71 = (aux + st.buffer[1]) & 3;
    switch (weight_71) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int tracker_52 = local_arr[aux % 3];
    acc = (acc + tracker_52 * 2) & 127;
    int offset_45 = 0;
    for (int k = 0; k < 2; k++) {
        offset_45 = (offset_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_5(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_82 = 0;
    for (int k = 0; k < 2; k++) {
        residue_82 = (residue_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_82) & 127;
    }
    int tally_41 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_41 > 50) {
        acc = (acc + tally_41 * 2 + 5) & 127;
        aux ^= (tally_41 & 15);
    } else {
        acc = (acc - tally_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int stride_82 = (aux + st.buffer[1]) & 3;
    switch (stride_82) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_13) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_47 = local_arr[aux % 3];
    acc = (acc + tracker_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001086_8613_7(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int phase_44 = 0;
    for (int k = 0; k < 3; k++) {
        phase_44 = (phase_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_44) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_21 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_21 > 28) {
        acc = (acc + parity_21 * 2 + 5) & 127;
        aux ^= (parity_21 & 15);
    } else {
        acc = (acc - parity_21 + 11) & 127;
        aux += 3;
    }
    int stride_94 = (aux + st.buffer[1]) & 3;
    switch (stride_94) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int factor_91 = 0;
    for (int k = 0; k < 2; k++) {
        factor_91 = (factor_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_91) & 127;
    }
    int cursor_78 = (aux + st.buffer[1]) & 3;
    switch (cursor_78) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001086_8613_9(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int stride_59 = 0;
    for (int k = 0; k < 2; k++) {
        stride_59 = (stride_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_59) & 127;
    }
    int pivot_13 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_13 > 23) {
        acc = (acc + pivot_13 * 2 + 5) & 127;
        aux ^= (pivot_13 & 15);
    } else {
        acc = (acc - pivot_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int scale_61 = local_arr[aux % 3];
    acc = (acc + scale_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001086_8613_11(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int window_58 = 0;
    for (int k = 0; k < 2; k++) {
        window_58 = (window_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_58) & 127;
    }
    int metric_33 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_33 > 23) {
        acc = (acc + metric_33 * 2 + 5) & 127;
        aux ^= (metric_33 & 15);
    } else {
        acc = (acc - metric_33 + 11) & 127;
        aux += 3;
    }
    int index_reg_44 = (aux + st.buffer[1]) & 3;
    switch (index_reg_44) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_12(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_58) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_37 = local_arr[aux % 3];
    acc = (acc + residue_37 * 2) & 127;
    int threshold_39 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_39 > 20) {
        acc = (acc + threshold_39 * 2 + 5) & 127;
        aux ^= (threshold_39 & 15);
    } else {
        acc = (acc - threshold_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_13(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int window_68 = 0;
    for (int k = 0; k < 3; k++) {
        window_68 = (window_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_68) & 127;
    }
    int factor_56 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_56 > 12) {
        acc = (acc + factor_56 * 2 + 5) & 127;
        aux ^= (factor_56 & 15);
    } else {
        acc = (acc - factor_56 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_96 = local_arr[aux % 3];
    acc = (acc + threshold_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001086_8613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int weight_55 = 0;
    for (int k = 0; k < 3; k++) {
        weight_55 = (weight_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_55) & 127;
    }
    int sample_83 = (aux + st.buffer[1]) & 3;
    switch (sample_83) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int window_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_53) & 63;
    acc ^= aux;
    int accumulator_75 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_75 > 26) {
        acc = (acc + accumulator_75 * 2 + 5) & 127;
        aux ^= (accumulator_75 & 15);
    } else {
        acc = (acc - accumulator_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_30 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_30 = (pivot_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_30) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_93 = local_arr[aux % 3];
    acc = (acc + sample_93 * 2) & 127;
    int cursor_15 = (aux + st.buffer[1]) & 3;
    switch (cursor_15) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_17(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_99 > 26) {
        acc = (acc + anchor_99 * 2 + 5) & 127;
        aux ^= (anchor_99 & 15);
    } else {
        acc = (acc - anchor_99 + 11) & 127;
        aux += 3;
    }
    int damping_90 = 0;
    for (int k = 0; k < 2; k++) {
        damping_90 = (damping_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_52) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_95 = local_arr[aux % 3];
    acc = (acc + phase_95 * 2) & 127;
    int checksum_23 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_23 = (checksum_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_23) & 127;
    }
    int window_42 = (st.buffer[0] * 3 + aux) & 63;
    if (window_42 > 46) {
        acc = (acc + window_42 * 2 + 5) & 127;
        aux ^= (window_42 & 15);
    } else {
        acc = (acc - window_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_19(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int index_reg_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_75) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_50 = local_arr[aux % 3];
    acc = (acc + anchor_50 * 2) & 127;
    int margin_43 = 0;
    for (int k = 0; k < 3; k++) {
        margin_43 = (margin_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_43) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_78) & 63;
    acc ^= aux;
    int tracker_66 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_66 > 36) {
        acc = (acc + tracker_66 * 2 + 5) & 127;
        aux ^= (tracker_66 & 15);
    } else {
        acc = (acc - tracker_66 + 11) & 127;
        aux += 3;
    }
    int cursor_48 = (aux + st.buffer[1]) & 3;
    switch (cursor_48) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001086_8613_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001086_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_26 = (aux + st.buffer[1]) & 3;
    switch (stride_26) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_25 = local_arr[aux % 3];
    acc = (acc + quantum_25 * 2) & 127;
    int damping_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001086_8613_22(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int vector_95 = (aux + st.buffer[1]) & 3;
    switch (vector_95) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_41 = local_arr[aux % 3];
    acc = (acc + stride_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001086_8613_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001086_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int sample_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_73) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001086_0;
    int sec_r001086_1;
    int sec_r001086_2;
    int sec_r001086_3;
    int sec_r001086_4;
    int sec_r001086_5;
    int sec_r001086_6;
    int sec_r001086_7;
    int sec_r001086_8;
    int sec_r001086_9;
    int sec_r001086_10;
    int sec_r001086_11;
    int sec_r001086_12;
    int sec_r001086_13;
    int sec_r001086_14;
    int sec_r001086_15;
    int sec_r001086_16;
    int sec_r001086_17;
    int sec_r001086_18;
    int sec_r001086_19;
    int sec_r001086_20;
    int sec_r001086_21;
    int sec_r001086_22;
    int sec_r001086_23;
    int pub_r001086_0;
    int pub_r001086_1;
    int pub_r001086_2;
    int pub_r001086_3;
    int pub_r001086_4;
    int pub_r001086_5;
    int pub_r001086_6;
    int pub_r001086_7;
    int pub_r001086_8;
    int pub_r001086_9;
    int pub_r001086_10;
    int pub_r001086_11;
    int pub_r001086_12;
    int pub_r001086_13;
    int pub_r001086_14;
    int pub_r001086_15;
    int pub_r001086_16;
    int pub_r001086_17;
    int pub_r001086_18;
    int pub_r001086_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001086_0 >= -100 && pub_r001086_0 <= 100);
    __CPROVER_assume(pub_r001086_1 >= -100 && pub_r001086_1 <= 100);
    __CPROVER_assume(pub_r001086_2 >= -100 && pub_r001086_2 <= 100);
    __CPROVER_assume(pub_r001086_3 >= -100 && pub_r001086_3 <= 100);
    __CPROVER_assume(pub_r001086_4 >= -100 && pub_r001086_4 <= 100);
    __CPROVER_assume(pub_r001086_5 >= -100 && pub_r001086_5 <= 100);
    __CPROVER_assume(pub_r001086_6 >= -100 && pub_r001086_6 <= 100);
    __CPROVER_assume(pub_r001086_7 >= -100 && pub_r001086_7 <= 100);
    __CPROVER_assume(pub_r001086_8 >= -100 && pub_r001086_8 <= 100);
    __CPROVER_assume(pub_r001086_9 >= -100 && pub_r001086_9 <= 100);
    __CPROVER_assume(pub_r001086_10 >= -100 && pub_r001086_10 <= 100);
    __CPROVER_assume(pub_r001086_11 >= -100 && pub_r001086_11 <= 100);
    __CPROVER_assume(pub_r001086_12 >= -100 && pub_r001086_12 <= 100);
    __CPROVER_assume(pub_r001086_13 >= -100 && pub_r001086_13 <= 100);
    __CPROVER_assume(pub_r001086_14 >= -100 && pub_r001086_14 <= 100);
    __CPROVER_assume(pub_r001086_15 >= -100 && pub_r001086_15 <= 100);
    __CPROVER_assume(pub_r001086_16 >= -100 && pub_r001086_16 <= 100);
    __CPROVER_assume(pub_r001086_17 >= -100 && pub_r001086_17 <= 100);
    __CPROVER_assume(pub_r001086_18 >= -100 && pub_r001086_18 <= 100);
    __CPROVER_assume(pub_r001086_19 >= -100 && pub_r001086_19 <= 100);
    __CPROVER_assume(sec_r001086_0 >= 0 && sec_r001086_0 <= 255);
    __CPROVER_assume(sec_r001086_1 >= 0 && sec_r001086_1 <= 255);
    __CPROVER_assume(sec_r001086_2 >= 0 && sec_r001086_2 <= 255);
    __CPROVER_assume(sec_r001086_3 >= 0 && sec_r001086_3 <= 255);
    __CPROVER_assume(sec_r001086_4 >= 0 && sec_r001086_4 <= 255);
    __CPROVER_assume(sec_r001086_5 >= 0 && sec_r001086_5 <= 255);
    __CPROVER_assume(sec_r001086_6 >= 0 && sec_r001086_6 <= 255);
    __CPROVER_assume(sec_r001086_7 >= 0 && sec_r001086_7 <= 255);
    __CPROVER_assume(sec_r001086_8 >= 0 && sec_r001086_8 <= 255);
    __CPROVER_assume(sec_r001086_9 >= 0 && sec_r001086_9 <= 255);
    __CPROVER_assume(sec_r001086_10 >= 0 && sec_r001086_10 <= 255);
    __CPROVER_assume(sec_r001086_11 >= 0 && sec_r001086_11 <= 255);
    __CPROVER_assume(sec_r001086_12 >= 0 && sec_r001086_12 <= 255);
    __CPROVER_assume(sec_r001086_13 >= 0 && sec_r001086_13 <= 255);
    __CPROVER_assume(sec_r001086_14 >= 0 && sec_r001086_14 <= 255);
    __CPROVER_assume(sec_r001086_15 >= 0 && sec_r001086_15 <= 255);
    __CPROVER_assume(sec_r001086_16 >= 0 && sec_r001086_16 <= 255);
    __CPROVER_assume(sec_r001086_17 >= 0 && sec_r001086_17 <= 255);
    __CPROVER_assume(sec_r001086_18 >= 0 && sec_r001086_18 <= 255);
    __CPROVER_assume(sec_r001086_19 >= 0 && sec_r001086_19 <= 255);
    __CPROVER_assume(sec_r001086_20 >= 0 && sec_r001086_20 <= 255);
    __CPROVER_assume(sec_r001086_21 >= 0 && sec_r001086_21 <= 255);
    __CPROVER_assume(sec_r001086_22 >= 0 && sec_r001086_22 <= 255);
    __CPROVER_assume(sec_r001086_23 >= 0 && sec_r001086_23 <= 255);

    struct MatrixBlock_R001086_8613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001086_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001086_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001086_0 + 7) & 15;
    struct SensorNode_R001086_8613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001086_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001086_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001086_0 + 9) & 15;

    union ColorPixel_R001086_8613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001086_8613_0(sec_r001086_0, pub_r001086_1);
    int helper_flow_1 = fn_R001086_8613_1(sec_r001086_1, pub_r001086_2, pub_r001086_3, pub_r001086_4, pub_r001086_5);
    int helper_flow_2 = fn_R001086_8613_2(sec_r001086_2, sec_r001086_3, pub_r001086_4);
    int helper_flow_3 = fn_R001086_8613_3(sec_r001086_3, sec_r001086_4, pub_r001086_5, pub_r001086_6, pub_r001086_7);
    int helper_flow_4 = fn_R001086_8613_4(sec_r001086_4, pub_r001086_5, pub_r001086_6, pub_r001086_7);
    int helper_flow_5 = fn_R001086_8613_5(sec_r001086_5, sec_r001086_6, pub_r001086_7);
    int helper_flow_6 = fn_R001086_8613_6(sec_r001086_6, sec_r001086_7, pub_r001086_8, pub_r001086_9);
    int helper_flow_7 = fn_R001086_8613_7(sec_r001086_7, sec_r001086_8, pub_r001086_9);
    int helper_flow_8 = fn_R001086_8613_8(sec_r001086_8, pub_r001086_9, pub_r001086_10, pub_r001086_11, pub_r001086_12);
    int helper_flow_9 = fn_R001086_8613_9(sec_r001086_9, sec_r001086_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001086_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001086_19 + pub_r001086_18 * 2 + 8) & 127;
    if (stage_v_1 > 33) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001086_23 + pub_r001086_9 * 2 + 11) & 127;
    if (stage_v_2 > 59) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001086_13 + pub_r001086_17 * 2 + 14) & 127;
    if (stage_v_3 > 59) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001086_7 + pub_r001086_2 * 2 + 17) & 127;
    if (stage_v_4 > 60) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_4 + pub_r001086_7 * 2 + 20) & 127;
    if (stage_v_5 > 48) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001086_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001086_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001086_22 + pub_r001086_14 * 2 + 29) & 127;
    if (stage_v_8 > 54) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001086_14 + pub_r001086_17 * 2 + 32) & 127;
    if (stage_v_9 > 51) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001086_18 + pub_r001086_6 * 2 + 35) & 127;
    if (stage_v_10 > 47) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (stage_v_8 + pub_r001086_18 * 2 + 38) & 127;
    if (stage_v_11 > 34) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001086_1 + pub_r001086_11 * 2 + 41) & 127;
    if (stage_v_12 > 58) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_12 + pub_r001086_18 * 2 + 44) & 127;
    if (stage_v_13 > 42) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001086_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001086_12 + pub_r001086_11 * 2 + 50) & 127;
    if (stage_v_15 > 42) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_3 + pub_r001086_6 * 2 + 53) & 127;
    if (stage_v_16 > 27) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001086_15 + pub_r001086_6 * 2 + 56) & 127;
    if (stage_v_17 > 41) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001086_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001086_3 + pub_r001086_14 * 2 + 62) & 127;
    if (stage_v_19 > 37) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001086_21 + pub_r001086_2 * 2 + 65) & 127;
    if (stage_v_20 > 30) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001086_9 + pub_r001086_4 * 2 + 68) & 127;
    if (stage_v_21 > 28) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001086_21 + pub_r001086_19 * 2 + 71) & 127;
    if (stage_v_22 > 31) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001086_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_2 + pub_r001086_1 * 2 + 77) & 127;
    if (stage_v_24 > 21) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001086_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001086_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001086_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001086_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001086_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001086_3 + pub_r001086_4 * 2 + 95) & 127;
    if (stage_v_30 > 15) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_13 + pub_r001086_8 * 2 + 98) & 127;
    if (stage_v_31 > 36) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001086_17 + pub_r001086_3 * 2 + 101) & 127;
    if (stage_v_32 > 35) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_17 + pub_r001086_0 * 2 + 104) & 127;
    if (stage_v_33 > 22) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001086_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001086_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001086_21 + pub_r001086_16 * 2 + 113) & 127;
    if (stage_v_36 > 32) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001086_17 + pub_r001086_10 * 2 + 116) & 127;
    if (stage_v_37 > 44) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (helper_flow_6 + pub_r001086_16 * 2 + 119) & 127;
    if (stage_v_38 > 57) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001086_14 + pub_r001086_3 * 2 + 122) & 127;
    if (stage_v_39 > 56) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001086_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001086_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001086_23 + pub_r001086_3 * 2 + 131) & 127;
    if (stage_v_42 > 16) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001086_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001086_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001086_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001086_20 + pub_r001086_15 * 2 + 143) & 127;
    if (stage_v_46 > 18) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001086_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001086_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_21 + pub_r001086_17 * 2 + 152) & 127;
    if (stage_v_49 > 33) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001086_23 + pub_r001086_5 * 2 + 155) & 127;
    if (stage_v_50 > 48) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001086_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001086_4 + pub_r001086_4 * 2 + 161) & 127;
    if (stage_v_52 > 27) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001086_22 + pub_r001086_16 * 2 + 164) & 127;
    if (stage_v_53 > 50) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_15 + pub_r001086_13 * 2 + 167) & 127;
    if (stage_v_54 > 52) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_31 + pub_r001086_19 * 2 + 170) & 127;
    if (stage_v_55 > 15) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (helper_flow_8 + pub_r001086_17 * 2 + 173) & 127;
    if (stage_v_56 > 18) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001086_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001086_20 + pub_r001086_2 * 2 + 179) & 127;
    if (stage_v_58 > 36) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (helper_flow_4 + pub_r001086_5 * 2 + 182) & 127;
    if (stage_v_59 > 28) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001086_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001086_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001086_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001086_9 + pub_r001086_13 * 2 + 194) & 127;
    if (stage_v_63 > 59) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_3 + pub_r001086_15 * 2 + 197) & 127;
    if (stage_v_64 > 40) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001086_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r001086_18 + pub_r001086_5 * 2 + 203) & 127;
    if (stage_v_66 > 18) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_46 + pub_r001086_6 * 2 + 206) & 127;
    if (stage_v_67 > 60) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001086_20 + pub_r001086_10 * 2 + 209) & 127;
    if (stage_v_68 > 39) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001086_18 + pub_r001086_5 * 2 + 212) & 127;
    if (stage_v_69 > 46) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001086_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (helper_flow_0 + pub_r001086_11 * 2 + 218) & 127;
    if (stage_v_71 > 19) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_5 + pub_r001086_16 * 2 + 221) & 127;
    if (stage_v_72 > 20) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (helper_flow_4 + pub_r001086_4 * 2 + 224) & 127;
    if (stage_v_73 > 42) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001086_14 + pub_r001086_12 * 2 + 227) & 127;
    if (stage_v_74 > 19) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001086_0 + pub_r001086_6 * 2 + 230) & 127;
    if (stage_v_75 > 49) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_5 + pub_r001086_11 * 2 + 233) & 127;
    if (stage_v_76 > 19) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_11 + pub_r001086_19 * 2 + 236) & 127;
    if (stage_v_77 > 50) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001086_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001086_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (helper_flow_0 + pub_r001086_2 * 2 + 245) & 127;
    if (stage_v_80 > 26) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001086_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_50 + pub_r001086_3 * 2 + 251) & 127;
    if (stage_v_82 > 24) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_75 + pub_r001086_8 * 2 + 254) & 127;
    if (stage_v_83 > 43) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_49 + pub_r001086_7 * 2 + 257) & 127;
    if (stage_v_84 > 43) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001086_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001086_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_38 + pub_r001086_14 * 2 + 266) & 127;
    if (stage_v_87 > 34) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001086_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_20 + pub_r001086_11 * 2 + 272) & 127;
    if (stage_v_89 > 43) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001086_3 + pub_r001086_14 * 2 + 275) & 127;
    if (stage_v_90 > 56) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001086_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001086_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_59 + pub_r001086_1 * 2 + 284) & 127;
    if (stage_v_93 > 23) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r001086_9 + pub_r001086_9 * 2 + 287) & 127;
    if (stage_v_94 > 31) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_6 + pub_r001086_10 * 2 + 290) & 127;
    if (stage_v_95 > 15) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_87 + pub_r001086_11 * 2 + 293) & 127;
    if (stage_v_96 > 25) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_1 + pub_r001086_16 * 2 + 296) & 127;
    if (stage_v_97 > 57) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (helper_flow_8 + pub_r001086_13 * 2 + 299) & 127;
    if (stage_v_98 > 47) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_82 + pub_r001086_2 * 2 + 302) & 127;
    if (stage_v_99 > 22) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_36 + pub_r001086_0 * 2 + 305) & 127;
    if (stage_v_100 > 21) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001086_22 + pub_r001086_15 * 2 + 308) & 127;
    if (stage_v_101 > 16) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r001086_8 + pub_r001086_15 * 2 + 311) & 127;
    if (stage_v_102 > 42) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_77 + pub_r001086_1 * 2 + 314) & 127;
    if (stage_v_103 > 43) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_67 + pub_r001086_10 * 2 + 317) & 127;
    if (stage_v_104 > 55) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_42 + pub_r001086_9 * 2 + 320) & 127;
    if (stage_v_105 > 19) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_67 + pub_r001086_9 * 2 + 323) & 127;
    if (stage_v_106 > 24) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001086_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_2 + pub_r001086_12 * 2 + 329) & 127;
    if (stage_v_108 > 23) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_1 + pub_r001086_18 * 2 + 332) & 127;
    if (stage_v_109 > 31) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001086_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001086_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_95 + pub_r001086_8 * 2 + 341) & 127;
    if (stage_v_112 > 38) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (helper_flow_4 + pub_r001086_4 * 2 + 344) & 127;
    if (stage_v_113 > 43) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_39 + pub_r001086_17 * 2 + 347) & 127;
    if (stage_v_114 > 22) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001086_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_39 + pub_r001086_11 * 2 + 353) & 127;
    if (stage_v_116 > 27) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_21 + pub_r001086_8 * 2 + 356) & 127;
    if (stage_v_117 > 36) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_108 + pub_r001086_11 * 2 + 359) & 127;
    if (stage_v_118 > 37) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_98 + pub_r001086_14 * 2 + 362) & 127;
    if (stage_v_119 > 41) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001086_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_90 + pub_r001086_18 * 2 + 368) & 127;
    if (stage_v_121 > 32) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r001086_22 + pub_r001086_12 * 2 + 371) & 127;
    if (stage_v_122 > 54) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_84 + pub_r001086_9 * 2 + 374) & 127;
    if (stage_v_123 > 18) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001086_18 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_16 + pub_r001086_0 * 2 + 380) & 127;
    if (stage_v_125 > 29) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_11 + pub_r001086_12 * 2 + 383) & 127;
    if (stage_v_126 > 44) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001086_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_71 + pub_r001086_7 * 2 + 389) & 127;
    if (stage_v_128 > 57) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001086_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001086_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001086_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001086_7 + pub_r001086_13 * 2 + 401) & 127;
    if (stage_v_132 > 24) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001086_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_17 + pub_r001086_16 * 2 + 407) & 127;
    if (stage_v_134 > 15) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001086_23 + pub_r001086_18 * 2 + 410) & 127;
    if (stage_v_135 > 32) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_117 + pub_r001086_19 * 2 + 413) & 127;
    if (stage_v_136 > 59) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001086_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_42 + pub_r001086_1 * 2 + 419) & 127;
    if (stage_v_138 > 36) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001086_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_114 + pub_r001086_18 * 2 + 425) & 127;
    if (stage_v_140 > 53) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_74 + pub_r001086_5 * 2 + 428) & 127;
    if (stage_v_141 > 24) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_4 + pub_r001086_4 * 2 + 431) & 127;
    if (stage_v_142 > 42) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_32 + pub_r001086_9 * 2 + 434) & 127;
    if (stage_v_143 > 19) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_52 + pub_r001086_0 * 2 + 437) & 127;
    if (stage_v_144 > 43) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001086_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001086_18 + pub_r001086_6 * 2 + 443) & 127;
    if (stage_v_146 > 56) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001086_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001086_16 + pub_r001086_4 * 2 + 449) & 127;
    if (stage_v_148 > 22) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001086_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001086_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_126 + pub_r001086_19 * 2 + 458) & 127;
    if (stage_v_151 > 59) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r001086_7 + pub_r001086_14 * 2 + 461) & 127;
    if (stage_v_152 > 25) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001086_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001086_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001086_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001086_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (helper_flow_2 + pub_r001086_16 * 2 + 476) & 127;
    if (stage_v_157 > 56) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_138 + pub_r001086_8 * 2 + 479) & 127;
    if (stage_v_158 > 39) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001086_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001086_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_68 + pub_r001086_17 * 2 + 488) & 127;
    if (stage_v_161 > 31) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_103 + pub_r001086_19 * 2 + 491) & 127;
    if (stage_v_162 > 38) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (sec_r001086_7 + pub_r001086_6 * 2 + 494) & 127;
    if (stage_v_163 > 44) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001086_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_89 + pub_r001086_1 * 2 + 500) & 127;
    if (stage_v_165 > 43) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (sec_r001086_3 + pub_r001086_15 * 2 + 503) & 127;
    if (stage_v_166 > 31) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_157 + pub_r001086_13 * 2 + 506) & 127;
    if (stage_v_167 > 40) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001086_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_31 + pub_r001086_0 * 2 + 512) & 127;
    if (stage_v_169 > 22) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_19 + pub_r001086_17 * 2 + 515) & 127;
    if (stage_v_170 > 29) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001086_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (sec_r001086_23 + pub_r001086_6 * 2 + 521) & 127;
    if (stage_v_172 > 17) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_90 + pub_r001086_5 * 2 + 524) & 127;
    if (stage_v_173 > 34) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001086_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (helper_flow_1 + pub_r001086_8 * 2 + 530) & 127;
    if (stage_v_175 > 17) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001086_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_118 + pub_r001086_3 * 2 + 536) & 127;
    if (stage_v_177 > 25) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001086_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_84 + pub_r001086_13 * 2 + 542) & 127;
    if (stage_v_179 > 44) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001086_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_24 + pub_r001086_15 * 2 + 548) & 127;
    if (stage_v_181 > 48) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_20 + pub_r001086_18 * 2 + 551) & 127;
    if (stage_v_182 > 40) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (helper_flow_0 + pub_r001086_11 * 2 + 554) & 127;
    if (stage_v_183 > 60) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001086_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001086_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (sec_r001086_18 + pub_r001086_8 * 2 + 563) & 127;
    if (stage_v_186 > 29) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_179 + pub_r001086_6 * 2 + 566) & 127;
    if (stage_v_187 > 35) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_117 + pub_r001086_6 * 2 + 569) & 127;
    if (stage_v_188 > 17) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_8 + pub_r001086_11 * 2 + 572) & 127;
    if (stage_v_189 > 48) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_141 + pub_r001086_0 * 2 + 575) & 127;
    if (stage_v_190 > 16) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_105 + pub_r001086_13 * 2 + 578) & 127;
    if (stage_v_191 > 49) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001086_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_24 + pub_r001086_10 * 2 + 584) & 127;
    if (stage_v_193 > 18) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001086_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_3 + pub_r001086_9 * 2 + 590) & 127;
    if (stage_v_195 > 26) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_100 + pub_r001086_13 * 2 + 593) & 127;
    if (stage_v_196 > 20) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_169 + pub_r001086_3 * 2 + 596) & 127;
    if (stage_v_197 > 55) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001086_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_11 + pub_r001086_16 * 2 + 602) & 127;
    if (stage_v_199 > 46) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
