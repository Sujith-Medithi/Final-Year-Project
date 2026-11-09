/*
 * Benchmark Program: R001835
 * Security Family: bitwise_flow
 * Generator Seed: 683513
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001835_3513_0 {
    int determinant;
    int dim;
    int scale;
    int trace;
    int stride;
    unsigned char density;
    int buffer[3];
};

struct DeviceConfig_R001835_3513_1 {
    int parity;
    short stop_bits;
    int id;
    short baud_rate;
    int buffer[3];
};

union RegisterBank_R001835_3513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001835_3513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001835_3513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tally_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_29 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_29 > 11) {
        acc = (acc + index_reg_29 * 2 + 5) & 127;
        aux ^= (index_reg_29 & 15);
    } else {
        acc = (acc - index_reg_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_1(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int metric_96 = local_arr[aux % 3];
    acc = (acc + metric_96 * 2) & 127;
    int pivot_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_82) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_23 = (aux + st.buffer[1]) & 3;
    switch (index_reg_23) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int pivot_78 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_78 > 35) {
        acc = (acc + pivot_78 * 2 + 5) & 127;
        aux ^= (pivot_78 & 15);
    } else {
        acc = (acc - pivot_78 + 11) & 127;
        aux += 3;
    }
    int stride_54 = 0;
    for (int k = 0; k < 3; k++) {
        stride_54 = (stride_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_54) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001835_3513_3(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tally_21 = 0;
    for (int k = 0; k < 2; k++) {
        tally_21 = (tally_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_21) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_47 = local_arr[aux % 3];
    acc = (acc + accumulator_47 * 2) & 127;
    int cursor_42 = (aux + st.buffer[1]) & 3;
    switch (cursor_42) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_4(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_40 = 0;
    for (int k = 0; k < 2; k++) {
        segment_40 = (segment_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_40) & 127;
    }
    int damping_40 = (aux + st.buffer[1]) & 3;
    switch (damping_40) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_5(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int delta_89 = (aux + st.buffer[1]) & 3;
    switch (delta_89) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_11 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_11 > 16) {
        acc = (acc + tracker_11 * 2 + 5) & 127;
        aux ^= (tracker_11 & 15);
    } else {
        acc = (acc - tracker_11 + 11) & 127;
        aux += 3;
    }
    int threshold_39 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_39 = (threshold_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_39) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_71 = local_arr[aux % 3];
    acc = (acc + segment_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001835_3513_6(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int window_84 = 0;
    for (int k = 0; k < 3; k++) {
        window_84 = (window_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_84) & 127;
    }
    int accumulator_75 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_75 > 25) {
        acc = (acc + accumulator_75 * 2 + 5) & 127;
        aux ^= (accumulator_75 & 15);
    } else {
        acc = (acc - accumulator_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_7(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int parity_22 = local_arr[aux % 3];
    acc = (acc + parity_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_94 = 0;
    for (int k = 0; k < 3; k++) {
        parity_94 = (parity_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_94) & 127;
    }
    int anchor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001835_3513_8(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int residue_38 = 0;
    for (int k = 0; k < 2; k++) {
        residue_38 = (residue_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_38) & 127;
    }
    int tally_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_50) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_18 = local_arr[aux % 3];
    acc = (acc + quantum_18 * 2) & 127;
    int weight_51 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_51 > 35) {
        acc = (acc + weight_51 * 2 + 5) & 127;
        aux ^= (weight_51 & 15);
    } else {
        acc = (acc - weight_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int stride_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_30) & 63;
    acc ^= aux;
    int mask_91 = 0;
    for (int k = 0; k < 3; k++) {
        mask_91 = (mask_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_91) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_37 = local_arr[aux % 3];
    acc = (acc + offset_37 * 2) & 127;
    int residue_80 = (aux + st.buffer[1]) & 3;
    switch (residue_80) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int weight_30 = local_arr[aux % 3];
    acc = (acc + weight_30 * 2) & 127;
    int accumulator_69 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_69 = (accumulator_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_69) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int anchor_11 = local_arr[aux % 3];
    acc = (acc + anchor_11 * 2) & 127;
    int weight_49 = 0;
    for (int k = 0; k < 2; k++) {
        weight_49 = (weight_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int scale_32 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_32 > 42) {
        acc = (acc + scale_32 * 2 + 5) & 127;
        aux ^= (scale_32 & 15);
    } else {
        acc = (acc - scale_32 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_90 = local_arr[aux % 3];
    acc = (acc + segment_90 * 2) & 127;
    int metric_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_55) & 63;
    acc ^= aux;
    int coefficient_87 = (aux + st.buffer[1]) & 3;
    switch (coefficient_87) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_13(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int anchor_15 = local_arr[aux % 3];
    acc = (acc + anchor_15 * 2) & 127;
    int delta_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001835_3513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001835_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int sample_55 = local_arr[aux % 3];
    acc = (acc + sample_55 * 2) & 127;
    int damping_86 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_86 > 32) {
        acc = (acc + damping_86 * 2 + 5) & 127;
        aux ^= (damping_86 & 15);
    } else {
        acc = (acc - damping_86 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_70 = (aux + st.buffer[1]) & 3;
    switch (damping_70) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001835_3513_15(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001835_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_24 = (aux + st.buffer[1]) & 3;
    switch (segment_24) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_61 = local_arr[aux % 3];
    acc = (acc + stride_61 * 2) & 127;
    int margin_84 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_84 > 14) {
        acc = (acc + margin_84 * 2 + 5) & 127;
        aux ^= (margin_84 & 15);
    } else {
        acc = (acc - margin_84 + 11) & 127;
        aux += 3;
    }
    int weight_83 = 0;
    for (int k = 0; k < 3; k++) {
        weight_83 = (weight_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_83) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001835_0;
    int sec_r001835_1;
    int sec_r001835_2;
    int sec_r001835_3;
    int sec_r001835_4;
    int sec_r001835_5;
    int sec_r001835_6;
    int sec_r001835_7;
    int sec_r001835_8;
    int sec_r001835_9;
    int sec_r001835_10;
    int sec_r001835_11;
    int sec_r001835_12;
    int sec_r001835_13;
    int sec_r001835_14;
    int sec_r001835_15;
    int pub_r001835_0;
    int pub_r001835_1;
    int pub_r001835_2;
    int pub_r001835_3;
    int pub_r001835_4;
    int pub_r001835_5;
    int pub_r001835_6;
    int pub_r001835_7;
    int pub_r001835_8;
    int pub_r001835_9;
    int pub_r001835_10;
    int pub_r001835_11;
    int pub_r001835_12;
    int pub_r001835_13;
    int pub_r001835_14;
    int pub_r001835_15;
    int pub_r001835_16;
    int pub_r001835_17;
    int pub_r001835_18;
    int pub_r001835_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001835_0 >= -100 && pub_r001835_0 <= 100);
    __CPROVER_assume(pub_r001835_1 >= -100 && pub_r001835_1 <= 100);
    __CPROVER_assume(pub_r001835_2 >= -100 && pub_r001835_2 <= 100);
    __CPROVER_assume(pub_r001835_3 >= -100 && pub_r001835_3 <= 100);
    __CPROVER_assume(pub_r001835_4 >= -100 && pub_r001835_4 <= 100);
    __CPROVER_assume(pub_r001835_5 >= -100 && pub_r001835_5 <= 100);
    __CPROVER_assume(pub_r001835_6 >= -100 && pub_r001835_6 <= 100);
    __CPROVER_assume(pub_r001835_7 >= -100 && pub_r001835_7 <= 100);
    __CPROVER_assume(pub_r001835_8 >= -100 && pub_r001835_8 <= 100);
    __CPROVER_assume(pub_r001835_9 >= -100 && pub_r001835_9 <= 100);
    __CPROVER_assume(pub_r001835_10 >= -100 && pub_r001835_10 <= 100);
    __CPROVER_assume(pub_r001835_11 >= -100 && pub_r001835_11 <= 100);
    __CPROVER_assume(pub_r001835_12 >= -100 && pub_r001835_12 <= 100);
    __CPROVER_assume(pub_r001835_13 >= -100 && pub_r001835_13 <= 100);
    __CPROVER_assume(pub_r001835_14 >= -100 && pub_r001835_14 <= 100);
    __CPROVER_assume(pub_r001835_15 >= -100 && pub_r001835_15 <= 100);
    __CPROVER_assume(pub_r001835_16 >= -100 && pub_r001835_16 <= 100);
    __CPROVER_assume(pub_r001835_17 >= -100 && pub_r001835_17 <= 100);
    __CPROVER_assume(pub_r001835_18 >= -100 && pub_r001835_18 <= 100);
    __CPROVER_assume(pub_r001835_19 >= -100 && pub_r001835_19 <= 100);
    __CPROVER_assume(sec_r001835_0 >= 0 && sec_r001835_0 <= 255);
    __CPROVER_assume(sec_r001835_1 >= 0 && sec_r001835_1 <= 255);
    __CPROVER_assume(sec_r001835_2 >= 0 && sec_r001835_2 <= 255);
    __CPROVER_assume(sec_r001835_3 >= 0 && sec_r001835_3 <= 255);
    __CPROVER_assume(sec_r001835_4 >= 0 && sec_r001835_4 <= 255);
    __CPROVER_assume(sec_r001835_5 >= 0 && sec_r001835_5 <= 255);
    __CPROVER_assume(sec_r001835_6 >= 0 && sec_r001835_6 <= 255);
    __CPROVER_assume(sec_r001835_7 >= 0 && sec_r001835_7 <= 255);
    __CPROVER_assume(sec_r001835_8 >= 0 && sec_r001835_8 <= 255);
    __CPROVER_assume(sec_r001835_9 >= 0 && sec_r001835_9 <= 255);
    __CPROVER_assume(sec_r001835_10 >= 0 && sec_r001835_10 <= 255);
    __CPROVER_assume(sec_r001835_11 >= 0 && sec_r001835_11 <= 255);
    __CPROVER_assume(sec_r001835_12 >= 0 && sec_r001835_12 <= 255);
    __CPROVER_assume(sec_r001835_13 >= 0 && sec_r001835_13 <= 255);
    __CPROVER_assume(sec_r001835_14 >= 0 && sec_r001835_14 <= 255);
    __CPROVER_assume(sec_r001835_15 >= 0 && sec_r001835_15 <= 255);

    struct MatrixBlock_R001835_3513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001835_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001835_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001835_0 + 7) & 15;
    struct DeviceConfig_R001835_3513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001835_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001835_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001835_0 + 9) & 15;

    union RegisterBank_R001835_3513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001835_3513_0(sec_r001835_0, pub_r001835_1, pub_r001835_2, pub_r001835_3, pub_r001835_4);
    int helper_flow_1 = fn_R001835_3513_1(sec_r001835_1, sec_r001835_2, pub_r001835_3);
    int helper_flow_2 = fn_R001835_3513_2(sec_r001835_2, pub_r001835_3, pub_r001835_4, pub_r001835_5);
    int helper_flow_3 = fn_R001835_3513_3(sec_r001835_3, sec_r001835_4);
    int helper_flow_4 = fn_R001835_3513_4(sec_r001835_4, pub_r001835_5, pub_r001835_6);
    int helper_flow_5 = fn_R001835_3513_5(sec_r001835_5, sec_r001835_6, pub_r001835_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001835_1 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001835_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001835_12 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001835_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001835_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001835_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001835_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001835_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001835_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_0 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001835_5 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001835_15 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001835_1 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001835_0 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001835_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001835_9 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001835_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001835_11 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001835_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001835_4 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001835_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_0 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001835_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001835_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_15 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001835_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_13 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001835_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_17 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_0 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_0 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001835_3 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001835_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001835_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001835_0 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001835_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001835_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001835_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001835_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001835_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001835_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001835_3 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001835_4 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_26 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001835_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001835_15 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_31 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001835_3 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_12 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_15 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001835_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001835_0 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_34 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_4 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001835_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001835_15 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001835_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_15 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001835_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_43 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_59 + 1) & 15;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001835_13 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_30 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001835_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001835_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001835_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001835_6 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001835_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001835_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001835_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001835_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_47 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_31 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001835_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001835_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001835_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001835_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_55 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001835_2 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_34 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001835_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001835_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_5 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001835_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001835_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001835_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_0 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001835_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001835_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001835_7 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_19 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_30 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_85 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001835_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_17 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001835_10 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((helper_flow_3 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001835_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((helper_flow_3 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001835_0 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_12 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001835_13 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001835_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001835_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r001835_4 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001835_7 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_31 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001835_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_81 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001835_13 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001835_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001835_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r001835_13 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_99 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001835_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001835_19 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_43 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_10 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((helper_flow_2 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001835_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001835_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_116 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_31 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_45 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_53 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_97 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((helper_flow_2 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001835_10 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_88 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001835_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001835_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_124 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001835_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001835_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_71 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_2 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_116 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_48 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001835_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001835_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_15 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001835_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_52 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001835_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_55 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001835_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_99 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001835_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((helper_flow_2 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_78 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001835_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_93 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_104 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_122 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001835_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_133 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_19 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001835_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_51 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001835_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001835_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_121 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_154 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_157 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_161 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001835_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r001835_1 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001835_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001835_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001835_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001835_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001835_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_0 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((helper_flow_4 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001835_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_107 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001835_13 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001835_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_136 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001835_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001835_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001835_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r001835_11 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_181 + 1) & 15;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001835_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_141 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001835_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001835_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001835_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001835_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_151 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_163 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_100 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_154 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_2 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001835_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_13 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001835_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_57 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r001835_5 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001835_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_135 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001835_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_196 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_120 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_123 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_171 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_94 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_99 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001835_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_52 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_65 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001835_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001835_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_17 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001835_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001835_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001835_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_163 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001835_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001835_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001835_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_41 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_216 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001835_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001835_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_141 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_24 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001835_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001835_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_212 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_76 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_133 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_171 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001835_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_88 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_57 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001835_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001835_9 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001835_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_150 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_154 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_26 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001835_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001835_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001835_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_197 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_225 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_212 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_151 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001835_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001835_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_115 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_53 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001835_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001835_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_12 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_124 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_61 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_71 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001835_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001835_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001835_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_190 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_205 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_48 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_240 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_90 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_88 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_240 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001835_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001835_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_224 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_60 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_70 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001835_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001835_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001835_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001835_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001835_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001835_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001835_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_85 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_206 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_148 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_10 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001835_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001835_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001835_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_136 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_229 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_288 + 1) & 15;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((helper_flow_3 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001835_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_165 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001835_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001835_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((helper_flow_4 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001835_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001835_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001835_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001835_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_231 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001835_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001835_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001835_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_288 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001835_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_61 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001835_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001835_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_299 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001835_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r001835_1 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_199 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001835_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_21 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001835_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_13 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_231 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_183 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001835_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001835_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_45 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001835_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((sec_r001835_14 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001835_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((sec_r001835_14 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_107 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001835_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001835_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001835_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001835_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_161 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001835_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001835_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_123 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001835_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001835_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001835_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001835_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_265 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001835_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_24 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_127 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_181 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_208 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001835_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_98 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_9 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001835_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001835_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001835_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001835_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001835_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001835_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001835_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_88 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((sec_r001835_14 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001835_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001835_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_177 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_299 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_78 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_189 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001835_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_234 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_117 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_354 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_42 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_267 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001835_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_341 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001835_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_338 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001835_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001835_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001835_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001835_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001835_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001835_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_177 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001835_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001835_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_147 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_190 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_247 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((sec_r001835_6 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_154 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_385 + 1) & 15;
    out_sink ^= (stage_v_385 & 63);

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001835_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001835_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001835_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001835_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001835_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_320 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_324 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_150 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_291 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001835_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001835_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_115 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_371 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_398 + 1) & 15;
    out_sink ^= (stage_v_398 & 63);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001835_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_245 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001835_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_364 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_317 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001835_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_391 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_53 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001835_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001835_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_89 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001835_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_163 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_26 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_123 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_13 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001835_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_194 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_28 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001835_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001835_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_171 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001835_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001835_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001835_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001835_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_330 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001835_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_236 << 1) ^ (pub_r001835_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_427 + 1) & 15;
    out_sink ^= (stage_v_427 & 63);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_364 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_181 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001835_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001835_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001835_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001835_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_189 << 1) ^ (pub_r001835_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_434 + 1) & 15;
    out_sink ^= (stage_v_434 & 63);

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_384 << 1) ^ (pub_r001835_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_183 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_160 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001835_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001835_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_100 << 1) ^ (pub_r001835_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_440 + 1) & 15;
    out_sink ^= (stage_v_440 & 63);

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001835_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001835_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_435 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_366 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_93 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_175 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001835_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001835_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((sec_r001835_9 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001835_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_105 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001835_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001835_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001835_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001835_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001835_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_201 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_457 + 1) & 15;
    out_sink ^= (stage_v_457 & 63);

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_163 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_458 + 1) & 15;
    out_sink ^= (stage_v_458 & 63);

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_196 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_459 + 1) & 15;
    out_sink ^= (stage_v_459 & 63);

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_434 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_367 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_461 + 1) & 15;
    out_sink ^= (stage_v_461 & 63);

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_122 << 1) ^ (pub_r001835_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_462 + 1) & 15;
    out_sink ^= (stage_v_462 & 63);

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_10 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_463 + 1) & 15;
    out_sink ^= (stage_v_463 & 63);

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001835_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_320 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_465 + 1) & 15;
    out_sink ^= (stage_v_465 & 63);

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001835_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_435 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001835_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = ((stage_v_392 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_469 + 1) & 15;
    out_sink ^= (stage_v_469 & 63);

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001835_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001835_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001835_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_412 << 1) ^ (pub_r001835_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_473 + 1) & 15;
    out_sink ^= (stage_v_473 & 63);

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_325 << 1) ^ (pub_r001835_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_474 + 1) & 15;
    out_sink ^= (stage_v_474 & 63);

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001835_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001835_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001835_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001835_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001835_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001835_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = ((stage_v_201 << 1) ^ (pub_r001835_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_481 + 1) & 15;
    out_sink ^= (stage_v_481 & 63);

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = ((stage_v_303 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_482 + 1) & 15;
    out_sink ^= (stage_v_482 & 63);

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001835_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001835_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001835_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001835_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_460 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_487 + 1) & 15;
    out_sink ^= (stage_v_487 & 63);

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001835_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001835_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001835_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001835_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001835_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_482 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_493 + 1) & 15;
    out_sink ^= (stage_v_493 & 63);

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = ((helper_flow_1 << 1) ^ (pub_r001835_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_494 + 1) & 15;
    out_sink ^= (stage_v_494 & 63);

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001835_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001835_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = ((stage_v_89 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_497 + 1) & 15;
    out_sink ^= (stage_v_497 & 63);

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = ((helper_flow_3 << 1) ^ (pub_r001835_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_498 + 1) & 15;
    out_sink ^= (stage_v_498 & 63);

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = ((stage_v_317 << 1) ^ (pub_r001835_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_499 + 1) & 15;
    out_sink ^= (stage_v_499 & 63);

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = ((stage_v_412 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_500 + 1) & 15;
    out_sink ^= (stage_v_500 & 63);

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = ((stage_v_29 << 1) ^ (pub_r001835_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_501 + 1) & 15;
    out_sink ^= (stage_v_501 & 63);

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001835_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001835_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = ((sec_r001835_14 << 1) ^ (pub_r001835_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_504 + 1) & 15;
    out_sink ^= (stage_v_504 & 63);

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = ((stage_v_264 << 1) ^ (pub_r001835_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_505 + 1) & 15;
    out_sink ^= (stage_v_505 & 63);

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001835_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = ((stage_v_247 << 1) ^ (pub_r001835_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_507 + 1) & 15;
    out_sink ^= (stage_v_507 & 63);

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = ((stage_v_238 << 1) ^ (pub_r001835_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_508 + 1) & 15;
    out_sink ^= (stage_v_508 & 63);

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = ((stage_v_89 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_509 + 1) & 15;
    out_sink ^= (stage_v_509 & 63);

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = (pub_r001835_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_510) & 127;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001835_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = ((stage_v_257 << 1) ^ (pub_r001835_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_512 + 1) & 15;
    out_sink ^= (stage_v_512 & 63);

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = (pub_r001835_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_513) & 127;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = ((stage_v_152 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_514 + 1) & 15;
    out_sink ^= (stage_v_514 & 63);

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = ((stage_v_94 << 1) ^ (pub_r001835_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_515 + 1) & 15;
    out_sink ^= (stage_v_515 & 63);

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = ((stage_v_358 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_516 + 1) & 15;
    out_sink ^= (stage_v_516 & 63);

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001835_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = ((stage_v_51 << 1) ^ (pub_r001835_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_518 + 1) & 15;
    out_sink ^= (stage_v_518 & 63);

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = ((sec_r001835_7 << 1) ^ (pub_r001835_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_519 + 1) & 15;
    out_sink ^= (stage_v_519 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
