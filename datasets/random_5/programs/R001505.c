/*
 * Benchmark Program: R001505
 * Security Family: bitwise_flow
 * Generator Seed: 650513
 * High Inputs: 18 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001505_513_0 {
    int offset;
    int gain;
    unsigned char threshold;
    int reading;
    int status;
    int buffer[3];
};

struct StreamBuffer_R001505_513_1 {
    int capacity;
    int watermark;
    int tail;
    int buffer[3];
};

struct EventLog_R001505_513_2 {
    int signature;
    int severity;
    unsigned char facility;
    int timestamp;
    unsigned char seq;
    int buffer[3];
};

union PacketPayload_R001505_513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001505_513_0(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_84 = (aux + st.buffer[1]) & 3;
    switch (mask_84) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_43 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_43 > 41) {
        acc = (acc + tracker_43 * 2 + 5) & 127;
        aux ^= (tracker_43 & 15);
    } else {
        acc = (acc - tracker_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_77 = 0;
    for (int k = 0; k < 2; k++) {
        bound_77 = (bound_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_77) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_1(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int bound_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_41) & 63;
    acc ^= aux;
    int weight_59 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_59 > 19) {
        acc = (acc + weight_59 * 2 + 5) & 127;
        aux ^= (weight_59 & 15);
    } else {
        acc = (acc - weight_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int damping_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_69) & 63;
    acc ^= aux;
    int anchor_74 = (aux + st.buffer[1]) & 3;
    switch (anchor_74) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_3(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int pivot_62 = (aux + st.buffer[1]) & 3;
    switch (pivot_62) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_96 = 0;
    for (int k = 0; k < 2; k++) {
        factor_96 = (factor_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_96) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_23 = local_arr[aux % 3];
    acc = (acc + metric_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001505_513_4(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001505_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tracker_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_50) & 63;
    acc ^= aux;
    int quantum_50 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_50 > 49) {
        acc = (acc + quantum_50 * 2 + 5) & 127;
        aux ^= (quantum_50 & 15);
    } else {
        acc = (acc - quantum_50 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_63 = local_arr[aux % 3];
    acc = (acc + phase_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001505_513_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_53 = (aux + st.buffer[1]) & 3;
    switch (metric_53) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_98 = local_arr[aux % 3];
    acc = (acc + metric_98 * 2) & 127;
    int metric_51 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_51 > 11) {
        acc = (acc + metric_51 * 2 + 5) & 127;
        aux ^= (metric_51 & 15);
    } else {
        acc = (acc - metric_51 + 11) & 127;
        aux += 3;
    }
    int cursor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001505_513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_26 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_26 = (anchor_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_26) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_63 = local_arr[aux % 3];
    acc = (acc + segment_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001505_513_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_35) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_94 = local_arr[aux % 3];
    acc = (acc + segment_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001505_513_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_86 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_86 = (quotient_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_86) & 127;
    }
    int stride_23 = (aux + st.buffer[1]) & 3;
    switch (stride_23) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001505_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int margin_57 = local_arr[aux % 3];
    acc = (acc + margin_57 * 2) & 127;
    int accumulator_85 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_85 > 33) {
        acc = (acc + accumulator_85 * 2 + 5) & 127;
        aux ^= (accumulator_85 & 15);
    } else {
        acc = (acc - accumulator_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int coefficient_20 = local_arr[aux % 3];
    acc = (acc + coefficient_20 * 2) & 127;
    int cursor_93 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_93 = (cursor_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_93) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001505_513_11(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int index_reg_65 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_65 > 17) {
        acc = (acc + index_reg_65 * 2 + 5) & 127;
        aux ^= (index_reg_65 & 15);
    } else {
        acc = (acc - index_reg_65 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_45 = local_arr[aux % 3];
    acc = (acc + stride_45 * 2) & 127;
    int quantum_52 = (aux + st.buffer[1]) & 3;
    switch (quantum_52) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_70 = 0;
    for (int k = 0; k < 2; k++) {
        sample_70 = (sample_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_70) & 127;
    }
    int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_75 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_75 > 36) {
        acc = (acc + sample_75 * 2 + 5) & 127;
        aux ^= (sample_75 & 15);
    } else {
        acc = (acc - sample_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_13(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_90) & 63;
    acc ^= aux;
    int sample_38 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_38 > 50) {
        acc = (acc + sample_38 * 2 + 5) & 127;
        aux ^= (sample_38 & 15);
    } else {
        acc = (acc - sample_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_14(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int offset_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_96) & 63;
    acc ^= aux;
    int phase_43 = 0;
    for (int k = 0; k < 2; k++) {
        phase_43 = (phase_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_43) & 127;
    }
    int phase_99 = (aux + st.buffer[1]) & 3;
    switch (phase_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001505_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int cursor_76 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_76 = (cursor_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_76) & 127;
    }
    int phase_31 = (aux + st.buffer[1]) & 3;
    switch (phase_31) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_16(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_13 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_13 > 23) {
        acc = (acc + margin_13 * 2 + 5) & 127;
        aux ^= (margin_13 & 15);
    } else {
        acc = (acc - margin_13 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_50) & 63;
    acc ^= aux;
    int residue_79 = (aux + st.buffer[1]) & 3;
    switch (residue_79) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int cursor_13 = local_arr[aux % 3];
    acc = (acc + cursor_13 * 2) & 127;
    int window_71 = 0;
    for (int k = 0; k < 3; k++) {
        window_71 = (window_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_71) & 127;
    }
    int stride_68 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_68 > 18) {
        acc = (acc + stride_68 * 2 + 5) & 127;
        aux ^= (stride_68 & 15);
    } else {
        acc = (acc - stride_68 + 11) & 127;
        aux += 3;
    }
    int parity_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001505_513_18(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int residue_23 = (aux + st.buffer[1]) & 3;
    switch (residue_23) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_39 = local_arr[aux % 3];
    acc = (acc + parity_39 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_82 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_82 > 41) {
        acc = (acc + quantum_82 * 2 + 5) & 127;
        aux ^= (quantum_82 & 15);
    } else {
        acc = (acc - quantum_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001505_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int scale_17 = local_arr[aux % 3];
    acc = (acc + scale_17 * 2) & 127;
    int coefficient_49 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_49 = (coefficient_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_20(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001505_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_92 = local_arr[aux % 3];
    acc = (acc + segment_92 * 2) & 127;
    int factor_51 = 0;
    for (int k = 0; k < 3; k++) {
        factor_51 = (factor_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_51) & 127;
    }
    int tracker_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001505_513_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001505_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quotient_74 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_74 > 30) {
        acc = (acc + quotient_74 * 2 + 5) & 127;
        aux ^= (quotient_74 & 15);
    } else {
        acc = (acc - quotient_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_77 = local_arr[aux % 3];
    acc = (acc + mask_77 * 2) & 127;
    int index_reg_18 = (aux + st.buffer[1]) & 3;
    switch (index_reg_18) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001505_513_22(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int metric_52 = local_arr[aux % 3];
    acc = (acc + metric_52 * 2) & 127;
    int window_38 = (st.buffer[0] * 3 + aux) & 63;
    if (window_38 > 32) {
        acc = (acc + window_38 * 2 + 5) & 127;
        aux ^= (window_38 & 15);
    } else {
        acc = (acc - window_38 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_91 = 0;
    for (int k = 0; k < 2; k++) {
        phase_91 = (phase_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001505_513_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001505_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int parity_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_32) & 63;
    acc ^= aux;
    int phase_63 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_63 > 22) {
        acc = (acc + phase_63 * 2 + 5) & 127;
        aux ^= (phase_63 & 15);
    } else {
        acc = (acc - phase_63 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001505_0;
    int sec_r001505_1;
    int sec_r001505_2;
    int sec_r001505_3;
    int sec_r001505_4;
    int sec_r001505_5;
    int sec_r001505_6;
    int sec_r001505_7;
    int sec_r001505_8;
    int sec_r001505_9;
    int sec_r001505_10;
    int sec_r001505_11;
    int sec_r001505_12;
    int sec_r001505_13;
    int sec_r001505_14;
    int sec_r001505_15;
    int sec_r001505_16;
    int sec_r001505_17;
    int pub_r001505_0;
    int pub_r001505_1;
    int pub_r001505_2;
    int pub_r001505_3;
    int pub_r001505_4;
    int pub_r001505_5;
    int pub_r001505_6;
    int pub_r001505_7;
    int pub_r001505_8;
    int pub_r001505_9;
    int pub_r001505_10;
    int pub_r001505_11;
    int pub_r001505_12;
    int pub_r001505_13;
    int pub_r001505_14;
    int pub_r001505_15;
    int pub_r001505_16;
    int pub_r001505_17;
    int pub_r001505_18;
    int pub_r001505_19;
    int pub_r001505_20;
    int pub_r001505_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001505_0 >= -100 && pub_r001505_0 <= 100);
    __CPROVER_assume(pub_r001505_1 >= -100 && pub_r001505_1 <= 100);
    __CPROVER_assume(pub_r001505_2 >= -100 && pub_r001505_2 <= 100);
    __CPROVER_assume(pub_r001505_3 >= -100 && pub_r001505_3 <= 100);
    __CPROVER_assume(pub_r001505_4 >= -100 && pub_r001505_4 <= 100);
    __CPROVER_assume(pub_r001505_5 >= -100 && pub_r001505_5 <= 100);
    __CPROVER_assume(pub_r001505_6 >= -100 && pub_r001505_6 <= 100);
    __CPROVER_assume(pub_r001505_7 >= -100 && pub_r001505_7 <= 100);
    __CPROVER_assume(pub_r001505_8 >= -100 && pub_r001505_8 <= 100);
    __CPROVER_assume(pub_r001505_9 >= -100 && pub_r001505_9 <= 100);
    __CPROVER_assume(pub_r001505_10 >= -100 && pub_r001505_10 <= 100);
    __CPROVER_assume(pub_r001505_11 >= -100 && pub_r001505_11 <= 100);
    __CPROVER_assume(pub_r001505_12 >= -100 && pub_r001505_12 <= 100);
    __CPROVER_assume(pub_r001505_13 >= -100 && pub_r001505_13 <= 100);
    __CPROVER_assume(pub_r001505_14 >= -100 && pub_r001505_14 <= 100);
    __CPROVER_assume(pub_r001505_15 >= -100 && pub_r001505_15 <= 100);
    __CPROVER_assume(pub_r001505_16 >= -100 && pub_r001505_16 <= 100);
    __CPROVER_assume(pub_r001505_17 >= -100 && pub_r001505_17 <= 100);
    __CPROVER_assume(pub_r001505_18 >= -100 && pub_r001505_18 <= 100);
    __CPROVER_assume(pub_r001505_19 >= -100 && pub_r001505_19 <= 100);
    __CPROVER_assume(pub_r001505_20 >= -100 && pub_r001505_20 <= 100);
    __CPROVER_assume(pub_r001505_21 >= -100 && pub_r001505_21 <= 100);
    __CPROVER_assume(sec_r001505_0 >= 0 && sec_r001505_0 <= 255);
    __CPROVER_assume(sec_r001505_1 >= 0 && sec_r001505_1 <= 255);
    __CPROVER_assume(sec_r001505_2 >= 0 && sec_r001505_2 <= 255);
    __CPROVER_assume(sec_r001505_3 >= 0 && sec_r001505_3 <= 255);
    __CPROVER_assume(sec_r001505_4 >= 0 && sec_r001505_4 <= 255);
    __CPROVER_assume(sec_r001505_5 >= 0 && sec_r001505_5 <= 255);
    __CPROVER_assume(sec_r001505_6 >= 0 && sec_r001505_6 <= 255);
    __CPROVER_assume(sec_r001505_7 >= 0 && sec_r001505_7 <= 255);
    __CPROVER_assume(sec_r001505_8 >= 0 && sec_r001505_8 <= 255);
    __CPROVER_assume(sec_r001505_9 >= 0 && sec_r001505_9 <= 255);
    __CPROVER_assume(sec_r001505_10 >= 0 && sec_r001505_10 <= 255);
    __CPROVER_assume(sec_r001505_11 >= 0 && sec_r001505_11 <= 255);
    __CPROVER_assume(sec_r001505_12 >= 0 && sec_r001505_12 <= 255);
    __CPROVER_assume(sec_r001505_13 >= 0 && sec_r001505_13 <= 255);
    __CPROVER_assume(sec_r001505_14 >= 0 && sec_r001505_14 <= 255);
    __CPROVER_assume(sec_r001505_15 >= 0 && sec_r001505_15 <= 255);
    __CPROVER_assume(sec_r001505_16 >= 0 && sec_r001505_16 <= 255);
    __CPROVER_assume(sec_r001505_17 >= 0 && sec_r001505_17 <= 255);

    struct SensorNode_R001505_513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001505_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001505_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001505_0 + 7) & 15;
    struct StreamBuffer_R001505_513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001505_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001505_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001505_0 + 9) & 15;
    struct EventLog_R001505_513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001505_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001505_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001505_0 + 11) & 15;

    union PacketPayload_R001505_513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001505_513_0(sec_r001505_0, pub_r001505_1, pub_r001505_2);
    int helper_flow_1 = fn_R001505_513_1(sec_r001505_1, pub_r001505_2, pub_r001505_3);
    int helper_flow_2 = fn_R001505_513_2(sec_r001505_2, sec_r001505_3, pub_r001505_4, pub_r001505_5, pub_r001505_6);
    int helper_flow_3 = fn_R001505_513_3(sec_r001505_3, sec_r001505_4);
    int helper_flow_4 = fn_R001505_513_4(sec_r001505_4, pub_r001505_5);
    int helper_flow_5 = fn_R001505_513_5(sec_r001505_5, sec_r001505_6, pub_r001505_7, pub_r001505_8, pub_r001505_9);
    int helper_flow_6 = fn_R001505_513_6(sec_r001505_6, pub_r001505_7, pub_r001505_8, pub_r001505_9, pub_r001505_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001505_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001505_16 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001505_6 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001505_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001505_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001505_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_5 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001505_5 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001505_13 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001505_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_1 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((stage_v_6 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001505_0 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_7 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001505_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_4 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001505_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001505_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001505_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001505_3 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001505_2 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001505_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001505_10 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001505_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001505_15 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001505_13 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001505_12 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001505_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001505_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_5 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001505_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_22 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_7 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001505_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_26 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001505_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001505_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_24 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001505_11 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_31 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001505_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_34 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001505_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_31 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001505_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001505_12 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001505_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_34 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_32 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_20 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_19 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001505_12 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((helper_flow_2 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001505_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_6 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_13 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_19 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_6 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_6 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001505_20 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001505_4 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_52 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001505_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_60 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001505_8 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_10 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_32 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001505_14 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001505_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001505_6 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_61 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_56 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_60 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001505_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_71 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_56 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_52 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_48 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001505_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_2 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001505_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001505_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001505_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_32 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001505_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001505_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001505_14 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_11 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_43 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001505_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_45 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001505_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001505_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001505_21 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_56 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_37 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001505_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001505_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_56 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_88 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001505_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_1 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_52 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_55 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001505_2 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001505_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_2 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_25 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001505_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_31 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001505_20 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_43 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001505_20 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_74 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_58 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_114 + 1) & 15;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001505_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_37 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_29 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001505_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001505_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001505_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001505_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((helper_flow_6 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001505_20 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001505_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_75 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001505_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001505_21 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001505_5 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_113 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001505_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001505_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001505_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_26 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001505_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001505_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001505_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_98 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001505_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001505_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_129 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001505_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001505_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001505_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001505_6 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001505_2 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001505_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((helper_flow_2 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001505_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001505_8 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001505_16 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001505_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001505_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001505_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_116 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_111 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_79 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001505_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001505_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001505_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_50 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_37 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001505_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_144 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_45 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_58 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_34 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001505_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_137 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_1 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_7 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001505_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_41 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001505_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_156 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001505_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001505_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_168 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_129 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001505_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001505_20 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_77 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_181 + 1) & 15;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001505_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_5 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001505_20 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_34 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001505_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001505_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_145 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001505_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001505_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_66 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_64 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_95 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_29 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001505_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001505_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001505_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_183 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001505_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_79 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_76 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_116 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r001505_7 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001505_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001505_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001505_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_203 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_37 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_116 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_177 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001505_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_1 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001505_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001505_21 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001505_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001505_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_212 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001505_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_144 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_150 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001505_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r001505_14 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_83 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001505_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001505_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_172 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_185 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001505_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_74 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001505_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001505_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_60 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_232 + 1) & 15;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001505_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_29 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_69 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_202 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001505_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001505_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001505_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001505_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_31 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_90 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_103 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_222 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_234 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001505_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001505_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001505_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_111 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_249 + 1) & 15;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_54 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_66 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_154 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_8 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001505_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001505_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_99 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_210 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_192 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_117 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001505_20 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_243 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_172 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001505_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001505_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001505_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001505_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001505_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_63 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_268 + 1) & 15;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_219 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001505_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001505_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((helper_flow_5 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001505_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_234 << 1) ^ (pub_r001505_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_222 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001505_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001505_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_72 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001505_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001505_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_57 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_129 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001505_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001505_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001505_21 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_223 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_10 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001505_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_87 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_145 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001505_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001505_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_29 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_67 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001505_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_150 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_50 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001505_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_48 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001505_21 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_208 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_56 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_302 + 1) & 15;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001505_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_226 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_66 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_49 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((sec_r001505_17 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_55 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001505_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001505_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001505_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001505_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001505_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_6 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001505_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_304 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_20 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001505_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001505_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r001505_5 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_170 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_6 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001505_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001505_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001505_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001505_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_137 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_57 << 1) ^ (pub_r001505_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_39 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001505_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001505_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_242 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_99 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001505_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001505_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_268 << 1) ^ (pub_r001505_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_244 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_161 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_268 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001505_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_208 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001505_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001505_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001505_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_274 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_43 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001505_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001505_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_8 << 1) ^ (pub_r001505_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_172 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001505_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((helper_flow_0 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_352 + 1) & 15;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001505_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_37 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001505_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_268 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001505_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001505_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_317 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_346 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_149 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_12 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_362 + 1) & 15;
    out_sink ^= (stage_v_362 & 63);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_193 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_222 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001505_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_144 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_259 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001505_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_168 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_71 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001505_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((sec_r001505_17 << 1) ^ (pub_r001505_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_75 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001505_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_67 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_297 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001505_20 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_43 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001505_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_74 << 1) ^ (pub_r001505_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_144 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001505_20 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001505_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_74 << 1) ^ (pub_r001505_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001505_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_268 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_164 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_191 << 1) ^ (pub_r001505_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_275 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_200 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_217 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001505_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_88 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_314 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001505_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_387 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001505_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((sec_r001505_6 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_398 + 1) & 15;
    out_sink ^= (stage_v_398 & 63);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_57 << 1) ^ (pub_r001505_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_320 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_107 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_257 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_39 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001505_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_174 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((sec_r001505_0 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_217 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_281 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_232 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001505_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((helper_flow_1 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_116 << 1) ^ (pub_r001505_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001505_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001505_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001505_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_181 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001505_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_223 << 1) ^ (pub_r001505_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_90 << 1) ^ (pub_r001505_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001505_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001505_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001505_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001505_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_145 << 1) ^ (pub_r001505_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001505_19 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_399 << 1) ^ (pub_r001505_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001505_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_201 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_253 << 1) ^ (pub_r001505_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001505_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_10 << 1) ^ (pub_r001505_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001505_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_137 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001505_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001505_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001505_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001505_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001505_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001505_20 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_433 << 1) ^ (pub_r001505_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_440 + 1) & 15;
    out_sink ^= (stage_v_440 & 63);

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001505_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_375 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_11 << 1) ^ (pub_r001505_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_338 << 1) ^ (pub_r001505_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_322 << 1) ^ (pub_r001505_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_390 << 1) ^ (pub_r001505_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_361 << 1) ^ (pub_r001505_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_304 << 1) ^ (pub_r001505_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_74 << 1) ^ (pub_r001505_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_150 << 1) ^ (pub_r001505_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001505_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
