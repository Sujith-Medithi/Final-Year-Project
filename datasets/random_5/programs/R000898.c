/*
 * Benchmark Program: R000898
 * Security Family: secret_dependent_loops
 * Generator Seed: 589813
 * High Inputs: 21 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000898_9813_0 {
    int account_id;
    short status;
    int rate;
    unsigned char auth_code;
    int buffer[3];
};

struct MatrixBlock_R000898_9813_1 {
    int dim;
    unsigned char determinant;
    int trace;
    short scale;
    short density;
    int buffer[3];
};

union ColorPixel_R000898_9813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000898_9813_0(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000898_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_47 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_47 > 47) {
        acc = (acc + offset_47 * 2 + 5) & 127;
        aux ^= (offset_47 & 15);
    } else {
        acc = (acc - offset_47 + 11) & 127;
        aux += 3;
    }
    int segment_14 = (aux + st.buffer[1]) & 3;
    switch (segment_14) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000898_9813_1(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_80) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_73 = local_arr[aux % 3];
    acc = (acc + segment_73 * 2) & 127;
    int delta_45 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_45 > 47) {
        acc = (acc + delta_45 * 2 + 5) & 127;
        aux ^= (delta_45 & 15);
    } else {
        acc = (acc - delta_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000898_9813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000898_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000898_9813_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int mask_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_92) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_72 = local_arr[aux % 3];
    acc = (acc + index_reg_72 * 2) & 127;
    int tracker_76 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_76 > 46) {
        acc = (acc + tracker_76 * 2 + 5) & 127;
        aux ^= (tracker_76 & 15);
    } else {
        acc = (acc - tracker_76 + 11) & 127;
        aux += 3;
    }
    int offset_14 = (aux + st.buffer[1]) & 3;
    switch (offset_14) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000898_9813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000898_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int stride_13 = local_arr[aux % 3];
    acc = (acc + stride_13 * 2) & 127;
    int threshold_20 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_20 > 19) {
        acc = (acc + threshold_20 * 2 + 5) & 127;
        aux ^= (threshold_20 & 15);
    } else {
        acc = (acc - threshold_20 + 11) & 127;
        aux += 3;
    }
    int bound_63 = (aux + st.buffer[1]) & 3;
    switch (bound_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000898_9813_5(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int parity_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_21) & 63;
    acc ^= aux;
    int segment_93 = (aux + st.buffer[1]) & 3;
    switch (segment_93) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000898_9813_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int parity_76 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_76 > 23) {
        acc = (acc + parity_76 * 2 + 5) & 127;
        aux ^= (parity_76 & 15);
    } else {
        acc = (acc - parity_76 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000898_9813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000898_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int pivot_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_54) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_85 = local_arr[aux % 3];
    acc = (acc + scale_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000898_9813_8(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int phase_31 = (aux + st.buffer[1]) & 3;
    switch (phase_31) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_80 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_80 > 10) {
        acc = (acc + mask_80 * 2 + 5) & 127;
        aux ^= (mask_80 & 15);
    } else {
        acc = (acc - mask_80 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_18 = local_arr[aux % 3];
    acc = (acc + mask_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000898_9813_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000898_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int offset_25 = (aux + st.buffer[1]) & 3;
    switch (offset_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000898_9813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000898_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int vector_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_79) & 63;
    acc ^= aux;
    int tracker_67 = (aux + st.buffer[1]) & 3;
    switch (tracker_67) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_67 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_67 > 39) {
        acc = (acc + segment_67 * 2 + 5) & 127;
        aux ^= (segment_67 & 15);
    } else {
        acc = (acc - segment_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000898_9813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_30 = local_arr[aux % 3];
    acc = (acc + accumulator_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000898_9813_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int weight_30 = local_arr[aux % 3];
    acc = (acc + weight_30 * 2) & 127;
    int phase_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000898_9813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000898_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int vector_90 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_90 > 11) {
        acc = (acc + vector_90 * 2 + 5) & 127;
        aux ^= (vector_90 & 15);
    } else {
        acc = (acc - vector_90 + 11) & 127;
        aux += 3;
    }
    int vector_38 = (aux + st.buffer[1]) & 3;
    switch (vector_38) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_56 = local_arr[aux % 3];
    acc = (acc + parity_56 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000898_0;
    int sec_r000898_1;
    int sec_r000898_2;
    int sec_r000898_3;
    int sec_r000898_4;
    int sec_r000898_5;
    int sec_r000898_6;
    int sec_r000898_7;
    int sec_r000898_8;
    int sec_r000898_9;
    int sec_r000898_10;
    int sec_r000898_11;
    int sec_r000898_12;
    int sec_r000898_13;
    int sec_r000898_14;
    int sec_r000898_15;
    int sec_r000898_16;
    int sec_r000898_17;
    int sec_r000898_18;
    int sec_r000898_19;
    int sec_r000898_20;
    int pub_r000898_0;
    int pub_r000898_1;
    int pub_r000898_2;
    int pub_r000898_3;
    int pub_r000898_4;
    int pub_r000898_5;
    int pub_r000898_6;
    int pub_r000898_7;
    int pub_r000898_8;
    int pub_r000898_9;
    int pub_r000898_10;
    int pub_r000898_11;
    int pub_r000898_12;
    int pub_r000898_13;
    int pub_r000898_14;
    int pub_r000898_15;
    int pub_r000898_16;
    int pub_r000898_17;
    int pub_r000898_18;
    int pub_r000898_19;
    int pub_r000898_20;
    int pub_r000898_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000898_0 >= -100 && pub_r000898_0 <= 100);
    __CPROVER_assume(pub_r000898_1 >= -100 && pub_r000898_1 <= 100);
    __CPROVER_assume(pub_r000898_2 >= -100 && pub_r000898_2 <= 100);
    __CPROVER_assume(pub_r000898_3 >= -100 && pub_r000898_3 <= 100);
    __CPROVER_assume(pub_r000898_4 >= -100 && pub_r000898_4 <= 100);
    __CPROVER_assume(pub_r000898_5 >= -100 && pub_r000898_5 <= 100);
    __CPROVER_assume(pub_r000898_6 >= -100 && pub_r000898_6 <= 100);
    __CPROVER_assume(pub_r000898_7 >= -100 && pub_r000898_7 <= 100);
    __CPROVER_assume(pub_r000898_8 >= -100 && pub_r000898_8 <= 100);
    __CPROVER_assume(pub_r000898_9 >= -100 && pub_r000898_9 <= 100);
    __CPROVER_assume(pub_r000898_10 >= -100 && pub_r000898_10 <= 100);
    __CPROVER_assume(pub_r000898_11 >= -100 && pub_r000898_11 <= 100);
    __CPROVER_assume(pub_r000898_12 >= -100 && pub_r000898_12 <= 100);
    __CPROVER_assume(pub_r000898_13 >= -100 && pub_r000898_13 <= 100);
    __CPROVER_assume(pub_r000898_14 >= -100 && pub_r000898_14 <= 100);
    __CPROVER_assume(pub_r000898_15 >= -100 && pub_r000898_15 <= 100);
    __CPROVER_assume(pub_r000898_16 >= -100 && pub_r000898_16 <= 100);
    __CPROVER_assume(pub_r000898_17 >= -100 && pub_r000898_17 <= 100);
    __CPROVER_assume(pub_r000898_18 >= -100 && pub_r000898_18 <= 100);
    __CPROVER_assume(pub_r000898_19 >= -100 && pub_r000898_19 <= 100);
    __CPROVER_assume(pub_r000898_20 >= -100 && pub_r000898_20 <= 100);
    __CPROVER_assume(pub_r000898_21 >= -100 && pub_r000898_21 <= 100);
    __CPROVER_assume(sec_r000898_0 >= 0 && sec_r000898_0 <= 255);
    __CPROVER_assume(sec_r000898_1 >= 0 && sec_r000898_1 <= 255);
    __CPROVER_assume(sec_r000898_2 >= 0 && sec_r000898_2 <= 255);
    __CPROVER_assume(sec_r000898_3 >= 0 && sec_r000898_3 <= 255);
    __CPROVER_assume(sec_r000898_4 >= 0 && sec_r000898_4 <= 255);
    __CPROVER_assume(sec_r000898_5 >= 0 && sec_r000898_5 <= 255);
    __CPROVER_assume(sec_r000898_6 >= 0 && sec_r000898_6 <= 255);
    __CPROVER_assume(sec_r000898_7 >= 0 && sec_r000898_7 <= 255);
    __CPROVER_assume(sec_r000898_8 >= 0 && sec_r000898_8 <= 255);
    __CPROVER_assume(sec_r000898_9 >= 0 && sec_r000898_9 <= 255);
    __CPROVER_assume(sec_r000898_10 >= 0 && sec_r000898_10 <= 255);
    __CPROVER_assume(sec_r000898_11 >= 0 && sec_r000898_11 <= 255);
    __CPROVER_assume(sec_r000898_12 >= 0 && sec_r000898_12 <= 255);
    __CPROVER_assume(sec_r000898_13 >= 0 && sec_r000898_13 <= 255);
    __CPROVER_assume(sec_r000898_14 >= 0 && sec_r000898_14 <= 255);
    __CPROVER_assume(sec_r000898_15 >= 0 && sec_r000898_15 <= 255);
    __CPROVER_assume(sec_r000898_16 >= 0 && sec_r000898_16 <= 255);
    __CPROVER_assume(sec_r000898_17 >= 0 && sec_r000898_17 <= 255);
    __CPROVER_assume(sec_r000898_18 >= 0 && sec_r000898_18 <= 255);
    __CPROVER_assume(sec_r000898_19 >= 0 && sec_r000898_19 <= 255);
    __CPROVER_assume(sec_r000898_20 >= 0 && sec_r000898_20 <= 255);

    struct Transaction_R000898_9813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000898_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000898_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000898_0 + 7) & 15;
    struct MatrixBlock_R000898_9813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000898_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000898_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000898_0 + 9) & 15;

    union ColorPixel_R000898_9813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 29) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 44) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 35) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 50) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

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
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 31) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 46) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 10) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 25) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 17) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 32) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 30) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 45) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 38) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 53) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 20) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 35) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (out_sink > 100) ? (chk_sum & 31) : (78 & 31);
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= (stage_v_73 << 1) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 18) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 33) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_3 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000898_3) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000898_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_8 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000898_7) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_8 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000898_12) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_2 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000898_7) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000898_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000898_12) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000898_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_19 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000898_19) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000898_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000898_4) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000898_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000898_19) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000898_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_13 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000898_18) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000898_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000898_17) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000898_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000898_11) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000898_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_10 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_17 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000898_18) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000898_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000898_17) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000898_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000898_2) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000898_14) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000898_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000898_11) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000898_2) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000898_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000898_14) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000898_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000898_17) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000898_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000898_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000898_16) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000898_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_5 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000898_14) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000898_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000898_5) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000898_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000898_10) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000898_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000898_10) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000898_3) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000898_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_7 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000898_0) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000898_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_17 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000898_20) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000898_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000898_17) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000898_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000898_12) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000898_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000898_7) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000898_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_17 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000898_8) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000898_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000898_20) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000898_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000898_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000898_2) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000898_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000898_20) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000898_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_14 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000898_9) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000898_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000898_2) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000898_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_5 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000898_15) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000898_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_10 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000898_5) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000898_6) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000898_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_0 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000898_16) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000898_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000898_9) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000898_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000898_3) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000898_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_17 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000898_16) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000898_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_0 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000898_3) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000898_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_18 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000898_21) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000898_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000898_5) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000898_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_2 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000898_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000898_18) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000898_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_9 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000898_16) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000898_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_5 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000898_16) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000898_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_13 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000898_17) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000898_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000898_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_115 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000898_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000898_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_17 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000898_15) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000898_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_3 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000898_16) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_11 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000898_11) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000898_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000898_6) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000898_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000898_7) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000898_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000898_20) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000898_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_134 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000898_14) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000898_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000898_3) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000898_5) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000898_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_115 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000898_4) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000898_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_8 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000898_6) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000898_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000898_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000898_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000898_20) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000898_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_9 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000898_5) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_151 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000898_21) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000898_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_148 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000898_4) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000898_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000898_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_16 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000898_17) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000898_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_9 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000898_19) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000898_18) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000898_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_127 & 1) == step) {
            stage_v_163 = (stage_v_163 + step * 4 + pub_r000898_20) & 63;
        } else {
            stage_v_163 = (stage_v_163 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_164 = (stage_v_164 + step * 4 + pub_r000898_10) & 63;
        } else {
            stage_v_164 = (stage_v_164 + pub_r000898_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_165 = (stage_v_165 + step * 4 + pub_r000898_9) & 63;
        } else {
            stage_v_165 = (stage_v_165 + pub_r000898_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_166 = (stage_v_166 + step * 4 + pub_r000898_15) & 63;
        } else {
            stage_v_166 = (stage_v_166 + pub_r000898_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_145 & 1) == step) {
            stage_v_167 = (stage_v_167 + step * 4 + pub_r000898_7) & 63;
        } else {
            stage_v_167 = (stage_v_167 + pub_r000898_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_134 & 1) == step) {
            stage_v_168 = (stage_v_168 + step * 4 + pub_r000898_19) & 63;
        } else {
            stage_v_168 = (stage_v_168 + pub_r000898_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_4 & 1) == step) {
            stage_v_169 = (stage_v_169 + step * 4 + pub_r000898_9) & 63;
        } else {
            stage_v_169 = (stage_v_169 + pub_r000898_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_170 = (stage_v_170 + step * 4 + pub_r000898_19) & 63;
        } else {
            stage_v_170 = (stage_v_170 + pub_r000898_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_170) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_143 & 1) == step) {
            stage_v_171 = (stage_v_171 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_171 = (stage_v_171 + pub_r000898_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_18 & 1) == step) {
            stage_v_172 = (stage_v_172 + step * 4 + pub_r000898_1) & 63;
        } else {
            stage_v_172 = (stage_v_172 + pub_r000898_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_173 = (stage_v_173 + step * 4 + pub_r000898_10) & 63;
        } else {
            stage_v_173 = (stage_v_173 + pub_r000898_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_107 & 1) == step) {
            stage_v_174 = (stage_v_174 + step * 4 + pub_r000898_15) & 63;
        } else {
            stage_v_174 = (stage_v_174 + pub_r000898_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_3 & 1) == step) {
            stage_v_175 = (stage_v_175 + step * 4 + pub_r000898_3) & 63;
        } else {
            stage_v_175 = (stage_v_175 + pub_r000898_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_175) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_157 & 1) == step) {
            stage_v_176 = (stage_v_176 + step * 4 + pub_r000898_16) & 63;
        } else {
            stage_v_176 = (stage_v_176 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_176) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_177 = (stage_v_177 + step * 4 + pub_r000898_3) & 63;
        } else {
            stage_v_177 = (stage_v_177 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_177) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_178 = (stage_v_178 + step * 4 + pub_r000898_10) & 63;
        } else {
            stage_v_178 = (stage_v_178 + pub_r000898_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_179 = (stage_v_179 + step * 4 + pub_r000898_14) & 63;
        } else {
            stage_v_179 = (stage_v_179 + pub_r000898_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_180 = (stage_v_180 + step * 4 + pub_r000898_20) & 63;
        } else {
            stage_v_180 = (stage_v_180 + pub_r000898_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_180) & 127;
    }
    out_sink = (out_sink + stage_v_180) & 255;
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_16 & 1) == step) {
            stage_v_181 = (stage_v_181 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_181 = (stage_v_181 + pub_r000898_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_145 & 1) == step) {
            stage_v_182 = (stage_v_182 + step * 4 + pub_r000898_9) & 63;
        } else {
            stage_v_182 = (stage_v_182 + pub_r000898_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_182) & 127;
    }
    out_sink = (out_sink + stage_v_182) & 255;
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_169 & 1) == step) {
            stage_v_183 = (stage_v_183 + step * 4 + pub_r000898_9) & 63;
        } else {
            stage_v_183 = (stage_v_183 + pub_r000898_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_183) & 127;
    }
    out_sink = (out_sink + stage_v_183) & 255;
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_12 & 1) == step) {
            stage_v_184 = (stage_v_184 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_184 = (stage_v_184 + pub_r000898_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_184) & 127;
    }
    out_sink = (out_sink + stage_v_184) & 255;
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000898_18 & 1) == step) {
            stage_v_185 = (stage_v_185 + step * 4 + pub_r000898_13) & 63;
        } else {
            stage_v_185 = (stage_v_185 + pub_r000898_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_185) & 127;
    }
    out_sink = (out_sink + stage_v_185) & 255;
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_186 = (stage_v_186 + step * 4 + pub_r000898_0) & 63;
        } else {
            stage_v_186 = (stage_v_186 + pub_r000898_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_186) & 127;
    }
    out_sink = (out_sink + stage_v_186) & 255;
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
