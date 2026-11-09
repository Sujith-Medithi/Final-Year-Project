/*
 * Benchmark Program: R001576
 * Security Family: implicit_flow
 * Generator Seed: 657613
 * High Inputs: 23 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001576_7613_0 {
    short reading;
    int offset;
    int calib;
    short status;
    short threshold;
    unsigned char gain;
    int buffer[3];
};

struct MatrixBlock_R001576_7613_1 {
    unsigned char trace;
    int determinant;
    short dim;
    int buffer[3];
};

union TelemetryField_R001576_7613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001576_7613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001576_7613_0(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001576_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int sample_33 = local_arr[aux % 3];
    acc = (acc + sample_33 * 2) & 127;
    int pivot_27 = (aux + st.buffer[1]) & 3;
    switch (pivot_27) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_35 > 14) {
        acc = (acc + factor_35 * 2 + 5) & 127;
        aux ^= (factor_35 & 15);
    } else {
        acc = (acc - factor_35 + 11) & 127;
        aux += 3;
    }
    int segment_77 = 0;
    for (int k = 0; k < 3; k++) {
        segment_77 = (segment_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_77) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_50) & 63;
    acc ^= aux;
    int delta_60 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_60 > 22) {
        acc = (acc + delta_60 * 2 + 5) & 127;
        aux ^= (delta_60 & 15);
    } else {
        acc = (acc - delta_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int bound_82 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_82 > 50) {
        acc = (acc + bound_82 * 2 + 5) & 127;
        aux ^= (bound_82 & 15);
    } else {
        acc = (acc - bound_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001576_7613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001576_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int weight_27 = local_arr[aux % 3];
    acc = (acc + weight_27 * 2) & 127;
    int tally_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_28) & 63;
    acc ^= aux;
    int cursor_58 = (aux + st.buffer[1]) & 3;
    switch (cursor_58) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_4(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001576_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_72 = 0;
    for (int k = 0; k < 2; k++) {
        phase_72 = (phase_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_72) & 127;
    }
    int anchor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001576_7613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_89) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001576_7613_6(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int delta_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_14 = local_arr[aux % 3];
    acc = (acc + phase_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001576_7613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001576_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int scale_86 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_86 > 39) {
        acc = (acc + scale_86 * 2 + 5) & 127;
        aux ^= (scale_86 & 15);
    } else {
        acc = (acc - scale_86 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_69 = 0;
    for (int k = 0; k < 2; k++) {
        phase_69 = (phase_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_69) & 127;
    }
    int parity_40 = (aux + st.buffer[1]) & 3;
    switch (parity_40) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_79 = (aux + st.buffer[1]) & 3;
    switch (quotient_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_74 = 0;
    for (int k = 0; k < 2; k++) {
        window_74 = (window_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_74) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001576_7613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int quantum_96 = local_arr[aux % 3];
    acc = (acc + quantum_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_78 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_78 > 47) {
        acc = (acc + threshold_78 * 2 + 5) & 127;
        aux ^= (threshold_78 & 15);
    } else {
        acc = (acc - threshold_78 + 11) & 127;
        aux += 3;
    }
    int bound_90 = 0;
    for (int k = 0; k < 2; k++) {
        bound_90 = (bound_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_10(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_47) & 63;
    acc ^= aux;
    int damping_34 = 0;
    for (int k = 0; k < 2; k++) {
        damping_34 = (damping_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_34) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_11(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001576_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_56 = local_arr[aux % 3];
    acc = (acc + coefficient_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001576_7613_12(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_76) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001576_7613_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quantum_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_28) & 63;
    acc ^= aux;
    int offset_67 = (aux + st.buffer[1]) & 3;
    switch (offset_67) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_58 = local_arr[aux % 3];
    acc = (acc + offset_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001576_7613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int factor_66 = local_arr[aux % 3];
    acc = (acc + factor_66 * 2) & 127;
    int margin_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_49) & 63;
    acc ^= aux;
    int quotient_67 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_67 = (quotient_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001576_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_93 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_93 > 37) {
        acc = (acc + quotient_93 * 2 + 5) & 127;
        aux ^= (quotient_93 & 15);
    } else {
        acc = (acc - quotient_93 + 11) & 127;
        aux += 3;
    }
    int pivot_12 = (aux + st.buffer[1]) & 3;
    switch (pivot_12) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001576_7613_16(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001576_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int threshold_66 = (aux + st.buffer[1]) & 3;
    switch (threshold_66) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_52 = local_arr[aux % 3];
    acc = (acc + bound_52 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001576_7613_17(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001576_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_59 = (aux + st.buffer[1]) & 3;
    switch (accumulator_59) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_64 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_64 > 37) {
        acc = (acc + metric_64 * 2 + 5) & 127;
        aux ^= (metric_64 & 15);
    } else {
        acc = (acc - metric_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001576_0;
    int sec_r001576_1;
    int sec_r001576_2;
    int sec_r001576_3;
    int sec_r001576_4;
    int sec_r001576_5;
    int sec_r001576_6;
    int sec_r001576_7;
    int sec_r001576_8;
    int sec_r001576_9;
    int sec_r001576_10;
    int sec_r001576_11;
    int sec_r001576_12;
    int sec_r001576_13;
    int sec_r001576_14;
    int sec_r001576_15;
    int sec_r001576_16;
    int sec_r001576_17;
    int sec_r001576_18;
    int sec_r001576_19;
    int sec_r001576_20;
    int sec_r001576_21;
    int sec_r001576_22;
    int pub_r001576_0;
    int pub_r001576_1;
    int pub_r001576_2;
    int pub_r001576_3;
    int pub_r001576_4;
    int pub_r001576_5;
    int pub_r001576_6;
    int pub_r001576_7;
    int pub_r001576_8;
    int pub_r001576_9;
    int pub_r001576_10;
    int pub_r001576_11;
    int pub_r001576_12;
    int pub_r001576_13;
    int pub_r001576_14;
    int pub_r001576_15;
    int pub_r001576_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001576_0 >= -100 && pub_r001576_0 <= 100);
    __CPROVER_assume(pub_r001576_1 >= -100 && pub_r001576_1 <= 100);
    __CPROVER_assume(pub_r001576_2 >= -100 && pub_r001576_2 <= 100);
    __CPROVER_assume(pub_r001576_3 >= -100 && pub_r001576_3 <= 100);
    __CPROVER_assume(pub_r001576_4 >= -100 && pub_r001576_4 <= 100);
    __CPROVER_assume(pub_r001576_5 >= -100 && pub_r001576_5 <= 100);
    __CPROVER_assume(pub_r001576_6 >= -100 && pub_r001576_6 <= 100);
    __CPROVER_assume(pub_r001576_7 >= -100 && pub_r001576_7 <= 100);
    __CPROVER_assume(pub_r001576_8 >= -100 && pub_r001576_8 <= 100);
    __CPROVER_assume(pub_r001576_9 >= -100 && pub_r001576_9 <= 100);
    __CPROVER_assume(pub_r001576_10 >= -100 && pub_r001576_10 <= 100);
    __CPROVER_assume(pub_r001576_11 >= -100 && pub_r001576_11 <= 100);
    __CPROVER_assume(pub_r001576_12 >= -100 && pub_r001576_12 <= 100);
    __CPROVER_assume(pub_r001576_13 >= -100 && pub_r001576_13 <= 100);
    __CPROVER_assume(pub_r001576_14 >= -100 && pub_r001576_14 <= 100);
    __CPROVER_assume(pub_r001576_15 >= -100 && pub_r001576_15 <= 100);
    __CPROVER_assume(pub_r001576_16 >= -100 && pub_r001576_16 <= 100);
    __CPROVER_assume(sec_r001576_0 >= 0 && sec_r001576_0 <= 255);
    __CPROVER_assume(sec_r001576_1 >= 0 && sec_r001576_1 <= 255);
    __CPROVER_assume(sec_r001576_2 >= 0 && sec_r001576_2 <= 255);
    __CPROVER_assume(sec_r001576_3 >= 0 && sec_r001576_3 <= 255);
    __CPROVER_assume(sec_r001576_4 >= 0 && sec_r001576_4 <= 255);
    __CPROVER_assume(sec_r001576_5 >= 0 && sec_r001576_5 <= 255);
    __CPROVER_assume(sec_r001576_6 >= 0 && sec_r001576_6 <= 255);
    __CPROVER_assume(sec_r001576_7 >= 0 && sec_r001576_7 <= 255);
    __CPROVER_assume(sec_r001576_8 >= 0 && sec_r001576_8 <= 255);
    __CPROVER_assume(sec_r001576_9 >= 0 && sec_r001576_9 <= 255);
    __CPROVER_assume(sec_r001576_10 >= 0 && sec_r001576_10 <= 255);
    __CPROVER_assume(sec_r001576_11 >= 0 && sec_r001576_11 <= 255);
    __CPROVER_assume(sec_r001576_12 >= 0 && sec_r001576_12 <= 255);
    __CPROVER_assume(sec_r001576_13 >= 0 && sec_r001576_13 <= 255);
    __CPROVER_assume(sec_r001576_14 >= 0 && sec_r001576_14 <= 255);
    __CPROVER_assume(sec_r001576_15 >= 0 && sec_r001576_15 <= 255);
    __CPROVER_assume(sec_r001576_16 >= 0 && sec_r001576_16 <= 255);
    __CPROVER_assume(sec_r001576_17 >= 0 && sec_r001576_17 <= 255);
    __CPROVER_assume(sec_r001576_18 >= 0 && sec_r001576_18 <= 255);
    __CPROVER_assume(sec_r001576_19 >= 0 && sec_r001576_19 <= 255);
    __CPROVER_assume(sec_r001576_20 >= 0 && sec_r001576_20 <= 255);
    __CPROVER_assume(sec_r001576_21 >= 0 && sec_r001576_21 <= 255);
    __CPROVER_assume(sec_r001576_22 >= 0 && sec_r001576_22 <= 255);

    struct SensorNode_R001576_7613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001576_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001576_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001576_0 + 7) & 15;
    struct MatrixBlock_R001576_7613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001576_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001576_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001576_0 + 9) & 15;

    union TelemetryField_R001576_7613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001576_7613_0(sec_r001576_0, sec_r001576_1, pub_r001576_2);
    int helper_flow_1 = fn_R001576_7613_1(sec_r001576_1, pub_r001576_2, pub_r001576_3, pub_r001576_4);
    int helper_flow_2 = fn_R001576_7613_2(sec_r001576_2, sec_r001576_3, pub_r001576_4, pub_r001576_5, pub_r001576_6);
    int helper_flow_3 = fn_R001576_7613_3(sec_r001576_3, pub_r001576_4, pub_r001576_5, pub_r001576_6, pub_r001576_7);
    int helper_flow_4 = fn_R001576_7613_4(sec_r001576_4, sec_r001576_5);
    int helper_flow_5 = fn_R001576_7613_5(sec_r001576_5, pub_r001576_6, pub_r001576_7, pub_r001576_8, pub_r001576_9);
    int helper_flow_6 = fn_R001576_7613_6(sec_r001576_6, pub_r001576_7, pub_r001576_8);
    int helper_flow_7 = fn_R001576_7613_7(sec_r001576_7, sec_r001576_8, pub_r001576_9, pub_r001576_10, pub_r001576_11);
    int helper_flow_8 = fn_R001576_7613_8(sec_r001576_8, sec_r001576_9, pub_r001576_10, pub_r001576_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001576_9 + pub_r001576_0 * 2 + 5) & 127;
    if (stage_v_0 > 32) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001576_21 + pub_r001576_1 * 2 + 8) & 127;
    if (stage_v_1 > 58) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001576_9 + pub_r001576_10 * 2 + 11) & 127;
    if (stage_v_2 > 22) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001576_3 + pub_r001576_16 * 2 + 14) & 127;
    if (stage_v_3 > 21) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001576_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001576_13 + pub_r001576_14 * 2 + 20) & 127;
    if (stage_v_5 > 37) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001576_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001576_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001576_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001576_4 + pub_r001576_9 * 2 + 32) & 127;
    if (stage_v_9 > 40) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001576_0 + pub_r001576_0 * 2 + 35) & 127;
    if (stage_v_10 > 31) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001576_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_4 + pub_r001576_9 * 2 + 41) & 127;
    if (stage_v_12 > 53) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001576_4 + pub_r001576_10 * 2 + 44) & 127;
    if (stage_v_13 > 26) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_5 + pub_r001576_15 * 2 + 47) & 127;
    if (stage_v_14 > 18) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_13 + pub_r001576_13 * 2 + 50) & 127;
    if (stage_v_15 > 17) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001576_21 + pub_r001576_15 * 2 + 53) & 127;
    if (stage_v_16 > 37) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001576_18 + pub_r001576_10 * 2 + 56) & 127;
    if (stage_v_17 > 35) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_5 + pub_r001576_8 * 2 + 59) & 127;
    if (stage_v_18 > 16) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001576_14 + pub_r001576_13 * 2 + 62) & 127;
    if (stage_v_19 > 27) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001576_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_18 + pub_r001576_7 * 2 + 68) & 127;
    if (stage_v_21 > 54) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001576_6 + pub_r001576_7 * 2 + 71) & 127;
    if (stage_v_22 > 60) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001576_21 + pub_r001576_8 * 2 + 74) & 127;
    if (stage_v_23 > 55) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001576_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001576_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_21 + pub_r001576_15 * 2 + 83) & 127;
    if (stage_v_26 > 24) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001576_19 + pub_r001576_4 * 2 + 86) & 127;
    if (stage_v_27 > 26) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_10 + pub_r001576_5 * 2 + 89) & 127;
    if (stage_v_28 > 50) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_17 + pub_r001576_12 * 2 + 92) & 127;
    if (stage_v_29 > 54) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_16 + pub_r001576_4 * 2 + 95) & 127;
    if (stage_v_30 > 35) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001576_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001576_8 + pub_r001576_16 * 2 + 101) & 127;
    if (stage_v_32 > 35) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_18 + pub_r001576_11 * 2 + 104) & 127;
    if (stage_v_33 > 24) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_10 + pub_r001576_15 * 2 + 107) & 127;
    if (stage_v_34 > 39) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001576_1 + pub_r001576_7 * 2 + 110) & 127;
    if (stage_v_35 > 29) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_14 + pub_r001576_15 * 2 + 113) & 127;
    if (stage_v_36 > 19) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001576_21 + pub_r001576_4 * 2 + 116) & 127;
    if (stage_v_37 > 54) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001576_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001576_1 + pub_r001576_6 * 2 + 122) & 127;
    if (stage_v_39 > 52) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001576_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_30 + pub_r001576_6 * 2 + 128) & 127;
    if (stage_v_41 > 34) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001576_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001576_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001576_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001576_10 + pub_r001576_15 * 2 + 140) & 127;
    if (stage_v_45 > 41) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_36 + pub_r001576_6 * 2 + 143) & 127;
    if (stage_v_46 > 27) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_19 + pub_r001576_14 * 2 + 146) & 127;
    if (stage_v_47 > 19) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001576_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001576_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_10 + pub_r001576_4 * 2 + 155) & 127;
    if (stage_v_50 > 29) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001576_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001576_21 + pub_r001576_2 * 2 + 161) & 127;
    if (stage_v_52 > 17) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001576_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001576_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_30 + pub_r001576_3 * 2 + 170) & 127;
    if (stage_v_55 > 31) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_47 + pub_r001576_6 * 2 + 173) & 127;
    if (stage_v_56 > 21) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001576_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_36 + pub_r001576_10 * 2 + 179) & 127;
    if (stage_v_58 > 43) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_13 + pub_r001576_12 * 2 + 182) & 127;
    if (stage_v_59 > 34) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001576_3 + pub_r001576_10 * 2 + 185) & 127;
    if (stage_v_60 > 48) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001576_22 + pub_r001576_16 * 2 + 188) & 127;
    if (stage_v_61 > 44) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_34 + pub_r001576_3 * 2 + 191) & 127;
    if (stage_v_62 > 35) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001576_0 + pub_r001576_12 * 2 + 194) & 127;
    if (stage_v_63 > 50) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_19 + pub_r001576_2 * 2 + 197) & 127;
    if (stage_v_64 > 45) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_63 + pub_r001576_2 * 2 + 200) & 127;
    if (stage_v_65 > 41) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_35 + pub_r001576_16 * 2 + 203) & 127;
    if (stage_v_66 > 29) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_12 + pub_r001576_15 * 2 + 206) & 127;
    if (stage_v_67 > 19) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001576_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001576_8 + pub_r001576_8 * 2 + 212) & 127;
    if (stage_v_69 > 42) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_39 + pub_r001576_12 * 2 + 215) & 127;
    if (stage_v_70 > 39) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_17 + pub_r001576_7 * 2 + 218) & 127;
    if (stage_v_71 > 48) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001576_7 + pub_r001576_0 * 2 + 221) & 127;
    if (stage_v_72 > 20) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_71 + pub_r001576_12 * 2 + 224) & 127;
    if (stage_v_73 > 26) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_45 + pub_r001576_6 * 2 + 227) & 127;
    if (stage_v_74 > 45) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001576_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001576_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001576_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_27 + pub_r001576_8 * 2 + 239) & 127;
    if (stage_v_78 > 41) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_13 + pub_r001576_12 * 2 + 242) & 127;
    if (stage_v_79 > 20) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001576_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001576_13 + pub_r001576_12 * 2 + 248) & 127;
    if (stage_v_81 > 60) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_15 + pub_r001576_7 * 2 + 251) & 127;
    if (stage_v_82 > 21) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_52 + pub_r001576_13 * 2 + 254) & 127;
    if (stage_v_83 > 45) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_74 + pub_r001576_6 * 2 + 257) & 127;
    if (stage_v_84 > 31) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001576_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_45 + pub_r001576_8 * 2 + 263) & 127;
    if (stage_v_86 > 21) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001576_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001576_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001576_12 + pub_r001576_4 * 2 + 272) & 127;
    if (stage_v_89 > 15) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001576_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_56 + pub_r001576_16 * 2 + 278) & 127;
    if (stage_v_91 > 27) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001576_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_12 + pub_r001576_16 * 2 + 284) & 127;
    if (stage_v_93 > 37) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001576_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_61 + pub_r001576_7 * 2 + 290) & 127;
    if (stage_v_95 > 44) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_22 + pub_r001576_13 * 2 + 293) & 127;
    if (stage_v_96 > 31) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_52 + pub_r001576_4 * 2 + 296) & 127;
    if (stage_v_97 > 35) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_2 + pub_r001576_9 * 2 + 299) & 127;
    if (stage_v_98 > 49) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (helper_flow_4 + pub_r001576_11 * 2 + 302) & 127;
    if (stage_v_99 > 25) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001576_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_65 + pub_r001576_5 * 2 + 308) & 127;
    if (stage_v_101 > 21) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_12 + pub_r001576_5 * 2 + 311) & 127;
    if (stage_v_102 > 29) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_81 + pub_r001576_8 * 2 + 314) & 127;
    if (stage_v_103 > 46) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001576_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_91 + pub_r001576_8 * 2 + 320) & 127;
    if (stage_v_105 > 39) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_56 + pub_r001576_16 * 2 + 323) & 127;
    if (stage_v_106 > 27) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_28 + pub_r001576_16 * 2 + 326) & 127;
    if (stage_v_107 > 42) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_5 + pub_r001576_1 * 2 + 329) & 127;
    if (stage_v_108 > 48) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001576_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_96 + pub_r001576_8 * 2 + 335) & 127;
    if (stage_v_110 > 59) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001576_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001576_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_97 + pub_r001576_9 * 2 + 344) & 127;
    if (stage_v_113 > 31) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001576_6 + pub_r001576_5 * 2 + 347) & 127;
    if (stage_v_114 > 24) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001576_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001576_6 + pub_r001576_11 * 2 + 353) & 127;
    if (stage_v_116 > 34) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001576_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_67 + pub_r001576_13 * 2 + 359) & 127;
    if (stage_v_118 > 32) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_81 + pub_r001576_6 * 2 + 362) & 127;
    if (stage_v_119 > 26) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001576_21 + pub_r001576_1 * 2 + 365) & 127;
    if (stage_v_120 > 31) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_99 + pub_r001576_14 * 2 + 368) & 127;
    if (stage_v_121 > 33) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_72 + pub_r001576_9 * 2 + 371) & 127;
    if (stage_v_122 > 19) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001576_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001576_13 + pub_r001576_9 * 2 + 377) & 127;
    if (stage_v_124 > 15) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_1 + pub_r001576_12 * 2 + 380) & 127;
    if (stage_v_125 > 44) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_83 + pub_r001576_0 * 2 + 383) & 127;
    if (stage_v_126 > 24) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_10 + pub_r001576_6 * 2 + 386) & 127;
    if (stage_v_127 > 48) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001576_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_120 + pub_r001576_5 * 2 + 392) & 127;
    if (stage_v_129 > 48) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001576_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r001576_15 + pub_r001576_3 * 2 + 398) & 127;
    if (stage_v_131 > 51) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001576_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_22 + pub_r001576_13 * 2 + 404) & 127;
    if (stage_v_133 > 38) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_97 + pub_r001576_1 * 2 + 407) & 127;
    if (stage_v_134 > 60) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001576_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_105 + pub_r001576_4 * 2 + 413) & 127;
    if (stage_v_136 > 22) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_45 + pub_r001576_0 * 2 + 416) & 127;
    if (stage_v_137 > 25) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_119 + pub_r001576_4 * 2 + 419) & 127;
    if (stage_v_138 > 57) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_32 + pub_r001576_13 * 2 + 422) & 127;
    if (stage_v_139 > 30) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_12 + pub_r001576_0 * 2 + 425) & 127;
    if (stage_v_140 > 32) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_3 + pub_r001576_12 * 2 + 428) & 127;
    if (stage_v_141 > 59) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_106 + pub_r001576_15 * 2 + 431) & 127;
    if (stage_v_142 > 19) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001576_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_67 + pub_r001576_14 * 2 + 437) & 127;
    if (stage_v_144 > 59) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001576_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001576_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001576_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_15 + pub_r001576_13 * 2 + 449) & 127;
    if (stage_v_148 > 18) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001576_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_127 + pub_r001576_7 * 2 + 455) & 127;
    if (stage_v_150 > 25) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_105 + pub_r001576_7 * 2 + 458) & 127;
    if (stage_v_151 > 58) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_9 + pub_r001576_3 * 2 + 461) & 127;
    if (stage_v_152 > 29) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_10 + pub_r001576_16 * 2 + 464) & 127;
    if (stage_v_153 > 21) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_82 + pub_r001576_12 * 2 + 467) & 127;
    if (stage_v_154 > 29) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_1 + pub_r001576_2 * 2 + 470) & 127;
    if (stage_v_155 > 48) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001576_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_52 + pub_r001576_3 * 2 + 476) & 127;
    if (stage_v_157 > 16) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r001576_15 + pub_r001576_14 * 2 + 479) & 127;
    if (stage_v_158 > 47) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_151 + pub_r001576_6 * 2 + 482) & 127;
    if (stage_v_159 > 43) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_96 + pub_r001576_16 * 2 + 485) & 127;
    if (stage_v_160 > 53) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_2 + pub_r001576_9 * 2 + 488) & 127;
    if (stage_v_161 > 43) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001576_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001576_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001576_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_19 + pub_r001576_0 * 2 + 500) & 127;
    if (stage_v_165 > 39) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_140 + pub_r001576_13 * 2 + 503) & 127;
    if (stage_v_166 > 20) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_96 + pub_r001576_9 * 2 + 506) & 127;
    if (stage_v_167 > 42) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (sec_r001576_6 + pub_r001576_14 * 2 + 509) & 127;
    if (stage_v_168 > 48) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_166 + pub_r001576_11 * 2 + 512) & 127;
    if (stage_v_169 > 24) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001576_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001576_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_39 + pub_r001576_8 * 2 + 521) & 127;
    if (stage_v_172 > 35) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001576_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001576_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001576_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_33 + pub_r001576_0 * 2 + 533) & 127;
    if (stage_v_176 > 19) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_108 + pub_r001576_12 * 2 + 536) & 127;
    if (stage_v_177 > 17) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_56 + pub_r001576_9 * 2 + 539) & 127;
    if (stage_v_178 > 17) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001576_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_74 + pub_r001576_14 * 2 + 545) & 127;
    if (stage_v_180 > 51) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_16 + pub_r001576_16 * 2 + 548) & 127;
    if (stage_v_181 > 54) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_105 + pub_r001576_7 * 2 + 551) & 127;
    if (stage_v_182 > 56) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_59 + pub_r001576_10 * 2 + 554) & 127;
    if (stage_v_183 > 36) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (sec_r001576_9 + pub_r001576_6 * 2 + 557) & 127;
    if (stage_v_184 > 44) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_116 + pub_r001576_14 * 2 + 560) & 127;
    if (stage_v_185 > 28) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_161 + pub_r001576_2 * 2 + 563) & 127;
    if (stage_v_186 > 45) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (sec_r001576_7 + pub_r001576_2 * 2 + 566) & 127;
    if (stage_v_187 > 22) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_137 + pub_r001576_3 * 2 + 569) & 127;
    if (stage_v_188 > 56) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001576_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001576_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001576_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_15 + pub_r001576_3 * 2 + 581) & 127;
    if (stage_v_192 > 39) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001576_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_91 + pub_r001576_7 * 2 + 587) & 127;
    if (stage_v_194 > 36) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_84 + pub_r001576_9 * 2 + 590) & 127;
    if (stage_v_195 > 31) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_70 + pub_r001576_16 * 2 + 593) & 127;
    if (stage_v_196 > 44) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001576_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_35 + pub_r001576_15 * 2 + 599) & 127;
    if (stage_v_198 > 22) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_114 + pub_r001576_14 * 2 + 602) & 127;
    if (stage_v_199 > 50) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_69 + pub_r001576_9 * 2 + 605) & 127;
    if (stage_v_200 > 43) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001576_19 + pub_r001576_1 * 2 + 608) & 127;
    if (stage_v_201 > 17) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001576_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_34 + pub_r001576_13 * 2 + 614) & 127;
    if (stage_v_203 > 37) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_157 + pub_r001576_13 * 2 + 617) & 127;
    if (stage_v_204 > 58) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_144 + pub_r001576_13 * 2 + 620) & 127;
    if (stage_v_205 > 38) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (sec_r001576_22 + pub_r001576_4 * 2 + 623) & 127;
    if (stage_v_206 > 55) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001576_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_34 + pub_r001576_4 * 2 + 629) & 127;
    if (stage_v_208 > 53) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_82 + pub_r001576_7 * 2 + 632) & 127;
    if (stage_v_209 > 47) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_12 + pub_r001576_15 * 2 + 635) & 127;
    if (stage_v_210 > 27) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (sec_r001576_12 + pub_r001576_11 * 2 + 638) & 127;
    if (stage_v_211 > 56) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_148 + pub_r001576_12 * 2 + 641) & 127;
    if (stage_v_212 > 23) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (helper_flow_2 + pub_r001576_11 * 2 + 644) & 127;
    if (stage_v_213 > 41) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_110 + pub_r001576_2 * 2 + 647) & 127;
    if (stage_v_214 > 26) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (sec_r001576_16 + pub_r001576_16 * 2 + 650) & 127;
    if (stage_v_215 > 36) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_107 + pub_r001576_7 * 2 + 653) & 127;
    if (stage_v_216 > 30) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (helper_flow_5 + pub_r001576_15 * 2 + 656) & 127;
    if (stage_v_217 > 35) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (sec_r001576_17 + pub_r001576_4 * 2 + 659) & 127;
    if (stage_v_218 > 31) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_158 + pub_r001576_14 * 2 + 662) & 127;
    if (stage_v_219 > 21) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_9 + pub_r001576_8 * 2 + 665) & 127;
    if (stage_v_220 > 24) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001576_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (helper_flow_0 + pub_r001576_3 * 2 + 671) & 127;
    if (stage_v_222 > 40) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_98 + pub_r001576_1 * 2 + 674) & 127;
    if (stage_v_223 > 18) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001576_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001576_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001576_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
