/*
 * Benchmark Program: R001060
 * Security Family: mixed_control_data
 * Generator Seed: 606013
 * High Inputs: 22 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001060_6013_0 {
    unsigned char offset;
    unsigned char status;
    unsigned char gain;
    int buffer[3];
};

struct StreamBuffer_R001060_6013_1 {
    int checksum;
    short tail;
    short watermark;
    int state;
    int head;
    unsigned char capacity;
    int buffer[3];
};

union RegisterBank_R001060_6013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001060_6013_0(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quotient_28 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_28 > 10) {
        acc = (acc + quotient_28 * 2 + 5) & 127;
        aux ^= (quotient_28 & 15);
    } else {
        acc = (acc - quotient_28 + 11) & 127;
        aux += 3;
    }
    int stride_76 = 0;
    for (int k = 0; k < 2; k++) {
        stride_76 = (stride_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int tally_23 = local_arr[aux % 3];
    acc = (acc + tally_23 * 2) & 127;
    int margin_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_33) & 63;
    acc ^= aux;
    int bound_86 = (aux + st.buffer[1]) & 3;
    switch (bound_86) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_2(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int factor_60 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_60 > 18) {
        acc = (acc + factor_60 * 2 + 5) & 127;
        aux ^= (factor_60 & 15);
    } else {
        acc = (acc - factor_60 + 11) & 127;
        aux += 3;
    }
    int checksum_78 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_78 = (checksum_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_78) & 127;
    }
    int residue_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_68) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_34 = local_arr[aux % 3];
    acc = (acc + tally_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001060_6013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_95 = (aux + st.buffer[1]) & 3;
    switch (factor_95) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_4(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001060_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int factor_71 = local_arr[aux % 3];
    acc = (acc + factor_71 * 2) & 127;
    int cursor_56 = (aux + st.buffer[1]) & 3;
    switch (cursor_56) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_5(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_28 = 0;
    for (int k = 0; k < 3; k++) {
        parity_28 = (parity_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_6(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001060_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_34) & 63;
    acc ^= aux;
    int coefficient_12 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_12 > 28) {
        acc = (acc + coefficient_12 * 2 + 5) & 127;
        aux ^= (coefficient_12 & 15);
    } else {
        acc = (acc - coefficient_12 + 11) & 127;
        aux += 3;
    }
    int vector_24 = (aux + st.buffer[1]) & 3;
    switch (vector_24) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int phase_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_96 = local_arr[aux % 3];
    acc = (acc + window_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_74 = 0;
    for (int k = 0; k < 3; k++) {
        segment_74 = (segment_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_74) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_8(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001060_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_33) & 63;
    acc ^= aux;
    int metric_23 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_23 > 41) {
        acc = (acc + metric_23 * 2 + 5) & 127;
        aux ^= (metric_23 & 15);
    } else {
        acc = (acc - metric_23 + 11) & 127;
        aux += 3;
    }
    int weight_51 = 0;
    for (int k = 0; k < 3; k++) {
        weight_51 = (weight_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_51) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_87 = local_arr[aux % 3];
    acc = (acc + factor_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001060_6013_9(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int sample_79 = (aux + st.buffer[1]) & 3;
    switch (sample_79) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_85 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_85 > 31) {
        acc = (acc + delta_85 * 2 + 5) & 127;
        aux ^= (delta_85 & 15);
    } else {
        acc = (acc - delta_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int index_reg_31 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_31 > 49) {
        acc = (acc + index_reg_31 * 2 + 5) & 127;
        aux ^= (index_reg_31 & 15);
    } else {
        acc = (acc - index_reg_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_67 = (aux + st.buffer[1]) & 3;
    switch (delta_67) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_23 = local_arr[aux % 3];
    acc = (acc + checksum_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001060_6013_11(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001060_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_61 = 0;
    for (int k = 0; k < 3; k++) {
        residue_61 = (residue_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_61) & 127;
    }
    int cursor_82 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_82 > 19) {
        acc = (acc + cursor_82 * 2 + 5) & 127;
        aux ^= (cursor_82 & 15);
    } else {
        acc = (acc - cursor_82 + 11) & 127;
        aux += 3;
    }
    int segment_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001060_6013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001060_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int pivot_42 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_42 = (pivot_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_42) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_37 = local_arr[aux % 3];
    acc = (acc + metric_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001060_6013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001060_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int scale_23 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_23 > 48) {
        acc = (acc + scale_23 * 2 + 5) & 127;
        aux ^= (scale_23 & 15);
    } else {
        acc = (acc - scale_23 + 11) & 127;
        aux += 3;
    }
    int threshold_11 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_11 = (threshold_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_11) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001060_6013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001060_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int coefficient_73 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_73 > 32) {
        acc = (acc + coefficient_73 * 2 + 5) & 127;
        aux ^= (coefficient_73 & 15);
    } else {
        acc = (acc - coefficient_73 + 11) & 127;
        aux += 3;
    }
    int bound_46 = 0;
    for (int k = 0; k < 3; k++) {
        bound_46 = (bound_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_46) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001060_0;
    int sec_r001060_1;
    int sec_r001060_2;
    int sec_r001060_3;
    int sec_r001060_4;
    int sec_r001060_5;
    int sec_r001060_6;
    int sec_r001060_7;
    int sec_r001060_8;
    int sec_r001060_9;
    int sec_r001060_10;
    int sec_r001060_11;
    int sec_r001060_12;
    int sec_r001060_13;
    int sec_r001060_14;
    int sec_r001060_15;
    int sec_r001060_16;
    int sec_r001060_17;
    int sec_r001060_18;
    int sec_r001060_19;
    int sec_r001060_20;
    int sec_r001060_21;
    int pub_r001060_0;
    int pub_r001060_1;
    int pub_r001060_2;
    int pub_r001060_3;
    int pub_r001060_4;
    int pub_r001060_5;
    int pub_r001060_6;
    int pub_r001060_7;
    int pub_r001060_8;
    int pub_r001060_9;
    int pub_r001060_10;
    int pub_r001060_11;
    int pub_r001060_12;
    int pub_r001060_13;
    int pub_r001060_14;
    int pub_r001060_15;
    int pub_r001060_16;
    int pub_r001060_17;
    int pub_r001060_18;
    int pub_r001060_19;
    int pub_r001060_20;
    int pub_r001060_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001060_0 >= -100 && pub_r001060_0 <= 100);
    __CPROVER_assume(pub_r001060_1 >= -100 && pub_r001060_1 <= 100);
    __CPROVER_assume(pub_r001060_2 >= -100 && pub_r001060_2 <= 100);
    __CPROVER_assume(pub_r001060_3 >= -100 && pub_r001060_3 <= 100);
    __CPROVER_assume(pub_r001060_4 >= -100 && pub_r001060_4 <= 100);
    __CPROVER_assume(pub_r001060_5 >= -100 && pub_r001060_5 <= 100);
    __CPROVER_assume(pub_r001060_6 >= -100 && pub_r001060_6 <= 100);
    __CPROVER_assume(pub_r001060_7 >= -100 && pub_r001060_7 <= 100);
    __CPROVER_assume(pub_r001060_8 >= -100 && pub_r001060_8 <= 100);
    __CPROVER_assume(pub_r001060_9 >= -100 && pub_r001060_9 <= 100);
    __CPROVER_assume(pub_r001060_10 >= -100 && pub_r001060_10 <= 100);
    __CPROVER_assume(pub_r001060_11 >= -100 && pub_r001060_11 <= 100);
    __CPROVER_assume(pub_r001060_12 >= -100 && pub_r001060_12 <= 100);
    __CPROVER_assume(pub_r001060_13 >= -100 && pub_r001060_13 <= 100);
    __CPROVER_assume(pub_r001060_14 >= -100 && pub_r001060_14 <= 100);
    __CPROVER_assume(pub_r001060_15 >= -100 && pub_r001060_15 <= 100);
    __CPROVER_assume(pub_r001060_16 >= -100 && pub_r001060_16 <= 100);
    __CPROVER_assume(pub_r001060_17 >= -100 && pub_r001060_17 <= 100);
    __CPROVER_assume(pub_r001060_18 >= -100 && pub_r001060_18 <= 100);
    __CPROVER_assume(pub_r001060_19 >= -100 && pub_r001060_19 <= 100);
    __CPROVER_assume(pub_r001060_20 >= -100 && pub_r001060_20 <= 100);
    __CPROVER_assume(pub_r001060_21 >= -100 && pub_r001060_21 <= 100);
    __CPROVER_assume(sec_r001060_0 >= 0 && sec_r001060_0 <= 255);
    __CPROVER_assume(sec_r001060_1 >= 0 && sec_r001060_1 <= 255);
    __CPROVER_assume(sec_r001060_2 >= 0 && sec_r001060_2 <= 255);
    __CPROVER_assume(sec_r001060_3 >= 0 && sec_r001060_3 <= 255);
    __CPROVER_assume(sec_r001060_4 >= 0 && sec_r001060_4 <= 255);
    __CPROVER_assume(sec_r001060_5 >= 0 && sec_r001060_5 <= 255);
    __CPROVER_assume(sec_r001060_6 >= 0 && sec_r001060_6 <= 255);
    __CPROVER_assume(sec_r001060_7 >= 0 && sec_r001060_7 <= 255);
    __CPROVER_assume(sec_r001060_8 >= 0 && sec_r001060_8 <= 255);
    __CPROVER_assume(sec_r001060_9 >= 0 && sec_r001060_9 <= 255);
    __CPROVER_assume(sec_r001060_10 >= 0 && sec_r001060_10 <= 255);
    __CPROVER_assume(sec_r001060_11 >= 0 && sec_r001060_11 <= 255);
    __CPROVER_assume(sec_r001060_12 >= 0 && sec_r001060_12 <= 255);
    __CPROVER_assume(sec_r001060_13 >= 0 && sec_r001060_13 <= 255);
    __CPROVER_assume(sec_r001060_14 >= 0 && sec_r001060_14 <= 255);
    __CPROVER_assume(sec_r001060_15 >= 0 && sec_r001060_15 <= 255);
    __CPROVER_assume(sec_r001060_16 >= 0 && sec_r001060_16 <= 255);
    __CPROVER_assume(sec_r001060_17 >= 0 && sec_r001060_17 <= 255);
    __CPROVER_assume(sec_r001060_18 >= 0 && sec_r001060_18 <= 255);
    __CPROVER_assume(sec_r001060_19 >= 0 && sec_r001060_19 <= 255);
    __CPROVER_assume(sec_r001060_20 >= 0 && sec_r001060_20 <= 255);
    __CPROVER_assume(sec_r001060_21 >= 0 && sec_r001060_21 <= 255);

    struct SensorNode_R001060_6013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001060_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001060_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001060_0 + 7) & 15;
    struct StreamBuffer_R001060_6013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001060_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001060_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001060_0 + 9) & 15;

    union RegisterBank_R001060_6013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001060_6013_0(sec_r001060_0, sec_r001060_1);
    int helper_flow_1 = fn_R001060_6013_1(sec_r001060_1, pub_r001060_2, pub_r001060_3, pub_r001060_4);
    int helper_flow_2 = fn_R001060_6013_2(sec_r001060_2, sec_r001060_3, pub_r001060_4);
    int helper_flow_3 = fn_R001060_6013_3(sec_r001060_3, pub_r001060_4, pub_r001060_5, pub_r001060_6, pub_r001060_7);
    int helper_flow_4 = fn_R001060_6013_4(sec_r001060_4, sec_r001060_5, pub_r001060_6);
    int helper_flow_5 = fn_R001060_6013_5(sec_r001060_5, pub_r001060_6, pub_r001060_7);
    int helper_flow_6 = fn_R001060_6013_6(sec_r001060_6, pub_r001060_7, pub_r001060_8);
    int helper_flow_7 = fn_R001060_6013_7(sec_r001060_7, sec_r001060_8, pub_r001060_9, pub_r001060_10);
    int helper_flow_8 = fn_R001060_6013_8(sec_r001060_8, pub_r001060_9, pub_r001060_10);
    int helper_flow_9 = fn_R001060_6013_9(sec_r001060_9, pub_r001060_10, pub_r001060_11);
    int helper_flow_10 = fn_R001060_6013_10(sec_r001060_10, pub_r001060_11, pub_r001060_12, pub_r001060_13, pub_r001060_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001060_14 ^ 0x2A) * 2 + pub_r001060_1) & 127;
    if (stage_v_0 > 21) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001060_16 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_1 > 41) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001060_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001060_17 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_3 > 34) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_4 > 29) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001060_5) & 127;
    if (stage_v_5 > 35) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001060_6 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_6 > 29) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001060_10 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_7 > 50) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001060_1) & 127;
    if (stage_v_8 > 41) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001060_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001060_21 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001060_4 ^ 0x2A) * 2 + pub_r001060_1) & 127;
    if (stage_v_11 > 49) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_12 > 33) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001060_7 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_13 > 24) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001060_0 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_14 > 46) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001060_1) & 127;
    if (stage_v_15 > 27) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001060_7 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_16 > 28) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001060_16 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_17 > 24) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001060_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_19 > 30) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001060_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_21 > 35) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001060_10 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_22 > 35) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001060_7 ^ 0x2A) * 2 + pub_r001060_0) & 127;
    if (stage_v_23 > 26) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_24 > 33) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001060_5) & 127;
    if (stage_v_25 > 25) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_26 > 33) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_27 > 40) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001060_0 ^ 0x2A) * 2 + pub_r001060_1) & 127;
    if (stage_v_28 > 46) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001060_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001060_0 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_30 > 41) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001060_13) & 127;
    if (stage_v_31 > 28) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001060_1) & 127;
    if (stage_v_32 > 32) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_33 > 49) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001060_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_35 > 37) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_36 > 47) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001060_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001060_1) & 127;
    if (stage_v_38 > 44) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_39 > 35) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001060_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001060_10 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_41 > 25) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001060_14 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_42 > 43) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001060_15 ^ 0x2A) * 2 + pub_r001060_5) & 127;
    if (stage_v_43 > 32) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001060_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001060_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001060_20) & 127;
    if (stage_v_46 > 41) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001060_19 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_47 > 47) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001060_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001060_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001060_19 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_50 > 23) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001060_12 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_51 > 47) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001060_12 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_52 > 46) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001060_7 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_53 > 32) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_54 > 46) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_55 > 50) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_56 > 32) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001060_13) & 127;
    if (stage_v_57 > 33) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_58 > 22) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001060_19 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_59 > 47) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001060_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_61 > 28) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_62 > 21) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_63 > 26) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001060_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001060_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001060_1 ^ 0x2A) * 2 + pub_r001060_14) & 127;
    if (stage_v_66 > 37) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_67 > 49) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001060_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001060_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001060_19 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_70 > 30) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001060_5 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_71 > 44) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_72 > 41) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_73 > 44) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001060_0) & 127;
    if (stage_v_74 > 22) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001060_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001060_20 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_77 > 48) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_78 > 48) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_79 > 45) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_80 > 28) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001060_20) & 127;
    if (stage_v_81 > 38) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_82 > 31) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_83 > 26) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001060_8) & 127;
    if (stage_v_84 > 42) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_85 > 50) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_86 > 22) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001060_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_88 > 44) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001060_14 ^ 0x2A) * 2 + pub_r001060_8) & 127;
    if (stage_v_89 > 21) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001060_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001060_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001060_3 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_92 > 49) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001060_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001060_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_95 > 48) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_96 > 39) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_97 > 27) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001060_18 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_98 > 27) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001060_9 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_99 > 44) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001060_18 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_100 > 35) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_101 > 37) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_102 > 41) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_103 > 42) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_104 > 40) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001060_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_106 > 39) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001060_19 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_107 > 31) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_108 > 45) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_109 > 29) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_110 > 36) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_111 > 31) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_112 > 42) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_113 > 20) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_114 > 39) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001060_12 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_115 > 22) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_116 > 38) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_117 > 44) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001060_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_119 > 31) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_120 > 37) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_121 > 32) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r001060_8 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_122 > 38) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_123 > 50) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001060_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001060_8 ^ 0x2A) * 2 + pub_r001060_0) & 127;
    if (stage_v_125 > 47) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001060_7 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_126 > 34) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_127 > 21) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_128 > 45) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_129 > 36) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_130 > 36) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_131 > 27) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_132 > 29) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_133 > 36) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001060_20) & 127;
    if (stage_v_134 > 49) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001060_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_136 > 38) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_137 > 26) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001060_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001060_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_140 > 29) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001060_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_142 > 46) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001060_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001060_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_145 > 49) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001060_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001060_5) & 127;
    if (stage_v_147 > 31) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_148 > 47) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001060_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001060_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_151 > 26) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001060_20) & 127;
    if (stage_v_152 > 20) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001060_18 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_153 > 20) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001060_14) & 127;
    if (stage_v_154 > 45) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001060_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r001060_7 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_156 > 21) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001060_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_158 > 22) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_159 > 35) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001060_0) & 127;
    if (stage_v_160 > 49) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_161 > 36) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001060_0) & 127;
    if (stage_v_162 > 49) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_163 > 29) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_164 > 22) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_165 > 49) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001060_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001060_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_168 > 50) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_169 > 32) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_170 > 29) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001060_9) & 127;
    if (stage_v_171 > 46) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001060_13) & 127;
    if (stage_v_172 > 32) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_173 > 49) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_174 > 42) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001060_1 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_175 > 28) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_176 > 26) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_177 > 43) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001060_8) & 127;
    if (stage_v_178 > 24) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001060_16 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_179 > 35) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001060_5) & 127;
    if (stage_v_180 > 39) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_181 > 33) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_182 > 41) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001060_13) & 127;
    if (stage_v_183 > 33) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001060_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_185 > 25) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_186 > 26) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001060_19) & 127;
    if (stage_v_187 > 31) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001060_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001060_8) & 127;
    if (stage_v_189 > 21) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_190 > 40) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_191 > 50) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_192 > 39) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001060_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001060_21 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_195 > 24) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001060_15) & 127;
    if (stage_v_196 > 48) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_197 > 44) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r001060_3 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_198 > 38) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r001060_2 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_199 > 47) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001060_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001060_6) & 127;
    if (stage_v_201 > 37) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_202 > 20) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_203 > 30) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_204 > 40) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001060_20 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_206 > 39) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_207 > 50) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001060_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001060_16) & 127;
    if (stage_v_209 > 30) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001060_2) & 127;
    if (stage_v_210 > 39) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_211 > 20) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001060_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001060_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001060_18) & 127;
    if (stage_v_214 > 29) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_215 > 45) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_190 ^ 0x2A) * 2 + pub_r001060_20) & 127;
    if (stage_v_216 > 44) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001060_7) & 127;
    if (stage_v_217 > 27) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001060_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_206 ^ 0x2A) * 2 + pub_r001060_3) & 127;
    if (stage_v_219 > 37) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001060_17) & 127;
    if (stage_v_220 > 44) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_215 ^ 0x2A) * 2 + pub_r001060_12) & 127;
    if (stage_v_221 > 27) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001060_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001060_4) & 127;
    if (stage_v_223 > 35) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001060_10) & 127;
    if (stage_v_224 > 33) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001060_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001060_6 ^ 0x2A) * 2 + pub_r001060_5) & 127;
    if (stage_v_226 > 49) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001060_14) & 127;
    if (stage_v_227 > 50) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001060_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r001060_7 ^ 0x2A) * 2 + pub_r001060_11) & 127;
    if (stage_v_229 > 40) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001060_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001060_21) & 127;
    if (stage_v_231 > 35) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001060_20) & 127;
    if (stage_v_232 > 37) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001060_8) & 127;
    if (stage_v_233 > 22) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
