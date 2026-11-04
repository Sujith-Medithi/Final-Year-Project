/*
 * Benchmark Program: R000515
 * Family: implicit_flow
 * Generator Seed: 451513
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000515_1513_0 {
    unsigned char auth_code;
    int account_id;
    short rate;
    int balance;
    int buffer[3];
};

struct MatrixBlock_R000515_1513_1 {
    int scale;
    unsigned char dim;
    int trace;
    int buffer[3];
};

struct Vector3D_R000515_1513_2 {
    int pitch;
    unsigned char coord_x;
    int norm_sq;
    int heading;
    int coord_y;
    int coord_z;
    int buffer[3];
};

union RegisterBank_R000515_1513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000515_1513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000515_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int parity_14 = local_arr[aux % 3];
    acc = (acc + parity_14 * 2) & 127;
    int stride_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_97) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_35 = (aux + st.buffer[1]) & 3;
    switch (bound_35) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000515_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tracker_44 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_44 > 28) {
        acc = (acc + tracker_44 * 2 + 5) & 127;
        aux ^= (tracker_44 & 15);
    } else {
        acc = (acc - tracker_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_41 = local_arr[aux % 3];
    acc = (acc + quantum_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000515_1513_2(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int offset_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_79) & 63;
    acc ^= aux;
    int index_reg_50 = (aux + st.buffer[1]) & 3;
    switch (index_reg_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000515_1513_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int weight_70 = 0;
    for (int k = 0; k < 2; k++) {
        weight_70 = (weight_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_70) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_41) & 63;
    acc ^= aux;
    int window_45 = (st.buffer[0] * 3 + aux) & 63;
    if (window_45 > 39) {
        acc = (acc + window_45 * 2 + 5) & 127;
        aux ^= (window_45 & 15);
    } else {
        acc = (acc - window_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_4(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int sample_20 = 0;
    for (int k = 0; k < 2; k++) {
        sample_20 = (sample_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_20) & 127;
    }
    int coefficient_16 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_16 > 15) {
        acc = (acc + coefficient_16 * 2 + 5) & 127;
        aux ^= (coefficient_16 & 15);
    } else {
        acc = (acc - coefficient_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_95 = local_arr[aux % 3];
    acc = (acc + delta_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000515_1513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int scale_93 = 0;
    for (int k = 0; k < 2; k++) {
        scale_93 = (scale_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_93) & 127;
    }
    int quantum_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_87) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_97 = local_arr[aux % 3];
    acc = (acc + margin_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000515_1513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000515_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int vector_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_44) & 63;
    acc ^= aux;
    int cursor_70 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_70 > 47) {
        acc = (acc + cursor_70 * 2 + 5) & 127;
        aux ^= (cursor_70 & 15);
    } else {
        acc = (acc - cursor_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int scale_55 = local_arr[aux % 3];
    acc = (acc + scale_55 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_45 = (aux + st.buffer[1]) & 3;
    switch (segment_45) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_24 = 0;
    for (int k = 0; k < 3; k++) {
        tally_24 = (tally_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_24) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_8(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int anchor_84 = local_arr[aux % 3];
    acc = (acc + anchor_84 * 2) & 127;
    int scale_91 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_91 > 13) {
        acc = (acc + scale_91 * 2 + 5) & 127;
        aux ^= (scale_91 & 15);
    } else {
        acc = (acc - scale_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int accumulator_93 = local_arr[aux % 3];
    acc = (acc + accumulator_93 * 2) & 127;
    int tally_88 = 0;
    for (int k = 0; k < 2; k++) {
        tally_88 = (tally_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_88) & 127;
    }
    int scale_30 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_30 > 50) {
        acc = (acc + scale_30 * 2 + 5) & 127;
        aux ^= (scale_30 & 15);
    } else {
        acc = (acc - scale_30 + 11) & 127;
        aux += 3;
    }
    int offset_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000515_1513_10(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int checksum_85 = (aux + st.buffer[1]) & 3;
    switch (checksum_85) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_42 = local_arr[aux % 3];
    acc = (acc + segment_42 * 2) & 127;
    int quantum_26 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_26 = (quantum_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_26) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_11(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000515_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_43) & 63;
    acc ^= aux;
    int pivot_54 = (aux + st.buffer[1]) & 3;
    switch (pivot_54) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_31 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_31 > 39) {
        acc = (acc + scale_31 * 2 + 5) & 127;
        aux ^= (scale_31 & 15);
    } else {
        acc = (acc - scale_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_14 = local_arr[aux % 3];
    acc = (acc + bound_14 * 2) & 127;
    int checksum_53 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_53 = (checksum_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_53) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_13(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_54 = (aux + st.buffer[1]) & 3;
    switch (margin_54) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000515_1513_14(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_38 = (aux + st.buffer[1]) & 3;
    switch (coefficient_38) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_44 = 0;
    for (int k = 0; k < 3; k++) {
        sample_44 = (sample_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_44) & 127;
    }
    int delta_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000515_1513_15(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_97 = 0;
    for (int k = 0; k < 3; k++) {
        residue_97 = (residue_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_97) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000515_1513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int pivot_13 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_13 > 25) {
        acc = (acc + pivot_13 * 2 + 5) & 127;
        aux ^= (pivot_13 & 15);
    } else {
        acc = (acc - pivot_13 + 11) & 127;
        aux += 3;
    }
    int accumulator_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_86) & 63;
    acc ^= aux;
    int scale_69 = (aux + st.buffer[1]) & 3;
    switch (scale_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_97 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_97 > 40) {
        acc = (acc + parity_97 * 2 + 5) & 127;
        aux ^= (parity_97 & 15);
    } else {
        acc = (acc - parity_97 + 11) & 127;
        aux += 3;
    }
    int tally_95 = (aux + st.buffer[1]) & 3;
    switch (tally_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000515_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_61 = local_arr[aux % 3];
    acc = (acc + anchor_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000515_1513_19(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000515_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tracker_91 = (aux + st.buffer[1]) & 3;
    switch (tracker_91) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_23) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000515_1513_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int residue_81 = local_arr[aux % 3];
    acc = (acc + residue_81 * 2) & 127;
    int phase_35 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_35 > 14) {
        acc = (acc + phase_35 * 2 + 5) & 127;
        aux ^= (phase_35 & 15);
    } else {
        acc = (acc - phase_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000515_1513_21(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int anchor_46 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_46 = (anchor_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_46) & 127;
    }
    int coefficient_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000515_1513_22(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000515_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_22 = (aux + st.buffer[1]) & 3;
    switch (margin_22) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_93 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_93 = (index_reg_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_93) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000515_0;
    int sec_r000515_1;
    int sec_r000515_2;
    int sec_r000515_3;
    int sec_r000515_4;
    int sec_r000515_5;
    int sec_r000515_6;
    int sec_r000515_7;
    int sec_r000515_8;
    int sec_r000515_9;
    int sec_r000515_10;
    int sec_r000515_11;
    int sec_r000515_12;
    int sec_r000515_13;
    int sec_r000515_14;
    int sec_r000515_15;
    int pub_r000515_0;
    int pub_r000515_1;
    int pub_r000515_2;
    int pub_r000515_3;
    int pub_r000515_4;
    int pub_r000515_5;
    int pub_r000515_6;
    int pub_r000515_7;
    int pub_r000515_8;
    int pub_r000515_9;
    int pub_r000515_10;
    int pub_r000515_11;
    int pub_r000515_12;
    int pub_r000515_13;
    int pub_r000515_14;
    int pub_r000515_15;
    int pub_r000515_16;
    int pub_r000515_17;
    int pub_r000515_18;
    int pub_r000515_19;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000515_0 >= -100 && pub_r000515_0 <= 100);
    __CPROVER_assume(pub_r000515_1 >= -100 && pub_r000515_1 <= 100);
    __CPROVER_assume(pub_r000515_2 >= -100 && pub_r000515_2 <= 100);
    __CPROVER_assume(pub_r000515_3 >= -100 && pub_r000515_3 <= 100);
    __CPROVER_assume(pub_r000515_4 >= -100 && pub_r000515_4 <= 100);
    __CPROVER_assume(pub_r000515_5 >= -100 && pub_r000515_5 <= 100);
    __CPROVER_assume(pub_r000515_6 >= -100 && pub_r000515_6 <= 100);
    __CPROVER_assume(pub_r000515_7 >= -100 && pub_r000515_7 <= 100);
    __CPROVER_assume(pub_r000515_8 >= -100 && pub_r000515_8 <= 100);
    __CPROVER_assume(pub_r000515_9 >= -100 && pub_r000515_9 <= 100);
    __CPROVER_assume(pub_r000515_10 >= -100 && pub_r000515_10 <= 100);
    __CPROVER_assume(pub_r000515_11 >= -100 && pub_r000515_11 <= 100);
    __CPROVER_assume(pub_r000515_12 >= -100 && pub_r000515_12 <= 100);
    __CPROVER_assume(pub_r000515_13 >= -100 && pub_r000515_13 <= 100);
    __CPROVER_assume(pub_r000515_14 >= -100 && pub_r000515_14 <= 100);
    __CPROVER_assume(pub_r000515_15 >= -100 && pub_r000515_15 <= 100);
    __CPROVER_assume(pub_r000515_16 >= -100 && pub_r000515_16 <= 100);
    __CPROVER_assume(pub_r000515_17 >= -100 && pub_r000515_17 <= 100);
    __CPROVER_assume(pub_r000515_18 >= -100 && pub_r000515_18 <= 100);
    __CPROVER_assume(pub_r000515_19 >= -100 && pub_r000515_19 <= 100);
    __CPROVER_assume(sec_r000515_0 >= 0 && sec_r000515_0 <= 255);
    __CPROVER_assume(sec_r000515_1 >= 0 && sec_r000515_1 <= 255);
    __CPROVER_assume(sec_r000515_2 >= 0 && sec_r000515_2 <= 255);
    __CPROVER_assume(sec_r000515_3 >= 0 && sec_r000515_3 <= 255);
    __CPROVER_assume(sec_r000515_4 >= 0 && sec_r000515_4 <= 255);
    __CPROVER_assume(sec_r000515_5 >= 0 && sec_r000515_5 <= 255);
    __CPROVER_assume(sec_r000515_6 >= 0 && sec_r000515_6 <= 255);
    __CPROVER_assume(sec_r000515_7 >= 0 && sec_r000515_7 <= 255);
    __CPROVER_assume(sec_r000515_8 >= 0 && sec_r000515_8 <= 255);
    __CPROVER_assume(sec_r000515_9 >= 0 && sec_r000515_9 <= 255);
    __CPROVER_assume(sec_r000515_10 >= 0 && sec_r000515_10 <= 255);
    __CPROVER_assume(sec_r000515_11 >= 0 && sec_r000515_11 <= 255);
    __CPROVER_assume(sec_r000515_12 >= 0 && sec_r000515_12 <= 255);
    __CPROVER_assume(sec_r000515_13 >= 0 && sec_r000515_13 <= 255);
    __CPROVER_assume(sec_r000515_14 >= 0 && sec_r000515_14 <= 255);
    __CPROVER_assume(sec_r000515_15 >= 0 && sec_r000515_15 <= 255);

    struct Transaction_R000515_1513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000515_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000515_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000515_0 + 7) & 15;
    struct MatrixBlock_R000515_1513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000515_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000515_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000515_0 + 9) & 15;
    struct Vector3D_R000515_1513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000515_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000515_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000515_0 + 11) & 15;

    union RegisterBank_R000515_1513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 24) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 39) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 26) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 41) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
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
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 39) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 54) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 18) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 33) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 19) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 34) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 31) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 46) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 12) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 27) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 10) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 25) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 34) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 49) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 20) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 35) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 28) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 43) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 12) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 27) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 20) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 35) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 27) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 42) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 10) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 25) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 89) & 15;
    int stage_v_88 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= stage_v_88;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 13) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 28) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_2.buffer[0] ^ 95) & 3;
    switch (stage_v_92) {
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

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_1.buffer[0] ^ 97) & 3;
    switch (stage_v_94) {
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

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (out_sink > 100) ? (chk_sum & 31) : (100 & 31);
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= (stage_v_95 << 1) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 34) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 49) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 99) & 15;
    int stage_v_98 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= stage_v_98;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[0] ^ 103) & 3;
    switch (stage_v_100) {
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

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_2.buffer[0] ^ 107) & 3;
    switch (stage_v_104) {
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

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = table[1];
    table[1] = (table[2] + 211) & 63;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_1.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 12) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 27) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (out_sink > 100) ? (chk_sum & 31) : (114 & 31);
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= (stage_v_109 << 1) & 127;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_2.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
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

    /* Execution Pipeline Stage 114 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 118) & 15;
    int stage_v_117 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= stage_v_117;

    /* Execution Pipeline Stage 118 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_2.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 30) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 45) {
            chk_sum ^= (stage_v_119 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_119 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] ^ 123) & 3;
    switch (stage_v_120) {
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

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = table[1];
    table[1] = (table[2] + 243) & 63;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] ^ 126) & 3;
    switch (stage_v_123) {
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

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_1.buffer[0] ^ 127) & 3;
    switch (stage_v_124) {
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

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_2.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] ^ 129) & 3;
    switch (stage_v_126) {
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

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (out_sink > 100) ? (chk_sum & 31) : (132 & 31);
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= (stage_v_127 << 1) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 130) & 15;
    int stage_v_129 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= stage_v_129;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = table[3];
    table[3] = (table[0] + 263) & 63;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_0.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 38) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 53) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_136 = (stage_v_136 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 15) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 30) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1];
    table[1] = (table[2] + 283) & 63;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
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

    /* Execution Pipeline Stage 143 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_2.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
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

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3];
    table[3] = (table[0] + 303) & 63;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 154) & 15;
    int stage_v_153 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= stage_v_153;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_157 = (st_var_1.buffer[0] ^ 160) & 3;
    switch (stage_v_157) {
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

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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
    int stage_v_164 = (st_var_2.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (out_sink > 100) ? (chk_sum & 31) : (170 & 31);
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= (stage_v_165 << 1) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2];
    table[2] = (table[3] + 333) & 63;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (out_sink > 100) ? (chk_sum & 31) : (173 & 31);
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= (stage_v_168 << 1) & 127;

    /* Security Information Flow: Family = implicit_flow */
    if ((sec_r000515_6 & 63) > 17) {
        out_sink += 34;
    } else {
        out_sink -= 44;
    }
    if ((sec_r000515_0 & 63) > 19) {
        out_sink += 36;
    } else {
        out_sink -= 54;
    }
    if ((sec_r000515_11 & 63) > 36) {
        out_sink += 68;
    } else {
        out_sink -= 69;
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
