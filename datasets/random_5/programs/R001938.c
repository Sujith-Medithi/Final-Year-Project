/*
 * Benchmark Program: R001938
 * Security Family: secret_dependent_loops
 * Generator Seed: 693813
 * High Inputs: 20 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001938_3813_0 {
    int reading;
    int gain;
    unsigned char threshold;
    int calib;
    unsigned char status;
    int buffer[3];
};

struct StreamBuffer_R001938_3813_1 {
    int checksum;
    short capacity;
    unsigned char head;
    short watermark;
    int buffer[3];
};

struct FilterState_R001938_3813_2 {
    int prev_out;
    short mode;
    short cutoff;
    int prev_in;
    int buffer[3];
};

struct Transaction_R001938_3813_3 {
    int balance;
    short rate;
    int status;
    int account_id;
    int auth_code;
    unsigned char fee;
    int buffer[3];
};

union RegisterBank_R001938_3813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001938_3813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001938_3813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001938_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int bound_79 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_79 > 37) {
        acc = (acc + bound_79 * 2 + 5) & 127;
        aux ^= (bound_79 & 15);
    } else {
        acc = (acc - bound_79 + 11) & 127;
        aux += 3;
    }
    int window_17 = 0;
    for (int k = 0; k < 2; k++) {
        window_17 = (window_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_17) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001938_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_49 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_49 = (threshold_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_49) & 127;
    }
    int mask_10 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_10 > 21) {
        acc = (acc + mask_10 * 2 + 5) & 127;
        aux ^= (mask_10 & 15);
    } else {
        acc = (acc - mask_10 + 11) & 127;
        aux += 3;
    }
    int vector_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001938_3813_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001938_3813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_17) & 63;
    acc ^= aux;
    int tracker_81 = (aux + st.buffer[1]) & 3;
    switch (tracker_81) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001938_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tracker_85 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_85 > 36) {
        acc = (acc + tracker_85 * 2 + 5) & 127;
        aux ^= (tracker_85 & 15);
    } else {
        acc = (acc - tracker_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_20 = local_arr[aux % 3];
    acc = (acc + offset_20 * 2) & 127;
    int weight_64 = (aux + st.buffer[1]) & 3;
    switch (weight_64) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_4(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001938_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int bound_74 = 0;
    for (int k = 0; k < 2; k++) {
        bound_74 = (bound_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_74) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_47) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_95 = local_arr[aux % 3];
    acc = (acc + threshold_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001938_3813_5(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001938_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_69 = 0;
    for (int k = 0; k < 2; k++) {
        weight_69 = (weight_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_69) & 127;
    }
    int mask_53 = (aux + st.buffer[1]) & 3;
    switch (mask_53) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_81) & 63;
    acc ^= aux;
    int quotient_36 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_36 > 12) {
        acc = (acc + quotient_36 * 2 + 5) & 127;
        aux ^= (quotient_36 & 15);
    } else {
        acc = (acc - quotient_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_6(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001938_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int damping_74 = 0;
    for (int k = 0; k < 3; k++) {
        damping_74 = (damping_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_74) & 127;
    }
    int tally_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_51 = local_arr[aux % 3];
    acc = (acc + mask_51 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001938_3813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001938_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int pivot_14 = local_arr[aux % 3];
    acc = (acc + pivot_14 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001938_3813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001938_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int cursor_59 = (aux + st.buffer[1]) & 3;
    switch (cursor_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_15 = local_arr[aux % 3];
    acc = (acc + accumulator_15 * 2) & 127;
    int stride_13 = 0;
    for (int k = 0; k < 2; k++) {
        stride_13 = (stride_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_13) & 127;
    }
    int tracker_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001938_3813_9(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001938_3813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_82) & 63;
    acc ^= aux;
    int offset_31 = (aux + st.buffer[1]) & 3;
    switch (offset_31) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001938_3813_10(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001938_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int pivot_28 = (aux + st.buffer[1]) & 3;
    switch (pivot_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_37) & 63;
    acc ^= aux;
    int phase_13 = 0;
    for (int k = 0; k < 3; k++) {
        phase_13 = (phase_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_11(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001938_3813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int anchor_94 = local_arr[aux % 3];
    acc = (acc + anchor_94 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001938_3813_12(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001938_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int cursor_64 = (aux + st.buffer[1]) & 3;
    switch (cursor_64) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_52 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_52 > 30) {
        acc = (acc + anchor_52 * 2 + 5) & 127;
        aux ^= (anchor_52 & 15);
    } else {
        acc = (acc - anchor_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_13(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001938_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int stride_13 = 0;
    for (int k = 0; k < 2; k++) {
        stride_13 = (stride_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_13) & 127;
    }
    int quantum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001938_3813_14(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001938_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tracker_27 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_27 = (tracker_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_27) & 127;
    }
    int weight_17 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_17 > 47) {
        acc = (acc + weight_17 * 2 + 5) & 127;
        aux ^= (weight_17 & 15);
    } else {
        acc = (acc - weight_17 + 11) & 127;
        aux += 3;
    }
    int metric_40 = (aux + st.buffer[1]) & 3;
    switch (metric_40) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001938_3813_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001938_3813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_26 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_26 > 23) {
        acc = (acc + index_reg_26 * 2 + 5) & 127;
        aux ^= (index_reg_26 & 15);
    } else {
        acc = (acc - index_reg_26 + 11) & 127;
        aux += 3;
    }
    int window_35 = 0;
    for (int k = 0; k < 2; k++) {
        window_35 = (window_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_35) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_16(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001938_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int threshold_36 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_36 > 16) {
        acc = (acc + threshold_36 * 2 + 5) & 127;
        aux ^= (threshold_36 & 15);
    } else {
        acc = (acc - threshold_36 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_45 = local_arr[aux % 3];
    acc = (acc + segment_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001938_3813_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001938_3813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int segment_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_84) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_27 = (aux + st.buffer[1]) & 3;
    switch (accumulator_27) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_72 = 0;
    for (int k = 0; k < 3; k++) {
        metric_72 = (metric_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001938_3813_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001938_3813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int coefficient_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_92) & 63;
    acc ^= aux;
    int damping_88 = (aux + st.buffer[1]) & 3;
    switch (damping_88) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_50 = 0;
    for (int k = 0; k < 2; k++) {
        offset_50 = (offset_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_50) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001938_0;
    int sec_r001938_1;
    int sec_r001938_2;
    int sec_r001938_3;
    int sec_r001938_4;
    int sec_r001938_5;
    int sec_r001938_6;
    int sec_r001938_7;
    int sec_r001938_8;
    int sec_r001938_9;
    int sec_r001938_10;
    int sec_r001938_11;
    int sec_r001938_12;
    int sec_r001938_13;
    int sec_r001938_14;
    int sec_r001938_15;
    int sec_r001938_16;
    int sec_r001938_17;
    int sec_r001938_18;
    int sec_r001938_19;
    int pub_r001938_0;
    int pub_r001938_1;
    int pub_r001938_2;
    int pub_r001938_3;
    int pub_r001938_4;
    int pub_r001938_5;
    int pub_r001938_6;
    int pub_r001938_7;
    int pub_r001938_8;
    int pub_r001938_9;
    int pub_r001938_10;
    int pub_r001938_11;
    int pub_r001938_12;
    int pub_r001938_13;
    int pub_r001938_14;
    int pub_r001938_15;
    int pub_r001938_16;
    int pub_r001938_17;
    int pub_r001938_18;
    int pub_r001938_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001938_0 >= -100 && pub_r001938_0 <= 100);
    __CPROVER_assume(pub_r001938_1 >= -100 && pub_r001938_1 <= 100);
    __CPROVER_assume(pub_r001938_2 >= -100 && pub_r001938_2 <= 100);
    __CPROVER_assume(pub_r001938_3 >= -100 && pub_r001938_3 <= 100);
    __CPROVER_assume(pub_r001938_4 >= -100 && pub_r001938_4 <= 100);
    __CPROVER_assume(pub_r001938_5 >= -100 && pub_r001938_5 <= 100);
    __CPROVER_assume(pub_r001938_6 >= -100 && pub_r001938_6 <= 100);
    __CPROVER_assume(pub_r001938_7 >= -100 && pub_r001938_7 <= 100);
    __CPROVER_assume(pub_r001938_8 >= -100 && pub_r001938_8 <= 100);
    __CPROVER_assume(pub_r001938_9 >= -100 && pub_r001938_9 <= 100);
    __CPROVER_assume(pub_r001938_10 >= -100 && pub_r001938_10 <= 100);
    __CPROVER_assume(pub_r001938_11 >= -100 && pub_r001938_11 <= 100);
    __CPROVER_assume(pub_r001938_12 >= -100 && pub_r001938_12 <= 100);
    __CPROVER_assume(pub_r001938_13 >= -100 && pub_r001938_13 <= 100);
    __CPROVER_assume(pub_r001938_14 >= -100 && pub_r001938_14 <= 100);
    __CPROVER_assume(pub_r001938_15 >= -100 && pub_r001938_15 <= 100);
    __CPROVER_assume(pub_r001938_16 >= -100 && pub_r001938_16 <= 100);
    __CPROVER_assume(pub_r001938_17 >= -100 && pub_r001938_17 <= 100);
    __CPROVER_assume(pub_r001938_18 >= -100 && pub_r001938_18 <= 100);
    __CPROVER_assume(pub_r001938_19 >= -100 && pub_r001938_19 <= 100);
    __CPROVER_assume(sec_r001938_0 >= 0 && sec_r001938_0 <= 255);
    __CPROVER_assume(sec_r001938_1 >= 0 && sec_r001938_1 <= 255);
    __CPROVER_assume(sec_r001938_2 >= 0 && sec_r001938_2 <= 255);
    __CPROVER_assume(sec_r001938_3 >= 0 && sec_r001938_3 <= 255);
    __CPROVER_assume(sec_r001938_4 >= 0 && sec_r001938_4 <= 255);
    __CPROVER_assume(sec_r001938_5 >= 0 && sec_r001938_5 <= 255);
    __CPROVER_assume(sec_r001938_6 >= 0 && sec_r001938_6 <= 255);
    __CPROVER_assume(sec_r001938_7 >= 0 && sec_r001938_7 <= 255);
    __CPROVER_assume(sec_r001938_8 >= 0 && sec_r001938_8 <= 255);
    __CPROVER_assume(sec_r001938_9 >= 0 && sec_r001938_9 <= 255);
    __CPROVER_assume(sec_r001938_10 >= 0 && sec_r001938_10 <= 255);
    __CPROVER_assume(sec_r001938_11 >= 0 && sec_r001938_11 <= 255);
    __CPROVER_assume(sec_r001938_12 >= 0 && sec_r001938_12 <= 255);
    __CPROVER_assume(sec_r001938_13 >= 0 && sec_r001938_13 <= 255);
    __CPROVER_assume(sec_r001938_14 >= 0 && sec_r001938_14 <= 255);
    __CPROVER_assume(sec_r001938_15 >= 0 && sec_r001938_15 <= 255);
    __CPROVER_assume(sec_r001938_16 >= 0 && sec_r001938_16 <= 255);
    __CPROVER_assume(sec_r001938_17 >= 0 && sec_r001938_17 <= 255);
    __CPROVER_assume(sec_r001938_18 >= 0 && sec_r001938_18 <= 255);
    __CPROVER_assume(sec_r001938_19 >= 0 && sec_r001938_19 <= 255);

    struct SensorNode_R001938_3813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001938_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001938_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001938_0 + 7) & 15;
    struct StreamBuffer_R001938_3813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001938_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001938_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001938_0 + 9) & 15;
    struct FilterState_R001938_3813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001938_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001938_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001938_0 + 11) & 15;
    struct Transaction_R001938_3813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001938_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001938_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001938_0 + 13) & 15;

    union RegisterBank_R001938_3813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001938_3813_0(sec_r001938_0, pub_r001938_1, pub_r001938_2, pub_r001938_3);
    int helper_flow_1 = fn_R001938_3813_1(sec_r001938_1, sec_r001938_2, pub_r001938_3, pub_r001938_4, pub_r001938_5);
    int helper_flow_2 = fn_R001938_3813_2(sec_r001938_2, pub_r001938_3, pub_r001938_4, pub_r001938_5, pub_r001938_6);
    int helper_flow_3 = fn_R001938_3813_3(sec_r001938_3, pub_r001938_4, pub_r001938_5, pub_r001938_6, pub_r001938_7);
    int helper_flow_4 = fn_R001938_3813_4(sec_r001938_4, sec_r001938_5);
    int helper_flow_5 = fn_R001938_3813_5(sec_r001938_5, pub_r001938_6, pub_r001938_7);
    int helper_flow_6 = fn_R001938_3813_6(sec_r001938_6, sec_r001938_7);
    int helper_flow_7 = fn_R001938_3813_7(sec_r001938_7, pub_r001938_8, pub_r001938_9, pub_r001938_10);
    int helper_flow_8 = fn_R001938_3813_8(sec_r001938_8, sec_r001938_9, pub_r001938_10, pub_r001938_11, pub_r001938_12);
    int helper_flow_9 = fn_R001938_3813_9(sec_r001938_9, pub_r001938_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001938_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (sec_r001938_15 & 15)) & 63;
        if ((sec_r001938_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001938_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_4 = (stage_v_4 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_4 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_4 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (sec_r001938_0 & 15)) & 63;
        if ((sec_r001938_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_8 = (stage_v_8 + it * 3 + (sec_r001938_9 & 15)) & 63;
        if ((sec_r001938_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_8 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_8 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_9 = (stage_v_9 + it * 3 + (sec_r001938_16 & 15)) & 63;
        if ((sec_r001938_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_9 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_9 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_10 = (stage_v_10 + it * 3 + (sec_r001938_14 & 15)) & 63;
        if ((sec_r001938_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_10 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_10 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_11 = (stage_v_11 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_11 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_11 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (sec_r001938_12 & 15)) & 63;
        if ((sec_r001938_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_13 = (stage_v_13 + it * 3 + (sec_r001938_2 & 15)) & 63;
        if ((sec_r001938_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_13 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_13 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_14 = (stage_v_14 + it * 3 + (sec_r001938_2 & 15)) & 63;
        if ((sec_r001938_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_14 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_14 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001938_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_16 = (stage_v_16 + it * 3 + (sec_r001938_17 & 15)) & 63;
        if ((sec_r001938_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_16 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_16 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_17 = (stage_v_17 + it * 3 + (sec_r001938_15 & 15)) & 63;
        if ((sec_r001938_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_17 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_17 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_18 = (stage_v_18 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_18 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_18 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001938_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_22 = (stage_v_22 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_22 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_22 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_23 = (stage_v_23 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_23 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_23 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_24 = (stage_v_24 + it * 3 + (sec_r001938_18 & 15)) & 63;
        if ((sec_r001938_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_24 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_24 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_25 = (stage_v_25 + it * 3 + (sec_r001938_14 & 15)) & 63;
        if ((sec_r001938_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_25 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_25 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (stage_v_14 & 15)) & 63;
        if ((stage_v_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001938_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001938_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_29 = (stage_v_29 + it * 3 + (sec_r001938_6 & 15)) & 63;
        if ((sec_r001938_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_29 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_29 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001938_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_31 = (stage_v_31 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_31 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_31 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001938_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_33 = (stage_v_33 + it * 3 + (stage_v_29 & 15)) & 63;
        if ((stage_v_29 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_33 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_33 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_34 = (stage_v_34 + it * 3 + (sec_r001938_5 & 15)) & 63;
        if ((sec_r001938_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_34 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_34 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_35 = (stage_v_35 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_35 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_35 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (sec_r001938_10 & 15)) & 63;
        if ((sec_r001938_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001938_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_39 = (stage_v_39 + it * 3 + (sec_r001938_18 & 15)) & 63;
        if ((sec_r001938_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_39 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_39 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_40 = (stage_v_40 + it * 3 + (sec_r001938_1 & 15)) & 63;
        if ((sec_r001938_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_40 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_40 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001938_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001938_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_44 = (stage_v_44 + it * 3 + (sec_r001938_7 & 15)) & 63;
        if ((sec_r001938_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_44 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_44 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (sec_r001938_3 & 15)) & 63;
        if ((sec_r001938_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (sec_r001938_16 & 15)) & 63;
        if ((sec_r001938_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_47 = (stage_v_47 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_47 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_47 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_48 = (stage_v_48 + it * 3 + (sec_r001938_11 & 15)) & 63;
        if ((sec_r001938_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_48 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_48 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (sec_r001938_6 & 15)) & 63;
        if ((sec_r001938_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_50 = (stage_v_50 + it * 3 + (sec_r001938_14 & 15)) & 63;
        if ((sec_r001938_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_50 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_50 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_51 = (stage_v_51 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_51 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_51 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_52 = (stage_v_52 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_52 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_52 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_54 = (stage_v_54 + it * 3 + (sec_r001938_18 & 15)) & 63;
        if ((sec_r001938_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_54 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_54 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001938_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_56 = (stage_v_56 + it * 3 + (sec_r001938_13 & 15)) & 63;
        if ((sec_r001938_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_56 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_56 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_57 = (stage_v_57 + it * 3 + (stage_v_11 & 15)) & 63;
        if ((stage_v_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_57 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_57 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001938_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_60 = (stage_v_60 + it * 3 + (stage_v_50 & 15)) & 63;
        if ((stage_v_50 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_60 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_60 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_61 = (stage_v_61 + it * 3 + (sec_r001938_4 & 15)) & 63;
        if ((sec_r001938_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_61 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_61 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_62 = (stage_v_62 + it * 3 + (sec_r001938_9 & 15)) & 63;
        if ((sec_r001938_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_62 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_62 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001938_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_64 = (stage_v_64 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_64 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_64 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_65 = (stage_v_65 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_65 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_65 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001938_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_67 = (stage_v_67 + it * 3 + (stage_v_39 & 15)) & 63;
        if ((stage_v_39 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_67 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_67 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_68 = (stage_v_68 + it * 3 + (sec_r001938_11 & 15)) & 63;
        if ((sec_r001938_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_68 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_68 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_69 = (stage_v_69 + it * 3 + (stage_v_54 & 15)) & 63;
        if ((stage_v_54 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_69 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_69 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_70 = (stage_v_70 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_70 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_70 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001938_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001938_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (stage_v_33 & 15)) & 63;
        if ((stage_v_33 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_74 = (stage_v_74 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_74 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_74 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_76 = (stage_v_76 + it * 3 + (stage_v_14 & 15)) & 63;
        if ((stage_v_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_76 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_76 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001938_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (stage_v_49 & 15)) & 63;
        if ((stage_v_49 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (sec_r001938_9 & 15)) & 63;
        if ((sec_r001938_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_80 = (stage_v_80 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_80 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_80 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001938_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001938_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_83 = (stage_v_83 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_83 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_83 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (sec_r001938_5 & 15)) & 63;
        if ((sec_r001938_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (stage_v_49 & 15)) & 63;
        if ((stage_v_49 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001938_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001938_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_88 = (stage_v_88 + it * 3 + (stage_v_33 & 15)) & 63;
        if ((stage_v_33 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_88 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_88 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001938_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_90 = (stage_v_90 + it * 3 + (sec_r001938_14 & 15)) & 63;
        if ((sec_r001938_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_90 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_90 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (sec_r001938_0 & 15)) & 63;
        if ((sec_r001938_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_92 = (stage_v_92 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_92 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_92 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001938_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001938_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001938_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001938_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_97 = (stage_v_97 + it * 3 + (sec_r001938_17 & 15)) & 63;
        if ((sec_r001938_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_97 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_97 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001938_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_99 = (stage_v_99 + it * 3 + (stage_v_65 & 15)) & 63;
        if ((stage_v_65 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_99 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_99 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001938_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_102 = (stage_v_102 + it * 3 + (stage_v_76 & 15)) & 63;
        if ((stage_v_76 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_102 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_102 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_105 = (stage_v_105 + it * 3 + (stage_v_69 & 15)) & 63;
        if ((stage_v_69 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_105 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_105 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_106 = (stage_v_106 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_106 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_106 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_107 = (stage_v_107 + it * 3 + (sec_r001938_5 & 15)) & 63;
        if ((sec_r001938_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_107 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_107 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_108 = (stage_v_108 + it * 3 + (stage_v_61 & 15)) & 63;
        if ((stage_v_61 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_108 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_108 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001938_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001938_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001938_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_112 = (stage_v_112 + it * 3 + (sec_r001938_19 & 15)) & 63;
        if ((sec_r001938_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_112 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_112 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001938_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_114 = (stage_v_114 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_114 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_114 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_115 = (stage_v_115 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_115 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_115 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_116 = (stage_v_116 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_116 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_116 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_117 = (stage_v_117 + it * 3 + (stage_v_99 & 15)) & 63;
        if ((stage_v_99 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_117 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_117 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001938_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_120 = (stage_v_120 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_120 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_120 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001938_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_122 = (stage_v_122 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_122 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_122 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001938_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_124 = (stage_v_124 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_124 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_124 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_125 = (stage_v_125 + it * 3 + (stage_v_114 & 15)) & 63;
        if ((stage_v_114 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_125 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_125 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_126 = (stage_v_126 + it * 3 + (sec_r001938_15 & 15)) & 63;
        if ((sec_r001938_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_126 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_126 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001938_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_129 = (stage_v_129 + it * 3 + (stage_v_106 & 15)) & 63;
        if ((stage_v_106 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_129 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_129 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (stage_v_97 & 15)) & 63;
        if ((stage_v_97 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_131 = (stage_v_131 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_131 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_131 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_132 = (stage_v_132 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_132 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_132 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_133 = (stage_v_133 + it * 3 + (stage_v_107 & 15)) & 63;
        if ((stage_v_107 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_133 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_133 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001938_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_70 & 15)) & 63;
        if ((stage_v_70 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001938_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_137 = (stage_v_137 + it * 3 + (stage_v_104 & 15)) & 63;
        if ((stage_v_104 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_137 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_137 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_138 = (stage_v_138 + it * 3 + (stage_v_122 & 15)) & 63;
        if ((stage_v_122 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_138 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_138 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (stage_v_118 & 15)) & 63;
        if ((stage_v_118 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (stage_v_120 & 15)) & 63;
        if ((stage_v_120 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001938_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_142 = (stage_v_142 + it * 3 + (stage_v_68 & 15)) & 63;
        if ((stage_v_68 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_142 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_142 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001938_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001938_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001938_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_146 = (stage_v_146 + it * 3 + (stage_v_65 & 15)) & 63;
        if ((stage_v_65 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_146 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_146 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_147 = (stage_v_147 + it * 3 + (stage_v_61 & 15)) & 63;
        if ((stage_v_61 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_147 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_147 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (stage_v_80 & 15)) & 63;
        if ((stage_v_80 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001938_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001938_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_107 & 15)) & 63;
        if ((stage_v_107 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_152 = (stage_v_152 + it * 3 + (sec_r001938_11 & 15)) & 63;
        if ((sec_r001938_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_152 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_152 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001938_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001938_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001938_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_156 = (stage_v_156 + it * 3 + (stage_v_59 & 15)) & 63;
        if ((stage_v_59 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_156 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_156 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001938_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_159 = (stage_v_159 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_159 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_159 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001938_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_163 = (stage_v_163 + it * 3 + (stage_v_107 & 15)) & 63;
        if ((stage_v_107 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_163 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_163 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (stage_v_135 & 15)) & 63;
        if ((stage_v_135 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_165 = (stage_v_165 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_165 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_165 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001938_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_167 = (stage_v_167 + it * 3 + (stage_v_105 & 15)) & 63;
        if ((stage_v_105 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_167 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_167 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001938_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_169 = (stage_v_169 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_169 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_169 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001938_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001938_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_103 & 15)) & 63;
        if ((stage_v_103 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_174 = (stage_v_174 + it * 3 + (sec_r001938_16 & 15)) & 63;
        if ((sec_r001938_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_174 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_174 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_175 = (stage_v_175 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_175 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_175 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001938_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001938_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001938_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_180 = (stage_v_180 + it * 3 + (stage_v_133 & 15)) & 63;
        if ((stage_v_133 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_180 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_180 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_181 = (stage_v_181 + it * 3 + (stage_v_8 & 15)) & 63;
        if ((stage_v_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_181 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_181 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001938_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (stage_v_174 & 15)) & 63;
        if ((stage_v_174 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001938_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_185 = (stage_v_185 + it * 3 + (stage_v_14 & 15)) & 63;
        if ((stage_v_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_185 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_185 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (stage_v_39 & 15)) & 63;
        if ((stage_v_39 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001938_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_188 = (stage_v_188 + it * 3 + (sec_r001938_11 & 15)) & 63;
        if ((sec_r001938_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_188 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_188 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_189 = (stage_v_189 + it * 3 + (sec_r001938_10 & 15)) & 63;
        if ((sec_r001938_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_189 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_189 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_190 = (stage_v_190 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_190 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_190 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_191 = (stage_v_191 + it * 3 + (sec_r001938_6 & 15)) & 63;
        if ((sec_r001938_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_191 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_191 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_192 = (stage_v_192 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_192 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_192 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001938_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_194 = (stage_v_194 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_194 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_194 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_195 = (stage_v_195 + it * 3 + (stage_v_122 & 15)) & 63;
        if ((stage_v_122 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_195 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_195 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_196 = (stage_v_196 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_196 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_196 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001938_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_198 = (stage_v_198 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_198 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_198 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001938_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001938_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_201 = (stage_v_201 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_201 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_201 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_202 = (stage_v_202 + it * 3 + (stage_v_99 & 15)) & 63;
        if ((stage_v_99 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_202 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_202 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_203 = (stage_v_203 + it * 3 + (stage_v_146 & 15)) & 63;
        if ((stage_v_146 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_203 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_203 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_204 = (stage_v_204 + it * 3 + (stage_v_11 & 15)) & 63;
        if ((stage_v_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_204 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_204 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001938_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_206 = (stage_v_206 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_206 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_206 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
