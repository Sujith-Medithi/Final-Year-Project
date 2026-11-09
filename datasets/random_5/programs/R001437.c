/*
 * Benchmark Program: R001437
 * Security Family: nested_implicit_flow
 * Generator Seed: 643713
 * High Inputs: 20 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001437_3713_0 {
    unsigned char envelope;
    short sample_rate;
    int peak;
    unsigned char rms;
    int channels;
    int gain;
    int buffer[3];
};

struct FilterState_R001437_3713_1 {
    int mode;
    unsigned char damping;
    unsigned char prev_in;
    int buffer[3];
};

struct StreamBuffer_R001437_3713_2 {
    unsigned char capacity;
    short watermark;
    short tail;
    unsigned char head;
    unsigned char checksum;
    short state;
    int buffer[3];
};

struct SensorNode_R001437_3713_3 {
    short gain;
    short reading;
    int calib;
    short threshold;
    int status;
    int offset;
    int buffer[3];
};

union RegisterBank_R001437_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001437_3713_0(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int offset_72 = local_arr[aux % 3];
    acc = (acc + offset_72 * 2) & 127;
    int cursor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001437_3713_1(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quantum_64 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_64 = (quantum_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_64) & 127;
    }
    int residue_69 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_69 > 42) {
        acc = (acc + residue_69 * 2 + 5) & 127;
        aux ^= (residue_69 & 15);
    } else {
        acc = (acc - residue_69 + 11) & 127;
        aux += 3;
    }
    int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_75) & 63;
    acc ^= aux;
    int quotient_52 = (aux + st.buffer[1]) & 3;
    switch (quotient_52) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_2(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_40) & 63;
    acc ^= aux;
    int threshold_77 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_77 > 20) {
        acc = (acc + threshold_77 * 2 + 5) & 127;
        aux ^= (threshold_77 & 15);
    } else {
        acc = (acc - threshold_77 + 11) & 127;
        aux += 3;
    }
    int vector_89 = 0;
    for (int k = 0; k < 2; k++) {
        vector_89 = (vector_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_89) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001437_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_10 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_10 > 11) {
        acc = (acc + cursor_10 * 2 + 5) & 127;
        aux ^= (cursor_10 & 15);
    } else {
        acc = (acc - cursor_10 + 11) & 127;
        aux += 3;
    }
    int delta_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_85 = 0;
    for (int k = 0; k < 3; k++) {
        tally_85 = (tally_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001437_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quotient_85 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_85 > 31) {
        acc = (acc + quotient_85 * 2 + 5) & 127;
        aux ^= (quotient_85 & 15);
    } else {
        acc = (acc - quotient_85 + 11) & 127;
        aux += 3;
    }
    int tracker_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001437_3713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_29) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_64 = local_arr[aux % 3];
    acc = (acc + cursor_64 * 2) & 127;
    int parity_85 = 0;
    for (int k = 0; k < 2; k++) {
        parity_85 = (parity_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_6(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001437_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int pivot_28 = local_arr[aux % 3];
    acc = (acc + pivot_28 * 2) & 127;
    int quantum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_25) & 63;
    acc ^= aux;
    int vector_36 = (aux + st.buffer[1]) & 3;
    switch (vector_36) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_7(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int segment_64 = 0;
    for (int k = 0; k < 3; k++) {
        segment_64 = (segment_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_64) & 127;
    }
    int index_reg_44 = (aux + st.buffer[1]) & 3;
    switch (index_reg_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_42 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_42 > 40) {
        acc = (acc + damping_42 * 2 + 5) & 127;
        aux ^= (damping_42 & 15);
    } else {
        acc = (acc - damping_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quotient_18 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_18 = (quotient_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_18) & 127;
    }
    int tracker_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001437_3713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int coefficient_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_70) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001437_3713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_23 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_23 > 28) {
        acc = (acc + bound_23 * 2 + 5) & 127;
        aux ^= (bound_23 & 15);
    } else {
        acc = (acc - bound_23 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_34 = (aux + st.buffer[1]) & 3;
    switch (vector_34) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_58 = 0;
    for (int k = 0; k < 3; k++) {
        weight_58 = (weight_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001437_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int parity_65 = (aux + st.buffer[1]) & 3;
    switch (parity_65) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001437_3713_12(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_17) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_20 = local_arr[aux % 3];
    acc = (acc + residue_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_45 = (aux + st.buffer[1]) & 3;
    switch (offset_45) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001437_3713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_38) & 63;
    acc ^= aux;
    int phase_56 = 0;
    for (int k = 0; k < 3; k++) {
        phase_56 = (phase_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_56) & 127;
    }
    int pivot_45 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_45 > 11) {
        acc = (acc + pivot_45 * 2 + 5) & 127;
        aux ^= (pivot_45 & 15);
    } else {
        acc = (acc - pivot_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001437_3713_14(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_13 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_13 > 20) {
        acc = (acc + anchor_13 * 2 + 5) & 127;
        aux ^= (anchor_13 & 15);
    } else {
        acc = (acc - anchor_13 + 11) & 127;
        aux += 3;
    }
    int sample_25 = 0;
    for (int k = 0; k < 2; k++) {
        sample_25 = (sample_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_25) & 127;
    }
    int window_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001437_3713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001437_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int scale_59 = (aux + st.buffer[1]) & 3;
    switch (scale_59) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_26 = 0;
    for (int k = 0; k < 2; k++) {
        weight_26 = (weight_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_26) & 127;
    }
    int vector_83 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_83 > 15) {
        acc = (acc + vector_83 * 2 + 5) & 127;
        aux ^= (vector_83 & 15);
    } else {
        acc = (acc - vector_83 + 11) & 127;
        aux += 3;
    }
    int tally_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001437_3713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001437_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_31 = local_arr[aux % 3];
    acc = (acc + anchor_31 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001437_0;
    int sec_r001437_1;
    int sec_r001437_2;
    int sec_r001437_3;
    int sec_r001437_4;
    int sec_r001437_5;
    int sec_r001437_6;
    int sec_r001437_7;
    int sec_r001437_8;
    int sec_r001437_9;
    int sec_r001437_10;
    int sec_r001437_11;
    int sec_r001437_12;
    int sec_r001437_13;
    int sec_r001437_14;
    int sec_r001437_15;
    int sec_r001437_16;
    int sec_r001437_17;
    int sec_r001437_18;
    int sec_r001437_19;
    int pub_r001437_0;
    int pub_r001437_1;
    int pub_r001437_2;
    int pub_r001437_3;
    int pub_r001437_4;
    int pub_r001437_5;
    int pub_r001437_6;
    int pub_r001437_7;
    int pub_r001437_8;
    int pub_r001437_9;
    int pub_r001437_10;
    int pub_r001437_11;
    int pub_r001437_12;
    int pub_r001437_13;
    int pub_r001437_14;
    int pub_r001437_15;
    int pub_r001437_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001437_0 >= -100 && pub_r001437_0 <= 100);
    __CPROVER_assume(pub_r001437_1 >= -100 && pub_r001437_1 <= 100);
    __CPROVER_assume(pub_r001437_2 >= -100 && pub_r001437_2 <= 100);
    __CPROVER_assume(pub_r001437_3 >= -100 && pub_r001437_3 <= 100);
    __CPROVER_assume(pub_r001437_4 >= -100 && pub_r001437_4 <= 100);
    __CPROVER_assume(pub_r001437_5 >= -100 && pub_r001437_5 <= 100);
    __CPROVER_assume(pub_r001437_6 >= -100 && pub_r001437_6 <= 100);
    __CPROVER_assume(pub_r001437_7 >= -100 && pub_r001437_7 <= 100);
    __CPROVER_assume(pub_r001437_8 >= -100 && pub_r001437_8 <= 100);
    __CPROVER_assume(pub_r001437_9 >= -100 && pub_r001437_9 <= 100);
    __CPROVER_assume(pub_r001437_10 >= -100 && pub_r001437_10 <= 100);
    __CPROVER_assume(pub_r001437_11 >= -100 && pub_r001437_11 <= 100);
    __CPROVER_assume(pub_r001437_12 >= -100 && pub_r001437_12 <= 100);
    __CPROVER_assume(pub_r001437_13 >= -100 && pub_r001437_13 <= 100);
    __CPROVER_assume(pub_r001437_14 >= -100 && pub_r001437_14 <= 100);
    __CPROVER_assume(pub_r001437_15 >= -100 && pub_r001437_15 <= 100);
    __CPROVER_assume(pub_r001437_16 >= -100 && pub_r001437_16 <= 100);
    __CPROVER_assume(sec_r001437_0 >= 0 && sec_r001437_0 <= 255);
    __CPROVER_assume(sec_r001437_1 >= 0 && sec_r001437_1 <= 255);
    __CPROVER_assume(sec_r001437_2 >= 0 && sec_r001437_2 <= 255);
    __CPROVER_assume(sec_r001437_3 >= 0 && sec_r001437_3 <= 255);
    __CPROVER_assume(sec_r001437_4 >= 0 && sec_r001437_4 <= 255);
    __CPROVER_assume(sec_r001437_5 >= 0 && sec_r001437_5 <= 255);
    __CPROVER_assume(sec_r001437_6 >= 0 && sec_r001437_6 <= 255);
    __CPROVER_assume(sec_r001437_7 >= 0 && sec_r001437_7 <= 255);
    __CPROVER_assume(sec_r001437_8 >= 0 && sec_r001437_8 <= 255);
    __CPROVER_assume(sec_r001437_9 >= 0 && sec_r001437_9 <= 255);
    __CPROVER_assume(sec_r001437_10 >= 0 && sec_r001437_10 <= 255);
    __CPROVER_assume(sec_r001437_11 >= 0 && sec_r001437_11 <= 255);
    __CPROVER_assume(sec_r001437_12 >= 0 && sec_r001437_12 <= 255);
    __CPROVER_assume(sec_r001437_13 >= 0 && sec_r001437_13 <= 255);
    __CPROVER_assume(sec_r001437_14 >= 0 && sec_r001437_14 <= 255);
    __CPROVER_assume(sec_r001437_15 >= 0 && sec_r001437_15 <= 255);
    __CPROVER_assume(sec_r001437_16 >= 0 && sec_r001437_16 <= 255);
    __CPROVER_assume(sec_r001437_17 >= 0 && sec_r001437_17 <= 255);
    __CPROVER_assume(sec_r001437_18 >= 0 && sec_r001437_18 <= 255);
    __CPROVER_assume(sec_r001437_19 >= 0 && sec_r001437_19 <= 255);

    struct AudioFrame_R001437_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001437_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001437_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001437_0 + 7) & 15;
    struct FilterState_R001437_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001437_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001437_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001437_0 + 9) & 15;
    struct StreamBuffer_R001437_3713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001437_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001437_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001437_0 + 11) & 15;
    struct SensorNode_R001437_3713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001437_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001437_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001437_0 + 13) & 15;

    union RegisterBank_R001437_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001437_3713_0(sec_r001437_0, pub_r001437_1);
    int helper_flow_1 = fn_R001437_3713_1(sec_r001437_1, sec_r001437_2);
    int helper_flow_2 = fn_R001437_3713_2(sec_r001437_2, sec_r001437_3, pub_r001437_4);
    int helper_flow_3 = fn_R001437_3713_3(sec_r001437_3, sec_r001437_4, pub_r001437_5, pub_r001437_6);
    int helper_flow_4 = fn_R001437_3713_4(sec_r001437_4, sec_r001437_5, pub_r001437_6, pub_r001437_7, pub_r001437_8);
    int helper_flow_5 = fn_R001437_3713_5(sec_r001437_5, pub_r001437_6, pub_r001437_7, pub_r001437_8);
    int helper_flow_6 = fn_R001437_3713_6(sec_r001437_6, pub_r001437_7, pub_r001437_8);
    int helper_flow_7 = fn_R001437_3713_7(sec_r001437_7, sec_r001437_8, pub_r001437_9);
    int helper_flow_8 = fn_R001437_3713_8(sec_r001437_8, sec_r001437_9, pub_r001437_10, pub_r001437_11, pub_r001437_12);
    int helper_flow_9 = fn_R001437_3713_9(sec_r001437_9, sec_r001437_10, pub_r001437_11, pub_r001437_12, pub_r001437_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001437_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001437_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001437_11 ^ pub_r001437_16) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001437_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001437_10 ^ pub_r001437_8) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001437_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001437_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001437_14 ^ pub_r001437_6) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001437_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (helper_flow_4 ^ pub_r001437_12) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001437_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_5 ^ pub_r001437_7) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001437_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001437_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001437_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001437_9 ^ pub_r001437_14) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001437_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001437_9 ^ pub_r001437_10) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001437_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_8 ^ pub_r001437_6) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001437_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_5 ^ pub_r001437_14) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_3 ^ pub_r001437_6) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_3 ^ pub_r001437_5) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001437_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001437_8 ^ pub_r001437_4) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001437_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001437_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001437_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_8 ^ pub_r001437_8) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001437_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001437_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001437_14 ^ pub_r001437_7) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001437_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_15 ^ pub_r001437_16) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001437_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001437_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_19 ^ pub_r001437_1) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r001437_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_14 ^ pub_r001437_1) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (helper_flow_4 ^ pub_r001437_11) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001437_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001437_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_3 ^ pub_r001437_14) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_3 ^ pub_r001437_1) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_14 ^ pub_r001437_4) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001437_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001437_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001437_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (helper_flow_8 ^ pub_r001437_10) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001437_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_21 ^ pub_r001437_3) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001437_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_38 ^ pub_r001437_0) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_21 ^ pub_r001437_8) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001437_5 ^ pub_r001437_7) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r001437_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_40 ^ pub_r001437_14) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001437_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001437_6 ^ pub_r001437_13) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001437_9 ^ pub_r001437_2) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r001437_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001437_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (helper_flow_9 ^ pub_r001437_6) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_2 ^ pub_r001437_6) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_42 ^ pub_r001437_5) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_2 ^ pub_r001437_9) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_11 ^ pub_r001437_15) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001437_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001437_19 ^ pub_r001437_2) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_28 ^ pub_r001437_12) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_21 ^ pub_r001437_10) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001437_18 ^ pub_r001437_15) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001437_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001437_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001437_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001437_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_48 ^ pub_r001437_4) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001437_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001437_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_5 ^ pub_r001437_1) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_54 ^ pub_r001437_8) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_12 ^ pub_r001437_12) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001437_5 ^ pub_r001437_6) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r001437_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_12 ^ pub_r001437_16) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001437_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_67 ^ pub_r001437_14) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_48 ^ pub_r001437_9) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (helper_flow_5 ^ pub_r001437_9) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r001437_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_38 ^ pub_r001437_6) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001437_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001437_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_23 ^ pub_r001437_4) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001437_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_64 ^ pub_r001437_14) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001437_14 ^ pub_r001437_7) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_50 ^ pub_r001437_9) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r001437_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_3 ^ pub_r001437_7) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_16 ^ pub_r001437_7) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r001437_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_77 ^ pub_r001437_2) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001437_16 ^ pub_r001437_16) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_42 ^ pub_r001437_5) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001437_5 ^ pub_r001437_16) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001437_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001437_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001437_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (helper_flow_6 ^ pub_r001437_16) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_23 ^ pub_r001437_13) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001437_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001437_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_10 ^ pub_r001437_7) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_80 ^ pub_r001437_2) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_33 ^ pub_r001437_3) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001437_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_36 ^ pub_r001437_0) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_3 ^ pub_r001437_2) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001437_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001437_7 ^ pub_r001437_9) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001437_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001437_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_96 ^ pub_r001437_2) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_61 ^ pub_r001437_13) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_26 ^ pub_r001437_14) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001437_8 ^ pub_r001437_4) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r001437_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_101 ^ pub_r001437_16) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_16 ^ pub_r001437_16) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (sec_r001437_2 ^ pub_r001437_3) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_45 ^ pub_r001437_13) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r001437_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (helper_flow_5 ^ pub_r001437_16) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r001437_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001437_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001437_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001437_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (sec_r001437_7 ^ pub_r001437_15) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001437_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_5 ^ pub_r001437_5) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_56 ^ pub_r001437_14) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001437_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (helper_flow_9 ^ pub_r001437_3) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_103 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001437_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001437_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_49 ^ pub_r001437_13) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_36 ^ pub_r001437_13) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_26 ^ pub_r001437_2) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_15 ^ pub_r001437_13) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_15 ^ pub_r001437_1) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001437_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001437_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001437_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_23 ^ pub_r001437_2) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001437_9 ^ pub_r001437_10) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001437_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_84 ^ pub_r001437_11) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_16 ^ pub_r001437_10) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001437_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_50 ^ pub_r001437_3) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001437_3 ^ pub_r001437_10) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_69 ^ pub_r001437_5) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001437_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (sec_r001437_0 ^ pub_r001437_0) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001437_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (helper_flow_4 ^ pub_r001437_9) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_130 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001437_3 ^ pub_r001437_13) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001437_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001437_15 ^ pub_r001437_10) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_117 ^ pub_r001437_0) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_13 ^ pub_r001437_14) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_66 ^ pub_r001437_16) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_106 ^ pub_r001437_8) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r001437_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_83 ^ pub_r001437_9) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001437_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_123 ^ pub_r001437_10) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_64 ^ pub_r001437_10) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_149 ^ pub_r001437_11) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_32 ^ pub_r001437_15) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_122 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001437_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_127 ^ pub_r001437_10) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (helper_flow_4 ^ pub_r001437_1) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001437_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (helper_flow_8 ^ pub_r001437_0) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_149 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_14 ^ pub_r001437_15) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001437_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (helper_flow_0 ^ pub_r001437_6) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((sec_r001437_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_137 ^ pub_r001437_4) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((sec_r001437_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001437_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_49 ^ pub_r001437_6) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_103 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r001437_7 ^ pub_r001437_12) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_11 ^ pub_r001437_12) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001437_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001437_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_98 ^ pub_r001437_2) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_146 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_82 ^ pub_r001437_10) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_77 ^ pub_r001437_16) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r001437_8 ^ pub_r001437_15) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_151 ^ pub_r001437_5) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (helper_flow_4 ^ pub_r001437_10) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_102 ^ pub_r001437_15) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_154 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_89 ^ pub_r001437_3) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001437_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (helper_flow_8 ^ pub_r001437_1) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (sec_r001437_17 ^ pub_r001437_11) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001437_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_89 ^ pub_r001437_13) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_160 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_117 ^ pub_r001437_13) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_12 ^ pub_r001437_7) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001437_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001437_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_149 ^ pub_r001437_11) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_134 ^ pub_r001437_14) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((sec_r001437_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_158 ^ pub_r001437_3) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001437_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001437_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_178 ^ pub_r001437_5) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_149 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001437_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001437_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_68 ^ pub_r001437_14) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001437_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (helper_flow_3 ^ pub_r001437_1) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_134 ^ pub_r001437_3) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001437_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001437_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_146 ^ pub_r001437_13) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_133 ^ pub_r001437_2) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_134 ^ pub_r001437_4) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001437_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_108 ^ pub_r001437_0) & 63;
    if ((stage_v_203 & 1) != 0) {
        if ((stage_v_151 & 2) != 0) {
            out_sink = (out_sink + stage_v_203 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_203 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_145 ^ pub_r001437_8) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001437_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_81 ^ pub_r001437_9) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_116 ^ pub_r001437_3) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((stage_v_152 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001437_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_55 ^ pub_r001437_7) & 63;
    if ((stage_v_209 & 1) != 0) {
        if ((stage_v_161 & 2) != 0) {
            out_sink = (out_sink + stage_v_209 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_209 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_49 ^ pub_r001437_15) & 63;
    if ((stage_v_210 & 1) != 0) {
        if ((stage_v_195 & 2) != 0) {
            out_sink = (out_sink + stage_v_210 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_210 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_163 ^ pub_r001437_16) & 63;
    if ((stage_v_211 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_211 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_211 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001437_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_98 ^ pub_r001437_15) & 63;
    if ((stage_v_213 & 1) != 0) {
        if ((stage_v_96 & 2) != 0) {
            out_sink = (out_sink + stage_v_213 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_213 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_128 ^ pub_r001437_1) & 63;
    if ((stage_v_214 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_214 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_214 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_55 ^ pub_r001437_4) & 63;
    if ((stage_v_215 & 1) != 0) {
        if ((stage_v_163 & 2) != 0) {
            out_sink = (out_sink + stage_v_215 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_215 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
