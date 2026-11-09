/*
 * Benchmark Program: R001286
 * Security Family: implicit_flow
 * Generator Seed: 628613
 * High Inputs: 18 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001286_8613_0 {
    short parity;
    unsigned char timeout;
    short id;
    int port;
    int baud_rate;
    unsigned char stop_bits;
    int buffer[3];
};

struct FilterState_R001286_8613_1 {
    short mode;
    unsigned char gain_db;
    int cutoff;
    unsigned char prev_in;
    short damping;
    int buffer[3];
};

union TelemetryField_R001286_8613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001286_8613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001286_8613_0(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int metric_32 = (aux + st.buffer[1]) & 3;
    switch (metric_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_17 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_17 > 19) {
        acc = (acc + tracker_17 * 2 + 5) & 127;
        aux ^= (tracker_17 & 15);
    } else {
        acc = (acc - tracker_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001286_8613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_77 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_77 > 14) {
        acc = (acc + weight_77 * 2 + 5) & 127;
        aux ^= (weight_77 & 15);
    } else {
        acc = (acc - weight_77 + 11) & 127;
        aux += 3;
    }
    int pivot_28 = (aux + st.buffer[1]) & 3;
    switch (pivot_28) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001286_8613_2(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int damping_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_57) & 63;
    acc ^= aux;
    int vector_45 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_45 > 25) {
        acc = (acc + vector_45 * 2 + 5) & 127;
        aux ^= (vector_45 & 15);
    } else {
        acc = (acc - vector_45 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_65 = local_arr[aux % 3];
    acc = (acc + damping_65 * 2) & 127;
    int threshold_56 = (aux + st.buffer[1]) & 3;
    switch (threshold_56) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001286_8613_3(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_61 = local_arr[aux % 3];
    acc = (acc + weight_61 * 2) & 127;
    int offset_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001286_8613_4(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int margin_20 = local_arr[aux % 3];
    acc = (acc + margin_20 * 2) & 127;
    int checksum_99 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_99 = (checksum_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_99) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001286_8613_5(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int anchor_99 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_99 = (anchor_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_99) & 127;
    }
    int bound_56 = (aux + st.buffer[1]) & 3;
    switch (bound_56) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_50 = local_arr[aux % 3];
    acc = (acc + anchor_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001286_8613_6(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_52 = (aux + st.buffer[1]) & 3;
    switch (margin_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_28 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_28 = (threshold_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_28) & 127;
    }
    int stride_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001286_8613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_55 = local_arr[aux % 3];
    acc = (acc + mask_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001286_8613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_12 = 0;
    for (int k = 0; k < 2; k++) {
        margin_12 = (margin_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001286_8613_9(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int mask_17 = (aux + st.buffer[1]) & 3;
    switch (mask_17) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_87 = local_arr[aux % 3];
    acc = (acc + tracker_87 * 2) & 127;
    int anchor_95 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_95 > 43) {
        acc = (acc + anchor_95 * 2 + 5) & 127;
        aux ^= (anchor_95 & 15);
    } else {
        acc = (acc - anchor_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001286_8613_10(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_61 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_61 = (threshold_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_61) & 127;
    }
    int residue_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001286_8613_11(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_89 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_89 > 42) {
        acc = (acc + threshold_89 * 2 + 5) & 127;
        aux ^= (threshold_89 & 15);
    } else {
        acc = (acc - threshold_89 + 11) & 127;
        aux += 3;
    }
    int factor_36 = (aux + st.buffer[1]) & 3;
    switch (factor_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001286_8613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int threshold_47 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_47 = (threshold_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_47) & 127;
    }
    int residue_20 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_20 > 17) {
        acc = (acc + residue_20 * 2 + 5) & 127;
        aux ^= (residue_20 & 15);
    } else {
        acc = (acc - residue_20 + 11) & 127;
        aux += 3;
    }
    int segment_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_74) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001286_8613_13(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quotient_47 = (aux + st.buffer[1]) & 3;
    switch (quotient_47) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_20) & 63;
    acc ^= aux;
    int parity_63 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_63 > 27) {
        acc = (acc + parity_63 * 2 + 5) & 127;
        aux ^= (parity_63 & 15);
    } else {
        acc = (acc - parity_63 + 11) & 127;
        aux += 3;
    }
    int coefficient_75 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_75 = (coefficient_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_75) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001286_0;
    int sec_r001286_1;
    int sec_r001286_2;
    int sec_r001286_3;
    int sec_r001286_4;
    int sec_r001286_5;
    int sec_r001286_6;
    int sec_r001286_7;
    int sec_r001286_8;
    int sec_r001286_9;
    int sec_r001286_10;
    int sec_r001286_11;
    int sec_r001286_12;
    int sec_r001286_13;
    int sec_r001286_14;
    int sec_r001286_15;
    int sec_r001286_16;
    int sec_r001286_17;
    int pub_r001286_0;
    int pub_r001286_1;
    int pub_r001286_2;
    int pub_r001286_3;
    int pub_r001286_4;
    int pub_r001286_5;
    int pub_r001286_6;
    int pub_r001286_7;
    int pub_r001286_8;
    int pub_r001286_9;
    int pub_r001286_10;
    int pub_r001286_11;
    int pub_r001286_12;
    int pub_r001286_13;
    int pub_r001286_14;
    int pub_r001286_15;
    int pub_r001286_16;
    int pub_r001286_17;
    int pub_r001286_18;
    int pub_r001286_19;
    int pub_r001286_20;
    int pub_r001286_21;
    int pub_r001286_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001286_0 >= -100 && pub_r001286_0 <= 100);
    __CPROVER_assume(pub_r001286_1 >= -100 && pub_r001286_1 <= 100);
    __CPROVER_assume(pub_r001286_2 >= -100 && pub_r001286_2 <= 100);
    __CPROVER_assume(pub_r001286_3 >= -100 && pub_r001286_3 <= 100);
    __CPROVER_assume(pub_r001286_4 >= -100 && pub_r001286_4 <= 100);
    __CPROVER_assume(pub_r001286_5 >= -100 && pub_r001286_5 <= 100);
    __CPROVER_assume(pub_r001286_6 >= -100 && pub_r001286_6 <= 100);
    __CPROVER_assume(pub_r001286_7 >= -100 && pub_r001286_7 <= 100);
    __CPROVER_assume(pub_r001286_8 >= -100 && pub_r001286_8 <= 100);
    __CPROVER_assume(pub_r001286_9 >= -100 && pub_r001286_9 <= 100);
    __CPROVER_assume(pub_r001286_10 >= -100 && pub_r001286_10 <= 100);
    __CPROVER_assume(pub_r001286_11 >= -100 && pub_r001286_11 <= 100);
    __CPROVER_assume(pub_r001286_12 >= -100 && pub_r001286_12 <= 100);
    __CPROVER_assume(pub_r001286_13 >= -100 && pub_r001286_13 <= 100);
    __CPROVER_assume(pub_r001286_14 >= -100 && pub_r001286_14 <= 100);
    __CPROVER_assume(pub_r001286_15 >= -100 && pub_r001286_15 <= 100);
    __CPROVER_assume(pub_r001286_16 >= -100 && pub_r001286_16 <= 100);
    __CPROVER_assume(pub_r001286_17 >= -100 && pub_r001286_17 <= 100);
    __CPROVER_assume(pub_r001286_18 >= -100 && pub_r001286_18 <= 100);
    __CPROVER_assume(pub_r001286_19 >= -100 && pub_r001286_19 <= 100);
    __CPROVER_assume(pub_r001286_20 >= -100 && pub_r001286_20 <= 100);
    __CPROVER_assume(pub_r001286_21 >= -100 && pub_r001286_21 <= 100);
    __CPROVER_assume(pub_r001286_22 >= -100 && pub_r001286_22 <= 100);
    __CPROVER_assume(sec_r001286_0 >= 0 && sec_r001286_0 <= 255);
    __CPROVER_assume(sec_r001286_1 >= 0 && sec_r001286_1 <= 255);
    __CPROVER_assume(sec_r001286_2 >= 0 && sec_r001286_2 <= 255);
    __CPROVER_assume(sec_r001286_3 >= 0 && sec_r001286_3 <= 255);
    __CPROVER_assume(sec_r001286_4 >= 0 && sec_r001286_4 <= 255);
    __CPROVER_assume(sec_r001286_5 >= 0 && sec_r001286_5 <= 255);
    __CPROVER_assume(sec_r001286_6 >= 0 && sec_r001286_6 <= 255);
    __CPROVER_assume(sec_r001286_7 >= 0 && sec_r001286_7 <= 255);
    __CPROVER_assume(sec_r001286_8 >= 0 && sec_r001286_8 <= 255);
    __CPROVER_assume(sec_r001286_9 >= 0 && sec_r001286_9 <= 255);
    __CPROVER_assume(sec_r001286_10 >= 0 && sec_r001286_10 <= 255);
    __CPROVER_assume(sec_r001286_11 >= 0 && sec_r001286_11 <= 255);
    __CPROVER_assume(sec_r001286_12 >= 0 && sec_r001286_12 <= 255);
    __CPROVER_assume(sec_r001286_13 >= 0 && sec_r001286_13 <= 255);
    __CPROVER_assume(sec_r001286_14 >= 0 && sec_r001286_14 <= 255);
    __CPROVER_assume(sec_r001286_15 >= 0 && sec_r001286_15 <= 255);
    __CPROVER_assume(sec_r001286_16 >= 0 && sec_r001286_16 <= 255);
    __CPROVER_assume(sec_r001286_17 >= 0 && sec_r001286_17 <= 255);

    struct DeviceConfig_R001286_8613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001286_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001286_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001286_0 + 7) & 15;
    struct FilterState_R001286_8613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001286_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001286_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001286_0 + 9) & 15;

    union TelemetryField_R001286_8613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001286_8613_0(sec_r001286_0, pub_r001286_1);
    int helper_flow_1 = fn_R001286_8613_1(sec_r001286_1, pub_r001286_2, pub_r001286_3, pub_r001286_4, pub_r001286_5);
    int helper_flow_2 = fn_R001286_8613_2(sec_r001286_2, sec_r001286_3);
    int helper_flow_3 = fn_R001286_8613_3(sec_r001286_3, pub_r001286_4);
    int helper_flow_4 = fn_R001286_8613_4(sec_r001286_4, sec_r001286_5, pub_r001286_6);
    int helper_flow_5 = fn_R001286_8613_5(sec_r001286_5, sec_r001286_6, pub_r001286_7);
    int helper_flow_6 = fn_R001286_8613_6(sec_r001286_6, pub_r001286_7, pub_r001286_8);
    int helper_flow_7 = fn_R001286_8613_7(sec_r001286_7, sec_r001286_8, pub_r001286_9, pub_r001286_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001286_1 + pub_r001286_8 * 2 + 5) & 127;
    if (stage_v_0 > 42) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001286_5 + pub_r001286_19 * 2 + 8) & 127;
    if (stage_v_1 > 27) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001286_6 + pub_r001286_16 * 2 + 11) & 127;
    if (stage_v_2 > 55) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001286_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001286_15 + pub_r001286_17 * 2 + 17) & 127;
    if (stage_v_4 > 17) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001286_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001286_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001286_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001286_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001286_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001286_1 + pub_r001286_8 * 2 + 35) & 127;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001286_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_4 + pub_r001286_4 * 2 + 41) & 127;
    if (stage_v_12 > 56) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001286_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_3 + pub_r001286_20 * 2 + 47) & 127;
    if (stage_v_14 > 42) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001286_17 + pub_r001286_10 * 2 + 50) & 127;
    if (stage_v_15 > 27) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_0 + pub_r001286_10 * 2 + 53) & 127;
    if (stage_v_16 > 53) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001286_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_16 + pub_r001286_18 * 2 + 59) & 127;
    if (stage_v_18 > 48) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_16 + pub_r001286_8 * 2 + 62) & 127;
    if (stage_v_19 > 15) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_14 + pub_r001286_15 * 2 + 65) & 127;
    if (stage_v_20 > 46) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001286_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001286_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001286_16 + pub_r001286_3 * 2 + 74) & 127;
    if (stage_v_23 > 22) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001286_21 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001286_0 + pub_r001286_15 * 2 + 80) & 127;
    if (stage_v_25 > 17) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001286_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001286_3 + pub_r001286_4 * 2 + 86) & 127;
    if (stage_v_27 > 16) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001286_21 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001286_8 + pub_r001286_0 * 2 + 92) & 127;
    if (stage_v_29 > 26) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001286_3 + pub_r001286_10 * 2 + 95) & 127;
    if (stage_v_30 > 52) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_23 + pub_r001286_8 * 2 + 98) & 127;
    if (stage_v_31 > 56) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_15 + pub_r001286_19 * 2 + 101) & 127;
    if (stage_v_32 > 39) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_4 + pub_r001286_12 * 2 + 104) & 127;
    if (stage_v_33 > 25) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_30 + pub_r001286_5 * 2 + 107) & 127;
    if (stage_v_34 > 50) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001286_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001286_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_1 + pub_r001286_10 * 2 + 116) & 127;
    if (stage_v_37 > 48) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001286_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001286_22 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_14 + pub_r001286_18 * 2 + 125) & 127;
    if (stage_v_40 > 24) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001286_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_12 + pub_r001286_22 * 2 + 131) & 127;
    if (stage_v_42 > 42) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001286_1 + pub_r001286_13 * 2 + 134) & 127;
    if (stage_v_43 > 46) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001286_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001286_1 + pub_r001286_13 * 2 + 140) & 127;
    if (stage_v_45 > 33) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001286_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_29 + pub_r001286_16 * 2 + 146) & 127;
    if (stage_v_47 > 17) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_16 + pub_r001286_15 * 2 + 149) & 127;
    if (stage_v_48 > 59) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001286_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001286_1 + pub_r001286_17 * 2 + 155) & 127;
    if (stage_v_50 > 29) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_4 + pub_r001286_20 * 2 + 158) & 127;
    if (stage_v_51 > 39) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_32 + pub_r001286_12 * 2 + 161) & 127;
    if (stage_v_52 > 49) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_20 + pub_r001286_16 * 2 + 164) & 127;
    if (stage_v_53 > 16) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001286_21 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001286_16 + pub_r001286_8 * 2 + 170) & 127;
    if (stage_v_55 > 35) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_37 + pub_r001286_7 * 2 + 173) & 127;
    if (stage_v_56 > 46) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_52 + pub_r001286_16 * 2 + 176) & 127;
    if (stage_v_57 > 31) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_45 + pub_r001286_2 * 2 + 179) & 127;
    if (stage_v_58 > 24) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001286_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_4 + pub_r001286_21 * 2 + 185) & 127;
    if (stage_v_60 > 17) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_53 + pub_r001286_21 * 2 + 188) & 127;
    if (stage_v_61 > 20) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_32 + pub_r001286_16 * 2 + 191) & 127;
    if (stage_v_62 > 28) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_31 + pub_r001286_3 * 2 + 194) & 127;
    if (stage_v_63 > 35) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_4 + pub_r001286_16 * 2 + 197) & 127;
    if (stage_v_64 > 35) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_43 + pub_r001286_6 * 2 + 200) & 127;
    if (stage_v_65 > 29) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001286_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_65 + pub_r001286_11 * 2 + 206) & 127;
    if (stage_v_67 > 15) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (helper_flow_3 + pub_r001286_15 * 2 + 209) & 127;
    if (stage_v_68 > 37) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001286_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001286_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_20 + pub_r001286_6 * 2 + 218) & 127;
    if (stage_v_71 > 49) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_42 + pub_r001286_4 * 2 + 221) & 127;
    if (stage_v_72 > 60) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001286_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_23 + pub_r001286_0 * 2 + 227) & 127;
    if (stage_v_74 > 17) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001286_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001286_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001286_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_37 + pub_r001286_13 * 2 + 239) & 127;
    if (stage_v_78 > 50) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_16 + pub_r001286_12 * 2 + 242) & 127;
    if (stage_v_79 > 23) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_37 + pub_r001286_9 * 2 + 245) & 127;
    if (stage_v_80 > 33) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_74 + pub_r001286_22 * 2 + 248) & 127;
    if (stage_v_81 > 51) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001286_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001286_12 + pub_r001286_9 * 2 + 254) & 127;
    if (stage_v_83 > 35) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001286_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_10 + pub_r001286_19 * 2 + 260) & 127;
    if (stage_v_85 > 59) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001286_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_43 + pub_r001286_7 * 2 + 266) & 127;
    if (stage_v_87 > 38) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001286_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001286_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001286_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_23 + pub_r001286_3 * 2 + 278) & 127;
    if (stage_v_91 > 33) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001286_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001286_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001286_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_48 + pub_r001286_1 * 2 + 290) & 127;
    if (stage_v_95 > 58) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_80 + pub_r001286_6 * 2 + 293) & 127;
    if (stage_v_96 > 50) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_55 + pub_r001286_20 * 2 + 296) & 127;
    if (stage_v_97 > 34) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001286_11 + pub_r001286_4 * 2 + 299) & 127;
    if (stage_v_98 > 55) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (helper_flow_0 + pub_r001286_6 * 2 + 302) & 127;
    if (stage_v_99 > 48) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_57 + pub_r001286_4 * 2 + 305) & 127;
    if (stage_v_100 > 50) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (helper_flow_0 + pub_r001286_15 * 2 + 308) & 127;
    if (stage_v_101 > 24) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_30 + pub_r001286_14 * 2 + 311) & 127;
    if (stage_v_102 > 16) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001286_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_56 + pub_r001286_3 * 2 + 317) & 127;
    if (stage_v_104 > 55) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001286_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001286_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_7 + pub_r001286_1 * 2 + 326) & 127;
    if (stage_v_107 > 42) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (helper_flow_2 + pub_r001286_1 * 2 + 329) & 127;
    if (stage_v_108 > 57) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001286_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_87 + pub_r001286_6 * 2 + 335) & 127;
    if (stage_v_110 > 23) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_0 + pub_r001286_13 * 2 + 338) & 127;
    if (stage_v_111 > 52) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001286_13 + pub_r001286_21 * 2 + 341) & 127;
    if (stage_v_112 > 36) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_0 + pub_r001286_9 * 2 + 344) & 127;
    if (stage_v_113 > 17) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_40 + pub_r001286_13 * 2 + 347) & 127;
    if (stage_v_114 > 31) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_40 + pub_r001286_22 * 2 + 350) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001286_15 + pub_r001286_0 * 2 + 353) & 127;
    if (stage_v_116 > 48) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001286_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001286_21 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_87 + pub_r001286_7 * 2 + 362) & 127;
    if (stage_v_119 > 48) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_0 + pub_r001286_6 * 2 + 365) & 127;
    if (stage_v_120 > 41) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_55 + pub_r001286_5 * 2 + 368) & 127;
    if (stage_v_121 > 42) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r001286_9 + pub_r001286_13 * 2 + 371) & 127;
    if (stage_v_122 > 17) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_50 + pub_r001286_3 * 2 + 374) & 127;
    if (stage_v_123 > 27) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (helper_flow_4 + pub_r001286_19 * 2 + 377) & 127;
    if (stage_v_124 > 26) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001286_5 + pub_r001286_0 * 2 + 380) & 127;
    if (stage_v_125 > 60) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001286_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001286_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_124 + pub_r001286_4 * 2 + 389) & 127;
    if (stage_v_128 > 38) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_10 + pub_r001286_13 * 2 + 392) & 127;
    if (stage_v_129 > 55) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r001286_7 + pub_r001286_16 * 2 + 395) & 127;
    if (stage_v_130 > 16) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (helper_flow_0 + pub_r001286_10 * 2 + 398) & 127;
    if (stage_v_131 > 54) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001286_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_120 + pub_r001286_8 * 2 + 404) & 127;
    if (stage_v_133 > 33) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_130 + pub_r001286_8 * 2 + 407) & 127;
    if (stage_v_134 > 16) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001286_11 + pub_r001286_12 * 2 + 410) & 127;
    if (stage_v_135 > 34) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_42 + pub_r001286_18 * 2 + 413) & 127;
    if (stage_v_136 > 59) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_58 + pub_r001286_1 * 2 + 416) & 127;
    if (stage_v_137 > 46) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001286_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_10 + pub_r001286_15 * 2 + 422) & 127;
    if (stage_v_139 > 41) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001286_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001286_21 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_137 + pub_r001286_13 * 2 + 431) & 127;
    if (stage_v_142 > 18) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_78 + pub_r001286_4 * 2 + 434) & 127;
    if (stage_v_143 > 56) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_67 + pub_r001286_8 * 2 + 437) & 127;
    if (stage_v_144 > 39) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001286_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_129 + pub_r001286_14 * 2 + 443) & 127;
    if (stage_v_146 > 34) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_123 + pub_r001286_16 * 2 + 446) & 127;
    if (stage_v_147 > 16) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001286_10 + pub_r001286_21 * 2 + 449) & 127;
    if (stage_v_148 > 57) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_33 + pub_r001286_17 * 2 + 452) & 127;
    if (stage_v_149 > 39) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001286_21 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001286_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r001286_13 + pub_r001286_19 * 2 + 461) & 127;
    if (stage_v_152 > 17) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001286_21 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_2 + pub_r001286_14 * 2 + 467) & 127;
    if (stage_v_154 > 32) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_78 + pub_r001286_6 * 2 + 470) & 127;
    if (stage_v_155 > 49) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_71 + pub_r001286_7 * 2 + 473) & 127;
    if (stage_v_156 > 29) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_63 + pub_r001286_1 * 2 + 476) & 127;
    if (stage_v_157 > 25) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001286_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_32 + pub_r001286_0 * 2 + 482) & 127;
    if (stage_v_159 > 32) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001286_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_97 + pub_r001286_1 * 2 + 488) & 127;
    if (stage_v_161 > 47) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_71 + pub_r001286_11 * 2 + 491) & 127;
    if (stage_v_162 > 20) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_72 + pub_r001286_11 * 2 + 494) & 127;
    if (stage_v_163 > 21) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_128 + pub_r001286_4 * 2 + 497) & 127;
    if (stage_v_164 > 15) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001286_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (sec_r001286_2 + pub_r001286_5 * 2 + 503) & 127;
    if (stage_v_166 > 43) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_102 + pub_r001286_5 * 2 + 506) & 127;
    if (stage_v_167 > 48) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_148 + pub_r001286_12 * 2 + 509) & 127;
    if (stage_v_168 > 26) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_107 + pub_r001286_22 * 2 + 512) & 127;
    if (stage_v_169 > 37) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001286_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_0 + pub_r001286_20 * 2 + 518) & 127;
    if (stage_v_171 > 57) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001286_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_2 + pub_r001286_5 * 2 + 524) & 127;
    if (stage_v_173 > 27) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001286_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001286_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_40 + pub_r001286_13 * 2 + 533) & 127;
    if (stage_v_176 > 16) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_166 + pub_r001286_0 * 2 + 536) & 127;
    if (stage_v_177 > 45) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001286_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001286_22 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_4 + pub_r001286_17 * 2 + 545) & 127;
    if (stage_v_180 > 45) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001286_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001286_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001286_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_131 + pub_r001286_3 * 2 + 557) & 127;
    if (stage_v_184 > 51) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_146 + pub_r001286_8 * 2 + 560) & 127;
    if (stage_v_185 > 50) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (helper_flow_0 + pub_r001286_20 * 2 + 563) & 127;
    if (stage_v_186 > 40) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001286_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001286_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_113 + pub_r001286_7 * 2 + 572) & 127;
    if (stage_v_189 > 50) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_130 + pub_r001286_15 * 2 + 575) & 127;
    if (stage_v_190 > 38) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_116 + pub_r001286_12 * 2 + 578) & 127;
    if (stage_v_191 > 29) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_10 + pub_r001286_12 * 2 + 581) & 127;
    if (stage_v_192 > 16) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (sec_r001286_10 + pub_r001286_7 * 2 + 584) & 127;
    if (stage_v_193 > 37) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001286_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_128 + pub_r001286_17 * 2 + 590) & 127;
    if (stage_v_195 > 58) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001286_21 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001286_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_142 + pub_r001286_8 * 2 + 599) & 127;
    if (stage_v_198 > 26) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001286_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_171 + pub_r001286_3 * 2 + 605) & 127;
    if (stage_v_200 > 43) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001286_6 + pub_r001286_19 * 2 + 608) & 127;
    if (stage_v_201 > 30) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001286_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001286_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_101 + pub_r001286_20 * 2 + 617) & 127;
    if (stage_v_204 > 60) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (sec_r001286_13 + pub_r001286_21 * 2 + 620) & 127;
    if (stage_v_205 > 51) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_148 + pub_r001286_10 * 2 + 623) & 127;
    if (stage_v_206 > 17) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_122 + pub_r001286_16 * 2 + 626) & 127;
    if (stage_v_207 > 53) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001286_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001286_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_48 + pub_r001286_2 * 2 + 635) & 127;
    if (stage_v_210 > 16) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_128 + pub_r001286_2 * 2 + 638) & 127;
    if (stage_v_211 > 60) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001286_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001286_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r001286_15 + pub_r001286_1 * 2 + 647) & 127;
    if (stage_v_214 > 39) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_163 + pub_r001286_0 * 2 + 650) & 127;
    if (stage_v_215 > 30) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001286_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001286_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001286_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001286_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_57 + pub_r001286_21 * 2 + 665) & 127;
    if (stage_v_220 > 37) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_20 + pub_r001286_18 * 2 + 668) & 127;
    if (stage_v_221 > 27) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_45 + pub_r001286_14 * 2 + 671) & 127;
    if (stage_v_222 > 15) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001286_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_207 + pub_r001286_15 * 2 + 677) & 127;
    if (stage_v_224 > 15) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (sec_r001286_9 + pub_r001286_22 * 2 + 680) & 127;
    if (stage_v_225 > 46) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_56 + pub_r001286_19 * 2 + 683) & 127;
    if (stage_v_226 > 44) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001286_21 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001286_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_121 + pub_r001286_13 * 2 + 692) & 127;
    if (stage_v_229 > 57) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_129 + pub_r001286_17 * 2 + 695) & 127;
    if (stage_v_230 > 51) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_210 + pub_r001286_3 * 2 + 698) & 127;
    if (stage_v_231 > 58) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_31 + pub_r001286_10 * 2 + 701) & 127;
    if (stage_v_232 > 39) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_192 + pub_r001286_15 * 2 + 704) & 127;
    if (stage_v_233 > 49) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_112 + pub_r001286_9 * 2 + 707) & 127;
    if (stage_v_234 > 56) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001286_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001286_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_221 + pub_r001286_2 * 2 + 716) & 127;
    if (stage_v_237 > 48) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_119 + pub_r001286_22 * 2 + 719) & 127;
    if (stage_v_238 > 45) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_19 + pub_r001286_1 * 2 + 722) & 127;
    if (stage_v_239 > 22) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001286_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_162 + pub_r001286_17 * 2 + 728) & 127;
    if (stage_v_241 > 39) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001286_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (helper_flow_7 + pub_r001286_18 * 2 + 734) & 127;
    if (stage_v_243 > 21) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_78 + pub_r001286_19 * 2 + 737) & 127;
    if (stage_v_244 > 44) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001286_22 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_20 + pub_r001286_4 * 2 + 743) & 127;
    if (stage_v_246 > 24) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001286_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_122 + pub_r001286_3 * 2 + 749) & 127;
    if (stage_v_248 > 42) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
        sec_accum ^= (stage_v_248 & 31);
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (sec_r001286_11 + pub_r001286_21 * 2 + 752) & 127;
    if (stage_v_249 > 17) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
        sec_accum ^= (stage_v_249 & 31);
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_16 + pub_r001286_10 * 2 + 755) & 127;
    if (stage_v_250 > 44) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
        sec_accum ^= (stage_v_250 & 31);
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_37 + pub_r001286_2 * 2 + 758) & 127;
    if (stage_v_251 > 59) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001286_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_122 + pub_r001286_0 * 2 + 764) & 127;
    if (stage_v_253 > 16) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
