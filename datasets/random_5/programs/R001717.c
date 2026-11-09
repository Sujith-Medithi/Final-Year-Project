/*
 * Benchmark Program: R001717
 * Security Family: nested_implicit_flow
 * Generator Seed: 671713
 * High Inputs: 18 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001717_1713_0 {
    int severity;
    unsigned char signature;
    int code;
    unsigned char seq;
    unsigned char timestamp;
    short facility;
    int buffer[3];
};

struct CipherContext_R001717_1713_1 {
    int tag;
    int nonce;
    short iv;
    short round_key;
    int buffer[3];
};

struct SensorNode_R001717_1713_2 {
    short calib;
    int reading;
    short offset;
    unsigned char gain;
    int buffer[3];
};

struct FilterState_R001717_1713_3 {
    short prev_out;
    int mode;
    short prev_in;
    int damping;
    int gain_db;
    short cutoff;
    int buffer[3];
};

union RegisterBank_R001717_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001717_1713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int vector_79 = 0;
    for (int k = 0; k < 2; k++) {
        vector_79 = (vector_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_79) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_14 = local_arr[aux % 3];
    acc = (acc + accumulator_14 * 2) & 127;
    int tracker_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001717_1713_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int vector_84 = 0;
    for (int k = 0; k < 2; k++) {
        vector_84 = (vector_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_84) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_21 = local_arr[aux % 3];
    acc = (acc + accumulator_21 * 2) & 127;
    int stride_42 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_42 > 41) {
        acc = (acc + stride_42 * 2 + 5) & 127;
        aux ^= (stride_42 & 15);
    } else {
        acc = (acc - stride_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001717_1713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001717_1713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int tally_63 = local_arr[aux % 3];
    acc = (acc + tally_63 * 2) & 127;
    int damping_53 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_53 > 43) {
        acc = (acc + damping_53 * 2 + 5) & 127;
        aux ^= (damping_53 & 15);
    } else {
        acc = (acc - damping_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001717_1713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_86 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_86 > 10) {
        acc = (acc + margin_86 * 2 + 5) & 127;
        aux ^= (margin_86 & 15);
    } else {
        acc = (acc - margin_86 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_53 = local_arr[aux % 3];
    acc = (acc + tracker_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001717_1713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001717_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int window_99 = 0;
    for (int k = 0; k < 2; k++) {
        window_99 = (window_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_99) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001717_1713_5(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_58 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_58 > 19) {
        acc = (acc + coefficient_58 * 2 + 5) & 127;
        aux ^= (coefficient_58 & 15);
    } else {
        acc = (acc - coefficient_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001717_1713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int threshold_35 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_35 = (threshold_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_35) & 127;
    }
    int parity_38 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_38 > 14) {
        acc = (acc + parity_38 * 2 + 5) & 127;
        aux ^= (parity_38 & 15);
    } else {
        acc = (acc - parity_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_61 = local_arr[aux % 3];
    acc = (acc + mask_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001717_1713_7(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001717_1713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quotient_77 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_77 > 13) {
        acc = (acc + quotient_77 * 2 + 5) & 127;
        aux ^= (quotient_77 & 15);
    } else {
        acc = (acc - quotient_77 + 11) & 127;
        aux += 3;
    }
    int sample_92 = 0;
    for (int k = 0; k < 3; k++) {
        sample_92 = (sample_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_92) & 127;
    }
    int coefficient_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001717_1713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_46 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_46 > 10) {
        acc = (acc + weight_46 * 2 + 5) & 127;
        aux ^= (weight_46 & 15);
    } else {
        acc = (acc - weight_46 + 11) & 127;
        aux += 3;
    }
    int metric_40 = 0;
    for (int k = 0; k < 2; k++) {
        metric_40 = (metric_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001717_1713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001717_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int accumulator_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_95) & 63;
    acc ^= aux;
    int phase_30 = (aux + st.buffer[1]) & 3;
    switch (phase_30) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_51 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_51 > 13) {
        acc = (acc + scale_51 * 2 + 5) & 127;
        aux ^= (scale_51 & 15);
    } else {
        acc = (acc - scale_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001717_1713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001717_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int metric_94 = local_arr[aux % 3];
    acc = (acc + metric_94 * 2) & 127;
    int index_reg_74 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_74 > 33) {
        acc = (acc + index_reg_74 * 2 + 5) & 127;
        aux ^= (index_reg_74 & 15);
    } else {
        acc = (acc - index_reg_74 + 11) & 127;
        aux += 3;
    }
    int residue_23 = (aux + st.buffer[1]) & 3;
    switch (residue_23) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001717_1713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001717_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int cursor_95 = (aux + st.buffer[1]) & 3;
    switch (cursor_95) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_30) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_22 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_22 > 25) {
        acc = (acc + weight_22 * 2 + 5) & 127;
        aux ^= (weight_22 & 15);
    } else {
        acc = (acc - weight_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001717_1713_12(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int residue_23 = local_arr[aux % 3];
    acc = (acc + residue_23 * 2) & 127;
    int weight_52 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_52 > 16) {
        acc = (acc + weight_52 * 2 + 5) & 127;
        aux ^= (weight_52 & 15);
    } else {
        acc = (acc - weight_52 + 11) & 127;
        aux += 3;
    }
    int window_34 = 0;
    for (int k = 0; k < 2; k++) {
        window_34 = (window_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_34) & 127;
    }
    int stride_86 = (aux + st.buffer[1]) & 3;
    switch (stride_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001717_1713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001717_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int coefficient_48 = local_arr[aux % 3];
    acc = (acc + coefficient_48 * 2) & 127;
    int damping_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_35) & 63;
    acc ^= aux;
    int checksum_60 = (aux + st.buffer[1]) & 3;
    switch (checksum_60) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001717_1713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001717_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int tally_92 = (aux + st.buffer[1]) & 3;
    switch (tally_92) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_36 = 0;
    for (int k = 0; k < 2; k++) {
        offset_36 = (offset_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_36) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_83 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_83 > 44) {
        acc = (acc + index_reg_83 * 2 + 5) & 127;
        aux ^= (index_reg_83 & 15);
    } else {
        acc = (acc - index_reg_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001717_0;
    int sec_r001717_1;
    int sec_r001717_2;
    int sec_r001717_3;
    int sec_r001717_4;
    int sec_r001717_5;
    int sec_r001717_6;
    int sec_r001717_7;
    int sec_r001717_8;
    int sec_r001717_9;
    int sec_r001717_10;
    int sec_r001717_11;
    int sec_r001717_12;
    int sec_r001717_13;
    int sec_r001717_14;
    int sec_r001717_15;
    int sec_r001717_16;
    int sec_r001717_17;
    int pub_r001717_0;
    int pub_r001717_1;
    int pub_r001717_2;
    int pub_r001717_3;
    int pub_r001717_4;
    int pub_r001717_5;
    int pub_r001717_6;
    int pub_r001717_7;
    int pub_r001717_8;
    int pub_r001717_9;
    int pub_r001717_10;
    int pub_r001717_11;
    int pub_r001717_12;
    int pub_r001717_13;
    int pub_r001717_14;
    int pub_r001717_15;
    int pub_r001717_16;
    int pub_r001717_17;
    int pub_r001717_18;
    int pub_r001717_19;
    int pub_r001717_20;
    int pub_r001717_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001717_0 >= -100 && pub_r001717_0 <= 100);
    __CPROVER_assume(pub_r001717_1 >= -100 && pub_r001717_1 <= 100);
    __CPROVER_assume(pub_r001717_2 >= -100 && pub_r001717_2 <= 100);
    __CPROVER_assume(pub_r001717_3 >= -100 && pub_r001717_3 <= 100);
    __CPROVER_assume(pub_r001717_4 >= -100 && pub_r001717_4 <= 100);
    __CPROVER_assume(pub_r001717_5 >= -100 && pub_r001717_5 <= 100);
    __CPROVER_assume(pub_r001717_6 >= -100 && pub_r001717_6 <= 100);
    __CPROVER_assume(pub_r001717_7 >= -100 && pub_r001717_7 <= 100);
    __CPROVER_assume(pub_r001717_8 >= -100 && pub_r001717_8 <= 100);
    __CPROVER_assume(pub_r001717_9 >= -100 && pub_r001717_9 <= 100);
    __CPROVER_assume(pub_r001717_10 >= -100 && pub_r001717_10 <= 100);
    __CPROVER_assume(pub_r001717_11 >= -100 && pub_r001717_11 <= 100);
    __CPROVER_assume(pub_r001717_12 >= -100 && pub_r001717_12 <= 100);
    __CPROVER_assume(pub_r001717_13 >= -100 && pub_r001717_13 <= 100);
    __CPROVER_assume(pub_r001717_14 >= -100 && pub_r001717_14 <= 100);
    __CPROVER_assume(pub_r001717_15 >= -100 && pub_r001717_15 <= 100);
    __CPROVER_assume(pub_r001717_16 >= -100 && pub_r001717_16 <= 100);
    __CPROVER_assume(pub_r001717_17 >= -100 && pub_r001717_17 <= 100);
    __CPROVER_assume(pub_r001717_18 >= -100 && pub_r001717_18 <= 100);
    __CPROVER_assume(pub_r001717_19 >= -100 && pub_r001717_19 <= 100);
    __CPROVER_assume(pub_r001717_20 >= -100 && pub_r001717_20 <= 100);
    __CPROVER_assume(pub_r001717_21 >= -100 && pub_r001717_21 <= 100);
    __CPROVER_assume(sec_r001717_0 >= 0 && sec_r001717_0 <= 255);
    __CPROVER_assume(sec_r001717_1 >= 0 && sec_r001717_1 <= 255);
    __CPROVER_assume(sec_r001717_2 >= 0 && sec_r001717_2 <= 255);
    __CPROVER_assume(sec_r001717_3 >= 0 && sec_r001717_3 <= 255);
    __CPROVER_assume(sec_r001717_4 >= 0 && sec_r001717_4 <= 255);
    __CPROVER_assume(sec_r001717_5 >= 0 && sec_r001717_5 <= 255);
    __CPROVER_assume(sec_r001717_6 >= 0 && sec_r001717_6 <= 255);
    __CPROVER_assume(sec_r001717_7 >= 0 && sec_r001717_7 <= 255);
    __CPROVER_assume(sec_r001717_8 >= 0 && sec_r001717_8 <= 255);
    __CPROVER_assume(sec_r001717_9 >= 0 && sec_r001717_9 <= 255);
    __CPROVER_assume(sec_r001717_10 >= 0 && sec_r001717_10 <= 255);
    __CPROVER_assume(sec_r001717_11 >= 0 && sec_r001717_11 <= 255);
    __CPROVER_assume(sec_r001717_12 >= 0 && sec_r001717_12 <= 255);
    __CPROVER_assume(sec_r001717_13 >= 0 && sec_r001717_13 <= 255);
    __CPROVER_assume(sec_r001717_14 >= 0 && sec_r001717_14 <= 255);
    __CPROVER_assume(sec_r001717_15 >= 0 && sec_r001717_15 <= 255);
    __CPROVER_assume(sec_r001717_16 >= 0 && sec_r001717_16 <= 255);
    __CPROVER_assume(sec_r001717_17 >= 0 && sec_r001717_17 <= 255);

    struct EventLog_R001717_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001717_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001717_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001717_0 + 7) & 15;
    struct CipherContext_R001717_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001717_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001717_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001717_0 + 9) & 15;
    struct SensorNode_R001717_1713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001717_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001717_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001717_0 + 11) & 15;
    struct FilterState_R001717_1713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001717_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001717_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001717_0 + 13) & 15;

    union RegisterBank_R001717_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001717_1713_0(sec_r001717_0, sec_r001717_1, pub_r001717_2, pub_r001717_3);
    int helper_flow_1 = fn_R001717_1713_1(sec_r001717_1, pub_r001717_2, pub_r001717_3);
    int helper_flow_2 = fn_R001717_1713_2(sec_r001717_2, sec_r001717_3, pub_r001717_4, pub_r001717_5, pub_r001717_6);
    int helper_flow_3 = fn_R001717_1713_3(sec_r001717_3, pub_r001717_4, pub_r001717_5, pub_r001717_6, pub_r001717_7);
    int helper_flow_4 = fn_R001717_1713_4(sec_r001717_4, pub_r001717_5, pub_r001717_6, pub_r001717_7, pub_r001717_8);
    int helper_flow_5 = fn_R001717_1713_5(sec_r001717_5, pub_r001717_6);
    int helper_flow_6 = fn_R001717_1713_6(sec_r001717_6, pub_r001717_7, pub_r001717_8, pub_r001717_9, pub_r001717_10);
    int helper_flow_7 = fn_R001717_1713_7(sec_r001717_7, pub_r001717_8, pub_r001717_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_1 ^ pub_r001717_21) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001717_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001717_17 ^ pub_r001717_0) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001717_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001717_11 ^ pub_r001717_5) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001717_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001717_2 ^ pub_r001717_15) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001717_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001717_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001717_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001717_10 ^ pub_r001717_20) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001717_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001717_11 ^ pub_r001717_4) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001717_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_1 ^ pub_r001717_20) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001717_7 ^ pub_r001717_16) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001717_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001717_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001717_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001717_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_2 ^ pub_r001717_14) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_1 ^ pub_r001717_13) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r001717_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001717_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001717_3 ^ pub_r001717_0) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001717_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001717_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_7 ^ pub_r001717_21) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001717_1 ^ pub_r001717_1) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001717_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001717_2 ^ pub_r001717_17) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001717_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_2 ^ pub_r001717_6) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001717_5 ^ pub_r001717_17) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001717_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001717_12 ^ pub_r001717_16) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001717_14 ^ pub_r001717_4) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001717_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001717_8 ^ pub_r001717_20) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001717_15 ^ pub_r001717_20) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001717_2 ^ pub_r001717_10) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001717_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_25 ^ pub_r001717_9) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001717_14 ^ pub_r001717_20) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_0 ^ pub_r001717_14) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001717_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001717_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_29 ^ pub_r001717_15) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001717_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_28 ^ pub_r001717_15) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_25 ^ pub_r001717_15) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001717_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001717_8 ^ pub_r001717_21) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001717_10 ^ pub_r001717_10) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001717_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_7 ^ pub_r001717_9) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r001717_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001717_6 ^ pub_r001717_19) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001717_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001717_14 ^ pub_r001717_8) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_43 ^ pub_r001717_20) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001717_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001717_3 ^ pub_r001717_5) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001717_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_32 ^ pub_r001717_2) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001717_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001717_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_25 ^ pub_r001717_2) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_16 ^ pub_r001717_21) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001717_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001717_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (helper_flow_1 ^ pub_r001717_7) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001717_12 ^ pub_r001717_2) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001717_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_33 ^ pub_r001717_8) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001717_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001717_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r001717_9 ^ pub_r001717_15) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r001717_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (helper_flow_3 ^ pub_r001717_19) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_57 ^ pub_r001717_5) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001717_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_30 ^ pub_r001717_9) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_48 ^ pub_r001717_18) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r001717_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_9 ^ pub_r001717_6) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001717_13 ^ pub_r001717_7) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_45 ^ pub_r001717_9) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001717_17 ^ pub_r001717_0) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_8 ^ pub_r001717_16) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r001717_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001717_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001717_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_53 ^ pub_r001717_15) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (helper_flow_1 ^ pub_r001717_9) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_71 ^ pub_r001717_10) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_16 ^ pub_r001717_10) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_1 ^ pub_r001717_13) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001717_0 ^ pub_r001717_9) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_72 ^ pub_r001717_17) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_58 ^ pub_r001717_5) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_8 ^ pub_r001717_8) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001717_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (helper_flow_0 ^ pub_r001717_14) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (helper_flow_3 ^ pub_r001717_18) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r001717_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_33 ^ pub_r001717_7) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r001717_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_85 ^ pub_r001717_14) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_9 ^ pub_r001717_21) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_14 ^ pub_r001717_18) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001717_20 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_28 ^ pub_r001717_20) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001717_4 ^ pub_r001717_8) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r001717_5 ^ pub_r001717_7) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001717_15 ^ pub_r001717_3) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001717_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001717_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001717_9 ^ pub_r001717_10) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_89 ^ pub_r001717_13) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001717_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001717_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001717_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001717_5 ^ pub_r001717_19) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001717_12 ^ pub_r001717_20) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_87 ^ pub_r001717_16) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r001717_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001717_21 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_87 ^ pub_r001717_20) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_93 ^ pub_r001717_1) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_53 ^ pub_r001717_13) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_78 ^ pub_r001717_13) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r001717_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_107 ^ pub_r001717_12) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r001717_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_89 ^ pub_r001717_6) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_111 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_94 ^ pub_r001717_11) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_46 ^ pub_r001717_3) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001717_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001717_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001717_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001717_14 ^ pub_r001717_21) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (helper_flow_0 ^ pub_r001717_7) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001717_17 ^ pub_r001717_20) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001717_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_14 ^ pub_r001717_17) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_3 ^ pub_r001717_5) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_110 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_29 ^ pub_r001717_10) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_122 ^ pub_r001717_0) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r001717_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_6 ^ pub_r001717_17) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001717_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001717_17 ^ pub_r001717_6) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r001717_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_120 ^ pub_r001717_8) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r001717_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_66 ^ pub_r001717_12) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_92 ^ pub_r001717_5) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_28 ^ pub_r001717_21) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_63 ^ pub_r001717_16) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_109 ^ pub_r001717_14) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_111 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_39 ^ pub_r001717_11) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001717_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (sec_r001717_10 ^ pub_r001717_21) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r001717_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001717_7 ^ pub_r001717_6) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001717_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001717_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_81 ^ pub_r001717_8) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_131 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_25 ^ pub_r001717_2) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_109 ^ pub_r001717_18) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_31 ^ pub_r001717_17) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_122 ^ pub_r001717_13) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_99 ^ pub_r001717_19) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_111 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001717_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_119 ^ pub_r001717_19) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_63 ^ pub_r001717_21) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_32 ^ pub_r001717_15) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001717_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_112 ^ pub_r001717_18) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((sec_r001717_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_75 ^ pub_r001717_2) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_113 ^ pub_r001717_3) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_112 ^ pub_r001717_12) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001717_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_28 ^ pub_r001717_20) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001717_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_123 ^ pub_r001717_5) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_30 ^ pub_r001717_19) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_150 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001717_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001717_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_86 ^ pub_r001717_4) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_130 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_159 ^ pub_r001717_18) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_9 ^ pub_r001717_0) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_99 ^ pub_r001717_11) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_44 ^ pub_r001717_17) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001717_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_129 ^ pub_r001717_11) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001717_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001717_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001717_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_13 ^ pub_r001717_14) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_131 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_60 ^ pub_r001717_13) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_94 ^ pub_r001717_15) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_99 ^ pub_r001717_8) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001717_15 ^ pub_r001717_9) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (sec_r001717_2 ^ pub_r001717_2) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((sec_r001717_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_131 ^ pub_r001717_5) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((sec_r001717_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001717_3 ^ pub_r001717_2) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001717_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001717_21 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_110 ^ pub_r001717_11) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_93 ^ pub_r001717_3) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001717_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001717_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001717_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001717_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_64 ^ pub_r001717_2) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_72 ^ pub_r001717_11) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (sec_r001717_10 ^ pub_r001717_18) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_179 ^ pub_r001717_21) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_31 ^ pub_r001717_6) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001717_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001717_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r001717_6 ^ pub_r001717_9) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_165 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001717_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001717_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_0 ^ pub_r001717_21) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_64 ^ pub_r001717_11) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((sec_r001717_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001717_5 ^ pub_r001717_21) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((sec_r001717_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001717_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_8 ^ pub_r001717_9) & 63;
    if ((stage_v_203 & 1) != 0) {
        if ((stage_v_196 & 2) != 0) {
            out_sink = (out_sink + stage_v_203 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_203 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_98 ^ pub_r001717_2) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((sec_r001717_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001717_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001717_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r001717_2 ^ pub_r001717_1) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001717_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001717_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_23 ^ pub_r001717_17) & 63;
    if ((stage_v_210 & 1) != 0) {
        if ((stage_v_207 & 2) != 0) {
            out_sink = (out_sink + stage_v_210 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_210 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_175 ^ pub_r001717_9) & 63;
    if ((stage_v_211 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_211 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_211 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (sec_r001717_8 ^ pub_r001717_2) & 63;
    if ((stage_v_212 & 1) != 0) {
        if ((stage_v_163 & 2) != 0) {
            out_sink = (out_sink + stage_v_212 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_212 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001717_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r001717_17 ^ pub_r001717_7) & 63;
    if ((stage_v_214 & 1) != 0) {
        if ((stage_v_152 & 2) != 0) {
            out_sink = (out_sink + stage_v_214 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_214 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_164 ^ pub_r001717_18) & 63;
    if ((stage_v_215 & 1) != 0) {
        if ((stage_v_159 & 2) != 0) {
            out_sink = (out_sink + stage_v_215 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_215 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_177 ^ pub_r001717_6) & 63;
    if ((stage_v_216 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_216 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_216 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
