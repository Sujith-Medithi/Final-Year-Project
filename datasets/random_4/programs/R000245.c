/*
 * Benchmark Program: R000245
 * Family: multi_step_explicit
 * Generator Seed: 424513
 * High Inputs: 19 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000245_4513_0 {
    int round_key;
    int counter;
    short tag;
    short iv;
    int buffer[3];
};

struct SensorNode_R000245_4513_1 {
    short gain;
    short reading;
    unsigned char threshold;
    int calib;
    int status;
    int offset;
    int buffer[3];
};

struct Transaction_R000245_4513_2 {
    int status;
    short rate;
    int auth_code;
    unsigned char fee;
    unsigned char balance;
    int buffer[3];
};

struct StreamBuffer_R000245_4513_3 {
    unsigned char watermark;
    unsigned char head;
    short tail;
    int capacity;
    int checksum;
    int buffer[3];
};

union TelemetryField_R000245_4513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000245_4513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000245_4513_0(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000245_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int coefficient_23 = local_arr[aux % 3];
    acc = (acc + coefficient_23 * 2) & 127;
    int mask_99 = 0;
    for (int k = 0; k < 3; k++) {
        mask_99 = (mask_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_99) & 127;
    }
    int delta_60 = (aux + st.buffer[1]) & 3;
    switch (delta_60) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_11 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_11 > 37) {
        acc = (acc + scale_11 * 2 + 5) & 127;
        aux ^= (scale_11 & 15);
    } else {
        acc = (acc - scale_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_83 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_83 = (quantum_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_83) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000245_4513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int delta_48 = 0;
    for (int k = 0; k < 3; k++) {
        delta_48 = (delta_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_48) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_44 = local_arr[aux % 3];
    acc = (acc + vector_44 * 2) & 127;
    int bound_88 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_88 > 22) {
        acc = (acc + bound_88 * 2 + 5) & 127;
        aux ^= (bound_88 & 15);
    } else {
        acc = (acc - bound_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int window_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_13) & 63;
    acc ^= aux;
    int checksum_98 = (aux + st.buffer[1]) & 3;
    switch (checksum_98) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int parity_94 = local_arr[aux % 3];
    acc = (acc + parity_94 * 2) & 127;
    int segment_61 = 0;
    for (int k = 0; k < 3; k++) {
        segment_61 = (segment_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_61) & 127;
    }
    int window_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_99) & 63;
    acc ^= aux;
    int delta_52 = (aux + st.buffer[1]) & 3;
    switch (delta_52) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_5(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000245_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int coefficient_80 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_80 > 16) {
        acc = (acc + coefficient_80 * 2 + 5) & 127;
        aux ^= (coefficient_80 & 15);
    } else {
        acc = (acc - coefficient_80 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000245_4513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000245_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_29 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_29 > 16) {
        acc = (acc + mask_29 * 2 + 5) & 127;
        aux ^= (mask_29 & 15);
    } else {
        acc = (acc - mask_29 + 11) & 127;
        aux += 3;
    }
    int tally_91 = 0;
    for (int k = 0; k < 3; k++) {
        tally_91 = (tally_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_7(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000245_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int metric_29 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_29 > 15) {
        acc = (acc + metric_29 * 2 + 5) & 127;
        aux ^= (metric_29 & 15);
    } else {
        acc = (acc - metric_29 + 11) & 127;
        aux += 3;
    }
    int residue_16 = (aux + st.buffer[1]) & 3;
    switch (residue_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_57 = 0;
    for (int k = 0; k < 3; k++) {
        phase_57 = (phase_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_57) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000245_4513_8(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_97 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_97 = (anchor_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_97) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_23 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_23 > 18) {
        acc = (acc + mask_23 * 2 + 5) & 127;
        aux ^= (mask_23 & 15);
    } else {
        acc = (acc - mask_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_9(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int bound_62 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_62 > 48) {
        acc = (acc + bound_62 * 2 + 5) & 127;
        aux ^= (bound_62 & 15);
    } else {
        acc = (acc - bound_62 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_47 = local_arr[aux % 3];
    acc = (acc + factor_47 * 2) & 127;
    int tracker_28 = (aux + st.buffer[1]) & 3;
    switch (tracker_28) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_97 = (aux + st.buffer[1]) & 3;
    switch (cursor_97) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_37 = 0;
    for (int k = 0; k < 3; k++) {
        scale_37 = (scale_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_37) & 127;
    }
    int parity_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000245_4513_11(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000245_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int index_reg_48 = (aux + st.buffer[1]) & 3;
    switch (index_reg_48) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_23 = 0;
    for (int k = 0; k < 3; k++) {
        factor_23 = (factor_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_12(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int residue_94 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_94 > 46) {
        acc = (acc + residue_94 * 2 + 5) & 127;
        aux ^= (residue_94 & 15);
    } else {
        acc = (acc - residue_94 + 11) & 127;
        aux += 3;
    }
    int bound_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000245_4513_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000245_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int segment_73 = local_arr[aux % 3];
    acc = (acc + segment_73 * 2) & 127;
    int quotient_16 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_16 > 46) {
        acc = (acc + quotient_16 * 2 + 5) & 127;
        aux ^= (quotient_16 & 15);
    } else {
        acc = (acc - quotient_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000245_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int residue_47 = local_arr[aux % 3];
    acc = (acc + residue_47 * 2) & 127;
    int tracker_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000245_4513_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000245_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int scale_86 = local_arr[aux % 3];
    acc = (acc + scale_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000245_4513_16(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000245_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_81) & 63;
    acc ^= aux;
    int metric_90 = (aux + st.buffer[1]) & 3;
    switch (metric_90) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_18 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_18 = (anchor_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_18) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_17(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000245_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int segment_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_43) & 63;
    acc ^= aux;
    int sample_16 = (aux + st.buffer[1]) & 3;
    switch (sample_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000245_4513_18(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000245_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_49) & 63;
    acc ^= aux;
    int weight_53 = 0;
    for (int k = 0; k < 3; k++) {
        weight_53 = (weight_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_53) & 127;
    }
    int scale_32 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_32 > 46) {
        acc = (acc + scale_32 * 2 + 5) & 127;
        aux ^= (scale_32 & 15);
    } else {
        acc = (acc - scale_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000245_0;
    int sec_r000245_1;
    int sec_r000245_2;
    int sec_r000245_3;
    int sec_r000245_4;
    int sec_r000245_5;
    int sec_r000245_6;
    int sec_r000245_7;
    int sec_r000245_8;
    int sec_r000245_9;
    int sec_r000245_10;
    int sec_r000245_11;
    int sec_r000245_12;
    int sec_r000245_13;
    int sec_r000245_14;
    int sec_r000245_15;
    int sec_r000245_16;
    int sec_r000245_17;
    int sec_r000245_18;
    int pub_r000245_0;
    int pub_r000245_1;
    int pub_r000245_2;
    int pub_r000245_3;
    int pub_r000245_4;
    int pub_r000245_5;
    int pub_r000245_6;
    int pub_r000245_7;
    int pub_r000245_8;
    int pub_r000245_9;
    int pub_r000245_10;
    int pub_r000245_11;
    int pub_r000245_12;
    int pub_r000245_13;
    int pub_r000245_14;
    int pub_r000245_15;
    int pub_r000245_16;
    int pub_r000245_17;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000245_0 >= -100 && pub_r000245_0 <= 100);
    __CPROVER_assume(pub_r000245_1 >= -100 && pub_r000245_1 <= 100);
    __CPROVER_assume(pub_r000245_2 >= -100 && pub_r000245_2 <= 100);
    __CPROVER_assume(pub_r000245_3 >= -100 && pub_r000245_3 <= 100);
    __CPROVER_assume(pub_r000245_4 >= -100 && pub_r000245_4 <= 100);
    __CPROVER_assume(pub_r000245_5 >= -100 && pub_r000245_5 <= 100);
    __CPROVER_assume(pub_r000245_6 >= -100 && pub_r000245_6 <= 100);
    __CPROVER_assume(pub_r000245_7 >= -100 && pub_r000245_7 <= 100);
    __CPROVER_assume(pub_r000245_8 >= -100 && pub_r000245_8 <= 100);
    __CPROVER_assume(pub_r000245_9 >= -100 && pub_r000245_9 <= 100);
    __CPROVER_assume(pub_r000245_10 >= -100 && pub_r000245_10 <= 100);
    __CPROVER_assume(pub_r000245_11 >= -100 && pub_r000245_11 <= 100);
    __CPROVER_assume(pub_r000245_12 >= -100 && pub_r000245_12 <= 100);
    __CPROVER_assume(pub_r000245_13 >= -100 && pub_r000245_13 <= 100);
    __CPROVER_assume(pub_r000245_14 >= -100 && pub_r000245_14 <= 100);
    __CPROVER_assume(pub_r000245_15 >= -100 && pub_r000245_15 <= 100);
    __CPROVER_assume(pub_r000245_16 >= -100 && pub_r000245_16 <= 100);
    __CPROVER_assume(pub_r000245_17 >= -100 && pub_r000245_17 <= 100);
    __CPROVER_assume(sec_r000245_0 >= 0 && sec_r000245_0 <= 255);
    __CPROVER_assume(sec_r000245_1 >= 0 && sec_r000245_1 <= 255);
    __CPROVER_assume(sec_r000245_2 >= 0 && sec_r000245_2 <= 255);
    __CPROVER_assume(sec_r000245_3 >= 0 && sec_r000245_3 <= 255);
    __CPROVER_assume(sec_r000245_4 >= 0 && sec_r000245_4 <= 255);
    __CPROVER_assume(sec_r000245_5 >= 0 && sec_r000245_5 <= 255);
    __CPROVER_assume(sec_r000245_6 >= 0 && sec_r000245_6 <= 255);
    __CPROVER_assume(sec_r000245_7 >= 0 && sec_r000245_7 <= 255);
    __CPROVER_assume(sec_r000245_8 >= 0 && sec_r000245_8 <= 255);
    __CPROVER_assume(sec_r000245_9 >= 0 && sec_r000245_9 <= 255);
    __CPROVER_assume(sec_r000245_10 >= 0 && sec_r000245_10 <= 255);
    __CPROVER_assume(sec_r000245_11 >= 0 && sec_r000245_11 <= 255);
    __CPROVER_assume(sec_r000245_12 >= 0 && sec_r000245_12 <= 255);
    __CPROVER_assume(sec_r000245_13 >= 0 && sec_r000245_13 <= 255);
    __CPROVER_assume(sec_r000245_14 >= 0 && sec_r000245_14 <= 255);
    __CPROVER_assume(sec_r000245_15 >= 0 && sec_r000245_15 <= 255);
    __CPROVER_assume(sec_r000245_16 >= 0 && sec_r000245_16 <= 255);
    __CPROVER_assume(sec_r000245_17 >= 0 && sec_r000245_17 <= 255);
    __CPROVER_assume(sec_r000245_18 >= 0 && sec_r000245_18 <= 255);

    struct CipherContext_R000245_4513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000245_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000245_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000245_0 + 7) & 15;
    struct SensorNode_R000245_4513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000245_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000245_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000245_0 + 9) & 15;
    struct Transaction_R000245_4513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000245_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000245_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000245_0 + 11) & 15;
    struct StreamBuffer_R000245_4513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000245_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000245_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000245_0 + 13) & 15;

    union TelemetryField_R000245_4513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 28) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 43) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 31) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 46) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_17 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 13) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 28) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 15) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 30) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

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
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 29) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 44) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 10) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 25) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 36) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 51) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 39) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 54) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 17) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 32) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 32) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 47) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 12) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 27) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_3.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 32) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 47) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_2.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_91 = (stage_v_91 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_0.buffer[0] ^ 95) & 3;
    switch (stage_v_92) {
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

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 11) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 26) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_94 = (stage_v_94 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = table[3];
    table[3] = (table[0] + 191) & 63;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (out_sink > 100) ? (chk_sum & 31) : (101 & 31);
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= (stage_v_96 << 1) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = table[0];
    table[0] = (table[1] + 201) & 63;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 102) & 15;
    int stage_v_101 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= stage_v_101;

    /* Execution Pipeline Stage 102 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 103) & 15;
    int stage_v_102 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= stage_v_102;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (out_sink > 100) ? (chk_sum & 31) : (111 & 31);
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= (stage_v_106 << 1) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_3.buffer[0] ^ 110) & 3;
    switch (stage_v_107) {
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

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = table[0];
    table[0] = (table[1] + 217) & 63;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[1] * 2 + 334) & 63;
    if (stage_v_109 > 30) {
        out_sink = (out_sink + stage_v_109 - 5) & 255;
        if (stage_v_109 > 45) {
            chk_sum ^= (stage_v_109 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_109 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 19) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 34) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_3.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 10) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 25) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_0.buffer[2] * 2 + 355) & 63;
    if (stage_v_116 > 27) {
        out_sink = (out_sink + stage_v_116 - 5) & 255;
        if (stage_v_116 > 42) {
            chk_sum ^= (stage_v_116 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_116 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_2.buffer[1] * 2 + 361) & 63;
    if (stage_v_118 > 32) {
        out_sink = (out_sink + stage_v_118 - 5) & 255;
        if (stage_v_118 > 47) {
            chk_sum ^= (stage_v_118 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_118 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 119 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 120) & 15;
    int stage_v_119 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= stage_v_119;

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_122 = (stage_v_122 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_3.buffer[0] ^ 126) & 3;
    switch (stage_v_123) {
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

    /* Execution Pipeline Stage 124 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 125) & 15;
    int stage_v_124 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= stage_v_124;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[2] * 2 + 382) & 63;
    if (stage_v_125 > 31) {
        out_sink = (out_sink + stage_v_125 - 5) & 255;
        if (stage_v_125 > 46) {
            chk_sum ^= (stage_v_125 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_125 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_0.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_3.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 11) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 26) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[0] ^ 137) & 3;
    switch (stage_v_134) {
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

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_2.buffer[0] ^ 141) & 3;
    switch (stage_v_138) {
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

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

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
    for (int step = 0; step < 3; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

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
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (out_sink > 100) ? (chk_sum & 31) : (153 & 31);
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= (stage_v_148 << 1) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (out_sink > 100) ? (chk_sum & 31) : (156 & 31);
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= (stage_v_151 << 1) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_0.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 27) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 42) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_156 = (stage_v_156 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_3.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = table[2];
    table[2] = (table[3] + 325) & 63;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_164 = (stage_v_164 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 166) & 15;
    int stage_v_165 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= stage_v_165;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_166 = (stage_v_166 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_168 = (stage_v_168 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[0] ^ 172) & 3;
    switch (stage_v_169) {
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

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_170 = (stage_v_170 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_170) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = table[0];
    table[0] = (table[1] + 345) & 63;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 174) & 15;
    int stage_v_173 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= stage_v_173;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = table[2];
    table[2] = (table[3] + 349) & 63;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 176) & 15;
    int stage_v_175 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= stage_v_175;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_0.buffer[0] ^ 179) & 3;
    switch (stage_v_176) {
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

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] ^ 180) & 3;
    switch (stage_v_177) {
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

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Execution Pipeline Stage 180 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 181) & 15;
    int stage_v_180 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= stage_v_180;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (out_sink > 100) ? (chk_sum & 31) : (186 & 31);
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= (stage_v_181 << 1) & 127;

    /* Execution Pipeline Stage 182 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 183) & 15;
    int stage_v_182 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= stage_v_182;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_183 = (stage_v_183 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_183) & 127;
    }
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (out_sink > 100) ? (chk_sum & 31) : (189 & 31);
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= (stage_v_184 << 1) & 127;

    /* Execution Pipeline Stage 185 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 186) & 15;
    int stage_v_185 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= stage_v_185;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_2.buffer[0] * 2 + 565) & 63;
    if (stage_v_186 > 21) {
        out_sink = (out_sink + stage_v_186 - 5) & 255;
        if (stage_v_186 > 36) {
            chk_sum ^= (stage_v_186 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_186 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Security Information Flow: Family = multi_step_explicit */
    int m_step_0 = (sec_r000245_4 + pub_r000245_2 + 16) & 127;
    int m_step_1 = (m_step_0 + pub_r000245_4 + 33) & 127;
    int m_step_2 = (m_step_1 + pub_r000245_5 + 18) & 127;
    out_sink = (out_sink + m_step_2) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
