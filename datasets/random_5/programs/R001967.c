/*
 * Benchmark Program: R001967
 * Security Family: nested_implicit_flow
 * Generator Seed: 696713
 * High Inputs: 20 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001967_6713_0 {
    int checksum;
    short state;
    unsigned char tail;
    short watermark;
    int buffer[3];
};

struct Vector3D_R001967_6713_1 {
    int coord_z;
    short pitch;
    unsigned char heading;
    unsigned char coord_y;
    short coord_x;
    short norm_sq;
    int buffer[3];
};

struct MatrixBlock_R001967_6713_2 {
    int scale;
    int density;
    int dim;
    int buffer[3];
};

union ColorPixel_R001967_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001967_6713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001967_6713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_31 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_31 = (cursor_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_31) & 127;
    }
    int checksum_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_67) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_27 = local_arr[aux % 3];
    acc = (acc + parity_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_96 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_96 > 47) {
        acc = (acc + pivot_96 * 2 + 5) & 127;
        aux ^= (pivot_96 & 15);
    } else {
        acc = (acc - pivot_96 + 11) & 127;
        aux += 3;
    }
    int metric_59 = (aux + st.buffer[1]) & 3;
    switch (metric_59) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_2(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int scale_41 = 0;
    for (int k = 0; k < 3; k++) {
        scale_41 = (scale_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_41) & 127;
    }
    int threshold_78 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_78 > 22) {
        acc = (acc + threshold_78 * 2 + 5) & 127;
        aux ^= (threshold_78 & 15);
    } else {
        acc = (acc - threshold_78 + 11) & 127;
        aux += 3;
    }
    int offset_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_85) & 63;
    acc ^= aux;
    int coefficient_32 = (aux + st.buffer[1]) & 3;
    switch (coefficient_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001967_6713_3(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int parity_59 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_59 > 35) {
        acc = (acc + parity_59 * 2 + 5) & 127;
        aux ^= (parity_59 & 15);
    } else {
        acc = (acc - parity_59 + 11) & 127;
        aux += 3;
    }
    int pivot_35 = (aux + st.buffer[1]) & 3;
    switch (pivot_35) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_23 = local_arr[aux % 3];
    acc = (acc + vector_23 * 2) & 127;
    int margin_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001967_6713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int threshold_37 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_37 > 37) {
        acc = (acc + threshold_37 * 2 + 5) & 127;
        aux ^= (threshold_37 & 15);
    } else {
        acc = (acc - threshold_37 + 11) & 127;
        aux += 3;
    }
    int tally_77 = (aux + st.buffer[1]) & 3;
    switch (tally_77) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_85 = 0;
    for (int k = 0; k < 3; k++) {
        window_85 = (window_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_85) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_42 = local_arr[aux % 3];
    acc = (acc + coefficient_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int threshold_74 = (aux + st.buffer[1]) & 3;
    switch (threshold_74) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_55 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_55 > 34) {
        acc = (acc + damping_55 * 2 + 5) & 127;
        aux ^= (damping_55 & 15);
    } else {
        acc = (acc - damping_55 + 11) & 127;
        aux += 3;
    }
    int pivot_88 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_88 = (pivot_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_88) & 127;
    }
    int bound_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001967_6713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_69 = (aux + st.buffer[1]) & 3;
    switch (index_reg_69) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001967_6713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_40 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_40 > 12) {
        acc = (acc + vector_40 * 2 + 5) & 127;
        aux ^= (vector_40 & 15);
    } else {
        acc = (acc - vector_40 + 11) & 127;
        aux += 3;
    }
    int accumulator_53 = (aux + st.buffer[1]) & 3;
    switch (accumulator_53) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_91 = local_arr[aux % 3];
    acc = (acc + delta_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_8(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_26 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_26 > 48) {
        acc = (acc + weight_26 * 2 + 5) & 127;
        aux ^= (weight_26 & 15);
    } else {
        acc = (acc - weight_26 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_20 = local_arr[aux % 3];
    acc = (acc + bound_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001967_6713_9(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_52) & 63;
    acc ^= aux;
    int bound_18 = 0;
    for (int k = 0; k < 3; k++) {
        bound_18 = (bound_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_18) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001967_6713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_95 = (aux + st.buffer[1]) & 3;
    switch (factor_95) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_16 = local_arr[aux % 3];
    acc = (acc + index_reg_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int scale_77 = (aux + st.buffer[1]) & 3;
    switch (scale_77) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_15 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_15 > 13) {
        acc = (acc + pivot_15 * 2 + 5) & 127;
        aux ^= (pivot_15 & 15);
    } else {
        acc = (acc - pivot_15 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_54 = local_arr[aux % 3];
    acc = (acc + quantum_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_74 = 0;
    for (int k = 0; k < 2; k++) {
        phase_74 = (phase_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_74) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_74 = local_arr[aux % 3];
    acc = (acc + weight_74 * 2) & 127;
    int delta_18 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_18 > 39) {
        acc = (acc + delta_18 * 2 + 5) & 127;
        aux ^= (delta_18 & 15);
    } else {
        acc = (acc - delta_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001967_6713_13(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_43 = (aux + st.buffer[1]) & 3;
    switch (vector_43) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_81) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_83 = local_arr[aux % 3];
    acc = (acc + accumulator_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_14(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_62) & 63;
    acc ^= aux;
    int scale_87 = (aux + st.buffer[1]) & 3;
    switch (scale_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001967_6713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_74 = local_arr[aux % 3];
    acc = (acc + anchor_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_23 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_23 = (index_reg_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_23) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_56 = local_arr[aux % 3];
    acc = (acc + metric_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int delta_28 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_28 > 23) {
        acc = (acc + delta_28 * 2 + 5) & 127;
        aux ^= (delta_28 & 15);
    } else {
        acc = (acc - delta_28 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001967_6713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_10 = (aux + st.buffer[1]) & 3;
    switch (pivot_10) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_42 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_42 = (pivot_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001967_6713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_14) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_92 = local_arr[aux % 3];
    acc = (acc + threshold_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001967_6713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001967_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_92 = local_arr[aux % 3];
    acc = (acc + offset_92 * 2) & 127;
    int index_reg_34 = (aux + st.buffer[1]) & 3;
    switch (index_reg_34) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001967_6713_21(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001967_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int damping_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_96 = local_arr[aux % 3];
    acc = (acc + threshold_96 * 2) & 127;
    int offset_60 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_60 > 50) {
        acc = (acc + offset_60 * 2 + 5) & 127;
        aux ^= (offset_60 & 15);
    } else {
        acc = (acc - offset_60 + 11) & 127;
        aux += 3;
    }
    int offset_24 = 0;
    for (int k = 0; k < 3; k++) {
        offset_24 = (offset_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_24) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001967_6713_22(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001967_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int segment_63 = 0;
    for (int k = 0; k < 2; k++) {
        segment_63 = (segment_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_63) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_20 = local_arr[aux % 3];
    acc = (acc + tally_20 * 2) & 127;
    int delta_22 = (aux + st.buffer[1]) & 3;
    switch (delta_22) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001967_0;
    int sec_r001967_1;
    int sec_r001967_2;
    int sec_r001967_3;
    int sec_r001967_4;
    int sec_r001967_5;
    int sec_r001967_6;
    int sec_r001967_7;
    int sec_r001967_8;
    int sec_r001967_9;
    int sec_r001967_10;
    int sec_r001967_11;
    int sec_r001967_12;
    int sec_r001967_13;
    int sec_r001967_14;
    int sec_r001967_15;
    int sec_r001967_16;
    int sec_r001967_17;
    int sec_r001967_18;
    int sec_r001967_19;
    int pub_r001967_0;
    int pub_r001967_1;
    int pub_r001967_2;
    int pub_r001967_3;
    int pub_r001967_4;
    int pub_r001967_5;
    int pub_r001967_6;
    int pub_r001967_7;
    int pub_r001967_8;
    int pub_r001967_9;
    int pub_r001967_10;
    int pub_r001967_11;
    int pub_r001967_12;
    int pub_r001967_13;
    int pub_r001967_14;
    int pub_r001967_15;
    int pub_r001967_16;
    int pub_r001967_17;
    int pub_r001967_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001967_0 >= -100 && pub_r001967_0 <= 100);
    __CPROVER_assume(pub_r001967_1 >= -100 && pub_r001967_1 <= 100);
    __CPROVER_assume(pub_r001967_2 >= -100 && pub_r001967_2 <= 100);
    __CPROVER_assume(pub_r001967_3 >= -100 && pub_r001967_3 <= 100);
    __CPROVER_assume(pub_r001967_4 >= -100 && pub_r001967_4 <= 100);
    __CPROVER_assume(pub_r001967_5 >= -100 && pub_r001967_5 <= 100);
    __CPROVER_assume(pub_r001967_6 >= -100 && pub_r001967_6 <= 100);
    __CPROVER_assume(pub_r001967_7 >= -100 && pub_r001967_7 <= 100);
    __CPROVER_assume(pub_r001967_8 >= -100 && pub_r001967_8 <= 100);
    __CPROVER_assume(pub_r001967_9 >= -100 && pub_r001967_9 <= 100);
    __CPROVER_assume(pub_r001967_10 >= -100 && pub_r001967_10 <= 100);
    __CPROVER_assume(pub_r001967_11 >= -100 && pub_r001967_11 <= 100);
    __CPROVER_assume(pub_r001967_12 >= -100 && pub_r001967_12 <= 100);
    __CPROVER_assume(pub_r001967_13 >= -100 && pub_r001967_13 <= 100);
    __CPROVER_assume(pub_r001967_14 >= -100 && pub_r001967_14 <= 100);
    __CPROVER_assume(pub_r001967_15 >= -100 && pub_r001967_15 <= 100);
    __CPROVER_assume(pub_r001967_16 >= -100 && pub_r001967_16 <= 100);
    __CPROVER_assume(pub_r001967_17 >= -100 && pub_r001967_17 <= 100);
    __CPROVER_assume(pub_r001967_18 >= -100 && pub_r001967_18 <= 100);
    __CPROVER_assume(sec_r001967_0 >= 0 && sec_r001967_0 <= 255);
    __CPROVER_assume(sec_r001967_1 >= 0 && sec_r001967_1 <= 255);
    __CPROVER_assume(sec_r001967_2 >= 0 && sec_r001967_2 <= 255);
    __CPROVER_assume(sec_r001967_3 >= 0 && sec_r001967_3 <= 255);
    __CPROVER_assume(sec_r001967_4 >= 0 && sec_r001967_4 <= 255);
    __CPROVER_assume(sec_r001967_5 >= 0 && sec_r001967_5 <= 255);
    __CPROVER_assume(sec_r001967_6 >= 0 && sec_r001967_6 <= 255);
    __CPROVER_assume(sec_r001967_7 >= 0 && sec_r001967_7 <= 255);
    __CPROVER_assume(sec_r001967_8 >= 0 && sec_r001967_8 <= 255);
    __CPROVER_assume(sec_r001967_9 >= 0 && sec_r001967_9 <= 255);
    __CPROVER_assume(sec_r001967_10 >= 0 && sec_r001967_10 <= 255);
    __CPROVER_assume(sec_r001967_11 >= 0 && sec_r001967_11 <= 255);
    __CPROVER_assume(sec_r001967_12 >= 0 && sec_r001967_12 <= 255);
    __CPROVER_assume(sec_r001967_13 >= 0 && sec_r001967_13 <= 255);
    __CPROVER_assume(sec_r001967_14 >= 0 && sec_r001967_14 <= 255);
    __CPROVER_assume(sec_r001967_15 >= 0 && sec_r001967_15 <= 255);
    __CPROVER_assume(sec_r001967_16 >= 0 && sec_r001967_16 <= 255);
    __CPROVER_assume(sec_r001967_17 >= 0 && sec_r001967_17 <= 255);
    __CPROVER_assume(sec_r001967_18 >= 0 && sec_r001967_18 <= 255);
    __CPROVER_assume(sec_r001967_19 >= 0 && sec_r001967_19 <= 255);

    struct StreamBuffer_R001967_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001967_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001967_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001967_0 + 7) & 15;
    struct Vector3D_R001967_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001967_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001967_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001967_0 + 9) & 15;
    struct MatrixBlock_R001967_6713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001967_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001967_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001967_0 + 11) & 15;

    union ColorPixel_R001967_6713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001967_6713_0(sec_r001967_0, sec_r001967_1, pub_r001967_2, pub_r001967_3, pub_r001967_4);
    int helper_flow_1 = fn_R001967_6713_1(sec_r001967_1, pub_r001967_2, pub_r001967_3, pub_r001967_4);
    int helper_flow_2 = fn_R001967_6713_2(sec_r001967_2, pub_r001967_3, pub_r001967_4);
    int helper_flow_3 = fn_R001967_6713_3(sec_r001967_3, pub_r001967_4, pub_r001967_5);
    int helper_flow_4 = fn_R001967_6713_4(sec_r001967_4, sec_r001967_5, pub_r001967_6, pub_r001967_7, pub_r001967_8);
    int helper_flow_5 = fn_R001967_6713_5(sec_r001967_5, sec_r001967_6, pub_r001967_7, pub_r001967_8);
    int helper_flow_6 = fn_R001967_6713_6(sec_r001967_6, sec_r001967_7, pub_r001967_8, pub_r001967_9, pub_r001967_10);
    int helper_flow_7 = fn_R001967_6713_7(sec_r001967_7, sec_r001967_8, pub_r001967_9, pub_r001967_10, pub_r001967_11);
    int helper_flow_8 = fn_R001967_6713_8(sec_r001967_8, pub_r001967_9);
    int helper_flow_9 = fn_R001967_6713_9(sec_r001967_9, sec_r001967_10, pub_r001967_11);
    int helper_flow_10 = fn_R001967_6713_10(sec_r001967_10, pub_r001967_11, pub_r001967_12, pub_r001967_13, pub_r001967_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001967_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001967_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001967_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001967_4 ^ pub_r001967_16) & 63;
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
    int stage_v_4 = (sec_r001967_18 ^ pub_r001967_0) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001967_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001967_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001967_10 ^ pub_r001967_17) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001967_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001967_4 ^ pub_r001967_17) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_4 ^ pub_r001967_7) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001967_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001967_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_8 ^ pub_r001967_0) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001967_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_10 ^ pub_r001967_14) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001967_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001967_11 ^ pub_r001967_3) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001967_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001967_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001967_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001967_17 ^ pub_r001967_9) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_6 ^ pub_r001967_5) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001967_9 ^ pub_r001967_10) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_10 ^ pub_r001967_1) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001967_0 ^ pub_r001967_14) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001967_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001967_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_8 ^ pub_r001967_11) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001967_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_17 ^ pub_r001967_10) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_0 ^ pub_r001967_5) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_0 ^ pub_r001967_0) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r001967_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_20 ^ pub_r001967_7) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001967_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001967_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001967_0 ^ pub_r001967_17) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001967_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_2 ^ pub_r001967_13) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001967_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001967_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001967_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_25 ^ pub_r001967_15) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_29 ^ pub_r001967_18) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001967_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_6 ^ pub_r001967_10) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001967_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001967_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001967_7 ^ pub_r001967_12) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001967_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001967_14 ^ pub_r001967_7) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r001967_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_6 ^ pub_r001967_15) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_16 ^ pub_r001967_13) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001967_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_31 ^ pub_r001967_14) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_1 ^ pub_r001967_4) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_17 ^ pub_r001967_4) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r001967_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001967_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_31 ^ pub_r001967_5) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_13 ^ pub_r001967_14) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_8 ^ pub_r001967_0) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_5 ^ pub_r001967_16) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001967_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001967_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_39 ^ pub_r001967_17) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001967_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_6 ^ pub_r001967_9) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r001967_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001967_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (helper_flow_1 ^ pub_r001967_18) & 63;
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
    int stage_v_57 = (stage_v_26 ^ pub_r001967_7) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r001967_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (helper_flow_7 ^ pub_r001967_7) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r001967_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001967_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001967_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_40 ^ pub_r001967_16) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001967_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001967_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001967_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001967_4 ^ pub_r001967_1) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_6 ^ pub_r001967_15) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001967_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001967_8 ^ pub_r001967_7) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001967_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001967_0 ^ pub_r001967_12) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (helper_flow_9 ^ pub_r001967_2) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r001967_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_24 ^ pub_r001967_17) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r001967_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (helper_flow_6 ^ pub_r001967_9) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001967_17 ^ pub_r001967_1) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r001967_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_17 ^ pub_r001967_4) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001967_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001967_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001967_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_25 ^ pub_r001967_1) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001967_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_26 ^ pub_r001967_16) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_7 ^ pub_r001967_12) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_17 ^ pub_r001967_14) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001967_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_31 ^ pub_r001967_8) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001967_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_79 ^ pub_r001967_3) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_23 ^ pub_r001967_5) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r001967_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001967_6 ^ pub_r001967_7) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r001967_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001967_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_7 ^ pub_r001967_2) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_41 ^ pub_r001967_5) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_35 ^ pub_r001967_4) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001967_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_74 ^ pub_r001967_0) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r001967_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_22 ^ pub_r001967_17) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_72 ^ pub_r001967_7) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001967_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001967_14 ^ pub_r001967_15) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r001967_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (helper_flow_8 ^ pub_r001967_0) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001967_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_56 ^ pub_r001967_10) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r001967_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_39 ^ pub_r001967_5) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_88 ^ pub_r001967_8) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001967_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001967_14 ^ pub_r001967_7) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_86 ^ pub_r001967_15) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_94 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001967_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001967_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (helper_flow_9 ^ pub_r001967_3) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r001967_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001967_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001967_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_10 ^ pub_r001967_3) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r001967_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001967_12 ^ pub_r001967_16) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (helper_flow_8 ^ pub_r001967_5) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r001967_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_12 ^ pub_r001967_6) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001967_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001967_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001967_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001967_16 ^ pub_r001967_5) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_85 ^ pub_r001967_13) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r001967_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001967_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_4 ^ pub_r001967_17) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001967_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001967_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001967_16 ^ pub_r001967_6) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001967_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001967_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001967_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001967_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001967_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001967_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (helper_flow_7 ^ pub_r001967_14) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_74 ^ pub_r001967_17) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_19 ^ pub_r001967_4) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001967_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001967_19 ^ pub_r001967_2) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_100 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_85 ^ pub_r001967_3) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (helper_flow_0 ^ pub_r001967_12) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001967_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001967_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001967_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_49 ^ pub_r001967_7) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_134 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_12 ^ pub_r001967_17) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (helper_flow_8 ^ pub_r001967_14) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_57 ^ pub_r001967_12) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001967_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_3 ^ pub_r001967_18) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_134 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (helper_flow_3 ^ pub_r001967_4) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_39 ^ pub_r001967_8) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (helper_flow_6 ^ pub_r001967_17) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_29 ^ pub_r001967_9) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_98 ^ pub_r001967_0) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001967_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001967_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_56 ^ pub_r001967_12) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((sec_r001967_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001967_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001967_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001967_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001967_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_10 ^ pub_r001967_5) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_147 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_8 ^ pub_r001967_5) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_75 ^ pub_r001967_7) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_6 ^ pub_r001967_12) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001967_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_124 ^ pub_r001967_14) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (helper_flow_7 ^ pub_r001967_3) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_91 ^ pub_r001967_10) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_141 ^ pub_r001967_15) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_150 ^ pub_r001967_0) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_91 ^ pub_r001967_7) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (sec_r001967_13 ^ pub_r001967_18) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001967_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001967_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_169 ^ pub_r001967_14) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001967_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001967_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_111 ^ pub_r001967_7) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001967_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001967_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001967_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_111 ^ pub_r001967_14) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001967_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_112 ^ pub_r001967_0) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_8 ^ pub_r001967_9) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001967_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_167 ^ pub_r001967_8) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((sec_r001967_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001967_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (helper_flow_3 ^ pub_r001967_10) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_153 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (sec_r001967_12 ^ pub_r001967_14) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_91 ^ pub_r001967_4) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((stage_v_134 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_143 ^ pub_r001967_2) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((sec_r001967_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
