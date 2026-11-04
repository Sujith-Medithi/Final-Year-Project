/*
 * Benchmark Program: R000836
 * Family: secret_dependent_array
 * Generator Seed: 483613
 * High Inputs: 18 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000836_3613_0 {
    unsigned char port;
    short parity;
    int id;
    int baud_rate;
    unsigned char timeout;
    int stop_bits;
    int buffer[3];
};

struct Vector3D_R000836_3613_1 {
    unsigned char coord_z;
    int coord_y;
    unsigned char norm_sq;
    short coord_x;
    short heading;
    short pitch;
    int buffer[3];
};

union TelemetryField_R000836_3613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000836_3613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_28 = local_arr[aux % 3];
    acc = (acc + residue_28 * 2) & 127;
    int bound_74 = (aux + st.buffer[1]) & 3;
    switch (bound_74) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_94 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_94 > 49) {
        acc = (acc + quantum_94 * 2 + 5) & 127;
        aux ^= (quantum_94 & 15);
    } else {
        acc = (acc - quantum_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_1(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_43 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_43 = (quotient_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_43) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_79 > 10) {
        acc = (acc + factor_79 * 2 + 5) & 127;
        aux ^= (factor_79 & 15);
    } else {
        acc = (acc - factor_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int cursor_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_47) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_61 = local_arr[aux % 3];
    acc = (acc + weight_61 * 2) & 127;
    int index_reg_79 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_79 = (index_reg_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_79) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000836_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int segment_63 = local_arr[aux % 3];
    acc = (acc + segment_63 * 2) & 127;
    int tally_68 = (aux + st.buffer[1]) & 3;
    switch (tally_68) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000836_3613_4(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_71 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_71 > 40) {
        acc = (acc + metric_71 * 2 + 5) & 127;
        aux ^= (metric_71 & 15);
    } else {
        acc = (acc - metric_71 + 11) & 127;
        aux += 3;
    }
    int factor_12 = 0;
    for (int k = 0; k < 2; k++) {
        factor_12 = (factor_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_12) & 127;
    }
    int index_reg_11 = (aux + st.buffer[1]) & 3;
    switch (index_reg_11) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000836_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int phase_22 = (aux + st.buffer[1]) & 3;
    switch (phase_22) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_63 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_63 > 16) {
        acc = (acc + scale_63 * 2 + 5) & 127;
        aux ^= (scale_63 & 15);
    } else {
        acc = (acc - scale_63 + 11) & 127;
        aux += 3;
    }
    int parity_59 = 0;
    for (int k = 0; k < 2; k++) {
        parity_59 = (parity_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_59) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_6(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000836_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_39) & 63;
    acc ^= aux;
    int index_reg_80 = (aux + st.buffer[1]) & 3;
    switch (index_reg_80) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_97 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_97 > 48) {
        acc = (acc + tracker_97 * 2 + 5) & 127;
        aux ^= (tracker_97 & 15);
    } else {
        acc = (acc - tracker_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_7(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000836_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int index_reg_18 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_18 > 41) {
        acc = (acc + index_reg_18 * 2 + 5) & 127;
        aux ^= (index_reg_18 & 15);
    } else {
        acc = (acc - index_reg_18 + 11) & 127;
        aux += 3;
    }
    int checksum_88 = (aux + st.buffer[1]) & 3;
    switch (checksum_88) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_85 = local_arr[aux % 3];
    acc = (acc + weight_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000836_3613_8(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000836_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int window_29 = local_arr[aux % 3];
    acc = (acc + window_29 * 2) & 127;
    int cursor_80 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_80 > 41) {
        acc = (acc + cursor_80 * 2 + 5) & 127;
        aux ^= (cursor_80 & 15);
    } else {
        acc = (acc - cursor_80 + 11) & 127;
        aux += 3;
    }
    int bound_69 = 0;
    for (int k = 0; k < 2; k++) {
        bound_69 = (bound_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_69) & 127;
    }
    int mask_67 = (aux + st.buffer[1]) & 3;
    switch (mask_67) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_84 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_84 > 32) {
        acc = (acc + metric_84 * 2 + 5) & 127;
        aux ^= (metric_84 & 15);
    } else {
        acc = (acc - metric_84 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_85 = local_arr[aux % 3];
    acc = (acc + delta_85 * 2) & 127;
    int residue_80 = (aux + st.buffer[1]) & 3;
    switch (residue_80) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_10(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quantum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_23) & 63;
    acc ^= aux;
    int segment_89 = 0;
    for (int k = 0; k < 2; k++) {
        segment_89 = (segment_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_89) & 127;
    }
    int residue_88 = (aux + st.buffer[1]) & 3;
    switch (residue_88) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_11(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int stride_55 = local_arr[aux % 3];
    acc = (acc + stride_55 * 2) & 127;
    int mask_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_68) & 63;
    acc ^= aux;
    int delta_23 = 0;
    for (int k = 0; k < 2; k++) {
        delta_23 = (delta_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_12(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000836_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_66 = (aux + st.buffer[1]) & 3;
    switch (pivot_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_23 = local_arr[aux % 3];
    acc = (acc + tally_23 * 2) & 127;
    int coefficient_40 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_40 > 17) {
        acc = (acc + coefficient_40 * 2 + 5) & 127;
        aux ^= (coefficient_40 & 15);
    } else {
        acc = (acc - coefficient_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000836_3613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000836_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int coefficient_51 = (aux + st.buffer[1]) & 3;
    switch (coefficient_51) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000836_0;
    int sec_r000836_1;
    int sec_r000836_2;
    int sec_r000836_3;
    int sec_r000836_4;
    int sec_r000836_5;
    int sec_r000836_6;
    int sec_r000836_7;
    int sec_r000836_8;
    int sec_r000836_9;
    int sec_r000836_10;
    int sec_r000836_11;
    int sec_r000836_12;
    int sec_r000836_13;
    int sec_r000836_14;
    int sec_r000836_15;
    int sec_r000836_16;
    int sec_r000836_17;
    int pub_r000836_0;
    int pub_r000836_1;
    int pub_r000836_2;
    int pub_r000836_3;
    int pub_r000836_4;
    int pub_r000836_5;
    int pub_r000836_6;
    int pub_r000836_7;
    int pub_r000836_8;
    int pub_r000836_9;
    int pub_r000836_10;
    int pub_r000836_11;
    int pub_r000836_12;
    int pub_r000836_13;
    int pub_r000836_14;
    int pub_r000836_15;
    int pub_r000836_16;
    int pub_r000836_17;
    int pub_r000836_18;
    int pub_r000836_19;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000836_0 >= -100 && pub_r000836_0 <= 100);
    __CPROVER_assume(pub_r000836_1 >= -100 && pub_r000836_1 <= 100);
    __CPROVER_assume(pub_r000836_2 >= -100 && pub_r000836_2 <= 100);
    __CPROVER_assume(pub_r000836_3 >= -100 && pub_r000836_3 <= 100);
    __CPROVER_assume(pub_r000836_4 >= -100 && pub_r000836_4 <= 100);
    __CPROVER_assume(pub_r000836_5 >= -100 && pub_r000836_5 <= 100);
    __CPROVER_assume(pub_r000836_6 >= -100 && pub_r000836_6 <= 100);
    __CPROVER_assume(pub_r000836_7 >= -100 && pub_r000836_7 <= 100);
    __CPROVER_assume(pub_r000836_8 >= -100 && pub_r000836_8 <= 100);
    __CPROVER_assume(pub_r000836_9 >= -100 && pub_r000836_9 <= 100);
    __CPROVER_assume(pub_r000836_10 >= -100 && pub_r000836_10 <= 100);
    __CPROVER_assume(pub_r000836_11 >= -100 && pub_r000836_11 <= 100);
    __CPROVER_assume(pub_r000836_12 >= -100 && pub_r000836_12 <= 100);
    __CPROVER_assume(pub_r000836_13 >= -100 && pub_r000836_13 <= 100);
    __CPROVER_assume(pub_r000836_14 >= -100 && pub_r000836_14 <= 100);
    __CPROVER_assume(pub_r000836_15 >= -100 && pub_r000836_15 <= 100);
    __CPROVER_assume(pub_r000836_16 >= -100 && pub_r000836_16 <= 100);
    __CPROVER_assume(pub_r000836_17 >= -100 && pub_r000836_17 <= 100);
    __CPROVER_assume(pub_r000836_18 >= -100 && pub_r000836_18 <= 100);
    __CPROVER_assume(pub_r000836_19 >= -100 && pub_r000836_19 <= 100);
    __CPROVER_assume(sec_r000836_0 >= 0 && sec_r000836_0 <= 255);
    __CPROVER_assume(sec_r000836_1 >= 0 && sec_r000836_1 <= 255);
    __CPROVER_assume(sec_r000836_2 >= 0 && sec_r000836_2 <= 255);
    __CPROVER_assume(sec_r000836_3 >= 0 && sec_r000836_3 <= 255);
    __CPROVER_assume(sec_r000836_4 >= 0 && sec_r000836_4 <= 255);
    __CPROVER_assume(sec_r000836_5 >= 0 && sec_r000836_5 <= 255);
    __CPROVER_assume(sec_r000836_6 >= 0 && sec_r000836_6 <= 255);
    __CPROVER_assume(sec_r000836_7 >= 0 && sec_r000836_7 <= 255);
    __CPROVER_assume(sec_r000836_8 >= 0 && sec_r000836_8 <= 255);
    __CPROVER_assume(sec_r000836_9 >= 0 && sec_r000836_9 <= 255);
    __CPROVER_assume(sec_r000836_10 >= 0 && sec_r000836_10 <= 255);
    __CPROVER_assume(sec_r000836_11 >= 0 && sec_r000836_11 <= 255);
    __CPROVER_assume(sec_r000836_12 >= 0 && sec_r000836_12 <= 255);
    __CPROVER_assume(sec_r000836_13 >= 0 && sec_r000836_13 <= 255);
    __CPROVER_assume(sec_r000836_14 >= 0 && sec_r000836_14 <= 255);
    __CPROVER_assume(sec_r000836_15 >= 0 && sec_r000836_15 <= 255);
    __CPROVER_assume(sec_r000836_16 >= 0 && sec_r000836_16 <= 255);
    __CPROVER_assume(sec_r000836_17 >= 0 && sec_r000836_17 <= 255);

    struct DeviceConfig_R000836_3613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000836_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000836_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000836_0 + 7) & 15;
    struct Vector3D_R000836_3613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000836_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000836_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000836_0 + 9) & 15;

    union TelemetryField_R000836_3613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 13) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 28) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 26) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 41) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 15) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 30) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_0.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 36) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 51) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 22) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 37) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 38) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 53) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 36) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 51) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 30) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 45) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_1.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 37) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 52) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[0] ^ 86) & 3;
    switch (stage_v_83) {
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
    int stage_v_86 = (st_var_0.buffer[0] ^ 89) & 3;
    switch (stage_v_86) {
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

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 36) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 51) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 27) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 42) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (out_sink > 100) ? (chk_sum & 31) : (95 & 31);
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= (stage_v_90 << 1) & 127;

    /* Execution Pipeline Stage 91 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 92) & 15;
    int stage_v_91 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= stage_v_91;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_0.buffer[0] ^ 95) & 3;
    switch (stage_v_92) {
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

    /* Execution Pipeline Stage 93 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_0.buffer[0] ^ 101) & 3;
    switch (stage_v_98) {
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

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = table[0];
    table[0] = (table[1] + 201) & 63;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 34) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 49) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 104) & 15;
    int stage_v_103 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= stage_v_103;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_106 = (stage_v_106 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
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

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_0.buffer[0] ^ 113) & 3;
    switch (stage_v_110) {
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

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 15) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 30) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 116) & 15;
    int stage_v_115 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= stage_v_115;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = table[2];
    table[2] = (table[3] + 237) & 63;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = table[0];
    table[0] = (table[1] + 249) & 63;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 126) & 15;
    int stage_v_125 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= stage_v_125;

    /* Execution Pipeline Stage 126 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 127) & 15;
    int stage_v_126 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= stage_v_126;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = table[2];
    table[2] = (table[3] + 261) & 63;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_137 = (stage_v_137 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_0.buffer[0] ^ 141) & 3;
    switch (stage_v_138) {
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

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 142) & 15;
    int stage_v_141 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= stage_v_141;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (out_sink > 100) ? (chk_sum & 31) : (152 & 31);
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= (stage_v_147 << 1) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_0.buffer[1] * 2 + 451) & 63;
    if (stage_v_148 > 20) {
        out_sink = (out_sink + stage_v_148 - 5) & 255;
        if (stage_v_148 > 35) {
            chk_sum ^= (stage_v_148 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_148 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[2] * 2 + 454) & 63;
    if (stage_v_149 > 13) {
        out_sink = (out_sink + stage_v_149 - 5) & 255;
        if (stage_v_149 > 28) {
            chk_sum ^= (stage_v_149 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_149 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
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

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (out_sink > 100) ? (chk_sum & 31) : (156 & 31);
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= (stage_v_151 << 1) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 13) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 28) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_0.buffer[0] ^ 157) & 3;
    switch (stage_v_154) {
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

    /* Execution Pipeline Stage 155 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] * 2 + 475) & 63;
    if (stage_v_156 > 27) {
        out_sink = (out_sink + stage_v_156 - 5) & 255;
        if (stage_v_156 > 42) {
            chk_sum ^= (stage_v_156 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_156 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_0.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 25) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 40) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 162) & 15;
    int stage_v_161 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= stage_v_161;

    /* Execution Pipeline Stage 162 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 165) & 15;
    int stage_v_164 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= stage_v_164;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[1] * 2 + 514) & 63;
    if (stage_v_169 > 16) {
        out_sink = (out_sink + stage_v_169 - 5) & 255;
        if (stage_v_169 > 31) {
            chk_sum ^= (stage_v_169 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_169 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 170 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 171) & 15;
    int stage_v_170 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= stage_v_170;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_171 = (stage_v_171 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (out_sink > 100) ? (chk_sum & 31) : (178 & 31);
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= (stage_v_173 << 1) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] ^ 177) & 3;
    switch (stage_v_174) {
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

    /* Execution Pipeline Stage 175 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 176) & 15;
    int stage_v_175 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= stage_v_175;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_0.buffer[0] ^ 179) & 3;
    switch (stage_v_176) {
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

    /* Execution Pipeline Stage 177 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 178) & 15;
    int stage_v_177 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= stage_v_177;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (out_sink > 100) ? (chk_sum & 31) : (184 & 31);
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= (stage_v_179 << 1) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] ^ 183) & 3;
    switch (stage_v_180) {
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

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = table[1];
    table[1] = (table[2] + 363) & 63;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_184 = (stage_v_184 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_184) & 127;
    }
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (st_var_1.buffer[2] * 2 + 562) & 63;
    if (stage_v_185 > 14) {
        out_sink = (out_sink + stage_v_185 - 5) & 255;
        if (stage_v_185 > 29) {
            chk_sum ^= (stage_v_185 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_185 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_186 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = table[3];
    table[3] = (table[0] + 375) & 63;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 190) & 15;
    int stage_v_189 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_189) & 255;
    chk_sum ^= stage_v_189;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_0.buffer[1] * 2 + 577) & 63;
    if (stage_v_190 > 19) {
        out_sink = (out_sink + stage_v_190 - 5) & 255;
        if (stage_v_190 > 34) {
            chk_sum ^= (stage_v_190 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_190 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_191 = (stage_v_191 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_191) & 127;
    }
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 193 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 194) & 15;
    int stage_v_193 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    chk_sum ^= stage_v_193;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = table[2];
    table[2] = (table[3] + 389) & 63;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_1.buffer[0] ^ 198) & 3;
    switch (stage_v_195) {
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

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = table[0];
    table[0] = (table[1] + 393) & 63;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = table[1];
    table[1] = (table[2] + 395) & 63;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_0.buffer[0] * 2 + 601) & 63;
    if (stage_v_198 > 39) {
        out_sink = (out_sink + stage_v_198 - 5) & 255;
        if (stage_v_198 > 54) {
            chk_sum ^= (stage_v_198 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_198 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_199 = (stage_v_199 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_199) & 127;
    }
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = table[0];
    table[0] = (table[1] + 401) & 63;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_201 = (stage_v_201 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_201) & 127;
    }
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = table[2];
    table[2] = (table[3] + 405) & 63;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = table[3];
    table[3] = (table[0] + 407) & 63;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_204 = (stage_v_204 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_204) & 127;
    }
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (st_var_1.buffer[0] ^ 208) & 3;
    switch (stage_v_205) {
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

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (st_var_0.buffer[0] ^ 209) & 3;
    switch (stage_v_206) {
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

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_207 = (stage_v_207 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_207) & 127;
    }
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = table[0];
    table[0] = (table[1] + 417) & 63;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = table[1];
    table[1] = (table[2] + 419) & 63;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 211) & 15;
    int stage_v_210 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_210) & 255;
    chk_sum ^= stage_v_210;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (st_var_1.buffer[0] ^ 214) & 3;
    switch (stage_v_211) {
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

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = table[0];
    table[0] = (table[1] + 425) & 63;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 61, 98, 30, 55 };
    int s_idx = (sec_r000836_1 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
