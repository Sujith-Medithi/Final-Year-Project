/*
 * Benchmark Program: R001126
 * Security Family: implicit_flow
 * Generator Seed: 612613
 * High Inputs: 19 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001126_2613_0 {
    unsigned char norm_sq;
    unsigned char pitch;
    int coord_x;
    int buffer[3];
};

struct Transaction_R001126_2613_1 {
    short status;
    short balance;
    short auth_code;
    int fee;
    int buffer[3];
};

struct DeviceConfig_R001126_2613_2 {
    short port;
    unsigned char timeout;
    int baud_rate;
    int buffer[3];
};

union ColorPixel_R001126_2613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001126_2613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001126_2613_0(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001126_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int damping_93 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_93 > 12) {
        acc = (acc + damping_93 * 2 + 5) & 127;
        aux ^= (damping_93 & 15);
    } else {
        acc = (acc - damping_93 + 11) & 127;
        aux += 3;
    }
    int margin_32 = 0;
    for (int k = 0; k < 3; k++) {
        margin_32 = (margin_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_32) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001126_2613_1(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001126_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int phase_57 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_57 > 44) {
        acc = (acc + phase_57 * 2 + 5) & 127;
        aux ^= (phase_57 & 15);
    } else {
        acc = (acc - phase_57 + 11) & 127;
        aux += 3;
    }
    int mask_19 = (aux + st.buffer[1]) & 3;
    switch (mask_19) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001126_2613_2(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001126_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int accumulator_90 = (aux + st.buffer[1]) & 3;
    switch (accumulator_90) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_93 = 0;
    for (int k = 0; k < 3; k++) {
        vector_93 = (vector_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_93) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_55 = local_arr[aux % 3];
    acc = (acc + metric_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001126_2613_3(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001126_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_91 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_91 > 22) {
        acc = (acc + pivot_91 * 2 + 5) & 127;
        aux ^= (pivot_91 & 15);
    } else {
        acc = (acc - pivot_91 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_80 = local_arr[aux % 3];
    acc = (acc + tracker_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001126_2613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001126_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int delta_20 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_20 > 42) {
        acc = (acc + delta_20 * 2 + 5) & 127;
        aux ^= (delta_20 & 15);
    } else {
        acc = (acc - delta_20 + 11) & 127;
        aux += 3;
    }
    int scale_14 = 0;
    for (int k = 0; k < 2; k++) {
        scale_14 = (scale_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_14) & 127;
    }
    int index_reg_34 = (aux + st.buffer[1]) & 3;
    switch (index_reg_34) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001126_2613_5(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001126_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int bound_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_71) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_58 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_58 > 20) {
        acc = (acc + quantum_58 * 2 + 5) & 127;
        aux ^= (quantum_58 & 15);
    } else {
        acc = (acc - quantum_58 + 11) & 127;
        aux += 3;
    }
    int tracker_49 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_49 = (tracker_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001126_2613_6(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001126_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int tally_43 = local_arr[aux % 3];
    acc = (acc + tally_43 * 2) & 127;
    int phase_14 = (aux + st.buffer[1]) & 3;
    switch (phase_14) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001126_2613_7(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001126_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int segment_10 = (aux + st.buffer[1]) & 3;
    switch (segment_10) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_84) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_22 = local_arr[aux % 3];
    acc = (acc + offset_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001126_2613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001126_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tally_99 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_99 > 21) {
        acc = (acc + tally_99 * 2 + 5) & 127;
        aux ^= (tally_99 & 15);
    } else {
        acc = (acc - tally_99 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_57 = local_arr[aux % 3];
    acc = (acc + accumulator_57 * 2) & 127;
    int checksum_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_81) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001126_2613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001126_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_41 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_41 = (anchor_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_41) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001126_2613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001126_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int vector_80 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_80 > 17) {
        acc = (acc + vector_80 * 2 + 5) & 127;
        aux ^= (vector_80 & 15);
    } else {
        acc = (acc - vector_80 + 11) & 127;
        aux += 3;
    }
    int vector_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_68) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001126_2613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001126_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int factor_98 = local_arr[aux % 3];
    acc = (acc + factor_98 * 2) & 127;
    int mask_51 = 0;
    for (int k = 0; k < 2; k++) {
        mask_51 = (mask_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_51) & 127;
    }
    int accumulator_69 = (aux + st.buffer[1]) & 3;
    switch (accumulator_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001126_2613_12(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001126_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int stride_26 = local_arr[aux % 3];
    acc = (acc + stride_26 * 2) & 127;
    int tracker_96 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_96 > 18) {
        acc = (acc + tracker_96 * 2 + 5) & 127;
        aux ^= (tracker_96 & 15);
    } else {
        acc = (acc - tracker_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001126_2613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001126_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_11 = (aux + st.buffer[1]) & 3;
    switch (quotient_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001126_2613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001126_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int scale_25 = 0;
    for (int k = 0; k < 3; k++) {
        scale_25 = (scale_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_25) & 127;
    }
    int tally_50 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_50 > 37) {
        acc = (acc + tally_50 * 2 + 5) & 127;
        aux ^= (tally_50 & 15);
    } else {
        acc = (acc - tally_50 + 11) & 127;
        aux += 3;
    }
    int metric_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001126_0;
    int sec_r001126_1;
    int sec_r001126_2;
    int sec_r001126_3;
    int sec_r001126_4;
    int sec_r001126_5;
    int sec_r001126_6;
    int sec_r001126_7;
    int sec_r001126_8;
    int sec_r001126_9;
    int sec_r001126_10;
    int sec_r001126_11;
    int sec_r001126_12;
    int sec_r001126_13;
    int sec_r001126_14;
    int sec_r001126_15;
    int sec_r001126_16;
    int sec_r001126_17;
    int sec_r001126_18;
    int pub_r001126_0;
    int pub_r001126_1;
    int pub_r001126_2;
    int pub_r001126_3;
    int pub_r001126_4;
    int pub_r001126_5;
    int pub_r001126_6;
    int pub_r001126_7;
    int pub_r001126_8;
    int pub_r001126_9;
    int pub_r001126_10;
    int pub_r001126_11;
    int pub_r001126_12;
    int pub_r001126_13;
    int pub_r001126_14;
    int pub_r001126_15;
    int pub_r001126_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001126_0 >= -100 && pub_r001126_0 <= 100);
    __CPROVER_assume(pub_r001126_1 >= -100 && pub_r001126_1 <= 100);
    __CPROVER_assume(pub_r001126_2 >= -100 && pub_r001126_2 <= 100);
    __CPROVER_assume(pub_r001126_3 >= -100 && pub_r001126_3 <= 100);
    __CPROVER_assume(pub_r001126_4 >= -100 && pub_r001126_4 <= 100);
    __CPROVER_assume(pub_r001126_5 >= -100 && pub_r001126_5 <= 100);
    __CPROVER_assume(pub_r001126_6 >= -100 && pub_r001126_6 <= 100);
    __CPROVER_assume(pub_r001126_7 >= -100 && pub_r001126_7 <= 100);
    __CPROVER_assume(pub_r001126_8 >= -100 && pub_r001126_8 <= 100);
    __CPROVER_assume(pub_r001126_9 >= -100 && pub_r001126_9 <= 100);
    __CPROVER_assume(pub_r001126_10 >= -100 && pub_r001126_10 <= 100);
    __CPROVER_assume(pub_r001126_11 >= -100 && pub_r001126_11 <= 100);
    __CPROVER_assume(pub_r001126_12 >= -100 && pub_r001126_12 <= 100);
    __CPROVER_assume(pub_r001126_13 >= -100 && pub_r001126_13 <= 100);
    __CPROVER_assume(pub_r001126_14 >= -100 && pub_r001126_14 <= 100);
    __CPROVER_assume(pub_r001126_15 >= -100 && pub_r001126_15 <= 100);
    __CPROVER_assume(pub_r001126_16 >= -100 && pub_r001126_16 <= 100);
    __CPROVER_assume(sec_r001126_0 >= 0 && sec_r001126_0 <= 255);
    __CPROVER_assume(sec_r001126_1 >= 0 && sec_r001126_1 <= 255);
    __CPROVER_assume(sec_r001126_2 >= 0 && sec_r001126_2 <= 255);
    __CPROVER_assume(sec_r001126_3 >= 0 && sec_r001126_3 <= 255);
    __CPROVER_assume(sec_r001126_4 >= 0 && sec_r001126_4 <= 255);
    __CPROVER_assume(sec_r001126_5 >= 0 && sec_r001126_5 <= 255);
    __CPROVER_assume(sec_r001126_6 >= 0 && sec_r001126_6 <= 255);
    __CPROVER_assume(sec_r001126_7 >= 0 && sec_r001126_7 <= 255);
    __CPROVER_assume(sec_r001126_8 >= 0 && sec_r001126_8 <= 255);
    __CPROVER_assume(sec_r001126_9 >= 0 && sec_r001126_9 <= 255);
    __CPROVER_assume(sec_r001126_10 >= 0 && sec_r001126_10 <= 255);
    __CPROVER_assume(sec_r001126_11 >= 0 && sec_r001126_11 <= 255);
    __CPROVER_assume(sec_r001126_12 >= 0 && sec_r001126_12 <= 255);
    __CPROVER_assume(sec_r001126_13 >= 0 && sec_r001126_13 <= 255);
    __CPROVER_assume(sec_r001126_14 >= 0 && sec_r001126_14 <= 255);
    __CPROVER_assume(sec_r001126_15 >= 0 && sec_r001126_15 <= 255);
    __CPROVER_assume(sec_r001126_16 >= 0 && sec_r001126_16 <= 255);
    __CPROVER_assume(sec_r001126_17 >= 0 && sec_r001126_17 <= 255);
    __CPROVER_assume(sec_r001126_18 >= 0 && sec_r001126_18 <= 255);

    struct Vector3D_R001126_2613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001126_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001126_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001126_0 + 7) & 15;
    struct Transaction_R001126_2613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001126_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001126_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001126_0 + 9) & 15;
    struct DeviceConfig_R001126_2613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001126_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001126_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001126_0 + 11) & 15;

    union ColorPixel_R001126_2613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001126_2613_0(sec_r001126_0, sec_r001126_1, pub_r001126_2);
    int helper_flow_1 = fn_R001126_2613_1(sec_r001126_1, sec_r001126_2, pub_r001126_3);
    int helper_flow_2 = fn_R001126_2613_2(sec_r001126_2, sec_r001126_3);
    int helper_flow_3 = fn_R001126_2613_3(sec_r001126_3, pub_r001126_4, pub_r001126_5);
    int helper_flow_4 = fn_R001126_2613_4(sec_r001126_4, pub_r001126_5, pub_r001126_6, pub_r001126_7, pub_r001126_8);
    int helper_flow_5 = fn_R001126_2613_5(sec_r001126_5, pub_r001126_6);
    int helper_flow_6 = fn_R001126_2613_6(sec_r001126_6, sec_r001126_7, pub_r001126_8);
    int helper_flow_7 = fn_R001126_2613_7(sec_r001126_7, sec_r001126_8);
    int helper_flow_8 = fn_R001126_2613_8(sec_r001126_8, sec_r001126_9, pub_r001126_10, pub_r001126_11, pub_r001126_12);
    int helper_flow_9 = fn_R001126_2613_9(sec_r001126_9, pub_r001126_10, pub_r001126_11, pub_r001126_12);
    int helper_flow_10 = fn_R001126_2613_10(sec_r001126_10, pub_r001126_11, pub_r001126_12, pub_r001126_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001126_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001126_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_3 + pub_r001126_8 * 2 + 11) & 127;
    if (stage_v_2 > 54) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001126_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001126_12 + pub_r001126_8 * 2 + 17) & 127;
    if (stage_v_4 > 48) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_6 + pub_r001126_4 * 2 + 20) & 127;
    if (stage_v_5 > 46) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001126_13 + pub_r001126_13 * 2 + 23) & 127;
    if (stage_v_6 > 55) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001126_1 + pub_r001126_16 * 2 + 26) & 127;
    if (stage_v_7 > 35) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001126_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_7 + pub_r001126_2 * 2 + 32) & 127;
    if (stage_v_9 > 42) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001126_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001126_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_1 + pub_r001126_14 * 2 + 41) & 127;
    if (stage_v_12 > 36) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001126_11 + pub_r001126_13 * 2 + 44) & 127;
    if (stage_v_13 > 46) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001126_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_1 + pub_r001126_16 * 2 + 50) & 127;
    if (stage_v_15 > 47) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001126_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001126_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001126_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001126_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001126_0 + pub_r001126_2 * 2 + 65) & 127;
    if (stage_v_20 > 25) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001126_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (helper_flow_5 + pub_r001126_11 * 2 + 71) & 127;
    if (stage_v_22 > 46) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001126_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_3 + pub_r001126_3 * 2 + 77) & 127;
    if (stage_v_24 > 25) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001126_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_6 + pub_r001126_6 * 2 + 83) & 127;
    if (stage_v_26 > 22) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_20 + pub_r001126_3 * 2 + 86) & 127;
    if (stage_v_27 > 22) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001126_6 + pub_r001126_5 * 2 + 89) & 127;
    if (stage_v_28 > 50) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001126_15 + pub_r001126_1 * 2 + 92) & 127;
    if (stage_v_29 > 47) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_7 + pub_r001126_16 * 2 + 95) & 127;
    if (stage_v_30 > 21) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001126_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_2 + pub_r001126_2 * 2 + 101) & 127;
    if (stage_v_32 > 56) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001126_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_0 + pub_r001126_0 * 2 + 107) & 127;
    if (stage_v_34 > 55) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_1 + pub_r001126_6 * 2 + 110) & 127;
    if (stage_v_35 > 42) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001126_5 + pub_r001126_5 * 2 + 113) & 127;
    if (stage_v_36 > 41) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_5 + pub_r001126_7 * 2 + 116) & 127;
    if (stage_v_37 > 48) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001126_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (helper_flow_0 + pub_r001126_11 * 2 + 122) & 127;
    if (stage_v_39 > 58) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_9 + pub_r001126_10 * 2 + 125) & 127;
    if (stage_v_40 > 24) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_32 + pub_r001126_1 * 2 + 128) & 127;
    if (stage_v_41 > 49) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001126_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_7 + pub_r001126_14 * 2 + 134) & 127;
    if (stage_v_43 > 52) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001126_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001126_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (helper_flow_4 + pub_r001126_2 * 2 + 143) & 127;
    if (stage_v_46 > 27) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001126_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001126_17 + pub_r001126_1 * 2 + 149) & 127;
    if (stage_v_48 > 56) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001126_11 + pub_r001126_11 * 2 + 152) & 127;
    if (stage_v_49 > 35) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001126_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001126_2 + pub_r001126_1 * 2 + 158) & 127;
    if (stage_v_51 > 30) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001126_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_32 + pub_r001126_12 * 2 + 164) & 127;
    if (stage_v_53 > 50) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001126_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_51 + pub_r001126_12 * 2 + 170) & 127;
    if (stage_v_55 > 38) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_30 + pub_r001126_10 * 2 + 173) & 127;
    if (stage_v_56 > 24) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001126_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_20 + pub_r001126_14 * 2 + 179) & 127;
    if (stage_v_58 > 41) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001126_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (helper_flow_1 + pub_r001126_15 * 2 + 185) & 127;
    if (stage_v_60 > 28) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_27 + pub_r001126_8 * 2 + 188) & 127;
    if (stage_v_61 > 57) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_30 + pub_r001126_12 * 2 + 191) & 127;
    if (stage_v_62 > 60) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001126_5 + pub_r001126_2 * 2 + 194) & 127;
    if (stage_v_63 > 21) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001126_9 + pub_r001126_2 * 2 + 197) & 127;
    if (stage_v_64 > 57) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001126_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_28 + pub_r001126_5 * 2 + 203) & 127;
    if (stage_v_66 > 44) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001126_18 + pub_r001126_0 * 2 + 206) & 127;
    if (stage_v_67 > 51) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_35 + pub_r001126_15 * 2 + 209) & 127;
    if (stage_v_68 > 27) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001126_17 + pub_r001126_12 * 2 + 212) & 127;
    if (stage_v_69 > 48) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_30 + pub_r001126_11 * 2 + 215) & 127;
    if (stage_v_70 > 30) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001126_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001126_16 + pub_r001126_5 * 2 + 221) & 127;
    if (stage_v_72 > 40) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001126_1 + pub_r001126_4 * 2 + 224) & 127;
    if (stage_v_73 > 31) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_28 + pub_r001126_7 * 2 + 227) & 127;
    if (stage_v_74 > 49) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001126_15 + pub_r001126_5 * 2 + 230) & 127;
    if (stage_v_75 > 42) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001126_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001126_13 + pub_r001126_15 * 2 + 236) & 127;
    if (stage_v_77 > 15) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_56 + pub_r001126_6 * 2 + 239) & 127;
    if (stage_v_78 > 37) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001126_8 + pub_r001126_1 * 2 + 242) & 127;
    if (stage_v_79 > 57) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001126_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001126_6 + pub_r001126_7 * 2 + 248) & 127;
    if (stage_v_81 > 49) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_70 + pub_r001126_16 * 2 + 251) & 127;
    if (stage_v_82 > 43) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_36 + pub_r001126_13 * 2 + 254) & 127;
    if (stage_v_83 > 43) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001126_5 + pub_r001126_0 * 2 + 257) & 127;
    if (stage_v_84 > 48) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_67 + pub_r001126_3 * 2 + 260) & 127;
    if (stage_v_85 > 48) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (helper_flow_7 + pub_r001126_7 * 2 + 263) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001126_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001126_9 + pub_r001126_2 * 2 + 269) & 127;
    if (stage_v_88 > 27) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_7 + pub_r001126_6 * 2 + 272) & 127;
    if (stage_v_89 > 51) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001126_5 + pub_r001126_6 * 2 + 275) & 127;
    if (stage_v_90 > 33) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (helper_flow_9 + pub_r001126_13 * 2 + 278) & 127;
    if (stage_v_91 > 43) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (helper_flow_3 + pub_r001126_4 * 2 + 281) & 127;
    if (stage_v_92 > 20) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001126_6 + pub_r001126_8 * 2 + 284) & 127;
    if (stage_v_93 > 42) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_32 + pub_r001126_5 * 2 + 287) & 127;
    if (stage_v_94 > 54) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_70 + pub_r001126_8 * 2 + 290) & 127;
    if (stage_v_95 > 50) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_64 + pub_r001126_0 * 2 + 293) & 127;
    if (stage_v_96 > 46) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_49 + pub_r001126_4 * 2 + 296) & 127;
    if (stage_v_97 > 20) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001126_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001126_7 + pub_r001126_2 * 2 + 302) & 127;
    if (stage_v_99 > 19) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001126_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_13 + pub_r001126_5 * 2 + 308) & 127;
    if (stage_v_101 > 47) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_77 + pub_r001126_12 * 2 + 311) & 127;
    if (stage_v_102 > 19) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (helper_flow_1 + pub_r001126_0 * 2 + 314) & 127;
    if (stage_v_103 > 56) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_6 + pub_r001126_5 * 2 + 317) & 127;
    if (stage_v_104 > 56) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_96 + pub_r001126_0 * 2 + 320) & 127;
    if (stage_v_105 > 60) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_46 + pub_r001126_7 * 2 + 323) & 127;
    if (stage_v_106 > 24) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_4 + pub_r001126_6 * 2 + 326) & 127;
    if (stage_v_107 > 50) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_61 + pub_r001126_16 * 2 + 329) & 127;
    if (stage_v_108 > 16) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_62 + pub_r001126_13 * 2 + 332) & 127;
    if (stage_v_109 > 47) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001126_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_46 + pub_r001126_5 * 2 + 338) & 127;
    if (stage_v_111 > 48) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001126_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001126_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_68 + pub_r001126_6 * 2 + 347) & 127;
    if (stage_v_114 > 18) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001126_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_26 + pub_r001126_1 * 2 + 353) & 127;
    if (stage_v_116 > 38) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001126_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001126_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_34 + pub_r001126_1 * 2 + 362) & 127;
    if (stage_v_119 > 42) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001126_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001126_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_63 + pub_r001126_2 * 2 + 371) & 127;
    if (stage_v_122 > 58) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_101 + pub_r001126_8 * 2 + 374) & 127;
    if (stage_v_123 > 46) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001126_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001126_0 + pub_r001126_14 * 2 + 380) & 127;
    if (stage_v_125 > 23) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (sec_r001126_3 + pub_r001126_14 * 2 + 383) & 127;
    if (stage_v_126 > 45) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001126_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001126_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_82 + pub_r001126_16 * 2 + 392) & 127;
    if (stage_v_129 > 20) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r001126_5 + pub_r001126_0 * 2 + 395) & 127;
    if (stage_v_130 > 28) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_103 + pub_r001126_6 * 2 + 398) & 127;
    if (stage_v_131 > 43) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_46 + pub_r001126_10 * 2 + 401) & 127;
    if (stage_v_132 > 50) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001126_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001126_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001126_10 + pub_r001126_8 * 2 + 410) & 127;
    if (stage_v_135 > 43) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_51 + pub_r001126_3 * 2 + 413) & 127;
    if (stage_v_136 > 38) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001126_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001126_9 + pub_r001126_0 * 2 + 419) & 127;
    if (stage_v_138 > 24) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_88 + pub_r001126_9 * 2 + 422) & 127;
    if (stage_v_139 > 17) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001126_17 + pub_r001126_9 * 2 + 425) & 127;
    if (stage_v_140 > 19) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_12 + pub_r001126_11 * 2 + 428) & 127;
    if (stage_v_141 > 29) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_109 + pub_r001126_14 * 2 + 431) & 127;
    if (stage_v_142 > 39) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_91 + pub_r001126_8 * 2 + 434) & 127;
    if (stage_v_143 > 24) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_27 + pub_r001126_8 * 2 + 437) & 127;
    if (stage_v_144 > 53) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001126_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001126_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (helper_flow_0 + pub_r001126_3 * 2 + 446) & 127;
    if (stage_v_147 > 29) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_81 + pub_r001126_0 * 2 + 449) & 127;
    if (stage_v_148 > 28) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001126_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_9 + pub_r001126_0 * 2 + 455) & 127;
    if (stage_v_150 > 21) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_135 + pub_r001126_6 * 2 + 458) & 127;
    if (stage_v_151 > 24) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001126_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_92 + pub_r001126_11 * 2 + 464) & 127;
    if (stage_v_153 > 41) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r001126_3 + pub_r001126_9 * 2 + 467) & 127;
    if (stage_v_154 > 26) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_2 + pub_r001126_16 * 2 + 470) & 127;
    if (stage_v_155 > 44) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_114 + pub_r001126_7 * 2 + 473) & 127;
    if (stage_v_156 > 53) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_111 + pub_r001126_5 * 2 + 476) & 127;
    if (stage_v_157 > 59) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001126_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001126_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (helper_flow_8 + pub_r001126_15 * 2 + 485) & 127;
    if (stage_v_160 > 39) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001126_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (helper_flow_8 + pub_r001126_2 * 2 + 491) & 127;
    if (stage_v_162 > 50) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_28 + pub_r001126_11 * 2 + 494) & 127;
    if (stage_v_163 > 16) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001126_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_70 + pub_r001126_13 * 2 + 500) & 127;
    if (stage_v_165 > 31) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_102 + pub_r001126_2 * 2 + 503) & 127;
    if (stage_v_166 > 27) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001126_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001126_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001126_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001126_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (helper_flow_10 + pub_r001126_5 * 2 + 518) & 127;
    if (stage_v_171 > 54) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_78 + pub_r001126_16 * 2 + 521) & 127;
    if (stage_v_172 > 54) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_40 + pub_r001126_7 * 2 + 524) & 127;
    if (stage_v_173 > 29) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (helper_flow_6 + pub_r001126_5 * 2 + 527) & 127;
    if (stage_v_174 > 33) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_94 + pub_r001126_0 * 2 + 530) & 127;
    if (stage_v_175 > 58) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (helper_flow_6 + pub_r001126_0 * 2 + 533) & 127;
    if (stage_v_176 > 16) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_104 + pub_r001126_4 * 2 + 536) & 127;
    if (stage_v_177 > 58) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001126_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_143 + pub_r001126_6 * 2 + 542) & 127;
    if (stage_v_179 > 26) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_166 + pub_r001126_0 * 2 + 545) & 127;
    if (stage_v_180 > 54) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_154 + pub_r001126_9 * 2 + 548) & 127;
    if (stage_v_181 > 34) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_103 + pub_r001126_11 * 2 + 551) & 127;
    if (stage_v_182 > 37) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (sec_r001126_3 + pub_r001126_13 * 2 + 554) & 127;
    if (stage_v_183 > 21) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_79 + pub_r001126_15 * 2 + 557) & 127;
    if (stage_v_184 > 45) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_61 + pub_r001126_11 * 2 + 560) & 127;
    if (stage_v_185 > 48) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001126_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (sec_r001126_13 + pub_r001126_0 * 2 + 566) & 127;
    if (stage_v_187 > 24) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_119 + pub_r001126_4 * 2 + 569) & 127;
    if (stage_v_188 > 42) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (sec_r001126_1 + pub_r001126_13 * 2 + 572) & 127;
    if (stage_v_189 > 50) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (sec_r001126_4 + pub_r001126_4 * 2 + 575) & 127;
    if (stage_v_190 > 33) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_83 + pub_r001126_5 * 2 + 578) & 127;
    if (stage_v_191 > 52) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_140 + pub_r001126_10 * 2 + 581) & 127;
    if (stage_v_192 > 23) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001126_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001126_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001126_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (helper_flow_9 + pub_r001126_14 * 2 + 593) & 127;
    if (stage_v_196 > 49) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001126_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_67 + pub_r001126_13 * 2 + 599) & 127;
    if (stage_v_198 > 52) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_94 + pub_r001126_11 * 2 + 602) & 127;
    if (stage_v_199 > 20) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_141 + pub_r001126_10 * 2 + 605) & 127;
    if (stage_v_200 > 15) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_153 + pub_r001126_2 * 2 + 608) & 127;
    if (stage_v_201 > 23) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001126_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001126_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_190 + pub_r001126_14 * 2 + 617) & 127;
    if (stage_v_204 > 33) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_49 + pub_r001126_11 * 2 + 620) & 127;
    if (stage_v_205 > 19) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_29 + pub_r001126_0 * 2 + 623) & 127;
    if (stage_v_206 > 24) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_200 + pub_r001126_8 * 2 + 626) & 127;
    if (stage_v_207 > 34) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_200 + pub_r001126_6 * 2 + 629) & 127;
    if (stage_v_208 > 51) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_101 + pub_r001126_8 * 2 + 632) & 127;
    if (stage_v_209 > 17) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_93 + pub_r001126_3 * 2 + 635) & 127;
    if (stage_v_210 > 17) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_206 + pub_r001126_9 * 2 + 638) & 127;
    if (stage_v_211 > 54) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (helper_flow_4 + pub_r001126_0 * 2 + 641) & 127;
    if (stage_v_212 > 35) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001126_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_62 + pub_r001126_3 * 2 + 647) & 127;
    if (stage_v_214 > 37) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_36 + pub_r001126_11 * 2 + 650) & 127;
    if (stage_v_215 > 60) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_188 + pub_r001126_1 * 2 + 653) & 127;
    if (stage_v_216 > 60) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_5 + pub_r001126_14 * 2 + 656) & 127;
    if (stage_v_217 > 35) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001126_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_144 + pub_r001126_12 * 2 + 662) & 127;
    if (stage_v_219 > 54) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001126_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001126_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001126_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_81 + pub_r001126_11 * 2 + 674) & 127;
    if (stage_v_223 > 59) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001126_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_77 + pub_r001126_14 * 2 + 680) & 127;
    if (stage_v_225 > 42) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001126_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_177 + pub_r001126_3 * 2 + 686) & 127;
    if (stage_v_227 > 52) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001126_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_84 + pub_r001126_14 * 2 + 692) & 127;
    if (stage_v_229 > 20) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (sec_r001126_2 + pub_r001126_7 * 2 + 695) & 127;
    if (stage_v_230 > 50) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (helper_flow_5 + pub_r001126_13 * 2 + 698) & 127;
    if (stage_v_231 > 26) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001126_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_96 + pub_r001126_14 * 2 + 704) & 127;
    if (stage_v_233 > 39) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_104 + pub_r001126_16 * 2 + 707) & 127;
    if (stage_v_234 > 42) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (sec_r001126_15 + pub_r001126_9 * 2 + 710) & 127;
    if (stage_v_235 > 30) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001126_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001126_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_165 + pub_r001126_16 * 2 + 719) & 127;
    if (stage_v_238 > 42) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_109 + pub_r001126_5 * 2 + 722) & 127;
    if (stage_v_239 > 22) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_184 + pub_r001126_12 * 2 + 725) & 127;
    if (stage_v_240 > 41) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_231 + pub_r001126_16 * 2 + 728) & 127;
    if (stage_v_241 > 28) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001126_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
