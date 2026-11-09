/*
 * Benchmark Program: R001417
 * Security Family: nested_implicit_flow
 * Generator Seed: 641713
 * High Inputs: 21 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001417_1713_0 {
    short envelope;
    int rms;
    int peak;
    int buffer[3];
};

struct CipherContext_R001417_1713_1 {
    int tag;
    int iv;
    int nonce;
    unsigned char flags;
    int buffer[3];
};

struct SensorNode_R001417_1713_2 {
    int offset;
    unsigned char calib;
    unsigned char threshold;
    int reading;
    unsigned char status;
    short gain;
    int buffer[3];
};

union TelemetryField_R001417_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001417_1713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001417_1713_0(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int margin_73 = 0;
    for (int k = 0; k < 2; k++) {
        margin_73 = (margin_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_73) & 127;
    }
    int scale_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_62) & 63;
    acc ^= aux;
    int offset_75 = (aux + st.buffer[1]) & 3;
    switch (offset_75) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001417_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_65 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_65 = (index_reg_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_65) & 127;
    }
    int coefficient_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_98) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001417_1713_2(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001417_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int cursor_57 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_57 > 18) {
        acc = (acc + cursor_57 * 2 + 5) & 127;
        aux ^= (cursor_57 & 15);
    } else {
        acc = (acc - cursor_57 + 11) & 127;
        aux += 3;
    }
    int parity_22 = (aux + st.buffer[1]) & 3;
    switch (parity_22) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_40) & 63;
    acc ^= aux;
    int coefficient_89 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_89 = (coefficient_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_89) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int checksum_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_76 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_76 > 17) {
        acc = (acc + factor_76 * 2 + 5) & 127;
        aux ^= (factor_76 & 15);
    } else {
        acc = (acc - factor_76 + 11) & 127;
        aux += 3;
    }
    int factor_74 = 0;
    for (int k = 0; k < 3; k++) {
        factor_74 = (factor_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_74) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_4(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_10 = (aux + st.buffer[1]) & 3;
    switch (tally_10) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_98 = 0;
    for (int k = 0; k < 2; k++) {
        vector_98 = (vector_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_98) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_88 = local_arr[aux % 3];
    acc = (acc + accumulator_88 * 2) & 127;
    int segment_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001417_1713_5(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001417_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int quantum_29 = local_arr[aux % 3];
    acc = (acc + quantum_29 * 2) & 127;
    int vector_74 = 0;
    for (int k = 0; k < 3; k++) {
        vector_74 = (vector_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_74) & 127;
    }
    int quotient_38 = (aux + st.buffer[1]) & 3;
    switch (quotient_38) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_26 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_26 > 12) {
        acc = (acc + tally_26 * 2 + 5) & 127;
        aux ^= (tally_26 & 15);
    } else {
        acc = (acc - tally_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int tracker_16 = local_arr[aux % 3];
    acc = (acc + tracker_16 * 2) & 127;
    int pivot_23 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_23 > 46) {
        acc = (acc + pivot_23 * 2 + 5) & 127;
        aux ^= (pivot_23 & 15);
    } else {
        acc = (acc - pivot_23 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001417_1713_7(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_40 = (aux + st.buffer[1]) & 3;
    switch (residue_40) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_50 = local_arr[aux % 3];
    acc = (acc + tracker_50 * 2) & 127;
    int tally_21 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_21 > 10) {
        acc = (acc + tally_21 * 2 + 5) & 127;
        aux ^= (tally_21 & 15);
    } else {
        acc = (acc - tally_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_8(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int index_reg_94 = (aux + st.buffer[1]) & 3;
    switch (index_reg_94) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_40 = local_arr[aux % 3];
    acc = (acc + window_40 * 2) & 127;
    int offset_48 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_48 > 28) {
        acc = (acc + offset_48 * 2 + 5) & 127;
        aux ^= (offset_48 & 15);
    } else {
        acc = (acc - offset_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001417_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_66 = (aux + st.buffer[1]) & 3;
    switch (pivot_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_54 = 0;
    for (int k = 0; k < 3; k++) {
        weight_54 = (weight_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_54) & 127;
    }
    int mask_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001417_1713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int stride_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_74) & 63;
    acc ^= aux;
    int vector_60 = 0;
    for (int k = 0; k < 3; k++) {
        vector_60 = (vector_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_60) & 127;
    }
    int damping_54 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_54 > 19) {
        acc = (acc + damping_54 * 2 + 5) & 127;
        aux ^= (damping_54 & 15);
    } else {
        acc = (acc - damping_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001417_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int pivot_44 = (aux + st.buffer[1]) & 3;
    switch (pivot_44) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_15) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001417_1713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001417_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int quantum_83 = local_arr[aux % 3];
    acc = (acc + quantum_83 * 2) & 127;
    int window_95 = 0;
    for (int k = 0; k < 3; k++) {
        window_95 = (window_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_95) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001417_1713_13(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001417_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int sample_21 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_21 > 41) {
        acc = (acc + sample_21 * 2 + 5) & 127;
        aux ^= (sample_21 & 15);
    } else {
        acc = (acc - sample_21 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001417_1713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001417_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int metric_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_70) & 63;
    acc ^= aux;
    int quantum_48 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_48 = (quantum_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_48) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001417_0;
    int sec_r001417_1;
    int sec_r001417_2;
    int sec_r001417_3;
    int sec_r001417_4;
    int sec_r001417_5;
    int sec_r001417_6;
    int sec_r001417_7;
    int sec_r001417_8;
    int sec_r001417_9;
    int sec_r001417_10;
    int sec_r001417_11;
    int sec_r001417_12;
    int sec_r001417_13;
    int sec_r001417_14;
    int sec_r001417_15;
    int sec_r001417_16;
    int sec_r001417_17;
    int sec_r001417_18;
    int sec_r001417_19;
    int sec_r001417_20;
    int pub_r001417_0;
    int pub_r001417_1;
    int pub_r001417_2;
    int pub_r001417_3;
    int pub_r001417_4;
    int pub_r001417_5;
    int pub_r001417_6;
    int pub_r001417_7;
    int pub_r001417_8;
    int pub_r001417_9;
    int pub_r001417_10;
    int pub_r001417_11;
    int pub_r001417_12;
    int pub_r001417_13;
    int pub_r001417_14;
    int pub_r001417_15;
    int pub_r001417_16;
    int pub_r001417_17;
    int pub_r001417_18;
    int pub_r001417_19;
    int pub_r001417_20;
    int pub_r001417_21;
    int pub_r001417_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001417_0 >= -100 && pub_r001417_0 <= 100);
    __CPROVER_assume(pub_r001417_1 >= -100 && pub_r001417_1 <= 100);
    __CPROVER_assume(pub_r001417_2 >= -100 && pub_r001417_2 <= 100);
    __CPROVER_assume(pub_r001417_3 >= -100 && pub_r001417_3 <= 100);
    __CPROVER_assume(pub_r001417_4 >= -100 && pub_r001417_4 <= 100);
    __CPROVER_assume(pub_r001417_5 >= -100 && pub_r001417_5 <= 100);
    __CPROVER_assume(pub_r001417_6 >= -100 && pub_r001417_6 <= 100);
    __CPROVER_assume(pub_r001417_7 >= -100 && pub_r001417_7 <= 100);
    __CPROVER_assume(pub_r001417_8 >= -100 && pub_r001417_8 <= 100);
    __CPROVER_assume(pub_r001417_9 >= -100 && pub_r001417_9 <= 100);
    __CPROVER_assume(pub_r001417_10 >= -100 && pub_r001417_10 <= 100);
    __CPROVER_assume(pub_r001417_11 >= -100 && pub_r001417_11 <= 100);
    __CPROVER_assume(pub_r001417_12 >= -100 && pub_r001417_12 <= 100);
    __CPROVER_assume(pub_r001417_13 >= -100 && pub_r001417_13 <= 100);
    __CPROVER_assume(pub_r001417_14 >= -100 && pub_r001417_14 <= 100);
    __CPROVER_assume(pub_r001417_15 >= -100 && pub_r001417_15 <= 100);
    __CPROVER_assume(pub_r001417_16 >= -100 && pub_r001417_16 <= 100);
    __CPROVER_assume(pub_r001417_17 >= -100 && pub_r001417_17 <= 100);
    __CPROVER_assume(pub_r001417_18 >= -100 && pub_r001417_18 <= 100);
    __CPROVER_assume(pub_r001417_19 >= -100 && pub_r001417_19 <= 100);
    __CPROVER_assume(pub_r001417_20 >= -100 && pub_r001417_20 <= 100);
    __CPROVER_assume(pub_r001417_21 >= -100 && pub_r001417_21 <= 100);
    __CPROVER_assume(pub_r001417_22 >= -100 && pub_r001417_22 <= 100);
    __CPROVER_assume(sec_r001417_0 >= 0 && sec_r001417_0 <= 255);
    __CPROVER_assume(sec_r001417_1 >= 0 && sec_r001417_1 <= 255);
    __CPROVER_assume(sec_r001417_2 >= 0 && sec_r001417_2 <= 255);
    __CPROVER_assume(sec_r001417_3 >= 0 && sec_r001417_3 <= 255);
    __CPROVER_assume(sec_r001417_4 >= 0 && sec_r001417_4 <= 255);
    __CPROVER_assume(sec_r001417_5 >= 0 && sec_r001417_5 <= 255);
    __CPROVER_assume(sec_r001417_6 >= 0 && sec_r001417_6 <= 255);
    __CPROVER_assume(sec_r001417_7 >= 0 && sec_r001417_7 <= 255);
    __CPROVER_assume(sec_r001417_8 >= 0 && sec_r001417_8 <= 255);
    __CPROVER_assume(sec_r001417_9 >= 0 && sec_r001417_9 <= 255);
    __CPROVER_assume(sec_r001417_10 >= 0 && sec_r001417_10 <= 255);
    __CPROVER_assume(sec_r001417_11 >= 0 && sec_r001417_11 <= 255);
    __CPROVER_assume(sec_r001417_12 >= 0 && sec_r001417_12 <= 255);
    __CPROVER_assume(sec_r001417_13 >= 0 && sec_r001417_13 <= 255);
    __CPROVER_assume(sec_r001417_14 >= 0 && sec_r001417_14 <= 255);
    __CPROVER_assume(sec_r001417_15 >= 0 && sec_r001417_15 <= 255);
    __CPROVER_assume(sec_r001417_16 >= 0 && sec_r001417_16 <= 255);
    __CPROVER_assume(sec_r001417_17 >= 0 && sec_r001417_17 <= 255);
    __CPROVER_assume(sec_r001417_18 >= 0 && sec_r001417_18 <= 255);
    __CPROVER_assume(sec_r001417_19 >= 0 && sec_r001417_19 <= 255);
    __CPROVER_assume(sec_r001417_20 >= 0 && sec_r001417_20 <= 255);

    struct AudioFrame_R001417_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001417_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001417_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001417_0 + 7) & 15;
    struct CipherContext_R001417_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001417_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001417_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001417_0 + 9) & 15;
    struct SensorNode_R001417_1713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001417_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001417_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001417_0 + 11) & 15;

    union TelemetryField_R001417_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001417_1713_0(sec_r001417_0, pub_r001417_1);
    int helper_flow_1 = fn_R001417_1713_1(sec_r001417_1, pub_r001417_2, pub_r001417_3, pub_r001417_4);
    int helper_flow_2 = fn_R001417_1713_2(sec_r001417_2, pub_r001417_3, pub_r001417_4);
    int helper_flow_3 = fn_R001417_1713_3(sec_r001417_3, sec_r001417_4, pub_r001417_5, pub_r001417_6);
    int helper_flow_4 = fn_R001417_1713_4(sec_r001417_4, sec_r001417_5);
    int helper_flow_5 = fn_R001417_1713_5(sec_r001417_5, pub_r001417_6);
    int helper_flow_6 = fn_R001417_1713_6(sec_r001417_6, pub_r001417_7, pub_r001417_8, pub_r001417_9, pub_r001417_10);
    int helper_flow_7 = fn_R001417_1713_7(sec_r001417_7, sec_r001417_8);
    int helper_flow_8 = fn_R001417_1713_8(sec_r001417_8, pub_r001417_9, pub_r001417_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001417_13 ^ pub_r001417_17) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001417_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_6 ^ pub_r001417_16) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001417_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001417_3 ^ pub_r001417_17) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001417_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001417_1 ^ pub_r001417_16) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001417_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001417_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001417_3 ^ pub_r001417_16) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001417_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001417_13 ^ pub_r001417_14) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_3 ^ pub_r001417_21) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001417_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001417_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001417_3 ^ pub_r001417_7) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001417_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001417_7 ^ pub_r001417_16) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001417_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_7 ^ pub_r001417_11) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001417_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001417_4 ^ pub_r001417_2) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001417_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001417_13 ^ pub_r001417_3) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001417_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001417_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001417_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001417_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001417_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_0 ^ pub_r001417_22) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001417_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_11 ^ pub_r001417_20) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001417_12 ^ pub_r001417_18) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001417_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001417_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001417_20 ^ pub_r001417_15) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001417_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_24 ^ pub_r001417_5) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001417_19 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_9 ^ pub_r001417_3) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001417_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_11 ^ pub_r001417_10) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001417_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_4 ^ pub_r001417_17) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_7 ^ pub_r001417_4) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001417_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001417_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_9 ^ pub_r001417_13) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001417_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001417_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001417_13 ^ pub_r001417_5) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001417_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001417_13 ^ pub_r001417_17) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001417_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_5 ^ pub_r001417_10) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_2 ^ pub_r001417_5) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001417_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001417_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001417_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001417_0 ^ pub_r001417_14) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001417_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_21 ^ pub_r001417_19) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001417_5 ^ pub_r001417_18) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_6 ^ pub_r001417_0) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r001417_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001417_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001417_11 ^ pub_r001417_19) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001417_6 ^ pub_r001417_15) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001417_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001417_15 ^ pub_r001417_14) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_13 ^ pub_r001417_17) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001417_9 ^ pub_r001417_11) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001417_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001417_16 ^ pub_r001417_11) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_7 ^ pub_r001417_19) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (helper_flow_2 ^ pub_r001417_11) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r001417_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001417_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001417_0 ^ pub_r001417_5) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001417_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001417_15 ^ pub_r001417_6) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_13 ^ pub_r001417_13) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r001417_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_38 ^ pub_r001417_3) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r001417_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001417_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_48 ^ pub_r001417_11) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_28 ^ pub_r001417_0) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001417_4 ^ pub_r001417_12) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_57 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_4 ^ pub_r001417_2) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001417_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001417_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_11 ^ pub_r001417_8) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001417_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_42 ^ pub_r001417_6) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001417_4 ^ pub_r001417_1) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_15 ^ pub_r001417_12) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_0 ^ pub_r001417_13) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001417_15 ^ pub_r001417_19) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_69 ^ pub_r001417_8) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001417_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_73 ^ pub_r001417_12) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001417_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_43 ^ pub_r001417_21) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001417_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001417_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_49 ^ pub_r001417_16) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001417_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_42 ^ pub_r001417_21) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001417_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (helper_flow_5 ^ pub_r001417_14) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001417_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_0 ^ pub_r001417_21) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001417_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001417_17 ^ pub_r001417_17) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_9 ^ pub_r001417_2) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001417_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001417_13 ^ pub_r001417_22) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_69 ^ pub_r001417_13) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_73 ^ pub_r001417_9) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001417_21 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001417_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_63 ^ pub_r001417_20) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001417_12 ^ pub_r001417_8) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001417_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_71 ^ pub_r001417_14) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001417_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001417_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_35 ^ pub_r001417_21) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001417_15 ^ pub_r001417_10) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_45 ^ pub_r001417_6) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r001417_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_84 ^ pub_r001417_9) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_48 ^ pub_r001417_18) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001417_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_80 ^ pub_r001417_12) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_56 ^ pub_r001417_16) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_92 ^ pub_r001417_1) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001417_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001417_20 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_89 ^ pub_r001417_19) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_9 ^ pub_r001417_13) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r001417_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (sec_r001417_10 ^ pub_r001417_3) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_95 ^ pub_r001417_6) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_42 ^ pub_r001417_12) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001417_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001417_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001417_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001417_17 ^ pub_r001417_9) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001417_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_108 ^ pub_r001417_8) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r001417_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001417_22 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (helper_flow_2 ^ pub_r001417_3) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001417_9 ^ pub_r001417_19) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001417_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_57 ^ pub_r001417_0) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001417_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_37 ^ pub_r001417_3) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_67 ^ pub_r001417_19) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r001417_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001417_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r001417_4 ^ pub_r001417_21) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_76 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_6 ^ pub_r001417_18) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001417_19 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_24 ^ pub_r001417_16) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001417_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001417_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001417_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_131 ^ pub_r001417_8) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001417_19 ^ pub_r001417_6) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_56 ^ pub_r001417_2) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_91 ^ pub_r001417_5) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_124 ^ pub_r001417_18) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (helper_flow_5 ^ pub_r001417_3) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_27 ^ pub_r001417_17) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001417_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001417_21 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_100 ^ pub_r001417_15) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001417_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (sec_r001417_16 ^ pub_r001417_2) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_140 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_42 ^ pub_r001417_7) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001417_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001417_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (helper_flow_6 ^ pub_r001417_16) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_103 ^ pub_r001417_15) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_42 ^ pub_r001417_9) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001417_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_149 ^ pub_r001417_20) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001417_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001417_22 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_153 ^ pub_r001417_20) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001417_19 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001417_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001417_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_104 ^ pub_r001417_8) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_157 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_73 ^ pub_r001417_17) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_51 ^ pub_r001417_14) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_38 ^ pub_r001417_0) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_107 ^ pub_r001417_19) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((sec_r001417_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001417_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001417_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_58 ^ pub_r001417_8) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_2 ^ pub_r001417_13) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_157 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001417_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_64 ^ pub_r001417_4) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001417_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001417_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001417_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001417_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_114 ^ pub_r001417_14) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_174 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_28 ^ pub_r001417_12) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_143 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_144 ^ pub_r001417_9) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_35 ^ pub_r001417_12) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_1 ^ pub_r001417_10) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_86 ^ pub_r001417_22) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001417_21 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_37 ^ pub_r001417_9) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
