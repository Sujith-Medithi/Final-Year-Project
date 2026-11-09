/*
 * Benchmark Program: R001900
 * Security Family: mixed_control_data
 * Generator Seed: 690013
 * High Inputs: 23 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001900_13_0 {
    unsigned char head;
    unsigned char state;
    short tail;
    unsigned char watermark;
    int checksum;
    int capacity;
    int buffer[3];
};

struct CipherContext_R001900_13_1 {
    int iv;
    int tag;
    int nonce;
    int counter;
    int round_key;
    int flags;
    int buffer[3];
};

struct FilterState_R001900_13_2 {
    short gain_db;
    short mode;
    int prev_out;
    unsigned char damping;
    int cutoff;
    int prev_in;
    int buffer[3];
};

union PacketPayload_R001900_13_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001900_13_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001900_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_21) & 63;
    acc ^= aux;
    int coefficient_92 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_92 > 10) {
        acc = (acc + coefficient_92 * 2 + 5) & 127;
        aux ^= (coefficient_92 & 15);
    } else {
        acc = (acc - coefficient_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_57 = local_arr[aux % 3];
    acc = (acc + segment_57 * 2) & 127;
    int delta_55 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_55 > 43) {
        acc = (acc + delta_55 * 2 + 5) & 127;
        aux ^= (delta_55 & 15);
    } else {
        acc = (acc - delta_55 + 11) & 127;
        aux += 3;
    }
    int mask_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001900_13_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001900_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int cursor_71 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_71 = (cursor_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_71) & 127;
    }
    int damping_64 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_64 > 22) {
        acc = (acc + damping_64 * 2 + 5) & 127;
        aux ^= (damping_64 & 15);
    } else {
        acc = (acc - damping_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_41 = local_arr[aux % 3];
    acc = (acc + margin_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_3(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001900_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int factor_32 = local_arr[aux % 3];
    acc = (acc + factor_32 * 2) & 127;
    int threshold_40 = (aux + st.buffer[1]) & 3;
    switch (threshold_40) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_21 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_21 > 47) {
        acc = (acc + factor_21 * 2 + 5) & 127;
        aux ^= (factor_21 & 15);
    } else {
        acc = (acc - factor_21 + 11) & 127;
        aux += 3;
    }
    int anchor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001900_13_4(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quotient_97 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_97 > 36) {
        acc = (acc + quotient_97 * 2 + 5) & 127;
        aux ^= (quotient_97 & 15);
    } else {
        acc = (acc - quotient_97 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_57 = local_arr[aux % 3];
    acc = (acc + index_reg_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int threshold_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_23) & 63;
    acc ^= aux;
    int scale_55 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_55 > 31) {
        acc = (acc + scale_55 * 2 + 5) & 127;
        aux ^= (scale_55 & 15);
    } else {
        acc = (acc - scale_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_18 = local_arr[aux % 3];
    acc = (acc + index_reg_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_6(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int scale_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_96 = local_arr[aux % 3];
    acc = (acc + bound_96 * 2) & 127;
    int quotient_19 = (aux + st.buffer[1]) & 3;
    switch (quotient_19) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_7(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int index_reg_86 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_86 > 33) {
        acc = (acc + index_reg_86 * 2 + 5) & 127;
        aux ^= (index_reg_86 & 15);
    } else {
        acc = (acc - index_reg_86 + 11) & 127;
        aux += 3;
    }
    int tracker_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_57) & 63;
    acc ^= aux;
    int bound_25 = 0;
    for (int k = 0; k < 2; k++) {
        bound_25 = (bound_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_25) & 127;
    }
    int residue_63 = (aux + st.buffer[1]) & 3;
    switch (residue_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001900_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_27) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_98 = local_arr[aux % 3];
    acc = (acc + phase_98 * 2) & 127;
    int metric_33 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_33 > 42) {
        acc = (acc + metric_33 * 2 + 5) & 127;
        aux ^= (metric_33 & 15);
    } else {
        acc = (acc - metric_33 + 11) & 127;
        aux += 3;
    }
    int tracker_64 = (aux + st.buffer[1]) & 3;
    switch (tracker_64) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_9(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001900_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int mask_88 = 0;
    for (int k = 0; k < 3; k++) {
        mask_88 = (mask_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_88) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_89 = local_arr[aux % 3];
    acc = (acc + cursor_89 * 2) & 127;
    int accumulator_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001900_13_10(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001900_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_34 = (aux + st.buffer[1]) & 3;
    switch (metric_34) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_92 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_92 > 25) {
        acc = (acc + tally_92 * 2 + 5) & 127;
        aux ^= (tally_92 & 15);
    } else {
        acc = (acc - tally_92 + 11) & 127;
        aux += 3;
    }
    int anchor_89 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_89 = (anchor_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_89) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_11(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_78 = 0;
    for (int k = 0; k < 3; k++) {
        delta_78 = (delta_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_78) & 127;
    }
    int tracker_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_68) & 63;
    acc ^= aux;
    int threshold_64 = (aux + st.buffer[1]) & 3;
    switch (threshold_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_97 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_97 > 17) {
        acc = (acc + stride_97 * 2 + 5) & 127;
        aux ^= (stride_97 & 15);
    } else {
        acc = (acc - stride_97 + 11) & 127;
        aux += 3;
    }
    int phase_84 = 0;
    for (int k = 0; k < 3; k++) {
        phase_84 = (phase_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_84) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_21 = local_arr[aux % 3];
    acc = (acc + offset_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001900_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_86) & 63;
    acc ^= aux;
    int anchor_16 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_16 = (anchor_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_16) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_26 = local_arr[aux % 3];
    acc = (acc + metric_26 * 2) & 127;
    int offset_82 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_82 > 42) {
        acc = (acc + offset_82 * 2 + 5) & 127;
        aux ^= (offset_82 & 15);
    } else {
        acc = (acc - offset_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001900_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int vector_85 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_85 > 38) {
        acc = (acc + vector_85 * 2 + 5) & 127;
        aux ^= (vector_85 & 15);
    } else {
        acc = (acc - vector_85 + 11) & 127;
        aux += 3;
    }
    int margin_50 = (aux + st.buffer[1]) & 3;
    switch (margin_50) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int accumulator_82 = (aux + st.buffer[1]) & 3;
    switch (accumulator_82) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_16(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_47 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_47 > 37) {
        acc = (acc + metric_47 * 2 + 5) & 127;
        aux ^= (metric_47 & 15);
    } else {
        acc = (acc - metric_47 + 11) & 127;
        aux += 3;
    }
    int anchor_12 = (aux + st.buffer[1]) & 3;
    switch (anchor_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_17(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001900_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int delta_37 = local_arr[aux % 3];
    acc = (acc + delta_37 * 2) & 127;
    int accumulator_39 = (aux + st.buffer[1]) & 3;
    switch (accumulator_39) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int threshold_58 = local_arr[aux % 3];
    acc = (acc + threshold_58 * 2) & 127;
    int margin_72 = (aux + st.buffer[1]) & 3;
    switch (margin_72) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001900_13_19(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int anchor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_79 > 40) {
        acc = (acc + anchor_79 * 2 + 5) & 127;
        aux ^= (anchor_79 & 15);
    } else {
        acc = (acc - anchor_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_18 = local_arr[aux % 3];
    acc = (acc + margin_18 * 2) & 127;
    int scale_77 = (aux + st.buffer[1]) & 3;
    switch (scale_77) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001900_13_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001900_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int accumulator_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_69) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_10 = (aux + st.buffer[1]) & 3;
    switch (vector_10) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_62 = local_arr[aux % 3];
    acc = (acc + index_reg_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_21(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001900_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int vector_62 = local_arr[aux % 3];
    acc = (acc + vector_62 * 2) & 127;
    int index_reg_27 = (aux + st.buffer[1]) & 3;
    switch (index_reg_27) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001900_13_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001900_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_95 = local_arr[aux % 3];
    acc = (acc + vector_95 * 2) & 127;
    int window_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_90) & 63;
    acc ^= aux;
    int quotient_49 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_49 = (quotient_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_49) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001900_0;
    int sec_r001900_1;
    int sec_r001900_2;
    int sec_r001900_3;
    int sec_r001900_4;
    int sec_r001900_5;
    int sec_r001900_6;
    int sec_r001900_7;
    int sec_r001900_8;
    int sec_r001900_9;
    int sec_r001900_10;
    int sec_r001900_11;
    int sec_r001900_12;
    int sec_r001900_13;
    int sec_r001900_14;
    int sec_r001900_15;
    int sec_r001900_16;
    int sec_r001900_17;
    int sec_r001900_18;
    int sec_r001900_19;
    int sec_r001900_20;
    int sec_r001900_21;
    int sec_r001900_22;
    int pub_r001900_0;
    int pub_r001900_1;
    int pub_r001900_2;
    int pub_r001900_3;
    int pub_r001900_4;
    int pub_r001900_5;
    int pub_r001900_6;
    int pub_r001900_7;
    int pub_r001900_8;
    int pub_r001900_9;
    int pub_r001900_10;
    int pub_r001900_11;
    int pub_r001900_12;
    int pub_r001900_13;
    int pub_r001900_14;
    int pub_r001900_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001900_0 >= -100 && pub_r001900_0 <= 100);
    __CPROVER_assume(pub_r001900_1 >= -100 && pub_r001900_1 <= 100);
    __CPROVER_assume(pub_r001900_2 >= -100 && pub_r001900_2 <= 100);
    __CPROVER_assume(pub_r001900_3 >= -100 && pub_r001900_3 <= 100);
    __CPROVER_assume(pub_r001900_4 >= -100 && pub_r001900_4 <= 100);
    __CPROVER_assume(pub_r001900_5 >= -100 && pub_r001900_5 <= 100);
    __CPROVER_assume(pub_r001900_6 >= -100 && pub_r001900_6 <= 100);
    __CPROVER_assume(pub_r001900_7 >= -100 && pub_r001900_7 <= 100);
    __CPROVER_assume(pub_r001900_8 >= -100 && pub_r001900_8 <= 100);
    __CPROVER_assume(pub_r001900_9 >= -100 && pub_r001900_9 <= 100);
    __CPROVER_assume(pub_r001900_10 >= -100 && pub_r001900_10 <= 100);
    __CPROVER_assume(pub_r001900_11 >= -100 && pub_r001900_11 <= 100);
    __CPROVER_assume(pub_r001900_12 >= -100 && pub_r001900_12 <= 100);
    __CPROVER_assume(pub_r001900_13 >= -100 && pub_r001900_13 <= 100);
    __CPROVER_assume(pub_r001900_14 >= -100 && pub_r001900_14 <= 100);
    __CPROVER_assume(pub_r001900_15 >= -100 && pub_r001900_15 <= 100);
    __CPROVER_assume(sec_r001900_0 >= 0 && sec_r001900_0 <= 255);
    __CPROVER_assume(sec_r001900_1 >= 0 && sec_r001900_1 <= 255);
    __CPROVER_assume(sec_r001900_2 >= 0 && sec_r001900_2 <= 255);
    __CPROVER_assume(sec_r001900_3 >= 0 && sec_r001900_3 <= 255);
    __CPROVER_assume(sec_r001900_4 >= 0 && sec_r001900_4 <= 255);
    __CPROVER_assume(sec_r001900_5 >= 0 && sec_r001900_5 <= 255);
    __CPROVER_assume(sec_r001900_6 >= 0 && sec_r001900_6 <= 255);
    __CPROVER_assume(sec_r001900_7 >= 0 && sec_r001900_7 <= 255);
    __CPROVER_assume(sec_r001900_8 >= 0 && sec_r001900_8 <= 255);
    __CPROVER_assume(sec_r001900_9 >= 0 && sec_r001900_9 <= 255);
    __CPROVER_assume(sec_r001900_10 >= 0 && sec_r001900_10 <= 255);
    __CPROVER_assume(sec_r001900_11 >= 0 && sec_r001900_11 <= 255);
    __CPROVER_assume(sec_r001900_12 >= 0 && sec_r001900_12 <= 255);
    __CPROVER_assume(sec_r001900_13 >= 0 && sec_r001900_13 <= 255);
    __CPROVER_assume(sec_r001900_14 >= 0 && sec_r001900_14 <= 255);
    __CPROVER_assume(sec_r001900_15 >= 0 && sec_r001900_15 <= 255);
    __CPROVER_assume(sec_r001900_16 >= 0 && sec_r001900_16 <= 255);
    __CPROVER_assume(sec_r001900_17 >= 0 && sec_r001900_17 <= 255);
    __CPROVER_assume(sec_r001900_18 >= 0 && sec_r001900_18 <= 255);
    __CPROVER_assume(sec_r001900_19 >= 0 && sec_r001900_19 <= 255);
    __CPROVER_assume(sec_r001900_20 >= 0 && sec_r001900_20 <= 255);
    __CPROVER_assume(sec_r001900_21 >= 0 && sec_r001900_21 <= 255);
    __CPROVER_assume(sec_r001900_22 >= 0 && sec_r001900_22 <= 255);

    struct StreamBuffer_R001900_13_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001900_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001900_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001900_0 + 7) & 15;
    struct CipherContext_R001900_13_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001900_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001900_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001900_0 + 9) & 15;
    struct FilterState_R001900_13_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001900_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001900_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001900_0 + 11) & 15;

    union PacketPayload_R001900_13_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001900_13_0(sec_r001900_0, pub_r001900_1, pub_r001900_2, pub_r001900_3);
    int helper_flow_1 = fn_R001900_13_1(sec_r001900_1, pub_r001900_2, pub_r001900_3, pub_r001900_4, pub_r001900_5);
    int helper_flow_2 = fn_R001900_13_2(sec_r001900_2, pub_r001900_3, pub_r001900_4, pub_r001900_5, pub_r001900_6);
    int helper_flow_3 = fn_R001900_13_3(sec_r001900_3, sec_r001900_4);
    int helper_flow_4 = fn_R001900_13_4(sec_r001900_4, pub_r001900_5, pub_r001900_6);
    int helper_flow_5 = fn_R001900_13_5(sec_r001900_5, pub_r001900_6, pub_r001900_7, pub_r001900_8);
    int helper_flow_6 = fn_R001900_13_6(sec_r001900_6, sec_r001900_7, pub_r001900_8);
    int helper_flow_7 = fn_R001900_13_7(sec_r001900_7, pub_r001900_8);
    int helper_flow_8 = fn_R001900_13_8(sec_r001900_8, sec_r001900_9, pub_r001900_10, pub_r001900_11, pub_r001900_12);
    int helper_flow_9 = fn_R001900_13_9(sec_r001900_9, sec_r001900_10, pub_r001900_11);
    int helper_flow_10 = fn_R001900_13_10(sec_r001900_10, sec_r001900_11);
    int helper_flow_11 = fn_R001900_13_11(sec_r001900_11, pub_r001900_12, pub_r001900_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001900_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001900_10 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_1 > 26) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001900_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_3 > 31) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001900_10 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_4 > 36) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001900_15 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_5 > 36) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001900_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001900_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001900_11 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_8 > 50) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001900_21 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_9 > 37) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001900_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001900_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_12 > 46) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_13 > 29) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_14 > 43) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001900_22 ^ 0x2A) * 2 + pub_r001900_2) & 127;
    if (stage_v_15 > 27) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001900_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_17 > 22) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001900_16 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_18 > 21) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001900_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001900_5 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_20 > 40) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_21 > 50) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_22 > 43) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_23 > 35) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_24 > 42) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001900_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001900_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_27 > 39) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_28 > 42) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001900_17 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_29 > 27) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_30 > 30) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001900_22 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_31 > 39) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_32 > 31) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_33 > 44) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_34 > 38) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001900_11 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_35 > 39) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001900_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001900_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_38 > 32) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001900_15 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_39 > 38) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_40 > 26) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_41 > 40) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001900_5 ^ 0x2A) * 2 + pub_r001900_5) & 127;
    if (stage_v_42 > 44) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_43 > 32) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_44 > 27) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_45 > 25) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_46 > 38) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_47 > 27) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_48 > 28) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001900_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001900_20 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_50 > 49) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_51 > 44) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_52 > 39) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_53 > 48) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001900_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_55 > 27) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_56 > 41) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_57 > 34) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001900_5) & 127;
    if (stage_v_58 > 20) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001900_16 ^ 0x2A) * 2 + pub_r001900_5) & 127;
    if (stage_v_59 > 24) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001900_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_61 > 41) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001900_11 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_63 > 35) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001900_2) & 127;
    if (stage_v_64 > 50) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001900_17 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_65 > 36) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_66 > 32) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_67 > 29) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_68 > 32) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001900_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_70 > 23) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001900_0 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_71 > 38) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001900_11 ^ 0x2A) * 2 + pub_r001900_5) & 127;
    if (stage_v_72 > 40) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_73 > 50) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_74 > 36) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001900_5 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_75 > 49) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001900_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001900_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_78 > 38) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001900_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_80 > 26) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001900_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001900_20 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_82 > 36) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001900_1 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_83 > 48) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_84 > 30) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001900_1 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_85 > 36) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001900_17 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_86 > 44) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001900_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_88 > 21) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_89 > 32) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001900_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_91 > 40) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_92 > 44) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001900_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_94 > 29) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001900_7 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_95 > 49) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_96 > 49) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_97 > 25) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_98 > 33) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_99 > 45) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001900_5) & 127;
    if (stage_v_100 > 46) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_101 > 44) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_102 > 40) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r001900_6 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_103 > 30) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_104 > 40) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001900_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_106 > 49) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001900_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001900_2) & 127;
    if (stage_v_108 > 36) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_109 > 22) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_110 > 21) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001900_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001900_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_113 > 47) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_114 > 38) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001900_17 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_115 > 35) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_116 > 27) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_117 > 31) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_118 > 33) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001900_5 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_119 > 34) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_120 > 29) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_121 > 41) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_122 > 20) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001900_0 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_123 > 33) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001900_14 ^ 0x2A) * 2 + pub_r001900_2) & 127;
    if (stage_v_124 > 29) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_125 > 32) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001900_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001900_5) & 127;
    if (stage_v_127 > 32) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001900_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_129 > 42) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001900_9 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_130 > 47) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_131 > 34) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_132 > 37) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_133 > 35) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001900_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001900_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_136 > 36) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_137 > 29) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001900_16 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_138 > 27) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_139 > 24) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_140 > 24) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_141 > 41) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_142 > 29) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_143 > 41) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001900_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_145 > 20) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001900_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001900_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_148 > 31) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_149 > 40) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001900_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_151 > 20) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_152 > 39) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_153 > 37) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_154 > 47) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001900_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r001900_2 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_156 > 30) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_157 > 42) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_158 > 26) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_159 > 31) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_160 > 40) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001900_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_162 > 39) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_163 > 23) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_164 > 43) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_165 > 35) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001900_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_167 > 48) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_168 > 22) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((sec_r001900_18 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_169 > 31) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_170 > 41) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_171 > 34) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_172 > 32) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001900_2) & 127;
    if (stage_v_173 > 26) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001900_10 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_174 > 49) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001900_16 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_175 > 34) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001900_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r001900_0 ^ 0x2A) * 2 + pub_r001900_2) & 127;
    if (stage_v_177 > 37) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_178 > 31) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001900_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_180 > 46) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_181 > 47) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r001900_22 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_182 > 36) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_183 > 48) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001900_10) & 127;
    if (stage_v_184 > 43) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_185 > 25) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001900_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_187 > 39) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001900_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001900_22 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_189 > 46) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r001900_21 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_190 > 29) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_191 > 35) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001900_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_193 > 42) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_190 ^ 0x2A) * 2 + pub_r001900_0) & 127;
    if (stage_v_194 > 30) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_195 > 26) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001900_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001900_4) & 127;
    if (stage_v_197 > 22) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_198 > 25) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001900_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_200 > 23) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001900_6) & 127;
    if (stage_v_201 > 32) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001900_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_203 > 46) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_193 ^ 0x2A) * 2 + pub_r001900_15) & 127;
    if (stage_v_204 > 30) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_205 > 38) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001900_1) & 127;
    if (stage_v_206 > 27) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001900_9) & 127;
    if (stage_v_207 > 39) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001900_13) & 127;
    if (stage_v_208 > 50) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001900_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_175 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_210 > 28) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001900_5) & 127;
    if (stage_v_211 > 36) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_203 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_212 > 39) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001900_3) & 127;
    if (stage_v_213 > 20) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001900_11) & 127;
    if (stage_v_214 > 48) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001900_14) & 127;
    if (stage_v_215 > 26) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_191 ^ 0x2A) * 2 + pub_r001900_7) & 127;
    if (stage_v_216 > 25) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001900_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r001900_1 ^ 0x2A) * 2 + pub_r001900_8) & 127;
    if (stage_v_218 > 40) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001900_12) & 127;
    if (stage_v_219 > 34) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001900_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
