/*
 * Benchmark Program: R000218
 * Security Family: secret_dependent_loops
 * Generator Seed: 521813
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000218_1813_0 {
    short dim;
    unsigned char determinant;
    int scale;
    int stride;
    int density;
    short trace;
    int buffer[3];
};

struct FilterState_R000218_1813_1 {
    int damping;
    short cutoff;
    int prev_out;
    unsigned char gain_db;
    int prev_in;
    short mode;
    int buffer[3];
};

union ColorPixel_R000218_1813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000218_1813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_43 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_43 > 14) {
        acc = (acc + coefficient_43 * 2 + 5) & 127;
        aux ^= (coefficient_43 & 15);
    } else {
        acc = (acc - coefficient_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000218_1813_1(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quantum_42 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_42 > 48) {
        acc = (acc + quantum_42 * 2 + 5) & 127;
        aux ^= (quantum_42 & 15);
    } else {
        acc = (acc - quantum_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_90 = local_arr[aux % 3];
    acc = (acc + phase_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000218_1813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int metric_89 = local_arr[aux % 3];
    acc = (acc + metric_89 * 2) & 127;
    int pivot_45 = (aux + st.buffer[1]) & 3;
    switch (pivot_45) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_43) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000218_1813_3(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int sample_74 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_74 > 12) {
        acc = (acc + sample_74 * 2 + 5) & 127;
        aux ^= (sample_74 & 15);
    } else {
        acc = (acc - sample_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000218_1813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_10 = local_arr[aux % 3];
    acc = (acc + sample_10 * 2) & 127;
    int phase_79 = (aux + st.buffer[1]) & 3;
    switch (phase_79) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_77 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_77 > 17) {
        acc = (acc + pivot_77 * 2 + 5) & 127;
        aux ^= (pivot_77 & 15);
    } else {
        acc = (acc - pivot_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000218_1813_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000218_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int anchor_71 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_71 > 44) {
        acc = (acc + anchor_71 * 2 + 5) & 127;
        aux ^= (anchor_71 & 15);
    } else {
        acc = (acc - anchor_71 + 11) & 127;
        aux += 3;
    }
    int metric_86 = (aux + st.buffer[1]) & 3;
    switch (metric_86) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000218_1813_6(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000218_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_96 = local_arr[aux % 3];
    acc = (acc + cursor_96 * 2) & 127;
    int parity_50 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_50 > 26) {
        acc = (acc + parity_50 * 2 + 5) & 127;
        aux ^= (parity_50 & 15);
    } else {
        acc = (acc - parity_50 + 11) & 127;
        aux += 3;
    }
    int window_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000218_1813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000218_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_54) & 63;
    acc ^= aux;
    int residue_78 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_78 > 17) {
        acc = (acc + residue_78 * 2 + 5) & 127;
        aux ^= (residue_78 & 15);
    } else {
        acc = (acc - residue_78 + 11) & 127;
        aux += 3;
    }
    int anchor_76 = (aux + st.buffer[1]) & 3;
    switch (anchor_76) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000218_1813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_30 = (aux + st.buffer[1]) & 3;
    switch (factor_30) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_52 = local_arr[aux % 3];
    acc = (acc + anchor_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000218_1813_9(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000218_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int index_reg_86 = (aux + st.buffer[1]) & 3;
    switch (index_reg_86) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000218_1813_10(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000218_1813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_11 = (aux + st.buffer[1]) & 3;
    switch (quotient_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000218_1813_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_90 = local_arr[aux % 3];
    acc = (acc + scale_90 * 2) & 127;
    int weight_51 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_51 > 42) {
        acc = (acc + weight_51 * 2 + 5) & 127;
        aux ^= (weight_51 & 15);
    } else {
        acc = (acc - weight_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000218_1813_12(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int threshold_91 = (aux + st.buffer[1]) & 3;
    switch (threshold_91) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_46) & 63;
    acc ^= aux;
    int accumulator_38 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_38 > 31) {
        acc = (acc + accumulator_38 * 2 + 5) & 127;
        aux ^= (accumulator_38 & 15);
    } else {
        acc = (acc - accumulator_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_35 = local_arr[aux % 3];
    acc = (acc + damping_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000218_1813_13(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int stride_26 = (aux + st.buffer[1]) & 3;
    switch (stride_26) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_85 = local_arr[aux % 3];
    acc = (acc + sample_85 * 2) & 127;
    int damping_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_34) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000218_1813_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000218_1813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int phase_58 = local_arr[aux % 3];
    acc = (acc + phase_58 * 2) & 127;
    int window_57 = (st.buffer[0] * 3 + aux) & 63;
    if (window_57 > 43) {
        acc = (acc + window_57 * 2 + 5) & 127;
        aux ^= (window_57 & 15);
    } else {
        acc = (acc - window_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000218_0;
    int sec_r000218_1;
    int sec_r000218_2;
    int sec_r000218_3;
    int sec_r000218_4;
    int sec_r000218_5;
    int sec_r000218_6;
    int sec_r000218_7;
    int sec_r000218_8;
    int sec_r000218_9;
    int sec_r000218_10;
    int sec_r000218_11;
    int sec_r000218_12;
    int sec_r000218_13;
    int sec_r000218_14;
    int sec_r000218_15;
    int sec_r000218_16;
    int pub_r000218_0;
    int pub_r000218_1;
    int pub_r000218_2;
    int pub_r000218_3;
    int pub_r000218_4;
    int pub_r000218_5;
    int pub_r000218_6;
    int pub_r000218_7;
    int pub_r000218_8;
    int pub_r000218_9;
    int pub_r000218_10;
    int pub_r000218_11;
    int pub_r000218_12;
    int pub_r000218_13;
    int pub_r000218_14;
    int pub_r000218_15;
    int pub_r000218_16;
    int pub_r000218_17;
    int pub_r000218_18;
    int pub_r000218_19;
    int pub_r000218_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000218_0 >= -100 && pub_r000218_0 <= 100);
    __CPROVER_assume(pub_r000218_1 >= -100 && pub_r000218_1 <= 100);
    __CPROVER_assume(pub_r000218_2 >= -100 && pub_r000218_2 <= 100);
    __CPROVER_assume(pub_r000218_3 >= -100 && pub_r000218_3 <= 100);
    __CPROVER_assume(pub_r000218_4 >= -100 && pub_r000218_4 <= 100);
    __CPROVER_assume(pub_r000218_5 >= -100 && pub_r000218_5 <= 100);
    __CPROVER_assume(pub_r000218_6 >= -100 && pub_r000218_6 <= 100);
    __CPROVER_assume(pub_r000218_7 >= -100 && pub_r000218_7 <= 100);
    __CPROVER_assume(pub_r000218_8 >= -100 && pub_r000218_8 <= 100);
    __CPROVER_assume(pub_r000218_9 >= -100 && pub_r000218_9 <= 100);
    __CPROVER_assume(pub_r000218_10 >= -100 && pub_r000218_10 <= 100);
    __CPROVER_assume(pub_r000218_11 >= -100 && pub_r000218_11 <= 100);
    __CPROVER_assume(pub_r000218_12 >= -100 && pub_r000218_12 <= 100);
    __CPROVER_assume(pub_r000218_13 >= -100 && pub_r000218_13 <= 100);
    __CPROVER_assume(pub_r000218_14 >= -100 && pub_r000218_14 <= 100);
    __CPROVER_assume(pub_r000218_15 >= -100 && pub_r000218_15 <= 100);
    __CPROVER_assume(pub_r000218_16 >= -100 && pub_r000218_16 <= 100);
    __CPROVER_assume(pub_r000218_17 >= -100 && pub_r000218_17 <= 100);
    __CPROVER_assume(pub_r000218_18 >= -100 && pub_r000218_18 <= 100);
    __CPROVER_assume(pub_r000218_19 >= -100 && pub_r000218_19 <= 100);
    __CPROVER_assume(pub_r000218_20 >= -100 && pub_r000218_20 <= 100);
    __CPROVER_assume(sec_r000218_0 >= 0 && sec_r000218_0 <= 255);
    __CPROVER_assume(sec_r000218_1 >= 0 && sec_r000218_1 <= 255);
    __CPROVER_assume(sec_r000218_2 >= 0 && sec_r000218_2 <= 255);
    __CPROVER_assume(sec_r000218_3 >= 0 && sec_r000218_3 <= 255);
    __CPROVER_assume(sec_r000218_4 >= 0 && sec_r000218_4 <= 255);
    __CPROVER_assume(sec_r000218_5 >= 0 && sec_r000218_5 <= 255);
    __CPROVER_assume(sec_r000218_6 >= 0 && sec_r000218_6 <= 255);
    __CPROVER_assume(sec_r000218_7 >= 0 && sec_r000218_7 <= 255);
    __CPROVER_assume(sec_r000218_8 >= 0 && sec_r000218_8 <= 255);
    __CPROVER_assume(sec_r000218_9 >= 0 && sec_r000218_9 <= 255);
    __CPROVER_assume(sec_r000218_10 >= 0 && sec_r000218_10 <= 255);
    __CPROVER_assume(sec_r000218_11 >= 0 && sec_r000218_11 <= 255);
    __CPROVER_assume(sec_r000218_12 >= 0 && sec_r000218_12 <= 255);
    __CPROVER_assume(sec_r000218_13 >= 0 && sec_r000218_13 <= 255);
    __CPROVER_assume(sec_r000218_14 >= 0 && sec_r000218_14 <= 255);
    __CPROVER_assume(sec_r000218_15 >= 0 && sec_r000218_15 <= 255);
    __CPROVER_assume(sec_r000218_16 >= 0 && sec_r000218_16 <= 255);

    struct MatrixBlock_R000218_1813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000218_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000218_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000218_0 + 7) & 15;
    struct FilterState_R000218_1813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000218_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000218_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000218_0 + 9) & 15;

    union ColorPixel_R000218_1813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 35) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 50) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 11) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 26) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 39) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 54) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 32) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 47) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 20) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 35) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 27) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 42) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
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
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 25) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 40) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 10) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 25) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 32) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 47) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 13) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 28) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 30) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 45) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_11 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000218_15) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000218_11) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000218_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000218_4) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000218_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_10 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000218_1) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000218_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_11 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000218_14) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000218_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000218_0) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_10 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000218_20) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000218_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000218_13) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000218_11) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000218_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_12 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000218_11) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000218_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000218_6) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000218_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000218_1) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000218_4) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000218_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000218_8) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000218_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000218_14) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000218_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000218_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000218_17) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000218_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000218_10) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000218_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000218_20) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000218_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000218_11) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000218_9) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000218_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000218_5) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000218_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000218_4) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_6 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000218_1) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000218_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000218_3) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000218_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000218_2) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000218_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000218_18) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000218_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_15 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000218_4) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000218_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000218_17) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000218_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_16 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000218_9) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000218_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_11 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000218_5) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000218_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000218_5) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000218_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_6 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000218_9) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000218_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000218_1) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000218_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000218_10) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000218_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000218_12) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000218_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000218_18) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000218_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_2 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000218_1) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000218_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000218_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_1 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000218_18) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000218_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000218_10) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000218_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_1 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000218_16) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000218_3) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000218_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000218_11) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000218_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000218_15) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_8 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000218_5) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_14 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000218_6) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000218_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000218_8) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000218_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000218_7) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000218_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_8 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000218_11) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000218_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_11 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000218_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000218_11) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000218_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000218_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000218_3) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000218_15) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000218_10) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000218_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000218_17) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000218_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000218_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000218_20) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000218_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_16 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000218_8) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_8 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000218_7) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000218_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000218_13) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000218_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000218_8) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000218_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000218_20) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_130 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000218_12) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000218_16) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000218_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000218_9) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_8 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000218_10) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000218_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000218_18) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000218_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_11 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000218_8) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000218_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000218_20) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000218_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000218_7) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000218_7) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000218_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000218_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000218_13) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000218_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_127 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000218_5) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000218_7) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000218_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000218_15) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000218_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000218_15) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000218_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000218_16) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000218_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_9 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000218_0) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000218_15) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_3 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000218_18) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000218_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000218_13) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000218_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_0 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000218_14) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000218_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_149 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000218_17) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000218_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_151 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000218_0) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000218_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000218_6) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000218_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_141 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000218_3) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000218_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_133 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000218_4) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000218_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_16 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000218_16) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000218_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_134 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000218_8) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_4 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000218_15) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000218_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_111 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000218_19) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_135 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000218_2) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000218_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_145 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000218_0) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000218_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_163 = (stage_v_163 + step * 4 + pub_r000218_13) & 63;
        } else {
            stage_v_163 = (stage_v_163 + pub_r000218_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_164 = (stage_v_164 + step * 4 + pub_r000218_3) & 63;
        } else {
            stage_v_164 = (stage_v_164 + pub_r000218_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_13 & 1) == step) {
            stage_v_165 = (stage_v_165 + step * 4 + pub_r000218_9) & 63;
        } else {
            stage_v_165 = (stage_v_165 + pub_r000218_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_166 = (stage_v_166 + step * 4 + pub_r000218_7) & 63;
        } else {
            stage_v_166 = (stage_v_166 + pub_r000218_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000218_0 & 1) == step) {
            stage_v_167 = (stage_v_167 + step * 4 + pub_r000218_18) & 63;
        } else {
            stage_v_167 = (stage_v_167 + pub_r000218_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
