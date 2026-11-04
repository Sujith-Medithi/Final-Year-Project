/*
 * Benchmark Program: R000319
 * Family: arithmetic_flow
 * Generator Seed: 431913
 * High Inputs: 18 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000319_1913_0 {
    short status;
    int fee;
    int balance;
    int rate;
    int buffer[3];
};

struct DeviceConfig_R000319_1913_1 {
    int parity;
    unsigned char port;
    unsigned char baud_rate;
    int stop_bits;
    int buffer[3];
};

struct CipherContext_R000319_1913_2 {
    int nonce;
    unsigned char tag;
    unsigned char counter;
    unsigned char iv;
    short round_key;
    int flags;
    int buffer[3];
};

union ColorPixel_R000319_1913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000319_1913_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000319_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int pivot_38 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_38 > 46) {
        acc = (acc + pivot_38 * 2 + 5) & 127;
        aux ^= (pivot_38 & 15);
    } else {
        acc = (acc - pivot_38 + 11) & 127;
        aux += 3;
    }
    int phase_79 = 0;
    for (int k = 0; k < 3; k++) {
        phase_79 = (phase_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_79) & 127;
    }
    int stride_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_68 = local_arr[aux % 3];
    acc = (acc + threshold_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_1913_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int vector_99 = local_arr[aux % 3];
    acc = (acc + vector_99 * 2) & 127;
    int sample_69 = (aux + st.buffer[1]) & 3;
    switch (sample_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_27) & 63;
    acc ^= aux;
    int metric_45 = 0;
    for (int k = 0; k < 3; k++) {
        metric_45 = (metric_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000319_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int tally_33 = local_arr[aux % 3];
    acc = (acc + tally_33 * 2) & 127;
    int parity_71 = 0;
    for (int k = 0; k < 3; k++) {
        parity_71 = (parity_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_71) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_1913_3(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_86 = (st.buffer[0] * 3 + aux) & 63;
    if (window_86 > 29) {
        acc = (acc + window_86 * 2 + 5) & 127;
        aux ^= (window_86 & 15);
    } else {
        acc = (acc - window_86 + 11) & 127;
        aux += 3;
    }
    int accumulator_31 = (aux + st.buffer[1]) & 3;
    switch (accumulator_31) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_1913_4(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_10 = (aux + st.buffer[1]) & 3;
    switch (quantum_10) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_1913_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int scale_42 = local_arr[aux % 3];
    acc = (acc + scale_42 * 2) & 127;
    int tracker_54 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_54 = (tracker_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_54) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_6(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_1913_7(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int factor_94 = 0;
    for (int k = 0; k < 3; k++) {
        factor_94 = (factor_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_94) & 127;
    }
    int quantum_87 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_87 > 38) {
        acc = (acc + quantum_87 * 2 + 5) & 127;
        aux ^= (quantum_87 & 15);
    } else {
        acc = (acc - quantum_87 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_56 = local_arr[aux % 3];
    acc = (acc + mask_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_1913_8(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000319_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_88 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_88 > 45) {
        acc = (acc + weight_88 * 2 + 5) & 127;
        aux ^= (weight_88 & 15);
    } else {
        acc = (acc - weight_88 + 11) & 127;
        aux += 3;
    }
    int segment_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_1913_9(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_84 = local_arr[aux % 3];
    acc = (acc + bound_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_1913_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int residue_75 = 0;
    for (int k = 0; k < 3; k++) {
        residue_75 = (residue_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_75) & 127;
    }
    int accumulator_63 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_63 > 34) {
        acc = (acc + accumulator_63 * 2 + 5) & 127;
        aux ^= (accumulator_63 & 15);
    } else {
        acc = (acc - accumulator_63 + 11) & 127;
        aux += 3;
    }
    int damping_26 = (aux + st.buffer[1]) & 3;
    switch (damping_26) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_11(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int quotient_80 = local_arr[aux % 3];
    acc = (acc + quotient_80 * 2) & 127;
    int index_reg_86 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_86 = (index_reg_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_86) & 127;
    }
    int residue_37 = (aux + st.buffer[1]) & 3;
    switch (residue_37) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_12(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000319_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int checksum_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_98) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_34 = local_arr[aux % 3];
    acc = (acc + tally_34 * 2) & 127;
    int bound_47 = 0;
    for (int k = 0; k < 2; k++) {
        bound_47 = (bound_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_47) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_13(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000319_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int segment_79 = local_arr[aux % 3];
    acc = (acc + segment_79 * 2) & 127;
    int factor_97 = (aux + st.buffer[1]) & 3;
    switch (factor_97) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_14(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_94 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_94 > 46) {
        acc = (acc + tally_94 * 2 + 5) & 127;
        aux ^= (tally_94 & 15);
    } else {
        acc = (acc - tally_94 + 11) & 127;
        aux += 3;
    }
    int checksum_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_15) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_1913_15(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int anchor_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_29) & 63;
    acc ^= aux;
    int accumulator_86 = (aux + st.buffer[1]) & 3;
    switch (accumulator_86) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_71 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_71 > 40) {
        acc = (acc + sample_71 * 2 + 5) & 127;
        aux ^= (sample_71 & 15);
    } else {
        acc = (acc - sample_71 + 11) & 127;
        aux += 3;
    }
    int mask_56 = 0;
    for (int k = 0; k < 3; k++) {
        mask_56 = (mask_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_56) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_44 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_44 > 38) {
        acc = (acc + vector_44 * 2 + 5) & 127;
        aux ^= (vector_44 & 15);
    } else {
        acc = (acc - vector_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_18(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_67 = (aux + st.buffer[1]) & 3;
    switch (anchor_67) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_59 = local_arr[aux % 3];
    acc = (acc + coefficient_59 * 2) & 127;
    int factor_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_1913_19(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int bound_10 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_10 > 34) {
        acc = (acc + bound_10 * 2 + 5) & 127;
        aux ^= (bound_10 & 15);
    } else {
        acc = (acc - bound_10 + 11) & 127;
        aux += 3;
    }
    int weight_31 = (aux + st.buffer[1]) & 3;
    switch (weight_31) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_71 = 0;
    for (int k = 0; k < 2; k++) {
        damping_71 = (damping_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int quotient_27 = local_arr[aux % 3];
    acc = (acc + quotient_27 * 2) & 127;
    int phase_64 = 0;
    for (int k = 0; k < 2; k++) {
        phase_64 = (phase_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_64) & 127;
    }
    int tracker_14 = (aux + st.buffer[1]) & 3;
    switch (tracker_14) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int stride_11 = local_arr[aux % 3];
    acc = (acc + stride_11 * 2) & 127;
    int threshold_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_55) & 63;
    acc ^= aux;
    int vector_69 = 0;
    for (int k = 0; k < 2; k++) {
        vector_69 = (vector_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_69) & 127;
    }
    int checksum_92 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_92 > 21) {
        acc = (acc + checksum_92 * 2 + 5) & 127;
        aux ^= (checksum_92 & 15);
    } else {
        acc = (acc - checksum_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000319_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_10 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_10 > 37) {
        acc = (acc + quotient_10 * 2 + 5) & 127;
        aux ^= (quotient_10 & 15);
    } else {
        acc = (acc - quotient_10 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_54 = local_arr[aux % 3];
    acc = (acc + weight_54 * 2) & 127;
    int threshold_76 = (aux + st.buffer[1]) & 3;
    switch (threshold_76) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_23(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int accumulator_62 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_62 = (accumulator_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_62) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_54 = local_arr[aux % 3];
    acc = (acc + scale_54 * 2) & 127;
    int cursor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_79 > 18) {
        acc = (acc + cursor_79 * 2 + 5) & 127;
        aux ^= (cursor_79 & 15);
    } else {
        acc = (acc - cursor_79 + 11) & 127;
        aux += 3;
    }
    int stride_44 = (aux + st.buffer[1]) & 3;
    switch (stride_44) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_1913_24(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000319_1913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int phase_16 = 0;
    for (int k = 0; k < 2; k++) {
        phase_16 = (phase_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_16) & 127;
    }
    int segment_49 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_49 > 31) {
        acc = (acc + segment_49 * 2 + 5) & 127;
        aux ^= (segment_49 & 15);
    } else {
        acc = (acc - segment_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000319_0;
    int sec_r000319_1;
    int sec_r000319_2;
    int sec_r000319_3;
    int sec_r000319_4;
    int sec_r000319_5;
    int sec_r000319_6;
    int sec_r000319_7;
    int sec_r000319_8;
    int sec_r000319_9;
    int sec_r000319_10;
    int sec_r000319_11;
    int sec_r000319_12;
    int sec_r000319_13;
    int sec_r000319_14;
    int sec_r000319_15;
    int sec_r000319_16;
    int sec_r000319_17;
    int pub_r000319_0;
    int pub_r000319_1;
    int pub_r000319_2;
    int pub_r000319_3;
    int pub_r000319_4;
    int pub_r000319_5;
    int pub_r000319_6;
    int pub_r000319_7;
    int pub_r000319_8;
    int pub_r000319_9;
    int pub_r000319_10;
    int pub_r000319_11;
    int pub_r000319_12;
    int pub_r000319_13;
    int pub_r000319_14;
    int pub_r000319_15;
    int pub_r000319_16;
    int pub_r000319_17;
    int pub_r000319_18;
    int pub_r000319_19;
    int pub_r000319_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000319_0 >= -100 && pub_r000319_0 <= 100);
    __CPROVER_assume(pub_r000319_1 >= -100 && pub_r000319_1 <= 100);
    __CPROVER_assume(pub_r000319_2 >= -100 && pub_r000319_2 <= 100);
    __CPROVER_assume(pub_r000319_3 >= -100 && pub_r000319_3 <= 100);
    __CPROVER_assume(pub_r000319_4 >= -100 && pub_r000319_4 <= 100);
    __CPROVER_assume(pub_r000319_5 >= -100 && pub_r000319_5 <= 100);
    __CPROVER_assume(pub_r000319_6 >= -100 && pub_r000319_6 <= 100);
    __CPROVER_assume(pub_r000319_7 >= -100 && pub_r000319_7 <= 100);
    __CPROVER_assume(pub_r000319_8 >= -100 && pub_r000319_8 <= 100);
    __CPROVER_assume(pub_r000319_9 >= -100 && pub_r000319_9 <= 100);
    __CPROVER_assume(pub_r000319_10 >= -100 && pub_r000319_10 <= 100);
    __CPROVER_assume(pub_r000319_11 >= -100 && pub_r000319_11 <= 100);
    __CPROVER_assume(pub_r000319_12 >= -100 && pub_r000319_12 <= 100);
    __CPROVER_assume(pub_r000319_13 >= -100 && pub_r000319_13 <= 100);
    __CPROVER_assume(pub_r000319_14 >= -100 && pub_r000319_14 <= 100);
    __CPROVER_assume(pub_r000319_15 >= -100 && pub_r000319_15 <= 100);
    __CPROVER_assume(pub_r000319_16 >= -100 && pub_r000319_16 <= 100);
    __CPROVER_assume(pub_r000319_17 >= -100 && pub_r000319_17 <= 100);
    __CPROVER_assume(pub_r000319_18 >= -100 && pub_r000319_18 <= 100);
    __CPROVER_assume(pub_r000319_19 >= -100 && pub_r000319_19 <= 100);
    __CPROVER_assume(pub_r000319_20 >= -100 && pub_r000319_20 <= 100);
    __CPROVER_assume(sec_r000319_0 >= 0 && sec_r000319_0 <= 255);
    __CPROVER_assume(sec_r000319_1 >= 0 && sec_r000319_1 <= 255);
    __CPROVER_assume(sec_r000319_2 >= 0 && sec_r000319_2 <= 255);
    __CPROVER_assume(sec_r000319_3 >= 0 && sec_r000319_3 <= 255);
    __CPROVER_assume(sec_r000319_4 >= 0 && sec_r000319_4 <= 255);
    __CPROVER_assume(sec_r000319_5 >= 0 && sec_r000319_5 <= 255);
    __CPROVER_assume(sec_r000319_6 >= 0 && sec_r000319_6 <= 255);
    __CPROVER_assume(sec_r000319_7 >= 0 && sec_r000319_7 <= 255);
    __CPROVER_assume(sec_r000319_8 >= 0 && sec_r000319_8 <= 255);
    __CPROVER_assume(sec_r000319_9 >= 0 && sec_r000319_9 <= 255);
    __CPROVER_assume(sec_r000319_10 >= 0 && sec_r000319_10 <= 255);
    __CPROVER_assume(sec_r000319_11 >= 0 && sec_r000319_11 <= 255);
    __CPROVER_assume(sec_r000319_12 >= 0 && sec_r000319_12 <= 255);
    __CPROVER_assume(sec_r000319_13 >= 0 && sec_r000319_13 <= 255);
    __CPROVER_assume(sec_r000319_14 >= 0 && sec_r000319_14 <= 255);
    __CPROVER_assume(sec_r000319_15 >= 0 && sec_r000319_15 <= 255);
    __CPROVER_assume(sec_r000319_16 >= 0 && sec_r000319_16 <= 255);
    __CPROVER_assume(sec_r000319_17 >= 0 && sec_r000319_17 <= 255);

    struct Transaction_R000319_1913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000319_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000319_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000319_0 + 7) & 15;
    struct DeviceConfig_R000319_1913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000319_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000319_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000319_0 + 9) & 15;
    struct CipherContext_R000319_1913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000319_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000319_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000319_0 + 11) & 15;

    union ColorPixel_R000319_1913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 35) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 50) {
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
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 18) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 33) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 19) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 34) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 31) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 46) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 31) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 46) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 34) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 49) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 21) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 36) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 37) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 52) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_2.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 11) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 26) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 22) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 37) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_1.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 19) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 34) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[2] * 2 + 256) & 63;
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
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (out_sink > 100) ? (chk_sum & 31) : (92 & 31);
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= (stage_v_87 << 1) & 127;

    /* Execution Pipeline Stage 88 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 89) & 15;
    int stage_v_88 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= stage_v_88;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_2.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
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

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] * 2 + 277) & 63;
    if (stage_v_90 > 30) {
        out_sink = (out_sink + stage_v_90 - 5) & 255;
        if (stage_v_90 > 45) {
            chk_sum ^= (stage_v_90 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_90 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2];
    table[2] = (table[3] + 189) & 63;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_95 = (stage_v_95 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 98) & 15;
    int stage_v_97 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= stage_v_97;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = table[3];
    table[3] = (table[0] + 199) & 63;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 36) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 51) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_1.buffer[0] ^ 106) & 3;
    switch (stage_v_103) {
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

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (out_sink > 100) ? (chk_sum & 31) : (109 & 31);
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= (stage_v_104 << 1) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_0.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 10) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 25) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 117) & 15;
    int stage_v_116 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= stage_v_116;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_0.buffer[0] * 2 + 358) & 63;
    if (stage_v_117 > 32) {
        out_sink = (out_sink + stage_v_117 - 5) & 255;
        if (stage_v_117 > 47) {
            chk_sum ^= (stage_v_117 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_117 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_120 = table[0];
    table[0] = (table[1] + 241) & 63;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_1.buffer[1] * 2 + 379) & 63;
    if (stage_v_124 > 36) {
        out_sink = (out_sink + stage_v_124 - 5) & 255;
        if (stage_v_124 > 51) {
            chk_sum ^= (stage_v_124 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_124 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 125 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 126) & 15;
    int stage_v_125 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= stage_v_125;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_127 = (stage_v_127 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_0.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_1.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 30) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 45) {
            chk_sum ^= (stage_v_130 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_130 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_136 = (st_var_1.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_137 = (stage_v_137 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[1] * 2 + 433) & 63;
    if (stage_v_142 > 40) {
        out_sink = (out_sink + stage_v_142 - 5) & 255;
        if (stage_v_142 > 55) {
            chk_sum ^= (stage_v_142 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_142 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_2.buffer[0] ^ 146) & 3;
    switch (stage_v_143) {
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

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_147 = (stage_v_147 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = table[1];
    table[1] = (table[2] + 299) & 63;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (out_sink > 100) ? (chk_sum & 31) : (155 & 31);
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= (stage_v_150 << 1) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (out_sink > 100) ? (chk_sum & 31) : (156 & 31);
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= (stage_v_151 << 1) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_2.buffer[0] ^ 155) & 3;
    switch (stage_v_152) {
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

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] ^ 156) & 3;
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 155) & 15;
    int stage_v_154 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= stage_v_154;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = table[3];
    table[3] = (table[0] + 311) & 63;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = table[1];
    table[1] = (table[2] + 315) & 63;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] * 2 + 493) & 63;
    if (stage_v_162 > 30) {
        out_sink = (out_sink + stage_v_162 - 5) & 255;
        if (stage_v_162 > 45) {
            chk_sum ^= (stage_v_162 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_162 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 163 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_0.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 28) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 43) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2];
    table[2] = (table[3] + 333) & 63;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] ^ 171) & 3;
    switch (stage_v_168) {
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

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[0] ^ 172) & 3;
    switch (stage_v_169) {
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

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_2.buffer[2] * 2 + 517) & 63;
    if (stage_v_170 > 18) {
        out_sink = (out_sink + stage_v_170 - 5) & 255;
        if (stage_v_170 > 33) {
            chk_sum ^= (stage_v_170 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_170 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_0.buffer[0] ^ 174) & 3;
    switch (stage_v_171) {
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

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = table[2];
    table[2] = (table[3] + 349) & 63;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[1] * 2 + 532) & 63;
    if (stage_v_175 > 24) {
        out_sink = (out_sink + stage_v_175 - 5) & 255;
        if (stage_v_175 > 39) {
            chk_sum ^= (stage_v_175 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_175 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (out_sink > 100) ? (chk_sum & 31) : (181 & 31);
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= (stage_v_176 << 1) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_0.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 15) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 30) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_180 = (stage_v_180 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_180) & 127;
    }
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (out_sink > 100) ? (chk_sum & 31) : (186 & 31);
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= (stage_v_181 << 1) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Security Information Flow: Family = arithmetic_flow */
    int arith_v_0 = (sec_r000319_14 * 3 + pub_r000319_18) & 127;
    int arith_v_1 = (arith_v_0 - (sec_r000319_9 * 2)) & 127;
    int arith_v_2 = (arith_v_1 - (sec_r000319_10 * 2)) & 127;
    int arith_v_3 = (arith_v_2 ^ (sec_r000319_4 * 2)) & 127;
    out_sink += arith_v_3 & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
