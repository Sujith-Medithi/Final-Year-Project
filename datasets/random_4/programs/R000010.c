/*
 * Benchmark Program: R000010
 * Family: zero_leakage
 * Generator Seed: 401013
 * High Inputs: 16 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000010_1013_0 {
    int dim;
    short determinant;
    short trace;
    int density;
    unsigned char stride;
    int buffer[3];
};

struct EventLog_R000010_1013_1 {
    short seq;
    int timestamp;
    short code;
    int buffer[3];
};

struct StreamBuffer_R000010_1013_2 {
    int checksum;
    unsigned char state;
    short watermark;
    int buffer[3];
};

struct CipherContext_R000010_1013_3 {
    int iv;
    int counter;
    int tag;
    int buffer[3];
};

union TelemetryField_R000010_1013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000010_1013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000010_1013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000010_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int scale_14 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_14 > 38) {
        acc = (acc + scale_14 * 2 + 5) & 127;
        aux ^= (scale_14 & 15);
    } else {
        acc = (acc - scale_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_23) & 63;
    acc ^= aux;
    int damping_27 = (aux + st.buffer[1]) & 3;
    switch (damping_27) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000010_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int cursor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_20 > 25) {
        acc = (acc + cursor_20 * 2 + 5) & 127;
        aux ^= (cursor_20 & 15);
    } else {
        acc = (acc - cursor_20 + 11) & 127;
        aux += 3;
    }
    int sample_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000010_1013_2(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int mask_95 = (aux + st.buffer[1]) & 3;
    switch (mask_95) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_17 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_17 > 24) {
        acc = (acc + cursor_17 * 2 + 5) & 127;
        aux ^= (cursor_17 & 15);
    } else {
        acc = (acc - cursor_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000010_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int bound_70 = (aux + st.buffer[1]) & 3;
    switch (bound_70) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_47) & 63;
    acc ^= aux;
    int stride_37 = 0;
    for (int k = 0; k < 2; k++) {
        stride_37 = (stride_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_37) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_90 = local_arr[aux % 3];
    acc = (acc + checksum_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000010_1013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000010_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int anchor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_54 > 12) {
        acc = (acc + anchor_54 * 2 + 5) & 127;
        aux ^= (anchor_54 & 15);
    } else {
        acc = (acc - anchor_54 + 11) & 127;
        aux += 3;
    }
    int window_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000010_1013_5(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int mask_36 = local_arr[aux % 3];
    acc = (acc + mask_36 * 2) & 127;
    int residue_10 = (aux + st.buffer[1]) & 3;
    switch (residue_10) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_15) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000010_1013_6(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000010_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int coefficient_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_99) & 63;
    acc ^= aux;
    int sample_78 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_78 > 29) {
        acc = (acc + sample_78 * 2 + 5) & 127;
        aux ^= (sample_78 & 15);
    } else {
        acc = (acc - sample_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_7(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000010_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_39 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_39 > 48) {
        acc = (acc + phase_39 * 2 + 5) & 127;
        aux ^= (phase_39 & 15);
    } else {
        acc = (acc - phase_39 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_96 = local_arr[aux % 3];
    acc = (acc + margin_96 * 2) & 127;
    int pivot_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_12) & 63;
    acc ^= aux;
    int threshold_80 = (aux + st.buffer[1]) & 3;
    switch (threshold_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_8(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000010_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_54 = local_arr[aux % 3];
    acc = (acc + stride_54 * 2) & 127;
    int delta_42 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_42 > 32) {
        acc = (acc + delta_42 * 2 + 5) & 127;
        aux ^= (delta_42 & 15);
    } else {
        acc = (acc - delta_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_9(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_59 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_59 = (coefficient_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_59) & 127;
    }
    int anchor_64 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_64 > 20) {
        acc = (acc + anchor_64 * 2 + 5) & 127;
        aux ^= (anchor_64 & 15);
    } else {
        acc = (acc - anchor_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000010_1013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int stride_21 = 0;
    for (int k = 0; k < 3; k++) {
        stride_21 = (stride_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_21) & 127;
    }
    int index_reg_85 = (aux + st.buffer[1]) & 3;
    switch (index_reg_85) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_69 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_69 > 48) {
        acc = (acc + checksum_69 * 2 + 5) & 127;
        aux ^= (checksum_69 & 15);
    } else {
        acc = (acc - checksum_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000010_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int margin_18 = 0;
    for (int k = 0; k < 2; k++) {
        margin_18 = (margin_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_18) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_86 = (aux + st.buffer[1]) & 3;
    switch (metric_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000010_1013_12(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tracker_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_35) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_71 = local_arr[aux % 3];
    acc = (acc + weight_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000010_1013_13(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000010_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int vector_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_89) & 63;
    acc ^= aux;
    int vector_47 = (aux + st.buffer[1]) & 3;
    switch (vector_47) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000010_1013_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000010_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int anchor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_68) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_54 = (aux + st.buffer[1]) & 3;
    switch (coefficient_54) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_15(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000010_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_73 = 0;
    for (int k = 0; k < 3; k++) {
        vector_73 = (vector_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_73) & 127;
    }
    int cursor_86 = (aux + st.buffer[1]) & 3;
    switch (cursor_86) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_16(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000010_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_84) & 63;
    acc ^= aux;
    int tracker_34 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_34 > 29) {
        acc = (acc + tracker_34 * 2 + 5) & 127;
        aux ^= (tracker_34 & 15);
    } else {
        acc = (acc - tracker_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_58 = local_arr[aux % 3];
    acc = (acc + quantum_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000010_1013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int scale_57 = (aux + st.buffer[1]) & 3;
    switch (scale_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_62 = local_arr[aux % 3];
    acc = (acc + index_reg_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000010_1013_18(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000010_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int parity_79 = 0;
    for (int k = 0; k < 2; k++) {
        parity_79 = (parity_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_79) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_88 = local_arr[aux % 3];
    acc = (acc + weight_88 * 2) & 127;
    int parity_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000010_1013_19(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int factor_41 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_41 > 37) {
        acc = (acc + factor_41 * 2 + 5) & 127;
        aux ^= (factor_41 & 15);
    } else {
        acc = (acc - factor_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_56 = local_arr[aux % 3];
    acc = (acc + margin_56 * 2) & 127;
    int coefficient_69 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_69 = (coefficient_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_69) & 127;
    }
    int mask_57 = (aux + st.buffer[1]) & 3;
    switch (mask_57) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000010_1013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_59 = (aux + st.buffer[1]) & 3;
    switch (margin_59) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000010_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quotient_33 = (aux + st.buffer[1]) & 3;
    switch (quotient_33) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_23) & 63;
    acc ^= aux;
    int scale_23 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_23 > 14) {
        acc = (acc + scale_23 * 2 + 5) & 127;
        aux ^= (scale_23 & 15);
    } else {
        acc = (acc - scale_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_22(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000010_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int factor_81 = (aux + st.buffer[1]) & 3;
    switch (factor_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000010_1013_23(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000010_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_78 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_78 = (tracker_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_78) & 127;
    }
    int margin_58 = (aux + st.buffer[1]) & 3;
    switch (margin_58) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000010_1013_24(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000010_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_29 = local_arr[aux % 3];
    acc = (acc + metric_29 * 2) & 127;
    int phase_89 = 0;
    for (int k = 0; k < 2; k++) {
        phase_89 = (phase_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_89) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000010_0;
    int sec_r000010_1;
    int sec_r000010_2;
    int sec_r000010_3;
    int sec_r000010_4;
    int sec_r000010_5;
    int sec_r000010_6;
    int sec_r000010_7;
    int sec_r000010_8;
    int sec_r000010_9;
    int sec_r000010_10;
    int sec_r000010_11;
    int sec_r000010_12;
    int sec_r000010_13;
    int sec_r000010_14;
    int sec_r000010_15;
    int pub_r000010_0;
    int pub_r000010_1;
    int pub_r000010_2;
    int pub_r000010_3;
    int pub_r000010_4;
    int pub_r000010_5;
    int pub_r000010_6;
    int pub_r000010_7;
    int pub_r000010_8;
    int pub_r000010_9;
    int pub_r000010_10;
    int pub_r000010_11;
    int pub_r000010_12;
    int pub_r000010_13;
    int pub_r000010_14;
    int pub_r000010_15;
    int pub_r000010_16;
    int pub_r000010_17;
    int pub_r000010_18;
    int pub_r000010_19;
    int pub_r000010_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000010_0 >= -100 && pub_r000010_0 <= 100);
    __CPROVER_assume(pub_r000010_1 >= -100 && pub_r000010_1 <= 100);
    __CPROVER_assume(pub_r000010_2 >= -100 && pub_r000010_2 <= 100);
    __CPROVER_assume(pub_r000010_3 >= -100 && pub_r000010_3 <= 100);
    __CPROVER_assume(pub_r000010_4 >= -100 && pub_r000010_4 <= 100);
    __CPROVER_assume(pub_r000010_5 >= -100 && pub_r000010_5 <= 100);
    __CPROVER_assume(pub_r000010_6 >= -100 && pub_r000010_6 <= 100);
    __CPROVER_assume(pub_r000010_7 >= -100 && pub_r000010_7 <= 100);
    __CPROVER_assume(pub_r000010_8 >= -100 && pub_r000010_8 <= 100);
    __CPROVER_assume(pub_r000010_9 >= -100 && pub_r000010_9 <= 100);
    __CPROVER_assume(pub_r000010_10 >= -100 && pub_r000010_10 <= 100);
    __CPROVER_assume(pub_r000010_11 >= -100 && pub_r000010_11 <= 100);
    __CPROVER_assume(pub_r000010_12 >= -100 && pub_r000010_12 <= 100);
    __CPROVER_assume(pub_r000010_13 >= -100 && pub_r000010_13 <= 100);
    __CPROVER_assume(pub_r000010_14 >= -100 && pub_r000010_14 <= 100);
    __CPROVER_assume(pub_r000010_15 >= -100 && pub_r000010_15 <= 100);
    __CPROVER_assume(pub_r000010_16 >= -100 && pub_r000010_16 <= 100);
    __CPROVER_assume(pub_r000010_17 >= -100 && pub_r000010_17 <= 100);
    __CPROVER_assume(pub_r000010_18 >= -100 && pub_r000010_18 <= 100);
    __CPROVER_assume(pub_r000010_19 >= -100 && pub_r000010_19 <= 100);
    __CPROVER_assume(pub_r000010_20 >= -100 && pub_r000010_20 <= 100);
    __CPROVER_assume(sec_r000010_0 >= 0 && sec_r000010_0 <= 255);
    __CPROVER_assume(sec_r000010_1 >= 0 && sec_r000010_1 <= 255);
    __CPROVER_assume(sec_r000010_2 >= 0 && sec_r000010_2 <= 255);
    __CPROVER_assume(sec_r000010_3 >= 0 && sec_r000010_3 <= 255);
    __CPROVER_assume(sec_r000010_4 >= 0 && sec_r000010_4 <= 255);
    __CPROVER_assume(sec_r000010_5 >= 0 && sec_r000010_5 <= 255);
    __CPROVER_assume(sec_r000010_6 >= 0 && sec_r000010_6 <= 255);
    __CPROVER_assume(sec_r000010_7 >= 0 && sec_r000010_7 <= 255);
    __CPROVER_assume(sec_r000010_8 >= 0 && sec_r000010_8 <= 255);
    __CPROVER_assume(sec_r000010_9 >= 0 && sec_r000010_9 <= 255);
    __CPROVER_assume(sec_r000010_10 >= 0 && sec_r000010_10 <= 255);
    __CPROVER_assume(sec_r000010_11 >= 0 && sec_r000010_11 <= 255);
    __CPROVER_assume(sec_r000010_12 >= 0 && sec_r000010_12 <= 255);
    __CPROVER_assume(sec_r000010_13 >= 0 && sec_r000010_13 <= 255);
    __CPROVER_assume(sec_r000010_14 >= 0 && sec_r000010_14 <= 255);
    __CPROVER_assume(sec_r000010_15 >= 0 && sec_r000010_15 <= 255);

    struct MatrixBlock_R000010_1013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000010_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000010_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000010_0 + 7) & 15;
    struct EventLog_R000010_1013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000010_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000010_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000010_0 + 9) & 15;
    struct StreamBuffer_R000010_1013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000010_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000010_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000010_0 + 11) & 15;
    struct CipherContext_R000010_1013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000010_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000010_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000010_0 + 13) & 15;

    union TelemetryField_R000010_1013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 16) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 31) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 23) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 38) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 13) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 28) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 19) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 34) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
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
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 10) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 25) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 22) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 37) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 23) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 38) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 30) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 45) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 29) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 44) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 27) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 42) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 37) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 52) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 33) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 48) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_3.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 33) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 48) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 86) & 15;
    int stage_v_85 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= stage_v_85;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3];
    table[3] = (table[0] + 175) & 63;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_89 = (stage_v_89 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_90 = (stage_v_90 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_2.buffer[1] * 2 + 289) & 63;
    if (stage_v_94 > 10) {
        out_sink = (out_sink + stage_v_94 - 5) & 255;
        if (stage_v_94 > 25) {
            chk_sum ^= (stage_v_94 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_94 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_3.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 29) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 44) {
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
    int stage_v_97 = table[1];
    table[1] = (table[2] + 195) & 63;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 11) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 26) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_3.buffer[0] ^ 102) & 3;
    switch (stage_v_99) {
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

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 101 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 102) & 15;
    int stage_v_101 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= stage_v_101;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 104) & 15;
    int stage_v_103 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= stage_v_103;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = table[0];
    table[0] = (table[1] + 217) & 63;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 38) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 53) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_2.buffer[0] ^ 117) & 3;
    switch (stage_v_114) {
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

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[0] ^ 127) & 3;
    switch (stage_v_124) {
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

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_125 = (stage_v_125 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (out_sink > 100) ? (chk_sum & 31) : (131 & 31);
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= (stage_v_126 << 1) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_3.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] * 2 + 394) & 63;
    if (stage_v_129 > 28) {
        out_sink = (out_sink + stage_v_129 - 5) & 255;
        if (stage_v_129 > 43) {
            chk_sum ^= (stage_v_129 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_129 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = table[2];
    table[2] = (table[3] + 261) & 63;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_3.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 33) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 48) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (out_sink > 100) ? (chk_sum & 31) : (137 & 31);
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= (stage_v_132 << 1) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 34) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 49) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_3.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 22) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 37) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[1] * 2 + 415) & 63;
    if (stage_v_136 > 13) {
        out_sink = (out_sink + stage_v_136 - 5) & 255;
        if (stage_v_136 > 28) {
            chk_sum ^= (stage_v_136 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_136 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (out_sink > 100) ? (chk_sum & 31) : (142 & 31);
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= (stage_v_137 << 1) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_3.buffer[0] ^ 142) & 3;
    switch (stage_v_139) {
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

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (out_sink > 100) ? (chk_sum & 31) : (145 & 31);
    out_sink = (out_sink + stage_v_140) & 255;
    chk_sum ^= (stage_v_140 << 1) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 150) & 15;
    int stage_v_149 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= stage_v_149;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (out_sink > 100) ? (chk_sum & 31) : (157 & 31);
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= (stage_v_152 << 1) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
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

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = table[2];
    table[2] = (table[3] + 309) & 63;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = table[3];
    table[3] = (table[0] + 311) & 63;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[1] * 2 + 478) & 63;
    if (stage_v_157 > 29) {
        out_sink = (out_sink + stage_v_157 - 5) & 255;
        if (stage_v_157 > 44) {
            chk_sum ^= (stage_v_157 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_157 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_159 = (stage_v_159 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Security Information Flow: Family = zero_leakage */
    int dead_sec_0 = (sec_r000010_4 ^ sec_r000010_4) * 0;
    int dead_sec_1 = (sec_r000010_12 & 0) * 0;
    int dead_sec_2 = (sec_r000010_10 ^ sec_r000010_10) * 0;
    int dead_sec_3 = ((sec_r000010_2 << 2) ^ (sec_r000010_2 << 2)) * 0;
    int dead_sec_4 = ((sec_r000010_4 + 7) - (sec_r000010_4 + 7)) * 0;
    out_sink = (out_sink + dead_sec_0 + dead_sec_1 + dead_sec_2 + dead_sec_3 + dead_sec_4) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
