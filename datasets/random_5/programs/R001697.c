/*
 * Benchmark Program: R001697
 * Security Family: nested_implicit_flow
 * Generator Seed: 669713
 * High Inputs: 23 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001697_9713_0 {
    unsigned char id;
    unsigned char parity;
    int timeout;
    int buffer[3];
};

struct EventLog_R001697_9713_1 {
    int seq;
    int signature;
    int facility;
    int buffer[3];
};

union ColorPixel_R001697_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001697_9713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_47) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_23 = local_arr[aux % 3];
    acc = (acc + segment_23 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_54 = (aux + st.buffer[1]) & 3;
    switch (factor_54) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int tracker_55 = (aux + st.buffer[1]) & 3;
    switch (tracker_55) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_22 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_22 > 39) {
        acc = (acc + tracker_22 * 2 + 5) & 127;
        aux ^= (tracker_22 & 15);
    } else {
        acc = (acc - tracker_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_2(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int cursor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_21) & 63;
    acc ^= aux;
    int residue_92 = 0;
    for (int k = 0; k < 2; k++) {
        residue_92 = (residue_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_92) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_3(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int index_reg_69 = (aux + st.buffer[1]) & 3;
    switch (index_reg_69) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_85 = local_arr[aux % 3];
    acc = (acc + delta_85 * 2) & 127;
    int vector_61 = 0;
    for (int k = 0; k < 2; k++) {
        vector_61 = (vector_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int delta_57 = (aux + st.buffer[1]) & 3;
    switch (delta_57) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_54 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_54 = (quantum_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_54) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_22 = local_arr[aux % 3];
    acc = (acc + threshold_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001697_9713_5(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_99 = local_arr[aux % 3];
    acc = (acc + accumulator_99 * 2) & 127;
    int bound_19 = (aux + st.buffer[1]) & 3;
    switch (bound_19) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_6(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int window_62 = (aux + st.buffer[1]) & 3;
    switch (window_62) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001697_9713_7(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_70 = (aux + st.buffer[1]) & 3;
    switch (tally_70) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_29 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_29 > 29) {
        acc = (acc + weight_29 * 2 + 5) & 127;
        aux ^= (weight_29 & 15);
    } else {
        acc = (acc - weight_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_8(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_97) & 63;
    acc ^= aux;
    int scale_17 = 0;
    for (int k = 0; k < 2; k++) {
        scale_17 = (scale_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_17) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_99 = local_arr[aux % 3];
    acc = (acc + anchor_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001697_9713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int accumulator_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_23) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_21 = local_arr[aux % 3];
    acc = (acc + scale_21 * 2) & 127;
    int weight_45 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_45 > 28) {
        acc = (acc + weight_45 * 2 + 5) & 127;
        aux ^= (weight_45 & 15);
    } else {
        acc = (acc - weight_45 + 11) & 127;
        aux += 3;
    }
    int factor_23 = (aux + st.buffer[1]) & 3;
    switch (factor_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_10(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int metric_86 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_86 > 48) {
        acc = (acc + metric_86 * 2 + 5) & 127;
        aux ^= (metric_86 & 15);
    } else {
        acc = (acc - metric_86 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_29 = local_arr[aux % 3];
    acc = (acc + factor_29 * 2) & 127;
    int delta_64 = 0;
    for (int k = 0; k < 2; k++) {
        delta_64 = (delta_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_72 = 0;
    for (int k = 0; k < 3; k++) {
        offset_72 = (offset_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_72) & 127;
    }
    int margin_54 = (aux + st.buffer[1]) & 3;
    switch (margin_54) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001697_9713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_48) & 63;
    acc ^= aux;
    int stride_71 = 0;
    for (int k = 0; k < 2; k++) {
        stride_71 = (stride_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_16 = (aux + st.buffer[1]) & 3;
    switch (mask_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_40 = local_arr[aux % 3];
    acc = (acc + checksum_40 * 2) & 127;
    int anchor_37 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_37 = (anchor_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_37) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int parity_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_85) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_75 = local_arr[aux % 3];
    acc = (acc + checksum_75 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001697_9713_15(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_46 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_46 > 36) {
        acc = (acc + anchor_46 * 2 + 5) & 127;
        aux ^= (anchor_46 & 15);
    } else {
        acc = (acc - anchor_46 + 11) & 127;
        aux += 3;
    }
    int tracker_11 = (aux + st.buffer[1]) & 3;
    switch (tracker_11) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_55 = 0;
    for (int k = 0; k < 3; k++) {
        metric_55 = (metric_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int pivot_39 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_39 = (pivot_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_39) & 127;
    }
    int anchor_55 = (aux + st.buffer[1]) & 3;
    switch (anchor_55) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_68 = local_arr[aux % 3];
    acc = (acc + phase_68 * 2) & 127;
    int checksum_77 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_77 > 26) {
        acc = (acc + checksum_77 * 2 + 5) & 127;
        aux ^= (checksum_77 & 15);
    } else {
        acc = (acc - checksum_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int sample_33 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_33 > 21) {
        acc = (acc + sample_33 * 2 + 5) & 127;
        aux ^= (sample_33 & 15);
    } else {
        acc = (acc - sample_33 + 11) & 127;
        aux += 3;
    }
    int offset_72 = 0;
    for (int k = 0; k < 3; k++) {
        offset_72 = (offset_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_72) & 127;
    }
    int mask_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_37 = local_arr[aux % 3];
    acc = (acc + anchor_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001697_9713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001697_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int scale_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_88) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_72 = local_arr[aux % 3];
    acc = (acc + stride_72 * 2) & 127;
    int accumulator_24 = (aux + st.buffer[1]) & 3;
    switch (accumulator_24) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001697_9713_19(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_73) & 63;
    acc ^= aux;
    int metric_88 = (aux + st.buffer[1]) & 3;
    switch (metric_88) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_80 = local_arr[aux % 3];
    acc = (acc + accumulator_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001697_9713_20(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int tally_47 = local_arr[aux % 3];
    acc = (acc + tally_47 * 2) & 127;
    int delta_55 = 0;
    for (int k = 0; k < 3; k++) {
        delta_55 = (delta_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_55) & 127;
    }
    int sample_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001697_9713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001697_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quotient_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_14) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001697_0;
    int sec_r001697_1;
    int sec_r001697_2;
    int sec_r001697_3;
    int sec_r001697_4;
    int sec_r001697_5;
    int sec_r001697_6;
    int sec_r001697_7;
    int sec_r001697_8;
    int sec_r001697_9;
    int sec_r001697_10;
    int sec_r001697_11;
    int sec_r001697_12;
    int sec_r001697_13;
    int sec_r001697_14;
    int sec_r001697_15;
    int sec_r001697_16;
    int sec_r001697_17;
    int sec_r001697_18;
    int sec_r001697_19;
    int sec_r001697_20;
    int sec_r001697_21;
    int sec_r001697_22;
    int pub_r001697_0;
    int pub_r001697_1;
    int pub_r001697_2;
    int pub_r001697_3;
    int pub_r001697_4;
    int pub_r001697_5;
    int pub_r001697_6;
    int pub_r001697_7;
    int pub_r001697_8;
    int pub_r001697_9;
    int pub_r001697_10;
    int pub_r001697_11;
    int pub_r001697_12;
    int pub_r001697_13;
    int pub_r001697_14;
    int pub_r001697_15;
    int pub_r001697_16;
    int pub_r001697_17;
    int pub_r001697_18;
    int pub_r001697_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001697_0 >= -100 && pub_r001697_0 <= 100);
    __CPROVER_assume(pub_r001697_1 >= -100 && pub_r001697_1 <= 100);
    __CPROVER_assume(pub_r001697_2 >= -100 && pub_r001697_2 <= 100);
    __CPROVER_assume(pub_r001697_3 >= -100 && pub_r001697_3 <= 100);
    __CPROVER_assume(pub_r001697_4 >= -100 && pub_r001697_4 <= 100);
    __CPROVER_assume(pub_r001697_5 >= -100 && pub_r001697_5 <= 100);
    __CPROVER_assume(pub_r001697_6 >= -100 && pub_r001697_6 <= 100);
    __CPROVER_assume(pub_r001697_7 >= -100 && pub_r001697_7 <= 100);
    __CPROVER_assume(pub_r001697_8 >= -100 && pub_r001697_8 <= 100);
    __CPROVER_assume(pub_r001697_9 >= -100 && pub_r001697_9 <= 100);
    __CPROVER_assume(pub_r001697_10 >= -100 && pub_r001697_10 <= 100);
    __CPROVER_assume(pub_r001697_11 >= -100 && pub_r001697_11 <= 100);
    __CPROVER_assume(pub_r001697_12 >= -100 && pub_r001697_12 <= 100);
    __CPROVER_assume(pub_r001697_13 >= -100 && pub_r001697_13 <= 100);
    __CPROVER_assume(pub_r001697_14 >= -100 && pub_r001697_14 <= 100);
    __CPROVER_assume(pub_r001697_15 >= -100 && pub_r001697_15 <= 100);
    __CPROVER_assume(pub_r001697_16 >= -100 && pub_r001697_16 <= 100);
    __CPROVER_assume(pub_r001697_17 >= -100 && pub_r001697_17 <= 100);
    __CPROVER_assume(pub_r001697_18 >= -100 && pub_r001697_18 <= 100);
    __CPROVER_assume(pub_r001697_19 >= -100 && pub_r001697_19 <= 100);
    __CPROVER_assume(sec_r001697_0 >= 0 && sec_r001697_0 <= 255);
    __CPROVER_assume(sec_r001697_1 >= 0 && sec_r001697_1 <= 255);
    __CPROVER_assume(sec_r001697_2 >= 0 && sec_r001697_2 <= 255);
    __CPROVER_assume(sec_r001697_3 >= 0 && sec_r001697_3 <= 255);
    __CPROVER_assume(sec_r001697_4 >= 0 && sec_r001697_4 <= 255);
    __CPROVER_assume(sec_r001697_5 >= 0 && sec_r001697_5 <= 255);
    __CPROVER_assume(sec_r001697_6 >= 0 && sec_r001697_6 <= 255);
    __CPROVER_assume(sec_r001697_7 >= 0 && sec_r001697_7 <= 255);
    __CPROVER_assume(sec_r001697_8 >= 0 && sec_r001697_8 <= 255);
    __CPROVER_assume(sec_r001697_9 >= 0 && sec_r001697_9 <= 255);
    __CPROVER_assume(sec_r001697_10 >= 0 && sec_r001697_10 <= 255);
    __CPROVER_assume(sec_r001697_11 >= 0 && sec_r001697_11 <= 255);
    __CPROVER_assume(sec_r001697_12 >= 0 && sec_r001697_12 <= 255);
    __CPROVER_assume(sec_r001697_13 >= 0 && sec_r001697_13 <= 255);
    __CPROVER_assume(sec_r001697_14 >= 0 && sec_r001697_14 <= 255);
    __CPROVER_assume(sec_r001697_15 >= 0 && sec_r001697_15 <= 255);
    __CPROVER_assume(sec_r001697_16 >= 0 && sec_r001697_16 <= 255);
    __CPROVER_assume(sec_r001697_17 >= 0 && sec_r001697_17 <= 255);
    __CPROVER_assume(sec_r001697_18 >= 0 && sec_r001697_18 <= 255);
    __CPROVER_assume(sec_r001697_19 >= 0 && sec_r001697_19 <= 255);
    __CPROVER_assume(sec_r001697_20 >= 0 && sec_r001697_20 <= 255);
    __CPROVER_assume(sec_r001697_21 >= 0 && sec_r001697_21 <= 255);
    __CPROVER_assume(sec_r001697_22 >= 0 && sec_r001697_22 <= 255);

    struct DeviceConfig_R001697_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001697_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001697_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001697_0 + 7) & 15;
    struct EventLog_R001697_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001697_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001697_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001697_0 + 9) & 15;

    union ColorPixel_R001697_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001697_9713_0(sec_r001697_0, sec_r001697_1, pub_r001697_2, pub_r001697_3);
    int helper_flow_1 = fn_R001697_9713_1(sec_r001697_1, pub_r001697_2, pub_r001697_3, pub_r001697_4);
    int helper_flow_2 = fn_R001697_9713_2(sec_r001697_2, sec_r001697_3);
    int helper_flow_3 = fn_R001697_9713_3(sec_r001697_3, pub_r001697_4, pub_r001697_5);
    int helper_flow_4 = fn_R001697_9713_4(sec_r001697_4, pub_r001697_5, pub_r001697_6, pub_r001697_7);
    int helper_flow_5 = fn_R001697_9713_5(sec_r001697_5, pub_r001697_6);
    int helper_flow_6 = fn_R001697_9713_6(sec_r001697_6, sec_r001697_7, pub_r001697_8);
    int helper_flow_7 = fn_R001697_9713_7(sec_r001697_7, sec_r001697_8, pub_r001697_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001697_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001697_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001697_0 ^ pub_r001697_19) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001697_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001697_22 ^ pub_r001697_13) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001697_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001697_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001697_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001697_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001697_0 ^ pub_r001697_0) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001697_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_2 ^ pub_r001697_1) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001697_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001697_0 ^ pub_r001697_6) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001697_10 ^ pub_r001697_1) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001697_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001697_14 ^ pub_r001697_2) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_6 ^ pub_r001697_9) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_8 ^ pub_r001697_12) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001697_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_0 ^ pub_r001697_15) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001697_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001697_4 ^ pub_r001697_8) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001697_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_4 ^ pub_r001697_18) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_4 ^ pub_r001697_7) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001697_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001697_9 ^ pub_r001697_6) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_10 ^ pub_r001697_15) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001697_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (helper_flow_1 ^ pub_r001697_11) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001697_3 ^ pub_r001697_14) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001697_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001697_5 ^ pub_r001697_9) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001697_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001697_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001697_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001697_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_16 ^ pub_r001697_10) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001697_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001697_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_6 ^ pub_r001697_6) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001697_20 ^ pub_r001697_16) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_4 ^ pub_r001697_15) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001697_13 ^ pub_r001697_4) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001697_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_10 ^ pub_r001697_18) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001697_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_30 ^ pub_r001697_16) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001697_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_2 ^ pub_r001697_15) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001697_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (helper_flow_7 ^ pub_r001697_8) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001697_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_10 ^ pub_r001697_11) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001697_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_22 ^ pub_r001697_4) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_9 ^ pub_r001697_10) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_2 ^ pub_r001697_11) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_5 ^ pub_r001697_6) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_18 ^ pub_r001697_14) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_23 ^ pub_r001697_4) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (helper_flow_1 ^ pub_r001697_15) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001697_19 ^ pub_r001697_2) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001697_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_33 ^ pub_r001697_18) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r001697_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001697_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001697_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001697_14 ^ pub_r001697_1) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_24 ^ pub_r001697_4) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001697_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001697_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_32 ^ pub_r001697_9) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_34 ^ pub_r001697_14) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001697_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001697_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001697_13 ^ pub_r001697_0) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (helper_flow_5 ^ pub_r001697_8) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001697_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001697_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001697_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_16 ^ pub_r001697_19) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001697_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_9 ^ pub_r001697_16) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001697_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_56 ^ pub_r001697_8) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001697_20 ^ pub_r001697_10) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001697_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_33 ^ pub_r001697_10) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (helper_flow_3 ^ pub_r001697_8) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001697_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_9 ^ pub_r001697_4) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r001697_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001697_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_22 ^ pub_r001697_17) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_56 ^ pub_r001697_16) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (helper_flow_3 ^ pub_r001697_3) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_8 ^ pub_r001697_8) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r001697_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_13 ^ pub_r001697_10) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r001697_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001697_20 ^ pub_r001697_0) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_10 ^ pub_r001697_1) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001697_2 ^ pub_r001697_4) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_14 ^ pub_r001697_1) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001697_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001697_21 ^ pub_r001697_4) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_73 ^ pub_r001697_1) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_37 ^ pub_r001697_10) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_67 ^ pub_r001697_19) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001697_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_7 ^ pub_r001697_14) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001697_16 ^ pub_r001697_3) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001697_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_45 ^ pub_r001697_0) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r001697_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_83 ^ pub_r001697_19) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r001697_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_78 ^ pub_r001697_10) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001697_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_43 ^ pub_r001697_11) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r001697_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_36 ^ pub_r001697_0) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001697_4 ^ pub_r001697_6) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_66 ^ pub_r001697_9) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r001697_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001697_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_16 ^ pub_r001697_3) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_77 ^ pub_r001697_11) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r001697_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_16 ^ pub_r001697_4) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_53 ^ pub_r001697_7) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_69 ^ pub_r001697_0) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001697_2 ^ pub_r001697_12) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r001697_19 ^ pub_r001697_7) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r001697_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001697_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001697_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r001697_14 ^ pub_r001697_14) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001697_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001697_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001697_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_45 ^ pub_r001697_7) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_97 ^ pub_r001697_7) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001697_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001697_16 ^ pub_r001697_5) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001697_21 ^ pub_r001697_10) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_59 ^ pub_r001697_13) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_44 ^ pub_r001697_19) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001697_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001697_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_24 ^ pub_r001697_7) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001697_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001697_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_13 ^ pub_r001697_6) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_116 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001697_1 ^ pub_r001697_5) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r001697_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_39 ^ pub_r001697_8) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001697_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_45 ^ pub_r001697_10) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r001697_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_30 ^ pub_r001697_11) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r001697_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001697_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001697_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_70 ^ pub_r001697_0) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_73 ^ pub_r001697_14) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_116 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001697_1 ^ pub_r001697_7) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_124 ^ pub_r001697_16) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_83 ^ pub_r001697_0) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_88 ^ pub_r001697_13) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_23 ^ pub_r001697_4) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001697_5 ^ pub_r001697_11) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((sec_r001697_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (helper_flow_2 ^ pub_r001697_17) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r001697_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_97 ^ pub_r001697_0) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_75 ^ pub_r001697_0) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_125 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001697_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_85 ^ pub_r001697_0) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_137 ^ pub_r001697_12) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001697_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001697_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001697_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_128 ^ pub_r001697_4) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_46 ^ pub_r001697_8) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_16 ^ pub_r001697_8) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_126 ^ pub_r001697_3) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001697_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001697_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001697_13 ^ pub_r001697_17) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_136 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001697_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_112 ^ pub_r001697_11) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001697_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001697_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001697_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r001697_22 ^ pub_r001697_10) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((sec_r001697_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_118 ^ pub_r001697_5) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_70 ^ pub_r001697_11) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001697_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001697_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_9 ^ pub_r001697_2) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (helper_flow_3 ^ pub_r001697_13) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_140 ^ pub_r001697_9) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((sec_r001697_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001697_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (helper_flow_2 ^ pub_r001697_16) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_73 ^ pub_r001697_4) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001697_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001697_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r001697_9 ^ pub_r001697_7) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((sec_r001697_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_19 ^ pub_r001697_6) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((sec_r001697_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
