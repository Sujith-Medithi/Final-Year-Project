/*
 * Benchmark Program: R001031
 * Security Family: zero_leakage
 * Generator Seed: 603113
 * High Inputs: 22 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001031_3113_0 {
    int cutoff;
    int damping;
    unsigned char prev_in;
    short prev_out;
    int buffer[3];
};

struct Transaction_R001031_3113_1 {
    int status;
    int fee;
    unsigned char balance;
    short auth_code;
    int account_id;
    int buffer[3];
};

struct MatrixBlock_R001031_3113_2 {
    short density;
    int scale;
    short stride;
    short trace;
    int dim;
    int determinant;
    int buffer[3];
};

union TelemetryField_R001031_3113_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001031_3113_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001031_3113_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001031_3113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int bound_38 = local_arr[aux % 3];
    acc = (acc + bound_38 * 2) & 127;
    int quotient_71 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_71 = (quotient_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_71) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001031_3113_1(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int window_69 = local_arr[aux % 3];
    acc = (acc + window_69 * 2) & 127;
    int cursor_45 = (aux + st.buffer[1]) & 3;
    switch (cursor_45) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_80 = 0;
    for (int k = 0; k < 2; k++) {
        weight_80 = (weight_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001031_3113_2(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int vector_19 = 0;
    for (int k = 0; k < 2; k++) {
        vector_19 = (vector_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_19) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_76 = local_arr[aux % 3];
    acc = (acc + cursor_76 * 2) & 127;
    int scale_96 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_96 > 10) {
        acc = (acc + scale_96 * 2 + 5) & 127;
        aux ^= (scale_96 & 15);
    } else {
        acc = (acc - scale_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001031_3113_3(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001031_3113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int quantum_81 = local_arr[aux % 3];
    acc = (acc + quantum_81 * 2) & 127;
    int tally_44 = 0;
    for (int k = 0; k < 2; k++) {
        tally_44 = (tally_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_44) & 127;
    }
    int cursor_70 = (aux + st.buffer[1]) & 3;
    switch (cursor_70) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001031_3113_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_42 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_42 = (threshold_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_42) & 127;
    }
    int tracker_76 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_76 > 45) {
        acc = (acc + tracker_76 * 2 + 5) & 127;
        aux ^= (tracker_76 & 15);
    } else {
        acc = (acc - tracker_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001031_3113_5(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int sample_32 = local_arr[aux % 3];
    acc = (acc + sample_32 * 2) & 127;
    int phase_71 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_71 > 16) {
        acc = (acc + phase_71 * 2 + 5) & 127;
        aux ^= (phase_71 & 15);
    } else {
        acc = (acc - phase_71 + 11) & 127;
        aux += 3;
    }
    int delta_80 = (aux + st.buffer[1]) & 3;
    switch (delta_80) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001031_3113_6(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001031_3113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int anchor_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_26) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001031_3113_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int quotient_84 = local_arr[aux % 3];
    acc = (acc + quotient_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001031_3113_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001031_3113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int stride_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_80) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_74 = (aux + st.buffer[1]) & 3;
    switch (cursor_74) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001031_3113_9(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int pivot_24 = (aux + st.buffer[1]) & 3;
    switch (pivot_24) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_70 = local_arr[aux % 3];
    acc = (acc + delta_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001031_3113_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int margin_85 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_85 > 32) {
        acc = (acc + margin_85 * 2 + 5) & 127;
        aux ^= (margin_85 & 15);
    } else {
        acc = (acc - margin_85 + 11) & 127;
        aux += 3;
    }
    int bound_69 = (aux + st.buffer[1]) & 3;
    switch (bound_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001031_3113_11(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int damping_92 = local_arr[aux % 3];
    acc = (acc + damping_92 * 2) & 127;
    int parity_30 = (aux + st.buffer[1]) & 3;
    switch (parity_30) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001031_3113_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_83 = 0;
    for (int k = 0; k < 3; k++) {
        tally_83 = (tally_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_83) & 127;
    }
    int residue_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001031_3113_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001031_3113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int quotient_61 = local_arr[aux % 3];
    acc = (acc + quotient_61 * 2) & 127;
    int quantum_51 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_51 > 36) {
        acc = (acc + quantum_51 * 2 + 5) & 127;
        aux ^= (quantum_51 & 15);
    } else {
        acc = (acc - quantum_51 + 11) & 127;
        aux += 3;
    }
    int checksum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001031_0;
    int sec_r001031_1;
    int sec_r001031_2;
    int sec_r001031_3;
    int sec_r001031_4;
    int sec_r001031_5;
    int sec_r001031_6;
    int sec_r001031_7;
    int sec_r001031_8;
    int sec_r001031_9;
    int sec_r001031_10;
    int sec_r001031_11;
    int sec_r001031_12;
    int sec_r001031_13;
    int sec_r001031_14;
    int sec_r001031_15;
    int sec_r001031_16;
    int sec_r001031_17;
    int sec_r001031_18;
    int sec_r001031_19;
    int sec_r001031_20;
    int sec_r001031_21;
    int pub_r001031_0;
    int pub_r001031_1;
    int pub_r001031_2;
    int pub_r001031_3;
    int pub_r001031_4;
    int pub_r001031_5;
    int pub_r001031_6;
    int pub_r001031_7;
    int pub_r001031_8;
    int pub_r001031_9;
    int pub_r001031_10;
    int pub_r001031_11;
    int pub_r001031_12;
    int pub_r001031_13;
    int pub_r001031_14;
    int pub_r001031_15;
    int pub_r001031_16;
    int pub_r001031_17;
    int pub_r001031_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001031_0 >= -100 && pub_r001031_0 <= 100);
    __CPROVER_assume(pub_r001031_1 >= -100 && pub_r001031_1 <= 100);
    __CPROVER_assume(pub_r001031_2 >= -100 && pub_r001031_2 <= 100);
    __CPROVER_assume(pub_r001031_3 >= -100 && pub_r001031_3 <= 100);
    __CPROVER_assume(pub_r001031_4 >= -100 && pub_r001031_4 <= 100);
    __CPROVER_assume(pub_r001031_5 >= -100 && pub_r001031_5 <= 100);
    __CPROVER_assume(pub_r001031_6 >= -100 && pub_r001031_6 <= 100);
    __CPROVER_assume(pub_r001031_7 >= -100 && pub_r001031_7 <= 100);
    __CPROVER_assume(pub_r001031_8 >= -100 && pub_r001031_8 <= 100);
    __CPROVER_assume(pub_r001031_9 >= -100 && pub_r001031_9 <= 100);
    __CPROVER_assume(pub_r001031_10 >= -100 && pub_r001031_10 <= 100);
    __CPROVER_assume(pub_r001031_11 >= -100 && pub_r001031_11 <= 100);
    __CPROVER_assume(pub_r001031_12 >= -100 && pub_r001031_12 <= 100);
    __CPROVER_assume(pub_r001031_13 >= -100 && pub_r001031_13 <= 100);
    __CPROVER_assume(pub_r001031_14 >= -100 && pub_r001031_14 <= 100);
    __CPROVER_assume(pub_r001031_15 >= -100 && pub_r001031_15 <= 100);
    __CPROVER_assume(pub_r001031_16 >= -100 && pub_r001031_16 <= 100);
    __CPROVER_assume(pub_r001031_17 >= -100 && pub_r001031_17 <= 100);
    __CPROVER_assume(pub_r001031_18 >= -100 && pub_r001031_18 <= 100);
    __CPROVER_assume(sec_r001031_0 >= 0 && sec_r001031_0 <= 255);
    __CPROVER_assume(sec_r001031_1 >= 0 && sec_r001031_1 <= 255);
    __CPROVER_assume(sec_r001031_2 >= 0 && sec_r001031_2 <= 255);
    __CPROVER_assume(sec_r001031_3 >= 0 && sec_r001031_3 <= 255);
    __CPROVER_assume(sec_r001031_4 >= 0 && sec_r001031_4 <= 255);
    __CPROVER_assume(sec_r001031_5 >= 0 && sec_r001031_5 <= 255);
    __CPROVER_assume(sec_r001031_6 >= 0 && sec_r001031_6 <= 255);
    __CPROVER_assume(sec_r001031_7 >= 0 && sec_r001031_7 <= 255);
    __CPROVER_assume(sec_r001031_8 >= 0 && sec_r001031_8 <= 255);
    __CPROVER_assume(sec_r001031_9 >= 0 && sec_r001031_9 <= 255);
    __CPROVER_assume(sec_r001031_10 >= 0 && sec_r001031_10 <= 255);
    __CPROVER_assume(sec_r001031_11 >= 0 && sec_r001031_11 <= 255);
    __CPROVER_assume(sec_r001031_12 >= 0 && sec_r001031_12 <= 255);
    __CPROVER_assume(sec_r001031_13 >= 0 && sec_r001031_13 <= 255);
    __CPROVER_assume(sec_r001031_14 >= 0 && sec_r001031_14 <= 255);
    __CPROVER_assume(sec_r001031_15 >= 0 && sec_r001031_15 <= 255);
    __CPROVER_assume(sec_r001031_16 >= 0 && sec_r001031_16 <= 255);
    __CPROVER_assume(sec_r001031_17 >= 0 && sec_r001031_17 <= 255);
    __CPROVER_assume(sec_r001031_18 >= 0 && sec_r001031_18 <= 255);
    __CPROVER_assume(sec_r001031_19 >= 0 && sec_r001031_19 <= 255);
    __CPROVER_assume(sec_r001031_20 >= 0 && sec_r001031_20 <= 255);
    __CPROVER_assume(sec_r001031_21 >= 0 && sec_r001031_21 <= 255);

    struct FilterState_R001031_3113_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001031_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001031_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001031_0 + 7) & 15;
    struct Transaction_R001031_3113_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001031_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001031_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001031_0 + 9) & 15;
    struct MatrixBlock_R001031_3113_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001031_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001031_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001031_0 + 11) & 15;

    union TelemetryField_R001031_3113_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001031_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001031_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001031_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001031_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001031_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001031_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001031_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001031_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001031_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001031_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001031_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001031_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001031_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001031_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001031_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001031_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001031_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001031_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001031_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001031_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001031_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001031_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001031_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001031_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001031_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001031_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001031_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001031_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001031_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001031_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001031_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001031_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001031_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001031_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001031_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001031_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001031_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001031_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001031_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001031_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001031_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001031_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001031_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001031_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001031_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001031_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001031_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001031_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001031_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001031_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001031_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001031_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001031_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001031_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001031_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001031_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001031_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001031_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001031_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001031_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001031_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001031_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001031_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001031_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001031_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001031_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001031_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001031_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001031_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001031_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001031_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001031_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001031_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001031_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001031_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001031_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001031_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001031_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001031_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001031_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001031_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001031_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001031_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001031_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001031_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001031_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001031_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001031_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001031_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001031_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001031_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001031_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001031_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001031_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001031_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001031_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001031_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001031_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001031_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001031_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001031_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001031_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001031_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001031_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001031_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001031_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001031_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001031_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001031_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001031_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001031_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001031_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001031_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001031_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001031_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001031_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001031_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001031_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001031_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001031_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001031_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001031_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001031_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001031_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001031_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001031_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001031_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001031_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001031_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001031_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001031_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001031_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001031_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001031_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001031_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001031_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001031_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001031_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001031_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001031_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001031_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001031_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001031_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001031_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001031_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001031_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001031_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001031_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001031_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001031_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001031_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001031_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001031_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001031_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001031_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001031_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001031_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001031_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001031_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001031_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001031_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001031_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001031_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001031_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001031_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001031_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001031_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001031_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001031_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001031_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001031_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001031_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001031_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001031_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001031_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001031_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001031_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001031_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001031_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001031_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001031_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001031_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001031_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001031_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001031_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001031_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001031_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001031_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001031_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001031_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001031_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001031_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001031_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001031_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001031_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001031_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001031_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001031_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001031_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001031_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001031_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001031_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001031_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001031_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001031_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001031_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001031_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001031_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001031_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001031_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001031_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001031_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001031_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001031_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001031_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001031_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001031_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001031_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001031_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001031_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001031_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001031_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001031_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001031_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001031_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001031_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001031_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001031_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001031_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001031_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001031_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001031_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001031_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001031_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001031_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001031_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001031_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001031_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001031_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001031_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001031_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001031_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001031_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001031_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001031_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001031_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001031_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001031_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001031_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001031_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001031_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001031_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001031_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001031_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001031_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001031_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001031_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001031_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001031_18 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001031_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001031_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001031_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001031_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001031_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001031_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001031_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001031_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001031_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001031_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001031_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001031_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001031_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001031_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001031_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001031_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001031_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001031_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001031_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001031_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001031_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001031_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001031_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001031_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001031_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001031_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001031_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001031_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001031_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001031_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001031_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001031_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001031_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001031_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001031_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001031_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001031_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001031_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001031_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001031_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001031_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001031_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001031_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001031_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001031_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001031_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001031_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001031_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001031_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001031_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001031_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001031_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001031_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001031_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001031_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001031_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001031_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001031_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001031_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001031_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001031_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001031_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001031_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001031_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001031_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001031_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001031_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001031_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001031_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001031_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001031_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001031_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001031_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001031_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001031_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001031_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001031_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001031_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001031_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001031_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001031_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001031_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001031_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001031_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001031_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001031_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001031_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001031_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001031_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001031_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001031_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001031_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001031_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001031_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001031_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001031_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001031_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001031_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001031_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001031_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001031_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001031_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001031_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001031_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001031_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001031_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001031_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001031_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001031_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001031_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001031_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001031_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001031_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001031_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001031_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001031_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001031_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001031_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001031_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001031_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001031_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001031_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001031_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001031_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001031_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001031_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001031_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001031_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001031_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001031_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001031_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001031_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001031_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001031_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001031_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001031_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001031_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001031_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001031_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001031_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001031_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001031_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001031_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001031_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001031_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001031_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001031_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001031_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001031_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001031_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001031_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001031_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001031_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001031_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001031_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001031_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001031_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001031_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001031_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001031_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001031_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001031_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001031_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001031_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001031_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001031_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001031_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001031_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001031_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001031_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001031_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001031_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001031_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001031_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001031_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001031_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001031_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001031_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001031_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001031_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001031_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001031_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001031_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001031_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001031_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001031_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001031_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001031_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001031_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001031_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001031_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001031_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001031_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001031_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001031_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001031_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001031_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001031_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001031_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001031_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001031_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001031_18 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001031_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001031_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001031_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001031_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001031_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001031_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001031_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001031_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001031_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001031_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001031_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001031_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001031_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001031_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001031_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001031_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001031_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001031_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001031_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001031_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001031_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001031_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001031_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001031_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001031_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001031_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001031_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001031_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001031_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001031_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001031_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001031_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = (pub_r001031_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_493) & 127;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001031_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001031_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = (pub_r001031_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_496) & 127;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001031_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001031_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = (pub_r001031_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_499) & 127;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001031_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001031_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001031_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001031_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = (pub_r001031_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_504) & 127;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001031_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001031_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = (pub_r001031_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_507) & 127;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = (pub_r001031_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_508) & 127;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001031_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = (pub_r001031_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_510) & 127;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001031_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = (pub_r001031_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_512) & 127;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = (pub_r001031_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_513) & 127;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = (pub_r001031_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_514) & 127;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = (pub_r001031_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_515) & 127;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = (pub_r001031_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_516) & 127;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001031_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = (pub_r001031_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_518) & 127;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = (pub_r001031_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_519) & 127;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = (pub_r001031_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_520) & 127;

    /* Execution Pipeline Stage 521 */
    int stage_v_521 = (pub_r001031_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_521) & 127;

    /* Execution Pipeline Stage 522 */
    int stage_v_522 = (pub_r001031_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_522) & 127;

    /* Execution Pipeline Stage 523 */
    int stage_v_523 = (pub_r001031_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_523) & 127;

    /* Execution Pipeline Stage 524 */
    int stage_v_524 = (pub_r001031_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_524) & 127;

    /* Execution Pipeline Stage 525 */
    int stage_v_525 = (pub_r001031_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_525) & 127;

    /* Execution Pipeline Stage 526 */
    int stage_v_526 = (pub_r001031_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_526) & 127;

    /* Execution Pipeline Stage 527 */
    int stage_v_527 = (pub_r001031_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_527) & 127;

    /* Execution Pipeline Stage 528 */
    int stage_v_528 = (pub_r001031_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_528) & 127;

    /* Execution Pipeline Stage 529 */
    int stage_v_529 = (pub_r001031_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_529) & 127;

    /* Execution Pipeline Stage 530 */
    int stage_v_530 = (pub_r001031_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_530) & 127;

    /* Execution Pipeline Stage 531 */
    int stage_v_531 = (pub_r001031_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_531) & 127;

    /* Execution Pipeline Stage 532 */
    int stage_v_532 = (pub_r001031_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_532) & 127;

    /* Execution Pipeline Stage 533 */
    int stage_v_533 = (pub_r001031_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_533) & 127;

    /* Execution Pipeline Stage 534 */
    int stage_v_534 = (pub_r001031_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_534) & 127;

    /* Execution Pipeline Stage 535 */
    int stage_v_535 = (pub_r001031_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_535) & 127;

    /* Execution Pipeline Stage 536 */
    int stage_v_536 = (pub_r001031_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_536) & 127;

    /* Execution Pipeline Stage 537 */
    int stage_v_537 = (pub_r001031_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_537) & 127;

    /* Execution Pipeline Stage 538 */
    int stage_v_538 = (pub_r001031_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_538) & 127;

    /* Execution Pipeline Stage 539 */
    int stage_v_539 = (pub_r001031_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_539) & 127;

    /* Execution Pipeline Stage 540 */
    int stage_v_540 = (pub_r001031_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_540) & 127;

    /* Execution Pipeline Stage 541 */
    int stage_v_541 = (pub_r001031_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_541) & 127;

    /* Execution Pipeline Stage 542 */
    int stage_v_542 = (pub_r001031_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_542) & 127;

    /* Execution Pipeline Stage 543 */
    int stage_v_543 = (pub_r001031_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_543) & 127;

    /* Execution Pipeline Stage 544 */
    int stage_v_544 = (pub_r001031_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_544) & 127;

    /* Execution Pipeline Stage 545 */
    int stage_v_545 = (pub_r001031_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_545) & 127;

    /* Execution Pipeline Stage 546 */
    int stage_v_546 = (pub_r001031_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_546) & 127;

    /* Execution Pipeline Stage 547 */
    int stage_v_547 = (pub_r001031_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_547) & 127;

    /* Execution Pipeline Stage 548 */
    int stage_v_548 = (pub_r001031_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_548) & 127;

    /* Execution Pipeline Stage 549 */
    int stage_v_549 = (pub_r001031_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_549) & 127;

    /* Execution Pipeline Stage 550 */
    int stage_v_550 = (pub_r001031_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_550) & 127;

    /* Execution Pipeline Stage 551 */
    int stage_v_551 = (pub_r001031_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_551) & 127;

    /* Execution Pipeline Stage 552 */
    int stage_v_552 = (pub_r001031_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_552) & 127;

    /* Execution Pipeline Stage 553 */
    int stage_v_553 = (pub_r001031_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_553) & 127;

    /* Execution Pipeline Stage 554 */
    int stage_v_554 = (pub_r001031_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_554) & 127;

    /* Execution Pipeline Stage 555 */
    int stage_v_555 = (pub_r001031_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_555) & 127;

    /* Execution Pipeline Stage 556 */
    int stage_v_556 = (pub_r001031_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_556) & 127;

    /* Execution Pipeline Stage 557 */
    int stage_v_557 = (pub_r001031_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_557) & 127;

    /* Execution Pipeline Stage 558 */
    int stage_v_558 = (pub_r001031_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_558) & 127;

    /* Execution Pipeline Stage 559 */
    int stage_v_559 = (pub_r001031_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_559) & 127;

    /* Execution Pipeline Stage 560 */
    int stage_v_560 = (pub_r001031_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_560) & 127;

    /* Execution Pipeline Stage 561 */
    int stage_v_561 = (pub_r001031_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_561) & 127;

    /* Execution Pipeline Stage 562 */
    int stage_v_562 = (pub_r001031_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_562) & 127;

    /* Execution Pipeline Stage 563 */
    int stage_v_563 = (pub_r001031_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_563) & 127;

    /* Execution Pipeline Stage 564 */
    int stage_v_564 = (pub_r001031_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_564) & 127;

    /* Execution Pipeline Stage 565 */
    int stage_v_565 = (pub_r001031_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_565) & 127;

    /* Execution Pipeline Stage 566 */
    int stage_v_566 = (pub_r001031_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_566) & 127;

    /* Execution Pipeline Stage 567 */
    int stage_v_567 = (pub_r001031_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_567) & 127;

    /* Execution Pipeline Stage 568 */
    int stage_v_568 = (pub_r001031_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_568) & 127;

    /* Execution Pipeline Stage 569 */
    int stage_v_569 = (pub_r001031_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_569) & 127;

    /* Execution Pipeline Stage 570 */
    int stage_v_570 = (pub_r001031_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_570) & 127;

    /* Execution Pipeline Stage 571 */
    int stage_v_571 = (pub_r001031_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_571) & 127;

    /* Execution Pipeline Stage 572 */
    int stage_v_572 = (pub_r001031_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_572) & 127;

    /* Execution Pipeline Stage 573 */
    int stage_v_573 = (pub_r001031_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_573) & 127;

    /* Execution Pipeline Stage 574 */
    int stage_v_574 = (pub_r001031_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_574) & 127;

    /* Execution Pipeline Stage 575 */
    int stage_v_575 = (pub_r001031_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_575) & 127;

    /* Execution Pipeline Stage 576 */
    int stage_v_576 = (pub_r001031_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_576) & 127;

    /* Execution Pipeline Stage 577 */
    int stage_v_577 = (pub_r001031_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_577) & 127;

    /* Execution Pipeline Stage 578 */
    int stage_v_578 = (pub_r001031_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_578) & 127;

    /* Execution Pipeline Stage 579 */
    int stage_v_579 = (pub_r001031_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_579) & 127;

    /* Execution Pipeline Stage 580 */
    int stage_v_580 = (pub_r001031_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_580) & 127;

    /* Execution Pipeline Stage 581 */
    int stage_v_581 = (pub_r001031_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_581) & 127;

    /* Execution Pipeline Stage 582 */
    int stage_v_582 = (pub_r001031_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_582) & 127;

    /* Execution Pipeline Stage 583 */
    int stage_v_583 = (pub_r001031_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_583) & 127;

    /* Execution Pipeline Stage 584 */
    int stage_v_584 = (pub_r001031_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_584) & 127;

    /* Execution Pipeline Stage 585 */
    int stage_v_585 = (pub_r001031_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_585) & 127;

    /* Execution Pipeline Stage 586 */
    int stage_v_586 = (pub_r001031_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_586) & 127;

    /* Execution Pipeline Stage 587 */
    int stage_v_587 = (pub_r001031_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_587) & 127;

    /* Execution Pipeline Stage 588 */
    int stage_v_588 = (pub_r001031_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_588) & 127;

    /* Execution Pipeline Stage 589 */
    int stage_v_589 = (pub_r001031_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_589) & 127;

    /* Execution Pipeline Stage 590 */
    int stage_v_590 = (pub_r001031_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_590) & 127;

    /* Execution Pipeline Stage 591 */
    int stage_v_591 = (pub_r001031_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_591) & 127;

    /* Execution Pipeline Stage 592 */
    int stage_v_592 = (pub_r001031_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_592) & 127;

    /* Execution Pipeline Stage 593 */
    int stage_v_593 = (pub_r001031_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_593) & 127;

    /* Execution Pipeline Stage 594 */
    int stage_v_594 = (pub_r001031_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_594) & 127;

    /* Execution Pipeline Stage 595 */
    int stage_v_595 = (pub_r001031_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_595) & 127;

    /* Execution Pipeline Stage 596 */
    int stage_v_596 = (pub_r001031_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_596) & 127;

    /* Execution Pipeline Stage 597 */
    int stage_v_597 = (pub_r001031_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_597) & 127;

    /* Execution Pipeline Stage 598 */
    int stage_v_598 = (pub_r001031_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_598) & 127;

    /* Execution Pipeline Stage 599 */
    int stage_v_599 = (pub_r001031_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_599) & 127;

    /* Execution Pipeline Stage 600 */
    int stage_v_600 = (pub_r001031_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_600) & 127;

    /* Execution Pipeline Stage 601 */
    int stage_v_601 = (pub_r001031_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_601) & 127;

    /* Execution Pipeline Stage 602 */
    int stage_v_602 = (pub_r001031_18 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_602) & 127;

    /* Execution Pipeline Stage 603 */
    int stage_v_603 = (pub_r001031_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_603) & 127;

    /* Execution Pipeline Stage 604 */
    int stage_v_604 = (pub_r001031_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_604) & 127;

    /* Execution Pipeline Stage 605 */
    int stage_v_605 = (pub_r001031_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_605) & 127;

    /* Execution Pipeline Stage 606 */
    int stage_v_606 = (pub_r001031_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_606) & 127;

    /* Execution Pipeline Stage 607 */
    int stage_v_607 = (pub_r001031_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_607) & 127;

    /* Execution Pipeline Stage 608 */
    int stage_v_608 = (pub_r001031_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_608) & 127;

    /* Execution Pipeline Stage 609 */
    int stage_v_609 = (pub_r001031_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_609) & 127;

    /* Execution Pipeline Stage 610 */
    int stage_v_610 = (pub_r001031_13 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_610) & 127;

    /* Execution Pipeline Stage 611 */
    int stage_v_611 = (pub_r001031_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_611) & 127;

    /* Execution Pipeline Stage 612 */
    int stage_v_612 = (pub_r001031_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_612) & 127;

    /* Execution Pipeline Stage 613 */
    int stage_v_613 = (pub_r001031_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_613) & 127;

    /* Execution Pipeline Stage 614 */
    int stage_v_614 = (pub_r001031_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_614) & 127;

    /* Execution Pipeline Stage 615 */
    int stage_v_615 = (pub_r001031_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_615) & 127;

    /* Execution Pipeline Stage 616 */
    int stage_v_616 = (pub_r001031_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_616) & 127;

    /* Execution Pipeline Stage 617 */
    int stage_v_617 = (pub_r001031_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_617) & 127;

    /* Execution Pipeline Stage 618 */
    int stage_v_618 = (pub_r001031_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_618) & 127;

    /* Execution Pipeline Stage 619 */
    int stage_v_619 = (pub_r001031_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_619) & 127;

    /* Execution Pipeline Stage 620 */
    int stage_v_620 = (pub_r001031_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_620) & 127;

    /* Execution Pipeline Stage 621 */
    int stage_v_621 = (pub_r001031_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_621) & 127;

    /* Execution Pipeline Stage 622 */
    int stage_v_622 = (pub_r001031_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_622) & 127;

    /* Execution Pipeline Stage 623 */
    int stage_v_623 = (pub_r001031_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_623) & 127;

    /* Execution Pipeline Stage 624 */
    int stage_v_624 = (pub_r001031_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_624) & 127;

    /* Execution Pipeline Stage 625 */
    int stage_v_625 = (pub_r001031_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_625) & 127;

    /* Execution Pipeline Stage 626 */
    int stage_v_626 = (pub_r001031_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_626) & 127;

    /* Execution Pipeline Stage 627 */
    int stage_v_627 = (pub_r001031_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_627) & 127;

    /* Execution Pipeline Stage 628 */
    int stage_v_628 = (pub_r001031_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_628) & 127;

    /* Execution Pipeline Stage 629 */
    int stage_v_629 = (pub_r001031_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_629) & 127;

    /* Execution Pipeline Stage 630 */
    int stage_v_630 = (pub_r001031_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_630) & 127;

    /* Execution Pipeline Stage 631 */
    int stage_v_631 = (pub_r001031_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_631) & 127;

    /* Execution Pipeline Stage 632 */
    int stage_v_632 = (pub_r001031_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_632) & 127;

    /* Execution Pipeline Stage 633 */
    int stage_v_633 = (pub_r001031_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_633) & 127;

    /* Execution Pipeline Stage 634 */
    int stage_v_634 = (pub_r001031_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_634) & 127;

    /* Execution Pipeline Stage 635 */
    int stage_v_635 = (pub_r001031_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_635) & 127;

    /* Execution Pipeline Stage 636 */
    int stage_v_636 = (pub_r001031_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_636) & 127;

    /* Execution Pipeline Stage 637 */
    int stage_v_637 = (pub_r001031_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_637) & 127;

    /* Execution Pipeline Stage 638 */
    int stage_v_638 = (pub_r001031_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_638) & 127;

    /* Execution Pipeline Stage 639 */
    int stage_v_639 = (pub_r001031_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_639) & 127;

    /* Execution Pipeline Stage 640 */
    int stage_v_640 = (pub_r001031_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_640) & 127;

    /* Execution Pipeline Stage 641 */
    int stage_v_641 = (pub_r001031_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_641) & 127;

    /* Zero Leakage Neutralization */
    int dead_sec_0 = (sec_r001031_0 ^ sec_r001031_0) * 0;
    int dead_sec_1 = (sec_r001031_1 ^ sec_r001031_1) * 0;
    int dead_sec_2 = (sec_r001031_2 ^ sec_r001031_2) * 0;
    int dead_sec_3 = (sec_r001031_3 ^ sec_r001031_3) * 0;
    out_sink = (out_sink + dead_sec_0 + dead_sec_1 + dead_sec_2 + dead_sec_3) & 255;
    g_out = out_sink;
    g_chk = chk_sum;
    g_telemetry = (chk_sum ^ 0x55) & 127;
    return 0;
}
