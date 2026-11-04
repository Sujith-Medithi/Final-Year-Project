/*
 * Benchmark Program: R000427
 * Family: bitwise_flow
 * Generator Seed: 442713
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000427_2713_0 {
    short stop_bits;
    unsigned char port;
    int id;
    int buffer[3];
};

struct StreamBuffer_R000427_2713_1 {
    int state;
    int checksum;
    unsigned char watermark;
    int buffer[3];
};

union TelemetryField_R000427_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000427_2713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int stride_52 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_52 > 24) {
        acc = (acc + stride_52 * 2 + 5) & 127;
        aux ^= (stride_52 & 15);
    } else {
        acc = (acc - stride_52 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_82 = local_arr[aux % 3];
    acc = (acc + parity_82 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int metric_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_60) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_51 = local_arr[aux % 3];
    acc = (acc + vector_51 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int sample_50 = local_arr[aux % 3];
    acc = (acc + sample_50 * 2) & 127;
    int delta_38 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_38 > 16) {
        acc = (acc + delta_38 * 2 + 5) & 127;
        aux ^= (delta_38 & 15);
    } else {
        acc = (acc - delta_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_3(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_65 = (aux + st.buffer[1]) & 3;
    switch (delta_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_95 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_95 > 38) {
        acc = (acc + delta_95 * 2 + 5) & 127;
        aux ^= (delta_95 & 15);
    } else {
        acc = (acc - delta_95 + 11) & 127;
        aux += 3;
    }
    int scale_35 = 0;
    for (int k = 0; k < 3; k++) {
        scale_35 = (scale_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_35) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int index_reg_61 = local_arr[aux % 3];
    acc = (acc + index_reg_61 * 2) & 127;
    int tally_97 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_97 > 15) {
        acc = (acc + tally_97 * 2 + 5) & 127;
        aux ^= (tally_97 & 15);
    } else {
        acc = (acc - tally_97 + 11) & 127;
        aux += 3;
    }
    int bound_84 = 0;
    for (int k = 0; k < 2; k++) {
        bound_84 = (bound_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_84) & 127;
    }
    int mask_90 = (aux + st.buffer[1]) & 3;
    switch (mask_90) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_5(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int coefficient_16 = (aux + st.buffer[1]) & 3;
    switch (coefficient_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_86 = local_arr[aux % 3];
    acc = (acc + index_reg_86 * 2) & 127;
    int cursor_34 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_34 = (cursor_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_34) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_6(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_30 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_30 > 19) {
        acc = (acc + index_reg_30 * 2 + 5) & 127;
        aux ^= (index_reg_30 & 15);
    } else {
        acc = (acc - index_reg_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int accumulator_70 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_70 > 19) {
        acc = (acc + accumulator_70 * 2 + 5) & 127;
        aux ^= (accumulator_70 & 15);
    } else {
        acc = (acc - accumulator_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_31 = local_arr[aux % 3];
    acc = (acc + stride_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int window_95 = (st.buffer[0] * 3 + aux) & 63;
    if (window_95 > 19) {
        acc = (acc + window_95 * 2 + 5) & 127;
        aux ^= (window_95 & 15);
    } else {
        acc = (acc - window_95 + 11) & 127;
        aux += 3;
    }
    int residue_79 = (aux + st.buffer[1]) & 3;
    switch (residue_79) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_9(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int phase_63 = 0;
    for (int k = 0; k < 2; k++) {
        phase_63 = (phase_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_63) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_22 = local_arr[aux % 3];
    acc = (acc + vector_22 * 2) & 127;
    int weight_45 = (aux + st.buffer[1]) & 3;
    switch (weight_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_14 = (aux + st.buffer[1]) & 3;
    switch (vector_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_85 = 0;
    for (int k = 0; k < 2; k++) {
        offset_85 = (offset_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_85) & 127;
    }
    int window_60 = (st.buffer[0] * 3 + aux) & 63;
    if (window_60 > 26) {
        acc = (acc + window_60 * 2 + 5) & 127;
        aux ^= (window_60 & 15);
    } else {
        acc = (acc - window_60 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_12 = local_arr[aux % 3];
    acc = (acc + sample_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_44 = (aux + st.buffer[1]) & 3;
    switch (sample_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_95 = local_arr[aux % 3];
    acc = (acc + tally_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_12(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int pivot_83 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_83 = (pivot_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_83) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000427_2713_13(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int offset_20 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_20 > 30) {
        acc = (acc + offset_20 * 2 + 5) & 127;
        aux ^= (offset_20 & 15);
    } else {
        acc = (acc - offset_20 + 11) & 127;
        aux += 3;
    }
    int damping_49 = 0;
    for (int k = 0; k < 3; k++) {
        damping_49 = (damping_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_49) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000427_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int cursor_63 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_63 > 28) {
        acc = (acc + cursor_63 * 2 + 5) & 127;
        aux ^= (cursor_63 & 15);
    } else {
        acc = (acc - cursor_63 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_37 = local_arr[aux % 3];
    acc = (acc + quotient_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_66 = local_arr[aux % 3];
    acc = (acc + weight_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000427_2713_16(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_54 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_54 = (quantum_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_54) & 127;
    }
    int tracker_27 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_27 > 19) {
        acc = (acc + tracker_27 * 2 + 5) & 127;
        aux ^= (tracker_27 & 15);
    } else {
        acc = (acc - tracker_27 + 11) & 127;
        aux += 3;
    }
    int weight_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_74) & 63;
    acc ^= aux;
    int quotient_28 = (aux + st.buffer[1]) & 3;
    switch (quotient_28) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000427_2713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000427_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int pivot_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_41) & 63;
    acc ^= aux;
    int factor_70 = 0;
    for (int k = 0; k < 3; k++) {
        factor_70 = (factor_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_70) & 127;
    }
    int margin_94 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_94 > 43) {
        acc = (acc + margin_94 * 2 + 5) & 127;
        aux ^= (margin_94 & 15);
    } else {
        acc = (acc - margin_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_52 = local_arr[aux % 3];
    acc = (acc + factor_52 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000427_0;
    int sec_r000427_1;
    int sec_r000427_2;
    int sec_r000427_3;
    int sec_r000427_4;
    int sec_r000427_5;
    int sec_r000427_6;
    int sec_r000427_7;
    int sec_r000427_8;
    int sec_r000427_9;
    int sec_r000427_10;
    int sec_r000427_11;
    int sec_r000427_12;
    int sec_r000427_13;
    int sec_r000427_14;
    int sec_r000427_15;
    int sec_r000427_16;
    int pub_r000427_0;
    int pub_r000427_1;
    int pub_r000427_2;
    int pub_r000427_3;
    int pub_r000427_4;
    int pub_r000427_5;
    int pub_r000427_6;
    int pub_r000427_7;
    int pub_r000427_8;
    int pub_r000427_9;
    int pub_r000427_10;
    int pub_r000427_11;
    int pub_r000427_12;
    int pub_r000427_13;
    int pub_r000427_14;
    int pub_r000427_15;
    int pub_r000427_16;
    int pub_r000427_17;
    int pub_r000427_18;
    int pub_r000427_19;
    int pub_r000427_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000427_0 >= -100 && pub_r000427_0 <= 100);
    __CPROVER_assume(pub_r000427_1 >= -100 && pub_r000427_1 <= 100);
    __CPROVER_assume(pub_r000427_2 >= -100 && pub_r000427_2 <= 100);
    __CPROVER_assume(pub_r000427_3 >= -100 && pub_r000427_3 <= 100);
    __CPROVER_assume(pub_r000427_4 >= -100 && pub_r000427_4 <= 100);
    __CPROVER_assume(pub_r000427_5 >= -100 && pub_r000427_5 <= 100);
    __CPROVER_assume(pub_r000427_6 >= -100 && pub_r000427_6 <= 100);
    __CPROVER_assume(pub_r000427_7 >= -100 && pub_r000427_7 <= 100);
    __CPROVER_assume(pub_r000427_8 >= -100 && pub_r000427_8 <= 100);
    __CPROVER_assume(pub_r000427_9 >= -100 && pub_r000427_9 <= 100);
    __CPROVER_assume(pub_r000427_10 >= -100 && pub_r000427_10 <= 100);
    __CPROVER_assume(pub_r000427_11 >= -100 && pub_r000427_11 <= 100);
    __CPROVER_assume(pub_r000427_12 >= -100 && pub_r000427_12 <= 100);
    __CPROVER_assume(pub_r000427_13 >= -100 && pub_r000427_13 <= 100);
    __CPROVER_assume(pub_r000427_14 >= -100 && pub_r000427_14 <= 100);
    __CPROVER_assume(pub_r000427_15 >= -100 && pub_r000427_15 <= 100);
    __CPROVER_assume(pub_r000427_16 >= -100 && pub_r000427_16 <= 100);
    __CPROVER_assume(pub_r000427_17 >= -100 && pub_r000427_17 <= 100);
    __CPROVER_assume(pub_r000427_18 >= -100 && pub_r000427_18 <= 100);
    __CPROVER_assume(pub_r000427_19 >= -100 && pub_r000427_19 <= 100);
    __CPROVER_assume(pub_r000427_20 >= -100 && pub_r000427_20 <= 100);
    __CPROVER_assume(sec_r000427_0 >= 0 && sec_r000427_0 <= 255);
    __CPROVER_assume(sec_r000427_1 >= 0 && sec_r000427_1 <= 255);
    __CPROVER_assume(sec_r000427_2 >= 0 && sec_r000427_2 <= 255);
    __CPROVER_assume(sec_r000427_3 >= 0 && sec_r000427_3 <= 255);
    __CPROVER_assume(sec_r000427_4 >= 0 && sec_r000427_4 <= 255);
    __CPROVER_assume(sec_r000427_5 >= 0 && sec_r000427_5 <= 255);
    __CPROVER_assume(sec_r000427_6 >= 0 && sec_r000427_6 <= 255);
    __CPROVER_assume(sec_r000427_7 >= 0 && sec_r000427_7 <= 255);
    __CPROVER_assume(sec_r000427_8 >= 0 && sec_r000427_8 <= 255);
    __CPROVER_assume(sec_r000427_9 >= 0 && sec_r000427_9 <= 255);
    __CPROVER_assume(sec_r000427_10 >= 0 && sec_r000427_10 <= 255);
    __CPROVER_assume(sec_r000427_11 >= 0 && sec_r000427_11 <= 255);
    __CPROVER_assume(sec_r000427_12 >= 0 && sec_r000427_12 <= 255);
    __CPROVER_assume(sec_r000427_13 >= 0 && sec_r000427_13 <= 255);
    __CPROVER_assume(sec_r000427_14 >= 0 && sec_r000427_14 <= 255);
    __CPROVER_assume(sec_r000427_15 >= 0 && sec_r000427_15 <= 255);
    __CPROVER_assume(sec_r000427_16 >= 0 && sec_r000427_16 <= 255);

    struct DeviceConfig_R000427_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000427_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000427_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000427_0 + 7) & 15;
    struct StreamBuffer_R000427_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000427_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000427_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000427_0 + 9) & 15;

    union TelemetryField_R000427_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 29) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 44) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 40) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 55) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 15) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 30) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 17) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 32) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 27) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 42) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 40) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 55) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_0.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 27) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 42) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 22) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 37) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 32) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 47) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 38) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 53) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 25) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 40) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 21) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 36) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] ^ 81) & 3;
    switch (stage_v_78) {
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

    /* Execution Pipeline Stage 79 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 36) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 51) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 82) & 15;
    int stage_v_81 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= stage_v_81;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 36) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 51) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[0] ^ 89) & 3;
    switch (stage_v_86) {
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

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[0] ^ 97) & 3;
    switch (stage_v_94) {
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

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 18) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 33) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = table[2];
    table[2] = (table[3] + 197) & 63;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_1.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 30) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 45) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = table[2];
    table[2] = (table[3] + 205) & 63;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_0.buffer[1] * 2 + 325) & 63;
    if (stage_v_106 > 17) {
        out_sink = (out_sink + stage_v_106 - 5) & 255;
        if (stage_v_106 > 32) {
            chk_sum ^= (stage_v_106 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_106 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_1.buffer[0] ^ 114) & 3;
    switch (stage_v_111) {
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

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 114) & 15;
    int stage_v_113 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= stage_v_113;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (out_sink > 100) ? (chk_sum & 31) : (123 & 31);
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= (stage_v_118 << 1) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = table[0];
    table[0] = (table[1] + 241) & 63;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3];
    table[3] = (table[0] + 255) & 63;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_0.buffer[2] * 2 + 391) & 63;
    if (stage_v_128 > 40) {
        out_sink = (out_sink + stage_v_128 - 5) & 255;
        if (stage_v_128 > 55) {
            chk_sum ^= (stage_v_128 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_128 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_0.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 33) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 48) {
            chk_sum ^= (stage_v_130 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_130 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 131 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_0.buffer[0] ^ 137) & 3;
    switch (stage_v_134) {
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

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_135 = (stage_v_135 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 138) & 15;
    int stage_v_137 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= stage_v_137;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (out_sink > 100) ? (chk_sum & 31) : (145 & 31);
    out_sink = (out_sink + stage_v_140) & 255;
    chk_sum ^= (stage_v_140 << 1) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1];
    table[1] = (table[2] + 283) & 63;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = table[2];
    table[2] = (table[3] + 285) & 63;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_1.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_149 = (stage_v_149 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_1.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
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

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_0.buffer[1] * 2 + 469) & 63;
    if (stage_v_154 > 30) {
        out_sink = (out_sink + stage_v_154 - 5) & 255;
        if (stage_v_154 > 45) {
            chk_sum ^= (stage_v_154 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_154 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_1.buffer[2] * 2 + 472) & 63;
    if (stage_v_155 > 26) {
        out_sink = (out_sink + stage_v_155 - 5) & 255;
        if (stage_v_155 > 41) {
            chk_sum ^= (stage_v_155 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_155 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_0.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_1.buffer[0] * 2 + 484) & 63;
    if (stage_v_159 > 39) {
        out_sink = (out_sink + stage_v_159 - 5) & 255;
        if (stage_v_159 > 54) {
            chk_sum ^= (stage_v_159 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_159 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (out_sink > 100) ? (chk_sum & 31) : (168 & 31);
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= (stage_v_163 << 1) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_164 = (stage_v_164 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_165 = (stage_v_165 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (out_sink > 100) ? (chk_sum & 31) : (171 & 31);
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= (stage_v_166 << 1) & 127;

    /* Execution Pipeline Stage 167 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_168 = (stage_v_168 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_170 = (stage_v_170 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_170) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = table[0];
    table[0] = (table[1] + 345) & 63;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Security Information Flow: Family = bitwise_flow */
    int b_w0 = (sec_r000427_6 ^ 0x5A) & 63;
    int b_w1 = ((b_w0 << 2) ^ (sec_r000427_14 >> 2)) & 63;
    int b_w2 = ((b_w1 << 1) | (sec_r000427_6 >> 1)) & 63;
    int b_w3 = ((b_w2 << 2) ^ (sec_r000427_14 >> 2)) & 63;
    int b_w4 = ((b_w3 << 1) ^ (sec_r000427_6 >> 1)) & 63;
    out_sink += b_w4 & 63;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
