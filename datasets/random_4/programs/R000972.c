/*
 * Benchmark Program: R000972
 * Family: mixed_control_data
 * Generator Seed: 497213
 * High Inputs: 18 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000972_7213_0 {
    int baud_rate;
    int id;
    int port;
    unsigned char timeout;
    int buffer[3];
};

struct AudioFrame_R000972_7213_1 {
    int channels;
    int sample_rate;
    int envelope;
    short rms;
    unsigned char gain;
    int peak;
    int buffer[3];
};

struct SensorNode_R000972_7213_2 {
    int gain;
    int reading;
    int calib;
    int buffer[3];
};

union PacketPayload_R000972_7213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000972_7213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000972_7213_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_99 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_99 > 14) {
        acc = (acc + sample_99 * 2 + 5) & 127;
        aux ^= (sample_99 & 15);
    } else {
        acc = (acc - sample_99 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000972_7213_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000972_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_99) & 63;
    acc ^= aux;
    int margin_94 = 0;
    for (int k = 0; k < 2; k++) {
        margin_94 = (margin_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_94) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_92 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_92 > 35) {
        acc = (acc + factor_92 * 2 + 5) & 127;
        aux ^= (factor_92 & 15);
    } else {
        acc = (acc - factor_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_2(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_62 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_62 > 28) {
        acc = (acc + offset_62 * 2 + 5) & 127;
        aux ^= (offset_62 & 15);
    } else {
        acc = (acc - offset_62 + 11) & 127;
        aux += 3;
    }
    int parity_63 = (aux + st.buffer[1]) & 3;
    switch (parity_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_15 = local_arr[aux % 3];
    acc = (acc + cursor_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000972_7213_3(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000972_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int coefficient_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_92) & 63;
    acc ^= aux;
    int tracker_73 = (aux + st.buffer[1]) & 3;
    switch (tracker_73) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_14 = local_arr[aux % 3];
    acc = (acc + threshold_14 * 2) & 127;
    int anchor_99 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_99 = (anchor_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_4(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int tally_10 = local_arr[aux % 3];
    acc = (acc + tally_10 * 2) & 127;
    int vector_73 = 0;
    for (int k = 0; k < 2; k++) {
        vector_73 = (vector_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_5(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int offset_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_50) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_23 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_23 > 30) {
        acc = (acc + delta_23 * 2 + 5) & 127;
        aux ^= (delta_23 & 15);
    } else {
        acc = (acc - delta_23 + 11) & 127;
        aux += 3;
    }
    int tally_71 = 0;
    for (int k = 0; k < 3; k++) {
        tally_71 = (tally_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_45 = (st.buffer[0] * 3 + aux) & 63;
    if (window_45 > 44) {
        acc = (acc + window_45 * 2 + 5) & 127;
        aux ^= (window_45 & 15);
    } else {
        acc = (acc - window_45 + 11) & 127;
        aux += 3;
    }
    int factor_41 = 0;
    for (int k = 0; k < 2; k++) {
        factor_41 = (factor_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_41) & 127;
    }
    int pivot_74 = (aux + st.buffer[1]) & 3;
    switch (pivot_74) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_7(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int parity_61 = 0;
    for (int k = 0; k < 2; k++) {
        parity_61 = (parity_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_61) & 127;
    }
    int factor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_69 > 14) {
        acc = (acc + factor_69 * 2 + 5) & 127;
        aux ^= (factor_69 & 15);
    } else {
        acc = (acc - factor_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_8(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tally_44 = 0;
    for (int k = 0; k < 3; k++) {
        tally_44 = (tally_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_44) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_45 = local_arr[aux % 3];
    acc = (acc + segment_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000972_7213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int parity_25 = local_arr[aux % 3];
    acc = (acc + parity_25 * 2) & 127;
    int anchor_98 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_98 = (anchor_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_98) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000972_7213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int delta_90 = (aux + st.buffer[1]) & 3;
    switch (delta_90) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000972_7213_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_26 = (aux + st.buffer[1]) & 3;
    switch (delta_26) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_28 = 0;
    for (int k = 0; k < 3; k++) {
        vector_28 = (vector_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int mask_50 = local_arr[aux % 3];
    acc = (acc + mask_50 * 2) & 127;
    int accumulator_42 = (aux + st.buffer[1]) & 3;
    switch (accumulator_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_94 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_94 > 20) {
        acc = (acc + accumulator_94 * 2 + 5) & 127;
        aux ^= (accumulator_94 & 15);
    } else {
        acc = (acc - accumulator_94 + 11) & 127;
        aux += 3;
    }
    int tally_35 = 0;
    for (int k = 0; k < 3; k++) {
        tally_35 = (tally_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_35) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_71 = (aux + st.buffer[1]) & 3;
    switch (coefficient_71) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_45 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_45 > 20) {
        acc = (acc + tracker_45 * 2 + 5) & 127;
        aux ^= (tracker_45 & 15);
    } else {
        acc = (acc - tracker_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_15(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quantum_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_55) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_96 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_96 = (cursor_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_96) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_16(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_97 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_97 > 38) {
        acc = (acc + cursor_97 * 2 + 5) & 127;
        aux ^= (cursor_97 & 15);
    } else {
        acc = (acc - cursor_97 + 11) & 127;
        aux += 3;
    }
    int parity_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_99) & 63;
    acc ^= aux;
    int residue_11 = (aux + st.buffer[1]) & 3;
    switch (residue_11) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000972_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int delta_12 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_12 > 28) {
        acc = (acc + delta_12 * 2 + 5) & 127;
        aux ^= (delta_12 & 15);
    } else {
        acc = (acc - delta_12 + 11) & 127;
        aux += 3;
    }
    int tracker_75 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_75 = (tracker_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_75) & 127;
    }
    int quotient_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000972_7213_18(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int quotient_20 = local_arr[aux % 3];
    acc = (acc + quotient_20 * 2) & 127;
    int stride_58 = 0;
    for (int k = 0; k < 3; k++) {
        stride_58 = (stride_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_58) & 127;
    }
    int quantum_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000972_7213_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000972_7213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_39 = local_arr[aux % 3];
    acc = (acc + factor_39 * 2) & 127;
    int stride_40 = (aux + st.buffer[1]) & 3;
    switch (stride_40) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tracker_17 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_17 > 42) {
        acc = (acc + tracker_17 * 2 + 5) & 127;
        aux ^= (tracker_17 & 15);
    } else {
        acc = (acc - tracker_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_36 = local_arr[aux % 3];
    acc = (acc + scale_36 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_25 = (aux + st.buffer[1]) & 3;
    switch (damping_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_39 = local_arr[aux % 3];
    acc = (acc + accumulator_39 * 2) & 127;
    int offset_29 = 0;
    for (int k = 0; k < 2; k++) {
        offset_29 = (offset_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_29) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000972_7213_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000972_7213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int phase_27 = local_arr[aux % 3];
    acc = (acc + phase_27 * 2) & 127;
    int index_reg_88 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_88 = (index_reg_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_88) & 127;
    }
    int offset_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000972_7213_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000972_7213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int window_49 = 0;
    for (int k = 0; k < 2; k++) {
        window_49 = (window_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_49) & 127;
    }
    int pivot_70 = (aux + st.buffer[1]) & 3;
    switch (pivot_70) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000972_0;
    int sec_r000972_1;
    int sec_r000972_2;
    int sec_r000972_3;
    int sec_r000972_4;
    int sec_r000972_5;
    int sec_r000972_6;
    int sec_r000972_7;
    int sec_r000972_8;
    int sec_r000972_9;
    int sec_r000972_10;
    int sec_r000972_11;
    int sec_r000972_12;
    int sec_r000972_13;
    int sec_r000972_14;
    int sec_r000972_15;
    int sec_r000972_16;
    int sec_r000972_17;
    int pub_r000972_0;
    int pub_r000972_1;
    int pub_r000972_2;
    int pub_r000972_3;
    int pub_r000972_4;
    int pub_r000972_5;
    int pub_r000972_6;
    int pub_r000972_7;
    int pub_r000972_8;
    int pub_r000972_9;
    int pub_r000972_10;
    int pub_r000972_11;
    int pub_r000972_12;
    int pub_r000972_13;
    int pub_r000972_14;
    int pub_r000972_15;
    int pub_r000972_16;
    int pub_r000972_17;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000972_0 >= -100 && pub_r000972_0 <= 100);
    __CPROVER_assume(pub_r000972_1 >= -100 && pub_r000972_1 <= 100);
    __CPROVER_assume(pub_r000972_2 >= -100 && pub_r000972_2 <= 100);
    __CPROVER_assume(pub_r000972_3 >= -100 && pub_r000972_3 <= 100);
    __CPROVER_assume(pub_r000972_4 >= -100 && pub_r000972_4 <= 100);
    __CPROVER_assume(pub_r000972_5 >= -100 && pub_r000972_5 <= 100);
    __CPROVER_assume(pub_r000972_6 >= -100 && pub_r000972_6 <= 100);
    __CPROVER_assume(pub_r000972_7 >= -100 && pub_r000972_7 <= 100);
    __CPROVER_assume(pub_r000972_8 >= -100 && pub_r000972_8 <= 100);
    __CPROVER_assume(pub_r000972_9 >= -100 && pub_r000972_9 <= 100);
    __CPROVER_assume(pub_r000972_10 >= -100 && pub_r000972_10 <= 100);
    __CPROVER_assume(pub_r000972_11 >= -100 && pub_r000972_11 <= 100);
    __CPROVER_assume(pub_r000972_12 >= -100 && pub_r000972_12 <= 100);
    __CPROVER_assume(pub_r000972_13 >= -100 && pub_r000972_13 <= 100);
    __CPROVER_assume(pub_r000972_14 >= -100 && pub_r000972_14 <= 100);
    __CPROVER_assume(pub_r000972_15 >= -100 && pub_r000972_15 <= 100);
    __CPROVER_assume(pub_r000972_16 >= -100 && pub_r000972_16 <= 100);
    __CPROVER_assume(pub_r000972_17 >= -100 && pub_r000972_17 <= 100);
    __CPROVER_assume(sec_r000972_0 >= 0 && sec_r000972_0 <= 255);
    __CPROVER_assume(sec_r000972_1 >= 0 && sec_r000972_1 <= 255);
    __CPROVER_assume(sec_r000972_2 >= 0 && sec_r000972_2 <= 255);
    __CPROVER_assume(sec_r000972_3 >= 0 && sec_r000972_3 <= 255);
    __CPROVER_assume(sec_r000972_4 >= 0 && sec_r000972_4 <= 255);
    __CPROVER_assume(sec_r000972_5 >= 0 && sec_r000972_5 <= 255);
    __CPROVER_assume(sec_r000972_6 >= 0 && sec_r000972_6 <= 255);
    __CPROVER_assume(sec_r000972_7 >= 0 && sec_r000972_7 <= 255);
    __CPROVER_assume(sec_r000972_8 >= 0 && sec_r000972_8 <= 255);
    __CPROVER_assume(sec_r000972_9 >= 0 && sec_r000972_9 <= 255);
    __CPROVER_assume(sec_r000972_10 >= 0 && sec_r000972_10 <= 255);
    __CPROVER_assume(sec_r000972_11 >= 0 && sec_r000972_11 <= 255);
    __CPROVER_assume(sec_r000972_12 >= 0 && sec_r000972_12 <= 255);
    __CPROVER_assume(sec_r000972_13 >= 0 && sec_r000972_13 <= 255);
    __CPROVER_assume(sec_r000972_14 >= 0 && sec_r000972_14 <= 255);
    __CPROVER_assume(sec_r000972_15 >= 0 && sec_r000972_15 <= 255);
    __CPROVER_assume(sec_r000972_16 >= 0 && sec_r000972_16 <= 255);
    __CPROVER_assume(sec_r000972_17 >= 0 && sec_r000972_17 <= 255);

    struct DeviceConfig_R000972_7213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000972_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000972_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000972_0 + 7) & 15;
    struct AudioFrame_R000972_7213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000972_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000972_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000972_0 + 9) & 15;
    struct SensorNode_R000972_7213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000972_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000972_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000972_0 + 11) & 15;

    union PacketPayload_R000972_7213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 38) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 53) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 25) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 40) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 24) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 39) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 20) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 35) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 13) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 28) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 14) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 29) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 11) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 26) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 12) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 27) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

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
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 25) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 40) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_1.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 25) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 40) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = table[0];
    table[0] = (table[1] + 169) & 63;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (out_sink > 100) ? (chk_sum & 31) : (91 & 31);
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= (stage_v_86 << 1) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 31) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 46) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[1] * 2 + 280) & 63;
    if (stage_v_91 > 40) {
        out_sink = (out_sink + stage_v_91 - 5) & 255;
        if (stage_v_91 > 55) {
            chk_sum ^= (stage_v_91 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_91 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_94 = (st_var_1.buffer[1] * 2 + 289) & 63;
    if (stage_v_94 > 19) {
        out_sink = (out_sink + stage_v_94 - 5) & 255;
        if (stage_v_94 > 34) {
            chk_sum ^= (stage_v_94 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_94 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_2.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 19) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 34) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_96 = (stage_v_96 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 98) & 15;
    int stage_v_97 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= stage_v_97;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_108 = (stage_v_108 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 27) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 42) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_2.buffer[2] * 2 + 355) & 63;
    if (stage_v_116 > 34) {
        out_sink = (out_sink + stage_v_116 - 5) & 255;
        if (stage_v_116 > 49) {
            chk_sum ^= (stage_v_116 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_116 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (out_sink > 100) ? (chk_sum & 31) : (122 & 31);
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= (stage_v_117 << 1) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_2.buffer[0] ^ 122) & 3;
    switch (stage_v_119) {
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

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 122) & 15;
    int stage_v_121 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= stage_v_121;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (out_sink > 100) ? (chk_sum & 31) : (128 & 31);
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= (stage_v_123 << 1) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

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
    int stage_v_127 = (st_var_1.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 35) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 50) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 130) & 15;
    int stage_v_129 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= stage_v_129;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (out_sink > 100) ? (chk_sum & 31) : (135 & 31);
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= (stage_v_130 << 1) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_2.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 20) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 35) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[0] ^ 136) & 3;
    switch (stage_v_133) {
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

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_1.buffer[1] * 2 + 415) & 63;
    if (stage_v_136 > 23) {
        out_sink = (out_sink + stage_v_136 - 5) & 255;
        if (stage_v_136 > 38) {
            chk_sum ^= (stage_v_136 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_136 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_139 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_2.buffer[2] * 2 + 427) & 63;
    if (stage_v_140 > 24) {
        out_sink = (out_sink + stage_v_140 - 5) & 255;
        if (stage_v_140 > 39) {
            chk_sum ^= (stage_v_140 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_140 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = table[3];
    table[3] = (table[0] + 287) & 63;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = table[1];
    table[1] = (table[2] + 291) & 63;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = table[1];
    table[1] = (table[2] + 299) & 63;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_2.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 31) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 46) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = table[1];
    table[1] = (table[2] + 307) & 63;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[1] * 2 + 478) & 63;
    if (stage_v_157 > 36) {
        out_sink = (out_sink + stage_v_157 - 5) & 255;
        if (stage_v_157 > 51) {
            chk_sum ^= (stage_v_157 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_157 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = table[3];
    table[3] = (table[0] + 319) & 63;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_2.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] ^ 171) & 3;
    switch (stage_v_168) {
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

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = table[1];
    table[1] = (table[2] + 339) & 63;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_1.buffer[0] ^ 175) & 3;
    switch (stage_v_172) {
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

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000972_4 ^ 0x55) & 63;
    if (m_var > 20) {
        out_sink += (m_var * 2 + pub_r000972_11) & 127;
    } else {
        out_sink -= (m_var + 11) & 31;
    }
    out_sink ^= (sec_r000972_7 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
