/*
 * Benchmark Program: R001746
 * Security Family: implicit_flow
 * Generator Seed: 674613
 * High Inputs: 16 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001746_4613_0 {
    int timestamp;
    int seq;
    unsigned char code;
    int buffer[3];
};

struct AudioFrame_R001746_4613_1 {
    short peak;
    short gain;
    unsigned char sample_rate;
    unsigned char rms;
    int buffer[3];
};

struct Transaction_R001746_4613_2 {
    unsigned char account_id;
    unsigned char status;
    int fee;
    int rate;
    short balance;
    int auth_code;
    int buffer[3];
};

struct CipherContext_R001746_4613_3 {
    int tag;
    short round_key;
    short nonce;
    int flags;
    int iv;
    int buffer[3];
};

union TelemetryField_R001746_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001746_4613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_42 = 0;
    for (int k = 0; k < 3; k++) {
        mask_42 = (mask_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_42) & 127;
    }
    int anchor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_68 = (aux + st.buffer[1]) & 3;
    switch (sample_68) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_1(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int window_82 = (aux + st.buffer[1]) & 3;
    switch (window_82) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_10 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_10 = (quotient_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_10) & 127;
    }
    int damping_27 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_27 > 31) {
        acc = (acc + damping_27 * 2 + 5) & 127;
        aux ^= (damping_27 & 15);
    } else {
        acc = (acc - damping_27 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_2(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001746_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int anchor_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_36) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_30 = local_arr[aux % 3];
    acc = (acc + sample_30 * 2) & 127;
    int offset_71 = 0;
    for (int k = 0; k < 2; k++) {
        offset_71 = (offset_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_3(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_35 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_35 > 13) {
        acc = (acc + quotient_35 * 2 + 5) & 127;
        aux ^= (quotient_35 & 15);
    } else {
        acc = (acc - quotient_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001746_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_42) & 63;
    acc ^= aux;
    int index_reg_80 = (aux + st.buffer[1]) & 3;
    switch (index_reg_80) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tally_79 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_79 > 35) {
        acc = (acc + tally_79 * 2 + 5) & 127;
        aux ^= (tally_79 & 15);
    } else {
        acc = (acc - tally_79 + 11) & 127;
        aux += 3;
    }
    int vector_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_11) & 63;
    acc ^= aux;
    int checksum_20 = (aux + st.buffer[1]) & 3;
    switch (checksum_20) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001746_4613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_54 = 0;
    for (int k = 0; k < 2; k++) {
        weight_54 = (weight_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_54) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_33 = local_arr[aux % 3];
    acc = (acc + metric_33 * 2) & 127;
    int factor_94 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_94 > 19) {
        acc = (acc + factor_94 * 2 + 5) & 127;
        aux ^= (factor_94 & 15);
    } else {
        acc = (acc - factor_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001746_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_66 = 0;
    for (int k = 0; k < 2; k++) {
        sample_66 = (sample_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_66) & 127;
    }
    int anchor_10 = (aux + st.buffer[1]) & 3;
    switch (anchor_10) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001746_4613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001746_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_20 > 41) {
        acc = (acc + factor_20 * 2 + 5) & 127;
        aux ^= (factor_20 & 15);
    } else {
        acc = (acc - factor_20 + 11) & 127;
        aux += 3;
    }
    int factor_62 = 0;
    for (int k = 0; k < 2; k++) {
        factor_62 = (factor_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_62) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_9(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001746_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_16) & 63;
    acc ^= aux;
    int pivot_31 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_31 = (pivot_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_31) & 127;
    }
    int delta_20 = (aux + st.buffer[1]) & 3;
    switch (delta_20) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_38 = local_arr[aux % 3];
    acc = (acc + tally_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001746_4613_10(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int scale_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_22) & 63;
    acc ^= aux;
    int cursor_35 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_35 = (cursor_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_35) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_77 = (aux + st.buffer[1]) & 3;
    switch (quotient_77) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001746_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int tracker_74 = local_arr[aux % 3];
    acc = (acc + tracker_74 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_58 = 0;
    for (int k = 0; k < 3; k++) {
        delta_58 = (delta_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_58) & 127;
    }
    int cursor_45 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_45 > 48) {
        acc = (acc + cursor_45 * 2 + 5) & 127;
        aux ^= (cursor_45 & 15);
    } else {
        acc = (acc - cursor_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int cursor_67 = (aux + st.buffer[1]) & 3;
    switch (cursor_67) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_23 = local_arr[aux % 3];
    acc = (acc + bound_23 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001746_4613_13(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001746_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int index_reg_61 = local_arr[aux % 3];
    acc = (acc + index_reg_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_60 = (aux + st.buffer[1]) & 3;
    switch (bound_60) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_14(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001746_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int bound_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_60) & 63;
    acc ^= aux;
    int quotient_89 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_89 = (quotient_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_89) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001746_4613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int damping_70 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_70 > 35) {
        acc = (acc + damping_70 * 2 + 5) & 127;
        aux ^= (damping_70 & 15);
    } else {
        acc = (acc - damping_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_80 = local_arr[aux % 3];
    acc = (acc + vector_80 * 2) & 127;
    int scale_65 = (aux + st.buffer[1]) & 3;
    switch (scale_65) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_11 = 0;
    for (int k = 0; k < 3; k++) {
        phase_11 = (phase_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_11) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_16(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_82 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_82 = (quotient_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_82) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001746_4613_17(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quantum_44 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_44 = (quantum_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_44) & 127;
    }
    int coefficient_28 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_28 > 36) {
        acc = (acc + coefficient_28 * 2 + 5) & 127;
        aux ^= (coefficient_28 & 15);
    } else {
        acc = (acc - coefficient_28 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_64 = local_arr[aux % 3];
    acc = (acc + cursor_64 * 2) & 127;
    int checksum_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001746_4613_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001746_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quantum_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_79) & 63;
    acc ^= aux;
    int bound_98 = (aux + st.buffer[1]) & 3;
    switch (bound_98) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int accumulator_18 = (aux + st.buffer[1]) & 3;
    switch (accumulator_18) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_53 = local_arr[aux % 3];
    acc = (acc + factor_53 * 2) & 127;
    int anchor_34 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_34 = (anchor_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_34) & 127;
    }
    int mask_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001746_4613_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001746_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int stride_79 = local_arr[aux % 3];
    acc = (acc + stride_79 * 2) & 127;
    int weight_65 = 0;
    for (int k = 0; k < 2; k++) {
        weight_65 = (weight_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_65) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_23 = (aux + st.buffer[1]) & 3;
    switch (index_reg_23) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001746_4613_21(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001746_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int sample_49 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_49 > 19) {
        acc = (acc + sample_49 * 2 + 5) & 127;
        aux ^= (sample_49 & 15);
    } else {
        acc = (acc - sample_49 + 11) & 127;
        aux += 3;
    }
    int residue_72 = (aux + st.buffer[1]) & 3;
    switch (residue_72) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001746_4613_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001746_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quantum_31 = (aux + st.buffer[1]) & 3;
    switch (quantum_31) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_32 = local_arr[aux % 3];
    acc = (acc + parity_32 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001746_0;
    int sec_r001746_1;
    int sec_r001746_2;
    int sec_r001746_3;
    int sec_r001746_4;
    int sec_r001746_5;
    int sec_r001746_6;
    int sec_r001746_7;
    int sec_r001746_8;
    int sec_r001746_9;
    int sec_r001746_10;
    int sec_r001746_11;
    int sec_r001746_12;
    int sec_r001746_13;
    int sec_r001746_14;
    int sec_r001746_15;
    int pub_r001746_0;
    int pub_r001746_1;
    int pub_r001746_2;
    int pub_r001746_3;
    int pub_r001746_4;
    int pub_r001746_5;
    int pub_r001746_6;
    int pub_r001746_7;
    int pub_r001746_8;
    int pub_r001746_9;
    int pub_r001746_10;
    int pub_r001746_11;
    int pub_r001746_12;
    int pub_r001746_13;
    int pub_r001746_14;
    int pub_r001746_15;
    int pub_r001746_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001746_0 >= -100 && pub_r001746_0 <= 100);
    __CPROVER_assume(pub_r001746_1 >= -100 && pub_r001746_1 <= 100);
    __CPROVER_assume(pub_r001746_2 >= -100 && pub_r001746_2 <= 100);
    __CPROVER_assume(pub_r001746_3 >= -100 && pub_r001746_3 <= 100);
    __CPROVER_assume(pub_r001746_4 >= -100 && pub_r001746_4 <= 100);
    __CPROVER_assume(pub_r001746_5 >= -100 && pub_r001746_5 <= 100);
    __CPROVER_assume(pub_r001746_6 >= -100 && pub_r001746_6 <= 100);
    __CPROVER_assume(pub_r001746_7 >= -100 && pub_r001746_7 <= 100);
    __CPROVER_assume(pub_r001746_8 >= -100 && pub_r001746_8 <= 100);
    __CPROVER_assume(pub_r001746_9 >= -100 && pub_r001746_9 <= 100);
    __CPROVER_assume(pub_r001746_10 >= -100 && pub_r001746_10 <= 100);
    __CPROVER_assume(pub_r001746_11 >= -100 && pub_r001746_11 <= 100);
    __CPROVER_assume(pub_r001746_12 >= -100 && pub_r001746_12 <= 100);
    __CPROVER_assume(pub_r001746_13 >= -100 && pub_r001746_13 <= 100);
    __CPROVER_assume(pub_r001746_14 >= -100 && pub_r001746_14 <= 100);
    __CPROVER_assume(pub_r001746_15 >= -100 && pub_r001746_15 <= 100);
    __CPROVER_assume(pub_r001746_16 >= -100 && pub_r001746_16 <= 100);
    __CPROVER_assume(sec_r001746_0 >= 0 && sec_r001746_0 <= 255);
    __CPROVER_assume(sec_r001746_1 >= 0 && sec_r001746_1 <= 255);
    __CPROVER_assume(sec_r001746_2 >= 0 && sec_r001746_2 <= 255);
    __CPROVER_assume(sec_r001746_3 >= 0 && sec_r001746_3 <= 255);
    __CPROVER_assume(sec_r001746_4 >= 0 && sec_r001746_4 <= 255);
    __CPROVER_assume(sec_r001746_5 >= 0 && sec_r001746_5 <= 255);
    __CPROVER_assume(sec_r001746_6 >= 0 && sec_r001746_6 <= 255);
    __CPROVER_assume(sec_r001746_7 >= 0 && sec_r001746_7 <= 255);
    __CPROVER_assume(sec_r001746_8 >= 0 && sec_r001746_8 <= 255);
    __CPROVER_assume(sec_r001746_9 >= 0 && sec_r001746_9 <= 255);
    __CPROVER_assume(sec_r001746_10 >= 0 && sec_r001746_10 <= 255);
    __CPROVER_assume(sec_r001746_11 >= 0 && sec_r001746_11 <= 255);
    __CPROVER_assume(sec_r001746_12 >= 0 && sec_r001746_12 <= 255);
    __CPROVER_assume(sec_r001746_13 >= 0 && sec_r001746_13 <= 255);
    __CPROVER_assume(sec_r001746_14 >= 0 && sec_r001746_14 <= 255);
    __CPROVER_assume(sec_r001746_15 >= 0 && sec_r001746_15 <= 255);

    struct EventLog_R001746_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001746_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001746_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001746_0 + 7) & 15;
    struct AudioFrame_R001746_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001746_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001746_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001746_0 + 9) & 15;
    struct Transaction_R001746_4613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001746_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001746_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001746_0 + 11) & 15;
    struct CipherContext_R001746_4613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001746_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001746_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001746_0 + 13) & 15;

    union TelemetryField_R001746_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001746_4613_0(sec_r001746_0, pub_r001746_1, pub_r001746_2, pub_r001746_3);
    int helper_flow_1 = fn_R001746_4613_1(sec_r001746_1, sec_r001746_2, pub_r001746_3);
    int helper_flow_2 = fn_R001746_4613_2(sec_r001746_2, pub_r001746_3, pub_r001746_4);
    int helper_flow_3 = fn_R001746_4613_3(sec_r001746_3, sec_r001746_4, pub_r001746_5);
    int helper_flow_4 = fn_R001746_4613_4(sec_r001746_4, pub_r001746_5, pub_r001746_6, pub_r001746_7, pub_r001746_8);
    int helper_flow_5 = fn_R001746_4613_5(sec_r001746_5, sec_r001746_6, pub_r001746_7, pub_r001746_8, pub_r001746_9);
    int helper_flow_6 = fn_R001746_4613_6(sec_r001746_6, sec_r001746_7, pub_r001746_8, pub_r001746_9, pub_r001746_10);
    int helper_flow_7 = fn_R001746_4613_7(sec_r001746_7, pub_r001746_8, pub_r001746_9, pub_r001746_10);
    int helper_flow_8 = fn_R001746_4613_8(sec_r001746_8, sec_r001746_9, pub_r001746_10, pub_r001746_11, pub_r001746_12);
    int helper_flow_9 = fn_R001746_4613_9(sec_r001746_9, sec_r001746_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001746_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001746_15 + pub_r001746_15 * 2 + 8) & 127;
    if (stage_v_1 > 18) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001746_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001746_11 + pub_r001746_16 * 2 + 14) & 127;
    if (stage_v_3 > 16) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_6 + pub_r001746_4 * 2 + 17) & 127;
    if (stage_v_4 > 33) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001746_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001746_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001746_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001746_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001746_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001746_12 + pub_r001746_4 * 2 + 35) & 127;
    if (stage_v_10 > 52) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_1 + pub_r001746_15 * 2 + 38) & 127;
    if (stage_v_11 > 32) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_7 + pub_r001746_7 * 2 + 41) & 127;
    if (stage_v_12 > 54) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001746_0 + pub_r001746_11 * 2 + 44) & 127;
    if (stage_v_13 > 57) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001746_7 + pub_r001746_0 * 2 + 47) & 127;
    if (stage_v_14 > 39) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_12 + pub_r001746_1 * 2 + 50) & 127;
    if (stage_v_15 > 28) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001746_13 + pub_r001746_3 * 2 + 53) & 127;
    if (stage_v_16 > 54) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001746_11 + pub_r001746_9 * 2 + 56) & 127;
    if (stage_v_17 > 20) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001746_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001746_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_8 + pub_r001746_9 * 2 + 65) & 127;
    if (stage_v_20 > 22) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001746_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001746_0 + pub_r001746_3 * 2 + 71) & 127;
    if (stage_v_22 > 29) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_4 + pub_r001746_0 * 2 + 74) & 127;
    if (stage_v_23 > 47) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001746_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001746_4 + pub_r001746_1 * 2 + 80) & 127;
    if (stage_v_25 > 38) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001746_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001746_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001746_9 + pub_r001746_0 * 2 + 89) & 127;
    if (stage_v_28 > 23) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001746_5 + pub_r001746_1 * 2 + 92) & 127;
    if (stage_v_29 > 33) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001746_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_1 + pub_r001746_6 * 2 + 98) & 127;
    if (stage_v_31 > 60) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001746_6 + pub_r001746_1 * 2 + 101) & 127;
    if (stage_v_32 > 20) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_17 + pub_r001746_10 * 2 + 104) & 127;
    if (stage_v_33 > 41) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_9 + pub_r001746_5 * 2 + 107) & 127;
    if (stage_v_34 > 28) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001746_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_32 + pub_r001746_12 * 2 + 113) & 127;
    if (stage_v_36 > 46) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001746_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001746_14 + pub_r001746_14 * 2 + 119) & 127;
    if (stage_v_38 > 15) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001746_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001746_15 + pub_r001746_10 * 2 + 125) & 127;
    if (stage_v_40 > 42) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_17 + pub_r001746_4 * 2 + 128) & 127;
    if (stage_v_41 > 22) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_4 + pub_r001746_2 * 2 + 131) & 127;
    if (stage_v_42 > 28) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_1 + pub_r001746_14 * 2 + 134) & 127;
    if (stage_v_43 > 56) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_9 + pub_r001746_7 * 2 + 137) & 127;
    if (stage_v_44 > 35) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_0 + pub_r001746_7 * 2 + 140) & 127;
    if (stage_v_45 > 40) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_22 + pub_r001746_13 * 2 + 143) & 127;
    if (stage_v_46 > 33) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001746_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_4 + pub_r001746_16 * 2 + 149) & 127;
    if (stage_v_48 > 15) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_48 + pub_r001746_2 * 2 + 152) & 127;
    if (stage_v_49 > 30) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_23 + pub_r001746_15 * 2 + 155) & 127;
    if (stage_v_50 > 29) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001746_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001746_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001746_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001746_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_9 + pub_r001746_16 * 2 + 170) & 127;
    if (stage_v_55 > 17) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001746_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_50 + pub_r001746_2 * 2 + 176) & 127;
    if (stage_v_57 > 48) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001746_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_57 + pub_r001746_12 * 2 + 182) & 127;
    if (stage_v_59 > 38) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_49 + pub_r001746_13 * 2 + 185) & 127;
    if (stage_v_60 > 50) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_38 + pub_r001746_8 * 2 + 188) & 127;
    if (stage_v_61 > 57) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (helper_flow_2 + pub_r001746_16 * 2 + 191) & 127;
    if (stage_v_62 > 15) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001746_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001746_3 + pub_r001746_12 * 2 + 197) & 127;
    if (stage_v_64 > 54) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_3 + pub_r001746_3 * 2 + 200) & 127;
    if (stage_v_65 > 57) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_3 + pub_r001746_13 * 2 + 203) & 127;
    if (stage_v_66 > 27) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_60 + pub_r001746_7 * 2 + 206) & 127;
    if (stage_v_67 > 37) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_41 + pub_r001746_10 * 2 + 209) & 127;
    if (stage_v_68 > 15) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001746_1 + pub_r001746_0 * 2 + 212) & 127;
    if (stage_v_69 > 39) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001746_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_65 + pub_r001746_0 * 2 + 218) & 127;
    if (stage_v_71 > 41) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_48 + pub_r001746_15 * 2 + 221) & 127;
    if (stage_v_72 > 26) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001746_9 + pub_r001746_1 * 2 + 224) & 127;
    if (stage_v_73 > 15) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_62 + pub_r001746_3 * 2 + 227) & 127;
    if (stage_v_74 > 31) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001746_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_48 + pub_r001746_8 * 2 + 233) & 127;
    if (stage_v_76 > 31) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001746_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_57 + pub_r001746_8 * 2 + 239) & 127;
    if (stage_v_78 > 56) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001746_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_25 + pub_r001746_2 * 2 + 245) & 127;
    if (stage_v_80 > 33) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001746_13 + pub_r001746_5 * 2 + 248) & 127;
    if (stage_v_81 > 41) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001746_14 + pub_r001746_0 * 2 + 251) & 127;
    if (stage_v_82 > 19) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (helper_flow_8 + pub_r001746_11 * 2 + 254) & 127;
    if (stage_v_83 > 40) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001746_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_29 + pub_r001746_0 * 2 + 260) & 127;
    if (stage_v_85 > 51) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_85 + pub_r001746_14 * 2 + 263) & 127;
    if (stage_v_86 > 27) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (helper_flow_1 + pub_r001746_11 * 2 + 266) & 127;
    if (stage_v_87 > 27) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001746_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001746_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001746_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001746_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r001746_15 + pub_r001746_9 * 2 + 281) & 127;
    if (stage_v_92 > 21) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001746_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_14 + pub_r001746_12 * 2 + 287) & 127;
    if (stage_v_94 > 41) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_10 + pub_r001746_3 * 2 + 290) & 127;
    if (stage_v_95 > 25) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001746_9 + pub_r001746_6 * 2 + 293) & 127;
    if (stage_v_96 > 23) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_95 + pub_r001746_7 * 2 + 296) & 127;
    if (stage_v_97 > 20) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001746_11 + pub_r001746_12 * 2 + 299) & 127;
    if (stage_v_98 > 57) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_28 + pub_r001746_2 * 2 + 302) & 127;
    if (stage_v_99 > 35) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_15 + pub_r001746_7 * 2 + 305) & 127;
    if (stage_v_100 > 30) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_12 + pub_r001746_8 * 2 + 308) & 127;
    if (stage_v_101 > 15) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001746_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001746_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001746_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001746_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_22 + pub_r001746_5 * 2 + 323) & 127;
    if (stage_v_106 > 47) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_92 + pub_r001746_9 * 2 + 326) & 127;
    if (stage_v_107 > 25) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_22 + pub_r001746_7 * 2 + 329) & 127;
    if (stage_v_108 > 31) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_15 + pub_r001746_12 * 2 + 332) & 127;
    if (stage_v_109 > 22) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (helper_flow_2 + pub_r001746_1 * 2 + 335) & 127;
    if (stage_v_110 > 29) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_106 + pub_r001746_11 * 2 + 338) & 127;
    if (stage_v_111 > 29) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_4 + pub_r001746_0 * 2 + 341) & 127;
    if (stage_v_112 > 49) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_40 + pub_r001746_14 * 2 + 344) & 127;
    if (stage_v_113 > 24) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_65 + pub_r001746_8 * 2 + 347) & 127;
    if (stage_v_114 > 56) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001746_6 + pub_r001746_15 * 2 + 350) & 127;
    if (stage_v_115 > 28) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (helper_flow_4 + pub_r001746_4 * 2 + 353) & 127;
    if (stage_v_116 > 59) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001746_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_10 + pub_r001746_13 * 2 + 359) & 127;
    if (stage_v_118 > 43) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_83 + pub_r001746_10 * 2 + 362) & 127;
    if (stage_v_119 > 48) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_15 + pub_r001746_15 * 2 + 365) & 127;
    if (stage_v_120 > 43) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001746_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_100 + pub_r001746_2 * 2 + 371) & 127;
    if (stage_v_122 > 16) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_109 + pub_r001746_15 * 2 + 374) & 127;
    if (stage_v_123 > 29) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001746_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_122 + pub_r001746_7 * 2 + 380) & 127;
    if (stage_v_125 > 26) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_59 + pub_r001746_11 * 2 + 383) & 127;
    if (stage_v_126 > 52) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_13 + pub_r001746_10 * 2 + 386) & 127;
    if (stage_v_127 > 47) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (helper_flow_5 + pub_r001746_16 * 2 + 389) & 127;
    if (stage_v_128 > 46) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001746_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001746_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_55 + pub_r001746_2 * 2 + 398) & 127;
    if (stage_v_131 > 33) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001746_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_40 + pub_r001746_13 * 2 + 404) & 127;
    if (stage_v_133 > 39) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001746_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_97 + pub_r001746_5 * 2 + 410) & 127;
    if (stage_v_135 > 25) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001746_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001746_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001746_7 + pub_r001746_12 * 2 + 419) & 127;
    if (stage_v_138 > 40) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001746_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001746_13 + pub_r001746_2 * 2 + 425) & 127;
    if (stage_v_140 > 38) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001746_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_42 + pub_r001746_8 * 2 + 431) & 127;
    if (stage_v_142 > 46) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001746_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_125 + pub_r001746_7 * 2 + 437) & 127;
    if (stage_v_144 > 42) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_86 + pub_r001746_1 * 2 + 440) & 127;
    if (stage_v_145 > 16) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_33 + pub_r001746_16 * 2 + 443) & 127;
    if (stage_v_146 > 16) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_43 + pub_r001746_0 * 2 + 446) & 127;
    if (stage_v_147 > 55) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001746_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (helper_flow_2 + pub_r001746_10 * 2 + 452) & 127;
    if (stage_v_149 > 47) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_86 + pub_r001746_4 * 2 + 455) & 127;
    if (stage_v_150 > 34) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001746_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (helper_flow_2 + pub_r001746_0 * 2 + 461) & 127;
    if (stage_v_152 > 55) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001746_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_22 + pub_r001746_1 * 2 + 467) & 127;
    if (stage_v_154 > 25) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_86 + pub_r001746_1 * 2 + 470) & 127;
    if (stage_v_155 > 37) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001746_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001746_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_64 + pub_r001746_6 * 2 + 479) & 127;
    if (stage_v_158 > 43) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (helper_flow_7 + pub_r001746_14 * 2 + 482) & 127;
    if (stage_v_159 > 52) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_118 + pub_r001746_8 * 2 + 485) & 127;
    if (stage_v_160 > 17) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_46 + pub_r001746_6 * 2 + 488) & 127;
    if (stage_v_161 > 23) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_20 + pub_r001746_1 * 2 + 491) & 127;
    if (stage_v_162 > 42) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (helper_flow_6 + pub_r001746_8 * 2 + 494) & 127;
    if (stage_v_163 > 36) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001746_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_15 + pub_r001746_0 * 2 + 500) & 127;
    if (stage_v_165 > 53) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001746_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001746_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_85 + pub_r001746_12 * 2 + 509) & 127;
    if (stage_v_168 > 58) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_80 + pub_r001746_2 * 2 + 512) & 127;
    if (stage_v_169 > 48) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001746_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001746_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_120 + pub_r001746_7 * 2 + 521) & 127;
    if (stage_v_172 > 26) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001746_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_69 + pub_r001746_3 * 2 + 527) & 127;
    if (stage_v_174 > 19) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_59 + pub_r001746_4 * 2 + 530) & 127;
    if (stage_v_175 > 56) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_43 + pub_r001746_15 * 2 + 533) & 127;
    if (stage_v_176 > 35) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_112 + pub_r001746_3 * 2 + 536) & 127;
    if (stage_v_177 > 16) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001746_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001746_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_98 + pub_r001746_3 * 2 + 545) & 127;
    if (stage_v_180 > 47) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_116 + pub_r001746_3 * 2 + 548) & 127;
    if (stage_v_181 > 26) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001746_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_162 + pub_r001746_14 * 2 + 554) & 127;
    if (stage_v_183 > 23) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_31 + pub_r001746_12 * 2 + 557) & 127;
    if (stage_v_184 > 39) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_118 + pub_r001746_6 * 2 + 560) & 127;
    if (stage_v_185 > 54) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001746_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_177 + pub_r001746_0 * 2 + 566) & 127;
    if (stage_v_187 > 59) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_144 + pub_r001746_5 * 2 + 569) & 127;
    if (stage_v_188 > 27) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (helper_flow_4 + pub_r001746_3 * 2 + 572) & 127;
    if (stage_v_189 > 37) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_149 + pub_r001746_13 * 2 + 575) & 127;
    if (stage_v_190 > 20) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (sec_r001746_15 + pub_r001746_8 * 2 + 578) & 127;
    if (stage_v_191 > 55) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001746_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001746_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_4 + pub_r001746_13 * 2 + 587) & 127;
    if (stage_v_194 > 53) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_194 + pub_r001746_15 * 2 + 590) & 127;
    if (stage_v_195 > 27) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_11 + pub_r001746_16 * 2 + 593) & 127;
    if (stage_v_196 > 53) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001746_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (sec_r001746_4 + pub_r001746_11 * 2 + 599) & 127;
    if (stage_v_198 > 46) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_133 + pub_r001746_16 * 2 + 602) & 127;
    if (stage_v_199 > 23) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_150 + pub_r001746_10 * 2 + 605) & 127;
    if (stage_v_200 > 48) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001746_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
