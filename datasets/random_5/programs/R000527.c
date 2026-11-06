/*
 * Benchmark Program: R000527
 * Security Family: nested_implicit_flow
 * Generator Seed: 552713
 * High Inputs: 20 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000527_2713_0 {
    short scale;
    unsigned char dim;
    int determinant;
    int buffer[3];
};

struct EventLog_R000527_2713_1 {
    unsigned char timestamp;
    int severity;
    int signature;
    unsigned char code;
    unsigned char seq;
    int buffer[3];
};

struct SensorNode_R000527_2713_2 {
    short status;
    int offset;
    short calib;
    unsigned char gain;
    int buffer[3];
};

struct CipherContext_R000527_2713_3 {
    int iv;
    unsigned char round_key;
    short flags;
    unsigned char nonce;
    int counter;
    unsigned char tag;
    int buffer[3];
};

union TelemetryField_R000527_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000527_2713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000527_2713_0(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000527_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_41 = (aux + st.buffer[1]) & 3;
    switch (threshold_41) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_56 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_56 > 28) {
        acc = (acc + parity_56 * 2 + 5) & 127;
        aux ^= (parity_56 & 15);
    } else {
        acc = (acc - parity_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_65 = (aux + st.buffer[1]) & 3;
    switch (factor_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_95 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_95 > 26) {
        acc = (acc + cursor_95 * 2 + 5) & 127;
        aux ^= (cursor_95 & 15);
    } else {
        acc = (acc - cursor_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int mask_35 = local_arr[aux % 3];
    acc = (acc + mask_35 * 2) & 127;
    int parity_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000527_2713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int phase_21 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_21 > 35) {
        acc = (acc + phase_21 * 2 + 5) & 127;
        aux ^= (phase_21 & 15);
    } else {
        acc = (acc - phase_21 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_93 = local_arr[aux % 3];
    acc = (acc + window_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000527_2713_5(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int pivot_67 = local_arr[aux % 3];
    acc = (acc + pivot_67 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_6(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000527_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int index_reg_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_63) & 63;
    acc ^= aux;
    int tracker_77 = (aux + st.buffer[1]) & 3;
    switch (tracker_77) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_96 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_96 > 25) {
        acc = (acc + coefficient_96 * 2 + 5) & 127;
        aux ^= (coefficient_96 & 15);
    } else {
        acc = (acc - coefficient_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000527_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_66 = (aux + st.buffer[1]) & 3;
    switch (tracker_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_34 = local_arr[aux % 3];
    acc = (acc + stride_34 * 2) & 127;
    int coefficient_52 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_52 > 27) {
        acc = (acc + coefficient_52 * 2 + 5) & 127;
        aux ^= (coefficient_52 & 15);
    } else {
        acc = (acc - coefficient_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_8(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int quantum_35 = local_arr[aux % 3];
    acc = (acc + quantum_35 * 2) & 127;
    int damping_97 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_97 > 12) {
        acc = (acc + damping_97 * 2 + 5) & 127;
        aux ^= (damping_97 & 15);
    } else {
        acc = (acc - damping_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_9(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int parity_13 = (aux + st.buffer[1]) & 3;
    switch (parity_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_48 = local_arr[aux % 3];
    acc = (acc + anchor_48 * 2) & 127;
    int stride_75 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_75 > 21) {
        acc = (acc + stride_75 * 2 + 5) & 127;
        aux ^= (stride_75 & 15);
    } else {
        acc = (acc - stride_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_37 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_37 > 48) {
        acc = (acc + threshold_37 * 2 + 5) & 127;
        aux ^= (threshold_37 & 15);
    } else {
        acc = (acc - threshold_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_59 = local_arr[aux % 3];
    acc = (acc + coefficient_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int vector_34 = local_arr[aux % 3];
    acc = (acc + vector_34 * 2) & 127;
    int margin_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_61) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_13 = (aux + st.buffer[1]) & 3;
    switch (margin_13) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int offset_93 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_93 > 25) {
        acc = (acc + offset_93 * 2 + 5) & 127;
        aux ^= (offset_93 & 15);
    } else {
        acc = (acc - offset_93 + 11) & 127;
        aux += 3;
    }
    int stride_24 = (aux + st.buffer[1]) & 3;
    switch (stride_24) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_77 = local_arr[aux % 3];
    acc = (acc + sample_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_13(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int vector_18 = local_arr[aux % 3];
    acc = (acc + vector_18 * 2) & 127;
    int weight_81 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_81 > 49) {
        acc = (acc + weight_81 * 2 + 5) & 127;
        aux ^= (weight_81 & 15);
    } else {
        acc = (acc - weight_81 + 11) & 127;
        aux += 3;
    }
    int threshold_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_77) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_14(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_17 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_17 > 20) {
        acc = (acc + metric_17 * 2 + 5) & 127;
        aux ^= (metric_17 & 15);
    } else {
        acc = (acc - metric_17 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_28 = local_arr[aux % 3];
    acc = (acc + parity_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000527_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int parity_39 = local_arr[aux % 3];
    acc = (acc + parity_39 * 2) & 127;
    int margin_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_90) & 63;
    acc ^= aux;
    int phase_83 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_83 > 49) {
        acc = (acc + phase_83 * 2 + 5) & 127;
        aux ^= (phase_83 & 15);
    } else {
        acc = (acc - phase_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_16(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000527_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quotient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_44) & 63;
    acc ^= aux;
    int offset_90 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_90 > 22) {
        acc = (acc + offset_90 * 2 + 5) & 127;
        aux ^= (offset_90 & 15);
    } else {
        acc = (acc - offset_90 + 11) & 127;
        aux += 3;
    }
    int sample_36 = (aux + st.buffer[1]) & 3;
    switch (sample_36) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int residue_90 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_90 > 39) {
        acc = (acc + residue_90 * 2 + 5) & 127;
        aux ^= (residue_90 & 15);
    } else {
        acc = (acc - residue_90 + 11) & 127;
        aux += 3;
    }
    int factor_63 = (aux + st.buffer[1]) & 3;
    switch (factor_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_23 = (aux + st.buffer[1]) & 3;
    switch (sample_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_83 = local_arr[aux % 3];
    acc = (acc + residue_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int accumulator_77 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_77 > 11) {
        acc = (acc + accumulator_77 * 2 + 5) & 127;
        aux ^= (accumulator_77 & 15);
    } else {
        acc = (acc - accumulator_77 + 11) & 127;
        aux += 3;
    }
    int parity_13 = (aux + st.buffer[1]) & 3;
    switch (parity_13) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int checksum_82 = local_arr[aux % 3];
    acc = (acc + checksum_82 * 2) & 127;
    int index_reg_36 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_36 > 47) {
        acc = (acc + index_reg_36 * 2 + 5) & 127;
        aux ^= (index_reg_36 & 15);
    } else {
        acc = (acc - index_reg_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_21(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tracker_74 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_74 > 31) {
        acc = (acc + tracker_74 * 2 + 5) & 127;
        aux ^= (tracker_74 & 15);
    } else {
        acc = (acc - tracker_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_37 = local_arr[aux % 3];
    acc = (acc + metric_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000527_2713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000527_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int offset_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_95 = local_arr[aux % 3];
    acc = (acc + cursor_95 * 2) & 127;
    int quantum_46 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_46 > 34) {
        acc = (acc + quantum_46 * 2 + 5) & 127;
        aux ^= (quantum_46 & 15);
    } else {
        acc = (acc - quantum_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000527_2713_23(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tracker_65 = (aux + st.buffer[1]) & 3;
    switch (tracker_65) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_52 = local_arr[aux % 3];
    acc = (acc + delta_52 * 2) & 127;
    int window_88 = (st.buffer[0] * 3 + aux) & 63;
    if (window_88 > 21) {
        acc = (acc + window_88 * 2 + 5) & 127;
        aux ^= (window_88 & 15);
    } else {
        acc = (acc - window_88 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000527_0;
    int sec_r000527_1;
    int sec_r000527_2;
    int sec_r000527_3;
    int sec_r000527_4;
    int sec_r000527_5;
    int sec_r000527_6;
    int sec_r000527_7;
    int sec_r000527_8;
    int sec_r000527_9;
    int sec_r000527_10;
    int sec_r000527_11;
    int sec_r000527_12;
    int sec_r000527_13;
    int sec_r000527_14;
    int sec_r000527_15;
    int sec_r000527_16;
    int sec_r000527_17;
    int sec_r000527_18;
    int sec_r000527_19;
    int pub_r000527_0;
    int pub_r000527_1;
    int pub_r000527_2;
    int pub_r000527_3;
    int pub_r000527_4;
    int pub_r000527_5;
    int pub_r000527_6;
    int pub_r000527_7;
    int pub_r000527_8;
    int pub_r000527_9;
    int pub_r000527_10;
    int pub_r000527_11;
    int pub_r000527_12;
    int pub_r000527_13;
    int pub_r000527_14;
    int pub_r000527_15;
    int pub_r000527_16;
    int pub_r000527_17;
    int pub_r000527_18;
    int pub_r000527_19;
    int pub_r000527_20;
    int pub_r000527_21;
    int pub_r000527_22;
    int pub_r000527_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000527_0 >= -100 && pub_r000527_0 <= 100);
    __CPROVER_assume(pub_r000527_1 >= -100 && pub_r000527_1 <= 100);
    __CPROVER_assume(pub_r000527_2 >= -100 && pub_r000527_2 <= 100);
    __CPROVER_assume(pub_r000527_3 >= -100 && pub_r000527_3 <= 100);
    __CPROVER_assume(pub_r000527_4 >= -100 && pub_r000527_4 <= 100);
    __CPROVER_assume(pub_r000527_5 >= -100 && pub_r000527_5 <= 100);
    __CPROVER_assume(pub_r000527_6 >= -100 && pub_r000527_6 <= 100);
    __CPROVER_assume(pub_r000527_7 >= -100 && pub_r000527_7 <= 100);
    __CPROVER_assume(pub_r000527_8 >= -100 && pub_r000527_8 <= 100);
    __CPROVER_assume(pub_r000527_9 >= -100 && pub_r000527_9 <= 100);
    __CPROVER_assume(pub_r000527_10 >= -100 && pub_r000527_10 <= 100);
    __CPROVER_assume(pub_r000527_11 >= -100 && pub_r000527_11 <= 100);
    __CPROVER_assume(pub_r000527_12 >= -100 && pub_r000527_12 <= 100);
    __CPROVER_assume(pub_r000527_13 >= -100 && pub_r000527_13 <= 100);
    __CPROVER_assume(pub_r000527_14 >= -100 && pub_r000527_14 <= 100);
    __CPROVER_assume(pub_r000527_15 >= -100 && pub_r000527_15 <= 100);
    __CPROVER_assume(pub_r000527_16 >= -100 && pub_r000527_16 <= 100);
    __CPROVER_assume(pub_r000527_17 >= -100 && pub_r000527_17 <= 100);
    __CPROVER_assume(pub_r000527_18 >= -100 && pub_r000527_18 <= 100);
    __CPROVER_assume(pub_r000527_19 >= -100 && pub_r000527_19 <= 100);
    __CPROVER_assume(pub_r000527_20 >= -100 && pub_r000527_20 <= 100);
    __CPROVER_assume(pub_r000527_21 >= -100 && pub_r000527_21 <= 100);
    __CPROVER_assume(pub_r000527_22 >= -100 && pub_r000527_22 <= 100);
    __CPROVER_assume(pub_r000527_23 >= -100 && pub_r000527_23 <= 100);
    __CPROVER_assume(sec_r000527_0 >= 0 && sec_r000527_0 <= 255);
    __CPROVER_assume(sec_r000527_1 >= 0 && sec_r000527_1 <= 255);
    __CPROVER_assume(sec_r000527_2 >= 0 && sec_r000527_2 <= 255);
    __CPROVER_assume(sec_r000527_3 >= 0 && sec_r000527_3 <= 255);
    __CPROVER_assume(sec_r000527_4 >= 0 && sec_r000527_4 <= 255);
    __CPROVER_assume(sec_r000527_5 >= 0 && sec_r000527_5 <= 255);
    __CPROVER_assume(sec_r000527_6 >= 0 && sec_r000527_6 <= 255);
    __CPROVER_assume(sec_r000527_7 >= 0 && sec_r000527_7 <= 255);
    __CPROVER_assume(sec_r000527_8 >= 0 && sec_r000527_8 <= 255);
    __CPROVER_assume(sec_r000527_9 >= 0 && sec_r000527_9 <= 255);
    __CPROVER_assume(sec_r000527_10 >= 0 && sec_r000527_10 <= 255);
    __CPROVER_assume(sec_r000527_11 >= 0 && sec_r000527_11 <= 255);
    __CPROVER_assume(sec_r000527_12 >= 0 && sec_r000527_12 <= 255);
    __CPROVER_assume(sec_r000527_13 >= 0 && sec_r000527_13 <= 255);
    __CPROVER_assume(sec_r000527_14 >= 0 && sec_r000527_14 <= 255);
    __CPROVER_assume(sec_r000527_15 >= 0 && sec_r000527_15 <= 255);
    __CPROVER_assume(sec_r000527_16 >= 0 && sec_r000527_16 <= 255);
    __CPROVER_assume(sec_r000527_17 >= 0 && sec_r000527_17 <= 255);
    __CPROVER_assume(sec_r000527_18 >= 0 && sec_r000527_18 <= 255);
    __CPROVER_assume(sec_r000527_19 >= 0 && sec_r000527_19 <= 255);

    struct MatrixBlock_R000527_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000527_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000527_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000527_0 + 7) & 15;
    struct EventLog_R000527_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000527_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000527_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000527_0 + 9) & 15;
    struct SensorNode_R000527_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000527_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000527_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000527_0 + 11) & 15;
    struct CipherContext_R000527_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000527_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000527_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000527_0 + 13) & 15;

    union TelemetryField_R000527_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 31) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 46) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 36) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 51) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 31) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 46) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 23) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 38) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 34) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 49) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 22) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 37) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 11) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 26) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 27) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 42) {
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
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 31) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 46) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 15) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 30) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 18) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 33) {
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
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000527_15 & 1) != 0) {
        if ((sec_r000527_17 & 2) != 0) {
            stage_v_52 = (pub_r000527_21 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000527_21 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000527_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000527_8 & 2) != 0) {
            stage_v_53 = (pub_r000527_5 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000527_5 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000527_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000527_19 & 2) != 0) {
            stage_v_54 = (pub_r000527_15 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000527_15 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000527_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000527_5 & 1) != 0) {
        if ((sec_r000527_6 & 2) != 0) {
            stage_v_55 = (pub_r000527_20 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000527_20 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000527_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000527_3 & 2) != 0) {
            stage_v_56 = (pub_r000527_23 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000527_23 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000527_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000527_0 & 2) != 0) {
            stage_v_57 = (pub_r000527_18 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000527_18 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000527_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000527_10 & 2) != 0) {
            stage_v_58 = (pub_r000527_22 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000527_22 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000527_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_59 = (pub_r000527_6 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000527_6 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000527_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000527_1 & 1) != 0) {
        if ((sec_r000527_13 & 2) != 0) {
            stage_v_60 = (pub_r000527_22 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000527_22 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000527_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000527_8 & 2) != 0) {
            stage_v_61 = (pub_r000527_18 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000527_18 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000527_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000527_18 & 2) != 0) {
            stage_v_62 = (pub_r000527_17 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000527_17 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000527_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000527_1 & 2) != 0) {
            stage_v_63 = (pub_r000527_12 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000527_12 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000527_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000527_4 & 2) != 0) {
            stage_v_64 = (pub_r000527_0 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000527_0 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000527_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000527_6 & 2) != 0) {
            stage_v_65 = (pub_r000527_13 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000527_13 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000527_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000527_19 & 2) != 0) {
            stage_v_66 = (pub_r000527_0 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000527_0 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000527_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000527_19 & 2) != 0) {
            stage_v_67 = (pub_r000527_21 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000527_21 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000527_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000527_15 & 1) != 0) {
        if ((sec_r000527_9 & 2) != 0) {
            stage_v_68 = (pub_r000527_12 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000527_12 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000527_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000527_11 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_69 = (pub_r000527_0 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000527_0 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000527_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000527_1 & 2) != 0) {
            stage_v_70 = (pub_r000527_9 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000527_9 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000527_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000527_0 & 2) != 0) {
            stage_v_71 = (pub_r000527_23 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000527_23 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000527_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000527_12 & 1) != 0) {
        if ((sec_r000527_0 & 2) != 0) {
            stage_v_72 = (pub_r000527_10 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000527_10 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000527_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000527_3 & 1) != 0) {
        if ((sec_r000527_9 & 2) != 0) {
            stage_v_73 = (pub_r000527_21 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000527_21 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000527_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000527_2 & 2) != 0) {
            stage_v_74 = (pub_r000527_16 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000527_16 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000527_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000527_11 & 2) != 0) {
            stage_v_75 = (pub_r000527_21 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000527_21 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000527_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000527_15 & 2) != 0) {
            stage_v_76 = (pub_r000527_3 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000527_3 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000527_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_77 = (pub_r000527_0 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000527_0 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000527_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000527_11 & 2) != 0) {
            stage_v_78 = (pub_r000527_17 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000527_17 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000527_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000527_1 & 2) != 0) {
            stage_v_79 = (pub_r000527_7 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000527_7 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000527_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000527_13 & 2) != 0) {
            stage_v_80 = (pub_r000527_23 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000527_23 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000527_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000527_0 & 2) != 0) {
            stage_v_81 = (pub_r000527_21 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000527_21 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000527_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000527_4 & 2) != 0) {
            stage_v_82 = (pub_r000527_17 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000527_17 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000527_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000527_4 & 2) != 0) {
            stage_v_83 = (pub_r000527_16 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000527_16 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000527_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000527_6 & 2) != 0) {
            stage_v_84 = (pub_r000527_10 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000527_10 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000527_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000527_1 & 2) != 0) {
            stage_v_85 = (pub_r000527_16 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000527_16 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000527_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000527_9 & 1) != 0) {
        if ((sec_r000527_15 & 2) != 0) {
            stage_v_86 = (pub_r000527_9 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000527_9 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000527_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000527_1 & 2) != 0) {
            stage_v_87 = (pub_r000527_5 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000527_5 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000527_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000527_0 & 2) != 0) {
            stage_v_88 = (pub_r000527_10 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000527_10 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000527_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000527_13 & 1) != 0) {
        if ((sec_r000527_3 & 2) != 0) {
            stage_v_89 = (pub_r000527_4 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000527_4 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000527_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000527_13 & 1) != 0) {
        if ((sec_r000527_10 & 2) != 0) {
            stage_v_90 = (pub_r000527_15 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000527_15 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000527_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000527_16 & 2) != 0) {
            stage_v_91 = (pub_r000527_14 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000527_14 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000527_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_92 = (pub_r000527_4 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000527_4 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000527_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000527_18 & 2) != 0) {
            stage_v_93 = (pub_r000527_2 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000527_2 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000527_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_94 = (pub_r000527_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000527_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000527_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000527_10 & 1) != 0) {
        if ((sec_r000527_17 & 2) != 0) {
            stage_v_95 = (pub_r000527_4 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000527_4 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000527_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000527_4 & 2) != 0) {
            stage_v_96 = (pub_r000527_15 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000527_15 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000527_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000527_13 & 1) != 0) {
        if ((sec_r000527_16 & 2) != 0) {
            stage_v_97 = (pub_r000527_10 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000527_10 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000527_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000527_9 & 2) != 0) {
            stage_v_98 = (pub_r000527_0 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000527_0 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000527_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000527_4 & 1) != 0) {
        if ((sec_r000527_12 & 2) != 0) {
            stage_v_99 = (pub_r000527_14 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000527_14 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000527_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000527_18 & 2) != 0) {
            stage_v_100 = (pub_r000527_19 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000527_19 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000527_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000527_13 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_101 = (pub_r000527_18 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000527_18 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000527_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000527_18 & 2) != 0) {
            stage_v_102 = (pub_r000527_21 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000527_21 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000527_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000527_4 & 2) != 0) {
            stage_v_103 = (pub_r000527_4 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000527_4 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000527_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000527_14 & 2) != 0) {
            stage_v_104 = (pub_r000527_11 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000527_11 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000527_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000527_8 & 1) != 0) {
        if ((sec_r000527_11 & 2) != 0) {
            stage_v_105 = (pub_r000527_11 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000527_11 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000527_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000527_11 & 1) != 0) {
        if ((sec_r000527_18 & 2) != 0) {
            stage_v_106 = (pub_r000527_18 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000527_18 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000527_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000527_17 & 2) != 0) {
            stage_v_107 = (pub_r000527_5 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000527_5 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000527_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000527_16 & 2) != 0) {
            stage_v_108 = (pub_r000527_12 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000527_12 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000527_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000527_4 & 2) != 0) {
            stage_v_109 = (pub_r000527_13 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000527_13 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000527_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000527_4 & 1) != 0) {
        if ((sec_r000527_11 & 2) != 0) {
            stage_v_110 = (pub_r000527_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000527_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000527_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000527_4 & 1) != 0) {
        if ((sec_r000527_18 & 2) != 0) {
            stage_v_111 = (pub_r000527_21 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000527_21 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000527_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000527_11 & 2) != 0) {
            stage_v_112 = (pub_r000527_18 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000527_18 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000527_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000527_11 & 2) != 0) {
            stage_v_113 = (pub_r000527_20 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000527_20 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000527_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000527_9 & 2) != 0) {
            stage_v_114 = (pub_r000527_16 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000527_16 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000527_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000527_9 & 2) != 0) {
            stage_v_115 = (pub_r000527_23 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000527_23 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000527_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000527_11 & 1) != 0) {
        if ((sec_r000527_11 & 2) != 0) {
            stage_v_116 = (pub_r000527_16 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000527_16 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000527_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000527_4 & 2) != 0) {
            stage_v_117 = (pub_r000527_10 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000527_10 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000527_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000527_9 & 2) != 0) {
            stage_v_118 = (pub_r000527_5 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000527_5 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000527_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000527_10 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_119 = (pub_r000527_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000527_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000527_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000527_12 & 1) != 0) {
        if ((sec_r000527_6 & 2) != 0) {
            stage_v_120 = (pub_r000527_4 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000527_4 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000527_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000527_7 & 2) != 0) {
            stage_v_121 = (pub_r000527_18 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000527_18 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000527_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
