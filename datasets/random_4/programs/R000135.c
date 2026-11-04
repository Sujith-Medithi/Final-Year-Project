/*
 * Benchmark Program: R000135
 * Family: direct_leakage
 * Generator Seed: 413513
 * High Inputs: 17 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000135_3513_0 {
    int account_id;
    unsigned char balance;
    int rate;
    short status;
    int auth_code;
    int fee;
    int buffer[3];
};

struct DeviceConfig_R000135_3513_1 {
    short id;
    int baud_rate;
    int timeout;
    int stop_bits;
    int port;
    unsigned char parity;
    int buffer[3];
};

struct SensorNode_R000135_3513_2 {
    unsigned char reading;
    int threshold;
    short status;
    int gain;
    unsigned char calib;
    unsigned char offset;
    int buffer[3];
};

union RegisterBank_R000135_3513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000135_3513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000135_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int stride_49 = local_arr[aux % 3];
    acc = (acc + stride_49 * 2) & 127;
    int cursor_39 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_39 > 19) {
        acc = (acc + cursor_39 * 2 + 5) & 127;
        aux ^= (cursor_39 & 15);
    } else {
        acc = (acc - cursor_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_20 = 0;
    for (int k = 0; k < 2; k++) {
        metric_20 = (metric_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_20) & 127;
    }
    int factor_93 = (aux + st.buffer[1]) & 3;
    switch (factor_93) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_93 = local_arr[aux % 3];
    acc = (acc + stride_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_2(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000135_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int accumulator_63 = (aux + st.buffer[1]) & 3;
    switch (accumulator_63) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_63 = 0;
    for (int k = 0; k < 3; k++) {
        mask_63 = (mask_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_63) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000135_3513_3(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000135_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int bound_81 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_81 > 20) {
        acc = (acc + bound_81 * 2 + 5) & 127;
        aux ^= (bound_81 & 15);
    } else {
        acc = (acc - bound_81 + 11) & 127;
        aux += 3;
    }
    int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_42 = local_arr[aux % 3];
    acc = (acc + margin_42 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int metric_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_66) & 63;
    acc ^= aux;
    int bound_66 = (aux + st.buffer[1]) & 3;
    switch (bound_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000135_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_75 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_75 > 14) {
        acc = (acc + pivot_75 * 2 + 5) & 127;
        aux ^= (pivot_75 & 15);
    } else {
        acc = (acc - pivot_75 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_93 = local_arr[aux % 3];
    acc = (acc + factor_93 * 2) & 127;
    int mask_19 = 0;
    for (int k = 0; k < 3; k++) {
        mask_19 = (mask_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_19) & 127;
    }
    int window_62 = (aux + st.buffer[1]) & 3;
    switch (window_62) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_29 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_29 = (checksum_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_29) & 127;
    }
    int vector_87 = (aux + st.buffer[1]) & 3;
    switch (vector_87) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_64 = local_arr[aux % 3];
    acc = (acc + mask_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_8(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000135_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int stride_49 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_49 > 26) {
        acc = (acc + stride_49 * 2 + 5) & 127;
        aux ^= (stride_49 & 15);
    } else {
        acc = (acc - stride_49 + 11) & 127;
        aux += 3;
    }
    int phase_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000135_3513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int bound_41 = 0;
    for (int k = 0; k < 2; k++) {
        bound_41 = (bound_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_41) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_98 = local_arr[aux % 3];
    acc = (acc + mask_98 * 2) & 127;
    int sample_56 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_56 > 18) {
        acc = (acc + sample_56 * 2 + 5) & 127;
        aux ^= (sample_56 & 15);
    } else {
        acc = (acc - sample_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_25 = local_arr[aux % 3];
    acc = (acc + tracker_25 * 2) & 127;
    int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000135_3513_11(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int residue_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_59) & 63;
    acc ^= aux;
    int delta_47 = 0;
    for (int k = 0; k < 3; k++) {
        delta_47 = (delta_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_47) & 127;
    }
    int threshold_76 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_76 > 35) {
        acc = (acc + threshold_76 * 2 + 5) & 127;
        aux ^= (threshold_76 & 15);
    } else {
        acc = (acc - threshold_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_12(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000135_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int anchor_37 = local_arr[aux % 3];
    acc = (acc + anchor_37 * 2) & 127;
    int coefficient_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_94) & 63;
    acc ^= aux;
    int delta_60 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_60 > 15) {
        acc = (acc + delta_60 * 2 + 5) & 127;
        aux ^= (delta_60 & 15);
    } else {
        acc = (acc - delta_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_13(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_28 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_28 > 47) {
        acc = (acc + metric_28 * 2 + 5) & 127;
        aux ^= (metric_28 & 15);
    } else {
        acc = (acc - metric_28 + 11) & 127;
        aux += 3;
    }
    int stride_93 = 0;
    for (int k = 0; k < 3; k++) {
        stride_93 = (stride_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_93) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000135_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int delta_84 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_84 > 14) {
        acc = (acc + delta_84 * 2 + 5) & 127;
        aux ^= (delta_84 & 15);
    } else {
        acc = (acc - delta_84 + 11) & 127;
        aux += 3;
    }
    int window_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_22) & 63;
    acc ^= aux;
    int mask_95 = 0;
    for (int k = 0; k < 2; k++) {
        mask_95 = (mask_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_95) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_69 = local_arr[aux % 3];
    acc = (acc + tracker_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000135_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int stride_31 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_31 > 16) {
        acc = (acc + stride_31 * 2 + 5) & 127;
        aux ^= (stride_31 & 15);
    } else {
        acc = (acc - stride_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_50 = local_arr[aux % 3];
    acc = (acc + scale_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_50 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_50 = (pivot_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_50) & 127;
    }
    int bound_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000135_3513_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000135_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_87 = (aux + st.buffer[1]) & 3;
    switch (stride_87) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000135_3513_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000135_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int tracker_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_39) & 63;
    acc ^= aux;
    int pivot_73 = (aux + st.buffer[1]) & 3;
    switch (pivot_73) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int phase_28 = local_arr[aux % 3];
    acc = (acc + phase_28 * 2) & 127;
    int quantum_51 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_51 = (quantum_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_20(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000135_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_49 = (aux + st.buffer[1]) & 3;
    switch (delta_49) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000135_3513_21(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000135_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int stride_74 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_74 > 15) {
        acc = (acc + stride_74 * 2 + 5) & 127;
        aux ^= (stride_74 & 15);
    } else {
        acc = (acc - stride_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_36 = local_arr[aux % 3];
    acc = (acc + residue_36 * 2) & 127;
    int threshold_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_76) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000135_0;
    int sec_r000135_1;
    int sec_r000135_2;
    int sec_r000135_3;
    int sec_r000135_4;
    int sec_r000135_5;
    int sec_r000135_6;
    int sec_r000135_7;
    int sec_r000135_8;
    int sec_r000135_9;
    int sec_r000135_10;
    int sec_r000135_11;
    int sec_r000135_12;
    int sec_r000135_13;
    int sec_r000135_14;
    int sec_r000135_15;
    int sec_r000135_16;
    int pub_r000135_0;
    int pub_r000135_1;
    int pub_r000135_2;
    int pub_r000135_3;
    int pub_r000135_4;
    int pub_r000135_5;
    int pub_r000135_6;
    int pub_r000135_7;
    int pub_r000135_8;
    int pub_r000135_9;
    int pub_r000135_10;
    int pub_r000135_11;
    int pub_r000135_12;
    int pub_r000135_13;
    int pub_r000135_14;
    int pub_r000135_15;
    int pub_r000135_16;
    int pub_r000135_17;
    int pub_r000135_18;
    int pub_r000135_19;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000135_0 >= -100 && pub_r000135_0 <= 100);
    __CPROVER_assume(pub_r000135_1 >= -100 && pub_r000135_1 <= 100);
    __CPROVER_assume(pub_r000135_2 >= -100 && pub_r000135_2 <= 100);
    __CPROVER_assume(pub_r000135_3 >= -100 && pub_r000135_3 <= 100);
    __CPROVER_assume(pub_r000135_4 >= -100 && pub_r000135_4 <= 100);
    __CPROVER_assume(pub_r000135_5 >= -100 && pub_r000135_5 <= 100);
    __CPROVER_assume(pub_r000135_6 >= -100 && pub_r000135_6 <= 100);
    __CPROVER_assume(pub_r000135_7 >= -100 && pub_r000135_7 <= 100);
    __CPROVER_assume(pub_r000135_8 >= -100 && pub_r000135_8 <= 100);
    __CPROVER_assume(pub_r000135_9 >= -100 && pub_r000135_9 <= 100);
    __CPROVER_assume(pub_r000135_10 >= -100 && pub_r000135_10 <= 100);
    __CPROVER_assume(pub_r000135_11 >= -100 && pub_r000135_11 <= 100);
    __CPROVER_assume(pub_r000135_12 >= -100 && pub_r000135_12 <= 100);
    __CPROVER_assume(pub_r000135_13 >= -100 && pub_r000135_13 <= 100);
    __CPROVER_assume(pub_r000135_14 >= -100 && pub_r000135_14 <= 100);
    __CPROVER_assume(pub_r000135_15 >= -100 && pub_r000135_15 <= 100);
    __CPROVER_assume(pub_r000135_16 >= -100 && pub_r000135_16 <= 100);
    __CPROVER_assume(pub_r000135_17 >= -100 && pub_r000135_17 <= 100);
    __CPROVER_assume(pub_r000135_18 >= -100 && pub_r000135_18 <= 100);
    __CPROVER_assume(pub_r000135_19 >= -100 && pub_r000135_19 <= 100);
    __CPROVER_assume(sec_r000135_0 >= 0 && sec_r000135_0 <= 255);
    __CPROVER_assume(sec_r000135_1 >= 0 && sec_r000135_1 <= 255);
    __CPROVER_assume(sec_r000135_2 >= 0 && sec_r000135_2 <= 255);
    __CPROVER_assume(sec_r000135_3 >= 0 && sec_r000135_3 <= 255);
    __CPROVER_assume(sec_r000135_4 >= 0 && sec_r000135_4 <= 255);
    __CPROVER_assume(sec_r000135_5 >= 0 && sec_r000135_5 <= 255);
    __CPROVER_assume(sec_r000135_6 >= 0 && sec_r000135_6 <= 255);
    __CPROVER_assume(sec_r000135_7 >= 0 && sec_r000135_7 <= 255);
    __CPROVER_assume(sec_r000135_8 >= 0 && sec_r000135_8 <= 255);
    __CPROVER_assume(sec_r000135_9 >= 0 && sec_r000135_9 <= 255);
    __CPROVER_assume(sec_r000135_10 >= 0 && sec_r000135_10 <= 255);
    __CPROVER_assume(sec_r000135_11 >= 0 && sec_r000135_11 <= 255);
    __CPROVER_assume(sec_r000135_12 >= 0 && sec_r000135_12 <= 255);
    __CPROVER_assume(sec_r000135_13 >= 0 && sec_r000135_13 <= 255);
    __CPROVER_assume(sec_r000135_14 >= 0 && sec_r000135_14 <= 255);
    __CPROVER_assume(sec_r000135_15 >= 0 && sec_r000135_15 <= 255);
    __CPROVER_assume(sec_r000135_16 >= 0 && sec_r000135_16 <= 255);

    struct Transaction_R000135_3513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000135_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000135_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000135_0 + 7) & 15;
    struct DeviceConfig_R000135_3513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000135_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000135_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000135_0 + 9) & 15;
    struct SensorNode_R000135_3513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000135_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000135_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000135_0 + 11) & 15;

    union RegisterBank_R000135_3513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 27) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 42) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 30) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 45) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 20) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 35) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 25) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 40) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 16) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 31) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 34) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 49) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 17) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 32) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 10) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 25) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 40) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 55) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 21) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 36) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 26) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 41) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_2.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 82) & 15;
    int stage_v_81 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= stage_v_81;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 14) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 29) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[0] ^ 89) & 3;
    switch (stage_v_86) {
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

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_91 = (stage_v_91 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_92 = (stage_v_92 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] ^ 96) & 3;
    switch (stage_v_93) {
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

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_95 = (stage_v_95 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 15) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 30) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[0] ^ 101) & 3;
    switch (stage_v_98) {
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

    /* Execution Pipeline Stage 99 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 100) & 15;
    int stage_v_99 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= stage_v_99;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_2.buffer[2] * 2 + 310) & 63;
    if (stage_v_101 > 16) {
        out_sink = (out_sink + stage_v_101 - 5) & 255;
        if (stage_v_101 > 31) {
            chk_sum ^= (stage_v_101 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_101 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = table[2];
    table[2] = (table[3] + 205) & 63;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 104) & 15;
    int stage_v_103 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= stage_v_103;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_2.buffer[0] ^ 107) & 3;
    switch (stage_v_104) {
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

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_1.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
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
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0];
    table[0] = (table[1] + 225) & 63;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_2.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 22) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 37) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 118) & 15;
    int stage_v_117 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= stage_v_117;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_1.buffer[0] ^ 121) & 3;
    switch (stage_v_118) {
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

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (out_sink > 100) ? (chk_sum & 31) : (126 & 31);
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= (stage_v_121 << 1) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 30) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 45) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 126) & 15;
    int stage_v_125 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= stage_v_125;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = table[1];
    table[1] = (table[2] + 259) & 63;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] * 2 + 403) & 63;
    if (stage_v_132 > 33) {
        out_sink = (out_sink + stage_v_132 - 5) & 255;
        if (stage_v_132 > 48) {
            chk_sum ^= (stage_v_132 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_132 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 40) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 55) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (out_sink > 100) ? (chk_sum & 31) : (140 & 31);
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= (stage_v_135 << 1) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[0] ^ 142) & 3;
    switch (stage_v_139) {
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

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 30) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 45) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_2.buffer[0] ^ 146) & 3;
    switch (stage_v_143) {
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

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] ^ 147) & 3;
    switch (stage_v_144) {
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
    int stage_v_146 = (st_var_2.buffer[0] ^ 149) & 3;
    switch (stage_v_146) {
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

    /* Execution Pipeline Stage 147 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_1.buffer[1] * 2 + 451) & 63;
    if (stage_v_148 > 36) {
        out_sink = (out_sink + stage_v_148 - 5) & 255;
        if (stage_v_148 > 51) {
            chk_sum ^= (stage_v_148 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_148 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_2.buffer[2] * 2 + 454) & 63;
    if (stage_v_149 > 26) {
        out_sink = (out_sink + stage_v_149 - 5) & 255;
        if (stage_v_149 > 41) {
            chk_sum ^= (stage_v_149 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_149 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 153) & 15;
    int stage_v_152 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= stage_v_152;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 33) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 48) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[1] * 2 + 496) & 63;
    if (stage_v_163 > 16) {
        out_sink = (out_sink + stage_v_163 - 5) & 255;
        if (stage_v_163 > 31) {
            chk_sum ^= (stage_v_163 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_163 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 164 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 165) & 15;
    int stage_v_164 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= stage_v_164;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = table[1];
    table[1] = (table[2] + 331) & 63;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 167) & 15;
    int stage_v_166 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= stage_v_166;

    /* Execution Pipeline Stage 167 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 169) & 15;
    int stage_v_168 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= stage_v_168;

    /* Execution Pipeline Stage 169 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 170) & 15;
    int stage_v_169 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= stage_v_169;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 172) & 15;
    int stage_v_171 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= stage_v_171;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_2.buffer[0] ^ 176) & 3;
    switch (stage_v_173) {
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

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_174 = (stage_v_174 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[1] * 2 + 532) & 63;
    if (stage_v_175 > 37) {
        out_sink = (out_sink + stage_v_175 - 5) & 255;
        if (stage_v_175 > 52) {
            chk_sum ^= (stage_v_175 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_175 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_2.buffer[0] ^ 179) & 3;
    switch (stage_v_176) {
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

    /* Execution Pipeline Stage 177 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 178) & 15;
    int stage_v_177 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= stage_v_177;

    /* Execution Pipeline Stage 178 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 179) & 15;
    int stage_v_178 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_178) & 255;
    chk_sum ^= stage_v_178;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_2.buffer[0] ^ 182) & 3;
    switch (stage_v_179) {
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

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] ^ 183) & 3;
    switch (stage_v_180) {
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

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (st_var_1.buffer[1] * 2 + 550) & 63;
    if (stage_v_181 > 14) {
        out_sink = (out_sink + stage_v_181 - 5) & 255;
        if (stage_v_181 > 29) {
            chk_sum ^= (stage_v_181 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_181 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Security Information Flow: Family = direct_leakage */
    out_sink += ((sec_r000135_16 * 2)) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
