/*
 * Benchmark Program: R000993
 * Family: mixed_control_data
 * Generator Seed: 499313
 * High Inputs: 20 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000993_9313_0 {
    short facility;
    int code;
    int severity;
    short seq;
    short timestamp;
    int signature;
    int buffer[3];
};

struct Vector3D_R000993_9313_1 {
    int heading;
    int coord_z;
    short coord_x;
    int buffer[3];
};

struct Transaction_R000993_9313_2 {
    unsigned char status;
    short account_id;
    short rate;
    int buffer[3];
};

struct SensorNode_R000993_9313_3 {
    unsigned char gain;
    short threshold;
    int calib;
    int offset;
    int reading;
    int status;
    int buffer[3];
};

union PacketPayload_R000993_9313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000993_9313_0(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000993_9313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tracker_11 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_11 > 31) {
        acc = (acc + tracker_11 * 2 + 5) & 127;
        aux ^= (tracker_11 & 15);
    } else {
        acc = (acc - tracker_11 + 11) & 127;
        aux += 3;
    }
    int parity_43 = 0;
    for (int k = 0; k < 3; k++) {
        parity_43 = (parity_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_43) & 127;
    }
    int accumulator_31 = (aux + st.buffer[1]) & 3;
    switch (accumulator_31) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_1(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int tracker_41 = local_arr[aux % 3];
    acc = (acc + tracker_41 * 2) & 127;
    int quantum_53 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_53 = (quantum_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_53) & 127;
    }
    int tally_64 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_64 > 16) {
        acc = (acc + tally_64 * 2 + 5) & 127;
        aux ^= (tally_64 & 15);
    } else {
        acc = (acc - tally_64 + 11) & 127;
        aux += 3;
    }
    int index_reg_36 = (aux + st.buffer[1]) & 3;
    switch (index_reg_36) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_2(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_88 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_88 > 24) {
        acc = (acc + scale_88 * 2 + 5) & 127;
        aux ^= (scale_88 & 15);
    } else {
        acc = (acc - scale_88 + 11) & 127;
        aux += 3;
    }
    int quotient_94 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_94 = (quotient_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_94) & 127;
    }
    int segment_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000993_9313_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int pivot_49 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_49 = (pivot_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_49) & 127;
    }
    int quotient_97 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_97 > 20) {
        acc = (acc + quotient_97 * 2 + 5) & 127;
        aux ^= (quotient_97 & 15);
    } else {
        acc = (acc - quotient_97 + 11) & 127;
        aux += 3;
    }
    int stride_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000993_9313_4(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000993_9313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_19 = (aux + st.buffer[1]) & 3;
    switch (stride_19) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_95 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_95 = (index_reg_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_95) & 127;
    }
    int phase_74 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_74 > 14) {
        acc = (acc + phase_74 * 2 + 5) & 127;
        aux ^= (phase_74 & 15);
    } else {
        acc = (acc - phase_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_5(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int margin_25 = 0;
    for (int k = 0; k < 3; k++) {
        margin_25 = (margin_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_25) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_13 = local_arr[aux % 3];
    acc = (acc + pivot_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_6(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000993_9313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_42 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_42 > 21) {
        acc = (acc + vector_42 * 2 + 5) & 127;
        aux ^= (vector_42 & 15);
    } else {
        acc = (acc - vector_42 + 11) & 127;
        aux += 3;
    }
    int stride_11 = 0;
    for (int k = 0; k < 2; k++) {
        stride_11 = (stride_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_11) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_55 = local_arr[aux % 3];
    acc = (acc + parity_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_7(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int factor_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_28) & 63;
    acc ^= aux;
    int accumulator_25 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_25 > 40) {
        acc = (acc + accumulator_25 * 2 + 5) & 127;
        aux ^= (accumulator_25 & 15);
    } else {
        acc = (acc - accumulator_25 + 11) & 127;
        aux += 3;
    }
    int cursor_81 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_81 = (cursor_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_81) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_8(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int metric_94 = local_arr[aux % 3];
    acc = (acc + metric_94 * 2) & 127;
    int factor_35 = 0;
    for (int k = 0; k < 3; k++) {
        factor_35 = (factor_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_35) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000993_9313_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000993_9313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_86 = local_arr[aux % 3];
    acc = (acc + coefficient_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_10(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000993_9313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int mask_61 = 0;
    for (int k = 0; k < 2; k++) {
        mask_61 = (mask_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_61) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_81 = local_arr[aux % 3];
    acc = (acc + delta_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_11(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int phase_17 = local_arr[aux % 3];
    acc = (acc + phase_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_12(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int sample_13 = 0;
    for (int k = 0; k < 3; k++) {
        sample_13 = (sample_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_13) & 127;
    }
    int margin_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int margin_73 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_73 > 43) {
        acc = (acc + margin_73 * 2 + 5) & 127;
        aux ^= (margin_73 & 15);
    } else {
        acc = (acc - margin_73 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_72 = local_arr[aux % 3];
    acc = (acc + damping_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000993_9313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int damping_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_81) & 63;
    acc ^= aux;
    int residue_33 = 0;
    for (int k = 0; k < 3; k++) {
        residue_33 = (residue_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_33) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_43 = local_arr[aux % 3];
    acc = (acc + scale_43 * 2) & 127;
    int factor_28 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_28 > 14) {
        acc = (acc + factor_28 * 2 + 5) & 127;
        aux ^= (factor_28 & 15);
    } else {
        acc = (acc - factor_28 + 11) & 127;
        aux += 3;
    }
    int tally_73 = (aux + st.buffer[1]) & 3;
    switch (tally_73) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000993_9313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_22 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_22 > 10) {
        acc = (acc + stride_22 * 2 + 5) & 127;
        aux ^= (stride_22 & 15);
    } else {
        acc = (acc - stride_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_17(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000993_9313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int margin_55 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_55 > 22) {
        acc = (acc + margin_55 * 2 + 5) & 127;
        aux ^= (margin_55 & 15);
    } else {
        acc = (acc - margin_55 + 11) & 127;
        aux += 3;
    }
    int vector_50 = 0;
    for (int k = 0; k < 2; k++) {
        vector_50 = (vector_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_50) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_70 = local_arr[aux % 3];
    acc = (acc + metric_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_86 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_86 > 12) {
        acc = (acc + checksum_86 * 2 + 5) & 127;
        aux ^= (checksum_86 & 15);
    } else {
        acc = (acc - checksum_86 + 11) & 127;
        aux += 3;
    }
    int checksum_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_77) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int weight_48 = 0;
    for (int k = 0; k < 3; k++) {
        weight_48 = (weight_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_48) & 127;
    }
    int cursor_87 = (aux + st.buffer[1]) & 3;
    switch (cursor_87) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_20(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_47) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_22 = 0;
    for (int k = 0; k < 2; k++) {
        factor_22 = (factor_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_22) & 127;
    }
    int sample_75 = (aux + st.buffer[1]) & 3;
    switch (sample_75) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int threshold_82 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_82 > 44) {
        acc = (acc + threshold_82 * 2 + 5) & 127;
        aux ^= (threshold_82 & 15);
    } else {
        acc = (acc - threshold_82 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_21 = local_arr[aux % 3];
    acc = (acc + mask_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000993_9313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int phase_90 = 0;
    for (int k = 0; k < 3; k++) {
        phase_90 = (phase_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_90) & 127;
    }
    int bound_33 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_33 > 13) {
        acc = (acc + bound_33 * 2 + 5) & 127;
        aux ^= (bound_33 & 15);
    } else {
        acc = (acc - bound_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_67 = local_arr[aux % 3];
    acc = (acc + damping_67 * 2) & 127;
    int factor_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000993_9313_23(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000993_9313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int window_79 = local_arr[aux % 3];
    acc = (acc + window_79 * 2) & 127;
    int parity_30 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_30 > 37) {
        acc = (acc + parity_30 * 2 + 5) & 127;
        aux ^= (parity_30 & 15);
    } else {
        acc = (acc - parity_30 + 11) & 127;
        aux += 3;
    }
    int quantum_71 = (aux + st.buffer[1]) & 3;
    switch (quantum_71) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000993_9313_24(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000993_9313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int index_reg_12 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_12 = (index_reg_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_12) & 127;
    }
    int metric_11 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_11 > 30) {
        acc = (acc + metric_11 * 2 + 5) & 127;
        aux ^= (metric_11 & 15);
    } else {
        acc = (acc - metric_11 + 11) & 127;
        aux += 3;
    }
    int window_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_17) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_47 = local_arr[aux % 3];
    acc = (acc + anchor_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000993_9313_25(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000993_9313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int checksum_86 = (aux + st.buffer[1]) & 3;
    switch (checksum_86) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_82) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_52 = local_arr[aux % 3];
    acc = (acc + checksum_52 * 2) & 127;
    int margin_28 = 0;
    for (int k = 0; k < 2; k++) {
        margin_28 = (margin_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_28) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000993_0;
    int sec_r000993_1;
    int sec_r000993_2;
    int sec_r000993_3;
    int sec_r000993_4;
    int sec_r000993_5;
    int sec_r000993_6;
    int sec_r000993_7;
    int sec_r000993_8;
    int sec_r000993_9;
    int sec_r000993_10;
    int sec_r000993_11;
    int sec_r000993_12;
    int sec_r000993_13;
    int sec_r000993_14;
    int sec_r000993_15;
    int sec_r000993_16;
    int sec_r000993_17;
    int sec_r000993_18;
    int sec_r000993_19;
    int pub_r000993_0;
    int pub_r000993_1;
    int pub_r000993_2;
    int pub_r000993_3;
    int pub_r000993_4;
    int pub_r000993_5;
    int pub_r000993_6;
    int pub_r000993_7;
    int pub_r000993_8;
    int pub_r000993_9;
    int pub_r000993_10;
    int pub_r000993_11;
    int pub_r000993_12;
    int pub_r000993_13;
    int pub_r000993_14;
    int pub_r000993_15;
    int pub_r000993_16;
    int pub_r000993_17;
    int pub_r000993_18;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000993_0 >= -100 && pub_r000993_0 <= 100);
    __CPROVER_assume(pub_r000993_1 >= -100 && pub_r000993_1 <= 100);
    __CPROVER_assume(pub_r000993_2 >= -100 && pub_r000993_2 <= 100);
    __CPROVER_assume(pub_r000993_3 >= -100 && pub_r000993_3 <= 100);
    __CPROVER_assume(pub_r000993_4 >= -100 && pub_r000993_4 <= 100);
    __CPROVER_assume(pub_r000993_5 >= -100 && pub_r000993_5 <= 100);
    __CPROVER_assume(pub_r000993_6 >= -100 && pub_r000993_6 <= 100);
    __CPROVER_assume(pub_r000993_7 >= -100 && pub_r000993_7 <= 100);
    __CPROVER_assume(pub_r000993_8 >= -100 && pub_r000993_8 <= 100);
    __CPROVER_assume(pub_r000993_9 >= -100 && pub_r000993_9 <= 100);
    __CPROVER_assume(pub_r000993_10 >= -100 && pub_r000993_10 <= 100);
    __CPROVER_assume(pub_r000993_11 >= -100 && pub_r000993_11 <= 100);
    __CPROVER_assume(pub_r000993_12 >= -100 && pub_r000993_12 <= 100);
    __CPROVER_assume(pub_r000993_13 >= -100 && pub_r000993_13 <= 100);
    __CPROVER_assume(pub_r000993_14 >= -100 && pub_r000993_14 <= 100);
    __CPROVER_assume(pub_r000993_15 >= -100 && pub_r000993_15 <= 100);
    __CPROVER_assume(pub_r000993_16 >= -100 && pub_r000993_16 <= 100);
    __CPROVER_assume(pub_r000993_17 >= -100 && pub_r000993_17 <= 100);
    __CPROVER_assume(pub_r000993_18 >= -100 && pub_r000993_18 <= 100);
    __CPROVER_assume(sec_r000993_0 >= 0 && sec_r000993_0 <= 255);
    __CPROVER_assume(sec_r000993_1 >= 0 && sec_r000993_1 <= 255);
    __CPROVER_assume(sec_r000993_2 >= 0 && sec_r000993_2 <= 255);
    __CPROVER_assume(sec_r000993_3 >= 0 && sec_r000993_3 <= 255);
    __CPROVER_assume(sec_r000993_4 >= 0 && sec_r000993_4 <= 255);
    __CPROVER_assume(sec_r000993_5 >= 0 && sec_r000993_5 <= 255);
    __CPROVER_assume(sec_r000993_6 >= 0 && sec_r000993_6 <= 255);
    __CPROVER_assume(sec_r000993_7 >= 0 && sec_r000993_7 <= 255);
    __CPROVER_assume(sec_r000993_8 >= 0 && sec_r000993_8 <= 255);
    __CPROVER_assume(sec_r000993_9 >= 0 && sec_r000993_9 <= 255);
    __CPROVER_assume(sec_r000993_10 >= 0 && sec_r000993_10 <= 255);
    __CPROVER_assume(sec_r000993_11 >= 0 && sec_r000993_11 <= 255);
    __CPROVER_assume(sec_r000993_12 >= 0 && sec_r000993_12 <= 255);
    __CPROVER_assume(sec_r000993_13 >= 0 && sec_r000993_13 <= 255);
    __CPROVER_assume(sec_r000993_14 >= 0 && sec_r000993_14 <= 255);
    __CPROVER_assume(sec_r000993_15 >= 0 && sec_r000993_15 <= 255);
    __CPROVER_assume(sec_r000993_16 >= 0 && sec_r000993_16 <= 255);
    __CPROVER_assume(sec_r000993_17 >= 0 && sec_r000993_17 <= 255);
    __CPROVER_assume(sec_r000993_18 >= 0 && sec_r000993_18 <= 255);
    __CPROVER_assume(sec_r000993_19 >= 0 && sec_r000993_19 <= 255);

    struct EventLog_R000993_9313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000993_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000993_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000993_0 + 7) & 15;
    struct Vector3D_R000993_9313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000993_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000993_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000993_0 + 9) & 15;
    struct Transaction_R000993_9313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000993_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000993_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000993_0 + 11) & 15;
    struct SensorNode_R000993_9313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000993_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000993_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000993_0 + 13) & 15;

    union PacketPayload_R000993_9313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 14) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 29) {
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
    for (int step = 0; step < 3; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 12) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 27) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 39) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 54) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 21) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 36) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 11) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 26) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 37) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 52) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 26) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 41) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 30) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 45) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 28) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 43) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 40) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 55) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 14) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 29) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 12) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 27) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[0] ^ 82) & 3;
    switch (stage_v_79) {
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

    /* Execution Pipeline Stage 80 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 24) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 39) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_92 = (stage_v_92 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_3.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 12) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 27) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (out_sink > 100) ? (chk_sum & 31) : (103 & 31);
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= (stage_v_98 << 1) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_0.buffer[0] ^ 103) & 3;
    switch (stage_v_100) {
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

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 103) & 15;
    int stage_v_102 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= stage_v_102;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (out_sink > 100) ? (chk_sum & 31) : (108 & 31);
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= (stage_v_103 << 1) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[0] ^ 107) & 3;
    switch (stage_v_104) {
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

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_3.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 28) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 43) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[2] * 2 + 337) & 63;
    if (stage_v_110 > 40) {
        out_sink = (out_sink + stage_v_110 - 5) & 255;
        if (stage_v_110 > 55) {
            chk_sum ^= (stage_v_110 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_110 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_3.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (out_sink > 100) ? (chk_sum & 31) : (118 & 31);
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= (stage_v_113 << 1) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_3.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 14) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 29) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (out_sink > 100) ? (chk_sum & 31) : (126 & 31);
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= (stage_v_121 << 1) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_124 = (stage_v_124 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (out_sink > 100) ? (chk_sum & 31) : (133 & 31);
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= (stage_v_128 << 1) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_3.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 31) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 46) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (out_sink > 100) ? (chk_sum & 31) : (142 & 31);
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= (stage_v_137 << 1) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_3.buffer[0] ^ 142) & 3;
    switch (stage_v_139) {
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

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_1.buffer[0] ^ 144) & 3;
    switch (stage_v_141) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = table[2];
    table[2] = (table[3] + 285) & 63;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_3.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 28) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 43) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_0.buffer[1] * 2 + 451) & 63;
    if (stage_v_148 > 37) {
        out_sink = (out_sink + stage_v_148 - 5) & 255;
        if (stage_v_148 > 52) {
            chk_sum ^= (stage_v_148 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_148 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 149 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 150) & 15;
    int stage_v_149 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= stage_v_149;

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
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_2.buffer[0] ^ 157) & 3;
    switch (stage_v_154) {
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

    /* Execution Pipeline Stage 155 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 157) & 15;
    int stage_v_156 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_156) & 255;
    chk_sum ^= stage_v_156;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_3.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (st_var_0.buffer[0] ^ 163) & 3;
    switch (stage_v_160) {
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

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_2.buffer[0] * 2 + 493) & 63;
    if (stage_v_162 > 13) {
        out_sink = (out_sink + stage_v_162 - 5) & 255;
        if (stage_v_162 > 28) {
            chk_sum ^= (stage_v_162 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_162 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 163 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_2.buffer[1] * 2 + 505) & 63;
    if (stage_v_166 > 29) {
        out_sink = (out_sink + stage_v_166 - 5) & 255;
        if (stage_v_166 > 44) {
            chk_sum ^= (stage_v_166 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_166 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 167 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 35) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 50) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 170) & 15;
    int stage_v_169 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= stage_v_169;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (out_sink > 100) ? (chk_sum & 31) : (177 & 31);
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= (stage_v_172 << 1) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (out_sink > 100) ? (chk_sum & 31) : (178 & 31);
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= (stage_v_173 << 1) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (out_sink > 100) ? (chk_sum & 31) : (180 & 31);
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= (stage_v_175 << 1) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = table[1];
    table[1] = (table[2] + 355) & 63;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (out_sink > 100) ? (chk_sum & 31) : (183 & 31);
    out_sink = (out_sink + stage_v_178) & 255;
    chk_sum ^= (stage_v_178 << 1) & 127;

    /* Execution Pipeline Stage 179 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] ^ 183) & 3;
    switch (stage_v_180) {
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

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_181 = (stage_v_181 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_2.buffer[0] ^ 185) & 3;
    switch (stage_v_182) {
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

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = table[0];
    table[0] = (table[1] + 369) & 63;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000993_16 ^ 0x55) & 63;
    if (m_var > 30) {
        out_sink += (m_var * 2 + pub_r000993_9) & 127;
    } else {
        out_sink -= (m_var + 5) & 31;
    }
    out_sink ^= (sec_r000993_5 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
