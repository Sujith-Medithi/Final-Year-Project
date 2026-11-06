/*
 * Benchmark Program: R000228
 * Security Family: secret_dependent_loops
 * Generator Seed: 522813
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000228_2813_0 {
    unsigned char determinant;
    short stride;
    int dim;
    int trace;
    int scale;
    int buffer[3];
};

struct EventLog_R000228_2813_1 {
    int timestamp;
    int severity;
    unsigned char seq;
    unsigned char facility;
    int code;
    int buffer[3];
};

union PacketPayload_R000228_2813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000228_2813_0(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int coefficient_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000228_2813_1(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int bound_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_41) & 63;
    acc ^= aux;
    int tally_29 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_29 > 10) {
        acc = (acc + tally_29 * 2 + 5) & 127;
        aux ^= (tally_29 & 15);
    } else {
        acc = (acc - tally_29 + 11) & 127;
        aux += 3;
    }
    int vector_90 = (aux + st.buffer[1]) & 3;
    switch (vector_90) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000228_2813_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tracker_16 = (aux + st.buffer[1]) & 3;
    switch (tracker_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000228_2813_3(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000228_2813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int stride_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_53) & 63;
    acc ^= aux;
    int damping_64 = (aux + st.buffer[1]) & 3;
    switch (damping_64) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000228_2813_5(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_57 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_57 > 29) {
        acc = (acc + vector_57 * 2 + 5) & 127;
        aux ^= (vector_57 & 15);
    } else {
        acc = (acc - vector_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000228_2813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000228_2813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int sample_35 = local_arr[aux % 3];
    acc = (acc + sample_35 * 2) & 127;
    int factor_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_91) & 63;
    acc ^= aux;
    int mask_52 = (aux + st.buffer[1]) & 3;
    switch (mask_52) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000228_2813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int mask_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_62) & 63;
    acc ^= aux;
    int delta_88 = (aux + st.buffer[1]) & 3;
    switch (delta_88) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000228_2813_9(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int tally_34 = local_arr[aux % 3];
    acc = (acc + tally_34 * 2) & 127;
    int stride_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_91) & 63;
    acc ^= aux;
    int quotient_69 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_69 > 24) {
        acc = (acc + quotient_69 * 2 + 5) & 127;
        aux ^= (quotient_69 & 15);
    } else {
        acc = (acc - quotient_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000228_2813_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_10 = (aux + st.buffer[1]) & 3;
    switch (scale_10) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_52 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_52 > 27) {
        acc = (acc + pivot_52 * 2 + 5) & 127;
        aux ^= (pivot_52 & 15);
    } else {
        acc = (acc - pivot_52 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_13 = local_arr[aux % 3];
    acc = (acc + stride_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000228_2813_11(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_28 = local_arr[aux % 3];
    acc = (acc + vector_28 * 2) & 127;
    int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_81) & 63;
    acc ^= aux;
    int pivot_65 = (aux + st.buffer[1]) & 3;
    switch (pivot_65) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000228_2813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int sample_78 = local_arr[aux % 3];
    acc = (acc + sample_78 * 2) & 127;
    int phase_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_24) & 63;
    acc ^= aux;
    int index_reg_78 = (aux + st.buffer[1]) & 3;
    switch (index_reg_78) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_81 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_81 > 50) {
        acc = (acc + sample_81 * 2 + 5) & 127;
        aux ^= (sample_81 & 15);
    } else {
        acc = (acc - sample_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000228_2813_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int scale_92 = (aux + st.buffer[1]) & 3;
    switch (scale_92) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_70) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_94 = local_arr[aux % 3];
    acc = (acc + damping_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000228_2813_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000228_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int bound_40 = local_arr[aux % 3];
    acc = (acc + bound_40 * 2) & 127;
    int coefficient_23 = (aux + st.buffer[1]) & 3;
    switch (coefficient_23) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000228_2813_15(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000228_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_82 = (aux + st.buffer[1]) & 3;
    switch (sample_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_94 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_94 > 42) {
        acc = (acc + sample_94 * 2 + 5) & 127;
        aux ^= (sample_94 & 15);
    } else {
        acc = (acc - sample_94 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000228_0;
    int sec_r000228_1;
    int sec_r000228_2;
    int sec_r000228_3;
    int sec_r000228_4;
    int sec_r000228_5;
    int sec_r000228_6;
    int sec_r000228_7;
    int sec_r000228_8;
    int sec_r000228_9;
    int sec_r000228_10;
    int sec_r000228_11;
    int sec_r000228_12;
    int sec_r000228_13;
    int sec_r000228_14;
    int sec_r000228_15;
    int sec_r000228_16;
    int sec_r000228_17;
    int sec_r000228_18;
    int sec_r000228_19;
    int sec_r000228_20;
    int sec_r000228_21;
    int pub_r000228_0;
    int pub_r000228_1;
    int pub_r000228_2;
    int pub_r000228_3;
    int pub_r000228_4;
    int pub_r000228_5;
    int pub_r000228_6;
    int pub_r000228_7;
    int pub_r000228_8;
    int pub_r000228_9;
    int pub_r000228_10;
    int pub_r000228_11;
    int pub_r000228_12;
    int pub_r000228_13;
    int pub_r000228_14;
    int pub_r000228_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000228_0 >= -100 && pub_r000228_0 <= 100);
    __CPROVER_assume(pub_r000228_1 >= -100 && pub_r000228_1 <= 100);
    __CPROVER_assume(pub_r000228_2 >= -100 && pub_r000228_2 <= 100);
    __CPROVER_assume(pub_r000228_3 >= -100 && pub_r000228_3 <= 100);
    __CPROVER_assume(pub_r000228_4 >= -100 && pub_r000228_4 <= 100);
    __CPROVER_assume(pub_r000228_5 >= -100 && pub_r000228_5 <= 100);
    __CPROVER_assume(pub_r000228_6 >= -100 && pub_r000228_6 <= 100);
    __CPROVER_assume(pub_r000228_7 >= -100 && pub_r000228_7 <= 100);
    __CPROVER_assume(pub_r000228_8 >= -100 && pub_r000228_8 <= 100);
    __CPROVER_assume(pub_r000228_9 >= -100 && pub_r000228_9 <= 100);
    __CPROVER_assume(pub_r000228_10 >= -100 && pub_r000228_10 <= 100);
    __CPROVER_assume(pub_r000228_11 >= -100 && pub_r000228_11 <= 100);
    __CPROVER_assume(pub_r000228_12 >= -100 && pub_r000228_12 <= 100);
    __CPROVER_assume(pub_r000228_13 >= -100 && pub_r000228_13 <= 100);
    __CPROVER_assume(pub_r000228_14 >= -100 && pub_r000228_14 <= 100);
    __CPROVER_assume(pub_r000228_15 >= -100 && pub_r000228_15 <= 100);
    __CPROVER_assume(sec_r000228_0 >= 0 && sec_r000228_0 <= 255);
    __CPROVER_assume(sec_r000228_1 >= 0 && sec_r000228_1 <= 255);
    __CPROVER_assume(sec_r000228_2 >= 0 && sec_r000228_2 <= 255);
    __CPROVER_assume(sec_r000228_3 >= 0 && sec_r000228_3 <= 255);
    __CPROVER_assume(sec_r000228_4 >= 0 && sec_r000228_4 <= 255);
    __CPROVER_assume(sec_r000228_5 >= 0 && sec_r000228_5 <= 255);
    __CPROVER_assume(sec_r000228_6 >= 0 && sec_r000228_6 <= 255);
    __CPROVER_assume(sec_r000228_7 >= 0 && sec_r000228_7 <= 255);
    __CPROVER_assume(sec_r000228_8 >= 0 && sec_r000228_8 <= 255);
    __CPROVER_assume(sec_r000228_9 >= 0 && sec_r000228_9 <= 255);
    __CPROVER_assume(sec_r000228_10 >= 0 && sec_r000228_10 <= 255);
    __CPROVER_assume(sec_r000228_11 >= 0 && sec_r000228_11 <= 255);
    __CPROVER_assume(sec_r000228_12 >= 0 && sec_r000228_12 <= 255);
    __CPROVER_assume(sec_r000228_13 >= 0 && sec_r000228_13 <= 255);
    __CPROVER_assume(sec_r000228_14 >= 0 && sec_r000228_14 <= 255);
    __CPROVER_assume(sec_r000228_15 >= 0 && sec_r000228_15 <= 255);
    __CPROVER_assume(sec_r000228_16 >= 0 && sec_r000228_16 <= 255);
    __CPROVER_assume(sec_r000228_17 >= 0 && sec_r000228_17 <= 255);
    __CPROVER_assume(sec_r000228_18 >= 0 && sec_r000228_18 <= 255);
    __CPROVER_assume(sec_r000228_19 >= 0 && sec_r000228_19 <= 255);
    __CPROVER_assume(sec_r000228_20 >= 0 && sec_r000228_20 <= 255);
    __CPROVER_assume(sec_r000228_21 >= 0 && sec_r000228_21 <= 255);

    struct MatrixBlock_R000228_2813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000228_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000228_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000228_0 + 7) & 15;
    struct EventLog_R000228_2813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000228_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000228_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000228_0 + 9) & 15;

    union PacketPayload_R000228_2813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 15) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 30) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_1 & 1) == step) {
            stage_v_12 = (stage_v_12 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_12 = (stage_v_12 + pub_r000228_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_12 & 1) == step) {
            stage_v_13 = (stage_v_13 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_13 = (stage_v_13 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_14 & 1) == step) {
            stage_v_14 = (stage_v_14 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_14 = (stage_v_14 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_12 & 1) == step) {
            stage_v_15 = (stage_v_15 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_15 = (stage_v_15 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_14 & 1) == step) {
            stage_v_16 = (stage_v_16 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_16 = (stage_v_16 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_21 & 1) == step) {
            stage_v_17 = (stage_v_17 + step * 4 + pub_r000228_12) & 63;
        } else {
            stage_v_17 = (stage_v_17 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_10 & 1) == step) {
            stage_v_18 = (stage_v_18 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_18 = (stage_v_18 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_12 & 1) == step) {
            stage_v_19 = (stage_v_19 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_19 = (stage_v_19 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_17 & 1) == step) {
            stage_v_20 = (stage_v_20 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_20 = (stage_v_20 + pub_r000228_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_14 & 1) == step) {
            stage_v_21 = (stage_v_21 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_21 = (stage_v_21 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_14 & 1) == step) {
            stage_v_22 = (stage_v_22 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_22 = (stage_v_22 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_18 & 1) == step) {
            stage_v_23 = (stage_v_23 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_23 = (stage_v_23 + pub_r000228_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_18 & 1) == step) {
            stage_v_24 = (stage_v_24 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_24 = (stage_v_24 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_23 & 1) == step) {
            stage_v_25 = (stage_v_25 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_25 = (stage_v_25 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_19 & 1) == step) {
            stage_v_26 = (stage_v_26 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_26 = (stage_v_26 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_16 & 1) == step) {
            stage_v_27 = (stage_v_27 + step * 4 + pub_r000228_1) & 63;
        } else {
            stage_v_27 = (stage_v_27 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_4 & 1) == step) {
            stage_v_28 = (stage_v_28 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_28 = (stage_v_28 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_25 & 1) == step) {
            stage_v_29 = (stage_v_29 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_29 = (stage_v_29 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_23 & 1) == step) {
            stage_v_30 = (stage_v_30 + step * 4 + pub_r000228_13) & 63;
        } else {
            stage_v_30 = (stage_v_30 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_5 & 1) == step) {
            stage_v_31 = (stage_v_31 + step * 4 + pub_r000228_12) & 63;
        } else {
            stage_v_31 = (stage_v_31 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_12 & 1) == step) {
            stage_v_32 = (stage_v_32 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_32 = (stage_v_32 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_33 = (stage_v_33 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_33 = (stage_v_33 + pub_r000228_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_17 & 1) == step) {
            stage_v_34 = (stage_v_34 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_34 = (stage_v_34 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_31 & 1) == step) {
            stage_v_35 = (stage_v_35 + step * 4 + pub_r000228_7) & 63;
        } else {
            stage_v_35 = (stage_v_35 + pub_r000228_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_1 & 1) == step) {
            stage_v_36 = (stage_v_36 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_36 = (stage_v_36 + pub_r000228_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_15 & 1) == step) {
            stage_v_37 = (stage_v_37 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_37 = (stage_v_37 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_2 & 1) == step) {
            stage_v_38 = (stage_v_38 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_38 = (stage_v_38 + pub_r000228_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_30 & 1) == step) {
            stage_v_39 = (stage_v_39 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_39 = (stage_v_39 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_7 & 1) == step) {
            stage_v_40 = (stage_v_40 + step * 4 + pub_r000228_7) & 63;
        } else {
            stage_v_40 = (stage_v_40 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_29 & 1) == step) {
            stage_v_41 = (stage_v_41 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_41 = (stage_v_41 + pub_r000228_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_24 & 1) == step) {
            stage_v_42 = (stage_v_42 + step * 4 + pub_r000228_1) & 63;
        } else {
            stage_v_42 = (stage_v_42 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_43 = (stage_v_43 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_43 = (stage_v_43 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_7 & 1) == step) {
            stage_v_44 = (stage_v_44 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_44 = (stage_v_44 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_7 & 1) == step) {
            stage_v_45 = (stage_v_45 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_45 = (stage_v_45 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_12 & 1) == step) {
            stage_v_46 = (stage_v_46 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_46 = (stage_v_46 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_42 & 1) == step) {
            stage_v_47 = (stage_v_47 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_47 = (stage_v_47 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_39 & 1) == step) {
            stage_v_48 = (stage_v_48 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_48 = (stage_v_48 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_8 & 1) == step) {
            stage_v_49 = (stage_v_49 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_49 = (stage_v_49 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_50 = (stage_v_50 + step * 4 + pub_r000228_13) & 63;
        } else {
            stage_v_50 = (stage_v_50 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_51 = (stage_v_51 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_51 = (stage_v_51 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_10 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_16 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_29 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_25 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_15 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_51 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_4 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000228_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_26 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000228_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_0 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000228_9) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000228_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_16 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_31 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000228_1) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_11 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000228_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_3 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000228_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_20 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000228_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_19 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000228_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_13 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_23 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000228_12) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_22 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_18 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_11 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000228_4) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_13 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_29 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000228_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_59 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_16 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_51 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_13 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_10 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_12 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000228_1) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_2 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000228_4) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000228_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_64 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000228_9) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000228_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_14 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_20 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000228_7) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_37 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000228_4) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000228_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_0 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_11 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_34 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_6 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_7 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000228_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_15 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000228_13) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_15 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000228_15) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_41 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000228_1) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000228_9) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000228_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_11 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000228_1) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000228_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_20 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000228_13) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000228_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_28 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000228_0) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_24 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_31 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000228_5) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000228_1) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000228_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_24 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000228_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_14 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000228_9) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000228_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_41 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000228_4) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000228_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_18 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000228_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_12 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000228_14) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_21 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000228_4) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000228_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_14 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000228_13) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_17 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000228_6) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000228_9) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000228_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_9 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000228_12) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000228_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000228_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000228_10) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_9 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000228_11) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000228_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_132 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000228_2) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000228_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000228_7) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000228_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000228_8) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000228_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000228_4) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000228_9 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000228_3) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000228_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_25 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000228_7) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000228_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
