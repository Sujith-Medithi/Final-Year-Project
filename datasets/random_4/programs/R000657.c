/*
 * Benchmark Program: R000657
 * Family: nested_implicit_flow
 * Generator Seed: 465713
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000657_5713_0 {
    int facility;
    short seq;
    unsigned char code;
    int buffer[3];
};

struct Transaction_R000657_5713_1 {
    int fee;
    short account_id;
    short status;
    int buffer[3];
};

struct MatrixBlock_R000657_5713_2 {
    int density;
    short scale;
    unsigned char determinant;
    int dim;
    int buffer[3];
};

struct StreamBuffer_R000657_5713_3 {
    short capacity;
    unsigned char watermark;
    unsigned char tail;
    int buffer[3];
};

union RegisterBank_R000657_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000657_5713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000657_5713_0(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int cursor_29 = local_arr[aux % 3];
    acc = (acc + cursor_29 * 2) & 127;
    int residue_26 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_26 > 42) {
        acc = (acc + residue_26 * 2 + 5) & 127;
        aux ^= (residue_26 & 15);
    } else {
        acc = (acc - residue_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000657_5713_1(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tally_58 = 0;
    for (int k = 0; k < 3; k++) {
        tally_58 = (tally_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_58) & 127;
    }
    int coefficient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000657_5713_2(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int sample_77 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_77 > 43) {
        acc = (acc + sample_77 * 2 + 5) & 127;
        aux ^= (sample_77 & 15);
    } else {
        acc = (acc - sample_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000657_5713_3(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int factor_36 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_36 > 15) {
        acc = (acc + factor_36 * 2 + 5) & 127;
        aux ^= (factor_36 & 15);
    } else {
        acc = (acc - factor_36 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_27 = local_arr[aux % 3];
    acc = (acc + anchor_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_55 = 0;
    for (int k = 0; k < 2; k++) {
        weight_55 = (weight_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000657_5713_4(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000657_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int threshold_47 = local_arr[aux % 3];
    acc = (acc + threshold_47 * 2) & 127;
    int bound_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000657_5713_5(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int delta_81 = 0;
    for (int k = 0; k < 3; k++) {
        delta_81 = (delta_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_81) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000657_5713_6(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_68 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_68 > 17) {
        acc = (acc + residue_68 * 2 + 5) & 127;
        aux ^= (residue_68 & 15);
    } else {
        acc = (acc - residue_68 + 11) & 127;
        aux += 3;
    }
    int stride_50 = (aux + st.buffer[1]) & 3;
    switch (stride_50) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000657_5713_7(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tally_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_93) & 63;
    acc ^= aux;
    int tally_47 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_47 > 19) {
        acc = (acc + tally_47 * 2 + 5) & 127;
        aux ^= (tally_47 & 15);
    } else {
        acc = (acc - tally_47 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000657_5713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int factor_76 = (aux + st.buffer[1]) & 3;
    switch (factor_76) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_72) & 63;
    acc ^= aux;
    int metric_46 = 0;
    for (int k = 0; k < 2; k++) {
        metric_46 = (metric_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_46) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000657_5713_9(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000657_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tally_25 = 0;
    for (int k = 0; k < 2; k++) {
        tally_25 = (tally_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_25) & 127;
    }
    int phase_59 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_59 > 21) {
        acc = (acc + phase_59 * 2 + 5) & 127;
        aux ^= (phase_59 & 15);
    } else {
        acc = (acc - phase_59 + 11) & 127;
        aux += 3;
    }
    int sample_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000657_5713_10(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int bound_66 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_66 > 36) {
        acc = (acc + bound_66 * 2 + 5) & 127;
        aux ^= (bound_66 & 15);
    } else {
        acc = (acc - bound_66 + 11) & 127;
        aux += 3;
    }
    int damping_48 = 0;
    for (int k = 0; k < 2; k++) {
        damping_48 = (damping_48 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_48) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000657_5713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int margin_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_48) & 63;
    acc ^= aux;
    int metric_76 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_76 > 34) {
        acc = (acc + metric_76 * 2 + 5) & 127;
        aux ^= (metric_76 & 15);
    } else {
        acc = (acc - metric_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000657_5713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000657_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int scale_92 = 0;
    for (int k = 0; k < 3; k++) {
        scale_92 = (scale_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_92) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_97 = local_arr[aux % 3];
    acc = (acc + quotient_97 * 2) & 127;
    int mask_76 = (aux + st.buffer[1]) & 3;
    switch (mask_76) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000657_5713_13(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000657_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int offset_77 = local_arr[aux % 3];
    acc = (acc + offset_77 * 2) & 127;
    int quantum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000657_0;
    int sec_r000657_1;
    int sec_r000657_2;
    int sec_r000657_3;
    int sec_r000657_4;
    int sec_r000657_5;
    int sec_r000657_6;
    int sec_r000657_7;
    int sec_r000657_8;
    int sec_r000657_9;
    int sec_r000657_10;
    int sec_r000657_11;
    int sec_r000657_12;
    int sec_r000657_13;
    int sec_r000657_14;
    int sec_r000657_15;
    int sec_r000657_16;
    int sec_r000657_17;
    int sec_r000657_18;
    int pub_r000657_0;
    int pub_r000657_1;
    int pub_r000657_2;
    int pub_r000657_3;
    int pub_r000657_4;
    int pub_r000657_5;
    int pub_r000657_6;
    int pub_r000657_7;
    int pub_r000657_8;
    int pub_r000657_9;
    int pub_r000657_10;
    int pub_r000657_11;
    int pub_r000657_12;
    int pub_r000657_13;
    int pub_r000657_14;
    int pub_r000657_15;
    int pub_r000657_16;
    int pub_r000657_17;
    int pub_r000657_18;
    int pub_r000657_19;
    int pub_r000657_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000657_0 >= -100 && pub_r000657_0 <= 100);
    __CPROVER_assume(pub_r000657_1 >= -100 && pub_r000657_1 <= 100);
    __CPROVER_assume(pub_r000657_2 >= -100 && pub_r000657_2 <= 100);
    __CPROVER_assume(pub_r000657_3 >= -100 && pub_r000657_3 <= 100);
    __CPROVER_assume(pub_r000657_4 >= -100 && pub_r000657_4 <= 100);
    __CPROVER_assume(pub_r000657_5 >= -100 && pub_r000657_5 <= 100);
    __CPROVER_assume(pub_r000657_6 >= -100 && pub_r000657_6 <= 100);
    __CPROVER_assume(pub_r000657_7 >= -100 && pub_r000657_7 <= 100);
    __CPROVER_assume(pub_r000657_8 >= -100 && pub_r000657_8 <= 100);
    __CPROVER_assume(pub_r000657_9 >= -100 && pub_r000657_9 <= 100);
    __CPROVER_assume(pub_r000657_10 >= -100 && pub_r000657_10 <= 100);
    __CPROVER_assume(pub_r000657_11 >= -100 && pub_r000657_11 <= 100);
    __CPROVER_assume(pub_r000657_12 >= -100 && pub_r000657_12 <= 100);
    __CPROVER_assume(pub_r000657_13 >= -100 && pub_r000657_13 <= 100);
    __CPROVER_assume(pub_r000657_14 >= -100 && pub_r000657_14 <= 100);
    __CPROVER_assume(pub_r000657_15 >= -100 && pub_r000657_15 <= 100);
    __CPROVER_assume(pub_r000657_16 >= -100 && pub_r000657_16 <= 100);
    __CPROVER_assume(pub_r000657_17 >= -100 && pub_r000657_17 <= 100);
    __CPROVER_assume(pub_r000657_18 >= -100 && pub_r000657_18 <= 100);
    __CPROVER_assume(pub_r000657_19 >= -100 && pub_r000657_19 <= 100);
    __CPROVER_assume(pub_r000657_20 >= -100 && pub_r000657_20 <= 100);
    __CPROVER_assume(sec_r000657_0 >= 0 && sec_r000657_0 <= 255);
    __CPROVER_assume(sec_r000657_1 >= 0 && sec_r000657_1 <= 255);
    __CPROVER_assume(sec_r000657_2 >= 0 && sec_r000657_2 <= 255);
    __CPROVER_assume(sec_r000657_3 >= 0 && sec_r000657_3 <= 255);
    __CPROVER_assume(sec_r000657_4 >= 0 && sec_r000657_4 <= 255);
    __CPROVER_assume(sec_r000657_5 >= 0 && sec_r000657_5 <= 255);
    __CPROVER_assume(sec_r000657_6 >= 0 && sec_r000657_6 <= 255);
    __CPROVER_assume(sec_r000657_7 >= 0 && sec_r000657_7 <= 255);
    __CPROVER_assume(sec_r000657_8 >= 0 && sec_r000657_8 <= 255);
    __CPROVER_assume(sec_r000657_9 >= 0 && sec_r000657_9 <= 255);
    __CPROVER_assume(sec_r000657_10 >= 0 && sec_r000657_10 <= 255);
    __CPROVER_assume(sec_r000657_11 >= 0 && sec_r000657_11 <= 255);
    __CPROVER_assume(sec_r000657_12 >= 0 && sec_r000657_12 <= 255);
    __CPROVER_assume(sec_r000657_13 >= 0 && sec_r000657_13 <= 255);
    __CPROVER_assume(sec_r000657_14 >= 0 && sec_r000657_14 <= 255);
    __CPROVER_assume(sec_r000657_15 >= 0 && sec_r000657_15 <= 255);
    __CPROVER_assume(sec_r000657_16 >= 0 && sec_r000657_16 <= 255);
    __CPROVER_assume(sec_r000657_17 >= 0 && sec_r000657_17 <= 255);
    __CPROVER_assume(sec_r000657_18 >= 0 && sec_r000657_18 <= 255);

    struct EventLog_R000657_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000657_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000657_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000657_0 + 7) & 15;
    struct Transaction_R000657_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000657_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000657_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000657_0 + 9) & 15;
    struct MatrixBlock_R000657_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000657_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000657_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000657_0 + 11) & 15;
    struct StreamBuffer_R000657_5713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000657_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000657_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000657_0 + 13) & 15;

    union RegisterBank_R000657_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 24) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 39) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 16) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 31) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 11) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 26) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 37) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 52) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 38) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 53) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
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
    for (int step = 0; step < 3; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 18) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 33) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 19) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 34) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 21) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 36) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 16) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 31) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 10) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 25) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 29) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 44) {
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
    int stage_v_79 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] * 2 + 259) & 63;
    if (stage_v_84 > 37) {
        out_sink = (out_sink + stage_v_84 - 5) & 255;
        if (stage_v_84 > 52) {
            chk_sum ^= (stage_v_84 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_84 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (out_sink > 100) ? (chk_sum & 31) : (91 & 31);
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= (stage_v_86 << 1) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_3.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 12) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 27) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 27) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 42) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_89 = (stage_v_89 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (out_sink > 100) ? (chk_sum & 31) : (95 & 31);
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= (stage_v_90 << 1) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_3.buffer[1] * 2 + 280) & 63;
    if (stage_v_91 > 13) {
        out_sink = (out_sink + stage_v_91 - 5) & 255;
        if (stage_v_91 > 28) {
            chk_sum ^= (stage_v_91 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_91 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_3.buffer[2] * 2 + 292) & 63;
    if (stage_v_95 > 35) {
        out_sink = (out_sink + stage_v_95 - 5) & 255;
        if (stage_v_95 > 50) {
            chk_sum ^= (stage_v_95 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_95 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = table[0];
    table[0] = (table[1] + 193) & 63;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (out_sink > 100) ? (chk_sum & 31) : (102 & 31);
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= (stage_v_97 << 1) & 127;

    /* Execution Pipeline Stage 98 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 99) & 15;
    int stage_v_98 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= stage_v_98;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_3.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 39) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 54) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = table[0];
    table[0] = (table[1] + 201) & 63;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 103) & 15;
    int stage_v_102 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    chk_sum ^= stage_v_102;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_3.buffer[1] * 2 + 316) & 63;
    if (stage_v_103 > 27) {
        out_sink = (out_sink + stage_v_103 - 5) & 255;
        if (stage_v_103 > 42) {
            chk_sum ^= (stage_v_103 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_103 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[0] ^ 107) & 3;
    switch (stage_v_104) {
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

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 108) & 15;
    int stage_v_107 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= stage_v_107;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
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

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 114) & 15;
    int stage_v_113 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= stage_v_113;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (out_sink > 100) ? (chk_sum & 31) : (124 & 31);
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= (stage_v_119 << 1) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_3.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 17) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 32) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_0.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_2.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 26) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 41) {
            chk_sum ^= (stage_v_130 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_130 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 131 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] ^ 135) & 3;
    switch (stage_v_132) {
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

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[1] * 2 + 415) & 63;
    if (stage_v_136 > 11) {
        out_sink = (out_sink + stage_v_136 - 5) & 255;
        if (stage_v_136 > 26) {
            chk_sum ^= (stage_v_136 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_136 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 142) & 15;
    int stage_v_141 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= stage_v_141;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = table[1];
    table[1] = (table[2] + 291) & 63;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = table[2];
    table[2] = (table[3] + 293) & 63;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_0.buffer[1] * 2 + 451) & 63;
    if (stage_v_148 > 19) {
        out_sink = (out_sink + stage_v_148 - 5) & 255;
        if (stage_v_148 > 34) {
            chk_sum ^= (stage_v_148 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_148 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (out_sink > 100) ? (chk_sum & 31) : (156 & 31);
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= (stage_v_151 << 1) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_152 = (stage_v_152 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 154) & 15;
    int stage_v_153 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= stage_v_153;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_2.buffer[1] * 2 + 469) & 63;
    if (stage_v_154 > 36) {
        out_sink = (out_sink + stage_v_154 - 5) & 255;
        if (stage_v_154 > 51) {
            chk_sum ^= (stage_v_154 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_154 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 15) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 30) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_3.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = table[1];
    table[1] = (table[2] + 323) & 63;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_2.buffer[0] ^ 165) & 3;
    switch (stage_v_162) {
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

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_3.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 16) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 31) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = table[0];
    table[0] = (table[1] + 337) & 63;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (out_sink > 100) ? (chk_sum & 31) : (174 & 31);
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= (stage_v_169 << 1) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_2.buffer[0] ^ 173) & 3;
    switch (stage_v_170) {
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

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (out_sink > 100) ? (chk_sum & 31) : (177 & 31);
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= (stage_v_172 << 1) & 127;

    /* Execution Pipeline Stage 173 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 174) & 15;
    int stage_v_173 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= stage_v_173;

    /* Execution Pipeline Stage 174 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 175) & 15;
    int stage_v_174 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= stage_v_174;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_3.buffer[0] ^ 178) & 3;
    switch (stage_v_175) {
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

    /* Execution Pipeline Stage 176 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 177) & 15;
    int stage_v_176 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= stage_v_176;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_177 = (stage_v_177 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_177) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_178 = (stage_v_178 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_3.buffer[0] ^ 182) & 3;
    switch (stage_v_179) {
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

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (st_var_1.buffer[0] ^ 184) & 3;
    switch (stage_v_181) {
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

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_182 = (stage_v_182 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_182) & 127;
    }
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (st_var_3.buffer[0] ^ 186) & 3;
    switch (stage_v_183) {
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

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_0.buffer[1] * 2 + 559) & 63;
    if (stage_v_184 > 13) {
        out_sink = (out_sink + stage_v_184 - 5) & 255;
        if (stage_v_184 > 28) {
            chk_sum ^= (stage_v_184 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_184 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (out_sink > 100) ? (chk_sum & 31) : (191 & 31);
    out_sink = (out_sink + stage_v_186) & 255;
    chk_sum ^= (stage_v_186 << 1) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (st_var_1.buffer[0] ^ 192) & 3;
    switch (stage_v_189) {
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

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = table[3];
    table[3] = (table[0] + 383) & 63;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] * 2 + 583) & 63;
    if (stage_v_192 > 16) {
        out_sink = (out_sink + stage_v_192 - 5) & 255;
        if (stage_v_192 > 31) {
            chk_sum ^= (stage_v_192 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_192 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 193 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 194) & 15;
    int stage_v_193 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    chk_sum ^= stage_v_193;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (st_var_2.buffer[0] ^ 197) & 3;
    switch (stage_v_194) {
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

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_3.buffer[0] ^ 198) & 3;
    switch (stage_v_195) {
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

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_0.buffer[0] ^ 199) & 3;
    switch (stage_v_196) {
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

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (st_var_1.buffer[2] * 2 + 598) & 63;
    if (stage_v_197 > 23) {
        out_sink = (out_sink + stage_v_197 - 5) & 255;
        if (stage_v_197 > 38) {
            chk_sum ^= (stage_v_197 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_197 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_198 = (stage_v_198 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_198) & 127;
    }
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_199 = (stage_v_199 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_199) & 127;
    }
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (st_var_0.buffer[0] ^ 203) & 3;
    switch (stage_v_200) {
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

    /* Execution Pipeline Stage 201 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 202) & 15;
    int stage_v_201 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_201) & 255;
    chk_sum ^= stage_v_201;

    /* Execution Pipeline Stage 202 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 203) & 15;
    int stage_v_202 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    chk_sum ^= stage_v_202;

    /* Execution Pipeline Stage 203 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 204) & 15;
    int stage_v_203 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_203) & 255;
    chk_sum ^= stage_v_203;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (st_var_0.buffer[0] ^ 207) & 3;
    switch (stage_v_204) {
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

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (st_var_1.buffer[0] ^ 208) & 3;
    switch (stage_v_205) {
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

    /* Security Information Flow: Family = nested_implicit_flow */
    if ((sec_r000657_5 & 1) != 0) {
        if ((sec_r000657_17 & 2) != 0) {
            out_sink += 26;
        } else {
            out_sink += 12;
        }
    } else {
        if ((sec_r000657_5 & 4) != 0) {
            out_sink -= 16;
        } else {
            out_sink -= 57;
        }
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
