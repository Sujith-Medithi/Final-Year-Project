/*
 * Benchmark Program: R002000
 * Security Family: mixed_control_data
 * Generator Seed: 700013
 * High Inputs: 18 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R002000_13_0 {
    int gain_db;
    short mode;
    int damping;
    int prev_out;
    int buffer[3];
};

struct MatrixBlock_R002000_13_1 {
    unsigned char determinant;
    int scale;
    unsigned char stride;
    int buffer[3];
};

union TelemetryField_R002000_13_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R002000_13_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int residue_28 = 0;
    for (int k = 0; k < 2; k++) {
        residue_28 = (residue_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_28) & 127;
    }
    int anchor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_22) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_32 = local_arr[aux % 3];
    acc = (acc + parity_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quotient_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_65) & 63;
    acc ^= aux;
    int window_72 = (st.buffer[0] * 3 + aux) & 63;
    if (window_72 > 36) {
        acc = (acc + window_72 * 2 + 5) & 127;
        aux ^= (window_72 & 15);
    } else {
        acc = (acc - window_72 + 11) & 127;
        aux += 3;
    }
    int accumulator_82 = (aux + st.buffer[1]) & 3;
    switch (accumulator_82) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_14 = 0;
    for (int k = 0; k < 2; k++) {
        sample_14 = (sample_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_2(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R002000_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int weight_46 = 0;
    for (int k = 0; k < 3; k++) {
        weight_46 = (weight_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_46) & 127;
    }
    int residue_85 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_85 > 26) {
        acc = (acc + residue_85 * 2 + 5) & 127;
        aux ^= (residue_85 & 15);
    } else {
        acc = (acc - residue_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_3(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_50 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_50 > 32) {
        acc = (acc + tracker_50 * 2 + 5) & 127;
        aux ^= (tracker_50 & 15);
    } else {
        acc = (acc - tracker_50 + 11) & 127;
        aux += 3;
    }
    int tally_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_16 = local_arr[aux % 3];
    acc = (acc + quotient_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_4(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_19) & 63;
    acc ^= aux;
    int mask_82 = (aux + st.buffer[1]) & 3;
    switch (mask_82) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_94 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_94 > 34) {
        acc = (acc + mask_94 * 2 + 5) & 127;
        aux ^= (mask_94 & 15);
    } else {
        acc = (acc - mask_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_5(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int scale_78 = 0;
    for (int k = 0; k < 3; k++) {
        scale_78 = (scale_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_78) & 127;
    }
    int vector_43 = (aux + st.buffer[1]) & 3;
    switch (vector_43) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int phase_93 = (aux + st.buffer[1]) & 3;
    switch (phase_93) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_63 = 0;
    for (int k = 0; k < 3; k++) {
        sample_63 = (sample_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_63) & 127;
    }
    int margin_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R002000_13_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R002000_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int mask_82 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_82 > 33) {
        acc = (acc + mask_82 * 2 + 5) & 127;
        aux ^= (mask_82 & 15);
    } else {
        acc = (acc - mask_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_68 = 0;
    for (int k = 0; k < 3; k++) {
        phase_68 = (phase_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_68) & 127;
    }
    int metric_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R002000_13_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int phase_24 = local_arr[aux % 3];
    acc = (acc + phase_24 * 2) & 127;
    int threshold_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_56) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_9(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R002000_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int parity_89 = 0;
    for (int k = 0; k < 2; k++) {
        parity_89 = (parity_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_89) & 127;
    }
    int segment_32 = (aux + st.buffer[1]) & 3;
    switch (segment_32) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_11 = local_arr[aux % 3];
    acc = (acc + index_reg_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int phase_23 = (aux + st.buffer[1]) & 3;
    switch (phase_23) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int phase_19 = (aux + st.buffer[1]) & 3;
    switch (phase_19) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_67 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_67 > 14) {
        acc = (acc + bound_67 * 2 + 5) & 127;
        aux ^= (bound_67 & 15);
    } else {
        acc = (acc - bound_67 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_69 = local_arr[aux % 3];
    acc = (acc + threshold_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R002000_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int coefficient_68 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_68 = (coefficient_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_68) & 127;
    }
    int bound_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_11) & 63;
    acc ^= aux;
    int index_reg_85 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_85 > 32) {
        acc = (acc + index_reg_85 * 2 + 5) & 127;
        aux ^= (index_reg_85 & 15);
    } else {
        acc = (acc - index_reg_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_59) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_44 = local_arr[aux % 3];
    acc = (acc + accumulator_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_14(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R002000_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int tracker_23 = local_arr[aux % 3];
    acc = (acc + tracker_23 * 2) & 127;
    int coefficient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_44) & 63;
    acc ^= aux;
    int tally_15 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_15 > 11) {
        acc = (acc + tally_15 * 2 + 5) & 127;
        aux ^= (tally_15 & 15);
    } else {
        acc = (acc - tally_15 + 11) & 127;
        aux += 3;
    }
    int phase_94 = (aux + st.buffer[1]) & 3;
    switch (phase_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R002000_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int weight_23 = local_arr[aux % 3];
    acc = (acc + weight_23 * 2) & 127;
    int window_30 = (st.buffer[0] * 3 + aux) & 63;
    if (window_30 > 48) {
        acc = (acc + window_30 * 2 + 5) & 127;
        aux ^= (window_30 & 15);
    } else {
        acc = (acc - window_30 + 11) & 127;
        aux += 3;
    }
    int offset_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R002000_13_16(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int checksum_37 = local_arr[aux % 3];
    acc = (acc + checksum_37 * 2) & 127;
    int checksum_30 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_30 = (checksum_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_30) & 127;
    }
    int scale_76 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_76 > 14) {
        acc = (acc + scale_76 * 2 + 5) & 127;
        aux ^= (scale_76 & 15);
    } else {
        acc = (acc - scale_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_18 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_18 > 11) {
        acc = (acc + anchor_18 * 2 + 5) & 127;
        aux ^= (anchor_18 & 15);
    } else {
        acc = (acc - anchor_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_22 = local_arr[aux % 3];
    acc = (acc + tally_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R002000_13_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quotient_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_21) & 63;
    acc ^= aux;
    int checksum_52 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_52 = (checksum_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R002000_13_19(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R002000_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int residue_20 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_20 > 16) {
        acc = (acc + residue_20 * 2 + 5) & 127;
        aux ^= (residue_20 & 15);
    } else {
        acc = (acc - residue_20 + 11) & 127;
        aux += 3;
    }
    int residue_44 = (aux + st.buffer[1]) & 3;
    switch (residue_44) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r002000_0;
    int sec_r002000_1;
    int sec_r002000_2;
    int sec_r002000_3;
    int sec_r002000_4;
    int sec_r002000_5;
    int sec_r002000_6;
    int sec_r002000_7;
    int sec_r002000_8;
    int sec_r002000_9;
    int sec_r002000_10;
    int sec_r002000_11;
    int sec_r002000_12;
    int sec_r002000_13;
    int sec_r002000_14;
    int sec_r002000_15;
    int sec_r002000_16;
    int sec_r002000_17;
    int pub_r002000_0;
    int pub_r002000_1;
    int pub_r002000_2;
    int pub_r002000_3;
    int pub_r002000_4;
    int pub_r002000_5;
    int pub_r002000_6;
    int pub_r002000_7;
    int pub_r002000_8;
    int pub_r002000_9;
    int pub_r002000_10;
    int pub_r002000_11;
    int pub_r002000_12;
    int pub_r002000_13;
    int pub_r002000_14;
    int pub_r002000_15;
    int pub_r002000_16;
    int pub_r002000_17;
    int pub_r002000_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r002000_0 >= -100 && pub_r002000_0 <= 100);
    __CPROVER_assume(pub_r002000_1 >= -100 && pub_r002000_1 <= 100);
    __CPROVER_assume(pub_r002000_2 >= -100 && pub_r002000_2 <= 100);
    __CPROVER_assume(pub_r002000_3 >= -100 && pub_r002000_3 <= 100);
    __CPROVER_assume(pub_r002000_4 >= -100 && pub_r002000_4 <= 100);
    __CPROVER_assume(pub_r002000_5 >= -100 && pub_r002000_5 <= 100);
    __CPROVER_assume(pub_r002000_6 >= -100 && pub_r002000_6 <= 100);
    __CPROVER_assume(pub_r002000_7 >= -100 && pub_r002000_7 <= 100);
    __CPROVER_assume(pub_r002000_8 >= -100 && pub_r002000_8 <= 100);
    __CPROVER_assume(pub_r002000_9 >= -100 && pub_r002000_9 <= 100);
    __CPROVER_assume(pub_r002000_10 >= -100 && pub_r002000_10 <= 100);
    __CPROVER_assume(pub_r002000_11 >= -100 && pub_r002000_11 <= 100);
    __CPROVER_assume(pub_r002000_12 >= -100 && pub_r002000_12 <= 100);
    __CPROVER_assume(pub_r002000_13 >= -100 && pub_r002000_13 <= 100);
    __CPROVER_assume(pub_r002000_14 >= -100 && pub_r002000_14 <= 100);
    __CPROVER_assume(pub_r002000_15 >= -100 && pub_r002000_15 <= 100);
    __CPROVER_assume(pub_r002000_16 >= -100 && pub_r002000_16 <= 100);
    __CPROVER_assume(pub_r002000_17 >= -100 && pub_r002000_17 <= 100);
    __CPROVER_assume(pub_r002000_18 >= -100 && pub_r002000_18 <= 100);
    __CPROVER_assume(sec_r002000_0 >= 0 && sec_r002000_0 <= 255);
    __CPROVER_assume(sec_r002000_1 >= 0 && sec_r002000_1 <= 255);
    __CPROVER_assume(sec_r002000_2 >= 0 && sec_r002000_2 <= 255);
    __CPROVER_assume(sec_r002000_3 >= 0 && sec_r002000_3 <= 255);
    __CPROVER_assume(sec_r002000_4 >= 0 && sec_r002000_4 <= 255);
    __CPROVER_assume(sec_r002000_5 >= 0 && sec_r002000_5 <= 255);
    __CPROVER_assume(sec_r002000_6 >= 0 && sec_r002000_6 <= 255);
    __CPROVER_assume(sec_r002000_7 >= 0 && sec_r002000_7 <= 255);
    __CPROVER_assume(sec_r002000_8 >= 0 && sec_r002000_8 <= 255);
    __CPROVER_assume(sec_r002000_9 >= 0 && sec_r002000_9 <= 255);
    __CPROVER_assume(sec_r002000_10 >= 0 && sec_r002000_10 <= 255);
    __CPROVER_assume(sec_r002000_11 >= 0 && sec_r002000_11 <= 255);
    __CPROVER_assume(sec_r002000_12 >= 0 && sec_r002000_12 <= 255);
    __CPROVER_assume(sec_r002000_13 >= 0 && sec_r002000_13 <= 255);
    __CPROVER_assume(sec_r002000_14 >= 0 && sec_r002000_14 <= 255);
    __CPROVER_assume(sec_r002000_15 >= 0 && sec_r002000_15 <= 255);
    __CPROVER_assume(sec_r002000_16 >= 0 && sec_r002000_16 <= 255);
    __CPROVER_assume(sec_r002000_17 >= 0 && sec_r002000_17 <= 255);

    struct FilterState_R002000_13_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r002000_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r002000_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r002000_0 + 7) & 15;
    struct MatrixBlock_R002000_13_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r002000_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r002000_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r002000_0 + 9) & 15;

    union TelemetryField_R002000_13_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R002000_13_0(sec_r002000_0, sec_r002000_1, pub_r002000_2, pub_r002000_3, pub_r002000_4);
    int helper_flow_1 = fn_R002000_13_1(sec_r002000_1, pub_r002000_2, pub_r002000_3, pub_r002000_4);
    int helper_flow_2 = fn_R002000_13_2(sec_r002000_2, sec_r002000_3, pub_r002000_4);
    int helper_flow_3 = fn_R002000_13_3(sec_r002000_3, pub_r002000_4);
    int helper_flow_4 = fn_R002000_13_4(sec_r002000_4, sec_r002000_5);
    int helper_flow_5 = fn_R002000_13_5(sec_r002000_5, sec_r002000_6);
    int helper_flow_6 = fn_R002000_13_6(sec_r002000_6, sec_r002000_7, pub_r002000_8, pub_r002000_9, pub_r002000_10);
    int helper_flow_7 = fn_R002000_13_7(sec_r002000_7, pub_r002000_8, pub_r002000_9, pub_r002000_10);
    int helper_flow_8 = fn_R002000_13_8(sec_r002000_8, pub_r002000_9, pub_r002000_10, pub_r002000_11, pub_r002000_12);
    int helper_flow_9 = fn_R002000_13_9(sec_r002000_9, sec_r002000_10);
    int helper_flow_10 = fn_R002000_13_10(sec_r002000_10, pub_r002000_11, pub_r002000_12, pub_r002000_13, pub_r002000_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r002000_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r002000_12 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_1 > 45) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r002000_0 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_2 > 29) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r002000_8) & 127;
    if (stage_v_3 > 46) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r002000_0 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_4 > 24) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r002000_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r002000_15 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_6 > 24) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r002000_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r002000_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r002000_8 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_9 > 21) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_10 > 29) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r002000_16) & 127;
    if (stage_v_11 > 21) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r002000_3 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_12 > 49) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_1 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_13 > 24) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r002000_4 ^ 0x2A) * 2 + pub_r002000_3) & 127;
    if (stage_v_14 > 30) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r002000_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_16 > 24) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_17 > 25) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r002000_17 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_18 > 50) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_19 > 34) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_3 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_20 > 41) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r002000_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_22 > 46) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_17 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_23 > 47) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r002000_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r002000_3 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_25 > 28) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r002000_6 ^ 0x2A) * 2 + pub_r002000_14) & 127;
    if (stage_v_26 > 42) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r002000_11 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_27 > 30) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r002000_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_29 > 46) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r002000_2 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_30 > 36) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r002000_17 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_31 > 41) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_32 > 40) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r002000_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r002000_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_26 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_35 > 21) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_31 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_36 > 20) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_29 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_37 > 22) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r002000_3) & 127;
    if (stage_v_38 > 21) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_26 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_39 > 36) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_40 > 43) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r002000_16 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_41 > 47) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r002000_8) & 127;
    if (stage_v_42 > 44) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r002000_4 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_43 > 40) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_44 > 38) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r002000_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_18 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_46 > 31) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_47 > 23) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_29 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_48 > 45) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_49 > 34) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r002000_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r002000_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_38 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_52 > 28) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r002000_15 ^ 0x2A) * 2 + pub_r002000_16) & 127;
    if (stage_v_53 > 48) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r002000_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r002000_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r002000_4 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_56 > 33) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_40 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_57 > 43) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_3 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_58 > 24) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r002000_17 ^ 0x2A) * 2 + pub_r002000_8) & 127;
    if (stage_v_59 > 33) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_41 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_60 > 32) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r002000_1 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r002000_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_20 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_63 > 33) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_17 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_64 > 47) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_35 ^ 0x2A) * 2 + pub_r002000_2) & 127;
    if (stage_v_65 > 32) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_66 > 32) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_46 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_67 > 29) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r002000_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_44 ^ 0x2A) * 2 + pub_r002000_16) & 127;
    if (stage_v_69 > 20) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_70 > 46) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r002000_8 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_71 > 25) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_1 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_72 > 40) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r002000_8 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_73 > 28) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r002000_8 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_74 > 27) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_69 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_75 > 38) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_52 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_76 > 24) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_56 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_77 > 43) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_78 > 28) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r002000_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_36 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_80 > 29) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_30 ^ 0x2A) * 2 + pub_r002000_8) & 127;
    if (stage_v_81 > 20) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r002000_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_76 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_83 > 45) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_53 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_84 > 49) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_57 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_85 > 27) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_1 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_86 > 44) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_35 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_87 > 36) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_81 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_88 > 22) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r002000_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_90 > 46) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_43 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_91 > 21) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r002000_15 ^ 0x2A) * 2 + pub_r002000_3) & 127;
    if (stage_v_92 > 45) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_74 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_93 > 46) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r002000_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_77 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_95 > 37) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_47 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_96 > 50) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_97 > 43) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_66 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_98 > 34) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r002000_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_100 > 25) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r002000_10 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_101 > 28) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_87 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_102 > 39) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r002000_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_93 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_104 > 39) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r002000_10 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_105 > 41) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r002000_12 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_106 > 40) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_107 > 48) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r002000_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_66 ^ 0x2A) * 2 + pub_r002000_9) & 127;
    if (stage_v_109 > 46) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r002000_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_26 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_111 > 47) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_44 ^ 0x2A) * 2 + pub_r002000_9) & 127;
    if (stage_v_112 > 21) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r002000_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_60 ^ 0x2A) * 2 + pub_r002000_2) & 127;
    if (stage_v_114 > 22) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r002000_15 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_115 > 46) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_96 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_116 > 40) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_85 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_117 > 40) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_49 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_118 > 35) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_109 ^ 0x2A) * 2 + pub_r002000_2) & 127;
    if (stage_v_119 > 24) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_87 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_120 > 48) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_101 ^ 0x2A) * 2 + pub_r002000_8) & 127;
    if (stage_v_121 > 27) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_84 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_122 > 38) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_85 ^ 0x2A) * 2 + pub_r002000_3) & 127;
    if (stage_v_123 > 45) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r002000_7 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_124 > 26) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_11 ^ 0x2A) * 2 + pub_r002000_14) & 127;
    if (stage_v_125 > 41) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_111 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_126 > 42) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_97 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_127 > 22) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r002000_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_53 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_129 > 35) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_65 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_130 > 46) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_66 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_131 > 31) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_30 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_132 > 22) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_72 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_133 > 44) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_105 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_134 > 47) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_77 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_135 > 50) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_81 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_136 > 41) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_48 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_137 > 36) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_138 > 44) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_119 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_139 > 40) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_135 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_140 > 48) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_139 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_141 > 23) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_80 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_142 > 21) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_85 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_143 > 37) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r002000_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_139 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_145 > 43) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_91 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_146 > 45) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r002000_7 ^ 0x2A) * 2 + pub_r002000_9) & 127;
    if (stage_v_147 > 42) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_141 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_148 > 46) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_73 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_149 > 45) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r002000_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_151 > 44) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_6 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_152 > 39) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_56 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_153 > 22) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_154 > 36) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r002000_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r002000_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_115 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_157 > 25) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_29 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_158 > 31) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_38 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_159 > 21) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_135 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_160 > 36) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_142 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_161 > 24) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r002000_1 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_162 > 47) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_119 ^ 0x2A) * 2 + pub_r002000_9) & 127;
    if (stage_v_163 > 47) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_131 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_164 > 43) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_126 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_165 > 41) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_105 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_166 > 30) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r002000_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_20 ^ 0x2A) * 2 + pub_r002000_14) & 127;
    if (stage_v_168 > 33) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_151 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_169 > 42) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_96 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_170 > 29) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_32 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_171 > 30) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_36 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_172 > 35) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r002000_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_30 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_174 > 22) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_174 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_175 > 50) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_107 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_176 > 23) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r002000_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_56 ^ 0x2A) * 2 + pub_r002000_13) & 127;
    if (stage_v_178 > 26) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r002000_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_9 ^ 0x2A) * 2 + pub_r002000_2) & 127;
    if (stage_v_180 > 36) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r002000_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r002000_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r002000_14) & 127;
    if (stage_v_183 > 37) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_1 ^ 0x2A) * 2 + pub_r002000_3) & 127;
    if (stage_v_184 > 43) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r002000_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_75 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_186 > 42) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r002000_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_76 ^ 0x2A) * 2 + pub_r002000_2) & 127;
    if (stage_v_188 > 49) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r002000_0 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_189 > 49) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r002000_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_169 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_191 > 43) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r002000_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r002000_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r002000_8 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_194 > 44) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r002000_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_137 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_196 > 27) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_63 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_197 > 33) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r002000_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_36 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_199 > 44) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r002000_11 ^ 0x2A) * 2 + pub_r002000_18) & 127;
    if (stage_v_200 > 42) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_201 > 38) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_170 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_202 > 47) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r002000_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_149 ^ 0x2A) * 2 + pub_r002000_9) & 127;
    if (stage_v_204 > 25) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_52 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_205 > 25) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_137 ^ 0x2A) * 2 + pub_r002000_14) & 127;
    if (stage_v_206 > 20) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_36 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_207 > 29) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_134 ^ 0x2A) * 2 + pub_r002000_14) & 127;
    if (stage_v_208 > 49) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_66 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_209 > 36) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_93 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_210 > 30) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r002000_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_142 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_212 > 22) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_71 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_213 > 43) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r002000_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r002000_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_44 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_216 > 44) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r002000_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r002000_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_11 ^ 0x2A) * 2 + pub_r002000_8) & 127;
    if (stage_v_219 > 30) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_176 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_220 > 22) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r002000_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_141 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_222 > 23) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_157 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_223 > 20) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_27 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_224 > 20) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_152 ^ 0x2A) * 2 + pub_r002000_3) & 127;
    if (stage_v_225 > 25) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r002000_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_73 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_227 > 22) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r002000_0 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_228 > 43) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_220 ^ 0x2A) * 2 + pub_r002000_16) & 127;
    if (stage_v_229 > 43) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r002000_10 ^ 0x2A) * 2 + pub_r002000_5) & 127;
    if (stage_v_230 > 30) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_112 ^ 0x2A) * 2 + pub_r002000_17) & 127;
    if (stage_v_231 > 42) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_35 ^ 0x2A) * 2 + pub_r002000_10) & 127;
    if (stage_v_232 > 37) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_186 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_233 > 29) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_136 ^ 0x2A) * 2 + pub_r002000_9) & 127;
    if (stage_v_234 > 33) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r002000_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_191 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_236 > 33) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((sec_r002000_11 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_237 > 36) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_23 ^ 0x2A) * 2 + pub_r002000_0) & 127;
    if (stage_v_238 > 45) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_114 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_239 > 39) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_164 ^ 0x2A) * 2 + pub_r002000_2) & 127;
    if (stage_v_240 > 50) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_3 ^ 0x2A) * 2 + pub_r002000_11) & 127;
    if (stage_v_241 > 44) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_3 ^ 0x2A) * 2 + pub_r002000_9) & 127;
    if (stage_v_242 > 49) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_41 ^ 0x2A) * 2 + pub_r002000_12) & 127;
    if (stage_v_243 > 49) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r002000_4) & 127;
    if (stage_v_244 > 27) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_60 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_245 > 30) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r002000_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r002000_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_157 ^ 0x2A) * 2 + pub_r002000_6) & 127;
    if (stage_v_248 > 32) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_145 ^ 0x2A) * 2 + pub_r002000_15) & 127;
    if (stage_v_249 > 22) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_36 ^ 0x2A) * 2 + pub_r002000_14) & 127;
    if (stage_v_250 > 42) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r002000_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((sec_r002000_11 ^ 0x2A) * 2 + pub_r002000_3) & 127;
    if (stage_v_252 > 35) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_18 ^ 0x2A) * 2 + pub_r002000_7) & 127;
    if (stage_v_253 > 42) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r002000_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r002000_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r002000_4 ^ 0x2A) * 2 + pub_r002000_16) & 127;
    if (stage_v_256 > 41) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r002000_7 ^ 0x2A) * 2 + pub_r002000_1) & 127;
    if (stage_v_257 > 40) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
