/*
 * Benchmark Program: R000897
 * Security Family: nested_implicit_flow
 * Generator Seed: 589713
 * High Inputs: 22 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000897_9713_0 {
    int auth_code;
    int balance;
    unsigned char status;
    int account_id;
    int buffer[3];
};

struct CipherContext_R000897_9713_1 {
    unsigned char flags;
    short iv;
    short tag;
    int round_key;
    int buffer[3];
};

struct Vector3D_R000897_9713_2 {
    unsigned char heading;
    unsigned char norm_sq;
    int coord_y;
    short coord_z;
    int pitch;
    unsigned char coord_x;
    int buffer[3];
};

struct DeviceConfig_R000897_9713_3 {
    int parity;
    unsigned char id;
    int timeout;
    int buffer[3];
};

union ColorPixel_R000897_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000897_9713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int residue_20 = (aux + st.buffer[1]) & 3;
    switch (residue_20) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_54 = local_arr[aux % 3];
    acc = (acc + metric_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_1(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int accumulator_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_81) & 63;
    acc ^= aux;
    int checksum_32 = (aux + st.buffer[1]) & 3;
    switch (checksum_32) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_72 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_72 > 43) {
        acc = (acc + damping_72 * 2 + 5) & 127;
        aux ^= (damping_72 & 15);
    } else {
        acc = (acc - damping_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_2(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000897_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int index_reg_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_75) & 63;
    acc ^= aux;
    int quotient_94 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_94 > 13) {
        acc = (acc + quotient_94 * 2 + 5) & 127;
        aux ^= (quotient_94 & 15);
    } else {
        acc = (acc - quotient_94 + 11) & 127;
        aux += 3;
    }
    int delta_42 = (aux + st.buffer[1]) & 3;
    switch (delta_42) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_3(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000897_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int mask_53 = (aux + st.buffer[1]) & 3;
    switch (mask_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_50) & 63;
    acc ^= aux;
    int parity_16 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_16 > 33) {
        acc = (acc + parity_16 * 2 + 5) & 127;
        aux ^= (parity_16 & 15);
    } else {
        acc = (acc - parity_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_4(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_31 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_31 > 33) {
        acc = (acc + threshold_31 * 2 + 5) & 127;
        aux ^= (threshold_31 & 15);
    } else {
        acc = (acc - threshold_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_38 = local_arr[aux % 3];
    acc = (acc + margin_38 * 2) & 127;
    int anchor_27 = (aux + st.buffer[1]) & 3;
    switch (anchor_27) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_5(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int coefficient_59 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_59 > 50) {
        acc = (acc + coefficient_59 * 2 + 5) & 127;
        aux ^= (coefficient_59 & 15);
    } else {
        acc = (acc - coefficient_59 + 11) & 127;
        aux += 3;
    }
    int quantum_10 = (aux + st.buffer[1]) & 3;
    switch (quantum_10) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int index_reg_48 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_48 > 21) {
        acc = (acc + index_reg_48 * 2 + 5) & 127;
        aux ^= (index_reg_48 & 15);
    } else {
        acc = (acc - index_reg_48 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_78 = (aux + st.buffer[1]) & 3;
    switch (offset_78) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_15 = local_arr[aux % 3];
    acc = (acc + tally_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_62 = (aux + st.buffer[1]) & 3;
    switch (window_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_38 = local_arr[aux % 3];
    acc = (acc + residue_38 * 2) & 127;
    int pivot_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000897_9713_8(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000897_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int factor_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_27) & 63;
    acc ^= aux;
    int metric_99 = (aux + st.buffer[1]) & 3;
    switch (metric_99) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_67 = local_arr[aux % 3];
    acc = (acc + coefficient_67 * 2) & 127;
    int stride_11 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_11 > 14) {
        acc = (acc + stride_11 * 2 + 5) & 127;
        aux ^= (stride_11 & 15);
    } else {
        acc = (acc - stride_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000897_9713_9(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_91 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_91 > 43) {
        acc = (acc + tracker_91 * 2 + 5) & 127;
        aux ^= (tracker_91 & 15);
    } else {
        acc = (acc - tracker_91 + 11) & 127;
        aux += 3;
    }
    int metric_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_45 = local_arr[aux % 3];
    acc = (acc + vector_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_77 = (aux + st.buffer[1]) & 3;
    switch (weight_77) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_55 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_55 > 29) {
        acc = (acc + factor_55 * 2 + 5) & 127;
        aux ^= (factor_55 & 15);
    } else {
        acc = (acc - factor_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_77 = local_arr[aux % 3];
    acc = (acc + checksum_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int anchor_32 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_32 > 40) {
        acc = (acc + anchor_32 * 2 + 5) & 127;
        aux ^= (anchor_32 & 15);
    } else {
        acc = (acc - anchor_32 + 11) & 127;
        aux += 3;
    }
    int delta_42 = (aux + st.buffer[1]) & 3;
    switch (delta_42) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000897_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int segment_62 = (aux + st.buffer[1]) & 3;
    switch (segment_62) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000897_9713_13(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int coefficient_22 = (aux + st.buffer[1]) & 3;
    switch (coefficient_22) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_88) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_38 = local_arr[aux % 3];
    acc = (acc + scale_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000897_9713_14(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000897_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_19 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_19 > 46) {
        acc = (acc + phase_19 * 2 + 5) & 127;
        aux ^= (phase_19 & 15);
    } else {
        acc = (acc - phase_19 + 11) & 127;
        aux += 3;
    }
    int index_reg_74 = (aux + st.buffer[1]) & 3;
    switch (index_reg_74) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000897_0;
    int sec_r000897_1;
    int sec_r000897_2;
    int sec_r000897_3;
    int sec_r000897_4;
    int sec_r000897_5;
    int sec_r000897_6;
    int sec_r000897_7;
    int sec_r000897_8;
    int sec_r000897_9;
    int sec_r000897_10;
    int sec_r000897_11;
    int sec_r000897_12;
    int sec_r000897_13;
    int sec_r000897_14;
    int sec_r000897_15;
    int sec_r000897_16;
    int sec_r000897_17;
    int sec_r000897_18;
    int sec_r000897_19;
    int sec_r000897_20;
    int sec_r000897_21;
    int pub_r000897_0;
    int pub_r000897_1;
    int pub_r000897_2;
    int pub_r000897_3;
    int pub_r000897_4;
    int pub_r000897_5;
    int pub_r000897_6;
    int pub_r000897_7;
    int pub_r000897_8;
    int pub_r000897_9;
    int pub_r000897_10;
    int pub_r000897_11;
    int pub_r000897_12;
    int pub_r000897_13;
    int pub_r000897_14;
    int pub_r000897_15;
    int pub_r000897_16;
    int pub_r000897_17;
    int pub_r000897_18;
    int pub_r000897_19;
    int pub_r000897_20;
    int pub_r000897_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000897_0 >= -100 && pub_r000897_0 <= 100);
    __CPROVER_assume(pub_r000897_1 >= -100 && pub_r000897_1 <= 100);
    __CPROVER_assume(pub_r000897_2 >= -100 && pub_r000897_2 <= 100);
    __CPROVER_assume(pub_r000897_3 >= -100 && pub_r000897_3 <= 100);
    __CPROVER_assume(pub_r000897_4 >= -100 && pub_r000897_4 <= 100);
    __CPROVER_assume(pub_r000897_5 >= -100 && pub_r000897_5 <= 100);
    __CPROVER_assume(pub_r000897_6 >= -100 && pub_r000897_6 <= 100);
    __CPROVER_assume(pub_r000897_7 >= -100 && pub_r000897_7 <= 100);
    __CPROVER_assume(pub_r000897_8 >= -100 && pub_r000897_8 <= 100);
    __CPROVER_assume(pub_r000897_9 >= -100 && pub_r000897_9 <= 100);
    __CPROVER_assume(pub_r000897_10 >= -100 && pub_r000897_10 <= 100);
    __CPROVER_assume(pub_r000897_11 >= -100 && pub_r000897_11 <= 100);
    __CPROVER_assume(pub_r000897_12 >= -100 && pub_r000897_12 <= 100);
    __CPROVER_assume(pub_r000897_13 >= -100 && pub_r000897_13 <= 100);
    __CPROVER_assume(pub_r000897_14 >= -100 && pub_r000897_14 <= 100);
    __CPROVER_assume(pub_r000897_15 >= -100 && pub_r000897_15 <= 100);
    __CPROVER_assume(pub_r000897_16 >= -100 && pub_r000897_16 <= 100);
    __CPROVER_assume(pub_r000897_17 >= -100 && pub_r000897_17 <= 100);
    __CPROVER_assume(pub_r000897_18 >= -100 && pub_r000897_18 <= 100);
    __CPROVER_assume(pub_r000897_19 >= -100 && pub_r000897_19 <= 100);
    __CPROVER_assume(pub_r000897_20 >= -100 && pub_r000897_20 <= 100);
    __CPROVER_assume(pub_r000897_21 >= -100 && pub_r000897_21 <= 100);
    __CPROVER_assume(sec_r000897_0 >= 0 && sec_r000897_0 <= 255);
    __CPROVER_assume(sec_r000897_1 >= 0 && sec_r000897_1 <= 255);
    __CPROVER_assume(sec_r000897_2 >= 0 && sec_r000897_2 <= 255);
    __CPROVER_assume(sec_r000897_3 >= 0 && sec_r000897_3 <= 255);
    __CPROVER_assume(sec_r000897_4 >= 0 && sec_r000897_4 <= 255);
    __CPROVER_assume(sec_r000897_5 >= 0 && sec_r000897_5 <= 255);
    __CPROVER_assume(sec_r000897_6 >= 0 && sec_r000897_6 <= 255);
    __CPROVER_assume(sec_r000897_7 >= 0 && sec_r000897_7 <= 255);
    __CPROVER_assume(sec_r000897_8 >= 0 && sec_r000897_8 <= 255);
    __CPROVER_assume(sec_r000897_9 >= 0 && sec_r000897_9 <= 255);
    __CPROVER_assume(sec_r000897_10 >= 0 && sec_r000897_10 <= 255);
    __CPROVER_assume(sec_r000897_11 >= 0 && sec_r000897_11 <= 255);
    __CPROVER_assume(sec_r000897_12 >= 0 && sec_r000897_12 <= 255);
    __CPROVER_assume(sec_r000897_13 >= 0 && sec_r000897_13 <= 255);
    __CPROVER_assume(sec_r000897_14 >= 0 && sec_r000897_14 <= 255);
    __CPROVER_assume(sec_r000897_15 >= 0 && sec_r000897_15 <= 255);
    __CPROVER_assume(sec_r000897_16 >= 0 && sec_r000897_16 <= 255);
    __CPROVER_assume(sec_r000897_17 >= 0 && sec_r000897_17 <= 255);
    __CPROVER_assume(sec_r000897_18 >= 0 && sec_r000897_18 <= 255);
    __CPROVER_assume(sec_r000897_19 >= 0 && sec_r000897_19 <= 255);
    __CPROVER_assume(sec_r000897_20 >= 0 && sec_r000897_20 <= 255);
    __CPROVER_assume(sec_r000897_21 >= 0 && sec_r000897_21 <= 255);

    struct Transaction_R000897_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000897_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000897_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000897_0 + 7) & 15;
    struct CipherContext_R000897_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000897_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000897_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000897_0 + 9) & 15;
    struct Vector3D_R000897_9713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000897_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000897_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000897_0 + 11) & 15;
    struct DeviceConfig_R000897_9713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000897_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000897_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000897_0 + 13) & 15;

    union ColorPixel_R000897_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 40) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 55) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 22) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 37) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 21) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 36) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 28) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 43) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 34) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 49) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 13) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 28) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 33) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 48) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 22) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 37) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 14) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 29) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 34) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 49) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 31) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 46) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 22) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 37) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 22) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 37) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[0] ^ 82) & 3;
    switch (stage_v_79) {
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

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000897_4 & 1) != 0) {
        if ((sec_r000897_17 & 2) != 0) {
            stage_v_81 = (pub_r000897_13 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000897_13 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000897_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000897_18 & 2) != 0) {
            stage_v_82 = (pub_r000897_6 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000897_6 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000897_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000897_8 & 2) != 0) {
            stage_v_83 = (pub_r000897_0 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000897_0 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000897_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000897_12 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_84 = (pub_r000897_3 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000897_3 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000897_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000897_7 & 1) != 0) {
        if ((sec_r000897_12 & 2) != 0) {
            stage_v_85 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000897_5 & 1) != 0) {
        if ((sec_r000897_12 & 2) != 0) {
            stage_v_86 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000897_14 & 2) != 0) {
            stage_v_87 = (pub_r000897_12 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000897_12 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000897_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000897_21 & 2) != 0) {
            stage_v_88 = (pub_r000897_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000897_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000897_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000897_10 & 2) != 0) {
            stage_v_89 = (pub_r000897_16 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000897_16 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000897_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000897_2 & 2) != 0) {
            stage_v_90 = (pub_r000897_13 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000897_13 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000897_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000897_21 & 1) != 0) {
        if ((sec_r000897_9 & 2) != 0) {
            stage_v_91 = (pub_r000897_18 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000897_18 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000897_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000897_12 & 2) != 0) {
            stage_v_92 = (pub_r000897_14 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000897_14 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000897_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000897_5 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_93 = (pub_r000897_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000897_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000897_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000897_0 & 1) != 0) {
        if ((sec_r000897_18 & 2) != 0) {
            stage_v_94 = (pub_r000897_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000897_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000897_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000897_3 & 2) != 0) {
            stage_v_95 = (pub_r000897_9 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000897_9 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000897_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000897_19 & 1) != 0) {
        if ((sec_r000897_21 & 2) != 0) {
            stage_v_96 = (pub_r000897_9 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000897_9 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000897_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000897_18 & 2) != 0) {
            stage_v_97 = (pub_r000897_2 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000897_2 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000897_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000897_0 & 2) != 0) {
            stage_v_98 = (pub_r000897_3 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000897_3 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000897_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000897_11 & 2) != 0) {
            stage_v_99 = (pub_r000897_20 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000897_20 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000897_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000897_0 & 2) != 0) {
            stage_v_100 = (pub_r000897_1 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000897_1 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000897_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000897_3 & 1) != 0) {
        if ((sec_r000897_17 & 2) != 0) {
            stage_v_101 = (pub_r000897_16 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000897_16 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000897_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000897_7 & 1) != 0) {
        if ((sec_r000897_12 & 2) != 0) {
            stage_v_102 = (pub_r000897_12 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000897_12 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000897_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000897_18 & 1) != 0) {
        if ((sec_r000897_21 & 2) != 0) {
            stage_v_103 = (pub_r000897_4 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000897_4 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000897_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000897_16 & 1) != 0) {
        if ((sec_r000897_3 & 2) != 0) {
            stage_v_104 = (pub_r000897_21 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000897_21 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000897_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_105 = (pub_r000897_11 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000897_11 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000897_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000897_5 & 2) != 0) {
            stage_v_106 = (pub_r000897_21 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000897_21 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000897_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000897_0 & 1) != 0) {
        if ((sec_r000897_11 & 2) != 0) {
            stage_v_107 = (pub_r000897_17 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000897_17 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000897_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000897_6 & 2) != 0) {
            stage_v_108 = (pub_r000897_18 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000897_18 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000897_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000897_6 & 2) != 0) {
            stage_v_109 = (pub_r000897_9 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000897_9 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000897_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000897_14 & 1) != 0) {
        if ((sec_r000897_21 & 2) != 0) {
            stage_v_110 = (pub_r000897_3 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000897_3 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000897_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_111 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000897_14 & 2) != 0) {
            stage_v_112 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_113 = (pub_r000897_11 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000897_11 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000897_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_114 = (pub_r000897_12 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000897_12 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000897_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000897_12 & 1) != 0) {
        if ((sec_r000897_0 & 2) != 0) {
            stage_v_115 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000897_19 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_116 = (pub_r000897_16 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000897_16 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000897_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000897_2 & 1) != 0) {
        if ((sec_r000897_18 & 2) != 0) {
            stage_v_117 = (pub_r000897_1 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000897_1 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000897_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000897_4 & 2) != 0) {
            stage_v_118 = (pub_r000897_17 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000897_17 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000897_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000897_5 & 1) != 0) {
        if ((sec_r000897_8 & 2) != 0) {
            stage_v_119 = (pub_r000897_13 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000897_13 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000897_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000897_21 & 2) != 0) {
            stage_v_120 = (pub_r000897_20 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000897_20 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000897_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000897_1 & 2) != 0) {
            stage_v_121 = (pub_r000897_14 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000897_14 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000897_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000897_11 & 1) != 0) {
        if ((sec_r000897_17 & 2) != 0) {
            stage_v_122 = (pub_r000897_10 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000897_10 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000897_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000897_1 & 2) != 0) {
            stage_v_123 = (pub_r000897_19 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000897_19 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000897_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000897_4 & 2) != 0) {
            stage_v_124 = (pub_r000897_2 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000897_2 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000897_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000897_21 & 1) != 0) {
        if ((sec_r000897_2 & 2) != 0) {
            stage_v_125 = (pub_r000897_2 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000897_2 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000897_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000897_21 & 2) != 0) {
            stage_v_126 = (pub_r000897_10 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000897_10 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000897_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_127 = (pub_r000897_11 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000897_11 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000897_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000897_16 & 2) != 0) {
            stage_v_128 = (pub_r000897_1 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000897_1 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000897_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_129 = (pub_r000897_18 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000897_18 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000897_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000897_12 & 2) != 0) {
            stage_v_130 = (pub_r000897_19 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000897_19 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000897_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_131 = (pub_r000897_2 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000897_2 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000897_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000897_2 & 1) != 0) {
        if ((sec_r000897_8 & 2) != 0) {
            stage_v_132 = (pub_r000897_13 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000897_13 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000897_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000897_9 & 2) != 0) {
            stage_v_133 = (pub_r000897_19 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000897_19 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000897_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000897_17 & 1) != 0) {
        if ((sec_r000897_8 & 2) != 0) {
            stage_v_134 = (pub_r000897_0 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000897_0 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000897_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000897_18 & 1) != 0) {
        if ((sec_r000897_2 & 2) != 0) {
            stage_v_135 = (pub_r000897_19 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000897_19 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000897_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000897_1 & 2) != 0) {
            stage_v_136 = (pub_r000897_5 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000897_5 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000897_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000897_0 & 2) != 0) {
            stage_v_137 = (pub_r000897_10 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000897_10 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000897_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000897_11 & 2) != 0) {
            stage_v_138 = (pub_r000897_11 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000897_11 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000897_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_139 = (pub_r000897_16 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000897_16 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000897_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000897_0 & 1) != 0) {
        if ((sec_r000897_4 & 2) != 0) {
            stage_v_140 = (pub_r000897_10 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000897_10 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000897_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000897_8 & 2) != 0) {
            stage_v_141 = (pub_r000897_5 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000897_5 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000897_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_142 = (pub_r000897_1 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000897_1 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000897_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000897_5 & 2) != 0) {
            stage_v_143 = (pub_r000897_17 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000897_17 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000897_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000897_14 & 2) != 0) {
            stage_v_144 = (pub_r000897_17 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000897_17 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000897_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_145 = (pub_r000897_17 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000897_17 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000897_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000897_3 & 2) != 0) {
            stage_v_146 = (pub_r000897_10 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000897_10 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000897_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_135 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_147 = (pub_r000897_18 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000897_18 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000897_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000897_14 & 2) != 0) {
            stage_v_148 = (pub_r000897_19 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000897_19 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000897_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000897_16 & 1) != 0) {
        if ((sec_r000897_12 & 2) != 0) {
            stage_v_149 = (pub_r000897_17 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000897_17 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000897_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000897_18 & 2) != 0) {
            stage_v_150 = (pub_r000897_8 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000897_8 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000897_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_148 & 1) != 0) {
        if ((sec_r000897_19 & 2) != 0) {
            stage_v_151 = (pub_r000897_16 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000897_16 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000897_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000897_19 & 2) != 0) {
            stage_v_152 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r000897_9 & 2) != 0) {
            stage_v_153 = (pub_r000897_17 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000897_17 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000897_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000897_8 & 1) != 0) {
        if ((sec_r000897_6 & 2) != 0) {
            stage_v_154 = (pub_r000897_7 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000897_7 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000897_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000897_5 & 1) != 0) {
        if ((sec_r000897_14 & 2) != 0) {
            stage_v_155 = (pub_r000897_18 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000897_18 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000897_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000897_15 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_156 = (pub_r000897_19 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000897_19 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000897_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_157 = (pub_r000897_7 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000897_7 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000897_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000897_7 & 2) != 0) {
            stage_v_158 = (pub_r000897_8 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000897_8 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000897_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000897_15 & 2) != 0) {
            stage_v_159 = (pub_r000897_1 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000897_1 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000897_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000897_0 & 2) != 0) {
            stage_v_160 = (pub_r000897_16 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000897_16 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000897_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r000897_8 & 2) != 0) {
            stage_v_161 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000897_4 & 2) != 0) {
            stage_v_162 = (pub_r000897_4 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000897_4 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000897_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((sec_r000897_21 & 1) != 0) {
        if ((sec_r000897_20 & 2) != 0) {
            stage_v_163 = (pub_r000897_15 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000897_15 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000897_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
