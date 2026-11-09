/*
 * Benchmark Program: R001470
 * Security Family: mixed_control_data
 * Generator Seed: 647013
 * High Inputs: 16 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001470_7013_0 {
    unsigned char cutoff;
    int prev_out;
    short gain_db;
    int buffer[3];
};

struct SensorNode_R001470_7013_1 {
    unsigned char offset;
    unsigned char threshold;
    int reading;
    short status;
    int gain;
    int calib;
    int buffer[3];
};

struct Vector3D_R001470_7013_2 {
    int norm_sq;
    int coord_y;
    short coord_z;
    int coord_x;
    int buffer[3];
};

struct CipherContext_R001470_7013_3 {
    int tag;
    unsigned char iv;
    int round_key;
    int flags;
    unsigned char nonce;
    int buffer[3];
};

union RegisterBank_R001470_7013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001470_7013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001470_7013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001470_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int quantum_86 = local_arr[aux % 3];
    acc = (acc + quantum_86 * 2) & 127;
    int threshold_69 = (aux + st.buffer[1]) & 3;
    switch (threshold_69) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_94 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_94 > 42) {
        acc = (acc + offset_94 * 2 + 5) & 127;
        aux ^= (offset_94 & 15);
    } else {
        acc = (acc - offset_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_1(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001470_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int margin_28 = (aux + st.buffer[1]) & 3;
    switch (margin_28) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_70 = local_arr[aux % 3];
    acc = (acc + quantum_70 * 2) & 127;
    int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001470_7013_2(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001470_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_82) & 63;
    acc ^= aux;
    int offset_88 = 0;
    for (int k = 0; k < 3; k++) {
        offset_88 = (offset_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_88) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_3(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001470_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int weight_35 = 0;
    for (int k = 0; k < 2; k++) {
        weight_35 = (weight_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_35) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_13 = local_arr[aux % 3];
    acc = (acc + tally_13 * 2) & 127;
    int offset_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_29) & 63;
    acc ^= aux;
    int index_reg_70 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_70 > 14) {
        acc = (acc + index_reg_70 * 2 + 5) & 127;
        aux ^= (index_reg_70 & 15);
    } else {
        acc = (acc - index_reg_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_4(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001470_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int vector_23 = (aux + st.buffer[1]) & 3;
    switch (vector_23) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_65 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_65 > 27) {
        acc = (acc + damping_65 * 2 + 5) & 127;
        aux ^= (damping_65 & 15);
    } else {
        acc = (acc - damping_65 + 11) & 127;
        aux += 3;
    }
    int window_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001470_7013_5(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001470_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int factor_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_26) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_48 = local_arr[aux % 3];
    acc = (acc + weight_48 * 2) & 127;
    int mask_67 = 0;
    for (int k = 0; k < 2; k++) {
        mask_67 = (mask_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_67) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001470_7013_6(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001470_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int stride_55 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_55 > 41) {
        acc = (acc + stride_55 * 2 + 5) & 127;
        aux ^= (stride_55 & 15);
    } else {
        acc = (acc - stride_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_75 = local_arr[aux % 3];
    acc = (acc + tracker_75 * 2) & 127;
    int phase_58 = (aux + st.buffer[1]) & 3;
    switch (phase_58) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001470_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int residue_65 = 0;
    for (int k = 0; k < 3; k++) {
        residue_65 = (residue_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_65) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_25 = local_arr[aux % 3];
    acc = (acc + tally_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001470_7013_8(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001470_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int metric_97 = 0;
    for (int k = 0; k < 2; k++) {
        metric_97 = (metric_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_97) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_55 = local_arr[aux % 3];
    acc = (acc + residue_55 * 2) & 127;
    int anchor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001470_7013_9(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001470_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int accumulator_66 = local_arr[aux % 3];
    acc = (acc + accumulator_66 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_81 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_81 = (accumulator_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_81) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001470_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_15) & 63;
    acc ^= aux;
    int coefficient_62 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_62 > 38) {
        acc = (acc + coefficient_62 * 2 + 5) & 127;
        aux ^= (coefficient_62 & 15);
    } else {
        acc = (acc - coefficient_62 + 11) & 127;
        aux += 3;
    }
    int metric_66 = 0;
    for (int k = 0; k < 2; k++) {
        metric_66 = (metric_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_66) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_68 = local_arr[aux % 3];
    acc = (acc + threshold_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001470_7013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001470_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_75 = (aux + st.buffer[1]) & 3;
    switch (offset_75) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_78 = local_arr[aux % 3];
    acc = (acc + damping_78 * 2) & 127;
    int segment_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001470_7013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001470_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_72 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_72 > 34) {
        acc = (acc + index_reg_72 * 2 + 5) & 127;
        aux ^= (index_reg_72 & 15);
    } else {
        acc = (acc - index_reg_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_11 = local_arr[aux % 3];
    acc = (acc + tally_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001470_7013_13(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001470_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_52 = (aux + st.buffer[1]) & 3;
    switch (phase_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_44 = local_arr[aux % 3];
    acc = (acc + threshold_44 * 2) & 127;
    int residue_37 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_37 > 28) {
        acc = (acc + residue_37 * 2 + 5) & 127;
        aux ^= (residue_37 & 15);
    } else {
        acc = (acc - residue_37 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001470_7013_14(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001470_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_91 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_91 = (quotient_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_91) & 127;
    }
    int threshold_80 = (aux + st.buffer[1]) & 3;
    switch (threshold_80) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001470_7013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001470_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int phase_29 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_29 > 38) {
        acc = (acc + phase_29 * 2 + 5) & 127;
        aux ^= (phase_29 & 15);
    } else {
        acc = (acc - phase_29 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001470_7013_16(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001470_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int window_78 = (aux + st.buffer[1]) & 3;
    switch (window_78) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_75 > 39) {
        acc = (acc + anchor_75 * 2 + 5) & 127;
        aux ^= (anchor_75 & 15);
    } else {
        acc = (acc - anchor_75 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_67 = local_arr[aux % 3];
    acc = (acc + weight_67 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001470_7013_17(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001470_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int accumulator_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_13 = (aux + st.buffer[1]) & 3;
    switch (stride_13) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_37 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_37 > 26) {
        acc = (acc + accumulator_37 * 2 + 5) & 127;
        aux ^= (accumulator_37 & 15);
    } else {
        acc = (acc - accumulator_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001470_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_17) & 63;
    acc ^= aux;
    int index_reg_15 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_15 > 17) {
        acc = (acc + index_reg_15 * 2 + 5) & 127;
        aux ^= (index_reg_15 & 15);
    } else {
        acc = (acc - index_reg_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001470_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_10 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_10 > 23) {
        acc = (acc + weight_10 * 2 + 5) & 127;
        aux ^= (weight_10 & 15);
    } else {
        acc = (acc - weight_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_68 = local_arr[aux % 3];
    acc = (acc + metric_68 * 2) & 127;
    int damping_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_17) & 63;
    acc ^= aux;
    int tally_32 = (aux + st.buffer[1]) & 3;
    switch (tally_32) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001470_7013_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001470_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int metric_26 = local_arr[aux % 3];
    acc = (acc + metric_26 * 2) & 127;
    int weight_54 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_54 > 17) {
        acc = (acc + weight_54 * 2 + 5) & 127;
        aux ^= (weight_54 & 15);
    } else {
        acc = (acc - weight_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001470_0;
    int sec_r001470_1;
    int sec_r001470_2;
    int sec_r001470_3;
    int sec_r001470_4;
    int sec_r001470_5;
    int sec_r001470_6;
    int sec_r001470_7;
    int sec_r001470_8;
    int sec_r001470_9;
    int sec_r001470_10;
    int sec_r001470_11;
    int sec_r001470_12;
    int sec_r001470_13;
    int sec_r001470_14;
    int sec_r001470_15;
    int pub_r001470_0;
    int pub_r001470_1;
    int pub_r001470_2;
    int pub_r001470_3;
    int pub_r001470_4;
    int pub_r001470_5;
    int pub_r001470_6;
    int pub_r001470_7;
    int pub_r001470_8;
    int pub_r001470_9;
    int pub_r001470_10;
    int pub_r001470_11;
    int pub_r001470_12;
    int pub_r001470_13;
    int pub_r001470_14;
    int pub_r001470_15;
    int pub_r001470_16;
    int pub_r001470_17;
    int pub_r001470_18;
    int pub_r001470_19;
    int pub_r001470_20;
    int pub_r001470_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001470_0 >= -100 && pub_r001470_0 <= 100);
    __CPROVER_assume(pub_r001470_1 >= -100 && pub_r001470_1 <= 100);
    __CPROVER_assume(pub_r001470_2 >= -100 && pub_r001470_2 <= 100);
    __CPROVER_assume(pub_r001470_3 >= -100 && pub_r001470_3 <= 100);
    __CPROVER_assume(pub_r001470_4 >= -100 && pub_r001470_4 <= 100);
    __CPROVER_assume(pub_r001470_5 >= -100 && pub_r001470_5 <= 100);
    __CPROVER_assume(pub_r001470_6 >= -100 && pub_r001470_6 <= 100);
    __CPROVER_assume(pub_r001470_7 >= -100 && pub_r001470_7 <= 100);
    __CPROVER_assume(pub_r001470_8 >= -100 && pub_r001470_8 <= 100);
    __CPROVER_assume(pub_r001470_9 >= -100 && pub_r001470_9 <= 100);
    __CPROVER_assume(pub_r001470_10 >= -100 && pub_r001470_10 <= 100);
    __CPROVER_assume(pub_r001470_11 >= -100 && pub_r001470_11 <= 100);
    __CPROVER_assume(pub_r001470_12 >= -100 && pub_r001470_12 <= 100);
    __CPROVER_assume(pub_r001470_13 >= -100 && pub_r001470_13 <= 100);
    __CPROVER_assume(pub_r001470_14 >= -100 && pub_r001470_14 <= 100);
    __CPROVER_assume(pub_r001470_15 >= -100 && pub_r001470_15 <= 100);
    __CPROVER_assume(pub_r001470_16 >= -100 && pub_r001470_16 <= 100);
    __CPROVER_assume(pub_r001470_17 >= -100 && pub_r001470_17 <= 100);
    __CPROVER_assume(pub_r001470_18 >= -100 && pub_r001470_18 <= 100);
    __CPROVER_assume(pub_r001470_19 >= -100 && pub_r001470_19 <= 100);
    __CPROVER_assume(pub_r001470_20 >= -100 && pub_r001470_20 <= 100);
    __CPROVER_assume(pub_r001470_21 >= -100 && pub_r001470_21 <= 100);
    __CPROVER_assume(sec_r001470_0 >= 0 && sec_r001470_0 <= 255);
    __CPROVER_assume(sec_r001470_1 >= 0 && sec_r001470_1 <= 255);
    __CPROVER_assume(sec_r001470_2 >= 0 && sec_r001470_2 <= 255);
    __CPROVER_assume(sec_r001470_3 >= 0 && sec_r001470_3 <= 255);
    __CPROVER_assume(sec_r001470_4 >= 0 && sec_r001470_4 <= 255);
    __CPROVER_assume(sec_r001470_5 >= 0 && sec_r001470_5 <= 255);
    __CPROVER_assume(sec_r001470_6 >= 0 && sec_r001470_6 <= 255);
    __CPROVER_assume(sec_r001470_7 >= 0 && sec_r001470_7 <= 255);
    __CPROVER_assume(sec_r001470_8 >= 0 && sec_r001470_8 <= 255);
    __CPROVER_assume(sec_r001470_9 >= 0 && sec_r001470_9 <= 255);
    __CPROVER_assume(sec_r001470_10 >= 0 && sec_r001470_10 <= 255);
    __CPROVER_assume(sec_r001470_11 >= 0 && sec_r001470_11 <= 255);
    __CPROVER_assume(sec_r001470_12 >= 0 && sec_r001470_12 <= 255);
    __CPROVER_assume(sec_r001470_13 >= 0 && sec_r001470_13 <= 255);
    __CPROVER_assume(sec_r001470_14 >= 0 && sec_r001470_14 <= 255);
    __CPROVER_assume(sec_r001470_15 >= 0 && sec_r001470_15 <= 255);

    struct FilterState_R001470_7013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001470_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001470_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001470_0 + 7) & 15;
    struct SensorNode_R001470_7013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001470_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001470_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001470_0 + 9) & 15;
    struct Vector3D_R001470_7013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001470_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001470_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001470_0 + 11) & 15;
    struct CipherContext_R001470_7013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001470_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001470_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001470_0 + 13) & 15;

    union RegisterBank_R001470_7013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001470_7013_0(sec_r001470_0, pub_r001470_1, pub_r001470_2, pub_r001470_3);
    int helper_flow_1 = fn_R001470_7013_1(sec_r001470_1, sec_r001470_2);
    int helper_flow_2 = fn_R001470_7013_2(sec_r001470_2, pub_r001470_3, pub_r001470_4);
    int helper_flow_3 = fn_R001470_7013_3(sec_r001470_3, sec_r001470_4);
    int helper_flow_4 = fn_R001470_7013_4(sec_r001470_4, sec_r001470_5, pub_r001470_6);
    int helper_flow_5 = fn_R001470_7013_5(sec_r001470_5, pub_r001470_6, pub_r001470_7);
    int helper_flow_6 = fn_R001470_7013_6(sec_r001470_6, pub_r001470_7, pub_r001470_8);
    int helper_flow_7 = fn_R001470_7013_7(sec_r001470_7, pub_r001470_8, pub_r001470_9, pub_r001470_10, pub_r001470_11);
    int helper_flow_8 = fn_R001470_7013_8(sec_r001470_8, sec_r001470_9);
    int helper_flow_9 = fn_R001470_7013_9(sec_r001470_9, sec_r001470_10, pub_r001470_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001470_4 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_0 > 21) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001470_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001470_1) & 127;
    if (stage_v_2 > 28) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001470_8 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_3 > 48) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_4 > 29) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_5 > 42) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001470_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001470_1 ^ 0x2A) * 2 + pub_r001470_8) & 127;
    if (stage_v_7 > 34) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001470_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001470_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001470_13 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_10 > 29) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001470_5 ^ 0x2A) * 2 + pub_r001470_4) & 127;
    if (stage_v_11 > 27) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001470_3 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_12 > 46) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001470_9 ^ 0x2A) * 2 + pub_r001470_14) & 127;
    if (stage_v_13 > 45) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001470_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_15 > 20) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001470_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001470_14 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_17 > 43) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001470_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001470_12 ^ 0x2A) * 2 + pub_r001470_5) & 127;
    if (stage_v_19 > 39) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001470_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_21 > 32) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_22 > 22) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001470_10 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_23 > 31) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001470_7) & 127;
    if (stage_v_24 > 32) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001470_4 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_25 > 47) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001470_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001470_5) & 127;
    if (stage_v_27 > 25) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_28 > 35) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001470_3 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_29 > 49) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_30 > 35) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001470_1) & 127;
    if (stage_v_31 > 29) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001470_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001470_15) & 127;
    if (stage_v_33 > 23) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001470_3 ^ 0x2A) * 2 + pub_r001470_15) & 127;
    if (stage_v_34 > 38) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001470_6 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_35 > 31) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_36 > 39) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_37 > 35) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_38 > 27) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_39 > 46) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001470_1 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_40 > 23) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001470_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001470_15) & 127;
    if (stage_v_42 > 32) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_43 > 46) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001470_13 ^ 0x2A) * 2 + pub_r001470_1) & 127;
    if (stage_v_44 > 22) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001470_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001470_7 ^ 0x2A) * 2 + pub_r001470_14) & 127;
    if (stage_v_46 > 21) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_47 > 37) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001470_14) & 127;
    if (stage_v_48 > 43) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_49 > 41) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_50 > 49) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001470_2 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_51 > 40) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_52 > 49) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001470_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_54 > 36) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001470_7) & 127;
    if (stage_v_55 > 31) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_56 > 45) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001470_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001470_8 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_58 > 32) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_59 > 46) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001470_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_61 > 49) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001470_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001470_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001470_8) & 127;
    if (stage_v_64 > 42) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001470_8) & 127;
    if (stage_v_65 > 48) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001470_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001470_0 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_67 > 49) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_68 > 28) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_69 > 23) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001470_6 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_70 > 33) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_71 > 29) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001470_9 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_72 > 38) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001470_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_74 > 37) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001470_1) & 127;
    if (stage_v_75 > 38) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001470_1 ^ 0x2A) * 2 + pub_r001470_17) & 127;
    if (stage_v_76 > 36) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001470_0 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_77 > 36) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_78 > 50) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_79 > 50) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001470_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001470_15 ^ 0x2A) * 2 + pub_r001470_8) & 127;
    if (stage_v_81 > 35) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001470_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001470_14) & 127;
    if (stage_v_83 > 49) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_84 > 23) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001470_20 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001470_20 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_87 > 25) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001470_0) & 127;
    if (stage_v_88 > 30) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001470_15 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_89 > 44) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_90 > 29) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001470_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001470_5 ^ 0x2A) * 2 + pub_r001470_0) & 127;
    if (stage_v_92 > 48) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_93 > 31) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001470_12 ^ 0x2A) * 2 + pub_r001470_17) & 127;
    if (stage_v_94 > 48) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_95 > 22) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001470_9) & 127;
    if (stage_v_96 > 23) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001470_0) & 127;
    if (stage_v_97 > 30) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_98 > 48) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_99 > 45) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001470_12 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_100 > 45) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001470_21 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001470_7) & 127;
    if (stage_v_102 > 37) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_103 > 44) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_104 > 23) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_105 > 44) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_106 > 36) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_107 > 47) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_108 > 40) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001470_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_110 > 47) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001470_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_112 > 36) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001470_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_114 > 44) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_115 > 20) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_116 > 25) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001470_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001470_8) & 127;
    if (stage_v_118 > 48) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001470_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_120 > 44) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001470_12 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_121 > 24) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r001470_13 ^ 0x2A) * 2 + pub_r001470_9) & 127;
    if (stage_v_122 > 49) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001470_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001470_15) & 127;
    if (stage_v_124 > 26) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_125 > 28) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_126 > 31) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_127 > 39) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_128 > 42) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001470_17) & 127;
    if (stage_v_129 > 50) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001470_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_131 > 38) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_132 > 40) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_133 > 35) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001470_9) & 127;
    if (stage_v_134 > 22) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_135 > 21) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_136 > 28) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001470_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_138 > 23) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001470_1) & 127;
    if (stage_v_139 > 35) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001470_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001470_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_142 > 22) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001470_4) & 127;
    if (stage_v_143 > 48) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001470_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001470_4) & 127;
    if (stage_v_145 > 36) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001470_9) & 127;
    if (stage_v_146 > 29) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_147 > 30) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001470_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_149 > 29) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001470_4) & 127;
    if (stage_v_150 > 23) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_151 > 42) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001470_7) & 127;
    if (stage_v_152 > 43) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_153 > 38) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001470_9) & 127;
    if (stage_v_154 > 25) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001470_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001470_15) & 127;
    if (stage_v_156 > 43) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_157 > 22) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001470_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001470_6) & 127;
    if (stage_v_159 > 39) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001470_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_161 > 48) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001470_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_163 > 40) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001470_7) & 127;
    if (stage_v_164 > 40) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r001470_7 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_165 > 27) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_166 > 44) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r001470_8 ^ 0x2A) * 2 + pub_r001470_15) & 127;
    if (stage_v_167 > 42) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001470_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_169 > 39) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_170 > 23) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_171 > 31) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_172 > 46) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r001470_2 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_173 > 45) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_174 > 36) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001470_8) & 127;
    if (stage_v_175 > 47) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001470_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001470_0) & 127;
    if (stage_v_177 > 37) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001470_12) & 127;
    if (stage_v_178 > 25) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_179 > 33) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_180 > 48) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_181 > 33) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_182 > 37) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_183 > 39) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_180 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_184 > 41) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001470_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_186 > 42) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r001470_11 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_187 > 24) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001470_0) & 127;
    if (stage_v_188 > 40) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001470_9) & 127;
    if (stage_v_189 > 25) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001470_14) & 127;
    if (stage_v_190 > 35) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001470_3) & 127;
    if (stage_v_191 > 47) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001470_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_193 > 49) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001470_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_195 > 38) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001470_2) & 127;
    if (stage_v_196 > 21) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001470_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_198 > 29) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001470_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001470_10) & 127;
    if (stage_v_200 > 42) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001470_13) & 127;
    if (stage_v_201 > 47) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001470_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001470_14) & 127;
    if (stage_v_203 > 39) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001470_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001470_4) & 127;
    if (stage_v_205 > 23) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_206 > 22) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_189 ^ 0x2A) * 2 + pub_r001470_4) & 127;
    if (stage_v_207 > 23) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001470_16) & 127;
    if (stage_v_208 > 20) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001470_21 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001470_20) & 127;
    if (stage_v_210 > 29) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001470_13 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_211 > 45) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r001470_4 ^ 0x2A) * 2 + pub_r001470_21) & 127;
    if (stage_v_212 > 44) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001470_11) & 127;
    if (stage_v_213 > 35) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001470_18) & 127;
    if (stage_v_214 > 45) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_201 ^ 0x2A) * 2 + pub_r001470_19) & 127;
    if (stage_v_215 > 33) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
