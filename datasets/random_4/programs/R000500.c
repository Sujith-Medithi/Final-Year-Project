/*
 * Benchmark Program: R000500
 * Family: bitwise_flow
 * Generator Seed: 450013
 * High Inputs: 18 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000500_13_0 {
    short damping;
    int mode;
    short cutoff;
    short prev_out;
    int prev_in;
    int gain_db;
    int buffer[3];
};

struct DeviceConfig_R000500_13_1 {
    int baud_rate;
    int parity;
    unsigned char port;
    short id;
    short timeout;
    int buffer[3];
};

union PacketPayload_R000500_13_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000500_13_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000500_13_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_83 = 0;
    for (int k = 0; k < 3; k++) {
        metric_83 = (metric_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_83) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_27 = local_arr[aux % 3];
    acc = (acc + sample_27 * 2) & 127;
    int cursor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000500_13_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int metric_16 = local_arr[aux % 3];
    acc = (acc + metric_16 * 2) & 127;
    int phase_63 = 0;
    for (int k = 0; k < 3; k++) {
        phase_63 = (phase_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_63) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_79 = (aux + st.buffer[1]) & 3;
    switch (factor_79) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_2(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int accumulator_59 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_59 > 39) {
        acc = (acc + accumulator_59 * 2 + 5) & 127;
        aux ^= (accumulator_59 & 15);
    } else {
        acc = (acc - accumulator_59 + 11) & 127;
        aux += 3;
    }
    int window_23 = 0;
    for (int k = 0; k < 3; k++) {
        window_23 = (window_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_23) & 127;
    }
    int bound_86 = (aux + st.buffer[1]) & 3;
    switch (bound_86) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_80 = local_arr[aux % 3];
    acc = (acc + index_reg_80 * 2) & 127;
    int pivot_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000500_13_4(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_94 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_94 > 16) {
        acc = (acc + coefficient_94 * 2 + 5) & 127;
        aux ^= (coefficient_94 & 15);
    } else {
        acc = (acc - coefficient_94 + 11) & 127;
        aux += 3;
    }
    int tracker_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_76) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_32 = local_arr[aux % 3];
    acc = (acc + accumulator_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int tally_29 = local_arr[aux % 3];
    acc = (acc + tally_29 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_39 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_39 > 26) {
        acc = (acc + cursor_39 * 2 + 5) & 127;
        aux ^= (cursor_39 & 15);
    } else {
        acc = (acc - cursor_39 + 11) & 127;
        aux += 3;
    }
    int delta_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000500_13_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int segment_13 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_13 > 45) {
        acc = (acc + segment_13 * 2 + 5) & 127;
        aux ^= (segment_13 & 15);
    } else {
        acc = (acc - segment_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_93 = local_arr[aux % 3];
    acc = (acc + stride_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_25 = (aux + st.buffer[1]) & 3;
    switch (cursor_25) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_8(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int bound_91 = local_arr[aux % 3];
    acc = (acc + bound_91 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000500_13_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int sample_25 = 0;
    for (int k = 0; k < 2; k++) {
        sample_25 = (sample_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_25) & 127;
    }
    int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000500_13_10(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_36 = (aux + st.buffer[1]) & 3;
    switch (bound_36) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_26) & 63;
    acc ^= aux;
    int residue_64 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_64 > 35) {
        acc = (acc + residue_64 * 2 + 5) & 127;
        aux ^= (residue_64 & 15);
    } else {
        acc = (acc - residue_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_11(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int cursor_92 = local_arr[aux % 3];
    acc = (acc + cursor_92 * 2) & 127;
    int checksum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_80) & 63;
    acc ^= aux;
    int pivot_13 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_13 = (pivot_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_12(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int window_40 = local_arr[aux % 3];
    acc = (acc + window_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quantum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_23) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_96 = local_arr[aux % 3];
    acc = (acc + stride_96 * 2) & 127;
    int accumulator_81 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_81 > 45) {
        acc = (acc + accumulator_81 * 2 + 5) & 127;
        aux ^= (accumulator_81 & 15);
    } else {
        acc = (acc - accumulator_81 + 11) & 127;
        aux += 3;
    }
    int cursor_95 = (aux + st.buffer[1]) & 3;
    switch (cursor_95) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int margin_31 = (aux + st.buffer[1]) & 3;
    switch (margin_31) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_69) & 63;
    acc ^= aux;
    int phase_10 = 0;
    for (int k = 0; k < 3; k++) {
        phase_10 = (phase_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_10) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_15(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tracker_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_30 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_30 > 48) {
        acc = (acc + mask_30 * 2 + 5) & 127;
        aux ^= (mask_30 & 15);
    } else {
        acc = (acc - mask_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_53 = local_arr[aux % 3];
    acc = (acc + cursor_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_18) & 63;
    acc ^= aux;
    int phase_12 = (aux + st.buffer[1]) & 3;
    switch (phase_12) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_13 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_13 > 49) {
        acc = (acc + index_reg_13 * 2 + 5) & 127;
        aux ^= (index_reg_13 & 15);
    } else {
        acc = (acc - index_reg_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_17(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_24 = local_arr[aux % 3];
    acc = (acc + quotient_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int parity_46 = local_arr[aux % 3];
    acc = (acc + parity_46 * 2) & 127;
    int coefficient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_64) & 63;
    acc ^= aux;
    int tally_88 = 0;
    for (int k = 0; k < 2; k++) {
        tally_88 = (tally_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_88) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_19(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int weight_82 = local_arr[aux % 3];
    acc = (acc + weight_82 * 2) & 127;
    int phase_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_83) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_20(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_73) & 63;
    acc ^= aux;
    int tracker_13 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_13 = (tracker_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_13) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_22 = local_arr[aux % 3];
    acc = (acc + quantum_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_39 = (aux + st.buffer[1]) & 3;
    switch (tracker_39) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000500_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_83 = (aux + st.buffer[1]) & 3;
    switch (coefficient_83) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_69 = local_arr[aux % 3];
    acc = (acc + delta_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000500_13_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tracker_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_76 = local_arr[aux % 3];
    acc = (acc + sample_76 * 2) & 127;
    int sample_64 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_64 > 11) {
        acc = (acc + sample_64 * 2 + 5) & 127;
        aux ^= (sample_64 & 15);
    } else {
        acc = (acc - sample_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000500_13_24(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000500_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int index_reg_26 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_26 > 27) {
        acc = (acc + index_reg_26 * 2 + 5) & 127;
        aux ^= (index_reg_26 & 15);
    } else {
        acc = (acc - index_reg_26 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_47 = local_arr[aux % 3];
    acc = (acc + index_reg_47 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000500_0;
    int sec_r000500_1;
    int sec_r000500_2;
    int sec_r000500_3;
    int sec_r000500_4;
    int sec_r000500_5;
    int sec_r000500_6;
    int sec_r000500_7;
    int sec_r000500_8;
    int sec_r000500_9;
    int sec_r000500_10;
    int sec_r000500_11;
    int sec_r000500_12;
    int sec_r000500_13;
    int sec_r000500_14;
    int sec_r000500_15;
    int sec_r000500_16;
    int sec_r000500_17;
    int pub_r000500_0;
    int pub_r000500_1;
    int pub_r000500_2;
    int pub_r000500_3;
    int pub_r000500_4;
    int pub_r000500_5;
    int pub_r000500_6;
    int pub_r000500_7;
    int pub_r000500_8;
    int pub_r000500_9;
    int pub_r000500_10;
    int pub_r000500_11;
    int pub_r000500_12;
    int pub_r000500_13;
    int pub_r000500_14;
    int pub_r000500_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000500_0 >= -100 && pub_r000500_0 <= 100);
    __CPROVER_assume(pub_r000500_1 >= -100 && pub_r000500_1 <= 100);
    __CPROVER_assume(pub_r000500_2 >= -100 && pub_r000500_2 <= 100);
    __CPROVER_assume(pub_r000500_3 >= -100 && pub_r000500_3 <= 100);
    __CPROVER_assume(pub_r000500_4 >= -100 && pub_r000500_4 <= 100);
    __CPROVER_assume(pub_r000500_5 >= -100 && pub_r000500_5 <= 100);
    __CPROVER_assume(pub_r000500_6 >= -100 && pub_r000500_6 <= 100);
    __CPROVER_assume(pub_r000500_7 >= -100 && pub_r000500_7 <= 100);
    __CPROVER_assume(pub_r000500_8 >= -100 && pub_r000500_8 <= 100);
    __CPROVER_assume(pub_r000500_9 >= -100 && pub_r000500_9 <= 100);
    __CPROVER_assume(pub_r000500_10 >= -100 && pub_r000500_10 <= 100);
    __CPROVER_assume(pub_r000500_11 >= -100 && pub_r000500_11 <= 100);
    __CPROVER_assume(pub_r000500_12 >= -100 && pub_r000500_12 <= 100);
    __CPROVER_assume(pub_r000500_13 >= -100 && pub_r000500_13 <= 100);
    __CPROVER_assume(pub_r000500_14 >= -100 && pub_r000500_14 <= 100);
    __CPROVER_assume(pub_r000500_15 >= -100 && pub_r000500_15 <= 100);
    __CPROVER_assume(sec_r000500_0 >= 0 && sec_r000500_0 <= 255);
    __CPROVER_assume(sec_r000500_1 >= 0 && sec_r000500_1 <= 255);
    __CPROVER_assume(sec_r000500_2 >= 0 && sec_r000500_2 <= 255);
    __CPROVER_assume(sec_r000500_3 >= 0 && sec_r000500_3 <= 255);
    __CPROVER_assume(sec_r000500_4 >= 0 && sec_r000500_4 <= 255);
    __CPROVER_assume(sec_r000500_5 >= 0 && sec_r000500_5 <= 255);
    __CPROVER_assume(sec_r000500_6 >= 0 && sec_r000500_6 <= 255);
    __CPROVER_assume(sec_r000500_7 >= 0 && sec_r000500_7 <= 255);
    __CPROVER_assume(sec_r000500_8 >= 0 && sec_r000500_8 <= 255);
    __CPROVER_assume(sec_r000500_9 >= 0 && sec_r000500_9 <= 255);
    __CPROVER_assume(sec_r000500_10 >= 0 && sec_r000500_10 <= 255);
    __CPROVER_assume(sec_r000500_11 >= 0 && sec_r000500_11 <= 255);
    __CPROVER_assume(sec_r000500_12 >= 0 && sec_r000500_12 <= 255);
    __CPROVER_assume(sec_r000500_13 >= 0 && sec_r000500_13 <= 255);
    __CPROVER_assume(sec_r000500_14 >= 0 && sec_r000500_14 <= 255);
    __CPROVER_assume(sec_r000500_15 >= 0 && sec_r000500_15 <= 255);
    __CPROVER_assume(sec_r000500_16 >= 0 && sec_r000500_16 <= 255);
    __CPROVER_assume(sec_r000500_17 >= 0 && sec_r000500_17 <= 255);

    struct FilterState_R000500_13_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000500_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000500_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000500_0 + 7) & 15;
    struct DeviceConfig_R000500_13_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000500_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000500_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000500_0 + 9) & 15;

    union PacketPayload_R000500_13_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 33) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 48) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 10) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 25) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[0] ^ 13) & 3;
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
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 31) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 46) {
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
    if (stage_v_13 > 38) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 53) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 31) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 46) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

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
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 27) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 42) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 15) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 30) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 14) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 29) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 19) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 34) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 20) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 35) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 10) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 25) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_1.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 33) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 48) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 27) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 42) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 3; step++) {
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
    if (stage_v_73 > 10) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 25) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] * 2 + 259) & 63;
    if (stage_v_84 > 39) {
        out_sink = (out_sink + stage_v_84 - 5) & 255;
        if (stage_v_84 > 54) {
            chk_sum ^= (stage_v_84 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_84 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 39) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 54) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3];
    table[3] = (table[0] + 175) & 63;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (out_sink > 100) ? (chk_sum & 31) : (95 & 31);
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= (stage_v_90 << 1) & 127;

    /* Execution Pipeline Stage 91 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 92) & 15;
    int stage_v_91 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= stage_v_91;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_93 = (stage_v_93 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[1] * 2 + 289) & 63;
    if (stage_v_94 > 37) {
        out_sink = (out_sink + stage_v_94 - 5) & 255;
        if (stage_v_94 > 52) {
            chk_sum ^= (stage_v_94 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_94 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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
    int stage_v_99 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_101 = (stage_v_101 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_102 = (stage_v_102 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_1.buffer[0] ^ 106) & 3;
    switch (stage_v_103) {
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

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[2] * 2 + 319) & 63;
    if (stage_v_104 > 30) {
        out_sink = (out_sink + stage_v_104 - 5) & 255;
        if (stage_v_104 > 45) {
            chk_sum ^= (stage_v_104 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_104 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 17) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 32) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_109 = (stage_v_109 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_0.buffer[2] * 2 + 337) & 63;
    if (stage_v_110 > 17) {
        out_sink = (out_sink + stage_v_110 - 5) & 255;
        if (stage_v_110 > 32) {
            chk_sum ^= (stage_v_110 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_110 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 16) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 31) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] ^ 117) & 3;
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
    int stage_v_115 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_115 = (stage_v_115 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] * 2 + 358) & 63;
    if (stage_v_117 > 10) {
        out_sink = (out_sink + stage_v_117 - 5) & 255;
        if (stage_v_117 > 25) {
            chk_sum ^= (stage_v_117 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_117 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_119 = (stage_v_119 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] * 2 + 367) & 63;
    if (stage_v_120 > 11) {
        out_sink = (out_sink + stage_v_120 - 5) & 255;
        if (stage_v_120 > 26) {
            chk_sum ^= (stage_v_120 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_120 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_0.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 17) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 32) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_1.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 26) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 41) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[0] ^ 127) & 3;
    switch (stage_v_124) {
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

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] ^ 129) & 3;
    switch (stage_v_126) {
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

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
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
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] * 2 + 394) & 63;
    if (stage_v_129 > 24) {
        out_sink = (out_sink + stage_v_129 - 5) & 255;
        if (stage_v_129 > 39) {
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
    int stage_v_131 = (st_var_1.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 19) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 34) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] * 2 + 403) & 63;
    if (stage_v_132 > 29) {
        out_sink = (out_sink + stage_v_132 - 5) & 255;
        if (stage_v_132 > 44) {
            chk_sum ^= (stage_v_132 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_132 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[0] ^ 136) & 3;
    switch (stage_v_133) {
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

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (out_sink > 100) ? (chk_sum & 31) : (142 & 31);
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= (stage_v_137 << 1) & 127;

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[1] * 2 + 424) & 63;
    if (stage_v_139 > 17) {
        out_sink = (out_sink + stage_v_139 - 5) & 255;
        if (stage_v_139 > 32) {
            chk_sum ^= (stage_v_139 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_139 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 140 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 141) & 15;
    int stage_v_140 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    chk_sum ^= stage_v_140;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_0.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
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

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (out_sink > 100) ? (chk_sum & 31) : (148 & 31);
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= (stage_v_143 << 1) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_144 = (stage_v_144 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_1.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_0.buffer[1] * 2 + 451) & 63;
    if (stage_v_148 > 23) {
        out_sink = (out_sink + stage_v_148 - 5) & 255;
        if (stage_v_148 > 38) {
            chk_sum ^= (stage_v_148 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_148 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 24) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 39) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3];
    table[3] = (table[0] + 303) & 63;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_0.buffer[0] ^ 155) & 3;
    switch (stage_v_152) {
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

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
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

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[1] * 2 + 478) & 63;
    if (stage_v_157 > 13) {
        out_sink = (out_sink + stage_v_157 - 5) & 255;
        if (stage_v_157 > 28) {
            chk_sum ^= (stage_v_157 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_157 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 162) & 15;
    int stage_v_161 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= stage_v_161;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_164 = (stage_v_164 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 17) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 32) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 167) & 15;
    int stage_v_166 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= stage_v_166;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_167 = (stage_v_167 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_168 = (stage_v_168 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = table[1];
    table[1] = (table[2] + 339) & 63;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 172) & 15;
    int stage_v_171 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= stage_v_171;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_1.buffer[2] * 2 + 526) & 63;
    if (stage_v_173 > 34) {
        out_sink = (out_sink + stage_v_173 - 5) & 255;
        if (stage_v_173 > 49) {
            chk_sum ^= (stage_v_173 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_173 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] ^ 177) & 3;
    switch (stage_v_174) {
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

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = table[3];
    table[3] = (table[0] + 351) & 63;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Security Information Flow: Family = bitwise_flow */
    int b_w0 = (sec_r000500_2 ^ 0x5A) & 63;
    int b_w1 = ((b_w0 << 1) ^ (sec_r000500_12 >> 1)) & 63;
    int b_w2 = ((b_w1 << 2) ^ (sec_r000500_14 >> 2)) & 63;
    int b_w3 = ((b_w2 << 2) & (sec_r000500_17 >> 2)) & 63;
    int b_w4 = ((b_w3 << 2) ^ (sec_r000500_11 >> 2)) & 63;
    out_sink += b_w4 & 63;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
