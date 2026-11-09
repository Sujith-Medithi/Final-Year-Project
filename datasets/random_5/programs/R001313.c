/*
 * Benchmark Program: R001313
 * Security Family: multi_step_explicit
 * Generator Seed: 631313
 * High Inputs: 20 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001313_1313_0 {
    unsigned char account_id;
    int auth_code;
    short status;
    unsigned char fee;
    int balance;
    unsigned char rate;
    int buffer[3];
};

struct Vector3D_R001313_1313_1 {
    unsigned char coord_x;
    unsigned char pitch;
    short coord_y;
    int coord_z;
    int buffer[3];
};

struct DeviceConfig_R001313_1313_2 {
    short port;
    int parity;
    int baud_rate;
    int timeout;
    int id;
    int stop_bits;
    int buffer[3];
};

union RegisterBank_R001313_1313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001313_1313_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_56 = (aux + st.buffer[1]) & 3;
    switch (damping_56) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_85 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_85 > 19) {
        acc = (acc + parity_85 * 2 + 5) & 127;
        aux ^= (parity_85 & 15);
    } else {
        acc = (acc - parity_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001313_1313_1(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_45 = 0;
    for (int k = 0; k < 2; k++) {
        factor_45 = (factor_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_45) & 127;
    }
    int stride_35 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_35 > 15) {
        acc = (acc + stride_35 * 2 + 5) & 127;
        aux ^= (stride_35 & 15);
    } else {
        acc = (acc - stride_35 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_58 = local_arr[aux % 3];
    acc = (acc + bound_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001313_1313_2(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_35 = 0;
    for (int k = 0; k < 2; k++) {
        stride_35 = (stride_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_35) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001313_1313_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_82 = 0;
    for (int k = 0; k < 2; k++) {
        offset_82 = (offset_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_82) & 127;
    }
    int tracker_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001313_1313_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_88) & 63;
    acc ^= aux;
    int threshold_84 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_84 = (threshold_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_84) & 127;
    }
    int sample_14 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_14 > 14) {
        acc = (acc + sample_14 * 2 + 5) & 127;
        aux ^= (sample_14 & 15);
    } else {
        acc = (acc - sample_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001313_1313_5(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int tally_62 = 0;
    for (int k = 0; k < 2; k++) {
        tally_62 = (tally_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_62) & 127;
    }
    int accumulator_32 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_32 > 27) {
        acc = (acc + accumulator_32 * 2 + 5) & 127;
        aux ^= (accumulator_32 & 15);
    } else {
        acc = (acc - accumulator_32 + 11) & 127;
        aux += 3;
    }
    int factor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_91 = local_arr[aux % 3];
    acc = (acc + threshold_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001313_1313_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quotient_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_24) & 63;
    acc ^= aux;
    int stride_87 = 0;
    for (int k = 0; k < 2; k++) {
        stride_87 = (stride_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_87) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001313_1313_7(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int mask_89 = local_arr[aux % 3];
    acc = (acc + mask_89 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_85 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_85 = (index_reg_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_85) & 127;
    }
    int residue_46 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_46 > 50) {
        acc = (acc + residue_46 * 2 + 5) & 127;
        aux ^= (residue_46 & 15);
    } else {
        acc = (acc - residue_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001313_1313_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_50 = (aux + st.buffer[1]) & 3;
    switch (vector_50) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_62 = 0;
    for (int k = 0; k < 3; k++) {
        stride_62 = (stride_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_62) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_98 = local_arr[aux % 3];
    acc = (acc + delta_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001313_1313_9(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int sample_65 = local_arr[aux % 3];
    acc = (acc + sample_65 * 2) & 127;
    int phase_94 = (aux + st.buffer[1]) & 3;
    switch (phase_94) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_46 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_46 > 33) {
        acc = (acc + sample_46 * 2 + 5) & 127;
        aux ^= (sample_46 & 15);
    } else {
        acc = (acc - sample_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001313_1313_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int accumulator_32 = (aux + st.buffer[1]) & 3;
    switch (accumulator_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001313_1313_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int delta_23 = local_arr[aux % 3];
    acc = (acc + delta_23 * 2) & 127;
    int parity_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_62) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_12 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_12 = (threshold_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001313_1313_12(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int pivot_65 = (aux + st.buffer[1]) & 3;
    switch (pivot_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_32 = 0;
    for (int k = 0; k < 2; k++) {
        tally_32 = (tally_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_32) & 127;
    }
    int anchor_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001313_1313_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int stride_46 = local_arr[aux % 3];
    acc = (acc + stride_46 * 2) & 127;
    int parity_83 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_83 > 40) {
        acc = (acc + parity_83 * 2 + 5) & 127;
        aux ^= (parity_83 & 15);
    } else {
        acc = (acc - parity_83 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_36 = 0;
    for (int k = 0; k < 2; k++) {
        offset_36 = (offset_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_36) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001313_1313_14(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int pivot_43 = (aux + st.buffer[1]) & 3;
    switch (pivot_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_49) & 63;
    acc ^= aux;
    int window_70 = 0;
    for (int k = 0; k < 3; k++) {
        window_70 = (window_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_70) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001313_0;
    int sec_r001313_1;
    int sec_r001313_2;
    int sec_r001313_3;
    int sec_r001313_4;
    int sec_r001313_5;
    int sec_r001313_6;
    int sec_r001313_7;
    int sec_r001313_8;
    int sec_r001313_9;
    int sec_r001313_10;
    int sec_r001313_11;
    int sec_r001313_12;
    int sec_r001313_13;
    int sec_r001313_14;
    int sec_r001313_15;
    int sec_r001313_16;
    int sec_r001313_17;
    int sec_r001313_18;
    int sec_r001313_19;
    int pub_r001313_0;
    int pub_r001313_1;
    int pub_r001313_2;
    int pub_r001313_3;
    int pub_r001313_4;
    int pub_r001313_5;
    int pub_r001313_6;
    int pub_r001313_7;
    int pub_r001313_8;
    int pub_r001313_9;
    int pub_r001313_10;
    int pub_r001313_11;
    int pub_r001313_12;
    int pub_r001313_13;
    int pub_r001313_14;
    int pub_r001313_15;
    int pub_r001313_16;
    int pub_r001313_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001313_0 >= -100 && pub_r001313_0 <= 100);
    __CPROVER_assume(pub_r001313_1 >= -100 && pub_r001313_1 <= 100);
    __CPROVER_assume(pub_r001313_2 >= -100 && pub_r001313_2 <= 100);
    __CPROVER_assume(pub_r001313_3 >= -100 && pub_r001313_3 <= 100);
    __CPROVER_assume(pub_r001313_4 >= -100 && pub_r001313_4 <= 100);
    __CPROVER_assume(pub_r001313_5 >= -100 && pub_r001313_5 <= 100);
    __CPROVER_assume(pub_r001313_6 >= -100 && pub_r001313_6 <= 100);
    __CPROVER_assume(pub_r001313_7 >= -100 && pub_r001313_7 <= 100);
    __CPROVER_assume(pub_r001313_8 >= -100 && pub_r001313_8 <= 100);
    __CPROVER_assume(pub_r001313_9 >= -100 && pub_r001313_9 <= 100);
    __CPROVER_assume(pub_r001313_10 >= -100 && pub_r001313_10 <= 100);
    __CPROVER_assume(pub_r001313_11 >= -100 && pub_r001313_11 <= 100);
    __CPROVER_assume(pub_r001313_12 >= -100 && pub_r001313_12 <= 100);
    __CPROVER_assume(pub_r001313_13 >= -100 && pub_r001313_13 <= 100);
    __CPROVER_assume(pub_r001313_14 >= -100 && pub_r001313_14 <= 100);
    __CPROVER_assume(pub_r001313_15 >= -100 && pub_r001313_15 <= 100);
    __CPROVER_assume(pub_r001313_16 >= -100 && pub_r001313_16 <= 100);
    __CPROVER_assume(pub_r001313_17 >= -100 && pub_r001313_17 <= 100);
    __CPROVER_assume(sec_r001313_0 >= 0 && sec_r001313_0 <= 255);
    __CPROVER_assume(sec_r001313_1 >= 0 && sec_r001313_1 <= 255);
    __CPROVER_assume(sec_r001313_2 >= 0 && sec_r001313_2 <= 255);
    __CPROVER_assume(sec_r001313_3 >= 0 && sec_r001313_3 <= 255);
    __CPROVER_assume(sec_r001313_4 >= 0 && sec_r001313_4 <= 255);
    __CPROVER_assume(sec_r001313_5 >= 0 && sec_r001313_5 <= 255);
    __CPROVER_assume(sec_r001313_6 >= 0 && sec_r001313_6 <= 255);
    __CPROVER_assume(sec_r001313_7 >= 0 && sec_r001313_7 <= 255);
    __CPROVER_assume(sec_r001313_8 >= 0 && sec_r001313_8 <= 255);
    __CPROVER_assume(sec_r001313_9 >= 0 && sec_r001313_9 <= 255);
    __CPROVER_assume(sec_r001313_10 >= 0 && sec_r001313_10 <= 255);
    __CPROVER_assume(sec_r001313_11 >= 0 && sec_r001313_11 <= 255);
    __CPROVER_assume(sec_r001313_12 >= 0 && sec_r001313_12 <= 255);
    __CPROVER_assume(sec_r001313_13 >= 0 && sec_r001313_13 <= 255);
    __CPROVER_assume(sec_r001313_14 >= 0 && sec_r001313_14 <= 255);
    __CPROVER_assume(sec_r001313_15 >= 0 && sec_r001313_15 <= 255);
    __CPROVER_assume(sec_r001313_16 >= 0 && sec_r001313_16 <= 255);
    __CPROVER_assume(sec_r001313_17 >= 0 && sec_r001313_17 <= 255);
    __CPROVER_assume(sec_r001313_18 >= 0 && sec_r001313_18 <= 255);
    __CPROVER_assume(sec_r001313_19 >= 0 && sec_r001313_19 <= 255);

    struct Transaction_R001313_1313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001313_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001313_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001313_0 + 7) & 15;
    struct Vector3D_R001313_1313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001313_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001313_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001313_0 + 9) & 15;
    struct DeviceConfig_R001313_1313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001313_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001313_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001313_0 + 11) & 15;

    union RegisterBank_R001313_1313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001313_1313_0(sec_r001313_0, pub_r001313_1, pub_r001313_2, pub_r001313_3, pub_r001313_4);
    int helper_flow_1 = fn_R001313_1313_1(sec_r001313_1, pub_r001313_2);
    int helper_flow_2 = fn_R001313_1313_2(sec_r001313_2, sec_r001313_3);
    int helper_flow_3 = fn_R001313_1313_3(sec_r001313_3, sec_r001313_4, pub_r001313_5, pub_r001313_6, pub_r001313_7);
    int helper_flow_4 = fn_R001313_1313_4(sec_r001313_4, sec_r001313_5, pub_r001313_6, pub_r001313_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_2 * 3) + pub_r001313_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001313_8 * 3) + pub_r001313_4 + 10) & 127;
    sec_accum = (sec_accum + stage_v_1) & 255;
    out_sink = (out_sink + stage_v_1 * 2) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001313_11 * 3) + pub_r001313_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001313_3 * 3) + pub_r001313_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_3) & 255;
    out_sink = (out_sink + stage_v_3 * 2) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001313_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001313_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001313_8 * 3) + pub_r001313_15 + 16) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001313_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001313_15 * 3) + pub_r001313_16 + 24) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8 * 2) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001313_10 * 3) + pub_r001313_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001313_18 * 3) + pub_r001313_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_10 * 3) + pub_r001313_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_11) & 255;
    out_sink = (out_sink + stage_v_11 * 2) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_3 * 3) + pub_r001313_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_4 * 3) + pub_r001313_14 + 36) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001313_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001313_4 * 3) + pub_r001313_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_15) & 255;
    out_sink = (out_sink + stage_v_15 * 2) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_3 * 3) + pub_r001313_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001313_8 * 3) + pub_r001313_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001313_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001313_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_13 * 3) + pub_r001313_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_2 * 3) + pub_r001313_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21 * 2) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001313_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001313_3 * 3) + pub_r001313_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001313_3 * 3) + pub_r001313_15 + 40) & 127;
    sec_accum = (sec_accum + stage_v_24) & 255;
    out_sink = (out_sink + stage_v_24 * 2) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001313_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001313_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001313_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001313_15 * 3) + pub_r001313_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001313_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001313_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001313_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_3 * 3) + pub_r001313_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_21 * 3) + pub_r001313_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001313_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001313_1 * 3) + pub_r001313_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_28 * 3) + pub_r001313_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001313_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001313_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001313_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001313_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001313_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001313_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001313_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_11 * 3) + pub_r001313_17 + 39) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001313_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001313_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001313_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_4 * 3) + pub_r001313_1 + 3) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001313_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001313_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001313_15 * 3) + pub_r001313_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_16 * 3) + pub_r001313_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_0 * 3) + pub_r001313_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53 * 2) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_4 * 3) + pub_r001313_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001313_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001313_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_9 * 3) + pub_r001313_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001313_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001313_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_6 * 3) + pub_r001313_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001313_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001313_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001313_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001313_4 * 3) + pub_r001313_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001313_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_54 * 3) + pub_r001313_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66 * 2) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001313_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001313_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_15 * 3) + pub_r001313_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69 * 2) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001313_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001313_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_12 * 3) + pub_r001313_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001313_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001313_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_16 * 3) + pub_r001313_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75 * 2) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001313_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001313_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001313_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001313_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001313_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001313_6 * 3) + pub_r001313_6 + 34) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81 * 2) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_15 * 3) + pub_r001313_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82 * 2) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001313_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001313_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001313_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_9 * 3) + pub_r001313_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_3 * 3) + pub_r001313_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((helper_flow_3 * 3) + pub_r001313_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001313_11 * 3) + pub_r001313_9 + 40) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001313_19 * 3) + pub_r001313_2 + 6) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001313_16 * 3) + pub_r001313_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001313_5 * 3) + pub_r001313_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001313_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001313_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_21 * 3) + pub_r001313_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95 * 2) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001313_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001313_7 * 3) + pub_r001313_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001313_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001313_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_15 * 3) + pub_r001313_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001313_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_2 * 3) + pub_r001313_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102 * 2) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_12 * 3) + pub_r001313_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103 * 2) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001313_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001313_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_66 * 3) + pub_r001313_15 + 9) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001313_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_15 * 3) + pub_r001313_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001313_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001313_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_92 * 3) + pub_r001313_7 + 15) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_35 * 3) + pub_r001313_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_0 * 3) + pub_r001313_1 + 18) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001313_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001313_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_103 * 3) + pub_r001313_14 + 36) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001313_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001313_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_3 * 3) + pub_r001313_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_81 * 3) + pub_r001313_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001313_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001313_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001313_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_95 * 3) + pub_r001313_5 + 40) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_120 * 3) + pub_r001313_3 + 15) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_89 * 3) + pub_r001313_9 + 33) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126 * 2) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001313_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001313_15 * 3) + pub_r001313_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001313_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_116 * 3) + pub_r001313_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001313_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001313_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_53 * 3) + pub_r001313_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_21 * 3) + pub_r001313_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134 * 2) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001313_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001313_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001313_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_53 * 3) + pub_r001313_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138 * 2) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r001313_4 * 3) + pub_r001313_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001313_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001313_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_100 * 3) + pub_r001313_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_57 * 3) + pub_r001313_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001313_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_90 * 3) + pub_r001313_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001313_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001313_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001313_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001313_14 * 3) + pub_r001313_3 + 41) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149 * 2) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_90 * 3) + pub_r001313_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_142 * 3) + pub_r001313_6 + 34) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151 * 2) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_95 * 3) + pub_r001313_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001313_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_152 * 3) + pub_r001313_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001313_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001313_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_64 * 3) + pub_r001313_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157 * 2) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_75 * 3) + pub_r001313_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r001313_8 * 3) + pub_r001313_14 + 31) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001313_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_20 * 3) + pub_r001313_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001313_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001313_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001313_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001313_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_111 * 3) + pub_r001313_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001313_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001313_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_16 * 3) + pub_r001313_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169 * 2) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001313_4 * 3) + pub_r001313_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_75 * 3) + pub_r001313_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_2 * 3) + pub_r001313_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_102 * 3) + pub_r001313_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173 * 2) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_95 * 3) + pub_r001313_17 + 39) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_12 * 3) + pub_r001313_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001313_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001313_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_138 * 3) + pub_r001313_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_32 * 3) + pub_r001313_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_142 * 3) + pub_r001313_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((helper_flow_4 * 3) + pub_r001313_0 + 43) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181 * 2) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001313_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001313_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_161 * 3) + pub_r001313_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_128 * 3) + pub_r001313_5 + 32) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_173 * 3) + pub_r001313_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001313_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001313_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001313_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_181 * 3) + pub_r001313_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001313_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001313_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001313_18 * 3) + pub_r001313_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001313_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_143 * 3) + pub_r001313_5 + 43) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_150 * 3) + pub_r001313_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_171 * 3) + pub_r001313_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_3 * 3) + pub_r001313_15 + 16) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198 * 2) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001313_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_198 * 3) + pub_r001313_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200 * 2) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001313_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_120 * 3) + pub_r001313_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001313_0 * 3) + pub_r001313_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203 * 2) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001313_1 * 3) + pub_r001313_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001313_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001313_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001313_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_181 * 3) + pub_r001313_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_134 * 3) + pub_r001313_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209 * 2) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r001313_2 * 3) + pub_r001313_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001313_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001313_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_88 * 3) + pub_r001313_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001313_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r001313_9 * 3) + pub_r001313_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001313_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_91 * 3) + pub_r001313_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001313_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001313_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_202 * 3) + pub_r001313_10 + 16) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220 * 2) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_112 * 3) + pub_r001313_3 + 39) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001313_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_139 * 3) + pub_r001313_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_145 * 3) + pub_r001313_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001313_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_95 * 3) + pub_r001313_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001313_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001313_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_92 * 3) + pub_r001313_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001313_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001313_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001313_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001313_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_208 * 3) + pub_r001313_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_208 * 3) + pub_r001313_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_198 * 3) + pub_r001313_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_60 * 3) + pub_r001313_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001313_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001313_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001313_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_235 * 3) + pub_r001313_10 + 41) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241 * 2) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_72 * 3) + pub_r001313_2 + 39) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242 * 2) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001313_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_103 * 3) + pub_r001313_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001313_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001313_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001313_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001313_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001313_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((sec_r001313_7 * 3) + pub_r001313_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250 * 2) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_169 * 3) + pub_r001313_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_185 * 3) + pub_r001313_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252 * 2) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_44 * 3) + pub_r001313_5 + 44) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001313_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_220 * 3) + pub_r001313_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255 * 2) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_119 * 3) + pub_r001313_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001313_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001313_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_23 * 3) + pub_r001313_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_11 * 3) + pub_r001313_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260 * 2) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_204 * 3) + pub_r001313_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_260 * 3) + pub_r001313_15 + 39) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001313_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_21 * 3) + pub_r001313_15 + 9) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001313_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001313_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_193 * 3) + pub_r001313_5 + 3) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_12 * 3) + pub_r001313_4 + 26) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_21 * 3) + pub_r001313_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001313_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001313_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001313_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_208 * 3) + pub_r001313_17 + 35) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001313_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001313_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001313_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_161 * 3) + pub_r001313_8 + 44) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_178 * 3) + pub_r001313_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_236 * 3) + pub_r001313_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001313_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001313_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001313_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_157 * 3) + pub_r001313_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283 * 2) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_161 * 3) + pub_r001313_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_213 * 3) + pub_r001313_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((sec_r001313_8 * 3) + pub_r001313_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001313_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r001313_2 * 3) + pub_r001313_2 + 22) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288 * 2) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_273 * 3) + pub_r001313_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289 * 2) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_92 * 3) + pub_r001313_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001313_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001313_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_134 * 3) + pub_r001313_1 + 39) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001313_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((helper_flow_3 * 3) + pub_r001313_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_17 * 3) + pub_r001313_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_143 * 3) + pub_r001313_16 + 29) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297 * 2) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001313_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001313_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_21 * 3) + pub_r001313_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_224 * 3) + pub_r001313_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001313_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001313_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001313_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001313_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001313_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_180 * 3) + pub_r001313_10 + 22) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_242 * 3) + pub_r001313_4 + 13) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308 * 2) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r001313_11 * 3) + pub_r001313_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_262 * 3) + pub_r001313_14 + 38) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((sec_r001313_9 * 3) + pub_r001313_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001313_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_11 * 3) + pub_r001313_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313 * 2) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001313_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001313_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_166 * 3) + pub_r001313_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316 * 2) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001313_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_120 * 3) + pub_r001313_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001313_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_72 * 3) + pub_r001313_12 + 26) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001313_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((sec_r001313_17 * 3) + pub_r001313_7 + 40) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((sec_r001313_14 * 3) + pub_r001313_2 + 41) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001313_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((sec_r001313_13 * 3) + pub_r001313_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325 * 2) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_111 * 3) + pub_r001313_15 + 40) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001313_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_313 * 3) + pub_r001313_0 + 15) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001313_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_126 * 3) + pub_r001313_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((sec_r001313_1 * 3) + pub_r001313_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_293 * 3) + pub_r001313_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332 * 2) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_179 * 3) + pub_r001313_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_204 * 3) + pub_r001313_16 + 29) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001313_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_220 * 3) + pub_r001313_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336 * 2) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_33 * 3) + pub_r001313_14 + 28) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337 * 2) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_260 * 3) + pub_r001313_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_229 * 3) + pub_r001313_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339 * 2) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_175 * 3) + pub_r001313_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001313_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_297 * 3) + pub_r001313_13 + 30) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_102 * 3) + pub_r001313_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001313_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001313_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((sec_r001313_2 * 3) + pub_r001313_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001313_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_113 * 3) + pub_r001313_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001313_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001313_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001313_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001313_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_33 * 3) + pub_r001313_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001313_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_133 * 3) + pub_r001313_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((sec_r001313_15 * 3) + pub_r001313_0 + 5) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356 * 2) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001313_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_139 * 3) + pub_r001313_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_52 * 3) + pub_r001313_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001313_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_2 * 3) + pub_r001313_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361 * 2) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001313_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_21 * 3) + pub_r001313_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363 * 2) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001313_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_2 * 3) + pub_r001313_15 + 41) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365 * 2) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001313_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_173 * 3) + pub_r001313_1 + 12) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001313_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001313_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_51 * 3) + pub_r001313_15 + 15) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001313_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001313_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_361 * 3) + pub_r001313_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_134 * 3) + pub_r001313_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_370 * 3) + pub_r001313_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375 * 2) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001313_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001313_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001313_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001313_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001313_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_10 * 3) + pub_r001313_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001313_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_297 * 3) + pub_r001313_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_100 * 3) + pub_r001313_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_384) & 255;
    out_sink = (out_sink + stage_v_384 * 2) & 255;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001313_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_224 * 3) + pub_r001313_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001313_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_367 * 3) + pub_r001313_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_388) & 255;
    out_sink = (out_sink + stage_v_388 * 2) & 255;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001313_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_149 * 3) + pub_r001313_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001313_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001313_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001313_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_244 * 3) + pub_r001313_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001313_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_273 * 3) + pub_r001313_14 + 18) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_186 * 3) + pub_r001313_13 + 39) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_32 * 3) + pub_r001313_12 + 25) & 127;
    sec_accum = (sec_accum + stage_v_398) & 255;
    out_sink = (out_sink + stage_v_398 * 2) & 255;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001313_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((sec_r001313_13 * 3) + pub_r001313_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_400) & 255;
    out_sink = (out_sink + stage_v_400 * 2) & 255;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001313_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_374 * 3) + pub_r001313_11 + 39) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001313_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001313_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001313_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_54 * 3) + pub_r001313_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_406) & 255;
    out_sink = (out_sink + stage_v_406 * 2) & 255;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001313_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001313_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001313_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_60 * 3) + pub_r001313_12 + 25) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001313_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001313_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_53 * 3) + pub_r001313_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_339 * 3) + pub_r001313_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_308 * 3) + pub_r001313_17 + 45) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((sec_r001313_18 * 3) + pub_r001313_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_36 * 3) + pub_r001313_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001313_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_359 * 3) + pub_r001313_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001313_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_288 * 3) + pub_r001313_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001313_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_220 * 3) + pub_r001313_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001313_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001313_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((sec_r001313_15 * 3) + pub_r001313_3 + 4) & 127;
    sec_accum = (sec_accum + stage_v_426) & 255;
    out_sink = (out_sink + stage_v_426 * 2) & 255;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_236 * 3) + pub_r001313_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001313_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001313_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001313_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_342 * 3) + pub_r001313_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_431) & 255;
    out_sink = (out_sink + stage_v_431 * 2) & 255;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001313_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001313_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001313_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_267 * 3) + pub_r001313_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_435) & 255;
    out_sink = (out_sink + stage_v_435 * 2) & 255;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_120 * 3) + pub_r001313_1 + 26) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_200 * 3) + pub_r001313_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_437) & 255;
    out_sink = (out_sink + stage_v_437 * 2) & 255;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((sec_r001313_13 * 3) + pub_r001313_1 + 11) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001313_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001313_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_0 * 3) + pub_r001313_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_441) & 255;
    out_sink = (out_sink + stage_v_441 * 2) & 255;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_260 * 3) + pub_r001313_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((helper_flow_2 * 3) + pub_r001313_6 + 39) & 127;
    sec_accum = (sec_accum + stage_v_443) & 255;
    out_sink = (out_sink + stage_v_443 * 2) & 255;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001313_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001313_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_112 * 3) + pub_r001313_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001313_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_111 * 3) + pub_r001313_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_172 * 3) + pub_r001313_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((sec_r001313_18 * 3) + pub_r001313_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_53 * 3) + pub_r001313_13 + 28) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001313_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001313_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001313_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_398 * 3) + pub_r001313_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_455) & 255;
    out_sink = (out_sink + stage_v_455 * 2) & 255;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_23 * 3) + pub_r001313_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001313_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_142 * 3) + pub_r001313_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_458) & 255;
    out_sink = (out_sink + stage_v_458 * 2) & 255;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_323 * 3) + pub_r001313_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_459) & 255;
    out_sink = (out_sink + stage_v_459 * 2) & 255;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001313_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_307 * 3) + pub_r001313_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001313_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001313_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_190 * 3) + pub_r001313_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_464) & 255;
    out_sink = (out_sink + stage_v_464 * 2) & 255;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001313_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001313_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_269 * 3) + pub_r001313_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_467) & 255;
    out_sink = (out_sink + stage_v_467 * 2) & 255;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001313_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = ((stage_v_158 * 3) + pub_r001313_12 + 41) & 127;
    sec_accum = (sec_accum + stage_v_469) & 255;
    out_sink = (out_sink + stage_v_469 * 2) & 255;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001313_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_442 * 3) + pub_r001313_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_471) & 255;
    out_sink = (out_sink + stage_v_471 * 2) & 255;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_229 * 3) + pub_r001313_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_472) & 255;
    out_sink = (out_sink + stage_v_472 * 2) & 255;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_204 * 3) + pub_r001313_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_473) & 255;
    out_sink = (out_sink + stage_v_473 * 2) & 255;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_413 * 3) + pub_r001313_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_474) & 255;
    out_sink = (out_sink + stage_v_474 * 2) & 255;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_126 * 3) + pub_r001313_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_475) & 255;
    out_sink = (out_sink + stage_v_475 * 2) & 255;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = ((stage_v_416 * 3) + pub_r001313_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_476) & 255;
    out_sink = (out_sink + stage_v_476 * 2) & 255;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001313_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001313_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = ((stage_v_296 * 3) + pub_r001313_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_479) & 255;
    out_sink = (out_sink + stage_v_479 * 2) & 255;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001313_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001313_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001313_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001313_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001313_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001313_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001313_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001313_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001313_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001313_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001313_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001313_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = ((stage_v_190 * 3) + pub_r001313_0 + 4) & 127;
    sec_accum = (sec_accum + stage_v_492) & 255;
    out_sink = (out_sink + stage_v_492 * 2) & 255;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_492 * 3) + pub_r001313_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_493) & 255;
    out_sink = (out_sink + stage_v_493 * 2) & 255;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = ((stage_v_328 * 3) + pub_r001313_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_494) & 255;
    out_sink = (out_sink + stage_v_494 * 2) & 255;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001313_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001313_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = ((stage_v_290 * 3) + pub_r001313_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_497) & 255;
    out_sink = (out_sink + stage_v_497 * 2) & 255;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001313_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001313_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = ((stage_v_89 * 3) + pub_r001313_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_500) & 255;
    out_sink = (out_sink + stage_v_500 * 2) & 255;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = ((stage_v_492 * 3) + pub_r001313_9 + 40) & 127;
    sec_accum = (sec_accum + stage_v_501) & 255;
    out_sink = (out_sink + stage_v_501 * 2) & 255;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001313_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001313_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = ((stage_v_44 * 3) + pub_r001313_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_504) & 255;
    out_sink = (out_sink + stage_v_504 * 2) & 255;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = ((stage_v_340 * 3) + pub_r001313_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_505) & 255;
    out_sink = (out_sink + stage_v_505 * 2) & 255;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = ((sec_r001313_13 * 3) + pub_r001313_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_506) & 255;
    out_sink = (out_sink + stage_v_506 * 2) & 255;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = ((stage_v_449 * 3) + pub_r001313_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_507) & 255;
    out_sink = (out_sink + stage_v_507 * 2) & 255;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = (pub_r001313_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_508) & 127;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001313_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = ((stage_v_285 * 3) + pub_r001313_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_510) & 255;
    out_sink = (out_sink + stage_v_510 * 2) & 255;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001313_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = ((stage_v_169 * 3) + pub_r001313_7 + 16) & 127;
    sec_accum = (sec_accum + stage_v_512) & 255;
    out_sink = (out_sink + stage_v_512 * 2) & 255;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = (pub_r001313_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_513) & 127;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = ((stage_v_204 * 3) + pub_r001313_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_514) & 255;
    out_sink = (out_sink + stage_v_514 * 2) & 255;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = (pub_r001313_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_515) & 127;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = (pub_r001313_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_516) & 127;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001313_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = ((sec_r001313_16 * 3) + pub_r001313_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_518) & 255;
    out_sink = (out_sink + stage_v_518 * 2) & 255;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = (pub_r001313_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_519) & 127;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = ((stage_v_500 * 3) + pub_r001313_12 + 35) & 127;
    sec_accum = (sec_accum + stage_v_520) & 255;
    out_sink = (out_sink + stage_v_520 * 2) & 255;

    /* Execution Pipeline Stage 521 */
    int stage_v_521 = ((stage_v_441 * 3) + pub_r001313_16 + 39) & 127;
    sec_accum = (sec_accum + stage_v_521) & 255;
    out_sink = (out_sink + stage_v_521 * 2) & 255;

    /* Execution Pipeline Stage 522 */
    int stage_v_522 = (pub_r001313_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_522) & 127;

    /* Execution Pipeline Stage 523 */
    int stage_v_523 = ((stage_v_361 * 3) + pub_r001313_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_523) & 255;
    out_sink = (out_sink + stage_v_523 * 2) & 255;

    /* Execution Pipeline Stage 524 */
    int stage_v_524 = (pub_r001313_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_524) & 127;

    /* Execution Pipeline Stage 525 */
    int stage_v_525 = ((stage_v_400 * 3) + pub_r001313_0 + 38) & 127;
    sec_accum = (sec_accum + stage_v_525) & 255;
    out_sink = (out_sink + stage_v_525 * 2) & 255;

    /* Execution Pipeline Stage 526 */
    int stage_v_526 = ((stage_v_309 * 3) + pub_r001313_6 + 20) & 127;
    sec_accum = (sec_accum + stage_v_526) & 255;
    out_sink = (out_sink + stage_v_526 * 2) & 255;

    /* Execution Pipeline Stage 527 */
    int stage_v_527 = ((stage_v_396 * 3) + pub_r001313_14 + 4) & 127;
    sec_accum = (sec_accum + stage_v_527) & 255;
    out_sink = (out_sink + stage_v_527 * 2) & 255;

    /* Execution Pipeline Stage 528 */
    int stage_v_528 = (pub_r001313_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_528) & 127;

    /* Execution Pipeline Stage 529 */
    int stage_v_529 = ((stage_v_133 * 3) + pub_r001313_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_529) & 255;
    out_sink = (out_sink + stage_v_529 * 2) & 255;

    /* Execution Pipeline Stage 530 */
    int stage_v_530 = (pub_r001313_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_530) & 127;

    /* Execution Pipeline Stage 531 */
    int stage_v_531 = ((stage_v_150 * 3) + pub_r001313_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_531) & 255;
    out_sink = (out_sink + stage_v_531 * 2) & 255;

    /* Execution Pipeline Stage 532 */
    int stage_v_532 = ((stage_v_186 * 3) + pub_r001313_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_532) & 255;
    out_sink = (out_sink + stage_v_532 * 2) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
