/*
 * Benchmark Program: R001927
 * Security Family: nested_implicit_flow
 * Generator Seed: 692713
 * High Inputs: 16 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001927_2713_0 {
    int density;
    short trace;
    short scale;
    int stride;
    int buffer[3];
};

struct SensorNode_R001927_2713_1 {
    int status;
    unsigned char gain;
    int threshold;
    int buffer[3];
};

struct StreamBuffer_R001927_2713_2 {
    int checksum;
    short head;
    unsigned char capacity;
    int state;
    int tail;
    short watermark;
    int buffer[3];
};

struct EventLog_R001927_2713_3 {
    int signature;
    int timestamp;
    unsigned char code;
    unsigned char facility;
    int buffer[3];
};

union TelemetryField_R001927_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001927_2713_0(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int margin_73 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_73 > 24) {
        acc = (acc + margin_73 * 2 + 5) & 127;
        aux ^= (margin_73 & 15);
    } else {
        acc = (acc - margin_73 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_38 = local_arr[aux % 3];
    acc = (acc + pivot_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_83 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_83 = (pivot_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_30 = 0;
    for (int k = 0; k < 3; k++) {
        segment_30 = (segment_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_30) & 127;
    }
    int coefficient_58 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_58 > 33) {
        acc = (acc + coefficient_58 * 2 + 5) & 127;
        aux ^= (coefficient_58 & 15);
    } else {
        acc = (acc - coefficient_58 + 11) & 127;
        aux += 3;
    }
    int anchor_23 = (aux + st.buffer[1]) & 3;
    switch (anchor_23) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int mask_63 = (aux + st.buffer[1]) & 3;
    switch (mask_63) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_90 = 0;
    for (int k = 0; k < 3; k++) {
        vector_90 = (vector_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_3(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int vector_10 = local_arr[aux % 3];
    acc = (acc + vector_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_4(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_91 = local_arr[aux % 3];
    acc = (acc + window_91 * 2) & 127;
    int coefficient_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001927_2713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_82 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_82 > 26) {
        acc = (acc + damping_82 * 2 + 5) & 127;
        aux ^= (damping_82 & 15);
    } else {
        acc = (acc - damping_82 + 11) & 127;
        aux += 3;
    }
    int delta_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001927_2713_6(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_77 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_77 > 24) {
        acc = (acc + metric_77 * 2 + 5) & 127;
        aux ^= (metric_77 & 15);
    } else {
        acc = (acc - metric_77 + 11) & 127;
        aux += 3;
    }
    int margin_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_84) & 63;
    acc ^= aux;
    int pivot_42 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_42 = (pivot_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_42) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int stride_12 = 0;
    for (int k = 0; k < 2; k++) {
        stride_12 = (stride_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_12) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_43 = local_arr[aux % 3];
    acc = (acc + parity_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_53) & 63;
    acc ^= aux;
    int index_reg_14 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_14 > 40) {
        acc = (acc + index_reg_14 * 2 + 5) & 127;
        aux ^= (index_reg_14 & 15);
    } else {
        acc = (acc - index_reg_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_19 = local_arr[aux % 3];
    acc = (acc + tracker_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_9(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int delta_44 = 0;
    for (int k = 0; k < 3; k++) {
        delta_44 = (delta_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_44) & 127;
    }
    int tracker_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_34 = local_arr[aux % 3];
    acc = (acc + offset_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_10(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int scale_84 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_84 > 49) {
        acc = (acc + scale_84 * 2 + 5) & 127;
        aux ^= (scale_84 & 15);
    } else {
        acc = (acc - scale_84 + 11) & 127;
        aux += 3;
    }
    int accumulator_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_33) & 63;
    acc ^= aux;
    int scale_40 = 0;
    for (int k = 0; k < 3; k++) {
        scale_40 = (scale_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_40) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_88 = local_arr[aux % 3];
    acc = (acc + metric_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_11(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int cursor_44 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_44 > 25) {
        acc = (acc + cursor_44 * 2 + 5) & 127;
        aux ^= (cursor_44 & 15);
    } else {
        acc = (acc - cursor_44 + 11) & 127;
        aux += 3;
    }
    int weight_13 = (aux + st.buffer[1]) & 3;
    switch (weight_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_58 = 0;
    for (int k = 0; k < 2; k++) {
        scale_58 = (scale_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_58) & 127;
    }
    int quotient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001927_2713_12(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_29 = 0;
    for (int k = 0; k < 3; k++) {
        offset_29 = (offset_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_29) & 127;
    }
    int stride_50 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_50 > 21) {
        acc = (acc + stride_50 * 2 + 5) & 127;
        aux ^= (stride_50 & 15);
    } else {
        acc = (acc - stride_50 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_52 = local_arr[aux % 3];
    acc = (acc + offset_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_38 = (aux + st.buffer[1]) & 3;
    switch (delta_38) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_94 = local_arr[aux % 3];
    acc = (acc + weight_94 * 2) & 127;
    int bound_42 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_42 > 28) {
        acc = (acc + bound_42 * 2 + 5) & 127;
        aux ^= (bound_42 & 15);
    } else {
        acc = (acc - bound_42 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_95) & 63;
    acc ^= aux;
    int metric_71 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_71 > 24) {
        acc = (acc + metric_71 * 2 + 5) & 127;
        aux ^= (metric_71 & 15);
    } else {
        acc = (acc - metric_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_15(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int mask_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_18) & 63;
    acc ^= aux;
    int window_68 = (aux + st.buffer[1]) & 3;
    switch (window_68) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int damping_59 = (aux + st.buffer[1]) & 3;
    switch (damping_59) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_82 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_82 = (coefficient_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_17(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int cursor_96 = (aux + st.buffer[1]) & 3;
    switch (cursor_96) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_43 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_43 > 50) {
        acc = (acc + vector_43 * 2 + 5) & 127;
        aux ^= (vector_43 & 15);
    } else {
        acc = (acc - vector_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int mask_40 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_40 > 27) {
        acc = (acc + mask_40 * 2 + 5) & 127;
        aux ^= (mask_40 & 15);
    } else {
        acc = (acc - mask_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_70 = 0;
    for (int k = 0; k < 2; k++) {
        vector_70 = (vector_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_70) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001927_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int parity_25 = 0;
    for (int k = 0; k < 2; k++) {
        parity_25 = (parity_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_25) & 127;
    }
    int window_71 = (st.buffer[0] * 3 + aux) & 63;
    if (window_71 > 37) {
        acc = (acc + window_71 * 2 + 5) & 127;
        aux ^= (window_71 & 15);
    } else {
        acc = (acc - window_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int checksum_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_20 = local_arr[aux % 3];
    acc = (acc + quotient_20 * 2) & 127;
    int metric_84 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_84 > 35) {
        acc = (acc + metric_84 * 2 + 5) & 127;
        aux ^= (metric_84 & 15);
    } else {
        acc = (acc - metric_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_21(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_99 = 0;
    for (int k = 0; k < 2; k++) {
        tally_99 = (tally_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_99) & 127;
    }
    int checksum_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_87) & 63;
    acc ^= aux;
    int factor_36 = (aux + st.buffer[1]) & 3;
    switch (factor_36) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_12 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_12 > 26) {
        acc = (acc + bound_12 * 2 + 5) & 127;
        aux ^= (bound_12 & 15);
    } else {
        acc = (acc - bound_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001927_2713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int anchor_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_18) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_18 = local_arr[aux % 3];
    acc = (acc + checksum_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001927_2713_23(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001927_0;
    int sec_r001927_1;
    int sec_r001927_2;
    int sec_r001927_3;
    int sec_r001927_4;
    int sec_r001927_5;
    int sec_r001927_6;
    int sec_r001927_7;
    int sec_r001927_8;
    int sec_r001927_9;
    int sec_r001927_10;
    int sec_r001927_11;
    int sec_r001927_12;
    int sec_r001927_13;
    int sec_r001927_14;
    int sec_r001927_15;
    int pub_r001927_0;
    int pub_r001927_1;
    int pub_r001927_2;
    int pub_r001927_3;
    int pub_r001927_4;
    int pub_r001927_5;
    int pub_r001927_6;
    int pub_r001927_7;
    int pub_r001927_8;
    int pub_r001927_9;
    int pub_r001927_10;
    int pub_r001927_11;
    int pub_r001927_12;
    int pub_r001927_13;
    int pub_r001927_14;
    int pub_r001927_15;
    int pub_r001927_16;
    int pub_r001927_17;
    int pub_r001927_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001927_0 >= -100 && pub_r001927_0 <= 100);
    __CPROVER_assume(pub_r001927_1 >= -100 && pub_r001927_1 <= 100);
    __CPROVER_assume(pub_r001927_2 >= -100 && pub_r001927_2 <= 100);
    __CPROVER_assume(pub_r001927_3 >= -100 && pub_r001927_3 <= 100);
    __CPROVER_assume(pub_r001927_4 >= -100 && pub_r001927_4 <= 100);
    __CPROVER_assume(pub_r001927_5 >= -100 && pub_r001927_5 <= 100);
    __CPROVER_assume(pub_r001927_6 >= -100 && pub_r001927_6 <= 100);
    __CPROVER_assume(pub_r001927_7 >= -100 && pub_r001927_7 <= 100);
    __CPROVER_assume(pub_r001927_8 >= -100 && pub_r001927_8 <= 100);
    __CPROVER_assume(pub_r001927_9 >= -100 && pub_r001927_9 <= 100);
    __CPROVER_assume(pub_r001927_10 >= -100 && pub_r001927_10 <= 100);
    __CPROVER_assume(pub_r001927_11 >= -100 && pub_r001927_11 <= 100);
    __CPROVER_assume(pub_r001927_12 >= -100 && pub_r001927_12 <= 100);
    __CPROVER_assume(pub_r001927_13 >= -100 && pub_r001927_13 <= 100);
    __CPROVER_assume(pub_r001927_14 >= -100 && pub_r001927_14 <= 100);
    __CPROVER_assume(pub_r001927_15 >= -100 && pub_r001927_15 <= 100);
    __CPROVER_assume(pub_r001927_16 >= -100 && pub_r001927_16 <= 100);
    __CPROVER_assume(pub_r001927_17 >= -100 && pub_r001927_17 <= 100);
    __CPROVER_assume(pub_r001927_18 >= -100 && pub_r001927_18 <= 100);
    __CPROVER_assume(sec_r001927_0 >= 0 && sec_r001927_0 <= 255);
    __CPROVER_assume(sec_r001927_1 >= 0 && sec_r001927_1 <= 255);
    __CPROVER_assume(sec_r001927_2 >= 0 && sec_r001927_2 <= 255);
    __CPROVER_assume(sec_r001927_3 >= 0 && sec_r001927_3 <= 255);
    __CPROVER_assume(sec_r001927_4 >= 0 && sec_r001927_4 <= 255);
    __CPROVER_assume(sec_r001927_5 >= 0 && sec_r001927_5 <= 255);
    __CPROVER_assume(sec_r001927_6 >= 0 && sec_r001927_6 <= 255);
    __CPROVER_assume(sec_r001927_7 >= 0 && sec_r001927_7 <= 255);
    __CPROVER_assume(sec_r001927_8 >= 0 && sec_r001927_8 <= 255);
    __CPROVER_assume(sec_r001927_9 >= 0 && sec_r001927_9 <= 255);
    __CPROVER_assume(sec_r001927_10 >= 0 && sec_r001927_10 <= 255);
    __CPROVER_assume(sec_r001927_11 >= 0 && sec_r001927_11 <= 255);
    __CPROVER_assume(sec_r001927_12 >= 0 && sec_r001927_12 <= 255);
    __CPROVER_assume(sec_r001927_13 >= 0 && sec_r001927_13 <= 255);
    __CPROVER_assume(sec_r001927_14 >= 0 && sec_r001927_14 <= 255);
    __CPROVER_assume(sec_r001927_15 >= 0 && sec_r001927_15 <= 255);

    struct MatrixBlock_R001927_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001927_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001927_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001927_0 + 7) & 15;
    struct SensorNode_R001927_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001927_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001927_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001927_0 + 9) & 15;
    struct StreamBuffer_R001927_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001927_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001927_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001927_0 + 11) & 15;
    struct EventLog_R001927_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001927_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001927_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001927_0 + 13) & 15;

    union TelemetryField_R001927_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001927_2713_0(sec_r001927_0, pub_r001927_1);
    int helper_flow_1 = fn_R001927_2713_1(sec_r001927_1, pub_r001927_2, pub_r001927_3, pub_r001927_4, pub_r001927_5);
    int helper_flow_2 = fn_R001927_2713_2(sec_r001927_2, sec_r001927_3, pub_r001927_4, pub_r001927_5);
    int helper_flow_3 = fn_R001927_2713_3(sec_r001927_3, pub_r001927_4);
    int helper_flow_4 = fn_R001927_2713_4(sec_r001927_4, sec_r001927_5);
    int helper_flow_5 = fn_R001927_2713_5(sec_r001927_5, sec_r001927_6, pub_r001927_7, pub_r001927_8);
    int helper_flow_6 = fn_R001927_2713_6(sec_r001927_6, sec_r001927_7);
    int helper_flow_7 = fn_R001927_2713_7(sec_r001927_7, pub_r001927_8, pub_r001927_9, pub_r001927_10, pub_r001927_11);
    int helper_flow_8 = fn_R001927_2713_8(sec_r001927_8, sec_r001927_9, pub_r001927_10, pub_r001927_11, pub_r001927_12);
    int helper_flow_9 = fn_R001927_2713_9(sec_r001927_9, sec_r001927_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001927_11 ^ pub_r001927_13) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001927_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_7 ^ pub_r001927_3) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001927_3 ^ pub_r001927_6) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001927_7 ^ pub_r001927_13) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001927_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_5 ^ pub_r001927_4) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001927_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_2 ^ pub_r001927_18) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_4 ^ pub_r001927_3) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001927_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001927_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001927_7 ^ pub_r001927_5) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001927_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001927_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001927_11 ^ pub_r001927_7) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001927_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001927_12 ^ pub_r001927_0) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001927_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_5 ^ pub_r001927_2) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001927_13 ^ pub_r001927_13) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001927_5 ^ pub_r001927_2) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (helper_flow_8 ^ pub_r001927_14) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001927_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_7 ^ pub_r001927_12) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_15 ^ pub_r001927_10) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001927_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001927_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_5 ^ pub_r001927_4) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001927_10 ^ pub_r001927_6) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001927_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001927_5 ^ pub_r001927_15) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (helper_flow_1 ^ pub_r001927_18) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_5 ^ pub_r001927_15) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001927_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_3 ^ pub_r001927_17) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001927_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001927_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_1 ^ pub_r001927_9) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_13 ^ pub_r001927_8) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001927_15 ^ pub_r001927_3) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_3 ^ pub_r001927_14) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001927_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001927_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_3 ^ pub_r001927_5) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001927_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001927_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_28 ^ pub_r001927_4) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001927_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_31 ^ pub_r001927_17) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001927_10 ^ pub_r001927_9) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001927_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001927_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001927_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001927_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001927_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_34 ^ pub_r001927_7) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001927_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_7 ^ pub_r001927_10) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001927_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001927_8 ^ pub_r001927_12) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001927_6 ^ pub_r001927_13) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001927_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001927_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001927_4 ^ pub_r001927_12) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_31 ^ pub_r001927_17) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001927_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001927_8 ^ pub_r001927_13) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_34 ^ pub_r001927_5) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_48 ^ pub_r001927_10) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_0 ^ pub_r001927_8) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_0 ^ pub_r001927_8) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_32 ^ pub_r001927_5) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_62 ^ pub_r001927_6) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001927_12 ^ pub_r001927_4) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (helper_flow_3 ^ pub_r001927_14) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_65 ^ pub_r001927_10) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_65 ^ pub_r001927_2) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_42 ^ pub_r001927_13) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001927_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_53 ^ pub_r001927_12) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001927_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001927_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001927_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_7 ^ pub_r001927_13) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001927_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_12 ^ pub_r001927_3) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001927_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001927_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001927_8 ^ pub_r001927_7) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001927_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001927_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_50 ^ pub_r001927_9) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001927_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001927_5 ^ pub_r001927_9) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_62 ^ pub_r001927_10) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001927_2 ^ pub_r001927_18) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001927_12 ^ pub_r001927_0) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_8 ^ pub_r001927_8) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (helper_flow_6 ^ pub_r001927_2) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001927_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_31 ^ pub_r001927_12) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_1 ^ pub_r001927_9) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (helper_flow_2 ^ pub_r001927_5) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r001927_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001927_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001927_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_65 ^ pub_r001927_2) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001927_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001927_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_90 ^ pub_r001927_5) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001927_8 ^ pub_r001927_3) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001927_15 ^ pub_r001927_8) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (helper_flow_4 ^ pub_r001927_9) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_41 ^ pub_r001927_6) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (helper_flow_5 ^ pub_r001927_7) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001927_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001927_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_101 ^ pub_r001927_13) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_100 ^ pub_r001927_17) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_3 ^ pub_r001927_6) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_23 ^ pub_r001927_9) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r001927_11 ^ pub_r001927_12) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_25 ^ pub_r001927_2) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_98 ^ pub_r001927_11) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001927_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001927_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001927_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_75 ^ pub_r001927_3) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (helper_flow_1 ^ pub_r001927_3) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_89 ^ pub_r001927_1) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_106 ^ pub_r001927_16) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_69 ^ pub_r001927_12) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001927_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_55 ^ pub_r001927_10) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001927_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001927_13 ^ pub_r001927_0) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r001927_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001927_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_48 ^ pub_r001927_1) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001927_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_107 ^ pub_r001927_16) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001927_2 ^ pub_r001927_16) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001927_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_69 ^ pub_r001927_9) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001927_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001927_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_109 ^ pub_r001927_3) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_102 ^ pub_r001927_12) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_10 ^ pub_r001927_13) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_52 ^ pub_r001927_0) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_134 ^ pub_r001927_11) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r001927_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_80 ^ pub_r001927_1) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_56 ^ pub_r001927_16) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001927_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_57 ^ pub_r001927_18) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001927_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_34 ^ pub_r001927_4) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_119 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_83 ^ pub_r001927_1) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001927_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001927_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_135 ^ pub_r001927_3) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_130 ^ pub_r001927_17) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_134 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001927_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_69 ^ pub_r001927_13) & 63;
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
    int stage_v_151 = (stage_v_82 ^ pub_r001927_2) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_118 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001927_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_67 ^ pub_r001927_5) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_90 ^ pub_r001927_16) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001927_5 ^ pub_r001927_13) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_130 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_63 ^ pub_r001927_0) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_148 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_130 ^ pub_r001927_0) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001927_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_52 ^ pub_r001927_1) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001927_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_90 ^ pub_r001927_1) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_63 ^ pub_r001927_2) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_154 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_144 ^ pub_r001927_6) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_83 ^ pub_r001927_6) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_116 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_143 ^ pub_r001927_11) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_85 ^ pub_r001927_15) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_12 ^ pub_r001927_11) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_10 ^ pub_r001927_10) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_1 ^ pub_r001927_14) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((sec_r001927_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
