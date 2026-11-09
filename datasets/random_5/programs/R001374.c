/*
 * Benchmark Program: R001374
 * Security Family: arithmetic_flow
 * Generator Seed: 637413
 * High Inputs: 16 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001374_7413_0 {
    int nonce;
    short flags;
    int iv;
    int buffer[3];
};

struct FilterState_R001374_7413_1 {
    int mode;
    int prev_out;
    unsigned char prev_in;
    int gain_db;
    short damping;
    int cutoff;
    int buffer[3];
};

union RegisterBank_R001374_7413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001374_7413_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int mask_87 = 0;
    for (int k = 0; k < 3; k++) {
        mask_87 = (mask_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_87) & 127;
    }
    int mask_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_42) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_70 = local_arr[aux % 3];
    acc = (acc + pivot_70 * 2) & 127;
    int quotient_55 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_55 > 10) {
        acc = (acc + quotient_55 * 2 + 5) & 127;
        aux ^= (quotient_55 & 15);
    } else {
        acc = (acc - quotient_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tally_58 = 0;
    for (int k = 0; k < 3; k++) {
        tally_58 = (tally_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_58) & 127;
    }
    int sample_37 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_37 > 44) {
        acc = (acc + sample_37 * 2 + 5) & 127;
        aux ^= (sample_37 & 15);
    } else {
        acc = (acc - sample_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int vector_55 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_55 > 48) {
        acc = (acc + vector_55 * 2 + 5) & 127;
        aux ^= (vector_55 & 15);
    } else {
        acc = (acc - vector_55 + 11) & 127;
        aux += 3;
    }
    int segment_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_83) & 63;
    acc ^= aux;
    int weight_97 = (aux + st.buffer[1]) & 3;
    switch (weight_97) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_26 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_26 = (pivot_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_26) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int quantum_52 = local_arr[aux % 3];
    acc = (acc + quantum_52 * 2) & 127;
    int cursor_91 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_91 = (cursor_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_4(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int phase_90 = (aux + st.buffer[1]) & 3;
    switch (phase_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_95 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_95 = (cursor_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_95) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_64 = local_arr[aux % 3];
    acc = (acc + tally_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_5(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_28) & 63;
    acc ^= aux;
    int bound_25 = (aux + st.buffer[1]) & 3;
    switch (bound_25) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_34 = local_arr[aux % 3];
    acc = (acc + scale_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_6(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001374_7413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int threshold_48 = local_arr[aux % 3];
    acc = (acc + threshold_48 * 2) & 127;
    int window_76 = (st.buffer[0] * 3 + aux) & 63;
    if (window_76 > 46) {
        acc = (acc + window_76 * 2 + 5) & 127;
        aux ^= (window_76 & 15);
    } else {
        acc = (acc - window_76 + 11) & 127;
        aux += 3;
    }
    int scale_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_30) & 63;
    acc ^= aux;
    int window_99 = (aux + st.buffer[1]) & 3;
    switch (window_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_7(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int vector_45 = local_arr[aux % 3];
    acc = (acc + vector_45 * 2) & 127;
    int metric_18 = 0;
    for (int k = 0; k < 3; k++) {
        metric_18 = (metric_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_18) & 127;
    }
    int stride_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_65) & 63;
    acc ^= aux;
    int pivot_81 = (aux + st.buffer[1]) & 3;
    switch (pivot_81) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_8(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int coefficient_84 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_84 = (coefficient_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_84) & 127;
    }
    int pivot_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001374_7413_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_91 = local_arr[aux % 3];
    acc = (acc + mask_91 * 2) & 127;
    int checksum_67 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_67 > 36) {
        acc = (acc + checksum_67 * 2 + 5) & 127;
        aux ^= (checksum_67 & 15);
    } else {
        acc = (acc - checksum_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_10(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001374_7413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int residue_57 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_57 > 34) {
        acc = (acc + residue_57 * 2 + 5) & 127;
        aux ^= (residue_57 & 15);
    } else {
        acc = (acc - residue_57 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_22 = local_arr[aux % 3];
    acc = (acc + checksum_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_11(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int weight_83 = local_arr[aux % 3];
    acc = (acc + weight_83 * 2) & 127;
    int segment_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001374_7413_12(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int window_65 = (st.buffer[0] * 3 + aux) & 63;
    if (window_65 > 23) {
        acc = (acc + window_65 * 2 + 5) & 127;
        aux ^= (window_65 & 15);
    } else {
        acc = (acc - window_65 + 11) & 127;
        aux += 3;
    }
    int delta_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_54) & 63;
    acc ^= aux;
    int coefficient_95 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_95 = (coefficient_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_95) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int metric_82 = local_arr[aux % 3];
    acc = (acc + metric_82 * 2) & 127;
    int vector_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001374_7413_14(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int residue_44 = 0;
    for (int k = 0; k < 2; k++) {
        residue_44 = (residue_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_44) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_20 = local_arr[aux % 3];
    acc = (acc + metric_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_15(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int delta_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_92) & 63;
    acc ^= aux;
    int anchor_69 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_69 = (anchor_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_69) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_95 = local_arr[aux % 3];
    acc = (acc + accumulator_95 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_16(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001374_7413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_20 > 43) {
        acc = (acc + factor_20 * 2 + 5) & 127;
        aux ^= (factor_20 & 15);
    } else {
        acc = (acc - factor_20 + 11) & 127;
        aux += 3;
    }
    int pivot_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_12) & 63;
    acc ^= aux;
    int index_reg_29 = (aux + st.buffer[1]) & 3;
    switch (index_reg_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_17(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tally_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_87) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_14 = local_arr[aux % 3];
    acc = (acc + metric_14 * 2) & 127;
    int segment_75 = 0;
    for (int k = 0; k < 3; k++) {
        segment_75 = (segment_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_75) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_18(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int scale_71 = (aux + st.buffer[1]) & 3;
    switch (scale_71) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_31) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_56 = local_arr[aux % 3];
    acc = (acc + metric_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_12 = (aux + st.buffer[1]) & 3;
    switch (anchor_12) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_19 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_19 = (accumulator_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_19) & 127;
    }
    int phase_72 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_72 > 13) {
        acc = (acc + phase_72 * 2 + 5) & 127;
        aux ^= (phase_72 & 15);
    } else {
        acc = (acc - phase_72 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001374_7413_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001374_7413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tracker_48 = (aux + st.buffer[1]) & 3;
    switch (tracker_48) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_11 = local_arr[aux % 3];
    acc = (acc + quotient_11 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_91 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_91 = (pivot_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001374_7413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int sample_87 = (aux + st.buffer[1]) & 3;
    switch (sample_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_98) & 63;
    acc ^= aux;
    int quotient_55 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_55 > 18) {
        acc = (acc + quotient_55 * 2 + 5) & 127;
        aux ^= (quotient_55 & 15);
    } else {
        acc = (acc - quotient_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001374_7413_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001374_7413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int vector_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_43) & 63;
    acc ^= aux;
    int cursor_52 = (aux + st.buffer[1]) & 3;
    switch (cursor_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001374_0;
    int sec_r001374_1;
    int sec_r001374_2;
    int sec_r001374_3;
    int sec_r001374_4;
    int sec_r001374_5;
    int sec_r001374_6;
    int sec_r001374_7;
    int sec_r001374_8;
    int sec_r001374_9;
    int sec_r001374_10;
    int sec_r001374_11;
    int sec_r001374_12;
    int sec_r001374_13;
    int sec_r001374_14;
    int sec_r001374_15;
    int pub_r001374_0;
    int pub_r001374_1;
    int pub_r001374_2;
    int pub_r001374_3;
    int pub_r001374_4;
    int pub_r001374_5;
    int pub_r001374_6;
    int pub_r001374_7;
    int pub_r001374_8;
    int pub_r001374_9;
    int pub_r001374_10;
    int pub_r001374_11;
    int pub_r001374_12;
    int pub_r001374_13;
    int pub_r001374_14;
    int pub_r001374_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001374_0 >= -100 && pub_r001374_0 <= 100);
    __CPROVER_assume(pub_r001374_1 >= -100 && pub_r001374_1 <= 100);
    __CPROVER_assume(pub_r001374_2 >= -100 && pub_r001374_2 <= 100);
    __CPROVER_assume(pub_r001374_3 >= -100 && pub_r001374_3 <= 100);
    __CPROVER_assume(pub_r001374_4 >= -100 && pub_r001374_4 <= 100);
    __CPROVER_assume(pub_r001374_5 >= -100 && pub_r001374_5 <= 100);
    __CPROVER_assume(pub_r001374_6 >= -100 && pub_r001374_6 <= 100);
    __CPROVER_assume(pub_r001374_7 >= -100 && pub_r001374_7 <= 100);
    __CPROVER_assume(pub_r001374_8 >= -100 && pub_r001374_8 <= 100);
    __CPROVER_assume(pub_r001374_9 >= -100 && pub_r001374_9 <= 100);
    __CPROVER_assume(pub_r001374_10 >= -100 && pub_r001374_10 <= 100);
    __CPROVER_assume(pub_r001374_11 >= -100 && pub_r001374_11 <= 100);
    __CPROVER_assume(pub_r001374_12 >= -100 && pub_r001374_12 <= 100);
    __CPROVER_assume(pub_r001374_13 >= -100 && pub_r001374_13 <= 100);
    __CPROVER_assume(pub_r001374_14 >= -100 && pub_r001374_14 <= 100);
    __CPROVER_assume(pub_r001374_15 >= -100 && pub_r001374_15 <= 100);
    __CPROVER_assume(sec_r001374_0 >= 0 && sec_r001374_0 <= 255);
    __CPROVER_assume(sec_r001374_1 >= 0 && sec_r001374_1 <= 255);
    __CPROVER_assume(sec_r001374_2 >= 0 && sec_r001374_2 <= 255);
    __CPROVER_assume(sec_r001374_3 >= 0 && sec_r001374_3 <= 255);
    __CPROVER_assume(sec_r001374_4 >= 0 && sec_r001374_4 <= 255);
    __CPROVER_assume(sec_r001374_5 >= 0 && sec_r001374_5 <= 255);
    __CPROVER_assume(sec_r001374_6 >= 0 && sec_r001374_6 <= 255);
    __CPROVER_assume(sec_r001374_7 >= 0 && sec_r001374_7 <= 255);
    __CPROVER_assume(sec_r001374_8 >= 0 && sec_r001374_8 <= 255);
    __CPROVER_assume(sec_r001374_9 >= 0 && sec_r001374_9 <= 255);
    __CPROVER_assume(sec_r001374_10 >= 0 && sec_r001374_10 <= 255);
    __CPROVER_assume(sec_r001374_11 >= 0 && sec_r001374_11 <= 255);
    __CPROVER_assume(sec_r001374_12 >= 0 && sec_r001374_12 <= 255);
    __CPROVER_assume(sec_r001374_13 >= 0 && sec_r001374_13 <= 255);
    __CPROVER_assume(sec_r001374_14 >= 0 && sec_r001374_14 <= 255);
    __CPROVER_assume(sec_r001374_15 >= 0 && sec_r001374_15 <= 255);

    struct CipherContext_R001374_7413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001374_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001374_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001374_0 + 7) & 15;
    struct FilterState_R001374_7413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001374_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001374_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001374_0 + 9) & 15;

    union RegisterBank_R001374_7413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001374_7413_0(sec_r001374_0, sec_r001374_1, pub_r001374_2, pub_r001374_3, pub_r001374_4);
    int helper_flow_1 = fn_R001374_7413_1(sec_r001374_1, sec_r001374_2, pub_r001374_3, pub_r001374_4);
    int helper_flow_2 = fn_R001374_7413_2(sec_r001374_2, sec_r001374_3, pub_r001374_4, pub_r001374_5, pub_r001374_6);
    int helper_flow_3 = fn_R001374_7413_3(sec_r001374_3, sec_r001374_4, pub_r001374_5, pub_r001374_6);
    int helper_flow_4 = fn_R001374_7413_4(sec_r001374_4, sec_r001374_5);
    int helper_flow_5 = fn_R001374_7413_5(sec_r001374_5, pub_r001374_6, pub_r001374_7);
    int helper_flow_6 = fn_R001374_7413_6(sec_r001374_6, sec_r001374_7);
    int helper_flow_7 = fn_R001374_7413_7(sec_r001374_7, sec_r001374_8);
    int helper_flow_8 = fn_R001374_7413_8(sec_r001374_8, sec_r001374_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001374_7 * 3) + pub_r001374_3 + 31) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001374_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001374_14 * 3) + pub_r001374_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_2) & 255;
    out_sink = (out_sink + stage_v_2 * 2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_3 * 3) + pub_r001374_11 + 39) & 127;
    sec_accum = (sec_accum + stage_v_3) & 255;
    out_sink = (out_sink + stage_v_3 * 2) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001374_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001374_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001374_2 * 3) + pub_r001374_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001374_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001374_2 * 3) + pub_r001374_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8 * 2) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_3 * 3) + pub_r001374_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001374_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001374_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001374_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001374_12 * 3) + pub_r001374_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_3 * 3) + pub_r001374_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_14) & 255;
    out_sink = (out_sink + stage_v_14 * 2) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001374_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_2 * 3) + pub_r001374_3 + 40) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001374_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_8 * 3) + pub_r001374_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001374_2 * 3) + pub_r001374_2 + 10) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001374_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001374_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_13 * 3) + pub_r001374_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001374_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_7 * 3) + pub_r001374_3 + 41) & 127;
    sec_accum = (sec_accum + stage_v_24) & 255;
    out_sink = (out_sink + stage_v_24 * 2) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001374_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_22 * 3) + pub_r001374_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26 * 2) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001374_10 * 3) + pub_r001374_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_27) & 255;
    out_sink = (out_sink + stage_v_27 * 2) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001374_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001374_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001374_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_8 * 3) + pub_r001374_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31 * 2) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_0 * 3) + pub_r001374_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001374_3 * 3) + pub_r001374_3 + 13) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001374_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001374_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_0 * 3) + pub_r001374_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001374_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001374_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001374_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001374_1 * 3) + pub_r001374_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_40 * 3) + pub_r001374_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001374_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_26 * 3) + pub_r001374_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001374_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001374_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001374_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_16 * 3) + pub_r001374_1 + 39) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_13 * 3) + pub_r001374_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_2 * 3) + pub_r001374_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49 * 2) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001374_0 * 3) + pub_r001374_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001374_14 * 3) + pub_r001374_2 + 11) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001374_6 * 3) + pub_r001374_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001374_0 * 3) + pub_r001374_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53 * 2) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001374_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001374_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001374_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001374_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001374_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001374_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001374_15 * 3) + pub_r001374_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001374_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001374_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001374_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001374_3 * 3) + pub_r001374_7 + 44) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001374_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_49 * 3) + pub_r001374_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66 * 2) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001374_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_32 * 3) + pub_r001374_15 + 11) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68 * 2) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((helper_flow_3 * 3) + pub_r001374_4 + 29) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69 * 2) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001374_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001374_12 * 3) + pub_r001374_4 + 29) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_8 * 3) + pub_r001374_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001374_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001374_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001374_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001374_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001374_5 * 3) + pub_r001374_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001374_13 * 3) + pub_r001374_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001374_7 * 3) + pub_r001374_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001374_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_4 * 3) + pub_r001374_2 + 33) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81 * 2) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001374_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_72 * 3) + pub_r001374_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001374_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_26 * 3) + pub_r001374_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85 * 2) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001374_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_49 * 3) + pub_r001374_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001374_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001374_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001374_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_2 * 3) + pub_r001374_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001374_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_71 * 3) + pub_r001374_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_64 * 3) + pub_r001374_12 + 35) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94 * 2) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001374_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_6 * 3) + pub_r001374_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_47 * 3) + pub_r001374_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001374_11 * 3) + pub_r001374_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((helper_flow_2 * 3) + pub_r001374_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_31 * 3) + pub_r001374_3 + 15) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_64 * 3) + pub_r001374_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_16 * 3) + pub_r001374_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102 * 2) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_2 * 3) + pub_r001374_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103 * 2) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_18 * 3) + pub_r001374_5 + 13) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001374_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_8 * 3) + pub_r001374_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001374_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001374_6 * 3) + pub_r001374_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001374_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_72 * 3) + pub_r001374_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_96 * 3) + pub_r001374_3 + 41) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_100 * 3) + pub_r001374_1 + 42) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_3 * 3) + pub_r001374_11 + 18) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001374_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001374_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001374_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001374_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001374_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_3 * 3) + pub_r001374_10 + 19) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_85 * 3) + pub_r001374_2 + 17) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001374_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001374_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001374_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001374_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_111 * 3) + pub_r001374_4 + 43) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001374_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_98 * 3) + pub_r001374_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127 * 2) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001374_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001374_7 * 3) + pub_r001374_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001374_12 * 3) + pub_r001374_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001374_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001374_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001374_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_9 * 3) + pub_r001374_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134 * 2) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_71 * 3) + pub_r001374_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_119 * 3) + pub_r001374_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001374_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001374_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001374_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_19 * 3) + pub_r001374_5 + 3) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140 * 2) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001374_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((helper_flow_5 * 3) + pub_r001374_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_96 * 3) + pub_r001374_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_32 * 3) + pub_r001374_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144 * 2) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_103 * 3) + pub_r001374_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001374_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_69 * 3) + pub_r001374_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147 * 2) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001374_1 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_31 * 3) + pub_r001374_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149 * 2) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_13 * 3) + pub_r001374_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001374_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_136 * 3) + pub_r001374_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001374_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_97 * 3) + pub_r001374_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001374_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001374_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((helper_flow_7 * 3) + pub_r001374_10 + 25) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157 * 2) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_50 * 3) + pub_r001374_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_53 * 3) + pub_r001374_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_31 * 3) + pub_r001374_14 + 40) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001374_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001374_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001374_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001374_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_159 * 3) + pub_r001374_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001374_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001374_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_102 * 3) + pub_r001374_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168 * 2) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001374_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001374_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_22 * 3) + pub_r001374_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_50 * 3) + pub_r001374_0 + 10) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_104 * 3) + pub_r001374_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173 * 2) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001374_10 * 3) + pub_r001374_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_60 * 3) + pub_r001374_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_26 * 3) + pub_r001374_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_108 * 3) + pub_r001374_4 + 7) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177 * 2) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001374_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_129 * 3) + pub_r001374_4 + 27) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001374_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001374_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_171 * 3) + pub_r001374_8 + 43) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001374_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_79 * 3) + pub_r001374_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184 * 2) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001374_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_157 * 3) + pub_r001374_15 + 27) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001374_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_18 * 3) + pub_r001374_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188 * 2) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001374_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001374_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_66 * 3) + pub_r001374_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001374_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001374_8 * 3) + pub_r001374_7 + 10) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_147 * 3) + pub_r001374_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001374_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_97 * 3) + pub_r001374_4 + 34) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001374_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_110 * 3) + pub_r001374_14 + 40) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198 * 2) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001374_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_145 * 3) + pub_r001374_6 + 44) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200 * 2) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_150 * 3) + pub_r001374_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001374_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001374_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_87 * 3) + pub_r001374_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_110 * 3) + pub_r001374_14 + 36) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001374_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_150 * 3) + pub_r001374_10 + 41) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207 * 2) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001374_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001374_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_93 * 3) + pub_r001374_7 + 32) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001374_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_31 * 3) + pub_r001374_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212 * 2) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001374_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001374_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001374_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_160 * 3) + pub_r001374_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_36 * 3) + pub_r001374_14 + 38) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((helper_flow_8 * 3) + pub_r001374_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_143 * 3) + pub_r001374_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219 * 2) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001374_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_40 * 3) + pub_r001374_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001374_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_66 * 3) + pub_r001374_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_77 * 3) + pub_r001374_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001374_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001374_0 * 3) + pub_r001374_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((helper_flow_6 * 3) + pub_r001374_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001374_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_9 * 3) + pub_r001374_13 + 42) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001374_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001374_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_119 * 3) + pub_r001374_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232 * 2) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_182 * 3) + pub_r001374_2 + 44) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_175 * 3) + pub_r001374_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_150 * 3) + pub_r001374_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001374_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001374_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001374_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001374_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001374_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001374_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_175 * 3) + pub_r001374_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242 * 2) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001374_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001374_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001374_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_94 * 3) + pub_r001374_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246 * 2) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001374_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_96 * 3) + pub_r001374_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248 * 2) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_81 * 3) + pub_r001374_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249 * 2) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001374_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_152 * 3) + pub_r001374_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_68 * 3) + pub_r001374_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252 * 2) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_152 * 3) + pub_r001374_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001374_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_226 * 3) + pub_r001374_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255 * 2) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001374_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001374_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001374_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_217 * 3) + pub_r001374_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259 * 2) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001374_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_78 * 3) + pub_r001374_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_157 * 3) + pub_r001374_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001374_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_87 * 3) + pub_r001374_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001374_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001374_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((sec_r001374_0 * 3) + pub_r001374_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_60 * 3) + pub_r001374_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001374_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((helper_flow_7 * 3) + pub_r001374_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_79 * 3) + pub_r001374_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001374_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_104 * 3) + pub_r001374_1 + 8) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001374_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_255 * 3) + pub_r001374_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001374_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_223 * 3) + pub_r001374_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_2 * 3) + pub_r001374_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_253 * 3) + pub_r001374_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_279 * 3) + pub_r001374_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001374_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001374_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001374_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001374_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001374_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_262 * 3) + pub_r001374_10 + 12) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001374_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_212 * 3) + pub_r001374_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288 * 2) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_106 * 3) + pub_r001374_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289 * 2) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_242 * 3) + pub_r001374_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_226 * 3) + pub_r001374_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001374_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001374_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_120 * 3) + pub_r001374_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294 * 2) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_157 * 3) + pub_r001374_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_159 * 3) + pub_r001374_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_130 * 3) + pub_r001374_14 + 28) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297 * 2) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_136 * 3) + pub_r001374_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298 * 2) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((sec_r001374_13 * 3) + pub_r001374_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299 * 2) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((sec_r001374_10 * 3) + pub_r001374_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_296 * 3) + pub_r001374_3 + 30) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_69 * 3) + pub_r001374_14 + 39) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302 * 2) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_52 * 3) + pub_r001374_0 + 45) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_136 * 3) + pub_r001374_3 + 40) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001374_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_277 * 3) + pub_r001374_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306 * 2) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_112 * 3) + pub_r001374_15 + 27) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001374_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001374_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_182 * 3) + pub_r001374_10 + 4) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_154 * 3) + pub_r001374_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_273 * 3) + pub_r001374_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312 * 2) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((sec_r001374_13 * 3) + pub_r001374_5 + 23) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313 * 2) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_77 * 3) + pub_r001374_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314 * 2) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001374_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001374_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_154 * 3) + pub_r001374_6 + 24) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317 * 2) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001374_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001374_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_51 * 3) + pub_r001374_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_106 * 3) + pub_r001374_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_6 * 3) + pub_r001374_11 + 33) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_216 * 3) + pub_r001374_12 + 35) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_100 * 3) + pub_r001374_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324 * 2) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001374_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_144 * 3) + pub_r001374_11 + 45) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001374_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_119 * 3) + pub_r001374_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001374_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_72 * 3) + pub_r001374_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001374_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_193 * 3) + pub_r001374_15 + 39) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332 * 2) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001374_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001374_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001374_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001374_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001374_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_191 * 3) + pub_r001374_14 + 40) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_159 * 3) + pub_r001374_9 + 42) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339 * 2) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001374_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_219 * 3) + pub_r001374_12 + 36) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001374_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001374_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_165 * 3) + pub_r001374_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344 * 2) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_66 * 3) + pub_r001374_5 + 12) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_22 * 3) + pub_r001374_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001374_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_264 * 3) + pub_r001374_3 + 16) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001374_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_253 * 3) + pub_r001374_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_341 * 3) + pub_r001374_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001374_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001374_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001374_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_108 * 3) + pub_r001374_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001374_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001374_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_150 * 3) + pub_r001374_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((sec_r001374_9 * 3) + pub_r001374_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_330 * 3) + pub_r001374_3 + 21) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001374_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001374_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001374_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_280 * 3) + pub_r001374_4 + 41) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364 * 2) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_268 * 3) + pub_r001374_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365 * 2) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_119 * 3) + pub_r001374_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001374_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_140 * 3) + pub_r001374_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368 * 2) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001374_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001374_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001374_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001374_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001374_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_110 * 3) + pub_r001374_12 + 15) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_368 * 3) + pub_r001374_4 + 5) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375 * 2) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001374_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001374_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001374_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001374_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001374_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001374_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001374_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001374_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001374_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_50 * 3) + pub_r001374_10 + 9) & 127;
    sec_accum = (sec_accum + stage_v_385) & 255;
    out_sink = (out_sink + stage_v_385 * 2) & 255;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_234 * 3) + pub_r001374_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001374_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_303 * 3) + pub_r001374_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_388) & 255;
    out_sink = (out_sink + stage_v_388 * 2) & 255;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_303 * 3) + pub_r001374_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_389) & 255;
    out_sink = (out_sink + stage_v_389 * 2) & 255;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_306 * 3) + pub_r001374_3 + 4) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_248 * 3) + pub_r001374_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_391) & 255;
    out_sink = (out_sink + stage_v_391 * 2) & 255;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001374_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_22 * 3) + pub_r001374_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_393) & 255;
    out_sink = (out_sink + stage_v_393 * 2) & 255;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_227 * 3) + pub_r001374_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_71 * 3) + pub_r001374_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001374_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001374_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001374_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001374_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001374_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001374_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_339 * 3) + pub_r001374_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001374_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_66 * 3) + pub_r001374_2 + 22) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_41 * 3) + pub_r001374_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001374_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((sec_r001374_8 * 3) + pub_r001374_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_407) & 255;
    out_sink = (out_sink + stage_v_407 * 2) & 255;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001374_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001374_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_50 * 3) + pub_r001374_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_147 * 3) + pub_r001374_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_411) & 255;
    out_sink = (out_sink + stage_v_411 * 2) & 255;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_360 * 3) + pub_r001374_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_85 * 3) + pub_r001374_13 + 24) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((sec_r001374_13 * 3) + pub_r001374_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_102 * 3) + pub_r001374_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_8 * 3) + pub_r001374_7 + 14) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((sec_r001374_5 * 3) + pub_r001374_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001374_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_323 * 3) + pub_r001374_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_8 * 3) + pub_r001374_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_420) & 255;
    out_sink = (out_sink + stage_v_420 * 2) & 255;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_13 * 3) + pub_r001374_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001374_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_40 * 3) + pub_r001374_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_332 * 3) + pub_r001374_5 + 40) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001374_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001374_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001374_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001374_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001374_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_314 * 3) + pub_r001374_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001374_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_390 * 3) + pub_r001374_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_432) & 255;
    out_sink = (out_sink + stage_v_432 * 2) & 255;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_296 * 3) + pub_r001374_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_433) & 255;
    out_sink = (out_sink + stage_v_433 * 2) & 255;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_142 * 3) + pub_r001374_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_227 * 3) + pub_r001374_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_435) & 255;
    out_sink = (out_sink + stage_v_435 * 2) & 255;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_143 * 3) + pub_r001374_4 + 29) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001374_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_60 * 3) + pub_r001374_5 + 45) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_71 * 3) + pub_r001374_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001374_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001374_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_279 * 3) + pub_r001374_15 + 44) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_194 * 3) + pub_r001374_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_443) & 255;
    out_sink = (out_sink + stage_v_443 * 2) & 255;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001374_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_414 * 3) + pub_r001374_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_445) & 255;
    out_sink = (out_sink + stage_v_445 * 2) & 255;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001374_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_296 * 3) + pub_r001374_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_447) & 255;
    out_sink = (out_sink + stage_v_447 * 2) & 255;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001374_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001374_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_280 * 3) + pub_r001374_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001374_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001374_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_255 * 3) + pub_r001374_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_453) & 255;
    out_sink = (out_sink + stage_v_453 * 2) & 255;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001374_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001374_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
