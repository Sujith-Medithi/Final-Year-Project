/*
 * Benchmark Program: R001207
 * Security Family: nested_implicit_flow
 * Generator Seed: 620713
 * High Inputs: 22 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001207_713_0 {
    unsigned char counter;
    unsigned char flags;
    unsigned char tag;
    short iv;
    int nonce;
    int buffer[3];
};

struct AudioFrame_R001207_713_1 {
    short sample_rate;
    short peak;
    unsigned char envelope;
    int gain;
    unsigned char channels;
    int buffer[3];
};

struct Transaction_R001207_713_2 {
    short balance;
    unsigned char auth_code;
    int fee;
    short status;
    int buffer[3];
};

struct DeviceConfig_R001207_713_3 {
    int port;
    unsigned char id;
    unsigned char stop_bits;
    int parity;
    int timeout;
    int buffer[3];
};

union RegisterBank_R001207_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001207_713_0(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001207_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_58) & 63;
    acc ^= aux;
    int metric_32 = 0;
    for (int k = 0; k < 3; k++) {
        metric_32 = (metric_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_32) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001207_713_1(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001207_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int delta_83 = 0;
    for (int k = 0; k < 3; k++) {
        delta_83 = (delta_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_83) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_25 = (aux + st.buffer[1]) & 3;
    switch (accumulator_25) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001207_713_2(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int stride_73 = 0;
    for (int k = 0; k < 2; k++) {
        stride_73 = (stride_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_73) & 127;
    }
    int quantum_71 = (aux + st.buffer[1]) & 3;
    switch (quantum_71) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001207_713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001207_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int cursor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_80) & 63;
    acc ^= aux;
    int delta_45 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_45 > 12) {
        acc = (acc + delta_45 * 2 + 5) & 127;
        aux ^= (delta_45 & 15);
    } else {
        acc = (acc - delta_45 + 11) & 127;
        aux += 3;
    }
    int index_reg_53 = (aux + st.buffer[1]) & 3;
    switch (index_reg_53) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_78 = 0;
    for (int k = 0; k < 2; k++) {
        sample_78 = (sample_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_78) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001207_713_4(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int sample_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_62) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_50 = local_arr[aux % 3];
    acc = (acc + index_reg_50 * 2) & 127;
    int window_36 = (st.buffer[0] * 3 + aux) & 63;
    if (window_36 > 41) {
        acc = (acc + window_36 * 2 + 5) & 127;
        aux ^= (window_36 & 15);
    } else {
        acc = (acc - window_36 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001207_713_5(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int mask_97 = (aux + st.buffer[1]) & 3;
    switch (mask_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_34 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_34 > 49) {
        acc = (acc + factor_34 * 2 + 5) & 127;
        aux ^= (factor_34 & 15);
    } else {
        acc = (acc - factor_34 + 11) & 127;
        aux += 3;
    }
    int offset_22 = 0;
    for (int k = 0; k < 3; k++) {
        offset_22 = (offset_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_22) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001207_713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_45 = (aux + st.buffer[1]) & 3;
    switch (tally_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_43 = 0;
    for (int k = 0; k < 3; k++) {
        tally_43 = (tally_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_43) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001207_713_7(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_69 = (aux + st.buffer[1]) & 3;
    switch (sample_69) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_84 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_84 = (checksum_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_84) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001207_713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_16 = local_arr[aux % 3];
    acc = (acc + metric_16 * 2) & 127;
    int vector_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001207_713_9(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int delta_75 = (aux + st.buffer[1]) & 3;
    switch (delta_75) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_29 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_29 > 27) {
        acc = (acc + residue_29 * 2 + 5) & 127;
        aux ^= (residue_29 & 15);
    } else {
        acc = (acc - residue_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001207_713_10(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_84 = 0;
    for (int k = 0; k < 2; k++) {
        damping_84 = (damping_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_84) & 127;
    }
    int vector_69 = (aux + st.buffer[1]) & 3;
    switch (vector_69) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_28 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_28 > 25) {
        acc = (acc + weight_28 * 2 + 5) & 127;
        aux ^= (weight_28 & 15);
    } else {
        acc = (acc - weight_28 + 11) & 127;
        aux += 3;
    }
    int anchor_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001207_713_11(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int accumulator_52 = (aux + st.buffer[1]) & 3;
    switch (accumulator_52) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_33 > 39) {
        acc = (acc + cursor_33 * 2 + 5) & 127;
        aux ^= (cursor_33 & 15);
    } else {
        acc = (acc - cursor_33 + 11) & 127;
        aux += 3;
    }
    int pivot_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001207_713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int stride_71 = (aux + st.buffer[1]) & 3;
    switch (stride_71) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_92) & 63;
    acc ^= aux;
    int checksum_18 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_18 > 34) {
        acc = (acc + checksum_18 * 2 + 5) & 127;
        aux ^= (checksum_18 & 15);
    } else {
        acc = (acc - checksum_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001207_713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int delta_20 = (aux + st.buffer[1]) & 3;
    switch (delta_20) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_22 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_22 = (threshold_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_22) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001207_0;
    int sec_r001207_1;
    int sec_r001207_2;
    int sec_r001207_3;
    int sec_r001207_4;
    int sec_r001207_5;
    int sec_r001207_6;
    int sec_r001207_7;
    int sec_r001207_8;
    int sec_r001207_9;
    int sec_r001207_10;
    int sec_r001207_11;
    int sec_r001207_12;
    int sec_r001207_13;
    int sec_r001207_14;
    int sec_r001207_15;
    int sec_r001207_16;
    int sec_r001207_17;
    int sec_r001207_18;
    int sec_r001207_19;
    int sec_r001207_20;
    int sec_r001207_21;
    int pub_r001207_0;
    int pub_r001207_1;
    int pub_r001207_2;
    int pub_r001207_3;
    int pub_r001207_4;
    int pub_r001207_5;
    int pub_r001207_6;
    int pub_r001207_7;
    int pub_r001207_8;
    int pub_r001207_9;
    int pub_r001207_10;
    int pub_r001207_11;
    int pub_r001207_12;
    int pub_r001207_13;
    int pub_r001207_14;
    int pub_r001207_15;
    int pub_r001207_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001207_0 >= -100 && pub_r001207_0 <= 100);
    __CPROVER_assume(pub_r001207_1 >= -100 && pub_r001207_1 <= 100);
    __CPROVER_assume(pub_r001207_2 >= -100 && pub_r001207_2 <= 100);
    __CPROVER_assume(pub_r001207_3 >= -100 && pub_r001207_3 <= 100);
    __CPROVER_assume(pub_r001207_4 >= -100 && pub_r001207_4 <= 100);
    __CPROVER_assume(pub_r001207_5 >= -100 && pub_r001207_5 <= 100);
    __CPROVER_assume(pub_r001207_6 >= -100 && pub_r001207_6 <= 100);
    __CPROVER_assume(pub_r001207_7 >= -100 && pub_r001207_7 <= 100);
    __CPROVER_assume(pub_r001207_8 >= -100 && pub_r001207_8 <= 100);
    __CPROVER_assume(pub_r001207_9 >= -100 && pub_r001207_9 <= 100);
    __CPROVER_assume(pub_r001207_10 >= -100 && pub_r001207_10 <= 100);
    __CPROVER_assume(pub_r001207_11 >= -100 && pub_r001207_11 <= 100);
    __CPROVER_assume(pub_r001207_12 >= -100 && pub_r001207_12 <= 100);
    __CPROVER_assume(pub_r001207_13 >= -100 && pub_r001207_13 <= 100);
    __CPROVER_assume(pub_r001207_14 >= -100 && pub_r001207_14 <= 100);
    __CPROVER_assume(pub_r001207_15 >= -100 && pub_r001207_15 <= 100);
    __CPROVER_assume(pub_r001207_16 >= -100 && pub_r001207_16 <= 100);
    __CPROVER_assume(sec_r001207_0 >= 0 && sec_r001207_0 <= 255);
    __CPROVER_assume(sec_r001207_1 >= 0 && sec_r001207_1 <= 255);
    __CPROVER_assume(sec_r001207_2 >= 0 && sec_r001207_2 <= 255);
    __CPROVER_assume(sec_r001207_3 >= 0 && sec_r001207_3 <= 255);
    __CPROVER_assume(sec_r001207_4 >= 0 && sec_r001207_4 <= 255);
    __CPROVER_assume(sec_r001207_5 >= 0 && sec_r001207_5 <= 255);
    __CPROVER_assume(sec_r001207_6 >= 0 && sec_r001207_6 <= 255);
    __CPROVER_assume(sec_r001207_7 >= 0 && sec_r001207_7 <= 255);
    __CPROVER_assume(sec_r001207_8 >= 0 && sec_r001207_8 <= 255);
    __CPROVER_assume(sec_r001207_9 >= 0 && sec_r001207_9 <= 255);
    __CPROVER_assume(sec_r001207_10 >= 0 && sec_r001207_10 <= 255);
    __CPROVER_assume(sec_r001207_11 >= 0 && sec_r001207_11 <= 255);
    __CPROVER_assume(sec_r001207_12 >= 0 && sec_r001207_12 <= 255);
    __CPROVER_assume(sec_r001207_13 >= 0 && sec_r001207_13 <= 255);
    __CPROVER_assume(sec_r001207_14 >= 0 && sec_r001207_14 <= 255);
    __CPROVER_assume(sec_r001207_15 >= 0 && sec_r001207_15 <= 255);
    __CPROVER_assume(sec_r001207_16 >= 0 && sec_r001207_16 <= 255);
    __CPROVER_assume(sec_r001207_17 >= 0 && sec_r001207_17 <= 255);
    __CPROVER_assume(sec_r001207_18 >= 0 && sec_r001207_18 <= 255);
    __CPROVER_assume(sec_r001207_19 >= 0 && sec_r001207_19 <= 255);
    __CPROVER_assume(sec_r001207_20 >= 0 && sec_r001207_20 <= 255);
    __CPROVER_assume(sec_r001207_21 >= 0 && sec_r001207_21 <= 255);

    struct CipherContext_R001207_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001207_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001207_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001207_0 + 7) & 15;
    struct AudioFrame_R001207_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001207_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001207_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001207_0 + 9) & 15;
    struct Transaction_R001207_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001207_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001207_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001207_0 + 11) & 15;
    struct DeviceConfig_R001207_713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001207_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001207_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001207_0 + 13) & 15;

    union RegisterBank_R001207_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001207_713_0(sec_r001207_0, pub_r001207_1);
    int helper_flow_1 = fn_R001207_713_1(sec_r001207_1, sec_r001207_2, pub_r001207_3);
    int helper_flow_2 = fn_R001207_713_2(sec_r001207_2, pub_r001207_3);
    int helper_flow_3 = fn_R001207_713_3(sec_r001207_3, pub_r001207_4, pub_r001207_5, pub_r001207_6, pub_r001207_7);
    int helper_flow_4 = fn_R001207_713_4(sec_r001207_4, sec_r001207_5, pub_r001207_6);
    int helper_flow_5 = fn_R001207_713_5(sec_r001207_5, pub_r001207_6, pub_r001207_7);
    int helper_flow_6 = fn_R001207_713_6(sec_r001207_6, pub_r001207_7, pub_r001207_8, pub_r001207_9, pub_r001207_10);
    int helper_flow_7 = fn_R001207_713_7(sec_r001207_7, sec_r001207_8, pub_r001207_9);
    int helper_flow_8 = fn_R001207_713_8(sec_r001207_8, sec_r001207_9, pub_r001207_10, pub_r001207_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_0 ^ pub_r001207_11) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001207_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_0 ^ pub_r001207_2) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001207_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001207_12 ^ pub_r001207_6) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001207_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001207_13 ^ pub_r001207_15) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001207_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001207_0 ^ pub_r001207_13) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001207_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001207_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001207_6 ^ pub_r001207_14) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_7 ^ pub_r001207_11) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001207_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001207_10 ^ pub_r001207_2) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_2 ^ pub_r001207_7) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_7 ^ pub_r001207_4) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001207_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001207_5 ^ pub_r001207_8) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001207_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001207_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001207_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_9 ^ pub_r001207_16) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001207_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001207_20 ^ pub_r001207_15) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001207_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001207_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_2 ^ pub_r001207_16) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_3 ^ pub_r001207_0) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001207_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_19 ^ pub_r001207_8) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001207_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_10 ^ pub_r001207_4) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001207_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001207_10 ^ pub_r001207_1) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_12 ^ pub_r001207_7) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (helper_flow_4 ^ pub_r001207_16) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_2 ^ pub_r001207_16) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001207_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001207_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_24 ^ pub_r001207_8) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001207_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_27 ^ pub_r001207_11) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r001207_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001207_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001207_3 ^ pub_r001207_10) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_21 ^ pub_r001207_4) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r001207_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001207_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001207_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_1 ^ pub_r001207_12) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001207_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (helper_flow_4 ^ pub_r001207_9) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_20 ^ pub_r001207_8) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_12 ^ pub_r001207_7) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001207_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_26 ^ pub_r001207_1) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001207_13 ^ pub_r001207_13) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_3 ^ pub_r001207_4) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001207_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_1 ^ pub_r001207_14) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r001207_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001207_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001207_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001207_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001207_16 ^ pub_r001207_9) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001207_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (helper_flow_2 ^ pub_r001207_5) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_45 ^ pub_r001207_15) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001207_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_51 ^ pub_r001207_16) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001207_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001207_12 ^ pub_r001207_2) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_44 ^ pub_r001207_0) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001207_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_56 ^ pub_r001207_6) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001207_13 ^ pub_r001207_16) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001207_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_21 ^ pub_r001207_1) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r001207_11 ^ pub_r001207_7) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_33 ^ pub_r001207_12) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_4 ^ pub_r001207_12) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001207_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_47 ^ pub_r001207_1) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001207_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (helper_flow_8 ^ pub_r001207_16) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001207_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001207_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001207_13 ^ pub_r001207_15) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r001207_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001207_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001207_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001207_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_25 ^ pub_r001207_15) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r001207_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_31 ^ pub_r001207_5) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001207_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_4 ^ pub_r001207_15) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001207_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001207_12 ^ pub_r001207_1) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r001207_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001207_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_56 ^ pub_r001207_8) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001207_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001207_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_3 ^ pub_r001207_1) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001207_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_52 ^ pub_r001207_15) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (helper_flow_8 ^ pub_r001207_4) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_60 ^ pub_r001207_11) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_51 ^ pub_r001207_11) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001207_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001207_14 ^ pub_r001207_0) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001207_17 ^ pub_r001207_10) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001207_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (helper_flow_5 ^ pub_r001207_12) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001207_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_20 ^ pub_r001207_8) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001207_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (helper_flow_4 ^ pub_r001207_16) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001207_17 ^ pub_r001207_8) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r001207_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_98 ^ pub_r001207_5) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001207_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001207_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_43 ^ pub_r001207_1) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_34 ^ pub_r001207_11) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_51 ^ pub_r001207_5) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_56 ^ pub_r001207_2) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (sec_r001207_9 ^ pub_r001207_0) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_26 ^ pub_r001207_8) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_20 ^ pub_r001207_12) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_88 ^ pub_r001207_8) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001207_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_37 ^ pub_r001207_0) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_105 ^ pub_r001207_6) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_60 ^ pub_r001207_16) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_57 ^ pub_r001207_0) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_2 ^ pub_r001207_9) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_103 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_112 ^ pub_r001207_5) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_7 ^ pub_r001207_1) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (helper_flow_7 ^ pub_r001207_7) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_86 ^ pub_r001207_16) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001207_4 ^ pub_r001207_5) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001207_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_30 ^ pub_r001207_9) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001207_1 ^ pub_r001207_16) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r001207_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_87 ^ pub_r001207_5) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001207_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001207_9 ^ pub_r001207_4) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_37 ^ pub_r001207_6) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001207_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001207_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_59 ^ pub_r001207_13) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001207_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001207_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001207_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001207_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001207_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_39 ^ pub_r001207_13) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (helper_flow_2 ^ pub_r001207_5) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_93 ^ pub_r001207_12) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_136 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001207_13 ^ pub_r001207_9) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001207_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_76 ^ pub_r001207_9) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001207_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_104 ^ pub_r001207_0) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r001207_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_27 ^ pub_r001207_2) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (helper_flow_6 ^ pub_r001207_14) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (helper_flow_2 ^ pub_r001207_15) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001207_17 ^ pub_r001207_12) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001207_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001207_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001207_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (helper_flow_2 ^ pub_r001207_2) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_136 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_112 ^ pub_r001207_16) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_1 ^ pub_r001207_12) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((sec_r001207_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001207_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001207_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001207_7 ^ pub_r001207_1) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_11 ^ pub_r001207_1) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001207_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_60 ^ pub_r001207_7) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001207_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001207_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001207_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001207_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_93 ^ pub_r001207_1) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_98 ^ pub_r001207_5) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001207_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (helper_flow_6 ^ pub_r001207_8) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_117 ^ pub_r001207_5) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (helper_flow_6 ^ pub_r001207_0) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001207_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_41 ^ pub_r001207_2) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r001207_14 ^ pub_r001207_16) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((sec_r001207_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001207_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (sec_r001207_3 ^ pub_r001207_2) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001207_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_68 ^ pub_r001207_12) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_156 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001207_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001207_4 ^ pub_r001207_16) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (sec_r001207_8 ^ pub_r001207_11) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001207_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001207_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_9 ^ pub_r001207_9) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_178 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_41 ^ pub_r001207_14) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001207_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001207_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_144 ^ pub_r001207_6) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_122 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001207_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_181 ^ pub_r001207_2) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_138 ^ pub_r001207_1) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_177 ^ pub_r001207_2) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((stage_v_143 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_41 ^ pub_r001207_12) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_7 ^ pub_r001207_14) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001207_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_60 ^ pub_r001207_13) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_189 ^ pub_r001207_16) & 63;
    if ((stage_v_194 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_194 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_194 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (sec_r001207_2 ^ pub_r001207_7) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_12 ^ pub_r001207_9) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_125 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (helper_flow_8 ^ pub_r001207_13) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((stage_v_175 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001207_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (helper_flow_3 ^ pub_r001207_2) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_168 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001207_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_106 ^ pub_r001207_13) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_118 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001207_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001207_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r001207_12 ^ pub_r001207_5) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((stage_v_187 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001207_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_43 ^ pub_r001207_3) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001207_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_195 ^ pub_r001207_10) & 63;
    if ((stage_v_208 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_208 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_208 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001207_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001207_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001207_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_150 ^ pub_r001207_10) & 63;
    if ((stage_v_212 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_212 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_212 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_26 ^ pub_r001207_0) & 63;
    if ((stage_v_213 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_213 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_213 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001207_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_57 ^ pub_r001207_16) & 63;
    if ((stage_v_215 & 1) != 0) {
        if ((stage_v_142 & 2) != 0) {
            out_sink = (out_sink + stage_v_215 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_215 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001207_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_150 ^ pub_r001207_2) & 63;
    if ((stage_v_217 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_217 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_217 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_76 ^ pub_r001207_8) & 63;
    if ((stage_v_218 & 1) != 0) {
        if ((stage_v_111 & 2) != 0) {
            out_sink = (out_sink + stage_v_218 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_218 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001207_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_145 ^ pub_r001207_4) & 63;
    if ((stage_v_220 & 1) != 0) {
        if ((stage_v_177 & 2) != 0) {
            out_sink = (out_sink + stage_v_220 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_220 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001207_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_171 ^ pub_r001207_4) & 63;
    if ((stage_v_222 & 1) != 0) {
        if ((sec_r001207_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_222 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_222 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_195 ^ pub_r001207_7) & 63;
    if ((stage_v_223 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_223 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_223 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001207_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (sec_r001207_14 ^ pub_r001207_6) & 63;
    if ((stage_v_225 & 1) != 0) {
        if ((stage_v_171 & 2) != 0) {
            out_sink = (out_sink + stage_v_225 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_225 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (sec_r001207_0 ^ pub_r001207_9) & 63;
    if ((stage_v_226 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_226 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_226 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_68 ^ pub_r001207_12) & 63;
    if ((stage_v_227 & 1) != 0) {
        if ((stage_v_197 & 2) != 0) {
            out_sink = (out_sink + stage_v_227 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_227 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_217 ^ pub_r001207_12) & 63;
    if ((stage_v_228 & 1) != 0) {
        if ((stage_v_155 & 2) != 0) {
            out_sink = (out_sink + stage_v_228 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_228 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (sec_r001207_9 ^ pub_r001207_6) & 63;
    if ((stage_v_229 & 1) != 0) {
        if ((stage_v_152 & 2) != 0) {
            out_sink = (out_sink + stage_v_229 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_229 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
