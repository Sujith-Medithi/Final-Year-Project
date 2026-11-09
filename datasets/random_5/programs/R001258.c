/*
 * Benchmark Program: R001258
 * Security Family: secret_dependent_loops
 * Generator Seed: 625813
 * High Inputs: 24 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001258_5813_0 {
    short gain;
    short calib;
    int offset;
    int buffer[3];
};

struct StreamBuffer_R001258_5813_1 {
    int state;
    int head;
    int capacity;
    int watermark;
    unsigned char tail;
    int buffer[3];
};

union TelemetryField_R001258_5813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001258_5813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int vector_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_25) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_64 = local_arr[aux % 3];
    acc = (acc + threshold_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001258_5813_1(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int quotient_40 = local_arr[aux % 3];
    acc = (acc + quotient_40 * 2) & 127;
    int anchor_55 = (aux + st.buffer[1]) & 3;
    switch (anchor_55) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001258_5813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_57 = 0;
    for (int k = 0; k < 2; k++) {
        bound_57 = (bound_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_57) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_75 = local_arr[aux % 3];
    acc = (acc + mask_75 * 2) & 127;
    int mask_32 = (aux + st.buffer[1]) & 3;
    switch (mask_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_13 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_13 > 33) {
        acc = (acc + phase_13 * 2 + 5) & 127;
        aux ^= (phase_13 & 15);
    } else {
        acc = (acc - phase_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_3(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quantum_91 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_91 > 40) {
        acc = (acc + quantum_91 * 2 + 5) & 127;
        aux ^= (quantum_91 & 15);
    } else {
        acc = (acc - quantum_91 + 11) & 127;
        aux += 3;
    }
    int offset_58 = 0;
    for (int k = 0; k < 3; k++) {
        offset_58 = (offset_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_58) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_48 = local_arr[aux % 3];
    acc = (acc + anchor_48 * 2) & 127;
    int margin_89 = (aux + st.buffer[1]) & 3;
    switch (margin_89) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_4(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_52) & 63;
    acc ^= aux;
    int quotient_43 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_43 > 49) {
        acc = (acc + quotient_43 * 2 + 5) & 127;
        aux ^= (quotient_43 & 15);
    } else {
        acc = (acc - quotient_43 + 11) & 127;
        aux += 3;
    }
    int residue_43 = 0;
    for (int k = 0; k < 2; k++) {
        residue_43 = (residue_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_43) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int pivot_62 = local_arr[aux % 3];
    acc = (acc + pivot_62 * 2) & 127;
    int segment_86 = 0;
    for (int k = 0; k < 2; k++) {
        segment_86 = (segment_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_86) & 127;
    }
    int window_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_32) & 63;
    acc ^= aux;
    int scale_91 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_91 > 45) {
        acc = (acc + scale_91 * 2 + 5) & 127;
        aux ^= (scale_91 & 15);
    } else {
        acc = (acc - scale_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_6(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_23 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_23 > 50) {
        acc = (acc + phase_23 * 2 + 5) & 127;
        aux ^= (phase_23 & 15);
    } else {
        acc = (acc - phase_23 + 11) & 127;
        aux += 3;
    }
    int window_57 = 0;
    for (int k = 0; k < 2; k++) {
        window_57 = (window_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_57) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_7(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_73 = (aux + st.buffer[1]) & 3;
    switch (stride_73) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_90) & 63;
    acc ^= aux;
    int quantum_42 = (aux + st.buffer[1]) & 3;
    switch (quantum_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_26 = 0;
    for (int k = 0; k < 3; k++) {
        mask_26 = (mask_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_26) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_9(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_11 = (aux + st.buffer[1]) & 3;
    switch (offset_11) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001258_5813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001258_5813_11(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int weight_12 = local_arr[aux % 3];
    acc = (acc + weight_12 * 2) & 127;
    int stride_71 = 0;
    for (int k = 0; k < 3; k++) {
        stride_71 = (stride_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_71) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_57 = (aux + st.buffer[1]) & 3;
    switch (cursor_57) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_77 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_77 > 49) {
        acc = (acc + offset_77 * 2 + 5) & 127;
        aux ^= (offset_77 & 15);
    } else {
        acc = (acc - offset_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_52 = local_arr[aux % 3];
    acc = (acc + factor_52 * 2) & 127;
    int quotient_34 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_34 = (quotient_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_34) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quantum_80 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_80 > 16) {
        acc = (acc + quantum_80 * 2 + 5) & 127;
        aux ^= (quantum_80 & 15);
    } else {
        acc = (acc - quantum_80 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_52 = local_arr[aux % 3];
    acc = (acc + threshold_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001258_5813_14(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int delta_86 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_86 > 36) {
        acc = (acc + delta_86 * 2 + 5) & 127;
        aux ^= (delta_86 & 15);
    } else {
        acc = (acc - delta_86 + 11) & 127;
        aux += 3;
    }
    int mask_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_64) & 63;
    acc ^= aux;
    int pivot_86 = (aux + st.buffer[1]) & 3;
    switch (pivot_86) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_18 = 0;
    for (int k = 0; k < 2; k++) {
        tally_18 = (tally_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_18) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_15(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001258_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_74 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_74 = (pivot_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_74) & 127;
    }
    int phase_77 = (aux + st.buffer[1]) & 3;
    switch (phase_77) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_32 = local_arr[aux % 3];
    acc = (acc + quantum_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001258_5813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_75 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_75 > 49) {
        acc = (acc + segment_75 * 2 + 5) & 127;
        aux ^= (segment_75 & 15);
    } else {
        acc = (acc - segment_75 + 11) & 127;
        aux += 3;
    }
    int vector_96 = 0;
    for (int k = 0; k < 3; k++) {
        vector_96 = (vector_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_96) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001258_5813_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001258_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_13 = local_arr[aux % 3];
    acc = (acc + cursor_13 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001258_0;
    int sec_r001258_1;
    int sec_r001258_2;
    int sec_r001258_3;
    int sec_r001258_4;
    int sec_r001258_5;
    int sec_r001258_6;
    int sec_r001258_7;
    int sec_r001258_8;
    int sec_r001258_9;
    int sec_r001258_10;
    int sec_r001258_11;
    int sec_r001258_12;
    int sec_r001258_13;
    int sec_r001258_14;
    int sec_r001258_15;
    int sec_r001258_16;
    int sec_r001258_17;
    int sec_r001258_18;
    int sec_r001258_19;
    int sec_r001258_20;
    int sec_r001258_21;
    int sec_r001258_22;
    int sec_r001258_23;
    int pub_r001258_0;
    int pub_r001258_1;
    int pub_r001258_2;
    int pub_r001258_3;
    int pub_r001258_4;
    int pub_r001258_5;
    int pub_r001258_6;
    int pub_r001258_7;
    int pub_r001258_8;
    int pub_r001258_9;
    int pub_r001258_10;
    int pub_r001258_11;
    int pub_r001258_12;
    int pub_r001258_13;
    int pub_r001258_14;
    int pub_r001258_15;
    int pub_r001258_16;
    int pub_r001258_17;
    int pub_r001258_18;
    int pub_r001258_19;
    int pub_r001258_20;
    int pub_r001258_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001258_0 >= -100 && pub_r001258_0 <= 100);
    __CPROVER_assume(pub_r001258_1 >= -100 && pub_r001258_1 <= 100);
    __CPROVER_assume(pub_r001258_2 >= -100 && pub_r001258_2 <= 100);
    __CPROVER_assume(pub_r001258_3 >= -100 && pub_r001258_3 <= 100);
    __CPROVER_assume(pub_r001258_4 >= -100 && pub_r001258_4 <= 100);
    __CPROVER_assume(pub_r001258_5 >= -100 && pub_r001258_5 <= 100);
    __CPROVER_assume(pub_r001258_6 >= -100 && pub_r001258_6 <= 100);
    __CPROVER_assume(pub_r001258_7 >= -100 && pub_r001258_7 <= 100);
    __CPROVER_assume(pub_r001258_8 >= -100 && pub_r001258_8 <= 100);
    __CPROVER_assume(pub_r001258_9 >= -100 && pub_r001258_9 <= 100);
    __CPROVER_assume(pub_r001258_10 >= -100 && pub_r001258_10 <= 100);
    __CPROVER_assume(pub_r001258_11 >= -100 && pub_r001258_11 <= 100);
    __CPROVER_assume(pub_r001258_12 >= -100 && pub_r001258_12 <= 100);
    __CPROVER_assume(pub_r001258_13 >= -100 && pub_r001258_13 <= 100);
    __CPROVER_assume(pub_r001258_14 >= -100 && pub_r001258_14 <= 100);
    __CPROVER_assume(pub_r001258_15 >= -100 && pub_r001258_15 <= 100);
    __CPROVER_assume(pub_r001258_16 >= -100 && pub_r001258_16 <= 100);
    __CPROVER_assume(pub_r001258_17 >= -100 && pub_r001258_17 <= 100);
    __CPROVER_assume(pub_r001258_18 >= -100 && pub_r001258_18 <= 100);
    __CPROVER_assume(pub_r001258_19 >= -100 && pub_r001258_19 <= 100);
    __CPROVER_assume(pub_r001258_20 >= -100 && pub_r001258_20 <= 100);
    __CPROVER_assume(pub_r001258_21 >= -100 && pub_r001258_21 <= 100);
    __CPROVER_assume(sec_r001258_0 >= 0 && sec_r001258_0 <= 255);
    __CPROVER_assume(sec_r001258_1 >= 0 && sec_r001258_1 <= 255);
    __CPROVER_assume(sec_r001258_2 >= 0 && sec_r001258_2 <= 255);
    __CPROVER_assume(sec_r001258_3 >= 0 && sec_r001258_3 <= 255);
    __CPROVER_assume(sec_r001258_4 >= 0 && sec_r001258_4 <= 255);
    __CPROVER_assume(sec_r001258_5 >= 0 && sec_r001258_5 <= 255);
    __CPROVER_assume(sec_r001258_6 >= 0 && sec_r001258_6 <= 255);
    __CPROVER_assume(sec_r001258_7 >= 0 && sec_r001258_7 <= 255);
    __CPROVER_assume(sec_r001258_8 >= 0 && sec_r001258_8 <= 255);
    __CPROVER_assume(sec_r001258_9 >= 0 && sec_r001258_9 <= 255);
    __CPROVER_assume(sec_r001258_10 >= 0 && sec_r001258_10 <= 255);
    __CPROVER_assume(sec_r001258_11 >= 0 && sec_r001258_11 <= 255);
    __CPROVER_assume(sec_r001258_12 >= 0 && sec_r001258_12 <= 255);
    __CPROVER_assume(sec_r001258_13 >= 0 && sec_r001258_13 <= 255);
    __CPROVER_assume(sec_r001258_14 >= 0 && sec_r001258_14 <= 255);
    __CPROVER_assume(sec_r001258_15 >= 0 && sec_r001258_15 <= 255);
    __CPROVER_assume(sec_r001258_16 >= 0 && sec_r001258_16 <= 255);
    __CPROVER_assume(sec_r001258_17 >= 0 && sec_r001258_17 <= 255);
    __CPROVER_assume(sec_r001258_18 >= 0 && sec_r001258_18 <= 255);
    __CPROVER_assume(sec_r001258_19 >= 0 && sec_r001258_19 <= 255);
    __CPROVER_assume(sec_r001258_20 >= 0 && sec_r001258_20 <= 255);
    __CPROVER_assume(sec_r001258_21 >= 0 && sec_r001258_21 <= 255);
    __CPROVER_assume(sec_r001258_22 >= 0 && sec_r001258_22 <= 255);
    __CPROVER_assume(sec_r001258_23 >= 0 && sec_r001258_23 <= 255);

    struct SensorNode_R001258_5813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001258_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001258_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001258_0 + 7) & 15;
    struct StreamBuffer_R001258_5813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001258_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001258_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001258_0 + 9) & 15;

    union TelemetryField_R001258_5813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001258_5813_0(sec_r001258_0, pub_r001258_1, pub_r001258_2, pub_r001258_3);
    int helper_flow_1 = fn_R001258_5813_1(sec_r001258_1, sec_r001258_2, pub_r001258_3);
    int helper_flow_2 = fn_R001258_5813_2(sec_r001258_2, pub_r001258_3, pub_r001258_4, pub_r001258_5);
    int helper_flow_3 = fn_R001258_5813_3(sec_r001258_3, pub_r001258_4, pub_r001258_5);
    int helper_flow_4 = fn_R001258_5813_4(sec_r001258_4, pub_r001258_5);
    int helper_flow_5 = fn_R001258_5813_5(sec_r001258_5, sec_r001258_6, pub_r001258_7, pub_r001258_8, pub_r001258_9);
    int helper_flow_6 = fn_R001258_5813_6(sec_r001258_6, pub_r001258_7, pub_r001258_8);
    int helper_flow_7 = fn_R001258_5813_7(sec_r001258_7, sec_r001258_8, pub_r001258_9);
    int helper_flow_8 = fn_R001258_5813_8(sec_r001258_8, sec_r001258_9, pub_r001258_10, pub_r001258_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_0 = (stage_v_0 + it * 3 + (sec_r001258_14 & 15)) & 63;
        if ((sec_r001258_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_0 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_0 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001258_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (sec_r001258_3 & 15)) & 63;
        if ((sec_r001258_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_3 = (stage_v_3 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_3 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_3 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_4 = (stage_v_4 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_4 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_4 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (sec_r001258_23 & 15)) & 63;
        if ((sec_r001258_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (sec_r001258_15 & 15)) & 63;
        if ((sec_r001258_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001258_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_9 = (stage_v_9 + it * 3 + (sec_r001258_18 & 15)) & 63;
        if ((sec_r001258_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_9 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_9 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_10 = (stage_v_10 + it * 3 + (stage_v_4 & 15)) & 63;
        if ((stage_v_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_10 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_10 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_11 = (stage_v_11 + it * 3 + (sec_r001258_18 & 15)) & 63;
        if ((sec_r001258_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_11 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_11 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (stage_v_11 & 15)) & 63;
        if ((stage_v_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001258_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_14 = (stage_v_14 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_14 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_14 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_15 = (stage_v_15 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_15 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_15 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_16 = (stage_v_16 + it * 3 + (sec_r001258_23 & 15)) & 63;
        if ((sec_r001258_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_16 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_16 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001258_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_18 = (stage_v_18 + it * 3 + (sec_r001258_13 & 15)) & 63;
        if ((sec_r001258_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_18 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_18 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001258_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (sec_r001258_10 & 15)) & 63;
        if ((sec_r001258_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001258_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001258_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_23 = (stage_v_23 + it * 3 + (sec_r001258_11 & 15)) & 63;
        if ((sec_r001258_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_23 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_23 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001258_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_25 = (stage_v_25 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_25 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_25 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (sec_r001258_13 & 15)) & 63;
        if ((sec_r001258_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_27 = (stage_v_27 + it * 3 + (sec_r001258_7 & 15)) & 63;
        if ((sec_r001258_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_27 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_27 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_28 = (stage_v_28 + it * 3 + (sec_r001258_6 & 15)) & 63;
        if ((sec_r001258_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_28 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_28 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_29 = (stage_v_29 + it * 3 + (sec_r001258_12 & 15)) & 63;
        if ((sec_r001258_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_29 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_29 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (sec_r001258_4 & 15)) & 63;
        if ((sec_r001258_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001258_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001258_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001258_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_34 = (stage_v_34 + it * 3 + (sec_r001258_0 & 15)) & 63;
        if ((sec_r001258_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_34 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_34 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_35 = (stage_v_35 + it * 3 + (sec_r001258_5 & 15)) & 63;
        if ((sec_r001258_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_35 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_35 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_38 = (stage_v_38 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_38 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_38 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001258_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_40 = (stage_v_40 + it * 3 + (stage_v_9 & 15)) & 63;
        if ((stage_v_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_40 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_40 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001258_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (stage_v_27 & 15)) & 63;
        if ((stage_v_27 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_43 = (stage_v_43 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_43 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_43 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_44 = (stage_v_44 + it * 3 + (sec_r001258_22 & 15)) & 63;
        if ((sec_r001258_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_44 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_44 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (sec_r001258_2 & 15)) & 63;
        if ((sec_r001258_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001258_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_47 = (stage_v_47 + it * 3 + (sec_r001258_11 & 15)) & 63;
        if ((sec_r001258_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_47 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_47 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001258_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001258_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_51 = (stage_v_51 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_51 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_51 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001258_20 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001258_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_55 = (stage_v_55 + it * 3 + (sec_r001258_15 & 15)) & 63;
        if ((sec_r001258_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_55 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_55 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_56 = (stage_v_56 + it * 3 + (sec_r001258_12 & 15)) & 63;
        if ((sec_r001258_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_56 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_56 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_57 = (stage_v_57 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_57 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_57 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001258_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001258_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_61 = (stage_v_61 + it * 3 + (stage_v_3 & 15)) & 63;
        if ((stage_v_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_61 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_61 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_62 = (stage_v_62 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_62 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_62 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001258_21 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_64 = (stage_v_64 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_64 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_64 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001258_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_66 = (stage_v_66 + it * 3 + (sec_r001258_11 & 15)) & 63;
        if ((sec_r001258_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_66 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_66 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_67 = (stage_v_67 + it * 3 + (stage_v_29 & 15)) & 63;
        if ((stage_v_29 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_67 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_67 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_68 = (stage_v_68 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_68 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_68 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_69 = (stage_v_69 + it * 3 + (stage_v_62 & 15)) & 63;
        if ((stage_v_62 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_69 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_69 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_70 = (stage_v_70 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_70 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_70 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_71 = (stage_v_71 + it * 3 + (stage_v_70 & 15)) & 63;
        if ((stage_v_70 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_71 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_71 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001258_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (stage_v_4 & 15)) & 63;
        if ((stage_v_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001258_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_76 = (stage_v_76 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_76 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_76 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_77 = (stage_v_77 + it * 3 + (sec_r001258_15 & 15)) & 63;
        if ((sec_r001258_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_77 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_77 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001258_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_81 = (stage_v_81 + it * 3 + (stage_v_77 & 15)) & 63;
        if ((stage_v_77 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_81 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_81 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_82 = (stage_v_82 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_82 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_82 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_83 = (stage_v_83 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_83 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_83 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (sec_r001258_6 & 15)) & 63;
        if ((sec_r001258_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (sec_r001258_2 & 15)) & 63;
        if ((sec_r001258_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_86 = (stage_v_86 + it * 3 + (sec_r001258_10 & 15)) & 63;
        if ((sec_r001258_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_86 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_86 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_87 = (stage_v_87 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_87 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_87 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_88 = (stage_v_88 + it * 3 + (stage_v_64 & 15)) & 63;
        if ((stage_v_64 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_88 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_88 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_89 = (stage_v_89 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_89 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_89 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001258_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (stage_v_76 & 15)) & 63;
        if ((stage_v_76 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_92 = (stage_v_92 + it * 3 + (sec_r001258_18 & 15)) & 63;
        if ((sec_r001258_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_92 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_92 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001258_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (stage_v_59 & 15)) & 63;
        if ((stage_v_59 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_96 = (stage_v_96 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_96 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_96 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_97 = (stage_v_97 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_97 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_97 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_98 = (stage_v_98 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_98 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_98 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001258_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_100 = (stage_v_100 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_100 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_100 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (sec_r001258_17 & 15)) & 63;
        if ((sec_r001258_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_102 = (stage_v_102 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_102 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_102 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001258_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (sec_r001258_3 & 15)) & 63;
        if ((sec_r001258_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001258_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001258_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_107 = (stage_v_107 + it * 3 + (sec_r001258_20 & 15)) & 63;
        if ((sec_r001258_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_107 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_107 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001258_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_109 = (stage_v_109 + it * 3 + (sec_r001258_20 & 15)) & 63;
        if ((sec_r001258_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_109 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_109 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_110 = (stage_v_110 + it * 3 + (sec_r001258_18 & 15)) & 63;
        if ((sec_r001258_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_110 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_110 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_111 = (stage_v_111 + it * 3 + (stage_v_95 & 15)) & 63;
        if ((stage_v_95 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_111 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_111 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001258_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_113 = (stage_v_113 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_113 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_113 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_114 = (stage_v_114 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_114 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_114 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001258_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_116 = (stage_v_116 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_116 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_116 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_117 = (stage_v_117 + it * 3 + (stage_v_70 & 15)) & 63;
        if ((stage_v_70 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_117 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_117 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001258_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001258_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_120 = (stage_v_120 + it * 3 + (stage_v_27 & 15)) & 63;
        if ((stage_v_27 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_120 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_120 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_121 = (stage_v_121 + it * 3 + (sec_r001258_17 & 15)) & 63;
        if ((sec_r001258_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_121 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_121 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001258_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001258_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001258_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_125 = (stage_v_125 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_125 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_125 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_126 = (stage_v_126 + it * 3 + (stage_v_97 & 15)) & 63;
        if ((stage_v_97 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_126 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_126 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001258_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_128 = (stage_v_128 + it * 3 + (stage_v_96 & 15)) & 63;
        if ((stage_v_96 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_128 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_128 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_129 = (stage_v_129 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_129 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_129 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001258_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001258_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_132 = (stage_v_132 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_132 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_132 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_133 = (stage_v_133 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_133 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_133 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_134 = (stage_v_134 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_134 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_134 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001258_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001258_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_137 = (stage_v_137 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_137 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_137 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001258_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (stage_v_4 & 15)) & 63;
        if ((stage_v_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001258_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_141 = (stage_v_141 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_141 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_141 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001258_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001258_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_144 = (stage_v_144 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_144 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_144 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_145 = (stage_v_145 + it * 3 + (stage_v_137 & 15)) & 63;
        if ((stage_v_137 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_145 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_145 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_146 = (stage_v_146 + it * 3 + (stage_v_11 & 15)) & 63;
        if ((stage_v_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_146 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_146 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_147 = (stage_v_147 + it * 3 + (helper_flow_7 & 15)) & 63;
        if ((helper_flow_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_147 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_147 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001258_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_150 = (stage_v_150 + it * 3 + (sec_r001258_20 & 15)) & 63;
        if ((sec_r001258_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_150 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_150 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001258_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_152 = (stage_v_152 + it * 3 + (sec_r001258_14 & 15)) & 63;
        if ((sec_r001258_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_152 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_152 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_153 = (stage_v_153 + it * 3 + (stage_v_86 & 15)) & 63;
        if ((stage_v_86 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_153 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_153 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_154 = (stage_v_154 + it * 3 + (sec_r001258_17 & 15)) & 63;
        if ((sec_r001258_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_154 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_154 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_155 = (stage_v_155 + it * 3 + (stage_v_139 & 15)) & 63;
        if ((stage_v_139 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_155 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_155 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001258_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_158 = (stage_v_158 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_158 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_158 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001258_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_160 = (stage_v_160 + it * 3 + (stage_v_121 & 15)) & 63;
        if ((stage_v_121 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_160 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_160 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (stage_v_133 & 15)) & 63;
        if ((stage_v_133 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_163 = (stage_v_163 + it * 3 + (sec_r001258_13 & 15)) & 63;
        if ((sec_r001258_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_163 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_163 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (stage_v_160 & 15)) & 63;
        if ((stage_v_160 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001258_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001258_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001258_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_168 = (stage_v_168 + it * 3 + (sec_r001258_3 & 15)) & 63;
        if ((sec_r001258_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_168 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_168 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_169 = (stage_v_169 + it * 3 + (stage_v_34 & 15)) & 63;
        if ((stage_v_34 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_169 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_169 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001258_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001258_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (stage_v_163 & 15)) & 63;
        if ((stage_v_163 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001258_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001258_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_176 = (stage_v_176 + it * 3 + (stage_v_92 & 15)) & 63;
        if ((stage_v_92 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_176 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_176 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001258_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (stage_v_92 & 15)) & 63;
        if ((stage_v_92 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_179 = (stage_v_179 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_179 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_179 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001258_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_181 = (stage_v_181 + it * 3 + (stage_v_114 & 15)) & 63;
        if ((stage_v_114 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_181 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_181 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (stage_v_61 & 15)) & 63;
        if ((stage_v_61 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (stage_v_121 & 15)) & 63;
        if ((stage_v_121 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001258_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_185 = (stage_v_185 + it * 3 + (sec_r001258_13 & 15)) & 63;
        if ((sec_r001258_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_185 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_185 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (sec_r001258_23 & 15)) & 63;
        if ((sec_r001258_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001258_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_188 = (stage_v_188 + it * 3 + (stage_v_77 & 15)) & 63;
        if ((stage_v_77 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_188 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_188 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_189 = (stage_v_189 + it * 3 + (sec_r001258_23 & 15)) & 63;
        if ((sec_r001258_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_189 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_189 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_190 = (stage_v_190 + it * 3 + (stage_v_86 & 15)) & 63;
        if ((stage_v_86 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_190 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_190 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_191 = (stage_v_191 + it * 3 + (stage_v_11 & 15)) & 63;
        if ((stage_v_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_191 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_191 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_192 = (stage_v_192 + it * 3 + (stage_v_178 & 15)) & 63;
        if ((stage_v_178 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_192 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_192 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_193 = (stage_v_193 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_193 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_193 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001258_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_195 = (stage_v_195 + it * 3 + (stage_v_129 & 15)) & 63;
        if ((stage_v_129 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_195 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_195 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_196 = (stage_v_196 + it * 3 + (stage_v_88 & 15)) & 63;
        if ((stage_v_88 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_196 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_196 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (stage_v_101 & 15)) & 63;
        if ((stage_v_101 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_198 = (stage_v_198 + it * 3 + (stage_v_192 & 15)) & 63;
        if ((stage_v_192 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_198 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_198 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (stage_v_169 & 15)) & 63;
        if ((stage_v_169 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_200 = (stage_v_200 + it * 3 + (stage_v_192 & 15)) & 63;
        if ((stage_v_192 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_200 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_200 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_201 = (stage_v_201 + it * 3 + (stage_v_168 & 15)) & 63;
        if ((stage_v_168 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_201 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_201 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_202 = (stage_v_202 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_202 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_202 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001258_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_204 = (stage_v_204 + it * 3 + (stage_v_202 & 15)) & 63;
        if ((stage_v_202 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_204 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_204 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_205 = (stage_v_205 + it * 3 + (stage_v_71 & 15)) & 63;
        if ((stage_v_71 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_205 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_205 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001258_21 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_207 = (stage_v_207 + it * 3 + (stage_v_183 & 15)) & 63;
        if ((stage_v_183 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_207 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_207 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001258_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_209 = (stage_v_209 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_209 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_209 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_210 = (stage_v_210 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_210 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_210 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_211 = (stage_v_211 + it * 3 + (stage_v_97 & 15)) & 63;
        if ((stage_v_97 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_211 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_211 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_212 = (stage_v_212 + it * 3 + (sec_r001258_21 & 15)) & 63;
        if ((sec_r001258_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_212 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_212 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_213 = (stage_v_213 + it * 3 + (sec_r001258_15 & 15)) & 63;
        if ((sec_r001258_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_213 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_213 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_214 = (stage_v_214 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_214 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_214 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_215 = (stage_v_215 + it * 3 + (stage_v_132 & 15)) & 63;
        if ((stage_v_132 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_215 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_215 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_216 = (stage_v_216 + it * 3 + (stage_v_146 & 15)) & 63;
        if ((stage_v_146 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_216 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_216 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_217 = (stage_v_217 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_217 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_217 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_218 = (stage_v_218 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_218 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_218 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_219 = (stage_v_219 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_219 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_219 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_220 = (stage_v_220 + it * 3 + (stage_v_107 & 15)) & 63;
        if ((stage_v_107 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_220 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_220 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001258_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001258_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001258_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_224 = (stage_v_224 + it * 3 + (stage_v_189 & 15)) & 63;
        if ((stage_v_189 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_224 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_224 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_225 = (stage_v_225 + it * 3 + (stage_v_211 & 15)) & 63;
        if ((stage_v_211 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_225 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_225 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_226 = (stage_v_226 + it * 3 + (stage_v_201 & 15)) & 63;
        if ((stage_v_201 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_226 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_226 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001258_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_228 = (stage_v_228 + it * 3 + (stage_v_144 & 15)) & 63;
        if ((stage_v_144 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_228 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_228 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_229 = (stage_v_229 + it * 3 + (stage_v_101 & 15)) & 63;
        if ((stage_v_101 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_229 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_229 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_230 = (stage_v_230 + it * 3 + (stage_v_132 & 15)) & 63;
        if ((stage_v_132 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_230 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_230 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_231 = (stage_v_231 + it * 3 + (stage_v_193 & 15)) & 63;
        if ((stage_v_193 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_231 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_231 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001258_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_233 = (stage_v_233 + it * 3 + (sec_r001258_5 & 15)) & 63;
        if ((sec_r001258_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_233 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_233 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_234 = (stage_v_234 + it * 3 + (stage_v_14 & 15)) & 63;
        if ((stage_v_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_234 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_234 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
