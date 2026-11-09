/*
 * Benchmark Program: R001266
 * Security Family: implicit_flow
 * Generator Seed: 626613
 * High Inputs: 17 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001266_6613_0 {
    unsigned char timestamp;
    short code;
    unsigned char signature;
    int buffer[3];
};

struct DeviceConfig_R001266_6613_1 {
    int baud_rate;
    int port;
    int stop_bits;
    int buffer[3];
};

union ColorPixel_R001266_6613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001266_6613_0(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_89 = local_arr[aux % 3];
    acc = (acc + residue_89 * 2) & 127;
    int coefficient_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_70) & 63;
    acc ^= aux;
    int segment_95 = 0;
    for (int k = 0; k < 2; k++) {
        segment_95 = (segment_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_95) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_1(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int parity_93 = local_arr[aux % 3];
    acc = (acc + parity_93 * 2) & 127;
    int window_92 = (aux + st.buffer[1]) & 3;
    switch (window_92) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001266_6613_3(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int threshold_67 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_67 > 37) {
        acc = (acc + threshold_67 * 2 + 5) & 127;
        aux ^= (threshold_67 & 15);
    } else {
        acc = (acc - threshold_67 + 11) & 127;
        aux += 3;
    }
    int sample_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001266_6613_4(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int residue_40 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_40 > 36) {
        acc = (acc + residue_40 * 2 + 5) & 127;
        aux ^= (residue_40 & 15);
    } else {
        acc = (acc - residue_40 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_43 = local_arr[aux % 3];
    acc = (acc + cursor_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_5(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int factor_71 = 0;
    for (int k = 0; k < 2; k++) {
        factor_71 = (factor_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_71) & 127;
    }
    int weight_97 = (aux + st.buffer[1]) & 3;
    switch (weight_97) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_10 = local_arr[aux % 3];
    acc = (acc + damping_10 * 2) & 127;
    int window_84 = (st.buffer[0] * 3 + aux) & 63;
    if (window_84 > 24) {
        acc = (acc + window_84 * 2 + 5) & 127;
        aux ^= (window_84 & 15);
    } else {
        acc = (acc - window_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_6(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_47 = (aux + st.buffer[1]) & 3;
    switch (mask_47) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_38 = 0;
    for (int k = 0; k < 3; k++) {
        residue_38 = (residue_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_38) & 127;
    }
    int cursor_31 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_31 > 49) {
        acc = (acc + cursor_31 * 2 + 5) & 127;
        aux ^= (cursor_31 & 15);
    } else {
        acc = (acc - cursor_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_33 = local_arr[aux % 3];
    acc = (acc + scale_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_61 = local_arr[aux % 3];
    acc = (acc + window_61 * 2) & 127;
    int cursor_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_23) & 63;
    acc ^= aux;
    int offset_28 = (aux + st.buffer[1]) & 3;
    switch (offset_28) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_8(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int delta_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_99) & 63;
    acc ^= aux;
    int accumulator_49 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_49 = (accumulator_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_49) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int weight_13 = local_arr[aux % 3];
    acc = (acc + weight_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_10(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_13 = (aux + st.buffer[1]) & 3;
    switch (margin_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_17 = 0;
    for (int k = 0; k < 3; k++) {
        window_17 = (window_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_17) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_11(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int pivot_77 = (aux + st.buffer[1]) & 3;
    switch (pivot_77) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_24 = 0;
    for (int k = 0; k < 2; k++) {
        offset_24 = (offset_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_24) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_16 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_16 > 29) {
        acc = (acc + mask_16 * 2 + 5) & 127;
        aux ^= (mask_16 & 15);
    } else {
        acc = (acc - mask_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_12(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_54 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_54 > 50) {
        acc = (acc + offset_54 * 2 + 5) & 127;
        aux ^= (offset_54 & 15);
    } else {
        acc = (acc - offset_54 + 11) & 127;
        aux += 3;
    }
    int tracker_40 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_40 = (tracker_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_13(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int coefficient_22 = (aux + st.buffer[1]) & 3;
    switch (coefficient_22) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_80 = 0;
    for (int k = 0; k < 2; k++) {
        tally_80 = (tally_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_14(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quotient_41 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_41 > 11) {
        acc = (acc + quotient_41 * 2 + 5) & 127;
        aux ^= (quotient_41 & 15);
    } else {
        acc = (acc - quotient_41 + 11) & 127;
        aux += 3;
    }
    int index_reg_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001266_6613_15(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int stride_53 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_53 > 37) {
        acc = (acc + stride_53 * 2 + 5) & 127;
        aux ^= (stride_53 & 15);
    } else {
        acc = (acc - stride_53 + 11) & 127;
        aux += 3;
    }
    int mask_33 = (aux + st.buffer[1]) & 3;
    switch (mask_33) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int tracker_91 = local_arr[aux % 3];
    acc = (acc + tracker_91 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_46 = 0;
    for (int k = 0; k < 2; k++) {
        stride_46 = (stride_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_46) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int delta_48 = local_arr[aux % 3];
    acc = (acc + delta_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_17 = (aux + st.buffer[1]) & 3;
    switch (offset_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001266_6613_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_84 = local_arr[aux % 3];
    acc = (acc + index_reg_84 * 2) & 127;
    int cursor_11 = (aux + st.buffer[1]) & 3;
    switch (cursor_11) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001266_6613_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int bound_37 = local_arr[aux % 3];
    acc = (acc + bound_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_20(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001266_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int anchor_66 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_66 > 48) {
        acc = (acc + anchor_66 * 2 + 5) & 127;
        aux ^= (anchor_66 & 15);
    } else {
        acc = (acc - anchor_66 + 11) & 127;
        aux += 3;
    }
    int tracker_75 = (aux + st.buffer[1]) & 3;
    switch (tracker_75) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_26) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001266_6613_21(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001266_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_55 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_55 > 19) {
        acc = (acc + threshold_55 * 2 + 5) & 127;
        aux ^= (threshold_55 & 15);
    } else {
        acc = (acc - threshold_55 + 11) & 127;
        aux += 3;
    }
    int metric_46 = 0;
    for (int k = 0; k < 2; k++) {
        metric_46 = (metric_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_46) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001266_0;
    int sec_r001266_1;
    int sec_r001266_2;
    int sec_r001266_3;
    int sec_r001266_4;
    int sec_r001266_5;
    int sec_r001266_6;
    int sec_r001266_7;
    int sec_r001266_8;
    int sec_r001266_9;
    int sec_r001266_10;
    int sec_r001266_11;
    int sec_r001266_12;
    int sec_r001266_13;
    int sec_r001266_14;
    int sec_r001266_15;
    int sec_r001266_16;
    int pub_r001266_0;
    int pub_r001266_1;
    int pub_r001266_2;
    int pub_r001266_3;
    int pub_r001266_4;
    int pub_r001266_5;
    int pub_r001266_6;
    int pub_r001266_7;
    int pub_r001266_8;
    int pub_r001266_9;
    int pub_r001266_10;
    int pub_r001266_11;
    int pub_r001266_12;
    int pub_r001266_13;
    int pub_r001266_14;
    int pub_r001266_15;
    int pub_r001266_16;
    int pub_r001266_17;
    int pub_r001266_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001266_0 >= -100 && pub_r001266_0 <= 100);
    __CPROVER_assume(pub_r001266_1 >= -100 && pub_r001266_1 <= 100);
    __CPROVER_assume(pub_r001266_2 >= -100 && pub_r001266_2 <= 100);
    __CPROVER_assume(pub_r001266_3 >= -100 && pub_r001266_3 <= 100);
    __CPROVER_assume(pub_r001266_4 >= -100 && pub_r001266_4 <= 100);
    __CPROVER_assume(pub_r001266_5 >= -100 && pub_r001266_5 <= 100);
    __CPROVER_assume(pub_r001266_6 >= -100 && pub_r001266_6 <= 100);
    __CPROVER_assume(pub_r001266_7 >= -100 && pub_r001266_7 <= 100);
    __CPROVER_assume(pub_r001266_8 >= -100 && pub_r001266_8 <= 100);
    __CPROVER_assume(pub_r001266_9 >= -100 && pub_r001266_9 <= 100);
    __CPROVER_assume(pub_r001266_10 >= -100 && pub_r001266_10 <= 100);
    __CPROVER_assume(pub_r001266_11 >= -100 && pub_r001266_11 <= 100);
    __CPROVER_assume(pub_r001266_12 >= -100 && pub_r001266_12 <= 100);
    __CPROVER_assume(pub_r001266_13 >= -100 && pub_r001266_13 <= 100);
    __CPROVER_assume(pub_r001266_14 >= -100 && pub_r001266_14 <= 100);
    __CPROVER_assume(pub_r001266_15 >= -100 && pub_r001266_15 <= 100);
    __CPROVER_assume(pub_r001266_16 >= -100 && pub_r001266_16 <= 100);
    __CPROVER_assume(pub_r001266_17 >= -100 && pub_r001266_17 <= 100);
    __CPROVER_assume(pub_r001266_18 >= -100 && pub_r001266_18 <= 100);
    __CPROVER_assume(sec_r001266_0 >= 0 && sec_r001266_0 <= 255);
    __CPROVER_assume(sec_r001266_1 >= 0 && sec_r001266_1 <= 255);
    __CPROVER_assume(sec_r001266_2 >= 0 && sec_r001266_2 <= 255);
    __CPROVER_assume(sec_r001266_3 >= 0 && sec_r001266_3 <= 255);
    __CPROVER_assume(sec_r001266_4 >= 0 && sec_r001266_4 <= 255);
    __CPROVER_assume(sec_r001266_5 >= 0 && sec_r001266_5 <= 255);
    __CPROVER_assume(sec_r001266_6 >= 0 && sec_r001266_6 <= 255);
    __CPROVER_assume(sec_r001266_7 >= 0 && sec_r001266_7 <= 255);
    __CPROVER_assume(sec_r001266_8 >= 0 && sec_r001266_8 <= 255);
    __CPROVER_assume(sec_r001266_9 >= 0 && sec_r001266_9 <= 255);
    __CPROVER_assume(sec_r001266_10 >= 0 && sec_r001266_10 <= 255);
    __CPROVER_assume(sec_r001266_11 >= 0 && sec_r001266_11 <= 255);
    __CPROVER_assume(sec_r001266_12 >= 0 && sec_r001266_12 <= 255);
    __CPROVER_assume(sec_r001266_13 >= 0 && sec_r001266_13 <= 255);
    __CPROVER_assume(sec_r001266_14 >= 0 && sec_r001266_14 <= 255);
    __CPROVER_assume(sec_r001266_15 >= 0 && sec_r001266_15 <= 255);
    __CPROVER_assume(sec_r001266_16 >= 0 && sec_r001266_16 <= 255);

    struct EventLog_R001266_6613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001266_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001266_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001266_0 + 7) & 15;
    struct DeviceConfig_R001266_6613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001266_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001266_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001266_0 + 9) & 15;

    union ColorPixel_R001266_6613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001266_6613_0(sec_r001266_0, sec_r001266_1, pub_r001266_2);
    int helper_flow_1 = fn_R001266_6613_1(sec_r001266_1, sec_r001266_2, pub_r001266_3);
    int helper_flow_2 = fn_R001266_6613_2(sec_r001266_2, pub_r001266_3, pub_r001266_4, pub_r001266_5, pub_r001266_6);
    int helper_flow_3 = fn_R001266_6613_3(sec_r001266_3, sec_r001266_4, pub_r001266_5);
    int helper_flow_4 = fn_R001266_6613_4(sec_r001266_4, sec_r001266_5);
    int helper_flow_5 = fn_R001266_6613_5(sec_r001266_5, pub_r001266_6);
    int helper_flow_6 = fn_R001266_6613_6(sec_r001266_6, pub_r001266_7, pub_r001266_8);
    int helper_flow_7 = fn_R001266_6613_7(sec_r001266_7, sec_r001266_8, pub_r001266_9, pub_r001266_10, pub_r001266_11);
    int helper_flow_8 = fn_R001266_6613_8(sec_r001266_8, sec_r001266_9, pub_r001266_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001266_1 + pub_r001266_9 * 2 + 5) & 127;
    if (stage_v_0 > 37) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_3 + pub_r001266_11 * 2 + 8) & 127;
    if (stage_v_1 > 26) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001266_9 + pub_r001266_0 * 2 + 11) & 127;
    if (stage_v_2 > 32) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001266_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001266_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001266_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001266_0 + pub_r001266_7 * 2 + 23) & 127;
    if (stage_v_6 > 20) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_6 + pub_r001266_13 * 2 + 26) & 127;
    if (stage_v_7 > 22) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001266_0 + pub_r001266_1 * 2 + 29) & 127;
    if (stage_v_8 > 56) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001266_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001266_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_3 + pub_r001266_0 * 2 + 38) & 127;
    if (stage_v_11 > 48) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001266_6 + pub_r001266_18 * 2 + 41) & 127;
    if (stage_v_12 > 60) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001266_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001266_13 + pub_r001266_2 * 2 + 47) & 127;
    if (stage_v_14 > 38) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001266_16 + pub_r001266_8 * 2 + 50) & 127;
    if (stage_v_15 > 15) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001266_12 + pub_r001266_2 * 2 + 53) & 127;
    if (stage_v_16 > 47) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_12 + pub_r001266_8 * 2 + 56) & 127;
    if (stage_v_17 > 52) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_14 + pub_r001266_4 * 2 + 59) & 127;
    if (stage_v_18 > 52) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001266_0 + pub_r001266_10 * 2 + 62) & 127;
    if (stage_v_19 > 28) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_15 + pub_r001266_6 * 2 + 65) & 127;
    if (stage_v_20 > 45) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001266_11 + pub_r001266_1 * 2 + 68) & 127;
    if (stage_v_21 > 22) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001266_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001266_7 + pub_r001266_5 * 2 + 74) & 127;
    if (stage_v_23 > 17) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_6 + pub_r001266_17 * 2 + 77) & 127;
    if (stage_v_24 > 26) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001266_10 + pub_r001266_6 * 2 + 80) & 127;
    if (stage_v_25 > 51) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001266_16 + pub_r001266_14 * 2 + 83) & 127;
    if (stage_v_26 > 33) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_8 + pub_r001266_0 * 2 + 86) & 127;
    if (stage_v_27 > 38) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001266_6 + pub_r001266_18 * 2 + 89) & 127;
    if (stage_v_28 > 46) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_3 + pub_r001266_18 * 2 + 92) & 127;
    if (stage_v_29 > 18) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001266_4 + pub_r001266_15 * 2 + 95) & 127;
    if (stage_v_30 > 40) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001266_15 + pub_r001266_4 * 2 + 98) & 127;
    if (stage_v_31 > 35) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001266_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_14 + pub_r001266_9 * 2 + 104) & 127;
    if (stage_v_33 > 58) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001266_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001266_7 + pub_r001266_12 * 2 + 110) & 127;
    if (stage_v_35 > 36) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (helper_flow_4 + pub_r001266_9 * 2 + 113) & 127;
    if (stage_v_36 > 53) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_24 + pub_r001266_7 * 2 + 116) & 127;
    if (stage_v_37 > 32) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_27 + pub_r001266_2 * 2 + 119) & 127;
    if (stage_v_38 > 54) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001266_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_4 + pub_r001266_6 * 2 + 125) & 127;
    if (stage_v_40 > 25) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001266_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_18 + pub_r001266_3 * 2 + 131) & 127;
    if (stage_v_42 > 46) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001266_11 + pub_r001266_14 * 2 + 134) & 127;
    if (stage_v_43 > 47) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_33 + pub_r001266_15 * 2 + 137) & 127;
    if (stage_v_44 > 30) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_18 + pub_r001266_4 * 2 + 140) & 127;
    if (stage_v_45 > 41) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001266_14 + pub_r001266_14 * 2 + 143) & 127;
    if (stage_v_46 > 43) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001266_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_3 + pub_r001266_5 * 2 + 149) & 127;
    if (stage_v_48 > 49) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001266_13 + pub_r001266_15 * 2 + 152) & 127;
    if (stage_v_49 > 17) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001266_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001266_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001266_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_29 + pub_r001266_18 * 2 + 164) & 127;
    if (stage_v_53 > 54) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001266_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001266_9 + pub_r001266_16 * 2 + 170) & 127;
    if (stage_v_55 > 30) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (helper_flow_5 + pub_r001266_2 * 2 + 173) & 127;
    if (stage_v_56 > 42) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_15 + pub_r001266_3 * 2 + 176) & 127;
    if (stage_v_57 > 43) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001266_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001266_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_1 + pub_r001266_7 * 2 + 185) & 127;
    if (stage_v_60 > 26) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001266_9 + pub_r001266_1 * 2 + 188) & 127;
    if (stage_v_61 > 27) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001266_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001266_2 + pub_r001266_13 * 2 + 194) & 127;
    if (stage_v_63 > 50) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_0 + pub_r001266_15 * 2 + 197) & 127;
    if (stage_v_64 > 21) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_60 + pub_r001266_4 * 2 + 200) & 127;
    if (stage_v_65 > 28) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001266_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_6 + pub_r001266_5 * 2 + 206) & 127;
    if (stage_v_67 > 32) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (helper_flow_0 + pub_r001266_4 * 2 + 209) & 127;
    if (stage_v_68 > 39) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001266_11 + pub_r001266_15 * 2 + 212) & 127;
    if (stage_v_69 > 59) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001266_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001266_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001266_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (helper_flow_6 + pub_r001266_14 * 2 + 224) & 127;
    if (stage_v_73 > 32) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_56 + pub_r001266_13 * 2 + 227) & 127;
    if (stage_v_74 > 49) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001266_10 + pub_r001266_2 * 2 + 230) & 127;
    if (stage_v_75 > 45) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_53 + pub_r001266_3 * 2 + 233) & 127;
    if (stage_v_76 > 18) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001266_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_43 + pub_r001266_17 * 2 + 239) & 127;
    if (stage_v_78 > 43) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (helper_flow_8 + pub_r001266_2 * 2 + 242) & 127;
    if (stage_v_79 > 60) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_44 + pub_r001266_18 * 2 + 245) & 127;
    if (stage_v_80 > 20) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001266_11 + pub_r001266_15 * 2 + 248) & 127;
    if (stage_v_81 > 28) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (helper_flow_5 + pub_r001266_4 * 2 + 251) & 127;
    if (stage_v_82 > 43) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_14 + pub_r001266_8 * 2 + 254) & 127;
    if (stage_v_83 > 44) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001266_2 + pub_r001266_1 * 2 + 257) & 127;
    if (stage_v_84 > 27) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_36 + pub_r001266_14 * 2 + 260) & 127;
    if (stage_v_85 > 57) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001266_0 + pub_r001266_3 * 2 + 263) & 127;
    if (stage_v_86 > 41) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_6 + pub_r001266_13 * 2 + 266) & 127;
    if (stage_v_87 > 34) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001266_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_86 + pub_r001266_12 * 2 + 272) & 127;
    if (stage_v_89 > 34) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_20 + pub_r001266_17 * 2 + 275) & 127;
    if (stage_v_90 > 60) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001266_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001266_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001266_8 + pub_r001266_15 * 2 + 284) & 127;
    if (stage_v_93 > 59) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001266_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001266_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_21 + pub_r001266_7 * 2 + 293) & 127;
    if (stage_v_96 > 52) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001266_5 + pub_r001266_8 * 2 + 296) & 127;
    if (stage_v_97 > 57) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001266_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001266_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001266_10 + pub_r001266_9 * 2 + 305) & 127;
    if (stage_v_100 > 18) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_19 + pub_r001266_13 * 2 + 308) & 127;
    if (stage_v_101 > 46) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_56 + pub_r001266_6 * 2 + 311) & 127;
    if (stage_v_102 > 47) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_45 + pub_r001266_1 * 2 + 314) & 127;
    if (stage_v_103 > 43) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_48 + pub_r001266_12 * 2 + 317) & 127;
    if (stage_v_104 > 51) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_18 + pub_r001266_3 * 2 + 320) & 127;
    if (stage_v_105 > 28) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_90 + pub_r001266_18 * 2 + 323) & 127;
    if (stage_v_106 > 47) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (sec_r001266_12 + pub_r001266_18 * 2 + 326) & 127;
    if (stage_v_107 > 58) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001266_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_57 + pub_r001266_7 * 2 + 332) & 127;
    if (stage_v_109 > 29) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001266_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_81 + pub_r001266_4 * 2 + 338) & 127;
    if (stage_v_111 > 39) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_37 + pub_r001266_1 * 2 + 341) & 127;
    if (stage_v_112 > 57) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_38 + pub_r001266_13 * 2 + 344) & 127;
    if (stage_v_113 > 46) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001266_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001266_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001266_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (sec_r001266_0 + pub_r001266_15 * 2 + 356) & 127;
    if (stage_v_117 > 49) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001266_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (helper_flow_4 + pub_r001266_7 * 2 + 362) & 127;
    if (stage_v_119 > 20) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_53 + pub_r001266_0 * 2 + 365) & 127;
    if (stage_v_120 > 39) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_105 + pub_r001266_2 * 2 + 368) & 127;
    if (stage_v_121 > 51) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_74 + pub_r001266_17 * 2 + 371) & 127;
    if (stage_v_122 > 57) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001266_6 + pub_r001266_3 * 2 + 374) & 127;
    if (stage_v_123 > 27) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_73 + pub_r001266_3 * 2 + 377) & 127;
    if (stage_v_124 > 49) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001266_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_25 + pub_r001266_8 * 2 + 383) & 127;
    if (stage_v_126 > 58) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001266_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_40 + pub_r001266_4 * 2 + 389) & 127;
    if (stage_v_128 > 55) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_11 + pub_r001266_2 * 2 + 392) & 127;
    if (stage_v_129 > 26) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_83 + pub_r001266_0 * 2 + 395) & 127;
    if (stage_v_130 > 39) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r001266_9 + pub_r001266_8 * 2 + 398) & 127;
    if (stage_v_131 > 52) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_12 + pub_r001266_6 * 2 + 401) & 127;
    if (stage_v_132 > 47) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001266_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001266_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001266_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_64 + pub_r001266_2 * 2 + 413) & 127;
    if (stage_v_136 > 40) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001266_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_129 + pub_r001266_8 * 2 + 419) & 127;
    if (stage_v_138 > 52) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001266_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_63 + pub_r001266_13 * 2 + 425) & 127;
    if (stage_v_140 > 31) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001266_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001266_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_45 + pub_r001266_11 * 2 + 434) & 127;
    if (stage_v_143 > 32) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_61 + pub_r001266_16 * 2 + 437) & 127;
    if (stage_v_144 > 37) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001266_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_143 + pub_r001266_6 * 2 + 443) & 127;
    if (stage_v_146 > 47) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001266_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_40 + pub_r001266_10 * 2 + 449) & 127;
    if (stage_v_148 > 45) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001266_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (sec_r001266_6 + pub_r001266_3 * 2 + 455) & 127;
    if (stage_v_150 > 24) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_36 + pub_r001266_15 * 2 + 458) & 127;
    if (stage_v_151 > 50) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_76 + pub_r001266_12 * 2 + 461) & 127;
    if (stage_v_152 > 32) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001266_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001266_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001266_5 + pub_r001266_0 * 2 + 470) & 127;
    if (stage_v_155 > 41) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_150 + pub_r001266_13 * 2 + 473) & 127;
    if (stage_v_156 > 31) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001266_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_131 + pub_r001266_11 * 2 + 479) & 127;
    if (stage_v_158 > 18) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (sec_r001266_4 + pub_r001266_10 * 2 + 482) & 127;
    if (stage_v_159 > 38) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001266_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_6 + pub_r001266_18 * 2 + 488) & 127;
    if (stage_v_161 > 56) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001266_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_43 + pub_r001266_1 * 2 + 494) & 127;
    if (stage_v_163 > 22) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_6 + pub_r001266_16 * 2 + 497) & 127;
    if (stage_v_164 > 20) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_15 + pub_r001266_2 * 2 + 500) & 127;
    if (stage_v_165 > 29) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001266_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_15 + pub_r001266_0 * 2 + 506) & 127;
    if (stage_v_167 > 21) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001266_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_138 + pub_r001266_12 * 2 + 512) & 127;
    if (stage_v_169 > 29) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001266_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_102 + pub_r001266_2 * 2 + 518) & 127;
    if (stage_v_171 > 56) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_93 + pub_r001266_3 * 2 + 521) & 127;
    if (stage_v_172 > 57) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001266_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r001266_14 + pub_r001266_7 * 2 + 527) & 127;
    if (stage_v_174 > 41) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_7 + pub_r001266_15 * 2 + 530) & 127;
    if (stage_v_175 > 18) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001266_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_31 + pub_r001266_10 * 2 + 536) & 127;
    if (stage_v_177 > 51) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001266_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_33 + pub_r001266_1 * 2 + 542) & 127;
    if (stage_v_179 > 43) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_179 + pub_r001266_9 * 2 + 545) & 127;
    if (stage_v_180 > 48) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_82 + pub_r001266_9 * 2 + 548) & 127;
    if (stage_v_181 > 48) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_128 + pub_r001266_0 * 2 + 551) & 127;
    if (stage_v_182 > 46) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001266_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001266_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001266_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_57 + pub_r001266_14 * 2 + 563) & 127;
    if (stage_v_186 > 22) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_87 + pub_r001266_11 * 2 + 566) & 127;
    if (stage_v_187 > 23) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001266_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_123 + pub_r001266_5 * 2 + 572) & 127;
    if (stage_v_189 > 18) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001266_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001266_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001266_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_179 + pub_r001266_2 * 2 + 584) & 127;
    if (stage_v_193 > 49) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001266_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_119 + pub_r001266_8 * 2 + 590) & 127;
    if (stage_v_195 > 36) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001266_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001266_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001266_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_0 + pub_r001266_7 * 2 + 602) & 127;
    if (stage_v_199 > 43) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_187 + pub_r001266_17 * 2 + 605) & 127;
    if (stage_v_200 > 37) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_26 + pub_r001266_10 * 2 + 608) & 127;
    if (stage_v_201 > 23) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (sec_r001266_10 + pub_r001266_15 * 2 + 611) & 127;
    if (stage_v_202 > 27) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_119 + pub_r001266_14 * 2 + 614) & 127;
    if (stage_v_203 > 15) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r001266_13 + pub_r001266_7 * 2 + 617) & 127;
    if (stage_v_204 > 37) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_23 + pub_r001266_13 * 2 + 620) & 127;
    if (stage_v_205 > 39) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_30 + pub_r001266_14 * 2 + 623) & 127;
    if (stage_v_206 > 23) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001266_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_2 + pub_r001266_8 * 2 + 629) & 127;
    if (stage_v_208 > 60) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001266_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (sec_r001266_3 + pub_r001266_1 * 2 + 635) & 127;
    if (stage_v_210 > 41) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001266_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001266_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_159 + pub_r001266_5 * 2 + 644) & 127;
    if (stage_v_213 > 28) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001266_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001266_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_144 + pub_r001266_4 * 2 + 653) & 127;
    if (stage_v_216 > 47) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001266_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001266_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_76 + pub_r001266_2 * 2 + 662) & 127;
    if (stage_v_219 > 57) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001266_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_49 + pub_r001266_14 * 2 + 668) & 127;
    if (stage_v_221 > 52) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001266_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_101 + pub_r001266_7 * 2 + 674) & 127;
    if (stage_v_223 > 20) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001266_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001266_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001266_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001266_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001266_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (sec_r001266_14 + pub_r001266_11 * 2 + 692) & 127;
    if (stage_v_229 > 39) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_16 + pub_r001266_3 * 2 + 695) & 127;
    if (stage_v_230 > 58) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (sec_r001266_14 + pub_r001266_13 * 2 + 698) & 127;
    if (stage_v_231 > 25) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_43 + pub_r001266_16 * 2 + 701) & 127;
    if (stage_v_232 > 41) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_221 + pub_r001266_3 * 2 + 704) & 127;
    if (stage_v_233 > 49) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_6 + pub_r001266_8 * 2 + 707) & 127;
    if (stage_v_234 > 38) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_67 + pub_r001266_10 * 2 + 710) & 127;
    if (stage_v_235 > 30) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_144 + pub_r001266_9 * 2 + 713) & 127;
    if (stage_v_236 > 21) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_30 + pub_r001266_18 * 2 + 716) & 127;
    if (stage_v_237 > 28) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001266_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_233 + pub_r001266_16 * 2 + 722) & 127;
    if (stage_v_239 > 40) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (helper_flow_8 + pub_r001266_15 * 2 + 725) & 127;
    if (stage_v_240 > 47) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001266_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_169 + pub_r001266_3 * 2 + 731) & 127;
    if (stage_v_242 > 41) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_151 + pub_r001266_18 * 2 + 734) & 127;
    if (stage_v_243 > 40) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (helper_flow_8 + pub_r001266_3 * 2 + 737) & 127;
    if (stage_v_244 > 30) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_243 + pub_r001266_6 * 2 + 740) & 127;
    if (stage_v_245 > 41) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
        sec_accum ^= (stage_v_245 & 31);
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_130 + pub_r001266_16 * 2 + 743) & 127;
    if (stage_v_246 > 40) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_189 + pub_r001266_16 * 2 + 746) & 127;
    if (stage_v_247 > 59) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (helper_flow_5 + pub_r001266_14 * 2 + 749) & 127;
    if (stage_v_248 > 27) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
        sec_accum ^= (stage_v_248 & 31);
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_89 + pub_r001266_12 * 2 + 752) & 127;
    if (stage_v_249 > 31) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
        sec_accum ^= (stage_v_249 & 31);
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_175 + pub_r001266_5 * 2 + 755) & 127;
    if (stage_v_250 > 54) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
        sec_accum ^= (stage_v_250 & 31);
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_155 + pub_r001266_16 * 2 + 758) & 127;
    if (stage_v_251 > 42) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_239 + pub_r001266_14 * 2 + 761) & 127;
    if (stage_v_252 > 55) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
        sec_accum ^= (stage_v_252 & 31);
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
