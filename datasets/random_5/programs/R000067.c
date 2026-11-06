/*
 * Benchmark Program: R000067
 * Security Family: nested_implicit_flow
 * Generator Seed: 506713
 * High Inputs: 20 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000067_6713_0 {
    short determinant;
    unsigned char stride;
    short density;
    unsigned char trace;
    int scale;
    int buffer[3];
};

struct StreamBuffer_R000067_6713_1 {
    int checksum;
    unsigned char watermark;
    int capacity;
    short head;
    unsigned char tail;
    int buffer[3];
};

struct AudioFrame_R000067_6713_2 {
    unsigned char gain;
    int channels;
    int rms;
    short envelope;
    int buffer[3];
};

struct Transaction_R000067_6713_3 {
    int account_id;
    int rate;
    int fee;
    int buffer[3];
};

union RegisterBank_R000067_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000067_6713_0(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000067_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_86) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_24 = local_arr[aux % 3];
    acc = (acc + coefficient_24 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000067_6713_1(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000067_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int quotient_25 = local_arr[aux % 3];
    acc = (acc + quotient_25 * 2) & 127;
    int tracker_49 = (aux + st.buffer[1]) & 3;
    switch (tracker_49) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000067_6713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000067_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int vector_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_83) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_20 = local_arr[aux % 3];
    acc = (acc + index_reg_20 * 2) & 127;
    int weight_51 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_51 > 29) {
        acc = (acc + weight_51 * 2 + 5) & 127;
        aux ^= (weight_51 & 15);
    } else {
        acc = (acc - weight_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000067_6713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000067_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_53) & 63;
    acc ^= aux;
    int residue_70 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_70 > 28) {
        acc = (acc + residue_70 * 2 + 5) & 127;
        aux ^= (residue_70 & 15);
    } else {
        acc = (acc - residue_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000067_6713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000067_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int residue_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_36 = local_arr[aux % 3];
    acc = (acc + anchor_36 * 2) & 127;
    int margin_92 = (aux + st.buffer[1]) & 3;
    switch (margin_92) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000067_6713_5(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000067_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_67 = (aux + st.buffer[1]) & 3;
    switch (bound_67) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_31 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_31 > 13) {
        acc = (acc + index_reg_31 * 2 + 5) & 127;
        aux ^= (index_reg_31 & 15);
    } else {
        acc = (acc - index_reg_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000067_6713_6(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000067_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int quantum_82 = local_arr[aux % 3];
    acc = (acc + quantum_82 * 2) & 127;
    int factor_33 = (aux + st.buffer[1]) & 3;
    switch (factor_33) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000067_6713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000067_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int weight_97 = local_arr[aux % 3];
    acc = (acc + weight_97 * 2) & 127;
    int segment_80 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_80 > 19) {
        acc = (acc + segment_80 * 2 + 5) & 127;
        aux ^= (segment_80 & 15);
    } else {
        acc = (acc - segment_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000067_6713_8(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000067_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_83 = (aux + st.buffer[1]) & 3;
    switch (pivot_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_93 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_93 > 47) {
        acc = (acc + sample_93 * 2 + 5) & 127;
        aux ^= (sample_93 & 15);
    } else {
        acc = (acc - sample_93 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_52 = local_arr[aux % 3];
    acc = (acc + accumulator_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000067_6713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000067_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_67 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_67 > 30) {
        acc = (acc + margin_67 * 2 + 5) & 127;
        aux ^= (margin_67 & 15);
    } else {
        acc = (acc - margin_67 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_82 = local_arr[aux % 3];
    acc = (acc + window_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000067_6713_10(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000067_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int offset_81 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_81 > 19) {
        acc = (acc + offset_81 * 2 + 5) & 127;
        aux ^= (offset_81 & 15);
    } else {
        acc = (acc - offset_81 + 11) & 127;
        aux += 3;
    }
    int segment_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000067_6713_11(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000067_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int residue_92 = (aux + st.buffer[1]) & 3;
    switch (residue_92) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_29 = local_arr[aux % 3];
    acc = (acc + anchor_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000067_6713_12(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000067_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int bound_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_82) & 63;
    acc ^= aux;
    int metric_66 = (aux + st.buffer[1]) & 3;
    switch (metric_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_66 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_66 > 12) {
        acc = (acc + stride_66 * 2 + 5) & 127;
        aux ^= (stride_66 & 15);
    } else {
        acc = (acc - stride_66 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000067_6713_13(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000067_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000067_0;
    int sec_r000067_1;
    int sec_r000067_2;
    int sec_r000067_3;
    int sec_r000067_4;
    int sec_r000067_5;
    int sec_r000067_6;
    int sec_r000067_7;
    int sec_r000067_8;
    int sec_r000067_9;
    int sec_r000067_10;
    int sec_r000067_11;
    int sec_r000067_12;
    int sec_r000067_13;
    int sec_r000067_14;
    int sec_r000067_15;
    int sec_r000067_16;
    int sec_r000067_17;
    int sec_r000067_18;
    int sec_r000067_19;
    int pub_r000067_0;
    int pub_r000067_1;
    int pub_r000067_2;
    int pub_r000067_3;
    int pub_r000067_4;
    int pub_r000067_5;
    int pub_r000067_6;
    int pub_r000067_7;
    int pub_r000067_8;
    int pub_r000067_9;
    int pub_r000067_10;
    int pub_r000067_11;
    int pub_r000067_12;
    int pub_r000067_13;
    int pub_r000067_14;
    int pub_r000067_15;
    int pub_r000067_16;
    int pub_r000067_17;
    int pub_r000067_18;
    int pub_r000067_19;
    int pub_r000067_20;
    int pub_r000067_21;
    int pub_r000067_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000067_0 >= -100 && pub_r000067_0 <= 100);
    __CPROVER_assume(pub_r000067_1 >= -100 && pub_r000067_1 <= 100);
    __CPROVER_assume(pub_r000067_2 >= -100 && pub_r000067_2 <= 100);
    __CPROVER_assume(pub_r000067_3 >= -100 && pub_r000067_3 <= 100);
    __CPROVER_assume(pub_r000067_4 >= -100 && pub_r000067_4 <= 100);
    __CPROVER_assume(pub_r000067_5 >= -100 && pub_r000067_5 <= 100);
    __CPROVER_assume(pub_r000067_6 >= -100 && pub_r000067_6 <= 100);
    __CPROVER_assume(pub_r000067_7 >= -100 && pub_r000067_7 <= 100);
    __CPROVER_assume(pub_r000067_8 >= -100 && pub_r000067_8 <= 100);
    __CPROVER_assume(pub_r000067_9 >= -100 && pub_r000067_9 <= 100);
    __CPROVER_assume(pub_r000067_10 >= -100 && pub_r000067_10 <= 100);
    __CPROVER_assume(pub_r000067_11 >= -100 && pub_r000067_11 <= 100);
    __CPROVER_assume(pub_r000067_12 >= -100 && pub_r000067_12 <= 100);
    __CPROVER_assume(pub_r000067_13 >= -100 && pub_r000067_13 <= 100);
    __CPROVER_assume(pub_r000067_14 >= -100 && pub_r000067_14 <= 100);
    __CPROVER_assume(pub_r000067_15 >= -100 && pub_r000067_15 <= 100);
    __CPROVER_assume(pub_r000067_16 >= -100 && pub_r000067_16 <= 100);
    __CPROVER_assume(pub_r000067_17 >= -100 && pub_r000067_17 <= 100);
    __CPROVER_assume(pub_r000067_18 >= -100 && pub_r000067_18 <= 100);
    __CPROVER_assume(pub_r000067_19 >= -100 && pub_r000067_19 <= 100);
    __CPROVER_assume(pub_r000067_20 >= -100 && pub_r000067_20 <= 100);
    __CPROVER_assume(pub_r000067_21 >= -100 && pub_r000067_21 <= 100);
    __CPROVER_assume(pub_r000067_22 >= -100 && pub_r000067_22 <= 100);
    __CPROVER_assume(sec_r000067_0 >= 0 && sec_r000067_0 <= 255);
    __CPROVER_assume(sec_r000067_1 >= 0 && sec_r000067_1 <= 255);
    __CPROVER_assume(sec_r000067_2 >= 0 && sec_r000067_2 <= 255);
    __CPROVER_assume(sec_r000067_3 >= 0 && sec_r000067_3 <= 255);
    __CPROVER_assume(sec_r000067_4 >= 0 && sec_r000067_4 <= 255);
    __CPROVER_assume(sec_r000067_5 >= 0 && sec_r000067_5 <= 255);
    __CPROVER_assume(sec_r000067_6 >= 0 && sec_r000067_6 <= 255);
    __CPROVER_assume(sec_r000067_7 >= 0 && sec_r000067_7 <= 255);
    __CPROVER_assume(sec_r000067_8 >= 0 && sec_r000067_8 <= 255);
    __CPROVER_assume(sec_r000067_9 >= 0 && sec_r000067_9 <= 255);
    __CPROVER_assume(sec_r000067_10 >= 0 && sec_r000067_10 <= 255);
    __CPROVER_assume(sec_r000067_11 >= 0 && sec_r000067_11 <= 255);
    __CPROVER_assume(sec_r000067_12 >= 0 && sec_r000067_12 <= 255);
    __CPROVER_assume(sec_r000067_13 >= 0 && sec_r000067_13 <= 255);
    __CPROVER_assume(sec_r000067_14 >= 0 && sec_r000067_14 <= 255);
    __CPROVER_assume(sec_r000067_15 >= 0 && sec_r000067_15 <= 255);
    __CPROVER_assume(sec_r000067_16 >= 0 && sec_r000067_16 <= 255);
    __CPROVER_assume(sec_r000067_17 >= 0 && sec_r000067_17 <= 255);
    __CPROVER_assume(sec_r000067_18 >= 0 && sec_r000067_18 <= 255);
    __CPROVER_assume(sec_r000067_19 >= 0 && sec_r000067_19 <= 255);

    struct MatrixBlock_R000067_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000067_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000067_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000067_0 + 7) & 15;
    struct StreamBuffer_R000067_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000067_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000067_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000067_0 + 9) & 15;
    struct AudioFrame_R000067_6713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000067_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000067_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000067_0 + 11) & 15;
    struct Transaction_R000067_6713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000067_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000067_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000067_0 + 13) & 15;

    union RegisterBank_R000067_6713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 37) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 52) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 18) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 33) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 31) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 46) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 14) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 29) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 23) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 38) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 17) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 32) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 13) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 28) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 24) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 39) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
        case 0:
            out_sink = (out_sink + 3) & 255;
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[0] ^ 58) & 3;
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
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 24) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 39) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 38) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 53) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[0] ^ 82) & 3;
    switch (stage_v_79) {
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

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000067_13 & 1) != 0) {
        if ((sec_r000067_1 & 2) != 0) {
            stage_v_87 = (pub_r000067_19 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000067_19 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000067_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000067_14 & 2) != 0) {
            stage_v_88 = (pub_r000067_17 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000067_17 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000067_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000067_14 & 1) != 0) {
        if ((sec_r000067_13 & 2) != 0) {
            stage_v_89 = (pub_r000067_10 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000067_10 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000067_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000067_2 & 1) != 0) {
        if ((sec_r000067_3 & 2) != 0) {
            stage_v_90 = (pub_r000067_19 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000067_19 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000067_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000067_2 & 1) != 0) {
        if ((sec_r000067_14 & 2) != 0) {
            stage_v_91 = (pub_r000067_8 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000067_8 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000067_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000067_16 & 2) != 0) {
            stage_v_92 = (pub_r000067_1 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000067_1 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000067_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_93 = (pub_r000067_7 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000067_7 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000067_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000067_17 & 2) != 0) {
            stage_v_94 = (pub_r000067_17 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000067_17 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000067_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000067_0 & 2) != 0) {
            stage_v_95 = (pub_r000067_4 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000067_4 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000067_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000067_1 & 2) != 0) {
            stage_v_96 = (pub_r000067_19 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000067_19 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000067_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000067_18 & 2) != 0) {
            stage_v_97 = (pub_r000067_20 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000067_20 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000067_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000067_7 & 2) != 0) {
            stage_v_98 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000067_12 & 2) != 0) {
            stage_v_99 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000067_2 & 1) != 0) {
        if ((sec_r000067_13 & 2) != 0) {
            stage_v_100 = (pub_r000067_10 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000067_10 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000067_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000067_8 & 2) != 0) {
            stage_v_101 = (pub_r000067_22 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000067_22 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000067_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000067_5 & 2) != 0) {
            stage_v_102 = (pub_r000067_16 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000067_16 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000067_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000067_17 & 2) != 0) {
            stage_v_103 = (pub_r000067_19 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000067_19 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000067_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000067_4 & 1) != 0) {
        if ((sec_r000067_16 & 2) != 0) {
            stage_v_104 = (pub_r000067_19 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000067_19 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000067_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000067_19 & 1) != 0) {
        if ((sec_r000067_12 & 2) != 0) {
            stage_v_105 = (pub_r000067_22 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000067_22 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000067_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000067_8 & 2) != 0) {
            stage_v_106 = (pub_r000067_1 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000067_1 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000067_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000067_15 & 1) != 0) {
        if ((sec_r000067_5 & 2) != 0) {
            stage_v_107 = (pub_r000067_15 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000067_15 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000067_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_108 = (pub_r000067_0 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000067_0 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000067_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_109 = (pub_r000067_6 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000067_6 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000067_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000067_8 & 2) != 0) {
            stage_v_110 = (pub_r000067_14 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000067_14 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000067_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000067_1 & 2) != 0) {
            stage_v_111 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000067_9 & 1) != 0) {
        if ((sec_r000067_19 & 2) != 0) {
            stage_v_112 = (pub_r000067_17 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000067_17 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000067_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000067_7 & 2) != 0) {
            stage_v_113 = (pub_r000067_7 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000067_7 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000067_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000067_5 & 2) != 0) {
            stage_v_114 = (pub_r000067_17 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000067_17 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000067_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000067_12 & 2) != 0) {
            stage_v_115 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000067_0 & 2) != 0) {
            stage_v_116 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000067_6 & 2) != 0) {
            stage_v_117 = (pub_r000067_7 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000067_7 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000067_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000067_11 & 2) != 0) {
            stage_v_118 = (pub_r000067_22 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000067_22 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000067_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000067_17 & 2) != 0) {
            stage_v_119 = (pub_r000067_6 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000067_6 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000067_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000067_2 & 1) != 0) {
        if ((sec_r000067_14 & 2) != 0) {
            stage_v_120 = (pub_r000067_18 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000067_18 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000067_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000067_9 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_121 = (pub_r000067_12 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000067_12 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000067_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000067_12 & 1) != 0) {
        if ((sec_r000067_6 & 2) != 0) {
            stage_v_122 = (pub_r000067_18 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000067_18 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000067_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_123 = (pub_r000067_3 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000067_3 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000067_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_124 = (pub_r000067_22 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000067_22 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000067_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_125 = (pub_r000067_4 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000067_4 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000067_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000067_11 & 2) != 0) {
            stage_v_126 = (pub_r000067_9 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000067_9 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000067_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_127 = (pub_r000067_21 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000067_21 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000067_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000067_2 & 2) != 0) {
            stage_v_128 = (pub_r000067_8 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000067_8 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000067_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000067_2 & 1) != 0) {
        if ((sec_r000067_7 & 2) != 0) {
            stage_v_129 = (pub_r000067_7 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000067_7 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000067_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000067_12 & 1) != 0) {
        if ((sec_r000067_19 & 2) != 0) {
            stage_v_130 = (pub_r000067_12 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000067_12 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000067_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_131 = (pub_r000067_9 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000067_9 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000067_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000067_3 & 2) != 0) {
            stage_v_132 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_133 = (pub_r000067_3 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000067_3 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000067_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000067_13 & 1) != 0) {
        if ((sec_r000067_14 & 2) != 0) {
            stage_v_134 = (pub_r000067_0 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000067_0 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000067_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000067_12 & 2) != 0) {
            stage_v_135 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000067_0 & 2) != 0) {
            stage_v_136 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000067_12 & 2) != 0) {
            stage_v_137 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000067_16 & 2) != 0) {
            stage_v_138 = (pub_r000067_12 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000067_12 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000067_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000067_15 & 2) != 0) {
            stage_v_139 = (pub_r000067_22 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000067_22 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000067_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000067_2 & 2) != 0) {
            stage_v_140 = (pub_r000067_6 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000067_6 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000067_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000067_5 & 2) != 0) {
            stage_v_141 = (pub_r000067_8 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000067_8 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000067_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000067_13 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_142 = (pub_r000067_0 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000067_0 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000067_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000067_4 & 2) != 0) {
            stage_v_143 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000067_4 & 2) != 0) {
            stage_v_144 = (pub_r000067_3 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000067_3 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000067_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000067_18 & 1) != 0) {
        if ((sec_r000067_4 & 2) != 0) {
            stage_v_145 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000067_4 & 2) != 0) {
            stage_v_146 = (pub_r000067_4 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000067_4 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000067_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000067_7 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_147 = (pub_r000067_20 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000067_20 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000067_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000067_6 & 1) != 0) {
        if ((sec_r000067_4 & 2) != 0) {
            stage_v_148 = (pub_r000067_9 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000067_9 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000067_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000067_4 & 2) != 0) {
            stage_v_149 = (pub_r000067_15 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000067_15 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000067_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000067_11 & 2) != 0) {
            stage_v_150 = (pub_r000067_12 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000067_12 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000067_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_151 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000067_16 & 1) != 0) {
        if ((sec_r000067_18 & 2) != 0) {
            stage_v_152 = (pub_r000067_5 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000067_5 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000067_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000067_11 & 2) != 0) {
            stage_v_153 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000067_5 & 2) != 0) {
            stage_v_154 = (pub_r000067_3 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000067_3 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000067_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r000067_14 & 2) != 0) {
            stage_v_155 = (pub_r000067_18 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000067_18 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000067_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000067_13 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_156 = (pub_r000067_11 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000067_11 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000067_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_157 = (pub_r000067_11 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000067_11 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000067_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000067_16 & 2) != 0) {
            stage_v_158 = (pub_r000067_21 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000067_21 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000067_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000067_11 & 1) != 0) {
        if ((sec_r000067_13 & 2) != 0) {
            stage_v_159 = (pub_r000067_1 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000067_1 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000067_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r000067_5 & 2) != 0) {
            stage_v_160 = (pub_r000067_9 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000067_9 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000067_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((sec_r000067_2 & 1) != 0) {
        if ((sec_r000067_4 & 2) != 0) {
            stage_v_161 = (pub_r000067_21 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000067_21 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000067_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000067_16 & 2) != 0) {
            stage_v_162 = (pub_r000067_19 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000067_19 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000067_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000067_7 & 2) != 0) {
            stage_v_163 = (pub_r000067_10 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000067_10 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000067_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000067_13 & 1) != 0) {
        if ((sec_r000067_8 & 2) != 0) {
            stage_v_164 = (pub_r000067_9 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000067_9 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000067_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000067_1 & 2) != 0) {
            stage_v_165 = (pub_r000067_1 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000067_1 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000067_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((sec_r000067_9 & 1) != 0) {
        if ((sec_r000067_10 & 2) != 0) {
            stage_v_166 = (pub_r000067_14 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000067_14 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000067_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000067_3 & 2) != 0) {
            stage_v_167 = (pub_r000067_8 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000067_8 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000067_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((stage_v_158 & 1) != 0) {
        if ((sec_r000067_13 & 2) != 0) {
            stage_v_168 = (pub_r000067_10 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000067_10 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000067_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000067_13 & 2) != 0) {
            stage_v_169 = (pub_r000067_22 + 31) & 127;
        } else {
            stage_v_169 = (pub_r000067_22 + 13) & 127;
        }
    } else {
        stage_v_169 = (pub_r000067_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((sec_r000067_11 & 1) != 0) {
        if ((sec_r000067_16 & 2) != 0) {
            stage_v_170 = (pub_r000067_22 + 31) & 127;
        } else {
            stage_v_170 = (pub_r000067_22 + 13) & 127;
        }
    } else {
        stage_v_170 = (pub_r000067_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r000067_13 & 2) != 0) {
            stage_v_171 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_171 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_171 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    if ((stage_v_169 & 1) != 0) {
        if ((sec_r000067_8 & 2) != 0) {
            stage_v_172 = (pub_r000067_15 + 31) & 127;
        } else {
            stage_v_172 = (pub_r000067_15 + 13) & 127;
        }
    } else {
        stage_v_172 = (pub_r000067_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    if ((sec_r000067_12 & 1) != 0) {
        if ((sec_r000067_9 & 2) != 0) {
            stage_v_173 = (pub_r000067_13 + 31) & 127;
        } else {
            stage_v_173 = (pub_r000067_13 + 13) & 127;
        }
    } else {
        stage_v_173 = (pub_r000067_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    if ((sec_r000067_10 & 1) != 0) {
        if ((sec_r000067_8 & 2) != 0) {
            stage_v_174 = (pub_r000067_16 + 31) & 127;
        } else {
            stage_v_174 = (pub_r000067_16 + 13) & 127;
        }
    } else {
        stage_v_174 = (pub_r000067_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000067_11 & 2) != 0) {
            stage_v_175 = (pub_r000067_15 + 31) & 127;
        } else {
            stage_v_175 = (pub_r000067_15 + 13) & 127;
        }
    } else {
        stage_v_175 = (pub_r000067_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000067_0 & 2) != 0) {
            stage_v_176 = (pub_r000067_14 + 31) & 127;
        } else {
            stage_v_176 = (pub_r000067_14 + 13) & 127;
        }
    } else {
        stage_v_176 = (pub_r000067_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    if ((sec_r000067_1 & 1) != 0) {
        if ((sec_r000067_2 & 2) != 0) {
            stage_v_177 = (pub_r000067_18 + 31) & 127;
        } else {
            stage_v_177 = (pub_r000067_18 + 13) & 127;
        }
    } else {
        stage_v_177 = (pub_r000067_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    if ((sec_r000067_18 & 1) != 0) {
        if ((sec_r000067_11 & 2) != 0) {
            stage_v_178 = (pub_r000067_20 + 31) & 127;
        } else {
            stage_v_178 = (pub_r000067_20 + 13) & 127;
        }
    } else {
        stage_v_178 = (pub_r000067_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000067_11 & 2) != 0) {
            stage_v_179 = (pub_r000067_1 + 31) & 127;
        } else {
            stage_v_179 = (pub_r000067_1 + 13) & 127;
        }
    } else {
        stage_v_179 = (pub_r000067_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000067_6 & 2) != 0) {
            stage_v_180 = (pub_r000067_7 + 31) & 127;
        } else {
            stage_v_180 = (pub_r000067_7 + 13) & 127;
        }
    } else {
        stage_v_180 = (pub_r000067_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_180) & 255;
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    if ((sec_r000067_10 & 1) != 0) {
        if ((sec_r000067_2 & 2) != 0) {
            stage_v_181 = (pub_r000067_11 + 31) & 127;
        } else {
            stage_v_181 = (pub_r000067_11 + 13) & 127;
        }
    } else {
        stage_v_181 = (pub_r000067_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
