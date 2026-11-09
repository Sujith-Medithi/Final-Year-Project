/*
 * Benchmark Program: R001108
 * Security Family: secret_dependent_loops
 * Generator Seed: 610813
 * High Inputs: 20 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001108_813_0 {
    int peak;
    short channels;
    short gain;
    int rms;
    int buffer[3];
};

struct StreamBuffer_R001108_813_1 {
    int state;
    unsigned char capacity;
    int checksum;
    short watermark;
    unsigned char head;
    int buffer[3];
};

struct MatrixBlock_R001108_813_2 {
    int dim;
    int stride;
    unsigned char determinant;
    int buffer[3];
};

union RegisterBank_R001108_813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001108_813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001108_813_0(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_93 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_93 > 10) {
        acc = (acc + accumulator_93 * 2 + 5) & 127;
        aux ^= (accumulator_93 & 15);
    } else {
        acc = (acc - accumulator_93 + 11) & 127;
        aux += 3;
    }
    int index_reg_73 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_73 = (index_reg_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_73) & 127;
    }
    int stride_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_68) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_1(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int delta_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_38) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_2(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int scale_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_71) & 63;
    acc ^= aux;
    int delta_57 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_57 > 48) {
        acc = (acc + delta_57 * 2 + 5) & 127;
        aux ^= (delta_57 & 15);
    } else {
        acc = (acc - delta_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001108_813_3(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001108_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tracker_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_11) & 63;
    acc ^= aux;
    int index_reg_41 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_41 > 11) {
        acc = (acc + index_reg_41 * 2 + 5) & 127;
        aux ^= (index_reg_41 & 15);
    } else {
        acc = (acc - index_reg_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001108_813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_11 = (aux + st.buffer[1]) & 3;
    switch (stride_11) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_63 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_63 > 35) {
        acc = (acc + offset_63 * 2 + 5) & 127;
        aux ^= (offset_63 & 15);
    } else {
        acc = (acc - offset_63 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_54 = local_arr[aux % 3];
    acc = (acc + delta_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_5(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int segment_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_16) & 63;
    acc ^= aux;
    int metric_32 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_32 > 18) {
        acc = (acc + metric_32 * 2 + 5) & 127;
        aux ^= (metric_32 & 15);
    } else {
        acc = (acc - metric_32 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int scale_36 = 0;
    for (int k = 0; k < 2; k++) {
        scale_36 = (scale_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_36) & 127;
    }
    int scale_85 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_85 > 24) {
        acc = (acc + scale_85 * 2 + 5) & 127;
        aux ^= (scale_85 & 15);
    } else {
        acc = (acc - scale_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_61 = local_arr[aux % 3];
    acc = (acc + checksum_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_7(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001108_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_13 = (aux + st.buffer[1]) & 3;
    switch (margin_13) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_71 = 0;
    for (int k = 0; k < 3; k++) {
        phase_71 = (phase_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001108_813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_26 = local_arr[aux % 3];
    acc = (acc + tracker_26 * 2) & 127;
    int quantum_40 = (aux + st.buffer[1]) & 3;
    switch (quantum_40) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_21 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_21 = (quantum_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001108_813_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001108_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_70 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_70 > 38) {
        acc = (acc + metric_70 * 2 + 5) & 127;
        aux ^= (metric_70 & 15);
    } else {
        acc = (acc - metric_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_92 = (aux + st.buffer[1]) & 3;
    switch (quantum_92) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_71 = local_arr[aux % 3];
    acc = (acc + anchor_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_10(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int weight_79 = (aux + st.buffer[1]) & 3;
    switch (weight_79) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_51 = local_arr[aux % 3];
    acc = (acc + tally_51 * 2) & 127;
    int anchor_77 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_77 = (anchor_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_77) & 127;
    }
    int quotient_97 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_97 > 45) {
        acc = (acc + quotient_97 * 2 + 5) & 127;
        aux ^= (quotient_97 & 15);
    } else {
        acc = (acc - quotient_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001108_813_11(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001108_813_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001108_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_52 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_52 = (pivot_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_52) & 127;
    }
    int tally_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_88) & 63;
    acc ^= aux;
    int residue_78 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_78 > 47) {
        acc = (acc + residue_78 * 2 + 5) & 127;
        aux ^= (residue_78 & 15);
    } else {
        acc = (acc - residue_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001108_813_13(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_36 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_36 = (checksum_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_36) & 127;
    }
    int vector_41 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_41 > 16) {
        acc = (acc + vector_41 * 2 + 5) & 127;
        aux ^= (vector_41 & 15);
    } else {
        acc = (acc - vector_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_14(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001108_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_54) & 63;
    acc ^= aux;
    int delta_64 = (aux + st.buffer[1]) & 3;
    switch (delta_64) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_27 = 0;
    for (int k = 0; k < 3; k++) {
        vector_27 = (vector_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_27) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001108_813_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001108_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quotient_25 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_25 = (quotient_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_25) & 127;
    }
    int margin_26 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_26 > 47) {
        acc = (acc + margin_26 * 2 + 5) & 127;
        aux ^= (margin_26 & 15);
    } else {
        acc = (acc - margin_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001108_0;
    int sec_r001108_1;
    int sec_r001108_2;
    int sec_r001108_3;
    int sec_r001108_4;
    int sec_r001108_5;
    int sec_r001108_6;
    int sec_r001108_7;
    int sec_r001108_8;
    int sec_r001108_9;
    int sec_r001108_10;
    int sec_r001108_11;
    int sec_r001108_12;
    int sec_r001108_13;
    int sec_r001108_14;
    int sec_r001108_15;
    int sec_r001108_16;
    int sec_r001108_17;
    int sec_r001108_18;
    int sec_r001108_19;
    int pub_r001108_0;
    int pub_r001108_1;
    int pub_r001108_2;
    int pub_r001108_3;
    int pub_r001108_4;
    int pub_r001108_5;
    int pub_r001108_6;
    int pub_r001108_7;
    int pub_r001108_8;
    int pub_r001108_9;
    int pub_r001108_10;
    int pub_r001108_11;
    int pub_r001108_12;
    int pub_r001108_13;
    int pub_r001108_14;
    int pub_r001108_15;
    int pub_r001108_16;
    int pub_r001108_17;
    int pub_r001108_18;
    int pub_r001108_19;
    int pub_r001108_20;
    int pub_r001108_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001108_0 >= -100 && pub_r001108_0 <= 100);
    __CPROVER_assume(pub_r001108_1 >= -100 && pub_r001108_1 <= 100);
    __CPROVER_assume(pub_r001108_2 >= -100 && pub_r001108_2 <= 100);
    __CPROVER_assume(pub_r001108_3 >= -100 && pub_r001108_3 <= 100);
    __CPROVER_assume(pub_r001108_4 >= -100 && pub_r001108_4 <= 100);
    __CPROVER_assume(pub_r001108_5 >= -100 && pub_r001108_5 <= 100);
    __CPROVER_assume(pub_r001108_6 >= -100 && pub_r001108_6 <= 100);
    __CPROVER_assume(pub_r001108_7 >= -100 && pub_r001108_7 <= 100);
    __CPROVER_assume(pub_r001108_8 >= -100 && pub_r001108_8 <= 100);
    __CPROVER_assume(pub_r001108_9 >= -100 && pub_r001108_9 <= 100);
    __CPROVER_assume(pub_r001108_10 >= -100 && pub_r001108_10 <= 100);
    __CPROVER_assume(pub_r001108_11 >= -100 && pub_r001108_11 <= 100);
    __CPROVER_assume(pub_r001108_12 >= -100 && pub_r001108_12 <= 100);
    __CPROVER_assume(pub_r001108_13 >= -100 && pub_r001108_13 <= 100);
    __CPROVER_assume(pub_r001108_14 >= -100 && pub_r001108_14 <= 100);
    __CPROVER_assume(pub_r001108_15 >= -100 && pub_r001108_15 <= 100);
    __CPROVER_assume(pub_r001108_16 >= -100 && pub_r001108_16 <= 100);
    __CPROVER_assume(pub_r001108_17 >= -100 && pub_r001108_17 <= 100);
    __CPROVER_assume(pub_r001108_18 >= -100 && pub_r001108_18 <= 100);
    __CPROVER_assume(pub_r001108_19 >= -100 && pub_r001108_19 <= 100);
    __CPROVER_assume(pub_r001108_20 >= -100 && pub_r001108_20 <= 100);
    __CPROVER_assume(pub_r001108_21 >= -100 && pub_r001108_21 <= 100);
    __CPROVER_assume(sec_r001108_0 >= 0 && sec_r001108_0 <= 255);
    __CPROVER_assume(sec_r001108_1 >= 0 && sec_r001108_1 <= 255);
    __CPROVER_assume(sec_r001108_2 >= 0 && sec_r001108_2 <= 255);
    __CPROVER_assume(sec_r001108_3 >= 0 && sec_r001108_3 <= 255);
    __CPROVER_assume(sec_r001108_4 >= 0 && sec_r001108_4 <= 255);
    __CPROVER_assume(sec_r001108_5 >= 0 && sec_r001108_5 <= 255);
    __CPROVER_assume(sec_r001108_6 >= 0 && sec_r001108_6 <= 255);
    __CPROVER_assume(sec_r001108_7 >= 0 && sec_r001108_7 <= 255);
    __CPROVER_assume(sec_r001108_8 >= 0 && sec_r001108_8 <= 255);
    __CPROVER_assume(sec_r001108_9 >= 0 && sec_r001108_9 <= 255);
    __CPROVER_assume(sec_r001108_10 >= 0 && sec_r001108_10 <= 255);
    __CPROVER_assume(sec_r001108_11 >= 0 && sec_r001108_11 <= 255);
    __CPROVER_assume(sec_r001108_12 >= 0 && sec_r001108_12 <= 255);
    __CPROVER_assume(sec_r001108_13 >= 0 && sec_r001108_13 <= 255);
    __CPROVER_assume(sec_r001108_14 >= 0 && sec_r001108_14 <= 255);
    __CPROVER_assume(sec_r001108_15 >= 0 && sec_r001108_15 <= 255);
    __CPROVER_assume(sec_r001108_16 >= 0 && sec_r001108_16 <= 255);
    __CPROVER_assume(sec_r001108_17 >= 0 && sec_r001108_17 <= 255);
    __CPROVER_assume(sec_r001108_18 >= 0 && sec_r001108_18 <= 255);
    __CPROVER_assume(sec_r001108_19 >= 0 && sec_r001108_19 <= 255);

    struct AudioFrame_R001108_813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001108_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001108_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001108_0 + 7) & 15;
    struct StreamBuffer_R001108_813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001108_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001108_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001108_0 + 9) & 15;
    struct MatrixBlock_R001108_813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001108_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001108_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001108_0 + 11) & 15;

    union RegisterBank_R001108_813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001108_813_0(sec_r001108_0, sec_r001108_1);
    int helper_flow_1 = fn_R001108_813_1(sec_r001108_1, pub_r001108_2, pub_r001108_3);
    int helper_flow_2 = fn_R001108_813_2(sec_r001108_2, pub_r001108_3, pub_r001108_4);
    int helper_flow_3 = fn_R001108_813_3(sec_r001108_3, pub_r001108_4);
    int helper_flow_4 = fn_R001108_813_4(sec_r001108_4, sec_r001108_5, pub_r001108_6, pub_r001108_7, pub_r001108_8);
    int helper_flow_5 = fn_R001108_813_5(sec_r001108_5, pub_r001108_6, pub_r001108_7);
    int helper_flow_6 = fn_R001108_813_6(sec_r001108_6, sec_r001108_7, pub_r001108_8, pub_r001108_9, pub_r001108_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001108_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (sec_r001108_16 & 15)) & 63;
        if ((sec_r001108_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (sec_r001108_16 & 15)) & 63;
        if ((sec_r001108_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001108_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001108_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (sec_r001108_18 & 15)) & 63;
        if ((sec_r001108_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001108_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_9 = (stage_v_9 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_9 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_9 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_10 = (stage_v_10 + it * 3 + (sec_r001108_2 & 15)) & 63;
        if ((sec_r001108_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_10 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_10 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_11 = (stage_v_11 + it * 3 + (sec_r001108_14 & 15)) & 63;
        if ((sec_r001108_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_11 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_11 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001108_21 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001108_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001108_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001108_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_17 = (stage_v_17 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_17 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_17 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_18 = (stage_v_18 + it * 3 + (sec_r001108_2 & 15)) & 63;
        if ((sec_r001108_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_18 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_18 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_19 = (stage_v_19 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_19 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_19 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (sec_r001108_11 & 15)) & 63;
        if ((sec_r001108_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_22 = (stage_v_22 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_22 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_22 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_23 = (stage_v_23 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_23 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_23 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001108_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001108_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001108_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_28 = (stage_v_28 + it * 3 + (sec_r001108_2 & 15)) & 63;
        if ((sec_r001108_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_28 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_28 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_29 = (stage_v_29 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_29 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_29 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_31 = (stage_v_31 + it * 3 + (sec_r001108_18 & 15)) & 63;
        if ((sec_r001108_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_31 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_31 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_32 = (stage_v_32 + it * 3 + (sec_r001108_5 & 15)) & 63;
        if ((sec_r001108_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_32 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_32 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001108_21 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001108_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_35 = (stage_v_35 + it * 3 + (sec_r001108_14 & 15)) & 63;
        if ((sec_r001108_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_35 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_35 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (sec_r001108_4 & 15)) & 63;
        if ((sec_r001108_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001108_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001108_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_40 = (stage_v_40 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_40 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_40 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001108_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001108_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001108_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (sec_r001108_19 & 15)) & 63;
        if ((sec_r001108_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_47 = (stage_v_47 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_47 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_47 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_48 = (stage_v_48 + it * 3 + (sec_r001108_15 & 15)) & 63;
        if ((sec_r001108_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_48 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_48 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (stage_v_47 & 15)) & 63;
        if ((stage_v_47 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_50 = (stage_v_50 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_50 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_50 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_51 = (stage_v_51 + it * 3 + (sec_r001108_11 & 15)) & 63;
        if ((sec_r001108_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_51 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_51 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001108_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_54 = (stage_v_54 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_54 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_54 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_55 = (stage_v_55 + it * 3 + (sec_r001108_14 & 15)) & 63;
        if ((sec_r001108_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_55 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_55 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_56 = (stage_v_56 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_56 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_56 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_57 = (stage_v_57 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_57 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_57 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_58 = (stage_v_58 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_58 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_58 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_60 = (stage_v_60 + it * 3 + (sec_r001108_5 & 15)) & 63;
        if ((sec_r001108_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_60 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_60 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_61 = (stage_v_61 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_61 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_61 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_62 = (stage_v_62 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_62 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_62 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_63 = (stage_v_63 + it * 3 + (stage_v_48 & 15)) & 63;
        if ((stage_v_48 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_63 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_63 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001108_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001108_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001108_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001108_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_68 = (stage_v_68 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_68 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_68 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001108_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001108_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001108_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
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
        stage_v_74 = (stage_v_74 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_74 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_74 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001108_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001108_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_77 = (stage_v_77 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_77 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_77 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (stage_v_61 & 15)) & 63;
        if ((stage_v_61 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001108_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001108_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001108_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001108_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_86 = (stage_v_86 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_86 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_86 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001108_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001108_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_89 = (stage_v_89 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_89 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_89 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_90 = (stage_v_90 + it * 3 + (sec_r001108_3 & 15)) & 63;
        if ((sec_r001108_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_90 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_90 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (sec_r001108_5 & 15)) & 63;
        if ((sec_r001108_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_92 = (stage_v_92 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_92 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_92 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001108_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_96 = (stage_v_96 + it * 3 + (stage_v_47 & 15)) & 63;
        if ((stage_v_47 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_96 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_96 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001108_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001108_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_99 = (stage_v_99 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_99 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_99 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_100 = (stage_v_100 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_100 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_100 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001108_21 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_102 = (stage_v_102 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_102 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_102 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_105 = (stage_v_105 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_105 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_105 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_106 = (stage_v_106 + it * 3 + (sec_r001108_11 & 15)) & 63;
        if ((sec_r001108_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_106 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_106 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_107 = (stage_v_107 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_107 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_107 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001108_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_109 = (stage_v_109 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_109 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_109 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_110 = (stage_v_110 + it * 3 + (stage_v_99 & 15)) & 63;
        if ((stage_v_99 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_110 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_110 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_111 = (stage_v_111 + it * 3 + (stage_v_94 & 15)) & 63;
        if ((stage_v_94 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_111 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_111 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_112 = (stage_v_112 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_112 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_112 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001108_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001108_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001108_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_116 = (stage_v_116 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_116 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_116 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_117 = (stage_v_117 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_117 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_117 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (sec_r001108_5 & 15)) & 63;
        if ((sec_r001108_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_119 = (stage_v_119 + it * 3 + (stage_v_68 & 15)) & 63;
        if ((stage_v_68 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_119 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_119 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001108_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001108_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001108_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001108_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_124 = (stage_v_124 + it * 3 + (sec_r001108_13 & 15)) & 63;
        if ((sec_r001108_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_124 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_124 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001108_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_126 = (stage_v_126 + it * 3 + (stage_v_90 & 15)) & 63;
        if ((stage_v_90 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_126 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_126 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (stage_v_96 & 15)) & 63;
        if ((stage_v_96 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001108_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_129 = (stage_v_129 + it * 3 + (stage_v_22 & 15)) & 63;
        if ((stage_v_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_129 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_129 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (sec_r001108_14 & 15)) & 63;
        if ((sec_r001108_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_131 = (stage_v_131 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_131 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_131 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001108_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_133 = (stage_v_133 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_133 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_133 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_134 = (stage_v_134 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_134 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_134 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_136 = (stage_v_136 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_136 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_136 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_137 = (stage_v_137 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_137 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_137 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_138 = (stage_v_138 + it * 3 + (stage_v_49 & 15)) & 63;
        if ((stage_v_49 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_138 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_138 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (stage_v_94 & 15)) & 63;
        if ((stage_v_94 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001108_20 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_142 = (stage_v_142 + it * 3 + (stage_v_111 & 15)) & 63;
        if ((stage_v_111 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_142 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_142 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_143 = (stage_v_143 + it * 3 + (stage_v_90 & 15)) & 63;
        if ((stage_v_90 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_143 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_143 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_144 = (stage_v_144 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_144 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_144 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001108_21 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_146 = (stage_v_146 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_146 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_146 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_147 = (stage_v_147 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_147 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_147 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (stage_v_147 & 15)) & 63;
        if ((stage_v_147 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_149 = (stage_v_149 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_149 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_149 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_150 = (stage_v_150 + it * 3 + (stage_v_104 & 15)) & 63;
        if ((stage_v_104 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_150 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_150 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_51 & 15)) & 63;
        if ((stage_v_51 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001108_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_153 = (stage_v_153 + it * 3 + (stage_v_143 & 15)) & 63;
        if ((stage_v_143 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_153 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_153 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_154 = (stage_v_154 + it * 3 + (sec_r001108_10 & 15)) & 63;
        if ((sec_r001108_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_154 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_154 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001108_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_156 = (stage_v_156 + it * 3 + (stage_v_131 & 15)) & 63;
        if ((stage_v_131 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_156 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_156 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (stage_v_131 & 15)) & 63;
        if ((stage_v_131 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001108_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001108_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_160 = (stage_v_160 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_160 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_160 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001108_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_165 = (stage_v_165 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_165 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_165 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_166 = (stage_v_166 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_166 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_166 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001108_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_168 = (stage_v_168 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_168 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_168 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_169 = (stage_v_169 + it * 3 + (stage_v_168 & 15)) & 63;
        if ((stage_v_168 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_169 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_169 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001108_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_171 = (stage_v_171 + it * 3 + (sec_r001108_2 & 15)) & 63;
        if ((sec_r001108_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_171 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_171 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (stage_v_109 & 15)) & 63;
        if ((stage_v_109 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001108_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_174 = (stage_v_174 + it * 3 + (stage_v_107 & 15)) & 63;
        if ((stage_v_107 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_174 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_174 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_175 = (stage_v_175 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_175 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_175 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_176 = (stage_v_176 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_176 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_176 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_177 = (stage_v_177 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_177 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_177 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001108_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001108_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001108_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_181 = (stage_v_181 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_181 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_181 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001108_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_184 = (stage_v_184 + it * 3 + (stage_v_103 & 15)) & 63;
        if ((stage_v_103 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_184 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_184 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_185 = (stage_v_185 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_185 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_185 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (stage_v_143 & 15)) & 63;
        if ((stage_v_143 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001108_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001108_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_189 = (stage_v_189 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_189 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_189 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001108_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_191 = (stage_v_191 + it * 3 + (sec_r001108_16 & 15)) & 63;
        if ((sec_r001108_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_191 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_191 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001108_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_193 = (stage_v_193 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_193 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_193 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001108_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_195 = (stage_v_195 + it * 3 + (stage_v_92 & 15)) & 63;
        if ((stage_v_92 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_195 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_195 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_196 = (stage_v_196 + it * 3 + (stage_v_140 & 15)) & 63;
        if ((stage_v_140 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_196 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_196 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (stage_v_48 & 15)) & 63;
        if ((stage_v_48 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001108_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (sec_r001108_10 & 15)) & 63;
        if ((sec_r001108_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001108_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_201 = (stage_v_201 + it * 3 + (stage_v_143 & 15)) & 63;
        if ((stage_v_143 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_201 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_201 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_202 = (stage_v_202 + it * 3 + (stage_v_112 & 15)) & 63;
        if ((stage_v_112 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_202 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_202 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_203 = (stage_v_203 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_203 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_203 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001108_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_205 = (stage_v_205 + it * 3 + (stage_v_40 & 15)) & 63;
        if ((stage_v_40 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_205 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_205 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_206 = (stage_v_206 + it * 3 + (stage_v_191 & 15)) & 63;
        if ((stage_v_191 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_206 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_206 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001108_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_208 = (stage_v_208 + it * 3 + (stage_v_126 & 15)) & 63;
        if ((stage_v_126 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_208 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_208 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001108_21 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_210 = (stage_v_210 + it * 3 + (stage_v_94 & 15)) & 63;
        if ((stage_v_94 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_210 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_210 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001108_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001108_19 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_213 = (stage_v_213 + it * 3 + (stage_v_59 & 15)) & 63;
        if ((stage_v_59 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_213 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_213 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_214 = (stage_v_214 + it * 3 + (stage_v_171 & 15)) & 63;
        if ((stage_v_171 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_214 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_214 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001108_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_216 = (stage_v_216 + it * 3 + (stage_v_201 & 15)) & 63;
        if ((stage_v_201 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_216 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_216 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001108_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001108_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_219 = (stage_v_219 + it * 3 + (stage_v_171 & 15)) & 63;
        if ((stage_v_171 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_219 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_219 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_220 = (stage_v_220 + it * 3 + (stage_v_102 & 15)) & 63;
        if ((stage_v_102 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_220 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_220 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001108_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_222 = (stage_v_222 + it * 3 + (sec_r001108_16 & 15)) & 63;
        if ((sec_r001108_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_222 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_222 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001108_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_224 = (stage_v_224 + it * 3 + (stage_v_182 & 15)) & 63;
        if ((stage_v_182 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_224 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_224 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001108_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001108_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_227 = (stage_v_227 + it * 3 + (stage_v_193 & 15)) & 63;
        if ((stage_v_193 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_227 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_227 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_228 = (stage_v_228 + it * 3 + (stage_v_219 & 15)) & 63;
        if ((stage_v_219 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_228 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_228 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_229 = (stage_v_229 + it * 3 + (stage_v_74 & 15)) & 63;
        if ((stage_v_74 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_229 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_229 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001108_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001108_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_232 = (stage_v_232 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_232 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_232 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_233 = (stage_v_233 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_233 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_233 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001108_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_235 = (stage_v_235 + it * 3 + (sec_r001108_1 & 15)) & 63;
        if ((sec_r001108_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_235 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_235 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_236 = (stage_v_236 + it * 3 + (stage_v_45 & 15)) & 63;
        if ((stage_v_45 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_236 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_236 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_237 = (stage_v_237 + it * 3 + (stage_v_106 & 15)) & 63;
        if ((stage_v_106 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_237 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_237 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_238 = (stage_v_238 + it * 3 + (stage_v_206 & 15)) & 63;
        if ((stage_v_206 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_238 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_238 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_239 = (stage_v_239 + it * 3 + (sec_r001108_1 & 15)) & 63;
        if ((sec_r001108_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_239 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_239 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_240 = (stage_v_240 + it * 3 + (stage_v_171 & 15)) & 63;
        if ((stage_v_171 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_240 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_240 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
