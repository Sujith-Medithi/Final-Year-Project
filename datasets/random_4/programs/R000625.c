/*
 * Benchmark Program: R000625
 * Family: nested_implicit_flow
 * Generator Seed: 462513
 * High Inputs: 20 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000625_2513_0 {
    int gain_db;
    unsigned char mode;
    unsigned char prev_in;
    int damping;
    int buffer[3];
};

struct SensorNode_R000625_2513_1 {
    int status;
    short offset;
    int gain;
    unsigned char calib;
    int buffer[3];
};

union RegisterBank_R000625_2513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000625_2513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int index_reg_16 = local_arr[aux % 3];
    acc = (acc + index_reg_16 * 2) & 127;
    int tally_82 = (aux + st.buffer[1]) & 3;
    switch (tally_82) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_31 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_31 > 30) {
        acc = (acc + vector_31 * 2 + 5) & 127;
        aux ^= (vector_31 & 15);
    } else {
        acc = (acc - vector_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000625_2513_1(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int checksum_67 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_67 > 22) {
        acc = (acc + checksum_67 * 2 + 5) & 127;
        aux ^= (checksum_67 & 15);
    } else {
        acc = (acc - checksum_67 + 11) & 127;
        aux += 3;
    }
    int stride_46 = 0;
    for (int k = 0; k < 2; k++) {
        stride_46 = (stride_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_46) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_45 = local_arr[aux % 3];
    acc = (acc + scale_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000625_2513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_31 = (aux + st.buffer[1]) & 3;
    switch (window_31) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_24) & 63;
    acc ^= aux;
    int parity_40 = 0;
    for (int k = 0; k < 2; k++) {
        parity_40 = (parity_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_3(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int segment_91 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_91 > 35) {
        acc = (acc + segment_91 * 2 + 5) & 127;
        aux ^= (segment_91 & 15);
    } else {
        acc = (acc - segment_91 + 11) & 127;
        aux += 3;
    }
    int margin_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_37) & 63;
    acc ^= aux;
    int phase_23 = (aux + st.buffer[1]) & 3;
    switch (phase_23) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_12 = 0;
    for (int k = 0; k < 2; k++) {
        weight_12 = (weight_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_4(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_32 = (aux + st.buffer[1]) & 3;
    switch (damping_32) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_10 = 0;
    for (int k = 0; k < 3; k++) {
        residue_10 = (residue_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_10) & 127;
    }
    int checksum_69 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_69 > 34) {
        acc = (acc + checksum_69 * 2 + 5) & 127;
        aux ^= (checksum_69 & 15);
    } else {
        acc = (acc - checksum_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tracker_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_93) & 63;
    acc ^= aux;
    int delta_11 = 0;
    for (int k = 0; k < 3; k++) {
        delta_11 = (delta_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_11) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int anchor_59 = local_arr[aux % 3];
    acc = (acc + anchor_59 * 2) & 127;
    int damping_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_65) & 63;
    acc ^= aux;
    int damping_75 = 0;
    for (int k = 0; k < 2; k++) {
        damping_75 = (damping_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_75) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_7(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int checksum_64 = local_arr[aux % 3];
    acc = (acc + checksum_64 * 2) & 127;
    int coefficient_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000625_2513_8(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int bound_47 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_47 > 35) {
        acc = (acc + bound_47 * 2 + 5) & 127;
        aux ^= (bound_47 & 15);
    } else {
        acc = (acc - bound_47 + 11) & 127;
        aux += 3;
    }
    int accumulator_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_38) & 63;
    acc ^= aux;
    int metric_54 = (aux + st.buffer[1]) & 3;
    switch (metric_54) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000625_2513_9(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int accumulator_38 = local_arr[aux % 3];
    acc = (acc + accumulator_38 * 2) & 127;
    int checksum_63 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_63 > 34) {
        acc = (acc + checksum_63 * 2 + 5) & 127;
        aux ^= (checksum_63 & 15);
    } else {
        acc = (acc - checksum_63 + 11) & 127;
        aux += 3;
    }
    int quotient_37 = (aux + st.buffer[1]) & 3;
    switch (quotient_37) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_79 = 0;
    for (int k = 0; k < 3; k++) {
        tally_79 = (tally_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_79) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_48 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_48 > 49) {
        acc = (acc + tally_48 * 2 + 5) & 127;
        aux ^= (tally_48 & 15);
    } else {
        acc = (acc - tally_48 + 11) & 127;
        aux += 3;
    }
    int phase_21 = 0;
    for (int k = 0; k < 3; k++) {
        phase_21 = (phase_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_11(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int parity_50 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_50 > 35) {
        acc = (acc + parity_50 * 2 + 5) & 127;
        aux ^= (parity_50 & 15);
    } else {
        acc = (acc - parity_50 + 11) & 127;
        aux += 3;
    }
    int accumulator_72 = (aux + st.buffer[1]) & 3;
    switch (accumulator_72) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_53 = (aux + st.buffer[1]) & 3;
    switch (window_53) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_13(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int sample_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_26) & 63;
    acc ^= aux;
    int damping_98 = 0;
    for (int k = 0; k < 3; k++) {
        damping_98 = (damping_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_98) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int vector_11 = local_arr[aux % 3];
    acc = (acc + vector_11 * 2) & 127;
    int cursor_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000625_2513_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_45 = local_arr[aux % 3];
    acc = (acc + accumulator_45 * 2) & 127;
    int pivot_52 = (aux + st.buffer[1]) & 3;
    switch (pivot_52) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quotient_53 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_53 = (quotient_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_53) & 127;
    }
    int offset_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_34 = local_arr[aux % 3];
    acc = (acc + metric_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000625_2513_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int stride_43 = 0;
    for (int k = 0; k < 2; k++) {
        stride_43 = (stride_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_43) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_30 = (aux + st.buffer[1]) & 3;
    switch (checksum_30) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_45 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_45 > 31) {
        acc = (acc + anchor_45 * 2 + 5) & 127;
        aux ^= (anchor_45 & 15);
    } else {
        acc = (acc - anchor_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int metric_53 = local_arr[aux % 3];
    acc = (acc + metric_53 * 2) & 127;
    int metric_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_83) & 63;
    acc ^= aux;
    int index_reg_78 = (aux + st.buffer[1]) & 3;
    switch (index_reg_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_38 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_38 > 49) {
        acc = (acc + accumulator_38 * 2 + 5) & 127;
        aux ^= (accumulator_38 & 15);
    } else {
        acc = (acc - accumulator_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_19(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int phase_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_32) & 63;
    acc ^= aux;
    int sample_29 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_29 > 50) {
        acc = (acc + sample_29 * 2 + 5) & 127;
        aux ^= (sample_29 & 15);
    } else {
        acc = (acc - sample_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000625_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int phase_44 = local_arr[aux % 3];
    acc = (acc + phase_44 * 2) & 127;
    int checksum_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_59) & 63;
    acc ^= aux;
    int residue_25 = 0;
    for (int k = 0; k < 3; k++) {
        residue_25 = (residue_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_25) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000625_2513_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_98 = local_arr[aux % 3];
    acc = (acc + anchor_98 * 2) & 127;
    int quotient_33 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_33 = (quotient_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_33) & 127;
    }
    int bound_51 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_51 > 29) {
        acc = (acc + bound_51 * 2 + 5) & 127;
        aux ^= (bound_51 & 15);
    } else {
        acc = (acc - bound_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000625_2513_22(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000625_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int pivot_45 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_45 = (pivot_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_45) & 127;
    }
    int delta_96 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_96 > 47) {
        acc = (acc + delta_96 * 2 + 5) & 127;
        aux ^= (delta_96 & 15);
    } else {
        acc = (acc - delta_96 + 11) & 127;
        aux += 3;
    }
    int window_79 = (aux + st.buffer[1]) & 3;
    switch (window_79) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000625_0;
    int sec_r000625_1;
    int sec_r000625_2;
    int sec_r000625_3;
    int sec_r000625_4;
    int sec_r000625_5;
    int sec_r000625_6;
    int sec_r000625_7;
    int sec_r000625_8;
    int sec_r000625_9;
    int sec_r000625_10;
    int sec_r000625_11;
    int sec_r000625_12;
    int sec_r000625_13;
    int sec_r000625_14;
    int sec_r000625_15;
    int sec_r000625_16;
    int sec_r000625_17;
    int sec_r000625_18;
    int sec_r000625_19;
    int pub_r000625_0;
    int pub_r000625_1;
    int pub_r000625_2;
    int pub_r000625_3;
    int pub_r000625_4;
    int pub_r000625_5;
    int pub_r000625_6;
    int pub_r000625_7;
    int pub_r000625_8;
    int pub_r000625_9;
    int pub_r000625_10;
    int pub_r000625_11;
    int pub_r000625_12;
    int pub_r000625_13;
    int pub_r000625_14;
    int pub_r000625_15;
    int pub_r000625_16;
    int pub_r000625_17;
    int pub_r000625_18;
    int pub_r000625_19;
    int pub_r000625_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000625_0 >= -100 && pub_r000625_0 <= 100);
    __CPROVER_assume(pub_r000625_1 >= -100 && pub_r000625_1 <= 100);
    __CPROVER_assume(pub_r000625_2 >= -100 && pub_r000625_2 <= 100);
    __CPROVER_assume(pub_r000625_3 >= -100 && pub_r000625_3 <= 100);
    __CPROVER_assume(pub_r000625_4 >= -100 && pub_r000625_4 <= 100);
    __CPROVER_assume(pub_r000625_5 >= -100 && pub_r000625_5 <= 100);
    __CPROVER_assume(pub_r000625_6 >= -100 && pub_r000625_6 <= 100);
    __CPROVER_assume(pub_r000625_7 >= -100 && pub_r000625_7 <= 100);
    __CPROVER_assume(pub_r000625_8 >= -100 && pub_r000625_8 <= 100);
    __CPROVER_assume(pub_r000625_9 >= -100 && pub_r000625_9 <= 100);
    __CPROVER_assume(pub_r000625_10 >= -100 && pub_r000625_10 <= 100);
    __CPROVER_assume(pub_r000625_11 >= -100 && pub_r000625_11 <= 100);
    __CPROVER_assume(pub_r000625_12 >= -100 && pub_r000625_12 <= 100);
    __CPROVER_assume(pub_r000625_13 >= -100 && pub_r000625_13 <= 100);
    __CPROVER_assume(pub_r000625_14 >= -100 && pub_r000625_14 <= 100);
    __CPROVER_assume(pub_r000625_15 >= -100 && pub_r000625_15 <= 100);
    __CPROVER_assume(pub_r000625_16 >= -100 && pub_r000625_16 <= 100);
    __CPROVER_assume(pub_r000625_17 >= -100 && pub_r000625_17 <= 100);
    __CPROVER_assume(pub_r000625_18 >= -100 && pub_r000625_18 <= 100);
    __CPROVER_assume(pub_r000625_19 >= -100 && pub_r000625_19 <= 100);
    __CPROVER_assume(pub_r000625_20 >= -100 && pub_r000625_20 <= 100);
    __CPROVER_assume(sec_r000625_0 >= 0 && sec_r000625_0 <= 255);
    __CPROVER_assume(sec_r000625_1 >= 0 && sec_r000625_1 <= 255);
    __CPROVER_assume(sec_r000625_2 >= 0 && sec_r000625_2 <= 255);
    __CPROVER_assume(sec_r000625_3 >= 0 && sec_r000625_3 <= 255);
    __CPROVER_assume(sec_r000625_4 >= 0 && sec_r000625_4 <= 255);
    __CPROVER_assume(sec_r000625_5 >= 0 && sec_r000625_5 <= 255);
    __CPROVER_assume(sec_r000625_6 >= 0 && sec_r000625_6 <= 255);
    __CPROVER_assume(sec_r000625_7 >= 0 && sec_r000625_7 <= 255);
    __CPROVER_assume(sec_r000625_8 >= 0 && sec_r000625_8 <= 255);
    __CPROVER_assume(sec_r000625_9 >= 0 && sec_r000625_9 <= 255);
    __CPROVER_assume(sec_r000625_10 >= 0 && sec_r000625_10 <= 255);
    __CPROVER_assume(sec_r000625_11 >= 0 && sec_r000625_11 <= 255);
    __CPROVER_assume(sec_r000625_12 >= 0 && sec_r000625_12 <= 255);
    __CPROVER_assume(sec_r000625_13 >= 0 && sec_r000625_13 <= 255);
    __CPROVER_assume(sec_r000625_14 >= 0 && sec_r000625_14 <= 255);
    __CPROVER_assume(sec_r000625_15 >= 0 && sec_r000625_15 <= 255);
    __CPROVER_assume(sec_r000625_16 >= 0 && sec_r000625_16 <= 255);
    __CPROVER_assume(sec_r000625_17 >= 0 && sec_r000625_17 <= 255);
    __CPROVER_assume(sec_r000625_18 >= 0 && sec_r000625_18 <= 255);
    __CPROVER_assume(sec_r000625_19 >= 0 && sec_r000625_19 <= 255);

    struct FilterState_R000625_2513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000625_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000625_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000625_0 + 7) & 15;
    struct SensorNode_R000625_2513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000625_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000625_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000625_0 + 9) & 15;

    union RegisterBank_R000625_2513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 15) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 30) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

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
    int stage_v_14 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 22) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 37) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 14) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 29) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 40) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 55) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 15) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 30) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 33) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 48) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 11) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 26) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 35) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 50) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 38) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 53) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 25) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 40) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] * 2 + 268) & 63;
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
    int stage_v_88 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_89 = (stage_v_89 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] ^ 96) & 3;
    switch (stage_v_93) {
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

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[1] * 2 + 289) & 63;
    if (stage_v_94 > 25) {
        out_sink = (out_sink + stage_v_94 - 5) & 255;
        if (stage_v_94 > 40) {
            chk_sum ^= (stage_v_94 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_94 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 95 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 96) & 15;
    int stage_v_95 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= stage_v_95;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (out_sink > 100) ? (chk_sum & 31) : (101 & 31);
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= (stage_v_96 << 1) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = table[1];
    table[1] = (table[2] + 195) & 63;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_0.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 18) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 33) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_1.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 15) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 30) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = table[2];
    table[2] = (table[3] + 205) & 63;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_1.buffer[1] * 2 + 316) & 63;
    if (stage_v_103 > 21) {
        out_sink = (out_sink + stage_v_103 - 5) & 255;
        if (stage_v_103 > 36) {
            chk_sum ^= (stage_v_103 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_103 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 108) & 15;
    int stage_v_107 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= stage_v_107;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_1.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_0.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 26) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 41) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (out_sink > 100) ? (chk_sum & 31) : (118 & 31);
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= (stage_v_113 << 1) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = table[2];
    table[2] = (table[3] + 229) & 63;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 116) & 15;
    int stage_v_115 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= stage_v_115;

    /* Execution Pipeline Stage 116 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 117) & 15;
    int stage_v_116 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= stage_v_116;

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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_119 = (stage_v_119 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] ^ 123) & 3;
    switch (stage_v_120) {
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

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_1.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 10) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 25) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[0] ^ 127) & 3;
    switch (stage_v_124) {
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

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[2] * 2 + 382) & 63;
    if (stage_v_125 > 27) {
        out_sink = (out_sink + stage_v_125 - 5) & 255;
        if (stage_v_125 > 42) {
            chk_sum ^= (stage_v_125 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_125 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = table[2];
    table[2] = (table[3] + 261) & 63;
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
    int stage_v_134 = (out_sink > 100) ? (chk_sum & 31) : (139 & 31);
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= (stage_v_134 << 1) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 140) & 15;
    int stage_v_139 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= stage_v_139;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_1.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 39) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 54) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] * 2 + 439) & 63;
    if (stage_v_144 > 33) {
        out_sink = (out_sink + stage_v_144 - 5) & 255;
        if (stage_v_144 > 48) {
            chk_sum ^= (stage_v_144 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_144 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_149 = (stage_v_149 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 37) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 52) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 162 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (out_sink > 100) ? (chk_sum & 31) : (168 & 31);
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= (stage_v_163 << 1) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 166) & 15;
    int stage_v_165 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= stage_v_165;

    /* Execution Pipeline Stage 166 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 167) & 15;
    int stage_v_166 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= stage_v_166;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] ^ 171) & 3;
    switch (stage_v_168) {
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

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = table[1];
    table[1] = (table[2] + 339) & 63;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = table[2];
    table[2] = (table[3] + 341) & 63;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_171 = (stage_v_171 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] ^ 177) & 3;
    switch (stage_v_174) {
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

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = table[3];
    table[3] = (table[0] + 351) & 63;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (out_sink > 100) ? (chk_sum & 31) : (181 & 31);
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= (stage_v_176 << 1) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = table[1];
    table[1] = (table[2] + 355) & 63;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_0.buffer[0] ^ 181) & 3;
    switch (stage_v_178) {
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

    /* Execution Pipeline Stage 179 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] * 2 + 547) & 63;
    if (stage_v_180 > 39) {
        out_sink = (out_sink + stage_v_180 - 5) & 255;
        if (stage_v_180 > 54) {
            chk_sum ^= (stage_v_180 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_180 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_181 = (stage_v_181 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = table[2];
    table[2] = (table[3] + 365) & 63;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (out_sink > 100) ? (chk_sum & 31) : (188 & 31);
    out_sink = (out_sink + stage_v_183) & 255;
    chk_sum ^= (stage_v_183 << 1) & 127;

    /* Execution Pipeline Stage 184 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 185) & 15;
    int stage_v_184 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= stage_v_184;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (out_sink > 100) ? (chk_sum & 31) : (190 & 31);
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= (stage_v_185 << 1) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_0.buffer[0] * 2 + 565) & 63;
    if (stage_v_186 > 27) {
        out_sink = (out_sink + stage_v_186 - 5) & 255;
        if (stage_v_186 > 42) {
            chk_sum ^= (stage_v_186 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_186 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = table[3];
    table[3] = (table[0] + 375) & 63;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (out_sink > 100) ? (chk_sum & 31) : (194 & 31);
    out_sink = (out_sink + stage_v_189) & 255;
    chk_sum ^= (stage_v_189 << 1) & 127;

    /* Execution Pipeline Stage 190 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 191) & 15;
    int stage_v_190 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_190) & 255;
    chk_sum ^= stage_v_190;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_191 = (stage_v_191 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_191) & 127;
    }
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_192 = (stage_v_192 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_192) & 127;
    }
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
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

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_195 = (stage_v_195 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_195) & 127;
    }
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_0.buffer[1] * 2 + 595) & 63;
    if (stage_v_196 > 12) {
        out_sink = (out_sink + stage_v_196 - 5) & 255;
        if (stage_v_196 > 27) {
            chk_sum ^= (stage_v_196 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_196 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (out_sink > 100) ? (chk_sum & 31) : (202 & 31);
    out_sink = (out_sink + stage_v_197) & 255;
    chk_sum ^= (stage_v_197 << 1) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (out_sink > 100) ? (chk_sum & 31) : (203 & 31);
    out_sink = (out_sink + stage_v_198) & 255;
    chk_sum ^= (stage_v_198 << 1) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = table[3];
    table[3] = (table[0] + 399) & 63;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (out_sink > 100) ? (chk_sum & 31) : (206 & 31);
    out_sink = (out_sink + stage_v_201) & 255;
    chk_sum ^= (stage_v_201 << 1) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (st_var_0.buffer[1] * 2 + 613) & 63;
    if (stage_v_202 > 37) {
        out_sink = (out_sink + stage_v_202 - 5) & 255;
        if (stage_v_202 > 52) {
            chk_sum ^= (stage_v_202 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_202 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (out_sink > 100) ? (chk_sum & 31) : (208 & 31);
    out_sink = (out_sink + stage_v_203) & 255;
    chk_sum ^= (stage_v_203 << 1) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (out_sink > 100) ? (chk_sum & 31) : (209 & 31);
    out_sink = (out_sink + stage_v_204) & 255;
    chk_sum ^= (stage_v_204 << 1) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (st_var_1.buffer[0] ^ 208) & 3;
    switch (stage_v_205) {
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

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = table[2];
    table[2] = (table[3] + 413) & 63;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (st_var_1.buffer[0] ^ 210) & 3;
    switch (stage_v_207) {
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

    /* Security Information Flow: Family = nested_implicit_flow */
    if ((sec_r000625_19 & 1) != 0) {
        if ((sec_r000625_2 & 2) != 0) {
            out_sink += 30;
        } else {
            out_sink += 19;
        }
    } else {
        if ((sec_r000625_1 & 4) != 0) {
            out_sink -= 25;
        } else {
            out_sink -= 47;
        }
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
