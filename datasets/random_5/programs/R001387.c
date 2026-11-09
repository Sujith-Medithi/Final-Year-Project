/*
 * Benchmark Program: R001387
 * Security Family: nested_implicit_flow
 * Generator Seed: 638713
 * High Inputs: 23 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001387_8713_0 {
    int fee;
    int status;
    int account_id;
    int auth_code;
    int rate;
    int balance;
    int buffer[3];
};

struct Vector3D_R001387_8713_1 {
    unsigned char heading;
    int norm_sq;
    unsigned char coord_z;
    unsigned char coord_x;
    int buffer[3];
};

struct StreamBuffer_R001387_8713_2 {
    int checksum;
    int tail;
    int capacity;
    short head;
    unsigned char state;
    int buffer[3];
};

union TelemetryField_R001387_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001387_8713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001387_8713_0(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_63) & 63;
    acc ^= aux;
    int index_reg_58 = (aux + st.buffer[1]) & 3;
    switch (index_reg_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_1(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_83 = 0;
    for (int k = 0; k < 2; k++) {
        damping_83 = (damping_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_83) & 127;
    }
    int threshold_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_32) & 63;
    acc ^= aux;
    int coefficient_83 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_83 > 15) {
        acc = (acc + coefficient_83 * 2 + 5) & 127;
        aux ^= (coefficient_83 & 15);
    } else {
        acc = (acc - coefficient_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_2(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int segment_28 = (aux + st.buffer[1]) & 3;
    switch (segment_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_18 = local_arr[aux % 3];
    acc = (acc + phase_18 * 2) & 127;
    int checksum_22 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_22 = (checksum_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_3(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int sample_40 = local_arr[aux % 3];
    acc = (acc + sample_40 * 2) & 127;
    int scale_39 = 0;
    for (int k = 0; k < 3; k++) {
        scale_39 = (scale_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_4(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_58 = 0;
    for (int k = 0; k < 2; k++) {
        segment_58 = (segment_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_58) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_53 = local_arr[aux % 3];
    acc = (acc + mask_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001387_8713_5(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001387_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_70) & 63;
    acc ^= aux;
    int index_reg_84 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_84 > 24) {
        acc = (acc + index_reg_84 * 2 + 5) & 127;
        aux ^= (index_reg_84 & 15);
    } else {
        acc = (acc - index_reg_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_51 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_51 > 26) {
        acc = (acc + bound_51 * 2 + 5) & 127;
        aux ^= (bound_51 & 15);
    } else {
        acc = (acc - bound_51 + 11) & 127;
        aux += 3;
    }
    int factor_38 = (aux + st.buffer[1]) & 3;
    switch (factor_38) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_57 = local_arr[aux % 3];
    acc = (acc + bound_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001387_8713_7(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_65 = 0;
    for (int k = 0; k < 2; k++) {
        factor_65 = (factor_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_65) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_95 = local_arr[aux % 3];
    acc = (acc + segment_95 * 2) & 127;
    int bound_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001387_8713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_67 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_67 = (quotient_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_63 = 0;
    for (int k = 0; k < 2; k++) {
        stride_63 = (stride_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_63) & 127;
    }
    int threshold_75 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_75 > 49) {
        acc = (acc + threshold_75 * 2 + 5) & 127;
        aux ^= (threshold_75 & 15);
    } else {
        acc = (acc - threshold_75 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_53 = local_arr[aux % 3];
    acc = (acc + offset_53 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001387_8713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001387_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tracker_76 = (aux + st.buffer[1]) & 3;
    switch (tracker_76) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_57 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_57 = (checksum_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_57) & 127;
    }
    int threshold_79 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_79 > 22) {
        acc = (acc + threshold_79 * 2 + 5) & 127;
        aux ^= (threshold_79 & 15);
    } else {
        acc = (acc - threshold_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_11(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_74 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_74 > 37) {
        acc = (acc + accumulator_74 * 2 + 5) & 127;
        aux ^= (accumulator_74 & 15);
    } else {
        acc = (acc - accumulator_74 + 11) & 127;
        aux += 3;
    }
    int mask_88 = 0;
    for (int k = 0; k < 3; k++) {
        mask_88 = (mask_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_88) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_44 = local_arr[aux % 3];
    acc = (acc + cursor_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001387_8713_12(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_20 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_20 > 22) {
        acc = (acc + tracker_20 * 2 + 5) & 127;
        aux ^= (tracker_20 & 15);
    } else {
        acc = (acc - tracker_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001387_8713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001387_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_52) & 63;
    acc ^= aux;
    int mask_90 = (aux + st.buffer[1]) & 3;
    switch (mask_90) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001387_0;
    int sec_r001387_1;
    int sec_r001387_2;
    int sec_r001387_3;
    int sec_r001387_4;
    int sec_r001387_5;
    int sec_r001387_6;
    int sec_r001387_7;
    int sec_r001387_8;
    int sec_r001387_9;
    int sec_r001387_10;
    int sec_r001387_11;
    int sec_r001387_12;
    int sec_r001387_13;
    int sec_r001387_14;
    int sec_r001387_15;
    int sec_r001387_16;
    int sec_r001387_17;
    int sec_r001387_18;
    int sec_r001387_19;
    int sec_r001387_20;
    int sec_r001387_21;
    int sec_r001387_22;
    int pub_r001387_0;
    int pub_r001387_1;
    int pub_r001387_2;
    int pub_r001387_3;
    int pub_r001387_4;
    int pub_r001387_5;
    int pub_r001387_6;
    int pub_r001387_7;
    int pub_r001387_8;
    int pub_r001387_9;
    int pub_r001387_10;
    int pub_r001387_11;
    int pub_r001387_12;
    int pub_r001387_13;
    int pub_r001387_14;
    int pub_r001387_15;
    int pub_r001387_16;
    int pub_r001387_17;
    int pub_r001387_18;
    int pub_r001387_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001387_0 >= -100 && pub_r001387_0 <= 100);
    __CPROVER_assume(pub_r001387_1 >= -100 && pub_r001387_1 <= 100);
    __CPROVER_assume(pub_r001387_2 >= -100 && pub_r001387_2 <= 100);
    __CPROVER_assume(pub_r001387_3 >= -100 && pub_r001387_3 <= 100);
    __CPROVER_assume(pub_r001387_4 >= -100 && pub_r001387_4 <= 100);
    __CPROVER_assume(pub_r001387_5 >= -100 && pub_r001387_5 <= 100);
    __CPROVER_assume(pub_r001387_6 >= -100 && pub_r001387_6 <= 100);
    __CPROVER_assume(pub_r001387_7 >= -100 && pub_r001387_7 <= 100);
    __CPROVER_assume(pub_r001387_8 >= -100 && pub_r001387_8 <= 100);
    __CPROVER_assume(pub_r001387_9 >= -100 && pub_r001387_9 <= 100);
    __CPROVER_assume(pub_r001387_10 >= -100 && pub_r001387_10 <= 100);
    __CPROVER_assume(pub_r001387_11 >= -100 && pub_r001387_11 <= 100);
    __CPROVER_assume(pub_r001387_12 >= -100 && pub_r001387_12 <= 100);
    __CPROVER_assume(pub_r001387_13 >= -100 && pub_r001387_13 <= 100);
    __CPROVER_assume(pub_r001387_14 >= -100 && pub_r001387_14 <= 100);
    __CPROVER_assume(pub_r001387_15 >= -100 && pub_r001387_15 <= 100);
    __CPROVER_assume(pub_r001387_16 >= -100 && pub_r001387_16 <= 100);
    __CPROVER_assume(pub_r001387_17 >= -100 && pub_r001387_17 <= 100);
    __CPROVER_assume(pub_r001387_18 >= -100 && pub_r001387_18 <= 100);
    __CPROVER_assume(pub_r001387_19 >= -100 && pub_r001387_19 <= 100);
    __CPROVER_assume(sec_r001387_0 >= 0 && sec_r001387_0 <= 255);
    __CPROVER_assume(sec_r001387_1 >= 0 && sec_r001387_1 <= 255);
    __CPROVER_assume(sec_r001387_2 >= 0 && sec_r001387_2 <= 255);
    __CPROVER_assume(sec_r001387_3 >= 0 && sec_r001387_3 <= 255);
    __CPROVER_assume(sec_r001387_4 >= 0 && sec_r001387_4 <= 255);
    __CPROVER_assume(sec_r001387_5 >= 0 && sec_r001387_5 <= 255);
    __CPROVER_assume(sec_r001387_6 >= 0 && sec_r001387_6 <= 255);
    __CPROVER_assume(sec_r001387_7 >= 0 && sec_r001387_7 <= 255);
    __CPROVER_assume(sec_r001387_8 >= 0 && sec_r001387_8 <= 255);
    __CPROVER_assume(sec_r001387_9 >= 0 && sec_r001387_9 <= 255);
    __CPROVER_assume(sec_r001387_10 >= 0 && sec_r001387_10 <= 255);
    __CPROVER_assume(sec_r001387_11 >= 0 && sec_r001387_11 <= 255);
    __CPROVER_assume(sec_r001387_12 >= 0 && sec_r001387_12 <= 255);
    __CPROVER_assume(sec_r001387_13 >= 0 && sec_r001387_13 <= 255);
    __CPROVER_assume(sec_r001387_14 >= 0 && sec_r001387_14 <= 255);
    __CPROVER_assume(sec_r001387_15 >= 0 && sec_r001387_15 <= 255);
    __CPROVER_assume(sec_r001387_16 >= 0 && sec_r001387_16 <= 255);
    __CPROVER_assume(sec_r001387_17 >= 0 && sec_r001387_17 <= 255);
    __CPROVER_assume(sec_r001387_18 >= 0 && sec_r001387_18 <= 255);
    __CPROVER_assume(sec_r001387_19 >= 0 && sec_r001387_19 <= 255);
    __CPROVER_assume(sec_r001387_20 >= 0 && sec_r001387_20 <= 255);
    __CPROVER_assume(sec_r001387_21 >= 0 && sec_r001387_21 <= 255);
    __CPROVER_assume(sec_r001387_22 >= 0 && sec_r001387_22 <= 255);

    struct Transaction_R001387_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001387_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001387_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001387_0 + 7) & 15;
    struct Vector3D_R001387_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001387_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001387_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001387_0 + 9) & 15;
    struct StreamBuffer_R001387_8713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001387_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001387_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001387_0 + 11) & 15;

    union TelemetryField_R001387_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001387_8713_0(sec_r001387_0, pub_r001387_1);
    int helper_flow_1 = fn_R001387_8713_1(sec_r001387_1, pub_r001387_2, pub_r001387_3);
    int helper_flow_2 = fn_R001387_8713_2(sec_r001387_2, pub_r001387_3, pub_r001387_4);
    int helper_flow_3 = fn_R001387_8713_3(sec_r001387_3, sec_r001387_4, pub_r001387_5);
    int helper_flow_4 = fn_R001387_8713_4(sec_r001387_4, pub_r001387_5);
    int helper_flow_5 = fn_R001387_8713_5(sec_r001387_5, sec_r001387_6);
    int helper_flow_6 = fn_R001387_8713_6(sec_r001387_6, sec_r001387_7, pub_r001387_8, pub_r001387_9, pub_r001387_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001387_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001387_12 ^ pub_r001387_15) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001387_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001387_11 ^ pub_r001387_18) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001387_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001387_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001387_10 ^ pub_r001387_2) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001387_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001387_7 ^ pub_r001387_1) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001387_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001387_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_5 ^ pub_r001387_19) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001387_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001387_14 ^ pub_r001387_13) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001387_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001387_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001387_19 ^ pub_r001387_10) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001387_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001387_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001387_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_3 ^ pub_r001387_13) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001387_20 ^ pub_r001387_0) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001387_6 ^ pub_r001387_12) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001387_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001387_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001387_0 ^ pub_r001387_13) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001387_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001387_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_10 ^ pub_r001387_8) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001387_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001387_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001387_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001387_9 ^ pub_r001387_11) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_1 ^ pub_r001387_9) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_8 ^ pub_r001387_4) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_1 ^ pub_r001387_17) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001387_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001387_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_6 ^ pub_r001387_2) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r001387_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_26 ^ pub_r001387_12) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001387_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001387_3 ^ pub_r001387_11) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_1 ^ pub_r001387_7) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r001387_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001387_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_1 ^ pub_r001387_12) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001387_5 ^ pub_r001387_17) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001387_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001387_2 ^ pub_r001387_8) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001387_7 ^ pub_r001387_12) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_31 ^ pub_r001387_3) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_19 ^ pub_r001387_0) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_12 ^ pub_r001387_9) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001387_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001387_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001387_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_10 ^ pub_r001387_13) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001387_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_4 ^ pub_r001387_12) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r001387_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001387_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001387_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_2 ^ pub_r001387_8) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_1 ^ pub_r001387_4) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_44 ^ pub_r001387_12) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001387_5 ^ pub_r001387_3) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001387_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001387_11 ^ pub_r001387_3) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_25 ^ pub_r001387_4) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001387_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_19 ^ pub_r001387_18) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_24 ^ pub_r001387_10) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001387_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_16 ^ pub_r001387_2) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001387_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001387_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_24 ^ pub_r001387_7) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001387_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001387_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001387_14 ^ pub_r001387_11) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001387_17 ^ pub_r001387_3) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_53 ^ pub_r001387_17) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r001387_8 ^ pub_r001387_11) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001387_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001387_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001387_19 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_39 ^ pub_r001387_10) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001387_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001387_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_52 ^ pub_r001387_12) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r001387_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (helper_flow_1 ^ pub_r001387_8) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r001387_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_4 ^ pub_r001387_19) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_63 ^ pub_r001387_17) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001387_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_17 ^ pub_r001387_10) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001387_10 ^ pub_r001387_10) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001387_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001387_21 ^ pub_r001387_19) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r001387_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_40 ^ pub_r001387_16) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_63 ^ pub_r001387_14) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001387_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001387_0 ^ pub_r001387_1) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_54 ^ pub_r001387_18) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001387_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001387_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001387_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001387_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001387_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001387_5 ^ pub_r001387_5) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001387_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001387_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_38 ^ pub_r001387_5) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r001387_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001387_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001387_5 ^ pub_r001387_14) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_49 ^ pub_r001387_4) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (helper_flow_6 ^ pub_r001387_6) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001387_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001387_1 ^ pub_r001387_13) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001387_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001387_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_36 ^ pub_r001387_0) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001387_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001387_0 ^ pub_r001387_11) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_83 ^ pub_r001387_1) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001387_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001387_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_52 ^ pub_r001387_10) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_8 ^ pub_r001387_17) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r001387_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_54 ^ pub_r001387_1) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r001387_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001387_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001387_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_105 ^ pub_r001387_8) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r001387_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001387_1 ^ pub_r001387_10) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001387_12 ^ pub_r001387_10) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_24 ^ pub_r001387_18) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001387_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (helper_flow_6 ^ pub_r001387_16) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_16 ^ pub_r001387_8) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_72 ^ pub_r001387_11) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001387_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_60 ^ pub_r001387_3) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001387_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001387_19 ^ pub_r001387_12) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_35 ^ pub_r001387_0) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001387_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_53 ^ pub_r001387_1) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r001387_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001387_1 ^ pub_r001387_10) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001387_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_95 ^ pub_r001387_3) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r001387_13 ^ pub_r001387_15) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001387_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001387_20 ^ pub_r001387_0) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001387_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_55 ^ pub_r001387_11) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r001387_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_1 ^ pub_r001387_10) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001387_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_126 ^ pub_r001387_1) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_99 ^ pub_r001387_15) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_115 ^ pub_r001387_7) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001387_14 ^ pub_r001387_16) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_81 ^ pub_r001387_5) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_137 ^ pub_r001387_14) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r001387_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001387_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001387_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (sec_r001387_6 ^ pub_r001387_4) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001387_5 ^ pub_r001387_6) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_138 ^ pub_r001387_13) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001387_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001387_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001387_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001387_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_40 ^ pub_r001387_9) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_147 ^ pub_r001387_6) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001387_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_64 ^ pub_r001387_1) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((sec_r001387_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (sec_r001387_8 ^ pub_r001387_16) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_105 ^ pub_r001387_10) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_110 ^ pub_r001387_4) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((sec_r001387_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001387_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001387_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_51 ^ pub_r001387_15) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_145 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_37 ^ pub_r001387_2) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((sec_r001387_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (sec_r001387_9 ^ pub_r001387_15) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((sec_r001387_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001387_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r001387_6 ^ pub_r001387_14) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_5 ^ pub_r001387_6) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r001387_0 ^ pub_r001387_5) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((sec_r001387_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_63 ^ pub_r001387_14) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_29 ^ pub_r001387_16) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001387_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001387_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_99 ^ pub_r001387_8) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_93 ^ pub_r001387_9) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001387_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_115 ^ pub_r001387_2) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001387_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001387_13 ^ pub_r001387_4) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001387_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_158 ^ pub_r001387_2) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (sec_r001387_17 ^ pub_r001387_4) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001387_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_110 ^ pub_r001387_5) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((sec_r001387_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001387_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001387_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r001387_2 ^ pub_r001387_3) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_139 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_57 ^ pub_r001387_2) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001387_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001387_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001387_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_108 ^ pub_r001387_8) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_142 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_166 ^ pub_r001387_17) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_50 ^ pub_r001387_0) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001387_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_97 ^ pub_r001387_17) & 63;
    if ((stage_v_194 & 1) != 0) {
        if ((stage_v_116 & 2) != 0) {
            out_sink = (out_sink + stage_v_194 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_194 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001387_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001387_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_55 ^ pub_r001387_1) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((sec_r001387_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001387_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (sec_r001387_3 ^ pub_r001387_2) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001387_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001387_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_105 ^ pub_r001387_0) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001387_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (helper_flow_3 ^ pub_r001387_18) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((stage_v_152 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_79 ^ pub_r001387_0) & 63;
    if ((stage_v_205 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_205 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_205 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_1 ^ pub_r001387_3) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((stage_v_204 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_72 ^ pub_r001387_6) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((sec_r001387_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_192 ^ pub_r001387_13) & 63;
    if ((stage_v_208 & 1) != 0) {
        if ((sec_r001387_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_208 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_208 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_19 ^ pub_r001387_19) & 63;
    if ((stage_v_209 & 1) != 0) {
        if ((sec_r001387_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_209 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_209 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (sec_r001387_9 ^ pub_r001387_4) & 63;
    if ((stage_v_210 & 1) != 0) {
        if ((stage_v_199 & 2) != 0) {
            out_sink = (out_sink + stage_v_210 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_210 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_4 ^ pub_r001387_6) & 63;
    if ((stage_v_211 & 1) != 0) {
        if ((stage_v_146 & 2) != 0) {
            out_sink = (out_sink + stage_v_211 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_211 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001387_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001387_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_102 ^ pub_r001387_15) & 63;
    if ((stage_v_214 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_214 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_214 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (sec_r001387_6 ^ pub_r001387_9) & 63;
    if ((stage_v_215 & 1) != 0) {
        if ((stage_v_166 & 2) != 0) {
            out_sink = (out_sink + stage_v_215 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_215 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001387_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001387_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_29 ^ pub_r001387_13) & 63;
    if ((stage_v_218 & 1) != 0) {
        if ((stage_v_179 & 2) != 0) {
            out_sink = (out_sink + stage_v_218 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_218 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_39 ^ pub_r001387_7) & 63;
    if ((stage_v_219 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_219 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_219 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_127 ^ pub_r001387_14) & 63;
    if ((stage_v_220 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_220 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_220 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_102 ^ pub_r001387_6) & 63;
    if ((stage_v_221 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_221 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_221 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_90 ^ pub_r001387_19) & 63;
    if ((stage_v_222 & 1) != 0) {
        if ((sec_r001387_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_222 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_222 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001387_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_95 ^ pub_r001387_19) & 63;
    if ((stage_v_224 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_224 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_224 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_208 ^ pub_r001387_4) & 63;
    if ((stage_v_225 & 1) != 0) {
        if ((stage_v_141 & 2) != 0) {
            out_sink = (out_sink + stage_v_225 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_225 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_180 ^ pub_r001387_5) & 63;
    if ((stage_v_226 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_226 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_226 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001387_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_215 ^ pub_r001387_5) & 63;
    if ((stage_v_228 & 1) != 0) {
        if ((sec_r001387_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_228 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_228 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_197 ^ pub_r001387_9) & 63;
    if ((stage_v_229 & 1) != 0) {
        if ((stage_v_205 & 2) != 0) {
            out_sink = (out_sink + stage_v_229 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_229 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_145 ^ pub_r001387_14) & 63;
    if ((stage_v_230 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_230 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_230 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_123 ^ pub_r001387_1) & 63;
    if ((stage_v_231 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_231 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_231 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_52 ^ pub_r001387_4) & 63;
    if ((stage_v_232 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_232 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_232 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_2 ^ pub_r001387_4) & 63;
    if ((stage_v_233 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_233 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_233 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_233 * 2) & 255;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_207 ^ pub_r001387_6) & 63;
    if ((stage_v_234 & 1) != 0) {
        if ((stage_v_175 & 2) != 0) {
            out_sink = (out_sink + stage_v_234 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_234 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_234 * 2) & 255;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001387_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_180 ^ pub_r001387_11) & 63;
    if ((stage_v_236 & 1) != 0) {
        if ((stage_v_119 & 2) != 0) {
            out_sink = (out_sink + stage_v_236 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_236 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_225 ^ pub_r001387_18) & 63;
    if ((stage_v_237 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_237 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_237 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
