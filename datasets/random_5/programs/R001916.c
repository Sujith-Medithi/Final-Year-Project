/*
 * Benchmark Program: R001916
 * Security Family: implicit_flow
 * Generator Seed: 691613
 * High Inputs: 17 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001916_1613_0 {
    int balance;
    unsigned char fee;
    unsigned char status;
    int account_id;
    int buffer[3];
};

struct CipherContext_R001916_1613_1 {
    unsigned char round_key;
    int iv;
    int nonce;
    int counter;
    unsigned char flags;
    int tag;
    int buffer[3];
};

struct StreamBuffer_R001916_1613_2 {
    int watermark;
    unsigned char head;
    unsigned char capacity;
    short state;
    unsigned char tail;
    int checksum;
    int buffer[3];
};

union ColorPixel_R001916_1613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001916_1613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001916_1613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001916_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_51 = (aux + st.buffer[1]) & 3;
    switch (factor_51) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_12 = 0;
    for (int k = 0; k < 2; k++) {
        sample_12 = (sample_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_1(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_32 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_32 > 29) {
        acc = (acc + weight_32 * 2 + 5) & 127;
        aux ^= (weight_32 & 15);
    } else {
        acc = (acc - weight_32 + 11) & 127;
        aux += 3;
    }
    int mask_18 = (aux + st.buffer[1]) & 3;
    switch (mask_18) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_95 = local_arr[aux % 3];
    acc = (acc + mask_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001916_1613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001916_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_50) & 63;
    acc ^= aux;
    int bound_64 = (aux + st.buffer[1]) & 3;
    switch (bound_64) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_54 = 0;
    for (int k = 0; k < 2; k++) {
        vector_54 = (vector_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_54) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001916_1613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001916_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_89 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_89 > 21) {
        acc = (acc + damping_89 * 2 + 5) & 127;
        aux ^= (damping_89 & 15);
    } else {
        acc = (acc - damping_89 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_60 = local_arr[aux % 3];
    acc = (acc + phase_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001916_1613_4(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int bound_98 = (aux + st.buffer[1]) & 3;
    switch (bound_98) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_79) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001916_1613_5(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001916_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int tally_75 = local_arr[aux % 3];
    acc = (acc + tally_75 * 2) & 127;
    int vector_78 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_78 > 23) {
        acc = (acc + vector_78 * 2 + 5) & 127;
        aux ^= (vector_78 & 15);
    } else {
        acc = (acc - vector_78 + 11) & 127;
        aux += 3;
    }
    int bound_30 = 0;
    for (int k = 0; k < 3; k++) {
        bound_30 = (bound_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_30) & 127;
    }
    int delta_45 = (aux + st.buffer[1]) & 3;
    switch (delta_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_6(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001916_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_30 = local_arr[aux % 3];
    acc = (acc + quantum_30 * 2) & 127;
    int tally_75 = 0;
    for (int k = 0; k < 3; k++) {
        tally_75 = (tally_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_75) & 127;
    }
    int weight_18 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_18 > 20) {
        acc = (acc + weight_18 * 2 + 5) & 127;
        aux ^= (weight_18 & 15);
    } else {
        acc = (acc - weight_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001916_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int mask_60 = (aux + st.buffer[1]) & 3;
    switch (mask_60) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_55 = local_arr[aux % 3];
    acc = (acc + cursor_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001916_1613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001916_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quotient_78 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_78 = (quotient_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_78) & 127;
    }
    int metric_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_15) & 63;
    acc ^= aux;
    int delta_36 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_36 > 50) {
        acc = (acc + delta_36 * 2 + 5) & 127;
        aux ^= (delta_36 & 15);
    } else {
        acc = (acc - delta_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_9(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001916_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_93 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_93 > 17) {
        acc = (acc + metric_93 * 2 + 5) & 127;
        aux ^= (metric_93 & 15);
    } else {
        acc = (acc - metric_93 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001916_1613_10(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001916_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_74 = 0;
    for (int k = 0; k < 2; k++) {
        delta_74 = (delta_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_74) & 127;
    }
    int factor_24 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_24 > 21) {
        acc = (acc + factor_24 * 2 + 5) & 127;
        aux ^= (factor_24 & 15);
    } else {
        acc = (acc - factor_24 + 11) & 127;
        aux += 3;
    }
    int quantum_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001916_1613_11(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001916_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quotient_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_69) & 63;
    acc ^= aux;
    int vector_20 = (aux + st.buffer[1]) & 3;
    switch (vector_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_12(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_16 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_16 > 42) {
        acc = (acc + offset_16 * 2 + 5) & 127;
        aux ^= (offset_16 & 15);
    } else {
        acc = (acc - offset_16 + 11) & 127;
        aux += 3;
    }
    int index_reg_77 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_77 = (index_reg_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_77) & 127;
    }
    int vector_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_33) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_87 = local_arr[aux % 3];
    acc = (acc + quotient_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001916_1613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_75) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_40 = (aux + st.buffer[1]) & 3;
    switch (threshold_40) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_51 = 0;
    for (int k = 0; k < 2; k++) {
        weight_51 = (weight_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int damping_83 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_83 > 35) {
        acc = (acc + damping_83 * 2 + 5) & 127;
        aux ^= (damping_83 & 15);
    } else {
        acc = (acc - damping_83 + 11) & 127;
        aux += 3;
    }
    int window_49 = (aux + st.buffer[1]) & 3;
    switch (window_49) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_61 = 0;
    for (int k = 0; k < 3; k++) {
        damping_61 = (damping_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_61) & 127;
    }
    int quantum_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001916_1613_15(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int window_27 = (st.buffer[0] * 3 + aux) & 63;
    if (window_27 > 16) {
        acc = (acc + window_27 * 2 + 5) & 127;
        aux ^= (window_27 & 15);
    } else {
        acc = (acc - window_27 + 11) & 127;
        aux += 3;
    }
    int sample_53 = (aux + st.buffer[1]) & 3;
    switch (sample_53) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_59 = local_arr[aux % 3];
    acc = (acc + offset_59 * 2) & 127;
    int scale_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001916_1613_16(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int offset_89 = local_arr[aux % 3];
    acc = (acc + offset_89 * 2) & 127;
    int weight_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_19) & 63;
    acc ^= aux;
    int quantum_95 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_95 = (quantum_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_95) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001916_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int sample_42 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_42 > 25) {
        acc = (acc + sample_42 * 2 + 5) & 127;
        aux ^= (sample_42 & 15);
    } else {
        acc = (acc - sample_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_61 = local_arr[aux % 3];
    acc = (acc + mask_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001916_1613_18(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001916_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int residue_87 = local_arr[aux % 3];
    acc = (acc + residue_87 * 2) & 127;
    int mask_67 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_67 > 50) {
        acc = (acc + mask_67 * 2 + 5) & 127;
        aux ^= (mask_67 & 15);
    } else {
        acc = (acc - mask_67 + 11) & 127;
        aux += 3;
    }
    int stride_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_51) & 63;
    acc ^= aux;
    int quantum_65 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_65 = (quantum_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001916_1613_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001916_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001916_0;
    int sec_r001916_1;
    int sec_r001916_2;
    int sec_r001916_3;
    int sec_r001916_4;
    int sec_r001916_5;
    int sec_r001916_6;
    int sec_r001916_7;
    int sec_r001916_8;
    int sec_r001916_9;
    int sec_r001916_10;
    int sec_r001916_11;
    int sec_r001916_12;
    int sec_r001916_13;
    int sec_r001916_14;
    int sec_r001916_15;
    int sec_r001916_16;
    int pub_r001916_0;
    int pub_r001916_1;
    int pub_r001916_2;
    int pub_r001916_3;
    int pub_r001916_4;
    int pub_r001916_5;
    int pub_r001916_6;
    int pub_r001916_7;
    int pub_r001916_8;
    int pub_r001916_9;
    int pub_r001916_10;
    int pub_r001916_11;
    int pub_r001916_12;
    int pub_r001916_13;
    int pub_r001916_14;
    int pub_r001916_15;
    int pub_r001916_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001916_0 >= -100 && pub_r001916_0 <= 100);
    __CPROVER_assume(pub_r001916_1 >= -100 && pub_r001916_1 <= 100);
    __CPROVER_assume(pub_r001916_2 >= -100 && pub_r001916_2 <= 100);
    __CPROVER_assume(pub_r001916_3 >= -100 && pub_r001916_3 <= 100);
    __CPROVER_assume(pub_r001916_4 >= -100 && pub_r001916_4 <= 100);
    __CPROVER_assume(pub_r001916_5 >= -100 && pub_r001916_5 <= 100);
    __CPROVER_assume(pub_r001916_6 >= -100 && pub_r001916_6 <= 100);
    __CPROVER_assume(pub_r001916_7 >= -100 && pub_r001916_7 <= 100);
    __CPROVER_assume(pub_r001916_8 >= -100 && pub_r001916_8 <= 100);
    __CPROVER_assume(pub_r001916_9 >= -100 && pub_r001916_9 <= 100);
    __CPROVER_assume(pub_r001916_10 >= -100 && pub_r001916_10 <= 100);
    __CPROVER_assume(pub_r001916_11 >= -100 && pub_r001916_11 <= 100);
    __CPROVER_assume(pub_r001916_12 >= -100 && pub_r001916_12 <= 100);
    __CPROVER_assume(pub_r001916_13 >= -100 && pub_r001916_13 <= 100);
    __CPROVER_assume(pub_r001916_14 >= -100 && pub_r001916_14 <= 100);
    __CPROVER_assume(pub_r001916_15 >= -100 && pub_r001916_15 <= 100);
    __CPROVER_assume(pub_r001916_16 >= -100 && pub_r001916_16 <= 100);
    __CPROVER_assume(sec_r001916_0 >= 0 && sec_r001916_0 <= 255);
    __CPROVER_assume(sec_r001916_1 >= 0 && sec_r001916_1 <= 255);
    __CPROVER_assume(sec_r001916_2 >= 0 && sec_r001916_2 <= 255);
    __CPROVER_assume(sec_r001916_3 >= 0 && sec_r001916_3 <= 255);
    __CPROVER_assume(sec_r001916_4 >= 0 && sec_r001916_4 <= 255);
    __CPROVER_assume(sec_r001916_5 >= 0 && sec_r001916_5 <= 255);
    __CPROVER_assume(sec_r001916_6 >= 0 && sec_r001916_6 <= 255);
    __CPROVER_assume(sec_r001916_7 >= 0 && sec_r001916_7 <= 255);
    __CPROVER_assume(sec_r001916_8 >= 0 && sec_r001916_8 <= 255);
    __CPROVER_assume(sec_r001916_9 >= 0 && sec_r001916_9 <= 255);
    __CPROVER_assume(sec_r001916_10 >= 0 && sec_r001916_10 <= 255);
    __CPROVER_assume(sec_r001916_11 >= 0 && sec_r001916_11 <= 255);
    __CPROVER_assume(sec_r001916_12 >= 0 && sec_r001916_12 <= 255);
    __CPROVER_assume(sec_r001916_13 >= 0 && sec_r001916_13 <= 255);
    __CPROVER_assume(sec_r001916_14 >= 0 && sec_r001916_14 <= 255);
    __CPROVER_assume(sec_r001916_15 >= 0 && sec_r001916_15 <= 255);
    __CPROVER_assume(sec_r001916_16 >= 0 && sec_r001916_16 <= 255);

    struct Transaction_R001916_1613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001916_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001916_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001916_0 + 7) & 15;
    struct CipherContext_R001916_1613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001916_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001916_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001916_0 + 9) & 15;
    struct StreamBuffer_R001916_1613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001916_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001916_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001916_0 + 11) & 15;

    union ColorPixel_R001916_1613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001916_1613_0(sec_r001916_0, pub_r001916_1, pub_r001916_2, pub_r001916_3, pub_r001916_4);
    int helper_flow_1 = fn_R001916_1613_1(sec_r001916_1, sec_r001916_2, pub_r001916_3);
    int helper_flow_2 = fn_R001916_1613_2(sec_r001916_2, pub_r001916_3, pub_r001916_4, pub_r001916_5, pub_r001916_6);
    int helper_flow_3 = fn_R001916_1613_3(sec_r001916_3, pub_r001916_4, pub_r001916_5, pub_r001916_6, pub_r001916_7);
    int helper_flow_4 = fn_R001916_1613_4(sec_r001916_4, pub_r001916_5, pub_r001916_6);
    int helper_flow_5 = fn_R001916_1613_5(sec_r001916_5, sec_r001916_6, pub_r001916_7);
    int helper_flow_6 = fn_R001916_1613_6(sec_r001916_6, sec_r001916_7);
    int helper_flow_7 = fn_R001916_1613_7(sec_r001916_7, pub_r001916_8, pub_r001916_9, pub_r001916_10);
    int helper_flow_8 = fn_R001916_1613_8(sec_r001916_8, pub_r001916_9, pub_r001916_10, pub_r001916_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001916_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_8 + pub_r001916_1 * 2 + 8) & 127;
    if (stage_v_1 > 41) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001916_3 + pub_r001916_15 * 2 + 11) & 127;
    if (stage_v_2 > 30) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001916_1 + pub_r001916_3 * 2 + 14) & 127;
    if (stage_v_3 > 48) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (stage_v_1 + pub_r001916_5 * 2 + 17) & 127;
    if (stage_v_4 > 42) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_2 + pub_r001916_1 * 2 + 20) & 127;
    if (stage_v_5 > 17) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001916_13 + pub_r001916_8 * 2 + 23) & 127;
    if (stage_v_6 > 24) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_0 + pub_r001916_12 * 2 + 26) & 127;
    if (stage_v_7 > 39) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001916_11 + pub_r001916_16 * 2 + 29) & 127;
    if (stage_v_8 > 41) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001916_5 + pub_r001916_12 * 2 + 32) & 127;
    if (stage_v_9 > 39) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001916_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001916_2 + pub_r001916_16 * 2 + 38) & 127;
    if (stage_v_11 > 47) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001916_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001916_0 + pub_r001916_0 * 2 + 44) & 127;
    if (stage_v_13 > 59) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001916_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_3 + pub_r001916_10 * 2 + 50) & 127;
    if (stage_v_15 > 25) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001916_16 + pub_r001916_13 * 2 + 53) & 127;
    if (stage_v_16 > 36) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_1 + pub_r001916_4 * 2 + 56) & 127;
    if (stage_v_17 > 60) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001916_6 + pub_r001916_14 * 2 + 59) & 127;
    if (stage_v_18 > 20) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_1 + pub_r001916_12 * 2 + 62) & 127;
    if (stage_v_19 > 24) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_16 + pub_r001916_9 * 2 + 65) & 127;
    if (stage_v_20 > 54) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001916_13 + pub_r001916_8 * 2 + 68) & 127;
    if (stage_v_21 > 38) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_13 + pub_r001916_0 * 2 + 71) & 127;
    if (stage_v_22 > 35) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_3 + pub_r001916_15 * 2 + 74) & 127;
    if (stage_v_23 > 15) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_8 + pub_r001916_6 * 2 + 77) & 127;
    if (stage_v_24 > 55) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_9 + pub_r001916_5 * 2 + 80) & 127;
    if (stage_v_25 > 32) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_4 + pub_r001916_12 * 2 + 83) & 127;
    if (stage_v_26 > 44) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001916_11 + pub_r001916_9 * 2 + 86) & 127;
    if (stage_v_27 > 34) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001916_9 + pub_r001916_10 * 2 + 89) & 127;
    if (stage_v_28 > 33) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_11 + pub_r001916_14 * 2 + 92) & 127;
    if (stage_v_29 > 49) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_7 + pub_r001916_12 * 2 + 95) & 127;
    if (stage_v_30 > 42) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001916_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001916_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001916_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001916_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001916_5 + pub_r001916_11 * 2 + 110) & 127;
    if (stage_v_35 > 54) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_19 + pub_r001916_4 * 2 + 113) & 127;
    if (stage_v_36 > 44) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001916_8 + pub_r001916_2 * 2 + 116) & 127;
    if (stage_v_37 > 20) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_13 + pub_r001916_7 * 2 + 119) & 127;
    if (stage_v_38 > 34) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001916_16 + pub_r001916_8 * 2 + 122) & 127;
    if (stage_v_39 > 29) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001916_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001916_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_6 + pub_r001916_6 * 2 + 131) & 127;
    if (stage_v_42 > 19) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001916_3 + pub_r001916_16 * 2 + 134) & 127;
    if (stage_v_43 > 18) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_24 + pub_r001916_3 * 2 + 137) & 127;
    if (stage_v_44 > 29) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001916_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001916_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001916_8 + pub_r001916_7 * 2 + 146) & 127;
    if (stage_v_47 > 23) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001916_0 + pub_r001916_4 * 2 + 149) & 127;
    if (stage_v_48 > 52) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_44 + pub_r001916_5 * 2 + 152) & 127;
    if (stage_v_49 > 27) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_0 + pub_r001916_9 * 2 + 155) & 127;
    if (stage_v_50 > 16) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_1 + pub_r001916_0 * 2 + 158) & 127;
    if (stage_v_51 > 15) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_5 + pub_r001916_10 * 2 + 161) & 127;
    if (stage_v_52 > 51) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001916_10 + pub_r001916_10 * 2 + 164) & 127;
    if (stage_v_53 > 47) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_1 + pub_r001916_4 * 2 + 167) & 127;
    if (stage_v_54 > 20) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_22 + pub_r001916_10 * 2 + 170) & 127;
    if (stage_v_55 > 59) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001916_7 + pub_r001916_0 * 2 + 173) & 127;
    if (stage_v_56 > 54) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001916_6 + pub_r001916_4 * 2 + 176) & 127;
    if (stage_v_57 > 31) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001916_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001916_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_7 + pub_r001916_10 * 2 + 185) & 127;
    if (stage_v_60 > 42) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001916_7 + pub_r001916_5 * 2 + 188) & 127;
    if (stage_v_61 > 38) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_11 + pub_r001916_10 * 2 + 191) & 127;
    if (stage_v_62 > 44) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001916_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001916_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001916_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_1 + pub_r001916_3 * 2 + 203) & 127;
    if (stage_v_66 > 47) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001916_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001916_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001916_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_7 + pub_r001916_2 * 2 + 215) & 127;
    if (stage_v_70 > 26) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_13 + pub_r001916_15 * 2 + 218) & 127;
    if (stage_v_71 > 30) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001916_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_23 + pub_r001916_6 * 2 + 224) & 127;
    if (stage_v_73 > 38) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_3 + pub_r001916_10 * 2 + 227) & 127;
    if (stage_v_74 > 34) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (helper_flow_2 + pub_r001916_2 * 2 + 230) & 127;
    if (stage_v_75 > 59) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_54 + pub_r001916_11 * 2 + 233) & 127;
    if (stage_v_76 > 38) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_66 + pub_r001916_8 * 2 + 236) & 127;
    if (stage_v_77 > 50) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_9 + pub_r001916_4 * 2 + 239) & 127;
    if (stage_v_78 > 33) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_13 + pub_r001916_15 * 2 + 242) & 127;
    if (stage_v_79 > 51) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001916_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_78 + pub_r001916_5 * 2 + 248) & 127;
    if (stage_v_81 > 28) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_5 + pub_r001916_10 * 2 + 251) & 127;
    if (stage_v_82 > 49) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_73 + pub_r001916_2 * 2 + 254) & 127;
    if (stage_v_83 > 40) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_55 + pub_r001916_4 * 2 + 257) & 127;
    if (stage_v_84 > 27) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001916_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_53 + pub_r001916_14 * 2 + 263) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_56 + pub_r001916_1 * 2 + 266) & 127;
    if (stage_v_87 > 47) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_35 + pub_r001916_1 * 2 + 269) & 127;
    if (stage_v_88 > 55) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001916_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001916_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001916_7 + pub_r001916_5 * 2 + 278) & 127;
    if (stage_v_91 > 44) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_35 + pub_r001916_2 * 2 + 281) & 127;
    if (stage_v_92 > 37) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001916_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_53 + pub_r001916_12 * 2 + 287) & 127;
    if (stage_v_94 > 18) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_53 + pub_r001916_10 * 2 + 290) & 127;
    if (stage_v_95 > 60) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001916_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (helper_flow_7 + pub_r001916_14 * 2 + 296) & 127;
    if (stage_v_97 > 41) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_53 + pub_r001916_3 * 2 + 299) & 127;
    if (stage_v_98 > 53) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001916_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001916_4 + pub_r001916_6 * 2 + 305) & 127;
    if (stage_v_100 > 28) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (helper_flow_6 + pub_r001916_4 * 2 + 308) & 127;
    if (stage_v_101 > 16) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_50 + pub_r001916_16 * 2 + 311) & 127;
    if (stage_v_102 > 41) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_15 + pub_r001916_4 * 2 + 314) & 127;
    if (stage_v_103 > 36) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001916_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_97 + pub_r001916_12 * 2 + 320) & 127;
    if (stage_v_105 > 39) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001916_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (sec_r001916_0 + pub_r001916_7 * 2 + 326) & 127;
    if (stage_v_107 > 17) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r001916_1 + pub_r001916_2 * 2 + 329) & 127;
    if (stage_v_108 > 22) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r001916_8 + pub_r001916_13 * 2 + 332) & 127;
    if (stage_v_109 > 49) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_23 + pub_r001916_15 * 2 + 335) & 127;
    if (stage_v_110 > 15) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (helper_flow_7 + pub_r001916_10 * 2 + 338) & 127;
    if (stage_v_111 > 30) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_56 + pub_r001916_8 * 2 + 341) & 127;
    if (stage_v_112 > 36) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001916_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001916_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_25 + pub_r001916_9 * 2 + 350) & 127;
    if (stage_v_115 > 35) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001916_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_73 + pub_r001916_11 * 2 + 356) & 127;
    if (stage_v_117 > 53) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_7 + pub_r001916_11 * 2 + 359) & 127;
    if (stage_v_118 > 44) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001916_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_115 + pub_r001916_12 * 2 + 365) & 127;
    if (stage_v_120 > 30) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (helper_flow_8 + pub_r001916_10 * 2 + 368) & 127;
    if (stage_v_121 > 31) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001916_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_50 + pub_r001916_2 * 2 + 374) & 127;
    if (stage_v_123 > 23) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_21 + pub_r001916_5 * 2 + 377) & 127;
    if (stage_v_124 > 59) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_22 + pub_r001916_10 * 2 + 380) & 127;
    if (stage_v_125 > 43) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_5 + pub_r001916_14 * 2 + 383) & 127;
    if (stage_v_126 > 39) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001916_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_108 + pub_r001916_16 * 2 + 389) & 127;
    if (stage_v_128 > 45) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_123 + pub_r001916_3 * 2 + 392) & 127;
    if (stage_v_129 > 50) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_23 + pub_r001916_14 * 2 + 395) & 127;
    if (stage_v_130 > 30) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_112 + pub_r001916_12 * 2 + 398) & 127;
    if (stage_v_131 > 43) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_73 + pub_r001916_14 * 2 + 401) & 127;
    if (stage_v_132 > 45) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_66 + pub_r001916_9 * 2 + 404) & 127;
    if (stage_v_133 > 48) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_133 + pub_r001916_10 * 2 + 407) & 127;
    if (stage_v_134 > 48) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001916_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_115 + pub_r001916_16 * 2 + 413) & 127;
    if (stage_v_136 > 26) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (sec_r001916_10 + pub_r001916_6 * 2 + 416) & 127;
    if (stage_v_137 > 31) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_129 + pub_r001916_3 * 2 + 419) & 127;
    if (stage_v_138 > 53) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001916_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001916_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001916_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (helper_flow_6 + pub_r001916_15 * 2 + 431) & 127;
    if (stage_v_142 > 33) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_95 + pub_r001916_5 * 2 + 434) & 127;
    if (stage_v_143 > 25) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001916_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_121 + pub_r001916_3 * 2 + 440) & 127;
    if (stage_v_145 > 50) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_2 + pub_r001916_16 * 2 + 443) & 127;
    if (stage_v_146 > 38) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_28 + pub_r001916_6 * 2 + 446) & 127;
    if (stage_v_147 > 17) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_3 + pub_r001916_2 * 2 + 449) & 127;
    if (stage_v_148 > 27) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_73 + pub_r001916_8 * 2 + 452) & 127;
    if (stage_v_149 > 27) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_79 + pub_r001916_9 * 2 + 455) & 127;
    if (stage_v_150 > 56) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_128 + pub_r001916_11 * 2 + 458) & 127;
    if (stage_v_151 > 40) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001916_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (sec_r001916_8 + pub_r001916_16 * 2 + 464) & 127;
    if (stage_v_153 > 55) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001916_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_136 + pub_r001916_12 * 2 + 470) & 127;
    if (stage_v_155 > 47) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_128 + pub_r001916_6 * 2 + 473) & 127;
    if (stage_v_156 > 42) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_48 + pub_r001916_1 * 2 + 476) & 127;
    if (stage_v_157 > 37) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_66 + pub_r001916_2 * 2 + 479) & 127;
    if (stage_v_158 > 48) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001916_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_97 + pub_r001916_6 * 2 + 485) & 127;
    if (stage_v_160 > 38) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001916_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_43 + pub_r001916_6 * 2 + 491) & 127;
    if (stage_v_162 > 46) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_50 + pub_r001916_0 * 2 + 494) & 127;
    if (stage_v_163 > 26) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r001916_16 + pub_r001916_9 * 2 + 497) & 127;
    if (stage_v_164 > 16) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001916_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_62 + pub_r001916_7 * 2 + 503) & 127;
    if (stage_v_166 > 18) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001916_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001916_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_42 + pub_r001916_14 * 2 + 512) & 127;
    if (stage_v_169 > 36) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_25 + pub_r001916_16 * 2 + 515) & 127;
    if (stage_v_170 > 35) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001916_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_7 + pub_r001916_2 * 2 + 521) & 127;
    if (stage_v_172 > 31) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001916_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_100 + pub_r001916_1 * 2 + 527) & 127;
    if (stage_v_174 > 25) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_55 + pub_r001916_1 * 2 + 530) & 127;
    if (stage_v_175 > 26) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (sec_r001916_8 + pub_r001916_16 * 2 + 533) & 127;
    if (stage_v_176 > 52) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_117 + pub_r001916_11 * 2 + 536) & 127;
    if (stage_v_177 > 55) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_61 + pub_r001916_12 * 2 + 539) & 127;
    if (stage_v_178 > 60) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001916_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001916_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_125 + pub_r001916_10 * 2 + 548) & 127;
    if (stage_v_181 > 60) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001916_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_38 + pub_r001916_2 * 2 + 554) & 127;
    if (stage_v_183 > 24) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001916_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_5 + pub_r001916_15 * 2 + 560) & 127;
    if (stage_v_185 > 45) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001916_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_56 + pub_r001916_11 * 2 + 566) & 127;
    if (stage_v_187 > 36) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_62 + pub_r001916_12 * 2 + 569) & 127;
    if (stage_v_188 > 36) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_110 + pub_r001916_7 * 2 + 572) & 127;
    if (stage_v_189 > 59) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (sec_r001916_12 + pub_r001916_13 * 2 + 575) & 127;
    if (stage_v_190 > 26) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001916_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001916_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001916_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_42 + pub_r001916_16 * 2 + 587) & 127;
    if (stage_v_194 > 47) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001916_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r001916_12 + pub_r001916_4 * 2 + 593) & 127;
    if (stage_v_196 > 33) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_6 + pub_r001916_1 * 2 + 596) & 127;
    if (stage_v_197 > 36) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_21 + pub_r001916_9 * 2 + 599) & 127;
    if (stage_v_198 > 28) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_84 + pub_r001916_9 * 2 + 602) & 127;
    if (stage_v_199 > 39) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001916_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_164 + pub_r001916_14 * 2 + 608) & 127;
    if (stage_v_201 > 53) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_157 + pub_r001916_12 * 2 + 611) & 127;
    if (stage_v_202 > 17) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001916_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001916_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001916_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001916_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_47 + pub_r001916_8 * 2 + 626) & 127;
    if (stage_v_207 > 20) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001916_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001916_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_87 + pub_r001916_4 * 2 + 635) & 127;
    if (stage_v_210 > 46) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_42 + pub_r001916_14 * 2 + 638) & 127;
    if (stage_v_211 > 51) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_115 + pub_r001916_11 * 2 + 641) & 127;
    if (stage_v_212 > 23) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001916_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_120 + pub_r001916_7 * 2 + 647) & 127;
    if (stage_v_214 > 19) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_25 + pub_r001916_5 * 2 + 650) & 127;
    if (stage_v_215 > 32) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_92 + pub_r001916_14 * 2 + 653) & 127;
    if (stage_v_216 > 43) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_112 + pub_r001916_15 * 2 + 656) & 127;
    if (stage_v_217 > 46) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001916_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001916_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_15 + pub_r001916_14 * 2 + 665) & 127;
    if (stage_v_220 > 45) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_11 + pub_r001916_4 * 2 + 668) & 127;
    if (stage_v_221 > 29) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001916_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001916_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001916_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_216 + pub_r001916_5 * 2 + 680) & 127;
    if (stage_v_225 > 27) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_5 + pub_r001916_3 * 2 + 683) & 127;
    if (stage_v_226 > 45) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_75 + pub_r001916_8 * 2 + 686) & 127;
    if (stage_v_227 > 23) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001916_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_26 + pub_r001916_11 * 2 + 692) & 127;
    if (stage_v_229 > 39) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001916_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001916_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_25 + pub_r001916_14 * 2 + 701) & 127;
    if (stage_v_232 > 57) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_108 + pub_r001916_8 * 2 + 704) & 127;
    if (stage_v_233 > 50) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (sec_r001916_11 + pub_r001916_13 * 2 + 707) & 127;
    if (stage_v_234 > 56) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001916_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_17 + pub_r001916_4 * 2 + 713) & 127;
    if (stage_v_236 > 40) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_43 + pub_r001916_15 * 2 + 716) & 127;
    if (stage_v_237 > 33) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
