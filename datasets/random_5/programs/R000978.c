/*
 * Benchmark Program: R000978
 * Security Family: secret_dependent_loops
 * Generator Seed: 597813
 * High Inputs: 17 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000978_7813_0 {
    unsigned char peak;
    int rms;
    short channels;
    int buffer[3];
};

struct MatrixBlock_R000978_7813_1 {
    unsigned char scale;
    short trace;
    int determinant;
    short dim;
    int buffer[3];
};

struct CipherContext_R000978_7813_2 {
    short iv;
    unsigned char flags;
    short counter;
    unsigned char round_key;
    int buffer[3];
};

struct SensorNode_R000978_7813_3 {
    int calib;
    int status;
    int offset;
    unsigned char gain;
    int buffer[3];
};

union TelemetryField_R000978_7813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000978_7813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000978_7813_0(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000978_7813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int threshold_37 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_37 > 13) {
        acc = (acc + threshold_37 * 2 + 5) & 127;
        aux ^= (threshold_37 & 15);
    } else {
        acc = (acc - threshold_37 + 11) & 127;
        aux += 3;
    }
    int vector_98 = (aux + st.buffer[1]) & 3;
    switch (vector_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_58 = local_arr[aux % 3];
    acc = (acc + sample_58 * 2) & 127;
    int sample_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000978_7813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000978_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int damping_49 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_49 > 42) {
        acc = (acc + damping_49 * 2 + 5) & 127;
        aux ^= (damping_49 & 15);
    } else {
        acc = (acc - damping_49 + 11) & 127;
        aux += 3;
    }
    int threshold_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000978_7813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000978_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int metric_35 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_35 > 48) {
        acc = (acc + metric_35 * 2 + 5) & 127;
        aux ^= (metric_35 & 15);
    } else {
        acc = (acc - metric_35 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_89 = local_arr[aux % 3];
    acc = (acc + weight_89 * 2) & 127;
    int window_43 = (aux + st.buffer[1]) & 3;
    switch (window_43) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000978_7813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000978_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_66 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_66 > 24) {
        acc = (acc + weight_66 * 2 + 5) & 127;
        aux ^= (weight_66 & 15);
    } else {
        acc = (acc - weight_66 + 11) & 127;
        aux += 3;
    }
    int mask_30 = (aux + st.buffer[1]) & 3;
    switch (mask_30) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000978_7813_4(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000978_7813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int tally_15 = local_arr[aux % 3];
    acc = (acc + tally_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_99) & 63;
    acc ^= aux;
    int coefficient_95 = (aux + st.buffer[1]) & 3;
    switch (coefficient_95) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000978_7813_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000978_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000978_7813_6(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000978_7813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int scale_22 = local_arr[aux % 3];
    acc = (acc + scale_22 * 2) & 127;
    int mask_36 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_36 > 21) {
        acc = (acc + mask_36 * 2 + 5) & 127;
        aux ^= (mask_36 & 15);
    } else {
        acc = (acc - mask_36 + 11) & 127;
        aux += 3;
    }
    int pivot_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_56) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000978_7813_7(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000978_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_30 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_30 > 48) {
        acc = (acc + tally_30 * 2 + 5) & 127;
        aux ^= (tally_30 & 15);
    } else {
        acc = (acc - tally_30 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_30 = (aux + st.buffer[1]) & 3;
    switch (vector_30) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000978_7813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000978_7813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int weight_63 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_63 > 21) {
        acc = (acc + weight_63 * 2 + 5) & 127;
        aux ^= (weight_63 & 15);
    } else {
        acc = (acc - weight_63 + 11) & 127;
        aux += 3;
    }
    int segment_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000978_7813_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000978_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int offset_83 = (aux + st.buffer[1]) & 3;
    switch (offset_83) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_66 = local_arr[aux % 3];
    acc = (acc + mask_66 * 2) & 127;
    int bound_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000978_7813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000978_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int scale_54 = local_arr[aux % 3];
    acc = (acc + scale_54 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000978_7813_11(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000978_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_20 = (aux + st.buffer[1]) & 3;
    switch (sample_20) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_95 = local_arr[aux % 3];
    acc = (acc + delta_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000978_7813_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000978_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_52) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_64 = local_arr[aux % 3];
    acc = (acc + bound_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000978_7813_13(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000978_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_66 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_66 > 19) {
        acc = (acc + damping_66 * 2 + 5) & 127;
        aux ^= (damping_66 & 15);
    } else {
        acc = (acc - damping_66 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_45 = local_arr[aux % 3];
    acc = (acc + phase_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000978_7813_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000978_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_58) & 63;
    acc ^= aux;
    int parity_52 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_52 > 12) {
        acc = (acc + parity_52 * 2 + 5) & 127;
        aux ^= (parity_52 & 15);
    } else {
        acc = (acc - parity_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000978_7813_15(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000978_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_57 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_57 > 21) {
        acc = (acc + sample_57 * 2 + 5) & 127;
        aux ^= (sample_57 & 15);
    } else {
        acc = (acc - sample_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000978_0;
    int sec_r000978_1;
    int sec_r000978_2;
    int sec_r000978_3;
    int sec_r000978_4;
    int sec_r000978_5;
    int sec_r000978_6;
    int sec_r000978_7;
    int sec_r000978_8;
    int sec_r000978_9;
    int sec_r000978_10;
    int sec_r000978_11;
    int sec_r000978_12;
    int sec_r000978_13;
    int sec_r000978_14;
    int sec_r000978_15;
    int sec_r000978_16;
    int pub_r000978_0;
    int pub_r000978_1;
    int pub_r000978_2;
    int pub_r000978_3;
    int pub_r000978_4;
    int pub_r000978_5;
    int pub_r000978_6;
    int pub_r000978_7;
    int pub_r000978_8;
    int pub_r000978_9;
    int pub_r000978_10;
    int pub_r000978_11;
    int pub_r000978_12;
    int pub_r000978_13;
    int pub_r000978_14;
    int pub_r000978_15;
    int pub_r000978_16;
    int pub_r000978_17;
    int pub_r000978_18;
    int pub_r000978_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000978_0 >= -100 && pub_r000978_0 <= 100);
    __CPROVER_assume(pub_r000978_1 >= -100 && pub_r000978_1 <= 100);
    __CPROVER_assume(pub_r000978_2 >= -100 && pub_r000978_2 <= 100);
    __CPROVER_assume(pub_r000978_3 >= -100 && pub_r000978_3 <= 100);
    __CPROVER_assume(pub_r000978_4 >= -100 && pub_r000978_4 <= 100);
    __CPROVER_assume(pub_r000978_5 >= -100 && pub_r000978_5 <= 100);
    __CPROVER_assume(pub_r000978_6 >= -100 && pub_r000978_6 <= 100);
    __CPROVER_assume(pub_r000978_7 >= -100 && pub_r000978_7 <= 100);
    __CPROVER_assume(pub_r000978_8 >= -100 && pub_r000978_8 <= 100);
    __CPROVER_assume(pub_r000978_9 >= -100 && pub_r000978_9 <= 100);
    __CPROVER_assume(pub_r000978_10 >= -100 && pub_r000978_10 <= 100);
    __CPROVER_assume(pub_r000978_11 >= -100 && pub_r000978_11 <= 100);
    __CPROVER_assume(pub_r000978_12 >= -100 && pub_r000978_12 <= 100);
    __CPROVER_assume(pub_r000978_13 >= -100 && pub_r000978_13 <= 100);
    __CPROVER_assume(pub_r000978_14 >= -100 && pub_r000978_14 <= 100);
    __CPROVER_assume(pub_r000978_15 >= -100 && pub_r000978_15 <= 100);
    __CPROVER_assume(pub_r000978_16 >= -100 && pub_r000978_16 <= 100);
    __CPROVER_assume(pub_r000978_17 >= -100 && pub_r000978_17 <= 100);
    __CPROVER_assume(pub_r000978_18 >= -100 && pub_r000978_18 <= 100);
    __CPROVER_assume(pub_r000978_19 >= -100 && pub_r000978_19 <= 100);
    __CPROVER_assume(sec_r000978_0 >= 0 && sec_r000978_0 <= 255);
    __CPROVER_assume(sec_r000978_1 >= 0 && sec_r000978_1 <= 255);
    __CPROVER_assume(sec_r000978_2 >= 0 && sec_r000978_2 <= 255);
    __CPROVER_assume(sec_r000978_3 >= 0 && sec_r000978_3 <= 255);
    __CPROVER_assume(sec_r000978_4 >= 0 && sec_r000978_4 <= 255);
    __CPROVER_assume(sec_r000978_5 >= 0 && sec_r000978_5 <= 255);
    __CPROVER_assume(sec_r000978_6 >= 0 && sec_r000978_6 <= 255);
    __CPROVER_assume(sec_r000978_7 >= 0 && sec_r000978_7 <= 255);
    __CPROVER_assume(sec_r000978_8 >= 0 && sec_r000978_8 <= 255);
    __CPROVER_assume(sec_r000978_9 >= 0 && sec_r000978_9 <= 255);
    __CPROVER_assume(sec_r000978_10 >= 0 && sec_r000978_10 <= 255);
    __CPROVER_assume(sec_r000978_11 >= 0 && sec_r000978_11 <= 255);
    __CPROVER_assume(sec_r000978_12 >= 0 && sec_r000978_12 <= 255);
    __CPROVER_assume(sec_r000978_13 >= 0 && sec_r000978_13 <= 255);
    __CPROVER_assume(sec_r000978_14 >= 0 && sec_r000978_14 <= 255);
    __CPROVER_assume(sec_r000978_15 >= 0 && sec_r000978_15 <= 255);
    __CPROVER_assume(sec_r000978_16 >= 0 && sec_r000978_16 <= 255);

    struct AudioFrame_R000978_7813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000978_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000978_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000978_0 + 7) & 15;
    struct MatrixBlock_R000978_7813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000978_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000978_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000978_0 + 9) & 15;
    struct CipherContext_R000978_7813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000978_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000978_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000978_0 + 11) & 15;
    struct SensorNode_R000978_7813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000978_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000978_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000978_0 + 13) & 15;

    union TelemetryField_R000978_7813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_15 & 1) == step) {
            stage_v_6 = (stage_v_6 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_6 = (stage_v_6 + pub_r000978_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_9 & 1) == step) {
            stage_v_7 = (stage_v_7 + step * 4 + pub_r000978_12) & 63;
        } else {
            stage_v_7 = (stage_v_7 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_6 & 1) == step) {
            stage_v_8 = (stage_v_8 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_8 = (stage_v_8 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_13 & 1) == step) {
            stage_v_9 = (stage_v_9 + step * 4 + pub_r000978_13) & 63;
        } else {
            stage_v_9 = (stage_v_9 + pub_r000978_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_9 & 1) == step) {
            stage_v_10 = (stage_v_10 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_10 = (stage_v_10 + pub_r000978_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_6 & 1) == step) {
            stage_v_11 = (stage_v_11 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_11 = (stage_v_11 + pub_r000978_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_7 & 1) == step) {
            stage_v_12 = (stage_v_12 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_12 = (stage_v_12 + pub_r000978_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_11 & 1) == step) {
            stage_v_13 = (stage_v_13 + step * 4 + pub_r000978_7) & 63;
        } else {
            stage_v_13 = (stage_v_13 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_5 & 1) == step) {
            stage_v_14 = (stage_v_14 + step * 4 + pub_r000978_12) & 63;
        } else {
            stage_v_14 = (stage_v_14 + pub_r000978_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_10 & 1) == step) {
            stage_v_15 = (stage_v_15 + step * 4 + pub_r000978_1) & 63;
        } else {
            stage_v_15 = (stage_v_15 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_5 & 1) == step) {
            stage_v_16 = (stage_v_16 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_16 = (stage_v_16 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_11 & 1) == step) {
            stage_v_17 = (stage_v_17 + step * 4 + pub_r000978_0) & 63;
        } else {
            stage_v_17 = (stage_v_17 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_10 & 1) == step) {
            stage_v_18 = (stage_v_18 + step * 4 + pub_r000978_16) & 63;
        } else {
            stage_v_18 = (stage_v_18 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_13 & 1) == step) {
            stage_v_19 = (stage_v_19 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_19 = (stage_v_19 + pub_r000978_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_10 & 1) == step) {
            stage_v_20 = (stage_v_20 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_20 = (stage_v_20 + pub_r000978_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_14 & 1) == step) {
            stage_v_21 = (stage_v_21 + step * 4 + pub_r000978_1) & 63;
        } else {
            stage_v_21 = (stage_v_21 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_19 & 1) == step) {
            stage_v_22 = (stage_v_22 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_22 = (stage_v_22 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_23 = (stage_v_23 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_23 = (stage_v_23 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_19 & 1) == step) {
            stage_v_24 = (stage_v_24 + step * 4 + pub_r000978_6) & 63;
        } else {
            stage_v_24 = (stage_v_24 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_17 & 1) == step) {
            stage_v_25 = (stage_v_25 + step * 4 + pub_r000978_9) & 63;
        } else {
            stage_v_25 = (stage_v_25 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_23 & 1) == step) {
            stage_v_26 = (stage_v_26 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_26 = (stage_v_26 + pub_r000978_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_14 & 1) == step) {
            stage_v_27 = (stage_v_27 + step * 4 + pub_r000978_6) & 63;
        } else {
            stage_v_27 = (stage_v_27 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_17 & 1) == step) {
            stage_v_28 = (stage_v_28 + step * 4 + pub_r000978_17) & 63;
        } else {
            stage_v_28 = (stage_v_28 + pub_r000978_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_15 & 1) == step) {
            stage_v_29 = (stage_v_29 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_29 = (stage_v_29 + pub_r000978_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_20 & 1) == step) {
            stage_v_30 = (stage_v_30 + step * 4 + pub_r000978_16) & 63;
        } else {
            stage_v_30 = (stage_v_30 + pub_r000978_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_3 & 1) == step) {
            stage_v_31 = (stage_v_31 + step * 4 + pub_r000978_6) & 63;
        } else {
            stage_v_31 = (stage_v_31 + pub_r000978_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_4 & 1) == step) {
            stage_v_32 = (stage_v_32 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_32 = (stage_v_32 + pub_r000978_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_11 & 1) == step) {
            stage_v_33 = (stage_v_33 + step * 4 + pub_r000978_7) & 63;
        } else {
            stage_v_33 = (stage_v_33 + pub_r000978_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_5 & 1) == step) {
            stage_v_34 = (stage_v_34 + step * 4 + pub_r000978_17) & 63;
        } else {
            stage_v_34 = (stage_v_34 + pub_r000978_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_8 & 1) == step) {
            stage_v_35 = (stage_v_35 + step * 4 + pub_r000978_0) & 63;
        } else {
            stage_v_35 = (stage_v_35 + pub_r000978_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_15 & 1) == step) {
            stage_v_36 = (stage_v_36 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_36 = (stage_v_36 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_28 & 1) == step) {
            stage_v_37 = (stage_v_37 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_37 = (stage_v_37 + pub_r000978_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_28 & 1) == step) {
            stage_v_38 = (stage_v_38 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_38 = (stage_v_38 + pub_r000978_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_7 & 1) == step) {
            stage_v_39 = (stage_v_39 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_39 = (stage_v_39 + pub_r000978_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_15 & 1) == step) {
            stage_v_40 = (stage_v_40 + step * 4 + pub_r000978_15) & 63;
        } else {
            stage_v_40 = (stage_v_40 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_32 & 1) == step) {
            stage_v_41 = (stage_v_41 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_41 = (stage_v_41 + pub_r000978_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_29 & 1) == step) {
            stage_v_42 = (stage_v_42 + step * 4 + pub_r000978_9) & 63;
        } else {
            stage_v_42 = (stage_v_42 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_11 & 1) == step) {
            stage_v_43 = (stage_v_43 + step * 4 + pub_r000978_7) & 63;
        } else {
            stage_v_43 = (stage_v_43 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_12 & 1) == step) {
            stage_v_44 = (stage_v_44 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_44 = (stage_v_44 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_40 & 1) == step) {
            stage_v_45 = (stage_v_45 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_45 = (stage_v_45 + pub_r000978_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_20 & 1) == step) {
            stage_v_46 = (stage_v_46 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_46 = (stage_v_46 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_34 & 1) == step) {
            stage_v_47 = (stage_v_47 + step * 4 + pub_r000978_17) & 63;
        } else {
            stage_v_47 = (stage_v_47 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_10 & 1) == step) {
            stage_v_48 = (stage_v_48 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_48 = (stage_v_48 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_11 & 1) == step) {
            stage_v_49 = (stage_v_49 + step * 4 + pub_r000978_15) & 63;
        } else {
            stage_v_49 = (stage_v_49 + pub_r000978_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_19 & 1) == step) {
            stage_v_50 = (stage_v_50 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_50 = (stage_v_50 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_16 & 1) == step) {
            stage_v_51 = (stage_v_51 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_51 = (stage_v_51 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000978_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_40 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000978_18) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000978_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_8 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_10 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000978_13) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_3 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000978_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_11 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000978_8) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000978_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_29 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_48 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000978_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_16 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_10 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_11 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000978_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000978_7) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000978_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_9 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000978_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_38 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000978_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000978_13) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_8 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_6 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000978_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_0 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000978_19) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000978_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_8 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000978_13) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000978_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_14 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_39 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_33 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000978_13) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000978_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_8 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000978_7) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000978_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_16 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000978_0) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_2 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000978_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_10 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000978_0) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000978_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000978_12) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000978_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000978_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_41 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000978_19) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000978_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_11 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000978_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_9 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000978_12) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000978_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_9 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000978_19) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000978_0) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000978_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_7 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000978_9) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_5 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000978_16) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000978_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000978_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_18 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_13 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000978_1) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000978_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000978_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_47 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000978_16) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_6 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000978_6) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000978_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000978_19) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000978_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000978_15) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_6 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000978_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_27 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000978_11) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_16 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000978_18) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000978_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_26 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000978_0) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000978_6) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000978_12) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_9 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000978_18) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_39 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000978_16) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000978_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000978_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000978_17) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000978_13) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000978_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_20 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000978_9) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000978_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_12 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000978_18) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000978_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000978_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_13 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000978_10) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000978_6) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000978_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000978_15) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000978_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000978_1) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000978_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_13 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000978_19) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000978_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000978_0) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000978_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_8 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000978_4) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000978_8) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000978_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_36 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000978_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_1 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000978_17) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000978_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000978_15) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_2 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000978_9) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000978_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_10 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000978_3) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000978_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000978_10 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000978_2) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000978_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_42 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000978_14) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000978_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000978_19) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000978_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000978_5) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000978_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000978_1) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000978_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
