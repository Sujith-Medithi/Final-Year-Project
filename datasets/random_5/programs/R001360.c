/*
 * Benchmark Program: R001360
 * Security Family: mixed_control_data
 * Generator Seed: 636013
 * High Inputs: 24 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001360_6013_0 {
    short facility;
    short code;
    int timestamp;
    int signature;
    int buffer[3];
};

struct FilterState_R001360_6013_1 {
    unsigned char prev_out;
    short damping;
    int prev_in;
    int mode;
    int buffer[3];
};

struct StreamBuffer_R001360_6013_2 {
    int checksum;
    int state;
    unsigned char capacity;
    unsigned char tail;
    int buffer[3];
};

struct MatrixBlock_R001360_6013_3 {
    int determinant;
    int scale;
    int stride;
    int density;
    int buffer[3];
};

union RegisterBank_R001360_6013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001360_6013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001360_6013_0(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001360_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int delta_24 = local_arr[aux % 3];
    acc = (acc + delta_24 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001360_6013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001360_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int parity_54 = local_arr[aux % 3];
    acc = (acc + parity_54 * 2) & 127;
    int factor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_35 > 38) {
        acc = (acc + factor_35 * 2 + 5) & 127;
        aux ^= (factor_35 & 15);
    } else {
        acc = (acc - factor_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_66 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_66 = (quantum_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001360_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int factor_39 = local_arr[aux % 3];
    acc = (acc + factor_39 * 2) & 127;
    int phase_84 = (aux + st.buffer[1]) & 3;
    switch (phase_84) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_3(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001360_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int damping_23 = local_arr[aux % 3];
    acc = (acc + damping_23 * 2) & 127;
    int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001360_6013_4(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001360_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_79 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_79 > 12) {
        acc = (acc + segment_79 * 2 + 5) & 127;
        aux ^= (segment_79 & 15);
    } else {
        acc = (acc - segment_79 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_44 = 0;
    for (int k = 0; k < 2; k++) {
        segment_44 = (segment_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_44) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_5(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int index_reg_82 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_82 = (index_reg_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_82) & 127;
    }
    int scale_64 = (aux + st.buffer[1]) & 3;
    switch (scale_64) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_6(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_67) & 63;
    acc ^= aux;
    int offset_95 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_95 > 12) {
        acc = (acc + offset_95 * 2 + 5) & 127;
        aux ^= (offset_95 & 15);
    } else {
        acc = (acc - offset_95 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_17 = local_arr[aux % 3];
    acc = (acc + offset_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001360_6013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_29 = (aux + st.buffer[1]) & 3;
    switch (quantum_29) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_15 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_15 = (cursor_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_15) & 127;
    }
    int anchor_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001360_6013_8(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_83 = 0;
    for (int k = 0; k < 2; k++) {
        weight_83 = (weight_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_83) & 127;
    }
    int anchor_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001360_6013_9(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001360_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_38 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_38 > 32) {
        acc = (acc + residue_38 * 2 + 5) & 127;
        aux ^= (residue_38 & 15);
    } else {
        acc = (acc - residue_38 + 11) & 127;
        aux += 3;
    }
    int sample_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001360_6013_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001360_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int checksum_32 = local_arr[aux % 3];
    acc = (acc + checksum_32 * 2) & 127;
    int phase_45 = (aux + st.buffer[1]) & 3;
    switch (phase_45) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_82 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_82 > 23) {
        acc = (acc + tracker_82 * 2 + 5) & 127;
        aux ^= (tracker_82 & 15);
    } else {
        acc = (acc - tracker_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_11(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int mask_34 = (aux + st.buffer[1]) & 3;
    switch (mask_34) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_32 = 0;
    for (int k = 0; k < 3; k++) {
        delta_32 = (delta_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_32) & 127;
    }
    int quotient_16 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_16 > 50) {
        acc = (acc + quotient_16 * 2 + 5) & 127;
        aux ^= (quotient_16 & 15);
    } else {
        acc = (acc - quotient_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_12(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int mask_78 = local_arr[aux % 3];
    acc = (acc + mask_78 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_69 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_69 > 10) {
        acc = (acc + threshold_69 * 2 + 5) & 127;
        aux ^= (threshold_69 & 15);
    } else {
        acc = (acc - threshold_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_13(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_46 = (aux + st.buffer[1]) & 3;
    switch (phase_46) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_38 = local_arr[aux % 3];
    acc = (acc + quantum_38 * 2) & 127;
    int tally_86 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_86 > 12) {
        acc = (acc + tally_86 * 2 + 5) & 127;
        aux ^= (tally_86 & 15);
    } else {
        acc = (acc - tally_86 + 11) & 127;
        aux += 3;
    }
    int tracker_27 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_27 = (tracker_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_27) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001360_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int checksum_70 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_70 > 32) {
        acc = (acc + checksum_70 * 2 + 5) & 127;
        aux ^= (checksum_70 & 15);
    } else {
        acc = (acc - checksum_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_35 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_35 = (coefficient_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_35) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_15(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001360_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int tracker_56 = local_arr[aux % 3];
    acc = (acc + tracker_56 * 2) & 127;
    int phase_82 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_82 > 38) {
        acc = (acc + phase_82 * 2 + 5) & 127;
        aux ^= (phase_82 & 15);
    } else {
        acc = (acc - phase_82 + 11) & 127;
        aux += 3;
    }
    int threshold_15 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_15 = (threshold_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_15) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001360_6013_16(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001360_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_65 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_65 = (quantum_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_65) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001360_6013_17(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001360_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int weight_28 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_28 > 16) {
        acc = (acc + weight_28 * 2 + 5) & 127;
        aux ^= (weight_28 & 15);
    } else {
        acc = (acc - weight_28 + 11) & 127;
        aux += 3;
    }
    int sample_84 = (aux + st.buffer[1]) & 3;
    switch (sample_84) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_18(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001360_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001360_6013_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001360_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_63) & 63;
    acc ^= aux;
    int quantum_32 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_32 > 44) {
        acc = (acc + quantum_32 * 2 + 5) & 127;
        aux ^= (quantum_32 & 15);
    } else {
        acc = (acc - quantum_32 + 11) & 127;
        aux += 3;
    }
    int metric_82 = (aux + st.buffer[1]) & 3;
    switch (metric_82) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001360_6013_20(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001360_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int factor_88 = local_arr[aux % 3];
    acc = (acc + factor_88 * 2) & 127;
    int anchor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_20) & 63;
    acc ^= aux;
    int pivot_52 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_52 > 34) {
        acc = (acc + pivot_52 * 2 + 5) & 127;
        aux ^= (pivot_52 & 15);
    } else {
        acc = (acc - pivot_52 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001360_6013_21(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001360_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_68 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_68 > 49) {
        acc = (acc + residue_68 * 2 + 5) & 127;
        aux ^= (residue_68 & 15);
    } else {
        acc = (acc - residue_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_69) & 63;
    acc ^= aux;
    int phase_21 = 0;
    for (int k = 0; k < 2; k++) {
        phase_21 = (phase_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_21) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001360_0;
    int sec_r001360_1;
    int sec_r001360_2;
    int sec_r001360_3;
    int sec_r001360_4;
    int sec_r001360_5;
    int sec_r001360_6;
    int sec_r001360_7;
    int sec_r001360_8;
    int sec_r001360_9;
    int sec_r001360_10;
    int sec_r001360_11;
    int sec_r001360_12;
    int sec_r001360_13;
    int sec_r001360_14;
    int sec_r001360_15;
    int sec_r001360_16;
    int sec_r001360_17;
    int sec_r001360_18;
    int sec_r001360_19;
    int sec_r001360_20;
    int sec_r001360_21;
    int sec_r001360_22;
    int sec_r001360_23;
    int pub_r001360_0;
    int pub_r001360_1;
    int pub_r001360_2;
    int pub_r001360_3;
    int pub_r001360_4;
    int pub_r001360_5;
    int pub_r001360_6;
    int pub_r001360_7;
    int pub_r001360_8;
    int pub_r001360_9;
    int pub_r001360_10;
    int pub_r001360_11;
    int pub_r001360_12;
    int pub_r001360_13;
    int pub_r001360_14;
    int pub_r001360_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001360_0 >= -100 && pub_r001360_0 <= 100);
    __CPROVER_assume(pub_r001360_1 >= -100 && pub_r001360_1 <= 100);
    __CPROVER_assume(pub_r001360_2 >= -100 && pub_r001360_2 <= 100);
    __CPROVER_assume(pub_r001360_3 >= -100 && pub_r001360_3 <= 100);
    __CPROVER_assume(pub_r001360_4 >= -100 && pub_r001360_4 <= 100);
    __CPROVER_assume(pub_r001360_5 >= -100 && pub_r001360_5 <= 100);
    __CPROVER_assume(pub_r001360_6 >= -100 && pub_r001360_6 <= 100);
    __CPROVER_assume(pub_r001360_7 >= -100 && pub_r001360_7 <= 100);
    __CPROVER_assume(pub_r001360_8 >= -100 && pub_r001360_8 <= 100);
    __CPROVER_assume(pub_r001360_9 >= -100 && pub_r001360_9 <= 100);
    __CPROVER_assume(pub_r001360_10 >= -100 && pub_r001360_10 <= 100);
    __CPROVER_assume(pub_r001360_11 >= -100 && pub_r001360_11 <= 100);
    __CPROVER_assume(pub_r001360_12 >= -100 && pub_r001360_12 <= 100);
    __CPROVER_assume(pub_r001360_13 >= -100 && pub_r001360_13 <= 100);
    __CPROVER_assume(pub_r001360_14 >= -100 && pub_r001360_14 <= 100);
    __CPROVER_assume(pub_r001360_15 >= -100 && pub_r001360_15 <= 100);
    __CPROVER_assume(sec_r001360_0 >= 0 && sec_r001360_0 <= 255);
    __CPROVER_assume(sec_r001360_1 >= 0 && sec_r001360_1 <= 255);
    __CPROVER_assume(sec_r001360_2 >= 0 && sec_r001360_2 <= 255);
    __CPROVER_assume(sec_r001360_3 >= 0 && sec_r001360_3 <= 255);
    __CPROVER_assume(sec_r001360_4 >= 0 && sec_r001360_4 <= 255);
    __CPROVER_assume(sec_r001360_5 >= 0 && sec_r001360_5 <= 255);
    __CPROVER_assume(sec_r001360_6 >= 0 && sec_r001360_6 <= 255);
    __CPROVER_assume(sec_r001360_7 >= 0 && sec_r001360_7 <= 255);
    __CPROVER_assume(sec_r001360_8 >= 0 && sec_r001360_8 <= 255);
    __CPROVER_assume(sec_r001360_9 >= 0 && sec_r001360_9 <= 255);
    __CPROVER_assume(sec_r001360_10 >= 0 && sec_r001360_10 <= 255);
    __CPROVER_assume(sec_r001360_11 >= 0 && sec_r001360_11 <= 255);
    __CPROVER_assume(sec_r001360_12 >= 0 && sec_r001360_12 <= 255);
    __CPROVER_assume(sec_r001360_13 >= 0 && sec_r001360_13 <= 255);
    __CPROVER_assume(sec_r001360_14 >= 0 && sec_r001360_14 <= 255);
    __CPROVER_assume(sec_r001360_15 >= 0 && sec_r001360_15 <= 255);
    __CPROVER_assume(sec_r001360_16 >= 0 && sec_r001360_16 <= 255);
    __CPROVER_assume(sec_r001360_17 >= 0 && sec_r001360_17 <= 255);
    __CPROVER_assume(sec_r001360_18 >= 0 && sec_r001360_18 <= 255);
    __CPROVER_assume(sec_r001360_19 >= 0 && sec_r001360_19 <= 255);
    __CPROVER_assume(sec_r001360_20 >= 0 && sec_r001360_20 <= 255);
    __CPROVER_assume(sec_r001360_21 >= 0 && sec_r001360_21 <= 255);
    __CPROVER_assume(sec_r001360_22 >= 0 && sec_r001360_22 <= 255);
    __CPROVER_assume(sec_r001360_23 >= 0 && sec_r001360_23 <= 255);

    struct EventLog_R001360_6013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001360_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001360_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001360_0 + 7) & 15;
    struct FilterState_R001360_6013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001360_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001360_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001360_0 + 9) & 15;
    struct StreamBuffer_R001360_6013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001360_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001360_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001360_0 + 11) & 15;
    struct MatrixBlock_R001360_6013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001360_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001360_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001360_0 + 13) & 15;

    union RegisterBank_R001360_6013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001360_6013_0(sec_r001360_0, pub_r001360_1);
    int helper_flow_1 = fn_R001360_6013_1(sec_r001360_1, pub_r001360_2, pub_r001360_3, pub_r001360_4, pub_r001360_5);
    int helper_flow_2 = fn_R001360_6013_2(sec_r001360_2, pub_r001360_3, pub_r001360_4, pub_r001360_5, pub_r001360_6);
    int helper_flow_3 = fn_R001360_6013_3(sec_r001360_3, pub_r001360_4, pub_r001360_5);
    int helper_flow_4 = fn_R001360_6013_4(sec_r001360_4, pub_r001360_5, pub_r001360_6);
    int helper_flow_5 = fn_R001360_6013_5(sec_r001360_5, pub_r001360_6, pub_r001360_7);
    int helper_flow_6 = fn_R001360_6013_6(sec_r001360_6, sec_r001360_7);
    int helper_flow_7 = fn_R001360_6013_7(sec_r001360_7, pub_r001360_8, pub_r001360_9, pub_r001360_10);
    int helper_flow_8 = fn_R001360_6013_8(sec_r001360_8, pub_r001360_9, pub_r001360_10);
    int helper_flow_9 = fn_R001360_6013_9(sec_r001360_9, sec_r001360_10, pub_r001360_11);
    int helper_flow_10 = fn_R001360_6013_10(sec_r001360_10, pub_r001360_11, pub_r001360_12, pub_r001360_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_0 > 36) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001360_18 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_1 > 30) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_2 > 23) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_3 > 30) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001360_12 ^ 0x2A) * 2 + pub_r001360_8) & 127;
    if (stage_v_4 > 32) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001360_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001360_9 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_6 > 39) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001360_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001360_1 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_8 > 20) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001360_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001360_10 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_10 > 32) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001360_22 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_11 > 38) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001360_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001360_14 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_13 > 49) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_14 > 27) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_15 > 34) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001360_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001360_3 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_17 > 33) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_18 > 41) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001360_16 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_19 > 27) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001360_15 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_20 > 23) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001360_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001360_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001360_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_24 > 47) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_25 > 39) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001360_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001360_20 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_27 > 27) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001360_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001360_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001360_8) & 127;
    if (stage_v_30 > 44) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001360_0 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_31 > 28) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_32 > 43) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_33 > 46) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001360_10 ^ 0x2A) * 2 + pub_r001360_11) & 127;
    if (stage_v_34 > 35) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001360_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_36 > 32) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_37 > 49) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_38 > 38) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001360_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_40 > 48) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001360_10 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_41 > 27) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001360_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001360_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_44 > 22) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_45 > 48) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001360_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_47 > 37) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_48 > 35) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_49 > 23) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_50 > 38) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_51 > 49) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_52 > 37) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001360_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_54 > 39) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001360_11) & 127;
    if (stage_v_55 > 49) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001360_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_57 > 22) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001360_13 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_58 > 44) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001360_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001360_7) & 127;
    if (stage_v_60 > 24) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001360_8) & 127;
    if (stage_v_61 > 32) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_62 > 30) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001360_18 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_63 > 22) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001360_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_65 > 48) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_66 > 21) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_67 > 42) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_68 > 27) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001360_2 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_69 > 42) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001360_23 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_70 > 32) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001360_11 ^ 0x2A) * 2 + pub_r001360_7) & 127;
    if (stage_v_71 > 25) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_72 > 31) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_73 > 38) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001360_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_75 > 25) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001360_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001360_7) & 127;
    if (stage_v_77 > 49) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_78 > 23) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001360_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001360_19 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_80 > 32) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_81 > 26) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001360_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_83 > 30) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001360_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_85 > 47) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_86 > 50) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001360_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_88 > 41) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_89 > 50) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_90 > 40) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001360_12 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_91 > 36) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_92 > 39) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_93 > 34) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001360_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_95 > 46) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001360_11) & 127;
    if (stage_v_96 > 45) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001360_8) & 127;
    if (stage_v_97 > 34) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_98 > 35) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001360_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001360_7) & 127;
    if (stage_v_100 > 32) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001360_0 ^ 0x2A) * 2 + pub_r001360_11) & 127;
    if (stage_v_101 > 43) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_102 > 43) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_103 > 29) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001360_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_105 > 28) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001360_4 ^ 0x2A) * 2 + pub_r001360_8) & 127;
    if (stage_v_106 > 42) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_107 > 23) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001360_22 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_108 > 31) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001360_12 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_109 > 30) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_110 > 50) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_111 > 37) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001360_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_113 > 21) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_114 > 35) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001360_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001360_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_117 > 35) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001360_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_119 > 29) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_120 > 24) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_121 > 35) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001360_8) & 127;
    if (stage_v_122 > 38) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_123 > 22) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_124 > 27) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_125 > 40) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_126 > 34) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_127 > 33) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_128 > 50) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001360_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_130 > 32) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001360_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_132 > 31) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001360_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_134 > 34) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_135 > 21) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001360_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r001360_9 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_137 > 21) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001360_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_139 > 46) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_140 > 22) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_141 > 42) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001360_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_143 > 44) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001360_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_145 > 38) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_146 > 49) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_147 > 41) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_148 > 23) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_149 > 49) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001360_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001360_8) & 127;
    if (stage_v_151 > 21) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001360_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_153 > 26) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001360_15) & 127;
    if (stage_v_154 > 24) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_155 > 23) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001360_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_157 > 22) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_158 > 36) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_159 > 26) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_160 > 25) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_161 > 20) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001360_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_163 > 20) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001360_1) & 127;
    if (stage_v_164 > 41) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r001360_13 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_165 > 24) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_166 > 20) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001360_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_168 > 42) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_169 > 35) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_170 > 33) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_171 > 47) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_172 > 28) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_173 > 28) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_174 > 43) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_175 > 44) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_176 > 37) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001360_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001360_10) & 127;
    if (stage_v_178 > 21) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001360_11) & 127;
    if (stage_v_179 > 39) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_180 > 34) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_180 ^ 0x2A) * 2 + pub_r001360_13) & 127;
    if (stage_v_181 > 46) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001360_3) & 127;
    if (stage_v_182 > 45) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001360_4) & 127;
    if (stage_v_183 > 43) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001360_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_185 > 31) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_186 > 22) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001360_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001360_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001360_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001360_7) & 127;
    if (stage_v_190 > 46) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001360_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001360_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001360_5) & 127;
    if (stage_v_193 > 30) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001360_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001360_0) & 127;
    if (stage_v_195 > 45) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001360_9) & 127;
    if (stage_v_196 > 22) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001360_14) & 127;
    if (stage_v_197 > 41) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001360_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r001360_12 ^ 0x2A) * 2 + pub_r001360_7) & 127;
    if (stage_v_199 > 47) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001360_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001360_12) & 127;
    if (stage_v_201 > 21) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001360_6) & 127;
    if (stage_v_202 > 31) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001360_14 ^ 0x2A) * 2 + pub_r001360_2) & 127;
    if (stage_v_203 > 45) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001360_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
