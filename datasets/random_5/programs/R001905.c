/*
 * Benchmark Program: R001905
 * Security Family: bitwise_flow
 * Generator Seed: 690513
 * High Inputs: 16 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001905_513_0 {
    int watermark;
    unsigned char tail;
    short state;
    unsigned char capacity;
    int checksum;
    int buffer[3];
};

struct Transaction_R001905_513_1 {
    short balance;
    unsigned char account_id;
    unsigned char rate;
    unsigned char status;
    int auth_code;
    int buffer[3];
};

struct Vector3D_R001905_513_2 {
    short norm_sq;
    int coord_z;
    short heading;
    int buffer[3];
};

struct CipherContext_R001905_513_3 {
    int nonce;
    unsigned char iv;
    int round_key;
    int buffer[3];
};

union PacketPayload_R001905_513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001905_513_0(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001905_513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_39 = (aux + st.buffer[1]) & 3;
    switch (metric_39) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_1(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001905_513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_81 = (aux + st.buffer[1]) & 3;
    switch (residue_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_79 = local_arr[aux % 3];
    acc = (acc + quotient_79 * 2) & 127;
    int threshold_39 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_39 > 50) {
        acc = (acc + threshold_39 * 2 + 5) & 127;
        aux ^= (threshold_39 & 15);
    } else {
        acc = (acc - threshold_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001905_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int coefficient_65 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_65 > 40) {
        acc = (acc + coefficient_65 * 2 + 5) & 127;
        aux ^= (coefficient_65 & 15);
    } else {
        acc = (acc - coefficient_65 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_22 = local_arr[aux % 3];
    acc = (acc + weight_22 * 2) & 127;
    int quantum_74 = (aux + st.buffer[1]) & 3;
    switch (quantum_74) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001905_513_3(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int scale_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_64) & 63;
    acc ^= aux;
    int scale_59 = (aux + st.buffer[1]) & 3;
    switch (scale_59) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_83 = local_arr[aux % 3];
    acc = (acc + damping_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001905_513_4(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int accumulator_91 = (aux + st.buffer[1]) & 3;
    switch (accumulator_91) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_33) & 63;
    acc ^= aux;
    int metric_20 = 0;
    for (int k = 0; k < 2; k++) {
        metric_20 = (metric_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_20) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_23 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_23 > 31) {
        acc = (acc + residue_23 * 2 + 5) & 127;
        aux ^= (residue_23 & 15);
    } else {
        acc = (acc - residue_23 + 11) & 127;
        aux += 3;
    }
    int checksum_47 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_47 = (checksum_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_47) & 127;
    }
    int vector_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001905_513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int stride_27 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_27 > 30) {
        acc = (acc + stride_27 * 2 + 5) & 127;
        aux ^= (stride_27 & 15);
    } else {
        acc = (acc - stride_27 + 11) & 127;
        aux += 3;
    }
    int mask_47 = (aux + st.buffer[1]) & 3;
    switch (mask_47) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_22 = local_arr[aux % 3];
    acc = (acc + factor_22 * 2) & 127;
    int tally_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001905_513_7(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001905_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int segment_29 = local_arr[aux % 3];
    acc = (acc + segment_29 * 2) & 127;
    int anchor_19 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_19 = (anchor_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_19) & 127;
    }
    int quotient_57 = (aux + st.buffer[1]) & 3;
    switch (quotient_57) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001905_513_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001905_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int segment_12 = (aux + st.buffer[1]) & 3;
    switch (segment_12) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_68 = local_arr[aux % 3];
    acc = (acc + checksum_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001905_513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001905_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_90 = local_arr[aux % 3];
    acc = (acc + pivot_90 * 2) & 127;
    int metric_60 = 0;
    for (int k = 0; k < 3; k++) {
        metric_60 = (metric_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_60) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tally_24 = 0;
    for (int k = 0; k < 2; k++) {
        tally_24 = (tally_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_24) & 127;
    }
    int metric_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001905_513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001905_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int factor_59 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_59 > 41) {
        acc = (acc + factor_59 * 2 + 5) & 127;
        aux ^= (factor_59 & 15);
    } else {
        acc = (acc - factor_59 + 11) & 127;
        aux += 3;
    }
    int vector_91 = (aux + st.buffer[1]) & 3;
    switch (vector_91) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_12(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001905_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int window_89 = local_arr[aux % 3];
    acc = (acc + window_89 * 2) & 127;
    int margin_58 = 0;
    for (int k = 0; k < 3; k++) {
        margin_58 = (margin_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_58) & 127;
    }
    int quotient_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_30) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001905_513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int weight_16 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_16 > 35) {
        acc = (acc + weight_16 * 2 + 5) & 127;
        aux ^= (weight_16 & 15);
    } else {
        acc = (acc - weight_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_64 = local_arr[aux % 3];
    acc = (acc + scale_64 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001905_513_14(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001905_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quotient_36 = (aux + st.buffer[1]) & 3;
    switch (quotient_36) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001905_513_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001905_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int index_reg_52 = local_arr[aux % 3];
    acc = (acc + index_reg_52 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_68 = 0;
    for (int k = 0; k < 3; k++) {
        phase_68 = (phase_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_68) & 127;
    }
    int damping_30 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_30 > 48) {
        acc = (acc + damping_30 * 2 + 5) & 127;
        aux ^= (damping_30 & 15);
    } else {
        acc = (acc - damping_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001905_513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int weight_69 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_69 > 18) {
        acc = (acc + weight_69 * 2 + 5) & 127;
        aux ^= (weight_69 & 15);
    } else {
        acc = (acc - weight_69 + 11) & 127;
        aux += 3;
    }
    int factor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_64) & 63;
    acc ^= aux;
    int tracker_44 = (aux + st.buffer[1]) & 3;
    switch (tracker_44) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_17(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_33) & 63;
    acc ^= aux;
    int bound_94 = 0;
    for (int k = 0; k < 3; k++) {
        bound_94 = (bound_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_94) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001905_513_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001905_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int stride_34 = local_arr[aux % 3];
    acc = (acc + stride_34 * 2) & 127;
    int bound_32 = 0;
    for (int k = 0; k < 3; k++) {
        bound_32 = (bound_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_32) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001905_0;
    int sec_r001905_1;
    int sec_r001905_2;
    int sec_r001905_3;
    int sec_r001905_4;
    int sec_r001905_5;
    int sec_r001905_6;
    int sec_r001905_7;
    int sec_r001905_8;
    int sec_r001905_9;
    int sec_r001905_10;
    int sec_r001905_11;
    int sec_r001905_12;
    int sec_r001905_13;
    int sec_r001905_14;
    int sec_r001905_15;
    int pub_r001905_0;
    int pub_r001905_1;
    int pub_r001905_2;
    int pub_r001905_3;
    int pub_r001905_4;
    int pub_r001905_5;
    int pub_r001905_6;
    int pub_r001905_7;
    int pub_r001905_8;
    int pub_r001905_9;
    int pub_r001905_10;
    int pub_r001905_11;
    int pub_r001905_12;
    int pub_r001905_13;
    int pub_r001905_14;
    int pub_r001905_15;
    int pub_r001905_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001905_0 >= -100 && pub_r001905_0 <= 100);
    __CPROVER_assume(pub_r001905_1 >= -100 && pub_r001905_1 <= 100);
    __CPROVER_assume(pub_r001905_2 >= -100 && pub_r001905_2 <= 100);
    __CPROVER_assume(pub_r001905_3 >= -100 && pub_r001905_3 <= 100);
    __CPROVER_assume(pub_r001905_4 >= -100 && pub_r001905_4 <= 100);
    __CPROVER_assume(pub_r001905_5 >= -100 && pub_r001905_5 <= 100);
    __CPROVER_assume(pub_r001905_6 >= -100 && pub_r001905_6 <= 100);
    __CPROVER_assume(pub_r001905_7 >= -100 && pub_r001905_7 <= 100);
    __CPROVER_assume(pub_r001905_8 >= -100 && pub_r001905_8 <= 100);
    __CPROVER_assume(pub_r001905_9 >= -100 && pub_r001905_9 <= 100);
    __CPROVER_assume(pub_r001905_10 >= -100 && pub_r001905_10 <= 100);
    __CPROVER_assume(pub_r001905_11 >= -100 && pub_r001905_11 <= 100);
    __CPROVER_assume(pub_r001905_12 >= -100 && pub_r001905_12 <= 100);
    __CPROVER_assume(pub_r001905_13 >= -100 && pub_r001905_13 <= 100);
    __CPROVER_assume(pub_r001905_14 >= -100 && pub_r001905_14 <= 100);
    __CPROVER_assume(pub_r001905_15 >= -100 && pub_r001905_15 <= 100);
    __CPROVER_assume(pub_r001905_16 >= -100 && pub_r001905_16 <= 100);
    __CPROVER_assume(sec_r001905_0 >= 0 && sec_r001905_0 <= 255);
    __CPROVER_assume(sec_r001905_1 >= 0 && sec_r001905_1 <= 255);
    __CPROVER_assume(sec_r001905_2 >= 0 && sec_r001905_2 <= 255);
    __CPROVER_assume(sec_r001905_3 >= 0 && sec_r001905_3 <= 255);
    __CPROVER_assume(sec_r001905_4 >= 0 && sec_r001905_4 <= 255);
    __CPROVER_assume(sec_r001905_5 >= 0 && sec_r001905_5 <= 255);
    __CPROVER_assume(sec_r001905_6 >= 0 && sec_r001905_6 <= 255);
    __CPROVER_assume(sec_r001905_7 >= 0 && sec_r001905_7 <= 255);
    __CPROVER_assume(sec_r001905_8 >= 0 && sec_r001905_8 <= 255);
    __CPROVER_assume(sec_r001905_9 >= 0 && sec_r001905_9 <= 255);
    __CPROVER_assume(sec_r001905_10 >= 0 && sec_r001905_10 <= 255);
    __CPROVER_assume(sec_r001905_11 >= 0 && sec_r001905_11 <= 255);
    __CPROVER_assume(sec_r001905_12 >= 0 && sec_r001905_12 <= 255);
    __CPROVER_assume(sec_r001905_13 >= 0 && sec_r001905_13 <= 255);
    __CPROVER_assume(sec_r001905_14 >= 0 && sec_r001905_14 <= 255);
    __CPROVER_assume(sec_r001905_15 >= 0 && sec_r001905_15 <= 255);

    struct StreamBuffer_R001905_513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001905_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001905_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001905_0 + 7) & 15;
    struct Transaction_R001905_513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001905_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001905_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001905_0 + 9) & 15;
    struct Vector3D_R001905_513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001905_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001905_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001905_0 + 11) & 15;
    struct CipherContext_R001905_513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001905_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001905_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001905_0 + 13) & 15;

    union PacketPayload_R001905_513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001905_513_0(sec_r001905_0, pub_r001905_1, pub_r001905_2);
    int helper_flow_1 = fn_R001905_513_1(sec_r001905_1, sec_r001905_2, pub_r001905_3);
    int helper_flow_2 = fn_R001905_513_2(sec_r001905_2, sec_r001905_3, pub_r001905_4, pub_r001905_5, pub_r001905_6);
    int helper_flow_3 = fn_R001905_513_3(sec_r001905_3, sec_r001905_4);
    int helper_flow_4 = fn_R001905_513_4(sec_r001905_4, sec_r001905_5, pub_r001905_6);
    int helper_flow_5 = fn_R001905_513_5(sec_r001905_5, sec_r001905_6, pub_r001905_7, pub_r001905_8, pub_r001905_9);
    int helper_flow_6 = fn_R001905_513_6(sec_r001905_6, sec_r001905_7, pub_r001905_8, pub_r001905_9);
    int helper_flow_7 = fn_R001905_513_7(sec_r001905_7, sec_r001905_8, pub_r001905_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001905_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001905_6 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001905_15 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001905_8 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001905_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001905_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001905_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001905_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001905_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001905_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001905_14 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001905_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001905_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001905_15 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001905_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001905_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001905_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001905_6 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001905_3 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_3 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001905_1 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001905_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001905_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001905_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_3 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_24 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001905_5 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001905_9 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_2 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001905_12 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_2 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_29 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001905_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001905_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_7 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001905_1 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_1 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001905_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001905_13 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001905_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001905_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001905_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_17 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001905_7 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001905_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001905_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001905_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001905_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001905_5 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001905_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001905_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_48 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_36 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_6 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001905_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_53 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((helper_flow_7 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_31 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((helper_flow_6 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001905_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001905_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001905_12 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_57 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_52 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001905_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_58 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_27 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001905_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001905_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001905_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001905_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001905_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001905_11 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001905_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001905_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001905_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_31 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_56 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_72 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((helper_flow_1 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_57 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001905_7 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001905_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((helper_flow_1 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001905_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001905_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001905_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001905_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_10 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001905_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001905_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001905_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_79 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001905_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_92 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_56 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001905_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_92 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_29 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001905_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001905_15 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001905_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_42 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_80 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_94 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001905_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_27 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_18 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_103 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_48 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_38 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001905_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_100 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_34 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_65 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_114 + 1) & 15;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001905_5 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001905_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001905_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_66 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001905_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001905_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001905_8 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001905_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_58 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_107 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_62 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001905_4 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001905_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_28 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001905_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001905_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((helper_flow_0 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001905_4 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001905_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001905_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_31 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001905_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_112 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001905_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_53 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_1 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001905_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_36 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001905_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001905_13 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_92 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001905_11 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_2 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001905_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_113 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_108 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001905_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_42 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((helper_flow_7 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001905_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001905_5 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001905_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_13 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_115 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_78 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001905_11 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r001905_12 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001905_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001905_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001905_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001905_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001905_14 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001905_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_123 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_30 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001905_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_153 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001905_6 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r001905_4 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_173 + 1) & 15;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001905_10 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_103 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_1 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_166 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001905_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_62 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_172 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_29 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_181 + 1) & 15;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_123 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001905_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001905_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001905_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001905_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_62 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001905_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_57 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001905_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001905_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r001905_9 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_36 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001905_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((helper_flow_7 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_66 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001905_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001905_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001905_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_158 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_152 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_152 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_56 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_160 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001905_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_27 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001905_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_150 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001905_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_126 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001905_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_53 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001905_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_152 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_34 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001905_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001905_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001905_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001905_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001905_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((helper_flow_2 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_62 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_2 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_112 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_189 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001905_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_20 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_214 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001905_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_171 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_29 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_212 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_232 + 1) & 15;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_103 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_175 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_48 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_182 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001905_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_88 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001905_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_214 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001905_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_53 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001905_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001905_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((sec_r001905_13 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_174 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_113 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_30 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001905_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_98 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_100 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((sec_r001905_2 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001905_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((helper_flow_2 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_150 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_204 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001905_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001905_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_80 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_254 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((helper_flow_5 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001905_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_236 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_242 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_155 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001905_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_97 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001905_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001905_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_231 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_252 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_225 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001905_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r001905_1 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_13 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_115 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_38 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_66 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_210 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001905_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_276 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_222 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_63 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001905_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_152 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001905_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_26 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_238 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_288 + 1) & 15;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001905_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001905_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001905_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_106 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_51 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_126 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001905_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001905_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001905_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_132 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001905_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001905_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001905_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001905_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001905_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_233 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001905_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_169 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001905_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001905_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_10 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001905_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001905_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001905_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001905_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_152 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_298 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((sec_r001905_12 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_31 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001905_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001905_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_27 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001905_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001905_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_114 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_233 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_135 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_282 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_1 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001905_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_118 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001905_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001905_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_10 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001905_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_214 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_325 << 1) ^ (pub_r001905_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_221 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_179 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_18 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001905_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001905_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001905_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_272 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_238 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_97 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_157 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_147 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_261 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_158 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001905_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001905_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_189 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001905_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001905_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001905_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_279 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001905_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((sec_r001905_7 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_123 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001905_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001905_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_315 << 1) ^ (pub_r001905_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001905_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001905_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_121 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_147 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_53 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001905_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001905_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001905_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001905_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001905_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001905_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001905_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001905_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001905_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_108 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_259 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_140 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_61 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001905_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001905_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001905_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_181 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((helper_flow_2 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001905_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001905_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001905_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_252 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_121 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_118 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001905_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((sec_r001905_6 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_202 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001905_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((helper_flow_3 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001905_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_55 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001905_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_378 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_80 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001905_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001905_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001905_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((sec_r001905_6 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_25 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_224 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_208 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001905_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_227 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_272 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001905_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001905_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001905_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001905_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_113 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001905_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_324 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_115 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001905_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001905_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001905_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_337 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_422 + 1) & 15;
    out_sink ^= (stage_v_422 & 63);

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_204 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_181 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_224 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001905_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_28 << 1) ^ (pub_r001905_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_427 + 1) & 15;
    out_sink ^= (stage_v_427 & 63);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((sec_r001905_4 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((sec_r001905_6 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001905_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_203 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001905_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001905_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001905_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_10 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001905_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001905_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001905_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_83 << 1) ^ (pub_r001905_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((sec_r001905_10 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_440 + 1) & 15;
    out_sink ^= (stage_v_440 & 63);

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001905_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001905_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_424 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001905_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001905_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_114 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_81 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_193 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_139 << 1) ^ (pub_r001905_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_94 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001905_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((helper_flow_0 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_452 + 1) & 15;
    out_sink ^= (stage_v_452 & 63);

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001905_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001905_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_410 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_455 + 1) & 15;
    out_sink ^= (stage_v_455 & 63);

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001905_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((sec_r001905_10 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_457 + 1) & 15;
    out_sink ^= (stage_v_457 & 63);

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_348 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_458 + 1) & 15;
    out_sink ^= (stage_v_458 & 63);

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((sec_r001905_13 << 1) ^ (pub_r001905_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_459 + 1) & 15;
    out_sink ^= (stage_v_459 & 63);

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001905_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_272 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_461 + 1) & 15;
    out_sink ^= (stage_v_461 & 63);

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_233 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_462 + 1) & 15;
    out_sink ^= (stage_v_462 & 63);

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001905_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_285 << 1) ^ (pub_r001905_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_464 + 1) & 15;
    out_sink ^= (stage_v_464 & 63);

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001905_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_95 << 1) ^ (pub_r001905_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_466 + 1) & 15;
    out_sink ^= (stage_v_466 & 63);

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_452 << 1) ^ (pub_r001905_3 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_29 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_468 + 1) & 15;
    out_sink ^= (stage_v_468 & 63);

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001905_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = ((stage_v_72 << 1) ^ (pub_r001905_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_470 + 1) & 15;
    out_sink ^= (stage_v_470 & 63);

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_3 << 1) ^ (pub_r001905_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_471 + 1) & 15;
    out_sink ^= (stage_v_471 & 63);

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_395 << 1) ^ (pub_r001905_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_472 + 1) & 15;
    out_sink ^= (stage_v_472 & 63);

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001905_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001905_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_147 << 1) ^ (pub_r001905_0 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_475 + 1) & 15;
    out_sink ^= (stage_v_475 & 63);

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001905_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001905_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001905_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001905_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_137 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_480 + 1) & 15;
    out_sink ^= (stage_v_480 & 63);

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001905_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001905_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = ((stage_v_281 << 1) ^ (pub_r001905_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_483 + 1) & 15;
    out_sink ^= (stage_v_483 & 63);

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = ((stage_v_159 << 1) ^ (pub_r001905_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_484 + 1) & 15;
    out_sink ^= (stage_v_484 & 63);

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001905_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = ((stage_v_56 << 1) ^ (pub_r001905_16 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_486 + 1) & 15;
    out_sink ^= (stage_v_486 & 63);

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_281 << 1) ^ (pub_r001905_6 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_487 + 1) & 15;
    out_sink ^= (stage_v_487 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
