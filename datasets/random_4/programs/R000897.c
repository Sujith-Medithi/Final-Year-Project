/*
 * Benchmark Program: R000897
 * Family: secret_dependent_array
 * Generator Seed: 489713
 * High Inputs: 20 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000897_9713_0 {
    short facility;
    int timestamp;
    short seq;
    int signature;
    int buffer[3];
};

struct FilterState_R000897_9713_1 {
    int cutoff;
    int damping;
    short prev_out;
    int mode;
    int prev_in;
    unsigned char gain_db;
    int buffer[3];
};

struct CipherContext_R000897_9713_2 {
    unsigned char nonce;
    int iv;
    int flags;
    int round_key;
    unsigned char counter;
    unsigned char tag;
    int buffer[3];
};

struct SensorNode_R000897_9713_3 {
    short calib;
    unsigned char offset;
    int reading;
    int gain;
    unsigned char threshold;
    int buffer[3];
};

union TelemetryField_R000897_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000897_9713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int pivot_18 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_18 > 37) {
        acc = (acc + pivot_18 * 2 + 5) & 127;
        aux ^= (pivot_18 & 15);
    } else {
        acc = (acc - pivot_18 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_48 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_48 = (anchor_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_48) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_1(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int index_reg_97 = local_arr[aux % 3];
    acc = (acc + index_reg_97 * 2) & 127;
    int metric_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000897_9713_2(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int phase_85 = 0;
    for (int k = 0; k < 3; k++) {
        phase_85 = (phase_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_85) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_60 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_60 > 35) {
        acc = (acc + sample_60 * 2 + 5) & 127;
        aux ^= (sample_60 & 15);
    } else {
        acc = (acc - sample_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_3(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_71) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_54 = local_arr[aux % 3];
    acc = (acc + residue_54 * 2) & 127;
    int residue_93 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_93 > 19) {
        acc = (acc + residue_93 * 2 + 5) & 127;
        aux ^= (residue_93 & 15);
    } else {
        acc = (acc - residue_93 + 11) & 127;
        aux += 3;
    }
    int index_reg_49 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_49 = (index_reg_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_4(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int delta_65 = local_arr[aux % 3];
    acc = (acc + delta_65 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000897_9713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_29) & 63;
    acc ^= aux;
    int residue_58 = 0;
    for (int k = 0; k < 2; k++) {
        residue_58 = (residue_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int parity_90 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_90 > 48) {
        acc = (acc + parity_90 * 2 + 5) & 127;
        aux ^= (parity_90 & 15);
    } else {
        acc = (acc - parity_90 + 11) & 127;
        aux += 3;
    }
    int phase_75 = 0;
    for (int k = 0; k < 3; k++) {
        phase_75 = (phase_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_75) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_82 = local_arr[aux % 3];
    acc = (acc + damping_82 * 2) & 127;
    int factor_41 = (aux + st.buffer[1]) & 3;
    switch (factor_41) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000897_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int factor_96 = (aux + st.buffer[1]) & 3;
    switch (factor_96) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000897_9713_8(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int pivot_22 = (aux + st.buffer[1]) & 3;
    switch (pivot_22) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_44) & 63;
    acc ^= aux;
    int delta_73 = 0;
    for (int k = 0; k < 3; k++) {
        delta_73 = (delta_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int delta_99 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_99 > 17) {
        acc = (acc + delta_99 * 2 + 5) & 127;
        aux ^= (delta_99 & 15);
    } else {
        acc = (acc - delta_99 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_61 = local_arr[aux % 3];
    acc = (acc + weight_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_12 = 0;
    for (int k = 0; k < 2; k++) {
        metric_12 = (metric_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_12) & 127;
    }
    int phase_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000897_9713_11(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000897_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_99 = 0;
    for (int k = 0; k < 3; k++) {
        offset_99 = (offset_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_99) & 127;
    }
    int scale_66 = (aux + st.buffer[1]) & 3;
    switch (scale_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_15) & 63;
    acc ^= aux;
    int parity_64 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_64 > 23) {
        acc = (acc + parity_64 * 2 + 5) & 127;
        aux ^= (parity_64 & 15);
    } else {
        acc = (acc - parity_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000897_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_45 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_45 > 49) {
        acc = (acc + metric_45 * 2 + 5) & 127;
        aux ^= (metric_45 & 15);
    } else {
        acc = (acc - metric_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_13(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_95) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_12 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_12 > 27) {
        acc = (acc + weight_12 * 2 + 5) & 127;
        aux ^= (weight_12 & 15);
    } else {
        acc = (acc - weight_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_27 = local_arr[aux % 3];
    acc = (acc + damping_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_84 = (aux + st.buffer[1]) & 3;
    switch (metric_84) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000897_0;
    int sec_r000897_1;
    int sec_r000897_2;
    int sec_r000897_3;
    int sec_r000897_4;
    int sec_r000897_5;
    int sec_r000897_6;
    int sec_r000897_7;
    int sec_r000897_8;
    int sec_r000897_9;
    int sec_r000897_10;
    int sec_r000897_11;
    int sec_r000897_12;
    int sec_r000897_13;
    int sec_r000897_14;
    int sec_r000897_15;
    int sec_r000897_16;
    int sec_r000897_17;
    int sec_r000897_18;
    int sec_r000897_19;
    int pub_r000897_0;
    int pub_r000897_1;
    int pub_r000897_2;
    int pub_r000897_3;
    int pub_r000897_4;
    int pub_r000897_5;
    int pub_r000897_6;
    int pub_r000897_7;
    int pub_r000897_8;
    int pub_r000897_9;
    int pub_r000897_10;
    int pub_r000897_11;
    int pub_r000897_12;
    int pub_r000897_13;
    int pub_r000897_14;
    int pub_r000897_15;
    int pub_r000897_16;
    int pub_r000897_17;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000897_0 >= -100 && pub_r000897_0 <= 100);
    __CPROVER_assume(pub_r000897_1 >= -100 && pub_r000897_1 <= 100);
    __CPROVER_assume(pub_r000897_2 >= -100 && pub_r000897_2 <= 100);
    __CPROVER_assume(pub_r000897_3 >= -100 && pub_r000897_3 <= 100);
    __CPROVER_assume(pub_r000897_4 >= -100 && pub_r000897_4 <= 100);
    __CPROVER_assume(pub_r000897_5 >= -100 && pub_r000897_5 <= 100);
    __CPROVER_assume(pub_r000897_6 >= -100 && pub_r000897_6 <= 100);
    __CPROVER_assume(pub_r000897_7 >= -100 && pub_r000897_7 <= 100);
    __CPROVER_assume(pub_r000897_8 >= -100 && pub_r000897_8 <= 100);
    __CPROVER_assume(pub_r000897_9 >= -100 && pub_r000897_9 <= 100);
    __CPROVER_assume(pub_r000897_10 >= -100 && pub_r000897_10 <= 100);
    __CPROVER_assume(pub_r000897_11 >= -100 && pub_r000897_11 <= 100);
    __CPROVER_assume(pub_r000897_12 >= -100 && pub_r000897_12 <= 100);
    __CPROVER_assume(pub_r000897_13 >= -100 && pub_r000897_13 <= 100);
    __CPROVER_assume(pub_r000897_14 >= -100 && pub_r000897_14 <= 100);
    __CPROVER_assume(pub_r000897_15 >= -100 && pub_r000897_15 <= 100);
    __CPROVER_assume(pub_r000897_16 >= -100 && pub_r000897_16 <= 100);
    __CPROVER_assume(pub_r000897_17 >= -100 && pub_r000897_17 <= 100);
    __CPROVER_assume(sec_r000897_0 >= 0 && sec_r000897_0 <= 255);
    __CPROVER_assume(sec_r000897_1 >= 0 && sec_r000897_1 <= 255);
    __CPROVER_assume(sec_r000897_2 >= 0 && sec_r000897_2 <= 255);
    __CPROVER_assume(sec_r000897_3 >= 0 && sec_r000897_3 <= 255);
    __CPROVER_assume(sec_r000897_4 >= 0 && sec_r000897_4 <= 255);
    __CPROVER_assume(sec_r000897_5 >= 0 && sec_r000897_5 <= 255);
    __CPROVER_assume(sec_r000897_6 >= 0 && sec_r000897_6 <= 255);
    __CPROVER_assume(sec_r000897_7 >= 0 && sec_r000897_7 <= 255);
    __CPROVER_assume(sec_r000897_8 >= 0 && sec_r000897_8 <= 255);
    __CPROVER_assume(sec_r000897_9 >= 0 && sec_r000897_9 <= 255);
    __CPROVER_assume(sec_r000897_10 >= 0 && sec_r000897_10 <= 255);
    __CPROVER_assume(sec_r000897_11 >= 0 && sec_r000897_11 <= 255);
    __CPROVER_assume(sec_r000897_12 >= 0 && sec_r000897_12 <= 255);
    __CPROVER_assume(sec_r000897_13 >= 0 && sec_r000897_13 <= 255);
    __CPROVER_assume(sec_r000897_14 >= 0 && sec_r000897_14 <= 255);
    __CPROVER_assume(sec_r000897_15 >= 0 && sec_r000897_15 <= 255);
    __CPROVER_assume(sec_r000897_16 >= 0 && sec_r000897_16 <= 255);
    __CPROVER_assume(sec_r000897_17 >= 0 && sec_r000897_17 <= 255);
    __CPROVER_assume(sec_r000897_18 >= 0 && sec_r000897_18 <= 255);
    __CPROVER_assume(sec_r000897_19 >= 0 && sec_r000897_19 <= 255);

    struct EventLog_R000897_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000897_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000897_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000897_0 + 7) & 15;
    struct FilterState_R000897_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000897_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000897_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000897_0 + 9) & 15;
    struct CipherContext_R000897_9713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000897_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000897_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000897_0 + 11) & 15;
    struct SensorNode_R000897_9713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000897_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000897_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000897_0 + 13) & 15;

    union TelemetryField_R000897_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 18) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 33) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 32) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 47) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 31) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 46) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 36) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 51) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 10) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 25) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 36) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 51) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 39) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 54) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 26) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 41) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 22) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 37) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] ^ 81) & 3;
    switch (stage_v_78) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[0] ^ 82) & 3;
    switch (stage_v_79) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_3.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 15) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 30) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 86) & 15;
    int stage_v_85 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= stage_v_85;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 36) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 51) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 39) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 54) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 19) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 34) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_2.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 37) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 52) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 20) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 35) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_2.buffer[0] ^ 97) & 3;
    switch (stage_v_94) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_3.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 30) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 45) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (out_sink > 100) ? (chk_sum & 31) : (101 & 31);
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= (stage_v_96 << 1) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 28) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 43) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_1.buffer[0] ^ 104) & 3;
    switch (stage_v_101) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = table[2];
    table[2] = (table[3] + 205) & 63;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[2] * 2 + 319) & 63;
    if (stage_v_104 > 26) {
        out_sink = (out_sink + stage_v_104 - 5) & 255;
        if (stage_v_104 > 41) {
            chk_sum ^= (stage_v_104 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_104 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 105 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[0] ^ 112) & 3;
    switch (stage_v_109) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_2.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 10) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 25) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[1] * 2 + 379) & 63;
    if (stage_v_124 > 28) {
        out_sink = (out_sink + stage_v_124 - 5) & 255;
        if (stage_v_124 > 43) {
            chk_sum ^= (stage_v_124 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_124 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[2] * 2 + 382) & 63;
    if (stage_v_125 > 25) {
        out_sink = (out_sink + stage_v_125 - 5) & 255;
        if (stage_v_125 > 40) {
            chk_sum ^= (stage_v_125 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_125 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_2.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 18) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 33) {
            chk_sum ^= (stage_v_130 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_130 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = table[3];
    table[3] = (table[0] + 263) & 63;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 39) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 54) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 40) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 55) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_135 = (stage_v_135 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (out_sink > 100) ? (chk_sum & 31) : (142 & 31);
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= (stage_v_137 << 1) & 127;

    /* Execution Pipeline Stage 138 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1];
    table[1] = (table[2] + 283) & 63;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_3.buffer[2] * 2 + 436) & 63;
    if (stage_v_143 > 39) {
        out_sink = (out_sink + stage_v_143 - 5) & 255;
        if (stage_v_143 > 54) {
            chk_sum ^= (stage_v_143 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_143 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_2.buffer[0] ^ 149) & 3;
    switch (stage_v_146) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (out_sink > 100) ? (chk_sum & 31) : (153 & 31);
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= (stage_v_148 << 1) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 150 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_3.buffer[2] * 2 + 472) & 63;
    if (stage_v_155 > 39) {
        out_sink = (out_sink + stage_v_155 - 5) & 255;
        if (stage_v_155 > 54) {
            chk_sum ^= (stage_v_155 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_155 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = table[2];
    table[2] = (table[3] + 317) & 63;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (out_sink > 100) ? (chk_sum & 31) : (164 & 31);
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= (stage_v_159 << 1) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = table[2];
    table[2] = (table[3] + 325) & 63;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_3.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 25) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 40) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (out_sink > 100) ? (chk_sum & 31) : (170 & 31);
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= (stage_v_165 << 1) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_166 = (stage_v_166 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_167 = (stage_v_167 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (out_sink > 100) ? (chk_sum & 31) : (173 & 31);
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= (stage_v_168 << 1) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_169 = (stage_v_169 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = table[3];
    table[3] = (table[0] + 343) & 63;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (out_sink > 100) ? (chk_sum & 31) : (177 & 31);
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= (stage_v_172 << 1) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_1.buffer[0] ^ 176) & 3;
    switch (stage_v_173) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_2.buffer[0] * 2 + 529) & 63;
    if (stage_v_174 > 36) {
        out_sink = (out_sink + stage_v_174 - 5) & 255;
        if (stage_v_174 > 51) {
            chk_sum ^= (stage_v_174 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_174 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] ^ 183) & 3;
    switch (stage_v_180) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = table[2];
    table[2] = (table[3] + 365) & 63;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = table[3];
    table[3] = (table[0] + 367) & 63;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_184 = (stage_v_184 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_184) & 127;
    }
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (st_var_1.buffer[0] ^ 188) & 3;
    switch (stage_v_185) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = table[2];
    table[2] = (table[3] + 373) & 63;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (out_sink > 100) ? (chk_sum & 31) : (192 & 31);
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= (stage_v_187 << 1) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (st_var_1.buffer[0] ^ 192) & 3;
    switch (stage_v_189) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 190 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 191) & 15;
    int stage_v_190 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_190) & 255;
    chk_sum ^= stage_v_190;

    /* Execution Pipeline Stage 191 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 192) & 15;
    int stage_v_191 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_191) & 255;
    chk_sum ^= stage_v_191;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_194 = (stage_v_194 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_194) & 127;
    }
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = table[3];
    table[3] = (table[0] + 391) & 63;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_196 = (stage_v_196 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_196) & 127;
    }
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (out_sink > 100) ? (chk_sum & 31) : (202 & 31);
    out_sink = (out_sink + stage_v_197) & 255;
    chk_sum ^= (stage_v_197 << 1) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_2.buffer[0] * 2 + 601) & 63;
    if (stage_v_198 > 35) {
        out_sink = (out_sink + stage_v_198 - 5) & 255;
        if (stage_v_198 > 50) {
            chk_sum ^= (stage_v_198 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_198 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (out_sink > 100) ? (chk_sum & 31) : (204 & 31);
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= (stage_v_199 << 1) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (out_sink > 100) ? (chk_sum & 31) : (206 & 31);
    out_sink = (out_sink + stage_v_201) & 255;
    chk_sum ^= (stage_v_201 << 1) & 127;

    /* Execution Pipeline Stage 202 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 203) & 15;
    int stage_v_202 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    chk_sum ^= stage_v_202;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (out_sink > 100) ? (chk_sum & 31) : (208 & 31);
    out_sink = (out_sink + stage_v_203) & 255;
    chk_sum ^= (stage_v_203 << 1) & 127;

    /* Execution Pipeline Stage 204 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 205) & 15;
    int stage_v_204 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_204) & 255;
    chk_sum ^= stage_v_204;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_205 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_206 = (stage_v_206 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_206) & 127;
    }
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_207 = (stage_v_207 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_207) & 127;
    }
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_208 = (stage_v_208 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_208) & 127;
    }
    out_sink = (out_sink + stage_v_208) & 255;

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 33, 98, 93, 48 };
    int s_idx = (sec_r000897_18 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
