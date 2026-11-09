/*
 * Benchmark Program: R001200
 * Security Family: mixed_control_data
 * Generator Seed: 620013
 * High Inputs: 21 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001200_13_0 {
    short checksum;
    short capacity;
    int watermark;
    int state;
    int tail;
    int buffer[3];
};

struct CipherContext_R001200_13_1 {
    unsigned char flags;
    short nonce;
    int counter;
    short tag;
    unsigned char round_key;
    int iv;
    int buffer[3];
};

struct SensorNode_R001200_13_2 {
    int threshold;
    int reading;
    int gain;
    int buffer[3];
};

union TelemetryField_R001200_13_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001200_13_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001200_13_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int scale_39 = (aux + st.buffer[1]) & 3;
    switch (scale_39) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_72 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_72 > 43) {
        acc = (acc + tally_72 * 2 + 5) & 127;
        aux ^= (tally_72 & 15);
    } else {
        acc = (acc - tally_72 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001200_13_1(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001200_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int anchor_81 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_81 = (anchor_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_81) & 127;
    }
    int parity_21 = (aux + st.buffer[1]) & 3;
    switch (parity_21) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_30 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_30 > 43) {
        acc = (acc + quantum_30 * 2 + 5) & 127;
        aux ^= (quantum_30 & 15);
    } else {
        acc = (acc - quantum_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_67 = local_arr[aux % 3];
    acc = (acc + damping_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001200_13_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001200_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int residue_48 = (aux + st.buffer[1]) & 3;
    switch (residue_48) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_64 = 0;
    for (int k = 0; k < 2; k++) {
        mask_64 = (mask_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_3(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001200_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_75 = local_arr[aux % 3];
    acc = (acc + vector_75 * 2) & 127;
    int quantum_37 = (aux + st.buffer[1]) & 3;
    switch (quantum_37) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001200_13_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001200_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int bound_62 = (aux + st.buffer[1]) & 3;
    switch (bound_62) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_22 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_22 > 22) {
        acc = (acc + delta_22 * 2 + 5) & 127;
        aux ^= (delta_22 & 15);
    } else {
        acc = (acc - delta_22 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_47 = local_arr[aux % 3];
    acc = (acc + window_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001200_13_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int coefficient_68 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_68 = (coefficient_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_68) & 127;
    }
    int parity_41 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_41 > 16) {
        acc = (acc + parity_41 * 2 + 5) & 127;
        aux ^= (parity_41 & 15);
    } else {
        acc = (acc - parity_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_97 = local_arr[aux % 3];
    acc = (acc + stride_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001200_13_6(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001200_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_39 = local_arr[aux % 3];
    acc = (acc + accumulator_39 * 2) & 127;
    int quantum_38 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_38 > 26) {
        acc = (acc + quantum_38 * 2 + 5) & 127;
        aux ^= (quantum_38 & 15);
    } else {
        acc = (acc - quantum_38 + 11) & 127;
        aux += 3;
    }
    int mask_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001200_13_7(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_88 = local_arr[aux % 3];
    acc = (acc + weight_88 * 2) & 127;
    int anchor_37 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_37 > 26) {
        acc = (acc + anchor_37 * 2 + 5) & 127;
        aux ^= (anchor_37 & 15);
    } else {
        acc = (acc - anchor_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_8(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int factor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_58) & 63;
    acc ^= aux;
    int residue_38 = 0;
    for (int k = 0; k < 3; k++) {
        residue_38 = (residue_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_38) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_58 = local_arr[aux % 3];
    acc = (acc + factor_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001200_13_9(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001200_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int vector_60 = (aux + st.buffer[1]) & 3;
    switch (vector_60) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001200_13_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001200_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_15 = (aux + st.buffer[1]) & 3;
    switch (stride_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_73 = local_arr[aux % 3];
    acc = (acc + parity_73 * 2) & 127;
    int residue_44 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_44 > 11) {
        acc = (acc + residue_44 * 2 + 5) & 127;
        aux ^= (residue_44 & 15);
    } else {
        acc = (acc - residue_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int checksum_23 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_23 = (checksum_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_23) & 127;
    }
    int threshold_52 = (aux + st.buffer[1]) & 3;
    switch (threshold_52) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_28) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_40 = local_arr[aux % 3];
    acc = (acc + quantum_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001200_13_12(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001200_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int residue_68 = (aux + st.buffer[1]) & 3;
    switch (residue_68) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001200_13_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_69 > 38) {
        acc = (acc + anchor_69 * 2 + 5) & 127;
        aux ^= (anchor_69 & 15);
    } else {
        acc = (acc - anchor_69 + 11) & 127;
        aux += 3;
    }
    int sample_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_59) & 63;
    acc ^= aux;
    int cursor_52 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_52 = (cursor_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int metric_62 = local_arr[aux % 3];
    acc = (acc + metric_62 * 2) & 127;
    int tally_42 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_42 > 27) {
        acc = (acc + tally_42 * 2 + 5) & 127;
        aux ^= (tally_42 & 15);
    } else {
        acc = (acc - tally_42 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_51 = (aux + st.buffer[1]) & 3;
    switch (scale_51) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int coefficient_67 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_67 = (coefficient_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_67) & 127;
    }
    int pivot_37 = (aux + st.buffer[1]) & 3;
    switch (pivot_37) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_46 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_46 > 46) {
        acc = (acc + weight_46 * 2 + 5) & 127;
        aux ^= (weight_46 & 15);
    } else {
        acc = (acc - weight_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_56 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_56 = (threshold_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_56) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_81 = local_arr[aux % 3];
    acc = (acc + tracker_81 * 2) & 127;
    int coefficient_84 = (aux + st.buffer[1]) & 3;
    switch (coefficient_84) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_17(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001200_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_59) & 63;
    acc ^= aux;
    int index_reg_38 = (aux + st.buffer[1]) & 3;
    switch (index_reg_38) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int damping_20 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_20 > 49) {
        acc = (acc + damping_20 * 2 + 5) & 127;
        aux ^= (damping_20 & 15);
    } else {
        acc = (acc - damping_20 + 11) & 127;
        aux += 3;
    }
    int mask_46 = (aux + st.buffer[1]) & 3;
    switch (mask_46) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001200_13_19(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001200_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int segment_39 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_39 > 18) {
        acc = (acc + segment_39 * 2 + 5) & 127;
        aux ^= (segment_39 & 15);
    } else {
        acc = (acc - segment_39 + 11) & 127;
        aux += 3;
    }
    int damping_14 = (aux + st.buffer[1]) & 3;
    switch (damping_14) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001200_0;
    int sec_r001200_1;
    int sec_r001200_2;
    int sec_r001200_3;
    int sec_r001200_4;
    int sec_r001200_5;
    int sec_r001200_6;
    int sec_r001200_7;
    int sec_r001200_8;
    int sec_r001200_9;
    int sec_r001200_10;
    int sec_r001200_11;
    int sec_r001200_12;
    int sec_r001200_13;
    int sec_r001200_14;
    int sec_r001200_15;
    int sec_r001200_16;
    int sec_r001200_17;
    int sec_r001200_18;
    int sec_r001200_19;
    int sec_r001200_20;
    int pub_r001200_0;
    int pub_r001200_1;
    int pub_r001200_2;
    int pub_r001200_3;
    int pub_r001200_4;
    int pub_r001200_5;
    int pub_r001200_6;
    int pub_r001200_7;
    int pub_r001200_8;
    int pub_r001200_9;
    int pub_r001200_10;
    int pub_r001200_11;
    int pub_r001200_12;
    int pub_r001200_13;
    int pub_r001200_14;
    int pub_r001200_15;
    int pub_r001200_16;
    int pub_r001200_17;
    int pub_r001200_18;
    int pub_r001200_19;
    int pub_r001200_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001200_0 >= -100 && pub_r001200_0 <= 100);
    __CPROVER_assume(pub_r001200_1 >= -100 && pub_r001200_1 <= 100);
    __CPROVER_assume(pub_r001200_2 >= -100 && pub_r001200_2 <= 100);
    __CPROVER_assume(pub_r001200_3 >= -100 && pub_r001200_3 <= 100);
    __CPROVER_assume(pub_r001200_4 >= -100 && pub_r001200_4 <= 100);
    __CPROVER_assume(pub_r001200_5 >= -100 && pub_r001200_5 <= 100);
    __CPROVER_assume(pub_r001200_6 >= -100 && pub_r001200_6 <= 100);
    __CPROVER_assume(pub_r001200_7 >= -100 && pub_r001200_7 <= 100);
    __CPROVER_assume(pub_r001200_8 >= -100 && pub_r001200_8 <= 100);
    __CPROVER_assume(pub_r001200_9 >= -100 && pub_r001200_9 <= 100);
    __CPROVER_assume(pub_r001200_10 >= -100 && pub_r001200_10 <= 100);
    __CPROVER_assume(pub_r001200_11 >= -100 && pub_r001200_11 <= 100);
    __CPROVER_assume(pub_r001200_12 >= -100 && pub_r001200_12 <= 100);
    __CPROVER_assume(pub_r001200_13 >= -100 && pub_r001200_13 <= 100);
    __CPROVER_assume(pub_r001200_14 >= -100 && pub_r001200_14 <= 100);
    __CPROVER_assume(pub_r001200_15 >= -100 && pub_r001200_15 <= 100);
    __CPROVER_assume(pub_r001200_16 >= -100 && pub_r001200_16 <= 100);
    __CPROVER_assume(pub_r001200_17 >= -100 && pub_r001200_17 <= 100);
    __CPROVER_assume(pub_r001200_18 >= -100 && pub_r001200_18 <= 100);
    __CPROVER_assume(pub_r001200_19 >= -100 && pub_r001200_19 <= 100);
    __CPROVER_assume(pub_r001200_20 >= -100 && pub_r001200_20 <= 100);
    __CPROVER_assume(sec_r001200_0 >= 0 && sec_r001200_0 <= 255);
    __CPROVER_assume(sec_r001200_1 >= 0 && sec_r001200_1 <= 255);
    __CPROVER_assume(sec_r001200_2 >= 0 && sec_r001200_2 <= 255);
    __CPROVER_assume(sec_r001200_3 >= 0 && sec_r001200_3 <= 255);
    __CPROVER_assume(sec_r001200_4 >= 0 && sec_r001200_4 <= 255);
    __CPROVER_assume(sec_r001200_5 >= 0 && sec_r001200_5 <= 255);
    __CPROVER_assume(sec_r001200_6 >= 0 && sec_r001200_6 <= 255);
    __CPROVER_assume(sec_r001200_7 >= 0 && sec_r001200_7 <= 255);
    __CPROVER_assume(sec_r001200_8 >= 0 && sec_r001200_8 <= 255);
    __CPROVER_assume(sec_r001200_9 >= 0 && sec_r001200_9 <= 255);
    __CPROVER_assume(sec_r001200_10 >= 0 && sec_r001200_10 <= 255);
    __CPROVER_assume(sec_r001200_11 >= 0 && sec_r001200_11 <= 255);
    __CPROVER_assume(sec_r001200_12 >= 0 && sec_r001200_12 <= 255);
    __CPROVER_assume(sec_r001200_13 >= 0 && sec_r001200_13 <= 255);
    __CPROVER_assume(sec_r001200_14 >= 0 && sec_r001200_14 <= 255);
    __CPROVER_assume(sec_r001200_15 >= 0 && sec_r001200_15 <= 255);
    __CPROVER_assume(sec_r001200_16 >= 0 && sec_r001200_16 <= 255);
    __CPROVER_assume(sec_r001200_17 >= 0 && sec_r001200_17 <= 255);
    __CPROVER_assume(sec_r001200_18 >= 0 && sec_r001200_18 <= 255);
    __CPROVER_assume(sec_r001200_19 >= 0 && sec_r001200_19 <= 255);
    __CPROVER_assume(sec_r001200_20 >= 0 && sec_r001200_20 <= 255);

    struct StreamBuffer_R001200_13_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001200_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001200_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001200_0 + 7) & 15;
    struct CipherContext_R001200_13_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001200_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001200_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001200_0 + 9) & 15;
    struct SensorNode_R001200_13_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001200_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001200_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001200_0 + 11) & 15;

    union TelemetryField_R001200_13_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001200_13_0(sec_r001200_0, pub_r001200_1, pub_r001200_2, pub_r001200_3, pub_r001200_4);
    int helper_flow_1 = fn_R001200_13_1(sec_r001200_1, sec_r001200_2, pub_r001200_3);
    int helper_flow_2 = fn_R001200_13_2(sec_r001200_2, sec_r001200_3, pub_r001200_4, pub_r001200_5);
    int helper_flow_3 = fn_R001200_13_3(sec_r001200_3, pub_r001200_4);
    int helper_flow_4 = fn_R001200_13_4(sec_r001200_4, pub_r001200_5, pub_r001200_6, pub_r001200_7);
    int helper_flow_5 = fn_R001200_13_5(sec_r001200_5, pub_r001200_6, pub_r001200_7, pub_r001200_8, pub_r001200_9);
    int helper_flow_6 = fn_R001200_13_6(sec_r001200_6, pub_r001200_7);
    int helper_flow_7 = fn_R001200_13_7(sec_r001200_7, pub_r001200_8, pub_r001200_9);
    int helper_flow_8 = fn_R001200_13_8(sec_r001200_8, pub_r001200_9, pub_r001200_10);
    int helper_flow_9 = fn_R001200_13_9(sec_r001200_9, pub_r001200_10, pub_r001200_11);
    int helper_flow_10 = fn_R001200_13_10(sec_r001200_10, sec_r001200_11, pub_r001200_12, pub_r001200_13);
    int helper_flow_11 = fn_R001200_13_11(sec_r001200_11, pub_r001200_12, pub_r001200_13, pub_r001200_14, pub_r001200_15);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001200_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001200_17 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_1 > 47) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_2 > 30) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001200_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001200_8 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_4 > 22) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001200_6 ^ 0x2A) * 2 + pub_r001200_1) & 127;
    if (stage_v_5 > 29) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001200_2) & 127;
    if (stage_v_6 > 30) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001200_3) & 127;
    if (stage_v_7 > 29) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_8 > 34) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001200_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001200_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001200_18) & 127;
    if (stage_v_11 > 26) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001200_20 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_12 > 23) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001200_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001200_7 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_14 > 45) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001200_2 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_15 > 20) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_16 > 35) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001200_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001200_12 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_18 > 29) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001200_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001200_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001200_9 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_21 > 25) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001200_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001200_6 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_23 > 40) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001200_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001200_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_26 > 41) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001200_19 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_27 > 46) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001200_20) & 127;
    if (stage_v_28 > 20) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001200_3) & 127;
    if (stage_v_29 > 26) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001200_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001200_13 ^ 0x2A) * 2 + pub_r001200_0) & 127;
    if (stage_v_31 > 29) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001200_13 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_32 > 41) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001200_20 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_33 > 31) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001200_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001200_4 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_35 > 26) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001200_20 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_36 > 24) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_37 > 20) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001200_18 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_38 > 44) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001200_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001200_15 ^ 0x2A) * 2 + pub_r001200_14) & 127;
    if (stage_v_40 > 37) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001200_12 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_41 > 49) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001200_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_43 > 41) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001200_2) & 127;
    if (stage_v_44 > 43) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001200_19 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_45 > 23) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001200_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001200_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001200_19 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_48 > 50) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001200_0 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_49 > 43) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001200_1) & 127;
    if (stage_v_50 > 42) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001200_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001200_5 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_52 > 38) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001200_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001200_11 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_54 > 42) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001200_18 ^ 0x2A) * 2 + pub_r001200_2) & 127;
    if (stage_v_55 > 50) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001200_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001200_0 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_57 > 34) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_58 > 49) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_59 > 47) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_60 > 35) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001200_14) & 127;
    if (stage_v_61 > 20) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_62 > 26) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_63 > 46) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001200_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001200_7 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_65 > 46) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_66 > 39) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001200_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_68 > 38) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_69 > 46) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001200_14) & 127;
    if (stage_v_70 > 29) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001200_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001200_19 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_72 > 46) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001200_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_74 > 30) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001200_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001200_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001200_14 ^ 0x2A) * 2 + pub_r001200_16) & 127;
    if (stage_v_77 > 36) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001200_16) & 127;
    if (stage_v_78 > 36) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_79 > 44) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_80 > 30) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001200_14 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_81 > 46) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_82 > 37) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001200_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001200_17 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_84 > 44) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_85 > 41) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001200_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r001200_19 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_87 > 37) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001200_13 ^ 0x2A) * 2 + pub_r001200_2) & 127;
    if (stage_v_88 > 31) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_89 > 30) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001200_12 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_90 > 25) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_91 > 43) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001200_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_93 > 27) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001200_20 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001200_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_96 > 45) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_97 > 34) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_98 > 37) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001200_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001200_20 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_100 > 22) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001200_1) & 127;
    if (stage_v_101 > 35) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_102 > 36) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_103 > 21) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001200_8 ^ 0x2A) * 2 + pub_r001200_3) & 127;
    if (stage_v_104 > 37) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001200_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_106 > 28) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_107 > 38) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_108 > 38) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001200_3) & 127;
    if (stage_v_109 > 25) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_110 > 49) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_111 > 36) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001200_20) & 127;
    if (stage_v_112 > 41) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001200_16) & 127;
    if (stage_v_113 > 28) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r001200_12 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_114 > 27) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001200_17 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_115 > 48) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001200_9) & 127;
    if (stage_v_116 > 36) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_117 > 33) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_118 > 36) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_119 > 20) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001200_9) & 127;
    if (stage_v_120 > 32) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_121 > 49) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001200_18) & 127;
    if (stage_v_122 > 49) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001200_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_124 > 50) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001200_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_126 > 30) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_127 > 23) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001200_3) & 127;
    if (stage_v_128 > 26) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001200_20) & 127;
    if (stage_v_129 > 47) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001200_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001200_9) & 127;
    if (stage_v_131 > 41) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001200_3) & 127;
    if (stage_v_132 > 49) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_133 > 32) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_134 > 22) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001200_6) & 127;
    if (stage_v_135 > 27) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r001200_7 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_136 > 23) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001200_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_138 > 24) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001200_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_140 > 20) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001200_11) & 127;
    if (stage_v_141 > 33) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_142 > 48) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001200_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001200_16 ^ 0x2A) * 2 + pub_r001200_16) & 127;
    if (stage_v_144 > 25) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001200_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001200_14) & 127;
    if (stage_v_146 > 39) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_147 > 43) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001200_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001200_14 ^ 0x2A) * 2 + pub_r001200_19) & 127;
    if (stage_v_149 > 24) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001200_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001200_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001200_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001200_1 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_153 > 31) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001200_14) & 127;
    if (stage_v_154 > 38) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_155 > 43) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001200_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001200_14) & 127;
    if (stage_v_157 > 28) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001200_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001200_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001200_14 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_160 > 34) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001200_19) & 127;
    if (stage_v_161 > 30) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_162 > 20) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001200_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_164 > 25) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001200_20 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001200_19 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_166 > 27) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001200_19) & 127;
    if (stage_v_167 > 39) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001200_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001200_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001200_0) & 127;
    if (stage_v_170 > 36) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001200_20) & 127;
    if (stage_v_171 > 24) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001200_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001200_20) & 127;
    if (stage_v_173 > 23) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001200_19) & 127;
    if (stage_v_174 > 47) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001200_2) & 127;
    if (stage_v_175 > 28) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_176 > 35) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001200_18) & 127;
    if (stage_v_177 > 26) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001200_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001200_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r001200_5 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_180 > 26) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_181 > 48) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001200_0) & 127;
    if (stage_v_182 > 38) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r001200_6 ^ 0x2A) * 2 + pub_r001200_16) & 127;
    if (stage_v_183 > 45) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001200_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001200_13) & 127;
    if (stage_v_185 > 30) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_186 > 43) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001200_18) & 127;
    if (stage_v_187 > 24) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001200_18) & 127;
    if (stage_v_188 > 34) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001200_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_190 > 34) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_191 > 46) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_192 > 32) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_193 > 46) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_194 > 35) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001200_4) & 127;
    if (stage_v_195 > 48) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_196 > 38) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001200_9) & 127;
    if (stage_v_197 > 25) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001200_1) & 127;
    if (stage_v_198 > 33) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001200_12 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001200_19) & 127;
    if (stage_v_200 > 42) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001200_0) & 127;
    if (stage_v_201 > 46) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001200_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001200_0) & 127;
    if (stage_v_203 > 35) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001200_16) & 127;
    if (stage_v_204 > 50) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001200_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_191 ^ 0x2A) * 2 + pub_r001200_15) & 127;
    if (stage_v_206 > 39) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001200_14) & 127;
    if (stage_v_207 > 23) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001200_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001200_15) & 127;
    if (stage_v_209 > 50) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001200_2) & 127;
    if (stage_v_210 > 30) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001200_14 ^ 0x2A) * 2 + pub_r001200_12) & 127;
    if (stage_v_211 > 29) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001200_17) & 127;
    if (stage_v_212 > 32) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001200_5) & 127;
    if (stage_v_213 > 38) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_214 > 30) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001200_8) & 127;
    if (stage_v_215 > 47) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001200_10) & 127;
    if (stage_v_216 > 29) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r001200_8 ^ 0x2A) * 2 + pub_r001200_7) & 127;
    if (stage_v_217 > 48) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_191 ^ 0x2A) * 2 + pub_r001200_3) & 127;
    if (stage_v_218 > 44) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
