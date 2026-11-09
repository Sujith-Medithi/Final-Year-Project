/*
 * Benchmark Program: R001690
 * Security Family: mixed_control_data
 * Generator Seed: 669013
 * High Inputs: 16 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001690_9013_0 {
    int balance;
    int status;
    int auth_code;
    unsigned char rate;
    int account_id;
    int buffer[3];
};

struct Vector3D_R001690_9013_1 {
    short coord_z;
    int coord_y;
    int heading;
    int coord_x;
    int buffer[3];
};

struct MatrixBlock_R001690_9013_2 {
    unsigned char stride;
    short scale;
    int density;
    int trace;
    int determinant;
    int buffer[3];
};

struct CipherContext_R001690_9013_3 {
    unsigned char round_key;
    unsigned char nonce;
    int counter;
    int buffer[3];
};

union ColorPixel_R001690_9013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001690_9013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001690_9013_0(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001690_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int factor_19 = (aux + st.buffer[1]) & 3;
    switch (factor_19) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001690_9013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001690_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int damping_31 = local_arr[aux % 3];
    acc = (acc + damping_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001690_9013_2(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001690_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_54) & 63;
    acc ^= aux;
    int accumulator_88 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_88 > 34) {
        acc = (acc + accumulator_88 * 2 + 5) & 127;
        aux ^= (accumulator_88 & 15);
    } else {
        acc = (acc - accumulator_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_3(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001690_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_94 = (aux + st.buffer[1]) & 3;
    switch (quotient_94) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_94 = local_arr[aux % 3];
    acc = (acc + phase_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001690_9013_4(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001690_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tally_95 = 0;
    for (int k = 0; k < 2; k++) {
        tally_95 = (tally_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_95) & 127;
    }
    int segment_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001690_9013_5(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001690_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int anchor_14 = local_arr[aux % 3];
    acc = (acc + anchor_14 * 2) & 127;
    int tracker_17 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_17 > 12) {
        acc = (acc + tracker_17 * 2 + 5) & 127;
        aux ^= (tracker_17 & 15);
    } else {
        acc = (acc - tracker_17 + 11) & 127;
        aux += 3;
    }
    int stride_12 = 0;
    for (int k = 0; k < 3; k++) {
        stride_12 = (stride_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_12) & 127;
    }
    int quotient_90 = (aux + st.buffer[1]) & 3;
    switch (quotient_90) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001690_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int metric_45 = (aux + st.buffer[1]) & 3;
    switch (metric_45) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_63 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_63 > 26) {
        acc = (acc + delta_63 * 2 + 5) & 127;
        aux ^= (delta_63 & 15);
    } else {
        acc = (acc - delta_63 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_32 = local_arr[aux % 3];
    acc = (acc + mask_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001690_9013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001690_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int sample_46 = local_arr[aux % 3];
    acc = (acc + sample_46 * 2) & 127;
    int window_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_48) & 63;
    acc ^= aux;
    int weight_42 = 0;
    for (int k = 0; k < 3; k++) {
        weight_42 = (weight_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_8(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001690_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int weight_58 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_58 > 48) {
        acc = (acc + weight_58 * 2 + 5) & 127;
        aux ^= (weight_58 & 15);
    } else {
        acc = (acc - weight_58 + 11) & 127;
        aux += 3;
    }
    int tally_47 = (aux + st.buffer[1]) & 3;
    switch (tally_47) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_84 = local_arr[aux % 3];
    acc = (acc + residue_84 * 2) & 127;
    int vector_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001690_9013_9(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001690_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int weight_16 = 0;
    for (int k = 0; k < 2; k++) {
        weight_16 = (weight_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_16) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_27 = local_arr[aux % 3];
    acc = (acc + parity_27 * 2) & 127;
    int offset_46 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_46 > 46) {
        acc = (acc + offset_46 * 2 + 5) & 127;
        aux ^= (offset_46 & 15);
    } else {
        acc = (acc - offset_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_10(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001690_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001690_9013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001690_9013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int threshold_39 = local_arr[aux % 3];
    acc = (acc + threshold_39 * 2) & 127;
    int tracker_63 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_63 = (tracker_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_63) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001690_9013_12(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001690_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int parity_47 = local_arr[aux % 3];
    acc = (acc + parity_47 * 2) & 127;
    int tally_52 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_52 > 40) {
        acc = (acc + tally_52 * 2 + 5) & 127;
        aux ^= (tally_52 & 15);
    } else {
        acc = (acc - tally_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_13(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001690_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int quantum_90 = local_arr[aux % 3];
    acc = (acc + quantum_90 * 2) & 127;
    int weight_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001690_9013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001690_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int anchor_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_27) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_24 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_24 > 42) {
        acc = (acc + tally_24 * 2 + 5) & 127;
        aux ^= (tally_24 & 15);
    } else {
        acc = (acc - tally_24 + 11) & 127;
        aux += 3;
    }
    int offset_91 = (aux + st.buffer[1]) & 3;
    switch (offset_91) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001690_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_67) & 63;
    acc ^= aux;
    int stride_54 = (aux + st.buffer[1]) & 3;
    switch (stride_54) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_27 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_27 = (checksum_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_27) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001690_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_85 = (aux + st.buffer[1]) & 3;
    switch (vector_85) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001690_9013_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001690_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_90 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_90 > 21) {
        acc = (acc + pivot_90 * 2 + 5) & 127;
        aux ^= (pivot_90 & 15);
    } else {
        acc = (acc - pivot_90 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_57 = (aux + st.buffer[1]) & 3;
    switch (offset_57) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_65 = local_arr[aux % 3];
    acc = (acc + tally_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001690_9013_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001690_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_37 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_37 = (checksum_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_37) & 127;
    }
    int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001690_0;
    int sec_r001690_1;
    int sec_r001690_2;
    int sec_r001690_3;
    int sec_r001690_4;
    int sec_r001690_5;
    int sec_r001690_6;
    int sec_r001690_7;
    int sec_r001690_8;
    int sec_r001690_9;
    int sec_r001690_10;
    int sec_r001690_11;
    int sec_r001690_12;
    int sec_r001690_13;
    int sec_r001690_14;
    int sec_r001690_15;
    int pub_r001690_0;
    int pub_r001690_1;
    int pub_r001690_2;
    int pub_r001690_3;
    int pub_r001690_4;
    int pub_r001690_5;
    int pub_r001690_6;
    int pub_r001690_7;
    int pub_r001690_8;
    int pub_r001690_9;
    int pub_r001690_10;
    int pub_r001690_11;
    int pub_r001690_12;
    int pub_r001690_13;
    int pub_r001690_14;
    int pub_r001690_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001690_0 >= -100 && pub_r001690_0 <= 100);
    __CPROVER_assume(pub_r001690_1 >= -100 && pub_r001690_1 <= 100);
    __CPROVER_assume(pub_r001690_2 >= -100 && pub_r001690_2 <= 100);
    __CPROVER_assume(pub_r001690_3 >= -100 && pub_r001690_3 <= 100);
    __CPROVER_assume(pub_r001690_4 >= -100 && pub_r001690_4 <= 100);
    __CPROVER_assume(pub_r001690_5 >= -100 && pub_r001690_5 <= 100);
    __CPROVER_assume(pub_r001690_6 >= -100 && pub_r001690_6 <= 100);
    __CPROVER_assume(pub_r001690_7 >= -100 && pub_r001690_7 <= 100);
    __CPROVER_assume(pub_r001690_8 >= -100 && pub_r001690_8 <= 100);
    __CPROVER_assume(pub_r001690_9 >= -100 && pub_r001690_9 <= 100);
    __CPROVER_assume(pub_r001690_10 >= -100 && pub_r001690_10 <= 100);
    __CPROVER_assume(pub_r001690_11 >= -100 && pub_r001690_11 <= 100);
    __CPROVER_assume(pub_r001690_12 >= -100 && pub_r001690_12 <= 100);
    __CPROVER_assume(pub_r001690_13 >= -100 && pub_r001690_13 <= 100);
    __CPROVER_assume(pub_r001690_14 >= -100 && pub_r001690_14 <= 100);
    __CPROVER_assume(pub_r001690_15 >= -100 && pub_r001690_15 <= 100);
    __CPROVER_assume(sec_r001690_0 >= 0 && sec_r001690_0 <= 255);
    __CPROVER_assume(sec_r001690_1 >= 0 && sec_r001690_1 <= 255);
    __CPROVER_assume(sec_r001690_2 >= 0 && sec_r001690_2 <= 255);
    __CPROVER_assume(sec_r001690_3 >= 0 && sec_r001690_3 <= 255);
    __CPROVER_assume(sec_r001690_4 >= 0 && sec_r001690_4 <= 255);
    __CPROVER_assume(sec_r001690_5 >= 0 && sec_r001690_5 <= 255);
    __CPROVER_assume(sec_r001690_6 >= 0 && sec_r001690_6 <= 255);
    __CPROVER_assume(sec_r001690_7 >= 0 && sec_r001690_7 <= 255);
    __CPROVER_assume(sec_r001690_8 >= 0 && sec_r001690_8 <= 255);
    __CPROVER_assume(sec_r001690_9 >= 0 && sec_r001690_9 <= 255);
    __CPROVER_assume(sec_r001690_10 >= 0 && sec_r001690_10 <= 255);
    __CPROVER_assume(sec_r001690_11 >= 0 && sec_r001690_11 <= 255);
    __CPROVER_assume(sec_r001690_12 >= 0 && sec_r001690_12 <= 255);
    __CPROVER_assume(sec_r001690_13 >= 0 && sec_r001690_13 <= 255);
    __CPROVER_assume(sec_r001690_14 >= 0 && sec_r001690_14 <= 255);
    __CPROVER_assume(sec_r001690_15 >= 0 && sec_r001690_15 <= 255);

    struct Transaction_R001690_9013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001690_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001690_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001690_0 + 7) & 15;
    struct Vector3D_R001690_9013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001690_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001690_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001690_0 + 9) & 15;
    struct MatrixBlock_R001690_9013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001690_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001690_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001690_0 + 11) & 15;
    struct CipherContext_R001690_9013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001690_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001690_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001690_0 + 13) & 15;

    union ColorPixel_R001690_9013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001690_9013_0(sec_r001690_0, pub_r001690_1);
    int helper_flow_1 = fn_R001690_9013_1(sec_r001690_1, sec_r001690_2, pub_r001690_3, pub_r001690_4);
    int helper_flow_2 = fn_R001690_9013_2(sec_r001690_2, sec_r001690_3);
    int helper_flow_3 = fn_R001690_9013_3(sec_r001690_3, sec_r001690_4);
    int helper_flow_4 = fn_R001690_9013_4(sec_r001690_4, sec_r001690_5, pub_r001690_6);
    int helper_flow_5 = fn_R001690_9013_5(sec_r001690_5, pub_r001690_6);
    int helper_flow_6 = fn_R001690_9013_6(sec_r001690_6, pub_r001690_7, pub_r001690_8, pub_r001690_9);
    int helper_flow_7 = fn_R001690_9013_7(sec_r001690_7, sec_r001690_8, pub_r001690_9, pub_r001690_10);
    int helper_flow_8 = fn_R001690_9013_8(sec_r001690_8, sec_r001690_9);
    int helper_flow_9 = fn_R001690_9013_9(sec_r001690_9, sec_r001690_10, pub_r001690_11);
    int helper_flow_10 = fn_R001690_9013_10(sec_r001690_10, pub_r001690_11, pub_r001690_12);
    int helper_flow_11 = fn_R001690_9013_11(sec_r001690_11, sec_r001690_12, pub_r001690_13, pub_r001690_14);
    int helper_flow_12 = fn_R001690_9013_12(sec_r001690_12, sec_r001690_13);
    int helper_flow_13 = fn_R001690_9013_13(sec_r001690_13, sec_r001690_14, pub_r001690_15);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001690_9 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_0 > 45) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_1 > 48) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001690_13 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_2 > 22) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001690_0 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_3 > 28) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_4 > 48) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001690_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001690_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001690_15 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_7 > 38) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_8 > 22) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_9 > 37) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001690_15 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_10 > 46) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001690_6 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_11 > 24) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001690_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001690_9 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_13 > 22) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001690_6 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_14 > 25) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001690_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_16 > 26) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001690_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001690_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_19 > 39) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_20 > 44) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001690_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001690_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_23 > 26) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_24 > 44) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_25 > 27) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001690_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_27 > 21) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_28 > 44) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001690_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_30 > 26) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_31 > 25) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_32 > 46) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001690_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_34 > 47) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_35 > 29) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_36 > 40) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_37 > 20) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001690_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001690_3 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_39 > 39) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001690_6 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_40 > 28) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_41 > 43) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_42 > 32) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001690_8 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_43 > 25) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001690_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001690_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001690_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_47 > 29) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001690_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_49 > 22) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_50 > 48) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_51 > 36) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001690_2 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_52 > 23) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001690_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001690_13 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_54 > 25) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_55 > 33) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001690_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001690_0 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_57 > 47) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_58 > 37) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_59 > 46) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_60 > 45) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001690_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001690_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001690_11 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_63 > 39) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_64 > 42) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_65 > 24) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_66 > 35) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_67 > 49) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_68 > 32) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001690_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001690_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001690_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_72 > 43) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001690_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_74 > 22) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_75 > 48) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_76 > 33) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001690_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_78 > 29) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_79 > 29) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_80 > 38) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_81 > 23) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_82 > 25) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_83 > 45) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_84 > 31) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001690_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001690_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_87 > 37) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_88 > 32) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_89 > 25) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001690_5) & 127;
    if (stage_v_90 > 31) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001690_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001690_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001690_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_94 > 45) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001690_9 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_95 > 33) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_96 > 43) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_97 > 30) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001690_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001690_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_100 > 23) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001690_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_102 > 25) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001690_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001690_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001690_12 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_105 > 20) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001690_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_107 > 30) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_108 > 37) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001690_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_110 > 22) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001690_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001690_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001690_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001690_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001690_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_116 > 39) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_117 > 21) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001690_5 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_118 > 48) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_119 > 45) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001690_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_121 > 20) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_122 > 50) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_123 > 29) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_124 > 48) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001690_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001690_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_127 > 36) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_128 > 40) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_129 > 48) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_130 > 34) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r001690_3 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_131 > 44) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_132 > 28) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_133 > 24) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_134 > 33) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_135 > 29) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_136 > 43) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_137 > 25) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_138 > 48) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001690_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_140 > 40) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_141 > 35) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_142 > 29) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r001690_14 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_143 > 36) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_144 > 36) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001690_4 ^ 0x2A) * 2 + pub_r001690_13) & 127;
    if (stage_v_145 > 36) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001690_2 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_146 > 25) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_147 > 32) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r001690_9 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_148 > 34) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_149 > 24) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_150 > 37) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_151 > 41) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_152 > 21) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001690_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_154 > 32) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_155 > 21) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001690_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_157 > 39) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r001690_15 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_158 > 43) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_159 > 43) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_160 > 37) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r001690_2 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_161 > 20) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001690_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_163 > 33) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_164 > 20) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_165 > 26) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_166 > 33) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_167 > 32) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_168 > 47) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((sec_r001690_13 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_169 > 44) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_170 > 43) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r001690_15 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_171 > 48) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_172 > 27) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001690_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001690_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_175 > 39) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001690_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_177 > 29) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_178 > 21) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_179 > 21) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_180 > 48) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001690_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001690_6) & 127;
    if (stage_v_182 > 23) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001690_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_184 > 32) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r001690_6 ^ 0x2A) * 2 + pub_r001690_1) & 127;
    if (stage_v_185 > 29) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_186 > 46) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_187 > 37) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_188 > 22) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001690_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_169 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_190 > 46) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001690_5) & 127;
    if (stage_v_191 > 29) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_192 > 49) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001690_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_192 ^ 0x2A) * 2 + pub_r001690_5) & 127;
    if (stage_v_194 > 36) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001690_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001690_5) & 127;
    if (stage_v_196 > 32) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001690_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001690_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001690_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001690_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_201 > 29) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001690_8) & 127;
    if (stage_v_202 > 31) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001690_14) & 127;
    if (stage_v_203 > 42) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001690_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_205 > 27) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_206 > 30) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_207 > 24) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001690_15) & 127;
    if (stage_v_208 > 25) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_209 > 34) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001690_4) & 127;
    if (stage_v_210 > 31) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001690_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001690_12) & 127;
    if (stage_v_212 > 30) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_213 > 30) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_214 > 45) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001690_10) & 127;
    if (stage_v_215 > 24) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001690_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_217 > 41) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001690_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001690_0) & 127;
    if (stage_v_219 > 36) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001690_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_187 ^ 0x2A) * 2 + pub_r001690_11) & 127;
    if (stage_v_221 > 23) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001690_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001690_3) & 127;
    if (stage_v_223 > 34) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_224 > 47) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001690_2) & 127;
    if (stage_v_225 > 45) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001690_5) & 127;
    if (stage_v_226 > 36) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001690_9) & 127;
    if (stage_v_227 > 23) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001690_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001690_7) & 127;
    if (stage_v_229 > 23) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001690_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
