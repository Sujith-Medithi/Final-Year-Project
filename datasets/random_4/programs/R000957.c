/*
 * Benchmark Program: R000957
 * Family: mixed_control_data
 * Generator Seed: 495713
 * High Inputs: 22 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000957_5713_0 {
    short tag;
    int nonce;
    short counter;
    short round_key;
    int flags;
    int iv;
    int buffer[3];
};

struct StreamBuffer_R000957_5713_1 {
    short checksum;
    int watermark;
    int head;
    short state;
    int buffer[3];
};

struct SensorNode_R000957_5713_2 {
    short status;
    unsigned char reading;
    int threshold;
    unsigned char offset;
    int gain;
    int buffer[3];
};

union ColorPixel_R000957_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000957_5713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int mask_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_86) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_93 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_93 > 35) {
        acc = (acc + vector_93 * 2 + 5) & 127;
        aux ^= (vector_93 & 15);
    } else {
        acc = (acc - vector_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_1(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int checksum_98 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_98 > 42) {
        acc = (acc + checksum_98 * 2 + 5) & 127;
        aux ^= (checksum_98 & 15);
    } else {
        acc = (acc - checksum_98 + 11) & 127;
        aux += 3;
    }
    int quantum_94 = (aux + st.buffer[1]) & 3;
    switch (quantum_94) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_59 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_59 = (threshold_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_59) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_2(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_19 = (aux + st.buffer[1]) & 3;
    switch (stride_19) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_15) & 63;
    acc ^= aux;
    int vector_90 = 0;
    for (int k = 0; k < 2; k++) {
        vector_90 = (vector_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_90) & 127;
    }
    int factor_34 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_34 > 24) {
        acc = (acc + factor_34 * 2 + 5) & 127;
        aux ^= (factor_34 & 15);
    } else {
        acc = (acc - factor_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int bound_69 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_69 > 44) {
        acc = (acc + bound_69 * 2 + 5) & 127;
        aux ^= (bound_69 & 15);
    } else {
        acc = (acc - bound_69 + 11) & 127;
        aux += 3;
    }
    int scale_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_78) & 63;
    acc ^= aux;
    int stride_50 = 0;
    for (int k = 0; k < 2; k++) {
        stride_50 = (stride_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_50) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_56 = local_arr[aux % 3];
    acc = (acc + weight_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quantum_22 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_22 = (quantum_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_22) & 127;
    }
    int quantum_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000957_5713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_31 = (aux + st.buffer[1]) & 3;
    switch (phase_31) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_48 = 0;
    for (int k = 0; k < 3; k++) {
        stride_48 = (stride_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_48) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_94 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_94 > 14) {
        acc = (acc + pivot_94 * 2 + 5) & 127;
        aux ^= (pivot_94 & 15);
    } else {
        acc = (acc - pivot_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_6(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_20 = (aux + st.buffer[1]) & 3;
    switch (coefficient_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000957_5713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int margin_83 = local_arr[aux % 3];
    acc = (acc + margin_83 * 2) & 127;
    int window_85 = (st.buffer[0] * 3 + aux) & 63;
    if (window_85 > 48) {
        acc = (acc + window_85 * 2 + 5) & 127;
        aux ^= (window_85 & 15);
    } else {
        acc = (acc - window_85 + 11) & 127;
        aux += 3;
    }
    int pivot_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_91) & 63;
    acc ^= aux;
    int quantum_41 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_41 = (quantum_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_41) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_8(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int mask_11 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_11 > 10) {
        acc = (acc + mask_11 * 2 + 5) & 127;
        aux ^= (mask_11 & 15);
    } else {
        acc = (acc - mask_11 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000957_5713_9(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_45) & 63;
    acc ^= aux;
    int scale_77 = 0;
    for (int k = 0; k < 3; k++) {
        scale_77 = (scale_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_77) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_10(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000957_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_95 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_95 > 43) {
        acc = (acc + segment_95 * 2 + 5) & 127;
        aux ^= (segment_95 & 15);
    } else {
        acc = (acc - segment_95 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_33 = local_arr[aux % 3];
    acc = (acc + vector_33 * 2) & 127;
    int factor_17 = 0;
    for (int k = 0; k < 3; k++) {
        factor_17 = (factor_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_17) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int coefficient_53 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_53 = (coefficient_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_53) & 127;
    }
    int parity_78 = (aux + st.buffer[1]) & 3;
    switch (parity_78) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_85 = local_arr[aux % 3];
    acc = (acc + delta_85 * 2) & 127;
    int tally_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000957_5713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000957_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_75 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_75 > 34) {
        acc = (acc + accumulator_75 * 2 + 5) & 127;
        aux ^= (accumulator_75 & 15);
    } else {
        acc = (acc - accumulator_75 + 11) & 127;
        aux += 3;
    }
    int threshold_18 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_18 = (threshold_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_18) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_84 = local_arr[aux % 3];
    acc = (acc + cursor_84 * 2) & 127;
    int offset_82 = (aux + st.buffer[1]) & 3;
    switch (offset_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_13(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int anchor_99 = (aux + st.buffer[1]) & 3;
    switch (anchor_99) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_93 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_93 > 44) {
        acc = (acc + segment_93 * 2 + 5) & 127;
        aux ^= (segment_93 & 15);
    } else {
        acc = (acc - segment_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000957_5713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000957_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int delta_43 = 0;
    for (int k = 0; k < 3; k++) {
        delta_43 = (delta_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_43) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_94 = local_arr[aux % 3];
    acc = (acc + quantum_94 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000957_0;
    int sec_r000957_1;
    int sec_r000957_2;
    int sec_r000957_3;
    int sec_r000957_4;
    int sec_r000957_5;
    int sec_r000957_6;
    int sec_r000957_7;
    int sec_r000957_8;
    int sec_r000957_9;
    int sec_r000957_10;
    int sec_r000957_11;
    int sec_r000957_12;
    int sec_r000957_13;
    int sec_r000957_14;
    int sec_r000957_15;
    int sec_r000957_16;
    int sec_r000957_17;
    int sec_r000957_18;
    int sec_r000957_19;
    int sec_r000957_20;
    int sec_r000957_21;
    int pub_r000957_0;
    int pub_r000957_1;
    int pub_r000957_2;
    int pub_r000957_3;
    int pub_r000957_4;
    int pub_r000957_5;
    int pub_r000957_6;
    int pub_r000957_7;
    int pub_r000957_8;
    int pub_r000957_9;
    int pub_r000957_10;
    int pub_r000957_11;
    int pub_r000957_12;
    int pub_r000957_13;
    int pub_r000957_14;
    int pub_r000957_15;
    int pub_r000957_16;
    int pub_r000957_17;
    int pub_r000957_18;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000957_0 >= -100 && pub_r000957_0 <= 100);
    __CPROVER_assume(pub_r000957_1 >= -100 && pub_r000957_1 <= 100);
    __CPROVER_assume(pub_r000957_2 >= -100 && pub_r000957_2 <= 100);
    __CPROVER_assume(pub_r000957_3 >= -100 && pub_r000957_3 <= 100);
    __CPROVER_assume(pub_r000957_4 >= -100 && pub_r000957_4 <= 100);
    __CPROVER_assume(pub_r000957_5 >= -100 && pub_r000957_5 <= 100);
    __CPROVER_assume(pub_r000957_6 >= -100 && pub_r000957_6 <= 100);
    __CPROVER_assume(pub_r000957_7 >= -100 && pub_r000957_7 <= 100);
    __CPROVER_assume(pub_r000957_8 >= -100 && pub_r000957_8 <= 100);
    __CPROVER_assume(pub_r000957_9 >= -100 && pub_r000957_9 <= 100);
    __CPROVER_assume(pub_r000957_10 >= -100 && pub_r000957_10 <= 100);
    __CPROVER_assume(pub_r000957_11 >= -100 && pub_r000957_11 <= 100);
    __CPROVER_assume(pub_r000957_12 >= -100 && pub_r000957_12 <= 100);
    __CPROVER_assume(pub_r000957_13 >= -100 && pub_r000957_13 <= 100);
    __CPROVER_assume(pub_r000957_14 >= -100 && pub_r000957_14 <= 100);
    __CPROVER_assume(pub_r000957_15 >= -100 && pub_r000957_15 <= 100);
    __CPROVER_assume(pub_r000957_16 >= -100 && pub_r000957_16 <= 100);
    __CPROVER_assume(pub_r000957_17 >= -100 && pub_r000957_17 <= 100);
    __CPROVER_assume(pub_r000957_18 >= -100 && pub_r000957_18 <= 100);
    __CPROVER_assume(sec_r000957_0 >= 0 && sec_r000957_0 <= 255);
    __CPROVER_assume(sec_r000957_1 >= 0 && sec_r000957_1 <= 255);
    __CPROVER_assume(sec_r000957_2 >= 0 && sec_r000957_2 <= 255);
    __CPROVER_assume(sec_r000957_3 >= 0 && sec_r000957_3 <= 255);
    __CPROVER_assume(sec_r000957_4 >= 0 && sec_r000957_4 <= 255);
    __CPROVER_assume(sec_r000957_5 >= 0 && sec_r000957_5 <= 255);
    __CPROVER_assume(sec_r000957_6 >= 0 && sec_r000957_6 <= 255);
    __CPROVER_assume(sec_r000957_7 >= 0 && sec_r000957_7 <= 255);
    __CPROVER_assume(sec_r000957_8 >= 0 && sec_r000957_8 <= 255);
    __CPROVER_assume(sec_r000957_9 >= 0 && sec_r000957_9 <= 255);
    __CPROVER_assume(sec_r000957_10 >= 0 && sec_r000957_10 <= 255);
    __CPROVER_assume(sec_r000957_11 >= 0 && sec_r000957_11 <= 255);
    __CPROVER_assume(sec_r000957_12 >= 0 && sec_r000957_12 <= 255);
    __CPROVER_assume(sec_r000957_13 >= 0 && sec_r000957_13 <= 255);
    __CPROVER_assume(sec_r000957_14 >= 0 && sec_r000957_14 <= 255);
    __CPROVER_assume(sec_r000957_15 >= 0 && sec_r000957_15 <= 255);
    __CPROVER_assume(sec_r000957_16 >= 0 && sec_r000957_16 <= 255);
    __CPROVER_assume(sec_r000957_17 >= 0 && sec_r000957_17 <= 255);
    __CPROVER_assume(sec_r000957_18 >= 0 && sec_r000957_18 <= 255);
    __CPROVER_assume(sec_r000957_19 >= 0 && sec_r000957_19 <= 255);
    __CPROVER_assume(sec_r000957_20 >= 0 && sec_r000957_20 <= 255);
    __CPROVER_assume(sec_r000957_21 >= 0 && sec_r000957_21 <= 255);

    struct CipherContext_R000957_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000957_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000957_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000957_0 + 7) & 15;
    struct StreamBuffer_R000957_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000957_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000957_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000957_0 + 9) & 15;
    struct SensorNode_R000957_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000957_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000957_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000957_0 + 11) & 15;

    union ColorPixel_R000957_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 39) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 54) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 21) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 36) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 29) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 44) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

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
    int stage_v_15 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 25) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 40) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 12) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 27) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 27) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 42) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 28) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 43) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 14) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 29) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 25) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 40) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 29) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 44) {
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
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 19) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 34) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[2] * 2 + 229) & 63;
    if (stage_v_74 > 23) {
        out_sink = (out_sink + stage_v_74 - 5) & 255;
        if (stage_v_74 > 38) {
            chk_sum ^= (stage_v_74 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_74 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 15) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 30) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_1.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 23) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 38) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 87) & 15;
    int stage_v_86 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= stage_v_86;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (out_sink > 100) ? (chk_sum & 31) : (92 & 31);
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= (stage_v_87 << 1) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_90 = (stage_v_90 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 22) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 37) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_95 = table[3];
    table[3] = (table[0] + 191) & 63;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 33) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 48) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_97 = (stage_v_97 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 34) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 49) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 100) & 15;
    int stage_v_99 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= stage_v_99;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (out_sink > 100) ? (chk_sum & 31) : (107 & 31);
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= (stage_v_102 << 1) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_2.buffer[0] ^ 107) & 3;
    switch (stage_v_104) {
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

    /* Execution Pipeline Stage 105 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_1.buffer[0] ^ 109) & 3;
    switch (stage_v_106) {
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

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (out_sink > 100) ? (chk_sum & 31) : (112 & 31);
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= (stage_v_107 << 1) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 25) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 40) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] ^ 117) & 3;
    switch (stage_v_114) {
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

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (out_sink > 100) ? (chk_sum & 31) : (122 & 31);
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= (stage_v_117 << 1) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = table[2];
    table[2] = (table[3] + 237) & 63;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 121 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 122) & 15;
    int stage_v_121 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= stage_v_121;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = table[0];
    table[0] = (table[1] + 249) & 63;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (out_sink > 100) ? (chk_sum & 31) : (131 & 31);
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= (stage_v_126 << 1) & 127;

    /* Execution Pipeline Stage 127 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_0.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_2.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 22) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 37) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 27) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 42) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_0.buffer[0] ^ 138) & 3;
    switch (stage_v_135) {
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

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_2.buffer[2] * 2 + 427) & 63;
    if (stage_v_140 > 30) {
        out_sink = (out_sink + stage_v_140 - 5) & 255;
        if (stage_v_140 > 45) {
            chk_sum ^= (stage_v_140 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_140 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 25) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 40) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
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

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_2.buffer[0] ^ 149) & 3;
    switch (stage_v_146) {
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

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 35) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 50) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[1] * 2 + 460) & 63;
    if (stage_v_151 > 18) {
        out_sink = (out_sink + stage_v_151 - 5) & 255;
        if (stage_v_151 > 33) {
            chk_sum ^= (stage_v_151 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_151 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_2.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 28) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 43) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
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

    /* Execution Pipeline Stage 154 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 155) & 15;
    int stage_v_154 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= stage_v_154;

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
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = table[2];
    table[2] = (table[3] + 317) & 63;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = table[1];
    table[1] = (table[2] + 323) & 63;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] * 2 + 493) & 63;
    if (stage_v_162 > 14) {
        out_sink = (out_sink + stage_v_162 - 5) & 255;
        if (stage_v_162 > 29) {
            chk_sum ^= (stage_v_162 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_162 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 163 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (out_sink > 100) ? (chk_sum & 31) : (170 & 31);
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= (stage_v_165 << 1) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (out_sink > 100) ? (chk_sum & 31) : (171 & 31);
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= (stage_v_166 << 1) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (st_var_2.buffer[0] ^ 170) & 3;
    switch (stage_v_167) {
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

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (out_sink > 100) ? (chk_sum & 31) : (174 & 31);
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= (stage_v_169 << 1) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_2.buffer[2] * 2 + 517) & 63;
    if (stage_v_170 > 38) {
        out_sink = (out_sink + stage_v_170 - 5) & 255;
        if (stage_v_170 > 53) {
            chk_sum ^= (stage_v_170 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_170 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_0.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 35) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 50) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] ^ 177) & 3;
    switch (stage_v_174) {
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

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[1] * 2 + 532) & 63;
    if (stage_v_175 > 40) {
        out_sink = (out_sink + stage_v_175 - 5) & 255;
        if (stage_v_175 > 55) {
            chk_sum ^= (stage_v_175 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_175 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_2.buffer[2] * 2 + 535) & 63;
    if (stage_v_176 > 22) {
        out_sink = (out_sink + stage_v_176 - 5) & 255;
        if (stage_v_176 > 37) {
            chk_sum ^= (stage_v_176 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_176 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_177 = (stage_v_177 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_177) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_178 = (stage_v_178 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_179 = (stage_v_179 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] ^ 183) & 3;
    switch (stage_v_180) {
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

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (st_var_1.buffer[0] ^ 184) & 3;
    switch (stage_v_181) {
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

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (out_sink > 100) ? (chk_sum & 31) : (187 & 31);
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= (stage_v_182 << 1) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = table[3];
    table[3] = (table[0] + 367) & 63;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (out_sink > 100) ? (chk_sum & 31) : (191 & 31);
    out_sink = (out_sink + stage_v_186) & 255;
    chk_sum ^= (stage_v_186 << 1) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = table[3];
    table[3] = (table[0] + 375) & 63;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (st_var_2.buffer[2] * 2 + 571) & 63;
    if (stage_v_188 > 30) {
        out_sink = (out_sink + stage_v_188 - 5) & 255;
        if (stage_v_188 > 45) {
            chk_sum ^= (stage_v_188 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_188 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_189 = (stage_v_189 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_189) & 127;
    }
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_1.buffer[0] ^ 193) & 3;
    switch (stage_v_190) {
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

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_2.buffer[2] * 2 + 580) & 63;
    if (stage_v_191 > 37) {
        out_sink = (out_sink + stage_v_191 - 5) & 255;
        if (stage_v_191 > 52) {
            chk_sum ^= (stage_v_191 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_191 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (out_sink > 100) ? (chk_sum & 31) : (197 & 31);
    out_sink = (out_sink + stage_v_192) & 255;
    chk_sum ^= (stage_v_192 << 1) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = table[1];
    table[1] = (table[2] + 387) & 63;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = table[2];
    table[2] = (table[3] + 389) & 63;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_0.buffer[0] * 2 + 592) & 63;
    if (stage_v_195 > 14) {
        out_sink = (out_sink + stage_v_195 - 5) & 255;
        if (stage_v_195 > 29) {
            chk_sum ^= (stage_v_195 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_195 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_1.buffer[0] ^ 199) & 3;
    switch (stage_v_196) {
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

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = table[1];
    table[1] = (table[2] + 395) & 63;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000957_10 ^ 0x55) & 63;
    if (m_var > 23) {
        out_sink += (m_var * 2 + pub_r000957_1) & 127;
    } else {
        out_sink -= (m_var + 15) & 31;
    }
    out_sink ^= (sec_r000957_20 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
