/*
 * Benchmark Program: R001626
 * Security Family: implicit_flow
 * Generator Seed: 662613
 * High Inputs: 17 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001626_2613_0 {
    int calib;
    unsigned char gain;
    unsigned char offset;
    int buffer[3];
};

struct MatrixBlock_R001626_2613_1 {
    int density;
    short stride;
    int determinant;
    unsigned char scale;
    short trace;
    int buffer[3];
};

struct DeviceConfig_R001626_2613_2 {
    short id;
    int timeout;
    short port;
    unsigned char parity;
    int stop_bits;
    int baud_rate;
    int buffer[3];
};

struct StreamBuffer_R001626_2613_3 {
    short watermark;
    int checksum;
    unsigned char head;
    unsigned char tail;
    int state;
    int buffer[3];
};

union ColorPixel_R001626_2613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001626_2613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001626_2613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001626_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_47 = (aux + st.buffer[1]) & 3;
    switch (margin_47) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_63 = local_arr[aux % 3];
    acc = (acc + window_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001626_2613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001626_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_87) & 63;
    acc ^= aux;
    int coefficient_10 = (aux + st.buffer[1]) & 3;
    switch (coefficient_10) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001626_2613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001626_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int coefficient_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_93) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_30 = local_arr[aux % 3];
    acc = (acc + quotient_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001626_2613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001626_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int threshold_16 = local_arr[aux % 3];
    acc = (acc + threshold_16 * 2) & 127;
    int segment_70 = (aux + st.buffer[1]) & 3;
    switch (segment_70) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_25 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_25 > 36) {
        acc = (acc + coefficient_25 * 2 + 5) & 127;
        aux ^= (coefficient_25 & 15);
    } else {
        acc = (acc - coefficient_25 + 11) & 127;
        aux += 3;
    }
    int margin_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001626_2613_4(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001626_2613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int checksum_34 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_34 > 50) {
        acc = (acc + checksum_34 * 2 + 5) & 127;
        aux ^= (checksum_34 & 15);
    } else {
        acc = (acc - checksum_34 + 11) & 127;
        aux += 3;
    }
    int threshold_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_64) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001626_2613_5(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001626_2613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tally_33 = 0;
    for (int k = 0; k < 3; k++) {
        tally_33 = (tally_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_33) & 127;
    }
    int mask_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001626_2613_6(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001626_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int offset_44 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_44 > 30) {
        acc = (acc + offset_44 * 2 + 5) & 127;
        aux ^= (offset_44 & 15);
    } else {
        acc = (acc - offset_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001626_2613_7(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001626_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_43 = local_arr[aux % 3];
    acc = (acc + residue_43 * 2) & 127;
    int bound_20 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_20 > 36) {
        acc = (acc + bound_20 * 2 + 5) & 127;
        aux ^= (bound_20 & 15);
    } else {
        acc = (acc - bound_20 + 11) & 127;
        aux += 3;
    }
    int stride_14 = (aux + st.buffer[1]) & 3;
    switch (stride_14) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001626_2613_8(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001626_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_13 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_13 > 45) {
        acc = (acc + accumulator_13 * 2 + 5) & 127;
        aux ^= (accumulator_13 & 15);
    } else {
        acc = (acc - accumulator_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_71 = local_arr[aux % 3];
    acc = (acc + margin_71 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_31 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_31 = (checksum_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001626_2613_9(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001626_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int segment_45 = 0;
    for (int k = 0; k < 2; k++) {
        segment_45 = (segment_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_45) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_31 = local_arr[aux % 3];
    acc = (acc + sample_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001626_2613_10(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001626_2613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_51 = local_arr[aux % 3];
    acc = (acc + stride_51 * 2) & 127;
    int parity_96 = 0;
    for (int k = 0; k < 3; k++) {
        parity_96 = (parity_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_96) & 127;
    }
    int pivot_29 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_29 > 20) {
        acc = (acc + pivot_29 * 2 + 5) & 127;
        aux ^= (pivot_29 & 15);
    } else {
        acc = (acc - pivot_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001626_2613_11(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001626_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_43 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_43 > 45) {
        acc = (acc + anchor_43 * 2 + 5) & 127;
        aux ^= (anchor_43 & 15);
    } else {
        acc = (acc - anchor_43 + 11) & 127;
        aux += 3;
    }
    int tracker_52 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_52 = (tracker_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001626_2613_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001626_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_65 = 0;
    for (int k = 0; k < 2; k++) {
        vector_65 = (vector_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001626_2613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001626_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int residue_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_95) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_23 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_23 = (coefficient_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001626_2613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001626_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_74 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_74 = (coefficient_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_74) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_30 = local_arr[aux % 3];
    acc = (acc + stride_30 * 2) & 127;
    int anchor_80 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_80 > 11) {
        acc = (acc + anchor_80 * 2 + 5) & 127;
        aux ^= (anchor_80 & 15);
    } else {
        acc = (acc - anchor_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001626_0;
    int sec_r001626_1;
    int sec_r001626_2;
    int sec_r001626_3;
    int sec_r001626_4;
    int sec_r001626_5;
    int sec_r001626_6;
    int sec_r001626_7;
    int sec_r001626_8;
    int sec_r001626_9;
    int sec_r001626_10;
    int sec_r001626_11;
    int sec_r001626_12;
    int sec_r001626_13;
    int sec_r001626_14;
    int sec_r001626_15;
    int sec_r001626_16;
    int pub_r001626_0;
    int pub_r001626_1;
    int pub_r001626_2;
    int pub_r001626_3;
    int pub_r001626_4;
    int pub_r001626_5;
    int pub_r001626_6;
    int pub_r001626_7;
    int pub_r001626_8;
    int pub_r001626_9;
    int pub_r001626_10;
    int pub_r001626_11;
    int pub_r001626_12;
    int pub_r001626_13;
    int pub_r001626_14;
    int pub_r001626_15;
    int pub_r001626_16;
    int pub_r001626_17;
    int pub_r001626_18;
    int pub_r001626_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001626_0 >= -100 && pub_r001626_0 <= 100);
    __CPROVER_assume(pub_r001626_1 >= -100 && pub_r001626_1 <= 100);
    __CPROVER_assume(pub_r001626_2 >= -100 && pub_r001626_2 <= 100);
    __CPROVER_assume(pub_r001626_3 >= -100 && pub_r001626_3 <= 100);
    __CPROVER_assume(pub_r001626_4 >= -100 && pub_r001626_4 <= 100);
    __CPROVER_assume(pub_r001626_5 >= -100 && pub_r001626_5 <= 100);
    __CPROVER_assume(pub_r001626_6 >= -100 && pub_r001626_6 <= 100);
    __CPROVER_assume(pub_r001626_7 >= -100 && pub_r001626_7 <= 100);
    __CPROVER_assume(pub_r001626_8 >= -100 && pub_r001626_8 <= 100);
    __CPROVER_assume(pub_r001626_9 >= -100 && pub_r001626_9 <= 100);
    __CPROVER_assume(pub_r001626_10 >= -100 && pub_r001626_10 <= 100);
    __CPROVER_assume(pub_r001626_11 >= -100 && pub_r001626_11 <= 100);
    __CPROVER_assume(pub_r001626_12 >= -100 && pub_r001626_12 <= 100);
    __CPROVER_assume(pub_r001626_13 >= -100 && pub_r001626_13 <= 100);
    __CPROVER_assume(pub_r001626_14 >= -100 && pub_r001626_14 <= 100);
    __CPROVER_assume(pub_r001626_15 >= -100 && pub_r001626_15 <= 100);
    __CPROVER_assume(pub_r001626_16 >= -100 && pub_r001626_16 <= 100);
    __CPROVER_assume(pub_r001626_17 >= -100 && pub_r001626_17 <= 100);
    __CPROVER_assume(pub_r001626_18 >= -100 && pub_r001626_18 <= 100);
    __CPROVER_assume(pub_r001626_19 >= -100 && pub_r001626_19 <= 100);
    __CPROVER_assume(sec_r001626_0 >= 0 && sec_r001626_0 <= 255);
    __CPROVER_assume(sec_r001626_1 >= 0 && sec_r001626_1 <= 255);
    __CPROVER_assume(sec_r001626_2 >= 0 && sec_r001626_2 <= 255);
    __CPROVER_assume(sec_r001626_3 >= 0 && sec_r001626_3 <= 255);
    __CPROVER_assume(sec_r001626_4 >= 0 && sec_r001626_4 <= 255);
    __CPROVER_assume(sec_r001626_5 >= 0 && sec_r001626_5 <= 255);
    __CPROVER_assume(sec_r001626_6 >= 0 && sec_r001626_6 <= 255);
    __CPROVER_assume(sec_r001626_7 >= 0 && sec_r001626_7 <= 255);
    __CPROVER_assume(sec_r001626_8 >= 0 && sec_r001626_8 <= 255);
    __CPROVER_assume(sec_r001626_9 >= 0 && sec_r001626_9 <= 255);
    __CPROVER_assume(sec_r001626_10 >= 0 && sec_r001626_10 <= 255);
    __CPROVER_assume(sec_r001626_11 >= 0 && sec_r001626_11 <= 255);
    __CPROVER_assume(sec_r001626_12 >= 0 && sec_r001626_12 <= 255);
    __CPROVER_assume(sec_r001626_13 >= 0 && sec_r001626_13 <= 255);
    __CPROVER_assume(sec_r001626_14 >= 0 && sec_r001626_14 <= 255);
    __CPROVER_assume(sec_r001626_15 >= 0 && sec_r001626_15 <= 255);
    __CPROVER_assume(sec_r001626_16 >= 0 && sec_r001626_16 <= 255);

    struct SensorNode_R001626_2613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001626_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001626_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001626_0 + 7) & 15;
    struct MatrixBlock_R001626_2613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001626_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001626_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001626_0 + 9) & 15;
    struct DeviceConfig_R001626_2613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001626_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001626_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001626_0 + 11) & 15;
    struct StreamBuffer_R001626_2613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001626_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001626_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001626_0 + 13) & 15;

    union ColorPixel_R001626_2613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001626_2613_0(sec_r001626_0, sec_r001626_1, pub_r001626_2, pub_r001626_3, pub_r001626_4);
    int helper_flow_1 = fn_R001626_2613_1(sec_r001626_1, sec_r001626_2, pub_r001626_3, pub_r001626_4, pub_r001626_5);
    int helper_flow_2 = fn_R001626_2613_2(sec_r001626_2, sec_r001626_3, pub_r001626_4, pub_r001626_5);
    int helper_flow_3 = fn_R001626_2613_3(sec_r001626_3, sec_r001626_4, pub_r001626_5, pub_r001626_6, pub_r001626_7);
    int helper_flow_4 = fn_R001626_2613_4(sec_r001626_4, sec_r001626_5);
    int helper_flow_5 = fn_R001626_2613_5(sec_r001626_5, pub_r001626_6);
    int helper_flow_6 = fn_R001626_2613_6(sec_r001626_6, pub_r001626_7, pub_r001626_8);
    int helper_flow_7 = fn_R001626_2613_7(sec_r001626_7, sec_r001626_8);
    int helper_flow_8 = fn_R001626_2613_8(sec_r001626_8, sec_r001626_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001626_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001626_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001626_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001626_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_8 + pub_r001626_3 * 2 + 17) & 127;
    if (stage_v_4 > 32) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001626_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001626_11 + pub_r001626_12 * 2 + 23) & 127;
    if (stage_v_6 > 52) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_6 + pub_r001626_15 * 2 + 26) & 127;
    if (stage_v_7 > 34) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001626_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001626_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_2 + pub_r001626_3 * 2 + 35) & 127;
    if (stage_v_10 > 47) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001626_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001626_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_3 + pub_r001626_10 * 2 + 44) & 127;
    if (stage_v_13 > 16) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001626_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_5 + pub_r001626_19 * 2 + 50) & 127;
    if (stage_v_15 > 20) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_6 + pub_r001626_1 * 2 + 53) & 127;
    if (stage_v_16 > 58) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_13 + pub_r001626_18 * 2 + 56) & 127;
    if (stage_v_17 > 33) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001626_11 + pub_r001626_12 * 2 + 59) & 127;
    if (stage_v_18 > 35) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_7 + pub_r001626_16 * 2 + 62) & 127;
    if (stage_v_19 > 39) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_4 + pub_r001626_8 * 2 + 65) & 127;
    if (stage_v_20 > 37) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001626_0 + pub_r001626_10 * 2 + 68) & 127;
    if (stage_v_21 > 41) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001626_0 + pub_r001626_16 * 2 + 71) & 127;
    if (stage_v_22 > 31) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001626_5 + pub_r001626_15 * 2 + 74) & 127;
    if (stage_v_23 > 30) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001626_9 + pub_r001626_3 * 2 + 77) & 127;
    if (stage_v_24 > 19) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001626_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001626_9 + pub_r001626_5 * 2 + 83) & 127;
    if (stage_v_26 > 58) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001626_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (helper_flow_8 + pub_r001626_19 * 2 + 89) & 127;
    if (stage_v_28 > 20) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001626_5 + pub_r001626_6 * 2 + 92) & 127;
    if (stage_v_29 > 45) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_6 + pub_r001626_1 * 2 + 95) & 127;
    if (stage_v_30 > 57) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001626_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001626_14 + pub_r001626_18 * 2 + 101) & 127;
    if (stage_v_32 > 17) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_20 + pub_r001626_8 * 2 + 104) & 127;
    if (stage_v_33 > 55) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001626_9 + pub_r001626_1 * 2 + 107) & 127;
    if (stage_v_34 > 26) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001626_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_4 + pub_r001626_17 * 2 + 113) & 127;
    if (stage_v_36 > 25) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001626_0 + pub_r001626_16 * 2 + 116) & 127;
    if (stage_v_37 > 54) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001626_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001626_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001626_16 + pub_r001626_12 * 2 + 125) & 127;
    if (stage_v_40 > 16) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001626_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_1 + pub_r001626_1 * 2 + 131) & 127;
    if (stage_v_42 > 49) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001626_15 + pub_r001626_12 * 2 + 134) & 127;
    if (stage_v_43 > 38) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001626_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001626_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_20 + pub_r001626_12 * 2 + 143) & 127;
    if (stage_v_46 > 60) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001626_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_8 + pub_r001626_11 * 2 + 149) & 127;
    if (stage_v_48 > 22) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001626_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001626_3 + pub_r001626_4 * 2 + 155) & 127;
    if (stage_v_50 > 33) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001626_9 + pub_r001626_15 * 2 + 158) & 127;
    if (stage_v_51 > 49) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (helper_flow_8 + pub_r001626_18 * 2 + 161) & 127;
    if (stage_v_52 > 25) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001626_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_43 + pub_r001626_9 * 2 + 167) & 127;
    if (stage_v_54 > 21) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_21 + pub_r001626_18 * 2 + 170) & 127;
    if (stage_v_55 > 32) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001626_15 + pub_r001626_4 * 2 + 173) & 127;
    if (stage_v_56 > 30) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001626_7 + pub_r001626_12 * 2 + 176) & 127;
    if (stage_v_57 > 23) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_23 + pub_r001626_3 * 2 + 179) & 127;
    if (stage_v_58 > 32) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_16 + pub_r001626_8 * 2 + 182) & 127;
    if (stage_v_59 > 42) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001626_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001626_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r001626_14 + pub_r001626_3 * 2 + 191) & 127;
    if (stage_v_62 > 34) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_20 + pub_r001626_18 * 2 + 194) & 127;
    if (stage_v_63 > 45) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001626_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_57 + pub_r001626_15 * 2 + 200) & 127;
    if (stage_v_65 > 30) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001626_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001626_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001626_8 + pub_r001626_18 * 2 + 209) & 127;
    if (stage_v_68 > 27) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001626_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001626_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001626_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_6 + pub_r001626_18 * 2 + 221) & 127;
    if (stage_v_72 > 43) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001626_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_5 + pub_r001626_14 * 2 + 227) & 127;
    if (stage_v_74 > 22) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001626_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_50 + pub_r001626_7 * 2 + 233) & 127;
    if (stage_v_76 > 34) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_4 + pub_r001626_17 * 2 + 236) & 127;
    if (stage_v_77 > 31) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001626_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001626_14 + pub_r001626_13 * 2 + 242) & 127;
    if (stage_v_79 > 28) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001626_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001626_3 + pub_r001626_3 * 2 + 248) & 127;
    if (stage_v_81 > 23) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_76 + pub_r001626_4 * 2 + 251) & 127;
    if (stage_v_82 > 47) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_10 + pub_r001626_4 * 2 + 254) & 127;
    if (stage_v_83 > 38) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001626_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001626_5 + pub_r001626_8 * 2 + 260) & 127;
    if (stage_v_85 > 23) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (helper_flow_7 + pub_r001626_18 * 2 + 263) & 127;
    if (stage_v_86 > 38) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_46 + pub_r001626_8 * 2 + 266) & 127;
    if (stage_v_87 > 30) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001626_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001626_16 + pub_r001626_11 * 2 + 272) & 127;
    if (stage_v_89 > 57) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001626_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001626_0 + pub_r001626_6 * 2 + 278) & 127;
    if (stage_v_91 > 44) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_22 + pub_r001626_19 * 2 + 281) & 127;
    if (stage_v_92 > 49) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001626_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001626_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_8 + pub_r001626_8 * 2 + 290) & 127;
    if (stage_v_95 > 17) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (helper_flow_7 + pub_r001626_1 * 2 + 293) & 127;
    if (stage_v_96 > 35) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001626_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_46 + pub_r001626_2 * 2 + 299) & 127;
    if (stage_v_98 > 21) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_83 + pub_r001626_11 * 2 + 302) & 127;
    if (stage_v_99 > 44) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_36 + pub_r001626_4 * 2 + 305) & 127;
    if (stage_v_100 > 23) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001626_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r001626_2 + pub_r001626_13 * 2 + 311) & 127;
    if (stage_v_102 > 21) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001626_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001626_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_48 + pub_r001626_0 * 2 + 320) & 127;
    if (stage_v_105 > 28) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (sec_r001626_12 + pub_r001626_0 * 2 + 323) & 127;
    if (stage_v_106 > 23) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (sec_r001626_10 + pub_r001626_0 * 2 + 326) & 127;
    if (stage_v_107 > 24) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r001626_10 + pub_r001626_8 * 2 + 329) & 127;
    if (stage_v_108 > 48) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001626_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001626_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001626_5 + pub_r001626_1 * 2 + 338) & 127;
    if (stage_v_111 > 34) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_32 + pub_r001626_7 * 2 + 341) & 127;
    if (stage_v_112 > 55) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_55 + pub_r001626_15 * 2 + 344) & 127;
    if (stage_v_113 > 20) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_46 + pub_r001626_3 * 2 + 347) & 127;
    if (stage_v_114 > 16) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_86 + pub_r001626_1 * 2 + 350) & 127;
    if (stage_v_115 > 31) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_96 + pub_r001626_1 * 2 + 353) & 127;
    if (stage_v_116 > 58) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001626_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001626_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001626_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001626_12 + pub_r001626_19 * 2 + 365) & 127;
    if (stage_v_120 > 60) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (sec_r001626_2 + pub_r001626_0 * 2 + 368) & 127;
    if (stage_v_121 > 19) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_22 + pub_r001626_10 * 2 + 371) & 127;
    if (stage_v_122 > 56) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001626_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_54 + pub_r001626_17 * 2 + 377) & 127;
    if (stage_v_124 > 25) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001626_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (sec_r001626_15 + pub_r001626_17 * 2 + 383) & 127;
    if (stage_v_126 > 41) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001626_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001626_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_81 + pub_r001626_5 * 2 + 392) & 127;
    if (stage_v_129 > 16) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_100 + pub_r001626_15 * 2 + 395) & 127;
    if (stage_v_130 > 24) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_63 + pub_r001626_19 * 2 + 398) & 127;
    if (stage_v_131 > 22) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_22 + pub_r001626_16 * 2 + 401) & 127;
    if (stage_v_132 > 56) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_15 + pub_r001626_10 * 2 + 404) & 127;
    if (stage_v_133 > 33) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001626_1 + pub_r001626_7 * 2 + 407) & 127;
    if (stage_v_134 > 51) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001626_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_13 + pub_r001626_11 * 2 + 413) & 127;
    if (stage_v_136 > 24) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_63 + pub_r001626_17 * 2 + 416) & 127;
    if (stage_v_137 > 49) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_89 + pub_r001626_2 * 2 + 419) & 127;
    if (stage_v_138 > 34) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_36 + pub_r001626_5 * 2 + 422) & 127;
    if (stage_v_139 > 17) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001626_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_85 + pub_r001626_4 * 2 + 428) & 127;
    if (stage_v_141 > 49) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001626_10 + pub_r001626_13 * 2 + 431) & 127;
    if (stage_v_142 > 26) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_95 + pub_r001626_15 * 2 + 434) & 127;
    if (stage_v_143 > 32) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_111 + pub_r001626_17 * 2 + 437) & 127;
    if (stage_v_144 > 24) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_17 + pub_r001626_15 * 2 + 440) & 127;
    if (stage_v_145 > 54) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_15 + pub_r001626_9 * 2 + 443) & 127;
    if (stage_v_146 > 30) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_100 + pub_r001626_1 * 2 + 446) & 127;
    if (stage_v_147 > 35) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001626_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_112 + pub_r001626_0 * 2 + 452) & 127;
    if (stage_v_149 > 46) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_105 + pub_r001626_8 * 2 + 455) & 127;
    if (stage_v_150 > 35) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001626_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_114 + pub_r001626_16 * 2 + 461) & 127;
    if (stage_v_152 > 19) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_92 + pub_r001626_8 * 2 + 464) & 127;
    if (stage_v_153 > 39) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_91 + pub_r001626_7 * 2 + 467) & 127;
    if (stage_v_154 > 48) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_15 + pub_r001626_10 * 2 + 470) & 127;
    if (stage_v_155 > 32) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_100 + pub_r001626_16 * 2 + 473) & 127;
    if (stage_v_156 > 26) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_22 + pub_r001626_6 * 2 + 476) & 127;
    if (stage_v_157 > 21) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_72 + pub_r001626_6 * 2 + 479) & 127;
    if (stage_v_158 > 42) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_156 + pub_r001626_17 * 2 + 482) & 127;
    if (stage_v_159 > 40) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_95 + pub_r001626_9 * 2 + 485) & 127;
    if (stage_v_160 > 24) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001626_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001626_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (helper_flow_6 + pub_r001626_1 * 2 + 494) & 127;
    if (stage_v_163 > 53) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_55 + pub_r001626_16 * 2 + 497) & 127;
    if (stage_v_164 > 49) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_10 + pub_r001626_4 * 2 + 500) & 127;
    if (stage_v_165 > 18) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001626_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_155 + pub_r001626_13 * 2 + 506) & 127;
    if (stage_v_167 > 51) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_144 + pub_r001626_2 * 2 + 509) & 127;
    if (stage_v_168 > 20) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_54 + pub_r001626_18 * 2 + 512) & 127;
    if (stage_v_169 > 60) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (helper_flow_8 + pub_r001626_14 * 2 + 515) & 127;
    if (stage_v_170 > 46) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_62 + pub_r001626_1 * 2 + 518) & 127;
    if (stage_v_171 > 36) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_144 + pub_r001626_14 * 2 + 521) & 127;
    if (stage_v_172 > 46) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001626_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_100 + pub_r001626_8 * 2 + 527) & 127;
    if (stage_v_174 > 46) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001626_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001626_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001626_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001626_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_156 + pub_r001626_14 * 2 + 542) & 127;
    if (stage_v_179 > 43) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_146 + pub_r001626_14 * 2 + 545) & 127;
    if (stage_v_180 > 21) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_6 + pub_r001626_6 * 2 + 548) & 127;
    if (stage_v_181 > 45) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (sec_r001626_2 + pub_r001626_1 * 2 + 551) & 127;
    if (stage_v_182 > 15) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001626_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001626_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_143 + pub_r001626_10 * 2 + 560) & 127;
    if (stage_v_185 > 57) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_153 + pub_r001626_8 * 2 + 563) & 127;
    if (stage_v_186 > 39) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (helper_flow_6 + pub_r001626_0 * 2 + 566) & 127;
    if (stage_v_187 > 43) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001626_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_130 + pub_r001626_11 * 2 + 572) & 127;
    if (stage_v_189 > 27) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001626_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (sec_r001626_15 + pub_r001626_6 * 2 + 578) & 127;
    if (stage_v_191 > 48) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001626_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_122 + pub_r001626_12 * 2 + 584) & 127;
    if (stage_v_193 > 38) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (helper_flow_2 + pub_r001626_9 * 2 + 587) & 127;
    if (stage_v_194 > 18) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001626_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_143 + pub_r001626_1 * 2 + 593) & 127;
    if (stage_v_196 > 44) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_107 + pub_r001626_3 * 2 + 596) & 127;
    if (stage_v_197 > 52) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_146 + pub_r001626_3 * 2 + 599) & 127;
    if (stage_v_198 > 28) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_145 + pub_r001626_4 * 2 + 602) & 127;
    if (stage_v_199 > 42) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_149 + pub_r001626_11 * 2 + 605) & 127;
    if (stage_v_200 > 43) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_194 + pub_r001626_10 * 2 + 608) & 127;
    if (stage_v_201 > 36) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_156 + pub_r001626_8 * 2 + 611) & 127;
    if (stage_v_202 > 33) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_169 + pub_r001626_10 * 2 + 614) & 127;
    if (stage_v_203 > 30) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001626_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001626_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_37 + pub_r001626_1 * 2 + 623) & 127;
    if (stage_v_206 > 26) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r001626_9 + pub_r001626_12 * 2 + 626) & 127;
    if (stage_v_207 > 51) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_13 + pub_r001626_9 * 2 + 629) & 127;
    if (stage_v_208 > 17) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_134 + pub_r001626_0 * 2 + 632) & 127;
    if (stage_v_209 > 39) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (sec_r001626_12 + pub_r001626_13 * 2 + 635) & 127;
    if (stage_v_210 > 27) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (helper_flow_3 + pub_r001626_6 * 2 + 638) & 127;
    if (stage_v_211 > 53) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001626_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_34 + pub_r001626_19 * 2 + 644) & 127;
    if (stage_v_213 > 22) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001626_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001626_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001626_19 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_51 + pub_r001626_11 * 2 + 656) & 127;
    if (stage_v_217 > 20) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001626_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001626_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001626_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_74 + pub_r001626_19 * 2 + 668) & 127;
    if (stage_v_221 > 47) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (helper_flow_3 + pub_r001626_10 * 2 + 671) & 127;
    if (stage_v_222 > 19) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_92 + pub_r001626_1 * 2 + 674) & 127;
    if (stage_v_223 > 36) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_77 + pub_r001626_16 * 2 + 677) & 127;
    if (stage_v_224 > 35) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001626_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_114 + pub_r001626_13 * 2 + 683) & 127;
    if (stage_v_226 > 29) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_196 + pub_r001626_4 * 2 + 686) & 127;
    if (stage_v_227 > 48) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001626_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_171 + pub_r001626_6 * 2 + 692) & 127;
    if (stage_v_229 > 60) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (sec_r001626_1 + pub_r001626_19 * 2 + 695) & 127;
    if (stage_v_230 > 39) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001626_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (sec_r001626_2 + pub_r001626_19 * 2 + 701) & 127;
    if (stage_v_232 > 28) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_112 + pub_r001626_3 * 2 + 704) & 127;
    if (stage_v_233 > 50) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001626_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_142 + pub_r001626_3 * 2 + 710) & 127;
    if (stage_v_235 > 53) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_158 + pub_r001626_4 * 2 + 713) & 127;
    if (stage_v_236 > 16) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_155 + pub_r001626_19 * 2 + 716) & 127;
    if (stage_v_237 > 57) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_121 + pub_r001626_18 * 2 + 719) & 127;
    if (stage_v_238 > 37) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001626_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001626_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_179 + pub_r001626_12 * 2 + 728) & 127;
    if (stage_v_241 > 32) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_167 + pub_r001626_3 * 2 + 731) & 127;
    if (stage_v_242 > 20) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001626_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001626_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001626_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001626_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001626_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001626_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001626_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_98 + pub_r001626_7 * 2 + 755) & 127;
    if (stage_v_250 > 29) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
        sec_accum ^= (stage_v_250 & 31);
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (helper_flow_3 + pub_r001626_14 * 2 + 758) & 127;
    if (stage_v_251 > 18) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_111 + pub_r001626_8 * 2 + 761) & 127;
    if (stage_v_252 > 30) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
        sec_accum ^= (stage_v_252 & 31);
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_37 + pub_r001626_14 * 2 + 764) & 127;
    if (stage_v_253 > 47) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_179 + pub_r001626_8 * 2 + 767) & 127;
    if (stage_v_254 > 23) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
        sec_accum ^= (stage_v_254 & 31);
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (stage_v_237 + pub_r001626_7 * 2 + 770) & 127;
    if (stage_v_255 > 48) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
        sec_accum ^= (stage_v_255 & 31);
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
