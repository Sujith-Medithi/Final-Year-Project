/*
 * Benchmark Program: R001436
 * Security Family: implicit_flow
 * Generator Seed: 643613
 * High Inputs: 20 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001436_3613_0 {
    short state;
    int capacity;
    int head;
    int buffer[3];
};

struct AudioFrame_R001436_3613_1 {
    unsigned char envelope;
    unsigned char peak;
    unsigned char sample_rate;
    int buffer[3];
};

union PacketPayload_R001436_3613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001436_3613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001436_3613_0(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int parity_88 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_88 > 16) {
        acc = (acc + parity_88 * 2 + 5) & 127;
        aux ^= (parity_88 & 15);
    } else {
        acc = (acc - parity_88 + 11) & 127;
        aux += 3;
    }
    int damping_16 = (aux + st.buffer[1]) & 3;
    switch (damping_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_1(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int accumulator_89 = local_arr[aux % 3];
    acc = (acc + accumulator_89 * 2) & 127;
    int margin_28 = (aux + st.buffer[1]) & 3;
    switch (margin_28) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001436_3613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int scale_70 = 0;
    for (int k = 0; k < 3; k++) {
        scale_70 = (scale_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_70) & 127;
    }
    int parity_37 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_37 > 21) {
        acc = (acc + parity_37 * 2 + 5) & 127;
        aux ^= (parity_37 & 15);
    } else {
        acc = (acc - parity_37 + 11) & 127;
        aux += 3;
    }
    int threshold_22 = (aux + st.buffer[1]) & 3;
    switch (threshold_22) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001436_3613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int window_78 = 0;
    for (int k = 0; k < 3; k++) {
        window_78 = (window_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_78) & 127;
    }
    int tracker_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_11) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_54 = local_arr[aux % 3];
    acc = (acc + anchor_54 * 2) & 127;
    int damping_32 = (aux + st.buffer[1]) & 3;
    switch (damping_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_70 = local_arr[aux % 3];
    acc = (acc + delta_70 * 2) & 127;
    int tally_84 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_84 > 19) {
        acc = (acc + tally_84 * 2 + 5) & 127;
        aux ^= (tally_84 & 15);
    } else {
        acc = (acc - tally_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quantum_60 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_60 = (quantum_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_60) & 127;
    }
    int anchor_26 = (aux + st.buffer[1]) & 3;
    switch (anchor_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_6(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tracker_88 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_88 = (tracker_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_88) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_85 = local_arr[aux % 3];
    acc = (acc + residue_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001436_3613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tally_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_13) & 63;
    acc ^= aux;
    int sample_31 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_31 > 28) {
        acc = (acc + sample_31 * 2 + 5) & 127;
        aux ^= (sample_31 & 15);
    } else {
        acc = (acc - sample_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_86 = local_arr[aux % 3];
    acc = (acc + coefficient_86 * 2) & 127;
    int offset_41 = 0;
    for (int k = 0; k < 2; k++) {
        offset_41 = (offset_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_41) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int coefficient_47 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_47 > 17) {
        acc = (acc + coefficient_47 * 2 + 5) & 127;
        aux ^= (coefficient_47 & 15);
    } else {
        acc = (acc - coefficient_47 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001436_3613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int index_reg_16 = local_arr[aux % 3];
    acc = (acc + index_reg_16 * 2) & 127;
    int residue_86 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_86 > 46) {
        acc = (acc + residue_86 * 2 + 5) & 127;
        aux ^= (residue_86 & 15);
    } else {
        acc = (acc - residue_86 + 11) & 127;
        aux += 3;
    }
    int index_reg_53 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_53 = (index_reg_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_53) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001436_3613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int accumulator_53 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_53 > 50) {
        acc = (acc + accumulator_53 * 2 + 5) & 127;
        aux ^= (accumulator_53 & 15);
    } else {
        acc = (acc - accumulator_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_21) & 63;
    acc ^= aux;
    int quotient_93 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_93 = (quotient_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_11(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int segment_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_87 = 0;
    for (int k = 0; k < 2; k++) {
        vector_87 = (vector_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_87) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_12(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int delta_74 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_74 > 33) {
        acc = (acc + delta_74 * 2 + 5) & 127;
        aux ^= (delta_74 & 15);
    } else {
        acc = (acc - delta_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_67 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_67 = (quotient_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_13(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int damping_80 = (aux + st.buffer[1]) & 3;
    switch (damping_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_90 = 0;
    for (int k = 0; k < 2; k++) {
        phase_90 = (phase_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_14(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int pivot_55 = (aux + st.buffer[1]) & 3;
    switch (pivot_55) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_69 = 0;
    for (int k = 0; k < 2; k++) {
        offset_69 = (offset_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_69) & 127;
    }
    int quantum_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_87) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_60 = local_arr[aux % 3];
    acc = (acc + scale_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001436_3613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_21 = 0;
    for (int k = 0; k < 2; k++) {
        factor_21 = (factor_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_21) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001436_3613_16(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_71) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_54 = local_arr[aux % 3];
    acc = (acc + weight_54 * 2) & 127;
    int stride_47 = 0;
    for (int k = 0; k < 2; k++) {
        stride_47 = (stride_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_47) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001436_3613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_10 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_10 = (threshold_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_10) & 127;
    }
    int tally_36 = (aux + st.buffer[1]) & 3;
    switch (tally_36) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001436_3613_18(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001436_3613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001436_0;
    int sec_r001436_1;
    int sec_r001436_2;
    int sec_r001436_3;
    int sec_r001436_4;
    int sec_r001436_5;
    int sec_r001436_6;
    int sec_r001436_7;
    int sec_r001436_8;
    int sec_r001436_9;
    int sec_r001436_10;
    int sec_r001436_11;
    int sec_r001436_12;
    int sec_r001436_13;
    int sec_r001436_14;
    int sec_r001436_15;
    int sec_r001436_16;
    int sec_r001436_17;
    int sec_r001436_18;
    int sec_r001436_19;
    int pub_r001436_0;
    int pub_r001436_1;
    int pub_r001436_2;
    int pub_r001436_3;
    int pub_r001436_4;
    int pub_r001436_5;
    int pub_r001436_6;
    int pub_r001436_7;
    int pub_r001436_8;
    int pub_r001436_9;
    int pub_r001436_10;
    int pub_r001436_11;
    int pub_r001436_12;
    int pub_r001436_13;
    int pub_r001436_14;
    int pub_r001436_15;
    int pub_r001436_16;
    int pub_r001436_17;
    int pub_r001436_18;
    int pub_r001436_19;
    int pub_r001436_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001436_0 >= -100 && pub_r001436_0 <= 100);
    __CPROVER_assume(pub_r001436_1 >= -100 && pub_r001436_1 <= 100);
    __CPROVER_assume(pub_r001436_2 >= -100 && pub_r001436_2 <= 100);
    __CPROVER_assume(pub_r001436_3 >= -100 && pub_r001436_3 <= 100);
    __CPROVER_assume(pub_r001436_4 >= -100 && pub_r001436_4 <= 100);
    __CPROVER_assume(pub_r001436_5 >= -100 && pub_r001436_5 <= 100);
    __CPROVER_assume(pub_r001436_6 >= -100 && pub_r001436_6 <= 100);
    __CPROVER_assume(pub_r001436_7 >= -100 && pub_r001436_7 <= 100);
    __CPROVER_assume(pub_r001436_8 >= -100 && pub_r001436_8 <= 100);
    __CPROVER_assume(pub_r001436_9 >= -100 && pub_r001436_9 <= 100);
    __CPROVER_assume(pub_r001436_10 >= -100 && pub_r001436_10 <= 100);
    __CPROVER_assume(pub_r001436_11 >= -100 && pub_r001436_11 <= 100);
    __CPROVER_assume(pub_r001436_12 >= -100 && pub_r001436_12 <= 100);
    __CPROVER_assume(pub_r001436_13 >= -100 && pub_r001436_13 <= 100);
    __CPROVER_assume(pub_r001436_14 >= -100 && pub_r001436_14 <= 100);
    __CPROVER_assume(pub_r001436_15 >= -100 && pub_r001436_15 <= 100);
    __CPROVER_assume(pub_r001436_16 >= -100 && pub_r001436_16 <= 100);
    __CPROVER_assume(pub_r001436_17 >= -100 && pub_r001436_17 <= 100);
    __CPROVER_assume(pub_r001436_18 >= -100 && pub_r001436_18 <= 100);
    __CPROVER_assume(pub_r001436_19 >= -100 && pub_r001436_19 <= 100);
    __CPROVER_assume(pub_r001436_20 >= -100 && pub_r001436_20 <= 100);
    __CPROVER_assume(sec_r001436_0 >= 0 && sec_r001436_0 <= 255);
    __CPROVER_assume(sec_r001436_1 >= 0 && sec_r001436_1 <= 255);
    __CPROVER_assume(sec_r001436_2 >= 0 && sec_r001436_2 <= 255);
    __CPROVER_assume(sec_r001436_3 >= 0 && sec_r001436_3 <= 255);
    __CPROVER_assume(sec_r001436_4 >= 0 && sec_r001436_4 <= 255);
    __CPROVER_assume(sec_r001436_5 >= 0 && sec_r001436_5 <= 255);
    __CPROVER_assume(sec_r001436_6 >= 0 && sec_r001436_6 <= 255);
    __CPROVER_assume(sec_r001436_7 >= 0 && sec_r001436_7 <= 255);
    __CPROVER_assume(sec_r001436_8 >= 0 && sec_r001436_8 <= 255);
    __CPROVER_assume(sec_r001436_9 >= 0 && sec_r001436_9 <= 255);
    __CPROVER_assume(sec_r001436_10 >= 0 && sec_r001436_10 <= 255);
    __CPROVER_assume(sec_r001436_11 >= 0 && sec_r001436_11 <= 255);
    __CPROVER_assume(sec_r001436_12 >= 0 && sec_r001436_12 <= 255);
    __CPROVER_assume(sec_r001436_13 >= 0 && sec_r001436_13 <= 255);
    __CPROVER_assume(sec_r001436_14 >= 0 && sec_r001436_14 <= 255);
    __CPROVER_assume(sec_r001436_15 >= 0 && sec_r001436_15 <= 255);
    __CPROVER_assume(sec_r001436_16 >= 0 && sec_r001436_16 <= 255);
    __CPROVER_assume(sec_r001436_17 >= 0 && sec_r001436_17 <= 255);
    __CPROVER_assume(sec_r001436_18 >= 0 && sec_r001436_18 <= 255);
    __CPROVER_assume(sec_r001436_19 >= 0 && sec_r001436_19 <= 255);

    struct StreamBuffer_R001436_3613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001436_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001436_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001436_0 + 7) & 15;
    struct AudioFrame_R001436_3613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001436_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001436_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001436_0 + 9) & 15;

    union PacketPayload_R001436_3613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001436_3613_0(sec_r001436_0, sec_r001436_1);
    int helper_flow_1 = fn_R001436_3613_1(sec_r001436_1, pub_r001436_2, pub_r001436_3);
    int helper_flow_2 = fn_R001436_3613_2(sec_r001436_2, sec_r001436_3, pub_r001436_4, pub_r001436_5);
    int helper_flow_3 = fn_R001436_3613_3(sec_r001436_3, pub_r001436_4, pub_r001436_5, pub_r001436_6);
    int helper_flow_4 = fn_R001436_3613_4(sec_r001436_4, pub_r001436_5, pub_r001436_6, pub_r001436_7, pub_r001436_8);
    int helper_flow_5 = fn_R001436_3613_5(sec_r001436_5, pub_r001436_6, pub_r001436_7, pub_r001436_8, pub_r001436_9);
    int helper_flow_6 = fn_R001436_3613_6(sec_r001436_6, sec_r001436_7);
    int helper_flow_7 = fn_R001436_3613_7(sec_r001436_7, sec_r001436_8, pub_r001436_9, pub_r001436_10);
    int helper_flow_8 = fn_R001436_3613_8(sec_r001436_8, pub_r001436_9, pub_r001436_10, pub_r001436_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_3 + pub_r001436_7 * 2 + 5) & 127;
    if (stage_v_0 > 21) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_0 + pub_r001436_3 * 2 + 8) & 127;
    if (stage_v_1 > 29) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001436_12 + pub_r001436_17 * 2 + 11) & 127;
    if (stage_v_2 > 33) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001436_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001436_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_7 + pub_r001436_13 * 2 + 20) & 127;
    if (stage_v_5 > 22) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001436_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_1 + pub_r001436_7 * 2 + 26) & 127;
    if (stage_v_7 > 42) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_1 + pub_r001436_18 * 2 + 29) & 127;
    if (stage_v_8 > 46) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001436_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001436_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_8 + pub_r001436_18 * 2 + 38) & 127;
    if (stage_v_11 > 20) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_4 + pub_r001436_10 * 2 + 41) & 127;
    if (stage_v_12 > 56) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001436_2 + pub_r001436_20 * 2 + 44) & 127;
    if (stage_v_13 > 30) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_5 + pub_r001436_1 * 2 + 47) & 127;
    if (stage_v_14 > 27) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001436_16 + pub_r001436_19 * 2 + 50) & 127;
    if (stage_v_15 > 20) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001436_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001436_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001436_9 + pub_r001436_4 * 2 + 59) & 127;
    if (stage_v_18 > 33) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001436_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001436_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_8 + pub_r001436_19 * 2 + 68) & 127;
    if (stage_v_21 > 24) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001436_19 + pub_r001436_12 * 2 + 71) & 127;
    if (stage_v_22 > 58) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001436_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001436_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001436_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001436_9 + pub_r001436_19 * 2 + 83) & 127;
    if (stage_v_26 > 40) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001436_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001436_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001436_6 + pub_r001436_16 * 2 + 92) & 127;
    if (stage_v_29 > 46) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001436_9 + pub_r001436_16 * 2 + 95) & 127;
    if (stage_v_30 > 25) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001436_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_18 + pub_r001436_12 * 2 + 101) & 127;
    if (stage_v_32 > 50) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001436_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_15 + pub_r001436_2 * 2 + 107) & 127;
    if (stage_v_34 > 17) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001436_14 + pub_r001436_16 * 2 + 110) & 127;
    if (stage_v_35 > 36) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001436_11 + pub_r001436_17 * 2 + 113) & 127;
    if (stage_v_36 > 48) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001436_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001436_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001436_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001436_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001436_17 + pub_r001436_18 * 2 + 128) & 127;
    if (stage_v_41 > 45) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_2 + pub_r001436_8 * 2 + 131) & 127;
    if (stage_v_42 > 38) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_1 + pub_r001436_15 * 2 + 134) & 127;
    if (stage_v_43 > 53) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_36 + pub_r001436_18 * 2 + 137) & 127;
    if (stage_v_44 > 55) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001436_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_44 + pub_r001436_9 * 2 + 143) & 127;
    if (stage_v_46 > 27) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_32 + pub_r001436_11 * 2 + 146) & 127;
    if (stage_v_47 > 20) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_7 + pub_r001436_10 * 2 + 149) & 127;
    if (stage_v_48 > 21) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_2 + pub_r001436_14 * 2 + 152) & 127;
    if (stage_v_49 > 56) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001436_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001436_11 + pub_r001436_14 * 2 + 158) & 127;
    if (stage_v_51 > 59) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001436_10 + pub_r001436_15 * 2 + 161) & 127;
    if (stage_v_52 > 58) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001436_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001436_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (helper_flow_7 + pub_r001436_13 * 2 + 170) & 127;
    if (stage_v_55 > 51) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (helper_flow_8 + pub_r001436_13 * 2 + 173) & 127;
    if (stage_v_56 > 34) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001436_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001436_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001436_8 + pub_r001436_16 * 2 + 182) & 127;
    if (stage_v_59 > 33) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (helper_flow_1 + pub_r001436_5 * 2 + 185) & 127;
    if (stage_v_60 > 30) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_48 + pub_r001436_19 * 2 + 188) & 127;
    if (stage_v_61 > 25) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_35 + pub_r001436_10 * 2 + 191) & 127;
    if (stage_v_62 > 32) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001436_15 + pub_r001436_16 * 2 + 194) & 127;
    if (stage_v_63 > 24) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_12 + pub_r001436_19 * 2 + 197) & 127;
    if (stage_v_64 > 17) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001436_3 + pub_r001436_5 * 2 + 200) & 127;
    if (stage_v_65 > 52) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001436_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001436_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_14 + pub_r001436_18 * 2 + 209) & 127;
    if (stage_v_68 > 59) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001436_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001436_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001436_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001436_16 + pub_r001436_8 * 2 + 221) & 127;
    if (stage_v_72 > 22) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001436_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001436_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001436_15 + pub_r001436_1 * 2 + 230) & 127;
    if (stage_v_75 > 19) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001436_2 + pub_r001436_1 * 2 + 233) & 127;
    if (stage_v_76 > 43) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_1 + pub_r001436_16 * 2 + 236) & 127;
    if (stage_v_77 > 24) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_43 + pub_r001436_5 * 2 + 239) & 127;
    if (stage_v_78 > 21) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001436_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_55 + pub_r001436_16 * 2 + 245) & 127;
    if (stage_v_80 > 51) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_49 + pub_r001436_7 * 2 + 248) & 127;
    if (stage_v_81 > 50) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001436_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001436_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001436_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001436_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001436_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001436_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_30 + pub_r001436_10 * 2 + 269) & 127;
    if (stage_v_88 > 30) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001436_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r001436_12 + pub_r001436_18 * 2 + 275) & 127;
    if (stage_v_90 > 23) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001436_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001436_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_36 + pub_r001436_3 * 2 + 284) & 127;
    if (stage_v_93 > 49) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_47 + pub_r001436_1 * 2 + 287) & 127;
    if (stage_v_94 > 20) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001436_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001436_19 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_60 + pub_r001436_8 * 2 + 296) & 127;
    if (stage_v_97 > 55) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_12 + pub_r001436_0 * 2 + 299) & 127;
    if (stage_v_98 > 55) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001436_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001436_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001436_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_97 + pub_r001436_12 * 2 + 311) & 127;
    if (stage_v_102 > 56) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001436_2 + pub_r001436_11 * 2 + 314) & 127;
    if (stage_v_103 > 58) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001436_4 + pub_r001436_3 * 2 + 317) & 127;
    if (stage_v_104 > 28) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001436_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_32 + pub_r001436_14 * 2 + 323) & 127;
    if (stage_v_106 > 19) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_93 + pub_r001436_12 * 2 + 326) & 127;
    if (stage_v_107 > 45) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001436_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_104 + pub_r001436_1 * 2 + 332) & 127;
    if (stage_v_109 > 34) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (sec_r001436_9 + pub_r001436_9 * 2 + 335) & 127;
    if (stage_v_110 > 60) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_41 + pub_r001436_15 * 2 + 338) & 127;
    if (stage_v_111 > 22) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001436_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001436_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001436_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_1 + pub_r001436_19 * 2 + 350) & 127;
    if (stage_v_115 > 48) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_64 + pub_r001436_19 * 2 + 353) & 127;
    if (stage_v_116 > 54) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_42 + pub_r001436_3 * 2 + 356) & 127;
    if (stage_v_117 > 42) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001436_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001436_16 + pub_r001436_10 * 2 + 362) & 127;
    if (stage_v_119 > 58) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001436_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_88 + pub_r001436_5 * 2 + 368) & 127;
    if (stage_v_121 > 60) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_8 + pub_r001436_11 * 2 + 371) & 127;
    if (stage_v_122 > 43) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_15 + pub_r001436_6 * 2 + 374) & 127;
    if (stage_v_123 > 51) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_93 + pub_r001436_8 * 2 + 377) & 127;
    if (stage_v_124 > 33) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001436_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001436_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001436_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_35 + pub_r001436_2 * 2 + 389) & 127;
    if (stage_v_128 > 41) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_21 + pub_r001436_1 * 2 + 392) & 127;
    if (stage_v_129 > 28) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_109 + pub_r001436_15 * 2 + 395) & 127;
    if (stage_v_130 > 59) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001436_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001436_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r001436_13 + pub_r001436_6 * 2 + 404) & 127;
    if (stage_v_133 > 29) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_123 + pub_r001436_9 * 2 + 407) & 127;
    if (stage_v_134 > 50) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_30 + pub_r001436_13 * 2 + 410) & 127;
    if (stage_v_135 > 55) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (helper_flow_2 + pub_r001436_5 * 2 + 413) & 127;
    if (stage_v_136 > 22) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001436_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001436_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001436_19 + pub_r001436_3 * 2 + 422) & 127;
    if (stage_v_139 > 29) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_15 + pub_r001436_19 * 2 + 425) & 127;
    if (stage_v_140 > 46) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001436_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001436_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_14 + pub_r001436_18 * 2 + 434) & 127;
    if (stage_v_143 > 28) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r001436_2 + pub_r001436_2 * 2 + 437) & 127;
    if (stage_v_144 > 43) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_88 + pub_r001436_2 * 2 + 440) & 127;
    if (stage_v_145 > 33) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001436_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001436_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001436_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001436_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_63 + pub_r001436_12 * 2 + 455) & 127;
    if (stage_v_150 > 33) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001436_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_78 + pub_r001436_20 * 2 + 461) & 127;
    if (stage_v_152 > 44) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_109 + pub_r001436_14 * 2 + 464) & 127;
    if (stage_v_153 > 35) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r001436_15 + pub_r001436_7 * 2 + 467) & 127;
    if (stage_v_154 > 31) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001436_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_72 + pub_r001436_18 * 2 + 473) & 127;
    if (stage_v_156 > 35) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_152 + pub_r001436_8 * 2 + 476) & 127;
    if (stage_v_157 > 42) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_62 + pub_r001436_5 * 2 + 479) & 127;
    if (stage_v_158 > 19) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_140 + pub_r001436_19 * 2 + 482) & 127;
    if (stage_v_159 > 29) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001436_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001436_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_140 + pub_r001436_7 * 2 + 491) & 127;
    if (stage_v_162 > 44) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001436_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_76 + pub_r001436_20 * 2 + 497) & 127;
    if (stage_v_164 > 29) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_55 + pub_r001436_13 * 2 + 500) & 127;
    if (stage_v_165 > 26) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_154 + pub_r001436_2 * 2 + 503) & 127;
    if (stage_v_166 > 37) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_164 + pub_r001436_14 * 2 + 506) & 127;
    if (stage_v_167 > 31) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_162 + pub_r001436_15 * 2 + 509) & 127;
    if (stage_v_168 > 43) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_124 + pub_r001436_2 * 2 + 512) & 127;
    if (stage_v_169 > 33) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_134 + pub_r001436_11 * 2 + 515) & 127;
    if (stage_v_170 > 29) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001436_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_12 + pub_r001436_15 * 2 + 521) & 127;
    if (stage_v_172 > 44) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_145 + pub_r001436_4 * 2 + 524) & 127;
    if (stage_v_173 > 42) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001436_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (helper_flow_5 + pub_r001436_15 * 2 + 530) & 127;
    if (stage_v_175 > 29) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_165 + pub_r001436_1 * 2 + 533) & 127;
    if (stage_v_176 > 40) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_94 + pub_r001436_2 * 2 + 536) & 127;
    if (stage_v_177 > 38) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001436_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_145 + pub_r001436_7 * 2 + 542) & 127;
    if (stage_v_179 > 16) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_123 + pub_r001436_20 * 2 + 545) & 127;
    if (stage_v_180 > 30) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_167 + pub_r001436_19 * 2 + 548) & 127;
    if (stage_v_181 > 28) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (sec_r001436_17 + pub_r001436_5 * 2 + 551) & 127;
    if (stage_v_182 > 53) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_98 + pub_r001436_19 * 2 + 554) & 127;
    if (stage_v_183 > 23) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_49 + pub_r001436_14 * 2 + 557) & 127;
    if (stage_v_184 > 49) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_166 + pub_r001436_19 * 2 + 560) & 127;
    if (stage_v_185 > 41) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_41 + pub_r001436_11 * 2 + 563) & 127;
    if (stage_v_186 > 43) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001436_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001436_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_130 + pub_r001436_3 * 2 + 572) & 127;
    if (stage_v_189 > 16) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001436_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001436_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (sec_r001436_4 + pub_r001436_14 * 2 + 581) & 127;
    if (stage_v_192 > 52) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_46 + pub_r001436_5 * 2 + 584) & 127;
    if (stage_v_193 > 27) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_168 + pub_r001436_8 * 2 + 587) & 127;
    if (stage_v_194 > 19) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001436_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_104 + pub_r001436_4 * 2 + 593) & 127;
    if (stage_v_196 > 44) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001436_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_196 + pub_r001436_14 * 2 + 599) & 127;
    if (stage_v_198 > 37) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_26 + pub_r001436_0 * 2 + 602) & 127;
    if (stage_v_199 > 60) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001436_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_136 + pub_r001436_7 * 2 + 608) & 127;
    if (stage_v_201 > 38) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_75 + pub_r001436_0 * 2 + 611) & 127;
    if (stage_v_202 > 48) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001436_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_115 + pub_r001436_10 * 2 + 617) & 127;
    if (stage_v_204 > 19) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_152 + pub_r001436_3 * 2 + 620) & 127;
    if (stage_v_205 > 34) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001436_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_204 + pub_r001436_16 * 2 + 626) & 127;
    if (stage_v_207 > 54) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (sec_r001436_2 + pub_r001436_20 * 2 + 629) & 127;
    if (stage_v_208 > 17) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_22 + pub_r001436_5 * 2 + 632) & 127;
    if (stage_v_209 > 54) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (sec_r001436_19 + pub_r001436_3 * 2 + 635) & 127;
    if (stage_v_210 > 31) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (helper_flow_0 + pub_r001436_20 * 2 + 638) & 127;
    if (stage_v_211 > 41) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001436_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (sec_r001436_15 + pub_r001436_3 * 2 + 644) & 127;
    if (stage_v_213 > 20) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_179 + pub_r001436_15 * 2 + 647) & 127;
    if (stage_v_214 > 50) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_35 + pub_r001436_10 * 2 + 650) & 127;
    if (stage_v_215 > 57) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_7 + pub_r001436_7 * 2 + 653) & 127;
    if (stage_v_216 > 52) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_152 + pub_r001436_9 * 2 + 656) & 127;
    if (stage_v_217 > 27) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_167 + pub_r001436_12 * 2 + 659) & 127;
    if (stage_v_218 > 19) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_0 + pub_r001436_7 * 2 + 662) & 127;
    if (stage_v_219 > 19) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_41 + pub_r001436_19 * 2 + 665) & 127;
    if (stage_v_220 > 45) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_192 + pub_r001436_12 * 2 + 668) & 127;
    if (stage_v_221 > 21) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_60 + pub_r001436_8 * 2 + 671) & 127;
    if (stage_v_222 > 38) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_26 + pub_r001436_0 * 2 + 674) & 127;
    if (stage_v_223 > 22) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (sec_r001436_14 + pub_r001436_12 * 2 + 677) & 127;
    if (stage_v_224 > 26) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_88 + pub_r001436_4 * 2 + 680) & 127;
    if (stage_v_225 > 50) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_107 + pub_r001436_0 * 2 + 683) & 127;
    if (stage_v_226 > 23) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_2 + pub_r001436_18 * 2 + 686) & 127;
    if (stage_v_227 > 28) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_90 + pub_r001436_4 * 2 + 689) & 127;
    if (stage_v_228 > 46) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_201 + pub_r001436_11 * 2 + 692) & 127;
    if (stage_v_229 > 42) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
