/*
 * Benchmark Program: R000157
 * Security Family: nested_implicit_flow
 * Generator Seed: 515713
 * High Inputs: 18 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000157_5713_0 {
    int rms;
    unsigned char gain;
    int envelope;
    int peak;
    int channels;
    int buffer[3];
};

struct Transaction_R000157_5713_1 {
    int fee;
    int status;
    int account_id;
    short balance;
    int buffer[3];
};

struct MatrixBlock_R000157_5713_2 {
    int stride;
    unsigned char density;
    short scale;
    unsigned char dim;
    unsigned char determinant;
    int buffer[3];
};

struct Vector3D_R000157_5713_3 {
    unsigned char norm_sq;
    int coord_z;
    int pitch;
    int buffer[3];
};

union ColorPixel_R000157_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000157_5713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000157_5713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000157_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int metric_41 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_41 > 48) {
        acc = (acc + metric_41 * 2 + 5) & 127;
        aux ^= (metric_41 & 15);
    } else {
        acc = (acc - metric_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000157_5713_1(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000157_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_88 = (aux + st.buffer[1]) & 3;
    switch (checksum_88) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_79 = local_arr[aux % 3];
    acc = (acc + damping_79 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000157_5713_2(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000157_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int threshold_74 = local_arr[aux % 3];
    acc = (acc + threshold_74 * 2) & 127;
    int sample_29 = (aux + st.buffer[1]) & 3;
    switch (sample_29) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_63 = (st.buffer[0] * 3 + aux) & 63;
    if (window_63 > 43) {
        acc = (acc + window_63 * 2 + 5) & 127;
        aux ^= (window_63 & 15);
    } else {
        acc = (acc - window_63 + 11) & 127;
        aux += 3;
    }
    int window_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000157_5713_3(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000157_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int sample_29 = local_arr[aux % 3];
    acc = (acc + sample_29 * 2) & 127;
    int scale_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000157_5713_4(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000157_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_19) & 63;
    acc ^= aux;
    int tally_66 = (aux + st.buffer[1]) & 3;
    switch (tally_66) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000157_5713_5(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000157_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_57) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_55 = local_arr[aux % 3];
    acc = (acc + parity_55 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_79 > 35) {
        acc = (acc + quantum_79 * 2 + 5) & 127;
        aux ^= (quantum_79 & 15);
    } else {
        acc = (acc - quantum_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000157_5713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000157_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tracker_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_80 = local_arr[aux % 3];
    acc = (acc + mask_80 * 2) & 127;
    int vector_70 = (aux + st.buffer[1]) & 3;
    switch (vector_70) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000157_5713_7(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000157_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int threshold_64 = (aux + st.buffer[1]) & 3;
    switch (threshold_64) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_45 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_45 > 41) {
        acc = (acc + residue_45 * 2 + 5) & 127;
        aux ^= (residue_45 & 15);
    } else {
        acc = (acc - residue_45 + 11) & 127;
        aux += 3;
    }
    int damping_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000157_5713_8(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000157_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_38) & 63;
    acc ^= aux;
    int vector_31 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_31 > 26) {
        acc = (acc + vector_31 * 2 + 5) & 127;
        aux ^= (vector_31 & 15);
    } else {
        acc = (acc - vector_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_46 = local_arr[aux % 3];
    acc = (acc + quotient_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000157_5713_9(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000157_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_49 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_49 > 30) {
        acc = (acc + checksum_49 * 2 + 5) & 127;
        aux ^= (checksum_49 & 15);
    } else {
        acc = (acc - checksum_49 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_17 = local_arr[aux % 3];
    acc = (acc + margin_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000157_5713_10(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000157_5713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int margin_52 = (aux + st.buffer[1]) & 3;
    switch (margin_52) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_35 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_35 > 29) {
        acc = (acc + coefficient_35 * 2 + 5) & 127;
        aux ^= (coefficient_35 & 15);
    } else {
        acc = (acc - coefficient_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000157_5713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000157_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int cursor_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_84) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_90 = local_arr[aux % 3];
    acc = (acc + cursor_90 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000157_5713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000157_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_46 = (aux + st.buffer[1]) & 3;
    switch (residue_46) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_26 = local_arr[aux % 3];
    acc = (acc + weight_26 * 2) & 127;
    int pivot_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_80) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000157_5713_13(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000157_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int residue_23 = local_arr[aux % 3];
    acc = (acc + residue_23 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_50 = (aux + st.buffer[1]) & 3;
    switch (damping_50) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000157_0;
    int sec_r000157_1;
    int sec_r000157_2;
    int sec_r000157_3;
    int sec_r000157_4;
    int sec_r000157_5;
    int sec_r000157_6;
    int sec_r000157_7;
    int sec_r000157_8;
    int sec_r000157_9;
    int sec_r000157_10;
    int sec_r000157_11;
    int sec_r000157_12;
    int sec_r000157_13;
    int sec_r000157_14;
    int sec_r000157_15;
    int sec_r000157_16;
    int sec_r000157_17;
    int pub_r000157_0;
    int pub_r000157_1;
    int pub_r000157_2;
    int pub_r000157_3;
    int pub_r000157_4;
    int pub_r000157_5;
    int pub_r000157_6;
    int pub_r000157_7;
    int pub_r000157_8;
    int pub_r000157_9;
    int pub_r000157_10;
    int pub_r000157_11;
    int pub_r000157_12;
    int pub_r000157_13;
    int pub_r000157_14;
    int pub_r000157_15;
    int pub_r000157_16;
    int pub_r000157_17;
    int pub_r000157_18;
    int pub_r000157_19;
    int pub_r000157_20;
    int pub_r000157_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000157_0 >= -100 && pub_r000157_0 <= 100);
    __CPROVER_assume(pub_r000157_1 >= -100 && pub_r000157_1 <= 100);
    __CPROVER_assume(pub_r000157_2 >= -100 && pub_r000157_2 <= 100);
    __CPROVER_assume(pub_r000157_3 >= -100 && pub_r000157_3 <= 100);
    __CPROVER_assume(pub_r000157_4 >= -100 && pub_r000157_4 <= 100);
    __CPROVER_assume(pub_r000157_5 >= -100 && pub_r000157_5 <= 100);
    __CPROVER_assume(pub_r000157_6 >= -100 && pub_r000157_6 <= 100);
    __CPROVER_assume(pub_r000157_7 >= -100 && pub_r000157_7 <= 100);
    __CPROVER_assume(pub_r000157_8 >= -100 && pub_r000157_8 <= 100);
    __CPROVER_assume(pub_r000157_9 >= -100 && pub_r000157_9 <= 100);
    __CPROVER_assume(pub_r000157_10 >= -100 && pub_r000157_10 <= 100);
    __CPROVER_assume(pub_r000157_11 >= -100 && pub_r000157_11 <= 100);
    __CPROVER_assume(pub_r000157_12 >= -100 && pub_r000157_12 <= 100);
    __CPROVER_assume(pub_r000157_13 >= -100 && pub_r000157_13 <= 100);
    __CPROVER_assume(pub_r000157_14 >= -100 && pub_r000157_14 <= 100);
    __CPROVER_assume(pub_r000157_15 >= -100 && pub_r000157_15 <= 100);
    __CPROVER_assume(pub_r000157_16 >= -100 && pub_r000157_16 <= 100);
    __CPROVER_assume(pub_r000157_17 >= -100 && pub_r000157_17 <= 100);
    __CPROVER_assume(pub_r000157_18 >= -100 && pub_r000157_18 <= 100);
    __CPROVER_assume(pub_r000157_19 >= -100 && pub_r000157_19 <= 100);
    __CPROVER_assume(pub_r000157_20 >= -100 && pub_r000157_20 <= 100);
    __CPROVER_assume(pub_r000157_21 >= -100 && pub_r000157_21 <= 100);
    __CPROVER_assume(sec_r000157_0 >= 0 && sec_r000157_0 <= 255);
    __CPROVER_assume(sec_r000157_1 >= 0 && sec_r000157_1 <= 255);
    __CPROVER_assume(sec_r000157_2 >= 0 && sec_r000157_2 <= 255);
    __CPROVER_assume(sec_r000157_3 >= 0 && sec_r000157_3 <= 255);
    __CPROVER_assume(sec_r000157_4 >= 0 && sec_r000157_4 <= 255);
    __CPROVER_assume(sec_r000157_5 >= 0 && sec_r000157_5 <= 255);
    __CPROVER_assume(sec_r000157_6 >= 0 && sec_r000157_6 <= 255);
    __CPROVER_assume(sec_r000157_7 >= 0 && sec_r000157_7 <= 255);
    __CPROVER_assume(sec_r000157_8 >= 0 && sec_r000157_8 <= 255);
    __CPROVER_assume(sec_r000157_9 >= 0 && sec_r000157_9 <= 255);
    __CPROVER_assume(sec_r000157_10 >= 0 && sec_r000157_10 <= 255);
    __CPROVER_assume(sec_r000157_11 >= 0 && sec_r000157_11 <= 255);
    __CPROVER_assume(sec_r000157_12 >= 0 && sec_r000157_12 <= 255);
    __CPROVER_assume(sec_r000157_13 >= 0 && sec_r000157_13 <= 255);
    __CPROVER_assume(sec_r000157_14 >= 0 && sec_r000157_14 <= 255);
    __CPROVER_assume(sec_r000157_15 >= 0 && sec_r000157_15 <= 255);
    __CPROVER_assume(sec_r000157_16 >= 0 && sec_r000157_16 <= 255);
    __CPROVER_assume(sec_r000157_17 >= 0 && sec_r000157_17 <= 255);

    struct AudioFrame_R000157_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000157_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000157_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000157_0 + 7) & 15;
    struct Transaction_R000157_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000157_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000157_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000157_0 + 9) & 15;
    struct MatrixBlock_R000157_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000157_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000157_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000157_0 + 11) & 15;
    struct Vector3D_R000157_5713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000157_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000157_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000157_0 + 13) & 15;

    union ColorPixel_R000157_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 24) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 39) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 15) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 30) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

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
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 11) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 26) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 32) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 47) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_27 = (st_var_3.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 22) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 37) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

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
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 39) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 54) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[0] ^ 61) & 3;
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
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 37) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 52) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 10) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 25) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_3.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 29) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 44) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 24) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 39) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 24) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 39) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 23) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 38) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 16) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 31) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000157_6 & 1) != 0) {
        if ((sec_r000157_2 & 2) != 0) {
            stage_v_79 = (pub_r000157_15 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000157_15 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000157_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000157_4 & 2) != 0) {
            stage_v_80 = (pub_r000157_4 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000157_4 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000157_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000157_3 & 2) != 0) {
            stage_v_81 = (pub_r000157_17 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000157_17 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000157_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000157_5 & 1) != 0) {
        if ((sec_r000157_16 & 2) != 0) {
            stage_v_82 = (pub_r000157_3 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000157_3 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000157_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000157_13 & 2) != 0) {
            stage_v_83 = (pub_r000157_4 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000157_4 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000157_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000157_4 & 2) != 0) {
            stage_v_84 = (pub_r000157_1 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000157_1 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000157_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000157_10 & 2) != 0) {
            stage_v_85 = (pub_r000157_6 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000157_6 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000157_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000157_11 & 2) != 0) {
            stage_v_86 = (pub_r000157_15 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000157_15 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000157_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000157_11 & 2) != 0) {
            stage_v_87 = (pub_r000157_14 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000157_14 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000157_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000157_4 & 1) != 0) {
        if ((sec_r000157_1 & 2) != 0) {
            stage_v_88 = (pub_r000157_19 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000157_19 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000157_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000157_0 & 2) != 0) {
            stage_v_89 = (pub_r000157_20 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000157_20 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000157_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000157_1 & 2) != 0) {
            stage_v_90 = (pub_r000157_13 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000157_13 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000157_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000157_12 & 2) != 0) {
            stage_v_91 = (pub_r000157_14 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000157_14 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000157_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000157_0 & 1) != 0) {
        if ((sec_r000157_11 & 2) != 0) {
            stage_v_92 = (pub_r000157_15 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000157_15 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000157_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000157_5 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_93 = (pub_r000157_14 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000157_14 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000157_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000157_6 & 2) != 0) {
            stage_v_94 = (pub_r000157_10 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000157_10 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000157_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000157_13 & 2) != 0) {
            stage_v_95 = (pub_r000157_0 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000157_0 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000157_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000157_5 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_96 = (pub_r000157_12 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000157_12 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000157_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000157_6 & 2) != 0) {
            stage_v_97 = (pub_r000157_14 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000157_14 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000157_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000157_16 & 2) != 0) {
            stage_v_98 = (pub_r000157_20 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000157_20 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000157_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000157_7 & 2) != 0) {
            stage_v_99 = (pub_r000157_11 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000157_11 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000157_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000157_8 & 1) != 0) {
        if ((sec_r000157_9 & 2) != 0) {
            stage_v_100 = (pub_r000157_19 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000157_19 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000157_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_101 = (pub_r000157_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000157_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000157_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000157_10 & 2) != 0) {
            stage_v_102 = (pub_r000157_14 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000157_14 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000157_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000157_11 & 2) != 0) {
            stage_v_103 = (pub_r000157_0 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000157_0 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000157_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000157_10 & 2) != 0) {
            stage_v_104 = (pub_r000157_1 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000157_1 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000157_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000157_4 & 1) != 0) {
        if ((sec_r000157_7 & 2) != 0) {
            stage_v_105 = (pub_r000157_2 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000157_2 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000157_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000157_1 & 2) != 0) {
            stage_v_106 = (pub_r000157_20 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000157_20 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000157_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000157_14 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_107 = (pub_r000157_20 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000157_20 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000157_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000157_3 & 2) != 0) {
            stage_v_108 = (pub_r000157_18 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000157_18 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000157_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000157_8 & 2) != 0) {
            stage_v_109 = (pub_r000157_8 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000157_8 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000157_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000157_1 & 2) != 0) {
            stage_v_110 = (pub_r000157_0 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000157_0 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000157_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000157_8 & 2) != 0) {
            stage_v_111 = (pub_r000157_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000157_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000157_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000157_9 & 2) != 0) {
            stage_v_112 = (pub_r000157_19 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000157_19 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000157_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000157_11 & 2) != 0) {
            stage_v_113 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_114 = (pub_r000157_19 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000157_19 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000157_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000157_7 & 2) != 0) {
            stage_v_115 = (pub_r000157_4 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000157_4 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000157_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000157_12 & 2) != 0) {
            stage_v_116 = (pub_r000157_8 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000157_8 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000157_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_117 = (pub_r000157_13 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000157_13 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000157_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000157_17 & 1) != 0) {
        if ((sec_r000157_15 & 2) != 0) {
            stage_v_118 = (pub_r000157_5 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000157_5 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000157_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000157_14 & 1) != 0) {
        if ((sec_r000157_3 & 2) != 0) {
            stage_v_119 = (pub_r000157_11 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000157_11 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000157_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000157_1 & 1) != 0) {
        if ((sec_r000157_6 & 2) != 0) {
            stage_v_120 = (pub_r000157_17 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000157_17 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000157_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000157_14 & 2) != 0) {
            stage_v_121 = (pub_r000157_6 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000157_6 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000157_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000157_15 & 2) != 0) {
            stage_v_122 = (pub_r000157_1 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000157_1 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000157_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000157_15 & 2) != 0) {
            stage_v_123 = (pub_r000157_11 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000157_11 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000157_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000157_1 & 1) != 0) {
        if ((sec_r000157_3 & 2) != 0) {
            stage_v_124 = (pub_r000157_2 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000157_2 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000157_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000157_2 & 1) != 0) {
        if ((sec_r000157_10 & 2) != 0) {
            stage_v_125 = (pub_r000157_7 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000157_7 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000157_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000157_0 & 2) != 0) {
            stage_v_126 = (pub_r000157_11 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000157_11 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000157_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000157_7 & 2) != 0) {
            stage_v_127 = (pub_r000157_16 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000157_16 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000157_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000157_6 & 2) != 0) {
            stage_v_128 = (pub_r000157_15 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000157_15 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000157_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_129 = (pub_r000157_10 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000157_10 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000157_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000157_10 & 2) != 0) {
            stage_v_130 = (pub_r000157_19 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000157_19 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000157_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_131 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000157_17 & 1) != 0) {
        if ((sec_r000157_14 & 2) != 0) {
            stage_v_132 = (pub_r000157_18 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000157_18 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000157_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_133 = (pub_r000157_10 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000157_10 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000157_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000157_11 & 2) != 0) {
            stage_v_134 = (pub_r000157_7 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000157_7 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000157_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000157_0 & 1) != 0) {
        if ((sec_r000157_12 & 2) != 0) {
            stage_v_135 = (pub_r000157_17 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000157_17 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000157_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_136 = (pub_r000157_4 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000157_4 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000157_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000157_7 & 2) != 0) {
            stage_v_137 = (pub_r000157_10 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000157_10 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000157_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000157_13 & 2) != 0) {
            stage_v_138 = (pub_r000157_3 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000157_3 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000157_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000157_12 & 2) != 0) {
            stage_v_139 = (pub_r000157_5 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000157_5 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000157_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000157_1 & 2) != 0) {
            stage_v_140 = (pub_r000157_10 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000157_10 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000157_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_141 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000157_4 & 2) != 0) {
            stage_v_142 = (pub_r000157_8 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000157_8 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000157_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000157_16 & 2) != 0) {
            stage_v_143 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000157_9 & 2) != 0) {
            stage_v_144 = (pub_r000157_2 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000157_2 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000157_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000157_17 & 1) != 0) {
        if ((sec_r000157_13 & 2) != 0) {
            stage_v_145 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_146 = (pub_r000157_16 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000157_16 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000157_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000157_7 & 2) != 0) {
            stage_v_147 = (pub_r000157_1 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000157_1 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000157_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000157_15 & 1) != 0) {
        if ((sec_r000157_1 & 2) != 0) {
            stage_v_148 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000157_3 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_149 = (pub_r000157_2 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000157_2 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000157_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000157_17 & 1) != 0) {
        if ((sec_r000157_13 & 2) != 0) {
            stage_v_150 = (pub_r000157_5 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000157_5 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000157_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000157_13 & 1) != 0) {
        if ((sec_r000157_0 & 2) != 0) {
            stage_v_151 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_152 = (pub_r000157_0 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000157_0 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000157_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000157_11 & 2) != 0) {
            stage_v_153 = (pub_r000157_2 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000157_2 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000157_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000157_6 & 2) != 0) {
            stage_v_154 = (pub_r000157_16 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000157_16 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000157_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000157_16 & 1) != 0) {
        if ((sec_r000157_1 & 2) != 0) {
            stage_v_155 = (pub_r000157_14 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000157_14 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000157_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_155 & 1) != 0) {
        if ((sec_r000157_17 & 2) != 0) {
            stage_v_156 = (pub_r000157_18 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000157_18 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000157_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000157_9 & 2) != 0) {
            stage_v_157 = (pub_r000157_12 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000157_12 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000157_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000157_3 & 2) != 0) {
            stage_v_158 = (pub_r000157_21 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000157_21 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000157_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000157_3 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_159 = (pub_r000157_0 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000157_0 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000157_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r000157_10 & 2) != 0) {
            stage_v_160 = (pub_r000157_8 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000157_8 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000157_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000157_5 & 2) != 0) {
            stage_v_161 = (pub_r000157_5 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000157_5 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000157_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000157_16 & 2) != 0) {
            stage_v_162 = (pub_r000157_19 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000157_19 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000157_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000157_6 & 2) != 0) {
            stage_v_163 = (pub_r000157_7 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000157_7 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000157_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
