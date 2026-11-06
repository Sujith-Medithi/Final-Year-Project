/*
 * Benchmark Program: R000413
 * Security Family: multi_step_explicit
 * Generator Seed: 541313
 * High Inputs: 24 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000413_1313_0 {
    int nonce;
    short tag;
    int counter;
    short flags;
    int buffer[3];
};

struct MatrixBlock_R000413_1313_1 {
    int dim;
    unsigned char determinant;
    short density;
    short scale;
    int stride;
    unsigned char trace;
    int buffer[3];
};

struct SensorNode_R000413_1313_2 {
    int calib;
    short gain;
    unsigned char reading;
    int threshold;
    int offset;
    int buffer[3];
};

struct StreamBuffer_R000413_1313_3 {
    unsigned char head;
    unsigned char checksum;
    short capacity;
    unsigned char state;
    int buffer[3];
};

union ColorPixel_R000413_1313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000413_1313_0(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000413_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int coefficient_64 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_64 > 20) {
        acc = (acc + coefficient_64 * 2 + 5) & 127;
        aux ^= (coefficient_64 & 15);
    } else {
        acc = (acc - coefficient_64 + 11) & 127;
        aux += 3;
    }
    int tracker_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000413_1313_1(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000413_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_11 = (aux + st.buffer[1]) & 3;
    switch (factor_11) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000413_1313_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000413_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int damping_29 = local_arr[aux % 3];
    acc = (acc + damping_29 * 2) & 127;
    int threshold_18 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_18 > 22) {
        acc = (acc + threshold_18 * 2 + 5) & 127;
        aux ^= (threshold_18 & 15);
    } else {
        acc = (acc - threshold_18 + 11) & 127;
        aux += 3;
    }
    int quotient_47 = (aux + st.buffer[1]) & 3;
    switch (quotient_47) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000413_1313_3(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000413_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int offset_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_23) & 63;
    acc ^= aux;
    int accumulator_79 = (aux + st.buffer[1]) & 3;
    switch (accumulator_79) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_86 = local_arr[aux % 3];
    acc = (acc + quantum_86 * 2) & 127;
    int threshold_33 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_33 > 30) {
        acc = (acc + threshold_33 * 2 + 5) & 127;
        aux ^= (threshold_33 & 15);
    } else {
        acc = (acc - threshold_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000413_1313_4(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000413_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int sample_44 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_44 > 25) {
        acc = (acc + sample_44 * 2 + 5) & 127;
        aux ^= (sample_44 & 15);
    } else {
        acc = (acc - sample_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_32 = local_arr[aux % 3];
    acc = (acc + segment_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000413_1313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000413_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_52 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_52 > 50) {
        acc = (acc + vector_52 * 2 + 5) & 127;
        aux ^= (vector_52 & 15);
    } else {
        acc = (acc - vector_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000413_1313_6(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000413_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int parity_86 = (aux + st.buffer[1]) & 3;
    switch (parity_86) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_47 = local_arr[aux % 3];
    acc = (acc + cursor_47 * 2) & 127;
    int vector_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000413_1313_7(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000413_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_63 = (aux + st.buffer[1]) & 3;
    switch (anchor_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_74 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_74 > 19) {
        acc = (acc + delta_74 * 2 + 5) & 127;
        aux ^= (delta_74 & 15);
    } else {
        acc = (acc - delta_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000413_1313_8(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000413_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_42 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_42 > 35) {
        acc = (acc + tally_42 * 2 + 5) & 127;
        aux ^= (tally_42 & 15);
    } else {
        acc = (acc - tally_42 + 11) & 127;
        aux += 3;
    }
    int parity_46 = (aux + st.buffer[1]) & 3;
    switch (parity_46) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000413_1313_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000413_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000413_1313_10(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000413_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_14) & 63;
    acc ^= aux;
    int damping_63 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_63 > 48) {
        acc = (acc + damping_63 * 2 + 5) & 127;
        aux ^= (damping_63 & 15);
    } else {
        acc = (acc - damping_63 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000413_1313_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000413_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int tally_89 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_89 > 35) {
        acc = (acc + tally_89 * 2 + 5) & 127;
        aux ^= (tally_89 & 15);
    } else {
        acc = (acc - tally_89 + 11) & 127;
        aux += 3;
    }
    int phase_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_94) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_88 = local_arr[aux % 3];
    acc = (acc + sample_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000413_1313_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000413_1313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_66 = local_arr[aux % 3];
    acc = (acc + damping_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000413_1313_13(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000413_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int bound_78 = local_arr[aux % 3];
    acc = (acc + bound_78 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = (aux + st.buffer[1]) & 3;
    switch (tally_80) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000413_0;
    int sec_r000413_1;
    int sec_r000413_2;
    int sec_r000413_3;
    int sec_r000413_4;
    int sec_r000413_5;
    int sec_r000413_6;
    int sec_r000413_7;
    int sec_r000413_8;
    int sec_r000413_9;
    int sec_r000413_10;
    int sec_r000413_11;
    int sec_r000413_12;
    int sec_r000413_13;
    int sec_r000413_14;
    int sec_r000413_15;
    int sec_r000413_16;
    int sec_r000413_17;
    int sec_r000413_18;
    int sec_r000413_19;
    int sec_r000413_20;
    int sec_r000413_21;
    int sec_r000413_22;
    int sec_r000413_23;
    int pub_r000413_0;
    int pub_r000413_1;
    int pub_r000413_2;
    int pub_r000413_3;
    int pub_r000413_4;
    int pub_r000413_5;
    int pub_r000413_6;
    int pub_r000413_7;
    int pub_r000413_8;
    int pub_r000413_9;
    int pub_r000413_10;
    int pub_r000413_11;
    int pub_r000413_12;
    int pub_r000413_13;
    int pub_r000413_14;
    int pub_r000413_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000413_0 >= -100 && pub_r000413_0 <= 100);
    __CPROVER_assume(pub_r000413_1 >= -100 && pub_r000413_1 <= 100);
    __CPROVER_assume(pub_r000413_2 >= -100 && pub_r000413_2 <= 100);
    __CPROVER_assume(pub_r000413_3 >= -100 && pub_r000413_3 <= 100);
    __CPROVER_assume(pub_r000413_4 >= -100 && pub_r000413_4 <= 100);
    __CPROVER_assume(pub_r000413_5 >= -100 && pub_r000413_5 <= 100);
    __CPROVER_assume(pub_r000413_6 >= -100 && pub_r000413_6 <= 100);
    __CPROVER_assume(pub_r000413_7 >= -100 && pub_r000413_7 <= 100);
    __CPROVER_assume(pub_r000413_8 >= -100 && pub_r000413_8 <= 100);
    __CPROVER_assume(pub_r000413_9 >= -100 && pub_r000413_9 <= 100);
    __CPROVER_assume(pub_r000413_10 >= -100 && pub_r000413_10 <= 100);
    __CPROVER_assume(pub_r000413_11 >= -100 && pub_r000413_11 <= 100);
    __CPROVER_assume(pub_r000413_12 >= -100 && pub_r000413_12 <= 100);
    __CPROVER_assume(pub_r000413_13 >= -100 && pub_r000413_13 <= 100);
    __CPROVER_assume(pub_r000413_14 >= -100 && pub_r000413_14 <= 100);
    __CPROVER_assume(pub_r000413_15 >= -100 && pub_r000413_15 <= 100);
    __CPROVER_assume(sec_r000413_0 >= 0 && sec_r000413_0 <= 255);
    __CPROVER_assume(sec_r000413_1 >= 0 && sec_r000413_1 <= 255);
    __CPROVER_assume(sec_r000413_2 >= 0 && sec_r000413_2 <= 255);
    __CPROVER_assume(sec_r000413_3 >= 0 && sec_r000413_3 <= 255);
    __CPROVER_assume(sec_r000413_4 >= 0 && sec_r000413_4 <= 255);
    __CPROVER_assume(sec_r000413_5 >= 0 && sec_r000413_5 <= 255);
    __CPROVER_assume(sec_r000413_6 >= 0 && sec_r000413_6 <= 255);
    __CPROVER_assume(sec_r000413_7 >= 0 && sec_r000413_7 <= 255);
    __CPROVER_assume(sec_r000413_8 >= 0 && sec_r000413_8 <= 255);
    __CPROVER_assume(sec_r000413_9 >= 0 && sec_r000413_9 <= 255);
    __CPROVER_assume(sec_r000413_10 >= 0 && sec_r000413_10 <= 255);
    __CPROVER_assume(sec_r000413_11 >= 0 && sec_r000413_11 <= 255);
    __CPROVER_assume(sec_r000413_12 >= 0 && sec_r000413_12 <= 255);
    __CPROVER_assume(sec_r000413_13 >= 0 && sec_r000413_13 <= 255);
    __CPROVER_assume(sec_r000413_14 >= 0 && sec_r000413_14 <= 255);
    __CPROVER_assume(sec_r000413_15 >= 0 && sec_r000413_15 <= 255);
    __CPROVER_assume(sec_r000413_16 >= 0 && sec_r000413_16 <= 255);
    __CPROVER_assume(sec_r000413_17 >= 0 && sec_r000413_17 <= 255);
    __CPROVER_assume(sec_r000413_18 >= 0 && sec_r000413_18 <= 255);
    __CPROVER_assume(sec_r000413_19 >= 0 && sec_r000413_19 <= 255);
    __CPROVER_assume(sec_r000413_20 >= 0 && sec_r000413_20 <= 255);
    __CPROVER_assume(sec_r000413_21 >= 0 && sec_r000413_21 <= 255);
    __CPROVER_assume(sec_r000413_22 >= 0 && sec_r000413_22 <= 255);
    __CPROVER_assume(sec_r000413_23 >= 0 && sec_r000413_23 <= 255);

    struct CipherContext_R000413_1313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000413_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000413_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000413_0 + 7) & 15;
    struct MatrixBlock_R000413_1313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000413_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000413_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000413_0 + 9) & 15;
    struct SensorNode_R000413_1313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000413_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000413_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000413_0 + 11) & 15;
    struct StreamBuffer_R000413_1313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000413_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000413_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000413_0 + 13) & 15;

    union ColorPixel_R000413_1313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 17) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 32) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 25) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 40) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 33) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 48) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 27) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 42) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 15) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 30) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 26) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 41) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 23) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 38) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 36) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 51) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 28) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 43) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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
    int stage_v_54 = (st_var_2.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 12) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 27) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 13) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 28) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 23) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 38) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 20) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 35) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_3.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 23) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 38) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (sec_r000413_15 + pub_r000413_13 + 16) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000413_5) & 127;
    st_var_1.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (sub_step_81 + pub_r000413_8 + 9) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (sec_r000413_16 + pub_r000413_13 + 18) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000413_6) & 127;
    st_var_3.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (stage_v_83 + pub_r000413_11 + 32) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000413_14) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (stage_v_82 + pub_r000413_3 + 21) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000413_4) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (sub_step_81 + pub_r000413_11 + 6) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (sec_r000413_0 + pub_r000413_7 + 19) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000413_5) & 127;
    st_var_3.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (stage_v_82 + pub_r000413_3 + 8) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000413_1) & 127;
    st_var_0.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (stage_v_86 + pub_r000413_0 + 31) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000413_11) & 127;
    st_var_1.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sub_step_84 + pub_r000413_0 + 18) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000413_11) & 127;
    st_var_2.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sec_r000413_11 + pub_r000413_0 + 25) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000413_10) & 127;
    st_var_3.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (sec_r000413_12 + pub_r000413_7 + 27) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000413_1) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (stage_v_87 + pub_r000413_9 + 6) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000413_15) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sec_r000413_9 + pub_r000413_11 + 23) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000413_5) & 127;
    st_var_2.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sub_step_94 + pub_r000413_3 + 8) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sec_r000413_19 + pub_r000413_0 + 10) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000413_9) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (sec_r000413_4 + pub_r000413_10 + 23) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000413_14) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sub_step_94 + pub_r000413_14 + 26) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000413_3) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (stage_v_89 + pub_r000413_14 + 14) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (sec_r000413_18 + pub_r000413_11 + 13) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000413_5) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (sub_step_93 + pub_r000413_14 + 35) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000413_3) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sub_step_93 + pub_r000413_11 + 16) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000413_3) & 127;
    st_var_2.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sec_r000413_14 + pub_r000413_3 + 25) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000413_7) & 127;
    st_var_3.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (stage_v_91 + pub_r000413_13 + 20) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000413_8) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sub_step_88 + pub_r000413_8 + 32) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000413_11) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (stage_v_90 + pub_r000413_8 + 7) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000413_14) & 127;
    st_var_2.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (sec_r000413_8 + pub_r000413_8 + 29) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000413_9) & 127;
    st_var_3.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sub_step_103 + pub_r000413_7 + 32) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000413_5) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (stage_v_87 + pub_r000413_12 + 30) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000413_7) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (sub_step_92 + pub_r000413_2 + 26) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000413_13) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (sub_step_88 + pub_r000413_4 + 25) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000413_8) & 127;
    st_var_3.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000413_5 + pub_r000413_9 + 25) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000413_15) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (stage_v_84 + pub_r000413_14 + 27) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000413_5) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (sec_r000413_18 + pub_r000413_7 + 6) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000413_9) & 127;
    st_var_2.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_110 + pub_r000413_0 + 9) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000413_5) & 127;
    st_var_3.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (stage_v_97 + pub_r000413_12 + 13) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000413_10) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sub_step_109 + pub_r000413_0 + 16) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000413_10) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (stage_v_81 + pub_r000413_11 + 13) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000413_11) & 127;
    st_var_2.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sub_step_84 + pub_r000413_12 + 18) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000413_13) & 127;
    st_var_3.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sec_r000413_5 + pub_r000413_11 + 6) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000413_7) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (stage_v_110 + pub_r000413_8 + 23) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000413_3) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (stage_v_92 + pub_r000413_4 + 13) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000413_13) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sub_step_121 + pub_r000413_3 + 21) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000413_9) & 127;
    st_var_3.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sub_step_94 + pub_r000413_10 + 13) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000413_5) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sec_r000413_11 + pub_r000413_4 + 23) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000413_8) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (sec_r000413_23 + pub_r000413_12 + 10) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000413_8) & 127;
    st_var_2.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (stage_v_113 + pub_r000413_0 + 33) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000413_13) & 127;
    st_var_3.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (stage_v_115 + pub_r000413_7 + 21) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000413_11) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (stage_v_116 + pub_r000413_2 + 25) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000413_1) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sec_r000413_9 + pub_r000413_1 + 18) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000413_1) & 127;
    st_var_2.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (stage_v_92 + pub_r000413_7 + 31) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000413_14) & 127;
    st_var_3.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (sec_r000413_5 + pub_r000413_1 + 35) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000413_4) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (stage_v_115 + pub_r000413_4 + 20) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000413_4) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sub_step_111 + pub_r000413_8 + 18) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000413_9) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (stage_v_115 + pub_r000413_13 + 10) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sub_step_85 + pub_r000413_13 + 6) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000413_1) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sub_step_92 + pub_r000413_12 + 14) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000413_0) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (stage_v_128 + pub_r000413_0 + 26) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000413_14) & 127;
    st_var_2.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sub_step_92 + pub_r000413_10 + 22) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000413_0) & 127;
    st_var_3.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sub_step_102 + pub_r000413_11 + 16) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000413_12) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sec_r000413_18 + pub_r000413_15 + 26) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000413_4) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sec_r000413_12 + pub_r000413_10 + 15) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000413_3) & 127;
    st_var_2.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sec_r000413_19 + pub_r000413_6 + 12) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (sub_step_97 + pub_r000413_5 + 23) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000413_5) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (sub_step_106 + pub_r000413_4 + 22) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000413_10) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sub_step_94 + pub_r000413_13 + 32) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000413_9) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sec_r000413_1 + pub_r000413_15 + 5) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000413_13) & 127;
    st_var_3.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000413_18 + pub_r000413_0 + 32) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000413_6) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (sec_r000413_14 + pub_r000413_10 + 14) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000413_13) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (sub_step_112 + pub_r000413_15 + 34) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000413_5) & 127;
    st_var_2.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (stage_v_138 + pub_r000413_1 + 25) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000413_2) & 127;
    st_var_3.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sub_step_101 + pub_r000413_8 + 31) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000413_10) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (sub_step_113 + pub_r000413_3 + 35) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000413_8) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (sub_step_141 + pub_r000413_5 + 19) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000413_2) & 127;
    st_var_2.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sec_r000413_6 + pub_r000413_4 + 23) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000413_7) & 127;
    st_var_3.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sub_step_132 + pub_r000413_11 + 26) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000413_2) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sec_r000413_19 + pub_r000413_8 + 29) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000413_0) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (stage_v_96 + pub_r000413_7 + 16) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000413_2) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sec_r000413_2 + pub_r000413_3 + 8) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (sub_step_137 + pub_r000413_12 + 6) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000413_13) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (sub_step_135 + pub_r000413_4 + 24) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000413_13) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (stage_v_148 + pub_r000413_13 + 33) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000413_6) & 127;
    st_var_2.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_102 + pub_r000413_6 + 5) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000413_6) & 127;
    st_var_3.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sec_r000413_9 + pub_r000413_14 + 29) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000413_7) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (sec_r000413_18 + pub_r000413_13 + 23) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000413_6) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sec_r000413_14 + pub_r000413_9 + 14) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000413_12) & 127;
    st_var_2.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (sec_r000413_11 + pub_r000413_3 + 12) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000413_11) & 127;
    st_var_3.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sec_r000413_11 + pub_r000413_6 + 21) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000413_8) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sub_step_133 + pub_r000413_3 + 15) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000413_7) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sec_r000413_18 + pub_r000413_3 + 35) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000413_13) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (stage_v_107 + pub_r000413_12 + 14) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000413_0) & 127;
    st_var_3.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sec_r000413_7 + pub_r000413_2 + 7) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000413_6) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (sec_r000413_10 + pub_r000413_9 + 13) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000413_4) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sec_r000413_3 + pub_r000413_15 + 17) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000413_9) & 127;
    st_var_2.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (stage_v_126 + pub_r000413_5 + 32) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000413_3) & 127;
    st_var_3.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (stage_v_170 + pub_r000413_11 + 29) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000413_8) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (stage_v_162 + pub_r000413_1 + 16) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000413_14) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sec_r000413_0 + pub_r000413_14 + 12) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000413_8) & 127;
    st_var_2.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sec_r000413_15 + pub_r000413_13 + 19) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000413_1) & 127;
    st_var_3.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (stage_v_105 + pub_r000413_0 + 33) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000413_7) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sub_step_111 + pub_r000413_11 + 26) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000413_12) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sec_r000413_21 + pub_r000413_3 + 12) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000413_6) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sub_step_108 + pub_r000413_7 + 22) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000413_13) & 127;
    st_var_3.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (sec_r000413_0 + pub_r000413_0 + 10) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000413_3) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (stage_v_128 + pub_r000413_8 + 18) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000413_0) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (stage_v_89 + pub_r000413_5 + 31) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (sub_step_186 + pub_r000413_11 + 35) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000413_5) & 127;
    st_var_3.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sub_step_113 + pub_r000413_0 + 33) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000413_13) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sub_step_93 + pub_r000413_7 + 20) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000413_1) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (stage_v_176 + pub_r000413_13 + 34) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (stage_v_117 + pub_r000413_8 + 14) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000413_7) & 127;
    st_var_3.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sec_r000413_15 + pub_r000413_11 + 29) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000413_0) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sec_r000413_0 + pub_r000413_9 + 28) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000413_9) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (stage_v_188 + pub_r000413_7 + 25) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000413_14) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sec_r000413_1 + pub_r000413_0 + 26) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000413_3) & 127;
    st_var_3.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (sub_step_131 + pub_r000413_11 + 21) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000413_0) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sub_step_180 + pub_r000413_13 + 32) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000413_3) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sub_step_98 + pub_r000413_11 + 11) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000413_2) & 127;
    st_var_2.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (stage_v_174 + pub_r000413_8 + 22) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sub_step_85 + pub_r000413_10 + 21) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000413_3) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sub_step_109 + pub_r000413_2 + 6) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000413_15) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (sec_r000413_13 + pub_r000413_8 + 33) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000413_12) & 127;
    st_var_2.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sub_step_169 + pub_r000413_4 + 5) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000413_2) & 127;
    st_var_3.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sub_step_148 + pub_r000413_0 + 15) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000413_14) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sec_r000413_6 + pub_r000413_5 + 33) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000413_13) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (stage_v_165 + pub_r000413_12 + 32) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (sub_step_186 + pub_r000413_11 + 10) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sub_step_147 + pub_r000413_7 + 21) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000413_6) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (stage_v_110 + pub_r000413_14 + 24) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000413_4) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (sec_r000413_12 + pub_r000413_9 + 30) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000413_14) & 127;
    st_var_2.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sub_step_175 + pub_r000413_4 + 24) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000413_15) & 127;
    st_var_3.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sec_r000413_6 + pub_r000413_1 + 7) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000413_15) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (sub_step_180 + pub_r000413_14 + 31) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000413_15) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (sec_r000413_2 + pub_r000413_1 + 27) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000413_7) & 127;
    st_var_2.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_91 + pub_r000413_15 + 33) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000413_12) & 127;
    st_var_3.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (stage_v_193 + pub_r000413_0 + 8) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000413_12) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sub_step_108 + pub_r000413_12 + 11) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000413_11) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (sub_step_163 + pub_r000413_3 + 31) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sub_step_175 + pub_r000413_7 + 23) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000413_4) & 127;
    st_var_3.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (stage_v_89 + pub_r000413_7 + 11) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000413_13) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sub_step_132 + pub_r000413_3 + 34) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000413_10) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (stage_v_129 + pub_r000413_8 + 5) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000413_7) & 127;
    st_var_2.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sub_step_104 + pub_r000413_6 + 18) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000413_9) & 127;
    st_var_3.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sub_step_116 + pub_r000413_2 + 26) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000413_15) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sub_step_121 + pub_r000413_10 + 35) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000413_8) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sec_r000413_17 + pub_r000413_3 + 19) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000413_10) & 127;
    st_var_2.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sec_r000413_15 + pub_r000413_7 + 11) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000413_0) & 127;
    st_var_3.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (stage_v_201 + pub_r000413_13 + 23) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000413_14) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (sec_r000413_10 + pub_r000413_6 + 34) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000413_0) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sec_r000413_15 + pub_r000413_2 + 20) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000413_1) & 127;
    st_var_2.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (stage_v_198 + pub_r000413_2 + 17) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000413_13) & 127;
    st_var_3.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (sec_r000413_20 + pub_r000413_13 + 35) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000413_9) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (sec_r000413_16 + pub_r000413_10 + 9) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000413_0) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sec_r000413_12 + pub_r000413_2 + 31) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000413_5) & 127;
    st_var_2.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sec_r000413_22 + pub_r000413_2 + 7) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000413_12) & 127;
    st_var_3.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (stage_v_134 + pub_r000413_9 + 31) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000413_12) & 127;
    st_var_0.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (stage_v_199 + pub_r000413_2 + 33) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000413_9) & 127;
    st_var_1.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (sec_r000413_21 + pub_r000413_2 + 30) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000413_1) & 127;
    st_var_2.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sub_step_199 + pub_r000413_12 + 27) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000413_9) & 127;
    st_var_3.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (stage_v_228 + pub_r000413_2 + 32) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000413_13) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (sub_step_157 + pub_r000413_9 + 22) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000413_13) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sec_r000413_19 + pub_r000413_13 + 30) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000413_12) & 127;
    st_var_2.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (stage_v_109 + pub_r000413_7 + 21) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000413_1) & 127;
    st_var_3.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (sec_r000413_23 + pub_r000413_11 + 18) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000413_8) & 127;
    st_var_0.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sec_r000413_18 + pub_r000413_10 + 14) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000413_6) & 127;
    st_var_1.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (sub_step_127 + pub_r000413_2 + 20) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (stage_v_226 + pub_r000413_10 + 33) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000413_11) & 127;
    st_var_3.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (sub_step_100 + pub_r000413_10 + 17) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000413_10) & 127;
    st_var_0.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (stage_v_97 + pub_r000413_1 + 16) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000413_8) & 127;
    st_var_1.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (stage_v_226 + pub_r000413_15 + 17) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (stage_v_161 + pub_r000413_14 + 25) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000413_12) & 127;
    st_var_3.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (sub_step_225 + pub_r000413_5 + 6) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000413_5) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (sub_step_158 + pub_r000413_7 + 27) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000413_7) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (sec_r000413_19 + pub_r000413_15 + 26) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000413_2) & 127;
    st_var_2.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (stage_v_246 + pub_r000413_10 + 12) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000413_5) & 127;
    st_var_3.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (sec_r000413_21 + pub_r000413_5 + 32) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000413_7) & 127;
    st_var_0.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int sub_step_257 = (sec_r000413_17 + pub_r000413_4 + 10) & 127;
    int stage_v_257 = (sub_step_257 * 2 + pub_r000413_10) & 127;
    st_var_1.buffer[2] = (stage_v_257 & 15);
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int sub_step_258 = (stage_v_228 + pub_r000413_3 + 10) & 127;
    int stage_v_258 = (sub_step_258 * 2 + pub_r000413_0) & 127;
    st_var_2.buffer[0] = (stage_v_258 & 15);
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int sub_step_259 = (stage_v_156 + pub_r000413_8 + 23) & 127;
    int stage_v_259 = (sub_step_259 * 2 + pub_r000413_6) & 127;
    st_var_3.buffer[1] = (stage_v_259 & 15);
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int sub_step_260 = (stage_v_217 + pub_r000413_8 + 12) & 127;
    int stage_v_260 = (sub_step_260 * 2 + pub_r000413_9) & 127;
    st_var_0.buffer[2] = (stage_v_260 & 15);
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int sub_step_261 = (sub_step_218 + pub_r000413_15 + 31) & 127;
    int stage_v_261 = (sub_step_261 * 2 + pub_r000413_7) & 127;
    st_var_1.buffer[0] = (stage_v_261 & 15);
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int sub_step_262 = (stage_v_94 + pub_r000413_0 + 24) & 127;
    int stage_v_262 = (sub_step_262 * 2 + pub_r000413_15) & 127;
    st_var_2.buffer[1] = (stage_v_262 & 15);
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int sub_step_263 = (stage_v_131 + pub_r000413_6 + 15) & 127;
    int stage_v_263 = (sub_step_263 * 2 + pub_r000413_2) & 127;
    st_var_3.buffer[2] = (stage_v_263 & 15);
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int sub_step_264 = (sec_r000413_1 + pub_r000413_0 + 18) & 127;
    int stage_v_264 = (sub_step_264 * 2 + pub_r000413_2) & 127;
    st_var_0.buffer[0] = (stage_v_264 & 15);
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int sub_step_265 = (sub_step_241 + pub_r000413_2 + 32) & 127;
    int stage_v_265 = (sub_step_265 * 2 + pub_r000413_14) & 127;
    st_var_1.buffer[1] = (stage_v_265 & 15);
    out_sink = (out_sink + stage_v_265) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
