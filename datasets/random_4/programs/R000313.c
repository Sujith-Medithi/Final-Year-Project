/*
 * Benchmark Program: R000313
 * Family: arithmetic_flow
 * Generator Seed: 431313
 * High Inputs: 18 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000313_1313_0 {
    int code;
    unsigned char seq;
    int severity;
    int buffer[3];
};

struct Transaction_R000313_1313_1 {
    int fee;
    int status;
    short auth_code;
    short account_id;
    int buffer[3];
};

struct CipherContext_R000313_1313_2 {
    int flags;
    short iv;
    int nonce;
    int round_key;
    unsigned char tag;
    int buffer[3];
};

struct FilterState_R000313_1313_3 {
    short mode;
    int gain_db;
    int cutoff;
    int prev_out;
    int prev_in;
    int damping;
    int buffer[3];
};

union ColorPixel_R000313_1313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000313_1313_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_47 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_47 > 39) {
        acc = (acc + threshold_47 * 2 + 5) & 127;
        aux ^= (threshold_47 & 15);
    } else {
        acc = (acc - threshold_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_1(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000313_1313_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_85 = 0;
    for (int k = 0; k < 2; k++) {
        mask_85 = (mask_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_85) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_34 = local_arr[aux % 3];
    acc = (acc + checksum_34 * 2) & 127;
    int anchor_27 = (aux + st.buffer[1]) & 3;
    switch (anchor_27) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_63 = (aux + st.buffer[1]) & 3;
    switch (scale_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_14 = 0;
    for (int k = 0; k < 3; k++) {
        vector_14 = (vector_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_14) & 127;
    }
    int tally_72 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_72 > 45) {
        acc = (acc + tally_72 * 2 + 5) & 127;
        aux ^= (tally_72 & 15);
    } else {
        acc = (acc - tally_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_4(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int accumulator_41 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_41 = (accumulator_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_41) & 127;
    }
    int checksum_82 = (aux + st.buffer[1]) & 3;
    switch (checksum_82) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_90 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_90 > 14) {
        acc = (acc + damping_90 * 2 + 5) & 127;
        aux ^= (damping_90 & 15);
    } else {
        acc = (acc - damping_90 + 11) & 127;
        aux += 3;
    }
    int residue_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_64) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_6(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int window_42 = 0;
    for (int k = 0; k < 2; k++) {
        window_42 = (window_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_42) & 127;
    }
    int stride_33 = (aux + st.buffer[1]) & 3;
    switch (stride_33) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000313_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_62 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_62 > 42) {
        acc = (acc + damping_62 * 2 + 5) & 127;
        aux ^= (damping_62 & 15);
    } else {
        acc = (acc - damping_62 + 11) & 127;
        aux += 3;
    }
    int coefficient_41 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_41 = (coefficient_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_41) & 127;
    }
    int vector_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_82) & 63;
    acc ^= aux;
    int tracker_45 = (aux + st.buffer[1]) & 3;
    switch (tracker_45) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_13 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_13 = (quotient_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_13) & 127;
    }
    int cursor_48 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_48 > 17) {
        acc = (acc + cursor_48 * 2 + 5) & 127;
        aux ^= (cursor_48 & 15);
    } else {
        acc = (acc - cursor_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_9(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int accumulator_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_11) & 63;
    acc ^= aux;
    int pivot_29 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_29 = (pivot_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_29) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_10(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000313_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_49 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_49 > 35) {
        acc = (acc + quantum_49 * 2 + 5) & 127;
        aux ^= (quantum_49 & 15);
    } else {
        acc = (acc - quantum_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int residue_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_65 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_65 = (index_reg_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_12(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_56 = (aux + st.buffer[1]) & 3;
    switch (parity_56) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000313_1313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000313_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_18 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_18 > 46) {
        acc = (acc + mask_18 * 2 + 5) & 127;
        aux ^= (mask_18 & 15);
    } else {
        acc = (acc - mask_18 + 11) & 127;
        aux += 3;
    }
    int factor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_68) & 63;
    acc ^= aux;
    int accumulator_16 = (aux + st.buffer[1]) & 3;
    switch (accumulator_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_41 = 0;
    for (int k = 0; k < 3; k++) {
        factor_41 = (factor_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_41) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int residue_66 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_66 > 26) {
        acc = (acc + residue_66 * 2 + 5) & 127;
        aux ^= (residue_66 & 15);
    } else {
        acc = (acc - residue_66 + 11) & 127;
        aux += 3;
    }
    int window_68 = (aux + st.buffer[1]) & 3;
    switch (window_68) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_92 = local_arr[aux % 3];
    acc = (acc + offset_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_15(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_15 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_15 > 16) {
        acc = (acc + index_reg_15 * 2 + 5) & 127;
        aux ^= (index_reg_15 & 15);
    } else {
        acc = (acc - index_reg_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_53 = local_arr[aux % 3];
    acc = (acc + tracker_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_16(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000313_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_55 = (aux + st.buffer[1]) & 3;
    switch (segment_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_81 = local_arr[aux % 3];
    acc = (acc + metric_81 * 2) & 127;
    int damping_55 = 0;
    for (int k = 0; k < 2; k++) {
        damping_55 = (damping_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_18) & 63;
    acc ^= aux;
    int coefficient_17 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_17 = (coefficient_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_17) & 127;
    }
    int window_96 = (st.buffer[0] * 3 + aux) & 63;
    if (window_96 > 43) {
        acc = (acc + window_96 * 2 + 5) & 127;
        aux ^= (window_96 & 15);
    } else {
        acc = (acc - window_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_18(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000313_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int weight_95 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_95 > 14) {
        acc = (acc + weight_95 * 2 + 5) & 127;
        aux ^= (weight_95 & 15);
    } else {
        acc = (acc - weight_95 + 11) & 127;
        aux += 3;
    }
    int window_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_79) & 63;
    acc ^= aux;
    int tally_43 = 0;
    for (int k = 0; k < 2; k++) {
        tally_43 = (tally_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_43) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_19(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_55 = local_arr[aux % 3];
    acc = (acc + vector_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_28 = (aux + st.buffer[1]) & 3;
    switch (window_28) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_87) & 63;
    acc ^= aux;
    int quotient_12 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_12 > 35) {
        acc = (acc + quotient_12 * 2 + 5) & 127;
        aux ^= (quotient_12 & 15);
    } else {
        acc = (acc - quotient_12 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_21(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000313_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int metric_71 = 0;
    for (int k = 0; k < 2; k++) {
        metric_71 = (metric_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_71) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_22(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int residue_35 = (aux + st.buffer[1]) & 3;
    switch (residue_35) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_20 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_20 > 42) {
        acc = (acc + vector_20 * 2 + 5) & 127;
        aux ^= (vector_20 & 15);
    } else {
        acc = (acc - vector_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000313_1313_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000313_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int anchor_52 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_52 = (anchor_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_52) & 127;
    }
    int anchor_48 = (aux + st.buffer[1]) & 3;
    switch (anchor_48) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_61 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_61 > 39) {
        acc = (acc + mask_61 * 2 + 5) & 127;
        aux ^= (mask_61 & 15);
    } else {
        acc = (acc - mask_61 + 11) & 127;
        aux += 3;
    }
    int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000313_1313_24(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int threshold_94 = local_arr[aux % 3];
    acc = (acc + threshold_94 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000313_1313_25(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000313_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_15 = (aux + st.buffer[1]) & 3;
    switch (anchor_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_28 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_28 > 25) {
        acc = (acc + sample_28 * 2 + 5) & 127;
        aux ^= (sample_28 & 15);
    } else {
        acc = (acc - sample_28 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000313_0;
    int sec_r000313_1;
    int sec_r000313_2;
    int sec_r000313_3;
    int sec_r000313_4;
    int sec_r000313_5;
    int sec_r000313_6;
    int sec_r000313_7;
    int sec_r000313_8;
    int sec_r000313_9;
    int sec_r000313_10;
    int sec_r000313_11;
    int sec_r000313_12;
    int sec_r000313_13;
    int sec_r000313_14;
    int sec_r000313_15;
    int sec_r000313_16;
    int sec_r000313_17;
    int pub_r000313_0;
    int pub_r000313_1;
    int pub_r000313_2;
    int pub_r000313_3;
    int pub_r000313_4;
    int pub_r000313_5;
    int pub_r000313_6;
    int pub_r000313_7;
    int pub_r000313_8;
    int pub_r000313_9;
    int pub_r000313_10;
    int pub_r000313_11;
    int pub_r000313_12;
    int pub_r000313_13;
    int pub_r000313_14;
    int pub_r000313_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000313_0 >= -100 && pub_r000313_0 <= 100);
    __CPROVER_assume(pub_r000313_1 >= -100 && pub_r000313_1 <= 100);
    __CPROVER_assume(pub_r000313_2 >= -100 && pub_r000313_2 <= 100);
    __CPROVER_assume(pub_r000313_3 >= -100 && pub_r000313_3 <= 100);
    __CPROVER_assume(pub_r000313_4 >= -100 && pub_r000313_4 <= 100);
    __CPROVER_assume(pub_r000313_5 >= -100 && pub_r000313_5 <= 100);
    __CPROVER_assume(pub_r000313_6 >= -100 && pub_r000313_6 <= 100);
    __CPROVER_assume(pub_r000313_7 >= -100 && pub_r000313_7 <= 100);
    __CPROVER_assume(pub_r000313_8 >= -100 && pub_r000313_8 <= 100);
    __CPROVER_assume(pub_r000313_9 >= -100 && pub_r000313_9 <= 100);
    __CPROVER_assume(pub_r000313_10 >= -100 && pub_r000313_10 <= 100);
    __CPROVER_assume(pub_r000313_11 >= -100 && pub_r000313_11 <= 100);
    __CPROVER_assume(pub_r000313_12 >= -100 && pub_r000313_12 <= 100);
    __CPROVER_assume(pub_r000313_13 >= -100 && pub_r000313_13 <= 100);
    __CPROVER_assume(pub_r000313_14 >= -100 && pub_r000313_14 <= 100);
    __CPROVER_assume(pub_r000313_15 >= -100 && pub_r000313_15 <= 100);
    __CPROVER_assume(sec_r000313_0 >= 0 && sec_r000313_0 <= 255);
    __CPROVER_assume(sec_r000313_1 >= 0 && sec_r000313_1 <= 255);
    __CPROVER_assume(sec_r000313_2 >= 0 && sec_r000313_2 <= 255);
    __CPROVER_assume(sec_r000313_3 >= 0 && sec_r000313_3 <= 255);
    __CPROVER_assume(sec_r000313_4 >= 0 && sec_r000313_4 <= 255);
    __CPROVER_assume(sec_r000313_5 >= 0 && sec_r000313_5 <= 255);
    __CPROVER_assume(sec_r000313_6 >= 0 && sec_r000313_6 <= 255);
    __CPROVER_assume(sec_r000313_7 >= 0 && sec_r000313_7 <= 255);
    __CPROVER_assume(sec_r000313_8 >= 0 && sec_r000313_8 <= 255);
    __CPROVER_assume(sec_r000313_9 >= 0 && sec_r000313_9 <= 255);
    __CPROVER_assume(sec_r000313_10 >= 0 && sec_r000313_10 <= 255);
    __CPROVER_assume(sec_r000313_11 >= 0 && sec_r000313_11 <= 255);
    __CPROVER_assume(sec_r000313_12 >= 0 && sec_r000313_12 <= 255);
    __CPROVER_assume(sec_r000313_13 >= 0 && sec_r000313_13 <= 255);
    __CPROVER_assume(sec_r000313_14 >= 0 && sec_r000313_14 <= 255);
    __CPROVER_assume(sec_r000313_15 >= 0 && sec_r000313_15 <= 255);
    __CPROVER_assume(sec_r000313_16 >= 0 && sec_r000313_16 <= 255);
    __CPROVER_assume(sec_r000313_17 >= 0 && sec_r000313_17 <= 255);

    struct EventLog_R000313_1313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000313_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000313_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000313_0 + 7) & 15;
    struct Transaction_R000313_1313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000313_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000313_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000313_0 + 9) & 15;
    struct CipherContext_R000313_1313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000313_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000313_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000313_0 + 11) & 15;
    struct FilterState_R000313_1313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000313_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000313_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000313_0 + 13) & 15;

    union ColorPixel_R000313_1313_0 u_var;
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
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 17) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 32) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 28) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 43) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 11) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 26) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 17) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 32) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

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
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 34) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 49) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

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
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 30) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 45) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 25) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 40) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 17) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 32) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 26) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 41) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 39) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 54) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 25) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 40) {
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
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 15) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 30) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 28) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 43) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 31) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 46) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

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
    int stage_v_82 = (st_var_2.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 25) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 40) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 87) & 15;
    int stage_v_86 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= stage_v_86;

    /* Execution Pipeline Stage 87 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_2.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_93 = (stage_v_93 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2];
    table[2] = (table[3] + 189) & 63;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (out_sink > 100) ? (chk_sum & 31) : (101 & 31);
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= (stage_v_96 << 1) & 127;

    /* Execution Pipeline Stage 97 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 98) & 15;
    int stage_v_97 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= stage_v_97;

    /* Execution Pipeline Stage 98 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 99) & 15;
    int stage_v_98 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= stage_v_98;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 103) & 15;
    int stage_v_102 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= stage_v_102;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_3.buffer[0] ^ 106) & 3;
    switch (stage_v_103) {
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

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 108) & 15;
    int stage_v_107 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= stage_v_107;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_108 = (stage_v_108 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[1] * 2 + 334) & 63;
    if (stage_v_109 > 15) {
        out_sink = (out_sink + stage_v_109 - 5) & 255;
        if (stage_v_109 > 30) {
            chk_sum ^= (stage_v_109 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_109 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
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

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 115 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 116) & 15;
    int stage_v_115 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= stage_v_115;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

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
    int stage_v_118 = table[2];
    table[2] = (table[3] + 237) & 63;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] ^ 123) & 3;
    switch (stage_v_120) {
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

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (out_sink > 100) ? (chk_sum & 31) : (126 & 31);
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= (stage_v_121 << 1) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 125) & 15;
    int stage_v_124 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= stage_v_124;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 127) & 15;
    int stage_v_126 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= stage_v_126;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3];
    table[3] = (table[0] + 255) & 63;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_0.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_2.buffer[0] ^ 133) & 3;
    switch (stage_v_130) {
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

    /* Execution Pipeline Stage 131 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 34) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 49) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1];
    table[1] = (table[2] + 283) & 63;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_144 = (stage_v_144 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_3.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 26) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 41) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = table[0];
    table[0] = (table[1] + 297) & 63;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (out_sink > 100) ? (chk_sum & 31) : (157 & 31);
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= (stage_v_152 << 1) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 28) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 43) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = table[2];
    table[2] = (table[3] + 309) & 63;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = table[3];
    table[3] = (table[0] + 311) & 63;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 157) & 15;
    int stage_v_156 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_156) & 255;
    chk_sum ^= stage_v_156;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 28) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 43) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 160 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 161) & 15;
    int stage_v_160 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= stage_v_160;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_1.buffer[2] * 2 + 490) & 63;
    if (stage_v_161 > 29) {
        out_sink = (out_sink + stage_v_161 - 5) & 255;
        if (stage_v_161 > 44) {
            chk_sum ^= (stage_v_161 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_161 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_2.buffer[0] ^ 165) & 3;
    switch (stage_v_162) {
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

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_3.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Security Information Flow: Family = arithmetic_flow */
    int arith_v_0 = (sec_r000313_15 * 3 + pub_r000313_6) & 127;
    int arith_v_1 = (arith_v_0 + (sec_r000313_2 * 2)) & 127;
    int arith_v_2 = (arith_v_1 + (sec_r000313_10 * 2)) & 127;
    int arith_v_3 = (arith_v_2 - (sec_r000313_6 * 2)) & 127;
    out_sink += arith_v_3 & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
