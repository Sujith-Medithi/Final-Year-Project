/*
 * Benchmark Program: R001303
 * Security Family: multi_step_explicit
 * Generator Seed: 630313
 * High Inputs: 21 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001303_313_0 {
    unsigned char prev_out;
    unsigned char damping;
    int prev_in;
    int mode;
    int buffer[3];
};

struct SensorNode_R001303_313_1 {
    unsigned char reading;
    unsigned char calib;
    int status;
    unsigned char offset;
    short gain;
    int buffer[3];
};

struct EventLog_R001303_313_2 {
    unsigned char facility;
    unsigned char signature;
    short code;
    int timestamp;
    int buffer[3];
};

union RegisterBank_R001303_313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001303_313_0(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001303_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int anchor_15 = local_arr[aux % 3];
    acc = (acc + anchor_15 * 2) & 127;
    int phase_30 = 0;
    for (int k = 0; k < 3; k++) {
        phase_30 = (phase_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_30) & 127;
    }
    int quantum_53 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_53 > 31) {
        acc = (acc + quantum_53 * 2 + 5) & 127;
        aux ^= (quantum_53 & 15);
    } else {
        acc = (acc - quantum_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001303_313_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001303_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int anchor_95 = local_arr[aux % 3];
    acc = (acc + anchor_95 * 2) & 127;
    int window_59 = (aux + st.buffer[1]) & 3;
    switch (window_59) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_25 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_25 = (threshold_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_25) & 127;
    }
    int scale_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001303_313_2(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001303_313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_84) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_80 = local_arr[aux % 3];
    acc = (acc + offset_80 * 2) & 127;
    int damping_74 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_74 > 39) {
        acc = (acc + damping_74 * 2 + 5) & 127;
        aux ^= (damping_74 & 15);
    } else {
        acc = (acc - damping_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001303_313_3(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001303_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_83 = local_arr[aux % 3];
    acc = (acc + factor_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001303_313_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001303_313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_21 = local_arr[aux % 3];
    acc = (acc + quantum_21 * 2) & 127;
    int segment_20 = (aux + st.buffer[1]) & 3;
    switch (segment_20) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001303_313_5(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001303_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int metric_20 = 0;
    for (int k = 0; k < 3; k++) {
        metric_20 = (metric_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_20) & 127;
    }
    int cursor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_99 > 12) {
        acc = (acc + cursor_99 * 2 + 5) & 127;
        aux ^= (cursor_99 & 15);
    } else {
        acc = (acc - cursor_99 + 11) & 127;
        aux += 3;
    }
    int phase_48 = (aux + st.buffer[1]) & 3;
    switch (phase_48) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001303_313_6(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001303_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int cursor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_79 > 48) {
        acc = (acc + cursor_79 * 2 + 5) & 127;
        aux ^= (cursor_79 & 15);
    } else {
        acc = (acc - cursor_79 + 11) & 127;
        aux += 3;
    }
    int index_reg_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001303_313_7(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001303_313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int parity_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_47) & 63;
    acc ^= aux;
    int factor_33 = 0;
    for (int k = 0; k < 2; k++) {
        factor_33 = (factor_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_33) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001303_313_8(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001303_313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int checksum_19 = (aux + st.buffer[1]) & 3;
    switch (checksum_19) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001303_313_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001303_313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_22 = (aux + st.buffer[1]) & 3;
    switch (cursor_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001303_313_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001303_313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_22 = (aux + st.buffer[1]) & 3;
    switch (checksum_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_99 = local_arr[aux % 3];
    acc = (acc + weight_99 * 2) & 127;
    int window_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001303_313_11(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001303_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int phase_44 = 0;
    for (int k = 0; k < 2; k++) {
        phase_44 = (phase_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_44) & 127;
    }
    int checksum_62 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_62 > 20) {
        acc = (acc + checksum_62 * 2 + 5) & 127;
        aux ^= (checksum_62 & 15);
    } else {
        acc = (acc - checksum_62 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_86 = local_arr[aux % 3];
    acc = (acc + quantum_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001303_313_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001303_313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_44) & 63;
    acc ^= aux;
    int margin_80 = 0;
    for (int k = 0; k < 3; k++) {
        margin_80 = (margin_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_80) & 127;
    }
    int index_reg_48 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_48 > 11) {
        acc = (acc + index_reg_48 * 2 + 5) & 127;
        aux ^= (index_reg_48 & 15);
    } else {
        acc = (acc - index_reg_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001303_313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001303_313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int phase_81 = local_arr[aux % 3];
    acc = (acc + phase_81 * 2) & 127;
    int residue_91 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_91 > 17) {
        acc = (acc + residue_91 * 2 + 5) & 127;
        aux ^= (residue_91 & 15);
    } else {
        acc = (acc - residue_91 + 11) & 127;
        aux += 3;
    }
    int delta_47 = (aux + st.buffer[1]) & 3;
    switch (delta_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001303_313_14(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001303_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int pivot_72 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_72 = (pivot_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_72) & 127;
    }
    int anchor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_12) & 63;
    acc ^= aux;
    int window_43 = (aux + st.buffer[1]) & 3;
    switch (window_43) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_55 = local_arr[aux % 3];
    acc = (acc + bound_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001303_313_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001303_313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int threshold_19 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_19 > 17) {
        acc = (acc + threshold_19 * 2 + 5) & 127;
        aux ^= (threshold_19 & 15);
    } else {
        acc = (acc - threshold_19 + 11) & 127;
        aux += 3;
    }
    int checksum_76 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_76 = (checksum_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_76) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001303_0;
    int sec_r001303_1;
    int sec_r001303_2;
    int sec_r001303_3;
    int sec_r001303_4;
    int sec_r001303_5;
    int sec_r001303_6;
    int sec_r001303_7;
    int sec_r001303_8;
    int sec_r001303_9;
    int sec_r001303_10;
    int sec_r001303_11;
    int sec_r001303_12;
    int sec_r001303_13;
    int sec_r001303_14;
    int sec_r001303_15;
    int sec_r001303_16;
    int sec_r001303_17;
    int sec_r001303_18;
    int sec_r001303_19;
    int sec_r001303_20;
    int pub_r001303_0;
    int pub_r001303_1;
    int pub_r001303_2;
    int pub_r001303_3;
    int pub_r001303_4;
    int pub_r001303_5;
    int pub_r001303_6;
    int pub_r001303_7;
    int pub_r001303_8;
    int pub_r001303_9;
    int pub_r001303_10;
    int pub_r001303_11;
    int pub_r001303_12;
    int pub_r001303_13;
    int pub_r001303_14;
    int pub_r001303_15;
    int pub_r001303_16;
    int pub_r001303_17;
    int pub_r001303_18;
    int pub_r001303_19;
    int pub_r001303_20;
    int pub_r001303_21;
    int pub_r001303_22;
    int pub_r001303_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001303_0 >= -100 && pub_r001303_0 <= 100);
    __CPROVER_assume(pub_r001303_1 >= -100 && pub_r001303_1 <= 100);
    __CPROVER_assume(pub_r001303_2 >= -100 && pub_r001303_2 <= 100);
    __CPROVER_assume(pub_r001303_3 >= -100 && pub_r001303_3 <= 100);
    __CPROVER_assume(pub_r001303_4 >= -100 && pub_r001303_4 <= 100);
    __CPROVER_assume(pub_r001303_5 >= -100 && pub_r001303_5 <= 100);
    __CPROVER_assume(pub_r001303_6 >= -100 && pub_r001303_6 <= 100);
    __CPROVER_assume(pub_r001303_7 >= -100 && pub_r001303_7 <= 100);
    __CPROVER_assume(pub_r001303_8 >= -100 && pub_r001303_8 <= 100);
    __CPROVER_assume(pub_r001303_9 >= -100 && pub_r001303_9 <= 100);
    __CPROVER_assume(pub_r001303_10 >= -100 && pub_r001303_10 <= 100);
    __CPROVER_assume(pub_r001303_11 >= -100 && pub_r001303_11 <= 100);
    __CPROVER_assume(pub_r001303_12 >= -100 && pub_r001303_12 <= 100);
    __CPROVER_assume(pub_r001303_13 >= -100 && pub_r001303_13 <= 100);
    __CPROVER_assume(pub_r001303_14 >= -100 && pub_r001303_14 <= 100);
    __CPROVER_assume(pub_r001303_15 >= -100 && pub_r001303_15 <= 100);
    __CPROVER_assume(pub_r001303_16 >= -100 && pub_r001303_16 <= 100);
    __CPROVER_assume(pub_r001303_17 >= -100 && pub_r001303_17 <= 100);
    __CPROVER_assume(pub_r001303_18 >= -100 && pub_r001303_18 <= 100);
    __CPROVER_assume(pub_r001303_19 >= -100 && pub_r001303_19 <= 100);
    __CPROVER_assume(pub_r001303_20 >= -100 && pub_r001303_20 <= 100);
    __CPROVER_assume(pub_r001303_21 >= -100 && pub_r001303_21 <= 100);
    __CPROVER_assume(pub_r001303_22 >= -100 && pub_r001303_22 <= 100);
    __CPROVER_assume(pub_r001303_23 >= -100 && pub_r001303_23 <= 100);
    __CPROVER_assume(sec_r001303_0 >= 0 && sec_r001303_0 <= 255);
    __CPROVER_assume(sec_r001303_1 >= 0 && sec_r001303_1 <= 255);
    __CPROVER_assume(sec_r001303_2 >= 0 && sec_r001303_2 <= 255);
    __CPROVER_assume(sec_r001303_3 >= 0 && sec_r001303_3 <= 255);
    __CPROVER_assume(sec_r001303_4 >= 0 && sec_r001303_4 <= 255);
    __CPROVER_assume(sec_r001303_5 >= 0 && sec_r001303_5 <= 255);
    __CPROVER_assume(sec_r001303_6 >= 0 && sec_r001303_6 <= 255);
    __CPROVER_assume(sec_r001303_7 >= 0 && sec_r001303_7 <= 255);
    __CPROVER_assume(sec_r001303_8 >= 0 && sec_r001303_8 <= 255);
    __CPROVER_assume(sec_r001303_9 >= 0 && sec_r001303_9 <= 255);
    __CPROVER_assume(sec_r001303_10 >= 0 && sec_r001303_10 <= 255);
    __CPROVER_assume(sec_r001303_11 >= 0 && sec_r001303_11 <= 255);
    __CPROVER_assume(sec_r001303_12 >= 0 && sec_r001303_12 <= 255);
    __CPROVER_assume(sec_r001303_13 >= 0 && sec_r001303_13 <= 255);
    __CPROVER_assume(sec_r001303_14 >= 0 && sec_r001303_14 <= 255);
    __CPROVER_assume(sec_r001303_15 >= 0 && sec_r001303_15 <= 255);
    __CPROVER_assume(sec_r001303_16 >= 0 && sec_r001303_16 <= 255);
    __CPROVER_assume(sec_r001303_17 >= 0 && sec_r001303_17 <= 255);
    __CPROVER_assume(sec_r001303_18 >= 0 && sec_r001303_18 <= 255);
    __CPROVER_assume(sec_r001303_19 >= 0 && sec_r001303_19 <= 255);
    __CPROVER_assume(sec_r001303_20 >= 0 && sec_r001303_20 <= 255);

    struct FilterState_R001303_313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001303_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001303_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001303_0 + 7) & 15;
    struct SensorNode_R001303_313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001303_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001303_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001303_0 + 9) & 15;
    struct EventLog_R001303_313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001303_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001303_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001303_0 + 11) & 15;

    union RegisterBank_R001303_313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001303_313_0(sec_r001303_0, pub_r001303_1);
    int helper_flow_1 = fn_R001303_313_1(sec_r001303_1, pub_r001303_2, pub_r001303_3, pub_r001303_4);
    int helper_flow_2 = fn_R001303_313_2(sec_r001303_2, pub_r001303_3);
    int helper_flow_3 = fn_R001303_313_3(sec_r001303_3, sec_r001303_4, pub_r001303_5);
    int helper_flow_4 = fn_R001303_313_4(sec_r001303_4, pub_r001303_5, pub_r001303_6, pub_r001303_7);
    int helper_flow_5 = fn_R001303_313_5(sec_r001303_5, pub_r001303_6);
    int helper_flow_6 = fn_R001303_313_6(sec_r001303_6, pub_r001303_7, pub_r001303_8);
    int helper_flow_7 = fn_R001303_313_7(sec_r001303_7, pub_r001303_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001303_13 * 3) + pub_r001303_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001303_7 * 3) + pub_r001303_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_1) & 255;
    out_sink = (out_sink + stage_v_1 * 2) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001303_8 * 3) + pub_r001303_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001303_22 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001303_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001303_15 * 3) + pub_r001303_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001303_8 * 3) + pub_r001303_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001303_10 * 3) + pub_r001303_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001303_23 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001303_17 * 3) + pub_r001303_22 + 20) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001303_14 * 3) + pub_r001303_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_3 * 3) + pub_r001303_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_11) & 255;
    out_sink = (out_sink + stage_v_11 * 2) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001303_12 * 3) + pub_r001303_22 + 45) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001303_0 * 3) + pub_r001303_4 + 21) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001303_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001303_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001303_5 * 3) + pub_r001303_19 + 42) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001303_19 * 3) + pub_r001303_7 + 40) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001303_1 * 3) + pub_r001303_12 + 6) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001303_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001303_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001303_17 * 3) + pub_r001303_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21 * 2) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_11 * 3) + pub_r001303_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001303_19 * 3) + pub_r001303_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001303_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001303_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001303_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001303_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_0 * 3) + pub_r001303_20 + 42) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001303_15 * 3) + pub_r001303_21 + 26) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29 * 2) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_0 * 3) + pub_r001303_9 + 29) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30 * 2) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001303_16 * 3) + pub_r001303_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31 * 2) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_6 * 3) + pub_r001303_11 + 25) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001303_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001303_20 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_11 * 3) + pub_r001303_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001303_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_6 * 3) + pub_r001303_3 + 4) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37 * 2) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001303_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001303_8 * 3) + pub_r001303_14 + 30) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39 * 2) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_32 * 3) + pub_r001303_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((helper_flow_1 * 3) + pub_r001303_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001303_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_1 * 3) + pub_r001303_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001303_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001303_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001303_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001303_15 * 3) + pub_r001303_20 + 43) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001303_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001303_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001303_21 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_5 * 3) + pub_r001303_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_37 * 3) + pub_r001303_20 + 17) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_6 * 3) + pub_r001303_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53 * 2) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_47 * 3) + pub_r001303_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001303_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001303_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001303_13 * 3) + pub_r001303_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_53 * 3) + pub_r001303_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001303_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001303_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001303_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_54 * 3) + pub_r001303_23 + 36) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62 * 2) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((helper_flow_3 * 3) + pub_r001303_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63 * 2) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_23 * 3) + pub_r001303_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_5 * 3) + pub_r001303_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001303_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001303_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_43 * 3) + pub_r001303_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001303_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001303_15 * 3) + pub_r001303_9 + 38) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70 * 2) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001303_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_6 * 3) + pub_r001303_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_1 * 3) + pub_r001303_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73 * 2) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001303_3 * 3) + pub_r001303_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74 * 2) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001303_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_52 * 3) + pub_r001303_23 + 32) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76 * 2) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_58 * 3) + pub_r001303_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_31 * 3) + pub_r001303_0 + 39) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_68 * 3) + pub_r001303_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001303_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001303_22 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_9 * 3) + pub_r001303_9 + 45) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82 * 2) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001303_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_43 * 3) + pub_r001303_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84 * 2) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((helper_flow_1 * 3) + pub_r001303_20 + 18) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85 * 2) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001303_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_13 * 3) + pub_r001303_18 + 38) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_77 * 3) + pub_r001303_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_21 * 3) + pub_r001303_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_73 * 3) + pub_r001303_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001303_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001303_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001303_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_63 * 3) + pub_r001303_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94 * 2) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001303_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_72 * 3) + pub_r001303_22 + 11) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_21 * 3) + pub_r001303_13 + 20) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001303_0 * 3) + pub_r001303_13 + 44) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001303_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001303_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001303_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_21 * 3) + pub_r001303_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102 * 2) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001303_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_62 * 3) + pub_r001303_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001303_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001303_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_7 * 3) + pub_r001303_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107 * 2) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_29 * 3) + pub_r001303_8 + 35) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_47 * 3) + pub_r001303_19 + 6) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_30 * 3) + pub_r001303_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_16 * 3) + pub_r001303_21 + 29) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001303_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_11 * 3) + pub_r001303_19 + 9) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_43 * 3) + pub_r001303_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114 * 2) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001303_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_94 * 3) + pub_r001303_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_62 * 3) + pub_r001303_19 + 40) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117 * 2) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001303_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001303_10 * 3) + pub_r001303_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_90 * 3) + pub_r001303_20 + 39) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_120 * 3) + pub_r001303_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_94 * 3) + pub_r001303_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_11 * 3) + pub_r001303_23 + 28) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123 * 2) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_52 * 3) + pub_r001303_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001303_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001303_23 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001303_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_21 * 3) + pub_r001303_22 + 9) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_7 * 3) + pub_r001303_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_16 * 3) + pub_r001303_2 + 38) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_79 * 3) + pub_r001303_18 + 12) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001303_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_39 * 3) + pub_r001303_11 + 25) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001303_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((helper_flow_7 * 3) + pub_r001303_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001303_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r001303_17 * 3) + pub_r001303_22 + 35) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137 * 2) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001303_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_104 * 3) + pub_r001303_23 + 17) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001303_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_78 * 3) + pub_r001303_1 + 12) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_72 * 3) + pub_r001303_7 + 40) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_68 * 3) + pub_r001303_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001303_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001303_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_12 * 3) + pub_r001303_18 + 38) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_9 * 3) + pub_r001303_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147 * 2) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001303_20 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001303_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001303_1 * 3) + pub_r001303_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001303_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001303_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((helper_flow_1 * 3) + pub_r001303_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153 * 2) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_111 * 3) + pub_r001303_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001303_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001303_20 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001303_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001303_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001303_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_147 * 3) + pub_r001303_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_160 * 3) + pub_r001303_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r001303_1 * 3) + pub_r001303_19 + 5) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162 * 2) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001303_22 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_153 * 3) + pub_r001303_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001303_21 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001303_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_82 * 3) + pub_r001303_18 + 30) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167 * 2) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001303_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001303_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_124 * 3) + pub_r001303_20 + 17) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_32 * 3) + pub_r001303_22 + 34) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_129 * 3) + pub_r001303_21 + 36) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001303_23 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001303_22 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001303_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_54 * 3) + pub_r001303_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_110 * 3) + pub_r001303_21 + 11) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177 * 2) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((helper_flow_1 * 3) + pub_r001303_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((helper_flow_5 * 3) + pub_r001303_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r001303_1 * 3) + pub_r001303_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001303_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_39 * 3) + pub_r001303_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_177 * 3) + pub_r001303_10 + 40) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183 * 2) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_6 * 3) + pub_r001303_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_90 * 3) + pub_r001303_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_29 * 3) + pub_r001303_21 + 13) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_87 * 3) + pub_r001303_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187 * 2) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_176 * 3) + pub_r001303_12 + 5) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188 * 2) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001303_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_150 * 3) + pub_r001303_17 + 40) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((sec_r001303_6 * 3) + pub_r001303_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001303_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001303_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001303_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001303_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_70 * 3) + pub_r001303_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001303_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001303_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_17 * 3) + pub_r001303_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199 * 2) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_120 * 3) + pub_r001303_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200 * 2) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001303_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_31 * 3) + pub_r001303_21 + 45) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001303_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_131 * 3) + pub_r001303_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001303_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_129 * 3) + pub_r001303_19 + 27) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206 * 2) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001303_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001303_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((helper_flow_5 * 3) + pub_r001303_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209 * 2) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((helper_flow_4 * 3) + pub_r001303_11 + 30) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001303_19 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_133 * 3) + pub_r001303_15 + 34) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212 * 2) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001303_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001303_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_177 * 3) + pub_r001303_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((helper_flow_1 * 3) + pub_r001303_23 + 37) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_143 * 3) + pub_r001303_6 + 45) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_22 * 3) + pub_r001303_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001303_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_121 * 3) + pub_r001303_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220 * 2) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001303_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((helper_flow_7 * 3) + pub_r001303_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222 * 2) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001303_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001303_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001303_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_89 * 3) + pub_r001303_18 + 40) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001303_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001303_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_177 * 3) + pub_r001303_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_76 * 3) + pub_r001303_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_7 * 3) + pub_r001303_19 + 20) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231 * 2) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001303_23 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001303_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_196 * 3) + pub_r001303_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_220 * 3) + pub_r001303_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_111 * 3) + pub_r001303_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001303_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((sec_r001303_3 * 3) + pub_r001303_17 + 38) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238 * 2) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_142 * 3) + pub_r001303_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r001303_19 * 3) + pub_r001303_7 + 37) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240 * 2) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001303_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001303_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_82 * 3) + pub_r001303_17 + 41) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243 * 2) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_186 * 3) + pub_r001303_22 + 36) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((sec_r001303_5 * 3) + pub_r001303_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245 * 2) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_111 * 3) + pub_r001303_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246 * 2) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_32 * 3) + pub_r001303_13 + 41) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247 * 2) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001303_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001303_23 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001303_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r001303_20 * 3) + pub_r001303_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001303_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_21 * 3) + pub_r001303_0 + 40) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001303_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001303_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_150 * 3) + pub_r001303_20 + 24) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001303_21 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_54 * 3) + pub_r001303_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258 * 2) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001303_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001303_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_129 * 3) + pub_r001303_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001303_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001303_23 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001303_20 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001303_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_142 * 3) + pub_r001303_19 + 3) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_183 * 3) + pub_r001303_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_47 * 3) + pub_r001303_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001303_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((sec_r001303_12 * 3) + pub_r001303_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_172 * 3) + pub_r001303_17 + 5) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_96 * 3) + pub_r001303_7 + 37) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272 * 2) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001303_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r001303_20 * 3) + pub_r001303_3 + 39) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274 * 2) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_47 * 3) + pub_r001303_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001303_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_131 * 3) + pub_r001303_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_230 * 3) + pub_r001303_7 + 41) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_90 * 3) + pub_r001303_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001303_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001303_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001303_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r001303_2 * 3) + pub_r001303_17 + 33) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283 * 2) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001303_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_76 * 3) + pub_r001303_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001303_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_238 * 3) + pub_r001303_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287 * 2) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_40 * 3) + pub_r001303_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288 * 2) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001303_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((helper_flow_3 * 3) + pub_r001303_23 + 35) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_90 * 3) + pub_r001303_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001303_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001303_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001303_22 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001303_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_124 * 3) + pub_r001303_22 + 28) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001303_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001303_20 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001303_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_16 * 3) + pub_r001303_8 + 5) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_109 * 3) + pub_r001303_19 + 26) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_102 * 3) + pub_r001303_15 + 41) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302 * 2) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_120 * 3) + pub_r001303_14 + 39) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001303_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001303_20 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_287 * 3) + pub_r001303_19 + 32) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306 * 2) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((sec_r001303_9 * 3) + pub_r001303_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001303_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_176 * 3) + pub_r001303_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001303_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001303_19 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_164 * 3) + pub_r001303_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312 * 2) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001303_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_186 * 3) + pub_r001303_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314 * 2) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_97 * 3) + pub_r001303_19 + 12) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_53 * 3) + pub_r001303_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316 * 2) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_96 * 3) + pub_r001303_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317 * 2) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_199 * 3) + pub_r001303_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001303_22 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001303_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_290 * 3) + pub_r001303_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((helper_flow_0 * 3) + pub_r001303_1 + 15) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001303_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001303_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((sec_r001303_17 * 3) + pub_r001303_17 + 13) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325 * 2) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001303_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_139 * 3) + pub_r001303_17 + 41) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001303_22 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001303_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001303_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((sec_r001303_20 * 3) + pub_r001303_21 + 21) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_202 * 3) + pub_r001303_19 + 5) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332 * 2) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((helper_flow_6 * 3) + pub_r001303_19 + 30) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_141 * 3) + pub_r001303_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001303_23 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_218 * 3) + pub_r001303_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336 * 2) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_321 * 3) + pub_r001303_11 + 30) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337 * 2) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001303_20 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001303_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001303_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_288 * 3) + pub_r001303_21 + 39) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((helper_flow_1 * 3) + pub_r001303_17 + 8) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_7 * 3) + pub_r001303_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001303_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001303_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001303_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001303_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_74 * 3) + pub_r001303_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001303_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001303_21 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_230 * 3) + pub_r001303_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_188 * 3) + pub_r001303_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_62 * 3) + pub_r001303_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001303_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_314 * 3) + pub_r001303_8 + 13) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001303_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_73 * 3) + pub_r001303_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((sec_r001303_10 * 3) + pub_r001303_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001303_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_104 * 3) + pub_r001303_7 + 38) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_54 * 3) + pub_r001303_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361 * 2) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001303_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001303_22 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001303_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001303_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001303_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_204 * 3) + pub_r001303_22 + 10) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001303_23 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_274 * 3) + pub_r001303_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_369) & 255;
    out_sink = (out_sink + stage_v_369 * 2) & 255;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((sec_r001303_11 * 3) + pub_r001303_10 + 43) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_251 * 3) + pub_r001303_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001303_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_234 * 3) + pub_r001303_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001303_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001303_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001303_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001303_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_196 * 3) + pub_r001303_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378 * 2) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_0 * 3) + pub_r001303_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_133 * 3) + pub_r001303_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380 * 2) & 255;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_190 * 3) + pub_r001303_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001303_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_185 * 3) + pub_r001303_19 + 13) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_102 * 3) + pub_r001303_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_384) & 255;
    out_sink = (out_sink + stage_v_384 * 2) & 255;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_179 * 3) + pub_r001303_9 + 43) & 127;
    sec_accum = (sec_accum + stage_v_385) & 255;
    out_sink = (out_sink + stage_v_385 * 2) & 255;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_135 * 3) + pub_r001303_16 + 8) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001303_22 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_196 * 3) + pub_r001303_3 + 9) & 127;
    sec_accum = (sec_accum + stage_v_388) & 255;
    out_sink = (out_sink + stage_v_388 * 2) & 255;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001303_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((helper_flow_4 * 3) + pub_r001303_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_218 * 3) + pub_r001303_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_391) & 255;
    out_sink = (out_sink + stage_v_391 * 2) & 255;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_268 * 3) + pub_r001303_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_392) & 255;
    out_sink = (out_sink + stage_v_392 * 2) & 255;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_378 * 3) + pub_r001303_20 + 45) & 127;
    sec_accum = (sec_accum + stage_v_393) & 255;
    out_sink = (out_sink + stage_v_393 * 2) & 255;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_153 * 3) + pub_r001303_8 + 37) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001303_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_64 * 3) + pub_r001303_19 + 6) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_230 * 3) + pub_r001303_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001303_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_235 * 3) + pub_r001303_3 + 31) & 127;
    sec_accum = (sec_accum + stage_v_399) & 255;
    out_sink = (out_sink + stage_v_399 * 2) & 255;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_177 * 3) + pub_r001303_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_400) & 255;
    out_sink = (out_sink + stage_v_400 * 2) & 255;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_303 * 3) + pub_r001303_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_171 * 3) + pub_r001303_20 + 36) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_266 * 3) + pub_r001303_0 + 41) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((helper_flow_0 * 3) + pub_r001303_23 + 39) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001303_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001303_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_391 * 3) + pub_r001303_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_407) & 255;
    out_sink = (out_sink + stage_v_407 * 2) & 255;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001303_23 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_17 * 3) + pub_r001303_0 + 10) & 127;
    sec_accum = (sec_accum + stage_v_409) & 255;
    out_sink = (out_sink + stage_v_409 * 2) & 255;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_2 * 3) + pub_r001303_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_268 * 3) + pub_r001303_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_411) & 255;
    out_sink = (out_sink + stage_v_411 * 2) & 255;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_116 * 3) + pub_r001303_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_378 * 3) + pub_r001303_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001303_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_288 * 3) + pub_r001303_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001303_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_301 * 3) + pub_r001303_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001303_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
