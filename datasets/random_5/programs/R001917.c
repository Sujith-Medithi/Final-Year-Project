/*
 * Benchmark Program: R001917
 * Security Family: nested_implicit_flow
 * Generator Seed: 691713
 * High Inputs: 24 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001917_1713_0 {
    int offset;
    int status;
    unsigned char threshold;
    int calib;
    short gain;
    int buffer[3];
};

struct AudioFrame_R001917_1713_1 {
    int peak;
    unsigned char rms;
    int channels;
    int envelope;
    int sample_rate;
    int buffer[3];
};

union ColorPixel_R001917_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001917_1713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001917_1713_0(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001917_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int bound_65 = local_arr[aux % 3];
    acc = (acc + bound_65 * 2) & 127;
    int mask_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_83) & 63;
    acc ^= aux;
    int metric_90 = 0;
    for (int k = 0; k < 2; k++) {
        metric_90 = (metric_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int phase_84 = 0;
    for (int k = 0; k < 2; k++) {
        phase_84 = (phase_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_84) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_61 = (aux + st.buffer[1]) & 3;
    switch (offset_61) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_2(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001917_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int coefficient_29 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_29 = (coefficient_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_29) & 127;
    }
    int mask_61 = (aux + st.buffer[1]) & 3;
    switch (mask_61) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_42 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_42 > 18) {
        acc = (acc + weight_42 * 2 + 5) & 127;
        aux ^= (weight_42 & 15);
    } else {
        acc = (acc - weight_42 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001917_1713_3(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_21 = (aux + st.buffer[1]) & 3;
    switch (sample_21) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_71 = local_arr[aux % 3];
    acc = (acc + window_71 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001917_1713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int scale_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_14) & 63;
    acc ^= aux;
    int offset_79 = 0;
    for (int k = 0; k < 3; k++) {
        offset_79 = (offset_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_79) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_12 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_12 > 39) {
        acc = (acc + segment_12 * 2 + 5) & 127;
        aux ^= (segment_12 & 15);
    } else {
        acc = (acc - segment_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_5(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_87 = local_arr[aux % 3];
    acc = (acc + scale_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001917_1713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001917_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int segment_82 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_82 > 15) {
        acc = (acc + segment_82 * 2 + 5) & 127;
        aux ^= (segment_82 & 15);
    } else {
        acc = (acc - segment_82 + 11) & 127;
        aux += 3;
    }
    int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_63) & 63;
    acc ^= aux;
    int mask_51 = 0;
    for (int k = 0; k < 2; k++) {
        mask_51 = (mask_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_7(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int window_21 = (aux + st.buffer[1]) & 3;
    switch (window_21) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_46 = 0;
    for (int k = 0; k < 2; k++) {
        metric_46 = (metric_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_46) & 127;
    }
    int parity_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_30) & 63;
    acc ^= aux;
    int tally_10 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_10 > 41) {
        acc = (acc + tally_10 * 2 + 5) & 127;
        aux ^= (tally_10 & 15);
    } else {
        acc = (acc - tally_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_8(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int anchor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_75 > 29) {
        acc = (acc + anchor_75 * 2 + 5) & 127;
        aux ^= (anchor_75 & 15);
    } else {
        acc = (acc - anchor_75 + 11) & 127;
        aux += 3;
    }
    int damping_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_33) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001917_1713_9(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001917_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int residue_46 = local_arr[aux % 3];
    acc = (acc + residue_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001917_1713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int checksum_80 = (aux + st.buffer[1]) & 3;
    switch (checksum_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_25) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_29 = local_arr[aux % 3];
    acc = (acc + factor_29 * 2) & 127;
    int phase_61 = 0;
    for (int k = 0; k < 2; k++) {
        phase_61 = (phase_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_13 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_13 > 27) {
        acc = (acc + damping_13 * 2 + 5) & 127;
        aux ^= (damping_13 & 15);
    } else {
        acc = (acc - damping_13 + 11) & 127;
        aux += 3;
    }
    int residue_70 = (aux + st.buffer[1]) & 3;
    switch (residue_70) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_12(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_41 = (aux + st.buffer[1]) & 3;
    switch (bound_41) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_39 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_39 > 43) {
        acc = (acc + metric_39 * 2 + 5) & 127;
        aux ^= (metric_39 & 15);
    } else {
        acc = (acc - metric_39 + 11) & 127;
        aux += 3;
    }
    int offset_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001917_1713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int threshold_62 = local_arr[aux % 3];
    acc = (acc + threshold_62 * 2) & 127;
    int damping_12 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_12 > 39) {
        acc = (acc + damping_12 * 2 + 5) & 127;
        aux ^= (damping_12 & 15);
    } else {
        acc = (acc - damping_12 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_20 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_20 = (index_reg_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_20) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001917_1713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001917_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_48 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_48 = (threshold_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_48) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_88 = local_arr[aux % 3];
    acc = (acc + delta_88 * 2) & 127;
    int stride_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001917_0;
    int sec_r001917_1;
    int sec_r001917_2;
    int sec_r001917_3;
    int sec_r001917_4;
    int sec_r001917_5;
    int sec_r001917_6;
    int sec_r001917_7;
    int sec_r001917_8;
    int sec_r001917_9;
    int sec_r001917_10;
    int sec_r001917_11;
    int sec_r001917_12;
    int sec_r001917_13;
    int sec_r001917_14;
    int sec_r001917_15;
    int sec_r001917_16;
    int sec_r001917_17;
    int sec_r001917_18;
    int sec_r001917_19;
    int sec_r001917_20;
    int sec_r001917_21;
    int sec_r001917_22;
    int sec_r001917_23;
    int pub_r001917_0;
    int pub_r001917_1;
    int pub_r001917_2;
    int pub_r001917_3;
    int pub_r001917_4;
    int pub_r001917_5;
    int pub_r001917_6;
    int pub_r001917_7;
    int pub_r001917_8;
    int pub_r001917_9;
    int pub_r001917_10;
    int pub_r001917_11;
    int pub_r001917_12;
    int pub_r001917_13;
    int pub_r001917_14;
    int pub_r001917_15;
    int pub_r001917_16;
    int pub_r001917_17;
    int pub_r001917_18;
    int pub_r001917_19;
    int pub_r001917_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001917_0 >= -100 && pub_r001917_0 <= 100);
    __CPROVER_assume(pub_r001917_1 >= -100 && pub_r001917_1 <= 100);
    __CPROVER_assume(pub_r001917_2 >= -100 && pub_r001917_2 <= 100);
    __CPROVER_assume(pub_r001917_3 >= -100 && pub_r001917_3 <= 100);
    __CPROVER_assume(pub_r001917_4 >= -100 && pub_r001917_4 <= 100);
    __CPROVER_assume(pub_r001917_5 >= -100 && pub_r001917_5 <= 100);
    __CPROVER_assume(pub_r001917_6 >= -100 && pub_r001917_6 <= 100);
    __CPROVER_assume(pub_r001917_7 >= -100 && pub_r001917_7 <= 100);
    __CPROVER_assume(pub_r001917_8 >= -100 && pub_r001917_8 <= 100);
    __CPROVER_assume(pub_r001917_9 >= -100 && pub_r001917_9 <= 100);
    __CPROVER_assume(pub_r001917_10 >= -100 && pub_r001917_10 <= 100);
    __CPROVER_assume(pub_r001917_11 >= -100 && pub_r001917_11 <= 100);
    __CPROVER_assume(pub_r001917_12 >= -100 && pub_r001917_12 <= 100);
    __CPROVER_assume(pub_r001917_13 >= -100 && pub_r001917_13 <= 100);
    __CPROVER_assume(pub_r001917_14 >= -100 && pub_r001917_14 <= 100);
    __CPROVER_assume(pub_r001917_15 >= -100 && pub_r001917_15 <= 100);
    __CPROVER_assume(pub_r001917_16 >= -100 && pub_r001917_16 <= 100);
    __CPROVER_assume(pub_r001917_17 >= -100 && pub_r001917_17 <= 100);
    __CPROVER_assume(pub_r001917_18 >= -100 && pub_r001917_18 <= 100);
    __CPROVER_assume(pub_r001917_19 >= -100 && pub_r001917_19 <= 100);
    __CPROVER_assume(pub_r001917_20 >= -100 && pub_r001917_20 <= 100);
    __CPROVER_assume(sec_r001917_0 >= 0 && sec_r001917_0 <= 255);
    __CPROVER_assume(sec_r001917_1 >= 0 && sec_r001917_1 <= 255);
    __CPROVER_assume(sec_r001917_2 >= 0 && sec_r001917_2 <= 255);
    __CPROVER_assume(sec_r001917_3 >= 0 && sec_r001917_3 <= 255);
    __CPROVER_assume(sec_r001917_4 >= 0 && sec_r001917_4 <= 255);
    __CPROVER_assume(sec_r001917_5 >= 0 && sec_r001917_5 <= 255);
    __CPROVER_assume(sec_r001917_6 >= 0 && sec_r001917_6 <= 255);
    __CPROVER_assume(sec_r001917_7 >= 0 && sec_r001917_7 <= 255);
    __CPROVER_assume(sec_r001917_8 >= 0 && sec_r001917_8 <= 255);
    __CPROVER_assume(sec_r001917_9 >= 0 && sec_r001917_9 <= 255);
    __CPROVER_assume(sec_r001917_10 >= 0 && sec_r001917_10 <= 255);
    __CPROVER_assume(sec_r001917_11 >= 0 && sec_r001917_11 <= 255);
    __CPROVER_assume(sec_r001917_12 >= 0 && sec_r001917_12 <= 255);
    __CPROVER_assume(sec_r001917_13 >= 0 && sec_r001917_13 <= 255);
    __CPROVER_assume(sec_r001917_14 >= 0 && sec_r001917_14 <= 255);
    __CPROVER_assume(sec_r001917_15 >= 0 && sec_r001917_15 <= 255);
    __CPROVER_assume(sec_r001917_16 >= 0 && sec_r001917_16 <= 255);
    __CPROVER_assume(sec_r001917_17 >= 0 && sec_r001917_17 <= 255);
    __CPROVER_assume(sec_r001917_18 >= 0 && sec_r001917_18 <= 255);
    __CPROVER_assume(sec_r001917_19 >= 0 && sec_r001917_19 <= 255);
    __CPROVER_assume(sec_r001917_20 >= 0 && sec_r001917_20 <= 255);
    __CPROVER_assume(sec_r001917_21 >= 0 && sec_r001917_21 <= 255);
    __CPROVER_assume(sec_r001917_22 >= 0 && sec_r001917_22 <= 255);
    __CPROVER_assume(sec_r001917_23 >= 0 && sec_r001917_23 <= 255);

    struct SensorNode_R001917_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001917_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001917_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001917_0 + 7) & 15;
    struct AudioFrame_R001917_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001917_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001917_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001917_0 + 9) & 15;

    union ColorPixel_R001917_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001917_1713_0(sec_r001917_0, sec_r001917_1);
    int helper_flow_1 = fn_R001917_1713_1(sec_r001917_1, pub_r001917_2, pub_r001917_3, pub_r001917_4);
    int helper_flow_2 = fn_R001917_1713_2(sec_r001917_2, pub_r001917_3, pub_r001917_4);
    int helper_flow_3 = fn_R001917_1713_3(sec_r001917_3, sec_r001917_4);
    int helper_flow_4 = fn_R001917_1713_4(sec_r001917_4, sec_r001917_5, pub_r001917_6, pub_r001917_7);
    int helper_flow_5 = fn_R001917_1713_5(sec_r001917_5, pub_r001917_6, pub_r001917_7);
    int helper_flow_6 = fn_R001917_1713_6(sec_r001917_6, sec_r001917_7, pub_r001917_8, pub_r001917_9);
    int helper_flow_7 = fn_R001917_1713_7(sec_r001917_7, pub_r001917_8);
    int helper_flow_8 = fn_R001917_1713_8(sec_r001917_8, sec_r001917_9);
    int helper_flow_9 = fn_R001917_1713_9(sec_r001917_9, pub_r001917_10, pub_r001917_11);
    int helper_flow_10 = fn_R001917_1713_10(sec_r001917_10, sec_r001917_11, pub_r001917_12, pub_r001917_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_5 ^ pub_r001917_15) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001917_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001917_8 ^ pub_r001917_8) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001917_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_4 ^ pub_r001917_8) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001917_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001917_8 ^ pub_r001917_16) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001917_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001917_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001917_5 ^ pub_r001917_6) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001917_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001917_5 ^ pub_r001917_16) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001917_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001917_20 ^ pub_r001917_19) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001917_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001917_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001917_14 ^ pub_r001917_1) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001917_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_6 ^ pub_r001917_6) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001917_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001917_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001917_0 ^ pub_r001917_2) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001917_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_9 ^ pub_r001917_2) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001917_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001917_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001917_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001917_4 ^ pub_r001917_11) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001917_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001917_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_10 ^ pub_r001917_15) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001917_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001917_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001917_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001917_17 ^ pub_r001917_10) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001917_7 ^ pub_r001917_15) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001917_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001917_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001917_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001917_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_10 ^ pub_r001917_18) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001917_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001917_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_23 ^ pub_r001917_12) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r001917_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_0 ^ pub_r001917_9) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001917_16 ^ pub_r001917_19) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_7 ^ pub_r001917_5) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r001917_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_18 ^ pub_r001917_6) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001917_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_8 ^ pub_r001917_6) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001917_5 ^ pub_r001917_8) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_2 ^ pub_r001917_2) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001917_19 ^ pub_r001917_9) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001917_4 ^ pub_r001917_5) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001917_14 ^ pub_r001917_6) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (helper_flow_5 ^ pub_r001917_1) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001917_18 ^ pub_r001917_19) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_9 ^ pub_r001917_5) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r001917_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_9 ^ pub_r001917_2) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001917_8 ^ pub_r001917_19) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r001917_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_13 ^ pub_r001917_19) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r001917_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (helper_flow_6 ^ pub_r001917_0) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_46 ^ pub_r001917_15) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001917_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_30 ^ pub_r001917_16) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r001917_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001917_14 ^ pub_r001917_3) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001917_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001917_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001917_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_1 ^ pub_r001917_20) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r001917_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_37 ^ pub_r001917_15) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001917_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_2 ^ pub_r001917_19) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001917_15 ^ pub_r001917_4) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_27 ^ pub_r001917_1) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r001917_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001917_23 ^ pub_r001917_20) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_12 ^ pub_r001917_3) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001917_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001917_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_55 ^ pub_r001917_17) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r001917_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001917_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r001917_4 ^ pub_r001917_7) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (helper_flow_5 ^ pub_r001917_8) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001917_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001917_3 ^ pub_r001917_5) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_46 ^ pub_r001917_0) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001917_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_42 ^ pub_r001917_19) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001917_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001917_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001917_19 ^ pub_r001917_17) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_23 ^ pub_r001917_4) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001917_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_10 ^ pub_r001917_0) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_50 ^ pub_r001917_13) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001917_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (helper_flow_3 ^ pub_r001917_4) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001917_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (helper_flow_9 ^ pub_r001917_2) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_43 ^ pub_r001917_8) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_13 ^ pub_r001917_9) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_3 ^ pub_r001917_14) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001917_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001917_8 ^ pub_r001917_10) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r001917_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_33 ^ pub_r001917_20) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001917_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_44 ^ pub_r001917_10) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r001917_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001917_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_42 ^ pub_r001917_7) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r001917_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001917_17 ^ pub_r001917_19) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001917_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_13 ^ pub_r001917_8) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001917_14 ^ pub_r001917_20) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001917_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_5 ^ pub_r001917_20) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_78 ^ pub_r001917_20) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_0 ^ pub_r001917_19) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001917_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_78 ^ pub_r001917_3) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r001917_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001917_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001917_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001917_16 ^ pub_r001917_7) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001917_20 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001917_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001917_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001917_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_41 ^ pub_r001917_5) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (helper_flow_7 ^ pub_r001917_16) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001917_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_88 ^ pub_r001917_9) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r001917_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_98 ^ pub_r001917_16) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_54 ^ pub_r001917_13) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_110 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_90 ^ pub_r001917_1) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001917_15 ^ pub_r001917_0) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (helper_flow_9 ^ pub_r001917_6) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001917_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_109 ^ pub_r001917_17) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_0 ^ pub_r001917_8) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r001917_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_59 ^ pub_r001917_12) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001917_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_116 ^ pub_r001917_9) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_43 ^ pub_r001917_3) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (helper_flow_1 ^ pub_r001917_3) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_77 ^ pub_r001917_18) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001917_12 ^ pub_r001917_9) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001917_11 ^ pub_r001917_10) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001917_22 ^ pub_r001917_13) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001917_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001917_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001917_18 ^ pub_r001917_12) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001917_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_18 ^ pub_r001917_7) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001917_19 ^ pub_r001917_18) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_113 ^ pub_r001917_20) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001917_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001917_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001917_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001917_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r001917_3 ^ pub_r001917_9) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_5 ^ pub_r001917_11) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (helper_flow_6 ^ pub_r001917_12) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_10 ^ pub_r001917_2) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_132 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_10 ^ pub_r001917_15) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001917_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_10 ^ pub_r001917_19) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_143 ^ pub_r001917_17) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((sec_r001917_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_46 ^ pub_r001917_6) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (sec_r001917_12 ^ pub_r001917_12) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r001917_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001917_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_141 ^ pub_r001917_13) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((sec_r001917_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_101 ^ pub_r001917_2) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001917_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (helper_flow_3 ^ pub_r001917_20) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_116 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001917_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001917_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_127 ^ pub_r001917_1) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (sec_r001917_1 ^ pub_r001917_12) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r001917_15 ^ pub_r001917_14) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_120 ^ pub_r001917_10) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_22 ^ pub_r001917_6) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((sec_r001917_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_5 ^ pub_r001917_1) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((sec_r001917_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_74 ^ pub_r001917_10) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r001917_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r001917_17 ^ pub_r001917_17) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((sec_r001917_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001917_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (helper_flow_4 ^ pub_r001917_5) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_144 ^ pub_r001917_14) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001917_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_150 ^ pub_r001917_2) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001917_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_162 ^ pub_r001917_4) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_158 ^ pub_r001917_8) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_148 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_29 ^ pub_r001917_3) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_90 ^ pub_r001917_12) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_145 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_143 ^ pub_r001917_14) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001917_14 ^ pub_r001917_0) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_132 ^ pub_r001917_9) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_126 ^ pub_r001917_14) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001917_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001917_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_7 ^ pub_r001917_1) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((stage_v_177 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_165 ^ pub_r001917_10) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_176 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001917_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001917_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001917_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_39 ^ pub_r001917_7) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_87 ^ pub_r001917_11) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((sec_r001917_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001917_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001917_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_126 ^ pub_r001917_2) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001917_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_152 ^ pub_r001917_9) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001917_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_119 ^ pub_r001917_18) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_165 ^ pub_r001917_5) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001917_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_96 ^ pub_r001917_4) & 63;
    if ((stage_v_198 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_198 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_198 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_45 ^ pub_r001917_4) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (sec_r001917_16 ^ pub_r001917_14) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_18 ^ pub_r001917_8) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((sec_r001917_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_119 ^ pub_r001917_6) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_159 ^ pub_r001917_14) & 63;
    if ((stage_v_203 & 1) != 0) {
        if ((sec_r001917_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_203 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_203 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001917_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_116 ^ pub_r001917_18) & 63;
    if ((stage_v_205 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_205 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_205 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (helper_flow_6 ^ pub_r001917_12) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001917_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_54 ^ pub_r001917_17) & 63;
    if ((stage_v_208 & 1) != 0) {
        if ((stage_v_205 & 2) != 0) {
            out_sink = (out_sink + stage_v_208 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_208 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001917_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
