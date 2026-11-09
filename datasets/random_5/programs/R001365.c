/*
 * Benchmark Program: R001365
 * Security Family: bitwise_flow
 * Generator Seed: 636513
 * High Inputs: 22 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001365_6513_0 {
    unsigned char watermark;
    int head;
    int checksum;
    int capacity;
    unsigned char state;
    int tail;
    int buffer[3];
};

struct DeviceConfig_R001365_6513_1 {
    int timeout;
    unsigned char id;
    int parity;
    short baud_rate;
    short port;
    int buffer[3];
};

union RegisterBank_R001365_6513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001365_6513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001365_6513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_31) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_92 = (aux + st.buffer[1]) & 3;
    switch (metric_92) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_64 = (aux + st.buffer[1]) & 3;
    switch (phase_64) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_88 = local_arr[aux % 3];
    acc = (acc + weight_88 * 2) & 127;
    int quotient_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001365_6513_2(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int scale_48 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_48 > 29) {
        acc = (acc + scale_48 * 2 + 5) & 127;
        aux ^= (scale_48 & 15);
    } else {
        acc = (acc - scale_48 + 11) & 127;
        aux += 3;
    }
    int index_reg_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_75) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001365_6513_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_44 = (aux + st.buffer[1]) & 3;
    switch (weight_44) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_54 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_54 > 37) {
        acc = (acc + stride_54 * 2 + 5) & 127;
        aux ^= (stride_54 & 15);
    } else {
        acc = (acc - stride_54 + 11) & 127;
        aux += 3;
    }
    int damping_49 = 0;
    for (int k = 0; k < 3; k++) {
        damping_49 = (damping_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int sample_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_94) & 63;
    acc ^= aux;
    int phase_59 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_59 > 10) {
        acc = (acc + phase_59 * 2 + 5) & 127;
        aux ^= (phase_59 & 15);
    } else {
        acc = (acc - phase_59 + 11) & 127;
        aux += 3;
    }
    int quantum_61 = (aux + st.buffer[1]) & 3;
    switch (quantum_61) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int parity_50 = 0;
    for (int k = 0; k < 2; k++) {
        parity_50 = (parity_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_50) & 127;
    }
    int stride_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_88) & 63;
    acc ^= aux;
    int vector_82 = (aux + st.buffer[1]) & 3;
    switch (vector_82) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tracker_50 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_50 = (tracker_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_50) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_62 = local_arr[aux % 3];
    acc = (acc + stride_62 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_55 = (aux + st.buffer[1]) & 3;
    switch (tally_55) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_7(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int index_reg_48 = local_arr[aux % 3];
    acc = (acc + index_reg_48 * 2) & 127;
    int pivot_74 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_74 = (pivot_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_74) & 127;
    }
    int residue_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001365_6513_8(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_39 = (aux + st.buffer[1]) & 3;
    switch (index_reg_39) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_9(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_38 = (aux + st.buffer[1]) & 3;
    switch (accumulator_38) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_83) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_31 = local_arr[aux % 3];
    acc = (acc + anchor_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001365_6513_10(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int coefficient_38 = local_arr[aux % 3];
    acc = (acc + coefficient_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_89) & 63;
    acc ^= aux;
    int vector_70 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_70 > 10) {
        acc = (acc + vector_70 * 2 + 5) & 127;
        aux ^= (vector_70 & 15);
    } else {
        acc = (acc - vector_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_70 = (aux + st.buffer[1]) & 3;
    switch (segment_70) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_94) & 63;
    acc ^= aux;
    int delta_77 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_77 > 40) {
        acc = (acc + delta_77 * 2 + 5) & 127;
        aux ^= (delta_77 & 15);
    } else {
        acc = (acc - delta_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_12(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int damping_75 = local_arr[aux % 3];
    acc = (acc + damping_75 * 2) & 127;
    int checksum_97 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_97 = (checksum_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_97) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int tally_65 = local_arr[aux % 3];
    acc = (acc + tally_65 * 2) & 127;
    int margin_31 = 0;
    for (int k = 0; k < 2; k++) {
        margin_31 = (margin_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_31) & 127;
    }
    int margin_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_79) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001365_6513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int mask_46 = (aux + st.buffer[1]) & 3;
    switch (mask_46) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_31 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_31 > 30) {
        acc = (acc + segment_31 * 2 + 5) & 127;
        aux ^= (segment_31 & 15);
    } else {
        acc = (acc - segment_31 + 11) & 127;
        aux += 3;
    }
    int phase_14 = 0;
    for (int k = 0; k < 2; k++) {
        phase_14 = (phase_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_15(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int metric_99 = (aux + st.buffer[1]) & 3;
    switch (metric_99) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_28 = local_arr[aux % 3];
    acc = (acc + tracker_28 * 2) & 127;
    int factor_71 = 0;
    for (int k = 0; k < 2; k++) {
        factor_71 = (factor_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_40 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_40 = (threshold_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_40) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_22 = local_arr[aux % 3];
    acc = (acc + cursor_22 * 2) & 127;
    int coefficient_98 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_98 > 39) {
        acc = (acc + coefficient_98 * 2 + 5) & 127;
        aux ^= (coefficient_98 & 15);
    } else {
        acc = (acc - coefficient_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_17(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int vector_25 = local_arr[aux % 3];
    acc = (acc + vector_25 * 2) & 127;
    int parity_31 = (aux + st.buffer[1]) & 3;
    switch (parity_31) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001365_6513_18(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int window_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_61) & 63;
    acc ^= aux;
    int tracker_86 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_86 = (tracker_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_86) & 127;
    }
    int sample_96 = (aux + st.buffer[1]) & 3;
    switch (sample_96) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001365_6513_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int tracker_33 = local_arr[aux % 3];
    acc = (acc + tracker_33 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001365_6513_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001365_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int sample_99 = local_arr[aux % 3];
    acc = (acc + sample_99 * 2) & 127;
    int segment_57 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_57 > 30) {
        acc = (acc + segment_57 * 2 + 5) & 127;
        aux ^= (segment_57 & 15);
    } else {
        acc = (acc - segment_57 + 11) & 127;
        aux += 3;
    }
    int mask_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_43) & 63;
    acc ^= aux;
    int window_28 = 0;
    for (int k = 0; k < 3; k++) {
        window_28 = (window_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001365_6513_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001365_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int parity_78 = 0;
    for (int k = 0; k < 3; k++) {
        parity_78 = (parity_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_78) & 127;
    }
    int stride_42 = (aux + st.buffer[1]) & 3;
    switch (stride_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001365_0;
    int sec_r001365_1;
    int sec_r001365_2;
    int sec_r001365_3;
    int sec_r001365_4;
    int sec_r001365_5;
    int sec_r001365_6;
    int sec_r001365_7;
    int sec_r001365_8;
    int sec_r001365_9;
    int sec_r001365_10;
    int sec_r001365_11;
    int sec_r001365_12;
    int sec_r001365_13;
    int sec_r001365_14;
    int sec_r001365_15;
    int sec_r001365_16;
    int sec_r001365_17;
    int sec_r001365_18;
    int sec_r001365_19;
    int sec_r001365_20;
    int sec_r001365_21;
    int pub_r001365_0;
    int pub_r001365_1;
    int pub_r001365_2;
    int pub_r001365_3;
    int pub_r001365_4;
    int pub_r001365_5;
    int pub_r001365_6;
    int pub_r001365_7;
    int pub_r001365_8;
    int pub_r001365_9;
    int pub_r001365_10;
    int pub_r001365_11;
    int pub_r001365_12;
    int pub_r001365_13;
    int pub_r001365_14;
    int pub_r001365_15;
    int pub_r001365_16;
    int pub_r001365_17;
    int pub_r001365_18;
    int pub_r001365_19;
    int pub_r001365_20;
    int pub_r001365_21;
    int pub_r001365_22;
    int pub_r001365_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001365_0 >= -100 && pub_r001365_0 <= 100);
    __CPROVER_assume(pub_r001365_1 >= -100 && pub_r001365_1 <= 100);
    __CPROVER_assume(pub_r001365_2 >= -100 && pub_r001365_2 <= 100);
    __CPROVER_assume(pub_r001365_3 >= -100 && pub_r001365_3 <= 100);
    __CPROVER_assume(pub_r001365_4 >= -100 && pub_r001365_4 <= 100);
    __CPROVER_assume(pub_r001365_5 >= -100 && pub_r001365_5 <= 100);
    __CPROVER_assume(pub_r001365_6 >= -100 && pub_r001365_6 <= 100);
    __CPROVER_assume(pub_r001365_7 >= -100 && pub_r001365_7 <= 100);
    __CPROVER_assume(pub_r001365_8 >= -100 && pub_r001365_8 <= 100);
    __CPROVER_assume(pub_r001365_9 >= -100 && pub_r001365_9 <= 100);
    __CPROVER_assume(pub_r001365_10 >= -100 && pub_r001365_10 <= 100);
    __CPROVER_assume(pub_r001365_11 >= -100 && pub_r001365_11 <= 100);
    __CPROVER_assume(pub_r001365_12 >= -100 && pub_r001365_12 <= 100);
    __CPROVER_assume(pub_r001365_13 >= -100 && pub_r001365_13 <= 100);
    __CPROVER_assume(pub_r001365_14 >= -100 && pub_r001365_14 <= 100);
    __CPROVER_assume(pub_r001365_15 >= -100 && pub_r001365_15 <= 100);
    __CPROVER_assume(pub_r001365_16 >= -100 && pub_r001365_16 <= 100);
    __CPROVER_assume(pub_r001365_17 >= -100 && pub_r001365_17 <= 100);
    __CPROVER_assume(pub_r001365_18 >= -100 && pub_r001365_18 <= 100);
    __CPROVER_assume(pub_r001365_19 >= -100 && pub_r001365_19 <= 100);
    __CPROVER_assume(pub_r001365_20 >= -100 && pub_r001365_20 <= 100);
    __CPROVER_assume(pub_r001365_21 >= -100 && pub_r001365_21 <= 100);
    __CPROVER_assume(pub_r001365_22 >= -100 && pub_r001365_22 <= 100);
    __CPROVER_assume(pub_r001365_23 >= -100 && pub_r001365_23 <= 100);
    __CPROVER_assume(sec_r001365_0 >= 0 && sec_r001365_0 <= 255);
    __CPROVER_assume(sec_r001365_1 >= 0 && sec_r001365_1 <= 255);
    __CPROVER_assume(sec_r001365_2 >= 0 && sec_r001365_2 <= 255);
    __CPROVER_assume(sec_r001365_3 >= 0 && sec_r001365_3 <= 255);
    __CPROVER_assume(sec_r001365_4 >= 0 && sec_r001365_4 <= 255);
    __CPROVER_assume(sec_r001365_5 >= 0 && sec_r001365_5 <= 255);
    __CPROVER_assume(sec_r001365_6 >= 0 && sec_r001365_6 <= 255);
    __CPROVER_assume(sec_r001365_7 >= 0 && sec_r001365_7 <= 255);
    __CPROVER_assume(sec_r001365_8 >= 0 && sec_r001365_8 <= 255);
    __CPROVER_assume(sec_r001365_9 >= 0 && sec_r001365_9 <= 255);
    __CPROVER_assume(sec_r001365_10 >= 0 && sec_r001365_10 <= 255);
    __CPROVER_assume(sec_r001365_11 >= 0 && sec_r001365_11 <= 255);
    __CPROVER_assume(sec_r001365_12 >= 0 && sec_r001365_12 <= 255);
    __CPROVER_assume(sec_r001365_13 >= 0 && sec_r001365_13 <= 255);
    __CPROVER_assume(sec_r001365_14 >= 0 && sec_r001365_14 <= 255);
    __CPROVER_assume(sec_r001365_15 >= 0 && sec_r001365_15 <= 255);
    __CPROVER_assume(sec_r001365_16 >= 0 && sec_r001365_16 <= 255);
    __CPROVER_assume(sec_r001365_17 >= 0 && sec_r001365_17 <= 255);
    __CPROVER_assume(sec_r001365_18 >= 0 && sec_r001365_18 <= 255);
    __CPROVER_assume(sec_r001365_19 >= 0 && sec_r001365_19 <= 255);
    __CPROVER_assume(sec_r001365_20 >= 0 && sec_r001365_20 <= 255);
    __CPROVER_assume(sec_r001365_21 >= 0 && sec_r001365_21 <= 255);

    struct StreamBuffer_R001365_6513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001365_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001365_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001365_0 + 7) & 15;
    struct DeviceConfig_R001365_6513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001365_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001365_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001365_0 + 9) & 15;

    union RegisterBank_R001365_6513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001365_6513_0(sec_r001365_0, pub_r001365_1, pub_r001365_2, pub_r001365_3, pub_r001365_4);
    int helper_flow_1 = fn_R001365_6513_1(sec_r001365_1, sec_r001365_2, pub_r001365_3, pub_r001365_4, pub_r001365_5);
    int helper_flow_2 = fn_R001365_6513_2(sec_r001365_2, sec_r001365_3, pub_r001365_4);
    int helper_flow_3 = fn_R001365_6513_3(sec_r001365_3, pub_r001365_4, pub_r001365_5, pub_r001365_6);
    int helper_flow_4 = fn_R001365_6513_4(sec_r001365_4, pub_r001365_5, pub_r001365_6, pub_r001365_7, pub_r001365_8);
    int helper_flow_5 = fn_R001365_6513_5(sec_r001365_5, sec_r001365_6, pub_r001365_7, pub_r001365_8, pub_r001365_9);
    int helper_flow_6 = fn_R001365_6513_6(sec_r001365_6, pub_r001365_7, pub_r001365_8, pub_r001365_9);
    int helper_flow_7 = fn_R001365_6513_7(sec_r001365_7, sec_r001365_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_0 << 1) ^ (pub_r001365_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_1 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001365_23 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001365_15 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001365_21 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001365_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001365_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001365_20 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001365_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001365_16 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001365_22 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001365_3 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001365_22 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001365_7 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001365_20 << 1) ^ (pub_r001365_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_3 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001365_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001365_9 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001365_15 << 1) ^ (pub_r001365_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001365_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_7 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001365_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_15 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001365_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001365_5 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001365_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001365_19 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001365_8 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_17 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_24 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001365_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001365_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001365_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001365_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_28 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_17 << 1) ^ (pub_r001365_23 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_13 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001365_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001365_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001365_4 << 1) ^ (pub_r001365_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_18 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((helper_flow_4 << 1) ^ (pub_r001365_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001365_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001365_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001365_8 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001365_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001365_14 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001365_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_44 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_1 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_7 << 1) ^ (pub_r001365_21 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_36 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_49 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001365_19 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_27 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001365_21 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001365_11 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001365_3 << 1) ^ (pub_r001365_21 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001365_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001365_9 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_59 + 1) & 15;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001365_13 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001365_19 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_3 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001365_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001365_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001365_23 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001365_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_39 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001365_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_48 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001365_9 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_69 << 1) ^ (pub_r001365_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_22 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_54 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_73 + 1) & 15;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_61 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001365_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001365_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001365_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001365_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_13 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_27 << 1) ^ (pub_r001365_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_13 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_81 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((helper_flow_7 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_71 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_72 << 1) ^ (pub_r001365_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_71 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001365_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_55 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001365_17 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001365_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001365_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_69 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001365_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001365_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_61 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001365_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001365_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001365_18 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001365_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_52 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001365_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001365_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001365_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001365_18 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001365_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_74 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_81 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001365_17 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_98 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001365_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001365_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001365_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001365_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001365_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001365_12 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001365_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_48 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001365_22 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_41 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001365_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_98 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001365_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_51 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001365_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((helper_flow_7 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_24 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_56 << 1) ^ (pub_r001365_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_40 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_62 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_11 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r001365_8 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_55 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001365_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_28 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001365_4 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001365_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_67 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001365_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_82 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_44 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001365_7 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_81 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001365_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_18 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_131 << 1) ^ (pub_r001365_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001365_18 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001365_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001365_20 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_108 << 1) ^ (pub_r001365_21 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_115 << 1) ^ (pub_r001365_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_128 << 1) ^ (pub_r001365_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_128 << 1) ^ (pub_r001365_21 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001365_17 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001365_1 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001365_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_81 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001365_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001365_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001365_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_24 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_117 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r001365_13 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_7 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001365_20 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001365_23 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_85 << 1) ^ (pub_r001365_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_152 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001365_22 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001365_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001365_1 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_9 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001365_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001365_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001365_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001365_18 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001365_10 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_95 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_104 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_11 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_154 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_83 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_181 + 1) & 15;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_24 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_126 << 1) ^ (pub_r001365_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_83 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_55 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001365_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r001365_9 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001365_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001365_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001365_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_14 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_185 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001365_23 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001365_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001365_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001365_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001365_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001365_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((helper_flow_7 << 1) ^ (pub_r001365_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r001365_9 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001365_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001365_21 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001365_10 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001365_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_135 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_44 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_52 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_121 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_3 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_150 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_200 << 1) ^ (pub_r001365_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_80 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_0 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001365_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001365_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r001365_13 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001365_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001365_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001365_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001365_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001365_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001365_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_72 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_89 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001365_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001365_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_74 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r001365_11 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001365_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_61 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_200 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001365_20 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001365_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001365_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_212 << 1) ^ (pub_r001365_23 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001365_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001365_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001365_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_154 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001365_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001365_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001365_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001365_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_49 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_44 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_166 << 1) ^ (pub_r001365_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001365_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_85 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001365_21 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001365_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001365_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_89 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_83 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_144 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r001365_9 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_213 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001365_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_57 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_132 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_27 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001365_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_227 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_142 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001365_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_141 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_260 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001365_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((sec_r001365_5 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_268 + 1) & 15;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001365_22 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001365_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001365_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001365_20 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_203 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001365_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_228 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r001365_15 << 1) ^ (pub_r001365_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((helper_flow_3 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_104 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_192 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_40 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001365_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_61 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_20 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001365_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001365_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((sec_r001365_12 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001365_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001365_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_230 << 1) ^ (pub_r001365_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001365_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_252 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r001365_0 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001365_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_191 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001365_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001365_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_108 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_35 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_262 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001365_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001365_21 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001365_22 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001365_22 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001365_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((sec_r001365_17 << 1) ^ (pub_r001365_23 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_82 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_149 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_192 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001365_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_130 << 1) ^ (pub_r001365_22 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001365_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_121 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_89 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_171 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_60 << 1) ^ (pub_r001365_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001365_22 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_224 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_299 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_34 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_227 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_319 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001365_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((helper_flow_3 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001365_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_216 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001365_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_131 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001365_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_255 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001365_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_35 << 1) ^ (pub_r001365_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001365_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001365_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_108 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001365_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001365_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_1 << 1) ^ (pub_r001365_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001365_22 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_327 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001365_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_92 << 1) ^ (pub_r001365_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001365_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_156 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001365_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001365_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001365_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_129 << 1) ^ (pub_r001365_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_306 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((sec_r001365_0 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001365_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_81 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001365_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001365_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001365_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_331 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_50 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001365_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001365_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001365_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_283 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_291 << 1) ^ (pub_r001365_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001365_22 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001365_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001365_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001365_21 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001365_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_44 << 1) ^ (pub_r001365_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_255 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001365_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_79 << 1) ^ (pub_r001365_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001365_20 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_361 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001365_20 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001365_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_268 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001365_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001365_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001365_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001365_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001365_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001365_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((sec_r001365_17 << 1) ^ (pub_r001365_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_239 << 1) ^ (pub_r001365_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_86 << 1) ^ (pub_r001365_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001365_20 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_108 << 1) ^ (pub_r001365_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001365_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_28 << 1) ^ (pub_r001365_20 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001365_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_203 << 1) ^ (pub_r001365_23 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_71 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001365_22 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001365_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001365_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_107 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001365_20 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_57 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001365_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_203 << 1) ^ (pub_r001365_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001365_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_191 << 1) ^ (pub_r001365_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_329 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001365_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_265 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_192 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001365_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_367 << 1) ^ (pub_r001365_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_199 << 1) ^ (pub_r001365_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001365_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001365_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_179 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_315 << 1) ^ (pub_r001365_22 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_212 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001365_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001365_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001365_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_15 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_3 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001365_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_44 << 1) ^ (pub_r001365_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_134 << 1) ^ (pub_r001365_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001365_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_305 << 1) ^ (pub_r001365_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_383 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((sec_r001365_12 << 1) ^ (pub_r001365_21 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_74 << 1) ^ (pub_r001365_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001365_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_263 << 1) ^ (pub_r001365_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001365_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_185 << 1) ^ (pub_r001365_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001365_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_428 << 1) ^ (pub_r001365_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_432 + 1) & 15;
    out_sink ^= (stage_v_432 & 63);

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001365_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001365_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_162 << 1) ^ (pub_r001365_18 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001365_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_314 << 1) ^ (pub_r001365_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001365_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_79 << 1) ^ (pub_r001365_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001365_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_424 << 1) ^ (pub_r001365_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_54 << 1) ^ (pub_r001365_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_132 << 1) ^ (pub_r001365_23 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_117 << 1) ^ (pub_r001365_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001365_1 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_314 << 1) ^ (pub_r001365_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
