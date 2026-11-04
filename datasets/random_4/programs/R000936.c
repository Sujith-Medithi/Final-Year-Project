/*
 * Benchmark Program: R000936
 * Family: mixed_control_data
 * Generator Seed: 493613
 * High Inputs: 22 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000936_3613_0 {
    unsigned char reading;
    int status;
    int gain;
    short calib;
    int offset;
    unsigned char threshold;
    int buffer[3];
};

struct AudioFrame_R000936_3613_1 {
    short gain;
    int channels;
    int rms;
    short sample_rate;
    int buffer[3];
};

struct DeviceConfig_R000936_3613_2 {
    int port;
    int id;
    int parity;
    short timeout;
    int buffer[3];
};

struct FilterState_R000936_3613_3 {
    int gain_db;
    int mode;
    int prev_out;
    int damping;
    short cutoff;
    unsigned char prev_in;
    int buffer[3];
};

union RegisterBank_R000936_3613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000936_3613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000936_3613_0(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000936_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_51 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_51 > 33) {
        acc = (acc + vector_51 * 2 + 5) & 127;
        aux ^= (vector_51 & 15);
    } else {
        acc = (acc - vector_51 + 11) & 127;
        aux += 3;
    }
    int scale_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000936_3613_1(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000936_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_13 = local_arr[aux % 3];
    acc = (acc + cursor_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000936_3613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000936_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_17 = 0;
    for (int k = 0; k < 3; k++) {
        damping_17 = (damping_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_17) & 127;
    }
    int anchor_97 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_97 > 28) {
        acc = (acc + anchor_97 * 2 + 5) & 127;
        aux ^= (anchor_97 & 15);
    } else {
        acc = (acc - anchor_97 + 11) & 127;
        aux += 3;
    }
    int parity_80 = (aux + st.buffer[1]) & 3;
    switch (parity_80) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_3(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000936_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_69 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_69 = (checksum_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_69) & 127;
    }
    int window_64 = (aux + st.buffer[1]) & 3;
    switch (window_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000936_3613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000936_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int margin_14 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_14 > 32) {
        acc = (acc + margin_14 * 2 + 5) & 127;
        aux ^= (margin_14 & 15);
    } else {
        acc = (acc - margin_14 + 11) & 127;
        aux += 3;
    }
    int quotient_24 = (aux + st.buffer[1]) & 3;
    switch (quotient_24) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_28 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_28 = (index_reg_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_28) & 127;
    }
    int delta_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000936_3613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000936_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_64 = 0;
    for (int k = 0; k < 3; k++) {
        bound_64 = (bound_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_64) & 127;
    }
    int damping_66 = (aux + st.buffer[1]) & 3;
    switch (damping_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_39 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_39 > 24) {
        acc = (acc + index_reg_39 * 2 + 5) & 127;
        aux ^= (index_reg_39 & 15);
    } else {
        acc = (acc - index_reg_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_6(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000936_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int accumulator_54 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_54 = (accumulator_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_54) & 127;
    }
    int segment_86 = (aux + st.buffer[1]) & 3;
    switch (segment_86) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000936_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_45 = 0;
    for (int k = 0; k < 2; k++) {
        residue_45 = (residue_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_45) & 127;
    }
    int coefficient_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000936_3613_8(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000936_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int mask_89 = 0;
    for (int k = 0; k < 2; k++) {
        mask_89 = (mask_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_89) & 127;
    }
    int residue_76 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_76 > 42) {
        acc = (acc + residue_76 * 2 + 5) & 127;
        aux ^= (residue_76 & 15);
    } else {
        acc = (acc - residue_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_9(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000936_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int segment_44 = 0;
    for (int k = 0; k < 3; k++) {
        segment_44 = (segment_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_44) & 127;
    }
    int delta_26 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_26 > 19) {
        acc = (acc + delta_26 * 2 + 5) & 127;
        aux ^= (delta_26 & 15);
    } else {
        acc = (acc - delta_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000936_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int accumulator_72 = local_arr[aux % 3];
    acc = (acc + accumulator_72 * 2) & 127;
    int tracker_98 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_98 > 39) {
        acc = (acc + tracker_98 * 2 + 5) & 127;
        aux ^= (tracker_98 & 15);
    } else {
        acc = (acc - tracker_98 + 11) & 127;
        aux += 3;
    }
    int factor_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000936_3613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000936_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int tracker_74 = local_arr[aux % 3];
    acc = (acc + tracker_74 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_97 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_97 > 21) {
        acc = (acc + margin_97 * 2 + 5) & 127;
        aux ^= (margin_97 & 15);
    } else {
        acc = (acc - margin_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_12(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000936_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_42 = (aux + st.buffer[1]) & 3;
    switch (cursor_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_98 = 0;
    for (int k = 0; k < 2; k++) {
        mask_98 = (mask_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_98) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000936_3613_13(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000936_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int phase_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_40) & 63;
    acc ^= aux;
    int sample_52 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_52 > 17) {
        acc = (acc + sample_52 * 2 + 5) & 127;
        aux ^= (sample_52 & 15);
    } else {
        acc = (acc - sample_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000936_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int scale_38 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_38 > 39) {
        acc = (acc + scale_38 * 2 + 5) & 127;
        aux ^= (scale_38 & 15);
    } else {
        acc = (acc - scale_38 + 11) & 127;
        aux += 3;
    }
    int damping_19 = (aux + st.buffer[1]) & 3;
    switch (damping_19) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000936_3613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000936_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_80 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_80 = (pivot_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_80) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_80 = local_arr[aux % 3];
    acc = (acc + quantum_80 * 2) & 127;
    int sample_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000936_3613_16(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000936_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int stride_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_60) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_59 = local_arr[aux % 3];
    acc = (acc + threshold_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000936_3613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000936_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int delta_58 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_58 > 15) {
        acc = (acc + delta_58 * 2 + 5) & 127;
        aux ^= (delta_58 & 15);
    } else {
        acc = (acc - delta_58 + 11) & 127;
        aux += 3;
    }
    int bound_91 = (aux + st.buffer[1]) & 3;
    switch (bound_91) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_74 = 0;
    for (int k = 0; k < 3; k++) {
        scale_74 = (scale_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_74) & 127;
    }
    int segment_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000936_3613_18(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000936_3613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_14 = 0;
    for (int k = 0; k < 2; k++) {
        damping_14 = (damping_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_14) & 127;
    }
    int offset_81 = (aux + st.buffer[1]) & 3;
    switch (offset_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_73 = local_arr[aux % 3];
    acc = (acc + quantum_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000936_3613_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000936_3613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_95 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_95 > 23) {
        acc = (acc + metric_95 * 2 + 5) & 127;
        aux ^= (metric_95 & 15);
    } else {
        acc = (acc - metric_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000936_0;
    int sec_r000936_1;
    int sec_r000936_2;
    int sec_r000936_3;
    int sec_r000936_4;
    int sec_r000936_5;
    int sec_r000936_6;
    int sec_r000936_7;
    int sec_r000936_8;
    int sec_r000936_9;
    int sec_r000936_10;
    int sec_r000936_11;
    int sec_r000936_12;
    int sec_r000936_13;
    int sec_r000936_14;
    int sec_r000936_15;
    int sec_r000936_16;
    int sec_r000936_17;
    int sec_r000936_18;
    int sec_r000936_19;
    int sec_r000936_20;
    int sec_r000936_21;
    int pub_r000936_0;
    int pub_r000936_1;
    int pub_r000936_2;
    int pub_r000936_3;
    int pub_r000936_4;
    int pub_r000936_5;
    int pub_r000936_6;
    int pub_r000936_7;
    int pub_r000936_8;
    int pub_r000936_9;
    int pub_r000936_10;
    int pub_r000936_11;
    int pub_r000936_12;
    int pub_r000936_13;
    int pub_r000936_14;
    int pub_r000936_15;
    int pub_r000936_16;
    int pub_r000936_17;
    int pub_r000936_18;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000936_0 >= -100 && pub_r000936_0 <= 100);
    __CPROVER_assume(pub_r000936_1 >= -100 && pub_r000936_1 <= 100);
    __CPROVER_assume(pub_r000936_2 >= -100 && pub_r000936_2 <= 100);
    __CPROVER_assume(pub_r000936_3 >= -100 && pub_r000936_3 <= 100);
    __CPROVER_assume(pub_r000936_4 >= -100 && pub_r000936_4 <= 100);
    __CPROVER_assume(pub_r000936_5 >= -100 && pub_r000936_5 <= 100);
    __CPROVER_assume(pub_r000936_6 >= -100 && pub_r000936_6 <= 100);
    __CPROVER_assume(pub_r000936_7 >= -100 && pub_r000936_7 <= 100);
    __CPROVER_assume(pub_r000936_8 >= -100 && pub_r000936_8 <= 100);
    __CPROVER_assume(pub_r000936_9 >= -100 && pub_r000936_9 <= 100);
    __CPROVER_assume(pub_r000936_10 >= -100 && pub_r000936_10 <= 100);
    __CPROVER_assume(pub_r000936_11 >= -100 && pub_r000936_11 <= 100);
    __CPROVER_assume(pub_r000936_12 >= -100 && pub_r000936_12 <= 100);
    __CPROVER_assume(pub_r000936_13 >= -100 && pub_r000936_13 <= 100);
    __CPROVER_assume(pub_r000936_14 >= -100 && pub_r000936_14 <= 100);
    __CPROVER_assume(pub_r000936_15 >= -100 && pub_r000936_15 <= 100);
    __CPROVER_assume(pub_r000936_16 >= -100 && pub_r000936_16 <= 100);
    __CPROVER_assume(pub_r000936_17 >= -100 && pub_r000936_17 <= 100);
    __CPROVER_assume(pub_r000936_18 >= -100 && pub_r000936_18 <= 100);
    __CPROVER_assume(sec_r000936_0 >= 0 && sec_r000936_0 <= 255);
    __CPROVER_assume(sec_r000936_1 >= 0 && sec_r000936_1 <= 255);
    __CPROVER_assume(sec_r000936_2 >= 0 && sec_r000936_2 <= 255);
    __CPROVER_assume(sec_r000936_3 >= 0 && sec_r000936_3 <= 255);
    __CPROVER_assume(sec_r000936_4 >= 0 && sec_r000936_4 <= 255);
    __CPROVER_assume(sec_r000936_5 >= 0 && sec_r000936_5 <= 255);
    __CPROVER_assume(sec_r000936_6 >= 0 && sec_r000936_6 <= 255);
    __CPROVER_assume(sec_r000936_7 >= 0 && sec_r000936_7 <= 255);
    __CPROVER_assume(sec_r000936_8 >= 0 && sec_r000936_8 <= 255);
    __CPROVER_assume(sec_r000936_9 >= 0 && sec_r000936_9 <= 255);
    __CPROVER_assume(sec_r000936_10 >= 0 && sec_r000936_10 <= 255);
    __CPROVER_assume(sec_r000936_11 >= 0 && sec_r000936_11 <= 255);
    __CPROVER_assume(sec_r000936_12 >= 0 && sec_r000936_12 <= 255);
    __CPROVER_assume(sec_r000936_13 >= 0 && sec_r000936_13 <= 255);
    __CPROVER_assume(sec_r000936_14 >= 0 && sec_r000936_14 <= 255);
    __CPROVER_assume(sec_r000936_15 >= 0 && sec_r000936_15 <= 255);
    __CPROVER_assume(sec_r000936_16 >= 0 && sec_r000936_16 <= 255);
    __CPROVER_assume(sec_r000936_17 >= 0 && sec_r000936_17 <= 255);
    __CPROVER_assume(sec_r000936_18 >= 0 && sec_r000936_18 <= 255);
    __CPROVER_assume(sec_r000936_19 >= 0 && sec_r000936_19 <= 255);
    __CPROVER_assume(sec_r000936_20 >= 0 && sec_r000936_20 <= 255);
    __CPROVER_assume(sec_r000936_21 >= 0 && sec_r000936_21 <= 255);

    struct SensorNode_R000936_3613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000936_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000936_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000936_0 + 7) & 15;
    struct AudioFrame_R000936_3613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000936_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000936_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000936_0 + 9) & 15;
    struct DeviceConfig_R000936_3613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000936_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000936_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000936_0 + 11) & 15;
    struct FilterState_R000936_3613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000936_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000936_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000936_0 + 13) & 15;

    union RegisterBank_R000936_3613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 26) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 41) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 18) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 33) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
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
    if (stage_v_12 > 34) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 49) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 29) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 44) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 14) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 29) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 28) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 43) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 37) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 52) {
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
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 12) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 27) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 10) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 25) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 13) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 28) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 14) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 29) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 15) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 30) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 17) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 32) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 18) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 33) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 14) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 29) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 26) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 41) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

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
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] * 2 + 259) & 63;
    if (stage_v_84 > 10) {
        out_sink = (out_sink + stage_v_84 - 5) & 255;
        if (stage_v_84 > 25) {
            chk_sum ^= (stage_v_84 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_84 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 16) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 31) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
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

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_90 = (stage_v_90 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_94 = (stage_v_94 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_3.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 27) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 42) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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

    /* Execution Pipeline Stage 97 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 98) & 15;
    int stage_v_97 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= stage_v_97;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
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
    int stage_v_102 = (st_var_2.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (out_sink > 100) ? (chk_sum & 31) : (108 & 31);
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= (stage_v_103 << 1) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_104 = (stage_v_104 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_1.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (out_sink > 100) ? (chk_sum & 31) : (111 & 31);
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= (stage_v_106 << 1) & 127;

    /* Execution Pipeline Stage 107 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 108) & 15;
    int stage_v_107 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= stage_v_107;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[0] ^ 112) & 3;
    switch (stage_v_109) {
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

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_3.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_2.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 28) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 43) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_3.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 20) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 35) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_3.buffer[0] ^ 122) & 3;
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
    for (int step = 0; step < 2; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = table[1];
    table[1] = (table[2] + 243) & 63;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[2] * 2 + 373) & 63;
    if (stage_v_122 > 40) {
        out_sink = (out_sink + stage_v_122 - 5) & 255;
        if (stage_v_122 > 55) {
            chk_sum ^= (stage_v_122 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_122 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[1] * 2 + 379) & 63;
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
    int stage_v_125 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_125 = (stage_v_125 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_2.buffer[0] * 2 + 385) & 63;
    if (stage_v_126 > 15) {
        out_sink = (out_sink + stage_v_126 - 5) & 255;
        if (stage_v_126 > 30) {
            chk_sum ^= (stage_v_126 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_126 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] ^ 132) & 3;
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
    int stage_v_130 = (st_var_2.buffer[0] ^ 133) & 3;
    switch (stage_v_130) {
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

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (out_sink > 100) ? (chk_sum & 31) : (137 & 31);
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= (stage_v_132 << 1) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 32) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 47) {
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
    int stage_v_135 = (st_var_3.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 39) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 54) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_136 = (stage_v_136 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (out_sink > 100) ? (chk_sum & 31) : (142 & 31);
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= (stage_v_137 << 1) & 127;

    /* Execution Pipeline Stage 138 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 142) & 15;
    int stage_v_141 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= stage_v_141;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (out_sink > 100) ? (chk_sum & 31) : (148 & 31);
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= (stage_v_143 << 1) & 127;

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_2.buffer[0] ^ 149) & 3;
    switch (stage_v_146) {
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

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_3.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 28) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 43) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_0.buffer[0] ^ 151) & 3;
    switch (stage_v_148) {
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

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[2] * 2 + 454) & 63;
    if (stage_v_149 > 30) {
        out_sink = (out_sink + stage_v_149 - 5) & 255;
        if (stage_v_149 > 45) {
            chk_sum ^= (stage_v_149 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_149 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 150 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_3.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = table[1];
    table[1] = (table[2] + 307) & 63;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_3.buffer[2] * 2 + 472) & 63;
    if (stage_v_155 > 26) {
        out_sink = (out_sink + stage_v_155 - 5) & 255;
        if (stage_v_155 > 41) {
            chk_sum ^= (stage_v_155 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_155 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[1] * 2 + 478) & 63;
    if (stage_v_157 > 20) {
        out_sink = (out_sink + stage_v_157 - 5) & 255;
        if (stage_v_157 > 35) {
            chk_sum ^= (stage_v_157 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_157 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 35) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 50) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000936_2 ^ 0x55) & 63;
    if (m_var > 27) {
        out_sink += (m_var * 2 + pub_r000936_14) & 127;
    } else {
        out_sink -= (m_var + 14) & 31;
    }
    out_sink ^= (sec_r000936_14 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
