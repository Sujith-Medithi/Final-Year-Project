/*
 * Benchmark Program: R000708
 * Security Family: secret_dependent_loops
 * Generator Seed: 570813
 * High Inputs: 17 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000708_813_0 {
    int envelope;
    int sample_rate;
    unsigned char channels;
    unsigned char gain;
    unsigned char rms;
    int peak;
    int buffer[3];
};

struct StreamBuffer_R000708_813_1 {
    unsigned char tail;
    int capacity;
    short watermark;
    int buffer[3];
};

struct MatrixBlock_R000708_813_2 {
    int determinant;
    short trace;
    int scale;
    int buffer[3];
};

union RegisterBank_R000708_813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000708_813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000708_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_50 = local_arr[aux % 3];
    acc = (acc + pivot_50 * 2) & 127;
    int factor_16 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_16 > 26) {
        acc = (acc + factor_16 * 2 + 5) & 127;
        aux ^= (factor_16 & 15);
    } else {
        acc = (acc - factor_16 + 11) & 127;
        aux += 3;
    }
    int parity_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000708_813_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000708_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int tally_70 = local_arr[aux % 3];
    acc = (acc + tally_70 * 2) & 127;
    int threshold_27 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_27 > 23) {
        acc = (acc + threshold_27 * 2 + 5) & 127;
        aux ^= (threshold_27 & 15);
    } else {
        acc = (acc - threshold_27 + 11) & 127;
        aux += 3;
    }
    int tracker_76 = (aux + st.buffer[1]) & 3;
    switch (tracker_76) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000708_813_2(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000708_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_92 = (aux + st.buffer[1]) & 3;
    switch (phase_92) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_96 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_96 > 32) {
        acc = (acc + quotient_96 * 2 + 5) & 127;
        aux ^= (quotient_96 & 15);
    } else {
        acc = (acc - quotient_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000708_813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000708_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int coefficient_54 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_54 > 14) {
        acc = (acc + coefficient_54 * 2 + 5) & 127;
        aux ^= (coefficient_54 & 15);
    } else {
        acc = (acc - coefficient_54 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000708_813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000708_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int scale_76 = local_arr[aux % 3];
    acc = (acc + scale_76 * 2) & 127;
    int delta_30 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_30 > 14) {
        acc = (acc + delta_30 * 2 + 5) & 127;
        aux ^= (delta_30 & 15);
    } else {
        acc = (acc - delta_30 + 11) & 127;
        aux += 3;
    }
    int pivot_21 = (aux + st.buffer[1]) & 3;
    switch (pivot_21) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000708_813_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000708_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int residue_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_94 = local_arr[aux % 3];
    acc = (acc + sample_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000708_813_6(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000708_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int offset_83 = (aux + st.buffer[1]) & 3;
    switch (offset_83) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_21 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_21 > 15) {
        acc = (acc + tracker_21 * 2 + 5) & 127;
        aux ^= (tracker_21 & 15);
    } else {
        acc = (acc - tracker_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000708_813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000708_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_61) & 63;
    acc ^= aux;
    int mask_63 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_63 > 25) {
        acc = (acc + mask_63 * 2 + 5) & 127;
        aux ^= (mask_63 & 15);
    } else {
        acc = (acc - mask_63 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000708_813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000708_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_72 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_72 > 20) {
        acc = (acc + metric_72 * 2 + 5) & 127;
        aux ^= (metric_72 & 15);
    } else {
        acc = (acc - metric_72 + 11) & 127;
        aux += 3;
    }
    int quantum_37 = (aux + st.buffer[1]) & 3;
    switch (quantum_37) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000708_813_9(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000708_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int threshold_60 = (aux + st.buffer[1]) & 3;
    switch (threshold_60) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000708_813_10(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000708_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int weight_12 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_12 > 30) {
        acc = (acc + weight_12 * 2 + 5) & 127;
        aux ^= (weight_12 & 15);
    } else {
        acc = (acc - weight_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_59 = local_arr[aux % 3];
    acc = (acc + parity_59 * 2) & 127;
    int index_reg_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_88) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000708_813_11(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000708_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_29 = (aux + st.buffer[1]) & 3;
    switch (stride_29) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_31 = local_arr[aux % 3];
    acc = (acc + factor_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000708_813_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000708_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int anchor_18 = local_arr[aux % 3];
    acc = (acc + anchor_18 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000708_813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000708_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int checksum_52 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_52 > 15) {
        acc = (acc + checksum_52 * 2 + 5) & 127;
        aux ^= (checksum_52 & 15);
    } else {
        acc = (acc - checksum_52 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_75 = local_arr[aux % 3];
    acc = (acc + phase_75 * 2) & 127;
    int quotient_70 = (aux + st.buffer[1]) & 3;
    switch (quotient_70) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000708_813_14(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000708_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int sample_45 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_45 > 44) {
        acc = (acc + sample_45 * 2 + 5) & 127;
        aux ^= (sample_45 & 15);
    } else {
        acc = (acc - sample_45 + 11) & 127;
        aux += 3;
    }
    int damping_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_63) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_85 = local_arr[aux % 3];
    acc = (acc + quotient_85 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000708_0;
    int sec_r000708_1;
    int sec_r000708_2;
    int sec_r000708_3;
    int sec_r000708_4;
    int sec_r000708_5;
    int sec_r000708_6;
    int sec_r000708_7;
    int sec_r000708_8;
    int sec_r000708_9;
    int sec_r000708_10;
    int sec_r000708_11;
    int sec_r000708_12;
    int sec_r000708_13;
    int sec_r000708_14;
    int sec_r000708_15;
    int sec_r000708_16;
    int pub_r000708_0;
    int pub_r000708_1;
    int pub_r000708_2;
    int pub_r000708_3;
    int pub_r000708_4;
    int pub_r000708_5;
    int pub_r000708_6;
    int pub_r000708_7;
    int pub_r000708_8;
    int pub_r000708_9;
    int pub_r000708_10;
    int pub_r000708_11;
    int pub_r000708_12;
    int pub_r000708_13;
    int pub_r000708_14;
    int pub_r000708_15;
    int pub_r000708_16;
    int pub_r000708_17;
    int pub_r000708_18;
    int pub_r000708_19;
    int pub_r000708_20;
    int pub_r000708_21;
    int pub_r000708_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000708_0 >= -100 && pub_r000708_0 <= 100);
    __CPROVER_assume(pub_r000708_1 >= -100 && pub_r000708_1 <= 100);
    __CPROVER_assume(pub_r000708_2 >= -100 && pub_r000708_2 <= 100);
    __CPROVER_assume(pub_r000708_3 >= -100 && pub_r000708_3 <= 100);
    __CPROVER_assume(pub_r000708_4 >= -100 && pub_r000708_4 <= 100);
    __CPROVER_assume(pub_r000708_5 >= -100 && pub_r000708_5 <= 100);
    __CPROVER_assume(pub_r000708_6 >= -100 && pub_r000708_6 <= 100);
    __CPROVER_assume(pub_r000708_7 >= -100 && pub_r000708_7 <= 100);
    __CPROVER_assume(pub_r000708_8 >= -100 && pub_r000708_8 <= 100);
    __CPROVER_assume(pub_r000708_9 >= -100 && pub_r000708_9 <= 100);
    __CPROVER_assume(pub_r000708_10 >= -100 && pub_r000708_10 <= 100);
    __CPROVER_assume(pub_r000708_11 >= -100 && pub_r000708_11 <= 100);
    __CPROVER_assume(pub_r000708_12 >= -100 && pub_r000708_12 <= 100);
    __CPROVER_assume(pub_r000708_13 >= -100 && pub_r000708_13 <= 100);
    __CPROVER_assume(pub_r000708_14 >= -100 && pub_r000708_14 <= 100);
    __CPROVER_assume(pub_r000708_15 >= -100 && pub_r000708_15 <= 100);
    __CPROVER_assume(pub_r000708_16 >= -100 && pub_r000708_16 <= 100);
    __CPROVER_assume(pub_r000708_17 >= -100 && pub_r000708_17 <= 100);
    __CPROVER_assume(pub_r000708_18 >= -100 && pub_r000708_18 <= 100);
    __CPROVER_assume(pub_r000708_19 >= -100 && pub_r000708_19 <= 100);
    __CPROVER_assume(pub_r000708_20 >= -100 && pub_r000708_20 <= 100);
    __CPROVER_assume(pub_r000708_21 >= -100 && pub_r000708_21 <= 100);
    __CPROVER_assume(pub_r000708_22 >= -100 && pub_r000708_22 <= 100);
    __CPROVER_assume(sec_r000708_0 >= 0 && sec_r000708_0 <= 255);
    __CPROVER_assume(sec_r000708_1 >= 0 && sec_r000708_1 <= 255);
    __CPROVER_assume(sec_r000708_2 >= 0 && sec_r000708_2 <= 255);
    __CPROVER_assume(sec_r000708_3 >= 0 && sec_r000708_3 <= 255);
    __CPROVER_assume(sec_r000708_4 >= 0 && sec_r000708_4 <= 255);
    __CPROVER_assume(sec_r000708_5 >= 0 && sec_r000708_5 <= 255);
    __CPROVER_assume(sec_r000708_6 >= 0 && sec_r000708_6 <= 255);
    __CPROVER_assume(sec_r000708_7 >= 0 && sec_r000708_7 <= 255);
    __CPROVER_assume(sec_r000708_8 >= 0 && sec_r000708_8 <= 255);
    __CPROVER_assume(sec_r000708_9 >= 0 && sec_r000708_9 <= 255);
    __CPROVER_assume(sec_r000708_10 >= 0 && sec_r000708_10 <= 255);
    __CPROVER_assume(sec_r000708_11 >= 0 && sec_r000708_11 <= 255);
    __CPROVER_assume(sec_r000708_12 >= 0 && sec_r000708_12 <= 255);
    __CPROVER_assume(sec_r000708_13 >= 0 && sec_r000708_13 <= 255);
    __CPROVER_assume(sec_r000708_14 >= 0 && sec_r000708_14 <= 255);
    __CPROVER_assume(sec_r000708_15 >= 0 && sec_r000708_15 <= 255);
    __CPROVER_assume(sec_r000708_16 >= 0 && sec_r000708_16 <= 255);

    struct AudioFrame_R000708_813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000708_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000708_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000708_0 + 7) & 15;
    struct StreamBuffer_R000708_813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000708_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000708_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000708_0 + 9) & 15;
    struct MatrixBlock_R000708_813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000708_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000708_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000708_0 + 11) & 15;

    union RegisterBank_R000708_813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 38) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 53) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 10) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 25) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 17) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 32) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 39) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 54) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 28) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 43) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 24) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 39) {
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
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 29) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 44) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 29) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 44) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 10) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 25) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 16) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 31) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 22) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 37) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 26) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 41) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_16 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000708_15) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000708_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000708_1) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000708_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000708_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000708_7) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000708_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_3 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000708_18) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000708_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000708_19) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000708_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000708_15) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000708_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_1 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000708_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_10 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000708_4) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000708_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_8 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000708_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000708_1) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000708_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000708_14) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000708_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000708_12) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000708_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_3 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000708_21) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000708_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_15 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000708_5) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000708_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000708_10) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000708_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000708_18) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000708_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000708_0) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000708_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_4 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000708_17) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000708_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_16 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000708_19) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000708_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000708_1) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000708_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_4 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000708_17) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000708_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_4 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000708_17) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000708_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000708_22) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000708_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000708_4) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000708_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_5 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000708_22) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000708_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000708_0) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000708_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_1 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000708_16) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000708_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000708_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000708_22) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000708_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000708_22) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000708_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_12 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000708_15) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000708_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000708_15) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000708_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000708_16) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000708_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000708_10) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000708_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_113 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000708_2) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000708_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_11 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000708_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_10 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000708_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000708_5) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000708_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000708_10) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000708_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000708_5) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000708_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000708_17) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000708_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000708_6) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000708_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000708_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000708_17) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000708_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_6 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000708_13) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000708_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000708_6) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000708_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000708_14) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000708_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000708_12) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000708_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000708_2) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000708_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000708_18) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000708_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000708_2) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000708_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000708_16) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000708_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_130 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000708_13) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000708_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000708_20) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000708_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000708_20) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000708_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000708_2) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000708_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_14 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000708_20) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000708_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000708_3) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000708_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000708_17) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000708_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000708_15) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000708_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000708_1) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000708_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_11 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000708_15) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000708_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_9 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000708_16) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000708_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000708_5) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000708_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000708_2) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000708_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_148 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000708_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000708_1) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000708_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000708_19) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000708_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000708_5) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000708_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_0 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000708_14) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000708_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000708_22) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000708_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_133 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000708_8) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000708_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_136 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000708_10) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000708_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000708_12) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000708_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_16 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000708_5) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000708_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_142 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000708_11) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000708_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_11 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000708_22) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000708_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_4 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000708_10) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000708_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_163 = (stage_v_163 + step * 4 + pub_r000708_22) & 63;
        } else {
            stage_v_163 = (stage_v_163 + pub_r000708_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_140 & 1) == step) {
            stage_v_164 = (stage_v_164 + step * 4 + pub_r000708_12) & 63;
        } else {
            stage_v_164 = (stage_v_164 + pub_r000708_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000708_12 & 1) == step) {
            stage_v_165 = (stage_v_165 + step * 4 + pub_r000708_11) & 63;
        } else {
            stage_v_165 = (stage_v_165 + pub_r000708_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
