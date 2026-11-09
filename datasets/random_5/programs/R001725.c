/*
 * Benchmark Program: R001725
 * Security Family: bitwise_flow
 * Generator Seed: 672513
 * High Inputs: 20 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001725_2513_0 {
    unsigned char threshold;
    int calib;
    short status;
    int buffer[3];
};

struct MatrixBlock_R001725_2513_1 {
    int density;
    unsigned char trace;
    unsigned char scale;
    int dim;
    unsigned char determinant;
    int stride;
    int buffer[3];
};

struct EventLog_R001725_2513_2 {
    short seq;
    short facility;
    int signature;
    int severity;
    int timestamp;
    int code;
    int buffer[3];
};

union TelemetryField_R001725_2513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001725_2513_0(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_14 = (aux + st.buffer[1]) & 3;
    switch (anchor_14) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_41 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_41 > 10) {
        acc = (acc + pivot_41 * 2 + 5) & 127;
        aux ^= (pivot_41 & 15);
    } else {
        acc = (acc - pivot_41 + 11) & 127;
        aux += 3;
    }
    int pivot_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001725_2513_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int damping_87 = local_arr[aux % 3];
    acc = (acc + damping_87 * 2) & 127;
    int parity_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_43) & 63;
    acc ^= aux;
    int quotient_46 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_46 > 17) {
        acc = (acc + quotient_46 * 2 + 5) & 127;
        aux ^= (quotient_46 & 15);
    } else {
        acc = (acc - quotient_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001725_2513_2(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001725_2513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int parity_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_92) & 63;
    acc ^= aux;
    int anchor_21 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_21 > 26) {
        acc = (acc + anchor_21 * 2 + 5) & 127;
        aux ^= (anchor_21 & 15);
    } else {
        acc = (acc - anchor_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001725_2513_3(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001725_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int pivot_55 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_55 = (pivot_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_55) & 127;
    }
    int threshold_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001725_2513_4(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001725_2513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int bound_23 = (aux + st.buffer[1]) & 3;
    switch (bound_23) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_59 = local_arr[aux % 3];
    acc = (acc + bound_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001725_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int metric_65 = (aux + st.buffer[1]) & 3;
    switch (metric_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_71) & 63;
    acc ^= aux;
    int scale_92 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_92 > 43) {
        acc = (acc + scale_92 * 2 + 5) & 127;
        aux ^= (scale_92 & 15);
    } else {
        acc = (acc - scale_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001725_2513_6(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001725_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int factor_15 = (aux + st.buffer[1]) & 3;
    switch (factor_15) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_74 = (st.buffer[0] * 3 + aux) & 63;
    if (window_74 > 30) {
        acc = (acc + window_74 * 2 + 5) & 127;
        aux ^= (window_74 & 15);
    } else {
        acc = (acc - window_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001725_2513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int sample_53 = local_arr[aux % 3];
    acc = (acc + sample_53 * 2) & 127;
    int delta_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_58) & 63;
    acc ^= aux;
    int tracker_26 = (aux + st.buffer[1]) & 3;
    switch (tracker_26) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_40 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_40 > 16) {
        acc = (acc + stride_40 * 2 + 5) & 127;
        aux ^= (stride_40 & 15);
    } else {
        acc = (acc - stride_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001725_2513_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001725_2513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int damping_93 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_93 > 32) {
        acc = (acc + damping_93 * 2 + 5) & 127;
        aux ^= (damping_93 & 15);
    } else {
        acc = (acc - damping_93 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_9(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001725_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int cursor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_62 = local_arr[aux % 3];
    acc = (acc + index_reg_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_10(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001725_2513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int segment_60 = 0;
    for (int k = 0; k < 2; k++) {
        segment_60 = (segment_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_60) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_91 = local_arr[aux % 3];
    acc = (acc + sample_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001725_2513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int sample_57 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_57 > 25) {
        acc = (acc + sample_57 * 2 + 5) & 127;
        aux ^= (sample_57 & 15);
    } else {
        acc = (acc - sample_57 + 11) & 127;
        aux += 3;
    }
    int margin_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001725_2513_12(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_72) & 63;
    acc ^= aux;
    int margin_37 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_37 > 11) {
        acc = (acc + margin_37 * 2 + 5) & 127;
        aux ^= (margin_37 & 15);
    } else {
        acc = (acc - margin_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_61 = local_arr[aux % 3];
    acc = (acc + scale_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_13(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_20 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_20 > 30) {
        acc = (acc + damping_20 * 2 + 5) & 127;
        aux ^= (damping_20 & 15);
    } else {
        acc = (acc - damping_20 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_90 = local_arr[aux % 3];
    acc = (acc + sample_90 * 2) & 127;
    int margin_71 = 0;
    for (int k = 0; k < 2; k++) {
        margin_71 = (margin_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_71) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int scale_15 = (aux + st.buffer[1]) & 3;
    switch (scale_15) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_27 = 0;
    for (int k = 0; k < 2; k++) {
        residue_27 = (residue_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_27) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_19 = local_arr[aux % 3];
    acc = (acc + accumulator_19 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_15(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001725_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_91 = local_arr[aux % 3];
    acc = (acc + pivot_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_16(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int damping_93 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_93 > 28) {
        acc = (acc + damping_93 * 2 + 5) & 127;
        aux ^= (damping_93 & 15);
    } else {
        acc = (acc - damping_93 + 11) & 127;
        aux += 3;
    }
    int pivot_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_70) & 63;
    acc ^= aux;
    int vector_64 = (aux + st.buffer[1]) & 3;
    switch (vector_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_31 = local_arr[aux % 3];
    acc = (acc + index_reg_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001725_2513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int offset_74 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_74 > 17) {
        acc = (acc + offset_74 * 2 + 5) & 127;
        aux ^= (offset_74 & 15);
    } else {
        acc = (acc - offset_74 + 11) & 127;
        aux += 3;
    }
    int parity_46 = 0;
    for (int k = 0; k < 3; k++) {
        parity_46 = (parity_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_46) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001725_2513_18(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_95) & 63;
    acc ^= aux;
    int delta_84 = (aux + st.buffer[1]) & 3;
    switch (delta_84) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_91 = 0;
    for (int k = 0; k < 3; k++) {
        delta_91 = (delta_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_91) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_21 = local_arr[aux % 3];
    acc = (acc + cursor_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001725_2513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int weight_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_43) & 63;
    acc ^= aux;
    int segment_87 = (aux + st.buffer[1]) & 3;
    switch (segment_87) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_20(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001725_2513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int phase_24 = (aux + st.buffer[1]) & 3;
    switch (phase_24) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_46) & 63;
    acc ^= aux;
    int tracker_30 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_30 > 11) {
        acc = (acc + tracker_30 * 2 + 5) & 127;
        aux ^= (tracker_30 & 15);
    } else {
        acc = (acc - tracker_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_16 = local_arr[aux % 3];
    acc = (acc + quantum_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001725_2513_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001725_2513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_97) & 63;
    acc ^= aux;
    int quantum_41 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_41 > 15) {
        acc = (acc + quantum_41 * 2 + 5) & 127;
        aux ^= (quantum_41 & 15);
    } else {
        acc = (acc - quantum_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001725_0;
    int sec_r001725_1;
    int sec_r001725_2;
    int sec_r001725_3;
    int sec_r001725_4;
    int sec_r001725_5;
    int sec_r001725_6;
    int sec_r001725_7;
    int sec_r001725_8;
    int sec_r001725_9;
    int sec_r001725_10;
    int sec_r001725_11;
    int sec_r001725_12;
    int sec_r001725_13;
    int sec_r001725_14;
    int sec_r001725_15;
    int sec_r001725_16;
    int sec_r001725_17;
    int sec_r001725_18;
    int sec_r001725_19;
    int pub_r001725_0;
    int pub_r001725_1;
    int pub_r001725_2;
    int pub_r001725_3;
    int pub_r001725_4;
    int pub_r001725_5;
    int pub_r001725_6;
    int pub_r001725_7;
    int pub_r001725_8;
    int pub_r001725_9;
    int pub_r001725_10;
    int pub_r001725_11;
    int pub_r001725_12;
    int pub_r001725_13;
    int pub_r001725_14;
    int pub_r001725_15;
    int pub_r001725_16;
    int pub_r001725_17;
    int pub_r001725_18;
    int pub_r001725_19;
    int pub_r001725_20;
    int pub_r001725_21;
    int pub_r001725_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001725_0 >= -100 && pub_r001725_0 <= 100);
    __CPROVER_assume(pub_r001725_1 >= -100 && pub_r001725_1 <= 100);
    __CPROVER_assume(pub_r001725_2 >= -100 && pub_r001725_2 <= 100);
    __CPROVER_assume(pub_r001725_3 >= -100 && pub_r001725_3 <= 100);
    __CPROVER_assume(pub_r001725_4 >= -100 && pub_r001725_4 <= 100);
    __CPROVER_assume(pub_r001725_5 >= -100 && pub_r001725_5 <= 100);
    __CPROVER_assume(pub_r001725_6 >= -100 && pub_r001725_6 <= 100);
    __CPROVER_assume(pub_r001725_7 >= -100 && pub_r001725_7 <= 100);
    __CPROVER_assume(pub_r001725_8 >= -100 && pub_r001725_8 <= 100);
    __CPROVER_assume(pub_r001725_9 >= -100 && pub_r001725_9 <= 100);
    __CPROVER_assume(pub_r001725_10 >= -100 && pub_r001725_10 <= 100);
    __CPROVER_assume(pub_r001725_11 >= -100 && pub_r001725_11 <= 100);
    __CPROVER_assume(pub_r001725_12 >= -100 && pub_r001725_12 <= 100);
    __CPROVER_assume(pub_r001725_13 >= -100 && pub_r001725_13 <= 100);
    __CPROVER_assume(pub_r001725_14 >= -100 && pub_r001725_14 <= 100);
    __CPROVER_assume(pub_r001725_15 >= -100 && pub_r001725_15 <= 100);
    __CPROVER_assume(pub_r001725_16 >= -100 && pub_r001725_16 <= 100);
    __CPROVER_assume(pub_r001725_17 >= -100 && pub_r001725_17 <= 100);
    __CPROVER_assume(pub_r001725_18 >= -100 && pub_r001725_18 <= 100);
    __CPROVER_assume(pub_r001725_19 >= -100 && pub_r001725_19 <= 100);
    __CPROVER_assume(pub_r001725_20 >= -100 && pub_r001725_20 <= 100);
    __CPROVER_assume(pub_r001725_21 >= -100 && pub_r001725_21 <= 100);
    __CPROVER_assume(pub_r001725_22 >= -100 && pub_r001725_22 <= 100);
    __CPROVER_assume(sec_r001725_0 >= 0 && sec_r001725_0 <= 255);
    __CPROVER_assume(sec_r001725_1 >= 0 && sec_r001725_1 <= 255);
    __CPROVER_assume(sec_r001725_2 >= 0 && sec_r001725_2 <= 255);
    __CPROVER_assume(sec_r001725_3 >= 0 && sec_r001725_3 <= 255);
    __CPROVER_assume(sec_r001725_4 >= 0 && sec_r001725_4 <= 255);
    __CPROVER_assume(sec_r001725_5 >= 0 && sec_r001725_5 <= 255);
    __CPROVER_assume(sec_r001725_6 >= 0 && sec_r001725_6 <= 255);
    __CPROVER_assume(sec_r001725_7 >= 0 && sec_r001725_7 <= 255);
    __CPROVER_assume(sec_r001725_8 >= 0 && sec_r001725_8 <= 255);
    __CPROVER_assume(sec_r001725_9 >= 0 && sec_r001725_9 <= 255);
    __CPROVER_assume(sec_r001725_10 >= 0 && sec_r001725_10 <= 255);
    __CPROVER_assume(sec_r001725_11 >= 0 && sec_r001725_11 <= 255);
    __CPROVER_assume(sec_r001725_12 >= 0 && sec_r001725_12 <= 255);
    __CPROVER_assume(sec_r001725_13 >= 0 && sec_r001725_13 <= 255);
    __CPROVER_assume(sec_r001725_14 >= 0 && sec_r001725_14 <= 255);
    __CPROVER_assume(sec_r001725_15 >= 0 && sec_r001725_15 <= 255);
    __CPROVER_assume(sec_r001725_16 >= 0 && sec_r001725_16 <= 255);
    __CPROVER_assume(sec_r001725_17 >= 0 && sec_r001725_17 <= 255);
    __CPROVER_assume(sec_r001725_18 >= 0 && sec_r001725_18 <= 255);
    __CPROVER_assume(sec_r001725_19 >= 0 && sec_r001725_19 <= 255);

    struct SensorNode_R001725_2513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001725_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001725_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001725_0 + 7) & 15;
    struct MatrixBlock_R001725_2513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001725_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001725_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001725_0 + 9) & 15;
    struct EventLog_R001725_2513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001725_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001725_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001725_0 + 11) & 15;

    union TelemetryField_R001725_2513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001725_2513_0(sec_r001725_0, pub_r001725_1, pub_r001725_2);
    int helper_flow_1 = fn_R001725_2513_1(sec_r001725_1, pub_r001725_2, pub_r001725_3);
    int helper_flow_2 = fn_R001725_2513_2(sec_r001725_2, sec_r001725_3);
    int helper_flow_3 = fn_R001725_2513_3(sec_r001725_3, sec_r001725_4);
    int helper_flow_4 = fn_R001725_2513_4(sec_r001725_4, sec_r001725_5, pub_r001725_6);
    int helper_flow_5 = fn_R001725_2513_5(sec_r001725_5, sec_r001725_6, pub_r001725_7, pub_r001725_8);
    int helper_flow_6 = fn_R001725_2513_6(sec_r001725_6, sec_r001725_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001725_14 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001725_17 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001725_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001725_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001725_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_1 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_5 + 1) & 15;
    out_sink ^= (stage_v_5 & 63);

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001725_1 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001725_2 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_7 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001725_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_6 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_2 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001725_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001725_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001725_16 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_6 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_2 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_16 + 1) & 15;
    out_sink ^= (stage_v_16 & 63);

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((helper_flow_6 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001725_14 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_14 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001725_19 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001725_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001725_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001725_14 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001725_19 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001725_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001725_21 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001725_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_1 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_5 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_0 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001725_2 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001725_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001725_14 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001725_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001725_17 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001725_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001725_10 << 1) ^ (pub_r001725_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001725_2 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_6 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001725_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001725_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001725_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001725_22 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001725_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_16 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001725_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_4 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001725_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_39 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001725_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_49 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001725_0 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_38 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001725_11 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((helper_flow_0 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001725_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001725_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_38 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_49 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_59 + 1) & 15;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_49 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((helper_flow_1 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_0 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001725_3 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001725_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_16 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_14 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001725_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001725_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_30 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_69 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001725_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_69 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001725_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001725_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001725_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_63 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001725_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_61 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001725_10 << 1) ^ (pub_r001725_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001725_22 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_59 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001725_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_70 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_30 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_69 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001725_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001725_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001725_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001725_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001725_22 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001725_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001725_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001725_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001725_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001725_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_6 << 1) ^ (pub_r001725_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_76 << 1) ^ (pub_r001725_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001725_19 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001725_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_76 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_65 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001725_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001725_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001725_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001725_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_81 << 1) ^ (pub_r001725_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001725_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_15 << 1) ^ (pub_r001725_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((helper_flow_5 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001725_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_100 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_28 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001725_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001725_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001725_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_14 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001725_21 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_116 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_58 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001725_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001725_16 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001725_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_52 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001725_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001725_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_118 << 1) ^ (pub_r001725_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_28 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001725_14 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_81 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001725_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001725_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_97 << 1) ^ (pub_r001725_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001725_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001725_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001725_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_85 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_118 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001725_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_108 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_121 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001725_1 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_132 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001725_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_142 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_24 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001725_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001725_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_127 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_19 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001725_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001725_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001725_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((helper_flow_4 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001725_22 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001725_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001725_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_23 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_79 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001725_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001725_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001725_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_4 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_69 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001725_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001725_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_28 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001725_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001725_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001725_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001725_16 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_5 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001725_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001725_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001725_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001725_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_53 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001725_21 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_66 << 1) ^ (pub_r001725_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_157 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001725_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001725_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r001725_5 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_106 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001725_21 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_170 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001725_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001725_22 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001725_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001725_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001725_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001725_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001725_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001725_18 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_142 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_58 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_11 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001725_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r001725_14 << 1) ^ (pub_r001725_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_58 << 1) ^ (pub_r001725_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_5 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001725_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_96 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001725_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001725_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001725_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001725_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((helper_flow_4 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_140 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001725_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001725_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001725_22 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_37 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_45 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_141 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001725_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_70 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001725_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_144 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001725_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_121 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001725_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_141 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001725_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001725_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001725_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001725_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_81 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_24 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001725_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001725_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_35 << 1) ^ (pub_r001725_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((sec_r001725_17 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_232 + 1) & 15;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_111 << 1) ^ (pub_r001725_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_15 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_227 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001725_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001725_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_116 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_29 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_63 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001725_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r001725_2 << 1) ^ (pub_r001725_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_166 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_69 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001725_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001725_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001725_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_39 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_171 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_249 + 1) & 15;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001725_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001725_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001725_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_53 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001725_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001725_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_214 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001725_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((sec_r001725_0 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_233 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_97 << 1) ^ (pub_r001725_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001725_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((helper_flow_5 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((sec_r001725_17 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_258 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_196 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001725_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_39 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001725_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_76 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_263 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001725_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_79 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_244 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_119 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_109 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r001725_11 << 1) ^ (pub_r001725_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001725_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_240 << 1) ^ (pub_r001725_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001725_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001725_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_176 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001725_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_273 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_128 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_65 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001725_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_183 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001725_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_218 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((sec_r001725_16 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001725_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_17 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001725_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_118 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001725_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_59 << 1) ^ (pub_r001725_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_126 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_63 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001725_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_216 << 1) ^ (pub_r001725_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_81 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001725_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_218 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_123 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_259 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((helper_flow_5 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_49 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001725_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r001725_3 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r001725_19 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_296 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((sec_r001725_5 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_72 << 1) ^ (pub_r001725_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001725_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001725_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001725_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((sec_r001725_16 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_287 << 1) ^ (pub_r001725_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001725_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001725_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_185 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001725_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001725_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_1 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_100 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_132 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001725_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001725_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((sec_r001725_12 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001725_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001725_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_18 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_218 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_19 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_72 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001725_22 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001725_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_29 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001725_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001725_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001725_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_140 << 1) ^ (pub_r001725_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_51 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001725_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001725_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001725_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001725_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_235 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((sec_r001725_16 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_162 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001725_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001725_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_213 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_101 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_325 << 1) ^ (pub_r001725_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_106 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_62 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_310 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001725_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((sec_r001725_2 << 1) ^ (pub_r001725_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001725_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_33 << 1) ^ (pub_r001725_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_362 + 1) & 15;
    out_sink ^= (stage_v_362 & 63);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_287 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_239 << 1) ^ (pub_r001725_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_72 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001725_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_5 << 1) ^ (pub_r001725_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_101 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001725_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001725_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_358 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((sec_r001725_3 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001725_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001725_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_106 << 1) ^ (pub_r001725_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001725_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((helper_flow_5 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_58 << 1) ^ (pub_r001725_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001725_22 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_47 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001725_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_289 << 1) ^ (pub_r001725_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_216 << 1) ^ (pub_r001725_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_158 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_242 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_385 + 1) & 15;
    out_sink ^= (stage_v_385 & 63);

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001725_22 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_371 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((sec_r001725_5 << 1) ^ (pub_r001725_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001725_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001725_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_81 << 1) ^ (pub_r001725_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001725_21 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001725_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_318 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001725_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_60 << 1) ^ (pub_r001725_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001725_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001725_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_234 << 1) ^ (pub_r001725_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_303 << 1) ^ (pub_r001725_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001725_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_212 << 1) ^ (pub_r001725_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_10 << 1) ^ (pub_r001725_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001725_20 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001725_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_309 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_166 << 1) ^ (pub_r001725_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_121 << 1) ^ (pub_r001725_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((sec_r001725_15 << 1) ^ (pub_r001725_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((sec_r001725_3 << 1) ^ (pub_r001725_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001725_22 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_399 << 1) ^ (pub_r001725_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001725_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001725_22 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((sec_r001725_19 << 1) ^ (pub_r001725_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001725_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001725_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
