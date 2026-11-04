/*
 * Benchmark Program: R000823
 * Family: secret_dependent_array
 * Generator Seed: 532317
 * High Inputs: 22 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000823_2317_0 {
    unsigned char dim;
    short scale;
    int density;
    short determinant;
    short stride;
    short trace;
    int buffer[3];
};

struct CipherContext_R000823_2317_1 {
    int nonce;
    int counter;
    unsigned char iv;
    int flags;
    int buffer[3];
};

struct SensorNode_R000823_2317_2 {
    int calib;
    short threshold;
    short offset;
    short gain;
    int reading;
    int buffer[3];
};

struct Transaction_R000823_2317_3 {
    int rate;
    unsigned char account_id;
    unsigned char status;
    int buffer[3];
};

union RegisterBank_R000823_2317_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000823_2317_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000823_2317_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000823_2317_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int vector_20 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_20 > 28) {
        acc = (acc + vector_20 * 2 + 5) & 127;
        aux ^= (vector_20 & 15);
    } else {
        acc = (acc - vector_20 + 11) & 127;
        aux += 3;
    }
    int bound_95 = (aux + st.buffer[1]) & 3;
    switch (bound_95) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_23 = local_arr[aux % 3];
    acc = (acc + pivot_23 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000823_2317_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000823_2317_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000823_2317_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000823_2317_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_40 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_40 = (index_reg_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_40) & 127;
    }
    int delta_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_55) & 63;
    acc ^= aux;
    int factor_94 = (aux + st.buffer[1]) & 3;
    switch (factor_94) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000823_2317_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000823_2317_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_54 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_54 = (accumulator_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_54) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_83) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_93 = local_arr[aux % 3];
    acc = (acc + residue_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000823_2317_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000823_2317_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int parity_33 = 0;
    for (int k = 0; k < 2; k++) {
        parity_33 = (parity_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_33) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000823_2317_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000823_2317_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int vector_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_81) & 63;
    acc ^= aux;
    int margin_24 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_24 > 47) {
        acc = (acc + margin_24 * 2 + 5) & 127;
        aux ^= (margin_24 & 15);
    } else {
        acc = (acc - margin_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000823_2317_6(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000823_2317_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_44 = 0;
    for (int k = 0; k < 3; k++) {
        damping_44 = (damping_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_44) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000823_2317_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000823_2317_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_41 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_41 > 38) {
        acc = (acc + quantum_41 * 2 + 5) & 127;
        aux ^= (quantum_41 & 15);
    } else {
        acc = (acc - quantum_41 + 11) & 127;
        aux += 3;
    }
    int anchor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000823_2317_8(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000823_2317_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int residue_50 = local_arr[aux % 3];
    acc = (acc + residue_50 * 2) & 127;
    int coefficient_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000823_2317_9(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000823_2317_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_95 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_95 = (checksum_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_95) & 127;
    }
    int mask_76 = (aux + st.buffer[1]) & 3;
    switch (mask_76) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000823_2317_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000823_2317_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_22) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_14 = local_arr[aux % 3];
    acc = (acc + threshold_14 * 2) & 127;
    int mask_80 = (aux + st.buffer[1]) & 3;
    switch (mask_80) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000823_2317_11(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000823_2317_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quantum_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_85) & 63;
    acc ^= aux;
    int mask_65 = 0;
    for (int k = 0; k < 2; k++) {
        mask_65 = (mask_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_65) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_74 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_74 > 39) {
        acc = (acc + bound_74 * 2 + 5) & 127;
        aux ^= (bound_74 & 15);
    } else {
        acc = (acc - bound_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000823_2317_12(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000823_2317_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_97 = 0;
    for (int k = 0; k < 3; k++) {
        segment_97 = (segment_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_97) & 127;
    }
    int coefficient_19 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_19 > 40) {
        acc = (acc + coefficient_19 * 2 + 5) & 127;
        aux ^= (coefficient_19 & 15);
    } else {
        acc = (acc - coefficient_19 + 11) & 127;
        aux += 3;
    }
    int delta_11 = (aux + st.buffer[1]) & 3;
    switch (delta_11) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000823_2317_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000823_2317_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_43 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_43 > 23) {
        acc = (acc + quantum_43 * 2 + 5) & 127;
        aux ^= (quantum_43 & 15);
    } else {
        acc = (acc - quantum_43 + 11) & 127;
        aux += 3;
    }
    int margin_71 = 0;
    for (int k = 0; k < 2; k++) {
        margin_71 = (margin_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000823_2317_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000823_2317_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_49) & 63;
    acc ^= aux;
    int bound_83 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_83 > 50) {
        acc = (acc + bound_83 * 2 + 5) & 127;
        aux ^= (bound_83 & 15);
    } else {
        acc = (acc - bound_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000823_0;
    int sec_r000823_1;
    int sec_r000823_2;
    int sec_r000823_3;
    int sec_r000823_4;
    int sec_r000823_5;
    int sec_r000823_6;
    int sec_r000823_7;
    int sec_r000823_8;
    int sec_r000823_9;
    int sec_r000823_10;
    int sec_r000823_11;
    int sec_r000823_12;
    int sec_r000823_13;
    int sec_r000823_14;
    int sec_r000823_15;
    int sec_r000823_16;
    int sec_r000823_17;
    int sec_r000823_18;
    int sec_r000823_19;
    int sec_r000823_20;
    int sec_r000823_21;
    int pub_r000823_0;
    int pub_r000823_1;
    int pub_r000823_2;
    int pub_r000823_3;
    int pub_r000823_4;
    int pub_r000823_5;
    int pub_r000823_6;
    int pub_r000823_7;
    int pub_r000823_8;
    int pub_r000823_9;
    int pub_r000823_10;
    int pub_r000823_11;
    int pub_r000823_12;
    int pub_r000823_13;
    int pub_r000823_14;
    int pub_r000823_15;
    int pub_r000823_16;
    int pub_r000823_17;
    int pub_r000823_18;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000823_0 >= -100 && pub_r000823_0 <= 100);
    __CPROVER_assume(pub_r000823_1 >= -100 && pub_r000823_1 <= 100);
    __CPROVER_assume(pub_r000823_2 >= -100 && pub_r000823_2 <= 100);
    __CPROVER_assume(pub_r000823_3 >= -100 && pub_r000823_3 <= 100);
    __CPROVER_assume(pub_r000823_4 >= -100 && pub_r000823_4 <= 100);
    __CPROVER_assume(pub_r000823_5 >= -100 && pub_r000823_5 <= 100);
    __CPROVER_assume(pub_r000823_6 >= -100 && pub_r000823_6 <= 100);
    __CPROVER_assume(pub_r000823_7 >= -100 && pub_r000823_7 <= 100);
    __CPROVER_assume(pub_r000823_8 >= -100 && pub_r000823_8 <= 100);
    __CPROVER_assume(pub_r000823_9 >= -100 && pub_r000823_9 <= 100);
    __CPROVER_assume(pub_r000823_10 >= -100 && pub_r000823_10 <= 100);
    __CPROVER_assume(pub_r000823_11 >= -100 && pub_r000823_11 <= 100);
    __CPROVER_assume(pub_r000823_12 >= -100 && pub_r000823_12 <= 100);
    __CPROVER_assume(pub_r000823_13 >= -100 && pub_r000823_13 <= 100);
    __CPROVER_assume(pub_r000823_14 >= -100 && pub_r000823_14 <= 100);
    __CPROVER_assume(pub_r000823_15 >= -100 && pub_r000823_15 <= 100);
    __CPROVER_assume(pub_r000823_16 >= -100 && pub_r000823_16 <= 100);
    __CPROVER_assume(pub_r000823_17 >= -100 && pub_r000823_17 <= 100);
    __CPROVER_assume(pub_r000823_18 >= -100 && pub_r000823_18 <= 100);
    __CPROVER_assume(sec_r000823_0 >= 0 && sec_r000823_0 <= 255);
    __CPROVER_assume(sec_r000823_1 >= 0 && sec_r000823_1 <= 255);
    __CPROVER_assume(sec_r000823_2 >= 0 && sec_r000823_2 <= 255);
    __CPROVER_assume(sec_r000823_3 >= 0 && sec_r000823_3 <= 255);
    __CPROVER_assume(sec_r000823_4 >= 0 && sec_r000823_4 <= 255);
    __CPROVER_assume(sec_r000823_5 >= 0 && sec_r000823_5 <= 255);
    __CPROVER_assume(sec_r000823_6 >= 0 && sec_r000823_6 <= 255);
    __CPROVER_assume(sec_r000823_7 >= 0 && sec_r000823_7 <= 255);
    __CPROVER_assume(sec_r000823_8 >= 0 && sec_r000823_8 <= 255);
    __CPROVER_assume(sec_r000823_9 >= 0 && sec_r000823_9 <= 255);
    __CPROVER_assume(sec_r000823_10 >= 0 && sec_r000823_10 <= 255);
    __CPROVER_assume(sec_r000823_11 >= 0 && sec_r000823_11 <= 255);
    __CPROVER_assume(sec_r000823_12 >= 0 && sec_r000823_12 <= 255);
    __CPROVER_assume(sec_r000823_13 >= 0 && sec_r000823_13 <= 255);
    __CPROVER_assume(sec_r000823_14 >= 0 && sec_r000823_14 <= 255);
    __CPROVER_assume(sec_r000823_15 >= 0 && sec_r000823_15 <= 255);
    __CPROVER_assume(sec_r000823_16 >= 0 && sec_r000823_16 <= 255);
    __CPROVER_assume(sec_r000823_17 >= 0 && sec_r000823_17 <= 255);
    __CPROVER_assume(sec_r000823_18 >= 0 && sec_r000823_18 <= 255);
    __CPROVER_assume(sec_r000823_19 >= 0 && sec_r000823_19 <= 255);
    __CPROVER_assume(sec_r000823_20 >= 0 && sec_r000823_20 <= 255);
    __CPROVER_assume(sec_r000823_21 >= 0 && sec_r000823_21 <= 255);

    struct MatrixBlock_R000823_2317_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000823_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000823_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000823_0 + 7) & 15;
    struct CipherContext_R000823_2317_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000823_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000823_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000823_0 + 9) & 15;
    struct SensorNode_R000823_2317_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000823_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000823_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000823_0 + 11) & 15;
    struct Transaction_R000823_2317_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000823_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000823_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000823_0 + 13) & 15;

    union RegisterBank_R000823_2317_0 u_var;
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
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 27) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 42) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 31) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 46) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 35) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 50) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 20) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 35) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 19) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 34) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 13) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 28) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 32) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 47) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 38) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 53) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 26) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 41) {
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
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

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
    int stage_v_51 = (st_var_3.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 37) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 52) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 29) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 44) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 29) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 44) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 25) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 40) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 19) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 34) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 11) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 26) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_2.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] ^ 96) & 3;
    switch (stage_v_93) {
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

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (out_sink > 100) ? (chk_sum & 31) : (100 & 31);
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= (stage_v_95 << 1) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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
    int stage_v_99 = (st_var_3.buffer[0] ^ 102) & 3;
    switch (stage_v_99) {
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

    /* Execution Pipeline Stage 100 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_2.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_1.buffer[0] * 2 + 322) & 63;
    if (stage_v_105 > 26) {
        out_sink = (out_sink + stage_v_105 - 5) & 255;
        if (stage_v_105 > 41) {
            chk_sum ^= (stage_v_105 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_105 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (out_sink > 100) ? (chk_sum & 31) : (112 & 31);
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= (stage_v_107 << 1) & 127;

    /* Execution Pipeline Stage 108 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 109) & 15;
    int stage_v_108 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= stage_v_108;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (out_sink > 100) ? (chk_sum & 31) : (114 & 31);
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= (stage_v_109 << 1) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[0] ^ 113) & 3;
    switch (stage_v_110) {
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

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = table[3];
    table[3] = (table[0] + 223) & 63;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (out_sink > 100) ? (chk_sum & 31) : (117 & 31);
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= (stage_v_112 << 1) & 127;

    /* Execution Pipeline Stage 113 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 114) & 15;
    int stage_v_113 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= stage_v_113;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_3.buffer[0] ^ 118) & 3;
    switch (stage_v_115) {
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

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = table[0];
    table[0] = (table[1] + 233) & 63;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (out_sink > 100) ? (chk_sum & 31) : (122 & 31);
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= (stage_v_117 << 1) & 127;

    /* Execution Pipeline Stage 118 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = table[1];
    table[1] = (table[2] + 243) & 63;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = table[3];
    table[3] = (table[0] + 247) & 63;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[1] * 2 + 379) & 63;
    if (stage_v_124 > 37) {
        out_sink = (out_sink + stage_v_124 - 5) & 255;
        if (stage_v_124 > 52) {
            chk_sum ^= (stage_v_124 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_124 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_3.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_3.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 31) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 46) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (out_sink > 100) ? (chk_sum & 31) : (140 & 31);
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= (stage_v_135 << 1) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_1.buffer[2] * 2 + 418) & 63;
    if (stage_v_137 > 21) {
        out_sink = (out_sink + stage_v_137 - 5) & 255;
        if (stage_v_137 > 36) {
            chk_sum ^= (stage_v_137 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_137 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

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
    int stage_v_143 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] ^ 147) & 3;
    switch (stage_v_144) {
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

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (out_sink > 100) ? (chk_sum & 31) : (153 & 31);
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= (stage_v_148 << 1) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = table[1];
    table[1] = (table[2] + 299) & 63;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_0.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 38) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 53) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 155) & 15;
    int stage_v_154 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= stage_v_154;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] ^ 159) & 3;
    switch (stage_v_156) {
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

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_159 = (stage_v_159 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 161) & 15;
    int stage_v_160 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= stage_v_160;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 38) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 53) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = table[1];
    table[1] = (table[2] + 331) & 63;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (out_sink > 100) ? (chk_sum & 31) : (171 & 31);
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= (stage_v_166 << 1) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] ^ 171) & 3;
    switch (stage_v_168) {
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

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_169 = (stage_v_169 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_171 = (stage_v_171 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_1.buffer[2] * 2 + 526) & 63;
    if (stage_v_173 > 28) {
        out_sink = (out_sink + stage_v_173 - 5) & 255;
        if (stage_v_173 > 43) {
            chk_sum ^= (stage_v_173 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_173 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_2.buffer[0] * 2 + 529) & 63;
    if (stage_v_174 > 31) {
        out_sink = (out_sink + stage_v_174 - 5) & 255;
        if (stage_v_174 > 46) {
            chk_sum ^= (stage_v_174 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_174 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 26) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 41) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_2.buffer[0] ^ 181) & 3;
    switch (stage_v_178) {
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

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_179 = (stage_v_179 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] ^ 183) & 3;
    switch (stage_v_180) {
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

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = table[1];
    table[1] = (table[2] + 363) & 63;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = table[2];
    table[2] = (table[3] + 365) & 63;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_0.buffer[0] ^ 187) & 3;
    switch (stage_v_184) {
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

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (st_var_1.buffer[0] ^ 188) & 3;
    switch (stage_v_185) {
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

    /* Execution Pipeline Stage 186 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 187) & 15;
    int stage_v_186 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_186) & 255;
    chk_sum ^= stage_v_186;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_187 = (stage_v_187 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_187) & 127;
    }
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (st_var_0.buffer[2] * 2 + 571) & 63;
    if (stage_v_188 > 20) {
        out_sink = (out_sink + stage_v_188 - 5) & 255;
        if (stage_v_188 > 35) {
            chk_sum ^= (stage_v_188 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_188 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (st_var_1.buffer[0] ^ 192) & 3;
    switch (stage_v_189) {
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

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (out_sink > 100) ? (chk_sum & 31) : (196 & 31);
    out_sink = (out_sink + stage_v_191) & 255;
    chk_sum ^= (stage_v_191 << 1) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[1] * 2 + 586) & 63;
    if (stage_v_193 > 29) {
        out_sink = (out_sink + stage_v_193 - 5) & 255;
        if (stage_v_193 > 44) {
            chk_sum ^= (stage_v_193 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_193 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (st_var_2.buffer[0] ^ 197) & 3;
    switch (stage_v_194) {
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

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_3.buffer[0] * 2 + 592) & 63;
    if (stage_v_195 > 33) {
        out_sink = (out_sink + stage_v_195 - 5) & 255;
        if (stage_v_195 > 48) {
            chk_sum ^= (stage_v_195 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_195 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = table[0];
    table[0] = (table[1] + 393) & 63;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_198 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_199 = (stage_v_199 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_199) & 127;
    }
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (out_sink > 100) ? (chk_sum & 31) : (205 & 31);
    out_sink = (out_sink + stage_v_200) & 255;
    chk_sum ^= (stage_v_200 << 1) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (st_var_1.buffer[0] ^ 204) & 3;
    switch (stage_v_201) {
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

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_202 = (stage_v_202 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_202) & 127;
    }
    out_sink = (out_sink + stage_v_202) & 255;

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 39, 94, 26, 88 };
    int s_idx = (sec_r000823_6 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
