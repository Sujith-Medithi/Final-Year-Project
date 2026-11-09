/*
 * Benchmark Program: R001192
 * Security Family: direct_leakage
 * Generator Seed: 619213
 * High Inputs: 20 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001192_9213_0 {
    unsigned char gain_db;
    unsigned char cutoff;
    int prev_in;
    unsigned char mode;
    unsigned char prev_out;
    short damping;
    int buffer[3];
};

struct SensorNode_R001192_9213_1 {
    int calib;
    int status;
    short offset;
    short threshold;
    short reading;
    unsigned char gain;
    int buffer[3];
};

struct EventLog_R001192_9213_2 {
    int signature;
    int severity;
    short timestamp;
    short seq;
    int code;
    unsigned char facility;
    int buffer[3];
};

struct CipherContext_R001192_9213_3 {
    unsigned char flags;
    int counter;
    int nonce;
    int round_key;
    int buffer[3];
};

union TelemetryField_R001192_9213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001192_9213_0(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001192_9213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int threshold_79 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_79 = (threshold_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_79) & 127;
    }
    int window_35 = (aux + st.buffer[1]) & 3;
    switch (window_35) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001192_9213_1(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001192_9213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int cursor_53 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_53 = (cursor_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_53) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001192_9213_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001192_9213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_76 = 0;
    for (int k = 0; k < 3; k++) {
        tally_76 = (tally_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_76) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001192_9213_3(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001192_9213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int stride_55 = local_arr[aux % 3];
    acc = (acc + stride_55 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_38 = 0;
    for (int k = 0; k < 2; k++) {
        offset_38 = (offset_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_38) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001192_9213_4(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001192_9213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int phase_99 = (aux + st.buffer[1]) & 3;
    switch (phase_99) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_86 = local_arr[aux % 3];
    acc = (acc + vector_86 * 2) & 127;
    int delta_17 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_17 > 43) {
        acc = (acc + delta_17 * 2 + 5) & 127;
        aux ^= (delta_17 & 15);
    } else {
        acc = (acc - delta_17 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001192_9213_5(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001192_9213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_57 = (aux + st.buffer[1]) & 3;
    switch (quantum_57) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001192_9213_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001192_9213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_91) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_25 = local_arr[aux % 3];
    acc = (acc + cursor_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001192_9213_7(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001192_9213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quotient_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_48) & 63;
    acc ^= aux;
    int residue_24 = 0;
    for (int k = 0; k < 3; k++) {
        residue_24 = (residue_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_24) & 127;
    }
    int anchor_47 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_47 > 43) {
        acc = (acc + anchor_47 * 2 + 5) & 127;
        aux ^= (anchor_47 & 15);
    } else {
        acc = (acc - anchor_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001192_9213_8(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001192_9213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int sample_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_84) & 63;
    acc ^= aux;
    int segment_59 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_59 > 48) {
        acc = (acc + segment_59 * 2 + 5) & 127;
        aux ^= (segment_59 & 15);
    } else {
        acc = (acc - segment_59 + 11) & 127;
        aux += 3;
    }
    int residue_94 = 0;
    for (int k = 0; k < 3; k++) {
        residue_94 = (residue_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_94) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001192_9213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001192_9213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int segment_30 = 0;
    for (int k = 0; k < 2; k++) {
        segment_30 = (segment_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_30) & 127;
    }
    int mask_81 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_81 > 11) {
        acc = (acc + mask_81 * 2 + 5) & 127;
        aux ^= (mask_81 & 15);
    } else {
        acc = (acc - mask_81 + 11) & 127;
        aux += 3;
    }
    int tracker_41 = (aux + st.buffer[1]) & 3;
    switch (tracker_41) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001192_9213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001192_9213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int scale_90 = (aux + st.buffer[1]) & 3;
    switch (scale_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_58 = 0;
    for (int k = 0; k < 2; k++) {
        mask_58 = (mask_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_58) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_10 = local_arr[aux % 3];
    acc = (acc + sample_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001192_9213_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001192_9213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int cursor_29 = local_arr[aux % 3];
    acc = (acc + cursor_29 * 2) & 127;
    int coefficient_49 = (aux + st.buffer[1]) & 3;
    switch (coefficient_49) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001192_9213_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001192_9213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int phase_68 = 0;
    for (int k = 0; k < 3; k++) {
        phase_68 = (phase_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_68) & 127;
    }
    int metric_53 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_53 > 10) {
        acc = (acc + metric_53 * 2 + 5) & 127;
        aux ^= (metric_53 & 15);
    } else {
        acc = (acc - metric_53 + 11) & 127;
        aux += 3;
    }
    int damping_46 = (aux + st.buffer[1]) & 3;
    switch (damping_46) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001192_9213_13(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001192_9213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_43 = (aux + st.buffer[1]) & 3;
    switch (phase_43) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_19 = 0;
    for (int k = 0; k < 3; k++) {
        residue_19 = (residue_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_19) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001192_9213_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001192_9213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int metric_71 = local_arr[aux % 3];
    acc = (acc + metric_71 * 2) & 127;
    int delta_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_60) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001192_0;
    int sec_r001192_1;
    int sec_r001192_2;
    int sec_r001192_3;
    int sec_r001192_4;
    int sec_r001192_5;
    int sec_r001192_6;
    int sec_r001192_7;
    int sec_r001192_8;
    int sec_r001192_9;
    int sec_r001192_10;
    int sec_r001192_11;
    int sec_r001192_12;
    int sec_r001192_13;
    int sec_r001192_14;
    int sec_r001192_15;
    int sec_r001192_16;
    int sec_r001192_17;
    int sec_r001192_18;
    int sec_r001192_19;
    int pub_r001192_0;
    int pub_r001192_1;
    int pub_r001192_2;
    int pub_r001192_3;
    int pub_r001192_4;
    int pub_r001192_5;
    int pub_r001192_6;
    int pub_r001192_7;
    int pub_r001192_8;
    int pub_r001192_9;
    int pub_r001192_10;
    int pub_r001192_11;
    int pub_r001192_12;
    int pub_r001192_13;
    int pub_r001192_14;
    int pub_r001192_15;
    int pub_r001192_16;
    int pub_r001192_17;
    int pub_r001192_18;
    int pub_r001192_19;
    int pub_r001192_20;
    int pub_r001192_21;
    int pub_r001192_22;
    int pub_r001192_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001192_0 >= -100 && pub_r001192_0 <= 100);
    __CPROVER_assume(pub_r001192_1 >= -100 && pub_r001192_1 <= 100);
    __CPROVER_assume(pub_r001192_2 >= -100 && pub_r001192_2 <= 100);
    __CPROVER_assume(pub_r001192_3 >= -100 && pub_r001192_3 <= 100);
    __CPROVER_assume(pub_r001192_4 >= -100 && pub_r001192_4 <= 100);
    __CPROVER_assume(pub_r001192_5 >= -100 && pub_r001192_5 <= 100);
    __CPROVER_assume(pub_r001192_6 >= -100 && pub_r001192_6 <= 100);
    __CPROVER_assume(pub_r001192_7 >= -100 && pub_r001192_7 <= 100);
    __CPROVER_assume(pub_r001192_8 >= -100 && pub_r001192_8 <= 100);
    __CPROVER_assume(pub_r001192_9 >= -100 && pub_r001192_9 <= 100);
    __CPROVER_assume(pub_r001192_10 >= -100 && pub_r001192_10 <= 100);
    __CPROVER_assume(pub_r001192_11 >= -100 && pub_r001192_11 <= 100);
    __CPROVER_assume(pub_r001192_12 >= -100 && pub_r001192_12 <= 100);
    __CPROVER_assume(pub_r001192_13 >= -100 && pub_r001192_13 <= 100);
    __CPROVER_assume(pub_r001192_14 >= -100 && pub_r001192_14 <= 100);
    __CPROVER_assume(pub_r001192_15 >= -100 && pub_r001192_15 <= 100);
    __CPROVER_assume(pub_r001192_16 >= -100 && pub_r001192_16 <= 100);
    __CPROVER_assume(pub_r001192_17 >= -100 && pub_r001192_17 <= 100);
    __CPROVER_assume(pub_r001192_18 >= -100 && pub_r001192_18 <= 100);
    __CPROVER_assume(pub_r001192_19 >= -100 && pub_r001192_19 <= 100);
    __CPROVER_assume(pub_r001192_20 >= -100 && pub_r001192_20 <= 100);
    __CPROVER_assume(pub_r001192_21 >= -100 && pub_r001192_21 <= 100);
    __CPROVER_assume(pub_r001192_22 >= -100 && pub_r001192_22 <= 100);
    __CPROVER_assume(pub_r001192_23 >= -100 && pub_r001192_23 <= 100);
    __CPROVER_assume(sec_r001192_0 >= 0 && sec_r001192_0 <= 255);
    __CPROVER_assume(sec_r001192_1 >= 0 && sec_r001192_1 <= 255);
    __CPROVER_assume(sec_r001192_2 >= 0 && sec_r001192_2 <= 255);
    __CPROVER_assume(sec_r001192_3 >= 0 && sec_r001192_3 <= 255);
    __CPROVER_assume(sec_r001192_4 >= 0 && sec_r001192_4 <= 255);
    __CPROVER_assume(sec_r001192_5 >= 0 && sec_r001192_5 <= 255);
    __CPROVER_assume(sec_r001192_6 >= 0 && sec_r001192_6 <= 255);
    __CPROVER_assume(sec_r001192_7 >= 0 && sec_r001192_7 <= 255);
    __CPROVER_assume(sec_r001192_8 >= 0 && sec_r001192_8 <= 255);
    __CPROVER_assume(sec_r001192_9 >= 0 && sec_r001192_9 <= 255);
    __CPROVER_assume(sec_r001192_10 >= 0 && sec_r001192_10 <= 255);
    __CPROVER_assume(sec_r001192_11 >= 0 && sec_r001192_11 <= 255);
    __CPROVER_assume(sec_r001192_12 >= 0 && sec_r001192_12 <= 255);
    __CPROVER_assume(sec_r001192_13 >= 0 && sec_r001192_13 <= 255);
    __CPROVER_assume(sec_r001192_14 >= 0 && sec_r001192_14 <= 255);
    __CPROVER_assume(sec_r001192_15 >= 0 && sec_r001192_15 <= 255);
    __CPROVER_assume(sec_r001192_16 >= 0 && sec_r001192_16 <= 255);
    __CPROVER_assume(sec_r001192_17 >= 0 && sec_r001192_17 <= 255);
    __CPROVER_assume(sec_r001192_18 >= 0 && sec_r001192_18 <= 255);
    __CPROVER_assume(sec_r001192_19 >= 0 && sec_r001192_19 <= 255);

    struct FilterState_R001192_9213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001192_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001192_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001192_0 + 7) & 15;
    struct SensorNode_R001192_9213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001192_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001192_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001192_0 + 9) & 15;
    struct EventLog_R001192_9213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001192_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001192_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001192_0 + 11) & 15;
    struct CipherContext_R001192_9213_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001192_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001192_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001192_0 + 13) & 15;

    union TelemetryField_R001192_9213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001192_9213_0(sec_r001192_0, pub_r001192_1);
    int helper_flow_1 = fn_R001192_9213_1(sec_r001192_1, pub_r001192_2);
    int helper_flow_2 = fn_R001192_9213_2(sec_r001192_2, pub_r001192_3, pub_r001192_4, pub_r001192_5);
    int helper_flow_3 = fn_R001192_9213_3(sec_r001192_3, sec_r001192_4);
    int helper_flow_4 = fn_R001192_9213_4(sec_r001192_4, pub_r001192_5, pub_r001192_6);
    int helper_flow_5 = fn_R001192_9213_5(sec_r001192_5, sec_r001192_6);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001192_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001192_14 * 3) + pub_r001192_6 + 43) & 127;
    sec_accum = (sec_accum + stage_v_1) & 255;
    out_sink = (out_sink + stage_v_1 * 2) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001192_7 * 3) + pub_r001192_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001192_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001192_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001192_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001192_20 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001192_9 * 3) + pub_r001192_18 + 13) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001192_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001192_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001192_18 * 3) + pub_r001192_1 + 38) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001192_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001192_13 * 3) + pub_r001192_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001192_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001192_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001192_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001192_10 * 3) + pub_r001192_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001192_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001192_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001192_14 * 3) + pub_r001192_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001192_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001192_23 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001192_19 * 3) + pub_r001192_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_1 * 3) + pub_r001192_6 + 19) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001192_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001192_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001192_18 * 3) + pub_r001192_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26 * 2) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001192_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_2 * 3) + pub_r001192_3 + 39) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_12 * 3) + pub_r001192_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29 * 2) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001192_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001192_8 * 3) + pub_r001192_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31 * 2) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001192_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001192_1 * 3) + pub_r001192_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001192_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001192_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001192_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001192_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001192_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001192_23 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001192_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001192_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001192_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_3 * 3) + pub_r001192_22 + 29) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001192_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001192_0 * 3) + pub_r001192_19 + 31) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45 * 2) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001192_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001192_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_7 * 3) + pub_r001192_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001192_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001192_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001192_5 * 3) + pub_r001192_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_29 * 3) + pub_r001192_23 + 27) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001192_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001192_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001192_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001192_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001192_22 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001192_11 * 3) + pub_r001192_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001192_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_28 * 3) + pub_r001192_5 + 44) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001192_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001192_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001192_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001192_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_48 * 3) + pub_r001192_4 + 27) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001192_23 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001192_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001192_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001192_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_48 * 3) + pub_r001192_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70 * 2) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001192_1 * 3) + pub_r001192_23 + 19) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001192_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001192_2 * 3) + pub_r001192_20 + 45) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73 * 2) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001192_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001192_9 * 3) + pub_r001192_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75 * 2) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001192_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_65 * 3) + pub_r001192_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_2 * 3) + pub_r001192_5 + 31) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_29 * 3) + pub_r001192_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001192_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001192_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001192_8 * 3) + pub_r001192_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82 * 2) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_31 * 3) + pub_r001192_15 + 39) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001192_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001192_23 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_26 * 3) + pub_r001192_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001192_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_28 * 3) + pub_r001192_12 + 39) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001192_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_2 * 3) + pub_r001192_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001192_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001192_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001192_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001192_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001192_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_1 * 3) + pub_r001192_23 + 41) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001192_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001192_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001192_1 * 3) + pub_r001192_23 + 28) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_48 * 3) + pub_r001192_19 + 24) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001192_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001192_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_31 * 3) + pub_r001192_14 + 34) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103 * 2) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001192_4 * 3) + pub_r001192_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001192_21 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_19 * 3) + pub_r001192_16 + 24) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001192_21 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001192_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_26 * 3) + pub_r001192_19 + 39) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_104 * 3) + pub_r001192_19 + 7) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_10 * 3) + pub_r001192_21 + 20) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_106 * 3) + pub_r001192_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001192_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001192_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001192_7 * 3) + pub_r001192_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115 * 2) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001192_16 * 3) + pub_r001192_13 + 39) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_52 * 3) + pub_r001192_18 + 26) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117 * 2) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_26 * 3) + pub_r001192_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118 * 2) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001192_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001192_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001192_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001192_20 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_88 * 3) + pub_r001192_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123 * 2) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001192_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001192_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001192_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001192_23 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001192_21 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((helper_flow_5 * 3) + pub_r001192_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_106 * 3) + pub_r001192_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_7 * 3) + pub_r001192_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001192_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001192_19 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r001192_17 * 3) + pub_r001192_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134 * 2) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_118 * 3) + pub_r001192_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_0 * 3) + pub_r001192_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001192_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001192_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_16 * 3) + pub_r001192_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001192_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_19 * 3) + pub_r001192_18 + 18) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001192_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001192_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001192_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001192_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001192_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001192_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_86 * 3) + pub_r001192_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_99 * 3) + pub_r001192_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149 * 2) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_118 * 3) + pub_r001192_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001192_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001192_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001192_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_123 * 3) + pub_r001192_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((helper_flow_5 * 3) + pub_r001192_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155 * 2) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001192_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001192_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r001192_0 * 3) + pub_r001192_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001192_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001192_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_28 * 3) + pub_r001192_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001192_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001192_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001192_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001192_23 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001192_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001192_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r001192_5 * 3) + pub_r001192_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168 * 2) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_99 * 3) + pub_r001192_13 + 45) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169 * 2) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001192_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001192_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001192_22 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001192_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001192_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001192_22 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_168 * 3) + pub_r001192_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001192_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r001192_3 * 3) + pub_r001192_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_70 * 3) + pub_r001192_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_58 * 3) + pub_r001192_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001192_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001192_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001192_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r001192_12 * 3) + pub_r001192_11 + 24) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_103 * 3) + pub_r001192_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_29 * 3) + pub_r001192_10 + 25) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001192_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001192_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001192_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001192_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001192_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001192_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001192_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001192_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001192_21 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001192_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001192_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001192_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001192_23 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001192_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_83 * 3) + pub_r001192_20 + 16) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_79 * 3) + pub_r001192_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001192_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001192_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001192_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_117 * 3) + pub_r001192_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206 * 2) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001192_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001192_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001192_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001192_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001192_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001192_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001192_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001192_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_79 * 3) + pub_r001192_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001192_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_16 * 3) + pub_r001192_23 + 15) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001192_20 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001192_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r001192_0 * 3) + pub_r001192_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220 * 2) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001192_22 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_148 * 3) + pub_r001192_18 + 3) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222 * 2) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001192_12 * 3) + pub_r001192_6 + 45) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001192_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001192_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_215 * 3) + pub_r001192_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_169 * 3) + pub_r001192_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001192_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001192_22 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_52 * 3) + pub_r001192_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001192_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001192_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_58 * 3) + pub_r001192_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001192_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r001192_3 * 3) + pub_r001192_19 + 12) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001192_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001192_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001192_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_86 * 3) + pub_r001192_17 + 25) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001192_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001192_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_106 * 3) + pub_r001192_20 + 13) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242 * 2) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((helper_flow_3 * 3) + pub_r001192_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243 * 2) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_16 * 3) + pub_r001192_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001192_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_161 * 3) + pub_r001192_21 + 34) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246 * 2) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001192_21 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001192_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_244 * 3) + pub_r001192_20 + 12) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249 * 2) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001192_23 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001192_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001192_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001192_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_233 * 3) + pub_r001192_20 + 34) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001192_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001192_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001192_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((sec_r001192_1 * 3) + pub_r001192_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258 * 2) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001192_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_243 * 3) + pub_r001192_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260 * 2) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_99 * 3) + pub_r001192_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001192_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001192_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_65 * 3) + pub_r001192_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_103 * 3) + pub_r001192_17 + 7) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265 * 2) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_43 * 3) + pub_r001192_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_96 * 3) + pub_r001192_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((sec_r001192_17 * 3) + pub_r001192_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001192_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001192_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001192_22 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001192_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((sec_r001192_16 * 3) + pub_r001192_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001192_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((helper_flow_0 * 3) + pub_r001192_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((helper_flow_5 * 3) + pub_r001192_20 + 17) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001192_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001192_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001192_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_155 * 3) + pub_r001192_19 + 33) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001192_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001192_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001192_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001192_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001192_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001192_19 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_78 * 3) + pub_r001192_20 + 16) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287 * 2) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001192_20 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001192_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001192_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001192_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r001192_10 * 3) + pub_r001192_20 + 30) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((sec_r001192_15 * 3) + pub_r001192_21 + 11) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001192_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001192_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_233 * 3) + pub_r001192_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001192_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001192_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001192_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001192_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_184 * 3) + pub_r001192_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001192_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001192_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001192_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((helper_flow_3 * 3) + pub_r001192_23 + 26) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001192_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001192_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001192_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_239 * 3) + pub_r001192_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001192_20 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001192_22 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001192_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_52 * 3) + pub_r001192_21 + 26) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313 * 2) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001192_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001192_20 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001192_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001192_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001192_20 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_1 * 3) + pub_r001192_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319 * 2) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r001192_7 * 3) + pub_r001192_4 + 25) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_139 * 3) + pub_r001192_10 + 25) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_176 * 3) + pub_r001192_2 + 24) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_33 * 3) + pub_r001192_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001192_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001192_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001192_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_233 * 3) + pub_r001192_15 + 39) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001192_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((sec_r001192_11 * 3) + pub_r001192_17 + 41) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329 * 2) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001192_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((sec_r001192_11 * 3) + pub_r001192_7 + 38) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001192_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001192_23 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001192_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((sec_r001192_3 * 3) + pub_r001192_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335 * 2) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001192_23 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001192_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001192_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001192_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001192_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001192_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((helper_flow_2 * 3) + pub_r001192_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_230 * 3) + pub_r001192_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001192_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001192_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001192_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_129 * 3) + pub_r001192_20 + 19) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_313 * 3) + pub_r001192_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001192_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_31 * 3) + pub_r001192_2 + 22) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001192_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_70 * 3) + pub_r001192_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001192_21 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001192_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_180 * 3) + pub_r001192_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001192_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001192_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_264 * 3) + pub_r001192_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001192_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001192_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_12 * 3) + pub_r001192_15 + 24) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361 * 2) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001192_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_23 * 3) + pub_r001192_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363 * 2) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001192_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001192_23 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_258 * 3) + pub_r001192_7 + 40) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((sec_r001192_0 * 3) + pub_r001192_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001192_23 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001192_20 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001192_23 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001192_23 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001192_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_51 * 3) + pub_r001192_17 + 32) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((sec_r001192_8 * 3) + pub_r001192_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001192_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((helper_flow_5 * 3) + pub_r001192_5 + 13) & 127;
    sec_accum = (sec_accum + stage_v_376) & 255;
    out_sink = (out_sink + stage_v_376 * 2) & 255;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001192_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001192_22 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_220 * 3) + pub_r001192_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001192_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_96 * 3) + pub_r001192_23 + 13) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001192_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_226 * 3) + pub_r001192_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_77 * 3) + pub_r001192_2 + 38) & 127;
    sec_accum = (sec_accum + stage_v_384) & 255;
    out_sink = (out_sink + stage_v_384 * 2) & 255;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001192_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_123 * 3) + pub_r001192_23 + 27) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001192_20 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001192_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001192_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001192_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_129 * 3) + pub_r001192_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_391) & 255;
    out_sink = (out_sink + stage_v_391 * 2) & 255;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001192_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001192_22 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001192_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001192_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_103 * 3) + pub_r001192_21 + 43) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001192_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_90 * 3) + pub_r001192_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_398) & 255;
    out_sink = (out_sink + stage_v_398 * 2) & 255;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001192_23 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001192_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_287 * 3) + pub_r001192_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_268 * 3) + pub_r001192_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_222 * 3) + pub_r001192_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001192_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001192_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((sec_r001192_9 * 3) + pub_r001192_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_406) & 255;
    out_sink = (out_sink + stage_v_406 * 2) & 255;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001192_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001192_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001192_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001192_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001192_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001192_20 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001192_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001192_22 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001192_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001192_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001192_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001192_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001192_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001192_20 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_264 * 3) + pub_r001192_12 + 41) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((sec_r001192_16 * 3) + pub_r001192_18 + 16) & 127;
    sec_accum = (sec_accum + stage_v_422) & 255;
    out_sink = (out_sink + stage_v_422 * 2) & 255;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_206 * 3) + pub_r001192_4 + 16) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_230 * 3) + pub_r001192_23 + 34) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001192_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001192_23 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001192_22 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_148 * 3) + pub_r001192_14 + 39) & 127;
    sec_accum = (sec_accum + stage_v_428) & 255;
    out_sink = (out_sink + stage_v_428 * 2) & 255;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001192_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_149 * 3) + pub_r001192_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001192_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001192_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001192_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_123 * 3) + pub_r001192_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001192_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001192_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001192_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001192_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001192_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001192_21 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001192_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001192_21 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001192_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001192_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001192_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_367 * 3) + pub_r001192_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001192_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001192_21 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((sec_r001192_3 * 3) + pub_r001192_6 + 25) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001192_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001192_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_117 * 3) + pub_r001192_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_452) & 255;
    out_sink = (out_sink + stage_v_452 * 2) & 255;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_329 * 3) + pub_r001192_14 + 28) & 127;
    sec_accum = (sec_accum + stage_v_453) & 255;
    out_sink = (out_sink + stage_v_453 * 2) & 255;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001192_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_29 * 3) + pub_r001192_2 + 31) & 127;
    sec_accum = (sec_accum + stage_v_455) & 255;
    out_sink = (out_sink + stage_v_455 * 2) & 255;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_292 * 3) + pub_r001192_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_267 * 3) + pub_r001192_10 + 25) & 127;
    sec_accum = (sec_accum + stage_v_457) & 255;
    out_sink = (out_sink + stage_v_457 * 2) & 255;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001192_20 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001192_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001192_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_99 * 3) + pub_r001192_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001192_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001192_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001192_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001192_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001192_22 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001192_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001192_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001192_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001192_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001192_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001192_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001192_23 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001192_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001192_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001192_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001192_20 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001192_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001192_20 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_366 * 3) + pub_r001192_7 + 20) & 127;
    sec_accum = (sec_accum + stage_v_480) & 255;
    out_sink = (out_sink + stage_v_480 * 2) & 255;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001192_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001192_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = ((stage_v_453 * 3) + pub_r001192_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_483) & 255;
    out_sink = (out_sink + stage_v_483 * 2) & 255;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = ((stage_v_10 * 3) + pub_r001192_19 + 24) & 127;
    sec_accum = (sec_accum + stage_v_484) & 255;
    out_sink = (out_sink + stage_v_484 * 2) & 255;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001192_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001192_12 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_423 * 3) + pub_r001192_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_487) & 255;
    out_sink = (out_sink + stage_v_487 * 2) & 255;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001192_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = ((stage_v_455 * 3) + pub_r001192_22 + 39) & 127;
    sec_accum = (sec_accum + stage_v_489) & 255;
    out_sink = (out_sink + stage_v_489 * 2) & 255;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001192_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001192_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001192_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = (pub_r001192_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_493) & 127;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001192_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = ((stage_v_184 * 3) + pub_r001192_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_495) & 255;
    out_sink = (out_sink + stage_v_495 * 2) & 255;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001192_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001192_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001192_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001192_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001192_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001192_23 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = ((stage_v_386 * 3) + pub_r001192_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_502) & 255;
    out_sink = (out_sink + stage_v_502 * 2) & 255;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = ((stage_v_118 * 3) + pub_r001192_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_503) & 255;
    out_sink = (out_sink + stage_v_503 * 2) & 255;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = ((stage_v_118 * 3) + pub_r001192_17 + 43) & 127;
    sec_accum = (sec_accum + stage_v_504) & 255;
    out_sink = (out_sink + stage_v_504 * 2) & 255;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = ((stage_v_2 * 3) + pub_r001192_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_505) & 255;
    out_sink = (out_sink + stage_v_505 * 2) & 255;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001192_19 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = (pub_r001192_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_507) & 127;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = (pub_r001192_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_508) & 127;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001192_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = (pub_r001192_23 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_510) & 127;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001192_23 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = ((sec_r001192_0 * 3) + pub_r001192_22 + 41) & 127;
    sec_accum = (sec_accum + stage_v_512) & 255;
    out_sink = (out_sink + stage_v_512 * 2) & 255;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = (pub_r001192_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_513) & 127;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = (pub_r001192_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_514) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
