/*
 * Benchmark Program: R000937
 * Security Family: nested_implicit_flow
 * Generator Seed: 593713
 * High Inputs: 18 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000937_3713_0 {
    int calib;
    short threshold;
    int status;
    int buffer[3];
};

struct CipherContext_R000937_3713_1 {
    int flags;
    unsigned char counter;
    short iv;
    unsigned char nonce;
    int tag;
    int buffer[3];
};

struct FilterState_R000937_3713_2 {
    int mode;
    int prev_out;
    short damping;
    short prev_in;
    int buffer[3];
};

union TelemetryField_R000937_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000937_3713_0(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int scale_16 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_16 > 43) {
        acc = (acc + scale_16 * 2 + 5) & 127;
        aux ^= (scale_16 & 15);
    } else {
        acc = (acc - scale_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_73 = local_arr[aux % 3];
    acc = (acc + tracker_73 * 2) & 127;
    int accumulator_64 = (aux + st.buffer[1]) & 3;
    switch (accumulator_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000937_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_42) & 63;
    acc ^= aux;
    int segment_20 = (aux + st.buffer[1]) & 3;
    switch (segment_20) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000937_3713_2(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000937_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_29 = (aux + st.buffer[1]) & 3;
    switch (threshold_29) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000937_3713_3(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000937_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_36 = (aux + st.buffer[1]) & 3;
    switch (factor_36) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_19 = local_arr[aux % 3];
    acc = (acc + phase_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000937_3713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000937_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int margin_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_37) & 63;
    acc ^= aux;
    int delta_75 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_75 > 13) {
        acc = (acc + delta_75 * 2 + 5) & 127;
        aux ^= (delta_75 & 15);
    } else {
        acc = (acc - delta_75 + 11) & 127;
        aux += 3;
    }
    int delta_11 = (aux + st.buffer[1]) & 3;
    switch (delta_11) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_96 = local_arr[aux % 3];
    acc = (acc + parity_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000937_3713_5(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000937_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_94 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_94 > 15) {
        acc = (acc + quantum_94 * 2 + 5) & 127;
        aux ^= (quantum_94 & 15);
    } else {
        acc = (acc - quantum_94 + 11) & 127;
        aux += 3;
    }
    int offset_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_12) & 63;
    acc ^= aux;
    int vector_53 = (aux + st.buffer[1]) & 3;
    switch (vector_53) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int scale_24 = (aux + st.buffer[1]) & 3;
    switch (scale_24) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000937_3713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000937_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_81) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_13 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_13 > 33) {
        acc = (acc + vector_13 * 2 + 5) & 127;
        aux ^= (vector_13 & 15);
    } else {
        acc = (acc - vector_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_88) & 63;
    acc ^= aux;
    int segment_22 = (aux + st.buffer[1]) & 3;
    switch (segment_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int margin_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_74) & 63;
    acc ^= aux;
    int residue_77 = (aux + st.buffer[1]) & 3;
    switch (residue_77) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_10(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000937_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_94 = local_arr[aux % 3];
    acc = (acc + factor_94 * 2) & 127;
    int stride_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_92) & 63;
    acc ^= aux;
    int factor_18 = (aux + st.buffer[1]) & 3;
    switch (factor_18) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_11(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int tally_64 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_64 > 12) {
        acc = (acc + tally_64 * 2 + 5) & 127;
        aux ^= (tally_64 & 15);
    } else {
        acc = (acc - tally_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_47 = local_arr[aux % 3];
    acc = (acc + threshold_47 * 2) & 127;
    int sample_26 = (aux + st.buffer[1]) & 3;
    switch (sample_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000937_3713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000937_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int window_39 = (aux + st.buffer[1]) & 3;
    switch (window_39) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_36 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_36 > 40) {
        acc = (acc + threshold_36 * 2 + 5) & 127;
        aux ^= (threshold_36 & 15);
    } else {
        acc = (acc - threshold_36 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_69 = local_arr[aux % 3];
    acc = (acc + accumulator_69 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000937_3713_13(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int cursor_48 = local_arr[aux % 3];
    acc = (acc + cursor_48 * 2) & 127;
    int residue_36 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_36 > 29) {
        acc = (acc + residue_36 * 2 + 5) & 127;
        aux ^= (residue_36 & 15);
    } else {
        acc = (acc - residue_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int sample_89 = local_arr[aux % 3];
    acc = (acc + sample_89 * 2) & 127;
    int coefficient_12 = (aux + st.buffer[1]) & 3;
    switch (coefficient_12) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_67 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_67 > 35) {
        acc = (acc + accumulator_67 * 2 + 5) & 127;
        aux ^= (accumulator_67 & 15);
    } else {
        acc = (acc - accumulator_67 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000937_3713_15(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000937_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_19 = (aux + st.buffer[1]) & 3;
    switch (quotient_19) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_46 = local_arr[aux % 3];
    acc = (acc + vector_46 * 2) & 127;
    int stride_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_92) & 63;
    acc ^= aux;
    int offset_99 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_99 > 11) {
        acc = (acc + offset_99 * 2 + 5) & 127;
        aux ^= (offset_99 & 15);
    } else {
        acc = (acc - offset_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000937_3713_16(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000937_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int anchor_96 = local_arr[aux % 3];
    acc = (acc + anchor_96 * 2) & 127;
    int coefficient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_52) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000937_0;
    int sec_r000937_1;
    int sec_r000937_2;
    int sec_r000937_3;
    int sec_r000937_4;
    int sec_r000937_5;
    int sec_r000937_6;
    int sec_r000937_7;
    int sec_r000937_8;
    int sec_r000937_9;
    int sec_r000937_10;
    int sec_r000937_11;
    int sec_r000937_12;
    int sec_r000937_13;
    int sec_r000937_14;
    int sec_r000937_15;
    int sec_r000937_16;
    int sec_r000937_17;
    int pub_r000937_0;
    int pub_r000937_1;
    int pub_r000937_2;
    int pub_r000937_3;
    int pub_r000937_4;
    int pub_r000937_5;
    int pub_r000937_6;
    int pub_r000937_7;
    int pub_r000937_8;
    int pub_r000937_9;
    int pub_r000937_10;
    int pub_r000937_11;
    int pub_r000937_12;
    int pub_r000937_13;
    int pub_r000937_14;
    int pub_r000937_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000937_0 >= -100 && pub_r000937_0 <= 100);
    __CPROVER_assume(pub_r000937_1 >= -100 && pub_r000937_1 <= 100);
    __CPROVER_assume(pub_r000937_2 >= -100 && pub_r000937_2 <= 100);
    __CPROVER_assume(pub_r000937_3 >= -100 && pub_r000937_3 <= 100);
    __CPROVER_assume(pub_r000937_4 >= -100 && pub_r000937_4 <= 100);
    __CPROVER_assume(pub_r000937_5 >= -100 && pub_r000937_5 <= 100);
    __CPROVER_assume(pub_r000937_6 >= -100 && pub_r000937_6 <= 100);
    __CPROVER_assume(pub_r000937_7 >= -100 && pub_r000937_7 <= 100);
    __CPROVER_assume(pub_r000937_8 >= -100 && pub_r000937_8 <= 100);
    __CPROVER_assume(pub_r000937_9 >= -100 && pub_r000937_9 <= 100);
    __CPROVER_assume(pub_r000937_10 >= -100 && pub_r000937_10 <= 100);
    __CPROVER_assume(pub_r000937_11 >= -100 && pub_r000937_11 <= 100);
    __CPROVER_assume(pub_r000937_12 >= -100 && pub_r000937_12 <= 100);
    __CPROVER_assume(pub_r000937_13 >= -100 && pub_r000937_13 <= 100);
    __CPROVER_assume(pub_r000937_14 >= -100 && pub_r000937_14 <= 100);
    __CPROVER_assume(pub_r000937_15 >= -100 && pub_r000937_15 <= 100);
    __CPROVER_assume(sec_r000937_0 >= 0 && sec_r000937_0 <= 255);
    __CPROVER_assume(sec_r000937_1 >= 0 && sec_r000937_1 <= 255);
    __CPROVER_assume(sec_r000937_2 >= 0 && sec_r000937_2 <= 255);
    __CPROVER_assume(sec_r000937_3 >= 0 && sec_r000937_3 <= 255);
    __CPROVER_assume(sec_r000937_4 >= 0 && sec_r000937_4 <= 255);
    __CPROVER_assume(sec_r000937_5 >= 0 && sec_r000937_5 <= 255);
    __CPROVER_assume(sec_r000937_6 >= 0 && sec_r000937_6 <= 255);
    __CPROVER_assume(sec_r000937_7 >= 0 && sec_r000937_7 <= 255);
    __CPROVER_assume(sec_r000937_8 >= 0 && sec_r000937_8 <= 255);
    __CPROVER_assume(sec_r000937_9 >= 0 && sec_r000937_9 <= 255);
    __CPROVER_assume(sec_r000937_10 >= 0 && sec_r000937_10 <= 255);
    __CPROVER_assume(sec_r000937_11 >= 0 && sec_r000937_11 <= 255);
    __CPROVER_assume(sec_r000937_12 >= 0 && sec_r000937_12 <= 255);
    __CPROVER_assume(sec_r000937_13 >= 0 && sec_r000937_13 <= 255);
    __CPROVER_assume(sec_r000937_14 >= 0 && sec_r000937_14 <= 255);
    __CPROVER_assume(sec_r000937_15 >= 0 && sec_r000937_15 <= 255);
    __CPROVER_assume(sec_r000937_16 >= 0 && sec_r000937_16 <= 255);
    __CPROVER_assume(sec_r000937_17 >= 0 && sec_r000937_17 <= 255);

    struct SensorNode_R000937_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000937_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000937_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000937_0 + 7) & 15;
    struct CipherContext_R000937_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000937_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000937_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000937_0 + 9) & 15;
    struct FilterState_R000937_3713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000937_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000937_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000937_0 + 11) & 15;

    union TelemetryField_R000937_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 40) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 55) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 11) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 26) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 25) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 40) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 31) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 46) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 24) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 39) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

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
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 35) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 50) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 37) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 52) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000937_9 & 1) != 0) {
        if ((sec_r000937_12 & 2) != 0) {
            stage_v_39 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_40 = (pub_r000937_13 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000937_13 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000937_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000937_0 & 1) != 0) {
        if ((sec_r000937_9 & 2) != 0) {
            stage_v_41 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000937_4 & 2) != 0) {
            stage_v_42 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((sec_r000937_2 & 1) != 0) {
        if ((sec_r000937_8 & 2) != 0) {
            stage_v_43 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_44 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_45 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000937_13 & 1) != 0) {
        if ((sec_r000937_16 & 2) != 0) {
            stage_v_46 = (pub_r000937_5 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000937_5 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000937_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000937_1 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_47 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000937_13 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_48 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000937_13 & 1) != 0) {
        if ((sec_r000937_0 & 2) != 0) {
            stage_v_49 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000937_7 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_50 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_51 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_52 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_53 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000937_16 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_54 = (pub_r000937_3 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000937_3 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000937_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000937_0 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_55 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000937_13 & 2) != 0) {
            stage_v_56 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000937_0 & 2) != 0) {
            stage_v_57 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000937_13 & 1) != 0) {
        if ((sec_r000937_5 & 2) != 0) {
            stage_v_58 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000937_13 & 1) != 0) {
        if ((sec_r000937_12 & 2) != 0) {
            stage_v_59 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000937_13 & 2) != 0) {
            stage_v_60 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000937_14 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_61 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_62 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000937_13 & 2) != 0) {
            stage_v_63 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000937_7 & 1) != 0) {
        if ((sec_r000937_0 & 2) != 0) {
            stage_v_64 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000937_5 & 1) != 0) {
        if ((sec_r000937_5 & 2) != 0) {
            stage_v_65 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000937_4 & 2) != 0) {
            stage_v_66 = (pub_r000937_12 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000937_12 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000937_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000937_8 & 1) != 0) {
        if ((sec_r000937_6 & 2) != 0) {
            stage_v_67 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000937_9 & 1) != 0) {
        if ((sec_r000937_15 & 2) != 0) {
            stage_v_68 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000937_10 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_69 = (pub_r000937_12 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000937_12 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000937_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_70 = (pub_r000937_0 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000937_0 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000937_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_71 = (pub_r000937_8 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000937_8 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000937_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000937_4 & 2) != 0) {
            stage_v_72 = (pub_r000937_13 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000937_13 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000937_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_73 = (pub_r000937_12 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000937_12 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000937_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000937_4 & 2) != 0) {
            stage_v_74 = (pub_r000937_2 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000937_2 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000937_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_75 = (pub_r000937_13 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000937_13 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000937_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000937_9 & 2) != 0) {
            stage_v_76 = (pub_r000937_5 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000937_5 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000937_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000937_3 & 1) != 0) {
        if ((sec_r000937_16 & 2) != 0) {
            stage_v_77 = (pub_r000937_0 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000937_0 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000937_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_78 = (pub_r000937_13 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000937_13 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000937_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000937_14 & 1) != 0) {
        if ((sec_r000937_15 & 2) != 0) {
            stage_v_79 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_80 = (pub_r000937_8 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000937_8 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000937_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_81 = (pub_r000937_3 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000937_3 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000937_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000937_15 & 2) != 0) {
            stage_v_82 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000937_14 & 2) != 0) {
            stage_v_83 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_84 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000937_11 & 1) != 0) {
        if ((sec_r000937_14 & 2) != 0) {
            stage_v_85 = (pub_r000937_0 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000937_0 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000937_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_86 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000937_3 & 1) != 0) {
        if ((sec_r000937_9 & 2) != 0) {
            stage_v_87 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_88 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000937_4 & 1) != 0) {
        if ((sec_r000937_9 & 2) != 0) {
            stage_v_89 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000937_12 & 1) != 0) {
        if ((sec_r000937_14 & 2) != 0) {
            stage_v_90 = (pub_r000937_2 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000937_2 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000937_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000937_0 & 1) != 0) {
        if ((sec_r000937_0 & 2) != 0) {
            stage_v_91 = (pub_r000937_5 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000937_5 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000937_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000937_5 & 2) != 0) {
            stage_v_92 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_93 = (pub_r000937_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000937_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000937_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_94 = (pub_r000937_5 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000937_5 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000937_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_95 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000937_8 & 2) != 0) {
            stage_v_96 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_97 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000937_16 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_98 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000937_13 & 2) != 0) {
            stage_v_99 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_100 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_101 = (pub_r000937_5 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000937_5 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000937_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_102 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000937_15 & 1) != 0) {
        if ((sec_r000937_15 & 2) != 0) {
            stage_v_103 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000937_6 & 1) != 0) {
        if ((sec_r000937_8 & 2) != 0) {
            stage_v_104 = (pub_r000937_8 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000937_8 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000937_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000937_8 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_105 = (pub_r000937_11 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000937_11 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000937_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000937_4 & 2) != 0) {
            stage_v_106 = (pub_r000937_3 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000937_3 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000937_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000937_13 & 2) != 0) {
            stage_v_107 = (pub_r000937_11 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000937_11 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000937_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000937_5 & 2) != 0) {
            stage_v_108 = (pub_r000937_11 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000937_11 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000937_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000937_4 & 2) != 0) {
            stage_v_109 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000937_15 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_110 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000937_10 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_111 = (pub_r000937_8 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000937_8 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000937_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000937_0 & 2) != 0) {
            stage_v_112 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000937_11 & 2) != 0) {
            stage_v_113 = (pub_r000937_2 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000937_2 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000937_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000937_9 & 2) != 0) {
            stage_v_114 = (pub_r000937_5 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000937_5 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000937_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000937_11 & 2) != 0) {
            stage_v_115 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000937_6 & 2) != 0) {
            stage_v_116 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000937_5 & 2) != 0) {
            stage_v_117 = (pub_r000937_13 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000937_13 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000937_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_118 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000937_4 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_119 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_120 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000937_12 & 2) != 0) {
            stage_v_121 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000937_6 & 1) != 0) {
        if ((sec_r000937_16 & 2) != 0) {
            stage_v_122 = (pub_r000937_13 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000937_13 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000937_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_123 = (pub_r000937_3 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000937_3 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000937_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000937_8 & 2) != 0) {
            stage_v_124 = (pub_r000937_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000937_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000937_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000937_3 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_125 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000937_11 & 2) != 0) {
            stage_v_126 = (pub_r000937_12 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000937_12 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000937_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000937_5 & 2) != 0) {
            stage_v_127 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_128 = (pub_r000937_13 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000937_13 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000937_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000937_11 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_129 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000937_5 & 1) != 0) {
        if ((sec_r000937_11 & 2) != 0) {
            stage_v_130 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000937_16 & 2) != 0) {
            stage_v_131 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000937_0 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_132 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000937_15 & 2) != 0) {
            stage_v_133 = (pub_r000937_8 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000937_8 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000937_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000937_15 & 1) != 0) {
        if ((sec_r000937_8 & 2) != 0) {
            stage_v_134 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_135 = (pub_r000937_6 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000937_6 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000937_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_136 = (pub_r000937_14 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000937_14 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000937_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_137 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000937_14 & 1) != 0) {
        if ((sec_r000937_5 & 2) != 0) {
            stage_v_138 = (pub_r000937_0 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000937_0 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000937_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_139 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000937_1 & 2) != 0) {
            stage_v_140 = (pub_r000937_8 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000937_8 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000937_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000937_9 & 1) != 0) {
        if ((sec_r000937_4 & 2) != 0) {
            stage_v_141 = (pub_r000937_11 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000937_11 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000937_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000937_2 & 2) != 0) {
            stage_v_142 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000937_11 & 1) != 0) {
        if ((sec_r000937_9 & 2) != 0) {
            stage_v_143 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000937_10 & 2) != 0) {
            stage_v_144 = (pub_r000937_8 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000937_8 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000937_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000937_3 & 2) != 0) {
            stage_v_145 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000937_0 & 2) != 0) {
            stage_v_146 = (pub_r000937_10 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000937_10 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000937_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000937_17 & 1) != 0) {
        if ((sec_r000937_8 & 2) != 0) {
            stage_v_147 = (pub_r000937_3 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000937_3 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000937_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000937_16 & 1) != 0) {
        if ((sec_r000937_12 & 2) != 0) {
            stage_v_148 = (pub_r000937_11 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000937_11 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000937_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_149 = (pub_r000937_2 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000937_2 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000937_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000937_8 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_150 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000937_17 & 1) != 0) {
        if ((sec_r000937_11 & 2) != 0) {
            stage_v_151 = (pub_r000937_1 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000937_1 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000937_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000937_9 & 2) != 0) {
            stage_v_152 = (pub_r000937_9 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000937_9 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000937_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_153 = (pub_r000937_4 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000937_4 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000937_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_154 = (pub_r000937_7 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000937_7 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000937_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000937_16 & 2) != 0) {
            stage_v_155 = (pub_r000937_12 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000937_12 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000937_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000937_17 & 2) != 0) {
            stage_v_156 = (pub_r000937_15 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000937_15 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000937_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r000937_7 & 2) != 0) {
            stage_v_157 = (pub_r000937_3 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000937_3 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000937_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
