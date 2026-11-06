/*
 * Benchmark Program: R000467
 * Security Family: nested_implicit_flow
 * Generator Seed: 546713
 * High Inputs: 17 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000467_6713_0 {
    unsigned char counter;
    int iv;
    int nonce;
    int round_key;
    int tag;
    int buffer[3];
};

struct SensorNode_R000467_6713_1 {
    unsigned char offset;
    int reading;
    short calib;
    short status;
    int gain;
    int buffer[3];
};

struct EventLog_R000467_6713_2 {
    int facility;
    int code;
    short timestamp;
    short seq;
    int signature;
    int buffer[3];
};

struct MatrixBlock_R000467_6713_3 {
    unsigned char trace;
    short scale;
    unsigned char dim;
    int density;
    int buffer[3];
};

union ColorPixel_R000467_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000467_6713_0(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_14) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_53 = local_arr[aux % 3];
    acc = (acc + checksum_53 * 2) & 127;
    int phase_52 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_52 > 13) {
        acc = (acc + phase_52 * 2 + 5) & 127;
        aux ^= (phase_52 & 15);
    } else {
        acc = (acc - phase_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_1(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000467_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int vector_96 = local_arr[aux % 3];
    acc = (acc + vector_96 * 2) & 127;
    int threshold_66 = (aux + st.buffer[1]) & 3;
    switch (threshold_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000467_6713_2(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int scale_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_64) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000467_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_18 = (aux + st.buffer[1]) & 3;
    switch (tally_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_24 = local_arr[aux % 3];
    acc = (acc + phase_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_4(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int pivot_30 = (aux + st.buffer[1]) & 3;
    switch (pivot_30) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_62 = local_arr[aux % 3];
    acc = (acc + anchor_62 * 2) & 127;
    int checksum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000467_6713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000467_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_96 = (aux + st.buffer[1]) & 3;
    switch (sample_96) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_72 = local_arr[aux % 3];
    acc = (acc + threshold_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_66 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_66 > 35) {
        acc = (acc + threshold_66 * 2 + 5) & 127;
        aux ^= (threshold_66 & 15);
    } else {
        acc = (acc - threshold_66 + 11) & 127;
        aux += 3;
    }
    int parity_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000467_6713_7(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int vector_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_52) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_81 = (aux + st.buffer[1]) & 3;
    switch (pivot_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_8(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000467_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_90 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_90 > 45) {
        acc = (acc + parity_90 * 2 + 5) & 127;
        aux ^= (parity_90 & 15);
    } else {
        acc = (acc - parity_90 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_65 = local_arr[aux % 3];
    acc = (acc + metric_65 * 2) & 127;
    int anchor_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_62) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000467_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_88 = (aux + st.buffer[1]) & 3;
    switch (segment_88) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_13 = local_arr[aux % 3];
    acc = (acc + pivot_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000467_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_63 = (aux + st.buffer[1]) & 3;
    switch (threshold_63) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_16 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_16 > 20) {
        acc = (acc + stride_16 * 2 + 5) & 127;
        aux ^= (stride_16 & 15);
    } else {
        acc = (acc - stride_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_42 = local_arr[aux % 3];
    acc = (acc + tracker_42 * 2) & 127;
    int offset_31 = (aux + st.buffer[1]) & 3;
    switch (offset_31) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_96 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_96 > 34) {
        acc = (acc + threshold_96 * 2 + 5) & 127;
        aux ^= (threshold_96 & 15);
    } else {
        acc = (acc - threshold_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000467_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int quotient_83 = local_arr[aux % 3];
    acc = (acc + quotient_83 * 2) & 127;
    int bound_83 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_83 > 23) {
        acc = (acc + bound_83 * 2 + 5) & 127;
        aux ^= (bound_83 & 15);
    } else {
        acc = (acc - bound_83 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_13(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000467_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int parity_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_66) & 63;
    acc ^= aux;
    int anchor_22 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_22 > 18) {
        acc = (acc + anchor_22 * 2 + 5) & 127;
        aux ^= (anchor_22 & 15);
    } else {
        acc = (acc - anchor_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_14(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000467_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int bound_69 = (aux + st.buffer[1]) & 3;
    switch (bound_69) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000467_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_47 = (aux + st.buffer[1]) & 3;
    switch (delta_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int window_84 = (st.buffer[0] * 3 + aux) & 63;
    if (window_84 > 45) {
        acc = (acc + window_84 * 2 + 5) & 127;
        aux ^= (window_84 & 15);
    } else {
        acc = (acc - window_84 + 11) & 127;
        aux += 3;
    }
    int parity_64 = (aux + st.buffer[1]) & 3;
    switch (parity_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int phase_27 = local_arr[aux % 3];
    acc = (acc + phase_27 * 2) & 127;
    int index_reg_51 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_51 > 24) {
        acc = (acc + index_reg_51 * 2 + 5) & 127;
        aux ^= (index_reg_51 & 15);
    } else {
        acc = (acc - index_reg_51 + 11) & 127;
        aux += 3;
    }
    int bound_16 = (aux + st.buffer[1]) & 3;
    switch (bound_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000467_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_36 = (aux + st.buffer[1]) & 3;
    switch (offset_36) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000467_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_53 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_53 > 16) {
        acc = (acc + pivot_53 * 2 + 5) & 127;
        aux ^= (pivot_53 & 15);
    } else {
        acc = (acc - pivot_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000467_6713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000467_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int offset_42 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_42 > 38) {
        acc = (acc + offset_42 * 2 + 5) & 127;
        aux ^= (offset_42 & 15);
    } else {
        acc = (acc - offset_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_73 = local_arr[aux % 3];
    acc = (acc + quantum_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000467_6713_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000467_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int residue_94 = local_arr[aux % 3];
    acc = (acc + residue_94 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_61 = (aux + st.buffer[1]) & 3;
    switch (tally_61) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_60 = (st.buffer[0] * 3 + aux) & 63;
    if (window_60 > 31) {
        acc = (acc + window_60 * 2 + 5) & 127;
        aux ^= (window_60 & 15);
    } else {
        acc = (acc - window_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000467_6713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000467_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int damping_43 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_43 > 21) {
        acc = (acc + damping_43 * 2 + 5) & 127;
        aux ^= (damping_43 & 15);
    } else {
        acc = (acc - damping_43 + 11) & 127;
        aux += 3;
    }
    int quotient_58 = (aux + st.buffer[1]) & 3;
    switch (quotient_58) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000467_0;
    int sec_r000467_1;
    int sec_r000467_2;
    int sec_r000467_3;
    int sec_r000467_4;
    int sec_r000467_5;
    int sec_r000467_6;
    int sec_r000467_7;
    int sec_r000467_8;
    int sec_r000467_9;
    int sec_r000467_10;
    int sec_r000467_11;
    int sec_r000467_12;
    int sec_r000467_13;
    int sec_r000467_14;
    int sec_r000467_15;
    int sec_r000467_16;
    int pub_r000467_0;
    int pub_r000467_1;
    int pub_r000467_2;
    int pub_r000467_3;
    int pub_r000467_4;
    int pub_r000467_5;
    int pub_r000467_6;
    int pub_r000467_7;
    int pub_r000467_8;
    int pub_r000467_9;
    int pub_r000467_10;
    int pub_r000467_11;
    int pub_r000467_12;
    int pub_r000467_13;
    int pub_r000467_14;
    int pub_r000467_15;
    int pub_r000467_16;
    int pub_r000467_17;
    int pub_r000467_18;
    int pub_r000467_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000467_0 >= -100 && pub_r000467_0 <= 100);
    __CPROVER_assume(pub_r000467_1 >= -100 && pub_r000467_1 <= 100);
    __CPROVER_assume(pub_r000467_2 >= -100 && pub_r000467_2 <= 100);
    __CPROVER_assume(pub_r000467_3 >= -100 && pub_r000467_3 <= 100);
    __CPROVER_assume(pub_r000467_4 >= -100 && pub_r000467_4 <= 100);
    __CPROVER_assume(pub_r000467_5 >= -100 && pub_r000467_5 <= 100);
    __CPROVER_assume(pub_r000467_6 >= -100 && pub_r000467_6 <= 100);
    __CPROVER_assume(pub_r000467_7 >= -100 && pub_r000467_7 <= 100);
    __CPROVER_assume(pub_r000467_8 >= -100 && pub_r000467_8 <= 100);
    __CPROVER_assume(pub_r000467_9 >= -100 && pub_r000467_9 <= 100);
    __CPROVER_assume(pub_r000467_10 >= -100 && pub_r000467_10 <= 100);
    __CPROVER_assume(pub_r000467_11 >= -100 && pub_r000467_11 <= 100);
    __CPROVER_assume(pub_r000467_12 >= -100 && pub_r000467_12 <= 100);
    __CPROVER_assume(pub_r000467_13 >= -100 && pub_r000467_13 <= 100);
    __CPROVER_assume(pub_r000467_14 >= -100 && pub_r000467_14 <= 100);
    __CPROVER_assume(pub_r000467_15 >= -100 && pub_r000467_15 <= 100);
    __CPROVER_assume(pub_r000467_16 >= -100 && pub_r000467_16 <= 100);
    __CPROVER_assume(pub_r000467_17 >= -100 && pub_r000467_17 <= 100);
    __CPROVER_assume(pub_r000467_18 >= -100 && pub_r000467_18 <= 100);
    __CPROVER_assume(pub_r000467_19 >= -100 && pub_r000467_19 <= 100);
    __CPROVER_assume(sec_r000467_0 >= 0 && sec_r000467_0 <= 255);
    __CPROVER_assume(sec_r000467_1 >= 0 && sec_r000467_1 <= 255);
    __CPROVER_assume(sec_r000467_2 >= 0 && sec_r000467_2 <= 255);
    __CPROVER_assume(sec_r000467_3 >= 0 && sec_r000467_3 <= 255);
    __CPROVER_assume(sec_r000467_4 >= 0 && sec_r000467_4 <= 255);
    __CPROVER_assume(sec_r000467_5 >= 0 && sec_r000467_5 <= 255);
    __CPROVER_assume(sec_r000467_6 >= 0 && sec_r000467_6 <= 255);
    __CPROVER_assume(sec_r000467_7 >= 0 && sec_r000467_7 <= 255);
    __CPROVER_assume(sec_r000467_8 >= 0 && sec_r000467_8 <= 255);
    __CPROVER_assume(sec_r000467_9 >= 0 && sec_r000467_9 <= 255);
    __CPROVER_assume(sec_r000467_10 >= 0 && sec_r000467_10 <= 255);
    __CPROVER_assume(sec_r000467_11 >= 0 && sec_r000467_11 <= 255);
    __CPROVER_assume(sec_r000467_12 >= 0 && sec_r000467_12 <= 255);
    __CPROVER_assume(sec_r000467_13 >= 0 && sec_r000467_13 <= 255);
    __CPROVER_assume(sec_r000467_14 >= 0 && sec_r000467_14 <= 255);
    __CPROVER_assume(sec_r000467_15 >= 0 && sec_r000467_15 <= 255);
    __CPROVER_assume(sec_r000467_16 >= 0 && sec_r000467_16 <= 255);

    struct CipherContext_R000467_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000467_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000467_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000467_0 + 7) & 15;
    struct SensorNode_R000467_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000467_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000467_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000467_0 + 9) & 15;
    struct EventLog_R000467_6713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000467_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000467_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000467_0 + 11) & 15;
    struct MatrixBlock_R000467_6713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000467_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000467_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000467_0 + 13) & 15;

    union ColorPixel_R000467_6713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 18) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 33) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 24) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 39) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] * 2 + 88) & 63;
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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 29) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 44) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 29) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 44) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 31) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 46) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 12) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 27) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 16) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 31) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 12) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 27) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 25) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 40) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 40) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 55) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 19) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 34) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000467_14 & 1) != 0) {
        if ((sec_r000467_5 & 2) != 0) {
            stage_v_73 = (pub_r000467_18 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000467_18 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000467_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_74 = (pub_r000467_5 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000467_5 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000467_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000467_10 & 2) != 0) {
            stage_v_75 = (pub_r000467_7 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000467_7 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000467_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000467_6 & 2) != 0) {
            stage_v_76 = (pub_r000467_14 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000467_14 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000467_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000467_12 & 2) != 0) {
            stage_v_77 = (pub_r000467_6 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000467_6 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000467_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000467_8 & 1) != 0) {
        if ((sec_r000467_7 & 2) != 0) {
            stage_v_78 = (pub_r000467_13 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000467_13 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000467_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000467_6 & 2) != 0) {
            stage_v_79 = (pub_r000467_2 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000467_2 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000467_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000467_8 & 2) != 0) {
            stage_v_80 = (pub_r000467_14 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000467_14 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000467_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000467_5 & 2) != 0) {
            stage_v_81 = (pub_r000467_8 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000467_8 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000467_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000467_12 & 2) != 0) {
            stage_v_82 = (pub_r000467_1 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000467_1 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000467_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000467_10 & 2) != 0) {
            stage_v_83 = (pub_r000467_16 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000467_16 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000467_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000467_16 & 2) != 0) {
            stage_v_84 = (pub_r000467_19 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000467_19 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000467_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000467_5 & 2) != 0) {
            stage_v_85 = (pub_r000467_3 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000467_3 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000467_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000467_10 & 2) != 0) {
            stage_v_86 = (pub_r000467_2 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000467_2 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000467_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000467_13 & 2) != 0) {
            stage_v_87 = (pub_r000467_2 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000467_2 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000467_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000467_3 & 1) != 0) {
        if ((sec_r000467_9 & 2) != 0) {
            stage_v_88 = (pub_r000467_4 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000467_4 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000467_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000467_10 & 2) != 0) {
            stage_v_89 = (pub_r000467_1 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000467_1 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000467_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000467_1 & 1) != 0) {
        if ((sec_r000467_6 & 2) != 0) {
            stage_v_90 = (pub_r000467_19 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000467_19 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000467_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000467_3 & 1) != 0) {
        if ((sec_r000467_12 & 2) != 0) {
            stage_v_91 = (pub_r000467_3 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000467_3 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000467_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_92 = (pub_r000467_5 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000467_5 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000467_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_93 = (pub_r000467_14 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000467_14 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000467_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000467_0 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_94 = (pub_r000467_13 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000467_13 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000467_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000467_1 & 1) != 0) {
        if ((sec_r000467_8 & 2) != 0) {
            stage_v_95 = (pub_r000467_2 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000467_2 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000467_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000467_13 & 1) != 0) {
        if ((sec_r000467_5 & 2) != 0) {
            stage_v_96 = (pub_r000467_3 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000467_3 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000467_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000467_12 & 2) != 0) {
            stage_v_97 = (pub_r000467_10 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000467_10 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000467_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000467_11 & 1) != 0) {
        if ((sec_r000467_7 & 2) != 0) {
            stage_v_98 = (pub_r000467_6 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000467_6 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000467_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000467_0 & 2) != 0) {
            stage_v_99 = (pub_r000467_3 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000467_3 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000467_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000467_5 & 2) != 0) {
            stage_v_100 = (pub_r000467_7 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000467_7 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000467_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000467_11 & 2) != 0) {
            stage_v_101 = (pub_r000467_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000467_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000467_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000467_6 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_102 = (pub_r000467_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000467_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000467_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000467_3 & 2) != 0) {
            stage_v_103 = (pub_r000467_9 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000467_9 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000467_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_104 = (pub_r000467_11 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000467_11 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000467_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000467_15 & 2) != 0) {
            stage_v_105 = (pub_r000467_14 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000467_14 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000467_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000467_5 & 2) != 0) {
            stage_v_106 = (pub_r000467_11 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000467_11 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000467_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000467_2 & 1) != 0) {
        if ((sec_r000467_3 & 2) != 0) {
            stage_v_107 = (pub_r000467_14 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000467_14 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000467_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000467_2 & 2) != 0) {
            stage_v_108 = (pub_r000467_0 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000467_0 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000467_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000467_10 & 1) != 0) {
        if ((sec_r000467_1 & 2) != 0) {
            stage_v_109 = (pub_r000467_5 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000467_5 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000467_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000467_0 & 2) != 0) {
            stage_v_110 = (pub_r000467_2 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000467_2 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000467_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000467_2 & 2) != 0) {
            stage_v_111 = (pub_r000467_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000467_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000467_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000467_15 & 1) != 0) {
        if ((sec_r000467_6 & 2) != 0) {
            stage_v_112 = (pub_r000467_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000467_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000467_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000467_14 & 1) != 0) {
        if ((sec_r000467_2 & 2) != 0) {
            stage_v_113 = (pub_r000467_9 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000467_9 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000467_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000467_13 & 2) != 0) {
            stage_v_114 = (pub_r000467_6 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000467_6 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000467_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000467_2 & 2) != 0) {
            stage_v_115 = (pub_r000467_15 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000467_15 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000467_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000467_12 & 2) != 0) {
            stage_v_116 = (pub_r000467_7 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000467_7 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000467_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000467_12 & 1) != 0) {
        if ((sec_r000467_13 & 2) != 0) {
            stage_v_117 = (pub_r000467_18 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000467_18 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000467_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000467_11 & 2) != 0) {
            stage_v_118 = (pub_r000467_1 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000467_1 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000467_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000467_0 & 2) != 0) {
            stage_v_119 = (pub_r000467_18 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000467_18 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000467_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000467_0 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_120 = (pub_r000467_19 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000467_19 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000467_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000467_11 & 2) != 0) {
            stage_v_121 = (pub_r000467_16 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000467_16 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000467_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000467_6 & 1) != 0) {
        if ((sec_r000467_13 & 2) != 0) {
            stage_v_122 = (pub_r000467_18 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000467_18 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000467_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000467_1 & 1) != 0) {
        if ((sec_r000467_1 & 2) != 0) {
            stage_v_123 = (pub_r000467_7 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000467_7 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000467_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000467_14 & 1) != 0) {
        if ((sec_r000467_10 & 2) != 0) {
            stage_v_124 = (pub_r000467_15 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000467_15 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000467_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000467_0 & 2) != 0) {
            stage_v_125 = (pub_r000467_6 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000467_6 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000467_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000467_6 & 2) != 0) {
            stage_v_126 = (pub_r000467_16 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000467_16 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000467_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000467_6 & 2) != 0) {
            stage_v_127 = (pub_r000467_2 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000467_2 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000467_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000467_5 & 1) != 0) {
        if ((sec_r000467_6 & 2) != 0) {
            stage_v_128 = (pub_r000467_16 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000467_16 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000467_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000467_12 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_129 = (pub_r000467_9 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000467_9 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000467_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000467_14 & 2) != 0) {
            stage_v_130 = (pub_r000467_17 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000467_17 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000467_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000467_13 & 1) != 0) {
        if ((sec_r000467_3 & 2) != 0) {
            stage_v_131 = (pub_r000467_5 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000467_5 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000467_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000467_9 & 2) != 0) {
            stage_v_132 = (pub_r000467_16 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000467_16 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000467_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000467_13 & 2) != 0) {
            stage_v_133 = (pub_r000467_9 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000467_9 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000467_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000467_12 & 2) != 0) {
            stage_v_134 = (pub_r000467_19 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000467_19 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000467_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000467_11 & 2) != 0) {
            stage_v_135 = (pub_r000467_5 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000467_5 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000467_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
