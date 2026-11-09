/*
 * Benchmark Program: R001270
 * Security Family: mixed_control_data
 * Generator Seed: 627013
 * High Inputs: 19 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001270_7013_0 {
    int counter;
    int flags;
    int tag;
    int buffer[3];
};

struct SensorNode_R001270_7013_1 {
    unsigned char offset;
    int calib;
    int status;
    int threshold;
    int buffer[3];
};

union ColorPixel_R001270_7013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001270_7013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001270_7013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int cursor_88 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_88 = (cursor_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_88) & 127;
    }
    int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_17 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_17 > 34) {
        acc = (acc + delta_17 * 2 + 5) & 127;
        aux ^= (delta_17 & 15);
    } else {
        acc = (acc - delta_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_1(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_78 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_78 > 10) {
        acc = (acc + delta_78 * 2 + 5) & 127;
        aux ^= (delta_78 & 15);
    } else {
        acc = (acc - delta_78 + 11) & 127;
        aux += 3;
    }
    int quotient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001270_7013_2(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_42 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_42 > 41) {
        acc = (acc + mask_42 * 2 + 5) & 127;
        aux ^= (mask_42 & 15);
    } else {
        acc = (acc - mask_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int segment_74 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_74 > 36) {
        acc = (acc + segment_74 * 2 + 5) & 127;
        aux ^= (segment_74 & 15);
    } else {
        acc = (acc - segment_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_44 = local_arr[aux % 3];
    acc = (acc + sample_44 * 2) & 127;
    int coefficient_82 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_82 = (coefficient_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_82 = 0;
    for (int k = 0; k < 2; k++) {
        vector_82 = (vector_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_5(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_28) & 63;
    acc ^= aux;
    int margin_98 = 0;
    for (int k = 0; k < 3; k++) {
        margin_98 = (margin_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_98) & 127;
    }
    int metric_96 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_96 > 10) {
        acc = (acc + metric_96 * 2 + 5) & 127;
        aux ^= (metric_96 & 15);
    } else {
        acc = (acc - metric_96 + 11) & 127;
        aux += 3;
    }
    int offset_49 = (aux + st.buffer[1]) & 3;
    switch (offset_49) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int threshold_54 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_54 = (threshold_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_54) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_77) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001270_7013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int pivot_47 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_47 > 18) {
        acc = (acc + pivot_47 * 2 + 5) & 127;
        aux ^= (pivot_47 & 15);
    } else {
        acc = (acc - pivot_47 + 11) & 127;
        aux += 3;
    }
    int coefficient_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001270_7013_8(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int residue_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_45) & 63;
    acc ^= aux;
    int factor_94 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_94 > 21) {
        acc = (acc + factor_94 * 2 + 5) & 127;
        aux ^= (factor_94 & 15);
    } else {
        acc = (acc - factor_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int sample_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_75 = local_arr[aux % 3];
    acc = (acc + segment_75 * 2) & 127;
    int pivot_14 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_14 = (pivot_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int phase_21 = local_arr[aux % 3];
    acc = (acc + phase_21 * 2) & 127;
    int offset_17 = (aux + st.buffer[1]) & 3;
    switch (offset_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_64 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_64 > 13) {
        acc = (acc + weight_64 * 2 + 5) & 127;
        aux ^= (weight_64 & 15);
    } else {
        acc = (acc - weight_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001270_7013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int factor_88 = 0;
    for (int k = 0; k < 3; k++) {
        factor_88 = (factor_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_88) & 127;
    }
    int bound_82 = (aux + st.buffer[1]) & 3;
    switch (bound_82) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int factor_24 = (aux + st.buffer[1]) & 3;
    switch (factor_24) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_69 = 0;
    for (int k = 0; k < 3; k++) {
        metric_69 = (metric_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_69) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_58 = local_arr[aux % 3];
    acc = (acc + threshold_58 * 2) & 127;
    int segment_81 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_81 > 11) {
        acc = (acc + segment_81 * 2 + 5) & 127;
        aux ^= (segment_81 & 15);
    } else {
        acc = (acc - segment_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int coefficient_96 = local_arr[aux % 3];
    acc = (acc + coefficient_96 * 2) & 127;
    int pivot_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_86) & 63;
    acc ^= aux;
    int segment_51 = 0;
    for (int k = 0; k < 2; k++) {
        segment_51 = (segment_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int checksum_69 = (aux + st.buffer[1]) & 3;
    switch (checksum_69) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001270_7013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_80 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_80 > 39) {
        acc = (acc + parity_80 * 2 + 5) & 127;
        aux ^= (parity_80 & 15);
    } else {
        acc = (acc - parity_80 + 11) & 127;
        aux += 3;
    }
    int index_reg_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001270_7013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int damping_18 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_18 > 30) {
        acc = (acc + damping_18 * 2 + 5) & 127;
        aux ^= (damping_18 & 15);
    } else {
        acc = (acc - damping_18 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001270_7013_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001270_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_21 = (aux + st.buffer[1]) & 3;
    switch (margin_21) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_46 = local_arr[aux % 3];
    acc = (acc + quantum_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001270_7013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tally_87 = (aux + st.buffer[1]) & 3;
    switch (tally_87) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_45) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_25 = local_arr[aux % 3];
    acc = (acc + cursor_25 * 2) & 127;
    int segment_96 = 0;
    for (int k = 0; k < 3; k++) {
        segment_96 = (segment_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_96) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001270_7013_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001270_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int segment_98 = (aux + st.buffer[1]) & 3;
    switch (segment_98) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001270_0;
    int sec_r001270_1;
    int sec_r001270_2;
    int sec_r001270_3;
    int sec_r001270_4;
    int sec_r001270_5;
    int sec_r001270_6;
    int sec_r001270_7;
    int sec_r001270_8;
    int sec_r001270_9;
    int sec_r001270_10;
    int sec_r001270_11;
    int sec_r001270_12;
    int sec_r001270_13;
    int sec_r001270_14;
    int sec_r001270_15;
    int sec_r001270_16;
    int sec_r001270_17;
    int sec_r001270_18;
    int pub_r001270_0;
    int pub_r001270_1;
    int pub_r001270_2;
    int pub_r001270_3;
    int pub_r001270_4;
    int pub_r001270_5;
    int pub_r001270_6;
    int pub_r001270_7;
    int pub_r001270_8;
    int pub_r001270_9;
    int pub_r001270_10;
    int pub_r001270_11;
    int pub_r001270_12;
    int pub_r001270_13;
    int pub_r001270_14;
    int pub_r001270_15;
    int pub_r001270_16;
    int pub_r001270_17;
    int pub_r001270_18;
    int pub_r001270_19;
    int pub_r001270_20;
    int pub_r001270_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001270_0 >= -100 && pub_r001270_0 <= 100);
    __CPROVER_assume(pub_r001270_1 >= -100 && pub_r001270_1 <= 100);
    __CPROVER_assume(pub_r001270_2 >= -100 && pub_r001270_2 <= 100);
    __CPROVER_assume(pub_r001270_3 >= -100 && pub_r001270_3 <= 100);
    __CPROVER_assume(pub_r001270_4 >= -100 && pub_r001270_4 <= 100);
    __CPROVER_assume(pub_r001270_5 >= -100 && pub_r001270_5 <= 100);
    __CPROVER_assume(pub_r001270_6 >= -100 && pub_r001270_6 <= 100);
    __CPROVER_assume(pub_r001270_7 >= -100 && pub_r001270_7 <= 100);
    __CPROVER_assume(pub_r001270_8 >= -100 && pub_r001270_8 <= 100);
    __CPROVER_assume(pub_r001270_9 >= -100 && pub_r001270_9 <= 100);
    __CPROVER_assume(pub_r001270_10 >= -100 && pub_r001270_10 <= 100);
    __CPROVER_assume(pub_r001270_11 >= -100 && pub_r001270_11 <= 100);
    __CPROVER_assume(pub_r001270_12 >= -100 && pub_r001270_12 <= 100);
    __CPROVER_assume(pub_r001270_13 >= -100 && pub_r001270_13 <= 100);
    __CPROVER_assume(pub_r001270_14 >= -100 && pub_r001270_14 <= 100);
    __CPROVER_assume(pub_r001270_15 >= -100 && pub_r001270_15 <= 100);
    __CPROVER_assume(pub_r001270_16 >= -100 && pub_r001270_16 <= 100);
    __CPROVER_assume(pub_r001270_17 >= -100 && pub_r001270_17 <= 100);
    __CPROVER_assume(pub_r001270_18 >= -100 && pub_r001270_18 <= 100);
    __CPROVER_assume(pub_r001270_19 >= -100 && pub_r001270_19 <= 100);
    __CPROVER_assume(pub_r001270_20 >= -100 && pub_r001270_20 <= 100);
    __CPROVER_assume(pub_r001270_21 >= -100 && pub_r001270_21 <= 100);
    __CPROVER_assume(sec_r001270_0 >= 0 && sec_r001270_0 <= 255);
    __CPROVER_assume(sec_r001270_1 >= 0 && sec_r001270_1 <= 255);
    __CPROVER_assume(sec_r001270_2 >= 0 && sec_r001270_2 <= 255);
    __CPROVER_assume(sec_r001270_3 >= 0 && sec_r001270_3 <= 255);
    __CPROVER_assume(sec_r001270_4 >= 0 && sec_r001270_4 <= 255);
    __CPROVER_assume(sec_r001270_5 >= 0 && sec_r001270_5 <= 255);
    __CPROVER_assume(sec_r001270_6 >= 0 && sec_r001270_6 <= 255);
    __CPROVER_assume(sec_r001270_7 >= 0 && sec_r001270_7 <= 255);
    __CPROVER_assume(sec_r001270_8 >= 0 && sec_r001270_8 <= 255);
    __CPROVER_assume(sec_r001270_9 >= 0 && sec_r001270_9 <= 255);
    __CPROVER_assume(sec_r001270_10 >= 0 && sec_r001270_10 <= 255);
    __CPROVER_assume(sec_r001270_11 >= 0 && sec_r001270_11 <= 255);
    __CPROVER_assume(sec_r001270_12 >= 0 && sec_r001270_12 <= 255);
    __CPROVER_assume(sec_r001270_13 >= 0 && sec_r001270_13 <= 255);
    __CPROVER_assume(sec_r001270_14 >= 0 && sec_r001270_14 <= 255);
    __CPROVER_assume(sec_r001270_15 >= 0 && sec_r001270_15 <= 255);
    __CPROVER_assume(sec_r001270_16 >= 0 && sec_r001270_16 <= 255);
    __CPROVER_assume(sec_r001270_17 >= 0 && sec_r001270_17 <= 255);
    __CPROVER_assume(sec_r001270_18 >= 0 && sec_r001270_18 <= 255);

    struct CipherContext_R001270_7013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001270_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001270_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001270_0 + 7) & 15;
    struct SensorNode_R001270_7013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001270_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001270_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001270_0 + 9) & 15;

    union ColorPixel_R001270_7013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001270_7013_0(sec_r001270_0, sec_r001270_1, pub_r001270_2, pub_r001270_3);
    int helper_flow_1 = fn_R001270_7013_1(sec_r001270_1, sec_r001270_2, pub_r001270_3);
    int helper_flow_2 = fn_R001270_7013_2(sec_r001270_2, sec_r001270_3, pub_r001270_4);
    int helper_flow_3 = fn_R001270_7013_3(sec_r001270_3, sec_r001270_4, pub_r001270_5, pub_r001270_6, pub_r001270_7);
    int helper_flow_4 = fn_R001270_7013_4(sec_r001270_4, pub_r001270_5, pub_r001270_6, pub_r001270_7);
    int helper_flow_5 = fn_R001270_7013_5(sec_r001270_5, sec_r001270_6);
    int helper_flow_6 = fn_R001270_7013_6(sec_r001270_6, pub_r001270_7, pub_r001270_8, pub_r001270_9, pub_r001270_10);
    int helper_flow_7 = fn_R001270_7013_7(sec_r001270_7, pub_r001270_8, pub_r001270_9, pub_r001270_10, pub_r001270_11);
    int helper_flow_8 = fn_R001270_7013_8(sec_r001270_8, pub_r001270_9);
    int helper_flow_9 = fn_R001270_7013_9(sec_r001270_9, sec_r001270_10, pub_r001270_11, pub_r001270_12);
    int helper_flow_10 = fn_R001270_7013_10(sec_r001270_10, sec_r001270_11, pub_r001270_12, pub_r001270_13, pub_r001270_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001270_15 ^ 0x2A) * 2 + pub_r001270_2) & 127;
    if (stage_v_0 > 38) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001270_14 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_1 > 25) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001270_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001270_4) & 127;
    if (stage_v_3 > 43) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001270_20 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001270_8 ^ 0x2A) * 2 + pub_r001270_7) & 127;
    if (stage_v_5 > 26) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001270_7 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_6 > 48) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001270_18 ^ 0x2A) * 2 + pub_r001270_20) & 127;
    if (stage_v_7 > 50) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001270_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_9 > 27) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001270_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001270_15 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_11 > 28) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001270_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_13 > 34) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001270_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001270_1 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_15 > 47) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001270_11) & 127;
    if (stage_v_16 > 40) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_17 > 25) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001270_2 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_18 > 42) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_19 > 45) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001270_11 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_20 > 21) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001270_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_22 > 43) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_23 > 20) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_24 > 45) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001270_1) & 127;
    if (stage_v_25 > 26) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_26 > 22) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_27 > 43) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_28 > 49) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001270_19) & 127;
    if (stage_v_29 > 50) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001270_11 ^ 0x2A) * 2 + pub_r001270_5) & 127;
    if (stage_v_30 > 28) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001270_18 ^ 0x2A) * 2 + pub_r001270_7) & 127;
    if (stage_v_31 > 36) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001270_5) & 127;
    if (stage_v_32 > 31) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_33 > 28) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001270_2 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_34 > 22) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_35 > 48) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_36 > 29) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_37 > 24) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001270_16 ^ 0x2A) * 2 + pub_r001270_7) & 127;
    if (stage_v_38 > 49) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_39 > 20) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001270_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001270_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_42 > 34) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001270_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001270_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_45 > 35) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001270_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001270_11) & 127;
    if (stage_v_47 > 26) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001270_19) & 127;
    if (stage_v_48 > 31) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001270_12) & 127;
    if (stage_v_49 > 28) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001270_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001270_5) & 127;
    if (stage_v_51 > 50) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001270_10 ^ 0x2A) * 2 + pub_r001270_20) & 127;
    if (stage_v_52 > 26) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001270_4) & 127;
    if (stage_v_53 > 38) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001270_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001270_2) & 127;
    if (stage_v_55 > 31) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001270_12 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_56 > 50) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_57 > 44) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001270_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001270_1) & 127;
    if (stage_v_59 > 43) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_60 > 49) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001270_12 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_61 > 22) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_62 > 25) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001270_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001270_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_65 > 33) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001270_5 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_66 > 36) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_67 > 39) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_68 > 38) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001270_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001270_1 ^ 0x2A) * 2 + pub_r001270_5) & 127;
    if (stage_v_70 > 45) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001270_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001270_14) & 127;
    if (stage_v_72 > 35) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001270_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_74 > 41) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_75 > 27) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_76 > 23) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001270_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001270_2) & 127;
    if (stage_v_78 > 28) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001270_21 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001270_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001270_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001270_9 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_82 > 39) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001270_10) & 127;
    if (stage_v_83 > 40) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001270_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_85 > 29) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_86 > 41) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001270_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001270_10 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_88 > 27) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_89 > 34) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_90 > 50) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001270_7 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_91 > 49) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001270_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_93 > 26) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_94 > 42) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001270_14) & 127;
    if (stage_v_95 > 36) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001270_21 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001270_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001270_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001270_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001270_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001270_4 ^ 0x2A) * 2 + pub_r001270_20) & 127;
    if (stage_v_101 > 48) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001270_12) & 127;
    if (stage_v_102 > 46) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_103 > 43) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001270_11) & 127;
    if (stage_v_104 > 32) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_105 > 50) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001270_20) & 127;
    if (stage_v_106 > 33) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001270_10) & 127;
    if (stage_v_107 > 33) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001270_10) & 127;
    if (stage_v_108 > 21) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_109 > 20) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_110 > 28) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_111 > 31) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001270_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001270_20) & 127;
    if (stage_v_113 > 29) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_114 > 21) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001270_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001270_12) & 127;
    if (stage_v_116 > 50) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001270_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_118 > 43) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_119 > 24) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001270_12) & 127;
    if (stage_v_120 > 20) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_121 > 36) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001270_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_123 > 36) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_124 > 35) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_125 > 28) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_126 > 41) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_127 > 28) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_128 > 35) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001270_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001270_17 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_130 > 29) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_131 > 41) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001270_5 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_132 > 42) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001270_20 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001270_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001270_5) & 127;
    if (stage_v_135 > 29) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_136 > 28) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001270_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001270_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001270_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_140 > 23) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_141 > 25) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_142 > 22) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001270_7) & 127;
    if (stage_v_143 > 21) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001270_14) & 127;
    if (stage_v_144 > 31) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001270_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001270_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001270_12) & 127;
    if (stage_v_147 > 30) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001270_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_149 > 42) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001270_11 ^ 0x2A) * 2 + pub_r001270_7) & 127;
    if (stage_v_150 > 46) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_151 > 46) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_152 > 24) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001270_12) & 127;
    if (stage_v_153 > 30) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001270_9 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_154 > 29) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_155 > 33) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001270_7) & 127;
    if (stage_v_156 > 21) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_157 > 36) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001270_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001270_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001270_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001270_7) & 127;
    if (stage_v_161 > 33) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_162 > 39) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_163 > 36) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001270_19) & 127;
    if (stage_v_164 > 35) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001270_20) & 127;
    if (stage_v_165 > 50) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_166 > 21) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_167 > 38) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_168 > 41) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_169 > 28) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001270_16) & 127;
    if (stage_v_170 > 30) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_171 > 26) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001270_21 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001270_20 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_174 > 22) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001270_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001270_21 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_177 > 37) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_178 > 33) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_179 > 23) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001270_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001270_2) & 127;
    if (stage_v_181 > 40) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001270_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001270_2) & 127;
    if (stage_v_183 > 49) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001270_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001270_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001270_21 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001270_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r001270_8 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_188 > 44) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001270_2 ^ 0x2A) * 2 + pub_r001270_10) & 127;
    if (stage_v_189 > 33) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001270_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_191 > 38) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001270_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001270_18 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_193 > 23) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_194 > 43) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001270_11) & 127;
    if (stage_v_195 > 41) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_196 > 24) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_197 > 28) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_198 > 27) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_197 ^ 0x2A) * 2 + pub_r001270_10) & 127;
    if (stage_v_199 > 33) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001270_19) & 127;
    if (stage_v_200 > 29) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001270_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_202 > 34) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_203 > 20) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001270_14) & 127;
    if (stage_v_204 > 24) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001270_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r001270_7 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_206 > 49) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r001270_4 ^ 0x2A) * 2 + pub_r001270_9) & 127;
    if (stage_v_207 > 35) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001270_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001270_8) & 127;
    if (stage_v_209 > 46) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_210 > 24) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001270_15) & 127;
    if (stage_v_211 > 29) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_212 > 34) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_213 > 46) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001270_18) & 127;
    if (stage_v_214 > 33) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_215 > 32) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_216 > 33) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001270_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001270_2) & 127;
    if (stage_v_218 > 34) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001270_19) & 127;
    if (stage_v_219 > 39) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_220 > 26) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001270_17) & 127;
    if (stage_v_221 > 35) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r001270_4 ^ 0x2A) * 2 + pub_r001270_0) & 127;
    if (stage_v_222 > 33) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001270_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001270_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001270_6) & 127;
    if (stage_v_225 > 23) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001270_21 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001270_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001270_3) & 127;
    if (stage_v_228 > 38) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r001270_18 ^ 0x2A) * 2 + pub_r001270_21) & 127;
    if (stage_v_229 > 27) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001270_13) & 127;
    if (stage_v_230 > 41) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001270_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
