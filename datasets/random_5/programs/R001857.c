/*
 * Benchmark Program: R001857
 * Security Family: nested_implicit_flow
 * Generator Seed: 685713
 * High Inputs: 17 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001857_5713_0 {
    unsigned char id;
    int parity;
    unsigned char baud_rate;
    int timeout;
    int stop_bits;
    unsigned char port;
    int buffer[3];
};

struct StreamBuffer_R001857_5713_1 {
    unsigned char checksum;
    int state;
    short watermark;
    int buffer[3];
};

union ColorPixel_R001857_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001857_5713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001857_5713_0(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_51 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_51 = (pivot_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_51) & 127;
    }
    int cursor_40 = (aux + st.buffer[1]) & 3;
    switch (cursor_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int residue_10 = (aux + st.buffer[1]) & 3;
    switch (residue_10) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_24 = local_arr[aux % 3];
    acc = (acc + damping_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001857_5713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_70 = (aux + st.buffer[1]) & 3;
    switch (parity_70) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_70) & 63;
    acc ^= aux;
    int tracker_28 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_28 > 47) {
        acc = (acc + tracker_28 * 2 + 5) & 127;
        aux ^= (tracker_28 & 15);
    } else {
        acc = (acc - tracker_28 + 11) & 127;
        aux += 3;
    }
    int anchor_64 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_64 = (anchor_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_3(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int pivot_65 = local_arr[aux % 3];
    acc = (acc + pivot_65 * 2) & 127;
    int quantum_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001857_5713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int scale_41 = 0;
    for (int k = 0; k < 2; k++) {
        scale_41 = (scale_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_41) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_35 = local_arr[aux % 3];
    acc = (acc + mask_35 * 2) & 127;
    int cursor_27 = (aux + st.buffer[1]) & 3;
    switch (cursor_27) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_5(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_69 = (aux + st.buffer[1]) & 3;
    switch (weight_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_75 = 0;
    for (int k = 0; k < 3; k++) {
        scale_75 = (scale_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_75) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_50 = local_arr[aux % 3];
    acc = (acc + residue_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001857_5713_6(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int accumulator_85 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_85 = (accumulator_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_85) & 127;
    }
    int offset_45 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_45 > 31) {
        acc = (acc + offset_45 * 2 + 5) & 127;
        aux ^= (offset_45 & 15);
    } else {
        acc = (acc - offset_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int delta_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_30) & 63;
    acc ^= aux;
    int window_21 = (aux + st.buffer[1]) & 3;
    switch (window_21) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_27 = local_arr[aux % 3];
    acc = (acc + parity_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001857_5713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int delta_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_61 = local_arr[aux % 3];
    acc = (acc + segment_61 * 2) & 127;
    int margin_91 = 0;
    for (int k = 0; k < 3; k++) {
        margin_91 = (margin_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_91) & 127;
    }
    int tracker_45 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_45 > 37) {
        acc = (acc + tracker_45 * 2 + 5) & 127;
        aux ^= (tracker_45 & 15);
    } else {
        acc = (acc - tracker_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_9(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int margin_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_48 = local_arr[aux % 3];
    acc = (acc + parity_48 * 2) & 127;
    int threshold_32 = (aux + st.buffer[1]) & 3;
    switch (threshold_32) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_41 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_41 > 36) {
        acc = (acc + pivot_41 * 2 + 5) & 127;
        aux ^= (pivot_41 & 15);
    } else {
        acc = (acc - pivot_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_97 = 0;
    for (int k = 0; k < 2; k++) {
        metric_97 = (metric_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_97) & 127;
    }
    int sample_78 = (aux + st.buffer[1]) & 3;
    switch (sample_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_33) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_80 = local_arr[aux % 3];
    acc = (acc + accumulator_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001857_5713_12(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int damping_94 = 0;
    for (int k = 0; k < 2; k++) {
        damping_94 = (damping_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_94) & 127;
    }
    int mask_11 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_11 > 15) {
        acc = (acc + mask_11 * 2 + 5) & 127;
        aux ^= (mask_11 & 15);
    } else {
        acc = (acc - mask_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_48 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_48 > 23) {
        acc = (acc + margin_48 * 2 + 5) & 127;
        aux ^= (margin_48 & 15);
    } else {
        acc = (acc - margin_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_70 = local_arr[aux % 3];
    acc = (acc + tracker_70 * 2) & 127;
    int index_reg_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001857_5713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int bound_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_69) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_43 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_43 > 24) {
        acc = (acc + tracker_43 * 2 + 5) & 127;
        aux ^= (tracker_43 & 15);
    } else {
        acc = (acc - tracker_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_34 = local_arr[aux % 3];
    acc = (acc + metric_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001857_5713_15(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tracker_90 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_90 = (tracker_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_90) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_39 = local_arr[aux % 3];
    acc = (acc + residue_39 * 2) & 127;
    int residue_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001857_5713_16(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int sample_86 = local_arr[aux % 3];
    acc = (acc + sample_86 * 2) & 127;
    int phase_92 = (aux + st.buffer[1]) & 3;
    switch (phase_92) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_17(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_29 = 0;
    for (int k = 0; k < 2; k++) {
        parity_29 = (parity_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_29) & 127;
    }
    int delta_63 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_63 > 26) {
        acc = (acc + delta_63 * 2 + 5) & 127;
        aux ^= (delta_63 & 15);
    } else {
        acc = (acc - delta_63 + 11) & 127;
        aux += 3;
    }
    int parity_52 = (aux + st.buffer[1]) & 3;
    switch (parity_52) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001857_5713_18(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int anchor_53 = local_arr[aux % 3];
    acc = (acc + anchor_53 * 2) & 127;
    int offset_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001857_5713_19(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_32 = (aux + st.buffer[1]) & 3;
    switch (offset_32) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_20(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int offset_97 = local_arr[aux % 3];
    acc = (acc + offset_97 * 2) & 127;
    int sample_14 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_14 > 11) {
        acc = (acc + sample_14 * 2 + 5) & 127;
        aux ^= (sample_14 & 15);
    } else {
        acc = (acc - sample_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001857_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_30 = (aux + st.buffer[1]) & 3;
    switch (threshold_30) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_84 = local_arr[aux % 3];
    acc = (acc + quantum_84 * 2) & 127;
    int margin_14 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_14 > 17) {
        acc = (acc + margin_14 * 2 + 5) & 127;
        aux ^= (margin_14 & 15);
    } else {
        acc = (acc - margin_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001857_5713_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001857_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_76 = 0;
    for (int k = 0; k < 2; k++) {
        damping_76 = (damping_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_76) & 127;
    }
    int mask_52 = (aux + st.buffer[1]) & 3;
    switch (mask_52) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_15 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_15 > 11) {
        acc = (acc + metric_15 * 2 + 5) & 127;
        aux ^= (metric_15 & 15);
    } else {
        acc = (acc - metric_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_85 = local_arr[aux % 3];
    acc = (acc + vector_85 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001857_0;
    int sec_r001857_1;
    int sec_r001857_2;
    int sec_r001857_3;
    int sec_r001857_4;
    int sec_r001857_5;
    int sec_r001857_6;
    int sec_r001857_7;
    int sec_r001857_8;
    int sec_r001857_9;
    int sec_r001857_10;
    int sec_r001857_11;
    int sec_r001857_12;
    int sec_r001857_13;
    int sec_r001857_14;
    int sec_r001857_15;
    int sec_r001857_16;
    int pub_r001857_0;
    int pub_r001857_1;
    int pub_r001857_2;
    int pub_r001857_3;
    int pub_r001857_4;
    int pub_r001857_5;
    int pub_r001857_6;
    int pub_r001857_7;
    int pub_r001857_8;
    int pub_r001857_9;
    int pub_r001857_10;
    int pub_r001857_11;
    int pub_r001857_12;
    int pub_r001857_13;
    int pub_r001857_14;
    int pub_r001857_15;
    int pub_r001857_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001857_0 >= -100 && pub_r001857_0 <= 100);
    __CPROVER_assume(pub_r001857_1 >= -100 && pub_r001857_1 <= 100);
    __CPROVER_assume(pub_r001857_2 >= -100 && pub_r001857_2 <= 100);
    __CPROVER_assume(pub_r001857_3 >= -100 && pub_r001857_3 <= 100);
    __CPROVER_assume(pub_r001857_4 >= -100 && pub_r001857_4 <= 100);
    __CPROVER_assume(pub_r001857_5 >= -100 && pub_r001857_5 <= 100);
    __CPROVER_assume(pub_r001857_6 >= -100 && pub_r001857_6 <= 100);
    __CPROVER_assume(pub_r001857_7 >= -100 && pub_r001857_7 <= 100);
    __CPROVER_assume(pub_r001857_8 >= -100 && pub_r001857_8 <= 100);
    __CPROVER_assume(pub_r001857_9 >= -100 && pub_r001857_9 <= 100);
    __CPROVER_assume(pub_r001857_10 >= -100 && pub_r001857_10 <= 100);
    __CPROVER_assume(pub_r001857_11 >= -100 && pub_r001857_11 <= 100);
    __CPROVER_assume(pub_r001857_12 >= -100 && pub_r001857_12 <= 100);
    __CPROVER_assume(pub_r001857_13 >= -100 && pub_r001857_13 <= 100);
    __CPROVER_assume(pub_r001857_14 >= -100 && pub_r001857_14 <= 100);
    __CPROVER_assume(pub_r001857_15 >= -100 && pub_r001857_15 <= 100);
    __CPROVER_assume(pub_r001857_16 >= -100 && pub_r001857_16 <= 100);
    __CPROVER_assume(sec_r001857_0 >= 0 && sec_r001857_0 <= 255);
    __CPROVER_assume(sec_r001857_1 >= 0 && sec_r001857_1 <= 255);
    __CPROVER_assume(sec_r001857_2 >= 0 && sec_r001857_2 <= 255);
    __CPROVER_assume(sec_r001857_3 >= 0 && sec_r001857_3 <= 255);
    __CPROVER_assume(sec_r001857_4 >= 0 && sec_r001857_4 <= 255);
    __CPROVER_assume(sec_r001857_5 >= 0 && sec_r001857_5 <= 255);
    __CPROVER_assume(sec_r001857_6 >= 0 && sec_r001857_6 <= 255);
    __CPROVER_assume(sec_r001857_7 >= 0 && sec_r001857_7 <= 255);
    __CPROVER_assume(sec_r001857_8 >= 0 && sec_r001857_8 <= 255);
    __CPROVER_assume(sec_r001857_9 >= 0 && sec_r001857_9 <= 255);
    __CPROVER_assume(sec_r001857_10 >= 0 && sec_r001857_10 <= 255);
    __CPROVER_assume(sec_r001857_11 >= 0 && sec_r001857_11 <= 255);
    __CPROVER_assume(sec_r001857_12 >= 0 && sec_r001857_12 <= 255);
    __CPROVER_assume(sec_r001857_13 >= 0 && sec_r001857_13 <= 255);
    __CPROVER_assume(sec_r001857_14 >= 0 && sec_r001857_14 <= 255);
    __CPROVER_assume(sec_r001857_15 >= 0 && sec_r001857_15 <= 255);
    __CPROVER_assume(sec_r001857_16 >= 0 && sec_r001857_16 <= 255);

    struct DeviceConfig_R001857_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001857_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001857_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001857_0 + 7) & 15;
    struct StreamBuffer_R001857_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001857_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001857_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001857_0 + 9) & 15;

    union ColorPixel_R001857_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001857_5713_0(sec_r001857_0, pub_r001857_1);
    int helper_flow_1 = fn_R001857_5713_1(sec_r001857_1, sec_r001857_2, pub_r001857_3, pub_r001857_4, pub_r001857_5);
    int helper_flow_2 = fn_R001857_5713_2(sec_r001857_2, sec_r001857_3, pub_r001857_4, pub_r001857_5);
    int helper_flow_3 = fn_R001857_5713_3(sec_r001857_3, sec_r001857_4);
    int helper_flow_4 = fn_R001857_5713_4(sec_r001857_4, pub_r001857_5, pub_r001857_6, pub_r001857_7, pub_r001857_8);
    int helper_flow_5 = fn_R001857_5713_5(sec_r001857_5, sec_r001857_6);
    int helper_flow_6 = fn_R001857_5713_6(sec_r001857_6, sec_r001857_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_1 ^ pub_r001857_3) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001857_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001857_2 ^ pub_r001857_15) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001857_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001857_0 ^ pub_r001857_8) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001857_15 ^ pub_r001857_12) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001857_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (stage_v_0 ^ pub_r001857_7) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001857_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001857_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001857_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001857_3 ^ pub_r001857_13) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001857_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001857_0 ^ pub_r001857_8) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001857_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001857_14 ^ pub_r001857_7) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001857_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_4 ^ pub_r001857_16) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001857_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001857_8 ^ pub_r001857_13) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r001857_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_1 ^ pub_r001857_7) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001857_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001857_16 ^ pub_r001857_14) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001857_0 ^ pub_r001857_2) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001857_2 ^ pub_r001857_13) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r001857_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001857_9 ^ pub_r001857_12) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001857_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001857_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (helper_flow_4 ^ pub_r001857_6) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_6 ^ pub_r001857_12) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001857_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001857_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001857_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001857_6 ^ pub_r001857_16) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001857_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_4 ^ pub_r001857_11) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r001857_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_17 ^ pub_r001857_1) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001857_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001857_3 ^ pub_r001857_11) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_4 ^ pub_r001857_7) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_1 ^ pub_r001857_16) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001857_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001857_2 ^ pub_r001857_14) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001857_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001857_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001857_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001857_0 ^ pub_r001857_9) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001857_13 ^ pub_r001857_0) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001857_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001857_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001857_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001857_10 ^ pub_r001857_3) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_13 ^ pub_r001857_3) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_33 ^ pub_r001857_15) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001857_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_39 ^ pub_r001857_6) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001857_9 ^ pub_r001857_11) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_14 ^ pub_r001857_13) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001857_0 ^ pub_r001857_10) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_0 ^ pub_r001857_0) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_43 ^ pub_r001857_10) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001857_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_45 ^ pub_r001857_7) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001857_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_45 ^ pub_r001857_12) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_0 ^ pub_r001857_5) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001857_0 ^ pub_r001857_4) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r001857_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_23 ^ pub_r001857_4) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (helper_flow_2 ^ pub_r001857_5) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001857_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_43 ^ pub_r001857_4) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_12 ^ pub_r001857_9) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001857_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001857_15 ^ pub_r001857_5) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r001857_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001857_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001857_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001857_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_62 ^ pub_r001857_9) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (helper_flow_3 ^ pub_r001857_3) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_44 ^ pub_r001857_16) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001857_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001857_2 ^ pub_r001857_10) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r001857_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001857_11 ^ pub_r001857_15) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r001857_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_32 ^ pub_r001857_11) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r001857_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_32 ^ pub_r001857_16) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001857_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_16 ^ pub_r001857_12) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r001857_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001857_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_12 ^ pub_r001857_15) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_16 ^ pub_r001857_6) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001857_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_79 ^ pub_r001857_2) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_57 ^ pub_r001857_2) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_52 ^ pub_r001857_3) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_34 ^ pub_r001857_1) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001857_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_34 ^ pub_r001857_0) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_63 ^ pub_r001857_12) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r001857_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001857_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001857_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001857_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_86 ^ pub_r001857_10) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r001857_16 ^ pub_r001857_9) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_30 ^ pub_r001857_14) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r001857_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_74 ^ pub_r001857_2) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_10 ^ pub_r001857_2) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001857_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_85 ^ pub_r001857_9) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_94 ^ pub_r001857_14) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_32 ^ pub_r001857_11) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001857_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001857_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001857_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001857_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_39 ^ pub_r001857_9) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r001857_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r001857_7 ^ pub_r001857_6) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001857_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_5 ^ pub_r001857_5) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_2 ^ pub_r001857_6) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r001857_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001857_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001857_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001857_7 ^ pub_r001857_5) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r001857_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_79 ^ pub_r001857_14) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_108 ^ pub_r001857_7) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_54 ^ pub_r001857_2) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r001857_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_69 ^ pub_r001857_5) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001857_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_70 ^ pub_r001857_3) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_60 ^ pub_r001857_6) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r001857_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_87 ^ pub_r001857_15) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001857_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001857_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001857_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001857_6 ^ pub_r001857_12) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_119 ^ pub_r001857_12) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001857_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_112 ^ pub_r001857_8) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001857_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_84 ^ pub_r001857_0) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (helper_flow_3 ^ pub_r001857_8) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r001857_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_124 ^ pub_r001857_16) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_130 ^ pub_r001857_7) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001857_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_131 ^ pub_r001857_12) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r001857_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001857_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001857_16 ^ pub_r001857_13) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_57 ^ pub_r001857_13) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (helper_flow_2 ^ pub_r001857_15) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001857_11 ^ pub_r001857_7) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (helper_flow_6 ^ pub_r001857_7) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_19 ^ pub_r001857_13) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001857_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_17 ^ pub_r001857_7) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001857_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_6 ^ pub_r001857_14) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001857_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001857_11 ^ pub_r001857_6) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_62 ^ pub_r001857_4) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001857_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001857_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (sec_r001857_14 ^ pub_r001857_9) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_84 ^ pub_r001857_6) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r001857_15 ^ pub_r001857_5) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001857_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_91 ^ pub_r001857_2) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_33 ^ pub_r001857_4) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (helper_flow_2 ^ pub_r001857_1) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((sec_r001857_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_2 ^ pub_r001857_10) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_12 ^ pub_r001857_12) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001857_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_70 ^ pub_r001857_0) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001857_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001857_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_69 ^ pub_r001857_0) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_111 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_85 ^ pub_r001857_8) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r001857_15 ^ pub_r001857_13) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_144 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001857_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_56 ^ pub_r001857_12) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (sec_r001857_4 ^ pub_r001857_2) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001857_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
