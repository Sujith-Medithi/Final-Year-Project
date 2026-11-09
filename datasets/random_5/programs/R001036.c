/*
 * Benchmark Program: R001036
 * Security Family: implicit_flow
 * Generator Seed: 603613
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001036_3613_0 {
    int coord_z;
    int pitch;
    int coord_y;
    int norm_sq;
    short coord_x;
    int heading;
    int buffer[3];
};

struct MatrixBlock_R001036_3613_1 {
    int determinant;
    int stride;
    int dim;
    int buffer[3];
};

struct SensorNode_R001036_3613_2 {
    short gain;
    int offset;
    int calib;
    int buffer[3];
};

struct FilterState_R001036_3613_3 {
    short mode;
    int damping;
    int cutoff;
    int prev_in;
    int prev_out;
    int buffer[3];
};

union RegisterBank_R001036_3613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001036_3613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001036_3613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001036_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int vector_59 = 0;
    for (int k = 0; k < 2; k++) {
        vector_59 = (vector_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_59) & 127;
    }
    int checksum_62 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_62 > 46) {
        acc = (acc + checksum_62 * 2 + 5) & 127;
        aux ^= (checksum_62 & 15);
    } else {
        acc = (acc - checksum_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_1(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001036_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int quantum_58 = local_arr[aux % 3];
    acc = (acc + quantum_58 * 2) & 127;
    int residue_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001036_3613_2(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001036_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int stride_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_80) & 63;
    acc ^= aux;
    int threshold_94 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_94 > 23) {
        acc = (acc + threshold_94 * 2 + 5) & 127;
        aux ^= (threshold_94 & 15);
    } else {
        acc = (acc - threshold_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001036_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int sample_98 = local_arr[aux % 3];
    acc = (acc + sample_98 * 2) & 127;
    int margin_26 = 0;
    for (int k = 0; k < 2; k++) {
        margin_26 = (margin_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_26) & 127;
    }
    int quantum_17 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_17 > 36) {
        acc = (acc + quantum_17 * 2 + 5) & 127;
        aux ^= (quantum_17 & 15);
    } else {
        acc = (acc - quantum_17 + 11) & 127;
        aux += 3;
    }
    int window_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001036_3613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001036_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quotient_78 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_78 > 25) {
        acc = (acc + quotient_78 * 2 + 5) & 127;
        aux ^= (quotient_78 & 15);
    } else {
        acc = (acc - quotient_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_83 = local_arr[aux % 3];
    acc = (acc + factor_83 * 2) & 127;
    int scale_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001036_3613_5(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001036_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int index_reg_43 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_43 > 46) {
        acc = (acc + index_reg_43 * 2 + 5) & 127;
        aux ^= (index_reg_43 & 15);
    } else {
        acc = (acc - index_reg_43 + 11) & 127;
        aux += 3;
    }
    int pivot_69 = (aux + st.buffer[1]) & 3;
    switch (pivot_69) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001036_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int metric_86 = 0;
    for (int k = 0; k < 2; k++) {
        metric_86 = (metric_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_86) & 127;
    }
    int residue_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_45) & 63;
    acc ^= aux;
    int delta_14 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_14 > 27) {
        acc = (acc + delta_14 * 2 + 5) & 127;
        aux ^= (delta_14 & 15);
    } else {
        acc = (acc - delta_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001036_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_50 = 0;
    for (int k = 0; k < 3; k++) {
        offset_50 = (offset_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_50) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_8(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001036_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int anchor_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_36) & 63;
    acc ^= aux;
    int tally_77 = 0;
    for (int k = 0; k < 2; k++) {
        tally_77 = (tally_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_77) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_9(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001036_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_51 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_51 > 44) {
        acc = (acc + weight_51 * 2 + 5) & 127;
        aux ^= (weight_51 & 15);
    } else {
        acc = (acc - weight_51 + 11) & 127;
        aux += 3;
    }
    int weight_40 = 0;
    for (int k = 0; k < 3; k++) {
        weight_40 = (weight_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001036_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_44 = 0;
    for (int k = 0; k < 3; k++) {
        metric_44 = (metric_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_44) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_82 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_82 > 19) {
        acc = (acc + mask_82 * 2 + 5) & 127;
        aux ^= (mask_82 & 15);
    } else {
        acc = (acc - mask_82 + 11) & 127;
        aux += 3;
    }
    int offset_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001036_3613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001036_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int coefficient_62 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_62 = (coefficient_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_62) & 127;
    }
    int anchor_94 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_94 > 17) {
        acc = (acc + anchor_94 * 2 + 5) & 127;
        aux ^= (anchor_94 & 15);
    } else {
        acc = (acc - anchor_94 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001036_3613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001036_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int factor_64 = local_arr[aux % 3];
    acc = (acc + factor_64 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_42 = 0;
    for (int k = 0; k < 2; k++) {
        damping_42 = (damping_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001036_3613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001036_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int pivot_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_50) & 63;
    acc ^= aux;
    int scale_69 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_69 > 33) {
        acc = (acc + scale_69 * 2 + 5) & 127;
        aux ^= (scale_69 & 15);
    } else {
        acc = (acc - scale_69 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001036_3613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001036_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_24 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_24 > 40) {
        acc = (acc + coefficient_24 * 2 + 5) & 127;
        aux ^= (coefficient_24 & 15);
    } else {
        acc = (acc - coefficient_24 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_75 = local_arr[aux % 3];
    acc = (acc + sample_75 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001036_0;
    int sec_r001036_1;
    int sec_r001036_2;
    int sec_r001036_3;
    int sec_r001036_4;
    int sec_r001036_5;
    int sec_r001036_6;
    int sec_r001036_7;
    int sec_r001036_8;
    int sec_r001036_9;
    int sec_r001036_10;
    int sec_r001036_11;
    int sec_r001036_12;
    int sec_r001036_13;
    int sec_r001036_14;
    int sec_r001036_15;
    int sec_r001036_16;
    int sec_r001036_17;
    int sec_r001036_18;
    int pub_r001036_0;
    int pub_r001036_1;
    int pub_r001036_2;
    int pub_r001036_3;
    int pub_r001036_4;
    int pub_r001036_5;
    int pub_r001036_6;
    int pub_r001036_7;
    int pub_r001036_8;
    int pub_r001036_9;
    int pub_r001036_10;
    int pub_r001036_11;
    int pub_r001036_12;
    int pub_r001036_13;
    int pub_r001036_14;
    int pub_r001036_15;
    int pub_r001036_16;
    int pub_r001036_17;
    int pub_r001036_18;
    int pub_r001036_19;
    int pub_r001036_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001036_0 >= -100 && pub_r001036_0 <= 100);
    __CPROVER_assume(pub_r001036_1 >= -100 && pub_r001036_1 <= 100);
    __CPROVER_assume(pub_r001036_2 >= -100 && pub_r001036_2 <= 100);
    __CPROVER_assume(pub_r001036_3 >= -100 && pub_r001036_3 <= 100);
    __CPROVER_assume(pub_r001036_4 >= -100 && pub_r001036_4 <= 100);
    __CPROVER_assume(pub_r001036_5 >= -100 && pub_r001036_5 <= 100);
    __CPROVER_assume(pub_r001036_6 >= -100 && pub_r001036_6 <= 100);
    __CPROVER_assume(pub_r001036_7 >= -100 && pub_r001036_7 <= 100);
    __CPROVER_assume(pub_r001036_8 >= -100 && pub_r001036_8 <= 100);
    __CPROVER_assume(pub_r001036_9 >= -100 && pub_r001036_9 <= 100);
    __CPROVER_assume(pub_r001036_10 >= -100 && pub_r001036_10 <= 100);
    __CPROVER_assume(pub_r001036_11 >= -100 && pub_r001036_11 <= 100);
    __CPROVER_assume(pub_r001036_12 >= -100 && pub_r001036_12 <= 100);
    __CPROVER_assume(pub_r001036_13 >= -100 && pub_r001036_13 <= 100);
    __CPROVER_assume(pub_r001036_14 >= -100 && pub_r001036_14 <= 100);
    __CPROVER_assume(pub_r001036_15 >= -100 && pub_r001036_15 <= 100);
    __CPROVER_assume(pub_r001036_16 >= -100 && pub_r001036_16 <= 100);
    __CPROVER_assume(pub_r001036_17 >= -100 && pub_r001036_17 <= 100);
    __CPROVER_assume(pub_r001036_18 >= -100 && pub_r001036_18 <= 100);
    __CPROVER_assume(pub_r001036_19 >= -100 && pub_r001036_19 <= 100);
    __CPROVER_assume(pub_r001036_20 >= -100 && pub_r001036_20 <= 100);
    __CPROVER_assume(sec_r001036_0 >= 0 && sec_r001036_0 <= 255);
    __CPROVER_assume(sec_r001036_1 >= 0 && sec_r001036_1 <= 255);
    __CPROVER_assume(sec_r001036_2 >= 0 && sec_r001036_2 <= 255);
    __CPROVER_assume(sec_r001036_3 >= 0 && sec_r001036_3 <= 255);
    __CPROVER_assume(sec_r001036_4 >= 0 && sec_r001036_4 <= 255);
    __CPROVER_assume(sec_r001036_5 >= 0 && sec_r001036_5 <= 255);
    __CPROVER_assume(sec_r001036_6 >= 0 && sec_r001036_6 <= 255);
    __CPROVER_assume(sec_r001036_7 >= 0 && sec_r001036_7 <= 255);
    __CPROVER_assume(sec_r001036_8 >= 0 && sec_r001036_8 <= 255);
    __CPROVER_assume(sec_r001036_9 >= 0 && sec_r001036_9 <= 255);
    __CPROVER_assume(sec_r001036_10 >= 0 && sec_r001036_10 <= 255);
    __CPROVER_assume(sec_r001036_11 >= 0 && sec_r001036_11 <= 255);
    __CPROVER_assume(sec_r001036_12 >= 0 && sec_r001036_12 <= 255);
    __CPROVER_assume(sec_r001036_13 >= 0 && sec_r001036_13 <= 255);
    __CPROVER_assume(sec_r001036_14 >= 0 && sec_r001036_14 <= 255);
    __CPROVER_assume(sec_r001036_15 >= 0 && sec_r001036_15 <= 255);
    __CPROVER_assume(sec_r001036_16 >= 0 && sec_r001036_16 <= 255);
    __CPROVER_assume(sec_r001036_17 >= 0 && sec_r001036_17 <= 255);
    __CPROVER_assume(sec_r001036_18 >= 0 && sec_r001036_18 <= 255);

    struct Vector3D_R001036_3613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001036_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001036_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001036_0 + 7) & 15;
    struct MatrixBlock_R001036_3613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001036_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001036_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001036_0 + 9) & 15;
    struct SensorNode_R001036_3613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001036_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001036_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001036_0 + 11) & 15;
    struct FilterState_R001036_3613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001036_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001036_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001036_0 + 13) & 15;

    union RegisterBank_R001036_3613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001036_3613_0(sec_r001036_0, pub_r001036_1, pub_r001036_2, pub_r001036_3, pub_r001036_4);
    int helper_flow_1 = fn_R001036_3613_1(sec_r001036_1, pub_r001036_2, pub_r001036_3);
    int helper_flow_2 = fn_R001036_3613_2(sec_r001036_2, pub_r001036_3, pub_r001036_4);
    int helper_flow_3 = fn_R001036_3613_3(sec_r001036_3, pub_r001036_4, pub_r001036_5, pub_r001036_6);
    int helper_flow_4 = fn_R001036_3613_4(sec_r001036_4, pub_r001036_5, pub_r001036_6, pub_r001036_7, pub_r001036_8);
    int helper_flow_5 = fn_R001036_3613_5(sec_r001036_5, pub_r001036_6, pub_r001036_7);
    int helper_flow_6 = fn_R001036_3613_6(sec_r001036_6, pub_r001036_7, pub_r001036_8, pub_r001036_9);
    int helper_flow_7 = fn_R001036_3613_7(sec_r001036_7, pub_r001036_8, pub_r001036_9, pub_r001036_10);
    int helper_flow_8 = fn_R001036_3613_8(sec_r001036_8, pub_r001036_9, pub_r001036_10);
    int helper_flow_9 = fn_R001036_3613_9(sec_r001036_9, pub_r001036_10, pub_r001036_11);
    int helper_flow_10 = fn_R001036_3613_10(sec_r001036_10, pub_r001036_11, pub_r001036_12, pub_r001036_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001036_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001036_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001036_7 + pub_r001036_12 * 2 + 11) & 127;
    if (stage_v_2 > 60) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001036_6 + pub_r001036_18 * 2 + 14) & 127;
    if (stage_v_3 > 45) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001036_16 + pub_r001036_5 * 2 + 17) & 127;
    if (stage_v_4 > 53) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001036_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001036_3 + pub_r001036_1 * 2 + 23) & 127;
    if (stage_v_6 > 53) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_3 + pub_r001036_8 * 2 + 26) & 127;
    if (stage_v_7 > 48) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_2 + pub_r001036_0 * 2 + 29) & 127;
    if (stage_v_8 > 41) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001036_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_4 + pub_r001036_5 * 2 + 35) & 127;
    if (stage_v_10 > 24) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_10 + pub_r001036_6 * 2 + 38) & 127;
    if (stage_v_11 > 41) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001036_12 + pub_r001036_7 * 2 + 41) & 127;
    if (stage_v_12 > 22) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001036_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_5 + pub_r001036_3 * 2 + 47) & 127;
    if (stage_v_14 > 50) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_3 + pub_r001036_10 * 2 + 50) & 127;
    if (stage_v_15 > 52) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001036_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001036_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001036_11 + pub_r001036_12 * 2 + 59) & 127;
    if (stage_v_18 > 24) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001036_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001036_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_7 + pub_r001036_17 * 2 + 68) & 127;
    if (stage_v_21 > 29) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_3 + pub_r001036_11 * 2 + 71) & 127;
    if (stage_v_22 > 15) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001036_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001036_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_4 + pub_r001036_16 * 2 + 80) & 127;
    if (stage_v_25 > 36) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001036_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001036_11 + pub_r001036_3 * 2 + 86) & 127;
    if (stage_v_27 > 55) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001036_4 + pub_r001036_9 * 2 + 89) & 127;
    if (stage_v_28 > 32) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001036_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001036_0 + pub_r001036_12 * 2 + 95) & 127;
    if (stage_v_30 > 58) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001036_12 + pub_r001036_3 * 2 + 98) & 127;
    if (stage_v_31 > 38) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001036_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_3 + pub_r001036_2 * 2 + 104) & 127;
    if (stage_v_33 > 29) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_33 + pub_r001036_19 * 2 + 107) & 127;
    if (stage_v_34 > 26) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_3 + pub_r001036_5 * 2 + 110) & 127;
    if (stage_v_35 > 55) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_12 + pub_r001036_0 * 2 + 113) & 127;
    if (stage_v_36 > 41) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001036_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001036_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_25 + pub_r001036_4 * 2 + 122) & 127;
    if (stage_v_39 > 39) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001036_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_15 + pub_r001036_13 * 2 + 128) & 127;
    if (stage_v_41 > 44) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_8 + pub_r001036_8 * 2 + 131) & 127;
    if (stage_v_42 > 28) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001036_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_39 + pub_r001036_16 * 2 + 137) & 127;
    if (stage_v_44 > 20) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001036_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (helper_flow_0 + pub_r001036_8 * 2 + 143) & 127;
    if (stage_v_46 > 18) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001036_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_4 + pub_r001036_2 * 2 + 149) & 127;
    if (stage_v_48 > 57) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001036_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_18 + pub_r001036_8 * 2 + 155) & 127;
    if (stage_v_50 > 19) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_21 + pub_r001036_17 * 2 + 158) & 127;
    if (stage_v_51 > 33) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (helper_flow_2 + pub_r001036_15 * 2 + 161) & 127;
    if (stage_v_52 > 59) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001036_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001036_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001036_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_15 + pub_r001036_6 * 2 + 173) & 127;
    if (stage_v_56 > 49) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001036_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_8 + pub_r001036_5 * 2 + 179) & 127;
    if (stage_v_58 > 21) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001036_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_27 + pub_r001036_12 * 2 + 185) & 127;
    if (stage_v_60 > 50) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001036_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r001036_14 + pub_r001036_19 * 2 + 191) & 127;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001036_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_6 + pub_r001036_4 * 2 + 197) & 127;
    if (stage_v_64 > 44) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_35 + pub_r001036_4 * 2 + 200) & 127;
    if (stage_v_65 > 33) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001036_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001036_15 + pub_r001036_7 * 2 + 206) & 127;
    if (stage_v_67 > 55) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001036_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001036_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001036_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001036_6 + pub_r001036_12 * 2 + 218) & 127;
    if (stage_v_71 > 54) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001036_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001036_14 + pub_r001036_7 * 2 + 224) & 127;
    if (stage_v_73 > 53) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001036_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (helper_flow_1 + pub_r001036_19 * 2 + 230) & 127;
    if (stage_v_75 > 58) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_31 + pub_r001036_13 * 2 + 233) & 127;
    if (stage_v_76 > 30) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_71 + pub_r001036_8 * 2 + 236) & 127;
    if (stage_v_77 > 29) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_52 + pub_r001036_16 * 2 + 239) & 127;
    if (stage_v_78 > 23) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_65 + pub_r001036_11 * 2 + 242) & 127;
    if (stage_v_79 > 59) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_48 + pub_r001036_8 * 2 + 245) & 127;
    if (stage_v_80 > 29) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001036_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_80 + pub_r001036_3 * 2 + 251) & 127;
    if (stage_v_82 > 35) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_12 + pub_r001036_2 * 2 + 254) & 127;
    if (stage_v_83 > 57) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_58 + pub_r001036_7 * 2 + 257) & 127;
    if (stage_v_84 > 50) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001036_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_2 + pub_r001036_19 * 2 + 263) & 127;
    if (stage_v_86 > 30) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_71 + pub_r001036_0 * 2 + 266) & 127;
    if (stage_v_87 > 51) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001036_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_12 + pub_r001036_20 * 2 + 272) & 127;
    if (stage_v_89 > 20) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_14 + pub_r001036_15 * 2 + 275) & 127;
    if (stage_v_90 > 30) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001036_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (helper_flow_3 + pub_r001036_13 * 2 + 281) & 127;
    if (stage_v_92 > 27) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001036_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_71 + pub_r001036_6 * 2 + 287) & 127;
    if (stage_v_94 > 21) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_84 + pub_r001036_4 * 2 + 290) & 127;
    if (stage_v_95 > 53) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001036_17 + pub_r001036_11 * 2 + 293) & 127;
    if (stage_v_96 > 59) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_34 + pub_r001036_0 * 2 + 296) & 127;
    if (stage_v_97 > 46) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_71 + pub_r001036_3 * 2 + 299) & 127;
    if (stage_v_98 > 16) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001036_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_82 + pub_r001036_9 * 2 + 305) & 127;
    if (stage_v_100 > 37) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001036_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (helper_flow_0 + pub_r001036_7 * 2 + 311) & 127;
    if (stage_v_102 > 59) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_75 + pub_r001036_3 * 2 + 314) & 127;
    if (stage_v_103 > 59) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (helper_flow_4 + pub_r001036_15 * 2 + 317) & 127;
    if (stage_v_104 > 60) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001036_20 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001036_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_84 + pub_r001036_20 * 2 + 326) & 127;
    if (stage_v_107 > 28) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r001036_10 + pub_r001036_11 * 2 + 329) & 127;
    if (stage_v_108 > 30) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (helper_flow_2 + pub_r001036_3 * 2 + 332) & 127;
    if (stage_v_109 > 25) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_96 + pub_r001036_11 * 2 + 335) & 127;
    if (stage_v_110 > 21) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001036_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_60 + pub_r001036_15 * 2 + 341) & 127;
    if (stage_v_112 > 43) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_10 + pub_r001036_11 * 2 + 344) & 127;
    if (stage_v_113 > 17) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_103 + pub_r001036_14 * 2 + 347) & 127;
    if (stage_v_114 > 55) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_84 + pub_r001036_7 * 2 + 350) & 127;
    if (stage_v_115 > 33) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001036_18 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_30 + pub_r001036_12 * 2 + 356) & 127;
    if (stage_v_117 > 40) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001036_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_4 + pub_r001036_13 * 2 + 362) & 127;
    if (stage_v_119 > 51) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001036_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_67 + pub_r001036_1 * 2 + 368) & 127;
    if (stage_v_121 > 58) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_48 + pub_r001036_20 * 2 + 371) & 127;
    if (stage_v_122 > 45) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001036_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_39 + pub_r001036_16 * 2 + 377) & 127;
    if (stage_v_124 > 31) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_100 + pub_r001036_3 * 2 + 380) & 127;
    if (stage_v_125 > 57) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_12 + pub_r001036_20 * 2 + 383) & 127;
    if (stage_v_126 > 22) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001036_3 + pub_r001036_11 * 2 + 386) & 127;
    if (stage_v_127 > 52) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (helper_flow_9 + pub_r001036_17 * 2 + 389) & 127;
    if (stage_v_128 > 39) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_42 + pub_r001036_3 * 2 + 392) & 127;
    if (stage_v_129 > 42) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001036_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (helper_flow_2 + pub_r001036_7 * 2 + 398) & 127;
    if (stage_v_131 > 22) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001036_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001036_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001036_10 + pub_r001036_15 * 2 + 407) & 127;
    if (stage_v_134 > 39) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001036_14 + pub_r001036_10 * 2 + 410) & 127;
    if (stage_v_135 > 53) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001036_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_31 + pub_r001036_18 * 2 + 416) & 127;
    if (stage_v_137 > 30) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_22 + pub_r001036_20 * 2 + 419) & 127;
    if (stage_v_138 > 19) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001036_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001036_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_80 + pub_r001036_3 * 2 + 428) & 127;
    if (stage_v_141 > 34) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001036_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_79 + pub_r001036_8 * 2 + 434) & 127;
    if (stage_v_143 > 24) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_134 + pub_r001036_13 * 2 + 437) & 127;
    if (stage_v_144 > 16) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_75 + pub_r001036_7 * 2 + 440) & 127;
    if (stage_v_145 > 23) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_50 + pub_r001036_18 * 2 + 443) & 127;
    if (stage_v_146 > 30) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001036_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001036_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001036_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001036_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_96 + pub_r001036_15 * 2 + 458) & 127;
    if (stage_v_151 > 57) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_144 + pub_r001036_11 * 2 + 461) & 127;
    if (stage_v_152 > 38) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_77 + pub_r001036_10 * 2 + 464) & 127;
    if (stage_v_153 > 26) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001036_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001036_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (sec_r001036_2 + pub_r001036_20 * 2 + 473) & 127;
    if (stage_v_156 > 58) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001036_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001036_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001036_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_145 + pub_r001036_14 * 2 + 485) & 127;
    if (stage_v_160 > 34) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_56 + pub_r001036_19 * 2 + 488) & 127;
    if (stage_v_161 > 32) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001036_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_58 + pub_r001036_1 * 2 + 494) & 127;
    if (stage_v_163 > 41) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001036_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001036_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_89 + pub_r001036_6 * 2 + 503) & 127;
    if (stage_v_166 > 38) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001036_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_121 + pub_r001036_0 * 2 + 509) & 127;
    if (stage_v_168 > 16) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001036_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001036_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001036_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_46 + pub_r001036_16 * 2 + 521) & 127;
    if (stage_v_172 > 36) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001036_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_110 + pub_r001036_10 * 2 + 527) & 127;
    if (stage_v_174 > 46) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001036_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_138 + pub_r001036_19 * 2 + 533) & 127;
    if (stage_v_176 > 55) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_42 + pub_r001036_1 * 2 + 536) & 127;
    if (stage_v_177 > 37) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_129 + pub_r001036_4 * 2 + 539) & 127;
    if (stage_v_178 > 31) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (helper_flow_6 + pub_r001036_9 * 2 + 542) & 127;
    if (stage_v_179 > 56) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_4 + pub_r001036_0 * 2 + 545) & 127;
    if (stage_v_180 > 25) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_179 + pub_r001036_2 * 2 + 548) & 127;
    if (stage_v_181 > 33) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_86 + pub_r001036_12 * 2 + 551) & 127;
    if (stage_v_182 > 31) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001036_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001036_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001036_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_79 + pub_r001036_3 * 2 + 563) & 127;
    if (stage_v_186 > 37) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_177 + pub_r001036_2 * 2 + 566) & 127;
    if (stage_v_187 > 41) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001036_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_172 + pub_r001036_20 * 2 + 572) & 127;
    if (stage_v_189 > 39) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001036_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_117 + pub_r001036_14 * 2 + 578) & 127;
    if (stage_v_191 > 31) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_114 + pub_r001036_14 * 2 + 581) & 127;
    if (stage_v_192 > 47) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_15 + pub_r001036_8 * 2 + 584) & 127;
    if (stage_v_193 > 56) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_151 + pub_r001036_19 * 2 + 587) & 127;
    if (stage_v_194 > 18) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_78 + pub_r001036_16 * 2 + 590) & 127;
    if (stage_v_195 > 54) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_146 + pub_r001036_7 * 2 + 593) & 127;
    if (stage_v_196 > 46) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_11 + pub_r001036_6 * 2 + 596) & 127;
    if (stage_v_197 > 22) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_78 + pub_r001036_16 * 2 + 599) & 127;
    if (stage_v_198 > 25) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001036_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_178 + pub_r001036_4 * 2 + 605) & 127;
    if (stage_v_200 > 24) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001036_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001036_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_179 + pub_r001036_17 * 2 + 614) & 127;
    if (stage_v_203 > 55) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_129 + pub_r001036_8 * 2 + 617) & 127;
    if (stage_v_204 > 57) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_2 + pub_r001036_12 * 2 + 620) & 127;
    if (stage_v_205 > 52) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_84 + pub_r001036_14 * 2 + 623) & 127;
    if (stage_v_206 > 41) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_3 + pub_r001036_12 * 2 + 626) & 127;
    if (stage_v_207 > 46) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001036_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (sec_r001036_16 + pub_r001036_16 * 2 + 632) & 127;
    if (stage_v_209 > 47) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001036_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_46 + pub_r001036_12 * 2 + 638) & 127;
    if (stage_v_211 > 33) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001036_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (helper_flow_5 + pub_r001036_14 * 2 + 644) & 127;
    if (stage_v_213 > 26) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r001036_9 + pub_r001036_13 * 2 + 647) & 127;
    if (stage_v_214 > 46) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_77 + pub_r001036_0 * 2 + 650) & 127;
    if (stage_v_215 > 28) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_7 + pub_r001036_13 * 2 + 653) & 127;
    if (stage_v_216 > 53) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (sec_r001036_6 + pub_r001036_12 * 2 + 656) & 127;
    if (stage_v_217 > 48) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001036_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001036_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001036_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_35 + pub_r001036_0 * 2 + 668) & 127;
    if (stage_v_221 > 28) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001036_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001036_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_48 + pub_r001036_5 * 2 + 677) & 127;
    if (stage_v_224 > 37) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001036_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001036_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_86 + pub_r001036_10 * 2 + 686) & 127;
    if (stage_v_227 > 20) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001036_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_215 + pub_r001036_11 * 2 + 692) & 127;
    if (stage_v_229 > 49) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_87 + pub_r001036_11 * 2 + 695) & 127;
    if (stage_v_230 > 23) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_28 + pub_r001036_1 * 2 + 698) & 127;
    if (stage_v_231 > 48) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_203 + pub_r001036_14 * 2 + 701) & 127;
    if (stage_v_232 > 19) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_50 + pub_r001036_5 * 2 + 704) & 127;
    if (stage_v_233 > 16) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_213 + pub_r001036_9 * 2 + 707) & 127;
    if (stage_v_234 > 33) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (sec_r001036_3 + pub_r001036_17 * 2 + 710) & 127;
    if (stage_v_235 > 38) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_62 + pub_r001036_8 * 2 + 713) & 127;
    if (stage_v_236 > 21) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_215 + pub_r001036_3 * 2 + 716) & 127;
    if (stage_v_237 > 32) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_112 + pub_r001036_1 * 2 + 719) & 127;
    if (stage_v_238 > 57) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_180 + pub_r001036_3 * 2 + 722) & 127;
    if (stage_v_239 > 52) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001036_20 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_174 + pub_r001036_4 * 2 + 728) & 127;
    if (stage_v_241 > 30) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001036_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (helper_flow_3 + pub_r001036_6 * 2 + 734) & 127;
    if (stage_v_243 > 35) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_83 + pub_r001036_9 * 2 + 737) & 127;
    if (stage_v_244 > 49) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001036_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_235 + pub_r001036_9 * 2 + 743) & 127;
    if (stage_v_246 > 51) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_115 + pub_r001036_4 * 2 + 746) & 127;
    if (stage_v_247 > 17) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_243 + pub_r001036_3 * 2 + 749) & 127;
    if (stage_v_248 > 24) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
        sec_accum ^= (stage_v_248 & 31);
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_10 + pub_r001036_14 * 2 + 752) & 127;
    if (stage_v_249 > 44) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
        sec_accum ^= (stage_v_249 & 31);
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_181 + pub_r001036_17 * 2 + 755) & 127;
    if (stage_v_250 > 34) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
        sec_accum ^= (stage_v_250 & 31);
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
