/*
 * Benchmark Program: R000314
 * Family: arithmetic_flow
 * Generator Seed: 431413
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000314_1413_0 {
    short seq;
    unsigned char facility;
    int severity;
    int timestamp;
    int buffer[3];
};

struct StreamBuffer_R000314_1413_1 {
    int capacity;
    int state;
    int tail;
    int watermark;
    unsigned char checksum;
    int buffer[3];
};

union RegisterBank_R000314_1413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000314_1413_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000314_1413_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int sample_48 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_48 > 14) {
        acc = (acc + sample_48 * 2 + 5) & 127;
        aux ^= (sample_48 & 15);
    } else {
        acc = (acc - sample_48 + 11) & 127;
        aux += 3;
    }
    int damping_16 = 0;
    for (int k = 0; k < 2; k++) {
        damping_16 = (damping_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_16) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_15 = local_arr[aux % 3];
    acc = (acc + factor_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000314_1413_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int sample_79 = local_arr[aux % 3];
    acc = (acc + sample_79 * 2) & 127;
    int metric_52 = (aux + st.buffer[1]) & 3;
    switch (metric_52) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_51 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_51 = (checksum_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_2(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int vector_92 = (aux + st.buffer[1]) & 3;
    switch (vector_92) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_14 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_14 > 10) {
        acc = (acc + tracker_14 * 2 + 5) & 127;
        aux ^= (tracker_14 & 15);
    } else {
        acc = (acc - tracker_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_40 = local_arr[aux % 3];
    acc = (acc + phase_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000314_1413_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int stride_80 = (aux + st.buffer[1]) & 3;
    switch (stride_80) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_76 = 0;
    for (int k = 0; k < 3; k++) {
        offset_76 = (offset_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_44 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_44 > 38) {
        acc = (acc + checksum_44 * 2 + 5) & 127;
        aux ^= (checksum_44 & 15);
    } else {
        acc = (acc - checksum_44 + 11) & 127;
        aux += 3;
    }
    int delta_33 = (aux + st.buffer[1]) & 3;
    switch (delta_33) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_48 = 0;
    for (int k = 0; k < 3; k++) {
        weight_48 = (weight_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_48) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int accumulator_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_80) & 63;
    acc ^= aux;
    int phase_48 = 0;
    for (int k = 0; k < 2; k++) {
        phase_48 = (phase_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_48) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_29 = local_arr[aux % 3];
    acc = (acc + factor_29 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000314_1413_6(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_50 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_50 > 35) {
        acc = (acc + threshold_50 * 2 + 5) & 127;
        aux ^= (threshold_50 & 15);
    } else {
        acc = (acc - threshold_50 + 11) & 127;
        aux += 3;
    }
    int stride_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_63) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_68 = local_arr[aux % 3];
    acc = (acc + delta_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000314_1413_7(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int tracker_44 = local_arr[aux % 3];
    acc = (acc + tracker_44 * 2) & 127;
    int cursor_83 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_83 > 44) {
        acc = (acc + cursor_83 * 2 + 5) & 127;
        aux ^= (cursor_83 & 15);
    } else {
        acc = (acc - cursor_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_8(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int coefficient_54 = local_arr[aux % 3];
    acc = (acc + coefficient_54 * 2) & 127;
    int phase_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_14) & 63;
    acc ^= aux;
    int accumulator_68 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_68 > 42) {
        acc = (acc + accumulator_68 * 2 + 5) & 127;
        aux ^= (accumulator_68 & 15);
    } else {
        acc = (acc - accumulator_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_9(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_44 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_44 > 18) {
        acc = (acc + phase_44 * 2 + 5) & 127;
        aux ^= (phase_44 & 15);
    } else {
        acc = (acc - phase_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int scale_17 = 0;
    for (int k = 0; k < 3; k++) {
        scale_17 = (scale_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_17) & 127;
    }
    int quantum_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_87) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_16 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_16 > 36) {
        acc = (acc + delta_16 * 2 + 5) & 127;
        aux ^= (delta_16 & 15);
    } else {
        acc = (acc - delta_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_11(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_20 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_20 = (pivot_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_20) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_10 = local_arr[aux % 3];
    acc = (acc + delta_10 * 2) & 127;
    int segment_69 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_69 > 28) {
        acc = (acc + segment_69 * 2 + 5) & 127;
        aux ^= (segment_69 & 15);
    } else {
        acc = (acc - segment_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000314_1413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int stride_69 = local_arr[aux % 3];
    acc = (acc + stride_69 * 2) & 127;
    int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_31 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_31 = (accumulator_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_16 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_16 > 30) {
        acc = (acc + stride_16 * 2 + 5) & 127;
        aux ^= (stride_16 & 15);
    } else {
        acc = (acc - stride_16 + 11) & 127;
        aux += 3;
    }
    int phase_73 = 0;
    for (int k = 0; k < 3; k++) {
        phase_73 = (phase_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_14(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int bound_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_23) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_82 = local_arr[aux % 3];
    acc = (acc + vector_82 * 2) & 127;
    int pivot_80 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_80 = (pivot_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000314_1413_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000314_1413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int parity_43 = 0;
    for (int k = 0; k < 3; k++) {
        parity_43 = (parity_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_43) & 127;
    }
    int threshold_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000314_0;
    int sec_r000314_1;
    int sec_r000314_2;
    int sec_r000314_3;
    int sec_r000314_4;
    int sec_r000314_5;
    int sec_r000314_6;
    int sec_r000314_7;
    int sec_r000314_8;
    int sec_r000314_9;
    int sec_r000314_10;
    int sec_r000314_11;
    int sec_r000314_12;
    int sec_r000314_13;
    int sec_r000314_14;
    int sec_r000314_15;
    int sec_r000314_16;
    int sec_r000314_17;
    int sec_r000314_18;
    int sec_r000314_19;
    int sec_r000314_20;
    int sec_r000314_21;
    int pub_r000314_0;
    int pub_r000314_1;
    int pub_r000314_2;
    int pub_r000314_3;
    int pub_r000314_4;
    int pub_r000314_5;
    int pub_r000314_6;
    int pub_r000314_7;
    int pub_r000314_8;
    int pub_r000314_9;
    int pub_r000314_10;
    int pub_r000314_11;
    int pub_r000314_12;
    int pub_r000314_13;
    int pub_r000314_14;
    int pub_r000314_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000314_0 >= -100 && pub_r000314_0 <= 100);
    __CPROVER_assume(pub_r000314_1 >= -100 && pub_r000314_1 <= 100);
    __CPROVER_assume(pub_r000314_2 >= -100 && pub_r000314_2 <= 100);
    __CPROVER_assume(pub_r000314_3 >= -100 && pub_r000314_3 <= 100);
    __CPROVER_assume(pub_r000314_4 >= -100 && pub_r000314_4 <= 100);
    __CPROVER_assume(pub_r000314_5 >= -100 && pub_r000314_5 <= 100);
    __CPROVER_assume(pub_r000314_6 >= -100 && pub_r000314_6 <= 100);
    __CPROVER_assume(pub_r000314_7 >= -100 && pub_r000314_7 <= 100);
    __CPROVER_assume(pub_r000314_8 >= -100 && pub_r000314_8 <= 100);
    __CPROVER_assume(pub_r000314_9 >= -100 && pub_r000314_9 <= 100);
    __CPROVER_assume(pub_r000314_10 >= -100 && pub_r000314_10 <= 100);
    __CPROVER_assume(pub_r000314_11 >= -100 && pub_r000314_11 <= 100);
    __CPROVER_assume(pub_r000314_12 >= -100 && pub_r000314_12 <= 100);
    __CPROVER_assume(pub_r000314_13 >= -100 && pub_r000314_13 <= 100);
    __CPROVER_assume(pub_r000314_14 >= -100 && pub_r000314_14 <= 100);
    __CPROVER_assume(pub_r000314_15 >= -100 && pub_r000314_15 <= 100);
    __CPROVER_assume(sec_r000314_0 >= 0 && sec_r000314_0 <= 255);
    __CPROVER_assume(sec_r000314_1 >= 0 && sec_r000314_1 <= 255);
    __CPROVER_assume(sec_r000314_2 >= 0 && sec_r000314_2 <= 255);
    __CPROVER_assume(sec_r000314_3 >= 0 && sec_r000314_3 <= 255);
    __CPROVER_assume(sec_r000314_4 >= 0 && sec_r000314_4 <= 255);
    __CPROVER_assume(sec_r000314_5 >= 0 && sec_r000314_5 <= 255);
    __CPROVER_assume(sec_r000314_6 >= 0 && sec_r000314_6 <= 255);
    __CPROVER_assume(sec_r000314_7 >= 0 && sec_r000314_7 <= 255);
    __CPROVER_assume(sec_r000314_8 >= 0 && sec_r000314_8 <= 255);
    __CPROVER_assume(sec_r000314_9 >= 0 && sec_r000314_9 <= 255);
    __CPROVER_assume(sec_r000314_10 >= 0 && sec_r000314_10 <= 255);
    __CPROVER_assume(sec_r000314_11 >= 0 && sec_r000314_11 <= 255);
    __CPROVER_assume(sec_r000314_12 >= 0 && sec_r000314_12 <= 255);
    __CPROVER_assume(sec_r000314_13 >= 0 && sec_r000314_13 <= 255);
    __CPROVER_assume(sec_r000314_14 >= 0 && sec_r000314_14 <= 255);
    __CPROVER_assume(sec_r000314_15 >= 0 && sec_r000314_15 <= 255);
    __CPROVER_assume(sec_r000314_16 >= 0 && sec_r000314_16 <= 255);
    __CPROVER_assume(sec_r000314_17 >= 0 && sec_r000314_17 <= 255);
    __CPROVER_assume(sec_r000314_18 >= 0 && sec_r000314_18 <= 255);
    __CPROVER_assume(sec_r000314_19 >= 0 && sec_r000314_19 <= 255);
    __CPROVER_assume(sec_r000314_20 >= 0 && sec_r000314_20 <= 255);
    __CPROVER_assume(sec_r000314_21 >= 0 && sec_r000314_21 <= 255);

    struct EventLog_R000314_1413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000314_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000314_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000314_0 + 7) & 15;
    struct StreamBuffer_R000314_1413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000314_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000314_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000314_0 + 9) & 15;

    union RegisterBank_R000314_1413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 27) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 42) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 33) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 48) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 10) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 25) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 27) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 42) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 20) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 35) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 21) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 36) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 19) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 34) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 34) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 49) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 28) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 43) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 10) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 25) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 39) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 54) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_1.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 11) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 26) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 35) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 50) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = table[2];
    table[2] = (table[3] + 157) & 63;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 18) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 33) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 89) & 15;
    int stage_v_88 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= stage_v_88;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_92 = (stage_v_92 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[0] ^ 97) & 3;
    switch (stage_v_94) {
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

    /* Execution Pipeline Stage 95 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 96) & 15;
    int stage_v_95 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= stage_v_95;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = table[1];
    table[1] = (table[2] + 195) & 63;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (out_sink > 100) ? (chk_sum & 31) : (103 & 31);
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= (stage_v_98 << 1) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_104 = (stage_v_104 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_108 = (stage_v_108 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_1.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 21) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 36) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_0.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 13) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 28) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (out_sink > 100) ? (chk_sum & 31) : (118 & 31);
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= (stage_v_113 << 1) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_0.buffer[0] ^ 119) & 3;
    switch (stage_v_116) {
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

    /* Execution Pipeline Stage 117 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 118) & 15;
    int stage_v_117 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= stage_v_117;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_0.buffer[0] ^ 121) & 3;
    switch (stage_v_118) {
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

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] * 2 + 367) & 63;
    if (stage_v_120 > 24) {
        out_sink = (out_sink + stage_v_120 - 5) & 255;
        if (stage_v_120 > 39) {
            chk_sum ^= (stage_v_120 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_120 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 121 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 122) & 15;
    int stage_v_121 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= stage_v_121;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = table[0];
    table[0] = (table[1] + 249) & 63;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[2] * 2 + 382) & 63;
    if (stage_v_125 > 13) {
        out_sink = (out_sink + stage_v_125 - 5) & 255;
        if (stage_v_125 > 28) {
            chk_sum ^= (stage_v_125 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_125 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 31) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 46) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 130) & 15;
    int stage_v_129 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= stage_v_129;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_1.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 22) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 37) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_1.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 32) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 47) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] ^ 147) & 3;
    switch (stage_v_144) {
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

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (out_sink > 100) ? (chk_sum & 31) : (152 & 31);
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= (stage_v_147 << 1) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_0.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 29) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 44) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_153 = (stage_v_153 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 159) & 15;
    int stage_v_158 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= stage_v_158;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (out_sink > 100) ? (chk_sum & 31) : (164 & 31);
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= (stage_v_159 << 1) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] * 2 + 493) & 63;
    if (stage_v_162 > 23) {
        out_sink = (out_sink + stage_v_162 - 5) & 255;
        if (stage_v_162 > 38) {
            chk_sum ^= (stage_v_162 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_162 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = table[3];
    table[3] = (table[0] + 327) & 63;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 16) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 31) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 166) & 15;
    int stage_v_165 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= stage_v_165;

    /* Execution Pipeline Stage 166 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 167) & 15;
    int stage_v_166 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= stage_v_166;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = table[0];
    table[0] = (table[1] + 337) & 63;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (out_sink > 100) ? (chk_sum & 31) : (174 & 31);
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= (stage_v_169 << 1) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 172) & 15;
    int stage_v_171 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= stage_v_171;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_0.buffer[0] ^ 175) & 3;
    switch (stage_v_172) {
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

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_1.buffer[2] * 2 + 526) & 63;
    if (stage_v_173 > 38) {
        out_sink = (out_sink + stage_v_173 - 5) & 255;
        if (stage_v_173 > 53) {
            chk_sum ^= (stage_v_173 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_173 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = table[3];
    table[3] = (table[0] + 351) & 63;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 177) & 15;
    int stage_v_176 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= stage_v_176;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (out_sink > 100) ? (chk_sum & 31) : (182 & 31);
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= (stage_v_177 << 1) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_1.buffer[0] ^ 182) & 3;
    switch (stage_v_179) {
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

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] * 2 + 547) & 63;
    if (stage_v_180 > 18) {
        out_sink = (out_sink + stage_v_180 - 5) & 255;
        if (stage_v_180 > 33) {
            chk_sum ^= (stage_v_180 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_180 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (out_sink > 100) ? (chk_sum & 31) : (186 & 31);
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= (stage_v_181 << 1) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_182 = (stage_v_182 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_182) & 127;
    }
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (out_sink > 100) ? (chk_sum & 31) : (188 & 31);
    out_sink = (out_sink + stage_v_183) & 255;
    chk_sum ^= (stage_v_183 << 1) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (out_sink > 100) ? (chk_sum & 31) : (189 & 31);
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= (stage_v_184 << 1) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = table[2];
    table[2] = (table[3] + 373) & 63;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (out_sink > 100) ? (chk_sum & 31) : (192 & 31);
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= (stage_v_187 << 1) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (out_sink > 100) ? (chk_sum & 31) : (193 & 31);
    out_sink = (out_sink + stage_v_188) & 255;
    chk_sum ^= (stage_v_188 << 1) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = table[1];
    table[1] = (table[2] + 379) & 63;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_0.buffer[1] * 2 + 577) & 63;
    if (stage_v_190 > 18) {
        out_sink = (out_sink + stage_v_190 - 5) & 255;
        if (stage_v_190 > 33) {
            chk_sum ^= (stage_v_190 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_190 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (out_sink > 100) ? (chk_sum & 31) : (197 & 31);
    out_sink = (out_sink + stage_v_192) & 255;
    chk_sum ^= (stage_v_192 << 1) & 127;

    /* Execution Pipeline Stage 193 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 194) & 15;
    int stage_v_193 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    chk_sum ^= stage_v_193;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (st_var_0.buffer[0] ^ 197) & 3;
    switch (stage_v_194) {
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

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (out_sink > 100) ? (chk_sum & 31) : (200 & 31);
    out_sink = (out_sink + stage_v_195) & 255;
    chk_sum ^= (stage_v_195 << 1) & 127;

    /* Execution Pipeline Stage 196 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 197) & 15;
    int stage_v_196 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    chk_sum ^= stage_v_196;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_0.buffer[0] ^ 201) & 3;
    switch (stage_v_198) {
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

    /* Execution Pipeline Stage 199 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 200) & 15;
    int stage_v_199 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= stage_v_199;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = table[0];
    table[0] = (table[1] + 401) & 63;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = table[1];
    table[1] = (table[2] + 403) & 63;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 203) & 15;
    int stage_v_202 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    chk_sum ^= stage_v_202;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_203 = (stage_v_203 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_203) & 127;
    }
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (st_var_0.buffer[0] * 2 + 619) & 63;
    if (stage_v_204 > 24) {
        out_sink = (out_sink + stage_v_204 - 5) & 255;
        if (stage_v_204 > 39) {
            chk_sum ^= (stage_v_204 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_204 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = table[1];
    table[1] = (table[2] + 411) & 63;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = table[2];
    table[2] = (table[3] + 413) & 63;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (st_var_1.buffer[0] ^ 210) & 3;
    switch (stage_v_207) {
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

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (st_var_0.buffer[0] ^ 211) & 3;
    switch (stage_v_208) {
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

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (st_var_1.buffer[0] ^ 212) & 3;
    switch (stage_v_209) {
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

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (st_var_0.buffer[0] ^ 213) & 3;
    switch (stage_v_210) {
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

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (out_sink > 100) ? (chk_sum & 31) : (216 & 31);
    out_sink = (out_sink + stage_v_211) & 255;
    chk_sum ^= (stage_v_211 << 1) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_212 = (stage_v_212 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_212) & 127;
    }
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 214) & 15;
    int stage_v_213 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_213) & 255;
    chk_sum ^= stage_v_213;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (st_var_0.buffer[1] * 2 + 649) & 63;
    if (stage_v_214 > 38) {
        out_sink = (out_sink + stage_v_214 - 5) & 255;
        if (stage_v_214 > 53) {
            chk_sum ^= (stage_v_214 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_214 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (st_var_1.buffer[2] * 2 + 652) & 63;
    if (stage_v_215 > 34) {
        out_sink = (out_sink + stage_v_215 - 5) & 255;
        if (stage_v_215 > 49) {
            chk_sum ^= (stage_v_215 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_215 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = table[0];
    table[0] = (table[1] + 433) & 63;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_217 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (st_var_0.buffer[2] * 2 + 661) & 63;
    if (stage_v_218 > 30) {
        out_sink = (out_sink + stage_v_218 - 5) & 255;
        if (stage_v_218 > 45) {
            chk_sum ^= (stage_v_218 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_218 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (st_var_1.buffer[0] * 2 + 664) & 63;
    if (stage_v_219 > 29) {
        out_sink = (out_sink + stage_v_219 - 5) & 255;
        if (stage_v_219 > 44) {
            chk_sum ^= (stage_v_219 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_219 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (st_var_0.buffer[1] * 2 + 667) & 63;
    if (stage_v_220 > 14) {
        out_sink = (out_sink + stage_v_220 - 5) & 255;
        if (stage_v_220 > 29) {
            chk_sum ^= (stage_v_220 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_220 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = table[1];
    table[1] = (table[2] + 443) & 63;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = table[2];
    table[2] = (table[3] + 445) & 63;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = table[3];
    table[3] = (table[0] + 447) & 63;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_224 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (out_sink > 100) ? (chk_sum & 31) : (230 & 31);
    out_sink = (out_sink + stage_v_225) & 255;
    chk_sum ^= (stage_v_225 << 1) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (out_sink > 100) ? (chk_sum & 31) : (231 & 31);
    out_sink = (out_sink + stage_v_226) & 255;
    chk_sum ^= (stage_v_226 << 1) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (st_var_1.buffer[2] * 2 + 688) & 63;
    if (stage_v_227 > 31) {
        out_sink = (out_sink + stage_v_227 - 5) & 255;
        if (stage_v_227 > 46) {
            chk_sum ^= (stage_v_227 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_227 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (st_var_0.buffer[0] * 2 + 691) & 63;
    if (stage_v_228 > 16) {
        out_sink = (out_sink + stage_v_228 - 5) & 255;
        if (stage_v_228 > 31) {
            chk_sum ^= (stage_v_228 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_228 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Security Information Flow: Family = arithmetic_flow */
    int arith_v_0 = (sec_r000314_5 * 3 + pub_r000314_14) & 127;
    int arith_v_1 = (arith_v_0 ^ (sec_r000314_6 * 2)) & 127;
    int arith_v_2 = (arith_v_1 + (sec_r000314_1 * 2)) & 127;
    out_sink += arith_v_2 & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
