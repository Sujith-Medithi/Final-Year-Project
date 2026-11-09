/*
 * Benchmark Program: R001293
 * Security Family: multi_step_explicit
 * Generator Seed: 629313
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001293_9313_0 {
    unsigned char pitch;
    int norm_sq;
    short coord_x;
    int buffer[3];
};

struct DeviceConfig_R001293_9313_1 {
    int timeout;
    int port;
    unsigned char id;
    short parity;
    int baud_rate;
    int stop_bits;
    int buffer[3];
};

union RegisterBank_R001293_9313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001293_9313_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001293_9313_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_71 = local_arr[aux % 3];
    acc = (acc + bound_71 * 2) & 127;
    int mask_95 = 0;
    for (int k = 0; k < 2; k++) {
        mask_95 = (mask_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_95) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_1(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001293_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int factor_12 = local_arr[aux % 3];
    acc = (acc + factor_12 * 2) & 127;
    int mask_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_40) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_85 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_85 = (tracker_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_2(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001293_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_78 = 0;
    for (int k = 0; k < 3; k++) {
        delta_78 = (delta_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_78) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_3(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001293_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_72 = 0;
    for (int k = 0; k < 2; k++) {
        delta_72 = (delta_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_72) & 127;
    }
    int coefficient_36 = (aux + st.buffer[1]) & 3;
    switch (coefficient_36) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_62 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_62 > 41) {
        acc = (acc + anchor_62 * 2 + 5) & 127;
        aux ^= (anchor_62 & 15);
    } else {
        acc = (acc - anchor_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int tally_92 = local_arr[aux % 3];
    acc = (acc + tally_92 * 2) & 127;
    int anchor_56 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_56 = (anchor_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_56) & 127;
    }
    int quantum_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_81) & 63;
    acc ^= aux;
    int residue_16 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_16 > 47) {
        acc = (acc + residue_16 * 2 + 5) & 127;
        aux ^= (residue_16 & 15);
    } else {
        acc = (acc - residue_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_5(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quantum_95 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_95 > 46) {
        acc = (acc + quantum_95 * 2 + 5) & 127;
        aux ^= (quantum_95 & 15);
    } else {
        acc = (acc - quantum_95 + 11) & 127;
        aux += 3;
    }
    int stride_96 = (aux + st.buffer[1]) & 3;
    switch (stride_96) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_83 = 0;
    for (int k = 0; k < 2; k++) {
        window_83 = (window_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_6(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int pivot_61 = local_arr[aux % 3];
    acc = (acc + pivot_61 * 2) & 127;
    int tally_29 = 0;
    for (int k = 0; k < 2; k++) {
        tally_29 = (tally_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_29) & 127;
    }
    int accumulator_74 = (aux + st.buffer[1]) & 3;
    switch (accumulator_74) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_7(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_11 = (aux + st.buffer[1]) & 3;
    switch (delta_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_42) & 63;
    acc ^= aux;
    int vector_52 = 0;
    for (int k = 0; k < 2; k++) {
        vector_52 = (vector_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_52) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001293_9313_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_19 = (aux + st.buffer[1]) & 3;
    switch (bound_19) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_85 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_85 = (accumulator_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int scale_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_84) & 63;
    acc ^= aux;
    int accumulator_39 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_39 > 13) {
        acc = (acc + accumulator_39 * 2 + 5) & 127;
        aux ^= (accumulator_39 & 15);
    } else {
        acc = (acc - accumulator_39 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_12 = (aux + st.buffer[1]) & 3;
    switch (cursor_12) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_10(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001293_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int residue_75 = (aux + st.buffer[1]) & 3;
    switch (residue_75) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_88 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_88 > 44) {
        acc = (acc + pivot_88 * 2 + 5) & 127;
        aux ^= (pivot_88 & 15);
    } else {
        acc = (acc - pivot_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int anchor_50 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_50 > 18) {
        acc = (acc + anchor_50 * 2 + 5) & 127;
        aux ^= (anchor_50 & 15);
    } else {
        acc = (acc - anchor_50 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_35 = local_arr[aux % 3];
    acc = (acc + damping_35 * 2) & 127;
    int tally_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_52) & 63;
    acc ^= aux;
    int window_81 = (aux + st.buffer[1]) & 3;
    switch (window_81) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_12) & 63;
    acc ^= aux;
    int anchor_43 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_43 > 43) {
        acc = (acc + anchor_43 * 2 + 5) & 127;
        aux ^= (anchor_43 & 15);
    } else {
        acc = (acc - anchor_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_37 = (aux + st.buffer[1]) & 3;
    switch (coefficient_37) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001293_9313_13(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001293_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int margin_23 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_23 > 29) {
        acc = (acc + margin_23 * 2 + 5) & 127;
        aux ^= (margin_23 & 15);
    } else {
        acc = (acc - margin_23 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_22 = local_arr[aux % 3];
    acc = (acc + mask_22 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001293_0;
    int sec_r001293_1;
    int sec_r001293_2;
    int sec_r001293_3;
    int sec_r001293_4;
    int sec_r001293_5;
    int sec_r001293_6;
    int sec_r001293_7;
    int sec_r001293_8;
    int sec_r001293_9;
    int sec_r001293_10;
    int sec_r001293_11;
    int sec_r001293_12;
    int sec_r001293_13;
    int sec_r001293_14;
    int sec_r001293_15;
    int sec_r001293_16;
    int pub_r001293_0;
    int pub_r001293_1;
    int pub_r001293_2;
    int pub_r001293_3;
    int pub_r001293_4;
    int pub_r001293_5;
    int pub_r001293_6;
    int pub_r001293_7;
    int pub_r001293_8;
    int pub_r001293_9;
    int pub_r001293_10;
    int pub_r001293_11;
    int pub_r001293_12;
    int pub_r001293_13;
    int pub_r001293_14;
    int pub_r001293_15;
    int pub_r001293_16;
    int pub_r001293_17;
    int pub_r001293_18;
    int pub_r001293_19;
    int pub_r001293_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001293_0 >= -100 && pub_r001293_0 <= 100);
    __CPROVER_assume(pub_r001293_1 >= -100 && pub_r001293_1 <= 100);
    __CPROVER_assume(pub_r001293_2 >= -100 && pub_r001293_2 <= 100);
    __CPROVER_assume(pub_r001293_3 >= -100 && pub_r001293_3 <= 100);
    __CPROVER_assume(pub_r001293_4 >= -100 && pub_r001293_4 <= 100);
    __CPROVER_assume(pub_r001293_5 >= -100 && pub_r001293_5 <= 100);
    __CPROVER_assume(pub_r001293_6 >= -100 && pub_r001293_6 <= 100);
    __CPROVER_assume(pub_r001293_7 >= -100 && pub_r001293_7 <= 100);
    __CPROVER_assume(pub_r001293_8 >= -100 && pub_r001293_8 <= 100);
    __CPROVER_assume(pub_r001293_9 >= -100 && pub_r001293_9 <= 100);
    __CPROVER_assume(pub_r001293_10 >= -100 && pub_r001293_10 <= 100);
    __CPROVER_assume(pub_r001293_11 >= -100 && pub_r001293_11 <= 100);
    __CPROVER_assume(pub_r001293_12 >= -100 && pub_r001293_12 <= 100);
    __CPROVER_assume(pub_r001293_13 >= -100 && pub_r001293_13 <= 100);
    __CPROVER_assume(pub_r001293_14 >= -100 && pub_r001293_14 <= 100);
    __CPROVER_assume(pub_r001293_15 >= -100 && pub_r001293_15 <= 100);
    __CPROVER_assume(pub_r001293_16 >= -100 && pub_r001293_16 <= 100);
    __CPROVER_assume(pub_r001293_17 >= -100 && pub_r001293_17 <= 100);
    __CPROVER_assume(pub_r001293_18 >= -100 && pub_r001293_18 <= 100);
    __CPROVER_assume(pub_r001293_19 >= -100 && pub_r001293_19 <= 100);
    __CPROVER_assume(pub_r001293_20 >= -100 && pub_r001293_20 <= 100);
    __CPROVER_assume(sec_r001293_0 >= 0 && sec_r001293_0 <= 255);
    __CPROVER_assume(sec_r001293_1 >= 0 && sec_r001293_1 <= 255);
    __CPROVER_assume(sec_r001293_2 >= 0 && sec_r001293_2 <= 255);
    __CPROVER_assume(sec_r001293_3 >= 0 && sec_r001293_3 <= 255);
    __CPROVER_assume(sec_r001293_4 >= 0 && sec_r001293_4 <= 255);
    __CPROVER_assume(sec_r001293_5 >= 0 && sec_r001293_5 <= 255);
    __CPROVER_assume(sec_r001293_6 >= 0 && sec_r001293_6 <= 255);
    __CPROVER_assume(sec_r001293_7 >= 0 && sec_r001293_7 <= 255);
    __CPROVER_assume(sec_r001293_8 >= 0 && sec_r001293_8 <= 255);
    __CPROVER_assume(sec_r001293_9 >= 0 && sec_r001293_9 <= 255);
    __CPROVER_assume(sec_r001293_10 >= 0 && sec_r001293_10 <= 255);
    __CPROVER_assume(sec_r001293_11 >= 0 && sec_r001293_11 <= 255);
    __CPROVER_assume(sec_r001293_12 >= 0 && sec_r001293_12 <= 255);
    __CPROVER_assume(sec_r001293_13 >= 0 && sec_r001293_13 <= 255);
    __CPROVER_assume(sec_r001293_14 >= 0 && sec_r001293_14 <= 255);
    __CPROVER_assume(sec_r001293_15 >= 0 && sec_r001293_15 <= 255);
    __CPROVER_assume(sec_r001293_16 >= 0 && sec_r001293_16 <= 255);

    struct Vector3D_R001293_9313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001293_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001293_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001293_0 + 7) & 15;
    struct DeviceConfig_R001293_9313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001293_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001293_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001293_0 + 9) & 15;

    union RegisterBank_R001293_9313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001293_9313_0(sec_r001293_0, pub_r001293_1, pub_r001293_2, pub_r001293_3);
    int helper_flow_1 = fn_R001293_9313_1(sec_r001293_1, pub_r001293_2);
    int helper_flow_2 = fn_R001293_9313_2(sec_r001293_2, pub_r001293_3, pub_r001293_4);
    int helper_flow_3 = fn_R001293_9313_3(sec_r001293_3, pub_r001293_4, pub_r001293_5);
    int helper_flow_4 = fn_R001293_9313_4(sec_r001293_4, pub_r001293_5, pub_r001293_6, pub_r001293_7, pub_r001293_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001293_12 * 3) + pub_r001293_14 + 5) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001293_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001293_2 * 3) + pub_r001293_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001293_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001293_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001293_2 * 3) + pub_r001293_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001293_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001293_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001293_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001293_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_5 * 3) + pub_r001293_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001293_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001293_0 * 3) + pub_r001293_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001293_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001293_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001293_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001293_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_10 * 3) + pub_r001293_9 + 44) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001293_13 * 3) + pub_r001293_20 + 3) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_0 * 3) + pub_r001293_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001293_10 * 3) + pub_r001293_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001293_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_1 * 3) + pub_r001293_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001293_8 * 3) + pub_r001293_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_2 * 3) + pub_r001293_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_24) & 255;
    out_sink = (out_sink + stage_v_24 * 2) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_20 * 3) + pub_r001293_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_25) & 255;
    out_sink = (out_sink + stage_v_25 * 2) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001293_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001293_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_5 * 3) + pub_r001293_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_20 * 3) + pub_r001293_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29 * 2) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001293_14 * 3) + pub_r001293_18 + 24) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30 * 2) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001293_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001293_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001293_7 * 3) + pub_r001293_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001293_6 * 3) + pub_r001293_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34 * 2) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001293_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001293_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001293_6 * 3) + pub_r001293_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37 * 2) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_24 * 3) + pub_r001293_11 + 12) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38 * 2) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_24 * 3) + pub_r001293_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39 * 2) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001293_9 * 3) + pub_r001293_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_18 * 3) + pub_r001293_17 + 9) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_40 * 3) + pub_r001293_7 + 27) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42 * 2) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_0 * 3) + pub_r001293_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_18 * 3) + pub_r001293_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001293_2 * 3) + pub_r001293_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45 * 2) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001293_7 * 3) + pub_r001293_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46 * 2) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001293_0 * 3) + pub_r001293_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001293_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001293_6 * 3) + pub_r001293_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49 * 2) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_18 * 3) + pub_r001293_0 + 12) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001293_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001293_8 * 3) + pub_r001293_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001293_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001293_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001293_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001293_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001293_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001293_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_10 * 3) + pub_r001293_9 + 42) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59 * 2) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001293_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_12 * 3) + pub_r001293_16 + 8) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61 * 2) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001293_15 * 3) + pub_r001293_19 + 8) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62 * 2) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001293_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001293_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001293_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001293_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001293_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_45 * 3) + pub_r001293_6 + 10) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_20 * 3) + pub_r001293_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69 * 2) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001293_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001293_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001293_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001293_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001293_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001293_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001293_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001293_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_69 * 3) + pub_r001293_20 + 44) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_69 * 3) + pub_r001293_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001293_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001293_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_23 * 3) + pub_r001293_20 + 42) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82 * 2) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_39 * 3) + pub_r001293_2 + 38) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((helper_flow_4 * 3) + pub_r001293_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84 * 2) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001293_3 * 3) + pub_r001293_17 + 16) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85 * 2) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((helper_flow_2 * 3) + pub_r001293_20 + 40) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r001293_10 * 3) + pub_r001293_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001293_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((helper_flow_4 * 3) + pub_r001293_11 + 45) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001293_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((helper_flow_1 * 3) + pub_r001293_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_68 * 3) + pub_r001293_18 + 40) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001293_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001293_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_33 * 3) + pub_r001293_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95 * 2) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001293_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_78 * 3) + pub_r001293_3 + 40) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_33 * 3) + pub_r001293_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_2 * 3) + pub_r001293_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001293_7 * 3) + pub_r001293_12 + 12) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_52 * 3) + pub_r001293_5 + 43) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001293_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_42 * 3) + pub_r001293_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103 * 2) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_85 * 3) + pub_r001293_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_91 * 3) + pub_r001293_2 + 33) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105 * 2) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001293_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001293_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001293_1 * 3) + pub_r001293_12 + 22) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_37 * 3) + pub_r001293_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001293_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_30 * 3) + pub_r001293_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001293_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_62 * 3) + pub_r001293_7 + 14) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001293_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001293_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_113 * 3) + pub_r001293_18 + 43) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001293_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_92 * 3) + pub_r001293_6 + 18) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118 * 2) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_105 * 3) + pub_r001293_7 + 10) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_41 * 3) + pub_r001293_12 + 6) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001293_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001293_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001293_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001293_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_42 * 3) + pub_r001293_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001293_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001293_20 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_25 * 3) + pub_r001293_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_0 * 3) + pub_r001293_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001293_2 * 3) + pub_r001293_13 + 28) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_118 * 3) + pub_r001293_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_69 * 3) + pub_r001293_16 + 32) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132 * 2) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_109 * 3) + pub_r001293_2 + 5) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001293_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_49 * 3) + pub_r001293_16 + 21) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_44 * 3) + pub_r001293_3 + 29) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001293_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001293_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001293_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_120 * 3) + pub_r001293_17 + 37) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140 * 2) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001293_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_68 * 3) + pub_r001293_4 + 10) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001293_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((helper_flow_4 * 3) + pub_r001293_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144 * 2) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_91 * 3) + pub_r001293_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001293_1 * 3) + pub_r001293_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001293_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_28 * 3) + pub_r001293_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_47 * 3) + pub_r001293_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149 * 2) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001293_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001293_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001293_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_145 * 3) + pub_r001293_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153 * 2) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_18 * 3) + pub_r001293_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001293_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001293_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001293_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001293_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_22 * 3) + pub_r001293_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001293_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001293_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001293_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001293_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_84 * 3) + pub_r001293_20 + 14) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((helper_flow_4 * 3) + pub_r001293_17 + 38) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001293_2 * 3) + pub_r001293_20 + 7) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_149 * 3) + pub_r001293_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167 * 2) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001293_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_167 * 3) + pub_r001293_13 + 29) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169 * 2) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_37 * 3) + pub_r001293_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001293_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_79 * 3) + pub_r001293_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_62 * 3) + pub_r001293_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173 * 2) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_78 * 3) + pub_r001293_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001293_2 * 3) + pub_r001293_14 + 18) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((helper_flow_4 * 3) + pub_r001293_12 + 42) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_61 * 3) + pub_r001293_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177 * 2) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001293_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001293_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_41 * 3) + pub_r001293_0 + 33) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001293_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_82 * 3) + pub_r001293_17 + 13) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001293_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001293_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001293_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_28 * 3) + pub_r001293_18 + 21) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r001293_4 * 3) + pub_r001293_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187 * 2) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001293_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001293_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001293_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001293_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001293_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001293_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001293_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_87 * 3) + pub_r001293_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001293_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r001293_11 * 3) + pub_r001293_9 + 44) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001293_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001293_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_175 * 3) + pub_r001293_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200 * 2) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_167 * 3) + pub_r001293_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_37 * 3) + pub_r001293_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001293_8 * 3) + pub_r001293_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203 * 2) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001293_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_0 * 3) + pub_r001293_3 + 9) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001293_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001293_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_24 * 3) + pub_r001293_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001293_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001293_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001293_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r001293_16 * 3) + pub_r001293_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212 * 2) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_46 * 3) + pub_r001293_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_132 * 3) + pub_r001293_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_214) & 255;
    out_sink = (out_sink + stage_v_214 * 2) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001293_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_176 * 3) + pub_r001293_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001293_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_78 * 3) + pub_r001293_20 + 22) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001293_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_23 * 3) + pub_r001293_2 + 16) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220 * 2) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001293_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001293_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_12 * 3) + pub_r001293_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001293_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_83 * 3) + pub_r001293_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225 * 2) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001293_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001293_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001293_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_25 * 3) + pub_r001293_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001293_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_201 * 3) + pub_r001293_19 + 12) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231 * 2) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_30 * 3) + pub_r001293_0 + 44) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232 * 2) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r001293_9 * 3) + pub_r001293_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001293_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_105 * 3) + pub_r001293_11 + 41) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((helper_flow_3 * 3) + pub_r001293_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((sec_r001293_14 * 3) + pub_r001293_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001293_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_149 * 3) + pub_r001293_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001293_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001293_20 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001293_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001293_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_225 * 3) + pub_r001293_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_37 * 3) + pub_r001293_4 + 21) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245 * 2) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001293_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_218 * 3) + pub_r001293_5 + 45) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247 * 2) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_111 * 3) + pub_r001293_14 + 18) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248 * 2) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_218 * 3) + pub_r001293_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249 * 2) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((sec_r001293_5 * 3) + pub_r001293_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250 * 2) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001293_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_229 * 3) + pub_r001293_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252 * 2) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_49 * 3) + pub_r001293_18 + 23) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_89 * 3) + pub_r001293_14 + 38) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r001293_4 * 3) + pub_r001293_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255 * 2) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_225 * 3) + pub_r001293_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r001293_14 * 3) + pub_r001293_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257 * 2) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_34 * 3) + pub_r001293_6 + 27) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258 * 2) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_154 * 3) + pub_r001293_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_44 * 3) + pub_r001293_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260 * 2) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_153 * 3) + pub_r001293_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((sec_r001293_10 * 3) + pub_r001293_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001293_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001293_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001293_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_214 * 3) + pub_r001293_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_176 * 3) + pub_r001293_17 + 28) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001293_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001293_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001293_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_133 * 3) + pub_r001293_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_254 * 3) + pub_r001293_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272 * 2) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001293_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_99 * 3) + pub_r001293_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274 * 2) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_182 * 3) + pub_r001293_11 + 15) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001293_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001293_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001293_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001293_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001293_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001293_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001293_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001293_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_105 * 3) + pub_r001293_19 + 33) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_167 * 3) + pub_r001293_1 + 8) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_253 * 3) + pub_r001293_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001293_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_256 * 3) + pub_r001293_0 + 3) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288 * 2) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_233 * 3) + pub_r001293_18 + 40) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289 * 2) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_113 * 3) + pub_r001293_19 + 10) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((helper_flow_2 * 3) + pub_r001293_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001293_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_200 * 3) + pub_r001293_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001293_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001293_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_69 * 3) + pub_r001293_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001293_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_118 * 3) + pub_r001293_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298 * 2) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_255 * 3) + pub_r001293_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299 * 2) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_39 * 3) + pub_r001293_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_208 * 3) + pub_r001293_10 + 40) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001293_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((sec_r001293_9 * 3) + pub_r001293_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001293_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_225 * 3) + pub_r001293_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001293_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001293_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001293_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001293_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r001293_3 * 3) + pub_r001293_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_40 * 3) + pub_r001293_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001293_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((sec_r001293_12 * 3) + pub_r001293_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313 * 2) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001293_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_41 * 3) + pub_r001293_12 + 45) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001293_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001293_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001293_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001293_20 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001293_20 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001293_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_30 * 3) + pub_r001293_3 + 18) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001293_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001293_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001293_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((sec_r001293_4 * 3) + pub_r001293_12 + 41) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_275 * 3) + pub_r001293_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_82 * 3) + pub_r001293_19 + 3) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_131 * 3) + pub_r001293_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329 * 2) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001293_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_237 * 3) + pub_r001293_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001293_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001293_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001293_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001293_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_98 * 3) + pub_r001293_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336 * 2) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001293_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_101 * 3) + pub_r001293_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001293_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001293_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001293_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_40 * 3) + pub_r001293_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_33 * 3) + pub_r001293_16 + 14) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001293_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_328 * 3) + pub_r001293_16 + 39) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_82 * 3) + pub_r001293_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_89 * 3) + pub_r001293_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001293_20 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_19 * 3) + pub_r001293_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_298 * 3) + pub_r001293_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_298 * 3) + pub_r001293_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_52 * 3) + pub_r001293_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_142 * 3) + pub_r001293_3 + 42) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001293_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001293_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_350 * 3) + pub_r001293_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356 * 2) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_41 * 3) + pub_r001293_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001293_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001293_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001293_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001293_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_303 * 3) + pub_r001293_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_362) & 255;
    out_sink = (out_sink + stage_v_362 * 2) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_351 * 3) + pub_r001293_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363 * 2) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_130 * 3) + pub_r001293_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364 * 2) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001293_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((sec_r001293_2 * 3) + pub_r001293_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001293_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_262 * 3) + pub_r001293_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368 * 2) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_322 * 3) + pub_r001293_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_369) & 255;
    out_sink = (out_sink + stage_v_369 * 2) & 255;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001293_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_225 * 3) + pub_r001293_15 + 22) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001293_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_310 * 3) + pub_r001293_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_39 * 3) + pub_r001293_5 + 25) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_202 * 3) + pub_r001293_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375 * 2) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001293_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_125 * 3) + pub_r001293_17 + 33) & 127;
    sec_accum = (sec_accum + stage_v_377) & 255;
    out_sink = (out_sink + stage_v_377 * 2) & 255;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_45 * 3) + pub_r001293_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378 * 2) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001293_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001293_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001293_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001293_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001293_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001293_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_186 * 3) + pub_r001293_19 + 27) & 127;
    sec_accum = (sec_accum + stage_v_385) & 255;
    out_sink = (out_sink + stage_v_385 * 2) & 255;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001293_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_18 * 3) + pub_r001293_5 + 8) & 127;
    sec_accum = (sec_accum + stage_v_387) & 255;
    out_sink = (out_sink + stage_v_387 * 2) & 255;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001293_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001293_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_313 * 3) + pub_r001293_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((sec_r001293_0 * 3) + pub_r001293_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_391) & 255;
    out_sink = (out_sink + stage_v_391 * 2) & 255;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001293_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_5 * 3) + pub_r001293_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_393) & 255;
    out_sink = (out_sink + stage_v_393 * 2) & 255;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_259 * 3) + pub_r001293_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001293_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_105 * 3) + pub_r001293_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001293_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001293_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001293_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001293_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_2 * 3) + pub_r001293_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_293 * 3) + pub_r001293_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001293_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_298 * 3) + pub_r001293_19 + 14) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_232 * 3) + pub_r001293_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_83 * 3) + pub_r001293_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_406) & 255;
    out_sink = (out_sink + stage_v_406 * 2) & 255;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_116 * 3) + pub_r001293_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_407) & 255;
    out_sink = (out_sink + stage_v_407 * 2) & 255;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001293_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_101 * 3) + pub_r001293_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_409) & 255;
    out_sink = (out_sink + stage_v_409 * 2) & 255;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_391 * 3) + pub_r001293_14 + 41) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001293_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001293_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001293_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((sec_r001293_0 * 3) + pub_r001293_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_349 * 3) + pub_r001293_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001293_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001293_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001293_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001293_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_414 * 3) + pub_r001293_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_420) & 255;
    out_sink = (out_sink + stage_v_420 * 2) & 255;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_415 * 3) + pub_r001293_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001293_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_393 * 3) + pub_r001293_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_271 * 3) + pub_r001293_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_267 * 3) + pub_r001293_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001293_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001293_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_95 * 3) + pub_r001293_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_428) & 255;
    out_sink = (out_sink + stage_v_428 * 2) & 255;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001293_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_25 * 3) + pub_r001293_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_430 * 3) + pub_r001293_7 + 12) & 127;
    sec_accum = (sec_accum + stage_v_431) & 255;
    out_sink = (out_sink + stage_v_431 * 2) & 255;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_393 * 3) + pub_r001293_20 + 10) & 127;
    sec_accum = (sec_accum + stage_v_432) & 255;
    out_sink = (out_sink + stage_v_432 * 2) & 255;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_187 * 3) + pub_r001293_5 + 44) & 127;
    sec_accum = (sec_accum + stage_v_433) & 255;
    out_sink = (out_sink + stage_v_433 * 2) & 255;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001293_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001293_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_29 * 3) + pub_r001293_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001293_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_343 * 3) + pub_r001293_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001293_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
