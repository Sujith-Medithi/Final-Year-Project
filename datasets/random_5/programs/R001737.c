/*
 * Benchmark Program: R001737
 * Security Family: nested_implicit_flow
 * Generator Seed: 673713
 * High Inputs: 16 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001737_3713_0 {
    unsigned char dim;
    short stride;
    short determinant;
    int buffer[3];
};

struct Vector3D_R001737_3713_1 {
    unsigned char coord_x;
    int norm_sq;
    short coord_z;
    int heading;
    int buffer[3];
};

struct FilterState_R001737_3713_2 {
    unsigned char cutoff;
    unsigned char prev_in;
    short gain_db;
    short damping;
    int mode;
    int prev_out;
    int buffer[3];
};

struct SensorNode_R001737_3713_3 {
    int calib;
    unsigned char reading;
    short threshold;
    unsigned char offset;
    short gain;
    int status;
    int buffer[3];
};

union RegisterBank_R001737_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001737_3713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001737_3713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001737_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_94 = (aux + st.buffer[1]) & 3;
    switch (offset_94) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_45) & 63;
    acc ^= aux;
    int sample_69 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_69 > 46) {
        acc = (acc + sample_69 * 2 + 5) & 127;
        aux ^= (sample_69 & 15);
    } else {
        acc = (acc - sample_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001737_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int bound_72 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_72 > 15) {
        acc = (acc + bound_72 * 2 + 5) & 127;
        aux ^= (bound_72 & 15);
    } else {
        acc = (acc - bound_72 + 11) & 127;
        aux += 3;
    }
    int stride_84 = 0;
    for (int k = 0; k < 2; k++) {
        stride_84 = (stride_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_84) & 127;
    }
    int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_11) & 63;
    acc ^= aux;
    int residue_11 = (aux + st.buffer[1]) & 3;
    switch (residue_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_2(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001737_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int phase_26 = 0;
    for (int k = 0; k < 2; k++) {
        phase_26 = (phase_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_26) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_96 = (aux + st.buffer[1]) & 3;
    switch (stride_96) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001737_3713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001737_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int margin_26 = (aux + st.buffer[1]) & 3;
    switch (margin_26) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_99 = 0;
    for (int k = 0; k < 2; k++) {
        bound_99 = (bound_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_99) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_39 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_39 > 48) {
        acc = (acc + stride_39 * 2 + 5) & 127;
        aux ^= (stride_39 & 15);
    } else {
        acc = (acc - stride_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_4(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001737_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int pivot_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_83) & 63;
    acc ^= aux;
    int anchor_65 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_65 = (anchor_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_65) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_32 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_32 > 20) {
        acc = (acc + stride_32 * 2 + 5) & 127;
        aux ^= (stride_32 & 15);
    } else {
        acc = (acc - stride_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_5(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001737_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int mask_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_18) & 63;
    acc ^= aux;
    int metric_77 = 0;
    for (int k = 0; k < 2; k++) {
        metric_77 = (metric_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_77) & 127;
    }
    int factor_16 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_16 > 29) {
        acc = (acc + factor_16 * 2 + 5) & 127;
        aux ^= (factor_16 & 15);
    } else {
        acc = (acc - factor_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_60 = local_arr[aux % 3];
    acc = (acc + weight_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001737_3713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001737_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int margin_69 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_69 > 26) {
        acc = (acc + margin_69 * 2 + 5) & 127;
        aux ^= (margin_69 & 15);
    } else {
        acc = (acc - margin_69 + 11) & 127;
        aux += 3;
    }
    int metric_17 = 0;
    for (int k = 0; k < 3; k++) {
        metric_17 = (metric_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_17) & 127;
    }
    int anchor_66 = (aux + st.buffer[1]) & 3;
    switch (anchor_66) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001737_3713_7(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001737_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_86 = 0;
    for (int k = 0; k < 2; k++) {
        factor_86 = (factor_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_86) & 127;
    }
    int weight_95 = (aux + st.buffer[1]) & 3;
    switch (weight_95) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_53 = local_arr[aux % 3];
    acc = (acc + checksum_53 * 2) & 127;
    int scale_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001737_3713_8(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001737_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_90 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_90 = (coefficient_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_90) & 127;
    }
    int vector_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001737_3713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001737_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int offset_59 = local_arr[aux % 3];
    acc = (acc + offset_59 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_10 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_10 = (pivot_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_10) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001737_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int accumulator_91 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_91 = (accumulator_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_91) & 127;
    }
    int metric_45 = (aux + st.buffer[1]) & 3;
    switch (metric_45) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_14 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_14 > 35) {
        acc = (acc + vector_14 * 2 + 5) & 127;
        aux ^= (vector_14 & 15);
    } else {
        acc = (acc - vector_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_38 = local_arr[aux % 3];
    acc = (acc + bound_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001737_3713_11(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001737_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int weight_72 = local_arr[aux % 3];
    acc = (acc + weight_72 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001737_3713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001737_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_88) & 63;
    acc ^= aux;
    int checksum_42 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_42 = (checksum_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_42) & 127;
    }
    int parity_67 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_67 > 11) {
        acc = (acc + parity_67 * 2 + 5) & 127;
        aux ^= (parity_67 & 15);
    } else {
        acc = (acc - parity_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_13(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001737_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int cursor_78 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_78 = (cursor_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_78) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_48 = local_arr[aux % 3];
    acc = (acc + damping_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_73 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_73 > 11) {
        acc = (acc + stride_73 * 2 + 5) & 127;
        aux ^= (stride_73 & 15);
    } else {
        acc = (acc - stride_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001737_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int mask_13 = 0;
    for (int k = 0; k < 3; k++) {
        mask_13 = (mask_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_13) & 127;
    }
    int anchor_42 = (aux + st.buffer[1]) & 3;
    switch (anchor_42) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_98 = local_arr[aux % 3];
    acc = (acc + residue_98 * 2) & 127;
    int checksum_65 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_65 > 10) {
        acc = (acc + checksum_65 * 2 + 5) & 127;
        aux ^= (checksum_65 & 15);
    } else {
        acc = (acc - checksum_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_15(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001737_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_91 = (aux + st.buffer[1]) & 3;
    switch (damping_91) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_16(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001737_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int weight_98 = (aux + st.buffer[1]) & 3;
    switch (weight_98) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_77) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_78 = local_arr[aux % 3];
    acc = (acc + offset_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001737_3713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001737_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int weight_76 = 0;
    for (int k = 0; k < 2; k++) {
        weight_76 = (weight_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_76) & 127;
    }
    int residue_24 = (aux + st.buffer[1]) & 3;
    switch (residue_24) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001737_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_47 = (aux + st.buffer[1]) & 3;
    switch (damping_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_34 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_34 > 44) {
        acc = (acc + cursor_34 * 2 + 5) & 127;
        aux ^= (cursor_34 & 15);
    } else {
        acc = (acc - cursor_34 + 11) & 127;
        aux += 3;
    }
    int coefficient_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001737_3713_19(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001737_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quotient_59 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_59 > 38) {
        acc = (acc + quotient_59 * 2 + 5) & 127;
        aux ^= (quotient_59 & 15);
    } else {
        acc = (acc - quotient_59 + 11) & 127;
        aux += 3;
    }
    int phase_24 = (aux + st.buffer[1]) & 3;
    switch (phase_24) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_20 = local_arr[aux % 3];
    acc = (acc + damping_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001737_3713_20(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001737_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int margin_38 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_38 > 44) {
        acc = (acc + margin_38 * 2 + 5) & 127;
        aux ^= (margin_38 & 15);
    } else {
        acc = (acc - margin_38 + 11) & 127;
        aux += 3;
    }
    int offset_82 = (aux + st.buffer[1]) & 3;
    switch (offset_82) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001737_3713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001737_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int offset_94 = local_arr[aux % 3];
    acc = (acc + offset_94 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_80 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_80 > 33) {
        acc = (acc + vector_80 * 2 + 5) & 127;
        aux ^= (vector_80 & 15);
    } else {
        acc = (acc - vector_80 + 11) & 127;
        aux += 3;
    }
    int mask_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001737_3713_22(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001737_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_43 = 0;
    for (int k = 0; k < 3; k++) {
        mask_43 = (mask_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_43) & 127;
    }
    int accumulator_60 = (aux + st.buffer[1]) & 3;
    switch (accumulator_60) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001737_3713_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001737_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int sample_58 = local_arr[aux % 3];
    acc = (acc + sample_58 * 2) & 127;
    int quantum_75 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_75 = (quantum_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_75) & 127;
    }
    int quotient_98 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_98 > 20) {
        acc = (acc + quotient_98 * 2 + 5) & 127;
        aux ^= (quotient_98 & 15);
    } else {
        acc = (acc - quotient_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001737_0;
    int sec_r001737_1;
    int sec_r001737_2;
    int sec_r001737_3;
    int sec_r001737_4;
    int sec_r001737_5;
    int sec_r001737_6;
    int sec_r001737_7;
    int sec_r001737_8;
    int sec_r001737_9;
    int sec_r001737_10;
    int sec_r001737_11;
    int sec_r001737_12;
    int sec_r001737_13;
    int sec_r001737_14;
    int sec_r001737_15;
    int pub_r001737_0;
    int pub_r001737_1;
    int pub_r001737_2;
    int pub_r001737_3;
    int pub_r001737_4;
    int pub_r001737_5;
    int pub_r001737_6;
    int pub_r001737_7;
    int pub_r001737_8;
    int pub_r001737_9;
    int pub_r001737_10;
    int pub_r001737_11;
    int pub_r001737_12;
    int pub_r001737_13;
    int pub_r001737_14;
    int pub_r001737_15;
    int pub_r001737_16;
    int pub_r001737_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001737_0 >= -100 && pub_r001737_0 <= 100);
    __CPROVER_assume(pub_r001737_1 >= -100 && pub_r001737_1 <= 100);
    __CPROVER_assume(pub_r001737_2 >= -100 && pub_r001737_2 <= 100);
    __CPROVER_assume(pub_r001737_3 >= -100 && pub_r001737_3 <= 100);
    __CPROVER_assume(pub_r001737_4 >= -100 && pub_r001737_4 <= 100);
    __CPROVER_assume(pub_r001737_5 >= -100 && pub_r001737_5 <= 100);
    __CPROVER_assume(pub_r001737_6 >= -100 && pub_r001737_6 <= 100);
    __CPROVER_assume(pub_r001737_7 >= -100 && pub_r001737_7 <= 100);
    __CPROVER_assume(pub_r001737_8 >= -100 && pub_r001737_8 <= 100);
    __CPROVER_assume(pub_r001737_9 >= -100 && pub_r001737_9 <= 100);
    __CPROVER_assume(pub_r001737_10 >= -100 && pub_r001737_10 <= 100);
    __CPROVER_assume(pub_r001737_11 >= -100 && pub_r001737_11 <= 100);
    __CPROVER_assume(pub_r001737_12 >= -100 && pub_r001737_12 <= 100);
    __CPROVER_assume(pub_r001737_13 >= -100 && pub_r001737_13 <= 100);
    __CPROVER_assume(pub_r001737_14 >= -100 && pub_r001737_14 <= 100);
    __CPROVER_assume(pub_r001737_15 >= -100 && pub_r001737_15 <= 100);
    __CPROVER_assume(pub_r001737_16 >= -100 && pub_r001737_16 <= 100);
    __CPROVER_assume(pub_r001737_17 >= -100 && pub_r001737_17 <= 100);
    __CPROVER_assume(sec_r001737_0 >= 0 && sec_r001737_0 <= 255);
    __CPROVER_assume(sec_r001737_1 >= 0 && sec_r001737_1 <= 255);
    __CPROVER_assume(sec_r001737_2 >= 0 && sec_r001737_2 <= 255);
    __CPROVER_assume(sec_r001737_3 >= 0 && sec_r001737_3 <= 255);
    __CPROVER_assume(sec_r001737_4 >= 0 && sec_r001737_4 <= 255);
    __CPROVER_assume(sec_r001737_5 >= 0 && sec_r001737_5 <= 255);
    __CPROVER_assume(sec_r001737_6 >= 0 && sec_r001737_6 <= 255);
    __CPROVER_assume(sec_r001737_7 >= 0 && sec_r001737_7 <= 255);
    __CPROVER_assume(sec_r001737_8 >= 0 && sec_r001737_8 <= 255);
    __CPROVER_assume(sec_r001737_9 >= 0 && sec_r001737_9 <= 255);
    __CPROVER_assume(sec_r001737_10 >= 0 && sec_r001737_10 <= 255);
    __CPROVER_assume(sec_r001737_11 >= 0 && sec_r001737_11 <= 255);
    __CPROVER_assume(sec_r001737_12 >= 0 && sec_r001737_12 <= 255);
    __CPROVER_assume(sec_r001737_13 >= 0 && sec_r001737_13 <= 255);
    __CPROVER_assume(sec_r001737_14 >= 0 && sec_r001737_14 <= 255);
    __CPROVER_assume(sec_r001737_15 >= 0 && sec_r001737_15 <= 255);

    struct MatrixBlock_R001737_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001737_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001737_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001737_0 + 7) & 15;
    struct Vector3D_R001737_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001737_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001737_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001737_0 + 9) & 15;
    struct FilterState_R001737_3713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001737_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001737_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001737_0 + 11) & 15;
    struct SensorNode_R001737_3713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001737_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001737_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001737_0 + 13) & 15;

    union RegisterBank_R001737_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001737_3713_0(sec_r001737_0, pub_r001737_1, pub_r001737_2, pub_r001737_3, pub_r001737_4);
    int helper_flow_1 = fn_R001737_3713_1(sec_r001737_1, pub_r001737_2, pub_r001737_3, pub_r001737_4, pub_r001737_5);
    int helper_flow_2 = fn_R001737_3713_2(sec_r001737_2, pub_r001737_3, pub_r001737_4);
    int helper_flow_3 = fn_R001737_3713_3(sec_r001737_3, sec_r001737_4, pub_r001737_5, pub_r001737_6);
    int helper_flow_4 = fn_R001737_3713_4(sec_r001737_4, sec_r001737_5);
    int helper_flow_5 = fn_R001737_3713_5(sec_r001737_5, pub_r001737_6);
    int helper_flow_6 = fn_R001737_3713_6(sec_r001737_6, sec_r001737_7, pub_r001737_8, pub_r001737_9, pub_r001737_10);
    int helper_flow_7 = fn_R001737_3713_7(sec_r001737_7, sec_r001737_8, pub_r001737_9);
    int helper_flow_8 = fn_R001737_3713_8(sec_r001737_8, sec_r001737_9, pub_r001737_10);
    int helper_flow_9 = fn_R001737_3713_9(sec_r001737_9, sec_r001737_10, pub_r001737_11, pub_r001737_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001737_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_3 ^ pub_r001737_0) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001737_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001737_12 ^ pub_r001737_4) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001737_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001737_4 ^ pub_r001737_11) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001737_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001737_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001737_12 ^ pub_r001737_3) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001737_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_3 ^ pub_r001737_13) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_5 ^ pub_r001737_8) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001737_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001737_7 ^ pub_r001737_1) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001737_1 ^ pub_r001737_0) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001737_6 ^ pub_r001737_9) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_5 ^ pub_r001737_11) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001737_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_8 ^ pub_r001737_11) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001737_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001737_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001737_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001737_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_0 ^ pub_r001737_0) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_19 ^ pub_r001737_15) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001737_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001737_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_8 ^ pub_r001737_14) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001737_10 ^ pub_r001737_11) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_3 ^ pub_r001737_4) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001737_4 ^ pub_r001737_8) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001737_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001737_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_9 ^ pub_r001737_4) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001737_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_0 ^ pub_r001737_4) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_3 ^ pub_r001737_5) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001737_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_10 ^ pub_r001737_6) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001737_13 ^ pub_r001737_15) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001737_5 ^ pub_r001737_6) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001737_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001737_1 ^ pub_r001737_7) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001737_9 ^ pub_r001737_12) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001737_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001737_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001737_3 ^ pub_r001737_2) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001737_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001737_7 ^ pub_r001737_3) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_34 ^ pub_r001737_15) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001737_3 ^ pub_r001737_7) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001737_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_10 ^ pub_r001737_7) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (helper_flow_5 ^ pub_r001737_5) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_15 ^ pub_r001737_11) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_9 ^ pub_r001737_5) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001737_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_0 ^ pub_r001737_8) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_35 ^ pub_r001737_10) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_1 ^ pub_r001737_9) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_37 ^ pub_r001737_13) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001737_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_9 ^ pub_r001737_3) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_10 ^ pub_r001737_11) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (helper_flow_1 ^ pub_r001737_15) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001737_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_56 ^ pub_r001737_7) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001737_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001737_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_59 ^ pub_r001737_16) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001737_0 ^ pub_r001737_0) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001737_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001737_8 ^ pub_r001737_6) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_6 ^ pub_r001737_12) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_20 ^ pub_r001737_8) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001737_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_51 ^ pub_r001737_14) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_63 ^ pub_r001737_5) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001737_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001737_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_29 ^ pub_r001737_12) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_7 ^ pub_r001737_1) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_31 ^ pub_r001737_13) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r001737_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_12 ^ pub_r001737_5) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001737_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001737_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_3 ^ pub_r001737_4) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_3 ^ pub_r001737_2) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001737_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001737_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001737_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001737_9 ^ pub_r001737_12) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r001737_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_13 ^ pub_r001737_7) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001737_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001737_6 ^ pub_r001737_15) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_56 ^ pub_r001737_6) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_10 ^ pub_r001737_2) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (helper_flow_4 ^ pub_r001737_0) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001737_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_47 ^ pub_r001737_11) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r001737_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001737_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_9 ^ pub_r001737_8) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001737_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_5 ^ pub_r001737_10) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_12 ^ pub_r001737_14) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001737_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_88 ^ pub_r001737_0) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_5 ^ pub_r001737_8) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001737_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001737_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_51 ^ pub_r001737_6) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (helper_flow_1 ^ pub_r001737_12) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r001737_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001737_10 ^ pub_r001737_17) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_15 ^ pub_r001737_1) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (helper_flow_4 ^ pub_r001737_15) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r001737_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001737_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_48 ^ pub_r001737_11) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001737_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_42 ^ pub_r001737_1) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001737_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001737_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001737_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001737_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_7 ^ pub_r001737_1) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_89 ^ pub_r001737_17) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_9 ^ pub_r001737_9) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r001737_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001737_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001737_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001737_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (sec_r001737_8 ^ pub_r001737_11) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (helper_flow_4 ^ pub_r001737_16) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001737_1 ^ pub_r001737_6) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_103 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_5 ^ pub_r001737_14) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_43 ^ pub_r001737_1) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001737_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001737_4 ^ pub_r001737_6) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_75 ^ pub_r001737_6) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_99 ^ pub_r001737_5) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001737_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_91 ^ pub_r001737_11) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_5 ^ pub_r001737_5) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_105 ^ pub_r001737_4) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001737_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_12 ^ pub_r001737_9) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((sec_r001737_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (sec_r001737_3 ^ pub_r001737_4) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_122 ^ pub_r001737_0) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_23 ^ pub_r001737_9) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_52 ^ pub_r001737_2) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001737_6 ^ pub_r001737_2) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_103 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001737_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (helper_flow_3 ^ pub_r001737_1) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_132 ^ pub_r001737_15) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_122 ^ pub_r001737_4) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_121 ^ pub_r001737_14) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r001737_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_32 ^ pub_r001737_16) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_43 ^ pub_r001737_0) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001737_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_104 ^ pub_r001737_0) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001737_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_91 ^ pub_r001737_16) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001737_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_128 ^ pub_r001737_2) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_146 ^ pub_r001737_17) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_145 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
