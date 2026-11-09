/*
 * Benchmark Program: R001772
 * Security Family: direct_leakage
 * Generator Seed: 677213
 * High Inputs: 23 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001772_7213_0 {
    short damping;
    unsigned char gain_db;
    int prev_out;
    int mode;
    int buffer[3];
};

struct Transaction_R001772_7213_1 {
    unsigned char account_id;
    int balance;
    int rate;
    int fee;
    int auth_code;
    int buffer[3];
};

struct SensorNode_R001772_7213_2 {
    int reading;
    short calib;
    unsigned char gain;
    int buffer[3];
};

union TelemetryField_R001772_7213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001772_7213_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int factor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_83 = local_arr[aux % 3];
    acc = (acc + window_83 * 2) & 127;
    int accumulator_22 = (aux + st.buffer[1]) & 3;
    switch (accumulator_22) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_94 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_94 > 32) {
        acc = (acc + parity_94 * 2 + 5) & 127;
        aux ^= (parity_94 & 15);
    } else {
        acc = (acc - parity_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001772_7213_1(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001772_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_77 = (aux + st.buffer[1]) & 3;
    switch (residue_77) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_68) & 63;
    acc ^= aux;
    int mask_17 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_17 > 24) {
        acc = (acc + mask_17 * 2 + 5) & 127;
        aux ^= (mask_17 & 15);
    } else {
        acc = (acc - mask_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001772_7213_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int tally_64 = local_arr[aux % 3];
    acc = (acc + tally_64 * 2) & 127;
    int pivot_95 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_95 > 22) {
        acc = (acc + pivot_95 * 2 + 5) & 127;
        aux ^= (pivot_95 & 15);
    } else {
        acc = (acc - pivot_95 + 11) & 127;
        aux += 3;
    }
    int parity_49 = 0;
    for (int k = 0; k < 3; k++) {
        parity_49 = (parity_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001772_7213_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_84 = 0;
    for (int k = 0; k < 2; k++) {
        bound_84 = (bound_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_84) & 127;
    }
    int bound_60 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_60 > 23) {
        acc = (acc + bound_60 * 2 + 5) & 127;
        aux ^= (bound_60 & 15);
    } else {
        acc = (acc - bound_60 + 11) & 127;
        aux += 3;
    }
    int coefficient_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_87) & 63;
    acc ^= aux;
    int phase_91 = (aux + st.buffer[1]) & 3;
    switch (phase_91) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001772_7213_4(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001772_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int delta_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_15) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_92 = local_arr[aux % 3];
    acc = (acc + accumulator_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001772_7213_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001772_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int margin_82 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_82 > 25) {
        acc = (acc + margin_82 * 2 + 5) & 127;
        aux ^= (margin_82 & 15);
    } else {
        acc = (acc - margin_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001772_7213_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001772_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int damping_33 = (aux + st.buffer[1]) & 3;
    switch (damping_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_60 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_60 > 14) {
        acc = (acc + threshold_60 * 2 + 5) & 127;
        aux ^= (threshold_60 & 15);
    } else {
        acc = (acc - threshold_60 + 11) & 127;
        aux += 3;
    }
    int weight_32 = 0;
    for (int k = 0; k < 2; k++) {
        weight_32 = (weight_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_32) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_37 = local_arr[aux % 3];
    acc = (acc + parity_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001772_7213_7(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_83 = (aux + st.buffer[1]) & 3;
    switch (window_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_75 = local_arr[aux % 3];
    acc = (acc + quotient_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001772_7213_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int offset_30 = (aux + st.buffer[1]) & 3;
    switch (offset_30) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_86 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_86 > 38) {
        acc = (acc + scale_86 * 2 + 5) & 127;
        aux ^= (scale_86 & 15);
    } else {
        acc = (acc - scale_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001772_7213_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_64 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_64 = (quotient_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_64) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_84 = local_arr[aux % 3];
    acc = (acc + margin_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001772_7213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int margin_83 = 0;
    for (int k = 0; k < 2; k++) {
        margin_83 = (margin_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_83) & 127;
    }
    int accumulator_50 = (aux + st.buffer[1]) & 3;
    switch (accumulator_50) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_92 = local_arr[aux % 3];
    acc = (acc + checksum_92 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001772_7213_11(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001772_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int delta_34 = local_arr[aux % 3];
    acc = (acc + delta_34 * 2) & 127;
    int index_reg_97 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_97 > 28) {
        acc = (acc + index_reg_97 * 2 + 5) & 127;
        aux ^= (index_reg_97 & 15);
    } else {
        acc = (acc - index_reg_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001772_7213_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001772_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_35) & 63;
    acc ^= aux;
    int tracker_94 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_94 > 29) {
        acc = (acc + tracker_94 * 2 + 5) & 127;
        aux ^= (tracker_94 & 15);
    } else {
        acc = (acc - tracker_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001772_7213_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001772_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int damping_91 = (aux + st.buffer[1]) & 3;
    switch (damping_91) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_48 = local_arr[aux % 3];
    acc = (acc + damping_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_17 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_17 = (threshold_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_17) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001772_0;
    int sec_r001772_1;
    int sec_r001772_2;
    int sec_r001772_3;
    int sec_r001772_4;
    int sec_r001772_5;
    int sec_r001772_6;
    int sec_r001772_7;
    int sec_r001772_8;
    int sec_r001772_9;
    int sec_r001772_10;
    int sec_r001772_11;
    int sec_r001772_12;
    int sec_r001772_13;
    int sec_r001772_14;
    int sec_r001772_15;
    int sec_r001772_16;
    int sec_r001772_17;
    int sec_r001772_18;
    int sec_r001772_19;
    int sec_r001772_20;
    int sec_r001772_21;
    int sec_r001772_22;
    int pub_r001772_0;
    int pub_r001772_1;
    int pub_r001772_2;
    int pub_r001772_3;
    int pub_r001772_4;
    int pub_r001772_5;
    int pub_r001772_6;
    int pub_r001772_7;
    int pub_r001772_8;
    int pub_r001772_9;
    int pub_r001772_10;
    int pub_r001772_11;
    int pub_r001772_12;
    int pub_r001772_13;
    int pub_r001772_14;
    int pub_r001772_15;
    int pub_r001772_16;
    int pub_r001772_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001772_0 >= -100 && pub_r001772_0 <= 100);
    __CPROVER_assume(pub_r001772_1 >= -100 && pub_r001772_1 <= 100);
    __CPROVER_assume(pub_r001772_2 >= -100 && pub_r001772_2 <= 100);
    __CPROVER_assume(pub_r001772_3 >= -100 && pub_r001772_3 <= 100);
    __CPROVER_assume(pub_r001772_4 >= -100 && pub_r001772_4 <= 100);
    __CPROVER_assume(pub_r001772_5 >= -100 && pub_r001772_5 <= 100);
    __CPROVER_assume(pub_r001772_6 >= -100 && pub_r001772_6 <= 100);
    __CPROVER_assume(pub_r001772_7 >= -100 && pub_r001772_7 <= 100);
    __CPROVER_assume(pub_r001772_8 >= -100 && pub_r001772_8 <= 100);
    __CPROVER_assume(pub_r001772_9 >= -100 && pub_r001772_9 <= 100);
    __CPROVER_assume(pub_r001772_10 >= -100 && pub_r001772_10 <= 100);
    __CPROVER_assume(pub_r001772_11 >= -100 && pub_r001772_11 <= 100);
    __CPROVER_assume(pub_r001772_12 >= -100 && pub_r001772_12 <= 100);
    __CPROVER_assume(pub_r001772_13 >= -100 && pub_r001772_13 <= 100);
    __CPROVER_assume(pub_r001772_14 >= -100 && pub_r001772_14 <= 100);
    __CPROVER_assume(pub_r001772_15 >= -100 && pub_r001772_15 <= 100);
    __CPROVER_assume(pub_r001772_16 >= -100 && pub_r001772_16 <= 100);
    __CPROVER_assume(pub_r001772_17 >= -100 && pub_r001772_17 <= 100);
    __CPROVER_assume(sec_r001772_0 >= 0 && sec_r001772_0 <= 255);
    __CPROVER_assume(sec_r001772_1 >= 0 && sec_r001772_1 <= 255);
    __CPROVER_assume(sec_r001772_2 >= 0 && sec_r001772_2 <= 255);
    __CPROVER_assume(sec_r001772_3 >= 0 && sec_r001772_3 <= 255);
    __CPROVER_assume(sec_r001772_4 >= 0 && sec_r001772_4 <= 255);
    __CPROVER_assume(sec_r001772_5 >= 0 && sec_r001772_5 <= 255);
    __CPROVER_assume(sec_r001772_6 >= 0 && sec_r001772_6 <= 255);
    __CPROVER_assume(sec_r001772_7 >= 0 && sec_r001772_7 <= 255);
    __CPROVER_assume(sec_r001772_8 >= 0 && sec_r001772_8 <= 255);
    __CPROVER_assume(sec_r001772_9 >= 0 && sec_r001772_9 <= 255);
    __CPROVER_assume(sec_r001772_10 >= 0 && sec_r001772_10 <= 255);
    __CPROVER_assume(sec_r001772_11 >= 0 && sec_r001772_11 <= 255);
    __CPROVER_assume(sec_r001772_12 >= 0 && sec_r001772_12 <= 255);
    __CPROVER_assume(sec_r001772_13 >= 0 && sec_r001772_13 <= 255);
    __CPROVER_assume(sec_r001772_14 >= 0 && sec_r001772_14 <= 255);
    __CPROVER_assume(sec_r001772_15 >= 0 && sec_r001772_15 <= 255);
    __CPROVER_assume(sec_r001772_16 >= 0 && sec_r001772_16 <= 255);
    __CPROVER_assume(sec_r001772_17 >= 0 && sec_r001772_17 <= 255);
    __CPROVER_assume(sec_r001772_18 >= 0 && sec_r001772_18 <= 255);
    __CPROVER_assume(sec_r001772_19 >= 0 && sec_r001772_19 <= 255);
    __CPROVER_assume(sec_r001772_20 >= 0 && sec_r001772_20 <= 255);
    __CPROVER_assume(sec_r001772_21 >= 0 && sec_r001772_21 <= 255);
    __CPROVER_assume(sec_r001772_22 >= 0 && sec_r001772_22 <= 255);

    struct FilterState_R001772_7213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001772_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001772_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001772_0 + 7) & 15;
    struct Transaction_R001772_7213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001772_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001772_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001772_0 + 9) & 15;
    struct SensorNode_R001772_7213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001772_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001772_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001772_0 + 11) & 15;

    union TelemetryField_R001772_7213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001772_7213_0(sec_r001772_0, pub_r001772_1, pub_r001772_2, pub_r001772_3, pub_r001772_4);
    int helper_flow_1 = fn_R001772_7213_1(sec_r001772_1, sec_r001772_2, pub_r001772_3);
    int helper_flow_2 = fn_R001772_7213_2(sec_r001772_2, pub_r001772_3, pub_r001772_4, pub_r001772_5);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001772_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001772_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001772_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001772_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001772_6 * 3) + pub_r001772_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001772_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001772_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001772_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001772_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001772_22 * 3) + pub_r001772_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_0 * 3) + pub_r001772_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001772_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001772_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001772_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001772_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001772_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001772_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001772_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001772_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001772_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_1 * 3) + pub_r001772_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001772_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001772_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001772_18 * 3) + pub_r001772_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001772_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001772_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001772_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001772_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001772_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001772_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001772_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001772_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001772_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_9 * 3) + pub_r001772_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001772_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001772_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001772_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001772_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001772_7 * 3) + pub_r001772_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38 * 2) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001772_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001772_22 * 3) + pub_r001772_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001772_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001772_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001772_0 * 3) + pub_r001772_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001772_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001772_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001772_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001772_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001772_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001772_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001772_11 * 3) + pub_r001772_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001772_15 * 3) + pub_r001772_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001772_7 * 3) + pub_r001772_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001772_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001772_14 * 3) + pub_r001772_9 + 38) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_33 * 3) + pub_r001772_12 + 24) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55 * 2) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001772_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001772_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001772_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001772_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((helper_flow_2 * 3) + pub_r001772_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001772_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001772_20 * 3) + pub_r001772_15 + 22) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62 * 2) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001772_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001772_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001772_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001772_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001772_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001772_8 * 3) + pub_r001772_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001772_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001772_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001772_10 * 3) + pub_r001772_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001772_7 * 3) + pub_r001772_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001772_22 * 3) + pub_r001772_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73 * 2) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001772_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001772_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001772_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001772_14 * 3) + pub_r001772_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001772_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_68 * 3) + pub_r001772_8 + 44) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001772_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001772_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001772_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001772_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001772_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001772_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_38 * 3) + pub_r001772_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((helper_flow_0 * 3) + pub_r001772_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001772_22 * 3) + pub_r001772_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_4 * 3) + pub_r001772_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_4 * 3) + pub_r001772_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001772_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_73 * 3) + pub_r001772_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001772_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001772_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001772_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001772_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001772_19 * 3) + pub_r001772_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001772_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_87 * 3) + pub_r001772_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((helper_flow_2 * 3) + pub_r001772_17 + 42) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_77 * 3) + pub_r001772_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001772_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_97 * 3) + pub_r001772_6 + 33) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103 * 2) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001772_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001772_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001772_20 * 3) + pub_r001772_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001772_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001772_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001772_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001772_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_4 * 3) + pub_r001772_10 + 9) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001772_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001772_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001772_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001772_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001772_2 * 3) + pub_r001772_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001772_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001772_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001772_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001772_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_43 * 3) + pub_r001772_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001772_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001772_15 * 3) + pub_r001772_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123 * 2) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001772_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((helper_flow_2 * 3) + pub_r001772_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_33 * 3) + pub_r001772_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126 * 2) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001772_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001772_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001772_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001772_1 * 3) + pub_r001772_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001772_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_86 * 3) + pub_r001772_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132 * 2) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001772_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001772_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001772_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001772_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_123 * 3) + pub_r001772_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137 * 2) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001772_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001772_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_73 * 3) + pub_r001772_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140 * 2) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001772_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r001772_11 * 3) + pub_r001772_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((helper_flow_2 * 3) + pub_r001772_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001772_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001772_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001772_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001772_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001772_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001772_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001772_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001772_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001772_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001772_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001772_11 * 3) + pub_r001772_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_130 * 3) + pub_r001772_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155 * 2) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001772_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001772_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001772_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001772_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001772_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001772_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001772_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001772_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001772_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001772_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001772_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_54 * 3) + pub_r001772_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167 * 2) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001772_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001772_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_126 * 3) + pub_r001772_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_140 * 3) + pub_r001772_4 + 42) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001772_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001772_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001772_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001772_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001772_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001772_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001772_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_87 * 3) + pub_r001772_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001772_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((helper_flow_2 * 3) + pub_r001772_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181 * 2) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001772_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001772_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001772_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001772_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001772_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001772_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r001772_2 * 3) + pub_r001772_14 + 41) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188 * 2) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001772_11 * 3) + pub_r001772_12 + 15) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189 * 2) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001772_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_73 * 3) + pub_r001772_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_54 * 3) + pub_r001772_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192 * 2) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001772_16 * 3) + pub_r001772_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001772_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001772_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001772_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_111 * 3) + pub_r001772_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001772_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001772_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001772_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001772_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001772_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001772_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001772_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001772_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001772_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001772_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001772_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_55 * 3) + pub_r001772_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209 * 2) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r001772_19 * 3) + pub_r001772_12 + 9) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001772_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001772_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001772_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001772_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_77 * 3) + pub_r001772_15 + 32) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_79 * 3) + pub_r001772_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r001772_9 * 3) + pub_r001772_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r001772_12 * 3) + pub_r001772_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001772_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001772_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((sec_r001772_6 * 3) + pub_r001772_11 + 31) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001772_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001772_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001772_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001772_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001772_3 * 3) + pub_r001772_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001772_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001772_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r001772_5 * 3) + pub_r001772_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001772_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_68 * 3) + pub_r001772_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231 * 2) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((sec_r001772_11 * 3) + pub_r001772_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232 * 2) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r001772_6 * 3) + pub_r001772_11 + 29) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001772_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((helper_flow_0 * 3) + pub_r001772_15 + 12) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001772_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001772_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001772_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001772_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001772_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_103 * 3) + pub_r001772_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241 * 2) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001772_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_126 * 3) + pub_r001772_17 + 38) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243 * 2) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_232 * 3) + pub_r001772_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001772_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001772_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001772_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((sec_r001772_6 * 3) + pub_r001772_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248 * 2) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001772_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001772_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001772_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001772_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001772_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001772_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001772_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r001772_21 * 3) + pub_r001772_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001772_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001772_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001772_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001772_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001772_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_154 * 3) + pub_r001772_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((helper_flow_1 * 3) + pub_r001772_17 + 8) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263 * 2) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_103 * 3) + pub_r001772_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001772_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_87 * 3) + pub_r001772_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001772_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001772_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_262 * 3) + pub_r001772_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_73 * 3) + pub_r001772_14 + 18) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001772_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001772_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001772_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001772_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((sec_r001772_20 * 3) + pub_r001772_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001772_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001772_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001772_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_170 * 3) + pub_r001772_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001772_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001772_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001772_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001772_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001772_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_264 * 3) + pub_r001772_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001772_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_192 * 3) + pub_r001772_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287 * 2) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001772_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001772_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_137 * 3) + pub_r001772_3 + 5) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001772_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_86 * 3) + pub_r001772_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_218 * 3) + pub_r001772_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001772_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001772_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_88 * 3) + pub_r001772_0 + 15) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001772_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001772_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001772_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001772_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_181 * 3) + pub_r001772_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001772_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((sec_r001772_16 * 3) + pub_r001772_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001772_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001772_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001772_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001772_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001772_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_90 * 3) + pub_r001772_14 + 39) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001772_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001772_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001772_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001772_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_86 * 3) + pub_r001772_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314 * 2) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_123 * 3) + pub_r001772_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001772_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_170 * 3) + pub_r001772_3 + 7) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317 * 2) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_167 * 3) + pub_r001772_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001772_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001772_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001772_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001772_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001772_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001772_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_269 * 3) + pub_r001772_6 + 6) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325 * 2) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001772_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001772_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_325 * 3) + pub_r001772_15 + 16) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_71 * 3) + pub_r001772_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329 * 2) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_218 * 3) + pub_r001772_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001772_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001772_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001772_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_23 * 3) + pub_r001772_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001772_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001772_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001772_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_60 * 3) + pub_r001772_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_290 * 3) + pub_r001772_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339 * 2) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_292 * 3) + pub_r001772_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001772_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001772_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001772_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001772_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_262 * 3) + pub_r001772_3 + 19) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001772_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001772_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_235 * 3) + pub_r001772_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001772_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_101 * 3) + pub_r001772_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001772_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001772_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001772_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001772_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001772_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001772_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_217 * 3) + pub_r001772_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001772_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_103 * 3) + pub_r001772_12 + 35) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((helper_flow_2 * 3) + pub_r001772_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001772_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001772_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001772_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001772_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001772_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001772_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001772_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001772_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001772_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001772_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_221 * 3) + pub_r001772_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_100 * 3) + pub_r001772_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_372) & 255;
    out_sink = (out_sink + stage_v_372 * 2) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_338 * 3) + pub_r001772_17 + 38) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((helper_flow_2 * 3) + pub_r001772_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001772_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001772_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((sec_r001772_18 * 3) + pub_r001772_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_377) & 255;
    out_sink = (out_sink + stage_v_377 * 2) & 255;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001772_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_360 * 3) + pub_r001772_17 + 29) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001772_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001772_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001772_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001772_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001772_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001772_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_345 * 3) + pub_r001772_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001772_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_350 * 3) + pub_r001772_15 + 40) & 127;
    sec_accum = (sec_accum + stage_v_388) & 255;
    out_sink = (out_sink + stage_v_388 * 2) & 255;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001772_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_40 * 3) + pub_r001772_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_379 * 3) + pub_r001772_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_391) & 255;
    out_sink = (out_sink + stage_v_391 * 2) & 255;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_4 * 3) + pub_r001772_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_392) & 255;
    out_sink = (out_sink + stage_v_392 * 2) & 255;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001772_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001772_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((sec_r001772_10 * 3) + pub_r001772_16 + 42) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_191 * 3) + pub_r001772_2 + 38) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_338 * 3) + pub_r001772_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001772_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001772_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_40 * 3) + pub_r001772_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_400) & 255;
    out_sink = (out_sink + stage_v_400 * 2) & 255;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001772_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001772_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_303 * 3) + pub_r001772_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((sec_r001772_0 * 3) + pub_r001772_16 + 35) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_279 * 3) + pub_r001772_5 + 45) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001772_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001772_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_315 * 3) + pub_r001772_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_408) & 255;
    out_sink = (out_sink + stage_v_408 * 2) & 255;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001772_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001772_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001772_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001772_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001772_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_23 * 3) + pub_r001772_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001772_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_62 * 3) + pub_r001772_13 + 29) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001772_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001772_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_372 * 3) + pub_r001772_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001772_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001772_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001772_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001772_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001772_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_101 * 3) + pub_r001772_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001772_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((sec_r001772_2 * 3) + pub_r001772_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001772_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001772_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_338 * 3) + pub_r001772_17 + 42) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001772_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001772_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001772_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_86 * 3) + pub_r001772_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001772_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_90 * 3) + pub_r001772_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001772_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((helper_flow_0 * 3) + pub_r001772_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001772_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001772_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((sec_r001772_11 * 3) + pub_r001772_17 + 37) & 127;
    sec_accum = (sec_accum + stage_v_441) & 255;
    out_sink = (out_sink + stage_v_441 * 2) & 255;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_77 * 3) + pub_r001772_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_330 * 3) + pub_r001772_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_443) & 255;
    out_sink = (out_sink + stage_v_443 * 2) & 255;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_188 * 3) + pub_r001772_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_444) & 255;
    out_sink = (out_sink + stage_v_444 * 2) & 255;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001772_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((sec_r001772_17 * 3) + pub_r001772_15 + 34) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((sec_r001772_2 * 3) + pub_r001772_5 + 26) & 127;
    sec_accum = (sec_accum + stage_v_447) & 255;
    out_sink = (out_sink + stage_v_447 * 2) & 255;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_221 * 3) + pub_r001772_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_116 * 3) + pub_r001772_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001772_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001772_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_436 * 3) + pub_r001772_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_452) & 255;
    out_sink = (out_sink + stage_v_452 * 2) & 255;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_419 * 3) + pub_r001772_6 + 43) & 127;
    sec_accum = (sec_accum + stage_v_453) & 255;
    out_sink = (out_sink + stage_v_453 * 2) & 255;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001772_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001772_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001772_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001772_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_400 * 3) + pub_r001772_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_458) & 255;
    out_sink = (out_sink + stage_v_458 * 2) & 255;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_396 * 3) + pub_r001772_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_459) & 255;
    out_sink = (out_sink + stage_v_459 * 2) & 255;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_23 * 3) + pub_r001772_13 + 39) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_10 * 3) + pub_r001772_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_388 * 3) + pub_r001772_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_462) & 255;
    out_sink = (out_sink + stage_v_462 * 2) & 255;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_130 * 3) + pub_r001772_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_463) & 255;
    out_sink = (out_sink + stage_v_463 * 2) & 255;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001772_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_314 * 3) + pub_r001772_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_465) & 255;
    out_sink = (out_sink + stage_v_465 * 2) & 255;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001772_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001772_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_458 * 3) + pub_r001772_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_468) & 255;
    out_sink = (out_sink + stage_v_468 * 2) & 255;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001772_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001772_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_285 * 3) + pub_r001772_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_471) & 255;
    out_sink = (out_sink + stage_v_471 * 2) & 255;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001772_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001772_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001772_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001772_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001772_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = ((stage_v_334 * 3) + pub_r001772_11 + 12) & 127;
    sec_accum = (sec_accum + stage_v_477) & 255;
    out_sink = (out_sink + stage_v_477 * 2) & 255;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = ((stage_v_338 * 3) + pub_r001772_16 + 29) & 127;
    sec_accum = (sec_accum + stage_v_478) & 255;
    out_sink = (out_sink + stage_v_478 * 2) & 255;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001772_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_444 * 3) + pub_r001772_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_480) & 255;
    out_sink = (out_sink + stage_v_480 * 2) & 255;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001772_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001772_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001772_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001772_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001772_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001772_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001772_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001772_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001772_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001772_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001772_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001772_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = (pub_r001772_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_493) & 127;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001772_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = ((stage_v_126 * 3) + pub_r001772_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_495) & 255;
    out_sink = (out_sink + stage_v_495 * 2) & 255;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001772_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = ((stage_v_244 * 3) + pub_r001772_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_497) & 255;
    out_sink = (out_sink + stage_v_497 * 2) & 255;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = ((stage_v_55 * 3) + pub_r001772_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_498) & 255;
    out_sink = (out_sink + stage_v_498 * 2) & 255;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = ((stage_v_400 * 3) + pub_r001772_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_499) & 255;
    out_sink = (out_sink + stage_v_499 * 2) & 255;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001772_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001772_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001772_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = ((stage_v_438 * 3) + pub_r001772_8 + 39) & 127;
    sec_accum = (sec_accum + stage_v_503) & 255;
    out_sink = (out_sink + stage_v_503 * 2) & 255;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = (pub_r001772_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_504) & 127;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001772_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001772_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = ((stage_v_447 * 3) + pub_r001772_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_507) & 255;
    out_sink = (out_sink + stage_v_507 * 2) & 255;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = ((stage_v_92 * 3) + pub_r001772_16 + 7) & 127;
    sec_accum = (sec_accum + stage_v_508) & 255;
    out_sink = (out_sink + stage_v_508 * 2) & 255;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001772_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = ((sec_r001772_4 * 3) + pub_r001772_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_510) & 255;
    out_sink = (out_sink + stage_v_510 * 2) & 255;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001772_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = (pub_r001772_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_512) & 127;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = (pub_r001772_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_513) & 127;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = ((stage_v_392 * 3) + pub_r001772_10 + 43) & 127;
    sec_accum = (sec_accum + stage_v_514) & 255;
    out_sink = (out_sink + stage_v_514 * 2) & 255;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = ((stage_v_55 * 3) + pub_r001772_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_515) & 255;
    out_sink = (out_sink + stage_v_515 * 2) & 255;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = (pub_r001772_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_516) & 127;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001772_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = (pub_r001772_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_518) & 127;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = (pub_r001772_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_519) & 127;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = (pub_r001772_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_520) & 127;

    /* Execution Pipeline Stage 521 */
    int stage_v_521 = (pub_r001772_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_521) & 127;

    /* Execution Pipeline Stage 522 */
    int stage_v_522 = ((stage_v_154 * 3) + pub_r001772_3 + 11) & 127;
    sec_accum = (sec_accum + stage_v_522) & 255;
    out_sink = (out_sink + stage_v_522 * 2) & 255;

    /* Execution Pipeline Stage 523 */
    int stage_v_523 = ((stage_v_231 * 3) + pub_r001772_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_523) & 255;
    out_sink = (out_sink + stage_v_523 * 2) & 255;

    /* Execution Pipeline Stage 524 */
    int stage_v_524 = (pub_r001772_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_524) & 127;

    /* Execution Pipeline Stage 525 */
    int stage_v_525 = (pub_r001772_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_525) & 127;

    /* Execution Pipeline Stage 526 */
    int stage_v_526 = ((helper_flow_2 * 3) + pub_r001772_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_526) & 255;
    out_sink = (out_sink + stage_v_526 * 2) & 255;

    /* Execution Pipeline Stage 527 */
    int stage_v_527 = (pub_r001772_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_527) & 127;

    /* Execution Pipeline Stage 528 */
    int stage_v_528 = (pub_r001772_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_528) & 127;

    /* Execution Pipeline Stage 529 */
    int stage_v_529 = (pub_r001772_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_529) & 127;

    /* Execution Pipeline Stage 530 */
    int stage_v_530 = ((stage_v_188 * 3) + pub_r001772_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_530) & 255;
    out_sink = (out_sink + stage_v_530 * 2) & 255;

    /* Execution Pipeline Stage 531 */
    int stage_v_531 = (pub_r001772_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_531) & 127;

    /* Execution Pipeline Stage 532 */
    int stage_v_532 = (pub_r001772_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_532) & 127;

    /* Execution Pipeline Stage 533 */
    int stage_v_533 = (pub_r001772_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_533) & 127;

    /* Execution Pipeline Stage 534 */
    int stage_v_534 = ((stage_v_508 * 3) + pub_r001772_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_534) & 255;
    out_sink = (out_sink + stage_v_534 * 2) & 255;

    /* Execution Pipeline Stage 535 */
    int stage_v_535 = (pub_r001772_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_535) & 127;

    /* Execution Pipeline Stage 536 */
    int stage_v_536 = (pub_r001772_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_536) & 127;

    /* Execution Pipeline Stage 537 */
    int stage_v_537 = (pub_r001772_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_537) & 127;

    /* Execution Pipeline Stage 538 */
    int stage_v_538 = (pub_r001772_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_538) & 127;

    /* Execution Pipeline Stage 539 */
    int stage_v_539 = (pub_r001772_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_539) & 127;

    /* Execution Pipeline Stage 540 */
    int stage_v_540 = (pub_r001772_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_540) & 127;

    /* Execution Pipeline Stage 541 */
    int stage_v_541 = (pub_r001772_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_541) & 127;

    /* Execution Pipeline Stage 542 */
    int stage_v_542 = ((stage_v_179 * 3) + pub_r001772_14 + 38) & 127;
    sec_accum = (sec_accum + stage_v_542) & 255;
    out_sink = (out_sink + stage_v_542 * 2) & 255;

    /* Execution Pipeline Stage 543 */
    int stage_v_543 = ((stage_v_405 * 3) + pub_r001772_12 + 18) & 127;
    sec_accum = (sec_accum + stage_v_543) & 255;
    out_sink = (out_sink + stage_v_543 * 2) & 255;

    /* Execution Pipeline Stage 544 */
    int stage_v_544 = (pub_r001772_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_544) & 127;

    /* Execution Pipeline Stage 545 */
    int stage_v_545 = (pub_r001772_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_545) & 127;

    /* Execution Pipeline Stage 546 */
    int stage_v_546 = ((stage_v_189 * 3) + pub_r001772_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_546) & 255;
    out_sink = (out_sink + stage_v_546 * 2) & 255;

    /* Execution Pipeline Stage 547 */
    int stage_v_547 = (pub_r001772_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_547) & 127;

    /* Execution Pipeline Stage 548 */
    int stage_v_548 = (pub_r001772_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_548) & 127;

    /* Execution Pipeline Stage 549 */
    int stage_v_549 = (pub_r001772_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_549) & 127;

    /* Execution Pipeline Stage 550 */
    int stage_v_550 = ((stage_v_290 * 3) + pub_r001772_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_550) & 255;
    out_sink = (out_sink + stage_v_550 * 2) & 255;

    /* Execution Pipeline Stage 551 */
    int stage_v_551 = (pub_r001772_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_551) & 127;

    /* Execution Pipeline Stage 552 */
    int stage_v_552 = (pub_r001772_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_552) & 127;

    /* Execution Pipeline Stage 553 */
    int stage_v_553 = (pub_r001772_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_553) & 127;

    /* Execution Pipeline Stage 554 */
    int stage_v_554 = (pub_r001772_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_554) & 127;

    /* Execution Pipeline Stage 555 */
    int stage_v_555 = ((stage_v_453 * 3) + pub_r001772_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_555) & 255;
    out_sink = (out_sink + stage_v_555 * 2) & 255;

    /* Execution Pipeline Stage 556 */
    int stage_v_556 = (pub_r001772_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_556) & 127;

    /* Execution Pipeline Stage 557 */
    int stage_v_557 = (pub_r001772_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_557) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
