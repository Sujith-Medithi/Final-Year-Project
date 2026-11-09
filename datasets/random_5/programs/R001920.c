/*
 * Benchmark Program: R001920
 * Security Family: mixed_control_data
 * Generator Seed: 692013
 * High Inputs: 20 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001920_2013_0 {
    unsigned char round_key;
    int flags;
    int iv;
    int nonce;
    int buffer[3];
};

struct FilterState_R001920_2013_1 {
    int prev_in;
    short prev_out;
    int damping;
    unsigned char mode;
    int cutoff;
    int buffer[3];
};

struct EventLog_R001920_2013_2 {
    int code;
    short facility;
    short seq;
    int signature;
    int severity;
    int timestamp;
    int buffer[3];
};

struct SensorNode_R001920_2013_3 {
    int offset;
    int threshold;
    int calib;
    unsigned char gain;
    int buffer[3];
};

union ColorPixel_R001920_2013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001920_2013_0(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_61 = local_arr[aux % 3];
    acc = (acc + window_61 * 2) & 127;
    int cursor_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_90) & 63;
    acc ^= aux;
    int quotient_27 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_27 = (quotient_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_27) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int anchor_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_13) & 63;
    acc ^= aux;
    int quantum_10 = (aux + st.buffer[1]) & 3;
    switch (quantum_10) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001920_2013_2(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_18 = (aux + st.buffer[1]) & 3;
    switch (factor_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_90 = 0;
    for (int k = 0; k < 2; k++) {
        mask_90 = (mask_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_3(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int weight_14 = (aux + st.buffer[1]) & 3;
    switch (weight_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001920_2013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_39) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_83 = local_arr[aux % 3];
    acc = (acc + quotient_83 * 2) & 127;
    int tracker_44 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_44 > 27) {
        acc = (acc + tracker_44 * 2 + 5) & 127;
        aux ^= (tracker_44 & 15);
    } else {
        acc = (acc - tracker_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_5(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int coefficient_57 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_57 = (coefficient_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_57) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_79 = (aux + st.buffer[1]) & 3;
    switch (coefficient_79) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_6(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_48 = 0;
    for (int k = 0; k < 3; k++) {
        sample_48 = (sample_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_48) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_58 = local_arr[aux % 3];
    acc = (acc + weight_58 * 2) & 127;
    int stride_19 = (aux + st.buffer[1]) & 3;
    switch (stride_19) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_7(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int parity_92 = local_arr[aux % 3];
    acc = (acc + parity_92 * 2) & 127;
    int window_33 = (st.buffer[0] * 3 + aux) & 63;
    if (window_33 > 32) {
        acc = (acc + window_33 * 2 + 5) & 127;
        aux ^= (window_33 & 15);
    } else {
        acc = (acc - window_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001920_2013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int weight_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_47) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_42 = local_arr[aux % 3];
    acc = (acc + tally_42 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001920_2013_9(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int mask_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_28) & 63;
    acc ^= aux;
    int sample_74 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_74 > 49) {
        acc = (acc + sample_74 * 2 + 5) & 127;
        aux ^= (sample_74 & 15);
    } else {
        acc = (acc - sample_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_46 = local_arr[aux % 3];
    acc = (acc + factor_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001920_2013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int scale_30 = local_arr[aux % 3];
    acc = (acc + scale_30 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_92 = (aux + st.buffer[1]) & 3;
    switch (parity_92) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_11(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_58) & 63;
    acc ^= aux;
    int index_reg_72 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_72 = (index_reg_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int coefficient_47 = (aux + st.buffer[1]) & 3;
    switch (coefficient_47) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_84 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_84 > 21) {
        acc = (acc + pivot_84 * 2 + 5) & 127;
        aux ^= (pivot_84 & 15);
    } else {
        acc = (acc - pivot_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_13(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int segment_74 = 0;
    for (int k = 0; k < 2; k++) {
        segment_74 = (segment_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_74) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_28 = local_arr[aux % 3];
    acc = (acc + stride_28 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001920_2013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int checksum_70 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_70 = (checksum_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_70) & 127;
    }
    int quotient_86 = (aux + st.buffer[1]) & 3;
    switch (quotient_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_14 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_14 > 19) {
        acc = (acc + damping_14 * 2 + 5) & 127;
        aux ^= (damping_14 & 15);
    } else {
        acc = (acc - damping_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_15(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001920_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_55) & 63;
    acc ^= aux;
    int offset_17 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_17 > 23) {
        acc = (acc + offset_17 * 2 + 5) & 127;
        aux ^= (offset_17 & 15);
    } else {
        acc = (acc - offset_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int threshold_12 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_12 = (threshold_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_12) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_35 = (aux + st.buffer[1]) & 3;
    switch (pivot_35) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_87 = local_arr[aux % 3];
    acc = (acc + factor_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001920_2013_17(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int pivot_67 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_67 > 42) {
        acc = (acc + pivot_67 * 2 + 5) & 127;
        aux ^= (pivot_67 & 15);
    } else {
        acc = (acc - pivot_67 + 11) & 127;
        aux += 3;
    }
    int tally_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001920_2013_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_52 = (aux + st.buffer[1]) & 3;
    switch (quantum_52) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_91 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_91 > 28) {
        acc = (acc + checksum_91 * 2 + 5) & 127;
        aux ^= (checksum_91 & 15);
    } else {
        acc = (acc - checksum_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_19(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001920_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int metric_84 = (aux + st.buffer[1]) & 3;
    switch (metric_84) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_37 = local_arr[aux % 3];
    acc = (acc + bound_37 * 2) & 127;
    int sample_22 = 0;
    for (int k = 0; k < 2; k++) {
        sample_22 = (sample_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_20(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int mask_28 = 0;
    for (int k = 0; k < 2; k++) {
        mask_28 = (mask_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_28) & 127;
    }
    int phase_61 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_61 > 49) {
        acc = (acc + phase_61 * 2 + 5) & 127;
        aux ^= (phase_61 & 15);
    } else {
        acc = (acc - phase_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001920_2013_21(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001920_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int stride_64 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_64 > 21) {
        acc = (acc + stride_64 * 2 + 5) & 127;
        aux ^= (stride_64 & 15);
    } else {
        acc = (acc - stride_64 + 11) & 127;
        aux += 3;
    }
    int bound_71 = 0;
    for (int k = 0; k < 2; k++) {
        bound_71 = (bound_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_71) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001920_2013_22(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001920_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_54 = (aux + st.buffer[1]) & 3;
    switch (tracker_54) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_40 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_40 > 37) {
        acc = (acc + residue_40 * 2 + 5) & 127;
        aux ^= (residue_40 & 15);
    } else {
        acc = (acc - residue_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001920_0;
    int sec_r001920_1;
    int sec_r001920_2;
    int sec_r001920_3;
    int sec_r001920_4;
    int sec_r001920_5;
    int sec_r001920_6;
    int sec_r001920_7;
    int sec_r001920_8;
    int sec_r001920_9;
    int sec_r001920_10;
    int sec_r001920_11;
    int sec_r001920_12;
    int sec_r001920_13;
    int sec_r001920_14;
    int sec_r001920_15;
    int sec_r001920_16;
    int sec_r001920_17;
    int sec_r001920_18;
    int sec_r001920_19;
    int pub_r001920_0;
    int pub_r001920_1;
    int pub_r001920_2;
    int pub_r001920_3;
    int pub_r001920_4;
    int pub_r001920_5;
    int pub_r001920_6;
    int pub_r001920_7;
    int pub_r001920_8;
    int pub_r001920_9;
    int pub_r001920_10;
    int pub_r001920_11;
    int pub_r001920_12;
    int pub_r001920_13;
    int pub_r001920_14;
    int pub_r001920_15;
    int pub_r001920_16;
    int pub_r001920_17;
    int pub_r001920_18;
    int pub_r001920_19;
    int pub_r001920_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001920_0 >= -100 && pub_r001920_0 <= 100);
    __CPROVER_assume(pub_r001920_1 >= -100 && pub_r001920_1 <= 100);
    __CPROVER_assume(pub_r001920_2 >= -100 && pub_r001920_2 <= 100);
    __CPROVER_assume(pub_r001920_3 >= -100 && pub_r001920_3 <= 100);
    __CPROVER_assume(pub_r001920_4 >= -100 && pub_r001920_4 <= 100);
    __CPROVER_assume(pub_r001920_5 >= -100 && pub_r001920_5 <= 100);
    __CPROVER_assume(pub_r001920_6 >= -100 && pub_r001920_6 <= 100);
    __CPROVER_assume(pub_r001920_7 >= -100 && pub_r001920_7 <= 100);
    __CPROVER_assume(pub_r001920_8 >= -100 && pub_r001920_8 <= 100);
    __CPROVER_assume(pub_r001920_9 >= -100 && pub_r001920_9 <= 100);
    __CPROVER_assume(pub_r001920_10 >= -100 && pub_r001920_10 <= 100);
    __CPROVER_assume(pub_r001920_11 >= -100 && pub_r001920_11 <= 100);
    __CPROVER_assume(pub_r001920_12 >= -100 && pub_r001920_12 <= 100);
    __CPROVER_assume(pub_r001920_13 >= -100 && pub_r001920_13 <= 100);
    __CPROVER_assume(pub_r001920_14 >= -100 && pub_r001920_14 <= 100);
    __CPROVER_assume(pub_r001920_15 >= -100 && pub_r001920_15 <= 100);
    __CPROVER_assume(pub_r001920_16 >= -100 && pub_r001920_16 <= 100);
    __CPROVER_assume(pub_r001920_17 >= -100 && pub_r001920_17 <= 100);
    __CPROVER_assume(pub_r001920_18 >= -100 && pub_r001920_18 <= 100);
    __CPROVER_assume(pub_r001920_19 >= -100 && pub_r001920_19 <= 100);
    __CPROVER_assume(pub_r001920_20 >= -100 && pub_r001920_20 <= 100);
    __CPROVER_assume(sec_r001920_0 >= 0 && sec_r001920_0 <= 255);
    __CPROVER_assume(sec_r001920_1 >= 0 && sec_r001920_1 <= 255);
    __CPROVER_assume(sec_r001920_2 >= 0 && sec_r001920_2 <= 255);
    __CPROVER_assume(sec_r001920_3 >= 0 && sec_r001920_3 <= 255);
    __CPROVER_assume(sec_r001920_4 >= 0 && sec_r001920_4 <= 255);
    __CPROVER_assume(sec_r001920_5 >= 0 && sec_r001920_5 <= 255);
    __CPROVER_assume(sec_r001920_6 >= 0 && sec_r001920_6 <= 255);
    __CPROVER_assume(sec_r001920_7 >= 0 && sec_r001920_7 <= 255);
    __CPROVER_assume(sec_r001920_8 >= 0 && sec_r001920_8 <= 255);
    __CPROVER_assume(sec_r001920_9 >= 0 && sec_r001920_9 <= 255);
    __CPROVER_assume(sec_r001920_10 >= 0 && sec_r001920_10 <= 255);
    __CPROVER_assume(sec_r001920_11 >= 0 && sec_r001920_11 <= 255);
    __CPROVER_assume(sec_r001920_12 >= 0 && sec_r001920_12 <= 255);
    __CPROVER_assume(sec_r001920_13 >= 0 && sec_r001920_13 <= 255);
    __CPROVER_assume(sec_r001920_14 >= 0 && sec_r001920_14 <= 255);
    __CPROVER_assume(sec_r001920_15 >= 0 && sec_r001920_15 <= 255);
    __CPROVER_assume(sec_r001920_16 >= 0 && sec_r001920_16 <= 255);
    __CPROVER_assume(sec_r001920_17 >= 0 && sec_r001920_17 <= 255);
    __CPROVER_assume(sec_r001920_18 >= 0 && sec_r001920_18 <= 255);
    __CPROVER_assume(sec_r001920_19 >= 0 && sec_r001920_19 <= 255);

    struct CipherContext_R001920_2013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001920_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001920_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001920_0 + 7) & 15;
    struct FilterState_R001920_2013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001920_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001920_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001920_0 + 9) & 15;
    struct EventLog_R001920_2013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001920_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001920_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001920_0 + 11) & 15;
    struct SensorNode_R001920_2013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001920_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001920_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001920_0 + 13) & 15;

    union ColorPixel_R001920_2013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001920_2013_0(sec_r001920_0, sec_r001920_1);
    int helper_flow_1 = fn_R001920_2013_1(sec_r001920_1, pub_r001920_2, pub_r001920_3, pub_r001920_4);
    int helper_flow_2 = fn_R001920_2013_2(sec_r001920_2, sec_r001920_3);
    int helper_flow_3 = fn_R001920_2013_3(sec_r001920_3, pub_r001920_4, pub_r001920_5);
    int helper_flow_4 = fn_R001920_2013_4(sec_r001920_4, pub_r001920_5, pub_r001920_6, pub_r001920_7);
    int helper_flow_5 = fn_R001920_2013_5(sec_r001920_5, pub_r001920_6);
    int helper_flow_6 = fn_R001920_2013_6(sec_r001920_6, sec_r001920_7, pub_r001920_8);
    int helper_flow_7 = fn_R001920_2013_7(sec_r001920_7, pub_r001920_8);
    int helper_flow_8 = fn_R001920_2013_8(sec_r001920_8, pub_r001920_9, pub_r001920_10, pub_r001920_11);
    int helper_flow_9 = fn_R001920_2013_9(sec_r001920_9, pub_r001920_10, pub_r001920_11);
    int helper_flow_10 = fn_R001920_2013_10(sec_r001920_10, pub_r001920_11, pub_r001920_12, pub_r001920_13, pub_r001920_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001920_11 ^ 0x2A) * 2 + pub_r001920_0) & 127;
    if (stage_v_0 > 48) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001920_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001920_3 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_2 > 30) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001920_15 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_3 > 49) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_4 > 24) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001920_7) & 127;
    if (stage_v_5 > 21) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001920_5 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_6 > 21) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001920_10 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_7 > 38) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001920_13 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_8 > 39) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_9 > 25) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001920_11 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_10 > 39) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001920_2 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_11 > 30) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_12 > 38) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001920_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001920_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001920_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_16 > 28) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001920_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001920_16 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_18 > 29) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001920_7) & 127;
    if (stage_v_19 > 29) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_20 > 21) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001920_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001920_15 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_22 > 32) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_23 > 26) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_24 > 49) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_25 > 26) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001920_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_27 > 41) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001920_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_29 > 34) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001920_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001920_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001920_5 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_32 > 41) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001920_1 ^ 0x2A) * 2 + pub_r001920_15) & 127;
    if (stage_v_33 > 39) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001920_17 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_34 > 43) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001920_2 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_35 > 39) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_36 > 48) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001920_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001920_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001920_5) & 127;
    if (stage_v_39 > 31) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001920_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001920_2) & 127;
    if (stage_v_41 > 30) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_42 > 33) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001920_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_44 > 41) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001920_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_46 > 42) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001920_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001920_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_49 > 34) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001920_10 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_50 > 29) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001920_2) & 127;
    if (stage_v_51 > 37) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001920_15 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_52 > 41) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_53 > 41) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_54 > 49) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001920_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001920_9 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_56 > 43) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_57 > 50) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_58 > 49) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001920_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_60 > 34) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_61 > 27) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_62 > 37) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_63 > 34) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001920_4 ^ 0x2A) * 2 + pub_r001920_5) & 127;
    if (stage_v_64 > 20) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001920_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_66 > 45) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_67 > 25) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_68 > 34) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_69 > 22) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_70 > 49) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001920_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_72 > 38) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_73 > 44) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_74 > 20) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001920_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_76 > 43) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001920_2) & 127;
    if (stage_v_77 > 22) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_78 > 21) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001920_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_80 > 22) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_81 > 44) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_82 > 22) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_83 > 22) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001920_17 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_84 > 40) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001920_11 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_85 > 39) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001920_7 ^ 0x2A) * 2 + pub_r001920_0) & 127;
    if (stage_v_86 > 39) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_87 > 21) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001920_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_89 > 39) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001920_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001920_2) & 127;
    if (stage_v_91 > 50) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001920_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_93 > 32) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_94 > 47) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001920_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_96 > 21) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_97 > 34) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001920_18) & 127;
    if (stage_v_98 > 50) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_99 > 38) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_100 > 32) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001920_18) & 127;
    if (stage_v_101 > 32) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001920_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001920_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_104 > 34) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_105 > 26) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_106 > 23) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_107 > 41) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001920_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001920_2) & 127;
    if (stage_v_109 > 43) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_110 > 48) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_111 > 36) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001920_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_113 > 50) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001920_15) & 127;
    if (stage_v_114 > 30) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_115 > 49) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001920_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_117 > 21) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001920_15 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_118 > 47) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_119 > 23) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_120 > 40) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001920_10 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_121 > 32) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001920_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_123 > 45) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001920_4 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_124 > 25) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001920_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_126 > 40) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_127 > 28) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_128 > 24) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001920_18 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_129 > 30) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_130 > 44) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001920_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_132 > 27) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001920_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r001920_19 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_134 > 22) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_135 > 42) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001920_0) & 127;
    if (stage_v_136 > 33) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001920_7) & 127;
    if (stage_v_137 > 36) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_138 > 39) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_139 > 29) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_140 > 30) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_141 > 45) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_142 > 36) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001920_5) & 127;
    if (stage_v_143 > 36) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001920_18) & 127;
    if (stage_v_144 > 42) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_145 > 49) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_146 > 27) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001920_0) & 127;
    if (stage_v_147 > 29) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001920_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_149 > 49) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_150 > 31) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_151 > 37) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_152 > 30) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001920_14 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_153 > 39) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_154 > 36) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001920_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_156 > 20) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_157 > 25) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_158 > 42) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_159 > 25) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_160 > 30) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_161 > 21) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001920_5) & 127;
    if (stage_v_162 > 25) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001920_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001920_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_165 > 49) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_166 > 35) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_167 > 46) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_168 > 27) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001920_0) & 127;
    if (stage_v_169 > 40) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_170 > 22) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_171 > 45) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_172 > 35) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_173 > 50) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001920_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_175 > 23) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001920_15 ^ 0x2A) * 2 + pub_r001920_5) & 127;
    if (stage_v_176 > 46) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001920_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001920_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_179 > 44) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_180 > 39) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_181 > 35) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001920_2) & 127;
    if (stage_v_182 > 34) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_183 > 40) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001920_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001920_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_186 > 29) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001920_17) & 127;
    if (stage_v_187 > 41) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_188 > 36) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001920_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_190 > 21) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001920_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_192 > 43) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001920_14 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_193 > 39) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_194 > 32) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_195 > 42) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001920_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001920_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_198 > 30) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_199 > 46) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001920_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001920_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_202 > 42) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001920_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001920_10) & 127;
    if (stage_v_204 > 27) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001920_2) & 127;
    if (stage_v_205 > 30) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001920_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001920_3) & 127;
    if (stage_v_207 > 33) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001920_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_151 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_209 > 31) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001920_15) & 127;
    if (stage_v_210 > 21) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_211 > 32) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_212 > 26) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_213 > 38) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001920_20) & 127;
    if (stage_v_214 > 33) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001920_4) & 127;
    if (stage_v_215 > 28) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001920_19) & 127;
    if (stage_v_216 > 21) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_217 > 21) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_218 > 22) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001920_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001920_18) & 127;
    if (stage_v_220 > 42) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001920_12) & 127;
    if (stage_v_221 > 23) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001920_16) & 127;
    if (stage_v_222 > 47) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001920_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_224 > 20) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001920_7) & 127;
    if (stage_v_225 > 34) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001920_0) & 127;
    if (stage_v_226 > 22) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001920_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_228 > 24) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_207 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_229 > 49) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001920_5) & 127;
    if (stage_v_230 > 32) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001920_6) & 127;
    if (stage_v_231 > 28) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001920_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001920_14) & 127;
    if (stage_v_233 > 27) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001920_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_235 > 22) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001920_8) & 127;
    if (stage_v_236 > 42) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001920_15) & 127;
    if (stage_v_237 > 49) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001920_13) & 127;
    if (stage_v_238 > 37) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_239 > 35) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001920_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001920_9) & 127;
    if (stage_v_241 > 30) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001920_1) & 127;
    if (stage_v_242 > 25) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_243 > 32) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r001920_3 ^ 0x2A) * 2 + pub_r001920_11) & 127;
    if (stage_v_244 > 38) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
