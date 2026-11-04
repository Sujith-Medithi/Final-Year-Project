/*
 * Benchmark Program: R000018
 * Family: zero_leakage
 * Generator Seed: 401813
 * High Inputs: 20 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000018_1813_0 {
    unsigned char threshold;
    short gain;
    unsigned char reading;
    int buffer[3];
};

struct DeviceConfig_R000018_1813_1 {
    short timeout;
    unsigned char baud_rate;
    unsigned char parity;
    short port;
    int buffer[3];
};

struct Transaction_R000018_1813_2 {
    short status;
    int auth_code;
    int fee;
    int rate;
    int account_id;
    int buffer[3];
};

union TelemetryField_R000018_1813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000018_1813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_54 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_54 > 24) {
        acc = (acc + pivot_54 * 2 + 5) & 127;
        aux ^= (pivot_54 & 15);
    } else {
        acc = (acc - pivot_54 + 11) & 127;
        aux += 3;
    }
    int index_reg_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_93) & 63;
    acc ^= aux;
    int parity_16 = 0;
    for (int k = 0; k < 3; k++) {
        parity_16 = (parity_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_71 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_71 > 19) {
        acc = (acc + sample_71 * 2 + 5) & 127;
        aux ^= (sample_71 & 15);
    } else {
        acc = (acc - sample_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_2(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int sample_79 = local_arr[aux % 3];
    acc = (acc + sample_79 * 2) & 127;
    int index_reg_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000018_1813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int metric_76 = local_arr[aux % 3];
    acc = (acc + metric_76 * 2) & 127;
    int stride_59 = (aux + st.buffer[1]) & 3;
    switch (stride_59) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_66 = (aux + st.buffer[1]) & 3;
    switch (tally_66) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_62 = local_arr[aux % 3];
    acc = (acc + bound_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_5(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int pivot_48 = local_arr[aux % 3];
    acc = (acc + pivot_48 * 2) & 127;
    int sample_60 = 0;
    for (int k = 0; k < 3; k++) {
        sample_60 = (sample_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_60) & 127;
    }
    int phase_96 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_96 > 40) {
        acc = (acc + phase_96 * 2 + 5) & 127;
        aux ^= (phase_96 & 15);
    } else {
        acc = (acc - phase_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_51 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_51 > 16) {
        acc = (acc + coefficient_51 * 2 + 5) & 127;
        aux ^= (coefficient_51 & 15);
    } else {
        acc = (acc - coefficient_51 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_33 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_33 = (pivot_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_33) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_7(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000018_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int metric_49 = local_arr[aux % 3];
    acc = (acc + metric_49 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_72 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_72 > 13) {
        acc = (acc + stride_72 * 2 + 5) & 127;
        aux ^= (stride_72 & 15);
    } else {
        acc = (acc - stride_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int coefficient_45 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_45 > 22) {
        acc = (acc + coefficient_45 * 2 + 5) & 127;
        aux ^= (coefficient_45 & 15);
    } else {
        acc = (acc - coefficient_45 + 11) & 127;
        aux += 3;
    }
    int stride_74 = 0;
    for (int k = 0; k < 3; k++) {
        stride_74 = (stride_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_74) & 127;
    }
    int quantum_40 = (aux + st.buffer[1]) & 3;
    switch (quantum_40) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_9(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000018_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int stride_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_57 = local_arr[aux % 3];
    acc = (acc + cursor_57 * 2) & 127;
    int segment_52 = 0;
    for (int k = 0; k < 2; k++) {
        segment_52 = (segment_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_52) & 127;
    }
    int coefficient_61 = (aux + st.buffer[1]) & 3;
    switch (coefficient_61) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_10(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int sample_86 = local_arr[aux % 3];
    acc = (acc + sample_86 * 2) & 127;
    int factor_96 = (aux + st.buffer[1]) & 3;
    switch (factor_96) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_11(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int index_reg_28 = local_arr[aux % 3];
    acc = (acc + index_reg_28 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_12(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int phase_64 = 0;
    for (int k = 0; k < 3; k++) {
        phase_64 = (phase_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_64) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_88 = local_arr[aux % 3];
    acc = (acc + accumulator_88 * 2) & 127;
    int segment_38 = (aux + st.buffer[1]) & 3;
    switch (segment_38) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_13(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int pivot_92 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_92 = (pivot_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_92) & 127;
    }
    int mask_14 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_14 > 39) {
        acc = (acc + mask_14 * 2 + 5) & 127;
        aux ^= (mask_14 & 15);
    } else {
        acc = (acc - mask_14 + 11) & 127;
        aux += 3;
    }
    int factor_85 = (aux + st.buffer[1]) & 3;
    switch (factor_85) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_14(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_83 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_83 > 44) {
        acc = (acc + threshold_83 * 2 + 5) & 127;
        aux ^= (threshold_83 & 15);
    } else {
        acc = (acc - threshold_83 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_64 = local_arr[aux % 3];
    acc = (acc + tracker_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int pivot_97 = local_arr[aux % 3];
    acc = (acc + pivot_97 * 2) & 127;
    int index_reg_48 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_48 > 43) {
        acc = (acc + index_reg_48 * 2 + 5) & 127;
        aux ^= (index_reg_48 & 15);
    } else {
        acc = (acc - index_reg_48 + 11) & 127;
        aux += 3;
    }
    int coefficient_88 = (aux + st.buffer[1]) & 3;
    switch (coefficient_88) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_16(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_69 = local_arr[aux % 3];
    acc = (acc + bound_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_17(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_12 = local_arr[aux % 3];
    acc = (acc + offset_12 * 2) & 127;
    int margin_91 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_91 > 10) {
        acc = (acc + margin_91 * 2 + 5) & 127;
        aux ^= (margin_91 & 15);
    } else {
        acc = (acc - margin_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_18(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000018_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int checksum_22 = (aux + st.buffer[1]) & 3;
    switch (checksum_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_67 = 0;
    for (int k = 0; k < 3; k++) {
        window_67 = (window_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_67) & 127;
    }
    int tracker_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000018_1813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int margin_52 = local_arr[aux % 3];
    acc = (acc + margin_52 * 2) & 127;
    int window_17 = (st.buffer[0] * 3 + aux) & 63;
    if (window_17 > 36) {
        acc = (acc + window_17 * 2 + 5) & 127;
        aux ^= (window_17 & 15);
    } else {
        acc = (acc - window_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_20(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int anchor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_65 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_65 > 30) {
        acc = (acc + tracker_65 * 2 + 5) & 127;
        aux ^= (tracker_65 & 15);
    } else {
        acc = (acc - tracker_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000018_1813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int vector_59 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_59 > 36) {
        acc = (acc + vector_59 * 2 + 5) & 127;
        aux ^= (vector_59 & 15);
    } else {
        acc = (acc - vector_59 + 11) & 127;
        aux += 3;
    }
    int tally_89 = (aux + st.buffer[1]) & 3;
    switch (tally_89) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_29) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_59 = local_arr[aux % 3];
    acc = (acc + bound_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000018_1813_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int index_reg_36 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_36 > 48) {
        acc = (acc + index_reg_36 * 2 + 5) & 127;
        aux ^= (index_reg_36 & 15);
    } else {
        acc = (acc - index_reg_36 + 11) & 127;
        aux += 3;
    }
    int factor_49 = 0;
    for (int k = 0; k < 2; k++) {
        factor_49 = (factor_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000018_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quotient_19 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_19 > 24) {
        acc = (acc + quotient_19 * 2 + 5) & 127;
        aux ^= (quotient_19 & 15);
    } else {
        acc = (acc - quotient_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_30 = local_arr[aux % 3];
    acc = (acc + accumulator_30 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_72 = (aux + st.buffer[1]) & 3;
    switch (index_reg_72) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000018_1813_24(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000018_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int stride_65 = 0;
    for (int k = 0; k < 3; k++) {
        stride_65 = (stride_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_65) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_87 = local_arr[aux % 3];
    acc = (acc + phase_87 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_98 = (aux + st.buffer[1]) & 3;
    switch (threshold_98) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000018_0;
    int sec_r000018_1;
    int sec_r000018_2;
    int sec_r000018_3;
    int sec_r000018_4;
    int sec_r000018_5;
    int sec_r000018_6;
    int sec_r000018_7;
    int sec_r000018_8;
    int sec_r000018_9;
    int sec_r000018_10;
    int sec_r000018_11;
    int sec_r000018_12;
    int sec_r000018_13;
    int sec_r000018_14;
    int sec_r000018_15;
    int sec_r000018_16;
    int sec_r000018_17;
    int sec_r000018_18;
    int sec_r000018_19;
    int pub_r000018_0;
    int pub_r000018_1;
    int pub_r000018_2;
    int pub_r000018_3;
    int pub_r000018_4;
    int pub_r000018_5;
    int pub_r000018_6;
    int pub_r000018_7;
    int pub_r000018_8;
    int pub_r000018_9;
    int pub_r000018_10;
    int pub_r000018_11;
    int pub_r000018_12;
    int pub_r000018_13;
    int pub_r000018_14;
    int pub_r000018_15;
    int pub_r000018_16;
    int pub_r000018_17;
    int pub_r000018_18;
    int pub_r000018_19;
    int pub_r000018_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000018_0 >= -100 && pub_r000018_0 <= 100);
    __CPROVER_assume(pub_r000018_1 >= -100 && pub_r000018_1 <= 100);
    __CPROVER_assume(pub_r000018_2 >= -100 && pub_r000018_2 <= 100);
    __CPROVER_assume(pub_r000018_3 >= -100 && pub_r000018_3 <= 100);
    __CPROVER_assume(pub_r000018_4 >= -100 && pub_r000018_4 <= 100);
    __CPROVER_assume(pub_r000018_5 >= -100 && pub_r000018_5 <= 100);
    __CPROVER_assume(pub_r000018_6 >= -100 && pub_r000018_6 <= 100);
    __CPROVER_assume(pub_r000018_7 >= -100 && pub_r000018_7 <= 100);
    __CPROVER_assume(pub_r000018_8 >= -100 && pub_r000018_8 <= 100);
    __CPROVER_assume(pub_r000018_9 >= -100 && pub_r000018_9 <= 100);
    __CPROVER_assume(pub_r000018_10 >= -100 && pub_r000018_10 <= 100);
    __CPROVER_assume(pub_r000018_11 >= -100 && pub_r000018_11 <= 100);
    __CPROVER_assume(pub_r000018_12 >= -100 && pub_r000018_12 <= 100);
    __CPROVER_assume(pub_r000018_13 >= -100 && pub_r000018_13 <= 100);
    __CPROVER_assume(pub_r000018_14 >= -100 && pub_r000018_14 <= 100);
    __CPROVER_assume(pub_r000018_15 >= -100 && pub_r000018_15 <= 100);
    __CPROVER_assume(pub_r000018_16 >= -100 && pub_r000018_16 <= 100);
    __CPROVER_assume(pub_r000018_17 >= -100 && pub_r000018_17 <= 100);
    __CPROVER_assume(pub_r000018_18 >= -100 && pub_r000018_18 <= 100);
    __CPROVER_assume(pub_r000018_19 >= -100 && pub_r000018_19 <= 100);
    __CPROVER_assume(pub_r000018_20 >= -100 && pub_r000018_20 <= 100);
    __CPROVER_assume(sec_r000018_0 >= 0 && sec_r000018_0 <= 255);
    __CPROVER_assume(sec_r000018_1 >= 0 && sec_r000018_1 <= 255);
    __CPROVER_assume(sec_r000018_2 >= 0 && sec_r000018_2 <= 255);
    __CPROVER_assume(sec_r000018_3 >= 0 && sec_r000018_3 <= 255);
    __CPROVER_assume(sec_r000018_4 >= 0 && sec_r000018_4 <= 255);
    __CPROVER_assume(sec_r000018_5 >= 0 && sec_r000018_5 <= 255);
    __CPROVER_assume(sec_r000018_6 >= 0 && sec_r000018_6 <= 255);
    __CPROVER_assume(sec_r000018_7 >= 0 && sec_r000018_7 <= 255);
    __CPROVER_assume(sec_r000018_8 >= 0 && sec_r000018_8 <= 255);
    __CPROVER_assume(sec_r000018_9 >= 0 && sec_r000018_9 <= 255);
    __CPROVER_assume(sec_r000018_10 >= 0 && sec_r000018_10 <= 255);
    __CPROVER_assume(sec_r000018_11 >= 0 && sec_r000018_11 <= 255);
    __CPROVER_assume(sec_r000018_12 >= 0 && sec_r000018_12 <= 255);
    __CPROVER_assume(sec_r000018_13 >= 0 && sec_r000018_13 <= 255);
    __CPROVER_assume(sec_r000018_14 >= 0 && sec_r000018_14 <= 255);
    __CPROVER_assume(sec_r000018_15 >= 0 && sec_r000018_15 <= 255);
    __CPROVER_assume(sec_r000018_16 >= 0 && sec_r000018_16 <= 255);
    __CPROVER_assume(sec_r000018_17 >= 0 && sec_r000018_17 <= 255);
    __CPROVER_assume(sec_r000018_18 >= 0 && sec_r000018_18 <= 255);
    __CPROVER_assume(sec_r000018_19 >= 0 && sec_r000018_19 <= 255);

    struct SensorNode_R000018_1813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000018_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000018_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000018_0 + 7) & 15;
    struct DeviceConfig_R000018_1813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000018_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000018_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000018_0 + 9) & 15;
    struct Transaction_R000018_1813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000018_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000018_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000018_0 + 11) & 15;

    union TelemetryField_R000018_1813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 20) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 35) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 22) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 37) {
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
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 24) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 39) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 11) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 26) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

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
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 37) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 52) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 11) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 26) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 38) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 53) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 35) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 50) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 34) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 49) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 10) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 25) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 31) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 46) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_2.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

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
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] ^ 81) & 3;
    switch (stage_v_78) {
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

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_1.buffer[0] ^ 82) & 3;
    switch (stage_v_79) {
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

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

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
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (out_sink > 100) ? (chk_sum & 31) : (98 & 31);
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= (stage_v_93 << 1) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (out_sink > 100) ? (chk_sum & 31) : (100 & 31);
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= (stage_v_95 << 1) & 127;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 30) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 45) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 38) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 53) {
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
    int stage_v_102 = (out_sink > 100) ? (chk_sum & 31) : (107 & 31);
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= (stage_v_102 << 1) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (out_sink > 100) ? (chk_sum & 31) : (108 & 31);
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= (stage_v_103 << 1) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] * 2 + 322) & 63;
    if (stage_v_105 > 16) {
        out_sink = (out_sink + stage_v_105 - 5) & 255;
        if (stage_v_105 > 31) {
            chk_sum ^= (stage_v_105 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_105 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_108 = (stage_v_108 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_0.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0];
    table[0] = (table[1] + 225) & 63;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

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
    int stage_v_117 = (st_var_0.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 119 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 120) & 15;
    int stage_v_119 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= stage_v_119;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 34) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 49) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 27) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 42) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_1.buffer[1] * 2 + 379) & 63;
    if (stage_v_124 > 24) {
        out_sink = (out_sink + stage_v_124 - 5) & 255;
        if (stage_v_124 > 39) {
            chk_sum ^= (stage_v_124 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_124 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_2.buffer[2] * 2 + 382) & 63;
    if (stage_v_125 > 26) {
        out_sink = (out_sink + stage_v_125 - 5) & 255;
        if (stage_v_125 > 41) {
            chk_sum ^= (stage_v_125 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_125 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (out_sink > 100) ? (chk_sum & 31) : (131 & 31);
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= (stage_v_126 << 1) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3];
    table[3] = (table[0] + 255) & 63;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_0.buffer[0] * 2 + 394) & 63;
    if (stage_v_129 > 17) {
        out_sink = (out_sink + stage_v_129 - 5) & 255;
        if (stage_v_129 > 32) {
            chk_sum ^= (stage_v_129 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_129 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] ^ 135) & 3;
    switch (stage_v_132) {
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

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = table[1];
    table[1] = (table[2] + 267) & 63;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

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
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 141) & 15;
    int stage_v_140 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    chk_sum ^= stage_v_140;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] ^ 144) & 3;
    switch (stage_v_141) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[1] * 2 + 433) & 63;
    if (stage_v_142 > 10) {
        out_sink = (out_sink + stage_v_142 - 5) & 255;
        if (stage_v_142 > 25) {
            chk_sum ^= (stage_v_142 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_142 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_2.buffer[2] * 2 + 436) & 63;
    if (stage_v_143 > 13) {
        out_sink = (out_sink + stage_v_143 - 5) & 255;
        if (stage_v_143 > 28) {
            chk_sum ^= (stage_v_143 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_143 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_149 = (stage_v_149 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_156 = (stage_v_156 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 158 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 159) & 15;
    int stage_v_158 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= stage_v_158;

    /* Execution Pipeline Stage 159 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 160) & 15;
    int stage_v_159 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= stage_v_159;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] * 2 + 493) & 63;
    if (stage_v_162 > 29) {
        out_sink = (out_sink + stage_v_162 - 5) & 255;
        if (stage_v_162 > 44) {
            chk_sum ^= (stage_v_162 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_162 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_2.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = table[1];
    table[1] = (table[2] + 331) & 63;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_166 = (stage_v_166 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_168 = (stage_v_168 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[1] * 2 + 514) & 63;
    if (stage_v_169 > 33) {
        out_sink = (out_sink + stage_v_169 - 5) & 255;
        if (stage_v_169 > 48) {
            chk_sum ^= (stage_v_169 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_169 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 170 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 171) & 15;
    int stage_v_170 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= stage_v_170;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_0.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 11) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 26) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = table[0];
    table[0] = (table[1] + 345) & 63;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_175 = (stage_v_175 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_175) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_176 = (stage_v_176 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_176) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (out_sink > 100) ? (chk_sum & 31) : (182 & 31);
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= (stage_v_177 << 1) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_1.buffer[0] ^ 181) & 3;
    switch (stage_v_178) {
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

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_2.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 38) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 53) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Security Information Flow: Family = zero_leakage */
    int dead_sec_0 = (sec_r000018_14 & 0) * 0;
    int dead_sec_1 = ((sec_r000018_7 << 2) ^ (sec_r000018_7 << 2)) * 0;
    out_sink = (out_sink + dead_sec_0 + dead_sec_1) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
