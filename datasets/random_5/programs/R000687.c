/*
 * Benchmark Program: R000687
 * Security Family: nested_implicit_flow
 * Generator Seed: 568713
 * High Inputs: 22 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000687_8713_0 {
    int tag;
    int round_key;
    unsigned char flags;
    int nonce;
    int buffer[3];
};

struct SensorNode_R000687_8713_1 {
    unsigned char status;
    short gain;
    int offset;
    int threshold;
    int buffer[3];
};

struct FilterState_R000687_8713_2 {
    short prev_out;
    int damping;
    short cutoff;
    short mode;
    int buffer[3];
};

union RegisterBank_R000687_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000687_8713_0(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int accumulator_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_68) & 63;
    acc ^= aux;
    int phase_20 = (aux + st.buffer[1]) & 3;
    switch (phase_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_86) & 63;
    acc ^= aux;
    int stride_56 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_56 > 24) {
        acc = (acc + stride_56 * 2 + 5) & 127;
        aux ^= (stride_56 & 15);
    } else {
        acc = (acc - stride_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_2(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000687_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int segment_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_39) & 63;
    acc ^= aux;
    int window_55 = (st.buffer[0] * 3 + aux) & 63;
    if (window_55 > 50) {
        acc = (acc + window_55 * 2 + 5) & 127;
        aux ^= (window_55 & 15);
    } else {
        acc = (acc - window_55 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_82 = (aux + st.buffer[1]) & 3;
    switch (weight_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_75 = (aux + st.buffer[1]) & 3;
    switch (accumulator_75) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_39 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_39 > 22) {
        acc = (acc + residue_39 * 2 + 5) & 127;
        aux ^= (residue_39 & 15);
    } else {
        acc = (acc - residue_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000687_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int tracker_44 = local_arr[aux % 3];
    acc = (acc + tracker_44 * 2) & 127;
    int vector_49 = (aux + st.buffer[1]) & 3;
    switch (vector_49) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000687_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int parity_36 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_36 > 41) {
        acc = (acc + parity_36 * 2 + 5) & 127;
        aux ^= (parity_36 & 15);
    } else {
        acc = (acc - parity_36 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000687_8713_6(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000687_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_91 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_91 > 49) {
        acc = (acc + metric_91 * 2 + 5) & 127;
        aux ^= (metric_91 & 15);
    } else {
        acc = (acc - metric_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_7(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int cursor_73 = local_arr[aux % 3];
    acc = (acc + cursor_73 * 2) & 127;
    int quantum_58 = (aux + st.buffer[1]) & 3;
    switch (quantum_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_47 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_47 > 45) {
        acc = (acc + stride_47 * 2 + 5) & 127;
        aux ^= (stride_47 & 15);
    } else {
        acc = (acc - stride_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_84 = (aux + st.buffer[1]) & 3;
    switch (segment_84) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_25 = local_arr[aux % 3];
    acc = (acc + anchor_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000687_8713_9(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int pivot_25 = local_arr[aux % 3];
    acc = (acc + pivot_25 * 2) & 127;
    int mask_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_48) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000687_8713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int offset_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_27) & 63;
    acc ^= aux;
    int segment_84 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_84 > 32) {
        acc = (acc + segment_84 * 2 + 5) & 127;
        aux ^= (segment_84 & 15);
    } else {
        acc = (acc - segment_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000687_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int residue_64 = (aux + st.buffer[1]) & 3;
    switch (residue_64) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_36 = local_arr[aux % 3];
    acc = (acc + weight_36 * 2) & 127;
    int parity_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_69) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000687_8713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000687_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_40 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_40 > 30) {
        acc = (acc + parity_40 * 2 + 5) & 127;
        aux ^= (parity_40 & 15);
    } else {
        acc = (acc - parity_40 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_54 = local_arr[aux % 3];
    acc = (acc + segment_54 * 2) & 127;
    int factor_75 = (aux + st.buffer[1]) & 3;
    switch (factor_75) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_13(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000687_8713_14(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000687_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_87 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_87 > 39) {
        acc = (acc + offset_87 * 2 + 5) & 127;
        aux ^= (offset_87 & 15);
    } else {
        acc = (acc - offset_87 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_97 = local_arr[aux % 3];
    acc = (acc + cursor_97 * 2) & 127;
    int index_reg_94 = (aux + st.buffer[1]) & 3;
    switch (index_reg_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_15(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000687_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_94 = (aux + st.buffer[1]) & 3;
    switch (metric_94) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_36 = local_arr[aux % 3];
    acc = (acc + tally_36 * 2) & 127;
    int parity_82 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_82 > 28) {
        acc = (acc + parity_82 * 2 + 5) & 127;
        aux ^= (parity_82 & 15);
    } else {
        acc = (acc - parity_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000687_8713_16(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000687_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_87 = (aux + st.buffer[1]) & 3;
    switch (scale_87) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000687_0;
    int sec_r000687_1;
    int sec_r000687_2;
    int sec_r000687_3;
    int sec_r000687_4;
    int sec_r000687_5;
    int sec_r000687_6;
    int sec_r000687_7;
    int sec_r000687_8;
    int sec_r000687_9;
    int sec_r000687_10;
    int sec_r000687_11;
    int sec_r000687_12;
    int sec_r000687_13;
    int sec_r000687_14;
    int sec_r000687_15;
    int sec_r000687_16;
    int sec_r000687_17;
    int sec_r000687_18;
    int sec_r000687_19;
    int sec_r000687_20;
    int sec_r000687_21;
    int pub_r000687_0;
    int pub_r000687_1;
    int pub_r000687_2;
    int pub_r000687_3;
    int pub_r000687_4;
    int pub_r000687_5;
    int pub_r000687_6;
    int pub_r000687_7;
    int pub_r000687_8;
    int pub_r000687_9;
    int pub_r000687_10;
    int pub_r000687_11;
    int pub_r000687_12;
    int pub_r000687_13;
    int pub_r000687_14;
    int pub_r000687_15;
    int pub_r000687_16;
    int pub_r000687_17;
    int pub_r000687_18;
    int pub_r000687_19;
    int pub_r000687_20;
    int pub_r000687_21;
    int pub_r000687_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000687_0 >= -100 && pub_r000687_0 <= 100);
    __CPROVER_assume(pub_r000687_1 >= -100 && pub_r000687_1 <= 100);
    __CPROVER_assume(pub_r000687_2 >= -100 && pub_r000687_2 <= 100);
    __CPROVER_assume(pub_r000687_3 >= -100 && pub_r000687_3 <= 100);
    __CPROVER_assume(pub_r000687_4 >= -100 && pub_r000687_4 <= 100);
    __CPROVER_assume(pub_r000687_5 >= -100 && pub_r000687_5 <= 100);
    __CPROVER_assume(pub_r000687_6 >= -100 && pub_r000687_6 <= 100);
    __CPROVER_assume(pub_r000687_7 >= -100 && pub_r000687_7 <= 100);
    __CPROVER_assume(pub_r000687_8 >= -100 && pub_r000687_8 <= 100);
    __CPROVER_assume(pub_r000687_9 >= -100 && pub_r000687_9 <= 100);
    __CPROVER_assume(pub_r000687_10 >= -100 && pub_r000687_10 <= 100);
    __CPROVER_assume(pub_r000687_11 >= -100 && pub_r000687_11 <= 100);
    __CPROVER_assume(pub_r000687_12 >= -100 && pub_r000687_12 <= 100);
    __CPROVER_assume(pub_r000687_13 >= -100 && pub_r000687_13 <= 100);
    __CPROVER_assume(pub_r000687_14 >= -100 && pub_r000687_14 <= 100);
    __CPROVER_assume(pub_r000687_15 >= -100 && pub_r000687_15 <= 100);
    __CPROVER_assume(pub_r000687_16 >= -100 && pub_r000687_16 <= 100);
    __CPROVER_assume(pub_r000687_17 >= -100 && pub_r000687_17 <= 100);
    __CPROVER_assume(pub_r000687_18 >= -100 && pub_r000687_18 <= 100);
    __CPROVER_assume(pub_r000687_19 >= -100 && pub_r000687_19 <= 100);
    __CPROVER_assume(pub_r000687_20 >= -100 && pub_r000687_20 <= 100);
    __CPROVER_assume(pub_r000687_21 >= -100 && pub_r000687_21 <= 100);
    __CPROVER_assume(pub_r000687_22 >= -100 && pub_r000687_22 <= 100);
    __CPROVER_assume(sec_r000687_0 >= 0 && sec_r000687_0 <= 255);
    __CPROVER_assume(sec_r000687_1 >= 0 && sec_r000687_1 <= 255);
    __CPROVER_assume(sec_r000687_2 >= 0 && sec_r000687_2 <= 255);
    __CPROVER_assume(sec_r000687_3 >= 0 && sec_r000687_3 <= 255);
    __CPROVER_assume(sec_r000687_4 >= 0 && sec_r000687_4 <= 255);
    __CPROVER_assume(sec_r000687_5 >= 0 && sec_r000687_5 <= 255);
    __CPROVER_assume(sec_r000687_6 >= 0 && sec_r000687_6 <= 255);
    __CPROVER_assume(sec_r000687_7 >= 0 && sec_r000687_7 <= 255);
    __CPROVER_assume(sec_r000687_8 >= 0 && sec_r000687_8 <= 255);
    __CPROVER_assume(sec_r000687_9 >= 0 && sec_r000687_9 <= 255);
    __CPROVER_assume(sec_r000687_10 >= 0 && sec_r000687_10 <= 255);
    __CPROVER_assume(sec_r000687_11 >= 0 && sec_r000687_11 <= 255);
    __CPROVER_assume(sec_r000687_12 >= 0 && sec_r000687_12 <= 255);
    __CPROVER_assume(sec_r000687_13 >= 0 && sec_r000687_13 <= 255);
    __CPROVER_assume(sec_r000687_14 >= 0 && sec_r000687_14 <= 255);
    __CPROVER_assume(sec_r000687_15 >= 0 && sec_r000687_15 <= 255);
    __CPROVER_assume(sec_r000687_16 >= 0 && sec_r000687_16 <= 255);
    __CPROVER_assume(sec_r000687_17 >= 0 && sec_r000687_17 <= 255);
    __CPROVER_assume(sec_r000687_18 >= 0 && sec_r000687_18 <= 255);
    __CPROVER_assume(sec_r000687_19 >= 0 && sec_r000687_19 <= 255);
    __CPROVER_assume(sec_r000687_20 >= 0 && sec_r000687_20 <= 255);
    __CPROVER_assume(sec_r000687_21 >= 0 && sec_r000687_21 <= 255);

    struct CipherContext_R000687_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000687_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000687_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000687_0 + 7) & 15;
    struct SensorNode_R000687_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000687_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000687_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000687_0 + 9) & 15;
    struct FilterState_R000687_8713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000687_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000687_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000687_0 + 11) & 15;

    union RegisterBank_R000687_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 27) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 42) {
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
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 26) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 41) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 27) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 42) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 22) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 37) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 28) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 43) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 28) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 43) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[0] ^ 50) & 3;
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
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 36) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 51) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 36) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 51) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 21) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 36) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 40) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 55) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 21) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 36) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = table[0];
    table[0] = (table[1] + 169) & 63;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 86) & 15;
    int stage_v_85 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= stage_v_85;

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
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 91) & 15;
    int stage_v_90 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= stage_v_90;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000687_13 & 1) != 0) {
        if ((sec_r000687_6 & 2) != 0) {
            stage_v_91 = (pub_r000687_17 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000687_17 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000687_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000687_0 & 2) != 0) {
            stage_v_92 = (pub_r000687_0 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000687_0 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000687_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000687_7 & 1) != 0) {
        if ((sec_r000687_2 & 2) != 0) {
            stage_v_93 = (pub_r000687_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000687_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000687_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000687_8 & 1) != 0) {
        if ((sec_r000687_8 & 2) != 0) {
            stage_v_94 = (pub_r000687_7 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000687_7 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000687_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000687_7 & 2) != 0) {
            stage_v_95 = (pub_r000687_18 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000687_18 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000687_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000687_1 & 2) != 0) {
            stage_v_96 = (pub_r000687_5 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000687_5 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000687_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000687_12 & 2) != 0) {
            stage_v_97 = (pub_r000687_2 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000687_2 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000687_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000687_15 & 2) != 0) {
            stage_v_98 = (pub_r000687_11 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000687_11 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000687_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000687_10 & 2) != 0) {
            stage_v_99 = (pub_r000687_6 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000687_6 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000687_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000687_11 & 2) != 0) {
            stage_v_100 = (pub_r000687_11 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000687_11 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000687_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000687_20 & 2) != 0) {
            stage_v_101 = (pub_r000687_16 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000687_16 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000687_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000687_10 & 2) != 0) {
            stage_v_102 = (pub_r000687_21 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000687_21 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000687_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000687_9 & 2) != 0) {
            stage_v_103 = (pub_r000687_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000687_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000687_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_104 = (pub_r000687_4 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000687_4 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000687_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000687_7 & 2) != 0) {
            stage_v_105 = (pub_r000687_22 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000687_22 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000687_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000687_16 & 1) != 0) {
        if ((sec_r000687_9 & 2) != 0) {
            stage_v_106 = (pub_r000687_9 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000687_9 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000687_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000687_5 & 1) != 0) {
        if ((sec_r000687_10 & 2) != 0) {
            stage_v_107 = (pub_r000687_10 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000687_10 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000687_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000687_11 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_108 = (pub_r000687_7 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000687_7 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000687_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000687_8 & 2) != 0) {
            stage_v_109 = (pub_r000687_4 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000687_4 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000687_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000687_15 & 2) != 0) {
            stage_v_110 = (pub_r000687_7 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000687_7 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000687_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_111 = (pub_r000687_21 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000687_21 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000687_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000687_18 & 1) != 0) {
        if ((sec_r000687_9 & 2) != 0) {
            stage_v_112 = (pub_r000687_9 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000687_9 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000687_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000687_6 & 2) != 0) {
            stage_v_113 = (pub_r000687_2 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000687_2 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000687_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000687_7 & 2) != 0) {
            stage_v_114 = (pub_r000687_17 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000687_17 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000687_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000687_6 & 2) != 0) {
            stage_v_115 = (pub_r000687_8 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000687_8 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000687_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000687_14 & 2) != 0) {
            stage_v_116 = (pub_r000687_3 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000687_3 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000687_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000687_18 & 1) != 0) {
        if ((sec_r000687_0 & 2) != 0) {
            stage_v_117 = (pub_r000687_16 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000687_16 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000687_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000687_1 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_118 = (pub_r000687_14 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000687_14 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000687_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000687_15 & 2) != 0) {
            stage_v_119 = (pub_r000687_1 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000687_1 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000687_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000687_0 & 2) != 0) {
            stage_v_120 = (pub_r000687_14 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000687_14 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000687_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000687_8 & 2) != 0) {
            stage_v_121 = (pub_r000687_3 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000687_3 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000687_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000687_7 & 2) != 0) {
            stage_v_122 = (pub_r000687_12 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000687_12 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000687_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000687_7 & 1) != 0) {
        if ((sec_r000687_13 & 2) != 0) {
            stage_v_123 = (pub_r000687_4 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000687_4 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000687_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000687_15 & 2) != 0) {
            stage_v_124 = (pub_r000687_21 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000687_21 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000687_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000687_4 & 1) != 0) {
        if ((sec_r000687_4 & 2) != 0) {
            stage_v_125 = (pub_r000687_19 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000687_19 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000687_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000687_10 & 2) != 0) {
            stage_v_126 = (pub_r000687_7 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000687_7 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000687_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000687_14 & 1) != 0) {
        if ((sec_r000687_20 & 2) != 0) {
            stage_v_127 = (pub_r000687_6 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000687_6 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000687_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000687_15 & 2) != 0) {
            stage_v_128 = (pub_r000687_16 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000687_16 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000687_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000687_18 & 1) != 0) {
        if ((sec_r000687_18 & 2) != 0) {
            stage_v_129 = (pub_r000687_21 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000687_21 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000687_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_130 = (pub_r000687_18 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000687_18 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000687_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000687_7 & 2) != 0) {
            stage_v_131 = (pub_r000687_5 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000687_5 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000687_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000687_1 & 1) != 0) {
        if ((sec_r000687_18 & 2) != 0) {
            stage_v_132 = (pub_r000687_18 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000687_18 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000687_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000687_18 & 2) != 0) {
            stage_v_133 = (pub_r000687_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000687_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000687_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000687_13 & 2) != 0) {
            stage_v_134 = (pub_r000687_13 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000687_13 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000687_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000687_10 & 2) != 0) {
            stage_v_135 = (pub_r000687_17 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000687_17 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000687_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000687_7 & 1) != 0) {
        if ((sec_r000687_9 & 2) != 0) {
            stage_v_136 = (pub_r000687_10 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000687_10 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000687_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_137 = (pub_r000687_7 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000687_7 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000687_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000687_8 & 2) != 0) {
            stage_v_138 = (pub_r000687_11 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000687_11 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000687_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000687_5 & 1) != 0) {
        if ((sec_r000687_21 & 2) != 0) {
            stage_v_139 = (pub_r000687_18 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000687_18 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000687_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000687_0 & 1) != 0) {
        if ((sec_r000687_17 & 2) != 0) {
            stage_v_140 = (pub_r000687_14 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000687_14 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000687_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000687_18 & 1) != 0) {
        if ((sec_r000687_8 & 2) != 0) {
            stage_v_141 = (pub_r000687_21 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000687_21 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000687_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000687_5 & 2) != 0) {
            stage_v_142 = (pub_r000687_5 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000687_5 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000687_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000687_0 & 2) != 0) {
            stage_v_143 = (pub_r000687_5 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000687_5 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000687_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000687_11 & 2) != 0) {
            stage_v_144 = (pub_r000687_11 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000687_11 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000687_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000687_13 & 2) != 0) {
            stage_v_145 = (pub_r000687_10 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000687_10 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000687_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000687_2 & 2) != 0) {
            stage_v_146 = (pub_r000687_10 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000687_10 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000687_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000687_1 & 1) != 0) {
        if ((sec_r000687_12 & 2) != 0) {
            stage_v_147 = (pub_r000687_22 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000687_22 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000687_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000687_20 & 1) != 0) {
        if ((sec_r000687_15 & 2) != 0) {
            stage_v_148 = (pub_r000687_0 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000687_0 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000687_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000687_8 & 2) != 0) {
            stage_v_149 = (pub_r000687_1 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000687_1 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000687_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000687_21 & 2) != 0) {
            stage_v_150 = (pub_r000687_18 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000687_18 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000687_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000687_4 & 1) != 0) {
        if ((sec_r000687_5 & 2) != 0) {
            stage_v_151 = (pub_r000687_22 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000687_22 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000687_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_141 & 1) != 0) {
        if ((sec_r000687_1 & 2) != 0) {
            stage_v_152 = (pub_r000687_1 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000687_1 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000687_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000687_10 & 1) != 0) {
        if ((sec_r000687_18 & 2) != 0) {
            stage_v_153 = (pub_r000687_0 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000687_0 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000687_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000687_3 & 1) != 0) {
        if ((sec_r000687_14 & 2) != 0) {
            stage_v_154 = (pub_r000687_14 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000687_14 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000687_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000687_12 & 1) != 0) {
        if ((sec_r000687_21 & 2) != 0) {
            stage_v_155 = (pub_r000687_5 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000687_5 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000687_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000687_4 & 1) != 0) {
        if ((sec_r000687_14 & 2) != 0) {
            stage_v_156 = (pub_r000687_2 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000687_2 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000687_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000687_4 & 1) != 0) {
        if ((sec_r000687_1 & 2) != 0) {
            stage_v_157 = (pub_r000687_1 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000687_1 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000687_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000687_21 & 1) != 0) {
        if ((sec_r000687_5 & 2) != 0) {
            stage_v_158 = (pub_r000687_1 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000687_1 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000687_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000687_6 & 2) != 0) {
            stage_v_159 = (pub_r000687_0 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000687_0 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000687_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000687_0 & 1) != 0) {
        if ((sec_r000687_18 & 2) != 0) {
            stage_v_160 = (pub_r000687_18 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000687_18 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000687_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000687_16 & 2) != 0) {
            stage_v_161 = (pub_r000687_8 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000687_8 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000687_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000687_4 & 1) != 0) {
        if ((sec_r000687_9 & 2) != 0) {
            stage_v_162 = (pub_r000687_17 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000687_17 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000687_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000687_2 & 2) != 0) {
            stage_v_163 = (pub_r000687_3 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000687_3 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000687_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000687_0 & 2) != 0) {
            stage_v_164 = (pub_r000687_1 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000687_1 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000687_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_165 = (pub_r000687_12 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000687_12 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000687_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_162 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_166 = (pub_r000687_9 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000687_9 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000687_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000687_2 & 2) != 0) {
            stage_v_167 = (pub_r000687_22 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000687_22 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000687_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000687_21 & 2) != 0) {
            stage_v_168 = (pub_r000687_19 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000687_19 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000687_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((stage_v_157 & 1) != 0) {
        if ((sec_r000687_3 & 2) != 0) {
            stage_v_169 = (pub_r000687_2 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000687_2 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000687_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r000687_12 & 2) != 0) {
            stage_v_170 = (pub_r000687_14 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000687_14 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000687_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
