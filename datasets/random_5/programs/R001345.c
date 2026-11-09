/*
 * Benchmark Program: R001345
 * Security Family: bitwise_flow
 * Generator Seed: 634513
 * High Inputs: 24 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001345_4513_0 {
    short timestamp;
    short code;
    int facility;
    int signature;
    int seq;
    short severity;
    int buffer[3];
};

struct MatrixBlock_R001345_4513_1 {
    int trace;
    int density;
    int determinant;
    unsigned char scale;
    int stride;
    short dim;
    int buffer[3];
};

union RegisterBank_R001345_4513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001345_4513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001345_4513_0(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int pivot_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_97) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_50 = (aux + st.buffer[1]) & 3;
    switch (pivot_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_71 = local_arr[aux % 3];
    acc = (acc + metric_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001345_4513_1(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int cursor_65 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_65 > 11) {
        acc = (acc + cursor_65 * 2 + 5) & 127;
        aux ^= (cursor_65 & 15);
    } else {
        acc = (acc - cursor_65 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_13 = local_arr[aux % 3];
    acc = (acc + bound_13 * 2) & 127;
    int delta_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001345_4513_2(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int accumulator_47 = (aux + st.buffer[1]) & 3;
    switch (accumulator_47) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_13 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_13 > 31) {
        acc = (acc + accumulator_13 * 2 + 5) & 127;
        aux ^= (accumulator_13 & 15);
    } else {
        acc = (acc - accumulator_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_3(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_92 = (aux + st.buffer[1]) & 3;
    switch (threshold_92) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_90 = local_arr[aux % 3];
    acc = (acc + delta_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001345_4513_4(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int weight_50 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_50 > 37) {
        acc = (acc + weight_50 * 2 + 5) & 127;
        aux ^= (weight_50 & 15);
    } else {
        acc = (acc - weight_50 + 11) & 127;
        aux += 3;
    }
    int index_reg_20 = (aux + st.buffer[1]) & 3;
    switch (index_reg_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_5(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int stride_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_87) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_98 = local_arr[aux % 3];
    acc = (acc + checksum_98 * 2) & 127;
    int accumulator_31 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_31 = (accumulator_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_6(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_81 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_81 > 41) {
        acc = (acc + delta_81 * 2 + 5) & 127;
        aux ^= (delta_81 & 15);
    } else {
        acc = (acc - delta_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quotient_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_59) & 63;
    acc ^= aux;
    int damping_51 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_51 > 25) {
        acc = (acc + damping_51 * 2 + 5) & 127;
        aux ^= (damping_51 & 15);
    } else {
        acc = (acc - damping_51 + 11) & 127;
        aux += 3;
    }
    int residue_18 = (aux + st.buffer[1]) & 3;
    switch (residue_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_79 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_79 = (index_reg_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_79) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int segment_45 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_45 > 37) {
        acc = (acc + segment_45 * 2 + 5) & 127;
        aux ^= (segment_45 & 15);
    } else {
        acc = (acc - segment_45 + 11) & 127;
        aux += 3;
    }
    int weight_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001345_4513_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_43 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_43 > 21) {
        acc = (acc + stride_43 * 2 + 5) & 127;
        aux ^= (stride_43 & 15);
    } else {
        acc = (acc - stride_43 + 11) & 127;
        aux += 3;
    }
    int sample_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001345_4513_10(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int cursor_35 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_35 = (cursor_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_35) & 127;
    }
    int threshold_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001345_4513_11(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int phase_20 = (aux + st.buffer[1]) & 3;
    switch (phase_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_73 = local_arr[aux % 3];
    acc = (acc + phase_73 * 2) & 127;
    int phase_57 = 0;
    for (int k = 0; k < 2; k++) {
        phase_57 = (phase_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_57) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int parity_78 = local_arr[aux % 3];
    acc = (acc + parity_78 * 2) & 127;
    int bound_66 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_66 > 44) {
        acc = (acc + bound_66 * 2 + 5) & 127;
        aux ^= (bound_66 & 15);
    } else {
        acc = (acc - bound_66 + 11) & 127;
        aux += 3;
    }
    int metric_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001345_4513_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int vector_73 = local_arr[aux % 3];
    acc = (acc + vector_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_67) & 63;
    acc ^= aux;
    int quotient_50 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_50 = (quotient_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_50) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int index_reg_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_54) & 63;
    acc ^= aux;
    int vector_63 = 0;
    for (int k = 0; k < 2; k++) {
        vector_63 = (vector_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_63) & 127;
    }
    int cursor_66 = (aux + st.buffer[1]) & 3;
    switch (cursor_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_15(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_66 = (aux + st.buffer[1]) & 3;
    switch (threshold_66) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001345_4513_16(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quotient_76 = (aux + st.buffer[1]) & 3;
    switch (quotient_76) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_13 = 0;
    for (int k = 0; k < 3; k++) {
        damping_13 = (damping_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_13) & 127;
    }
    int margin_74 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_74 > 32) {
        acc = (acc + margin_74 * 2 + 5) & 127;
        aux ^= (margin_74 & 15);
    } else {
        acc = (acc - margin_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_48 = local_arr[aux % 3];
    acc = (acc + threshold_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001345_4513_17(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_79 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_79 > 19) {
        acc = (acc + threshold_79 * 2 + 5) & 127;
        aux ^= (threshold_79 & 15);
    } else {
        acc = (acc - threshold_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_10 = local_arr[aux % 3];
    acc = (acc + sample_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001345_4513_18(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_31 = 0;
    for (int k = 0; k < 3; k++) {
        metric_31 = (metric_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_19(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int sample_85 = local_arr[aux % 3];
    acc = (acc + sample_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_55 = 0;
    for (int k = 0; k < 2; k++) {
        parity_55 = (parity_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_55) & 127;
    }
    int pivot_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001345_4513_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int phase_20 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_20 > 29) {
        acc = (acc + phase_20 * 2 + 5) & 127;
        aux ^= (phase_20 & 15);
    } else {
        acc = (acc - phase_20 + 11) & 127;
        aux += 3;
    }
    int coefficient_46 = (aux + st.buffer[1]) & 3;
    switch (coefficient_46) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_28) & 63;
    acc ^= aux;
    int phase_36 = 0;
    for (int k = 0; k < 2; k++) {
        phase_36 = (phase_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_36) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001345_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int vector_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_28) & 63;
    acc ^= aux;
    int bound_57 = 0;
    for (int k = 0; k < 2; k++) {
        bound_57 = (bound_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_57) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_81 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_81 > 15) {
        acc = (acc + accumulator_81 * 2 + 5) & 127;
        aux ^= (accumulator_81 & 15);
    } else {
        acc = (acc - accumulator_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001345_4513_22(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int tally_12 = local_arr[aux % 3];
    acc = (acc + tally_12 * 2) & 127;
    int parity_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001345_4513_23(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001345_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int bound_97 = (aux + st.buffer[1]) & 3;
    switch (bound_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001345_0;
    int sec_r001345_1;
    int sec_r001345_2;
    int sec_r001345_3;
    int sec_r001345_4;
    int sec_r001345_5;
    int sec_r001345_6;
    int sec_r001345_7;
    int sec_r001345_8;
    int sec_r001345_9;
    int sec_r001345_10;
    int sec_r001345_11;
    int sec_r001345_12;
    int sec_r001345_13;
    int sec_r001345_14;
    int sec_r001345_15;
    int sec_r001345_16;
    int sec_r001345_17;
    int sec_r001345_18;
    int sec_r001345_19;
    int sec_r001345_20;
    int sec_r001345_21;
    int sec_r001345_22;
    int sec_r001345_23;
    int pub_r001345_0;
    int pub_r001345_1;
    int pub_r001345_2;
    int pub_r001345_3;
    int pub_r001345_4;
    int pub_r001345_5;
    int pub_r001345_6;
    int pub_r001345_7;
    int pub_r001345_8;
    int pub_r001345_9;
    int pub_r001345_10;
    int pub_r001345_11;
    int pub_r001345_12;
    int pub_r001345_13;
    int pub_r001345_14;
    int pub_r001345_15;
    int pub_r001345_16;
    int pub_r001345_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001345_0 >= -100 && pub_r001345_0 <= 100);
    __CPROVER_assume(pub_r001345_1 >= -100 && pub_r001345_1 <= 100);
    __CPROVER_assume(pub_r001345_2 >= -100 && pub_r001345_2 <= 100);
    __CPROVER_assume(pub_r001345_3 >= -100 && pub_r001345_3 <= 100);
    __CPROVER_assume(pub_r001345_4 >= -100 && pub_r001345_4 <= 100);
    __CPROVER_assume(pub_r001345_5 >= -100 && pub_r001345_5 <= 100);
    __CPROVER_assume(pub_r001345_6 >= -100 && pub_r001345_6 <= 100);
    __CPROVER_assume(pub_r001345_7 >= -100 && pub_r001345_7 <= 100);
    __CPROVER_assume(pub_r001345_8 >= -100 && pub_r001345_8 <= 100);
    __CPROVER_assume(pub_r001345_9 >= -100 && pub_r001345_9 <= 100);
    __CPROVER_assume(pub_r001345_10 >= -100 && pub_r001345_10 <= 100);
    __CPROVER_assume(pub_r001345_11 >= -100 && pub_r001345_11 <= 100);
    __CPROVER_assume(pub_r001345_12 >= -100 && pub_r001345_12 <= 100);
    __CPROVER_assume(pub_r001345_13 >= -100 && pub_r001345_13 <= 100);
    __CPROVER_assume(pub_r001345_14 >= -100 && pub_r001345_14 <= 100);
    __CPROVER_assume(pub_r001345_15 >= -100 && pub_r001345_15 <= 100);
    __CPROVER_assume(pub_r001345_16 >= -100 && pub_r001345_16 <= 100);
    __CPROVER_assume(pub_r001345_17 >= -100 && pub_r001345_17 <= 100);
    __CPROVER_assume(sec_r001345_0 >= 0 && sec_r001345_0 <= 255);
    __CPROVER_assume(sec_r001345_1 >= 0 && sec_r001345_1 <= 255);
    __CPROVER_assume(sec_r001345_2 >= 0 && sec_r001345_2 <= 255);
    __CPROVER_assume(sec_r001345_3 >= 0 && sec_r001345_3 <= 255);
    __CPROVER_assume(sec_r001345_4 >= 0 && sec_r001345_4 <= 255);
    __CPROVER_assume(sec_r001345_5 >= 0 && sec_r001345_5 <= 255);
    __CPROVER_assume(sec_r001345_6 >= 0 && sec_r001345_6 <= 255);
    __CPROVER_assume(sec_r001345_7 >= 0 && sec_r001345_7 <= 255);
    __CPROVER_assume(sec_r001345_8 >= 0 && sec_r001345_8 <= 255);
    __CPROVER_assume(sec_r001345_9 >= 0 && sec_r001345_9 <= 255);
    __CPROVER_assume(sec_r001345_10 >= 0 && sec_r001345_10 <= 255);
    __CPROVER_assume(sec_r001345_11 >= 0 && sec_r001345_11 <= 255);
    __CPROVER_assume(sec_r001345_12 >= 0 && sec_r001345_12 <= 255);
    __CPROVER_assume(sec_r001345_13 >= 0 && sec_r001345_13 <= 255);
    __CPROVER_assume(sec_r001345_14 >= 0 && sec_r001345_14 <= 255);
    __CPROVER_assume(sec_r001345_15 >= 0 && sec_r001345_15 <= 255);
    __CPROVER_assume(sec_r001345_16 >= 0 && sec_r001345_16 <= 255);
    __CPROVER_assume(sec_r001345_17 >= 0 && sec_r001345_17 <= 255);
    __CPROVER_assume(sec_r001345_18 >= 0 && sec_r001345_18 <= 255);
    __CPROVER_assume(sec_r001345_19 >= 0 && sec_r001345_19 <= 255);
    __CPROVER_assume(sec_r001345_20 >= 0 && sec_r001345_20 <= 255);
    __CPROVER_assume(sec_r001345_21 >= 0 && sec_r001345_21 <= 255);
    __CPROVER_assume(sec_r001345_22 >= 0 && sec_r001345_22 <= 255);
    __CPROVER_assume(sec_r001345_23 >= 0 && sec_r001345_23 <= 255);

    struct EventLog_R001345_4513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001345_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001345_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001345_0 + 7) & 15;
    struct MatrixBlock_R001345_4513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001345_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001345_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001345_0 + 9) & 15;

    union RegisterBank_R001345_4513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001345_4513_0(sec_r001345_0, pub_r001345_1, pub_r001345_2);
    int helper_flow_1 = fn_R001345_4513_1(sec_r001345_1, sec_r001345_2, pub_r001345_3);
    int helper_flow_2 = fn_R001345_4513_2(sec_r001345_2, pub_r001345_3);
    int helper_flow_3 = fn_R001345_4513_3(sec_r001345_3, pub_r001345_4, pub_r001345_5);
    int helper_flow_4 = fn_R001345_4513_4(sec_r001345_4, pub_r001345_5, pub_r001345_6);
    int helper_flow_5 = fn_R001345_4513_5(sec_r001345_5, pub_r001345_6, pub_r001345_7);
    int helper_flow_6 = fn_R001345_4513_6(sec_r001345_6, pub_r001345_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001345_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001345_3 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001345_6 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001345_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001345_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001345_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001345_2 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001345_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001345_0 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_6 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001345_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001345_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001345_13 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001345_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001345_13 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001345_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001345_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001345_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001345_7 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001345_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001345_3 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001345_0 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001345_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001345_21 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001345_12 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_8 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001345_23 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001345_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001345_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_0 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001345_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001345_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_21 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001345_6 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001345_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001345_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001345_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001345_23 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001345_6 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001345_1 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001345_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001345_10 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_26 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001345_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001345_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001345_19 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001345_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001345_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001345_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001345_5 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001345_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_37 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001345_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001345_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001345_2 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001345_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001345_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001345_22 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001345_21 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001345_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_57 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_18 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001345_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001345_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001345_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_57 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((helper_flow_4 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_45 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001345_0 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_68 + 1) & 15;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_25 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001345_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001345_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_0 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001345_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001345_15 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_51 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_65 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001345_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_1 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_29 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001345_15 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_45 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((helper_flow_4 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001345_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001345_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001345_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001345_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_58 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_49 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001345_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001345_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001345_7 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_67 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001345_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_79 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_51 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001345_23 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001345_15 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001345_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_49 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_61 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_82 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_23 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001345_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_26 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001345_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001345_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001345_22 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001345_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001345_16 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001345_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001345_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001345_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001345_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001345_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001345_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001345_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001345_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_38 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001345_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001345_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001345_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001345_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001345_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_72 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001345_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001345_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001345_17 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001345_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((helper_flow_5 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_76 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001345_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_100 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_49 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r001345_12 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001345_6 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r001345_20 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r001345_15 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_42 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_138 + 1) & 15;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001345_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001345_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_80 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r001345_20 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_94 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001345_16 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_87 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_102 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((helper_flow_3 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_24 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_51 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001345_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_2 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_138 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_1 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_145 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001345_6 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_26 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001345_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_58 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_74 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_155 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001345_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_92 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_33 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((helper_flow_4 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_97 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001345_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_24 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_61 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_20 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001345_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_130 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001345_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001345_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_33 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_1 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_65 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r001345_17 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_148 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001345_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001345_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001345_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001345_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001345_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_109 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_145 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_25 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001345_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001345_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((helper_flow_0 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001345_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_8 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_177 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_102 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001345_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_72 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_102 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_41 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001345_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r001345_23 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_12 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001345_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001345_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001345_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001345_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001345_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r001345_7 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_146 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_186 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_146 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_191 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001345_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_6 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001345_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001345_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001345_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r001345_8 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001345_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_216 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_88 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001345_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_78 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001345_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001345_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_159 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001345_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_32 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001345_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001345_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_95 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_189 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_25 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001345_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_100 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_152 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001345_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_159 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_163 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_237 + 1) & 15;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001345_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001345_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_129 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001345_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001345_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_95 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001345_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001345_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_129 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_69 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001345_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001345_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001345_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_107 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001345_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001345_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001345_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_76 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001345_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001345_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_159 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_207 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001345_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_237 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001345_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_6 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_171 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001345_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_91 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001345_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001345_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_45 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_18 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001345_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_141 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001345_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_156 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001345_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_57 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_32 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_270 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001345_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001345_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001345_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001345_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_159 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001345_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_81 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_67 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001345_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001345_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_276 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_68 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((helper_flow_1 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_237 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001345_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_285 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001345_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r001345_4 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_130 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_82 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_39 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001345_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_58 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001345_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001345_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001345_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001345_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001345_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001345_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001345_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r001345_7 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001345_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001345_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001345_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001345_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001345_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_100 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001345_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_94 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((helper_flow_4 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_118 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_191 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((helper_flow_0 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_309 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_317 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001345_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_299 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001345_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001345_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001345_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001345_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001345_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001345_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001345_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((sec_r001345_5 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_38 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001345_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001345_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((helper_flow_5 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_226 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_247 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_1 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_156 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_286 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((sec_r001345_21 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001345_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_81 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001345_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_221 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_101 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001345_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_124 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001345_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001345_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001345_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001345_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((sec_r001345_9 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001345_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001345_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_88 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001345_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_339 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001345_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001345_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001345_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_82 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_185 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((helper_flow_1 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001345_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_68 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001345_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001345_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_21 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001345_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001345_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001345_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_263 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_236 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_184 << 1) ^ (pub_r001345_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001345_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_155 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001345_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_319 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001345_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001345_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_342 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001345_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_168 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_299 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_178 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((sec_r001345_1 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001345_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001345_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_8 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_387 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_92 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_208 << 1) ^ (pub_r001345_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((sec_r001345_14 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_196 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_79 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_398 + 1) & 15;
    out_sink ^= (stage_v_398 & 63);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001345_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_269 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001345_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001345_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_274 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001345_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_276 << 1) ^ (pub_r001345_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_296 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_296 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_339 << 1) ^ (pub_r001345_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_186 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_323 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001345_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001345_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((sec_r001345_17 << 1) ^ (pub_r001345_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_155 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_269 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001345_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_261 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001345_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001345_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001345_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_141 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001345_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_75 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_339 << 1) ^ (pub_r001345_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_26 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_153 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((sec_r001345_18 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_427 + 1) & 15;
    out_sink ^= (stage_v_427 & 63);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_251 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_118 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001345_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_68 << 1) ^ (pub_r001345_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001345_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_104 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_42 << 1) ^ (pub_r001345_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_434 + 1) & 15;
    out_sink ^= (stage_v_434 & 63);

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_169 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_133 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((sec_r001345_21 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_406 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_438 + 1) & 15;
    out_sink ^= (stage_v_438 & 63);

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_186 << 1) ^ (pub_r001345_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001345_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((sec_r001345_6 << 1) ^ (pub_r001345_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_155 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_25 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_365 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_92 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001345_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001345_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_23 << 1) ^ (pub_r001345_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001345_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_347 << 1) ^ (pub_r001345_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_290 << 1) ^ (pub_r001345_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001345_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001345_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((sec_r001345_1 << 1) ^ (pub_r001345_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_454 + 1) & 15;
    out_sink ^= (stage_v_454 & 63);

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_135 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_455 + 1) & 15;
    out_sink ^= (stage_v_455 & 63);

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001345_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001345_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_243 << 1) ^ (pub_r001345_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_458 + 1) & 15;
    out_sink ^= (stage_v_458 & 63);

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_421 << 1) ^ (pub_r001345_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_459 + 1) & 15;
    out_sink ^= (stage_v_459 & 63);

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_364 << 1) ^ (pub_r001345_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_350 << 1) ^ (pub_r001345_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_461 + 1) & 15;
    out_sink ^= (stage_v_461 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
