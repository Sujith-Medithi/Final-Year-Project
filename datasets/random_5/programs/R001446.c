/*
 * Benchmark Program: R001446
 * Security Family: implicit_flow
 * Generator Seed: 644613
 * High Inputs: 18 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001446_4613_0 {
    unsigned char density;
    short trace;
    int stride;
    int dim;
    int buffer[3];
};

struct DeviceConfig_R001446_4613_1 {
    unsigned char port;
    int parity;
    int baud_rate;
    short stop_bits;
    int id;
    unsigned char timeout;
    int buffer[3];
};

struct SensorNode_R001446_4613_2 {
    short status;
    unsigned char offset;
    int reading;
    int threshold;
    int buffer[3];
};

union PacketPayload_R001446_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001446_4613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001446_4613_0(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_26 = (aux + st.buffer[1]) & 3;
    switch (scale_26) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_80 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_80 = (anchor_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_80) & 127;
    }
    int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001446_4613_1(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int tally_20 = local_arr[aux % 3];
    acc = (acc + tally_20 * 2) & 127;
    int vector_38 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_38 > 21) {
        acc = (acc + vector_38 * 2 + 5) & 127;
        aux ^= (vector_38 & 15);
    } else {
        acc = (acc - vector_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_2(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_15 = (aux + st.buffer[1]) & 3;
    switch (coefficient_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_82 = local_arr[aux % 3];
    acc = (acc + margin_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001446_4613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int metric_32 = 0;
    for (int k = 0; k < 3; k++) {
        metric_32 = (metric_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_32) & 127;
    }
    int coefficient_77 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_77 > 14) {
        acc = (acc + coefficient_77 * 2 + 5) & 127;
        aux ^= (coefficient_77 & 15);
    } else {
        acc = (acc - coefficient_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_82) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001446_4613_4(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001446_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int pivot_50 = local_arr[aux % 3];
    acc = (acc + pivot_50 * 2) & 127;
    int offset_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_19 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_19 > 42) {
        acc = (acc + sample_19 * 2 + 5) & 127;
        aux ^= (sample_19 & 15);
    } else {
        acc = (acc - sample_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001446_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_91 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_91 = (anchor_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_91) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001446_4613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001446_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int residue_47 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_47 > 28) {
        acc = (acc + residue_47 * 2 + 5) & 127;
        aux ^= (residue_47 & 15);
    } else {
        acc = (acc - residue_47 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_89 = local_arr[aux % 3];
    acc = (acc + metric_89 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_26 = 0;
    for (int k = 0; k < 2; k++) {
        weight_26 = (weight_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_26) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_74 = 0;
    for (int k = 0; k < 2; k++) {
        margin_74 = (margin_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_74) & 127;
    }
    int damping_11 = (aux + st.buffer[1]) & 3;
    switch (damping_11) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_58) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_44 = local_arr[aux % 3];
    acc = (acc + checksum_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001446_4613_8(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001446_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_39) & 63;
    acc ^= aux;
    int accumulator_63 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_63 > 49) {
        acc = (acc + accumulator_63 * 2 + 5) & 127;
        aux ^= (accumulator_63 & 15);
    } else {
        acc = (acc - accumulator_63 + 11) & 127;
        aux += 3;
    }
    int parity_11 = (aux + st.buffer[1]) & 3;
    switch (parity_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_22 = local_arr[aux % 3];
    acc = (acc + metric_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001446_4613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int scale_46 = local_arr[aux % 3];
    acc = (acc + scale_46 * 2) & 127;
    int stride_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_10) & 63;
    acc ^= aux;
    int quantum_41 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_41 = (quantum_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_41) & 127;
    }
    int phase_59 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_59 > 20) {
        acc = (acc + phase_59 * 2 + 5) & 127;
        aux ^= (phase_59 & 15);
    } else {
        acc = (acc - phase_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001446_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int metric_12 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_12 > 31) {
        acc = (acc + metric_12 * 2 + 5) & 127;
        aux ^= (metric_12 & 15);
    } else {
        acc = (acc - metric_12 + 11) & 127;
        aux += 3;
    }
    int delta_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001446_4613_11(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int segment_62 = (aux + st.buffer[1]) & 3;
    switch (segment_62) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_78) & 63;
    acc ^= aux;
    int margin_62 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_62 > 48) {
        acc = (acc + margin_62 * 2 + 5) & 127;
        aux ^= (margin_62 & 15);
    } else {
        acc = (acc - margin_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001446_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int accumulator_36 = local_arr[aux % 3];
    acc = (acc + accumulator_36 * 2) & 127;
    int tracker_82 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_82 = (tracker_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_82) & 127;
    }
    int parity_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001446_4613_13(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001446_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int mask_60 = local_arr[aux % 3];
    acc = (acc + mask_60 * 2) & 127;
    int phase_96 = 0;
    for (int k = 0; k < 3; k++) {
        phase_96 = (phase_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_96) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int anchor_94 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_94 > 24) {
        acc = (acc + anchor_94 * 2 + 5) & 127;
        aux ^= (anchor_94 & 15);
    } else {
        acc = (acc - anchor_94 + 11) & 127;
        aux += 3;
    }
    int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001446_4613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int factor_19 = (aux + st.buffer[1]) & 3;
    switch (factor_19) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_47 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_47 > 38) {
        acc = (acc + margin_47 * 2 + 5) & 127;
        aux ^= (margin_47 & 15);
    } else {
        acc = (acc - margin_47 + 11) & 127;
        aux += 3;
    }
    int delta_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001446_4613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int cursor_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_32) & 63;
    acc ^= aux;
    int mask_88 = 0;
    for (int k = 0; k < 2; k++) {
        mask_88 = (mask_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_88) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_20 = (aux + st.buffer[1]) & 3;
    switch (factor_20) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_17(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001446_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_84 = local_arr[aux % 3];
    acc = (acc + phase_84 * 2) & 127;
    int parity_60 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_60 > 13) {
        acc = (acc + parity_60 * 2 + 5) & 127;
        aux ^= (parity_60 & 15);
    } else {
        acc = (acc - parity_60 + 11) & 127;
        aux += 3;
    }
    int mask_92 = (aux + st.buffer[1]) & 3;
    switch (mask_92) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_18(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001446_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_14) & 63;
    acc ^= aux;
    int index_reg_35 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_35 > 28) {
        acc = (acc + index_reg_35 * 2 + 5) & 127;
        aux ^= (index_reg_35 & 15);
    } else {
        acc = (acc - index_reg_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001446_4613_19(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001446_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_80) & 63;
    acc ^= aux;
    int anchor_38 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_38 = (anchor_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_38) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001446_0;
    int sec_r001446_1;
    int sec_r001446_2;
    int sec_r001446_3;
    int sec_r001446_4;
    int sec_r001446_5;
    int sec_r001446_6;
    int sec_r001446_7;
    int sec_r001446_8;
    int sec_r001446_9;
    int sec_r001446_10;
    int sec_r001446_11;
    int sec_r001446_12;
    int sec_r001446_13;
    int sec_r001446_14;
    int sec_r001446_15;
    int sec_r001446_16;
    int sec_r001446_17;
    int pub_r001446_0;
    int pub_r001446_1;
    int pub_r001446_2;
    int pub_r001446_3;
    int pub_r001446_4;
    int pub_r001446_5;
    int pub_r001446_6;
    int pub_r001446_7;
    int pub_r001446_8;
    int pub_r001446_9;
    int pub_r001446_10;
    int pub_r001446_11;
    int pub_r001446_12;
    int pub_r001446_13;
    int pub_r001446_14;
    int pub_r001446_15;
    int pub_r001446_16;
    int pub_r001446_17;
    int pub_r001446_18;
    int pub_r001446_19;
    int pub_r001446_20;
    int pub_r001446_21;
    int pub_r001446_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001446_0 >= -100 && pub_r001446_0 <= 100);
    __CPROVER_assume(pub_r001446_1 >= -100 && pub_r001446_1 <= 100);
    __CPROVER_assume(pub_r001446_2 >= -100 && pub_r001446_2 <= 100);
    __CPROVER_assume(pub_r001446_3 >= -100 && pub_r001446_3 <= 100);
    __CPROVER_assume(pub_r001446_4 >= -100 && pub_r001446_4 <= 100);
    __CPROVER_assume(pub_r001446_5 >= -100 && pub_r001446_5 <= 100);
    __CPROVER_assume(pub_r001446_6 >= -100 && pub_r001446_6 <= 100);
    __CPROVER_assume(pub_r001446_7 >= -100 && pub_r001446_7 <= 100);
    __CPROVER_assume(pub_r001446_8 >= -100 && pub_r001446_8 <= 100);
    __CPROVER_assume(pub_r001446_9 >= -100 && pub_r001446_9 <= 100);
    __CPROVER_assume(pub_r001446_10 >= -100 && pub_r001446_10 <= 100);
    __CPROVER_assume(pub_r001446_11 >= -100 && pub_r001446_11 <= 100);
    __CPROVER_assume(pub_r001446_12 >= -100 && pub_r001446_12 <= 100);
    __CPROVER_assume(pub_r001446_13 >= -100 && pub_r001446_13 <= 100);
    __CPROVER_assume(pub_r001446_14 >= -100 && pub_r001446_14 <= 100);
    __CPROVER_assume(pub_r001446_15 >= -100 && pub_r001446_15 <= 100);
    __CPROVER_assume(pub_r001446_16 >= -100 && pub_r001446_16 <= 100);
    __CPROVER_assume(pub_r001446_17 >= -100 && pub_r001446_17 <= 100);
    __CPROVER_assume(pub_r001446_18 >= -100 && pub_r001446_18 <= 100);
    __CPROVER_assume(pub_r001446_19 >= -100 && pub_r001446_19 <= 100);
    __CPROVER_assume(pub_r001446_20 >= -100 && pub_r001446_20 <= 100);
    __CPROVER_assume(pub_r001446_21 >= -100 && pub_r001446_21 <= 100);
    __CPROVER_assume(pub_r001446_22 >= -100 && pub_r001446_22 <= 100);
    __CPROVER_assume(sec_r001446_0 >= 0 && sec_r001446_0 <= 255);
    __CPROVER_assume(sec_r001446_1 >= 0 && sec_r001446_1 <= 255);
    __CPROVER_assume(sec_r001446_2 >= 0 && sec_r001446_2 <= 255);
    __CPROVER_assume(sec_r001446_3 >= 0 && sec_r001446_3 <= 255);
    __CPROVER_assume(sec_r001446_4 >= 0 && sec_r001446_4 <= 255);
    __CPROVER_assume(sec_r001446_5 >= 0 && sec_r001446_5 <= 255);
    __CPROVER_assume(sec_r001446_6 >= 0 && sec_r001446_6 <= 255);
    __CPROVER_assume(sec_r001446_7 >= 0 && sec_r001446_7 <= 255);
    __CPROVER_assume(sec_r001446_8 >= 0 && sec_r001446_8 <= 255);
    __CPROVER_assume(sec_r001446_9 >= 0 && sec_r001446_9 <= 255);
    __CPROVER_assume(sec_r001446_10 >= 0 && sec_r001446_10 <= 255);
    __CPROVER_assume(sec_r001446_11 >= 0 && sec_r001446_11 <= 255);
    __CPROVER_assume(sec_r001446_12 >= 0 && sec_r001446_12 <= 255);
    __CPROVER_assume(sec_r001446_13 >= 0 && sec_r001446_13 <= 255);
    __CPROVER_assume(sec_r001446_14 >= 0 && sec_r001446_14 <= 255);
    __CPROVER_assume(sec_r001446_15 >= 0 && sec_r001446_15 <= 255);
    __CPROVER_assume(sec_r001446_16 >= 0 && sec_r001446_16 <= 255);
    __CPROVER_assume(sec_r001446_17 >= 0 && sec_r001446_17 <= 255);

    struct MatrixBlock_R001446_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001446_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001446_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001446_0 + 7) & 15;
    struct DeviceConfig_R001446_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001446_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001446_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001446_0 + 9) & 15;
    struct SensorNode_R001446_4613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001446_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001446_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001446_0 + 11) & 15;

    union PacketPayload_R001446_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001446_4613_0(sec_r001446_0, sec_r001446_1);
    int helper_flow_1 = fn_R001446_4613_1(sec_r001446_1, pub_r001446_2, pub_r001446_3);
    int helper_flow_2 = fn_R001446_4613_2(sec_r001446_2, sec_r001446_3, pub_r001446_4);
    int helper_flow_3 = fn_R001446_4613_3(sec_r001446_3, sec_r001446_4, pub_r001446_5, pub_r001446_6, pub_r001446_7);
    int helper_flow_4 = fn_R001446_4613_4(sec_r001446_4, sec_r001446_5);
    int helper_flow_5 = fn_R001446_4613_5(sec_r001446_5, pub_r001446_6, pub_r001446_7, pub_r001446_8, pub_r001446_9);
    int helper_flow_6 = fn_R001446_4613_6(sec_r001446_6, pub_r001446_7, pub_r001446_8, pub_r001446_9);
    int helper_flow_7 = fn_R001446_4613_7(sec_r001446_7, sec_r001446_8, pub_r001446_9, pub_r001446_10, pub_r001446_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_3 + pub_r001446_6 * 2 + 5) & 127;
    if (stage_v_0 > 56) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_2 + pub_r001446_20 * 2 + 8) & 127;
    if (stage_v_1 > 22) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001446_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001446_14 + pub_r001446_6 * 2 + 14) & 127;
    if (stage_v_3 > 43) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001446_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_1 + pub_r001446_6 * 2 + 20) & 127;
    if (stage_v_5 > 30) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001446_0 + pub_r001446_10 * 2 + 23) & 127;
    if (stage_v_6 > 17) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001446_17 + pub_r001446_1 * 2 + 26) & 127;
    if (stage_v_7 > 20) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_0 + pub_r001446_10 * 2 + 29) & 127;
    if (stage_v_8 > 24) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001446_20 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_1 + pub_r001446_22 * 2 + 35) & 127;
    if (stage_v_10 > 17) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_3 + pub_r001446_7 * 2 + 38) & 127;
    if (stage_v_11 > 50) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001446_11 + pub_r001446_7 * 2 + 41) & 127;
    if (stage_v_12 > 22) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001446_9 + pub_r001446_13 * 2 + 44) & 127;
    if (stage_v_13 > 51) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001446_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001446_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_13 + pub_r001446_8 * 2 + 53) & 127;
    if (stage_v_16 > 25) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (helper_flow_0 + pub_r001446_21 * 2 + 56) & 127;
    if (stage_v_17 > 36) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_5 + pub_r001446_13 * 2 + 59) & 127;
    if (stage_v_18 > 54) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001446_4 + pub_r001446_13 * 2 + 62) & 127;
    if (stage_v_19 > 55) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_2 + pub_r001446_7 * 2 + 65) & 127;
    if (stage_v_20 > 34) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001446_13 + pub_r001446_10 * 2 + 68) & 127;
    if (stage_v_21 > 21) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001446_8 + pub_r001446_5 * 2 + 71) & 127;
    if (stage_v_22 > 42) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001446_22 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_18 + pub_r001446_7 * 2 + 77) & 127;
    if (stage_v_24 > 25) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_7 + pub_r001446_19 * 2 + 80) & 127;
    if (stage_v_25 > 23) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001446_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_21 + pub_r001446_6 * 2 + 86) & 127;
    if (stage_v_27 > 53) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001446_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_10 + pub_r001446_6 * 2 + 92) & 127;
    if (stage_v_29 > 60) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_25 + pub_r001446_18 * 2 + 95) & 127;
    if (stage_v_30 > 24) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001446_14 + pub_r001446_20 * 2 + 98) & 127;
    if (stage_v_31 > 43) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001446_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_1 + pub_r001446_2 * 2 + 104) & 127;
    if (stage_v_33 > 44) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001446_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001446_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001446_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_0 + pub_r001446_21 * 2 + 116) & 127;
    if (stage_v_37 > 44) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_31 + pub_r001446_13 * 2 + 119) & 127;
    if (stage_v_38 > 18) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001446_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_13 + pub_r001446_15 * 2 + 125) & 127;
    if (stage_v_40 > 35) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001446_9 + pub_r001446_14 * 2 + 128) & 127;
    if (stage_v_41 > 19) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001446_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001446_10 + pub_r001446_1 * 2 + 134) & 127;
    if (stage_v_43 > 47) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001446_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001446_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001446_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001446_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001446_10 + pub_r001446_2 * 2 + 149) & 127;
    if (stage_v_48 > 22) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001446_2 + pub_r001446_10 * 2 + 152) & 127;
    if (stage_v_49 > 45) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001446_22 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001446_16 + pub_r001446_7 * 2 + 158) & 127;
    if (stage_v_51 > 51) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001446_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001446_17 + pub_r001446_10 * 2 + 164) & 127;
    if (stage_v_53 > 19) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001446_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_2 + pub_r001446_9 * 2 + 170) & 127;
    if (stage_v_55 > 45) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001446_13 + pub_r001446_17 * 2 + 173) & 127;
    if (stage_v_56 > 24) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001446_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_16 + pub_r001446_13 * 2 + 179) & 127;
    if (stage_v_58 > 31) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001446_16 + pub_r001446_6 * 2 + 182) & 127;
    if (stage_v_59 > 28) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_56 + pub_r001446_19 * 2 + 185) & 127;
    if (stage_v_60 > 50) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_49 + pub_r001446_1 * 2 + 188) & 127;
    if (stage_v_61 > 38) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001446_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (helper_flow_6 + pub_r001446_18 * 2 + 194) & 127;
    if (stage_v_63 > 24) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001446_14 + pub_r001446_14 * 2 + 197) & 127;
    if (stage_v_64 > 19) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_58 + pub_r001446_4 * 2 + 200) & 127;
    if (stage_v_65 > 16) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_25 + pub_r001446_14 * 2 + 203) & 127;
    if (stage_v_66 > 54) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_18 + pub_r001446_2 * 2 + 206) & 127;
    if (stage_v_67 > 31) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_17 + pub_r001446_1 * 2 + 209) & 127;
    if (stage_v_68 > 28) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001446_0 + pub_r001446_19 * 2 + 212) & 127;
    if (stage_v_69 > 32) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_12 + pub_r001446_9 * 2 + 215) & 127;
    if (stage_v_70 > 18) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001446_14 + pub_r001446_18 * 2 + 218) & 127;
    if (stage_v_71 > 54) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_19 + pub_r001446_3 * 2 + 221) & 127;
    if (stage_v_72 > 44) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001446_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_12 + pub_r001446_7 * 2 + 227) & 127;
    if (stage_v_74 > 42) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_5 + pub_r001446_10 * 2 + 230) & 127;
    if (stage_v_75 > 33) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001446_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001446_9 + pub_r001446_8 * 2 + 236) & 127;
    if (stage_v_77 > 24) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_7 + pub_r001446_20 * 2 + 239) & 127;
    if (stage_v_78 > 18) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001446_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001446_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_24 + pub_r001446_8 * 2 + 248) & 127;
    if (stage_v_81 > 17) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001446_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001446_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_67 + pub_r001446_14 * 2 + 257) & 127;
    if (stage_v_84 > 22) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001446_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_61 + pub_r001446_18 * 2 + 263) & 127;
    if (stage_v_86 > 20) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_69 + pub_r001446_18 * 2 + 266) & 127;
    if (stage_v_87 > 19) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_61 + pub_r001446_19 * 2 + 269) & 127;
    if (stage_v_88 > 54) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001446_16 + pub_r001446_19 * 2 + 272) & 127;
    if (stage_v_89 > 17) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001446_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_40 + pub_r001446_13 * 2 + 278) & 127;
    if (stage_v_91 > 57) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_16 + pub_r001446_11 * 2 + 281) & 127;
    if (stage_v_92 > 40) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_43 + pub_r001446_20 * 2 + 284) & 127;
    if (stage_v_93 > 29) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001446_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001446_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_51 + pub_r001446_14 * 2 + 293) & 127;
    if (stage_v_96 > 59) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_86 + pub_r001446_21 * 2 + 296) & 127;
    if (stage_v_97 > 44) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001446_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_40 + pub_r001446_21 * 2 + 302) & 127;
    if (stage_v_99 > 32) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_19 + pub_r001446_8 * 2 + 305) & 127;
    if (stage_v_100 > 17) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001446_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_96 + pub_r001446_3 * 2 + 311) & 127;
    if (stage_v_102 > 23) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001446_6 + pub_r001446_14 * 2 + 314) & 127;
    if (stage_v_103 > 46) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_27 + pub_r001446_1 * 2 + 317) & 127;
    if (stage_v_104 > 22) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001446_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001446_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_51 + pub_r001446_14 * 2 + 326) & 127;
    if (stage_v_107 > 44) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_99 + pub_r001446_10 * 2 + 329) & 127;
    if (stage_v_108 > 16) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_92 + pub_r001446_7 * 2 + 332) & 127;
    if (stage_v_109 > 60) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001446_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_67 + pub_r001446_0 * 2 + 338) & 127;
    if (stage_v_111 > 26) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_100 + pub_r001446_1 * 2 + 341) & 127;
    if (stage_v_112 > 37) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_66 + pub_r001446_7 * 2 + 344) & 127;
    if (stage_v_113 > 18) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001446_21 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001446_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_43 + pub_r001446_12 * 2 + 353) & 127;
    if (stage_v_116 > 28) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001446_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_11 + pub_r001446_18 * 2 + 359) & 127;
    if (stage_v_118 > 55) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001446_22 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_58 + pub_r001446_4 * 2 + 365) & 127;
    if (stage_v_120 > 19) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_108 + pub_r001446_9 * 2 + 368) & 127;
    if (stage_v_121 > 21) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_69 + pub_r001446_3 * 2 + 371) & 127;
    if (stage_v_122 > 25) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001446_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001446_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_25 + pub_r001446_19 * 2 + 380) & 127;
    if (stage_v_125 > 53) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_69 + pub_r001446_4 * 2 + 383) & 127;
    if (stage_v_126 > 15) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001446_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001446_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001446_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_67 + pub_r001446_5 * 2 + 395) & 127;
    if (stage_v_130 > 28) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_69 + pub_r001446_6 * 2 + 398) & 127;
    if (stage_v_131 > 38) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001446_22 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (helper_flow_1 + pub_r001446_5 * 2 + 404) & 127;
    if (stage_v_133 > 23) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001446_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_108 + pub_r001446_14 * 2 + 410) & 127;
    if (stage_v_135 > 32) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_133 + pub_r001446_10 * 2 + 413) & 127;
    if (stage_v_136 > 37) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001446_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001446_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001446_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001446_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001446_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001446_8 + pub_r001446_3 * 2 + 431) & 127;
    if (stage_v_142 > 50) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r001446_10 + pub_r001446_5 * 2 + 434) & 127;
    if (stage_v_143 > 46) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r001446_12 + pub_r001446_1 * 2 + 437) & 127;
    if (stage_v_144 > 48) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001446_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_135 + pub_r001446_3 * 2 + 443) & 127;
    if (stage_v_146 > 17) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_31 + pub_r001446_0 * 2 + 446) & 127;
    if (stage_v_147 > 44) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_97 + pub_r001446_0 * 2 + 449) & 127;
    if (stage_v_148 > 17) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001446_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_29 + pub_r001446_18 * 2 + 455) & 127;
    if (stage_v_150 > 40) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_68 + pub_r001446_12 * 2 + 458) & 127;
    if (stage_v_151 > 18) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_109 + pub_r001446_12 * 2 + 461) & 127;
    if (stage_v_152 > 47) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001446_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001446_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_65 + pub_r001446_11 * 2 + 470) & 127;
    if (stage_v_155 > 45) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_147 + pub_r001446_7 * 2 + 473) & 127;
    if (stage_v_156 > 17) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_55 + pub_r001446_4 * 2 + 476) & 127;
    if (stage_v_157 > 53) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_12 + pub_r001446_22 * 2 + 479) & 127;
    if (stage_v_158 > 17) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_152 + pub_r001446_5 * 2 + 482) & 127;
    if (stage_v_159 > 16) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_148 + pub_r001446_9 * 2 + 485) & 127;
    if (stage_v_160 > 31) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_116 + pub_r001446_16 * 2 + 488) & 127;
    if (stage_v_161 > 28) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_100 + pub_r001446_6 * 2 + 491) & 127;
    if (stage_v_162 > 28) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_146 + pub_r001446_2 * 2 + 494) & 127;
    if (stage_v_163 > 40) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001446_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r001446_10 + pub_r001446_16 * 2 + 500) & 127;
    if (stage_v_165 > 28) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_91 + pub_r001446_18 * 2 + 503) & 127;
    if (stage_v_166 > 31) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001446_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_157 + pub_r001446_6 * 2 + 509) & 127;
    if (stage_v_168 > 23) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001446_22 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001446_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_75 + pub_r001446_3 * 2 + 518) & 127;
    if (stage_v_171 > 40) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001446_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (sec_r001446_11 + pub_r001446_13 * 2 + 524) & 127;
    if (stage_v_173 > 59) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001446_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_33 + pub_r001446_19 * 2 + 530) & 127;
    if (stage_v_175 > 42) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001446_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_111 + pub_r001446_21 * 2 + 536) & 127;
    if (stage_v_177 > 50) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_61 + pub_r001446_2 * 2 + 539) & 127;
    if (stage_v_178 > 41) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001446_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001446_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_20 + pub_r001446_11 * 2 + 548) & 127;
    if (stage_v_181 > 40) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_133 + pub_r001446_22 * 2 + 551) & 127;
    if (stage_v_182 > 47) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001446_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_111 + pub_r001446_7 * 2 + 557) & 127;
    if (stage_v_184 > 16) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (helper_flow_6 + pub_r001446_1 * 2 + 560) & 127;
    if (stage_v_185 > 31) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_60 + pub_r001446_5 * 2 + 563) & 127;
    if (stage_v_186 > 19) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (sec_r001446_5 + pub_r001446_1 * 2 + 566) & 127;
    if (stage_v_187 > 19) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001446_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (helper_flow_1 + pub_r001446_1 * 2 + 572) & 127;
    if (stage_v_189 > 27) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001446_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_161 + pub_r001446_19 * 2 + 578) & 127;
    if (stage_v_191 > 36) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_173 + pub_r001446_12 * 2 + 581) & 127;
    if (stage_v_192 > 37) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (sec_r001446_12 + pub_r001446_21 * 2 + 584) & 127;
    if (stage_v_193 > 50) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_60 + pub_r001446_1 * 2 + 587) & 127;
    if (stage_v_194 > 35) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001446_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001446_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001446_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_182 + pub_r001446_0 * 2 + 599) & 127;
    if (stage_v_198 > 21) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (sec_r001446_1 + pub_r001446_18 * 2 + 602) & 127;
    if (stage_v_199 > 45) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_108 + pub_r001446_8 * 2 + 605) & 127;
    if (stage_v_200 > 58) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_20 + pub_r001446_6 * 2 + 608) & 127;
    if (stage_v_201 > 46) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_122 + pub_r001446_5 * 2 + 611) & 127;
    if (stage_v_202 > 18) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (sec_r001446_12 + pub_r001446_1 * 2 + 614) & 127;
    if (stage_v_203 > 56) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001446_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_21 + pub_r001446_13 * 2 + 620) & 127;
    if (stage_v_205 > 15) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001446_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_63 + pub_r001446_18 * 2 + 626) & 127;
    if (stage_v_207 > 16) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_19 + pub_r001446_16 * 2 + 629) & 127;
    if (stage_v_208 > 44) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (sec_r001446_4 + pub_r001446_13 * 2 + 632) & 127;
    if (stage_v_209 > 54) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_156 + pub_r001446_0 * 2 + 635) & 127;
    if (stage_v_210 > 19) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001446_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001446_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001446_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_96 + pub_r001446_3 * 2 + 647) & 127;
    if (stage_v_214 > 17) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001446_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001446_21 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001446_20 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001446_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001446_18 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001446_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (sec_r001446_5 + pub_r001446_20 * 2 + 668) & 127;
    if (stage_v_221 > 58) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_55 + pub_r001446_18 * 2 + 671) & 127;
    if (stage_v_222 > 20) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_166 + pub_r001446_11 * 2 + 674) & 127;
    if (stage_v_223 > 34) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_112 + pub_r001446_3 * 2 + 677) & 127;
    if (stage_v_224 > 29) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001446_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001446_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_102 + pub_r001446_13 * 2 + 686) & 127;
    if (stage_v_227 > 54) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001446_21 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001446_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001446_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_122 + pub_r001446_11 * 2 + 698) & 127;
    if (stage_v_231 > 52) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001446_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_231 + pub_r001446_20 * 2 + 704) & 127;
    if (stage_v_233 > 48) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (sec_r001446_13 + pub_r001446_15 * 2 + 707) & 127;
    if (stage_v_234 > 32) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_70 + pub_r001446_9 * 2 + 710) & 127;
    if (stage_v_235 > 55) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001446_22 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_40 + pub_r001446_13 * 2 + 716) & 127;
    if (stage_v_237 > 20) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_189 + pub_r001446_7 * 2 + 719) & 127;
    if (stage_v_238 > 54) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_0 + pub_r001446_2 * 2 + 722) & 127;
    if (stage_v_239 > 38) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_69 + pub_r001446_8 * 2 + 725) & 127;
    if (stage_v_240 > 55) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001446_21 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_120 + pub_r001446_7 * 2 + 731) & 127;
    if (stage_v_242 > 51) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001446_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (helper_flow_7 + pub_r001446_16 * 2 + 737) & 127;
    if (stage_v_244 > 44) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
