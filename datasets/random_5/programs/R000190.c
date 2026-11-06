/*
 * Benchmark Program: R000190
 * Security Family: mixed_control_data
 * Generator Seed: 519013
 * High Inputs: 23 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000190_9013_0 {
    int calib;
    unsigned char offset;
    short gain;
    unsigned char status;
    int buffer[3];
};

struct StreamBuffer_R000190_9013_1 {
    int watermark;
    int checksum;
    int head;
    int buffer[3];
};

union TelemetryField_R000190_9013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000190_9013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000190_9013_0(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_21 = (aux + st.buffer[1]) & 3;
    switch (threshold_21) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000190_9013_1(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int cursor_39 = local_arr[aux % 3];
    acc = (acc + cursor_39 * 2) & 127;
    int anchor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_20 > 24) {
        acc = (acc + anchor_20 * 2 + 5) & 127;
        aux ^= (anchor_20 & 15);
    } else {
        acc = (acc - anchor_20 + 11) & 127;
        aux += 3;
    }
    int damping_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_50) & 63;
    acc ^= aux;
    int checksum_98 = (aux + st.buffer[1]) & 3;
    switch (checksum_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000190_9013_2(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int metric_93 = local_arr[aux % 3];
    acc = (acc + metric_93 * 2) & 127;
    int residue_78 = (aux + st.buffer[1]) & 3;
    switch (residue_78) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_89) & 63;
    acc ^= aux;
    int index_reg_22 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_22 > 30) {
        acc = (acc + index_reg_22 * 2 + 5) & 127;
        aux ^= (index_reg_22 & 15);
    } else {
        acc = (acc - index_reg_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000190_9013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int threshold_48 = (aux + st.buffer[1]) & 3;
    switch (threshold_48) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000190_9013_4(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quantum_36 = (aux + st.buffer[1]) & 3;
    switch (quantum_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_23) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_71 = local_arr[aux % 3];
    acc = (acc + offset_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000190_9013_5(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int pivot_70 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_70 > 23) {
        acc = (acc + pivot_70 * 2 + 5) & 127;
        aux ^= (pivot_70 & 15);
    } else {
        acc = (acc - pivot_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_22 = local_arr[aux % 3];
    acc = (acc + metric_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000190_9013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int scale_92 = local_arr[aux % 3];
    acc = (acc + scale_92 * 2) & 127;
    int vector_97 = (aux + st.buffer[1]) & 3;
    switch (vector_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000190_9013_7(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int segment_78 = (aux + st.buffer[1]) & 3;
    switch (segment_78) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_99) & 63;
    acc ^= aux;
    int damping_39 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_39 > 25) {
        acc = (acc + damping_39 * 2 + 5) & 127;
        aux ^= (damping_39 & 15);
    } else {
        acc = (acc - damping_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000190_9013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_95 = (aux + st.buffer[1]) & 3;
    switch (margin_95) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_93 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_93 > 42) {
        acc = (acc + threshold_93 * 2 + 5) & 127;
        aux ^= (threshold_93 & 15);
    } else {
        acc = (acc - threshold_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000190_9013_9(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tally_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_29) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_76 = local_arr[aux % 3];
    acc = (acc + offset_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000190_9013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_60 = (aux + st.buffer[1]) & 3;
    switch (stride_60) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_10 = local_arr[aux % 3];
    acc = (acc + sample_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000190_9013_11(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_93) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_27 = local_arr[aux % 3];
    acc = (acc + damping_27 * 2) & 127;
    int quantum_75 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_75 > 30) {
        acc = (acc + quantum_75 * 2 + 5) & 127;
        aux ^= (quantum_75 & 15);
    } else {
        acc = (acc - quantum_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000190_9013_12(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_41 = local_arr[aux % 3];
    acc = (acc + threshold_41 * 2) & 127;
    int offset_13 = (aux + st.buffer[1]) & 3;
    switch (offset_13) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_43 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_43 > 22) {
        acc = (acc + tracker_43 * 2 + 5) & 127;
        aux ^= (tracker_43 & 15);
    } else {
        acc = (acc - tracker_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000190_9013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_12) & 63;
    acc ^= aux;
    int scale_54 = (aux + st.buffer[1]) & 3;
    switch (scale_54) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000190_9013_14(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_18 = (aux + st.buffer[1]) & 3;
    switch (scale_18) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_38 = local_arr[aux % 3];
    acc = (acc + phase_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000190_9013_15(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000190_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_36) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_42 = local_arr[aux % 3];
    acc = (acc + sample_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000190_9013_16(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000190_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000190_0;
    int sec_r000190_1;
    int sec_r000190_2;
    int sec_r000190_3;
    int sec_r000190_4;
    int sec_r000190_5;
    int sec_r000190_6;
    int sec_r000190_7;
    int sec_r000190_8;
    int sec_r000190_9;
    int sec_r000190_10;
    int sec_r000190_11;
    int sec_r000190_12;
    int sec_r000190_13;
    int sec_r000190_14;
    int sec_r000190_15;
    int sec_r000190_16;
    int sec_r000190_17;
    int sec_r000190_18;
    int sec_r000190_19;
    int sec_r000190_20;
    int sec_r000190_21;
    int sec_r000190_22;
    int pub_r000190_0;
    int pub_r000190_1;
    int pub_r000190_2;
    int pub_r000190_3;
    int pub_r000190_4;
    int pub_r000190_5;
    int pub_r000190_6;
    int pub_r000190_7;
    int pub_r000190_8;
    int pub_r000190_9;
    int pub_r000190_10;
    int pub_r000190_11;
    int pub_r000190_12;
    int pub_r000190_13;
    int pub_r000190_14;
    int pub_r000190_15;
    int pub_r000190_16;
    int pub_r000190_17;
    int pub_r000190_18;
    int pub_r000190_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000190_0 >= -100 && pub_r000190_0 <= 100);
    __CPROVER_assume(pub_r000190_1 >= -100 && pub_r000190_1 <= 100);
    __CPROVER_assume(pub_r000190_2 >= -100 && pub_r000190_2 <= 100);
    __CPROVER_assume(pub_r000190_3 >= -100 && pub_r000190_3 <= 100);
    __CPROVER_assume(pub_r000190_4 >= -100 && pub_r000190_4 <= 100);
    __CPROVER_assume(pub_r000190_5 >= -100 && pub_r000190_5 <= 100);
    __CPROVER_assume(pub_r000190_6 >= -100 && pub_r000190_6 <= 100);
    __CPROVER_assume(pub_r000190_7 >= -100 && pub_r000190_7 <= 100);
    __CPROVER_assume(pub_r000190_8 >= -100 && pub_r000190_8 <= 100);
    __CPROVER_assume(pub_r000190_9 >= -100 && pub_r000190_9 <= 100);
    __CPROVER_assume(pub_r000190_10 >= -100 && pub_r000190_10 <= 100);
    __CPROVER_assume(pub_r000190_11 >= -100 && pub_r000190_11 <= 100);
    __CPROVER_assume(pub_r000190_12 >= -100 && pub_r000190_12 <= 100);
    __CPROVER_assume(pub_r000190_13 >= -100 && pub_r000190_13 <= 100);
    __CPROVER_assume(pub_r000190_14 >= -100 && pub_r000190_14 <= 100);
    __CPROVER_assume(pub_r000190_15 >= -100 && pub_r000190_15 <= 100);
    __CPROVER_assume(pub_r000190_16 >= -100 && pub_r000190_16 <= 100);
    __CPROVER_assume(pub_r000190_17 >= -100 && pub_r000190_17 <= 100);
    __CPROVER_assume(pub_r000190_18 >= -100 && pub_r000190_18 <= 100);
    __CPROVER_assume(pub_r000190_19 >= -100 && pub_r000190_19 <= 100);
    __CPROVER_assume(sec_r000190_0 >= 0 && sec_r000190_0 <= 255);
    __CPROVER_assume(sec_r000190_1 >= 0 && sec_r000190_1 <= 255);
    __CPROVER_assume(sec_r000190_2 >= 0 && sec_r000190_2 <= 255);
    __CPROVER_assume(sec_r000190_3 >= 0 && sec_r000190_3 <= 255);
    __CPROVER_assume(sec_r000190_4 >= 0 && sec_r000190_4 <= 255);
    __CPROVER_assume(sec_r000190_5 >= 0 && sec_r000190_5 <= 255);
    __CPROVER_assume(sec_r000190_6 >= 0 && sec_r000190_6 <= 255);
    __CPROVER_assume(sec_r000190_7 >= 0 && sec_r000190_7 <= 255);
    __CPROVER_assume(sec_r000190_8 >= 0 && sec_r000190_8 <= 255);
    __CPROVER_assume(sec_r000190_9 >= 0 && sec_r000190_9 <= 255);
    __CPROVER_assume(sec_r000190_10 >= 0 && sec_r000190_10 <= 255);
    __CPROVER_assume(sec_r000190_11 >= 0 && sec_r000190_11 <= 255);
    __CPROVER_assume(sec_r000190_12 >= 0 && sec_r000190_12 <= 255);
    __CPROVER_assume(sec_r000190_13 >= 0 && sec_r000190_13 <= 255);
    __CPROVER_assume(sec_r000190_14 >= 0 && sec_r000190_14 <= 255);
    __CPROVER_assume(sec_r000190_15 >= 0 && sec_r000190_15 <= 255);
    __CPROVER_assume(sec_r000190_16 >= 0 && sec_r000190_16 <= 255);
    __CPROVER_assume(sec_r000190_17 >= 0 && sec_r000190_17 <= 255);
    __CPROVER_assume(sec_r000190_18 >= 0 && sec_r000190_18 <= 255);
    __CPROVER_assume(sec_r000190_19 >= 0 && sec_r000190_19 <= 255);
    __CPROVER_assume(sec_r000190_20 >= 0 && sec_r000190_20 <= 255);
    __CPROVER_assume(sec_r000190_21 >= 0 && sec_r000190_21 <= 255);
    __CPROVER_assume(sec_r000190_22 >= 0 && sec_r000190_22 <= 255);

    struct SensorNode_R000190_9013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000190_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000190_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000190_0 + 7) & 15;
    struct StreamBuffer_R000190_9013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000190_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000190_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000190_0 + 9) & 15;

    union TelemetryField_R000190_9013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 38) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 53) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r000190_6 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_8 > 35) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((stage_v_8 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_9 > 42) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_8 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r000190_4 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_11 > 49) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r000190_20 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_12 > 29) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_11 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_13 > 25) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_9 ^ 0x2A) + pub_r000190_4) & 127;
    if (stage_v_14 > 50) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_8 ^ 0x2A) + pub_r000190_4) & 127;
    if (stage_v_15 > 30) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_12 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_16 > 27) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r000190_17 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_17 > 30) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_17 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_18 > 33) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r000190_3 ^ 0x2A) + pub_r000190_8) & 127;
    if (stage_v_19 > 20) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_8 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_20 > 43) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_10 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_21 > 48) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r000190_4 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_22 > 45) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_19 ^ 0x2A) + pub_r000190_5) & 127;
    if (stage_v_23 > 50) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r000190_15 ^ 0x2A) + pub_r000190_8) & 127;
    if (stage_v_24 > 33) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_17 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_25 > 47) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_18 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_26 > 50) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r000190_15 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_27 > 31) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_19 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_28 > 46) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_19 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_29 > 30) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_16 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_30 > 29) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r000190_4 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_31 > 20) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_21 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_32 > 41) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r000190_2 ^ 0x2A) + pub_r000190_13) & 127;
    if (stage_v_33 > 45) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_10 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_34 > 42) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_34 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_35 > 34) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_13 ^ 0x2A) + pub_r000190_13) & 127;
    if (stage_v_36 > 23) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_27 ^ 0x2A) + pub_r000190_8) & 127;
    if (stage_v_37 > 21) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r000190_20 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_38 > 20) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_34 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_39 > 45) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r000190_10 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_40 > 22) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_11 ^ 0x2A) + pub_r000190_2) & 127;
    if (stage_v_41 > 47) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_26 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_42 > 20) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r000190_11 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_43 > 33) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_22 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_44 > 46) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r000190_12 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_45 > 48) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r000190_8 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_46 > 20) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_36 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_47 > 30) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_19 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_48 > 35) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000190_10 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_49 > 26) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r000190_21 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_50 > 21) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r000190_16 ^ 0x2A) + pub_r000190_4) & 127;
    if (stage_v_51 > 31) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_8 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_52 > 25) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r000190_19 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_53 > 39) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000190_18 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_54 > 27) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_23 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_55 > 48) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r000190_21 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_56 > 37) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r000190_5 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_57 > 31) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_26 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_58 > 21) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_22 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_59 > 31) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_20 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_60 > 33) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r000190_17 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_61 > 36) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_36 ^ 0x2A) + pub_r000190_13) & 127;
    if (stage_v_62 > 45) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_12 ^ 0x2A) + pub_r000190_19) & 127;
    if (stage_v_63 > 32) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_61 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_64 > 38) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r000190_9 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_65 > 49) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_21 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_66 > 23) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_61 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_67 > 38) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_20 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_68 > 33) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r000190_22 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_69 > 22) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_15 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_70 > 48) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r000190_11 ^ 0x2A) + pub_r000190_5) & 127;
    if (stage_v_71 > 26) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000190_17 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_72 > 49) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_24 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_73 > 26) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_40 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_74 > 24) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_9 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_75 > 43) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r000190_3 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_76 > 28) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_37 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_77 > 24) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_24 ^ 0x2A) + pub_r000190_5) & 127;
    if (stage_v_78 > 46) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_44 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_79 > 38) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r000190_15 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_80 > 24) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_55 ^ 0x2A) + pub_r000190_13) & 127;
    if (stage_v_81 > 45) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_40 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_82 > 32) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r000190_9 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_83 > 48) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_50 ^ 0x2A) + pub_r000190_2) & 127;
    if (stage_v_84 > 42) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_31 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_85 > 22) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_67 ^ 0x2A) + pub_r000190_5) & 127;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_51 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_87 > 39) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_20 ^ 0x2A) + pub_r000190_7) & 127;
    if (stage_v_88 > 44) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_44 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_89 > 21) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_43 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_90 > 36) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r000190_15 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_91 > 45) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_13 ^ 0x2A) + pub_r000190_8) & 127;
    if (stage_v_92 > 45) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000190_19 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_93 > 32) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_41 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_94 > 36) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_23 ^ 0x2A) + pub_r000190_13) & 127;
    if (stage_v_95 > 28) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_37 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_96 > 43) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_20 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_97 > 47) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_21 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_98 > 33) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_88 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_99 > 30) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_99 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_100 > 29) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r000190_19 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_101 > 34) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r000190_7 ^ 0x2A) + pub_r000190_7) & 127;
    if (stage_v_102 > 42) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000190_13 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_103 > 43) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_38 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_104 > 25) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_98 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_105 > 48) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_42 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_106 > 32) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_32 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_107 > 30) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_84 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_108 > 50) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_36 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_109 > 47) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_29 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_110 > 40) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_48 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_111 > 35) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_88 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_112 > 21) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_84 ^ 0x2A) + pub_r000190_5) & 127;
    if (stage_v_113 > 32) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_98 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_114 > 26) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_79 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_115 > 33) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_16 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_116 > 20) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_9 ^ 0x2A) + pub_r000190_4) & 127;
    if (stage_v_117 > 37) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_8 ^ 0x2A) + pub_r000190_4) & 127;
    if (stage_v_118 > 49) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r000190_6 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_119 > 38) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_19 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_120 > 42) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r000190_8 ^ 0x2A) + pub_r000190_8) & 127;
    if (stage_v_121 > 50) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_86 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_122 > 48) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r000190_18 ^ 0x2A) + pub_r000190_2) & 127;
    if (stage_v_123 > 30) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_103 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_124 > 47) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_56 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_125 > 25) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000190_13 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_126 > 34) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_21 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_127 > 38) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_30 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_128 > 24) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_128 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_129 > 45) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_79 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_130 > 32) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_124 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_131 > 45) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_70 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_132 > 37) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_80 ^ 0x2A) + pub_r000190_17) & 127;
    if (stage_v_133 > 44) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_13 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_134 > 34) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_76 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_135 > 46) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r000190_12 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_136 > 40) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r000190_20 ^ 0x2A) + pub_r000190_2) & 127;
    if (stage_v_137 > 46) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_37 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_138 > 28) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r000190_17 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_139 > 27) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_128 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_140 > 47) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_99 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_141 > 36) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r000190_16 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_142 > 35) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_61 ^ 0x2A) + pub_r000190_8) & 127;
    if (stage_v_143 > 35) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r000190_8 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_144 > 26) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_81 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_145 > 34) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r000190_7 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_146 > 46) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_129 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_147 > 32) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r000190_12 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_148 > 33) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000190_15 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_149 > 46) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_139 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_150 > 30) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000190_15 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_151 > 46) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_141 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_152 > 46) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_8 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_153 > 48) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000190_17 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_154 > 20) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_89 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_155 > 29) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_53 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_156 > 20) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_100 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_157 > 24) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r000190_15 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_158 > 27) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_55 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_159 > 33) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_142 ^ 0x2A) + pub_r000190_19) & 127;
    if (stage_v_160 > 36) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r000190_4 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_161 > 33) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_40 ^ 0x2A) + pub_r000190_2) & 127;
    if (stage_v_162 > 33) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_129 ^ 0x2A) + pub_r000190_5) & 127;
    if (stage_v_163 > 24) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_56 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_164 > 44) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_66 ^ 0x2A) + pub_r000190_19) & 127;
    if (stage_v_165 > 37) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_79 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_166 > 45) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_132 ^ 0x2A) + pub_r000190_12) & 127;
    if (stage_v_167 > 37) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_143 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_168 > 37) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_58 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_169 > 29) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_33 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_170 > 40) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_23 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_171 > 32) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000190_4 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_172 > 30) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_36 ^ 0x2A) + pub_r000190_2) & 127;
    if (stage_v_173 > 43) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_86 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_174 > 29) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_154 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_175 > 26) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_96 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_176 > 30) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000190_17 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_177 > 50) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_104 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_178 > 22) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_59 ^ 0x2A) + pub_r000190_19) & 127;
    if (stage_v_179 > 34) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_111 ^ 0x2A) + pub_r000190_11) & 127;
    if (stage_v_180 > 46) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_139 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_181 > 50) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000190_14 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_182 > 50) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r000190_1 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_183 > 22) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_97 ^ 0x2A) + pub_r000190_18) & 127;
    if (stage_v_184 > 23) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r000190_12 ^ 0x2A) + pub_r000190_13) & 127;
    if (stage_v_185 > 29) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_90 ^ 0x2A) + pub_r000190_16) & 127;
    if (stage_v_186 > 44) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_161 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_187 > 32) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_76 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_188 > 31) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r000190_3 ^ 0x2A) + pub_r000190_13) & 127;
    if (stage_v_189 > 24) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r000190_12 ^ 0x2A) + pub_r000190_10) & 127;
    if (stage_v_190 > 20) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_112 ^ 0x2A) + pub_r000190_1) & 127;
    if (stage_v_191 > 23) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_137 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_192 > 23) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000190_22 ^ 0x2A) + pub_r000190_15) & 127;
    if (stage_v_193 > 20) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_151 ^ 0x2A) + pub_r000190_6) & 127;
    if (stage_v_194 > 32) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_63 ^ 0x2A) + pub_r000190_9) & 127;
    if (stage_v_195 > 40) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_194 ^ 0x2A) + pub_r000190_2) & 127;
    if (stage_v_196 > 29) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_174 ^ 0x2A) + pub_r000190_0) & 127;
    if (stage_v_197 > 24) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_130 ^ 0x2A) + pub_r000190_4) & 127;
    if (stage_v_198 > 32) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_98 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_199 > 26) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r000190_17 ^ 0x2A) + pub_r000190_14) & 127;
    if (stage_v_200 > 25) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_110 ^ 0x2A) + pub_r000190_5) & 127;
    if (stage_v_201 > 42) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_96 ^ 0x2A) + pub_r000190_3) & 127;
    if (stage_v_202 > 38) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
