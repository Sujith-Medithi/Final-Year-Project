/*
 * Benchmark Program: R001996
 * Security Family: implicit_flow
 * Generator Seed: 699613
 * High Inputs: 16 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001996_9613_0 {
    short timeout;
    int parity;
    int id;
    unsigned char baud_rate;
    int stop_bits;
    int port;
    int buffer[3];
};

struct MatrixBlock_R001996_9613_1 {
    int stride;
    int scale;
    unsigned char dim;
    int density;
    unsigned char determinant;
    int buffer[3];
};

struct StreamBuffer_R001996_9613_2 {
    short tail;
    unsigned char capacity;
    int watermark;
    int head;
    unsigned char state;
    int buffer[3];
};

union RegisterBank_R001996_9613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001996_9613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int segment_92 = 0;
    for (int k = 0; k < 2; k++) {
        segment_92 = (segment_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_92) & 127;
    }
    int parity_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001996_9613_1(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int bound_27 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_27 > 35) {
        acc = (acc + bound_27 * 2 + 5) & 127;
        aux ^= (bound_27 & 15);
    } else {
        acc = (acc - bound_27 + 11) & 127;
        aux += 3;
    }
    int sample_15 = 0;
    for (int k = 0; k < 2; k++) {
        sample_15 = (sample_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_15) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001996_9613_2(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tally_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_92) & 63;
    acc ^= aux;
    int scale_28 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_28 > 21) {
        acc = (acc + scale_28 * 2 + 5) & 127;
        aux ^= (scale_28 & 15);
    } else {
        acc = (acc - scale_28 + 11) & 127;
        aux += 3;
    }
    int segment_10 = 0;
    for (int k = 0; k < 2; k++) {
        segment_10 = (segment_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_10) & 127;
    }
    int cursor_25 = (aux + st.buffer[1]) & 3;
    switch (cursor_25) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_90 = 0;
    for (int k = 0; k < 3; k++) {
        bound_90 = (bound_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_90) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_70 = local_arr[aux % 3];
    acc = (acc + cursor_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001996_9613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int checksum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_42) & 63;
    acc ^= aux;
    int sample_48 = 0;
    for (int k = 0; k < 2; k++) {
        sample_48 = (sample_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_48) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_96 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_96 > 26) {
        acc = (acc + pivot_96 * 2 + 5) & 127;
        aux ^= (pivot_96 & 15);
    } else {
        acc = (acc - pivot_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_5(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int coefficient_23 = local_arr[aux % 3];
    acc = (acc + coefficient_23 * 2) & 127;
    int vector_22 = 0;
    for (int k = 0; k < 3; k++) {
        vector_22 = (vector_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int factor_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_87) & 63;
    acc ^= aux;
    int weight_35 = 0;
    for (int k = 0; k < 3; k++) {
        weight_35 = (weight_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_35) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001996_9613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int bound_49 = 0;
    for (int k = 0; k < 2; k++) {
        bound_49 = (bound_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_49) & 127;
    }
    int margin_31 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_31 > 39) {
        acc = (acc + margin_31 * 2 + 5) & 127;
        aux ^= (margin_31 & 15);
    } else {
        acc = (acc - margin_31 + 11) & 127;
        aux += 3;
    }
    int mask_95 = (aux + st.buffer[1]) & 3;
    switch (mask_95) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int window_80 = (aux + st.buffer[1]) & 3;
    switch (window_80) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_36 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_36 > 42) {
        acc = (acc + segment_36 * 2 + 5) & 127;
        aux ^= (segment_36 & 15);
    } else {
        acc = (acc - segment_36 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_46 = local_arr[aux % 3];
    acc = (acc + checksum_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001996_9613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int anchor_72 = local_arr[aux % 3];
    acc = (acc + anchor_72 * 2) & 127;
    int weight_96 = 0;
    for (int k = 0; k < 2; k++) {
        weight_96 = (weight_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_96) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_19 = (aux + st.buffer[1]) & 3;
    switch (vector_19) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int damping_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_91) & 63;
    acc ^= aux;
    int checksum_57 = (aux + st.buffer[1]) & 3;
    switch (checksum_57) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int mask_54 = local_arr[aux % 3];
    acc = (acc + mask_54 * 2) & 127;
    int threshold_63 = (aux + st.buffer[1]) & 3;
    switch (threshold_63) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001996_9613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int window_37 = local_arr[aux % 3];
    acc = (acc + window_37 * 2) & 127;
    int damping_39 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_39 > 22) {
        acc = (acc + damping_39 * 2 + 5) & 127;
        aux ^= (damping_39 & 15);
    } else {
        acc = (acc - damping_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_13(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_12 = (aux + st.buffer[1]) & 3;
    switch (mask_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_42 = local_arr[aux % 3];
    acc = (acc + quotient_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001996_9613_14(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001996_9613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int factor_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_60) & 63;
    acc ^= aux;
    int stride_16 = 0;
    for (int k = 0; k < 2; k++) {
        stride_16 = (stride_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quotient_78 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_78 > 29) {
        acc = (acc + quotient_78 * 2 + 5) & 127;
        aux ^= (quotient_78 & 15);
    } else {
        acc = (acc - quotient_78 + 11) & 127;
        aux += 3;
    }
    int pivot_32 = (aux + st.buffer[1]) & 3;
    switch (pivot_32) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_10 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_10 > 37) {
        acc = (acc + cursor_10 * 2 + 5) & 127;
        aux ^= (cursor_10 & 15);
    } else {
        acc = (acc - cursor_10 + 11) & 127;
        aux += 3;
    }
    int offset_45 = (aux + st.buffer[1]) & 3;
    switch (offset_45) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_18 = 0;
    for (int k = 0; k < 2; k++) {
        damping_18 = (damping_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_18) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_17(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001996_9613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int checksum_55 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_55 = (checksum_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_55) & 127;
    }
    int bound_69 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_69 > 44) {
        acc = (acc + bound_69 * 2 + 5) & 127;
        aux ^= (bound_69 & 15);
    } else {
        acc = (acc - bound_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001996_9613_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001996_9613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int accumulator_90 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_90 = (accumulator_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_90) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_98 = local_arr[aux % 3];
    acc = (acc + checksum_98 * 2) & 127;
    int metric_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_66) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001996_0;
    int sec_r001996_1;
    int sec_r001996_2;
    int sec_r001996_3;
    int sec_r001996_4;
    int sec_r001996_5;
    int sec_r001996_6;
    int sec_r001996_7;
    int sec_r001996_8;
    int sec_r001996_9;
    int sec_r001996_10;
    int sec_r001996_11;
    int sec_r001996_12;
    int sec_r001996_13;
    int sec_r001996_14;
    int sec_r001996_15;
    int pub_r001996_0;
    int pub_r001996_1;
    int pub_r001996_2;
    int pub_r001996_3;
    int pub_r001996_4;
    int pub_r001996_5;
    int pub_r001996_6;
    int pub_r001996_7;
    int pub_r001996_8;
    int pub_r001996_9;
    int pub_r001996_10;
    int pub_r001996_11;
    int pub_r001996_12;
    int pub_r001996_13;
    int pub_r001996_14;
    int pub_r001996_15;
    int pub_r001996_16;
    int pub_r001996_17;
    int pub_r001996_18;
    int pub_r001996_19;
    int pub_r001996_20;
    int pub_r001996_21;
    int pub_r001996_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001996_0 >= -100 && pub_r001996_0 <= 100);
    __CPROVER_assume(pub_r001996_1 >= -100 && pub_r001996_1 <= 100);
    __CPROVER_assume(pub_r001996_2 >= -100 && pub_r001996_2 <= 100);
    __CPROVER_assume(pub_r001996_3 >= -100 && pub_r001996_3 <= 100);
    __CPROVER_assume(pub_r001996_4 >= -100 && pub_r001996_4 <= 100);
    __CPROVER_assume(pub_r001996_5 >= -100 && pub_r001996_5 <= 100);
    __CPROVER_assume(pub_r001996_6 >= -100 && pub_r001996_6 <= 100);
    __CPROVER_assume(pub_r001996_7 >= -100 && pub_r001996_7 <= 100);
    __CPROVER_assume(pub_r001996_8 >= -100 && pub_r001996_8 <= 100);
    __CPROVER_assume(pub_r001996_9 >= -100 && pub_r001996_9 <= 100);
    __CPROVER_assume(pub_r001996_10 >= -100 && pub_r001996_10 <= 100);
    __CPROVER_assume(pub_r001996_11 >= -100 && pub_r001996_11 <= 100);
    __CPROVER_assume(pub_r001996_12 >= -100 && pub_r001996_12 <= 100);
    __CPROVER_assume(pub_r001996_13 >= -100 && pub_r001996_13 <= 100);
    __CPROVER_assume(pub_r001996_14 >= -100 && pub_r001996_14 <= 100);
    __CPROVER_assume(pub_r001996_15 >= -100 && pub_r001996_15 <= 100);
    __CPROVER_assume(pub_r001996_16 >= -100 && pub_r001996_16 <= 100);
    __CPROVER_assume(pub_r001996_17 >= -100 && pub_r001996_17 <= 100);
    __CPROVER_assume(pub_r001996_18 >= -100 && pub_r001996_18 <= 100);
    __CPROVER_assume(pub_r001996_19 >= -100 && pub_r001996_19 <= 100);
    __CPROVER_assume(pub_r001996_20 >= -100 && pub_r001996_20 <= 100);
    __CPROVER_assume(pub_r001996_21 >= -100 && pub_r001996_21 <= 100);
    __CPROVER_assume(pub_r001996_22 >= -100 && pub_r001996_22 <= 100);
    __CPROVER_assume(sec_r001996_0 >= 0 && sec_r001996_0 <= 255);
    __CPROVER_assume(sec_r001996_1 >= 0 && sec_r001996_1 <= 255);
    __CPROVER_assume(sec_r001996_2 >= 0 && sec_r001996_2 <= 255);
    __CPROVER_assume(sec_r001996_3 >= 0 && sec_r001996_3 <= 255);
    __CPROVER_assume(sec_r001996_4 >= 0 && sec_r001996_4 <= 255);
    __CPROVER_assume(sec_r001996_5 >= 0 && sec_r001996_5 <= 255);
    __CPROVER_assume(sec_r001996_6 >= 0 && sec_r001996_6 <= 255);
    __CPROVER_assume(sec_r001996_7 >= 0 && sec_r001996_7 <= 255);
    __CPROVER_assume(sec_r001996_8 >= 0 && sec_r001996_8 <= 255);
    __CPROVER_assume(sec_r001996_9 >= 0 && sec_r001996_9 <= 255);
    __CPROVER_assume(sec_r001996_10 >= 0 && sec_r001996_10 <= 255);
    __CPROVER_assume(sec_r001996_11 >= 0 && sec_r001996_11 <= 255);
    __CPROVER_assume(sec_r001996_12 >= 0 && sec_r001996_12 <= 255);
    __CPROVER_assume(sec_r001996_13 >= 0 && sec_r001996_13 <= 255);
    __CPROVER_assume(sec_r001996_14 >= 0 && sec_r001996_14 <= 255);
    __CPROVER_assume(sec_r001996_15 >= 0 && sec_r001996_15 <= 255);

    struct DeviceConfig_R001996_9613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001996_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001996_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001996_0 + 7) & 15;
    struct MatrixBlock_R001996_9613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001996_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001996_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001996_0 + 9) & 15;
    struct StreamBuffer_R001996_9613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001996_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001996_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001996_0 + 11) & 15;

    union RegisterBank_R001996_9613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001996_9613_0(sec_r001996_0, pub_r001996_1, pub_r001996_2, pub_r001996_3);
    int helper_flow_1 = fn_R001996_9613_1(sec_r001996_1, sec_r001996_2, pub_r001996_3);
    int helper_flow_2 = fn_R001996_9613_2(sec_r001996_2, pub_r001996_3);
    int helper_flow_3 = fn_R001996_9613_3(sec_r001996_3, sec_r001996_4, pub_r001996_5, pub_r001996_6, pub_r001996_7);
    int helper_flow_4 = fn_R001996_9613_4(sec_r001996_4, pub_r001996_5, pub_r001996_6, pub_r001996_7);
    int helper_flow_5 = fn_R001996_9613_5(sec_r001996_5, sec_r001996_6, pub_r001996_7);
    int helper_flow_6 = fn_R001996_9613_6(sec_r001996_6, sec_r001996_7, pub_r001996_8, pub_r001996_9, pub_r001996_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_3 + pub_r001996_13 * 2 + 5) & 127;
    if (stage_v_0 > 35) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001996_3 + pub_r001996_0 * 2 + 8) & 127;
    if (stage_v_1 > 56) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001996_2 + pub_r001996_6 * 2 + 11) & 127;
    if (stage_v_2 > 25) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001996_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_0 + pub_r001996_6 * 2 + 17) & 127;
    if (stage_v_4 > 22) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (stage_v_1 + pub_r001996_15 * 2 + 20) & 127;
    if (stage_v_5 > 38) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (helper_flow_5 + pub_r001996_21 * 2 + 23) & 127;
    if (stage_v_6 > 18) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001996_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_2 + pub_r001996_0 * 2 + 29) & 127;
    if (stage_v_8 > 43) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_6 + pub_r001996_17 * 2 + 32) & 127;
    if (stage_v_9 > 23) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_8 + pub_r001996_12 * 2 + 35) & 127;
    if (stage_v_10 > 60) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001996_1 + pub_r001996_10 * 2 + 38) & 127;
    if (stage_v_11 > 31) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001996_10 + pub_r001996_1 * 2 + 41) & 127;
    if (stage_v_12 > 38) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001996_5 + pub_r001996_13 * 2 + 44) & 127;
    if (stage_v_13 > 22) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_8 + pub_r001996_0 * 2 + 47) & 127;
    if (stage_v_14 > 60) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_14 + pub_r001996_16 * 2 + 50) & 127;
    if (stage_v_15 > 37) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_5 + pub_r001996_10 * 2 + 53) & 127;
    if (stage_v_16 > 40) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001996_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001996_8 + pub_r001996_2 * 2 + 59) & 127;
    if (stage_v_18 > 58) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_2 + pub_r001996_3 * 2 + 62) & 127;
    if (stage_v_19 > 22) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_4 + pub_r001996_4 * 2 + 65) & 127;
    if (stage_v_20 > 48) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001996_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001996_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001996_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001996_4 + pub_r001996_15 * 2 + 77) & 127;
    if (stage_v_24 > 35) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001996_7 + pub_r001996_7 * 2 + 80) & 127;
    if (stage_v_25 > 50) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_15 + pub_r001996_22 * 2 + 83) & 127;
    if (stage_v_26 > 45) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001996_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001996_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_11 + pub_r001996_6 * 2 + 92) & 127;
    if (stage_v_29 > 52) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001996_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001996_5 + pub_r001996_21 * 2 + 98) & 127;
    if (stage_v_31 > 49) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_26 + pub_r001996_18 * 2 + 101) & 127;
    if (stage_v_32 > 31) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001996_10 + pub_r001996_0 * 2 + 104) & 127;
    if (stage_v_33 > 29) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001996_10 + pub_r001996_10 * 2 + 107) & 127;
    if (stage_v_34 > 51) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001996_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_32 + pub_r001996_17 * 2 + 113) & 127;
    if (stage_v_36 > 30) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_10 + pub_r001996_18 * 2 + 116) & 127;
    if (stage_v_37 > 37) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001996_9 + pub_r001996_13 * 2 + 119) & 127;
    if (stage_v_38 > 57) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001996_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001996_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001996_9 + pub_r001996_6 * 2 + 128) & 127;
    if (stage_v_41 > 43) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001996_12 + pub_r001996_4 * 2 + 131) & 127;
    if (stage_v_42 > 19) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_13 + pub_r001996_6 * 2 + 134) & 127;
    if (stage_v_43 > 50) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001996_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_32 + pub_r001996_16 * 2 + 140) & 127;
    if (stage_v_45 > 25) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001996_21 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_14 + pub_r001996_9 * 2 + 146) & 127;
    if (stage_v_47 > 45) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001996_3 + pub_r001996_0 * 2 + 149) & 127;
    if (stage_v_48 > 47) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001996_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001996_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (helper_flow_0 + pub_r001996_13 * 2 + 158) & 127;
    if (stage_v_51 > 31) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_43 + pub_r001996_14 * 2 + 161) & 127;
    if (stage_v_52 > 45) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_5 + pub_r001996_2 * 2 + 164) & 127;
    if (stage_v_53 > 29) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_24 + pub_r001996_8 * 2 + 167) & 127;
    if (stage_v_54 > 21) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001996_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_11 + pub_r001996_7 * 2 + 173) & 127;
    if (stage_v_56 > 30) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_10 + pub_r001996_17 * 2 + 176) & 127;
    if (stage_v_57 > 21) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001996_6 + pub_r001996_18 * 2 + 179) & 127;
    if (stage_v_58 > 42) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001996_1 + pub_r001996_21 * 2 + 182) & 127;
    if (stage_v_59 > 37) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001996_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_57 + pub_r001996_20 * 2 + 188) & 127;
    if (stage_v_61 > 24) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_24 + pub_r001996_6 * 2 + 191) & 127;
    if (stage_v_62 > 17) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001996_12 + pub_r001996_7 * 2 + 194) & 127;
    if (stage_v_63 > 17) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_25 + pub_r001996_4 * 2 + 197) & 127;
    if (stage_v_64 > 35) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (helper_flow_5 + pub_r001996_10 * 2 + 200) & 127;
    if (stage_v_65 > 27) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_6 + pub_r001996_6 * 2 + 203) & 127;
    if (stage_v_66 > 42) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_20 + pub_r001996_17 * 2 + 206) & 127;
    if (stage_v_67 > 37) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_18 + pub_r001996_4 * 2 + 209) & 127;
    if (stage_v_68 > 15) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_0 + pub_r001996_19 * 2 + 212) & 127;
    if (stage_v_69 > 59) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_6 + pub_r001996_16 * 2 + 215) & 127;
    if (stage_v_70 > 49) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_20 + pub_r001996_8 * 2 + 218) & 127;
    if (stage_v_71 > 60) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_5 + pub_r001996_7 * 2 + 221) & 127;
    if (stage_v_72 > 17) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001996_3 + pub_r001996_8 * 2 + 224) & 127;
    if (stage_v_73 > 23) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001996_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_11 + pub_r001996_15 * 2 + 230) & 127;
    if (stage_v_75 > 57) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_13 + pub_r001996_3 * 2 + 233) & 127;
    if (stage_v_76 > 49) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_67 + pub_r001996_2 * 2 + 236) & 127;
    if (stage_v_77 > 19) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_2 + pub_r001996_11 * 2 + 239) & 127;
    if (stage_v_78 > 58) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001996_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_36 + pub_r001996_14 * 2 + 245) & 127;
    if (stage_v_80 > 55) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_69 + pub_r001996_17 * 2 + 248) & 127;
    if (stage_v_81 > 24) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_20 + pub_r001996_16 * 2 + 251) & 127;
    if (stage_v_82 > 54) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_47 + pub_r001996_8 * 2 + 254) & 127;
    if (stage_v_83 > 34) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_15 + pub_r001996_20 * 2 + 257) & 127;
    if (stage_v_84 > 51) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001996_8 + pub_r001996_13 * 2 + 260) & 127;
    if (stage_v_85 > 21) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_68 + pub_r001996_19 * 2 + 263) & 127;
    if (stage_v_86 > 40) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_14 + pub_r001996_0 * 2 + 266) & 127;
    if (stage_v_87 > 23) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_20 + pub_r001996_21 * 2 + 269) & 127;
    if (stage_v_88 > 43) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_73 + pub_r001996_15 * 2 + 272) & 127;
    if (stage_v_89 > 28) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_2 + pub_r001996_2 * 2 + 275) & 127;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_69 + pub_r001996_20 * 2 + 278) & 127;
    if (stage_v_91 > 21) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r001996_2 + pub_r001996_6 * 2 + 281) & 127;
    if (stage_v_92 > 21) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001996_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001996_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_4 + pub_r001996_20 * 2 + 290) & 127;
    if (stage_v_95 > 37) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_75 + pub_r001996_4 * 2 + 293) & 127;
    if (stage_v_96 > 59) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001996_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001996_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_85 + pub_r001996_1 * 2 + 302) & 127;
    if (stage_v_99 > 45) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001996_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001996_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_29 + pub_r001996_4 * 2 + 311) & 127;
    if (stage_v_102 > 27) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_96 + pub_r001996_6 * 2 + 314) & 127;
    if (stage_v_103 > 56) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_0 + pub_r001996_8 * 2 + 317) & 127;
    if (stage_v_104 > 25) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_62 + pub_r001996_13 * 2 + 320) & 127;
    if (stage_v_105 > 41) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001996_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001996_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_66 + pub_r001996_8 * 2 + 329) & 127;
    if (stage_v_108 > 21) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_81 + pub_r001996_0 * 2 + 332) & 127;
    if (stage_v_109 > 49) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001996_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001996_2 + pub_r001996_14 * 2 + 338) & 127;
    if (stage_v_111 > 15) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001996_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (helper_flow_3 + pub_r001996_22 * 2 + 344) & 127;
    if (stage_v_113 > 58) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001996_0 + pub_r001996_11 * 2 + 347) & 127;
    if (stage_v_114 > 31) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001996_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001996_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001996_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001996_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_5 + pub_r001996_11 * 2 + 362) & 127;
    if (stage_v_119 > 26) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001996_12 + pub_r001996_16 * 2 + 365) & 127;
    if (stage_v_120 > 28) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001996_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001996_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_92 + pub_r001996_20 * 2 + 374) & 127;
    if (stage_v_123 > 56) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001996_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001996_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001996_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_24 + pub_r001996_16 * 2 + 386) & 127;
    if (stage_v_127 > 41) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_2 + pub_r001996_17 * 2 + 389) & 127;
    if (stage_v_128 > 31) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001996_10 + pub_r001996_9 * 2 + 392) & 127;
    if (stage_v_129 > 42) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_29 + pub_r001996_12 * 2 + 395) & 127;
    if (stage_v_130 > 42) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_73 + pub_r001996_5 * 2 + 398) & 127;
    if (stage_v_131 > 49) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001996_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001996_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001996_21 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_88 + pub_r001996_0 * 2 + 410) & 127;
    if (stage_v_135 > 27) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (sec_r001996_11 + pub_r001996_8 * 2 + 413) & 127;
    if (stage_v_136 > 48) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (sec_r001996_12 + pub_r001996_19 * 2 + 416) & 127;
    if (stage_v_137 > 40) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_38 + pub_r001996_15 * 2 + 419) & 127;
    if (stage_v_138 > 22) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_78 + pub_r001996_11 * 2 + 422) & 127;
    if (stage_v_139 > 24) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_10 + pub_r001996_2 * 2 + 425) & 127;
    if (stage_v_140 > 36) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001996_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_137 + pub_r001996_19 * 2 + 431) & 127;
    if (stage_v_142 > 59) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_47 + pub_r001996_10 * 2 + 434) & 127;
    if (stage_v_143 > 60) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_119 + pub_r001996_9 * 2 + 437) & 127;
    if (stage_v_144 > 46) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_9 + pub_r001996_3 * 2 + 440) & 127;
    if (stage_v_145 > 45) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_87 + pub_r001996_20 * 2 + 443) & 127;
    if (stage_v_146 > 29) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_64 + pub_r001996_12 * 2 + 446) & 127;
    if (stage_v_147 > 49) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_146 + pub_r001996_17 * 2 + 449) & 127;
    if (stage_v_148 > 55) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_43 + pub_r001996_10 * 2 + 452) & 127;
    if (stage_v_149 > 53) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001996_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (sec_r001996_8 + pub_r001996_3 * 2 + 458) & 127;
    if (stage_v_151 > 32) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001996_21 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_48 + pub_r001996_1 * 2 + 464) & 127;
    if (stage_v_153 > 39) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001996_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_102 + pub_r001996_13 * 2 + 470) & 127;
    if (stage_v_155 > 29) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001996_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001996_20 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001996_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (sec_r001996_1 + pub_r001996_17 * 2 + 482) & 127;
    if (stage_v_159 > 27) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001996_21 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_71 + pub_r001996_11 * 2 + 488) & 127;
    if (stage_v_161 > 27) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_159 + pub_r001996_2 * 2 + 491) & 127;
    if (stage_v_162 > 26) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_102 + pub_r001996_15 * 2 + 494) & 127;
    if (stage_v_163 > 20) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_29 + pub_r001996_13 * 2 + 497) & 127;
    if (stage_v_164 > 15) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001996_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (helper_flow_3 + pub_r001996_10 * 2 + 503) & 127;
    if (stage_v_166 > 43) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001996_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001996_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_149 + pub_r001996_10 * 2 + 512) & 127;
    if (stage_v_169 > 26) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001996_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_58 + pub_r001996_12 * 2 + 518) & 127;
    if (stage_v_171 > 47) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_1 + pub_r001996_10 * 2 + 521) & 127;
    if (stage_v_172 > 41) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001996_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_147 + pub_r001996_11 * 2 + 527) & 127;
    if (stage_v_174 > 37) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001996_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_128 + pub_r001996_15 * 2 + 533) & 127;
    if (stage_v_176 > 55) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001996_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_147 + pub_r001996_22 * 2 + 539) & 127;
    if (stage_v_178 > 19) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_80 + pub_r001996_7 * 2 + 542) & 127;
    if (stage_v_179 > 31) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_176 + pub_r001996_16 * 2 + 545) & 127;
    if (stage_v_180 > 35) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001996_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (sec_r001996_4 + pub_r001996_3 * 2 + 551) & 127;
    if (stage_v_182 > 19) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001996_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001996_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_57 + pub_r001996_7 * 2 + 560) & 127;
    if (stage_v_185 > 42) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001996_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_4 + pub_r001996_15 * 2 + 566) & 127;
    if (stage_v_187 > 33) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_91 + pub_r001996_22 * 2 + 569) & 127;
    if (stage_v_188 > 25) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_164 + pub_r001996_10 * 2 + 572) & 127;
    if (stage_v_189 > 22) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_34 + pub_r001996_7 * 2 + 575) & 127;
    if (stage_v_190 > 25) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_24 + pub_r001996_18 * 2 + 578) & 127;
    if (stage_v_191 > 22) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (sec_r001996_4 + pub_r001996_20 * 2 + 581) & 127;
    if (stage_v_192 > 59) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_19 + pub_r001996_22 * 2 + 584) & 127;
    if (stage_v_193 > 34) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001996_22 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001996_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001996_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_26 + pub_r001996_20 * 2 + 596) & 127;
    if (stage_v_197 > 25) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_137 + pub_r001996_14 * 2 + 599) & 127;
    if (stage_v_198 > 17) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_82 + pub_r001996_2 * 2 + 602) & 127;
    if (stage_v_199 > 37) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_143 + pub_r001996_14 * 2 + 605) & 127;
    if (stage_v_200 > 47) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001996_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (helper_flow_0 + pub_r001996_12 * 2 + 611) & 127;
    if (stage_v_202 > 16) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_166 + pub_r001996_22 * 2 + 614) & 127;
    if (stage_v_203 > 58) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
