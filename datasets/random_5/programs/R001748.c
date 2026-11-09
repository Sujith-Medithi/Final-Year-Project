/*
 * Benchmark Program: R001748
 * Security Family: secret_dependent_loops
 * Generator Seed: 674813
 * High Inputs: 23 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001748_4813_0 {
    int code;
    short severity;
    int seq;
    int timestamp;
    int buffer[3];
};

struct MatrixBlock_R001748_4813_1 {
    int stride;
    short determinant;
    int density;
    int dim;
    int buffer[3];
};

struct SensorNode_R001748_4813_2 {
    int offset;
    unsigned char threshold;
    int reading;
    int gain;
    unsigned char status;
    int buffer[3];
};

struct StreamBuffer_R001748_4813_3 {
    unsigned char state;
    short checksum;
    unsigned char head;
    int tail;
    int capacity;
    int buffer[3];
};

union RegisterBank_R001748_4813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001748_4813_0(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int vector_34 = (aux + st.buffer[1]) & 3;
    switch (vector_34) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_17 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_17 > 12) {
        acc = (acc + metric_17 * 2 + 5) & 127;
        aux ^= (metric_17 & 15);
    } else {
        acc = (acc - metric_17 + 11) & 127;
        aux += 3;
    }
    int scale_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_76) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001748_4813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int stride_31 = 0;
    for (int k = 0; k < 2; k++) {
        stride_31 = (stride_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_31) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001748_4813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int sample_22 = local_arr[aux % 3];
    acc = (acc + sample_22 * 2) & 127;
    int metric_80 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_80 > 11) {
        acc = (acc + metric_80 * 2 + 5) & 127;
        aux ^= (metric_80 & 15);
    } else {
        acc = (acc - metric_80 + 11) & 127;
        aux += 3;
    }
    int factor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_75) & 63;
    acc ^= aux;
    int delta_25 = (aux + st.buffer[1]) & 3;
    switch (delta_25) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int mask_29 = (aux + st.buffer[1]) & 3;
    switch (mask_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_71 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_71 > 26) {
        acc = (acc + quantum_71 * 2 + 5) & 127;
        aux ^= (quantum_71 & 15);
    } else {
        acc = (acc - quantum_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_84 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_84 > 22) {
        acc = (acc + coefficient_84 * 2 + 5) & 127;
        aux ^= (coefficient_84 & 15);
    } else {
        acc = (acc - coefficient_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_5(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quantum_96 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_96 > 49) {
        acc = (acc + quantum_96 * 2 + 5) & 127;
        aux ^= (quantum_96 & 15);
    } else {
        acc = (acc - quantum_96 + 11) & 127;
        aux += 3;
    }
    int checksum_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001748_4813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int metric_27 = local_arr[aux % 3];
    acc = (acc + metric_27 * 2) & 127;
    int mask_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_88) & 63;
    acc ^= aux;
    int parity_70 = (aux + st.buffer[1]) & 3;
    switch (parity_70) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int phase_28 = local_arr[aux % 3];
    acc = (acc + phase_28 * 2) & 127;
    int tally_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001748_4813_8(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001748_4813_9(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int margin_83 = (aux + st.buffer[1]) & 3;
    switch (margin_83) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_56 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_56 = (quantum_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_56) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_47 = local_arr[aux % 3];
    acc = (acc + offset_47 * 2) & 127;
    int mask_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001748_4813_10(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_98 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_98 > 48) {
        acc = (acc + bound_98 * 2 + 5) & 127;
        aux ^= (bound_98 & 15);
    } else {
        acc = (acc - bound_98 + 11) & 127;
        aux += 3;
    }
    int vector_51 = 0;
    for (int k = 0; k < 3; k++) {
        vector_51 = (vector_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_11(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int accumulator_66 = (aux + st.buffer[1]) & 3;
    switch (accumulator_66) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_44 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_44 > 46) {
        acc = (acc + weight_44 * 2 + 5) & 127;
        aux ^= (weight_44 & 15);
    } else {
        acc = (acc - weight_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_39 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_39 > 48) {
        acc = (acc + threshold_39 * 2 + 5) & 127;
        aux ^= (threshold_39 & 15);
    } else {
        acc = (acc - threshold_39 + 11) & 127;
        aux += 3;
    }
    int coefficient_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001748_4813_13(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001748_4813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int delta_57 = local_arr[aux % 3];
    acc = (acc + delta_57 * 2) & 127;
    int margin_32 = 0;
    for (int k = 0; k < 2; k++) {
        margin_32 = (margin_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_32) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int checksum_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_69) & 63;
    acc ^= aux;
    int bound_38 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_38 > 31) {
        acc = (acc + bound_38 * 2 + 5) & 127;
        aux ^= (bound_38 & 15);
    } else {
        acc = (acc - bound_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001748_4813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int vector_70 = (aux + st.buffer[1]) & 3;
    switch (vector_70) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_19 = local_arr[aux % 3];
    acc = (acc + segment_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001748_4813_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int damping_21 = local_arr[aux % 3];
    acc = (acc + damping_21 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_52 = (aux + st.buffer[1]) & 3;
    switch (cursor_52) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_17(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int segment_60 = (aux + st.buffer[1]) & 3;
    switch (segment_60) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_71 = 0;
    for (int k = 0; k < 2; k++) {
        window_71 = (window_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_71) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_90 = local_arr[aux % 3];
    acc = (acc + vector_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001748_4813_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001748_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_72 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_72 > 39) {
        acc = (acc + threshold_72 * 2 + 5) & 127;
        aux ^= (threshold_72 & 15);
    } else {
        acc = (acc - threshold_72 + 11) & 127;
        aux += 3;
    }
    int scale_14 = 0;
    for (int k = 0; k < 3; k++) {
        scale_14 = (scale_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001748_4813_19(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001748_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_41) & 63;
    acc ^= aux;
    int cursor_47 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_47 > 39) {
        acc = (acc + cursor_47 * 2 + 5) & 127;
        aux ^= (cursor_47 & 15);
    } else {
        acc = (acc - cursor_47 + 11) & 127;
        aux += 3;
    }
    int bound_84 = (aux + st.buffer[1]) & 3;
    switch (bound_84) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_57 = 0;
    for (int k = 0; k < 3; k++) {
        scale_57 = (scale_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_57) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001748_0;
    int sec_r001748_1;
    int sec_r001748_2;
    int sec_r001748_3;
    int sec_r001748_4;
    int sec_r001748_5;
    int sec_r001748_6;
    int sec_r001748_7;
    int sec_r001748_8;
    int sec_r001748_9;
    int sec_r001748_10;
    int sec_r001748_11;
    int sec_r001748_12;
    int sec_r001748_13;
    int sec_r001748_14;
    int sec_r001748_15;
    int sec_r001748_16;
    int sec_r001748_17;
    int sec_r001748_18;
    int sec_r001748_19;
    int sec_r001748_20;
    int sec_r001748_21;
    int sec_r001748_22;
    int pub_r001748_0;
    int pub_r001748_1;
    int pub_r001748_2;
    int pub_r001748_3;
    int pub_r001748_4;
    int pub_r001748_5;
    int pub_r001748_6;
    int pub_r001748_7;
    int pub_r001748_8;
    int pub_r001748_9;
    int pub_r001748_10;
    int pub_r001748_11;
    int pub_r001748_12;
    int pub_r001748_13;
    int pub_r001748_14;
    int pub_r001748_15;
    int pub_r001748_16;
    int pub_r001748_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001748_0 >= -100 && pub_r001748_0 <= 100);
    __CPROVER_assume(pub_r001748_1 >= -100 && pub_r001748_1 <= 100);
    __CPROVER_assume(pub_r001748_2 >= -100 && pub_r001748_2 <= 100);
    __CPROVER_assume(pub_r001748_3 >= -100 && pub_r001748_3 <= 100);
    __CPROVER_assume(pub_r001748_4 >= -100 && pub_r001748_4 <= 100);
    __CPROVER_assume(pub_r001748_5 >= -100 && pub_r001748_5 <= 100);
    __CPROVER_assume(pub_r001748_6 >= -100 && pub_r001748_6 <= 100);
    __CPROVER_assume(pub_r001748_7 >= -100 && pub_r001748_7 <= 100);
    __CPROVER_assume(pub_r001748_8 >= -100 && pub_r001748_8 <= 100);
    __CPROVER_assume(pub_r001748_9 >= -100 && pub_r001748_9 <= 100);
    __CPROVER_assume(pub_r001748_10 >= -100 && pub_r001748_10 <= 100);
    __CPROVER_assume(pub_r001748_11 >= -100 && pub_r001748_11 <= 100);
    __CPROVER_assume(pub_r001748_12 >= -100 && pub_r001748_12 <= 100);
    __CPROVER_assume(pub_r001748_13 >= -100 && pub_r001748_13 <= 100);
    __CPROVER_assume(pub_r001748_14 >= -100 && pub_r001748_14 <= 100);
    __CPROVER_assume(pub_r001748_15 >= -100 && pub_r001748_15 <= 100);
    __CPROVER_assume(pub_r001748_16 >= -100 && pub_r001748_16 <= 100);
    __CPROVER_assume(pub_r001748_17 >= -100 && pub_r001748_17 <= 100);
    __CPROVER_assume(sec_r001748_0 >= 0 && sec_r001748_0 <= 255);
    __CPROVER_assume(sec_r001748_1 >= 0 && sec_r001748_1 <= 255);
    __CPROVER_assume(sec_r001748_2 >= 0 && sec_r001748_2 <= 255);
    __CPROVER_assume(sec_r001748_3 >= 0 && sec_r001748_3 <= 255);
    __CPROVER_assume(sec_r001748_4 >= 0 && sec_r001748_4 <= 255);
    __CPROVER_assume(sec_r001748_5 >= 0 && sec_r001748_5 <= 255);
    __CPROVER_assume(sec_r001748_6 >= 0 && sec_r001748_6 <= 255);
    __CPROVER_assume(sec_r001748_7 >= 0 && sec_r001748_7 <= 255);
    __CPROVER_assume(sec_r001748_8 >= 0 && sec_r001748_8 <= 255);
    __CPROVER_assume(sec_r001748_9 >= 0 && sec_r001748_9 <= 255);
    __CPROVER_assume(sec_r001748_10 >= 0 && sec_r001748_10 <= 255);
    __CPROVER_assume(sec_r001748_11 >= 0 && sec_r001748_11 <= 255);
    __CPROVER_assume(sec_r001748_12 >= 0 && sec_r001748_12 <= 255);
    __CPROVER_assume(sec_r001748_13 >= 0 && sec_r001748_13 <= 255);
    __CPROVER_assume(sec_r001748_14 >= 0 && sec_r001748_14 <= 255);
    __CPROVER_assume(sec_r001748_15 >= 0 && sec_r001748_15 <= 255);
    __CPROVER_assume(sec_r001748_16 >= 0 && sec_r001748_16 <= 255);
    __CPROVER_assume(sec_r001748_17 >= 0 && sec_r001748_17 <= 255);
    __CPROVER_assume(sec_r001748_18 >= 0 && sec_r001748_18 <= 255);
    __CPROVER_assume(sec_r001748_19 >= 0 && sec_r001748_19 <= 255);
    __CPROVER_assume(sec_r001748_20 >= 0 && sec_r001748_20 <= 255);
    __CPROVER_assume(sec_r001748_21 >= 0 && sec_r001748_21 <= 255);
    __CPROVER_assume(sec_r001748_22 >= 0 && sec_r001748_22 <= 255);

    struct EventLog_R001748_4813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001748_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001748_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001748_0 + 7) & 15;
    struct MatrixBlock_R001748_4813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001748_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001748_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001748_0 + 9) & 15;
    struct SensorNode_R001748_4813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001748_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001748_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001748_0 + 11) & 15;
    struct StreamBuffer_R001748_4813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001748_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001748_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001748_0 + 13) & 15;

    union RegisterBank_R001748_4813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001748_4813_0(sec_r001748_0, sec_r001748_1, pub_r001748_2);
    int helper_flow_1 = fn_R001748_4813_1(sec_r001748_1, sec_r001748_2, pub_r001748_3, pub_r001748_4);
    int helper_flow_2 = fn_R001748_4813_2(sec_r001748_2, sec_r001748_3, pub_r001748_4, pub_r001748_5);
    int helper_flow_3 = fn_R001748_4813_3(sec_r001748_3, pub_r001748_4, pub_r001748_5, pub_r001748_6);
    int helper_flow_4 = fn_R001748_4813_4(sec_r001748_4, sec_r001748_5, pub_r001748_6, pub_r001748_7);
    int helper_flow_5 = fn_R001748_4813_5(sec_r001748_5, sec_r001748_6);
    int helper_flow_6 = fn_R001748_4813_6(sec_r001748_6, pub_r001748_7, pub_r001748_8, pub_r001748_9, pub_r001748_10);
    int helper_flow_7 = fn_R001748_4813_7(sec_r001748_7, sec_r001748_8, pub_r001748_9, pub_r001748_10);
    int helper_flow_8 = fn_R001748_4813_8(sec_r001748_8, sec_r001748_9, pub_r001748_10);
    int helper_flow_9 = fn_R001748_4813_9(sec_r001748_9, sec_r001748_10);
    int helper_flow_10 = fn_R001748_4813_10(sec_r001748_10, pub_r001748_11, pub_r001748_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001748_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (sec_r001748_2 & 15)) & 63;
        if ((sec_r001748_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (sec_r001748_9 & 15)) & 63;
        if ((sec_r001748_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_3 = (stage_v_3 + it * 3 + (sec_r001748_8 & 15)) & 63;
        if ((sec_r001748_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_3 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_3 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001748_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (sec_r001748_6 & 15)) & 63;
        if ((sec_r001748_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001748_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001748_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_10 = (stage_v_10 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_10 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_10 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001748_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001748_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_13 = (stage_v_13 + it * 3 + (sec_r001748_19 & 15)) & 63;
        if ((sec_r001748_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_13 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_13 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_14 = (stage_v_14 + it * 3 + (sec_r001748_21 & 15)) & 63;
        if ((sec_r001748_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_14 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_14 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_15 = (stage_v_15 + it * 3 + (sec_r001748_6 & 15)) & 63;
        if ((sec_r001748_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_15 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_15 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_16 = (stage_v_16 + it * 3 + (sec_r001748_21 & 15)) & 63;
        if ((sec_r001748_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_16 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_16 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001748_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_18 = (stage_v_18 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_18 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_18 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_19 = (stage_v_19 + it * 3 + (sec_r001748_0 & 15)) & 63;
        if ((sec_r001748_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_19 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_19 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001748_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001748_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001748_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_25 = (stage_v_25 + it * 3 + (sec_r001748_20 & 15)) & 63;
        if ((sec_r001748_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_25 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_25 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (sec_r001748_1 & 15)) & 63;
        if ((sec_r001748_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_27 = (stage_v_27 + it * 3 + (sec_r001748_22 & 15)) & 63;
        if ((sec_r001748_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_27 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_27 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001748_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_29 = (stage_v_29 + it * 3 + (sec_r001748_22 & 15)) & 63;
        if ((sec_r001748_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_29 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_29 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (sec_r001748_15 & 15)) & 63;
        if ((sec_r001748_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_31 = (stage_v_31 + it * 3 + (stage_v_3 & 15)) & 63;
        if ((stage_v_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_31 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_31 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_32 = (stage_v_32 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_32 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_32 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001748_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_34 = (stage_v_34 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_34 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_34 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001748_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001748_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001748_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001748_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001748_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001748_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_43 = (stage_v_43 + it * 3 + (sec_r001748_5 & 15)) & 63;
        if ((sec_r001748_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_43 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_43 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001748_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (sec_r001748_5 & 15)) & 63;
        if ((sec_r001748_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (sec_r001748_4 & 15)) & 63;
        if ((sec_r001748_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_47 = (stage_v_47 + it * 3 + (stage_v_45 & 15)) & 63;
        if ((stage_v_45 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_47 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_47 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_48 = (stage_v_48 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_48 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_48 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001748_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001748_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001748_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001748_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_55 = (stage_v_55 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_55 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_55 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001748_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_57 = (stage_v_57 + it * 3 + (stage_v_15 & 15)) & 63;
        if ((stage_v_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_57 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_57 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_58 = (stage_v_58 + it * 3 + (stage_v_48 & 15)) & 63;
        if ((stage_v_48 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_58 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_58 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_60 = (stage_v_60 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_60 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_60 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001748_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001748_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001748_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001748_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_65 = (stage_v_65 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_65 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_65 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_66 = (stage_v_66 + it * 3 + (sec_r001748_21 & 15)) & 63;
        if ((sec_r001748_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_66 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_66 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_67 = (stage_v_67 + it * 3 + (sec_r001748_22 & 15)) & 63;
        if ((sec_r001748_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_67 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_67 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_68 = (stage_v_68 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_68 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_68 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001748_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_70 = (stage_v_70 + it * 3 + (sec_r001748_5 & 15)) & 63;
        if ((sec_r001748_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_70 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_70 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_71 = (stage_v_71 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_71 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_71 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (stage_v_47 & 15)) & 63;
        if ((stage_v_47 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_72 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_72 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_74 = (stage_v_74 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_74 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_74 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (sec_r001748_11 & 15)) & 63;
        if ((sec_r001748_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001748_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_77 = (stage_v_77 + it * 3 + (stage_v_13 & 15)) & 63;
        if ((stage_v_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_77 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_77 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001748_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001748_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_81 = (stage_v_81 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_81 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_81 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_82 = (stage_v_82 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_82 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_82 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001748_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (stage_v_66 & 15)) & 63;
        if ((stage_v_66 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (sec_r001748_20 & 15)) & 63;
        if ((sec_r001748_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001748_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001748_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001748_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_89 = (stage_v_89 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_89 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_89 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001748_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_92 = (stage_v_92 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_92 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_92 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_93 = (stage_v_93 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_93 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_93 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_96 = (stage_v_96 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_96 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_96 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001748_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_98 = (stage_v_98 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_98 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_98 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_99 = (stage_v_99 + it * 3 + (sec_r001748_5 & 15)) & 63;
        if ((sec_r001748_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_99 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_99 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_100 = (stage_v_100 + it * 3 + (sec_r001748_15 & 15)) & 63;
        if ((sec_r001748_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_100 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_100 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (stage_v_49 & 15)) & 63;
        if ((stage_v_49 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001748_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_93 & 15)) & 63;
        if ((stage_v_93 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (sec_r001748_8 & 15)) & 63;
        if ((sec_r001748_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_105 = (stage_v_105 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_105 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_105 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001748_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001748_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_108 = (stage_v_108 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_108 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_108 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_109 = (stage_v_109 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_109 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_109 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_110 = (stage_v_110 + it * 3 + (sec_r001748_0 & 15)) & 63;
        if ((sec_r001748_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_110 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_110 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_111 = (stage_v_111 + it * 3 + (stage_v_98 & 15)) & 63;
        if ((stage_v_98 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_111 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_111 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_112 = (stage_v_112 + it * 3 + (stage_v_34 & 15)) & 63;
        if ((stage_v_34 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_112 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_112 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_113 = (stage_v_113 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_113 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_113 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001748_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_115 = (stage_v_115 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_115 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_115 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001748_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_117 = (stage_v_117 + it * 3 + (sec_r001748_3 & 15)) & 63;
        if ((sec_r001748_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_117 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_117 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (sec_r001748_21 & 15)) & 63;
        if ((sec_r001748_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_119 = (stage_v_119 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_119 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_119 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001748_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001748_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_122 = (stage_v_122 + it * 3 + (stage_v_66 & 15)) & 63;
        if ((stage_v_66 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_122 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_122 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001748_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001748_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_125 = (stage_v_125 + it * 3 + (stage_v_81 & 15)) & 63;
        if ((stage_v_81 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_125 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_125 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_126 = (stage_v_126 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_126 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_126 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001748_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_128 = (stage_v_128 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_128 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_128 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001748_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001748_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001748_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001748_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_134 = (stage_v_134 + it * 3 + (stage_v_108 & 15)) & 63;
        if ((stage_v_108 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_134 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_134 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001748_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001748_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_138 = (stage_v_138 + it * 3 + (sec_r001748_22 & 15)) & 63;
        if ((sec_r001748_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_138 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_138 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (sec_r001748_22 & 15)) & 63;
        if ((sec_r001748_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_141 = (stage_v_141 + it * 3 + (stage_v_13 & 15)) & 63;
        if ((stage_v_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_141 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_141 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001748_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_143 = (stage_v_143 + it * 3 + (sec_r001748_22 & 15)) & 63;
        if ((sec_r001748_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_143 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_143 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001748_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001748_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001748_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001748_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (stage_v_110 & 15)) & 63;
        if ((stage_v_110 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_149 = (stage_v_149 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_149 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_149 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001748_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_152 = (stage_v_152 + it * 3 + (stage_v_105 & 15)) & 63;
        if ((stage_v_105 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_152 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_152 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001748_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001748_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_155 = (stage_v_155 + it * 3 + (stage_v_74 & 15)) & 63;
        if ((stage_v_74 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_155 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_155 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001748_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (stage_v_58 & 15)) & 63;
        if ((stage_v_58 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_158 = (stage_v_158 + it * 3 + (sec_r001748_0 & 15)) & 63;
        if ((sec_r001748_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_158 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_158 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001748_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_160 = (stage_v_160 + it * 3 + (sec_r001748_5 & 15)) & 63;
        if ((sec_r001748_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_160 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_160 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (sec_r001748_15 & 15)) & 63;
        if ((sec_r001748_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (stage_v_77 & 15)) & 63;
        if ((stage_v_77 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001748_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (sec_r001748_0 & 15)) & 63;
        if ((sec_r001748_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_165 = (stage_v_165 + it * 3 + (stage_v_164 & 15)) & 63;
        if ((stage_v_164 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_165 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_165 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_166 = (stage_v_166 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_166 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_166 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_167 = (stage_v_167 + it * 3 + (sec_r001748_21 & 15)) & 63;
        if ((sec_r001748_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_167 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_167 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_168 = (stage_v_168 + it * 3 + (stage_v_13 & 15)) & 63;
        if ((stage_v_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_168 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_168 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_169 = (stage_v_169 + it * 3 + (sec_r001748_18 & 15)) & 63;
        if ((sec_r001748_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_169 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_169 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_170 = (stage_v_170 + it * 3 + (stage_v_151 & 15)) & 63;
        if ((stage_v_151 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_170 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_170 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001748_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001748_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_174 = (stage_v_174 + it * 3 + (stage_v_71 & 15)) & 63;
        if ((stage_v_71 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_174 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_174 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001748_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_176 = (stage_v_176 + it * 3 + (stage_v_98 & 15)) & 63;
        if ((stage_v_98 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_176 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_176 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_177 = (stage_v_177 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_177 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_177 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001748_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_179 = (stage_v_179 + it * 3 + (stage_v_96 & 15)) & 63;
        if ((stage_v_96 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_179 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_179 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_180 = (stage_v_180 + it * 3 + (sec_r001748_20 & 15)) & 63;
        if ((sec_r001748_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_180 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_180 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_181 = (stage_v_181 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_181 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_181 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (stage_v_13 & 15)) & 63;
        if ((stage_v_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (stage_v_143 & 15)) & 63;
        if ((stage_v_143 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_184 = (stage_v_184 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_184 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_184 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001748_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_187 = (stage_v_187 + it * 3 + (stage_v_161 & 15)) & 63;
        if ((stage_v_161 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_187 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_187 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001748_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_189 = (stage_v_189 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_189 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_189 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001748_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_191 = (stage_v_191 + it * 3 + (stage_v_181 & 15)) & 63;
        if ((stage_v_181 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_191 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_191 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001748_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_193 = (stage_v_193 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_193 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_193 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001748_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_195 = (stage_v_195 + it * 3 + (stage_v_181 & 15)) & 63;
        if ((stage_v_181 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_195 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_195 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001748_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001748_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001748_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001748_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_202 = (stage_v_202 + it * 3 + (stage_v_115 & 15)) & 63;
        if ((stage_v_115 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_202 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_202 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_203 = (stage_v_203 + it * 3 + (stage_v_158 & 15)) & 63;
        if ((stage_v_158 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_203 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_203 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_204 = (stage_v_204 + it * 3 + (stage_v_164 & 15)) & 63;
        if ((stage_v_164 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_204 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_204 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001748_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_206 = (stage_v_206 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_206 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_206 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_207 = (stage_v_207 + it * 3 + (sec_r001748_3 & 15)) & 63;
        if ((sec_r001748_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_207 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_207 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_208 = (stage_v_208 + it * 3 + (sec_r001748_21 & 15)) & 63;
        if ((sec_r001748_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_208 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_208 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001748_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_210 = (stage_v_210 + it * 3 + (helper_flow_8 & 15)) & 63;
        if ((helper_flow_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_210 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_210 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_211 = (stage_v_211 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_211 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_211 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_212 = (stage_v_212 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_212 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_212 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_213 = (stage_v_213 + it * 3 + (stage_v_105 & 15)) & 63;
        if ((stage_v_105 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_213 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_213 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001748_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_215 = (stage_v_215 + it * 3 + (stage_v_68 & 15)) & 63;
        if ((stage_v_68 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_215 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_215 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001748_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_217 = (stage_v_217 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_217 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_217 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001748_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_219 = (stage_v_219 + it * 3 + (stage_v_208 & 15)) & 63;
        if ((stage_v_208 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_219 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_219 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_220 = (stage_v_220 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_220 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_220 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_221 = (stage_v_221 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_221 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_221 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001748_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001748_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_224 = (stage_v_224 + it * 3 + (sec_r001748_11 & 15)) & 63;
        if ((sec_r001748_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_224 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_224 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_225 = (stage_v_225 + it * 3 + (stage_v_134 & 15)) & 63;
        if ((stage_v_134 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_225 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_225 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_226 = (stage_v_226 + it * 3 + (sec_r001748_2 & 15)) & 63;
        if ((sec_r001748_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_226 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_226 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_227 = (stage_v_227 + it * 3 + (stage_v_217 & 15)) & 63;
        if ((stage_v_217 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_227 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_227 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_228 = (stage_v_228 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_228 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_228 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001748_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001748_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001748_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_232 = (stage_v_232 + it * 3 + (stage_v_89 & 15)) & 63;
        if ((stage_v_89 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_232 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_232 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
