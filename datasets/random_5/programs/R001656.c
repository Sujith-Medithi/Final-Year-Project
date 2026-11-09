/*
 * Benchmark Program: R001656
 * Security Family: implicit_flow
 * Generator Seed: 665613
 * High Inputs: 21 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001656_5613_0 {
    short gain;
    int calib;
    short reading;
    int buffer[3];
};

struct CipherContext_R001656_5613_1 {
    int iv;
    int flags;
    short tag;
    int counter;
    int buffer[3];
};

union PacketPayload_R001656_5613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001656_5613_0(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001656_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int window_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_18) & 63;
    acc ^= aux;
    int sample_16 = 0;
    for (int k = 0; k < 2; k++) {
        sample_16 = (sample_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_16) & 127;
    }
    int accumulator_90 = (aux + st.buffer[1]) & 3;
    switch (accumulator_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001656_5613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001656_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_57 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_57 > 27) {
        acc = (acc + accumulator_57 * 2 + 5) & 127;
        aux ^= (accumulator_57 & 15);
    } else {
        acc = (acc - accumulator_57 + 11) & 127;
        aux += 3;
    }
    int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001656_5613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001656_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_83 = 0;
    for (int k = 0; k < 2; k++) {
        metric_83 = (metric_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_83) & 127;
    }
    int parity_27 = (aux + st.buffer[1]) & 3;
    switch (parity_27) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001656_5613_3(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001656_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_93 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_93 > 42) {
        acc = (acc + segment_93 * 2 + 5) & 127;
        aux ^= (segment_93 & 15);
    } else {
        acc = (acc - segment_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001656_5613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001656_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int weight_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_75) & 63;
    acc ^= aux;
    int metric_42 = (aux + st.buffer[1]) & 3;
    switch (metric_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001656_5613_5(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001656_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int accumulator_10 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_10 > 48) {
        acc = (acc + accumulator_10 * 2 + 5) & 127;
        aux ^= (accumulator_10 & 15);
    } else {
        acc = (acc - accumulator_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_76 = local_arr[aux % 3];
    acc = (acc + quantum_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001656_5613_6(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001656_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int checksum_16 = local_arr[aux % 3];
    acc = (acc + checksum_16 * 2) & 127;
    int segment_71 = 0;
    for (int k = 0; k < 3; k++) {
        segment_71 = (segment_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001656_5613_7(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001656_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int residue_85 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_85 > 42) {
        acc = (acc + residue_85 * 2 + 5) & 127;
        aux ^= (residue_85 & 15);
    } else {
        acc = (acc - residue_85 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_12 = (aux + st.buffer[1]) & 3;
    switch (quotient_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_62 = local_arr[aux % 3];
    acc = (acc + phase_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001656_5613_8(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001656_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int bound_72 = local_arr[aux % 3];
    acc = (acc + bound_72 * 2) & 127;
    int quantum_85 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_85 > 15) {
        acc = (acc + quantum_85 * 2 + 5) & 127;
        aux ^= (quantum_85 & 15);
    } else {
        acc = (acc - quantum_85 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_86 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_86 = (pivot_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_86) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001656_5613_9(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001656_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int sample_93 = local_arr[aux % 3];
    acc = (acc + sample_93 * 2) & 127;
    int index_reg_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_23) & 63;
    acc ^= aux;
    int segment_87 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_87 > 49) {
        acc = (acc + segment_87 * 2 + 5) & 127;
        aux ^= (segment_87 & 15);
    } else {
        acc = (acc - segment_87 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001656_5613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001656_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int window_40 = (aux + st.buffer[1]) & 3;
    switch (window_40) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001656_5613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001656_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int checksum_51 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_51 > 43) {
        acc = (acc + checksum_51 * 2 + 5) & 127;
        aux ^= (checksum_51 & 15);
    } else {
        acc = (acc - checksum_51 + 11) & 127;
        aux += 3;
    }
    int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_89) & 63;
    acc ^= aux;
    int quantum_20 = (aux + st.buffer[1]) & 3;
    switch (quantum_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_44 = 0;
    for (int k = 0; k < 3; k++) {
        parity_44 = (parity_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_44) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001656_5613_12(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001656_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int anchor_45 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_45 = (anchor_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_45) & 127;
    }
    int tally_83 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_83 > 15) {
        acc = (acc + tally_83 * 2 + 5) & 127;
        aux ^= (tally_83 & 15);
    } else {
        acc = (acc - tally_83 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001656_5613_13(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001656_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tracker_20 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_20 = (tracker_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_20) & 127;
    }
    int parity_78 = (aux + st.buffer[1]) & 3;
    switch (parity_78) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_78 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_78 > 26) {
        acc = (acc + vector_78 * 2 + 5) & 127;
        aux ^= (vector_78 & 15);
    } else {
        acc = (acc - vector_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_10 = local_arr[aux % 3];
    acc = (acc + tally_10 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001656_0;
    int sec_r001656_1;
    int sec_r001656_2;
    int sec_r001656_3;
    int sec_r001656_4;
    int sec_r001656_5;
    int sec_r001656_6;
    int sec_r001656_7;
    int sec_r001656_8;
    int sec_r001656_9;
    int sec_r001656_10;
    int sec_r001656_11;
    int sec_r001656_12;
    int sec_r001656_13;
    int sec_r001656_14;
    int sec_r001656_15;
    int sec_r001656_16;
    int sec_r001656_17;
    int sec_r001656_18;
    int sec_r001656_19;
    int sec_r001656_20;
    int pub_r001656_0;
    int pub_r001656_1;
    int pub_r001656_2;
    int pub_r001656_3;
    int pub_r001656_4;
    int pub_r001656_5;
    int pub_r001656_6;
    int pub_r001656_7;
    int pub_r001656_8;
    int pub_r001656_9;
    int pub_r001656_10;
    int pub_r001656_11;
    int pub_r001656_12;
    int pub_r001656_13;
    int pub_r001656_14;
    int pub_r001656_15;
    int pub_r001656_16;
    int pub_r001656_17;
    int pub_r001656_18;
    int pub_r001656_19;
    int pub_r001656_20;
    int pub_r001656_21;
    int pub_r001656_22;
    int pub_r001656_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001656_0 >= -100 && pub_r001656_0 <= 100);
    __CPROVER_assume(pub_r001656_1 >= -100 && pub_r001656_1 <= 100);
    __CPROVER_assume(pub_r001656_2 >= -100 && pub_r001656_2 <= 100);
    __CPROVER_assume(pub_r001656_3 >= -100 && pub_r001656_3 <= 100);
    __CPROVER_assume(pub_r001656_4 >= -100 && pub_r001656_4 <= 100);
    __CPROVER_assume(pub_r001656_5 >= -100 && pub_r001656_5 <= 100);
    __CPROVER_assume(pub_r001656_6 >= -100 && pub_r001656_6 <= 100);
    __CPROVER_assume(pub_r001656_7 >= -100 && pub_r001656_7 <= 100);
    __CPROVER_assume(pub_r001656_8 >= -100 && pub_r001656_8 <= 100);
    __CPROVER_assume(pub_r001656_9 >= -100 && pub_r001656_9 <= 100);
    __CPROVER_assume(pub_r001656_10 >= -100 && pub_r001656_10 <= 100);
    __CPROVER_assume(pub_r001656_11 >= -100 && pub_r001656_11 <= 100);
    __CPROVER_assume(pub_r001656_12 >= -100 && pub_r001656_12 <= 100);
    __CPROVER_assume(pub_r001656_13 >= -100 && pub_r001656_13 <= 100);
    __CPROVER_assume(pub_r001656_14 >= -100 && pub_r001656_14 <= 100);
    __CPROVER_assume(pub_r001656_15 >= -100 && pub_r001656_15 <= 100);
    __CPROVER_assume(pub_r001656_16 >= -100 && pub_r001656_16 <= 100);
    __CPROVER_assume(pub_r001656_17 >= -100 && pub_r001656_17 <= 100);
    __CPROVER_assume(pub_r001656_18 >= -100 && pub_r001656_18 <= 100);
    __CPROVER_assume(pub_r001656_19 >= -100 && pub_r001656_19 <= 100);
    __CPROVER_assume(pub_r001656_20 >= -100 && pub_r001656_20 <= 100);
    __CPROVER_assume(pub_r001656_21 >= -100 && pub_r001656_21 <= 100);
    __CPROVER_assume(pub_r001656_22 >= -100 && pub_r001656_22 <= 100);
    __CPROVER_assume(pub_r001656_23 >= -100 && pub_r001656_23 <= 100);
    __CPROVER_assume(sec_r001656_0 >= 0 && sec_r001656_0 <= 255);
    __CPROVER_assume(sec_r001656_1 >= 0 && sec_r001656_1 <= 255);
    __CPROVER_assume(sec_r001656_2 >= 0 && sec_r001656_2 <= 255);
    __CPROVER_assume(sec_r001656_3 >= 0 && sec_r001656_3 <= 255);
    __CPROVER_assume(sec_r001656_4 >= 0 && sec_r001656_4 <= 255);
    __CPROVER_assume(sec_r001656_5 >= 0 && sec_r001656_5 <= 255);
    __CPROVER_assume(sec_r001656_6 >= 0 && sec_r001656_6 <= 255);
    __CPROVER_assume(sec_r001656_7 >= 0 && sec_r001656_7 <= 255);
    __CPROVER_assume(sec_r001656_8 >= 0 && sec_r001656_8 <= 255);
    __CPROVER_assume(sec_r001656_9 >= 0 && sec_r001656_9 <= 255);
    __CPROVER_assume(sec_r001656_10 >= 0 && sec_r001656_10 <= 255);
    __CPROVER_assume(sec_r001656_11 >= 0 && sec_r001656_11 <= 255);
    __CPROVER_assume(sec_r001656_12 >= 0 && sec_r001656_12 <= 255);
    __CPROVER_assume(sec_r001656_13 >= 0 && sec_r001656_13 <= 255);
    __CPROVER_assume(sec_r001656_14 >= 0 && sec_r001656_14 <= 255);
    __CPROVER_assume(sec_r001656_15 >= 0 && sec_r001656_15 <= 255);
    __CPROVER_assume(sec_r001656_16 >= 0 && sec_r001656_16 <= 255);
    __CPROVER_assume(sec_r001656_17 >= 0 && sec_r001656_17 <= 255);
    __CPROVER_assume(sec_r001656_18 >= 0 && sec_r001656_18 <= 255);
    __CPROVER_assume(sec_r001656_19 >= 0 && sec_r001656_19 <= 255);
    __CPROVER_assume(sec_r001656_20 >= 0 && sec_r001656_20 <= 255);

    struct SensorNode_R001656_5613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001656_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001656_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001656_0 + 7) & 15;
    struct CipherContext_R001656_5613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001656_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001656_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001656_0 + 9) & 15;

    union PacketPayload_R001656_5613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001656_5613_0(sec_r001656_0, sec_r001656_1, pub_r001656_2);
    int helper_flow_1 = fn_R001656_5613_1(sec_r001656_1, pub_r001656_2, pub_r001656_3, pub_r001656_4, pub_r001656_5);
    int helper_flow_2 = fn_R001656_5613_2(sec_r001656_2, pub_r001656_3, pub_r001656_4, pub_r001656_5, pub_r001656_6);
    int helper_flow_3 = fn_R001656_5613_3(sec_r001656_3, sec_r001656_4);
    int helper_flow_4 = fn_R001656_5613_4(sec_r001656_4, pub_r001656_5, pub_r001656_6, pub_r001656_7);
    int helper_flow_5 = fn_R001656_5613_5(sec_r001656_5, sec_r001656_6, pub_r001656_7);
    int helper_flow_6 = fn_R001656_5613_6(sec_r001656_6, sec_r001656_7, pub_r001656_8);
    int helper_flow_7 = fn_R001656_5613_7(sec_r001656_7, sec_r001656_8);
    int helper_flow_8 = fn_R001656_5613_8(sec_r001656_8, pub_r001656_9, pub_r001656_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001656_19 + pub_r001656_11 * 2 + 5) & 127;
    if (stage_v_0 > 48) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001656_20 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001656_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001656_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001656_23 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001656_12 + pub_r001656_7 * 2 + 20) & 127;
    if (stage_v_5 > 24) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (stage_v_0 + pub_r001656_17 * 2 + 23) & 127;
    if (stage_v_6 > 41) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001656_3 + pub_r001656_20 * 2 + 26) & 127;
    if (stage_v_7 > 46) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001656_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001656_10 + pub_r001656_17 * 2 + 32) & 127;
    if (stage_v_9 > 20) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_6 + pub_r001656_15 * 2 + 35) & 127;
    if (stage_v_10 > 55) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_1 + pub_r001656_5 * 2 + 38) & 127;
    if (stage_v_11 > 19) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001656_2 + pub_r001656_16 * 2 + 41) & 127;
    if (stage_v_12 > 23) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_7 + pub_r001656_23 * 2 + 44) & 127;
    if (stage_v_13 > 31) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001656_4 + pub_r001656_13 * 2 + 47) & 127;
    if (stage_v_14 > 35) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001656_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001656_5 + pub_r001656_2 * 2 + 53) & 127;
    if (stage_v_16 > 35) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001656_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001656_6 + pub_r001656_11 * 2 + 59) & 127;
    if (stage_v_18 > 17) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001656_0 + pub_r001656_0 * 2 + 62) & 127;
    if (stage_v_19 > 46) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001656_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_7 + pub_r001656_1 * 2 + 68) & 127;
    if (stage_v_21 > 25) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001656_19 + pub_r001656_3 * 2 + 71) & 127;
    if (stage_v_22 > 26) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001656_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001656_15 + pub_r001656_14 * 2 + 77) & 127;
    if (stage_v_24 > 41) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_7 + pub_r001656_8 * 2 + 80) & 127;
    if (stage_v_25 > 17) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (helper_flow_0 + pub_r001656_2 * 2 + 83) & 127;
    if (stage_v_26 > 59) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_2 + pub_r001656_23 * 2 + 86) & 127;
    if (stage_v_27 > 37) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001656_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001656_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_4 + pub_r001656_10 * 2 + 95) & 127;
    if (stage_v_30 > 48) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001656_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_7 + pub_r001656_11 * 2 + 101) & 127;
    if (stage_v_32 > 15) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001656_23 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001656_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_9 + pub_r001656_13 * 2 + 110) & 127;
    if (stage_v_35 > 57) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_22 + pub_r001656_11 * 2 + 113) & 127;
    if (stage_v_36 > 53) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001656_15 + pub_r001656_5 * 2 + 116) & 127;
    if (stage_v_37 > 23) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001656_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001656_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001656_13 + pub_r001656_5 * 2 + 125) & 127;
    if (stage_v_40 > 16) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001656_18 + pub_r001656_13 * 2 + 128) & 127;
    if (stage_v_41 > 26) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_1 + pub_r001656_0 * 2 + 131) & 127;
    if (stage_v_42 > 57) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001656_19 + pub_r001656_11 * 2 + 134) & 127;
    if (stage_v_43 > 50) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001656_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_14 + pub_r001656_23 * 2 + 140) & 127;
    if (stage_v_45 > 22) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001656_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001656_17 + pub_r001656_19 * 2 + 146) & 127;
    if (stage_v_47 > 27) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001656_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_7 + pub_r001656_12 * 2 + 152) & 127;
    if (stage_v_49 > 36) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001656_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001656_15 + pub_r001656_19 * 2 + 158) & 127;
    if (stage_v_51 > 22) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001656_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_2 + pub_r001656_1 * 2 + 164) & 127;
    if (stage_v_53 > 31) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001656_22 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_8 + pub_r001656_3 * 2 + 170) & 127;
    if (stage_v_55 > 43) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_42 + pub_r001656_22 * 2 + 173) & 127;
    if (stage_v_56 > 34) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001656_5 + pub_r001656_5 * 2 + 176) & 127;
    if (stage_v_57 > 21) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001656_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001656_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001656_12 + pub_r001656_21 * 2 + 185) & 127;
    if (stage_v_60 > 48) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001656_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001656_22 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (helper_flow_4 + pub_r001656_4 * 2 + 194) & 127;
    if (stage_v_63 > 44) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001656_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001656_10 + pub_r001656_7 * 2 + 200) & 127;
    if (stage_v_65 > 20) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_2 + pub_r001656_7 * 2 + 203) & 127;
    if (stage_v_66 > 30) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001656_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_43 + pub_r001656_2 * 2 + 209) & 127;
    if (stage_v_68 > 41) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001656_13 + pub_r001656_6 * 2 + 212) & 127;
    if (stage_v_69 > 34) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r001656_4 + pub_r001656_11 * 2 + 215) & 127;
    if (stage_v_70 > 15) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_10 + pub_r001656_13 * 2 + 218) & 127;
    if (stage_v_71 > 36) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001656_10 + pub_r001656_15 * 2 + 221) & 127;
    if (stage_v_72 > 54) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_41 + pub_r001656_6 * 2 + 224) & 127;
    if (stage_v_73 > 46) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001656_14 + pub_r001656_20 * 2 + 227) & 127;
    if (stage_v_74 > 39) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001656_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001656_17 + pub_r001656_11 * 2 + 233) & 127;
    if (stage_v_76 > 50) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001656_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_32 + pub_r001656_11 * 2 + 239) & 127;
    if (stage_v_78 > 60) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_18 + pub_r001656_17 * 2 + 242) & 127;
    if (stage_v_79 > 59) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001656_8 + pub_r001656_3 * 2 + 245) & 127;
    if (stage_v_80 > 44) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_27 + pub_r001656_14 * 2 + 248) & 127;
    if (stage_v_81 > 38) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001656_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001656_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_65 + pub_r001656_1 * 2 + 257) & 127;
    if (stage_v_84 > 52) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001656_13 + pub_r001656_10 * 2 + 260) & 127;
    if (stage_v_85 > 52) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_65 + pub_r001656_21 * 2 + 263) & 127;
    if (stage_v_86 > 17) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_72 + pub_r001656_15 * 2 + 266) & 127;
    if (stage_v_87 > 15) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_9 + pub_r001656_14 * 2 + 269) & 127;
    if (stage_v_88 > 60) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_76 + pub_r001656_19 * 2 + 272) & 127;
    if (stage_v_89 > 54) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_6 + pub_r001656_18 * 2 + 275) & 127;
    if (stage_v_90 > 34) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_26 + pub_r001656_4 * 2 + 278) & 127;
    if (stage_v_91 > 38) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001656_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001656_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001656_19 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_6 + pub_r001656_10 * 2 + 290) & 127;
    if (stage_v_95 > 18) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001656_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001656_23 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_74 + pub_r001656_14 * 2 + 299) & 127;
    if (stage_v_98 > 30) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_16 + pub_r001656_8 * 2 + 302) & 127;
    if (stage_v_99 > 46) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001656_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001656_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_41 + pub_r001656_16 * 2 + 311) & 127;
    if (stage_v_102 > 45) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001656_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_47 + pub_r001656_16 * 2 + 317) & 127;
    if (stage_v_104 > 44) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_84 + pub_r001656_7 * 2 + 320) & 127;
    if (stage_v_105 > 54) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_68 + pub_r001656_17 * 2 + 323) & 127;
    if (stage_v_106 > 22) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_6 + pub_r001656_20 * 2 + 326) & 127;
    if (stage_v_107 > 15) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (helper_flow_4 + pub_r001656_15 * 2 + 329) & 127;
    if (stage_v_108 > 22) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_40 + pub_r001656_7 * 2 + 332) & 127;
    if (stage_v_109 > 54) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001656_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001656_12 + pub_r001656_16 * 2 + 338) & 127;
    if (stage_v_111 > 45) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_49 + pub_r001656_14 * 2 + 341) & 127;
    if (stage_v_112 > 55) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (sec_r001656_8 + pub_r001656_13 * 2 + 344) & 127;
    if (stage_v_113 > 39) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001656_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001656_12 + pub_r001656_2 * 2 + 350) & 127;
    if (stage_v_115 > 53) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001656_6 + pub_r001656_15 * 2 + 353) & 127;
    if (stage_v_116 > 42) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001656_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_79 + pub_r001656_11 * 2 + 359) & 127;
    if (stage_v_118 > 17) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001656_13 + pub_r001656_15 * 2 + 362) & 127;
    if (stage_v_119 > 27) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_56 + pub_r001656_5 * 2 + 365) & 127;
    if (stage_v_120 > 17) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (sec_r001656_6 + pub_r001656_5 * 2 + 368) & 127;
    if (stage_v_121 > 48) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001656_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (helper_flow_5 + pub_r001656_6 * 2 + 374) & 127;
    if (stage_v_123 > 35) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_11 + pub_r001656_3 * 2 + 377) & 127;
    if (stage_v_124 > 50) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_13 + pub_r001656_18 * 2 + 380) & 127;
    if (stage_v_125 > 22) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_105 + pub_r001656_19 * 2 + 383) & 127;
    if (stage_v_126 > 45) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_120 + pub_r001656_17 * 2 + 386) & 127;
    if (stage_v_127 > 33) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_99 + pub_r001656_19 * 2 + 389) & 127;
    if (stage_v_128 > 51) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001656_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r001656_3 + pub_r001656_1 * 2 + 395) & 127;
    if (stage_v_130 > 48) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001656_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001656_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001656_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001656_3 + pub_r001656_21 * 2 + 407) & 127;
    if (stage_v_134 > 22) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_76 + pub_r001656_5 * 2 + 410) & 127;
    if (stage_v_135 > 32) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_14 + pub_r001656_3 * 2 + 413) & 127;
    if (stage_v_136 > 30) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_111 + pub_r001656_22 * 2 + 416) & 127;
    if (stage_v_137 > 40) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (helper_flow_7 + pub_r001656_16 * 2 + 419) & 127;
    if (stage_v_138 > 27) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001656_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001656_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_49 + pub_r001656_19 * 2 + 428) & 127;
    if (stage_v_141 > 16) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_36 + pub_r001656_21 * 2 + 431) & 127;
    if (stage_v_142 > 38) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_49 + pub_r001656_9 * 2 + 434) & 127;
    if (stage_v_143 > 27) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_88 + pub_r001656_16 * 2 + 437) & 127;
    if (stage_v_144 > 22) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_111 + pub_r001656_4 * 2 + 440) & 127;
    if (stage_v_145 > 53) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_108 + pub_r001656_20 * 2 + 443) & 127;
    if (stage_v_146 > 56) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_144 + pub_r001656_2 * 2 + 446) & 127;
    if (stage_v_147 > 34) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_119 + pub_r001656_23 * 2 + 449) & 127;
    if (stage_v_148 > 37) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_113 + pub_r001656_19 * 2 + 452) & 127;
    if (stage_v_149 > 33) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (helper_flow_6 + pub_r001656_20 * 2 + 455) & 127;
    if (stage_v_150 > 18) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_66 + pub_r001656_6 * 2 + 458) & 127;
    if (stage_v_151 > 41) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r001656_18 + pub_r001656_16 * 2 + 461) & 127;
    if (stage_v_152 > 43) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_81 + pub_r001656_12 * 2 + 464) & 127;
    if (stage_v_153 > 15) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r001656_10 + pub_r001656_20 * 2 + 467) & 127;
    if (stage_v_154 > 42) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001656_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001656_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_25 + pub_r001656_2 * 2 + 476) & 127;
    if (stage_v_157 > 51) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001656_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (helper_flow_3 + pub_r001656_23 * 2 + 482) & 127;
    if (stage_v_159 > 38) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_157 + pub_r001656_0 * 2 + 485) & 127;
    if (stage_v_160 > 52) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001656_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (helper_flow_4 + pub_r001656_23 * 2 + 491) & 127;
    if (stage_v_162 > 47) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_89 + pub_r001656_21 * 2 + 494) & 127;
    if (stage_v_163 > 43) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_9 + pub_r001656_6 * 2 + 497) & 127;
    if (stage_v_164 > 50) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_127 + pub_r001656_10 * 2 + 500) & 127;
    if (stage_v_165 > 40) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_109 + pub_r001656_2 * 2 + 503) & 127;
    if (stage_v_166 > 34) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_147 + pub_r001656_0 * 2 + 506) & 127;
    if (stage_v_167 > 56) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_35 + pub_r001656_19 * 2 + 509) & 127;
    if (stage_v_168 > 20) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_69 + pub_r001656_13 * 2 + 512) & 127;
    if (stage_v_169 > 18) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001656_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001656_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (sec_r001656_8 + pub_r001656_21 * 2 + 521) & 127;
    if (stage_v_172 > 22) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_166 + pub_r001656_17 * 2 + 524) & 127;
    if (stage_v_173 > 47) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_124 + pub_r001656_13 * 2 + 527) & 127;
    if (stage_v_174 > 48) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_115 + pub_r001656_10 * 2 + 530) & 127;
    if (stage_v_175 > 43) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001656_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_175 + pub_r001656_21 * 2 + 536) & 127;
    if (stage_v_177 > 38) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001656_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_57 + pub_r001656_2 * 2 + 542) & 127;
    if (stage_v_179 > 27) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_179 + pub_r001656_1 * 2 + 545) & 127;
    if (stage_v_180 > 44) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_7 + pub_r001656_10 * 2 + 548) & 127;
    if (stage_v_181 > 28) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001656_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001656_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_166 + pub_r001656_20 * 2 + 557) & 127;
    if (stage_v_184 > 30) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001656_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_63 + pub_r001656_0 * 2 + 563) & 127;
    if (stage_v_186 > 29) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_65 + pub_r001656_3 * 2 + 566) & 127;
    if (stage_v_187 > 46) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_104 + pub_r001656_7 * 2 + 569) & 127;
    if (stage_v_188 > 39) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_186 + pub_r001656_19 * 2 + 572) & 127;
    if (stage_v_189 > 23) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001656_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (sec_r001656_18 + pub_r001656_1 * 2 + 578) & 127;
    if (stage_v_191 > 24) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_85 + pub_r001656_10 * 2 + 581) & 127;
    if (stage_v_192 > 47) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_78 + pub_r001656_1 * 2 + 584) & 127;
    if (stage_v_193 > 38) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001656_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (sec_r001656_14 + pub_r001656_9 * 2 + 590) & 127;
    if (stage_v_195 > 39) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r001656_7 + pub_r001656_4 * 2 + 593) & 127;
    if (stage_v_196 > 18) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r001656_1 + pub_r001656_6 * 2 + 596) & 127;
    if (stage_v_197 > 30) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001656_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_11 + pub_r001656_8 * 2 + 602) & 127;
    if (stage_v_199 > 20) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001656_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_111 + pub_r001656_8 * 2 + 608) & 127;
    if (stage_v_201 > 16) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_104 + pub_r001656_11 * 2 + 611) & 127;
    if (stage_v_202 > 32) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_79 + pub_r001656_6 * 2 + 614) & 127;
    if (stage_v_203 > 16) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_130 + pub_r001656_16 * 2 + 617) & 127;
    if (stage_v_204 > 54) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_165 + pub_r001656_1 * 2 + 620) & 127;
    if (stage_v_205 > 38) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001656_23 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (sec_r001656_1 + pub_r001656_11 * 2 + 626) & 127;
    if (stage_v_207 > 51) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_147 + pub_r001656_22 * 2 + 629) & 127;
    if (stage_v_208 > 34) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001656_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001656_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (helper_flow_3 + pub_r001656_11 * 2 + 638) & 127;
    if (stage_v_211 > 26) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (sec_r001656_4 + pub_r001656_11 * 2 + 641) & 127;
    if (stage_v_212 > 16) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_116 + pub_r001656_4 * 2 + 644) & 127;
    if (stage_v_213 > 21) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_119 + pub_r001656_17 * 2 + 647) & 127;
    if (stage_v_214 > 59) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_87 + pub_r001656_3 * 2 + 650) & 127;
    if (stage_v_215 > 30) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001656_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_169 + pub_r001656_5 * 2 + 656) & 127;
    if (stage_v_217 > 44) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_160 + pub_r001656_0 * 2 + 659) & 127;
    if (stage_v_218 > 34) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_174 + pub_r001656_10 * 2 + 662) & 127;
    if (stage_v_219 > 17) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001656_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_7 + pub_r001656_9 * 2 + 668) & 127;
    if (stage_v_221 > 24) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_201 + pub_r001656_2 * 2 + 671) & 127;
    if (stage_v_222 > 44) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_211 + pub_r001656_16 * 2 + 674) & 127;
    if (stage_v_223 > 46) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_106 + pub_r001656_16 * 2 + 677) & 127;
    if (stage_v_224 > 39) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_168 + pub_r001656_7 * 2 + 680) & 127;
    if (stage_v_225 > 44) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (helper_flow_8 + pub_r001656_2 * 2 + 683) & 127;
    if (stage_v_226 > 56) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001656_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (sec_r001656_10 + pub_r001656_4 * 2 + 689) & 127;
    if (stage_v_228 > 16) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_160 + pub_r001656_16 * 2 + 692) & 127;
    if (stage_v_229 > 43) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001656_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (sec_r001656_17 + pub_r001656_8 * 2 + 698) & 127;
    if (stage_v_231 > 32) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001656_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_113 + pub_r001656_6 * 2 + 704) & 127;
    if (stage_v_233 > 49) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_37 + pub_r001656_6 * 2 + 707) & 127;
    if (stage_v_234 > 55) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_16 + pub_r001656_16 * 2 + 710) & 127;
    if (stage_v_235 > 16) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (helper_flow_0 + pub_r001656_15 * 2 + 713) & 127;
    if (stage_v_236 > 20) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_70 + pub_r001656_11 * 2 + 716) & 127;
    if (stage_v_237 > 37) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_144 + pub_r001656_0 * 2 + 719) & 127;
    if (stage_v_238 > 48) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
        sec_accum ^= (stage_v_238 & 31);
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (sec_r001656_17 + pub_r001656_17 * 2 + 722) & 127;
    if (stage_v_239 > 21) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (sec_r001656_15 + pub_r001656_2 * 2 + 725) & 127;
    if (stage_v_240 > 36) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_13 + pub_r001656_23 * 2 + 728) & 127;
    if (stage_v_241 > 35) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001656_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001656_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_78 + pub_r001656_6 * 2 + 737) & 127;
    if (stage_v_244 > 56) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_36 + pub_r001656_7 * 2 + 740) & 127;
    if (stage_v_245 > 17) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
        sec_accum ^= (stage_v_245 & 31);
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_229 + pub_r001656_3 * 2 + 743) & 127;
    if (stage_v_246 > 59) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_204 + pub_r001656_2 * 2 + 746) & 127;
    if (stage_v_247 > 34) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_181 + pub_r001656_12 * 2 + 749) & 127;
    if (stage_v_248 > 38) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
        sec_accum ^= (stage_v_248 & 31);
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_154 + pub_r001656_14 * 2 + 752) & 127;
    if (stage_v_249 > 55) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
        sec_accum ^= (stage_v_249 & 31);
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001656_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_68 + pub_r001656_13 * 2 + 758) & 127;
    if (stage_v_251 > 30) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001656_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001656_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001656_22 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (stage_v_66 + pub_r001656_8 * 2 + 770) & 127;
    if (stage_v_255 > 18) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
        sec_accum ^= (stage_v_255 & 31);
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_235 + pub_r001656_14 * 2 + 773) & 127;
    if (stage_v_256 > 57) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
        sec_accum ^= (stage_v_256 & 31);
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001656_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001656_22 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001656_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (stage_v_18 + pub_r001656_16 * 2 + 785) & 127;
    if (stage_v_260 > 29) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
        sec_accum ^= (stage_v_260 & 31);
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (stage_v_202 + pub_r001656_0 * 2 + 788) & 127;
    if (stage_v_261 > 32) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
        sec_accum ^= (stage_v_261 & 31);
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (stage_v_217 + pub_r001656_1 * 2 + 791) & 127;
    if (stage_v_262 > 23) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
        sec_accum ^= (stage_v_262 & 31);
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (stage_v_157 + pub_r001656_1 * 2 + 794) & 127;
    if (stage_v_263 > 53) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
        sec_accum ^= (stage_v_263 & 31);
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (stage_v_202 + pub_r001656_1 * 2 + 797) & 127;
    if (stage_v_264 > 57) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
        sec_accum ^= (stage_v_264 & 31);
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (stage_v_14 + pub_r001656_3 * 2 + 800) & 127;
    if (stage_v_265 > 59) {
        out_sink = (out_sink + stage_v_265 * 2 + 7) & 255;
        sec_accum ^= (stage_v_265 & 31);
    } else {
        out_sink = (out_sink - stage_v_265 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (stage_v_88 + pub_r001656_16 * 2 + 803) & 127;
    if (stage_v_266 > 40) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
        sec_accum ^= (stage_v_266 & 31);
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001656_20 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (stage_v_218 + pub_r001656_15 * 2 + 809) & 127;
    if (stage_v_268 > 56) {
        out_sink = (out_sink + stage_v_268 * 2 + 7) & 255;
        sec_accum ^= (stage_v_268 & 31);
    } else {
        out_sink = (out_sink - stage_v_268 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
