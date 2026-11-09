/*
 * Benchmark Program: R001657
 * Security Family: nested_implicit_flow
 * Generator Seed: 665713
 * High Inputs: 23 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001657_5713_0 {
    int offset;
    short gain;
    unsigned char calib;
    short reading;
    unsigned char status;
    unsigned char threshold;
    int buffer[3];
};

struct CipherContext_R001657_5713_1 {
    int round_key;
    int nonce;
    short iv;
    int tag;
    int buffer[3];
};

struct StreamBuffer_R001657_5713_2 {
    int state;
    short head;
    short checksum;
    short tail;
    int capacity;
    int buffer[3];
};

struct Transaction_R001657_5713_3 {
    short auth_code;
    int status;
    int balance;
    short rate;
    unsigned char account_id;
    int fee;
    int buffer[3];
};

union ColorPixel_R001657_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001657_5713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001657_5713_0(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int anchor_12 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_12 = (anchor_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_12) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_68 = local_arr[aux % 3];
    acc = (acc + accumulator_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001657_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_78 = (aux + st.buffer[1]) & 3;
    switch (margin_78) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_19 = 0;
    for (int k = 0; k < 2; k++) {
        phase_19 = (phase_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_19) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_22 = local_arr[aux % 3];
    acc = (acc + scale_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_96 = (aux + st.buffer[1]) & 3;
    switch (delta_96) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_66 = local_arr[aux % 3];
    acc = (acc + segment_66 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_3(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_19 = (aux + st.buffer[1]) & 3;
    switch (quantum_19) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_4(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001657_5713_5(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_37 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_37 = (checksum_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_37) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_38 = local_arr[aux % 3];
    acc = (acc + offset_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_79 = (aux + st.buffer[1]) & 3;
    switch (factor_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int residue_91 = local_arr[aux % 3];
    acc = (acc + residue_91 * 2) & 127;
    int coefficient_68 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_68 > 31) {
        acc = (acc + coefficient_68 * 2 + 5) & 127;
        aux ^= (coefficient_68 & 15);
    } else {
        acc = (acc - coefficient_68 + 11) & 127;
        aux += 3;
    }
    int tally_38 = (aux + st.buffer[1]) & 3;
    switch (tally_38) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int factor_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_82) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_99 = local_arr[aux % 3];
    acc = (acc + metric_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_8(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001657_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int factor_43 = local_arr[aux % 3];
    acc = (acc + factor_43 * 2) & 127;
    int threshold_35 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_35 = (threshold_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_35) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001657_5713_10(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int offset_69 = 0;
    for (int k = 0; k < 3; k++) {
        offset_69 = (offset_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_69) & 127;
    }
    int segment_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_32) & 63;
    acc ^= aux;
    int accumulator_78 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_78 > 37) {
        acc = (acc + accumulator_78 * 2 + 5) & 127;
        aux ^= (accumulator_78 & 15);
    } else {
        acc = (acc - accumulator_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001657_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int stride_51 = (aux + st.buffer[1]) & 3;
    switch (stride_51) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001657_5713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int bound_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_94) & 63;
    acc ^= aux;
    int segment_43 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_43 > 50) {
        acc = (acc + segment_43 * 2 + 5) & 127;
        aux ^= (segment_43 & 15);
    } else {
        acc = (acc - segment_43 + 11) & 127;
        aux += 3;
    }
    int threshold_38 = (aux + st.buffer[1]) & 3;
    switch (threshold_38) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_13(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_88) & 63;
    acc ^= aux;
    int phase_25 = (aux + st.buffer[1]) & 3;
    switch (phase_25) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_65 = local_arr[aux % 3];
    acc = (acc + scale_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int quotient_95 = local_arr[aux % 3];
    acc = (acc + quotient_95 * 2) & 127;
    int residue_73 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_73 > 40) {
        acc = (acc + residue_73 * 2 + 5) & 127;
        aux ^= (residue_73 & 15);
    } else {
        acc = (acc - residue_73 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_15(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001657_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_31 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_31 = (accumulator_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_31) & 127;
    }
    int quotient_98 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_98 > 33) {
        acc = (acc + quotient_98 * 2 + 5) & 127;
        aux ^= (quotient_98 & 15);
    } else {
        acc = (acc - quotient_98 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_53 = local_arr[aux % 3];
    acc = (acc + stride_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_16(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int parity_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_14) & 63;
    acc ^= aux;
    int delta_77 = 0;
    for (int k = 0; k < 2; k++) {
        delta_77 = (delta_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_77) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int damping_23 = (aux + st.buffer[1]) & 3;
    switch (damping_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_48 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_48 > 43) {
        acc = (acc + tracker_48 * 2 + 5) & 127;
        aux ^= (tracker_48 & 15);
    } else {
        acc = (acc - tracker_48 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_85 = local_arr[aux % 3];
    acc = (acc + offset_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_18(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001657_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int anchor_73 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_73 > 29) {
        acc = (acc + anchor_73 * 2 + 5) & 127;
        aux ^= (anchor_73 & 15);
    } else {
        acc = (acc - anchor_73 + 11) & 127;
        aux += 3;
    }
    int pivot_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_91) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_98 = local_arr[aux % 3];
    acc = (acc + anchor_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001657_5713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001657_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int metric_97 = local_arr[aux % 3];
    acc = (acc + metric_97 * 2) & 127;
    int anchor_63 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_63 = (anchor_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_63) & 127;
    }
    int parity_69 = (aux + st.buffer[1]) & 3;
    switch (parity_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_21(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int accumulator_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_34) & 63;
    acc ^= aux;
    int quantum_54 = (aux + st.buffer[1]) & 3;
    switch (quantum_54) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_55 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_55 > 25) {
        acc = (acc + offset_55 * 2 + 5) & 127;
        aux ^= (offset_55 & 15);
    } else {
        acc = (acc - offset_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int window_40 = 0;
    for (int k = 0; k < 3; k++) {
        window_40 = (window_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_40) & 127;
    }
    int quantum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_47) & 63;
    acc ^= aux;
    int stride_82 = (aux + st.buffer[1]) & 3;
    switch (stride_82) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001657_5713_23(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int coefficient_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_21) & 63;
    acc ^= aux;
    int delta_86 = 0;
    for (int k = 0; k < 2; k++) {
        delta_86 = (delta_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_86) & 127;
    }
    int stride_41 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_41 > 45) {
        acc = (acc + stride_41 * 2 + 5) & 127;
        aux ^= (stride_41 & 15);
    } else {
        acc = (acc - stride_41 + 11) & 127;
        aux += 3;
    }
    int quotient_80 = (aux + st.buffer[1]) & 3;
    switch (quotient_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001657_0;
    int sec_r001657_1;
    int sec_r001657_2;
    int sec_r001657_3;
    int sec_r001657_4;
    int sec_r001657_5;
    int sec_r001657_6;
    int sec_r001657_7;
    int sec_r001657_8;
    int sec_r001657_9;
    int sec_r001657_10;
    int sec_r001657_11;
    int sec_r001657_12;
    int sec_r001657_13;
    int sec_r001657_14;
    int sec_r001657_15;
    int sec_r001657_16;
    int sec_r001657_17;
    int sec_r001657_18;
    int sec_r001657_19;
    int sec_r001657_20;
    int sec_r001657_21;
    int sec_r001657_22;
    int pub_r001657_0;
    int pub_r001657_1;
    int pub_r001657_2;
    int pub_r001657_3;
    int pub_r001657_4;
    int pub_r001657_5;
    int pub_r001657_6;
    int pub_r001657_7;
    int pub_r001657_8;
    int pub_r001657_9;
    int pub_r001657_10;
    int pub_r001657_11;
    int pub_r001657_12;
    int pub_r001657_13;
    int pub_r001657_14;
    int pub_r001657_15;
    int pub_r001657_16;
    int pub_r001657_17;
    int pub_r001657_18;
    int pub_r001657_19;
    int pub_r001657_20;
    int pub_r001657_21;
    int pub_r001657_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001657_0 >= -100 && pub_r001657_0 <= 100);
    __CPROVER_assume(pub_r001657_1 >= -100 && pub_r001657_1 <= 100);
    __CPROVER_assume(pub_r001657_2 >= -100 && pub_r001657_2 <= 100);
    __CPROVER_assume(pub_r001657_3 >= -100 && pub_r001657_3 <= 100);
    __CPROVER_assume(pub_r001657_4 >= -100 && pub_r001657_4 <= 100);
    __CPROVER_assume(pub_r001657_5 >= -100 && pub_r001657_5 <= 100);
    __CPROVER_assume(pub_r001657_6 >= -100 && pub_r001657_6 <= 100);
    __CPROVER_assume(pub_r001657_7 >= -100 && pub_r001657_7 <= 100);
    __CPROVER_assume(pub_r001657_8 >= -100 && pub_r001657_8 <= 100);
    __CPROVER_assume(pub_r001657_9 >= -100 && pub_r001657_9 <= 100);
    __CPROVER_assume(pub_r001657_10 >= -100 && pub_r001657_10 <= 100);
    __CPROVER_assume(pub_r001657_11 >= -100 && pub_r001657_11 <= 100);
    __CPROVER_assume(pub_r001657_12 >= -100 && pub_r001657_12 <= 100);
    __CPROVER_assume(pub_r001657_13 >= -100 && pub_r001657_13 <= 100);
    __CPROVER_assume(pub_r001657_14 >= -100 && pub_r001657_14 <= 100);
    __CPROVER_assume(pub_r001657_15 >= -100 && pub_r001657_15 <= 100);
    __CPROVER_assume(pub_r001657_16 >= -100 && pub_r001657_16 <= 100);
    __CPROVER_assume(pub_r001657_17 >= -100 && pub_r001657_17 <= 100);
    __CPROVER_assume(pub_r001657_18 >= -100 && pub_r001657_18 <= 100);
    __CPROVER_assume(pub_r001657_19 >= -100 && pub_r001657_19 <= 100);
    __CPROVER_assume(pub_r001657_20 >= -100 && pub_r001657_20 <= 100);
    __CPROVER_assume(pub_r001657_21 >= -100 && pub_r001657_21 <= 100);
    __CPROVER_assume(pub_r001657_22 >= -100 && pub_r001657_22 <= 100);
    __CPROVER_assume(sec_r001657_0 >= 0 && sec_r001657_0 <= 255);
    __CPROVER_assume(sec_r001657_1 >= 0 && sec_r001657_1 <= 255);
    __CPROVER_assume(sec_r001657_2 >= 0 && sec_r001657_2 <= 255);
    __CPROVER_assume(sec_r001657_3 >= 0 && sec_r001657_3 <= 255);
    __CPROVER_assume(sec_r001657_4 >= 0 && sec_r001657_4 <= 255);
    __CPROVER_assume(sec_r001657_5 >= 0 && sec_r001657_5 <= 255);
    __CPROVER_assume(sec_r001657_6 >= 0 && sec_r001657_6 <= 255);
    __CPROVER_assume(sec_r001657_7 >= 0 && sec_r001657_7 <= 255);
    __CPROVER_assume(sec_r001657_8 >= 0 && sec_r001657_8 <= 255);
    __CPROVER_assume(sec_r001657_9 >= 0 && sec_r001657_9 <= 255);
    __CPROVER_assume(sec_r001657_10 >= 0 && sec_r001657_10 <= 255);
    __CPROVER_assume(sec_r001657_11 >= 0 && sec_r001657_11 <= 255);
    __CPROVER_assume(sec_r001657_12 >= 0 && sec_r001657_12 <= 255);
    __CPROVER_assume(sec_r001657_13 >= 0 && sec_r001657_13 <= 255);
    __CPROVER_assume(sec_r001657_14 >= 0 && sec_r001657_14 <= 255);
    __CPROVER_assume(sec_r001657_15 >= 0 && sec_r001657_15 <= 255);
    __CPROVER_assume(sec_r001657_16 >= 0 && sec_r001657_16 <= 255);
    __CPROVER_assume(sec_r001657_17 >= 0 && sec_r001657_17 <= 255);
    __CPROVER_assume(sec_r001657_18 >= 0 && sec_r001657_18 <= 255);
    __CPROVER_assume(sec_r001657_19 >= 0 && sec_r001657_19 <= 255);
    __CPROVER_assume(sec_r001657_20 >= 0 && sec_r001657_20 <= 255);
    __CPROVER_assume(sec_r001657_21 >= 0 && sec_r001657_21 <= 255);
    __CPROVER_assume(sec_r001657_22 >= 0 && sec_r001657_22 <= 255);

    struct SensorNode_R001657_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001657_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001657_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001657_0 + 7) & 15;
    struct CipherContext_R001657_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001657_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001657_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001657_0 + 9) & 15;
    struct StreamBuffer_R001657_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001657_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001657_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001657_0 + 11) & 15;
    struct Transaction_R001657_5713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001657_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001657_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001657_0 + 13) & 15;

    union ColorPixel_R001657_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001657_5713_0(sec_r001657_0, sec_r001657_1);
    int helper_flow_1 = fn_R001657_5713_1(sec_r001657_1, pub_r001657_2, pub_r001657_3, pub_r001657_4, pub_r001657_5);
    int helper_flow_2 = fn_R001657_5713_2(sec_r001657_2, sec_r001657_3, pub_r001657_4, pub_r001657_5);
    int helper_flow_3 = fn_R001657_5713_3(sec_r001657_3, pub_r001657_4);
    int helper_flow_4 = fn_R001657_5713_4(sec_r001657_4, pub_r001657_5, pub_r001657_6);
    int helper_flow_5 = fn_R001657_5713_5(sec_r001657_5, pub_r001657_6);
    int helper_flow_6 = fn_R001657_5713_6(sec_r001657_6, pub_r001657_7, pub_r001657_8, pub_r001657_9, pub_r001657_10);
    int helper_flow_7 = fn_R001657_5713_7(sec_r001657_7, sec_r001657_8, pub_r001657_9, pub_r001657_10, pub_r001657_11);
    int helper_flow_8 = fn_R001657_5713_8(sec_r001657_8, pub_r001657_9);
    int helper_flow_9 = fn_R001657_5713_9(sec_r001657_9, pub_r001657_10, pub_r001657_11, pub_r001657_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_2 ^ pub_r001657_16) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001657_14 ^ pub_r001657_5) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001657_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001657_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001657_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001657_22 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001657_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001657_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001657_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_1 ^ pub_r001657_5) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001657_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_5 ^ pub_r001657_21) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001657_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_2 ^ pub_r001657_6) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001657_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001657_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001657_20 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001657_14 ^ pub_r001657_2) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r001657_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001657_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_4 ^ pub_r001657_21) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001657_20 ^ pub_r001657_10) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001657_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001657_2 ^ pub_r001657_7) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001657_19 ^ pub_r001657_9) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001657_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001657_14 ^ pub_r001657_4) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001657_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001657_18 ^ pub_r001657_20) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001657_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_9 ^ pub_r001657_6) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001657_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001657_17 ^ pub_r001657_9) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001657_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_1 ^ pub_r001657_1) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_17 ^ pub_r001657_20) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_9 ^ pub_r001657_22) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001657_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_0 ^ pub_r001657_1) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001657_7 ^ pub_r001657_14) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_20 ^ pub_r001657_21) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001657_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_7 ^ pub_r001657_4) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r001657_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_8 ^ pub_r001657_14) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001657_20 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_5 ^ pub_r001657_4) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001657_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001657_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001657_15 ^ pub_r001657_21) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (helper_flow_1 ^ pub_r001657_19) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_26 ^ pub_r001657_6) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_25 ^ pub_r001657_3) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r001657_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001657_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001657_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_0 ^ pub_r001657_0) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r001657_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_1 ^ pub_r001657_12) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001657_11 ^ pub_r001657_9) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001657_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (helper_flow_1 ^ pub_r001657_3) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001657_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001657_14 ^ pub_r001657_17) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_28 ^ pub_r001657_9) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r001657_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (helper_flow_8 ^ pub_r001657_0) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001657_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_23 ^ pub_r001657_10) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r001657_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001657_21 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001657_10 ^ pub_r001657_10) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001657_6 ^ pub_r001657_18) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r001657_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001657_14 ^ pub_r001657_12) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001657_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_44 ^ pub_r001657_7) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r001657_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001657_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001657_21 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001657_16 ^ pub_r001657_15) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001657_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_20 ^ pub_r001657_21) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001657_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001657_22 ^ pub_r001657_12) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (sec_r001657_17 ^ pub_r001657_7) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_31 ^ pub_r001657_2) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_25 ^ pub_r001657_5) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001657_21 ^ pub_r001657_14) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r001657_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001657_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001657_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_2 ^ pub_r001657_4) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r001657_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_63 ^ pub_r001657_21) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r001657_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001657_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_39 ^ pub_r001657_10) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001657_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_73 ^ pub_r001657_2) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_5 ^ pub_r001657_14) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001657_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001657_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_61 ^ pub_r001657_5) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001657_22 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_73 ^ pub_r001657_1) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_56 ^ pub_r001657_18) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001657_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_8 ^ pub_r001657_15) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001657_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_19 ^ pub_r001657_10) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001657_6 ^ pub_r001657_2) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_3 ^ pub_r001657_13) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_39 ^ pub_r001657_16) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001657_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (helper_flow_7 ^ pub_r001657_12) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001657_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_61 ^ pub_r001657_2) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r001657_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_45 ^ pub_r001657_20) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001657_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001657_18 ^ pub_r001657_18) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001657_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_77 ^ pub_r001657_17) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001657_17 ^ pub_r001657_7) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001657_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001657_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001657_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001657_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_65 ^ pub_r001657_18) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_49 ^ pub_r001657_17) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001657_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_65 ^ pub_r001657_8) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001657_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (sec_r001657_1 ^ pub_r001657_5) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001657_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001657_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001657_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001657_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001657_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001657_20 ^ pub_r001657_22) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_54 ^ pub_r001657_6) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_9 ^ pub_r001657_14) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_89 ^ pub_r001657_12) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_47 ^ pub_r001657_11) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r001657_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_90 ^ pub_r001657_22) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r001657_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001657_20 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_93 ^ pub_r001657_19) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (helper_flow_8 ^ pub_r001657_4) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001657_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001657_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (sec_r001657_1 ^ pub_r001657_6) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_58 ^ pub_r001657_6) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_25 ^ pub_r001657_14) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001657_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001657_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001657_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001657_11 ^ pub_r001657_7) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_100 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001657_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_77 ^ pub_r001657_3) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_73 ^ pub_r001657_9) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (helper_flow_2 ^ pub_r001657_4) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_14 ^ pub_r001657_0) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_22 ^ pub_r001657_21) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_24 ^ pub_r001657_7) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001657_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r001657_7 ^ pub_r001657_17) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_118 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001657_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001657_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r001657_9 ^ pub_r001657_2) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_90 ^ pub_r001657_7) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_100 ^ pub_r001657_21) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_54 ^ pub_r001657_22) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r001657_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_83 ^ pub_r001657_17) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_126 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (sec_r001657_2 ^ pub_r001657_17) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001657_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_43 ^ pub_r001657_18) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((sec_r001657_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_88 ^ pub_r001657_18) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((sec_r001657_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001657_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001657_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001657_20 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_152 ^ pub_r001657_13) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_144 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (sec_r001657_18 ^ pub_r001657_4) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((sec_r001657_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_31 ^ pub_r001657_20) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001657_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_63 ^ pub_r001657_2) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001657_22 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_40 ^ pub_r001657_11) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001657_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r001657_5 ^ pub_r001657_5) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r001657_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001657_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001657_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_26 ^ pub_r001657_0) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_137 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_63 ^ pub_r001657_17) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_146 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
