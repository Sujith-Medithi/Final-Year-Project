/*
 * Benchmark Program: R001027
 * Security Family: nested_implicit_flow
 * Generator Seed: 602713
 * High Inputs: 17 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001027_2713_0 {
    unsigned char facility;
    int signature;
    short code;
    short seq;
    int timestamp;
    short severity;
    int buffer[3];
};

struct AudioFrame_R001027_2713_1 {
    int rms;
    unsigned char peak;
    unsigned char channels;
    int sample_rate;
    short envelope;
    int buffer[3];
};

struct CipherContext_R001027_2713_2 {
    short iv;
    short counter;
    short flags;
    short round_key;
    short tag;
    int nonce;
    int buffer[3];
};

union ColorPixel_R001027_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001027_2713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001027_2713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_77 = (aux + st.buffer[1]) & 3;
    switch (index_reg_77) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_44 = local_arr[aux % 3];
    acc = (acc + delta_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001027_2713_1(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int index_reg_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_77) & 63;
    acc ^= aux;
    int mask_17 = (aux + st.buffer[1]) & 3;
    switch (mask_17) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001027_2713_2(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int phase_58 = 0;
    for (int k = 0; k < 3; k++) {
        phase_58 = (phase_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_58) & 127;
    }
    int mask_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_33) & 63;
    acc ^= aux;
    int mask_90 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_90 > 34) {
        acc = (acc + mask_90 * 2 + 5) & 127;
        aux ^= (mask_90 & 15);
    } else {
        acc = (acc - mask_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001027_2713_3(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_96 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_96 > 13) {
        acc = (acc + stride_96 * 2 + 5) & 127;
        aux ^= (stride_96 & 15);
    } else {
        acc = (acc - stride_96 + 11) & 127;
        aux += 3;
    }
    int accumulator_94 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_94 = (accumulator_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_94) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_91 = local_arr[aux % 3];
    acc = (acc + scale_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001027_2713_4(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_29) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_37 = local_arr[aux % 3];
    acc = (acc + window_37 * 2) & 127;
    int tally_71 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_71 > 23) {
        acc = (acc + tally_71 * 2 + 5) & 127;
        aux ^= (tally_71 & 15);
    } else {
        acc = (acc - tally_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001027_2713_5(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int checksum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_84) & 63;
    acc ^= aux;
    int mask_41 = (aux + st.buffer[1]) & 3;
    switch (mask_41) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_76 = local_arr[aux % 3];
    acc = (acc + metric_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001027_2713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int index_reg_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_20) & 63;
    acc ^= aux;
    int vector_50 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_50 > 23) {
        acc = (acc + vector_50 * 2 + 5) & 127;
        aux ^= (vector_50 & 15);
    } else {
        acc = (acc - vector_50 + 11) & 127;
        aux += 3;
    }
    int damping_53 = 0;
    for (int k = 0; k < 3; k++) {
        damping_53 = (damping_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_53) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001027_2713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_89 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_89 > 44) {
        acc = (acc + delta_89 * 2 + 5) & 127;
        aux ^= (delta_89 & 15);
    } else {
        acc = (acc - delta_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_47 = (aux + st.buffer[1]) & 3;
    switch (parity_47) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_23 = 0;
    for (int k = 0; k < 2; k++) {
        stride_23 = (stride_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001027_2713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int segment_83 = (aux + st.buffer[1]) & 3;
    switch (segment_83) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_11 = 0;
    for (int k = 0; k < 2; k++) {
        metric_11 = (metric_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_11) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001027_2713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_15 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_15 = (accumulator_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_15) & 127;
    }
    int anchor_63 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_63 > 27) {
        acc = (acc + anchor_63 * 2 + 5) & 127;
        aux ^= (anchor_63 & 15);
    } else {
        acc = (acc - anchor_63 + 11) & 127;
        aux += 3;
    }
    int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001027_2713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int vector_73 = (aux + st.buffer[1]) & 3;
    switch (vector_73) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_43) & 63;
    acc ^= aux;
    int anchor_91 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_91 > 32) {
        acc = (acc + anchor_91 * 2 + 5) & 127;
        aux ^= (anchor_91 & 15);
    } else {
        acc = (acc - anchor_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001027_2713_11(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001027_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_59 = 0;
    for (int k = 0; k < 2; k++) {
        segment_59 = (segment_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_59) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001027_2713_12(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001027_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int segment_77 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_77 > 34) {
        acc = (acc + segment_77 * 2 + 5) & 127;
        aux ^= (segment_77 & 15);
    } else {
        acc = (acc - segment_77 + 11) & 127;
        aux += 3;
    }
    int tally_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001027_2713_13(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001027_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_81 = 0;
    for (int k = 0; k < 2; k++) {
        offset_81 = (offset_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_81) & 127;
    }
    int sample_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_32) & 63;
    acc ^= aux;
    int bound_58 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_58 > 29) {
        acc = (acc + bound_58 * 2 + 5) & 127;
        aux ^= (bound_58 & 15);
    } else {
        acc = (acc - bound_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001027_0;
    int sec_r001027_1;
    int sec_r001027_2;
    int sec_r001027_3;
    int sec_r001027_4;
    int sec_r001027_5;
    int sec_r001027_6;
    int sec_r001027_7;
    int sec_r001027_8;
    int sec_r001027_9;
    int sec_r001027_10;
    int sec_r001027_11;
    int sec_r001027_12;
    int sec_r001027_13;
    int sec_r001027_14;
    int sec_r001027_15;
    int sec_r001027_16;
    int pub_r001027_0;
    int pub_r001027_1;
    int pub_r001027_2;
    int pub_r001027_3;
    int pub_r001027_4;
    int pub_r001027_5;
    int pub_r001027_6;
    int pub_r001027_7;
    int pub_r001027_8;
    int pub_r001027_9;
    int pub_r001027_10;
    int pub_r001027_11;
    int pub_r001027_12;
    int pub_r001027_13;
    int pub_r001027_14;
    int pub_r001027_15;
    int pub_r001027_16;
    int pub_r001027_17;
    int pub_r001027_18;
    int pub_r001027_19;
    int pub_r001027_20;
    int pub_r001027_21;
    int pub_r001027_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001027_0 >= -100 && pub_r001027_0 <= 100);
    __CPROVER_assume(pub_r001027_1 >= -100 && pub_r001027_1 <= 100);
    __CPROVER_assume(pub_r001027_2 >= -100 && pub_r001027_2 <= 100);
    __CPROVER_assume(pub_r001027_3 >= -100 && pub_r001027_3 <= 100);
    __CPROVER_assume(pub_r001027_4 >= -100 && pub_r001027_4 <= 100);
    __CPROVER_assume(pub_r001027_5 >= -100 && pub_r001027_5 <= 100);
    __CPROVER_assume(pub_r001027_6 >= -100 && pub_r001027_6 <= 100);
    __CPROVER_assume(pub_r001027_7 >= -100 && pub_r001027_7 <= 100);
    __CPROVER_assume(pub_r001027_8 >= -100 && pub_r001027_8 <= 100);
    __CPROVER_assume(pub_r001027_9 >= -100 && pub_r001027_9 <= 100);
    __CPROVER_assume(pub_r001027_10 >= -100 && pub_r001027_10 <= 100);
    __CPROVER_assume(pub_r001027_11 >= -100 && pub_r001027_11 <= 100);
    __CPROVER_assume(pub_r001027_12 >= -100 && pub_r001027_12 <= 100);
    __CPROVER_assume(pub_r001027_13 >= -100 && pub_r001027_13 <= 100);
    __CPROVER_assume(pub_r001027_14 >= -100 && pub_r001027_14 <= 100);
    __CPROVER_assume(pub_r001027_15 >= -100 && pub_r001027_15 <= 100);
    __CPROVER_assume(pub_r001027_16 >= -100 && pub_r001027_16 <= 100);
    __CPROVER_assume(pub_r001027_17 >= -100 && pub_r001027_17 <= 100);
    __CPROVER_assume(pub_r001027_18 >= -100 && pub_r001027_18 <= 100);
    __CPROVER_assume(pub_r001027_19 >= -100 && pub_r001027_19 <= 100);
    __CPROVER_assume(pub_r001027_20 >= -100 && pub_r001027_20 <= 100);
    __CPROVER_assume(pub_r001027_21 >= -100 && pub_r001027_21 <= 100);
    __CPROVER_assume(pub_r001027_22 >= -100 && pub_r001027_22 <= 100);
    __CPROVER_assume(sec_r001027_0 >= 0 && sec_r001027_0 <= 255);
    __CPROVER_assume(sec_r001027_1 >= 0 && sec_r001027_1 <= 255);
    __CPROVER_assume(sec_r001027_2 >= 0 && sec_r001027_2 <= 255);
    __CPROVER_assume(sec_r001027_3 >= 0 && sec_r001027_3 <= 255);
    __CPROVER_assume(sec_r001027_4 >= 0 && sec_r001027_4 <= 255);
    __CPROVER_assume(sec_r001027_5 >= 0 && sec_r001027_5 <= 255);
    __CPROVER_assume(sec_r001027_6 >= 0 && sec_r001027_6 <= 255);
    __CPROVER_assume(sec_r001027_7 >= 0 && sec_r001027_7 <= 255);
    __CPROVER_assume(sec_r001027_8 >= 0 && sec_r001027_8 <= 255);
    __CPROVER_assume(sec_r001027_9 >= 0 && sec_r001027_9 <= 255);
    __CPROVER_assume(sec_r001027_10 >= 0 && sec_r001027_10 <= 255);
    __CPROVER_assume(sec_r001027_11 >= 0 && sec_r001027_11 <= 255);
    __CPROVER_assume(sec_r001027_12 >= 0 && sec_r001027_12 <= 255);
    __CPROVER_assume(sec_r001027_13 >= 0 && sec_r001027_13 <= 255);
    __CPROVER_assume(sec_r001027_14 >= 0 && sec_r001027_14 <= 255);
    __CPROVER_assume(sec_r001027_15 >= 0 && sec_r001027_15 <= 255);
    __CPROVER_assume(sec_r001027_16 >= 0 && sec_r001027_16 <= 255);

    struct EventLog_R001027_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001027_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001027_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001027_0 + 7) & 15;
    struct AudioFrame_R001027_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001027_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001027_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001027_0 + 9) & 15;
    struct CipherContext_R001027_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001027_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001027_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001027_0 + 11) & 15;

    union ColorPixel_R001027_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001027_2713_0(sec_r001027_0, pub_r001027_1, pub_r001027_2, pub_r001027_3);
    int helper_flow_1 = fn_R001027_2713_1(sec_r001027_1, pub_r001027_2, pub_r001027_3);
    int helper_flow_2 = fn_R001027_2713_2(sec_r001027_2, pub_r001027_3, pub_r001027_4);
    int helper_flow_3 = fn_R001027_2713_3(sec_r001027_3, sec_r001027_4, pub_r001027_5);
    int helper_flow_4 = fn_R001027_2713_4(sec_r001027_4, sec_r001027_5);
    int helper_flow_5 = fn_R001027_2713_5(sec_r001027_5, pub_r001027_6);
    int helper_flow_6 = fn_R001027_2713_6(sec_r001027_6, sec_r001027_7, pub_r001027_8, pub_r001027_9);
    int helper_flow_7 = fn_R001027_2713_7(sec_r001027_7, pub_r001027_8, pub_r001027_9, pub_r001027_10, pub_r001027_11);
    int helper_flow_8 = fn_R001027_2713_8(sec_r001027_8, pub_r001027_9, pub_r001027_10, pub_r001027_11, pub_r001027_12);
    int helper_flow_9 = fn_R001027_2713_9(sec_r001027_9, sec_r001027_10, pub_r001027_11, pub_r001027_12, pub_r001027_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001027_6 ^ pub_r001027_6) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_8 ^ pub_r001027_5) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001027_7 ^ pub_r001027_20) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_0 ^ pub_r001027_11) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001027_3 ^ pub_r001027_1) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001027_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (stage_v_4 ^ pub_r001027_1) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001027_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001027_12 ^ pub_r001027_22) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001027_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001027_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001027_16 ^ pub_r001027_16) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001027_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_0 ^ pub_r001027_15) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001027_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001027_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001027_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001027_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001027_14 ^ pub_r001027_9) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001027_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (helper_flow_1 ^ pub_r001027_5) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001027_5 ^ pub_r001027_10) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_4 ^ pub_r001027_15) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001027_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001027_11 ^ pub_r001027_3) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001027_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001027_10 ^ pub_r001027_8) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001027_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001027_6 ^ pub_r001027_2) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_4 ^ pub_r001027_19) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001027_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001027_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001027_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_5 ^ pub_r001027_22) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001027_1 ^ pub_r001027_20) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001027_8 ^ pub_r001027_0) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001027_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001027_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001027_6 ^ pub_r001027_17) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001027_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001027_13 ^ pub_r001027_0) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r001027_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001027_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_19 ^ pub_r001027_17) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001027_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001027_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001027_4 ^ pub_r001027_20) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001027_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_4 ^ pub_r001027_21) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001027_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_3 ^ pub_r001027_2) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001027_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_11 ^ pub_r001027_4) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001027_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_7 ^ pub_r001027_9) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001027_16 ^ pub_r001027_21) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_16 ^ pub_r001027_19) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001027_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001027_12 ^ pub_r001027_0) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_4 ^ pub_r001027_5) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_5 ^ pub_r001027_2) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001027_10 ^ pub_r001027_3) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001027_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001027_6 ^ pub_r001027_12) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r001027_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001027_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_5 ^ pub_r001027_7) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001027_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_19 ^ pub_r001027_20) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001027_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001027_2 ^ pub_r001027_19) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001027_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001027_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001027_5 ^ pub_r001027_2) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_0 ^ pub_r001027_8) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001027_9 ^ pub_r001027_17) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_19 ^ pub_r001027_19) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001027_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001027_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (helper_flow_3 ^ pub_r001027_3) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001027_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001027_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001027_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001027_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (helper_flow_0 ^ pub_r001027_1) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_49 ^ pub_r001027_8) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_23 ^ pub_r001027_0) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r001027_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_45 ^ pub_r001027_19) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001027_5 ^ pub_r001027_11) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r001027_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001027_0 ^ pub_r001027_8) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001027_0 ^ pub_r001027_12) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001027_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001027_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001027_6 ^ pub_r001027_19) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001027_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001027_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_4 ^ pub_r001027_17) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_18 ^ pub_r001027_6) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_76 ^ pub_r001027_12) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_19 ^ pub_r001027_0) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001027_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001027_1 ^ pub_r001027_6) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r001027_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_41 ^ pub_r001027_21) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001027_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001027_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001027_6 ^ pub_r001027_10) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001027_5 ^ pub_r001027_8) & 63;
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
    int stage_v_89 = (pub_r001027_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_45 ^ pub_r001027_3) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_49 ^ pub_r001027_14) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001027_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001027_4 ^ pub_r001027_4) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r001027_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_51 ^ pub_r001027_3) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r001027_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001027_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_71 ^ pub_r001027_8) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001027_7 ^ pub_r001027_13) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_49 ^ pub_r001027_3) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001027_11 ^ pub_r001027_13) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001027_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001027_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_38 ^ pub_r001027_15) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001027_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_93 ^ pub_r001027_12) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001027_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_72 ^ pub_r001027_13) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001027_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_57 ^ pub_r001027_11) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r001027_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001027_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (helper_flow_5 ^ pub_r001027_2) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001027_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_0 ^ pub_r001027_1) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_19 ^ pub_r001027_14) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001027_22 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_41 ^ pub_r001027_21) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001027_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_0 ^ pub_r001027_7) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_19 ^ pub_r001027_2) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001027_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001027_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001027_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001027_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001027_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_45 ^ pub_r001027_0) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001027_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001027_10 ^ pub_r001027_3) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_33 ^ pub_r001027_1) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001027_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_58 ^ pub_r001027_15) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_54 ^ pub_r001027_16) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001027_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_44 ^ pub_r001027_1) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_44 ^ pub_r001027_14) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_87 ^ pub_r001027_3) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001027_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_79 ^ pub_r001027_13) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_131 ^ pub_r001027_14) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001027_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_117 ^ pub_r001027_5) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_110 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001027_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_18 ^ pub_r001027_17) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001027_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_57 ^ pub_r001027_2) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_94 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001027_22 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r001027_4 ^ pub_r001027_19) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_142 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001027_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_132 ^ pub_r001027_1) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_68 ^ pub_r001027_22) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001027_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_21 ^ pub_r001027_2) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r001027_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_63 ^ pub_r001027_18) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001027_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_88 ^ pub_r001027_1) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001027_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_49 ^ pub_r001027_20) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001027_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_54 ^ pub_r001027_12) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_3 ^ pub_r001027_4) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_71 ^ pub_r001027_5) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_149 ^ pub_r001027_11) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001027_22 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_131 ^ pub_r001027_5) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_90 ^ pub_r001027_2) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((sec_r001027_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_79 ^ pub_r001027_18) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_35 ^ pub_r001027_18) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_118 ^ pub_r001027_22) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_164 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (sec_r001027_11 ^ pub_r001027_9) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_41 ^ pub_r001027_14) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((sec_r001027_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_162 ^ pub_r001027_16) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_157 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_72 ^ pub_r001027_4) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((sec_r001027_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001027_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (helper_flow_4 ^ pub_r001027_15) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_99 ^ pub_r001027_20) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_157 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001027_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001027_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001027_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001027_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001027_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_140 ^ pub_r001027_15) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((sec_r001027_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (helper_flow_0 ^ pub_r001027_1) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001027_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001027_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001027_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001027_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_159 ^ pub_r001027_11) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_156 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_161 ^ pub_r001027_19) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_131 ^ pub_r001027_21) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_140 ^ pub_r001027_7) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_185 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_113 ^ pub_r001027_5) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001027_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001027_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_140 ^ pub_r001027_19) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_158 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001027_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_67 ^ pub_r001027_4) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_144 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_9 ^ pub_r001027_22) & 63;
    if ((stage_v_194 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_194 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_194 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_71 ^ pub_r001027_20) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_5 ^ pub_r001027_4) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_110 ^ pub_r001027_8) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001027_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_149 ^ pub_r001027_21) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_157 ^ pub_r001027_22) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((sec_r001027_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_161 ^ pub_r001027_16) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001027_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_201 ^ pub_r001027_11) & 63;
    if ((stage_v_203 & 1) != 0) {
        if ((stage_v_193 & 2) != 0) {
            out_sink = (out_sink + stage_v_203 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_203 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_168 ^ pub_r001027_9) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((stage_v_125 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001027_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001027_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_106 ^ pub_r001027_3) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((stage_v_154 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_110 ^ pub_r001027_0) & 63;
    if ((stage_v_208 & 1) != 0) {
        if ((stage_v_204 & 2) != 0) {
            out_sink = (out_sink + stage_v_208 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_208 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_197 ^ pub_r001027_3) & 63;
    if ((stage_v_209 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_209 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_209 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_2 ^ pub_r001027_5) & 63;
    if ((stage_v_210 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_210 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_210 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
