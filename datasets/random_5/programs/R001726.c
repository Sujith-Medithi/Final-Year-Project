/*
 * Benchmark Program: R001726
 * Security Family: implicit_flow
 * Generator Seed: 672613
 * High Inputs: 22 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001726_2613_0 {
    short fee;
    unsigned char rate;
    unsigned char balance;
    int account_id;
    int auth_code;
    int buffer[3];
};

struct CipherContext_R001726_2613_1 {
    int counter;
    short iv;
    unsigned char nonce;
    int buffer[3];
};

struct EventLog_R001726_2613_2 {
    unsigned char code;
    int seq;
    short timestamp;
    int severity;
    unsigned char signature;
    int buffer[3];
};

struct FilterState_R001726_2613_3 {
    short gain_db;
    unsigned char prev_out;
    short prev_in;
    short mode;
    short damping;
    int buffer[3];
};

union TelemetryField_R001726_2613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001726_2613_0(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001726_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int margin_24 = (aux + st.buffer[1]) & 3;
    switch (margin_24) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_77 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_77 = (threshold_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_77) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001726_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int metric_95 = (aux + st.buffer[1]) & 3;
    switch (metric_95) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_53 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_53 = (quotient_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_53) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_82 = local_arr[aux % 3];
    acc = (acc + accumulator_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001726_2613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001726_2613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int anchor_61 = local_arr[aux % 3];
    acc = (acc + anchor_61 * 2) & 127;
    int index_reg_12 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_12 = (index_reg_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_12) & 127;
    }
    int factor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_35 > 31) {
        acc = (acc + factor_35 * 2 + 5) & 127;
        aux ^= (factor_35 & 15);
    } else {
        acc = (acc - factor_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_3(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001726_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_43) & 63;
    acc ^= aux;
    int sample_83 = (aux + st.buffer[1]) & 3;
    switch (sample_83) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int mask_75 = local_arr[aux % 3];
    acc = (acc + mask_75 * 2) & 127;
    int tracker_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_40 > 14) {
        acc = (acc + tracker_40 * 2 + 5) & 127;
        aux ^= (tracker_40 & 15);
    } else {
        acc = (acc - tracker_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001726_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int quantum_17 = local_arr[aux % 3];
    acc = (acc + quantum_17 * 2) & 127;
    int offset_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001726_2613_6(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001726_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_19 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_19 > 26) {
        acc = (acc + anchor_19 * 2 + 5) & 127;
        aux ^= (anchor_19 & 15);
    } else {
        acc = (acc - anchor_19 + 11) & 127;
        aux += 3;
    }
    int parity_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001726_2613_7(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_95 = (aux + st.buffer[1]) & 3;
    switch (anchor_95) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_54 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_54 > 32) {
        acc = (acc + quantum_54 * 2 + 5) & 127;
        aux ^= (quantum_54 & 15);
    } else {
        acc = (acc - quantum_54 + 11) & 127;
        aux += 3;
    }
    int mask_21 = 0;
    for (int k = 0; k < 2; k++) {
        mask_21 = (mask_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001726_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int scale_78 = 0;
    for (int k = 0; k < 3; k++) {
        scale_78 = (scale_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_78) & 127;
    }
    int checksum_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_17) & 63;
    acc ^= aux;
    int phase_23 = (aux + st.buffer[1]) & 3;
    switch (phase_23) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int offset_89 = 0;
    for (int k = 0; k < 3; k++) {
        offset_89 = (offset_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_89) & 127;
    }
    int tracker_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001726_2613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_12 = (aux + st.buffer[1]) & 3;
    switch (stride_12) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_46 = local_arr[aux % 3];
    acc = (acc + offset_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001726_2613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001726_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_31 = 0;
    for (int k = 0; k < 3; k++) {
        residue_31 = (residue_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_31) & 127;
    }
    int stride_92 = (aux + st.buffer[1]) & 3;
    switch (stride_92) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_18 = local_arr[aux % 3];
    acc = (acc + quantum_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001726_2613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int checksum_27 = local_arr[aux % 3];
    acc = (acc + checksum_27 * 2) & 127;
    int threshold_23 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_23 > 33) {
        acc = (acc + threshold_23 * 2 + 5) & 127;
        aux ^= (threshold_23 & 15);
    } else {
        acc = (acc - threshold_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_98) & 63;
    acc ^= aux;
    int threshold_17 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_17 > 16) {
        acc = (acc + threshold_17 * 2 + 5) & 127;
        aux ^= (threshold_17 & 15);
    } else {
        acc = (acc - threshold_17 + 11) & 127;
        aux += 3;
    }
    int quantum_87 = (aux + st.buffer[1]) & 3;
    switch (quantum_87) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001726_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001726_2613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001726_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int segment_23 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_23 > 29) {
        acc = (acc + segment_23 * 2 + 5) & 127;
        aux ^= (segment_23 & 15);
    } else {
        acc = (acc - segment_23 + 11) & 127;
        aux += 3;
    }
    int accumulator_24 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_24 = (accumulator_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_24) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_20 = local_arr[aux % 3];
    acc = (acc + margin_20 * 2) & 127;
    int index_reg_54 = (aux + st.buffer[1]) & 3;
    switch (index_reg_54) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001726_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int parity_81 = (aux + st.buffer[1]) & 3;
    switch (parity_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_52 = local_arr[aux % 3];
    acc = (acc + coefficient_52 * 2) & 127;
    int tally_11 = 0;
    for (int k = 0; k < 2; k++) {
        tally_11 = (tally_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_11) & 127;
    }
    int parity_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001726_2613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001726_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quotient_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_82) & 63;
    acc ^= aux;
    int tally_48 = 0;
    for (int k = 0; k < 2; k++) {
        tally_48 = (tally_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_48) & 127;
    }
    int index_reg_13 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_13 > 18) {
        acc = (acc + index_reg_13 * 2 + 5) & 127;
        aux ^= (index_reg_13 & 15);
    } else {
        acc = (acc - index_reg_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001726_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_42 = local_arr[aux % 3];
    acc = (acc + segment_42 * 2) & 127;
    int segment_42 = 0;
    for (int k = 0; k < 2; k++) {
        segment_42 = (segment_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_19(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001726_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int vector_87 = 0;
    for (int k = 0; k < 3; k++) {
        vector_87 = (vector_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_87) & 127;
    }
    int sample_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001726_2613_20(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_39 = local_arr[aux % 3];
    acc = (acc + tally_39 * 2) & 127;
    int anchor_25 = (aux + st.buffer[1]) & 3;
    switch (anchor_25) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001726_2613_21(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001726_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int window_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_42) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001726_2613_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001726_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001726_0;
    int sec_r001726_1;
    int sec_r001726_2;
    int sec_r001726_3;
    int sec_r001726_4;
    int sec_r001726_5;
    int sec_r001726_6;
    int sec_r001726_7;
    int sec_r001726_8;
    int sec_r001726_9;
    int sec_r001726_10;
    int sec_r001726_11;
    int sec_r001726_12;
    int sec_r001726_13;
    int sec_r001726_14;
    int sec_r001726_15;
    int sec_r001726_16;
    int sec_r001726_17;
    int sec_r001726_18;
    int sec_r001726_19;
    int sec_r001726_20;
    int sec_r001726_21;
    int pub_r001726_0;
    int pub_r001726_1;
    int pub_r001726_2;
    int pub_r001726_3;
    int pub_r001726_4;
    int pub_r001726_5;
    int pub_r001726_6;
    int pub_r001726_7;
    int pub_r001726_8;
    int pub_r001726_9;
    int pub_r001726_10;
    int pub_r001726_11;
    int pub_r001726_12;
    int pub_r001726_13;
    int pub_r001726_14;
    int pub_r001726_15;
    int pub_r001726_16;
    int pub_r001726_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001726_0 >= -100 && pub_r001726_0 <= 100);
    __CPROVER_assume(pub_r001726_1 >= -100 && pub_r001726_1 <= 100);
    __CPROVER_assume(pub_r001726_2 >= -100 && pub_r001726_2 <= 100);
    __CPROVER_assume(pub_r001726_3 >= -100 && pub_r001726_3 <= 100);
    __CPROVER_assume(pub_r001726_4 >= -100 && pub_r001726_4 <= 100);
    __CPROVER_assume(pub_r001726_5 >= -100 && pub_r001726_5 <= 100);
    __CPROVER_assume(pub_r001726_6 >= -100 && pub_r001726_6 <= 100);
    __CPROVER_assume(pub_r001726_7 >= -100 && pub_r001726_7 <= 100);
    __CPROVER_assume(pub_r001726_8 >= -100 && pub_r001726_8 <= 100);
    __CPROVER_assume(pub_r001726_9 >= -100 && pub_r001726_9 <= 100);
    __CPROVER_assume(pub_r001726_10 >= -100 && pub_r001726_10 <= 100);
    __CPROVER_assume(pub_r001726_11 >= -100 && pub_r001726_11 <= 100);
    __CPROVER_assume(pub_r001726_12 >= -100 && pub_r001726_12 <= 100);
    __CPROVER_assume(pub_r001726_13 >= -100 && pub_r001726_13 <= 100);
    __CPROVER_assume(pub_r001726_14 >= -100 && pub_r001726_14 <= 100);
    __CPROVER_assume(pub_r001726_15 >= -100 && pub_r001726_15 <= 100);
    __CPROVER_assume(pub_r001726_16 >= -100 && pub_r001726_16 <= 100);
    __CPROVER_assume(pub_r001726_17 >= -100 && pub_r001726_17 <= 100);
    __CPROVER_assume(sec_r001726_0 >= 0 && sec_r001726_0 <= 255);
    __CPROVER_assume(sec_r001726_1 >= 0 && sec_r001726_1 <= 255);
    __CPROVER_assume(sec_r001726_2 >= 0 && sec_r001726_2 <= 255);
    __CPROVER_assume(sec_r001726_3 >= 0 && sec_r001726_3 <= 255);
    __CPROVER_assume(sec_r001726_4 >= 0 && sec_r001726_4 <= 255);
    __CPROVER_assume(sec_r001726_5 >= 0 && sec_r001726_5 <= 255);
    __CPROVER_assume(sec_r001726_6 >= 0 && sec_r001726_6 <= 255);
    __CPROVER_assume(sec_r001726_7 >= 0 && sec_r001726_7 <= 255);
    __CPROVER_assume(sec_r001726_8 >= 0 && sec_r001726_8 <= 255);
    __CPROVER_assume(sec_r001726_9 >= 0 && sec_r001726_9 <= 255);
    __CPROVER_assume(sec_r001726_10 >= 0 && sec_r001726_10 <= 255);
    __CPROVER_assume(sec_r001726_11 >= 0 && sec_r001726_11 <= 255);
    __CPROVER_assume(sec_r001726_12 >= 0 && sec_r001726_12 <= 255);
    __CPROVER_assume(sec_r001726_13 >= 0 && sec_r001726_13 <= 255);
    __CPROVER_assume(sec_r001726_14 >= 0 && sec_r001726_14 <= 255);
    __CPROVER_assume(sec_r001726_15 >= 0 && sec_r001726_15 <= 255);
    __CPROVER_assume(sec_r001726_16 >= 0 && sec_r001726_16 <= 255);
    __CPROVER_assume(sec_r001726_17 >= 0 && sec_r001726_17 <= 255);
    __CPROVER_assume(sec_r001726_18 >= 0 && sec_r001726_18 <= 255);
    __CPROVER_assume(sec_r001726_19 >= 0 && sec_r001726_19 <= 255);
    __CPROVER_assume(sec_r001726_20 >= 0 && sec_r001726_20 <= 255);
    __CPROVER_assume(sec_r001726_21 >= 0 && sec_r001726_21 <= 255);

    struct Transaction_R001726_2613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001726_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001726_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001726_0 + 7) & 15;
    struct CipherContext_R001726_2613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001726_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001726_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001726_0 + 9) & 15;
    struct EventLog_R001726_2613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001726_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001726_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001726_0 + 11) & 15;
    struct FilterState_R001726_2613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001726_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001726_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001726_0 + 13) & 15;

    union TelemetryField_R001726_2613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001726_2613_0(sec_r001726_0, pub_r001726_1);
    int helper_flow_1 = fn_R001726_2613_1(sec_r001726_1, sec_r001726_2, pub_r001726_3, pub_r001726_4);
    int helper_flow_2 = fn_R001726_2613_2(sec_r001726_2, pub_r001726_3, pub_r001726_4, pub_r001726_5);
    int helper_flow_3 = fn_R001726_2613_3(sec_r001726_3, pub_r001726_4);
    int helper_flow_4 = fn_R001726_2613_4(sec_r001726_4, pub_r001726_5, pub_r001726_6, pub_r001726_7, pub_r001726_8);
    int helper_flow_5 = fn_R001726_2613_5(sec_r001726_5, sec_r001726_6, pub_r001726_7, pub_r001726_8, pub_r001726_9);
    int helper_flow_6 = fn_R001726_2613_6(sec_r001726_6, sec_r001726_7, pub_r001726_8);
    int helper_flow_7 = fn_R001726_2613_7(sec_r001726_7, pub_r001726_8);
    int helper_flow_8 = fn_R001726_2613_8(sec_r001726_8, sec_r001726_9, pub_r001726_10, pub_r001726_11);
    int helper_flow_9 = fn_R001726_2613_9(sec_r001726_9, pub_r001726_10, pub_r001726_11, pub_r001726_12);
    int helper_flow_10 = fn_R001726_2613_10(sec_r001726_10, sec_r001726_11, pub_r001726_12, pub_r001726_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_1 + pub_r001726_8 * 2 + 5) & 127;
    if (stage_v_0 > 38) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001726_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001726_7 + pub_r001726_5 * 2 + 11) & 127;
    if (stage_v_2 > 42) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (stage_v_2 + pub_r001726_6 * 2 + 14) & 127;
    if (stage_v_3 > 18) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001726_8 + pub_r001726_0 * 2 + 17) & 127;
    if (stage_v_4 > 38) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_10 + pub_r001726_0 * 2 + 20) & 127;
    if (stage_v_5 > 34) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001726_7 + pub_r001726_4 * 2 + 23) & 127;
    if (stage_v_6 > 27) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001726_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001726_17 + pub_r001726_10 * 2 + 29) & 127;
    if (stage_v_8 > 20) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_3 + pub_r001726_15 * 2 + 32) & 127;
    if (stage_v_9 > 32) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001726_21 + pub_r001726_3 * 2 + 35) & 127;
    if (stage_v_10 > 57) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_10 + pub_r001726_4 * 2 + 38) & 127;
    if (stage_v_11 > 28) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001726_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_9 + pub_r001726_7 * 2 + 44) & 127;
    if (stage_v_13 > 29) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_7 + pub_r001726_17 * 2 + 47) & 127;
    if (stage_v_14 > 51) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001726_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001726_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001726_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_10 + pub_r001726_3 * 2 + 59) & 127;
    if (stage_v_18 > 26) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_9 + pub_r001726_10 * 2 + 62) & 127;
    if (stage_v_19 > 42) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001726_10 + pub_r001726_1 * 2 + 65) & 127;
    if (stage_v_20 > 26) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001726_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001726_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_8 + pub_r001726_5 * 2 + 74) & 127;
    if (stage_v_23 > 21) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001726_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_4 + pub_r001726_12 * 2 + 80) & 127;
    if (stage_v_25 > 32) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_3 + pub_r001726_6 * 2 + 83) & 127;
    if (stage_v_26 > 51) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_19 + pub_r001726_1 * 2 + 86) & 127;
    if (stage_v_27 > 15) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001726_6 + pub_r001726_17 * 2 + 89) & 127;
    if (stage_v_28 > 42) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_3 + pub_r001726_5 * 2 + 92) & 127;
    if (stage_v_29 > 45) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001726_9 + pub_r001726_15 * 2 + 95) & 127;
    if (stage_v_30 > 51) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_19 + pub_r001726_10 * 2 + 98) & 127;
    if (stage_v_31 > 28) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001726_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001726_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_3 + pub_r001726_0 * 2 + 107) & 127;
    if (stage_v_34 > 49) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001726_14 + pub_r001726_16 * 2 + 110) & 127;
    if (stage_v_35 > 27) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001726_3 + pub_r001726_7 * 2 + 113) & 127;
    if (stage_v_36 > 38) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_30 + pub_r001726_2 * 2 + 116) & 127;
    if (stage_v_37 > 25) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001726_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001726_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001726_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001726_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_10 + pub_r001726_2 * 2 + 131) & 127;
    if (stage_v_42 > 59) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_8 + pub_r001726_15 * 2 + 134) & 127;
    if (stage_v_43 > 52) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001726_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001726_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001726_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001726_1 + pub_r001726_16 * 2 + 146) & 127;
    if (stage_v_47 > 50) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_20 + pub_r001726_12 * 2 + 149) & 127;
    if (stage_v_48 > 45) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001726_20 + pub_r001726_8 * 2 + 152) & 127;
    if (stage_v_49 > 27) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_27 + pub_r001726_17 * 2 + 155) & 127;
    if (stage_v_50 > 42) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001726_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_0 + pub_r001726_15 * 2 + 161) & 127;
    if (stage_v_52 > 46) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_4 + pub_r001726_1 * 2 + 164) & 127;
    if (stage_v_53 > 27) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001726_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001726_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001726_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001726_2 + pub_r001726_17 * 2 + 176) & 127;
    if (stage_v_57 > 36) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001726_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001726_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001726_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_10 + pub_r001726_15 * 2 + 188) & 127;
    if (stage_v_61 > 53) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (helper_flow_5 + pub_r001726_14 * 2 + 191) & 127;
    if (stage_v_62 > 39) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001726_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001726_7 + pub_r001726_1 * 2 + 197) & 127;
    if (stage_v_64 > 48) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001726_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_4 + pub_r001726_1 * 2 + 203) & 127;
    if (stage_v_66 > 49) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_34 + pub_r001726_8 * 2 + 206) & 127;
    if (stage_v_67 > 48) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001726_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001726_8 + pub_r001726_15 * 2 + 212) & 127;
    if (stage_v_69 > 36) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (helper_flow_4 + pub_r001726_16 * 2 + 215) & 127;
    if (stage_v_70 > 29) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_19 + pub_r001726_17 * 2 + 218) & 127;
    if (stage_v_71 > 50) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_0 + pub_r001726_11 * 2 + 221) & 127;
    if (stage_v_72 > 32) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001726_9 + pub_r001726_5 * 2 + 224) & 127;
    if (stage_v_73 > 28) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_10 + pub_r001726_7 * 2 + 227) & 127;
    if (stage_v_74 > 32) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_66 + pub_r001726_1 * 2 + 230) & 127;
    if (stage_v_75 > 24) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001726_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_57 + pub_r001726_9 * 2 + 236) & 127;
    if (stage_v_77 > 41) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_53 + pub_r001726_3 * 2 + 239) & 127;
    if (stage_v_78 > 53) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_64 + pub_r001726_3 * 2 + 242) & 127;
    if (stage_v_79 > 54) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_47 + pub_r001726_17 * 2 + 245) & 127;
    if (stage_v_80 > 16) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (helper_flow_5 + pub_r001726_15 * 2 + 248) & 127;
    if (stage_v_81 > 22) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001726_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (helper_flow_3 + pub_r001726_15 * 2 + 254) & 127;
    if (stage_v_83 > 49) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001726_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001726_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001726_17 + pub_r001726_15 * 2 + 263) & 127;
    if (stage_v_86 > 53) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001726_13 + pub_r001726_15 * 2 + 266) & 127;
    if (stage_v_87 > 18) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001726_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001726_9 + pub_r001726_17 * 2 + 272) & 127;
    if (stage_v_89 > 17) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001726_14 + pub_r001726_17 * 2 + 275) & 127;
    if (stage_v_90 > 45) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001726_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001726_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001726_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_86 + pub_r001726_5 * 2 + 287) & 127;
    if (stage_v_94 > 51) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001726_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001726_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001726_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_30 + pub_r001726_13 * 2 + 299) & 127;
    if (stage_v_98 > 32) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001726_8 + pub_r001726_7 * 2 + 302) & 127;
    if (stage_v_99 > 26) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_4 + pub_r001726_2 * 2 + 305) & 127;
    if (stage_v_100 > 23) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_70 + pub_r001726_17 * 2 + 308) & 127;
    if (stage_v_101 > 54) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001726_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001726_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_14 + pub_r001726_13 * 2 + 317) & 127;
    if (stage_v_104 > 21) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001726_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_19 + pub_r001726_1 * 2 + 323) & 127;
    if (stage_v_106 > 55) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001726_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001726_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_52 + pub_r001726_9 * 2 + 332) & 127;
    if (stage_v_109 > 54) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_75 + pub_r001726_9 * 2 + 335) & 127;
    if (stage_v_110 > 35) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_27 + pub_r001726_4 * 2 + 338) & 127;
    if (stage_v_111 > 41) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001726_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_18 + pub_r001726_15 * 2 + 344) & 127;
    if (stage_v_113 > 44) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001726_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001726_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_99 + pub_r001726_15 * 2 + 353) & 127;
    if (stage_v_116 > 35) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001726_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001726_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_9 + pub_r001726_3 * 2 + 362) & 127;
    if (stage_v_119 > 48) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001726_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_104 + pub_r001726_15 * 2 + 368) & 127;
    if (stage_v_121 > 38) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001726_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001726_18 + pub_r001726_16 * 2 + 374) & 127;
    if (stage_v_123 > 33) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001726_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001726_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001726_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001726_9 + pub_r001726_17 * 2 + 386) & 127;
    if (stage_v_127 > 59) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_48 + pub_r001726_11 * 2 + 389) & 127;
    if (stage_v_128 > 60) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001726_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001726_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_9 + pub_r001726_17 * 2 + 398) & 127;
    if (stage_v_131 > 39) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_36 + pub_r001726_13 * 2 + 401) & 127;
    if (stage_v_132 > 38) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r001726_16 + pub_r001726_0 * 2 + 404) & 127;
    if (stage_v_133 > 24) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_0 + pub_r001726_8 * 2 + 407) & 127;
    if (stage_v_134 > 42) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_123 + pub_r001726_13 * 2 + 410) & 127;
    if (stage_v_135 > 27) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_110 + pub_r001726_10 * 2 + 413) & 127;
    if (stage_v_136 > 29) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_66 + pub_r001726_16 * 2 + 416) & 127;
    if (stage_v_137 > 50) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001726_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_94 + pub_r001726_3 * 2 + 422) & 127;
    if (stage_v_139 > 57) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_131 + pub_r001726_15 * 2 + 425) & 127;
    if (stage_v_140 > 22) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_29 + pub_r001726_7 * 2 + 428) & 127;
    if (stage_v_141 > 46) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001726_16 + pub_r001726_2 * 2 + 431) & 127;
    if (stage_v_142 > 33) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_26 + pub_r001726_12 * 2 + 434) & 127;
    if (stage_v_143 > 28) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001726_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_90 + pub_r001726_2 * 2 + 440) & 127;
    if (stage_v_145 > 49) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001726_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001726_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001726_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001726_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_109 + pub_r001726_3 * 2 + 455) & 127;
    if (stage_v_150 > 47) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_110 + pub_r001726_16 * 2 + 458) & 127;
    if (stage_v_151 > 52) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_34 + pub_r001726_14 * 2 + 461) & 127;
    if (stage_v_152 > 38) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_29 + pub_r001726_3 * 2 + 464) & 127;
    if (stage_v_153 > 18) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001726_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_127 + pub_r001726_6 * 2 + 470) & 127;
    if (stage_v_155 > 23) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001726_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_128 + pub_r001726_3 * 2 + 476) & 127;
    if (stage_v_157 > 32) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_121 + pub_r001726_6 * 2 + 479) & 127;
    if (stage_v_158 > 58) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001726_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r001726_13 + pub_r001726_1 * 2 + 485) & 127;
    if (stage_v_160 > 46) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_2 + pub_r001726_6 * 2 + 488) & 127;
    if (stage_v_161 > 36) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001726_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (sec_r001726_13 + pub_r001726_6 * 2 + 494) & 127;
    if (stage_v_163 > 23) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001726_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001726_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_113 + pub_r001726_2 * 2 + 503) & 127;
    if (stage_v_166 > 45) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001726_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001726_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001726_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_66 + pub_r001726_1 * 2 + 515) & 127;
    if (stage_v_170 > 28) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_153 + pub_r001726_2 * 2 + 518) & 127;
    if (stage_v_171 > 46) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_110 + pub_r001726_0 * 2 + 521) & 127;
    if (stage_v_172 > 33) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (sec_r001726_18 + pub_r001726_4 * 2 + 524) & 127;
    if (stage_v_173 > 37) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_3 + pub_r001726_13 * 2 + 527) & 127;
    if (stage_v_174 > 22) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_75 + pub_r001726_3 * 2 + 530) & 127;
    if (stage_v_175 > 28) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001726_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_175 + pub_r001726_15 * 2 + 536) & 127;
    if (stage_v_177 > 21) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_89 + pub_r001726_0 * 2 + 539) & 127;
    if (stage_v_178 > 20) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001726_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_4 + pub_r001726_3 * 2 + 545) & 127;
    if (stage_v_180 > 26) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001726_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_137 + pub_r001726_9 * 2 + 551) & 127;
    if (stage_v_182 > 55) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_10 + pub_r001726_5 * 2 + 554) & 127;
    if (stage_v_183 > 49) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001726_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r001726_14 + pub_r001726_7 * 2 + 560) & 127;
    if (stage_v_185 > 47) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_131 + pub_r001726_11 * 2 + 563) & 127;
    if (stage_v_186 > 54) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_175 + pub_r001726_0 * 2 + 566) & 127;
    if (stage_v_187 > 54) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_43 + pub_r001726_6 * 2 + 569) & 127;
    if (stage_v_188 > 23) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001726_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (sec_r001726_11 + pub_r001726_12 * 2 + 575) & 127;
    if (stage_v_190 > 37) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_79 + pub_r001726_16 * 2 + 578) & 127;
    if (stage_v_191 > 58) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001726_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001726_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_183 + pub_r001726_4 * 2 + 587) & 127;
    if (stage_v_194 > 45) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001726_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001726_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_13 + pub_r001726_10 * 2 + 596) & 127;
    if (stage_v_197 > 20) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001726_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_36 + pub_r001726_13 * 2 + 602) & 127;
    if (stage_v_199 > 15) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001726_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001726_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001726_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001726_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (helper_flow_9 + pub_r001726_17 * 2 + 617) & 127;
    if (stage_v_204 > 30) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001726_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_136 + pub_r001726_11 * 2 + 623) & 127;
    if (stage_v_206 > 54) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r001726_6 + pub_r001726_11 * 2 + 626) & 127;
    if (stage_v_207 > 43) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_23 + pub_r001726_4 * 2 + 629) & 127;
    if (stage_v_208 > 16) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
