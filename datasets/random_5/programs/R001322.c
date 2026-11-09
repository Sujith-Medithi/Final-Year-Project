/*
 * Benchmark Program: R001322
 * Security Family: direct_leakage
 * Generator Seed: 632213
 * High Inputs: 22 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001322_2213_0 {
    int timeout;
    unsigned char parity;
    int baud_rate;
    int id;
    int buffer[3];
};

struct MatrixBlock_R001322_2213_1 {
    int scale;
    int trace;
    unsigned char determinant;
    unsigned char stride;
    short density;
    int dim;
    int buffer[3];
};

union RegisterBank_R001322_2213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001322_2213_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_25 = 0;
    for (int k = 0; k < 3; k++) {
        tally_25 = (tally_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_25) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_14 = local_arr[aux % 3];
    acc = (acc + residue_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001322_2213_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_60) & 63;
    acc ^= aux;
    int index_reg_48 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_48 = (index_reg_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_48) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_60 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_60 > 22) {
        acc = (acc + parity_60 * 2 + 5) & 127;
        aux ^= (parity_60 & 15);
    } else {
        acc = (acc - parity_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_99 = (aux + st.buffer[1]) & 3;
    switch (bound_99) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_79 > 36) {
        acc = (acc + quantum_79 * 2 + 5) & 127;
        aux ^= (quantum_79 & 15);
    } else {
        acc = (acc - quantum_79 + 11) & 127;
        aux += 3;
    }
    int weight_57 = 0;
    for (int k = 0; k < 3; k++) {
        weight_57 = (weight_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_57) & 127;
    }
    int mask_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_48) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001322_2213_4(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int parity_61 = 0;
    for (int k = 0; k < 3; k++) {
        parity_61 = (parity_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_61) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_42) & 63;
    acc ^= aux;
    int sample_44 = (aux + st.buffer[1]) & 3;
    switch (sample_44) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_5(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int anchor_26 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_26 = (anchor_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_26) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_70 = local_arr[aux % 3];
    acc = (acc + mask_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001322_2213_6(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_82 = 0;
    for (int k = 0; k < 2; k++) {
        residue_82 = (residue_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_82) & 127;
    }
    int metric_76 = (aux + st.buffer[1]) & 3;
    switch (metric_76) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_80 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_80 > 21) {
        acc = (acc + phase_80 * 2 + 5) & 127;
        aux ^= (phase_80 & 15);
    } else {
        acc = (acc - phase_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_56 = 0;
    for (int k = 0; k < 2; k++) {
        delta_56 = (delta_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_56) & 127;
    }
    int parity_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001322_2213_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int damping_23 = (aux + st.buffer[1]) & 3;
    switch (damping_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_81 = local_arr[aux % 3];
    acc = (acc + vector_81 * 2) & 127;
    int scale_65 = 0;
    for (int k = 0; k < 3; k++) {
        scale_65 = (scale_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_65) & 127;
    }
    int residue_87 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_87 > 49) {
        acc = (acc + residue_87 * 2 + 5) & 127;
        aux ^= (residue_87 & 15);
    } else {
        acc = (acc - residue_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_34 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_34 > 39) {
        acc = (acc + segment_34 * 2 + 5) & 127;
        aux ^= (segment_34 & 15);
    } else {
        acc = (acc - segment_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int metric_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_69) & 63;
    acc ^= aux;
    int bound_43 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_43 > 31) {
        acc = (acc + bound_43 * 2 + 5) & 127;
        aux ^= (bound_43 & 15);
    } else {
        acc = (acc - bound_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_11(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int cursor_79 = (aux + st.buffer[1]) & 3;
    switch (cursor_79) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_69 = local_arr[aux % 3];
    acc = (acc + scale_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001322_2213_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int phase_10 = (aux + st.buffer[1]) & 3;
    switch (phase_10) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_42 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_42 > 44) {
        acc = (acc + parity_42 * 2 + 5) & 127;
        aux ^= (parity_42 & 15);
    } else {
        acc = (acc - parity_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_88 = local_arr[aux % 3];
    acc = (acc + index_reg_88 * 2) & 127;
    int weight_24 = (aux + st.buffer[1]) & 3;
    switch (weight_24) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_58 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_58 > 13) {
        acc = (acc + quantum_58 * 2 + 5) & 127;
        aux ^= (quantum_58 & 15);
    } else {
        acc = (acc - quantum_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_14(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_40 = 0;
    for (int k = 0; k < 3; k++) {
        bound_40 = (bound_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_15(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int scale_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_86) & 63;
    acc ^= aux;
    int index_reg_55 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_55 > 45) {
        acc = (acc + index_reg_55 * 2 + 5) & 127;
        aux ^= (index_reg_55 & 15);
    } else {
        acc = (acc - index_reg_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_16(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_95 = 0;
    for (int k = 0; k < 3; k++) {
        sample_95 = (sample_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_95) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_64 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_64 > 20) {
        acc = (acc + stride_64 * 2 + 5) & 127;
        aux ^= (stride_64 & 15);
    } else {
        acc = (acc - stride_64 + 11) & 127;
        aux += 3;
    }
    int factor_97 = (aux + st.buffer[1]) & 3;
    switch (factor_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_17(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int pivot_67 = (aux + st.buffer[1]) & 3;
    switch (pivot_67) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_43 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_43 = (threshold_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_43) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int window_31 = local_arr[aux % 3];
    acc = (acc + window_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001322_2213_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int checksum_35 = (aux + st.buffer[1]) & 3;
    switch (checksum_35) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_74 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_74 > 18) {
        acc = (acc + residue_74 * 2 + 5) & 127;
        aux ^= (residue_74 & 15);
    } else {
        acc = (acc - residue_74 + 11) & 127;
        aux += 3;
    }
    int stride_65 = 0;
    for (int k = 0; k < 2; k++) {
        stride_65 = (stride_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_65) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_83 = local_arr[aux % 3];
    acc = (acc + delta_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001322_2213_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int parity_44 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_44 > 48) {
        acc = (acc + parity_44 * 2 + 5) & 127;
        aux ^= (parity_44 & 15);
    } else {
        acc = (acc - parity_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_31 = local_arr[aux % 3];
    acc = (acc + metric_31 * 2) & 127;
    int delta_73 = (aux + st.buffer[1]) & 3;
    switch (delta_73) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_20(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001322_2213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int delta_14 = (aux + st.buffer[1]) & 3;
    switch (delta_14) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_31 = local_arr[aux % 3];
    acc = (acc + stride_31 * 2) & 127;
    int parity_65 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_65 > 49) {
        acc = (acc + parity_65 * 2 + 5) & 127;
        aux ^= (parity_65 & 15);
    } else {
        acc = (acc - parity_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001322_2213_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quotient_25 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_25 = (quotient_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_25) & 127;
    }
    int pivot_43 = (aux + st.buffer[1]) & 3;
    switch (pivot_43) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001322_2213_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int offset_95 = local_arr[aux % 3];
    acc = (acc + offset_95 * 2) & 127;
    int quotient_11 = (aux + st.buffer[1]) & 3;
    switch (quotient_11) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001322_2213_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001322_2213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int delta_12 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_12 > 48) {
        acc = (acc + delta_12 * 2 + 5) & 127;
        aux ^= (delta_12 & 15);
    } else {
        acc = (acc - delta_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_55 = local_arr[aux % 3];
    acc = (acc + mask_55 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001322_0;
    int sec_r001322_1;
    int sec_r001322_2;
    int sec_r001322_3;
    int sec_r001322_4;
    int sec_r001322_5;
    int sec_r001322_6;
    int sec_r001322_7;
    int sec_r001322_8;
    int sec_r001322_9;
    int sec_r001322_10;
    int sec_r001322_11;
    int sec_r001322_12;
    int sec_r001322_13;
    int sec_r001322_14;
    int sec_r001322_15;
    int sec_r001322_16;
    int sec_r001322_17;
    int sec_r001322_18;
    int sec_r001322_19;
    int sec_r001322_20;
    int sec_r001322_21;
    int pub_r001322_0;
    int pub_r001322_1;
    int pub_r001322_2;
    int pub_r001322_3;
    int pub_r001322_4;
    int pub_r001322_5;
    int pub_r001322_6;
    int pub_r001322_7;
    int pub_r001322_8;
    int pub_r001322_9;
    int pub_r001322_10;
    int pub_r001322_11;
    int pub_r001322_12;
    int pub_r001322_13;
    int pub_r001322_14;
    int pub_r001322_15;
    int pub_r001322_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001322_0 >= -100 && pub_r001322_0 <= 100);
    __CPROVER_assume(pub_r001322_1 >= -100 && pub_r001322_1 <= 100);
    __CPROVER_assume(pub_r001322_2 >= -100 && pub_r001322_2 <= 100);
    __CPROVER_assume(pub_r001322_3 >= -100 && pub_r001322_3 <= 100);
    __CPROVER_assume(pub_r001322_4 >= -100 && pub_r001322_4 <= 100);
    __CPROVER_assume(pub_r001322_5 >= -100 && pub_r001322_5 <= 100);
    __CPROVER_assume(pub_r001322_6 >= -100 && pub_r001322_6 <= 100);
    __CPROVER_assume(pub_r001322_7 >= -100 && pub_r001322_7 <= 100);
    __CPROVER_assume(pub_r001322_8 >= -100 && pub_r001322_8 <= 100);
    __CPROVER_assume(pub_r001322_9 >= -100 && pub_r001322_9 <= 100);
    __CPROVER_assume(pub_r001322_10 >= -100 && pub_r001322_10 <= 100);
    __CPROVER_assume(pub_r001322_11 >= -100 && pub_r001322_11 <= 100);
    __CPROVER_assume(pub_r001322_12 >= -100 && pub_r001322_12 <= 100);
    __CPROVER_assume(pub_r001322_13 >= -100 && pub_r001322_13 <= 100);
    __CPROVER_assume(pub_r001322_14 >= -100 && pub_r001322_14 <= 100);
    __CPROVER_assume(pub_r001322_15 >= -100 && pub_r001322_15 <= 100);
    __CPROVER_assume(pub_r001322_16 >= -100 && pub_r001322_16 <= 100);
    __CPROVER_assume(sec_r001322_0 >= 0 && sec_r001322_0 <= 255);
    __CPROVER_assume(sec_r001322_1 >= 0 && sec_r001322_1 <= 255);
    __CPROVER_assume(sec_r001322_2 >= 0 && sec_r001322_2 <= 255);
    __CPROVER_assume(sec_r001322_3 >= 0 && sec_r001322_3 <= 255);
    __CPROVER_assume(sec_r001322_4 >= 0 && sec_r001322_4 <= 255);
    __CPROVER_assume(sec_r001322_5 >= 0 && sec_r001322_5 <= 255);
    __CPROVER_assume(sec_r001322_6 >= 0 && sec_r001322_6 <= 255);
    __CPROVER_assume(sec_r001322_7 >= 0 && sec_r001322_7 <= 255);
    __CPROVER_assume(sec_r001322_8 >= 0 && sec_r001322_8 <= 255);
    __CPROVER_assume(sec_r001322_9 >= 0 && sec_r001322_9 <= 255);
    __CPROVER_assume(sec_r001322_10 >= 0 && sec_r001322_10 <= 255);
    __CPROVER_assume(sec_r001322_11 >= 0 && sec_r001322_11 <= 255);
    __CPROVER_assume(sec_r001322_12 >= 0 && sec_r001322_12 <= 255);
    __CPROVER_assume(sec_r001322_13 >= 0 && sec_r001322_13 <= 255);
    __CPROVER_assume(sec_r001322_14 >= 0 && sec_r001322_14 <= 255);
    __CPROVER_assume(sec_r001322_15 >= 0 && sec_r001322_15 <= 255);
    __CPROVER_assume(sec_r001322_16 >= 0 && sec_r001322_16 <= 255);
    __CPROVER_assume(sec_r001322_17 >= 0 && sec_r001322_17 <= 255);
    __CPROVER_assume(sec_r001322_18 >= 0 && sec_r001322_18 <= 255);
    __CPROVER_assume(sec_r001322_19 >= 0 && sec_r001322_19 <= 255);
    __CPROVER_assume(sec_r001322_20 >= 0 && sec_r001322_20 <= 255);
    __CPROVER_assume(sec_r001322_21 >= 0 && sec_r001322_21 <= 255);

    struct DeviceConfig_R001322_2213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001322_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001322_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001322_0 + 7) & 15;
    struct MatrixBlock_R001322_2213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001322_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001322_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001322_0 + 9) & 15;

    union RegisterBank_R001322_2213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001322_2213_0(sec_r001322_0, pub_r001322_1, pub_r001322_2, pub_r001322_3);
    int helper_flow_1 = fn_R001322_2213_1(sec_r001322_1, pub_r001322_2, pub_r001322_3, pub_r001322_4, pub_r001322_5);
    int helper_flow_2 = fn_R001322_2213_2(sec_r001322_2, pub_r001322_3, pub_r001322_4, pub_r001322_5);
    int helper_flow_3 = fn_R001322_2213_3(sec_r001322_3, sec_r001322_4, pub_r001322_5, pub_r001322_6, pub_r001322_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001322_12 * 3) + pub_r001322_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001322_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001322_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001322_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001322_16 * 3) + pub_r001322_4 + 13) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001322_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001322_12 * 3) + pub_r001322_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001322_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_1 * 3) + pub_r001322_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8 * 2) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001322_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001322_2 * 3) + pub_r001322_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001322_12 * 3) + pub_r001322_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_11) & 255;
    out_sink = (out_sink + stage_v_11 * 2) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001322_4 * 3) + pub_r001322_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001322_17 * 3) + pub_r001322_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001322_0 * 3) + pub_r001322_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_14) & 255;
    out_sink = (out_sink + stage_v_14 * 2) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001322_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001322_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001322_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001322_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001322_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001322_12 * 3) + pub_r001322_14 + 36) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_13 * 3) + pub_r001322_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21 * 2) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001322_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001322_21 * 3) + pub_r001322_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001322_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001322_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001322_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001322_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001322_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001322_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001322_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001322_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001322_3 * 3) + pub_r001322_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001322_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001322_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001322_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001322_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001322_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001322_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_4 * 3) + pub_r001322_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39 * 2) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001322_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001322_2 * 3) + pub_r001322_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001322_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001322_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001322_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001322_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((helper_flow_2 * 3) + pub_r001322_16 + 32) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46 * 2) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001322_12 * 3) + pub_r001322_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001322_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001322_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001322_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001322_13 * 3) + pub_r001322_1 + 26) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001322_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001322_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001322_5 * 3) + pub_r001322_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001322_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001322_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001322_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001322_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001322_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001322_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001322_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_46 * 3) + pub_r001322_15 + 27) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62 * 2) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001322_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001322_6 * 3) + pub_r001322_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001322_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001322_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001322_16 * 3) + pub_r001322_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67 * 2) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001322_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001322_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_67 * 3) + pub_r001322_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70 * 2) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_32 * 3) + pub_r001322_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001322_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001322_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001322_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001322_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001322_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001322_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001322_14 * 3) + pub_r001322_16 + 12) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_11 * 3) + pub_r001322_6 + 41) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79 * 2) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001322_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_51 * 3) + pub_r001322_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81 * 2) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001322_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_81 * 3) + pub_r001322_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001322_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001322_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001322_10 * 3) + pub_r001322_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001322_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001322_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001322_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001322_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001322_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001322_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001322_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001322_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001322_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001322_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001322_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_21 * 3) + pub_r001322_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001322_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001322_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001322_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001322_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001322_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001322_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001322_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_67 * 3) + pub_r001322_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001322_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001322_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001322_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r001322_16 * 3) + pub_r001322_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001322_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001322_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001322_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r001322_0 * 3) + pub_r001322_16 + 22) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114 * 2) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001322_13 * 3) + pub_r001322_16 + 42) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115 * 2) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_71 * 3) + pub_r001322_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001322_1 * 3) + pub_r001322_16 + 32) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117 * 2) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001322_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001322_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001322_20 * 3) + pub_r001322_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001322_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_11 * 3) + pub_r001322_13 + 10) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001322_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001322_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001322_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001322_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_14 * 3) + pub_r001322_2 + 33) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127 * 2) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001322_6 * 3) + pub_r001322_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001322_12 * 3) + pub_r001322_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001322_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001322_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001322_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001322_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001322_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_116 * 3) + pub_r001322_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001322_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001322_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001322_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001322_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001322_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001322_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001322_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001322_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001322_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001322_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_8 * 3) + pub_r001322_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r001322_9 * 3) + pub_r001322_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147 * 2) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_11 * 3) + pub_r001322_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001322_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_122 * 3) + pub_r001322_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001322_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_39 * 3) + pub_r001322_6 + 36) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001322_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_21 * 3) + pub_r001322_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001322_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001322_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001322_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_135 * 3) + pub_r001322_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158 * 2) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001322_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_62 * 3) + pub_r001322_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001322_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_39 * 3) + pub_r001322_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162 * 2) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001322_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001322_1 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001322_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001322_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_23 * 3) + pub_r001322_13 + 34) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167 * 2) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_147 * 3) + pub_r001322_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168 * 2) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001322_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((helper_flow_1 * 3) + pub_r001322_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((helper_flow_0 * 3) + pub_r001322_2 + 6) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001322_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r001322_6 * 3) + pub_r001322_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173 * 2) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001322_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_41 * 3) + pub_r001322_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_117 * 3) + pub_r001322_13 + 16) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001322_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001322_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((helper_flow_3 * 3) + pub_r001322_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001322_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001322_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001322_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001322_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001322_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001322_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_39 * 3) + pub_r001322_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186 * 2) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_154 * 3) + pub_r001322_4 + 40) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187 * 2) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001322_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001322_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001322_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((helper_flow_0 * 3) + pub_r001322_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001322_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001322_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_0 * 3) + pub_r001322_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_46 * 3) + pub_r001322_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((helper_flow_2 * 3) + pub_r001322_11 + 17) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001322_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_81 * 3) + pub_r001322_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198 * 2) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001322_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001322_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001322_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001322_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001322_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001322_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001322_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001322_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001322_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001322_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001322_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001322_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_148 * 3) + pub_r001322_0 + 43) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211 * 2) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001322_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_67 * 3) + pub_r001322_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001322_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001322_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001322_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001322_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((helper_flow_1 * 3) + pub_r001322_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_175 * 3) + pub_r001322_3 + 4) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219 * 2) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001322_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_160 * 3) + pub_r001322_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001322_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001322_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_195 * 3) + pub_r001322_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001322_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001322_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_13 * 3) + pub_r001322_16 + 29) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001322_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001322_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_67 * 3) + pub_r001322_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001322_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_127 * 3) + pub_r001322_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232 * 2) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_152 * 3) + pub_r001322_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001322_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_4 * 3) + pub_r001322_8 + 39) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_64 * 3) + pub_r001322_8 + 9) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001322_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_114 * 3) + pub_r001322_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238 * 2) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001322_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001322_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((helper_flow_3 * 3) + pub_r001322_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241 * 2) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_120 * 3) + pub_r001322_3 + 43) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242 * 2) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001322_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001322_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001322_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001322_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001322_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001322_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001322_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001322_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001322_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001322_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001322_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_219 * 3) + pub_r001322_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_167 * 3) + pub_r001322_0 + 19) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255 * 2) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001322_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001322_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001322_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001322_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001322_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_242 * 3) + pub_r001322_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001322_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001322_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001322_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001322_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_81 * 3) + pub_r001322_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266 * 2) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001322_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_122 * 3) + pub_r001322_3 + 20) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001322_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_4 * 3) + pub_r001322_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_71 * 3) + pub_r001322_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001322_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001322_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001322_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001322_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001322_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_191 * 3) + pub_r001322_13 + 45) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001322_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_168 * 3) + pub_r001322_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_213 * 3) + pub_r001322_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001322_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((helper_flow_2 * 3) + pub_r001322_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282 * 2) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001322_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_176 * 3) + pub_r001322_9 + 42) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001322_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001322_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_10 * 3) + pub_r001322_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287 * 2) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001322_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_8 * 3) + pub_r001322_11 + 30) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289 * 2) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001322_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001322_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_54 * 3) + pub_r001322_0 + 42) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001322_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r001322_20 * 3) + pub_r001322_16 + 4) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294 * 2) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_98 * 3) + pub_r001322_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001322_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001322_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001322_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_280 * 3) + pub_r001322_11 + 13) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299 * 2) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001322_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001322_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001322_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_150 * 3) + pub_r001322_4 + 5) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001322_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_21 * 3) + pub_r001322_14 + 44) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((sec_r001322_3 * 3) + pub_r001322_4 + 41) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306 * 2) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001322_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001322_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001322_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001322_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001322_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001322_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001322_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001322_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001322_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001322_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001322_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001322_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001322_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r001322_7 * 3) + pub_r001322_16 + 18) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001322_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001322_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001322_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_135 * 3) + pub_r001322_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324 * 2) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001322_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001322_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((sec_r001322_12 * 3) + pub_r001322_15 + 26) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((helper_flow_0 * 3) + pub_r001322_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_284 * 3) + pub_r001322_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329 * 2) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001322_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001322_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001322_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001322_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001322_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001322_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001322_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001322_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_11 * 3) + pub_r001322_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001322_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001322_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001322_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001322_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001322_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_221 * 3) + pub_r001322_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344 * 2) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_160 * 3) + pub_r001322_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_114 * 3) + pub_r001322_7 + 25) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001322_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001322_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001322_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_198 * 3) + pub_r001322_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001322_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001322_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001322_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001322_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001322_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001322_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_129 * 3) + pub_r001322_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357 * 2) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((helper_flow_3 * 3) + pub_r001322_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001322_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001322_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_280 * 3) + pub_r001322_16 + 45) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361 * 2) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001322_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001322_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001322_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001322_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001322_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_346 * 3) + pub_r001322_2 + 24) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001322_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001322_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_81 * 3) + pub_r001322_6 + 37) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001322_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_12 * 3) + pub_r001322_2 + 6) & 127;
    sec_accum = (sec_accum + stage_v_372) & 255;
    out_sink = (out_sink + stage_v_372 * 2) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001322_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_158 * 3) + pub_r001322_4 + 34) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001322_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001322_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001322_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001322_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001322_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_128 * 3) + pub_r001322_3 + 41) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380 * 2) & 255;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001322_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001322_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001322_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001322_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_79 * 3) + pub_r001322_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_385) & 255;
    out_sink = (out_sink + stage_v_385 * 2) & 255;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001322_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001322_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001322_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001322_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001322_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001322_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001322_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_21 * 3) + pub_r001322_10 + 4) & 127;
    sec_accum = (sec_accum + stage_v_393) & 255;
    out_sink = (out_sink + stage_v_393 * 2) & 255;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001322_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_289 * 3) + pub_r001322_0 + 10) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((sec_r001322_21 * 3) + pub_r001322_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001322_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001322_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001322_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001322_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001322_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001322_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_198 * 3) + pub_r001322_13 + 44) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001322_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001322_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001322_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001322_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001322_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001322_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001322_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001322_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001322_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001322_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001322_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001322_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((sec_r001322_9 * 3) + pub_r001322_1 + 35) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_79 * 3) + pub_r001322_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001322_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001322_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((sec_r001322_17 * 3) + pub_r001322_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_420) & 255;
    out_sink = (out_sink + stage_v_420 * 2) & 255;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001322_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_393 * 3) + pub_r001322_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_422) & 255;
    out_sink = (out_sink + stage_v_422 * 2) & 255;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001322_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_67 * 3) + pub_r001322_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_328 * 3) + pub_r001322_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001322_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_287 * 3) + pub_r001322_11 + 18) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001322_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001322_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((sec_r001322_16 * 3) + pub_r001322_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_430) & 255;
    out_sink = (out_sink + stage_v_430 * 2) & 255;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001322_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001322_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((sec_r001322_2 * 3) + pub_r001322_1 + 10) & 127;
    sec_accum = (sec_accum + stage_v_433) & 255;
    out_sink = (out_sink + stage_v_433 * 2) & 255;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_4 * 3) + pub_r001322_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001322_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_427 * 3) + pub_r001322_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001322_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001322_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001322_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_176 * 3) + pub_r001322_13 + 16) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001322_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001322_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_436 * 3) + pub_r001322_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_443) & 255;
    out_sink = (out_sink + stage_v_443 * 2) & 255;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_280 * 3) + pub_r001322_10 + 19) & 127;
    sec_accum = (sec_accum + stage_v_444) & 255;
    out_sink = (out_sink + stage_v_444 * 2) & 255;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001322_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001322_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001322_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_51 * 3) + pub_r001322_2 + 11) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001322_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001322_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_444 * 3) + pub_r001322_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_211 * 3) + pub_r001322_16 + 12) & 127;
    sec_accum = (sec_accum + stage_v_452) & 255;
    out_sink = (out_sink + stage_v_452 * 2) & 255;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001322_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((stage_v_345 * 3) + pub_r001322_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_454) & 255;
    out_sink = (out_sink + stage_v_454 * 2) & 255;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001322_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001322_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001322_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_395 * 3) + pub_r001322_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_458) & 255;
    out_sink = (out_sink + stage_v_458 * 2) & 255;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_170 * 3) + pub_r001322_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_459) & 255;
    out_sink = (out_sink + stage_v_459 * 2) & 255;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001322_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001322_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001322_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001322_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_54 * 3) + pub_r001322_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_464) & 255;
    out_sink = (out_sink + stage_v_464 * 2) & 255;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_160 * 3) + pub_r001322_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_465) & 255;
    out_sink = (out_sink + stage_v_465 * 2) & 255;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_433 * 3) + pub_r001322_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_466) & 255;
    out_sink = (out_sink + stage_v_466 * 2) & 255;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_227 * 3) + pub_r001322_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_467) & 255;
    out_sink = (out_sink + stage_v_467 * 2) & 255;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001322_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001322_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001322_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001322_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_13 * 3) + pub_r001322_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_472) & 255;
    out_sink = (out_sink + stage_v_472 * 2) & 255;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_150 * 3) + pub_r001322_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_473) & 255;
    out_sink = (out_sink + stage_v_473 * 2) & 255;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_173 * 3) + pub_r001322_4 + 37) & 127;
    sec_accum = (sec_accum + stage_v_474) & 255;
    out_sink = (out_sink + stage_v_474 * 2) & 255;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001322_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = ((stage_v_279 * 3) + pub_r001322_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_476) & 255;
    out_sink = (out_sink + stage_v_476 * 2) & 255;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001322_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001322_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001322_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001322_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001322_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001322_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001322_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = ((stage_v_292 * 3) + pub_r001322_15 + 9) & 127;
    sec_accum = (sec_accum + stage_v_484) & 255;
    out_sink = (out_sink + stage_v_484 * 2) & 255;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001322_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = ((stage_v_268 * 3) + pub_r001322_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_486) & 255;
    out_sink = (out_sink + stage_v_486 * 2) & 255;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001322_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = ((stage_v_127 * 3) + pub_r001322_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_488) & 255;
    out_sink = (out_sink + stage_v_488 * 2) & 255;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001322_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = ((stage_v_46 * 3) + pub_r001322_15 + 27) & 127;
    sec_accum = (sec_accum + stage_v_490) & 255;
    out_sink = (out_sink + stage_v_490 * 2) & 255;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001322_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001322_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_196 * 3) + pub_r001322_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_493) & 255;
    out_sink = (out_sink + stage_v_493 * 2) & 255;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001322_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001322_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001322_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = ((stage_v_81 * 3) + pub_r001322_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_497) & 255;
    out_sink = (out_sink + stage_v_497 * 2) & 255;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = ((stage_v_459 * 3) + pub_r001322_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_498) & 255;
    out_sink = (out_sink + stage_v_498 * 2) & 255;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = ((sec_r001322_11 * 3) + pub_r001322_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_499) & 255;
    out_sink = (out_sink + stage_v_499 * 2) & 255;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001322_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = ((sec_r001322_0 * 3) + pub_r001322_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_501) & 255;
    out_sink = (out_sink + stage_v_501 * 2) & 255;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001322_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001322_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = (pub_r001322_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_504) & 127;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001322_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001322_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = ((stage_v_486 * 3) + pub_r001322_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_507) & 255;
    out_sink = (out_sink + stage_v_507 * 2) & 255;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = ((stage_v_270 * 3) + pub_r001322_8 + 43) & 127;
    sec_accum = (sec_accum + stage_v_508) & 255;
    out_sink = (out_sink + stage_v_508 * 2) & 255;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = ((stage_v_187 * 3) + pub_r001322_2 + 39) & 127;
    sec_accum = (sec_accum + stage_v_509) & 255;
    out_sink = (out_sink + stage_v_509 * 2) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
